//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium/entities/enum/enum_equal_pattern.hpp"
#include "annium/entities/enum/enum_entity.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> enum_equal_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    
    // Get first argument
    prepared_call::argument_descriptor_t lhs_expr;
    auto lhs_arg = call_session.use_next_positioned_argument(expected_result_t{}, &lhs_expr);
    if (!lhs_arg) {
        if (lhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(lhs_expr)->location, "invalid first argument for enum equality comparison"sv),
                std::move(lhs_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "enum equality comparison requires two arguments: missing first argument"sv));
        }
    }

    resource_location const& lhs_loc = get<0>(lhs_expr)->location;
    syntax_expression_result& lhs_arg_er = lhs_arg->first;
    
    // Check if first argument is an enum
    entity_identifier lhs_type = get_result_type(env, lhs_arg_er);
    enum_entity const* lhs_enum = dynamic_cast<enum_entity const*>(&get_entity(env, lhs_type));
    if (!lhs_enum) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_loc, lhs_type, "an enumeration"sv));
    }

    // Get second argument, expecting the same enum type
    prepared_call::argument_descriptor_t rhs_expr;
    auto rhs_arg = call_session.use_next_positioned_argument(expected_result_t{ .type = lhs_type }, &rhs_expr);
    if (!rhs_arg) {
        if (rhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(rhs_expr)->location, "invalid second argument for enum equality comparison"sv),
                std::move(rhs_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "enum equality comparison requires two arguments: missing second argument"sv));
        }
    }

    resource_location const& rhs_loc = get<0>(rhs_expr)->location;
    syntax_expression_result& rhs_arg_er = rhs_arg->first;

    // Check if second argument is also an enum of the same type
    entity_identifier rhs_type = get_result_type(env, rhs_arg_er);
    if (lhs_type != rhs_type) {
        return std::unexpected(make_error<type_mismatch_error>(rhs_loc, rhs_type, ("an enumeration of type %1%"_fmt % env.print(lhs_type)).str()));
    }

    // Check for extra arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "enum equality comparison accepts exactly two arguments, but more were provided"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->emplace_back(0, lhs_arg_er, lhs_loc);
    pmd->emplace_back(1, rhs_arg_er, rhs_loc);
    
    entity_signature& call_sig = pmd->signature;
    call_sig.emplace_back(lhs_arg_er.value_or_type, lhs_arg_er.is_const_result);
    call_sig.emplace_back(rhs_arg_er.value_or_type, rhs_arg_er.is_const_result);
    
    // If both arguments are constexpr and we can evaluate at compile time, or if expected result allows runtime
    if (lhs_arg_er.is_const_result && rhs_arg_er.is_const_result && !can_be_only_runtime(exp.modifier)) {
        // Result will be constexpr bool
        call_sig.result.emplace(env.make_bool_entity(lhs_arg_er.value() == rhs_arg_er.value()).id, true);
    } else {
        // Result will be runtime bool
        call_sig.result.emplace(env.get(builtin_eid::boolean), false);
    }
    
    return pmd;
}

std::expected<syntax_expression_result, error_storage> enum_equal_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& [_, lhs_er, lhs_loc] = md.matches.front();
    auto& [__, rhs_er, rhs_loc] = md.matches.back();

    field_descriptor const& rfd = *md.signature.result;
    syntax_expression_result result{
        .value_or_type = rfd.entity_id(),
        .is_const_result = rfd.is_const()
    };

    if (result.is_const_result) {
        // Both arguments are constexpr - result is already computed and stored in result.value_or_type
        return std::move(result);
    }

    // Runtime comparison
    if (lhs_er.is_const_result) {
        // Convert left constexpr value to runtime
        smart_blob which = dynamic_cast<generic_literal_entity const&>(get_entity(env, lhs_er.value())).value();
        env.push_back_expression(el, result.expressions, semantic::push_value{ which });
    } else {
        append_semantic_result(el, lhs_er, result);
    }
    
    if (rhs_er.is_const_result) {
        // Convert right constexpr value to runtime
        smart_blob which = dynamic_cast<generic_literal_entity const&>(get_entity(env, rhs_er.value())).value();
        env.push_back_expression(el, result.expressions, semantic::push_value{ which });
    } else {
        append_semantic_result(el, rhs_er, result);
    }

    // Use built-in equal function for runtime comparison
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::equal)));

    return std::move(result);
}

}