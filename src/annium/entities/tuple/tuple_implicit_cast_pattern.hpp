//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// Pattern for implicit casting between tuples with matching field names and count.
class tuple_implicit_cast_pattern : public functional::pattern
{
public:
    tuple_implicit_cast_pattern() = default;

    // Attempts to match a call for tuple implicit cast.
    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const override;

    // Applies the cast, producing the result tuple if all fields can be cast.
    std::expected<syntax_expression_result_t, error_storage>
    apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "implicit_cast(@tuple)->@tuple"sv; }
};

} // namespace annium
