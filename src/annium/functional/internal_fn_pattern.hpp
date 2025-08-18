//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
#include "basic_fn_pattern.hpp"

namespace annium {

class internal_fn_pattern : public basic_fn_pattern
{
    statement_span body_;
    fn_kind kind_;

public:
    using basic_fn_pattern::basic_fn_pattern;

    using basic_fn_pattern::init;
    error_storage init(fn_compiler_context&, fn_decl_t const&);

    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

protected:
    void build_scope(environment&, functional_match_descriptor&, internal_function_entity& /* out */) const;

    // builds entity that represents the function
    virtual shared_ptr<entity> build(fn_compiler_context&, functional_match_descriptor&, entity_signature&&) const;
};

}
