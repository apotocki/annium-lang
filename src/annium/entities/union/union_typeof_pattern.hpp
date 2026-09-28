//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// typeof(typename ~union, integer|__identifier) -> typename
// Reflection over a union's own case list, by position or by (possibly short) case name --
// the typename counterpart of union_get_pattern (which returns a *value* for a bare case only).
// A bare/const case has no type of its own beyond the atom it is, so it reports back
// `typename ::__identifier` honestly rather than something more specific; a structural case
// reports its own struct type directly. A by-name lookup matching more than one case (only
// possible for a hand-built union combining differently-namespaced same-named cases, never for
// a plain `enum`) reports back a `union(...)` of every match's type instead of picking one --
// see RESOLVED.md's `EnumName.CaseName(args)` entry for how this is used (the `::invoke` overload
// in bootstrap.ann it backs).
class union_typeof_pattern : public functional::pattern
{
public:
    union_typeof_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "typeof(typename ~union, integer|__identifier)->typename"sv; }
};

}
