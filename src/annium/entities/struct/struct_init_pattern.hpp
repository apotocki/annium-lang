//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/basic_fn_pattern.hpp"

namespace annium {

class struct_init_pattern : public basic_fn_pattern
{
    parameter_list_t body_parameters_;
    //variant<field_list_t, statement_span> body_;

public:
    explicit struct_init_pattern(variant<field_list_t, statement_span> const&);
    error_storage init(fn_compiler_context& ctx, annotated_entity_identifier result); // result is a defined entity
    error_storage init(fn_compiler_context& ctx, annotated_qname fname, parameter_list_t const& fparameters); // result is a functional name with parameters

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override;
};

}
