//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "external_fn_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/functions/function_entity.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> external_fn_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    return basic_fn_pattern::try_match(ctx, call, exp);
}

std::expected<syntax_expression_result, error_storage> external_fn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto [result, _] = apply_arguments(ctx, el, md);

    e.push_back_expression(el, result.expressions, semantic::invoke_function(ent_->id));
    BOOST_ASSERT(md.signature.result);
    result.value_or_type = md.signature.result->entity_id();
    result.is_const_result = md.signature.result->is_const();
    return result;
}

//shared_ptr<entity> external_fn_pattern::build(fn_compiler_context& ctx, functional_match_descriptor&, entity_signature&& signature) const
//{
//    THROW_NOT_IMPLEMENTED_ERROR("external_fn_pattern::build");
//    //environment& e = ctx.env();
//    //return make_shared<external_function_entity>(e, fnl_.name() / e.new_identifier(), std::move(signature), extfnid_);
//}

}
