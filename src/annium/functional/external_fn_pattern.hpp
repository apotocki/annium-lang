//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "basic_fn_pattern.hpp"

namespace annium {

class external_function_entity;

class external_fn_pattern : public basic_fn_pattern
{
    size_t extfnid_;
    shared_ptr<external_function_entity> ent_;

public:
    inline explicit external_fn_pattern(size_t extfnid) noexcept
        : extfnid_{ extfnid }
    {}

    void set_result_entity(shared_ptr<external_function_entity> e) { ent_ = std::move(e); }
        
    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;
};

}
