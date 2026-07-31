//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_promotion.hpp"

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

namespace {

constexpr builtin_eid k_all_numeric_eids[] = {
    builtin_eid::i8, builtin_eid::u8, builtin_eid::i16, builtin_eid::u16,
    builtin_eid::i32, builtin_eid::u32, builtin_eid::i64, builtin_eid::u64,
    builtin_eid::f16, builtin_eid::f32, builtin_eid::f64,
    builtin_eid::integer, builtin_eid::decimal
};

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
    blob_result const* p = &b;
    while (p->type == blob_type::blob_reference) {
        p = data_of<blob_result>(*p);
    }

    switch (p->type) {
    case blob_type::bigint: return builtin_eid::integer;
    case blob_type::decimal: return builtin_eid::decimal;
    default: break;
    }

    blob_type decayed = (blob_type)(((uint8_t)p->type) & 0x7f);
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

} // namespace annium
