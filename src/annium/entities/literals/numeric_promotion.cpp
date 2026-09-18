//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_promotion.hpp"

#include <algorithm>
#include <array>

namespace annium {

bool is_numeric_eid(builtin_eid type) noexcept
{
    switch (type) {
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

// Conversions that are always safe for runtime values
bool is_always_safe_runtime_conversion(builtin_eid source_type, builtin_eid target_type)
{
    if (source_type == target_type) return true;

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

smart_blob integer_view_to_numeric(numetron::integer_view source_val, builtin_eid target_type)
{
    switch (target_type) {
    case builtin_eid::boolean:
        return bool_blob_result(!!source_val);
    case builtin_eid::integer:
        return smart_blob{ bigint_blob_result(source_val) }.allocate();
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
        return smart_blob{ decimal_blob_result(numetron::decimal{ source_val }) }.allocate();
    default:
        THROW_NOT_IMPLEMENTED_ERROR("integer_view_to_numeric: integer to other types conversion is not implemented"sv);
    }
}

bool is_integral_kind_eid(builtin_eid t) noexcept
{
    switch (t) {
    case builtin_eid::i8:
    case builtin_eid::u8:
    case builtin_eid::i16:
    case builtin_eid::u16:
    case builtin_eid::i32:
    case builtin_eid::u32:
    case builtin_eid::i64:
    case builtin_eid::u64:
    case builtin_eid::integer:
        return true;
    default:
        return false;
    }
}

namespace {

constexpr builtin_eid k_all_numeric_eids[] = {
    builtin_eid::i8, builtin_eid::u8, builtin_eid::i16, builtin_eid::u16,
    builtin_eid::i32, builtin_eid::u32, builtin_eid::i64, builtin_eid::u64,
    builtin_eid::f16, builtin_eid::f32, builtin_eid::f64,
    builtin_eid::integer, builtin_eid::decimal
};

bool is_floating_kind_eid(builtin_eid t) noexcept
{
    return t == builtin_eid::f16 || t == builtin_eid::f32 || t == builtin_eid::f64;
}

inline bool safe_or_same(builtin_eid from, builtin_eid to)
{
    return from == to || is_always_safe_runtime_conversion(from, to);
}

} // anonymous namespace

builtin_eid strongest_numeric_type(builtin_eid a, builtin_eid b)
{
    if (a == b) return a;

    // Mixing two integral-kind operands must never pick a floating result just because some
    // small enough common candidate also happens to fit a narrow float exactly (i8+u8 can
    // safely reach both i16 and f16 -- only i16 is the intended, integral, result).
    bool exclude_floating = is_integral_kind_eid(a) && is_integral_kind_eid(b);

    std::array<builtin_eid, 13> candidates;
    size_t candidates_count = 0;
    for (builtin_eid t : k_all_numeric_eids) {
        if (exclude_floating && is_floating_kind_eid(t)) continue;
        if (safe_or_same(a, t) && safe_or_same(b, t)) candidates[candidates_count++] = t;
    }

    // The result is the bottom element of the candidate set: the one candidate that safely
    // converts into every other candidate.
    for (size_t i = 0; i < candidates_count; ++i) {
        builtin_eid t = candidates[i];
        bool is_bottom = true;
        for (size_t j = 0; j < candidates_count; ++j) {
            if (candidates[j] != t && !safe_or_same(t, candidates[j])) { is_bottom = false; break; }
        }
        if (is_bottom) return t;
    }

    THROW_INTERNAL_ERROR("strongest_numeric_type: no common safe numeric type"sv);
}

builtin_eid numeric_builtin_eid_of(blob_result const& b)
{
    blob_result const& p = unref(b);

    switch (p.type) {
    case blob_type::bigint: return builtin_eid::integer;
    case blob_type::decimal: return builtin_eid::decimal;
    default: break;
    }

    blob_type decayed = (blob_type)(((uint8_t)p.type) & 0x7f);
    switch (decayed) {
    case blob_type::boolean: return builtin_eid::boolean;
    case blob_type::i8: return builtin_eid::i8;
    case blob_type::ui8: return builtin_eid::u8;
    case blob_type::i16: return builtin_eid::i16;
    case blob_type::ui16: return builtin_eid::u16;
    case blob_type::i32: return builtin_eid::i32;
    case blob_type::ui32: return builtin_eid::u32;
    case blob_type::i64: return builtin_eid::i64;
    case blob_type::ui64: return builtin_eid::u64;
    case blob_type::flt16: return builtin_eid::f16;
    case blob_type::flt32: return builtin_eid::f32;
    case blob_type::flt64: return builtin_eid::f64;
    default:
        THROW_INTERNAL_ERROR("numeric_builtin_eid_of: blob is not a numeric type"sv);
    }
}

smart_blob add_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() + rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() + rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() + rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() + rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() + rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() + rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() + rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() + rhs.as<uint64_t>()));
    case builtin_eid::f16: {
        // float16 only defines unary operator-() (see negate_constexpr_numeric), no binary +:
        // round-trip through float for the addition itself.
        float sum = static_cast<float>(lhs.as<numetron::float16>()) + static_cast<float>(rhs.as<numetron::float16>());
        return f16_blob_result(numetron::float16_cast(sum));
    }
    case builtin_eid::f32:
        return f32_blob_result(lhs.as<float>() + rhs.as<float>());
    case builtin_eid::f64:
        return f64_blob_result(lhs.as<double_t>() + rhs.as<double_t>());
    case builtin_eid::integer: {
        auto sum = lhs.as<numetron::integer>() + rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(sum) }.allocate();
    }
    case builtin_eid::decimal: {
        auto sum = lhs.as<numetron::decimal>() + rhs.as<numetron::decimal_view>();
        return smart_blob{ decimal_blob_result(sum) }.allocate();
    }
    default:
        THROW_INTERNAL_ERROR("add_numeric: unsupported result type"sv);
    }
}

smart_blob subtract_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() - rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() - rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() - rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() - rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() - rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() - rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() - rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() - rhs.as<uint64_t>()));
    case builtin_eid::f16: {
        // float16 only defines unary operator-() (see negate_constexpr_numeric), no binary -:
        // round-trip through float for the subtraction itself.
        float diff = static_cast<float>(lhs.as<numetron::float16>()) - static_cast<float>(rhs.as<numetron::float16>());
        return f16_blob_result(numetron::float16_cast(diff));
    }
    case builtin_eid::f32:
        return f32_blob_result(lhs.as<float>() - rhs.as<float>());
    case builtin_eid::f64:
        return f64_blob_result(lhs.as<double_t>() - rhs.as<double_t>());
    case builtin_eid::integer: {
        auto diff = lhs.as<numetron::integer>() - rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(diff) }.allocate();
    }
    case builtin_eid::decimal: {
        // numetron::decimal only defines binary operator+ (no binary operator-, see
        // basic_decimal.hpp) -- negate the view (basic_decimal_view::operator-(), cheap sign
        // flip) and add instead.
        auto diff = lhs.as<numetron::decimal>() + (-rhs.as<numetron::decimal_view>());
        return smart_blob{ decimal_blob_result(diff) }.allocate();
    }
    default:
        THROW_INTERNAL_ERROR("subtract_numeric: unsupported result type"sv);
    }
}

smart_blob multiply_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() * rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() * rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() * rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() * rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() * rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() * rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() * rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() * rhs.as<uint64_t>()));
    case builtin_eid::f16: {
        // float16 only defines unary operator-() (see negate_constexpr_numeric), no binary *:
        // round-trip through float for the multiplication itself.
        float prod = static_cast<float>(lhs.as<numetron::float16>()) * static_cast<float>(rhs.as<numetron::float16>());
        return f16_blob_result(numetron::float16_cast(prod));
    }
    case builtin_eid::f32:
        return f32_blob_result(lhs.as<float>() * rhs.as<float>());
    case builtin_eid::f64:
        return f64_blob_result(lhs.as<double_t>() * rhs.as<double_t>());
    case builtin_eid::integer: {
        auto prod = lhs.as<numetron::integer>() * rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(prod) }.allocate();
    }
    case builtin_eid::decimal: {
        auto prod = lhs.as<numetron::decimal>() * rhs.as<numetron::decimal_view>();
        return smart_blob{ decimal_blob_result(prod) }.allocate();
    }
    default:
        THROW_INTERNAL_ERROR("multiply_numeric: unsupported result type"sv);
    }
}

smart_blob divide_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() / rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() / rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() / rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() / rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() / rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() / rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() / rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() / rhs.as<uint64_t>()));
    case builtin_eid::f16: {
        // float16 only defines unary operator-() (see negate_constexpr_numeric), no binary /:
        // round-trip through float for the division itself.
        float quot = static_cast<float>(lhs.as<numetron::float16>()) / static_cast<float>(rhs.as<numetron::float16>());
        return f16_blob_result(numetron::float16_cast(quot));
    }
    case builtin_eid::f32:
        return f32_blob_result(lhs.as<float>() / rhs.as<float>());
    case builtin_eid::f64:
        return f64_blob_result(lhs.as<double_t>() / rhs.as<double_t>());
    case builtin_eid::integer: {
        auto quot = lhs.as<numetron::integer>() / rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(quot) }.allocate();
    }
    default:
        // builtin_eid::decimal deliberately excluded: division isn't defined for decimal yet
        // (see FUTURE_WORK.md) -- numeric_literal_div_pattern rejects decimal operands before
        // this function is ever reached, so reaching here for decimal (or anything else) is a bug.
        THROW_INTERNAL_ERROR("divide_numeric: unsupported result type"sv);
    }
}

smart_blob modulo_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() % rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() % rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() % rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() % rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() % rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() % rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() % rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() % rhs.as<uint64_t>()));
    case builtin_eid::f16: {
        // float16 only defines unary operator-() (see negate_constexpr_numeric), no binary %:
        // round-trip through float for the modulo itself.
        float rem = std::fmod(static_cast<float>(lhs.as<numetron::float16>()), static_cast<float>(rhs.as<numetron::float16>()));
        return f16_blob_result(numetron::float16_cast(rem));
    }
    case builtin_eid::f32:
        return f32_blob_result(std::fmod(lhs.as<float>(), rhs.as<float>()));
    case builtin_eid::f64:
        return f64_blob_result(std::fmod(lhs.as<double_t>(), rhs.as<double_t>()));
    case builtin_eid::integer: {
        auto rem = lhs.as<numetron::integer>() % rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(rem) }.allocate();
    }
    default:
        // builtin_eid::decimal deliberately excluded: modulo isn't defined for decimal at all
        // yet (see FUTURE_WORK.md) -- numeric_literal_mod_pattern rejects decimal operands
        // (constexpr or runtime) before this function is ever reached, so reaching here for
        // decimal (or anything else) is a bug.
        THROW_INTERNAL_ERROR("modulo_numeric: unsupported result type"sv);
    }
}

smart_blob bit_and_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() & rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() & rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() & rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() & rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() & rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() & rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() & rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() & rhs.as<uint64_t>()));
    case builtin_eid::integer: {
        auto conj = lhs.as<numetron::integer>() & rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(conj) }.allocate();
    }
    default:
        // builtin_eid::decimal/f16/f32/f64 deliberately excluded: bitwise AND isn't defined for
        // them -- numeric_literal_bit_and_pattern rejects non-integral operands before this
        // function is ever reached, so reaching here is a bug.
        THROW_INTERNAL_ERROR("bit_and_numeric: unsupported result type"sv);
    }
}

smart_blob bit_or_numeric(smart_blob const& lhs, smart_blob const& rhs, builtin_eid result_type)
{
    switch (result_type) {
    case builtin_eid::i8:
        return i8_blob_result(static_cast<int8_t>(lhs.as<int8_t>() | rhs.as<int8_t>()));
    case builtin_eid::u8:
        return ui8_blob_result(static_cast<uint8_t>(lhs.as<uint8_t>() | rhs.as<uint8_t>()));
    case builtin_eid::i16:
        return i16_blob_result(static_cast<int16_t>(lhs.as<int16_t>() | rhs.as<int16_t>()));
    case builtin_eid::u16:
        return ui16_blob_result(static_cast<uint16_t>(lhs.as<uint16_t>() | rhs.as<uint16_t>()));
    case builtin_eid::i32:
        return i32_blob_result(static_cast<int32_t>(lhs.as<int32_t>() | rhs.as<int32_t>()));
    case builtin_eid::u32:
        return ui32_blob_result(static_cast<uint32_t>(lhs.as<uint32_t>() | rhs.as<uint32_t>()));
    case builtin_eid::i64:
        return i64_blob_result(static_cast<int64_t>(lhs.as<int64_t>() | rhs.as<int64_t>()));
    case builtin_eid::u64:
        return ui64_blob_result(static_cast<uint64_t>(lhs.as<uint64_t>() | rhs.as<uint64_t>()));
    case builtin_eid::integer: {
        auto disj = lhs.as<numetron::integer>() | rhs.as<numetron::integer_view>();
        return smart_blob{ bigint_blob_result(disj) }.allocate();
    }
    default:
        // See bit_and_numeric's comment: numeric_literal_bit_or_pattern rejects non-integral
        // operands before this function is ever reached.
        THROW_INTERNAL_ERROR("bit_or_numeric: unsupported result type"sv);
    }
}

namespace {

numetron::integer integer_gcd(numetron::integer a, numetron::integer b)
{
    while (b) {
        numetron::integer r = a % b;
        a = std::move(b);
        b = std::move(r);
    }
    return a;
}

// Formats a non-negative bigint magnitude `sig` that already *is* the target value * 10^digits
// (rounded) into a "int.frac" (or bare integer at digits == 0) string, left-padding the integer
// part with zeros so there's always at least one digit ahead of the decimal point (e.g. sig == 5
// at digits == 2 must read "0.05", not split "5" into nothing). Shared by to_fixed_decimal_string's
// base-10 scaling below and to_fixed_string_from_finite's base-2 one (see its comment) -- once a
// value's been rounded down to an exact bigint at the target scale, the string layout is identical
// either way, only how that bigint was obtained differs.
std::string format_fixed_digits(numetron::integer_view sig, bool negative, int64_t digits)
{
    std::string digit_str = (std::ostringstream{} << sig).str();

    std::string result;
    // Sign follows the caller's `negative` flag alone (not whether the rounded magnitude happens
    // to be zero) -- matches std::to_chars/printf's own "-0" behavior for e.g. a small negative
    // value rounded away to nothing at digits == 0.
    if (negative) result.push_back('-');

    if (digits == 0) {
        result += digit_str;
        return result;
    }

    if (digit_str.size() <= static_cast<size_t>(digits)) {
        digit_str.insert(0, static_cast<size_t>(digits) + 1 - digit_str.size(), '0');
    }
    size_t split = digit_str.size() - static_cast<size_t>(digits);
    result += digit_str.substr(0, split);
    result.push_back('.');
    result += digit_str.substr(split);
    return result;
}

// Rounds a finite double's *exact* value to `digits` fractional decimal digits, honoring `mode`,
// entirely in base 2. An earlier version of to_fixed_string routed a float source through
// exact_decimal_from_finite (below) and then this same to_fixed_decimal_string-style rounding, but
// in base 10 -- that's exact, but exact_decimal_from_finite folds a negative binary exponent into a
// decimal one via 2^binexp == 5^-binexp / 10^binexp, which keeps *binexp itself* as the decimal
// exponent. For a typical double binexp is around -50, and for a subnormal one as low as -1074, so
// rounding that decimal down to a handful of fractional digits needs a base-10 divisor of 10^n for
// n up to ~1074 -- around 3570 bits, far past numetron::limb_arithmetic::udiv's single-64-bit-limb
// fast path, so it threw "not implemented" for essentially any real-world to_fixed(f64_value,
// small_digits, mode) call (e.g. formatBytes.ann's own szval), not just a contrived test input --
// see BUGFIXES.md.
//
// `value`'s bits are exactly int_mantissa * 2^binexp (frexp/ldexp are exact for finite doubles), so
// value * 10^digits == int_mantissa * 5^digits * 2^(binexp + digits): when binexp + digits >= 0
// that's an exact multiply (the value has no fractional bits left to round away at this scale);
// otherwise it's one division by 2^-(binexp + digits), whose required bit width tracks binexp
// directly (at most 1074, for the smallest representable subnormal double) instead of binexp's
// *decimal* equivalent (~3570 bits) -- comfortably within udiv's single-limb fast path for any
// normal-magnitude double and any typical `digits`, and it covers most subnormals too unless
// `digits` is unusually small relative to how tiny the value is.
std::string to_fixed_string_from_finite(double value, int64_t digits, decimal_rounding_mode mode)
{
    if (mode != decimal_rounding_mode::half_even && mode != decimal_rounding_mode::half_up) {
        THROW_NOT_IMPLEMENTED_ERROR("to_fixed: only rounding_mode.half_even and .half_up are implemented so far"sv);
    }

    bool negative = std::signbit(value);
    if (value == 0.0) {
        return format_fixed_digits((numetron::integer_view)numetron::integer{ 0 }, negative, digits);
    }

    int exp2;
    double mantissa = std::frexp(value, &exp2);
    constexpr int mantissa_bits = std::numeric_limits<double>::digits;
    int64_t int_mantissa = static_cast<int64_t>(std::ldexp(std::fabs(mantissa), mantissa_bits));
    int64_t binexp = static_cast<int64_t>(exp2) - mantissa_bits;

    numetron::integer sig{ int_mantissa };
    sig *= numetron::pow(numetron::integer{ 5 }, static_cast<uint64_t>(digits));

    int64_t k = binexp + digits;
    if (k >= 0) {
        sig *= numetron::pow(numetron::integer{ 2 }, static_cast<uint64_t>(k));
    } else {
        numetron::integer den = numetron::pow(numetron::integer{ 2 }, static_cast<uint64_t>(-k));
        numetron::integer q = sig / den;
        numetron::integer r = sig % den;
        numetron::integer twice_r = r * numetron::integer{ 2 };
        numetron::integer_view twice_r_v = (numetron::integer_view)twice_r;
        numetron::integer_view den_v = (numetron::integer_view)den;
        if (mode == decimal_rounding_mode::half_up) {
            if (twice_r_v >= den_v) q += 1;
        } else if (twice_r_v > den_v) {
            q += 1;
        } else if (twice_r_v == den_v && (q % 2)) {
            q += 1; // exact tie, half_even: round to the even neighbor, and q is currently odd
        }
        sig = std::move(q);
    }

    return format_fixed_digits((numetron::integer_view)sig, negative, digits);
}

} // anonymous namespace

std::optional<numetron::decimal> try_divide_decimal_constexpr(numetron::decimal_view lhs, numetron::decimal_view rhs)
{
    numetron::integer den{ rhs.significand().abs() };
    if (!den) return std::nullopt; // division by zero

    numetron::integer num{ lhs.significand().abs() };
    if (!num) return numetron::decimal{ 0 }; // 0 / (nonzero) == 0

    numetron::integer g = integer_gcd(num, den);
    num /= g;
    den /= g;

    // Strip all factors of 2 and 5 out of the (now coprime with num) denominator -- if anything
    // other than 1 is left, the reduced fraction's denominator has some other prime factor, so
    // its base-10 expansion repeats forever and there's no exact decimal result.
    int e2 = 0;
    while (!(den % 2)) { den /= 2; ++e2; }
    int e5 = 0;
    while (!(den % 5)) { den /= 5; ++e5; }
    if (!(den == 1)) return std::nullopt;

    // num/den == num / (2^e2 * 5^e5); multiplying num by the missing powers of 2 and 5 turns the
    // denominator into an exact 10^k, so the quotient becomes an exact integer significand over
    // 10^k -- no rounding anywhere in this computation.
    int k = std::max(e2, e5);
    numetron::integer multiplier = numetron::pow(numetron::integer{ 2 }, static_cast<unsigned int>(k - e2))
                                  * numetron::pow(numetron::integer{ 5 }, static_cast<unsigned int>(k - e5));
    numetron::integer result_sig = num * multiplier;
    if (lhs.is_negative() != rhs.is_negative()) result_sig = -result_sig;

    numetron::integer result_exp{ lhs.exponent() };
    result_exp -= rhs.exponent();
    result_exp -= k;

    return numetron::decimal{ (numetron::integer_view)result_sig, (numetron::integer_view)result_exp };
}

std::optional<numetron::decimal> divide_decimal_rounded(numetron::decimal_view lhs, numetron::decimal_view rhs, uint32_t scale, decimal_rounding_mode mode)
{
    if (mode != decimal_rounding_mode::half_even) {
        THROW_NOT_IMPLEMENTED_ERROR("divide_decimal_rounded: only rounding_mode::half_even is implemented so far"sv);
    }

    numetron::integer den{ rhs.significand().abs() };
    if (!den) return std::nullopt; // division by zero

    numetron::integer num{ lhs.significand().abs() };
    if (!num) return numetron::decimal{ 0 };

    // num/den * 10^scale, scaled by the operands' own exponent difference -- push the whole 10^e
    // factor onto whichever side (numerator or denominator) keeps it a positive power, so the
    // division below is always an exact-integer numerator over an exact-integer denominator.
    int64_t e = (int64_t)lhs.exponent() - (int64_t)rhs.exponent() + (int64_t)scale;
    if (e >= 0) {
        num *= numetron::pow(numetron::integer{ 10 }, static_cast<uint64_t>(e));
    } else {
        den *= numetron::pow(numetron::integer{ 10 }, static_cast<uint64_t>(-e));
    }

    numetron::integer q = num / den; // truncated (toward zero) magnitude quotient
    numetron::integer r = num % den;

    // round-half-even tie-break on the discarded remainder, compared against half the denominator
    // (via 2*r instead of den/2 -- den isn't necessarily even, so this avoids integer-dividing it).
    numetron::integer twice_r = r * numetron::integer{ 2 };
    numetron::integer_view twice_r_v = (numetron::integer_view)twice_r;
    numetron::integer_view den_v = (numetron::integer_view)den;
    if (twice_r_v > den_v) {
        q += 1;
    } else if (twice_r_v == den_v && (q % 2)) {
        q += 1; // exact tie: round to the even neighbor, and q is currently odd
    }

    if (lhs.is_negative() != rhs.is_negative()) q = -q;

    numetron::integer result_exp{ -static_cast<int64_t>(scale) };
    if (q) {
        // Strip trailing zeros -- same normalization every other decimal arithmetic result already
        // gets (see e.g. multiply_numeric's decimal case), so a `scale` larger than the quotient
        // actually needs doesn't leave fake extra precision sitting in the significand.
        while (!(q % 10)) { q /= 10; result_exp += 1; }
    }

    return numetron::decimal{ (numetron::integer_view)q, (numetron::integer_view)result_exp };
}

std::string to_fixed_decimal_string(numetron::decimal_view d, int64_t digits, decimal_rounding_mode mode)
{
    if (mode != decimal_rounding_mode::half_even && mode != decimal_rounding_mode::half_up) {
        THROW_NOT_IMPLEMENTED_ERROR("to_fixed: only rounding_mode.half_even and .half_up are implemented so far"sv);
    }

    numetron::integer sig{ d.significand().abs() };

    // Scale sig to the target exponent -digits: e >= 0 is an exact widening (just appends trailing
    // zeros, no rounding possible); e < 0 discards digits and needs a remainder tie-break per `mode`
    // (compare 2*r against the denominator) -- half_up always rounds a tie away from zero (q's sign
    // is applied later, so "away from zero" here just means "up", unconditionally on a tie); half_even
    // additionally checks q's own parity, same as divide_decimal_rounded above.
    int64_t e = (int64_t)d.exponent() + digits;
    if (e >= 0) {
        sig *= numetron::pow(numetron::integer{ 10 }, static_cast<uint64_t>(e));
    } else {
        numetron::integer den = numetron::pow(numetron::integer{ 10 }, static_cast<uint64_t>(-e));
        numetron::integer q = sig / den;
        numetron::integer r = sig % den;
        numetron::integer twice_r = r * numetron::integer{ 2 };
        numetron::integer_view twice_r_v = (numetron::integer_view)twice_r;
        numetron::integer_view den_v = (numetron::integer_view)den;
        if (mode == decimal_rounding_mode::half_up) {
            if (twice_r_v >= den_v) q += 1;
        } else if (twice_r_v > den_v) {
            q += 1;
        } else if (twice_r_v == den_v && (q % 2)) {
            q += 1; // exact tie, half_even: round to the even neighbor, and q is currently odd
        }
        sig = std::move(q);
    }

    return format_fixed_digits((numetron::integer_view)sig, d.is_negative(), digits);
}

std::string to_fixed_string(smart_blob const& value, int64_t digits, decimal_rounding_mode mode)
{
    switch (numeric_builtin_eid_of(*value)) {
    case builtin_eid::f16:
    case builtin_eid::f32:
    case builtin_eid::f64: {
        // decimal_view's own conversion from a native float goes through Dragonbox (shortest
        // round-tripping decimal, not the exact binary value) -- reading it back out as a double
        // is exact regardless (Dragonbox's whole guarantee is that this round-trips losslessly).
        // From there, rounding has to stay in base 2 (to_fixed_string_from_finite, above) rather
        // than going through an exact base-10 decimal (exact_decimal_from_finite) -- see that
        // function's comment for why the base-10 route blows past numetron's single-limb udiv fast
        // path for essentially any real float input.
        double val = static_cast<double>(value.as<numetron::decimal_view>());
        return to_fixed_string_from_finite(val, digits, mode);
    }
    default:
        // decimal itself, and every integral source (fixed-width int, bigint integer) -- none of
        // these go through Dragonbox when read as a decimal_view (see
        // sonia::invocation::from_blob<basic_decimal_view<LimbT>>), so this is already exact.
        return to_fixed_decimal_string(value.as<numetron::decimal_view>(), digits, mode);
    }
}

} // namespace annium
