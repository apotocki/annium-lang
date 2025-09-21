//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/basic_fn_pattern.hpp"

namespace annium {

// const array to array
// fn implicit_cast(array(element: _, size: $Sz)) -> array(element: _, size: $Sz) => implementation defined
class fixed_array_elements_implicit_cast_pattern : public functional::pattern
{
public:
    fixed_array_elements_implicit_cast_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "implicit_cast(~array(of, size))~>array(of)"sv; }
};

}
