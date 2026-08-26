//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "consteval_evaluator.hpp"

#include <algorithm>

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/vm/annium_vm.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

namespace {

// Walks a scratch expression span exactly as it will be compiled by vm::compiler_visitor, to
// perform the "dependency materialisation" step from CONSTEVAL_CTFE_PLAN.md section 5.1: every
// transitively reachable non-inline internal_function_entity must have a real address before we
// run anything, since environment::compile() is only ever called for the entities we name here --
// nothing else in the pipeline compiles them for us at this point in time.
//
// It also doubles as a cheap compile-time-safety check: `top_level` is true only while walking
// the scratch block's own instructions (not a called function's body, inline or not -- an inline
// callee's own frame, if it needs one, is independently pushfp/popfp-wrapped at the splice site
// by the compiler, so its local variables are never a problem; a non-inline callee gets its own
// real frame when it actually runs). A push/set of a local variable at the top level means the
// operand reaches into the *enclosing* function's frame, which does not exist yet at compile
// time -- that must be rejected cleanly rather than left to crash inside a frame-less scratch
// function.
struct dependency_walker
{
    environment& env;
    small_vector<entity_identifier, 8> visited;
    small_vector<internal_function_entity*, 8> to_compile;
    bool has_frame_reference = false;
    error_storage build_error;

    void walk(semantic::expression_span span, bool top_level)
    {
        while (span && !build_error) {
            std::visit([this, top_level](auto const& e) { (*this)(e, top_level); }, span.front());
            span.pop_front();
        }
    }

    template <typename T>
    void operator()(T const&, bool) {}

    void operator()(semantic::push_local_variable const&, bool top_level) { if (top_level) has_frame_reference = true; }
    void operator()(semantic::set_local_variable const&, bool top_level) { if (top_level) has_frame_reference = true; }

    void operator()(semantic::push_by_offset const& pv, bool top_level)
    {
        if (top_level && pv.base == semantic::push_by_base::frame_bottom) has_frame_reference = true;
    }

    void operator()(semantic::expression_span const& nested, bool top_level) { walk(nested, top_level); }
    void operator()(semantic::conditional_t const& c, bool top_level) { walk(c.true_branch, top_level); walk(c.false_branch, top_level); }
    void operator()(semantic::not_empty_condition_t const& n, bool top_level) { walk(n.branch, top_level); }
    void operator()(semantic::loop_scope_t const& l, bool top_level) { walk(l.branch, top_level); walk(l.continue_branch, top_level); }
    void operator()(semantic::return_statement const& r, bool top_level) { walk(r.scope_deconstruction, top_level); }
    void operator()(semantic::yield_statement const& y, bool top_level) { walk(y.result, top_level); }

    void operator()(semantic::switch_t const& s, bool top_level)
    {
        for (auto const& b : s.branches) {
            if (build_error) return;
            walk(b, top_level);
        }
    }

    void operator()(semantic::invoke_function const& invf, bool /*top_level*/)
    {
        entity const& e = env.eregistry_get(invf.fn);
        auto* fe = const_cast<internal_function_entity*>(dynamic_cast<internal_function_entity const*>(&e));
        if (!fe) return; // a builtin_function_entity is a plain extern C++ call, nothing to recurse into

        if (std::ranges::find(visited, fe->id) != visited.end()) return;
        visited.push_back(fe->id);

        if (!fe->is_built()) {
            if (auto err = fe->build()) {
                build_error = std::move(err);
                return;
            }
        }
        if (!fe->is_inline()) to_compile.push_back(fe);
        walk(fe->body, false);
    }
};

}

std::expected<syntax_expression_result, error_storage> evaluate_consteval(
    fn_compiler_context& ctx, resource_location const& loc, syntax_expression_result operand)
{
    environment& env = ctx.env();
    BOOST_ASSERT(!operand.is_const_result);

    if (!operand.temporaries.empty()) {
        return std::unexpected(make_error<basic_general_error>(loc,
            "consteval operand requires temporary storage, which is not supported yet"sv));
    }

    // CT-representability, structural part (CONSTEVAL_CTFE_PLAN.md section 3.4): the two builtin
    // opaque-handle types are never representable as a compile-time entity, regardless of what
    // the expression's static type says. This is deliberately checked *before* running anything,
    // both as a cheap early-out and because it's the case the plan's test suite exercises. `any`
    // is not statically rejectable here (see the plan) -- the actual blob_type of the result is
    // checked below once we have it.
    entity_identifier result_type = operand.type();
    if (result_type == env.get(builtin_eid::object) || result_type == env.get(builtin_eid::callable)) {
        return std::unexpected(make_error<basic_general_error>(loc,
            "consteval result type is not representable as a compile-time constant"sv, result_type));
    }

    // Everything from here on can force-build/force-compile arbitrary user code and then run
    // host-backed bytecode -- wrap all of it, not just the run itself, so neither a host
    // exception nor an internal THROW_*_ERROR from a callee's build() escapes the compiler
    // unhandled (CONSTEVAL_CTFE_PLAN.md section 6.5).
    try {
        dependency_walker walker{ env };
        walker.walk(operand.expressions, true);
        if (walker.build_error) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(loc, "consteval: a called function failed to build"sv),
                std::move(walker.build_error)));
        }
        if (walker.has_frame_reference) {
            return std::unexpected(make_error<basic_general_error>(loc,
                "consteval operand references a runtime-only value that does not exist at compile time"sv));
        }

        // section 5.1: materialise every transitively-called non-inline function before running.
        for (internal_function_entity* fe : walker.to_compile) {
            env.compile(*fe);
        }

        // section 5.2: a throwaway, unnamed internal_function_entity purely to reuse
        // environment::compile()'s codegen (append_ret + materialize) for the scratch block.
        // It stays a "provision" (the constructor's default) so the normal end-of-program
        // build-everything/compile-everything traversal (annium_impl::compile) skips it -- we
        // compile and run it ourselves, right here, and its code is accepted as permanent dead
        // bytes in the shared code_ buffer (see the plan's "scratch code region" note).
        //
        // tagged_signatured_entity<resource_location>::equal/hash key off (location, signature)
        // (signatured_entity.hpp), and eregistry_insert rejects a second entity that compares
        // equal to one already registered ("an equivalent entity has been already registered").
        // An empty entity_signature{} is equal to every other empty entity_signature{}, so two
        // scratch entities at the same `loc` -- e.g. the same `consteval` expression sitting
        // inside an `inline fn`, evaluated once per distinct call-site match -- would collide.
        // Giving the signature a fresh qname_identifier as its `name` (which participates in
        // entity_signature equality) makes every scratch entity unique regardless of `loc` reuse.
        auto scratch_fe = make_shared<internal_function_entity>(env, qname{}, entity_signature{ env.new_qname_identifier() }, loc, field_descriptor{});
        env.eregistry_insert(scratch_fe);
        scratch_fe->body = operand.expressions;
        size_t address = env.compile(*scratch_fe);

        vm::context vmctx{ env, env.compile_time_host() };
        size_t init_stack_sz = vmctx.stack_size();
        env.bvm().run(vmctx, address);

        // A void-typed operand (called purely for a side effect, e.g. `consteval print(...)`)
        // leaves nothing on the stack -- not supported, and checked for real here (not just a
        // debug assert) since reading past the end of the stack otherwise would not be caught in
        // a release build.
        if (vmctx.stack_size() != init_stack_sz + 1) {
            return std::unexpected(make_error<basic_general_error>(loc,
                "consteval operand does not produce a value (e.g. a void expression), which is not supported"sv));
        }

        // section 3.6: deep-copy the result unconditionally, before vmctx (and whatever it
        // still owns, e.g. an argument a host call's result might be a view into) is torn down.
        smart_blob result_blob = vmctx.stack_back();
        result_blob.allocate();
        vmctx.stack_pop();

        // CT-representability, the `any` case: the actual blob_type is only known now.
        if (result_blob->type == blob_type::object) {
            return std::unexpected(make_error<basic_general_error>(loc,
                "consteval result is not representable as a compile-time constant"sv));
        }

        // section 5.3
        generic_literal_entity const& result_entity = env.make_generic_entity(std::move(result_blob), result_type);
        return syntax_expression_result{ .value_or_type = result_entity.id, .is_const_result = true };
    } catch (...) {
        return std::unexpected(make_error<basic_general_error>(loc,
            std::string(boost::current_exception_diagnostic_information())));
    }
}

}
