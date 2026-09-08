//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

class tuple_get_pattern : public functional::pattern
{
public:
    tuple_get_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    
    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "get(self: tuple(...), property: integer|__identifier)~>auto"sv; }

protected:
    class tuple_get_match_descriptor : public functional_match_descriptor
    {
    public:
        inline tuple_get_match_descriptor(prepared_call const& call, entity const& ent, entity_signature const& sig) noexcept
            : functional_match_descriptor{ call }
            , tpl_entity{ ent }
            , arg_sig{ sig }
        {}

        entity const& tpl_entity;
        entity_signature const& arg_sig;

        // Empty when `self` is a plain tuple value; otherwise `self` (matches[0], read via `slfer`
        // in apply) IS a `ref(of: self_ref_of)` -- self_ref_of is that tuple's own type (never the
        // ref(of:...) entity itself). Decided once in try_match, by resolving `self` in a single pass
        // with the `runtime_reference` modifier when `want_ref_result` is set -- see
        // IMPLEMENTATION_NOTES.md's `ref(T)` section for why this never inspects self's raw
        // expression.
        entity_identifier self_ref_of;

        // Whether this get() call's own caller wants ITS result to be a reference -- captured from
        // try_match's `exp` (either exp.type itself decomposes as ref(of:...), or exp.modifier carries
        // `runtime_reference` with no specific type prescribed), since apply() has no access to `exp`.
        // Used only to decide apply()'s output shape (keep the field as a reference vs. dereference
        // it); independent of self_ref_of (self can be a reference while this particular call's own
        // result isn't wanted as one, e.g. `let x: i32 = ref(t).0;`). When true, apply() presents the
        // field as ref(of: <the field's own natural type>) -- freshly derived, not a type prescribed
        // by the caller -- and leaves any actual type mismatch (e.g. `let x: ref(of: u8) = t.0;` where
        // field 0 is really i32) for the ordinary apply_cast that wraps this whole call to catch.
        bool want_ref_result = false;
    };
};

}
