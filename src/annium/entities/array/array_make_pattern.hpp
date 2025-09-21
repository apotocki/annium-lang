//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

// creates instance of vector
// fn make_vector(of $T: typename, ~ $T ...) -> vector(of: $T);
class array_make_pattern : public functional::pattern
{
public:
    array_make_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "make_array(of $T: typename, ~ $T ...) ~> array(of: $T)"sv; }

private:
    class vector_make_match_descriptor : public functional_match_descriptor
    {
    public:
        using functional_match_descriptor::functional_match_descriptor;
        
        entity_identifier element_type;
    };
};

}