//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

class enum_implicit_runtime_cast_pattern : public functional::pattern
{
public:
    enum_implicit_runtime_cast_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "implicit_cast(@enumeration)->@enumeration"sv; }
};

}
