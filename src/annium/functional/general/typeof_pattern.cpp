//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "typeof_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> typeof_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);
    auto arg_descr = call_session.get_next_positioned_argument();
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));
    
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
    pmd->signature.result.emplace(get_result_type(ctx.env(), arg_descr->result), true);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> typeof_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return syntax_expression_result {
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

}
