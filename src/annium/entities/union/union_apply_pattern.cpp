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
    union_apply_match_descriptor(prepared_call const& call, entity const& union_entity) noexcept
        : functional_match_descriptor{ call }
        , union_entity_type{ union_entity }
    {}

    entity const& union_entity_type;
};

std::expected<functional_match_descriptor_ptr, error_storage>
union_apply_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();

    auto call_session = call.new_session(ctx);

    // Get union argument
    prepared_call::argument_descriptor_t union_expr;
    auto union_arg = call_session.use_named_argument(env.get(builtin_id::to), expected_result_t{}, &union_expr);
    if (!union_arg) {
        if (union_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(union_expr)), "error resolving 'to' argument"sv),
                std::move(union_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing 'to' argument"sv));
    }

    // Union argument must be a union type
    resource_location const& union_arg_loc = get_start_location(*get<0>(union_expr));
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
    prepared_call::argument_descriptor_t visitor_expr;
    auto visitor_arg = call_session.use_named_argument(env.get(builtin_id::visitor), expected_result_t{}, &visitor_expr);
    if (!visitor_arg) {
        if (visitor_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(visitor_expr)), "error resolving 'visitor' argument"sv),
                std::move(visitor_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing 'visitor' argument"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& visitor_arg_loc = get_start_location(*get<0>(visitor_expr));
    syntax_expression_result & visitor_arg_er = visitor_arg->first;

    auto pmd = make_shared<union_apply_match_descriptor>(call, union_entity_type);
    pmd->emplace_back(0, union_arg_er, union_arg_loc);
    pmd->emplace_back(1, visitor_arg_er, visitor_arg_loc);
    pmd->signature.emplace_back(env.get(builtin_id::to), union_arg_er.type(), false);
    pmd->signature.emplace_back(env.get(builtin_id::visitor), visitor_arg_er.value_or_type, visitor_arg_er.is_const_result);
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
union_apply_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    union_apply_match_descriptor& apply_md = static_cast<union_apply_match_descriptor&>(md);
    auto& union_er = get<1>(md.matches[0]);
    auto& visitor_er = get<1>(md.matches[1]);

    syntax_expression_result result{ };

    fn_compiler_context_scope fn_scope{ ctx };

    // Prepare visitor object expression
    optional<syntax_expression_t> visitor_expr;
    local_variable* visitor_var = nullptr;
    if (visitor_er.is_const_result) {
        visitor_expr.emplace(annotated_entity_identifier{ visitor_er.value(), get<2>(md.matches[1]) });
    } else {
        identifier visitor_var_name = fn_scope.push_scope_variable(visitor_er.type()).first;
        visitor_expr.emplace(name_reference{ annotated_identifier{ visitor_var_name } });
        append_semantic_result(el, visitor_er, result);
        //identifier visitor_var_name = env.new_identifier();
        //visitor_var = &fn_scope.new_temporary(visitor_var_name, visitor_er.type());
        //append_semantic_result(el, result, visitor_er);
        //env.push_back_expression(el, result.expressions, semantic::set_local_variable{ *visitor_var });
        //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 }); // remove visitor value from stack
    }

    // Prepare union value expression
    append_semantic_result(el, union_er, result);
    //fn_scope.skip_scope_variables(); // we don't need to keep union argument temporary variables
    env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::unfold) });
    //env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 0 }); // keep only the unfolded union value on stack

    auto union_value_var_pair = fn_scope.push_scope_variable(entity_identifier{}); // yet unknown type
    //auto which_var_pair = fn_scope.push_scope_variable(env.get(builtin_eid::integer));

    // 'which' is on top of stack now
    env.push_back_expression(el, result.expressions, semantic::switch_t{}); // doesn't 'eat' the 'which' value
    semantic::switch_t& sw = get<semantic::switch_t>(result.expressions.back());

    // Collect results
    boost::container::small_flat_set<entity_identifier, 8> result_types;
    small_vector<entity_identifier, 16> stable_result_types_set;
    bool all_result_const = true;
    // generate branches for each union type
    entity_signature const& union_sig = *apply_md.union_entity_type.signature();
    for (size_t i = 0; i < union_sig.field_count(); ++i) {
        auto const& union_field = union_sig.field(i);

        function_call_t visitor_call{ get<2>(md.matches[1]), syntax_expression_t{ *visitor_expr } };
        if (!union_field.is_const()) {
            // set union_value_var_pair type for this branch
            union_value_var_pair.second.type = union_field.entity_id();
            visitor_call.emplace_back(name_reference{ annotated_identifier{ union_value_var_pair.first } });
        } else {
            visitor_call.emplace_back(annotated_entity_identifier{ union_field.entity_id() });
        }

        auto res = base_expression_visitor{ ctx, el }(visitor_call);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(visitor_call.location, ("error calling visitor for union type index %1% (%2%)"_fmt % i % env.print(union_field.entity_id())).str()),
                std::move(res.error())));
        }

        syntax_expression_result& branch = res->first; // visitor call result
        env.push_back_expression(el, branch.expressions, semantic::truncate_values{ .count = 2, .keep_back = uint16_t(branch.is_const_result ? 0 : 1) }); // remove unfold union value and 'which' value from stack
        sw.branches.emplace_back();
        append_semantic_result_to_branch(el, branch, result, sw.branches.back());

        // Collect result type for inference if needed
        entity_identifier result_type;
        if (branch.is_const_result) {
            result_type = get_entity(env, branch.value()).get_type();
            THROW_NOT_IMPLEMENTED_ERROR("union apply: can't infer result type if some branches are constant and some are runtime");
        } else {
            result_type = branch.type();
            all_result_const = false;
        }
        if (result_types.insert(result_type).second) {
            stable_result_types_set.push_back(result_type);
        }
    }

    if (stable_result_types_set.size() != 1) {
        THROW_NOT_IMPLEMENTED_ERROR("union apply: can't infer result type if branches return different types");
    }
    result.value_or_type = stable_result_types_set.front();
    result.is_const_result = all_result_const;
    return std::move(result);
}

} // namespace annium
