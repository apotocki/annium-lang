//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// Handles binary modulo (a % b) between any two numeric types (bool excluded -- it's a cast
// source, not an arithmetic operand) without requiring an explicit numeric_cast. Mirrors
// numeric_literal_div_pattern's shape exactly (same strongest_numeric_type() join, same
// operand-order-matters reasoning -- modulo isn't commutative either), with one simplification:
// decimal is rejected unconditionally, even when both operands are constexpr. Division has an
// exact-fraction escape hatch for decimal (try_divide_decimal_constexpr) because a fraction's
// exactness is a well-defined question; modulo's decimal semantics haven't been designed at all
// yet (see FUTURE_WORK.md), so there's no equivalent constexpr special case here.
//
// For constexpr values: computed entirely at compile time.
// For runtime values: delegates to the generic __mod_numeric extern (annium_operator_mod_numeric),
// which repeats the same strongest_numeric_type() join against the operands' actual runtime types.
class numeric_literal_mod_pattern : public functional::pattern
{
public:
    numeric_literal_mod_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override
    { return s << "modulo(@numeric, @numeric)->auto"sv; }
};

} // namespace annium
