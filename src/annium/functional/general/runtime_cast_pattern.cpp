//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "runtime_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> runtime_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_desc;
    auto arg = call_session.use_next_positioned_argument(expected_result_t{ .type = exp.type, .location = call.location, .modifier = value_modifier_t::runtime_value }, &arg_desc);
    if (!arg) return std::unexpected(arg.error());
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg->first, get<0>(arg_desc)->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> runtime_cast_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    auto & [_, ser, loc] = md.matches.front();

    BOOST_ASSERT(!ser.is_const_result);
    //if (ser.is_const_result) {
    //    ctx.env().push_back_expression(el, ser.expressions, semantic::push_value{ ser.value() });
    //    ser.value_or_type = get_entity(ctx.env(), ser.value()).get_type();
    //    ser.is_const_result = false;
    //}
    return std::move(ser);
}

}
