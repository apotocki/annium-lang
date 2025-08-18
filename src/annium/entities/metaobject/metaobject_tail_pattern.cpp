//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "metaobject_tail_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/ct_expression_visitor.hpp"

#include "annium/entities/signatured_entity.hpp"

namespace annium {

std::expected<syntax_expression_result_t, error_storage> metaobject_tail_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();

    entity_signature const& objsignature = argument_signature(ctx, md);
    
    if (objsignature.fields().empty()) {
        return std::unexpected(make_error<basic_general_error>(md.call_location, "metaobject is empty"sv));
    }

    entity_signature tail_signature{ objsignature.name };
    tail_signature.result = objsignature.result;
    //auto nids = objsignature.named_fields_indices();
    auto pids = objsignature.positioned_fields_indices();
    if (!pids.front()) pids = pids.subspan(1);
    for (uint32_t i = 1; i < objsignature.fields().size(); ++i) {
        tail_signature.push_back(objsignature.fields()[i]);
        bool is_positional = !pids.empty() && pids.front() == i;
        if (is_positional) {
            pids = pids.subspan(1);
        }
    }

    return syntax_expression_result_t{
        .expressions = md.merge_void_spans(el),
        .value_or_type = e.make_basic_signatured_entity(std::move(tail_signature)).id,
        .is_const_result = true
    };
}

}
