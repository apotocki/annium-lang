//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_literal_unary_minus_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

namespace {

// Helper function to check if a type is a numeric type
inline bool is_numeric_type(builtin_eid type) noexcept
{
    switch (type) {
    case builtin_eid::boolean:
    case builtin_eid::integer:
    case builtin_eid::decimal:
    case builtin_eid::f16:
    case builtin_eid::f32:
    case builtin_eid::f64:
    case builtin_eid::i8:
    case builtin_eid::u8:
    case builtin_eid::i16:
    case builtin_eid::u16:
    case builtin_eid::i32:
    case builtin_eid::u32:
    case builtin_eid::i64:
    case builtin_eid::u64:
        return true;
    default:
        return false;
    }
}

// Helper function to negate a numeric value at compile time
smart_blob negate_constexpr_numeric(generic_literal_entity const* arg, builtin_eid type)
{
    smart_blob const& value = arg->value();
    
    switch (type) {
    case builtin_eid::boolean: {
        return value; // return the same value
    }
    case builtin_eid::integer: {
        numetron::integer_view val = value.as<numetron::integer_view>();
        return bigint_blob_result(-val);
    }
    case builtin_eid::i8: {
        int8_t val = value.as<int8_t>();
        return i8_blob_result(-val);
    }
    case builtin_eid::u8: {
        uint8_t val = value.as<uint8_t>();
        return ui8_blob_result(-static_cast<int8_t>(val));
    }
    case builtin_eid::i16: {
        int16_t val = value.as<int16_t>();
        return i16_blob_result(-val);
    }
    case builtin_eid::u16: {
        uint16_t val = value.as<uint16_t>();
        return ui16_blob_result(-static_cast<int16_t>(val));
    }
    case builtin_eid::i32: {
        int32_t val = value.as<int32_t>();
        return i32_blob_result(-val);
    }
    case builtin_eid::u32: {
        uint32_t val = value.as<uint32_t>();
        return ui32_blob_result(-static_cast<int32_t>(val));
    }
    case builtin_eid::i64: {
        int64_t val = value.as<int64_t>();
        return i64_blob_result(-val);
    }
    case builtin_eid::u64: {
        uint64_t val = value.as<uint64_t>();
        return ui64_blob_result(-static_cast<int64_t>(val));
    }
    case builtin_eid::decimal: {
        numetron::decimal_view val = value.as<numetron::decimal_view>();
        return decimal_blob_result(-val);
    }
    case builtin_eid::f16: {
        numetron::float16 val = value.as<numetron::float16>();
        return f16_blob_result(-val);
    }
    case builtin_eid::f32: {
        float val = value.as<float>();
        return f32_blob_result(-val);
    }
    case builtin_eid::f64: {
        double val = value.as<double>();
        return f64_blob_result(-val);
    }
    default:
        THROW_NOT_IMPLEMENTED_ERROR("negate_constexpr_numeric: unsupported type"sv);
    }
}

} // anonymous namespace

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_literal_unary_minus_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_expr;
    
    // Get the single argument
    auto arg = call_session.use_next_positioned_argument(exp, &arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                std::move(arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
    }
    
    // Check for unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "argument mismatch"sv, std::move(argterm.value())));
    }
    
    syntax_expression_result& arg_er = arg->first;
    
    // Determine the argument type
    entity const* arg_type_entity = nullptr;
    entity_identifier arg_type_id = get_result_type(env, arg_er, &arg_type_entity);
    
    builtin_eid arg_type = static_cast<builtin_eid>(arg_type_id.value);
    resource_location arg_loc = get_start_location(*get<0>(arg_expr));
    
    // Check if argument is numeric
    if (!is_numeric_type(arg_type)) {
        return std::unexpected(make_error<type_mismatch_error>(arg_loc, arg_type_id, "a numeric type"sv));
    }
    
    // Create match descriptor
    auto pmd = sonia::make_shared<functional_match_descriptor>(call);
    
    pmd->append_arg(arg_er, arg_loc);

    if (arg_er.is_const_result) {
        generic_literal_entity const* arg = dynamic_cast<generic_literal_entity const*>(arg_type_entity);
        smart_blob negated_value = negate_constexpr_numeric(arg, arg_type);
        pmd->signature.result.emplace(env.make_generic_entity(std::move(negated_value), arg_type_id).id, true);
    } else {
        pmd->signature.result.emplace(arg_type_id, false);
    }
    return std::move(pmd);
}

std::expected<syntax_expression_result, error_storage>
numeric_literal_unary_minus_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& res = *md.signature.result;
    if (res.is_const()) {
        return syntax_expression_result{
            .value_or_type = res.entity_id(),
            .is_const_result = true
        };
    }

    environment& env = ctx.env();
    auto& [_, arg_er, arg_loc] = md.matches.front();
    
    // Runtime case - generate runtime negation using semantic::invoke_function
    env.push_back_expression(el, arg_er.expressions, semantic::invoke_function(env.get(builtin_eid::unary_minus)));
    return std::move(arg_er);
}

}
