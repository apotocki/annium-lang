//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <cmath>
#include <iostream>
#include <optional>
#include <sstream>

#include "annium/environment.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

// True for the 13 concrete arithmetic numeric types (fixed-width integers, floating types,
// and the arbitrary-precision integer/decimal types). Excludes bool: it participates in
// numeric literal casts but is not itself an arithmetic operand.
bool is_numeric_eid(builtin_eid type) noexcept;

// True for the 9 integral-kind types (fixed-width integers and the arbitrary-precision integer
// type) among is_numeric_eid's 13 -- excludes decimal and the floating types, and (like
// is_numeric_eid) excludes bool. Bitwise & and | are only defined for these: see
// numeric_literal_bit_and_pattern/numeric_literal_bit_or_pattern, which use this to reject a
// float/decimal operand before ever reaching bit_and_numeric/bit_or_numeric below (bool's own
// & and | go through the separate bool_bit_and_pattern/bool_bit_or_pattern instead, since bool
// isn't itself numeric).
bool is_integral_kind_eid(builtin_eid type) noexcept;

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

// Same shape as add_numeric, but lhs - rhs. Operand order matters here (unlike addition), so
// callers must keep lhs/rhs in their original left/right position.
smart_blob subtract_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Same shape as add_numeric, but lhs * rhs.
smart_blob multiply_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Same shape as add_numeric, but lhs / rhs. `result_type` is never builtin_eid::decimal --
// numeric_literal_div_pattern rejects decimal operands before this is ever called (division isn't
// defined for decimal yet, pending a design decision -- see FUTURE_WORK.md). Two integral-kind
// operands truncate (C++ integer division semantics), matching the caller's join rule of picking
// an integral result_type only when both operands are integral-kind.
smart_blob divide_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Same shape as add_numeric, but lhs % rhs. `result_type` is never builtin_eid::decimal --
// numeric_literal_mod_pattern rejects decimal operands before this is ever called (unlike
// divide_numeric, there's no constexpr escape hatch either -- decimal modulo has no design yet,
// see FUTURE_WORK.md). Two integral-kind operands use native C++ `%` (remainder, sign follows the
// dividend, matching divide_numeric's truncating-toward-zero `/`); floating-kind operands use
// std::fmod, which follows the same toward-zero-truncation convention.
smart_blob modulo_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Same shape as add_numeric, but lhs & rhs. `result_type` must be one of the 9 integral-kind
// types (see is_integral_kind_eid) -- numeric_literal_bit_and_pattern rejects any other type
// (decimal, f16/f32/f64) before this is ever called, same reasoning as divide_numeric excluding
// decimal.
smart_blob bit_and_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Same shape as bit_and_numeric, but lhs | rhs.
smart_blob bit_or_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type);

// Attempts an exact constexpr `decimal / decimal` division. Unlike +, -, * (see divide_numeric's
// comment), decimal division has no general definition here: most quotients (e.g. 1/3) don't have
// a finite base-10 representation. But when the reduced fraction's denominator's only prime
// factors are 2 and 5, the quotient *is* finite and exact -- computed here by clearing the
// denominator to an exact power of 10 (via gcd + repeated factoring-out of 2s and 5s), never by
// rounding or long division. Returns std::nullopt for division by zero or a non-terminating
// (repeating) quotient; numeric_literal_div_pattern turns either into a compile error.
// constexpr-only by design: at runtime nothing could reject a non-terminating result until the
// actual operand values are known, so the plain `/` operator stays fully undefined for decimal at
// runtime -- see FUTURE_WORK.md. (The explicit `divide(a, b, scale, mode)` bootstrap.ann function,
// see numetron::decimal_round_mode/divide_decimal_rounded below, is the runtime-safe alternative:
// it always produces a result by rounding to a caller-chosen scale instead of rejecting anything.)
std::optional<numetron::decimal> try_divide_decimal_constexpr(numetron::decimal_view lhs, numetron::decimal_view rhs);

// Divides two decimal values, rounded to at most `scale` digits after the decimal point (trailing
// zeros are stripped afterward, same normalization every other decimal arithmetic result already
// gets -- this codebase's decimal type has no way to print a non-significant trailing zero, so an
// exact `scale`-digit padding wouldn't be observable anyway). Unlike try_divide_decimal_constexpr,
// this never rejects a non-terminating quotient -- it always produces a result, by rounding.
// Returns std::nullopt for division by zero (the caller, annium_divide_decimal_rounded, turns that
// into a runtime exception). Throws THROW_NOT_IMPLEMENTED_ERROR for any `mode` other than
// half_even -- the other modes are deliberately not implemented yet, see FUTURE_WORK.md.
//
// `mode` is `numetron::decimal_round_mode` (decimal_view.hpp) directly -- there used to be a
// separate Annium-side `decimal_rounding_mode` mirroring it member-for-member, purely so numetron
// wouldn't need an Annium-shaped enum; it added a conversion function and a second enum to keep in
// sync for no actual decoupling benefit (nothing outside this rounding-mode plumbing ever used it),
// so it was dropped in favor of using numetron's enum everywhere on the C++ side too. This still
// has to mirror bootstrap.ann's own `rounding_mode` enum member-for-member (ordinal order must
// match exactly -- the bootstrap.ann `divide(...)` wrapper crosses the runtime boundary by passing
// `to_integer(mode)`'s bare ordinal to __divide_decimal_rounded, there's no shared symbolic type
// across that boundary) -- that constraint didn't go away, it just targets numetron's enum now
// instead of an intermediate Annium one.
std::optional<numetron::decimal> divide_decimal_rounded(numetron::decimal_view lhs, numetron::decimal_view rhs, uint32_t scale, numetron::decimal_round_mode mode);

// Formats `d` to exactly `digits` fractional digits (zero-padded, never trimmed), correctly rounded.
// `digits` must be >= 0 (annium_numeric_to_fixed, the only caller, already clamps). Thin wrapper
// around numetron::to_fixed_string(numetron::decimal_view, digits, numetron::decimal_round_mode)
// (decimal_view.hpp) -- the actual bigint significand/exponent rounding algorithm lives there now,
// since it's pure numetron arithmetic with no Annium dependency (see RESOLVED.md's "Moved
// to_fixed_string's rounding algorithms into numetron" entry). This wrapper's own job is just
// guarding unimplemented modes with Annium's own THROW_NOT_IMPLEMENTED_ERROR (rather than letting
// numetron's plain std::runtime_error escape, which wouldn't match this codebase's own "not
// implemented yet" exception type) -- only decimal_round_mode::half_even and ::half_up are
// implemented (mirroring the two conventions round(value, digits, mode) implements natively in
// annium_library.cpp), every other mode throws.
std::string to_fixed_decimal_string(numetron::decimal_view d, int64_t digits, numetron::decimal_round_mode mode);

// Formats any numeric value to exactly `digits` fractional digits (zero-padded, correctly rounded,
// per `mode` -- backs bootstrap.ann's to_fixed(value, digits, mode)). Always exact, but splits into
// two different rounding paths by source kind, both now living in numetron (decimal_view.hpp) --
// this function is just the builtin_eid dispatch:
//
// - A `decimal` source, or any integral source (fixed-width int, bigint integer), is already exact
//   when read as a numetron::decimal_view (no Dragonbox involved for those -- see
//   sonia::invocation::from_blob<basic_decimal_view<LimbT>>, invocation.hpp) -- rounded directly via
//   to_fixed_decimal_string above (itself calling numetron::to_fixed_string's decimal_view overload).
// - An f16/f32/f64 source is read as a double first (exact: decimal_view -> double round-trips
//   losslessly by Dragonbox's own round-trip guarantee) and then rounded by
//   numetron::to_fixed_string's floating-point overload, which stays in base 2 throughout rather
//   than going through an exact base-10 decimal -- see that overload's own comment (decimal_view.hpp)
//   for why the base-10 route needs a divisor far too wide for numetron::limb_arithmetic::udiv's
//   single-limb fast path for essentially any real float input, not a contrived one (see
//   BUGFIXES.md), while the base-2 route uses only shifts and subtraction (no division at all,
//   hence no udiv-width concern regardless of magnitude).
//
// (An even earlier version went through `double` + std::to_chars(..., chars_format::fixed) instead
// of either exact path -- that couldn't have honored `mode` at all for a float source, since
// std::to_chars has no rounding-mode parameter, it always uses whatever the current floating-point
// environment's rounding mode happens to be -- which is *why* `mode` forced a rewrite in the first
// place, rather than just being bolted on.)
std::string to_fixed_string(smart_blob const& value, int64_t digits, numetron::decimal_round_mode mode);

// The *exact* decimal value of a finite native float/double -- not `numetron::decimal{value}`,
// which goes through Dragonbox (basic_decimal_view's floating-point constructor) and deliberately
// produces the *shortest* decimal string that still round-trips back to `value`, not the exact
// one. That's the right tool for printing a float concisely, but the wrong one for an exactness
// check: comparing a shortened Dragonbox decimal against a `source_val` written with more digits
// than Dragonbox's minimal round-trip form spuriously reports "different" even when both exactly
// represent the same value once rounded to the target float type (found via `f32.pi`/`f32.e`:
// their correctly-rounded exact decimal expansions are longer than Dragonbox's shortest form for
// the same bit pattern). `value`'s bits are exactly `int_mantissa * 2^binexp` (frexp/ldexp are
// exact for finite floats); folding the 2^binexp factor into a decimal is exact too -- into the
// significand when binexp >= 0, or via 2^binexp = 5^-binexp / 10^binexp when binexp < 0 (same
// "split off the base-5 part, the base-2 part is exact" trick decimal_view's own float conversion
// operator uses, just inverted).
template <std::floating_point T>
numetron::decimal exact_decimal_from_finite(T value)
{
    if (value == T{0}) return numetron::decimal{0};
    int exp2;
    T mantissa = std::frexp(value, &exp2);
    constexpr int mantissa_bits = std::numeric_limits<T>::digits;
    int64_t int_mantissa = static_cast<int64_t>(std::ldexp(mantissa, mantissa_bits));
    int64_t binexp = static_cast<int64_t>(exp2) - mantissa_bits;
    numetron::integer sig{ int_mantissa };
    if (binexp >= 0) {
        sig *= numetron::pow(numetron::integer{2}, static_cast<unsigned int>(binexp));
        return numetron::decimal{ (numetron::integer_view)sig, numetron::integer_view{0} };
    } else {
        sig *= numetron::pow(numetron::integer{5}, static_cast<unsigned int>(-binexp));
        return numetron::decimal{ (numetron::integer_view)sig, numetron::integer_view{binexp} };
    }
}

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
                float f16v_widened = static_cast<float>(f16v); // exact: float16 -> float always widens exactly
                if (!std::isfinite(f16v_widened)) return false;
                return exact_decimal_from_finite(f16v_widened) == source_val;
            }
            case builtin_eid::f32: {
                float f32v = static_cast<float>(source_val);
                if (!std::isfinite(f32v)) return false;
                return exact_decimal_from_finite(f32v) == source_val;
            }
            case builtin_eid::f64: {
                double_t f64v = static_cast<double_t>(source_val);
                if (!std::isfinite(f64v)) return false;
                return exact_decimal_from_finite(f64v) == source_val;
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
