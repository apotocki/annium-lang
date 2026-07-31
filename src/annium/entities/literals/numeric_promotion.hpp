//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <cmath>
#include <sstream>

#include "annium/environment.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

// True for the 13 concrete arithmetic numeric types (fixed-width integers, floating types,
// and the arbitrary-precision integer/decimal types). Excludes bool: it participates in
// numeric literal casts but is not itself an arithmetic operand.
bool is_numeric_eid(builtin_eid type) noexcept;

// Is a runtime value of `source_type` always representable as `target_type` without any
// possibility of precision loss, independent of the actual value? This is the directed
// safe-conversion graph implicit casts rely on; strongest_numeric_type() takes its join.
bool is_always_safe_runtime_conversion(builtin_eid source_type, builtin_eid target_type);

// The result type of combining two numeric operands of types `a` and `b` in an arithmetic
// expression: the smallest numeric type both `a` and `b` safely convert into (the join over
// is_always_safe_runtime_conversion). Same-family operands pick the wider/dominant type
// (i8+i32 -> i32); incomparable operands (signed/unsigned collisions, mixed int/float, integer
// vs decimal) escalate to the smallest common safe supertype (i32+u32 -> i64, i64+u64 ->
// integer, i32+f32 -> f64, integer+decimal -> decimal).
//
// Combining two integral-kind types never picks a floating-kind result purely because some
// small enough candidate happens to also fit a narrow float exactly -- e.g. i8+u8 could safely
// reach both i16 and f16, but the intended (and only integral) result is i16.
builtin_eid strongest_numeric_type(builtin_eid a, builtin_eid b);

// Maps a VM runtime blob's concrete storage type to the corresponding numeric builtin_eid, so
// runtime code (which only sees blob_type) can drive strongest_numeric_type() the same way the
// compiler does. Dereferences blob_reference first.
builtin_eid numeric_builtin_eid_of(blob_result const& b);

// Adds two numeric operands, both read out as the C++ representation of `result_type` (which
// must be the strongest_numeric_type() of the operands' own types, or at least a type both
// safely convert into), and returns the sum as a blob of `result_type`. Shared by the runtime
// __plus_numeric extern and the constexpr fold in numeric_literal_plus_pattern -- smart_blob
// exposes the same generic as<T>() accessor for VM stack values and constexpr literal values.
smart_blob add_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Can the constexpr value `source_val` (of type `source_type`) be represented in `target_type`
// without loss of precision? Used to check, at compile time, whether a literal operand's
// actual value fits a candidate result type.
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
                // Exact comparison against the (possibly rounded) float16 value -- correctly
                // rejects a bigint/fixed-width value too large for float16 to represent exactly
                // (e.g. 2^63+1 rounding to 2^63), same class of issue as draft.ann's commented-out
                // f_pow2/big_pow2_plus1 case at the top of the file. numetron::operator==(basic_
                // integer_view, floating_point) already handles non-finite/fractional rhs safely
                // (returns false rather than throwing), so no separate isfinite guard is needed here.
                return source_val == static_cast<float>(numetron::float16_cast(source_val));
            case builtin_eid::f32:
                return source_val == static_cast<float>(source_val);
            case builtin_eid::f64:
                return source_val == static_cast<double_t>(source_val);
            case builtin_eid::integer:
            case builtin_eid::decimal:
                return true; // arbitrary precision: any integer/bigint value fits exactly
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
            case builtin_eid::integer:
                if (source_val.exponent().sgn() < 0) return false; // has fractional part
                return true; // arbitrary precision: any integral decimal value fits
            case builtin_eid::f16: {
                // Round-trip through float16 and back: if converting loses any digit of the
                // original (normalized) significand/exponent, float16_cast()'s rounding would
                // have discarded precision -- not "always safe" the way an exact-family
                // conversion is. A magnitude that overflows float16's range entirely (-> +-inf)
                // is rejected up front, since basic_decimal's floating-point constructor throws
                // for a non-finite value rather than reporting "doesn't fit".
                numetron::float16 f16v = numetron::float16_cast(source_val);
                if (!std::isfinite(static_cast<float>(f16v))) return false;
                return numetron::decimal{ f16v } == source_val;
            }
            case builtin_eid::f32: {
                float f32v = static_cast<float>(source_val);
                if (!std::isfinite(f32v)) return false;
                return numetron::decimal{ f32v } == source_val;
            }
            case builtin_eid::f64: {
                double_t f64v = static_cast<double_t>(source_val);
                if (!std::isfinite(f64v)) return false;
                return numetron::decimal{ f64v } == source_val;
            }
            case builtin_eid::decimal:
                return true; // same type; source_type == target_type already returned true above
            default:
                return false;
        }
    }

    return false;
}

// Finds the smallest numeric type T such that `runtime_type` safely converts into T (or T is
// `runtime_type` itself) and the constexpr `literal_value` (of type `literal_type`) fits T
// without loss of precision. Used when combining a runtime operand with a literal operand: the
// literal adapts to (at most) a minimal widening of the runtime operand's own type, instead of
// forcing promotion to the literal's own default type (bare integer literals default to
// `integer`, which would otherwise make every runtime-plus-literal expression allocate a bigint).
template <typename LiteralValue>
builtin_eid widen_for_literal_fit(builtin_eid runtime_type, LiteralValue const& literal_value, builtin_eid literal_type)
{
    if (can_convert_constexpr_value_safely(literal_value, literal_type, runtime_type)) return runtime_type;

    constexpr builtin_eid all_numeric_eids[] = {
        builtin_eid::i8, builtin_eid::u8, builtin_eid::i16, builtin_eid::u16,
        builtin_eid::i32, builtin_eid::u32, builtin_eid::i64, builtin_eid::u64,
        builtin_eid::f16, builtin_eid::f32, builtin_eid::f64,
        builtin_eid::integer, builtin_eid::decimal
    };
    for (builtin_eid candidate : all_numeric_eids) {
        if (candidate == runtime_type) continue;
        if (!is_always_safe_runtime_conversion(runtime_type, candidate)) continue;
        if (!can_convert_constexpr_value_safely(literal_value, literal_type, candidate)) continue;
        return candidate;
    }

    THROW_INTERNAL_ERROR("widen_for_literal_fit: no common safe numeric type"sv);
}

smart_blob integer_view_to_numeric(numetron::integer_view source_val, builtin_eid target_type);

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
                return integer_view_to_numeric(ival, target_type);
            } else {
                numetron::integer ival = static_cast<numetron::integer>((int64_t)(double)source_val);
                return integer_view_to_numeric(ival, target_type);
            }
        } else {
            numetron::integer ival = static_cast<numetron::integer>(source_val);
            return integer_view_to_numeric(ival, target_type);
        }
    }
}

} // namespace annium
