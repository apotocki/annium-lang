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
    expected_result_t expected_result;
    bool enum_union;
};

std::expected<functional_match_descriptor_ptr, error_storage>
union_apply_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();

    auto call_session = call.new_session(ctx);

    // Get union argument
    prepared_call::argument_descriptor_t union_arg_descr;
    auto union_arg = call_session.get_named_argument(env.get(builtin_id::to), expected_result_t{}, &union_arg_descr);
    if (!union_arg) return std::unexpected(std::move(union_arg.error()));

    // Union argument must be a union type
    resource_location const& union_arg_loc = union_arg_descr.expression->location;
    syntax_expression_result& union_arg_er = union_arg->first;
    if (union_arg_er.is_const_result) {
        return std::unexpected(make_error<basic_general_error>(union_arg_loc, "'to' argument must be a runtime value"sv));
    }
    
    entity const& union_entity_type = get_entity(env, union_arg_er.type());
    auto* union_sig = union_entity_type.signature();
    if (!union_sig || union_sig->name != env.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, union_entity_type.id, "a union"sv));
    }

    // Get visitor argument
    prepared_call::argument_descriptor_t visitor_arg_descr;
    auto visitor_arg = call_session.get_named_argument(env.get(builtin_id::visitor), expected_result_t{}, &visitor_arg_descr);
    if (!visitor_arg) return std::unexpected(std::move(visitor_arg.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& visitor_arg_loc = visitor_arg_descr.expression->location;
    syntax_expression_result & visitor_arg_er = visitor_arg->first;

    // if union has only which field?
    bool enum_union = true;
    // to do: optimize, check in reverse order
    for (field_descriptor const& fd : union_sig->fields()) {
        if (!fd.is_const()) {
            enum_union = false;
            break;
        }
    }

    // calculate size of union after unfolding
    size_t unfolded_union_size = 1 + (enum_union ? 0 : 1); // 1 for which + 1 for value if not enum

    auto pmd = make_shared<union_apply_match_descriptor>(call, union_entity_type, enum_union, exp);
    
    // Validate that visitor can be applied to ALL types of the union
    optional<syntax_expression> visitor_arg_expr;
    if (visitor_arg_er.is_const_result) {
        visitor_arg_expr.emplace(visitor_arg_loc, visitor_arg_er.value());
    } else {
        visitor_arg_expr.emplace(visitor_arg_loc, stack_value_reference_expression{ .type = visitor_arg_er.type(), .offset = static_cast<intptr_t>(unfolded_union_size) });
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
            visitor_call_builder.emplace_back(visitor_arg_loc, stack_value_reference_expression{ .type = union_field.entity_id(), .offset = 1 });
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
    
    size_t apply_args_size = 1;
    // Prepare visitor object expression
    if (!visitor_er.is_const_result) {
        append_semantic_result(el, visitor_er, result);
        ++apply_args_size;
    }
    
    // Prepare union value expression
    append_semantic_result(el, union_er, result);
    if (!apply_md.enum_union) {
        env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::unfold) });
        ++apply_args_size;
    } // enum value is the pure 'which' field => no unfold is needed
    
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
        // the result value is on top of stack now, remove apply's arguments under it
        env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = uint16_t(apply_args_size), .keep_back = 1 });
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

    // not a clean code, implicit cast to union type should be done here for each branch result
    for (syntax_expression_result& branch_er : apply_md.branch_results) {
        if (branch_er.is_const_result) {
            if (!apply_md.enum_union) {
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
    if (!apply_md.enum_union) {
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(2) } });
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    }
    // the result value is on top of stack now, remove apply's arguments under it
    env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = uint16_t(apply_args_size), .keep_back = 1 });
    result.value_or_type = env.make_basic_signatured_entity(std::move(usig)).id;
    return result;

#if 0

            // need to cast constant value to union type
            call_builder cast_call{ visitor_loc };
            cast_call.emplace_back(syntax_expression{ visitor_loc, entity_identifier{ branch_er.value() } });
            auto res = ctx.find_and_apply(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{
                .type = entity_identifier{ usig },
                .location = md.call_location,
                .modifier = value_modifier_t::runtime_value
            });
            if (!res) {
                std::ostringstream errss;
                env.print_to(env.print_to(errss << "error casting branch constant result `"sv, branch_er.value()) << "` to union type `"sv, entity_identifier{ usig }) << '`';
                return std::unexpected(append_cause(make_error<basic_general_error>(visitor_loc, errss.str()), std::move(res.error())));
            }
            append_semantic_result_to_branch(el, *res, result, sw.branches.back());
        }
        else {
    for (syntax_expression_result& branch_er : apply_md.branch_results) {
        sw.branches.emplace_back();
        call_builder cast_call{ visitor_loc };
        if (branch_er.is_const_result) {
            cast_call.emplace_back(syntax_expression{ visitor_loc, entity_identifier{ branch_er.value() } });
        } else {
            cast_call.emplace_back(syntax_expression{ visitor_loc, entity_identifier{ branch_er.type() } });
        }
    }

            // all branches are constant results
            apply_md.stable_result_types_set = std::move(apply_md.stable_result_types_set);
            std::sort(apply_md.stable_result_types_set.begin(), apply_md.stable_result_types_set.end());
            apply_md.stable_result_types_set.erase(std::unique(apply_md.stable_result_types_set.begin(), apply_md.stable_result_types_set.end()), apply_md.stable_result_types_set.end());
        }
        // some branches could have constexpr results, we need cast them to runtime values

        }
        for (size_t i = 0; i < apply_md.branch_results.size(); ++i) {
            syntax_expression_result& branch_er = apply_md.branch_results[i];
            env.push_back_expression(el, branch_er.expressions, semantic::truncate_values{ .count = uint16_t(apply_md.enum_union ? 1 : 2), .keep_back = 1 }); // remove unfold union value and 'which' value from stack
            sw.branches.emplace_back();
            append_semantic_result_to_branch(el, branch_er, result, sw.branches.back());
        }
    }
    optional<syntax_expression> visitor_arg_descr;
    if (visitor_er.is_const_result) {
        visitor_arg_descr.emplace(visitor_loc, visitor_er.value());
    } else {
        identifier visitor_var_name = fn_scope.push_scope_variable(visitor_er.type()).first;
        visitor_arg_descr.emplace(visitor_loc, name_reference_expression{ visitor_var_name });
        append_semantic_result(el, visitor_er, result);
        //identifier visitor_var_name = env.new_identifier();
        //visitor_var = &fn_scope.new_temporary(visitor_var_name, visitor_er.type());
        //append_semantic_result(el, result, visitor_er);
        //env.push_back_expression(el, result.expressions, semantic::set_local_variable{ *visitor_var });
        //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 }); // remove visitor value from stack
    }

    // Prepare union value expression
    append_semantic_result(el, union_er, result);

    entity_signature const& union_sig = *apply_md.union_entity_type.signature();
    
    //fn_scope.skip_scope_variables(); // we don't need to keep union argument temporary variables
    if (!enum_union) {
        env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::unfold) });
    } // enum value is the pure 'which' field => no unfold is needed

    // 'which' is on top of stack now
    env.push_back_expression(el, result.expressions, semantic::switch_t{}); // doesn't 'eat' the 'which' value
    semantic::switch_t& sw = get<semantic::switch_t>(result.expressions.back());

    //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 }); // keep only the unfolded union value on stack
    //auto union_value_var_pair = fn_scope.push_scope_variable(entity_identifier{}); // yet unknown type
    //auto which_var_pair = fn_scope.push_scope_variable(env.get(builtin_eid::integer));
    
    // Collect results
#if 0
    boost::container::small_flat_set<entity_identifier, 8> result_elements;
    
    // generate branches for each union type
    small_vector<field_descriptor, 4> branch_results;
    branch_results.reserve(union_sig.field_count());
    for (size_t i = 0; i < union_sig.field_count(); ++i) {
        field_descriptor const& union_field = union_sig.field(i);
        fn_compiler_context_scope fn_scope_inner{ ctx };

        call_builder visitor_call_builder{ visitor_loc };
        if (!union_field.is_const()) {
            // set union_value_var_pair type for this branch
            std::pair<identifier, local_variable> union_value_var_pair = fn_scope_inner.push_scope_variable(union_field.entity_id());
            // scope variable look at union field value
            visitor_call_builder.emplace_back(visitor_loc, name_reference_expression{ union_value_var_pair.first });
        } else {
            visitor_call_builder.emplace_back(visitor_loc, union_field.entity_id());
        }
        syntax_expression visitor_call_expr{ visitor_loc, function_call{ &*visitor_arg_descr, visitor_call_builder.arguments } };
        auto res = base_expression_visitor::visit(ctx, el, visitor_call_expr);

        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(visitor_call_builder.location, ("error calling visitor for union type index %1% (%2%)"_fmt % i % env.print(union_field.entity_id())).str()),
                std::move(res.error())));
        }

        syntax_expression_result& branch = res->first; // visitor call result
        branch_results.emplace_back(branch.value_or_type, branch.is_const_result);
        env.push_back_expression(el, branch.expressions, semantic::truncate_values{ .count = uint16_t(enum_union ? 1 : 2), .keep_back = uint16_t(branch.is_const_result ? 0 : 1) }); // remove unfold union value and 'which' value from stack
        sw.branches.emplace_back();
        append_semantic_result_to_branch(el, branch, result, sw.branches.back());

        // Collect result type for inference if needed
        if (branch.is_const_result) {
            if (result_elements.insert(branch.value()).second) {
                stable_result_values_set.push_back(branch.value());
            }
        } else {
            if (result_elements.insert(branch.type()).second) {
                entity_signature const* psig = get_entity(env, branch.type()).signature();
                if (psig && psig->name == env.get(builtin_qnid::union_)) {
                    for (field_descriptor const& fd : psig->fields()) {
                        if (result_elements.insert(fd.entity_id()).second) {
                            if (fd.is_const()) {
                                stable_result_values_set.push_back(fd.entity_id());
                            } else {
                                stable_result_types_set.push_back(fd.entity_id());
                            }
                        }
                    }
                } else {
                    stable_result_types_set.push_back(branch.type());
                }
            }
        }
    }
#endif

    if (stable_result_types_set.size() == 1 && stable_result_values_set.empty()) {
        // all branches returned the same runtime type
        result.value_or_type = stable_result_types_set.front();
        result.is_const_result = false;
        return result;
    }

    // build union
    entity_signature usig(env.get(builtin_qnid::union_), env.get(builtin_eid::typename_));
    for (entity_identifier const& eid : stable_result_values_set) {
        usig.push_back(field_descriptor{ eid, true });
    }
    for (entity_identifier const& eid : stable_result_types_set) {
        usig.push_back(field_descriptor{ eid, false });
    }

    result.value_or_type = env.make_basic_signatured_entity(std::move(usig)).id;
    result.is_const_result = false;

    // append casts to result union type
    for (size_t i = 0; i < union_sig.field_count(); ++i) {
        field_descriptor const& br = branch_results[i];
        
        call_builder cast_call{ visitor_loc };
        if (!br.is_const()) {
            if (br.entity_id() == result.value_or_type) continue;
            cast_call.emplace_back(syntax_expression{ visitor_loc, stack_value_reference_expression{ .type = br.entity_id(), .offset = 0 } });
        } else {
            cast_call.emplace_back(syntax_expression{ visitor_loc, entity_identifier{ br.entity_id() } });
        }

        auto res = ctx.find_and_apply(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{
            .type = result.value_or_type,
            .location = md.call_location,
            .modifier = value_modifier_t::runtime_value
        });
        if (!res) {
            THROW_INTERNAL_ERROR("unexpected error during union apply cast: %1%"_fmt % env.print(*res.error()));
        }
        append_semantic_result_to_branch(el, *res, result, sw.branches[i]);
        if (!br.is_const()) {
            env.push_back_expression(el, sw.branches[i], semantic::truncate_values{ .count = 1, .keep_back = 1 }); // remove casted value
        }
    }

    return result;
#endif
}

} // namespace annium
