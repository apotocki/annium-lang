//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "array_from_iterator_make_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> array_from_iterator_make_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);

    // Try to get the optional 'of' parameter first
    prepared_call::argument_descriptor_t from_iterator_arg_descr;
    auto from_iterator_res = call_session.use_named_argument(env.get(builtin_id::from_iterator), expected_result_t{ .modifier = value_modifier_t::runtime_value }, &from_iterator_arg_descr);
    
    if (!from_iterator_res) {
        if (from_iterator_res.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(from_iterator_arg_descr)), "invalid 'from_iterator' argument"sv),
                std::move(from_iterator_res.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required 'from_iterator' argument"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->emplace_back(0, from_iterator_res->first, get_start_location(*get<0>(from_iterator_arg_descr)));
    pmd->signature.emplace_back(from_iterator_res->first.value_or_type, from_iterator_res->first.is_const_result);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> array_from_iterator_make_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& [_, er, loc] = md.matches.front();
    
    syntax_expression_result result{ .is_const_result = false };

    // Result - array with unknown size, element type will be determined from next()
    // For now we don't know the element type, will be determined later
    
    // Add iterator expressions to result
    append_semantic_result(el, er, result);
    // iterator value is on top of the stack now
    
    fn_compiler_context_scope fn_scope{ ctx };

    // Create variable for iterator
    identifier iterator_var_name = env.new_identifier();
    local_variable iterator_var = fn_scope.new_temporary(iterator_var_name, er.type());
    
    env.push_back_expression(el, result.expressions, semantic::set_local_variable(iterator_var));
    env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 });

    identifier stack_size_var_name = env.new_identifier();
    local_variable stack_size_var = fn_scope.new_temporary(stack_size_var_name, env.get(builtin_eid::integer));
    

    // put current stack size on top of the stack to track number of elements added
    env.push_back_expression(el, result.expressions, semantic::push_special_value{ semantic::push_special_value::kind_type::stack_size });
    env.push_back_expression(el, result.expressions, semantic::set_local_variable(stack_size_var));
    env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 });
    // Start loop to collect elements
    env.push_back_expression(el, result.expressions, semantic::loop_scope_t{});
    semantic::loop_scope_t& ls = get<semantic::loop_scope_t>(result.expressions.back());

    // Check has_next(iterator)
    pure_call_t has_next_call{ loc };
    has_next_call.emplace_back(name_reference{ annotated_identifier{ iterator_var_name, loc } });
    
    auto has_next_result = ctx.find_and_apply(builtin_qnid::has_next, has_next_call, el,
        expected_result_t{ env.get(builtin_eid::boolean), loc });
    if (!has_next_result) {
        return std::unexpected(append_cause( 
            make_error<basic_general_error>(loc, "Cannot invoke has_next function for the iterator"sv),
            std::move(has_next_result.error())));
    }

    env.push_back_expression(el, has_next_result->expressions, semantic::conditional_t{});
    semantic::conditional_t& cond = get<semantic::conditional_t>(has_next_result->expressions.back());

    // finalize loop branch
    append_semantic_result_to_branch(el, *has_next_result, result, ls.branch);

    // True branch:
    syntax_expression_result true_branch_res{ .is_const_result = false };

    // Call next(iterator)
    pure_call_t next_call{ loc };
    next_call.emplace_back(name_reference{ annotated_identifier{ iterator_var_name, loc }});
    
    auto next_result = ctx.find_and_apply(builtin_qnid::next, next_call, el);
    if (!next_result) {
        return std::unexpected(append_cause( 
            make_error<basic_general_error>(loc, "Cannot invoke next function for the iterator"sv),
            std::move(next_result.error())));
    }
    
    // First call to next determines array element type
    if (!result.value_or_type) {
        auto elemtype = get_result_type(env, *next_result);
        result.value_or_type = env.make_array_type_entity(elemtype).id;
    }
    
    // remove has_next result from stack
    env.push_back_expression(el, true_branch_res.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 });

    // push next_result to stack
    append_semantic_result(el, *next_result, true_branch_res);

    // Continue loop
    env.push_back_expression(el, true_branch_res.expressions, semantic::loop_continuer{});

    // finalize true branch
    append_semantic_result_to_branch(el, true_branch_res, result, cond.true_branch);

    
    // False branch:
    syntax_expression_result false_branch_res{ .is_const_result = false };

    // remove has_next result from stack
    env.push_back_expression(el, false_branch_res.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 });

    // We have all elements on the stack
    // Need to count them and create array using arrayify
    
    // put current stack size on top of the stack to track number of elements added
    env.push_back_expression(el, false_branch_res.expressions, semantic::push_special_value{ semantic::push_special_value::kind_type::stack_size });
    env.push_back_expression(el, false_branch_res.expressions, semantic::push_local_variable{ stack_size_var });
    env.push_back_expression(el, false_branch_res.expressions, semantic::invoke_function(env.get(builtin_eid::isubtract)));
    //env.push_back_expression(el, false_branch_res.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(1) } }); // subtract 2 (because we have two stack size variables on stack)
    //env.push_back_expression(el, false_branch_res.expressions, semantic::invoke_function(env.get(builtin_eid::isubtract)));
    env.push_back_expression(el, false_branch_res.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));

    // remove initial stack size and iterator variables
    //env.push_back_expression(el, true_branch_res.expressions, semantic::truncate_values{ .count = 2, .keep_back = 1 });

    // break the loop
    // env.push_back_expression(el, false_branch_res.expressions, semantic::loop_breaker{});
    
    // finalize false branch
    append_semantic_result_to_branch(el, false_branch_res, result, cond.false_branch);
    
    result.temporaries.emplace_back(iterator_var_name, std::move(iterator_var), semantic::expression_span{});
    result.temporaries.emplace_back(stack_size_var_name, std::move(stack_size_var), semantic::expression_span{});

    return result;
}

}
