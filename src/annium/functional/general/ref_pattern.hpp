//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// An overload on the `ref` functional, alongside `typefn ref(of: typename)` (bootstrap.ann) --
// `ref(of: i32)` (constexpr type argument) resolves to that typefn; `ref(x)` (a single runtime
// argument) resolves here. Given any argument, returns it unchanged if it's already a reference,
// otherwise turns it into one -- see ref_pattern.cpp's try_match for the mechanism (never inspects
// the argument's raw expression; resolves it twice through prepared_call::session's own cached,
// type-keyed argument resolution instead).
class ref_pattern : public functional::pattern
{
public:
    ref_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "ref(self: runtime auto)->ref(of: auto)"sv; }
};

}
