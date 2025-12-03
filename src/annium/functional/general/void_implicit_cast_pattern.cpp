//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "void_implicit_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> void_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type || exp.type != ctx.env().get(builtin_eid::void_type) || !can_be_constexpr(exp.modifier)) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a void result"sv));
    }
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_desc;
    auto arg = call_session.use_next_positioned_argument(&arg_desc);
    if (!arg) return std::unexpected(arg.error());
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg->first, get<0>(arg_desc)->location);
    pmd->signature.result.emplace(ctx.env().get(builtin_eid::void_), true);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> void_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    syntax_expression_result result{
        .value_or_type = ctx.env().get(builtin_eid::void_),
        .is_const_result = true
    };
    size_t rtval_count = 0;
    for (auto & [_, ser, loc] : md.matches) {
        if (ser.is_const_result) continue;
        append_semantic_result(el, ser, result);
        ++rtval_count;
    }
    if (rtval_count) {
        ctx.env().push_back_expression(el, result.expressions, semantic::truncate_values{ .count = static_cast<uint16_t>(rtval_count) });
    }

    return result;
}

}
