//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "qname_implicit_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> qname_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type || exp.type != ctx.env().get(builtin_eid::qname) || !can_be_constexpr(exp.modifier)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "qname"sv));
    }

    auto call_session = call.new_session(ctx);

    auto arg_descr = call_session.get_next_positioned_argument(
        expected_result_t{ .modifier = value_modifier_t::constexpr_value });
    if (!arg_descr) return std::unexpected(arg_descr.error());

    syntax_expression_result& arg_er = arg_descr->result;
    entity const& arg_ent = get_entity(ctx.env(), arg_er.value());

    entity_identifier arg_type = get_result_type(ctx.env(), arg_er);
    if (arg_ent.get_type() != ctx.env().get(builtin_eid::identifier)) {
        return std::unexpected(make_error<type_mismatch_error>(arg_descr->expression->location, arg_type, "__identifier"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    identifier_entity const& id_ent = static_cast<identifier_entity const&>(arg_ent);
    auto refent = ctx.lookup_entity(id_ent.value());

    entity_identifier const* eid = get_if<entity_identifier>(&refent);
    if (!eid || !*eid) {
        return std::unexpected(make_error<basic_general_error>(arg_descr->expression->location, "not a qname identifier"sv, id_ent.value()));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
    pmd->signature.result.emplace(*eid, true);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> qname_implicit_cast_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return syntax_expression_result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
    
    /*

    auto [_, ser, loc] = md.matches.front();
    
    identifier_entity const& id_ent = static_cast<identifier_entity const&>(get_entity(ctx.env(), ser.value()));

    auto refent = ctx.lookup_entity(id_ent.value());

    using result_type = std::expected<syntax_expression_result, error_storage>;
    return visit(match(
        [&id_ent, &loc, &ser](entity_identifier const& entid) -> result_type {
            if (entid) {
                ser.value_or_type = entid;
                ser.is_const_result = true;
                return ser;
            }
            return std::unexpected(make_error<undeclared_identifier_error>(loc, id_ent.value()));
        },
        [&ctx , &el](local_variable const& lvar) -> result_type {
            semantic::expression_span exprs_span;
            ctx.env().push_back_expression(el, exprs_span, semantic::push_local_variable::create(lvar));
            return syntax_expression_result{ .expressions = std::move(exprs_span), .value_or_type = lvar.type, .is_const_result = false };
        },
        [&ctx , &el](functional_variable const& fvar) -> result_type {
            semantic::expression_span exprs_span;
            ctx.env().push_back_expression(el, exprs_span, semantic::push_variable{ fvar });
            return syntax_expression_result{ .expressions = std::move(exprs_span), .value_or_type = fvar.type, .is_const_result = false };
        }
    ), refent);
    */
}

}
