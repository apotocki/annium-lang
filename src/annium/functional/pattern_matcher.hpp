//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/ast_terms.hpp"
#include "annium/errors.hpp"
#include "annium/functional/match_penalty.hpp"

namespace annium {

class fn_compiler_context;
class layered_binding_set;

class pattern_matcher
{
    fn_compiler_context& ctx_;
    layered_binding_set& bindings_;
    semantic::expression_list_t& expressions_;

    using fields_t = span<const syntax_pattern::field>;

    mutable fields_t::iterator fld_bit, fld_it, fld_end;

    match_penalty & penalty;
    mutable size_t hierarchy_level;

public:
    inline pattern_matcher(fn_compiler_context& ctx, layered_binding_set& bindings, semantic::expression_list_t& expressions, match_penalty& penalty_ref, size_t hlevel = 0) noexcept
        : ctx_{ ctx }, bindings_{ bindings }, expressions_{ expressions }, penalty{ penalty_ref }, hierarchy_level{ hlevel }
    {}

    error_storage match(syntax_pattern const&, annotated_entity_identifier const& type) const;

private:
    error_storage do_match(syntax_pattern::signature_descriptor const&, syntax_pattern const&, annotated_entity_identifier const&) const;

    error_storage do_match_context_identifier(context_identifier, syntax_pattern const&, annotated_entity_identifier const&) const;
    error_storage do_match_concepts(span<const syntax_expression>, annotated_entity_identifier const&) const;

    error_storage do_match_positioned_ellipsis_field(annotated_identifier boundid, span<const field_descriptor>& smplfields) const;
    //void finalize_ellipsis(identifier boundid, span<field_descriptor>) const;

    //error_storage match_signature_name(
    //    variant<placeholder, annotated_qname, context_identifier, syntax_expression> const& name,
    //    entity_signature const& sig, 
    //    annotated_entity_identifier const& type) const;

    inline void append_penalty_for_placeholder() const
    {
        if (penalty.placeholders.size() <= hierarchy_level) {
            penalty.placeholders.resize(hierarchy_level + 1, 0);
        }
        ++penalty.placeholders[hierarchy_level];
    }
};

}
