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

std::expected<functional_match_descriptor_ptr, error_storage> typeof_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto call_session = call.new_session(ctx);
    auto arg = call_session.use_next_positioned_argument(exp);
    if (!arg) return std::unexpected(arg.error());
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->emplace_back(0, arg->first);
    return std::move(pmd);
}

std::expected<syntax_expression_result, error_storage> typeof_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto & er = get<1>(md.matches.front());

    return syntax_expression_result {
        .value_or_type = er.is_const_result ? get_entity(ctx.env(), er.value()).get_type() : er.type(),
        .is_const_result = true
    };
}

}
