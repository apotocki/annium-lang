//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// deref_call(method: constexpr qname, args: ...) -- last-resort fallback for a call that matched
// nothing: retries `method` (the ORIGINAL call's own functional) with every argument whose own
// type is ref(of: T) transparently dereferenced first. Called directly by
// base_expression_visitor::operator()(FnIdT&&, args) (base_expression_visitor.ipp) whenever the
// direct call fails -- covers every current and future operator/function uniformly (`y + 1`,
// `y + z` with both ref, ...) with no per-function ref(T) awareness needed.
//
// Registered with `default_pattern_implementation_weight` (like equal_pattern/to_string_pattern) --
// a genuinely low-priority, generic catch-all: an `.ann`-declared `fn ::deref_call(...)` overload
// with a more specific signature can intercept particular cases ahead of this one, giving user code
// a real way to override the fallback's behavior without touching the compiler. See
// IMPLEMENTATION_NOTES.md's `ref(T)` section.
class deref_call_pattern : public functional::pattern
{
public:
    inline deref_call_pattern() noexcept : functional::pattern{ functional::default_pattern_implementation_weight } {}

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "deref_call(method: constexpr qname, args: ...)->auto"sv; }
};

}
