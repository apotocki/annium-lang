//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "union_apply_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

#include "sonia/utility/scope_exit.hpp"

namespace annium {

class union_apply_match_descriptor : public functional_match_descriptor
{
public:
    inline union_apply_match_descriptor(prepared_call const& call, entity const& union_entity, bool enum_union_val, expected_result_t exp) noexcept
        : functional_match_descriptor{ call }
        , union_entity_type{ union_entity }
        , expected_result{ std::move(exp) }
        , enum_union{ enum_union_val }
    {}

    entity const& union_entity_type;
    small_vector<entity_identifier, 4> stable_result_types_set;
    small_vector<entity_identifier, 4> stable_result_values_set;
    small_vector<syntax_expression_result, 4> branch_results;
    local_variable visitor_var, union_value_var;
    expected_result_t expected_result;
    bool enum_union;
};

std::expected<functional_match_descriptor_ptr, error_storage>
union_apply_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();

    auto call_session = call.new_session(ctx);

    // Get union argument
    auto union_arg_descr = call_session.get_named_argument(builtin_id::to);
    if (!union_arg_descr) return std::unexpected(std::move(union_arg_descr.error()));

    // Union argument must be a union type
    resource_location const& union_arg_loc = union_arg_descr->expression->location;
    syntax_expression_result& union_arg_er = union_arg_descr->result;
    if (union_arg_er.is_const_result) {
        return std::unexpected(make_error<basic_general_error>(union_arg_loc, "'to' argument must be a runtime value"sv));
    }
    
    entity const& union_entity_type = get_entity(env, union_arg_er.type());
    auto* union_sig = union_entity_type.signature();
    if (!union_sig || union_sig->name != env.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, union_entity_type.id, "a union"sv));
    }

    // Get visitor argument
    auto visitor_arg_descr = call_session.get_named_argument(builtin_id::visitor);
    if (!visitor_arg_descr) return std::unexpected(std::move(visitor_arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& visitor_arg_loc = visitor_arg_descr->expression->location;
    syntax_expression_result & visitor_arg_er = visitor_arg_descr->result;

    // if union has only which field?
    bool enum_union = true;
    // TODO: optimize, check in reverse order
    for (field_descriptor const& fd : union_sig->fields()) {
        if (!fd.is_const()) {
            enum_union = false;
            break;
        }
    }

    auto pmd = make_shared<union_apply_match_descriptor>(call, union_entity_type, enum_union, exp);
    
    // Validate that visitor can be applied to ALL types of the union
    optional<syntax_expression> visitor_arg_expr;
    if (visitor_arg_er.is_const_result) {
        visitor_arg_expr.emplace(visitor_arg_loc, visitor_arg_er.value());
    } else {
        pmd->visitor_var = local_variable{ .type = visitor_arg_er.type(), .varid = env.new_variable_identifier() };
        visitor_arg_expr.emplace(visitor_arg_loc, local_variable_expression::from_var(pmd->visitor_var));
    }
    
    // Collect results
    boost::container::small_flat_set<entity_identifier, 8> result_elements;

    // Probe each union member
    for (size_t i = 0; i < union_sig->field_count(); ++i) {
        auto const& union_field = union_sig->field(i);

        call_builder visitor_call_builder{ visitor_arg_loc };
        if (!union_field.is_const()) {
            // Provide a placeholder runtime argument of the proper type
            // union 'which' will be on top of stack, value will be under it
            if (!pmd->union_value_var.type) {
                // create new variable
                pmd->union_value_var = local_variable{ .type = union_field.entity_id(), .varid = env.new_variable_identifier() };
            } else {
                // or fix type of existing one
                pmd->union_value_var.type = union_field.entity_id();
            }
            
            visitor_call_builder.emplace_back(visitor_arg_loc, local_variable_expression::from_var(pmd->union_value_var));
        } else {
            // Provide a constant typed argument
            visitor_call_builder.emplace_back(visitor_arg_loc, union_field.entity_id());
        }
            
        syntax_expression visitor_call_expr{ visitor_arg_loc, function_call{ &*visitor_arg_expr, visitor_call_builder.arguments } };
        auto res = base_expression_visitor::visit(ctx, call.expressions, exp, visitor_call_expr);
           
        if (!res) {
            std::ostringstream errss;
            env.print_to(env.print_to(errss << "error calling visitor for "sv, union_field.entity_id()) << " of "sv, union_entity_type.id);
            return std::unexpected(append_cause(make_error<basic_general_error>(visitor_arg_loc, errss.str()), std::move(res.error())));
        }

        syntax_expression_result& branch_er = res->first; // visitor call result
        if (branch_er.is_const_result) {
            if (result_elements.insert(branch_er.value()).second) {
                pmd->stable_result_values_set.push_back(branch_er.value());
            }
        } else {
            if (result_elements.insert(branch_er.type()).second) {
                // do not decompose union result types
#if 0
                entity_signature const* psig = get_entity(env, branch_er.type()).signature();
                if (psig && psig->name == env.get(builtin_qnid::union_)) {
                    for (field_descriptor const& fd : psig->fields()) {
                        if (result_elements.insert(fd.entity_id()).second) {
                            if (fd.is_const()) {
                                pmd->stable_result_values_set.push_back(fd.entity_id());
                            } else {
                                pmd->stable_result_types_set.push_back(fd.entity_id());
                            }
                        }
                    }
                } else {
                    pmd->stable_result_types_set.push_back(branch_er.type());
                }
#endif
                pmd->stable_result_types_set.push_back(branch_er.type());
            }
        }
        pmd->branch_results.emplace_back(std::move(branch_er));
    }
    
    if (!exp.type && pmd->stable_result_types_set.size() == 1 && pmd->stable_result_values_set.empty()) {
        // all branches return the same runtime type
        pmd->expected_result = expected_result_t { .type = pmd->stable_result_types_set.front(), .modifier = value_modifier_t::runtime_value };
    }

    pmd->append_arg(env.get(builtin_id::to), union_arg_er, union_arg_loc);
    pmd->append_arg(env.get(builtin_id::visitor), visitor_arg_er, visitor_arg_loc);

    return pmd;
}

std::expected<syntax_expression_result, error_storage>
union_apply_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    union_apply_match_descriptor& apply_md = static_cast<union_apply_match_descriptor&>(md);
    
    // special case
    if (apply_md.stable_result_types_set.empty() && apply_md.stable_result_values_set.size() == 1) {
        // all branches returned the same constant value
        return syntax_expression_result{
            .value_or_type = apply_md.stable_result_values_set.front(),
            .is_const_result = true
        };
    }
    
    auto& union_er = get<1>(md.matches[0]);
    auto& visitor_er = get<1>(md.matches[1]);
    resource_location visitor_loc = get<2>(md.matches[1]);

    syntax_expression_result result{ .is_const_result = false };
    
    // Prepare visitor object expression
    if (!visitor_er.is_const_result) {
        semantic::expression_span vis_expr = std::move(visitor_er.expressions);
        visitor_er.expressions = {};
        append_semantic_result(el, visitor_er, result);
        result.temporaries.emplace_back(apply_md.visitor_var, std::move(vis_expr));
    }
    
    // Prepare union value expression
    append_semantic_result(el, union_er, result);
    if (!apply_md.enum_union) {
        env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::unfold) });
        
        BOOST_ASSERT(apply_md.union_value_var.type);
        result.temporaries.emplace_back(apply_md.union_value_var, semantic::expression_span{});
        env.push_back_expression(el, result.expressions, semantic::push_by_offset{ .offset = 1, .base = semantic::push_by_base::stack_top });
        env.push_back_expression(el, result.expressions, semantic::set_local_variable::create(apply_md.union_value_var)); // copy union value from stack to local variable for later use in branches
        env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 }); // remove copy of union value from stack
        env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 1 }); // remove original union value from stack
    } // else enum value is the pure 'which' field => no unfold is needed
    
    // 'which' is on top of stack now
    env.push_back_expression(el, result.expressions, semantic::switch_t{}); // doesn't 'eat' the 'which' value
    semantic::switch_t& sw = get<semantic::switch_t>(result.expressions.back());
    
    // do we need to cast result of each branch to expected result type?
    if (apply_md.expected_result.type) {
        // some branches could have constexpr results, we need cast them to runtime values
        for (syntax_expression_result& branch_er : apply_md.branch_results) {
            if (branch_er.is_const_result) {
                call_builder cast_call{ visitor_loc };
                cast_call.emplace_back(syntax_expression{ visitor_loc, entity_identifier{ branch_er.value() } });
                auto res = ctx.find_and_apply(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{
                    .type = apply_md.expected_result.type,
                    .location = md.call_location,
                    .modifier = value_modifier_t::runtime_value
                });
                if (!res) {
                    std::ostringstream errss;
                    env.print_to(env.print_to(errss << "error casting branch result `"sv, branch_er.value()) << "` to runtime type `"sv, apply_md.expected_result.type) << '`';
                    return std::unexpected(append_cause(make_error<basic_general_error>(visitor_loc, errss.str()), std::move(res.error())));
                }
                sw.branches.emplace_back(res->expressions);
                append_branch_semantic_result(el, *res, result);
            } else {
                sw.branches.emplace_back(branch_er.expressions);
                append_branch_semantic_result(el, branch_er, result);
            }
        }
        // the result value is on top of stack now, remove 'which' under it
        env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 1 });
        //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = uint16_t(apply_vars_cnt), .keep_back = 1 });
        result.value_or_type = apply_md.expected_result.type;
        return result;
    }

    // no expected result type, just collect all branch results and build union result type
    entity_signature usig(env.get(builtin_qnid::union_), env.get(builtin_eid::typename_));
    for (entity_identifier const& eid : apply_md.stable_result_values_set) {
        usig.push_back(field_descriptor{ eid, true });
    }
    for (entity_identifier const& eid : apply_md.stable_result_types_set) {
        usig.push_back(field_descriptor{ eid, false });
    }
    bool is_result_enum_union = apply_md.stable_result_types_set.empty();
    // not a clean code, implicit cast to union type should be done here for each branch result
    for (syntax_expression_result& branch_er : apply_md.branch_results) {
        if (branch_er.is_const_result) {
            if (!is_result_enum_union) {
                // append null as dummy runtime value for const union element
                env.push_back_expression(el, branch_er.expressions, semantic::push_value{ smart_blob{} });
            }
        }
        // find union 'which' value
        auto it = std::ranges::find_if(usig.fields(), [&branch_er](field_descriptor const& fd) {
            return fd.entity_id() == branch_er.value_or_type && fd.is_const() == branch_er.is_const_result;
        });
        BOOST_ASSERT(it != usig.fields().end());
        size_t which_index = std::distance(usig.fields().begin(), it);

        // append result union 'which' value
        env.push_back_expression(el, branch_er.expressions, semantic::push_value{ ui64_blob_result(which_index) });

        sw.branches.emplace_back(branch_er.expressions);
        append_branch_semantic_result(el, branch_er, result);
    }
    
    // fold union result
    if (!is_result_enum_union) {
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(2) } });
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    }
    // the result value is on top of stack now, remove 'which' under it
    env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 1 });
    //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = uint16_t(apply_vars_cnt), .keep_back = 1 });
    result.value_or_type = env.make_basic_signatured_entity(std::move(usig)).id;
    return result;
}

} // namespace annium
