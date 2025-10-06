//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "fixed_array_get_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class fixed_array_get_match_descriptor : public functional_match_descriptor
{
public:
    inline fixed_array_get_match_descriptor(prepared_call const& call, entity_signature const& arr_type_sig_val) noexcept
        : functional_match_descriptor{ call }
        , arr_type_sig{ arr_type_sig_val }
    {
    }

    entity_signature const& arr_type_sig;
};

std::expected<functional_match_descriptor_ptr, error_storage> fixed_array_get_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t slf_arg_expr;
    auto slf_arg = call_session.use_named_argument(env.get(builtin_id::self), expected_result_t{}, &slf_arg_expr);
    if (!slf_arg) {
        if (slf_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(slf_arg_expr)), "invalid `self` argument"sv),
                std::move(slf_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `self`"sv));
    }

    resource_location const& slfargloc = get_start_location(*get<0>(slf_arg_expr));
    syntax_expression_result& slf_arg_er = slf_arg->first;
    entity_identifier slftype = get_result_type(env, slf_arg_er);
    
    entity const& slf_type_entity = get_entity(env, slftype);
    entity_signature const* psig = slf_type_entity.signature();
    if (!psig || psig->name != env.get(builtin_qnid::array)) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slftype, "an array"sv));
    }

    prepared_call::argument_descriptor_t prop_arg;
    auto property_arg = call_session.use_named_argument(env.get(builtin_id::property), expected_result_t{ env.get(builtin_eid::integer) }, &prop_arg);
    if (!property_arg) {
        if (property_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(prop_arg)), "invalid `property` argument"sv),
                std::move(property_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `property`"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& propargloc = get_start_location(*get<0>(prop_arg));

    shared_ptr<fixed_array_get_match_descriptor> pmd = make_shared<fixed_array_get_match_descriptor>(call, *psig);
    
    pmd->emplace_back(0, slf_arg_er, slfargloc);
    pmd->emplace_back(1, property_arg->first, propargloc);
    
    entity_signature& call_sig = pmd->signature;
    call_sig.emplace_back(env.get(builtin_id::self), slf_arg_er.value_or_type, slf_arg_er.is_const_result);
    call_sig.emplace_back(env.get(builtin_id::property), property_arg->first.value_or_type, property_arg->first.is_const_result);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> fixed_array_get_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& amd = static_cast<fixed_array_get_match_descriptor&>(md);
    auto& slfer = get<1>(md.matches[0]);
    auto& proper = get<1>(md.matches[1]);

    entity_signature const& sig = amd.arr_type_sig;
    field_descriptor const* of_fd = sig.find_field(env.get(builtin_id::of));
    BOOST_ASSERT(of_fd);
    field_descriptor const* size_fd = sig.find_field(env.get(builtin_id::size));
    size_t array_size = (std::numeric_limits<size_t>::max)();
    if (size_fd) {
        generic_literal_entity const& sz_ent = static_cast<generic_literal_entity const&>(get_entity(env, size_fd->entity_id()));
        array_size = sz_ent.value().as<size_t>();
    }

    optional<size_t> index;
    if (proper.is_const_result) {
        generic_literal_entity const& index_ent = static_cast<generic_literal_entity const&>(get_entity(env, proper.value()));
        index.emplace(index_ent.value().as<size_t>());
        if (*index >= array_size) {
            return std::unexpected(make_error<basic_general_error>(amd.call_location, "array index out of range"sv, proper.value()));
        }
    }

    entity_signature const* datasig = nullptr;
    if (slfer.is_const_result) {
        entity const& slf_data_entity = get_entity(env, slfer.value());
        datasig = slf_data_entity.signature();
        BOOST_ASSERT(datasig && datasig->name == env.get(builtin_qnid::data));
        BOOST_ASSERT(datasig->fields().size() == array_size);
    }

    // Case 1: Both self and property are constant
    if (slfer.is_const_result && proper.is_const_result) {
        return syntax_expression_result{
            .temporaries = {},
            .expressions = {},
            .value_or_type = datasig->field(*index).entity_id(),
            .is_const_result = true
        };
    }
    // Case 2: self is not constant, property is constant
    if (!slfer.is_const_result && proper.is_const_result) {
        syntax_expression_result result{ 
            .value_or_type = of_fd->entity_id(),
            .is_const_result = false
        };
        append_semantic_result(el, slfer, result);

        if (array_size > 1) {
            env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(*index) } });
            env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::array_at)));
        }

        return result;
    }

    // Case 4: Both self and property are not constant
    if (!slfer.is_const_result && !proper.is_const_result) {
        syntax_expression_result result = slfer;
        if (array_size > 1) {
            append_semantic_result(el, proper, result);
            // Add runtime array access
            env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::array_at)));
        }
        result.value_or_type = of_fd->entity_id();
        return std::move(result);
    }

    THROW_NOT_IMPLEMENTED_ERROR("fixed_array_get_pattern::apply");
#if 0

    // Case 3: self is constant, property is not constant
    if (slfer.is_const_result && !proper.is_const_result) {
        // The array structure is known, but the index is dynamic.
        // The result type is always the element type.
        
        // Merge expressions
        semantic::expression_span exprs = el.concat(slfer.expressions, proper.expressions);
        
        // Add runtime array access
        e.push_back_expression(el, exprs, semantic::invoke_function(e.get(builtin_eid::array_at)));
        
        return syntax_expression_result{
            .temporaries = std::move(slfer.temporaries),
            .expressions = std::move(exprs),
            .value_or_type = element_type,
            .is_const_result = false
        };
    }

    // Case 4: Both self and property are not constant
    BOOST_ASSERT(!slfer.is_const_result && !proper.is_const_result);
        
    // Both array and index are dynamic
        
        // Merge expressions
        semantic::expression_span exprs = el.concat(slfer.expressions, proper.expressions);
        
        // Add runtime array access
        e.push_back_expression(el, exprs, semantic::invoke_function(e.get(builtin_eid::array_at)));
        
        return syntax_expression_result{
            .temporaries = std::move(slfer.temporaries),
            .expressions = std::move(exprs),
            .value_or_type = element_type,
            .is_const_result = false
        };
#endif
}

}