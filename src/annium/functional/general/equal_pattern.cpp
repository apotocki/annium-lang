//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "equal_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> equal_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t lhs_descr, rhs_descr;
    auto lhs_arg = call_session.use_next_positioned_argument(expected_result_t{}, &lhs_descr);
    if (!lhs_arg) {
        if (lhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(lhs_descr.expression->location, "invalid first argument for equality comparison"sv),
                std::move(lhs_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "equality comparison requires two arguments: missing first argument"sv));
    }
    syntax_expression_result& lhs_arg_er = lhs_arg->first;
    resource_location lhs_loc = lhs_descr.expression->location;
    entity_identifier lhs_type = lhs_arg_er.is_const_result ? get_entity(ctx.env(), lhs_arg_er.value()).get_type() : lhs_arg_er.type();

    auto rhs_arg = call_session.use_next_positioned_argument(expected_result_t{ lhs_type }, &rhs_descr);
    if (!rhs_arg) {
        if (rhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(rhs_descr.expression->location, "invalid second argument for equality comparison"sv),
                std::move(rhs_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "equality comparison requires two arguments: missing second argument"sv));
        }
    }
    resource_location rhs_loc = rhs_descr.expression->location;
    syntax_expression_result& rhs_arg_er = rhs_arg->first;
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "equality comparison accepts exactly two arguments, but more were provided"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(lhs_arg_er, lhs_loc);
    pmd->append_arg(rhs_arg_er, rhs_loc);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> equal_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& [_, lhs_er, lhs_loc] = md.matches.front();
    auto& [__, rhs_er, rhs_loc] = md.matches.back();

    if (lhs_er.is_const_result && rhs_er.is_const_result) {
        return syntax_expression_result{
            .value_or_type = e.make_bool_entity(lhs_er.value() == rhs_er.value()).id,
            .is_const_result = true
        };
    }

    syntax_expression_result result{
        .value_or_type = e.get(builtin_eid::boolean),
        .is_const_result = false
    };

    if (lhs_er.is_const_result) {
        // Get non-const type for the left argument
        entity_identifier lhs_type = get_entity(e, lhs_er.value()).get_type();
        
        // Create implicit cast call instead of direct push_value
        call_builder cast_call{ md.call_location };
        cast_call.emplace_back(lhs_loc, lhs_er.value());

        // Try to find an implicit cast from const value to non-const type
        auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{ .type = lhs_type, .location = lhs_loc, .modifier = value_modifier_t::runtime_value });
        if (!match) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(lhs_loc, "failed to convert left constant value to runtime value for equality comparison"sv),
                std::move(match.error())));
        } else {
            // Apply the implicit cast and use its result
            auto cast_result = match->apply(ctx);
            if (!cast_result) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(lhs_loc, "failed to apply implicit cast for left argument in equality comparison"sv),
                    std::move(cast_result.error())));
            } else {
                result.expressions = el.concat(result.expressions, cast_result->expressions);
                result.temporaries.insert(result.temporaries.end(), cast_result->temporaries.begin(), cast_result->temporaries.end());
            }
        }
    } else {
        append_semantic_result(el, lhs_er, result);
    }
    
    if (rhs_er.is_const_result) {
        // Get non-const type for the right argument
        entity_identifier rhs_type = get_entity(e, rhs_er.value()).get_type();
        
        // Create implicit cast call instead of direct push_value
        call_builder cast_call{ md.call_location };
        cast_call.emplace_back(rhs_loc, rhs_er.value());

        // Try to find an implicit cast from const value to non-const type
        auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{ .type = rhs_type, .location = rhs_loc, .modifier = value_modifier_t::runtime_value });
        if (!match) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(rhs_loc, "failed to convert right constant value to runtime value for equality comparison"sv),
                std::move(match.error())));
        } else {
            // Apply the implicit cast and use its result
            auto cast_result = match->apply(ctx);
            if (!cast_result) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(rhs_loc, "failed to apply implicit cast for right argument in equality comparison"sv),
                    std::move(cast_result.error())));
            } else {
                result.expressions = el.concat(result.expressions, cast_result->expressions);
                result.temporaries.insert(result.temporaries.end(), cast_result->temporaries.begin(), cast_result->temporaries.end());
            }
        }
    } else {
        append_semantic_result(el, rhs_er, result);
    }

    e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::equal)));

    return result;
}

}
