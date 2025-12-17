//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_literal_implicit_cast_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

class numeric_literal_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    numeric_literal_implicit_cast_match_descriptor(prepared_call const& call, generic_literal_entity const* arg) noexcept
        : functional_match_descriptor{ call }
        , arg{ arg }
    {}

    generic_literal_entity const* arg = nullptr; // nullptr for runtime arguments
};

// Helper function to check if runtime conversion from source to target is always safe (no precision loss possible)
bool is_always_safe_runtime_conversion(builtin_eid source_type, builtin_eid target_type)
{
    if (source_type == target_type) return true;
    
    // Conversions that are always safe for runtime values
    switch (source_type) {
        case builtin_eid::boolean:
            return target_type == builtin_eid::i8 || target_type == builtin_eid::u8 ||
                   target_type == builtin_eid::i16 || target_type == builtin_eid::u16 ||
                   target_type == builtin_eid::i32 || target_type == builtin_eid::u32 ||
                   target_type == builtin_eid::i64 || target_type == builtin_eid::u64 ||
                   target_type == builtin_eid::f16 || target_type == builtin_eid::f32 ||
                   target_type == builtin_eid::f64 || target_type == builtin_eid::integer ||
                   target_type == builtin_eid::decimal;
        case builtin_eid::i8:
            return target_type == builtin_eid::i16 || target_type == builtin_eid::i32 ||
                   target_type == builtin_eid::i64 || target_type == builtin_eid::f16 ||
                   target_type == builtin_eid::f32 || target_type == builtin_eid::f64 ||
                   target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::u8:
            return target_type == builtin_eid::i16 || target_type == builtin_eid::u16 ||
                   target_type == builtin_eid::i32 || target_type == builtin_eid::u32 ||
                   target_type == builtin_eid::i64 || target_type == builtin_eid::u64 ||
                   target_type == builtin_eid::f16 || target_type == builtin_eid::f32 ||
                   target_type == builtin_eid::f64 || target_type == builtin_eid::integer ||
                   target_type == builtin_eid::decimal;
        case builtin_eid::i16:
            return target_type == builtin_eid::i32 || target_type == builtin_eid::i64 ||
                   target_type == builtin_eid::f32 || target_type == builtin_eid::f64 ||
                   target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::u16:
            return target_type == builtin_eid::i32 || target_type == builtin_eid::u32 ||
                   target_type == builtin_eid::i64 || target_type == builtin_eid::u64 ||
                   target_type == builtin_eid::f32 || target_type == builtin_eid::f64 ||
                   target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::i32:
            return target_type == builtin_eid::i64 || target_type == builtin_eid::f64 ||
                   target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::u32:
            return target_type == builtin_eid::i64 || target_type == builtin_eid::u64 ||
                   target_type == builtin_eid::f64 || target_type == builtin_eid::integer ||
                   target_type == builtin_eid::decimal;
        case builtin_eid::i64:
            return target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::u64:
            return target_type == builtin_eid::integer || target_type == builtin_eid::decimal;
        case builtin_eid::f16:
            return target_type == builtin_eid::f32 || target_type == builtin_eid::f64 ||
                   target_type == builtin_eid::decimal;
        case builtin_eid::f32:
            return target_type == builtin_eid::f64 || target_type == builtin_eid::decimal;
        case builtin_eid::f64:
            return target_type == builtin_eid::decimal;
        case builtin_eid::integer:
            return target_type == builtin_eid::decimal;
        case builtin_eid::decimal:
            return false; // decimal can't be safely converted to anything else at runtime
        default:
            return false;
    }
}

// Helper function to check if constexpr value can be converted without precision loss
template<typename SourceValue>
bool can_convert_constexpr_value_safely(SourceValue const& source_val, builtin_eid source_type, builtin_eid target_type)
{
    if (source_type == target_type) return true;
    
    if constexpr (std::is_same_v<SourceValue, bool>) {
        // bool can be converted to any numeric type
        return true;
    } else if constexpr (std::is_same_v<SourceValue, numetron::integer_view>) {
        // Check if integer value fits in target type
        switch (target_type) {
            case builtin_eid::i8:
                return source_val.template is_fit<int8_t>();
            case builtin_eid::u8:
                return source_val.template is_fit<uint8_t>() && source_val.sgn() >= 0;
            case builtin_eid::i16:
                return source_val.template is_fit<int16_t>();
            case builtin_eid::u16:
                return source_val.template is_fit<uint16_t>() && source_val.sgn() >= 0;
            case builtin_eid::i32:
                return source_val.template is_fit<int32_t>();
            case builtin_eid::u32:
                return source_val.template is_fit<uint32_t>() && source_val.sgn() >= 0;
            case builtin_eid::i64:
                return source_val.template is_fit<int64_t>();
            case builtin_eid::u64:
                return source_val.template is_fit<uint64_t>() && source_val.sgn() >= 0;
            case builtin_eid::f16:
            case builtin_eid::f32:
            case builtin_eid::f64:
            case builtin_eid::integer:
            case builtin_eid::decimal:
                return true; // integers can always be converted to floats and decimal
            default:
                return false;
        }
    } else if constexpr (std::is_same_v<SourceValue, numetron::decimal_view>) {
        // Check if decimal value can be converted
        switch (target_type) {
            case builtin_eid::i8:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<int8_t>();
            case builtin_eid::u8:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<uint8_t>() && !source_val.is_negative();
            case builtin_eid::i16:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<int16_t>();
            case builtin_eid::u16:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<uint16_t>() && !source_val.is_negative();
            case builtin_eid::i32:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<int32_t>();
            case builtin_eid::u32:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<uint32_t>() && !source_val.is_negative();
            case builtin_eid::i64:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<int64_t>();
            case builtin_eid::u64:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return source_val.significand().template is_fit<uint64_t>() && !source_val.is_negative();
            case builtin_eid::f16:
            case builtin_eid::f32:
            case builtin_eid::f64:
            case builtin_eid::integer:
            case builtin_eid::decimal:
                return true; // decimal can always be converted to floats and decimal/integer
            default:
                return false;
        }
    }
    
    return false;
}

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_literal_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();

    if (exp.type &&
        exp.type != e.get(builtin_eid::integer) &&
        exp.type != e.get(builtin_eid::decimal) &&
        exp.type != e.get(builtin_eid::f16) &&
        exp.type != e.get(builtin_eid::f32) &&
        exp.type != e.get(builtin_eid::f64) &&
        exp.type != e.get(builtin_eid::boolean) &&
        exp.type != e.get(builtin_eid::i8) &&
        exp.type != e.get(builtin_eid::u8) &&
        exp.type != e.get(builtin_eid::i16) &&
        exp.type != e.get(builtin_eid::u16) &&
        exp.type != e.get(builtin_eid::i32) &&
        exp.type != e.get(builtin_eid::u32) &&
        exp.type != e.get(builtin_eid::i64) &&
        exp.type != e.get(builtin_eid::u64))
    {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "a literal type"sv));
    }
    builtin_eid target_type = static_cast<builtin_eid>(exp.type.value);

    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_descr;
    value_modifier_t arg_mod = can_be_only_constexpr(exp.modifier) ? value_modifier_t::constexpr_value : value_modifier_t::constexpr_or_runtime_value;
    auto src_arg = call_session.use_next_positioned_argument(expected_result_t{ .modifier = arg_mod }, &arg_descr);
    if (!src_arg) {
        if (src_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(arg_descr.expression->location, "invalid argument"sv),
                std::move(src_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result & src_arg_er = src_arg->first;
    
    entity_identifier source_type_id;
    entity const* source_type_entity = nullptr;
    if (src_arg_er.is_const_result) {
        source_type_entity = &get_entity(e, src_arg_er.value());
        source_type_id = source_type_entity->get_type();
    } else {
        source_type_id = src_arg_er.type();
    }
    builtin_eid source_type = static_cast<builtin_eid>(source_type_id.value);

    switch (source_type) {
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
        break;
    default:
        return std::unexpected(make_error<type_mismatch_error>(arg_descr.expression->location, source_type_id, "a numeric literal type"sv));
    }

    // Handle both constexpr and runtime arguments
    if (src_arg_er.is_const_result) {
        // Constexpr argument - check actual value for precision loss
        generic_literal_entity const& src_arg_literal = dynamic_cast<generic_literal_entity const&>(*source_type_entity);
        
        // Check if the constexpr value can be converted without precision loss
        
        if (source_type != target_type) {
            bool can_convert = false;
            switch (source_type) {
                case builtin_eid::boolean: {
                    can_convert = true; // boolean can be converted to any numeric type
                    break;
                }
                case builtin_eid::integer: {
                    numetron::integer_view source_val = src_arg_literal.value().as<numetron::integer_view>();
                    can_convert = can_convert_constexpr_value_safely(source_val, source_type, target_type);
                    break;
                }
                case builtin_eid::decimal: {
                    numetron::decimal_view source_val = src_arg_literal.value().as<numetron::decimal_view>();
                    can_convert = can_convert_constexpr_value_safely(source_val, source_type, target_type);
                    break;
                }
                case builtin_eid::f16: {
                    numetron::float16 source_val = src_arg_literal.value().as<numetron::float16>();
                    can_convert = can_convert_constexpr_value_safely(source_val, source_type, target_type);
                    break;
                }
                case builtin_eid::f32: {
                    float source_val = src_arg_literal.value().as<float>();
                    can_convert = can_convert_constexpr_value_safely(source_val, source_type, target_type);
                    break;
                }
                case builtin_eid::f64: {
                    double_t source_val = src_arg_literal.value().as<double_t>();
                    can_convert = can_convert_constexpr_value_safely(source_val, source_type, target_type);
                    break;
                }
                default: {
                    // Integer types
                    //numetron::integer_view source_val = src_arg_literal.value().as<numetron::integer_view>();
                    can_convert = is_always_safe_runtime_conversion(source_type, target_type);
                    break;
                }
            }

            if (!can_convert) {
                return std::unexpected(make_error<basic_general_error>(arg_descr.expression->location, "constexpr value cannot be converted without loss of precision"sv));
            }
        }
        
        auto pmd = sonia::make_shared<numeric_literal_implicit_cast_match_descriptor>(call, &src_arg_literal);
        pmd->signature.emplace_back(src_arg_er.value(), true);
        pmd->signature.result.emplace(exp.type, can_be_constexpr(exp.modifier));
        pmd->emplace_back(0, src_arg_er);
        return pmd;
    } else {
        // Runtime argument - only allow conversions that are always safe
        if (!is_always_safe_runtime_conversion(source_type, target_type)) {
            return std::unexpected(make_error<basic_general_error>(arg_descr.expression->location, "runtime conversion is not always safe"sv));
        }
        
        auto pmd = sonia::make_shared<numeric_literal_implicit_cast_match_descriptor>(call, nullptr);
        pmd->signature.emplace_back(src_arg_er.type(), false);
        pmd->signature.result.emplace(exp.type, can_be_constexpr(exp.modifier));
        pmd->emplace_back(0, src_arg_er);
        return pmd;
    }
}

smart_blob integet_view_to_numeric(numetron::integer_view source_val, builtin_eid target_type)
{
    switch (target_type) {
    case builtin_eid::boolean:
        return bool_blob_result(!!source_val);
    case builtin_eid::integer:
        return bigint_blob_result(source_val);
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(source_val));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(source_val));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(source_val));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(source_val));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(source_val));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(source_val));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(source_val));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(source_val));
    case builtin_eid::f16:
        return f16_blob_result(float16_cast(source_val));
    case builtin_eid::f32:
        return f32_blob_result(static_cast<float>(source_val));
    case builtin_eid::f64:
        return f64_blob_result(static_cast<double_t>(source_val));
    case builtin_eid::decimal:
        return decimal_blob_result(numetron::decimal_view{ source_val, 0 });
    default:
        THROW_NOT_IMPLEMENTED_ERROR("numeric_literal_implicit_cast_pattern: integer to other types conversion is not implemented"sv);
    }
}

template <typename T>
requires(std::is_floating_point_v<T> || std::is_same_v<numetron::float16, T> || std::is_same_v<numetron::decimal_view, T>)
smart_blob floating_point_to_numeric(T source_val, builtin_eid target_type)
{
    switch (target_type) {
    case builtin_eid::f16:
        return f16_blob_result(numetron::float16_cast(source_val));
    case builtin_eid::f32:
        return f32_blob_result(static_cast<float>(source_val));
    case builtin_eid::f64:
        return f64_blob_result(static_cast<double_t>(source_val));
    case builtin_eid::decimal:
        if constexpr (std::is_same_v<numetron::decimal_view, T>) {
            return decimal_blob_result(source_val);
        } else {
            // to do: convert float to decimal without going through string
            numetron::decimal d{(std::ostringstream{} << source_val).str()};
            return decimal_blob_result(d);
        }
    default:
        // all integral types here
        if constexpr (std::is_floating_point_v<T> || std::is_same_v<numetron::float16, T>) {
            if (source_val >= 0) {
                numetron::integer ival = static_cast<numetron::integer>((uint64_t)(double)source_val);
                return integet_view_to_numeric(ival, target_type);
            } else {
                numetron::integer ival = static_cast<numetron::integer>((int64_t)(double)source_val);
                return integet_view_to_numeric(ival, target_type);
            }
        } else {
            numetron::integer ival = static_cast<numetron::integer>(source_val);
            return integet_view_to_numeric(ival, target_type);
        }
    }
}

std::expected<syntax_expression_result, error_storage>
numeric_literal_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& nmd = static_cast<numeric_literal_implicit_cast_match_descriptor&>(md);
    auto& [_, src, loc] = md.matches.front();
    
    environment& env = ctx.env();
    entity_identifier target_type_eid = nmd.signature.result->entity_id();
    builtin_eid target_type = static_cast<builtin_eid>(target_type_eid.value);
    bool is_constexpr_result = nmd.signature.result->is_const();
    
    if (nmd.arg) {
        // Constexpr case - we already validated the conversion is safe in try_match
        builtin_eid source_type = static_cast<builtin_eid>(nmd.arg->get_type().value);
        if (source_type == target_type) {
            // No conversion needed
            if (is_constexpr_result) {
                src.value_or_type = nmd.arg->id;
            } else {
                env.push_back_expression(el, src.expressions, semantic::push_value{ smart_blob{ nmd.arg->value() } });
                src.value_or_type = target_type_eid;
                src.is_const_result = false;
            }
            return src;
        }
        smart_blob result_blob;
        switch (source_type) {
            case builtin_eid::boolean:
            case builtin_eid::integer:
            case builtin_eid::u8:
            case builtin_eid::i8:
            case builtin_eid::u16:
            case builtin_eid::i16:
            case builtin_eid::u32:
            case builtin_eid::i32:
            case builtin_eid::u64:
            case builtin_eid::i64: {
                numetron::integer_view source_val = nmd.arg->value().as<numetron::integer_view>();
                result_blob = integet_view_to_numeric(source_val, target_type);
                break;
            }
            case builtin_eid::decimal: {
                numetron::decimal_view source_val = nmd.arg->value().as<numetron::decimal_view>();
                result_blob = floating_point_to_numeric(source_val, target_type);
                break;
            }
            case builtin_eid::f16: {
                numetron::float16 source_val = nmd.arg->value().as<numetron::float16>();
                result_blob = floating_point_to_numeric(source_val, target_type);
                break;
            }
            case builtin_eid::f32: {
                float source_val = nmd.arg->value().as<float>();
                result_blob = floating_point_to_numeric(source_val, target_type);
                break;
            }
            case builtin_eid::f64: {
                double_t source_val = nmd.arg->value().as<double_t>();
                result_blob = floating_point_to_numeric(source_val, target_type);
                break;
            }
            default:
                THROW_NOT_IMPLEMENTED_ERROR("numeric_literal_implicit_cast_pattern: source type conversion is not implemented"sv);
        }

        if (is_constexpr_result) {
            src.value_or_type = env.make_generic_entity(std::move(result_blob), target_type_eid).id;
        } else {
            env.push_back_expression(el, src.expressions, semantic::push_value{ std::move(result_blob) });
            src.value_or_type = target_type_eid;
            src.is_const_result = false;
        }
        return std::move(src);
    }
     
    if (is_constexpr_result) {
        // This shouldn't happen - runtime values can't produce constexpr results
        return std::unexpected(make_error<basic_general_error>(md.call_location, "runtime value cannot produce constexpr result"sv));
    }

    // Runtime case - conversion is already validated as safe in try_match
    BOOST_ASSERT(!src.is_const_result);
    builtin_eid source_type = static_cast<builtin_eid>(src.type().value);
    if (source_type == target_type) {
        // No conversion needed
        return std::move(src);
    }
    src.value_or_type = target_type_eid;
    switch(target_type) {
    case builtin_eid::integer:
        env.push_back_expression(el, src.expressions, semantic::invoke_function(env.get(builtin_eid::to_integer)));
        break;
    case builtin_eid::decimal:
        switch (source_type) {
        case builtin_eid::boolean:
        case builtin_eid::integer:
        case builtin_eid::u8:
        case builtin_eid::i8:
        case builtin_eid::u16:
        case builtin_eid::i16:
        case builtin_eid::u32:
        case builtin_eid::i32:
        case builtin_eid::u64:
        case builtin_eid::i64:
            env.push_back_expression(el, src.expressions, semantic::invoke_function(env.get(builtin_eid::int2dec)));
            break;
        default:
            THROW_NOT_IMPLEMENTED_ERROR("numeric_literal_implicit_cast_pattern: runtime conversion is not implemented"sv);
        }
        break;
    default:
        THROW_NOT_IMPLEMENTED_ERROR("numeric_literal_implicit_cast_pattern: runtime conversion is not implemented"sv);
    }
    return std::move(src);
}

} // namespace annium
