//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// creates instance of array
// fn make_array(of $T: typename, $elements: ~ $T ...) ~> array(of: $T, size: size($elements));
// or
// fn make_array($elements ...) ~> array(of: union(typeof($elements)...), size: size($elements)); // array element type is inferred from elements 
class array_make_pattern : public functional::pattern
{
public:
    array_make_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "make_array(of?: typename, ...)~>array(...)"sv; }
};

}