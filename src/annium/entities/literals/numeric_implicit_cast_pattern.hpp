//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/basic_fn_pattern.hpp"

namespace annium {

// const array to vector
// fn implicit_cast(integer) -> float16 => implementation defined
// fn implicit_cast(integer) -> float => implementation defined
// fn implicit_cast(integer) -> double => implementation defined
// fn implicit_cast(integer) -> decimal => implementation defined

class numeric_implicit_cast_pattern : public functional::pattern
{
public:
    numeric_implicit_cast_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "implicy_cast(runtime @literal)->auto"sv; }
};

}
