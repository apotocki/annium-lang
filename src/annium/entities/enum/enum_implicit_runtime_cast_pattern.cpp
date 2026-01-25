//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "enum_implicit_runtime_cast_pattern.hpp"
#include "enum_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> enum_implicit_runtime_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected an enumeration result"sv));
    }
    if (!can_be_only_runtime(exp.modifier)) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a runtime enumeration result"sv));
    }
    environment& env = ctx.env();
    entity const& enum_ent = get_entity(env, exp.type);
    
    enum_entity const* penum = dynamic_cast<enum_entity const*>(&enum_ent);
    if (!penum) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "an enumeration"sv));
    }

    auto call_session = call.new_session(ctx);
    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::constexpr_or_runtime_value });
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));
    
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    // .type = enum_ent.id,
    entity_identifier rtid = get_result_type(ctx.env(), arg_descr->result);
    if (rtid != exp.type) {
        return std::unexpected(make_error<type_mismatch_error>(arg_descr->expression->location, rtid, exp.type));
    }

    functional_match_descriptor_ptr pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
    pmd->signature.result.emplace(exp.type, false);
    return pmd;
}


std::expected<syntax_expression_result, error_storage> enum_implicit_runtime_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto &[_, ser, argloc] = md.matches.front();

    if (!ser.is_const_result) {
        return ser;
    }
    
    syntax_expression_result result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = false
    };

    entity const& ent = get_entity(ctx.env(), ser.value());
    size_t which = static_cast<generic_literal_entity const&>(ent).value().as<size_t>();

    if (!result.is_const_result) {
        ctx.env().push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(which) } });
    }
    return result;
}

}
