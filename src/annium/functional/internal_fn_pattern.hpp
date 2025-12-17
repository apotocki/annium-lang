//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
#include "basic_fn_pattern.hpp"

namespace annium {

class internal_fn_pattern : public basic_fn_pattern
{
    basic_signatured_entity const * captures_ = nullptr;
    span<const statement> body_;
    fn_kind kind_;

public:
    using basic_fn_pattern::basic_fn_pattern;

    using basic_fn_pattern::init;
    error_storage init(fn_compiler_context&, fn_decl const&);

    inline void set_captures(basic_signatured_entity const& captures) noexcept { captures_ = &captures; }

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

protected:
    shared_ptr<internal_function_entity> build(fn_compiler_context&, entity_signature&&, basic_functional_binding&&) const override;
    void build_scope(environment&, basic_functional_binding&&, internal_function_entity& /* out */) const override;
};

}
