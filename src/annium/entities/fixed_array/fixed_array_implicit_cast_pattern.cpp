//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "fixed_array_implicit_cast_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.ipp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/cast_error.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> fixed_array_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a vector result"sv));
    }

    environment& env = ctx.env();
    entity const& ent = get_entity(env, exp.type);
    
    entity_signature const* psig = ent.signature();
    if (!psig || psig->name != env.get(builtin_qnid::vector)) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a vector"sv));
    }
    entity_identifier vec_element_type_eid = psig->find_field(env.get(builtin_id::of))->entity_id();

    auto call_session = call.new_session(ctx);
    std::pair<syntax_expression_t const*, size_t> arg_expr;
    auto arg = call_session.use_next_positioned_argument(&arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                std::move(arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& argloc = get_start_location(*get<0>(arg_expr));
    syntax_expression_result& er = arg->first;
    entity_identifier argtype = er.is_const_result ? get_entity(env, er.value()).get_type() : er.type();
    entity const& argtype_ent = get_entity(env, argtype);
    entity_signature const* type_sig = argtype_ent.signature();
    if (!type_sig || type_sig->name != env.get(builtin_qnid::array)) {
        return std::unexpected(make_error<type_mismatch_error>(argloc, argtype, "an array type"sv));
    }
    entity_identifier arr_element_type_eid = type_sig->find_field(env.get(builtin_id::of))->entity_id();

    if (arr_element_type_eid != vec_element_type_eid) {
        if (er.is_const_result) {
            value_modifier_t arg_mod = can_be_only_runtime(exp.modifier) ? value_modifier_t::runtime_value : value_modifier_t::constexpr_value;
            entity_signature const* array_data = get_entity(env, er.value()).signature();
            BOOST_ASSERT(array_data && array_data->name == env.get(builtin_qnid::data));
            
            alt_error cast_errors;
            semantic::managed_expression_list temp_expressions{ env };
            entity_signature res_vec_sig{ ctx.env().get(builtin_qnid::data), exp.type };

            if (!can_be_only_runtime(exp.modifier)) { // try to do constexpr casts and result
                for (field_descriptor const& fd : array_data->fields()) {
                    pure_call_t cast_call{ call.location };
                    cast_call.emplace_back(annotated_entity_identifier{ fd.entity_id(), argloc });
                    auto res = ctx.find_and_apply(builtin_qnid::implicit_cast, cast_call, temp_expressions,
                        expected_result_t{ .type = vec_element_type_eid, .location = exp.location, .modifier = value_modifier_t::constexpr_value });
                    if (!res) {
                        error_storage err = append_cause(
                            make_error<basic_general_error>(call.location, "cannot cast constexpr array type to constexpr vector type because element types are not compatible"sv, fd.entity_id()),
                            std::move(res.error()));
                        if (can_be_only_constexpr(exp.modifier)) return std::unexpected(std::move(err));
                        cast_errors.alternatives.emplace_back(std::move(err));
                        break;
                    }
                    res_vec_sig.emplace_back(res->value(), true);
                }
                if (cast_errors.alternatives.empty()) {
                    auto pmd = make_shared<functional_match_descriptor>();
                    pmd->emplace_back(0, er, argloc);
                    pmd->signature.emplace_back(er.value(), true);
                    pmd->signature.result.emplace(env.make_basic_signatured_entity(std::move(res_vec_sig)).id, true);
                    return pmd;
                }
            }
            // try runtime casts
            // check if each element can be casted to vector element type
            for (field_descriptor const& fd : array_data->fields()) {
                pure_call_t cast_call{ call.location };
                cast_call.emplace_back(annotated_entity_identifier{ fd.entity_id(), argloc });
                auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, temp_expressions,
                    expected_result_t{ .type = vec_element_type_eid, .location = exp.location, .modifier = value_modifier_t::runtime_value });
                if (!match) {
                    error_storage err = append_cause(
                        make_error<basic_general_error>(call.location, "cannot cast constexpr array type to runtime vector type because element types are not compatible"sv, fd.entity_id()),
                        std::move(match.error()));
                    if (cast_errors.alternatives.empty()) {
                        return std::unexpected(std::move(err));
                    }
                    cast_errors.alternatives.emplace_back(std::move(err));
                    return std::unexpected(make_error<alt_error>(std::move(cast_errors)));
                }
            }
            auto pmd = make_shared<functional_match_descriptor>();
            pmd->emplace_back(0, er, argloc);
            pmd->signature.emplace_back(er.value(), true);
            pmd->signature.result.emplace(exp.type, false);
            return pmd;
        }

        // check if element cast exists
        pure_call_t cast_call{ call.location };
        semantic::managed_expression_list temp_expressions{ env };
        // fake stack value reference for the array element
        cast_call.emplace_back(stack_value_reference{ .name = annotated_identifier{.location = argloc }, .type = arr_element_type_eid, .offset = 0 });
        auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, temp_expressions,
            expected_result_t{ .type = vec_element_type_eid, .location = exp.location, .modifier = value_modifier_t::runtime_value });
        if (!match) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "cannot cast runtime array type to runtime vector type because element types are not compatible"sv),
                match.error()));
        }
    }

    auto pmd = make_shared<functional_match_descriptor>();
    pmd->emplace_back(0, er, argloc);
    pmd->signature.emplace_back(er.value_or_type, er.is_const_result);
    pmd->signature.result.emplace(exp.type);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> fixed_array_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& [_, er, argloc] = md.matches.front();
    
    syntax_expression_result result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = md.signature.result->is_const()
    };
    
    if (result.is_const_result) return result;

    // Get array element types
    entity_identifier argtype = er.is_const_result ? get_entity(env, er.value()).get_type() : er.type();
    entity const& argtype_ent = get_entity(env, argtype);
    entity_signature const* arr_sig = argtype_ent.signature();
    entity_identifier arr_element_type_eid = arr_sig->find_field(env.get(builtin_id::of))->entity_id();

    // Get array size from the type signature
    field_descriptor const* pszd = arr_sig->find_field(env.get(builtin_id::size));
    BOOST_ASSERT(pszd);
    size_t array_size = static_cast<generic_literal_entity const&>(get_entity(env, pszd->entity_id())).value().as<size_t>();

    // Get vector element types
    entity const& result_ent = get_entity(env, md.signature.result->entity_id());
    entity_signature const* vec_sig = result_ent.signature();
    entity_identifier vec_element_type_eid = vec_sig->find_field(env.get(builtin_id::of))->entity_id();
    
    BOOST_ASSERT(!er.is_const_result); // for now, array argument should not be const

    // Add the array argument expressions to result
    append_semantic_result(el, result, er);

    if (arr_element_type_eid == vec_element_type_eid) {
        BOOST_ASSERT(array_size > 0);
        // no need to cast elements, just return with vector type
        if (array_size == 1) {
            env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(1) } });
            env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::arrayify) });
            return result;
        }
        return result;
    }

    // First unfold the array to get individual elements on the stack
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::unfold)));

    //fn_compiler_context_scope fn_scope{ ctx };
    
    for (size_t i = 0; i < array_size; ++i) {
        //identifier element_var_name = fn_scope.push_scope_variable(arr_element_type_eid).first;
    
        function_call_t cast_call{ md.call_location, qname_reference{} };
        cast_call.emplace_back(stack_value_reference{ .name = annotated_identifier{}, .type = arr_element_type_eid, .offset = array_size - 1 }); // we put on stack also the result of the cast => offset is const
        base_expression_visitor bev{ ctx, el, expected_result_t{ .type = vec_element_type_eid, .modifier = value_modifier_t::runtime_value } };
        auto res = bev(builtin_qnid::implicit_cast, cast_call);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<cast_error>(argloc, arr_element_type_eid, vec_element_type_eid, "internal error: cannot cast array element to vector element type"sv),
                std::move(res.error())));
        }
        append_semantic_result(el, result, res->first);
    }

    // Push the element count and invoke arrayify to create the vector
    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(array_size) } });
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    
    // remove unfolded array from stack
    BOOST_ASSERT(array_size <= (std::numeric_limits<decltype(semantic::truncate_values::count)>::max)());
    env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = static_cast<uint16_t>(array_size), .keep_back = 1 });

    return result;
}

}
