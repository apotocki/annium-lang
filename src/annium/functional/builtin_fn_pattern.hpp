//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "basic_fn_pattern.hpp"

namespace annium {

class builtin_function_entity;

class builtin_fn_pattern : public basic_fn_pattern
{
    shared_ptr<builtin_function_entity> ent_;

public:
    builtin_fn_pattern() = default;

    void set_result_entity(shared_ptr<builtin_function_entity> e) { ent_ = std::move(e); }

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;
};

}
