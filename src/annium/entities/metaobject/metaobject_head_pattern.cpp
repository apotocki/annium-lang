//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "metaobject_head_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/ct_expression_visitor.hpp"

#include "annium/entities/signatured_entity.hpp"

namespace annium {

std::expected<syntax_expression_result_t, error_storage> metaobject_head_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    entity_signature const& objsignature = argument_signature(ctx, md);
    
    if (!objsignature.fields().empty()) {
        return std::unexpected(make_error<basic_general_error>(md.call_location, "metaobject is empty"sv));
    }
    return syntax_expression_result_t{
        .expressions = md.merge_void_spans(el),
        .value_or_type = objsignature.fields().front().entity_id(),
        .is_const_result = true
    };
}

}
