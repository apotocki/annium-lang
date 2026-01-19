//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "internal_fn_pattern.hpp"

#include "annium/environment.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/circular_dependency_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

error_storage internal_fn_pattern::init(fn_compiler_context& ctx, fn_decl const& fnd)
{
    body_ = fnd.body;
    kind_ = fnd.kind;
    return basic_fn_pattern::init(ctx, fnd);
    // if (auto err = init(ctx, static_cast<fn_pure const&>(fnd))) return err;
}

std::expected<functional_match_descriptor_ptr, error_storage> internal_fn_pattern::try_match(fn_compiler_context& caller_ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto res = basic_fn_pattern::try_match(caller_ctx, call, exp);
    if (!res || !has(kind_, fn_kind::VIABLE)) return res;

    // check if vaible
    functional_match_descriptor& md = **res;

    indirect_internal_function_entity smpl{ md.signature, location };

    environment& env = caller_ctx.env();

    internal_function_entity& fne = static_cast<internal_function_entity&>(env.eregistry_find_or_create(smpl, [this, &caller_ctx, &md]() {
        return build(caller_ctx, entity_signature{ md.signature }, md.bindings.to_basic_functional_binding());
    }));

    sonia::lang::compiler_task_tracer::task_guard tg = caller_ctx.try_lock_task(entity_task_id{ fne });
    if (!tg) return std::unexpected(
        make_error<circular_dependency_error>(make_error<basic_general_error>(location, "function build failed"sv, fne.id))
    );
    if (fne.is_built()) return res; // already checked for vailability
    if (fne.build_errors || (fne.build_errors = fne.build(env))) {
        fne.set_provision(true); // this definition will be used as a provision only
        return std::unexpected(append_cause(
            make_error<basic_general_error>(location, "function build failed"sv, fne.id),
            std::move(fne.build_errors)
        ));
    }

    return res;
}

shared_ptr<internal_function_entity> internal_fn_pattern::build(fn_compiler_context& ctx, entity_signature&& signature, basic_functional_binding&& bindings) const
{
    auto res = basic_fn_pattern::build(ctx, std::move(signature), std::move(bindings));
    res->set_body(body_);
    res->set_inline(has(kind_, fn_kind::INLINE));
    res->set_provision(false);
    return res;
}

void internal_fn_pattern::build_scope(environment& e, basic_functional_binding&& bindings, internal_function_entity& fent) const
{
    // setup captures
    if (captures_) {
        entity_signature const* psig = captures_->signature();
        BOOST_ASSERT(psig);
        span<const field_descriptor> fields = psig->fields().subspan(1); // skip 'this'
        // calculate runtime size of captures
        size_t rt_size = std::ranges::count_if(fields, [](field_descriptor const& fd) { return !fd.is_const(); });
        fent.set_captured_var_count(rt_size);
        int64_t capture_var_offset = -static_cast<int64_t>(rt_size);
        for (field_descriptor const& fd : fields) {
            if (!fd.is_const()) {
                fent.push_capture(e, fd.name(), fd.entity_id(), capture_var_offset++);
            }
        }
        // to do: for multivalued names bound constexpr vector of captures
    }
    basic_fn_pattern::build_scope(e, std::move(bindings), fent);
}

std::expected<syntax_expression_result, error_storage> internal_fn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto [result, mut_arg_cnt] = apply_arguments(ctx, el, md);

    indirect_internal_function_entity smpl{ md.signature, location };

    internal_function_entity& fne = static_cast<internal_function_entity&>(env.eregistry_find_or_create(smpl, [this, &ctx, &md]() {
        return build(ctx, std::move(md.signature), md.bindings.to_basic_functional_binding());
    }));

    // we need to build the function if:
    if (!fne.result || // result type is not yet resolved
        // the function has no runtime arguments and not zero count constexpr arguments (to check if result is constexpr too)
        ((!fne.is_built() && !mut_arg_cnt && fne.result.entity_id() != env.get(builtin_eid::void_type) &&
            fne.result.entity_id() != env.get(builtin_eid::void_)) && md.matches.size()))
    {

        sonia::lang::compiler_task_tracer::task_guard tg = ctx.try_lock_task(entity_task_id{ fne });
        if (!tg) return std::unexpected(
            make_error<circular_dependency_error>(make_error<basic_general_error>(location, "resolving function result type"sv, fne.id))
        );
        if (!fne.is_built()) {
            if (auto err = fne.build(env)) {
                return std::unexpected(std::move(err));
            }
        }

        BOOST_ASSERT(fne.result);
    }

    result.value_or_type = fne.result.entity_id();
    result.is_const_result = fne.result.is_const();

    if (mut_arg_cnt || !fne.is_const_eval(env)) {
        env.push_back_expression(el, result.expressions, semantic::invoke_function(fne.id));
    }

    return result;
}

}
