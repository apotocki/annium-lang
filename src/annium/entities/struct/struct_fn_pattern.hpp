//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/basic_fn_pattern.hpp"

namespace annium {

class struct_fn_pattern : public basic_fn_pattern
{
    //using struct_body_t = variant<span<const field>, span<const statement>>;
    using struct_body_t = span<const field>;
    struct_body_t body_;

public:
    explicit struct_fn_pattern(struct_body_t const&);

    error_storage init(fn_compiler_context&, annotated_qname const&, span<const parameter>);

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;
};

}
