//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// Handles addition between any two numeric types (bool excluded -- it's a cast source, not an
// arithmetic operand) without requiring an explicit numeric_cast. The result type is the
// "strongest" of the two operand types: see numeric_promotion.hpp's strongest_numeric_type().
//
// For constexpr values: computed entirely at compile time.
// For runtime values: delegates to the generic __plus_numeric extern (annium_operator_plus_numeric),
// which repeats the same strongest_numeric_type() join against the operands' actual runtime types.
// A literal operand paired with a runtime operand adapts to -- at most -- a minimal widening of
// the runtime operand's own type (see widen_for_literal_fit in numeric_promotion.hpp), rather than
// forcing promotion to the literal's own default type (bare integer literals default to `integer`).
class numeric_literal_plus_pattern : public functional::pattern
{
public:
    numeric_literal_plus_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override
    { return s << "plus(@is_numeric, @is_numeric)->strongest($0, $1)"sv; }
};

} // namespace annium
