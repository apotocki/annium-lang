//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "is_struct_pattern.hpp"
#include "struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> is_struct_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    
    // Get the type argument
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t{}, &arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(arg_expr)->location, "invalid argument for is_struct"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "is_struct requires one argument"sv));
    }

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "is_struct accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg->first;
    resource_location arg_loc = get<0>(arg_expr)->location;

    // Create match descriptor
    auto pmd = make_shared<functional_match_descriptor>(call);

    // Check if the argument is a struct_entity or a typename referring to a struct_entity
    struct_entity const* arg_as_struct;
    entity const* arg_entity;
    entity_identifier arg_type = get_result_type(env, arg_er, &arg_entity);
    if (arg_type == env.get(builtin_eid::typename_)) {
        arg_as_struct = arg_er.is_const_result ? dynamic_cast<struct_entity const*>(arg_entity) : nullptr;
    } else {
        arg_as_struct = dynamic_cast<struct_entity const*>(&get_entity(env, arg_type));
    }
    pmd->signature.result.emplace(env.get(arg_as_struct ? builtin_eid::true_ : builtin_eid::false_), true);

    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    return pmd;
}

std::expected<syntax_expression_result, error_storage> is_struct_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    return syntax_expression_result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

}
