//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "any_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> any_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type || !can_be_runtime(exp.modifier)) {
        if (exp.type) {
            return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "a runtime result"sv));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "expected a runtime result"sv));
        }
    }
    auto call_session = call.new_session(ctx);

    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::runtime_value });
    if (!arg_descr) return std::unexpected(arg_descr.error());

    syntax_expression_result& arg_er = arg_descr->result;
    if (arg_er.type() != ctx.env().get(builtin_eid::any)) {
        return std::unexpected(make_error<type_mismatch_error>(arg_descr->expression->location, arg_er.type(), "runtime any"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
    pmd->signature.result.emplace(exp.type, false);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> any_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    auto [_, ser, loc] = md.matches.front();
    ser.value_or_type = md.signature.result->entity_id();
    ser.is_const_result = false;
    return ser;
}

}
