//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "metaobject_empty_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/ct_expression_visitor.hpp"

#include "annium/entities/signatured_entity.hpp"

namespace annium {

std::expected<syntax_expression_result_t, error_storage> metaobject_empty_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    entity_signature const& objsignature = argument_signature(ctx, md);
    return syntax_expression_result_t{
        .expressions = md.merge_void_spans(el),
        .value_or_type = ctx.env().get(objsignature.fields().empty() ? builtin_eid::true_ : builtin_eid::false_),
        .is_const_result = true
    };
}

}
