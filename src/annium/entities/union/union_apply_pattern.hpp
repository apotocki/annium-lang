//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

class union_apply_pattern : public functional::pattern
{
public:
    //union_apply_pattern() noexcept : functional::pattern{ numetron::decimal{ "0.1"sv } } {}

    std::expected<functional_match_descriptor_ptr, error_storage>
    try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage>
    apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override {
        return s << "apply(to: union(...), visitor: _)->auto";
    }
};

} // namespace annium