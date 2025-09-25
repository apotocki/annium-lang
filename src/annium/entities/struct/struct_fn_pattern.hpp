//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/internal_fn_pattern.hpp"

namespace annium {

class struct_fn_pattern : public internal_fn_pattern
{
    //using struct_body_t = variant<field_list_t, statement_span>;
    using struct_body_t = field_list_t;
    struct_body_t body_;

public:
    explicit struct_fn_pattern(struct_body_t const&);

    error_storage init(fn_compiler_context&, annotated_qname const&, parameter_list_t const&);

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;
};

}
