//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "deref_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> deref_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto call_session = call.new_session(ctx);
    
    auto arg_descr = call_session.get_next_positioned_argument(exp);
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    auto argerror = [&arg_descr] {
        return std::unexpected(make_error<basic_general_error>(arg_descr->expression->location, "argument mismatch"sv, *arg_descr->expression));
    };
    syntax_expression_result& arg_er = arg_descr->result;
    if (!arg_er.is_const_result) return argerror();
    entity const& argent = get_entity(ctx.env(), arg_er.value());
    if (argent.get_type() != ctx.env().get(builtin_eid::qname)) return argerror();

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_er, arg_descr->expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> deref_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto & [_, ser, loc] = md.matches.front();

    BOOST_ASSERT(ser.is_const_result);
    qname_entity const& argent = static_cast<qname_entity const&>(get_entity(ctx.env(), ser.value()));

    syntax_expression expr{ md.call_location, qname_reference_expression{ argent.value() } };
    auto res = base_expression_visitor::visit(ctx, el, expr);
    if (!res) return std::unexpected(res.error());
    auto& er = res->first;
    er.expressions = el.concat(ser.expressions, er.expressions);
    er.temporaries.insert(er.temporaries.begin(), ser.temporaries.begin(), ser.temporaries.end());
    return std::move(er);
}

}
