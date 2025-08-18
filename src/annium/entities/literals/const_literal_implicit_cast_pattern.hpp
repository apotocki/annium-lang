//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// Handles implicit cast of compile-time literals (bool, string, integer, decimal) to both runtime and constexpr values.
// Supports conversion between all numeric literal types: i8, u8, i16, u16, i32, u32, i64, u64, f16, f32, f64.
// Conversions are checked for precision loss at the apply stage.
// Float values can be converted to integers only if they don't have a fractional part.
// When expected result is constexpr, returns new constexpr literal entities with converted values.
// When expected result is runtime, returns runtime blob values.
class const_literal_implicit_cast_pattern : public functional::pattern
{
public:
    const_literal_implicit_cast_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const override;

    std::expected<syntax_expression_result_t, error_storage>
    apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "implicy_cast(constexpr bool|integer|decimal|string)->numeric_type"sv; }
};

} // namespace annium
