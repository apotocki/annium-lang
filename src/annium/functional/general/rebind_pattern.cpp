//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "rebind_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> rebind_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    // First pass: resolve self as an ordinary runtime value, purely to learn its OWN declared
    // type. self must already be some ref(of: T) -- rebind repoints an EXISTING reference, it
    // doesn't manufacture one from a plain T.
    auto self_peek = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::runtime_value }, "self"sv);
    if (!self_peek) return std::unexpected(std::move(self_peek.error()));
    size_t const self_arg_index = self_peek->arg_index;
    resource_location const self_loc = self_peek->expression->location;
    entity_identifier self_type = get_result_type(e, self_peek->result);
    entity_identifier target_type = try_decompose_ref_of(e, self_type); // T, if self already IS ref(of: T)
    if (!target_type) {
        return std::unexpected(make_error<type_mismatch_error>(self_loc, self_type, "a ref(of: T) variable (self must already be a reference to rebind it)"sv));
    }

    // Second pass: re-resolve self, this time prescribing the OUTER type ref(of: ref(of: T))
    // explicitly. This is what makes base_expression_visitor::try_take_reference take its
    // caller-prescribed-exact-type path (expected_result.type given, decomposed of_type == vartype
    // exactly) instead of the modifier-only path plain ref(x) uses -- that path deliberately
    // declines to double-wrap a variable that's already a reference (see FUTURE_WORK.md's `ref(T)`
    // item 4 and base_expression_visitor.cpp's try_take_reference). rebind's whole point is
    // reaching that OUTER slot (self's own storage), not whatever it currently points at, so it
    // deliberately routes around that decline via the other path instead. The first, now-discarded
    // resolution is a dead, unspliced expression_list_t span -- safe to abandon (see
    // IMPLEMENTATION_NOTES.md's `ref(T)` section, "A discarded resolution attempt..."), not a
    // soundness risk. Same re-resolve-with-a-prescribed-type technique equal_pattern.cpp already
    // uses (prepared_call::session::reuse_argument).
    call_session.reuse_argument(self_arg_index);
    entity_identifier outer_ref_type = make_ref_of_type(e, self_type);
    auto self_descr = call_session.get_next_positioned_argument(expected_result_t{ .type = outer_ref_type, .modifier = value_modifier_t::runtime_value }, "self"sv);
    if (!self_descr) {
        // Most likely cause: self isn't a plain, addressable local variable/parameter (an arbitrary
        // expression, a weak variable, ...) -- try_take_reference only ever fires for one.
        return std::unexpected(make_error<type_mismatch_error>(self_loc, self_type, "a plain variable (rebind's target must be addressable)"sv));
    }

    // value: the new ref(of: T) to install -- always runtime, exact type, no coercion (the same
    // rule set()'s value carries, just one level further out: ref(T) never implicitly casts).
    auto value_descr = call_session.get_next_positioned_argument(expected_result_t{ .type = self_type, .modifier = value_modifier_t::runtime_value }, "value"sv);
    if (!value_descr) return std::unexpected(std::move(value_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(self_descr->result, self_descr->expression->location);
    pmd->append_arg(value_descr->result, value_descr->expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> rebind_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& [_, self_er, self_loc] = md.matches.front();
    auto& [__, value_er, value_loc] = md.matches.back();

    // self_er is the OUTER ref(of: ref(of: T)); the call's own result is the (inner) ref(of: T)
    // just written -- annium_ref_rebind overwrites the outer slot's own bytes but leaves the
    // freshly-written value behind as its return, matching print()'s declared shape.
    entity_identifier result_type = try_decompose_ref_of(e, get_result_type(e, self_er));
    syntax_expression_result result{ .value_or_type = result_type, .is_const_result = false };
    append_semantic_result(el, self_er, result);
    append_semantic_result(el, value_er, result);
    e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::ref_rebind)));
    return result;
}

}
