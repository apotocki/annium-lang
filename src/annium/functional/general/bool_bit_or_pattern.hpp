//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// Handles bitwise OR ('|') between two bool operands. Mirrors bool_bit_and_pattern (see its
// comment) -- same shape, both operands always evaluated (unlike bootstrap.ann's short-circuiting
// __or, the '||' operator).
class bool_bit_or_pattern : public functional::pattern
{
public:
    bool_bit_or_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "bit_or(bool, bool)->bool"sv; }
};

} // namespace annium
