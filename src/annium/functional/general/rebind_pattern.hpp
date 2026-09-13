//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// rebind(self: ref(of: T), value: runtime ref(of: T)) -> ref(of: T) -- repoints `self` at a
// DIFFERENT target, overwriting self's own storage slot with a new reference value. The rare
// counterpart to `set(self: ~ref(of $T), value: runtime $T)` (bootstrap.ann), which writes
// THROUGH self to its current target instead -- see IMPLEMENTATION_NOTES.md's `ref(T)` section.
//
// Deliberately native, not `.ann`-declared like get/set: rebind needs a genuine reference to
// self's OWN slot (ref(of: ref(of: T))), not a copy of self's current value -- `~ref(of $T)`
// (get/set's self) only ever produces the latter. Getting the former requires self to go through
// base_expression_visitor::try_take_reference's "caller-prescribed exact type" path, which needs a
// concrete type known up front -- incompatible with `.ann`'s `$T`-capturing structural patterns,
// which only ever produce a plain-value self. try_match resolves self TWICE (an established,
// current technique -- see equal_pattern.cpp/prepared_call::session::reuse_argument) to learn its
// own type first, then re-requests it with that type wrapped one more time; see rebind_pattern.cpp.
class rebind_pattern : public functional::pattern
{
public:
    rebind_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "rebind(self: ref(of: auto), value: runtime ref(of: auto))->ref(of: auto)"sv; }
};

}
