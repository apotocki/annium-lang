//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// to_integer(unionVal) -> the ordinal ("which") of unionVal's active member, in declaration order
// -- the generic, union-based replacement for the old enum-only enum_to_integer_pattern, now that
// every enum (bare or structural) desugars to a union. See IMPLEMENTATION_NOTES.md's "Retiring
// enum_entity" section.
class union_to_integer_pattern : public functional::pattern
{
public:
    union_to_integer_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "to_integer(:@union)->integer"sv; }
};

}
