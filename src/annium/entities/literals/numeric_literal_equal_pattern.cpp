//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_literal_equal_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

class numeric_literal_equal_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    numeric_literal_equal_match_descriptor(prepared_call const& call, generic_literal_entity const* lhs_arg, generic_literal_entity const* rhs_arg) noexcept
        : functional_match_descriptor{ call }
        , lhs_arg{ lhs_arg }
        , rhs_arg{ rhs_arg }
    {}

    generic_literal_entity const* lhs_arg = nullptr; // nullptr for runtime arguments
    generic_literal_entity const* rhs_arg = nullptr; // nullptr for runtime arguments
};

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

// Helper function to compare two constexpr numeric values
template <typename T>
requires(std::is_floating_point_v<T> || std::is_same_v<numetron::float16, T> || std::is_same_v<numetron::decimal_view, T>)
bool compare_constexpr_values(T const& lhs_val, T const& rhs_val)
{
    if constexpr (std::is_same_v<T, T>) {
        return lhs_val == rhs_val;
    } else if constexpr (std::is_same_v<T, bool> && std::is_arithmetic_v<T>) {
        return (lhs_val ? 1 : 0) == rhs_val;
    } else if constexpr (std::is_arithmetic_v<T> && std::is_same_v<T, bool>) {
        return lhs_val == (rhs_val ? 1 : 0);
    } else if constexpr (std::is_same_v<T, numetron::integer_view> && std::is_arithmetic_v<T>) {
        if constexpr (std::is_floating_point_v<T>) {
            return static_cast<double>(lhs_val) == static_cast<double>(rhs_val);
        } else {
            return lhs_val == static_cast<int64_t>(rhs_val);
        }
    } else if constexpr (std::is_arithmetic_v<T> && std::is_same_v<T, numetron::integer_view>) {
        if constexpr (std::is_floating_point_v<T>) {
            return static_cast<double>(lhs_val) == static_cast<double>(rhs_val);
        } else {
            return static_cast<int64_t>(lhs_val) == rhs_val;
        }
    } else if constexpr (std::is_same_v<T, numetron::decimal_view> || std::is_same_v<T, numetron::decimal_view>) {
        // For decimal comparisons, convert both to decimal
        numetron::decimal lhs_decimal, rhs_decimal;
        
        if constexpr (std::is_same_v<T, numetron::decimal_view>) {
            lhs_decimal = numetron::decimal{ lhs_val };
        } else if constexpr (std::is_same_v<T, numetron::integer_view>) {
            lhs_decimal = numetron::decimal{ lhs_val };
        } else {
            lhs_decimal = numetron::decimal{ std::to_string(lhs_val) };
        }
        
        if constexpr (std::is_same_v<T, numetron::decimal_view>) {
            rhs_decimal = numetron::decimal{ rhs_val };
        } else if constexpr (std::is_same_v<T, numetron::integer_view>) {
            rhs_decimal = numetron::decimal{ rhs_val };
        } else {
            rhs_decimal = numetron::decimal{ std::to_string(rhs_val) };
        }
        
        return lhs_decimal == rhs_decimal;
    } else {
        // General arithmetic comparison
        return static_cast<double>(lhs_val) == static_cast<double>(rhs_val);
    }
}

// Helper function to extract and compare constexpr values based on their types
bool compare_constexpr_literal_values(generic_literal_entity const* lhs_entity, generic_literal_entity const* rhs_entity, 
                                      builtin_eid lhs_type, builtin_eid rhs_type)
{
    smart_blob const& lhs_value = lhs_entity->value();
    smart_blob const& rhs_value = rhs_entity->value();
    
    // Simple approach: convert both values to double and compare
    double lhs_val = 0.0;
    double rhs_val = 0.0;
    
    // Extract left value
    switch (lhs_type) {
        case builtin_eid::boolean:
            lhs_val = lhs_value.as<bool>() ? 1.0 : 0.0;
            break;
        case builtin_eid::integer:
        case builtin_eid::i8:
        case builtin_eid::u8:
        case builtin_eid::i16:
        case builtin_eid::u16:
        case builtin_eid::i32:
        case builtin_eid::u32:
        case builtin_eid::i64:
        case builtin_eid::u64:
            // All integer types are stored as integer_view
            lhs_val = static_cast<double>(lhs_value.as<numetron::integer_view>());
            break;
        case builtin_eid::f16:
            // f16 might be stored as integer_view
            lhs_val = lhs_value.as<double>();
            break;
        case builtin_eid::f32:
            lhs_val = static_cast<double>(lhs_value.as<float>());
            break;
        case builtin_eid::f64:
            lhs_val = lhs_value.as<double>();
            break;
        case builtin_eid::decimal: {
            numetron::decimal_view dv = lhs_value.as<numetron::decimal_view>();
            lhs_val = static_cast<double>(dv);
            break;
        }
        default:
            return false;
    }
    
    // Extract right value
    switch (rhs_type) {
        case builtin_eid::boolean:
            rhs_val = rhs_value.as<bool>() ? 1.0 : 0.0;
            break;
        case builtin_eid::integer:
        case builtin_eid::i8:
        case builtin_eid::u8:
        case builtin_eid::i16:
        case builtin_eid::u16:
        case builtin_eid::i32:
        case builtin_eid::u32:
        case builtin_eid::i64:
        case builtin_eid::u64:
            // All integer types are stored as integer_view
            rhs_val = static_cast<double>(rhs_value.as<numetron::integer_view>());
            break;
        case builtin_eid::f16:
            // f16 might be stored as integer_view
            rhs_val = static_cast<double>(rhs_value.as<numetron::integer_view>());
            break;
        case builtin_eid::f32:
            rhs_val = static_cast<double>(rhs_value.as<float>());
            break;
        case builtin_eid::f64:
            rhs_val = rhs_value.as<double>();
            break;
        case builtin_eid::decimal: {
            numetron::decimal_view dv = rhs_value.as<numetron::decimal_view>();
            rhs_val = static_cast<double>(dv);
            break;
        }
        default:
            return false;
    }
    
    return lhs_val == rhs_val;
}

} // anonymous namespace

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_literal_equal_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();

    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t lhs_expr, rhs_expr;
    
    // Get first argument
    auto lhs_arg = call_session.use_next_positioned_argument(&lhs_expr);
    if (!lhs_arg) {
        if (lhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(lhs_expr)), "invalid first argument"sv),
                std::move(lhs_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required first argument"sv));
        }
    }

    syntax_expression_result & lhs_arg_er = lhs_arg->first;
    
    entity_identifier lhs_type_id;
    entity const* lhs_type_entity = nullptr;
    if (lhs_arg_er.is_const_result) {
        lhs_type_entity = &get_entity(e, lhs_arg_er.value());
        lhs_type_id = lhs_type_entity->get_type();
    } else {
        lhs_type_id = lhs_arg_er.type();
    }
    builtin_eid lhs_type = static_cast<builtin_eid>(lhs_type_id.value);
    resource_location lhs_arg_loc = get_start_location(*get<0>(lhs_expr));
    // Check if first argument is numeric
    if (!is_numeric_type(lhs_type)) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_arg_loc, lhs_type_id, "a numeric literal type"sv));
    }

    // Get second argument
    auto rhs_arg = call_session.use_next_positioned_argument(expected_result_t{}, &rhs_expr);
    if (!rhs_arg) {
        if (rhs_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(rhs_expr)), "invalid second argument"sv),
                std::move(rhs_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required second argument"sv));
        }
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result & rhs_arg_er = rhs_arg->first;
    
    entity_identifier rhs_type_id;
    entity const* rhs_type_entity = nullptr;
    if (rhs_arg_er.is_const_result) {
        rhs_type_entity = &get_entity(e, rhs_arg_er.value());
        rhs_type_id = rhs_type_entity->get_type();
    } else {
        rhs_type_id = rhs_arg_er.type();
    }
    builtin_eid rhs_type = static_cast<builtin_eid>(rhs_type_id.value);
    resource_location rhs_arg_loc = get_start_location(*get<0>(rhs_expr));

    // Check if second argument is numeric
    if (!is_numeric_type(rhs_type)) {
        return std::unexpected(make_error<type_mismatch_error>(rhs_arg_loc, rhs_type_id, "a numeric literal type"sv));
    }

    // Create match descriptor
    generic_literal_entity const* lhs_literal = lhs_arg_er.is_const_result ? 
        dynamic_cast<generic_literal_entity const*>(lhs_type_entity) : nullptr;
    generic_literal_entity const* rhs_literal = rhs_arg_er.is_const_result ? 
        dynamic_cast<generic_literal_entity const*>(rhs_type_entity) : nullptr;

    auto pmd = sonia::make_shared<numeric_literal_equal_match_descriptor>(call, lhs_literal, rhs_literal);
    
    // Set up signature
    pmd->signature.emplace_back(lhs_arg_er.value_or_type, lhs_arg_er.is_const_result);
    pmd->signature.emplace_back(rhs_arg_er.value_or_type, rhs_arg_er.is_const_result);
    
    // Result is boolean, constexpr if both arguments are constexpr
    bool is_constexpr_result = lhs_arg_er.is_const_result && rhs_arg_er.is_const_result;
    if (!is_constexpr_result) {
        pmd->signature.result.emplace(e.get(builtin_eid::boolean), false);
    }
    
    pmd->emplace_back(0, lhs_arg_er, lhs_arg_loc);
    pmd->emplace_back(1, rhs_arg_er, rhs_arg_loc);
    
    return std::move(pmd);
}

std::expected<syntax_expression_result, error_storage>
numeric_literal_equal_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& nmd = static_cast<numeric_literal_equal_match_descriptor&>(md);
    auto& [_, lhs_src, lhs_loc] = md.matches[0];
    auto& [__, rhs_src, rhs_loc] = md.matches[1];
    
    environment& e = ctx.env();
    bool is_constexpr_result = nmd.lhs_arg && nmd.rhs_arg;
    
    if (is_constexpr_result) {
        // Both arguments are constexpr - compute result at compile time
        builtin_eid lhs_type = static_cast<builtin_eid>(nmd.lhs_arg->get_type().value);
        builtin_eid rhs_type = static_cast<builtin_eid>(nmd.rhs_arg->get_type().value);
        
        bool comparison_result = compare_constexpr_literal_values(nmd.lhs_arg, nmd.rhs_arg, lhs_type, rhs_type);
        
        return syntax_expression_result{
            .value_or_type = e.make_bool_entity(comparison_result).id,
            .is_const_result = true
        };
    } else {
        // At least one argument is runtime - generate runtime comparison
        syntax_expression_result result{
            .value_or_type = e.get(builtin_eid::boolean),
            .is_const_result = false
        };

        // Handle left argument
        if (lhs_src.is_const_result) {
            // Convert constexpr to runtime value
            e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ nmd.lhs_arg->value() } });
        } else {
            // Use runtime value
            append_semantic_result(el, result, lhs_src);
        }

        // Handle right argument
        if (rhs_src.is_const_result) {
            // Convert constexpr to runtime value
            e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ nmd.rhs_arg->value() } });
        } else {
            // Use runtime value
            append_semantic_result(el, result, rhs_src);
        }

        // Generate runtime equality check
        e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::equal)));

        return std::move(result);
    }
}

} // namespace annium