//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// Handles bitwise OR ('|') between any two integral-kind operands (i8..u64, integer) without
// requiring an explicit numeric_cast. Mirrors numeric_literal_bit_and_pattern (see its comment)
// -- same constexpr-fold and literal-widening machinery, restricted to is_integral_kind_eid.
// bool's own '|' goes through the separate, non-numeric bool_bit_or_pattern instead;
// typename '|' (union-type construction) is a distinct overload registered under the same
// "__bit_or" qname by union_bit_or_pattern.
class numeric_literal_bit_or_pattern : public functional::pattern
{
public:
    numeric_literal_bit_or_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override
    { return s << "bit_or(integral, integral)->auto"sv; }
};

} // namespace annium
