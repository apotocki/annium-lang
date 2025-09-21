//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// Handles implicit cast between numeric literals (bool, integer, decimal, etc) for both runtime and constexpr values.
// The pattern is matched only when the cast is possible without precision loss.
// 
// For constexpr values: The actual value is checked at compile time to ensure it fits in the target type
// without precision loss. For example, a constexpr integer 100 can be converted to u8, but 300 cannot.
//
// For runtime values: Only conversions that are always safe are allowed. For example, u8 can always be
// converted to u16, but u16 to u8 is never allowed for runtime values since it could cause precision loss.
class numeric_literal_implicit_cast_pattern : public functional::pattern
{
public:
    numeric_literal_implicit_cast_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override
    { return s << "implicy_cast(:integer|decimal|bool|i8|u8|i16|u16|i32|u32|i64|u64|f16|f32|f64)->integer|decimal|bool|i8|u8|i16|u16|i32|u32|i64|u64|f16|f32|f64"sv; }
};

} // namespace annium
