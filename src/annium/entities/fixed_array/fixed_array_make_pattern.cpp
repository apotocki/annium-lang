//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "fixed_array_make_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class fixed_array_make_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    entity_identifier element_type;
    bool has_explicit_type;  // true if 'of' parameter was provided
    bool all_const; // true if all elements are const
    bool all_runtime; // true if all elements are runtime
    bool need_cast; // true if some elements need cast to element_type
};

std::expected<functional_match_descriptor_ptr, error_storage> fixed_array_make_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    auto pmd = make_shared<fixed_array_make_match_descriptor>(call);

    // Try to get the optional 'of' parameter first
    prepared_call::argument_descriptor_t of_arg_descr;
    auto of_res = call_session.use_named_argument(e.get(builtin_id::of), 
        expected_result_t{ .type = e.get(builtin_eid::typename_), .modifier = value_modifier_t::constexpr_value }, &of_arg_descr);
    
    if (of_res) {
        // Explicit type specified
        auto& of_arg = of_res->first;
        // Check that it's a valid type
        entity const& etype = get_entity(e, of_arg.value());
        if (etype.get_type() != e.get(builtin_eid::typename_)) {
            return std::unexpected(make_error<type_mismatch_error>(of_arg_descr.expression->location, of_arg.value(), "a type"sv));
        }
        pmd->element_type = of_arg.value();
        pmd->has_explicit_type = true;
        pmd->emplace_back(0, of_arg, of_arg_descr.expression->location);
    } else if (of_res.error()) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(of_arg_descr.expression->location, "invalid 'of' argument"sv),
            std::move(of_res.error())));
    } else {
        // No explicit type, will be inferred from elements
        pmd->has_explicit_type = false;
    }

    // Collect element arguments
    boost::container::small_flat_set<entity_identifier, 8> elements;
    entity_signature usig(e.get(builtin_qnid::union_), e.get(builtin_eid::typename_));
    pmd->all_const = true;
    pmd->all_runtime = true;
    expected_result_t exp_element_res{ .type = pmd->element_type, .modifier = exp.modifier };
    // Get all positioned arguments (the array elements)
    for (size_t arg_num = 0;; ++arg_num) {
        prepared_call::argument_descriptor_t elem_descr;
        auto elem_res = call_session.use_next_positioned_argument(exp_element_res, &elem_descr);
        if (!elem_res) {
            if (elem_res.error()) 
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(elem_descr.expression->location, "invalid argument"sv),
                    std::move(elem_res.error())));
            break;
        }
        auto& ser = elem_res->first;

        if (!pmd->has_explicit_type) {
            entity_identifier etype;
            if (ser.is_const_result) {
                etype = get_entity(e, ser.value()).get_type();
                pmd->all_runtime = false;
            } else {
                etype = ser.type();
                pmd->all_const = false;
            }
        
            if (elements.insert(etype).second) {
                usig.push_back(field_descriptor{ etype, false });
            }
        } else if (ser.is_const_result) {
            pmd->all_runtime = false;
        } else {
            pmd->all_const = false;
        }

        pmd->append_arg(ser, elem_descr.expression->location);
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    // If no explicit type, infer from elements
    if (!pmd->has_explicit_type) {
        if (elements.empty()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "cannot infer array element type from empty argument list"sv));
        }
        pmd->need_cast = usig.fields().size() > 1;
        pmd->element_type = !pmd->need_cast ?
            usig.fields().front().entity_id() :
            e.make_basic_signatured_entity(std::move(usig)).id;
    } else {
        pmd->need_cast = false;
    }

    if (pmd->matches.empty()) { // will consider empty array as a constexpr value
        pmd->all_runtime = false;
    }

#if 0
    entity_identifier array_type_id = e.make_array_type_entity(pmd->element_type, element_count).id;
    if (pmd->all_const) {
        auto mspan = span{ pmd->matches };
        if (pmd->has_explicit_type) {
            // Skip the 'of' parameter
            mspan = mspan.subspan(1);
        }

        entity_signature data_sig{ e.get(builtin_qnid::data), array_type_id };
        for (auto& [arg_idx, mr, loc] : mspan) {
            data_sig.emplace_back(mr.value(), true);
        }
        entity_identifier const_array_id = e.make_basic_signatured_entity(std::move(data_sig)).id;
        pmd->signature.result.emplace(const_array_id, true);
    } else {
        // If not all elements are const, the array type is not const
        pmd->signature.result.emplace(array_type_id, false);
    }
#endif
    return pmd;
}

std::expected<syntax_expression_result, error_storage> fixed_array_make_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& amd = static_cast<fixed_array_make_match_descriptor&>(md);
    
    syntax_expression_result result{ .is_const_result = amd.all_const };

    entity_identifier array_type_id = env.make_array_type_entity(amd.element_type, amd.matches.size()).id;

    if (amd.all_const) {
        if (!amd.need_cast) {
            entity_signature array_data{ env.get(builtin_qnid::data), array_type_id };
            for (auto& [_, er, loc] : amd.matches) {
                array_data.emplace_back(er.value(), true);
            }
            result.value_or_type = env.make_basic_signatured_entity(std::move(array_data)).id;
            return result;
        }
        // to do: make a literal array entity
        // but for now, create runtime array
        result.is_const_result = false;
    }
    
    result.value_or_type = array_type_id;
    if (amd.all_runtime && !amd.need_cast) {
        for (auto& [_, er, loc] : amd.matches) {
            append_semantic_result(el, er, result);
        }
    } else {
        // Mixed const and runtime elements, need to cast to runtime element type
        for (auto& [_, er, loc] : amd.matches) {
            if (!er.is_const_result && er.type() == amd.element_type) {
                append_semantic_result(el, er, result);
                continue;
            }
            call_builder cast_call{ loc };
            if (er.is_const_result) {
                cast_call.emplace_back(loc, er.value());
            } else {
                cast_call.emplace_back(make_indirect_value(env, el, std::move(er), loc));
            }
            auto res = ctx.find_and_apply(builtin_qnid::implicit_cast, cast_call, el,
                expected_result_t{ .type = amd.element_type, .location = loc, .modifier = value_modifier_t::runtime_value });
            if (!res) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(loc, "cannot cast array element to the specified element type"sv),
                    res.error()));
            }
            append_semantic_result(el, *res, result);
        }
    }
    if (amd.matches.size() > 1) {
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(amd.matches.size()) } });
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    }

    return result;
}

}
