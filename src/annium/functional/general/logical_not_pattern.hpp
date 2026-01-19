//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

class logical_not_pattern : public functional::pattern
{
public:
    logical_not_pattern() = default;

    // Attempts to match a call with a single boolean argument
    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const override;

    // Applies the negation operation to the boolean argument
    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "logical_not(:@is_numeric)->boolean"sv; }
};

} // namespace annium