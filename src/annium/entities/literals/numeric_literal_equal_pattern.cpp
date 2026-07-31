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

#include <stdexcept>

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

// A constexpr numeric literal's value, tagged by which native representation it's stored in --
// mirrors the blob layout produced by ui64_blob_result/f16_blob_result/f32_blob_result/f64_blob_result/
// decimal_blob_result (sonia-prime's invocation.hpp): every fixed-width and bigint integral type
// (including boolean, folded to 0/1) is stored as numetron::integer_view.
struct extracted_numeric_value
{
    enum class kind { integral, f16, f32, f64, decimal } k;
    numetron::integer_view iv{};
    numetron::float16 f16v{};
    float f32v = 0;
    double f64v = 0;
    numetron::decimal_view decv{};
};

extracted_numeric_value extract_numeric_value(smart_blob const& value, builtin_eid type)
{
    using kind = extracted_numeric_value::kind;
    switch (type) {
        case builtin_eid::boolean:
            return { .k = kind::integral, .iv = numetron::integer_view{ value.as<bool>() ? 1 : 0 } };
        case builtin_eid::integer:
        case builtin_eid::i8:
        case builtin_eid::u8:
        case builtin_eid::i16:
        case builtin_eid::u16:
        case builtin_eid::i32:
        case builtin_eid::u32:
        case builtin_eid::i64:
        case builtin_eid::u64:
            return { .k = kind::integral, .iv = value.as<numetron::integer_view>() };
        case builtin_eid::f16:
            return { .k = kind::f16, .f16v = value.as<numetron::float16>() };
        case builtin_eid::f32:
            return { .k = kind::f32, .f32v = value.as<float>() };
        case builtin_eid::f64:
            return { .k = kind::f64, .f64v = value.as<double>() };
        case builtin_eid::decimal:
            return { .k = kind::decimal, .decv = value.as<numetron::decimal_view>() };
        default:
            throw std::logic_error("extract_numeric_value: not a numeric type"); // guarded by is_numeric_type at the call site
    }
}

inline bool is_floating_kind(extracted_numeric_value::kind k) noexcept
{
    using kind = extracted_numeric_value::kind;
    return k == kind::f16 || k == kind::f32 || k == kind::f64;
}

// Widens a floating-ish or decimal value to double. Always exact for f16/f32 (lossless widening) and
// f64 (identity); for decimal this is the same lossy-above-53-bits conversion this function already
// used before, kept only for the decimal-vs-floating pair, which no test currently exercises.
double to_double(extracted_numeric_value const& v) noexcept
{
    using kind = extracted_numeric_value::kind;
    switch (v.k) {
        case kind::f16: return static_cast<double>(v.f16v);
        case kind::f32: return static_cast<double>(v.f32v);
        case kind::f64: return v.f64v;
        case kind::decimal: return static_cast<double>(v.decv);
        default: return static_cast<double>(v.iv); // unreachable from this file's call sites; kept for switch exhaustiveness
    }
}

// Extract and compare two constexpr numeric literal values, mirroring annium_any_equal's runtime
// category split (annium_library.cpp): same-family pairs (integral vs integral, decimal vs decimal)
// compare natively and exactly. The cross-family pair that needs care is integral-ish (fixed-width int
// or bigint) vs floating-ish (f16/f32/f64): converting the INTEGRAL side to double would be lossy
// above double's 53 exact mantissa bits, silently colliding distinct large values (see BUGFIXES.md).
// numetron::basic_integer_view::operator==(T floating) avoids that by decomposing the float's own
// IEEE754 bits (exact for any finite whole-number float) instead of rounding the integer.
bool compare_constexpr_literal_values(generic_literal_entity const* lhs_entity, generic_literal_entity const* rhs_entity,
                                      builtin_eid lhs_type, builtin_eid rhs_type)
{
    using kind = extracted_numeric_value::kind;
    extracted_numeric_value lhs = extract_numeric_value(lhs_entity->value(), lhs_type);
    extracted_numeric_value rhs = extract_numeric_value(rhs_entity->value(), rhs_type);

    if (lhs.k == kind::integral && rhs.k == kind::integral) return lhs.iv == rhs.iv;
    if (lhs.k == kind::decimal && rhs.k == kind::decimal) return lhs.decv == rhs.decv;

    // integral <-> decimal: exact, since constructing a decimal from an integer_view is exact (no
    // dragonbox shortest-round-trip float formatting involved, unlike decimal-from-float).
    if (lhs.k == kind::integral && rhs.k == kind::decimal) return numetron::decimal{ lhs.iv } == rhs.decv;
    if (lhs.k == kind::decimal && rhs.k == kind::integral) return numetron::decimal{ rhs.iv } == lhs.decv;

    // integral <-> floating: the exact cross-family path this function used to get wrong.
    if (lhs.k == kind::integral && is_floating_kind(rhs.k)) return lhs.iv == to_double(rhs);
    if (is_floating_kind(lhs.k) && rhs.k == kind::integral) return rhs.iv == to_double(lhs);

    // Both floating-ish (any width, including decimal-vs-float): widening f16/f32 to double is always
    // exact, so a plain double comparison is correct here.
    return to_double(lhs) == to_double(rhs);
}

} // anonymous namespace

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_literal_equal_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();

    auto call_session = call.new_session(ctx);
    
    // Get first argument
    auto lhs_descr = call_session.get_next_positioned_argument();
    if (!lhs_descr) return std::unexpected(std::move(lhs_descr.error()));

    syntax_expression_result & lhs_arg_er = lhs_descr->result;
    
    entity_identifier lhs_type_id;
    entity const* lhs_type_entity = nullptr;
    if (lhs_arg_er.is_const_result) {
        lhs_type_entity = &get_entity(e, lhs_arg_er.value());
        lhs_type_id = lhs_type_entity->get_type();
    } else {
        lhs_type_id = lhs_arg_er.type();
    }
    builtin_eid lhs_type = static_cast<builtin_eid>(lhs_type_id.value);
    resource_location lhs_arg_loc = lhs_descr->expression->location;
    // Check if first argument is numeric
    if (!is_numeric_type(lhs_type)) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_arg_loc, lhs_type_id, "a numeric literal type"sv));
    }

    // Get second argument
    auto rhs_descr = call_session.get_next_positioned_argument();
    if (!rhs_descr) return std::unexpected(std::move(rhs_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result & rhs_arg_er = rhs_descr->result;
    
    entity_identifier rhs_type_id;
    entity const* rhs_type_entity = nullptr;
    if (rhs_arg_er.is_const_result) {
        rhs_type_entity = &get_entity(e, rhs_arg_er.value());
        rhs_type_id = rhs_type_entity->get_type();
    } else {
        rhs_type_id = rhs_arg_er.type();
    }
    builtin_eid rhs_type = static_cast<builtin_eid>(rhs_type_id.value);
    resource_location rhs_arg_loc = rhs_descr->expression->location;

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
    pmd->append_arg(lhs_arg_er, lhs_arg_loc);
    pmd->append_arg(rhs_arg_er, rhs_arg_loc);

    // Result is boolean, constexpr if both arguments are constexpr
    bool is_constexpr_result = lhs_arg_er.is_const_result && rhs_arg_er.is_const_result;
    if (!is_constexpr_result) {
        pmd->signature.result.emplace(e.get(builtin_eid::boolean), false);
    }

    return pmd;
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
            append_semantic_result(el, lhs_src, result);
        }

        // Handle right argument
        if (rhs_src.is_const_result) {
            // Convert constexpr to runtime value
            e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ nmd.rhs_arg->value() } });
        } else {
            // Use runtime value
            append_semantic_result(el, rhs_src, result);
        }

        // Generate runtime equality check
        e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::equal)));

        return result;
    }
}

} // namespace annium