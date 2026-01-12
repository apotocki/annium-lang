//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "string_empty_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage>
string_empty_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();

    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_descr;
    expected_result_t string_exp{
        .type = env.get(builtin_eid::string),
        .modifier = value_modifier_t::constexpr_value
    };
    auto arg = call_session.use_next_positioned_argument(string_exp, &arg_descr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(arg_descr.expression->location, "invalid argument"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing argument"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result& er = arg->first;
    BOOST_ASSERT(er.is_const_result);
    
    entity const& arg_entity = get_entity(env, er.value());
    BOOST_ASSERT(arg_entity.get_type() == env.get(builtin_eid::string));

    auto const* str_literal = dynamic_cast<generic_literal_entity const*>(&arg_entity);
    BOOST_ASSERT(str_literal);

    bool const is_empty = str_literal->value().as<string_view>().empty();

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(er, arg_descr.expression->location);
    pmd->signature.result.emplace(env.make_bool_entity(is_empty).id, true);
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
string_empty_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    BOOST_ASSERT(md.signature.result);
    return syntax_expression_result {
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

} // namespace annium
