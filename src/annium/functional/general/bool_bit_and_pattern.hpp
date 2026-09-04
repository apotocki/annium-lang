//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// Handles bitwise AND ('&') between two bool operands. bool isn't itself numeric (see
// numeric_promotion.hpp's is_numeric_eid/is_integral_kind_eid), so this is a separate, much
// simpler pattern from numeric_literal_bit_and_pattern: no widening, no promotion, both operands
// are always exactly bool. Unlike bootstrap.ann's short-circuiting __and (the '&&' operator),
// both operands are always evaluated -- '&' just runs `logical_not`'s sibling boolean-op family
// at runtime via the __bit_and_bool extern.
class bool_bit_and_pattern : public functional::pattern
{
public:
    bool_bit_and_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "bit_and(bool, bool)->bool"sv; }
};

} // namespace annium
