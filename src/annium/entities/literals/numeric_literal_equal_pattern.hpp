//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// Handles equality comparison between numeric literals (bool, integer, decimal, etc) for both runtime and constexpr values.
// The pattern compares any numeric type with another numeric type and returns a boolean result.
// 
// For constexpr values: The actual values are compared at compile time.
// For runtime values: The comparison is performed at runtime.
// If both arguments are constexpr, the result will be constexpr.
class numeric_literal_equal_pattern : public functional::pattern
{
public:
    numeric_literal_equal_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override
    { return s << "equal(@is_numeric, @is_numeric)->bool"sv; }
};

} // namespace annium