//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "metaobject_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/ct_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> metaobject_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    size_t pos_arg_num = 0;
    auto pmd = make_shared<functional_match_descriptor>();
    for (auto const& arg : call.args) {
        ct_expression_visitor evis{ ctx, call.expressions };
        auto res = apply_visitor(evis, arg.value());
        if (!res) return std::unexpected(std::move(res.error()));

        annotated_identifier const* pargname = arg.name();
        parameter_match_result* pmr = pargname ? &pmd->get_match_result(pargname->value) : &pmd->get_match_result(pos_arg_num++);
        pmr->append_result(*res);
    }
    return pmd;
}

std::expected<syntax_expression_result_t, error_storage> metaobject_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    
    THROW_NOT_IMPLEMENTED_ERROR("metaobject_pattern::apply is not implemented yet");
#if 0
    entity_signature sig = md.build_signature(e, e.get(builtin_qnid::metaobject));
    sig.result = field_descriptor{ e.get(builtin_eid::metaobject) };

    return syntax_expression_result_t{
        .expressions = md.merge_void_spans(el),
        .value_or_type = e.make_basic_signatured_entity(std::move(sig)).id,
        .is_const_result = true
    };
#endif
}

}
