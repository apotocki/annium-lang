//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "logical_not_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> 
logical_not_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    
    // Expect a boolean argument
    expected_result_t bool_exp{ env.get(builtin_eid::boolean), call.location };
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(bool_exp, &arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(arg_expr)->location, "invalid argument"sv),
                std::move(arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
    }
    
    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "argument mismatch"sv, std::move(argterm.value())));
    }
    
    // Create match descriptor
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg->first, get<0>(arg_expr)->location);
    pmd->signature.result.emplace(env.get(builtin_eid::boolean), arg->first.is_const_result);
    
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
logical_not_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& [_, arg_er, loc] = md.matches.front();
    
    syntax_expression_result result{
        .temporaries = std::move(arg_er.temporaries),
        .branches_expressions = arg_er.branches_expressions,
        .is_const_result = arg_er.is_const_result
    };
    
    // If argument is constant, compute the result at compile time
    if (arg_er.is_const_result) {
        entity_identifier value = arg_er.value();
        bool is_true = (value == e.get(builtin_eid::true_));
        result.value_or_type = is_true ? e.get(builtin_eid::false_) : e.get(builtin_eid::true_);
        return result;
    }
    
    // For non-const values, generate a runtime negate operation
    result.value_or_type = e.get(builtin_eid::boolean);
    result.expressions = el.concat(result.expressions, arg_er.expressions);
    e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::logical_not)));
    
    return result;
}

} // namespace annium
