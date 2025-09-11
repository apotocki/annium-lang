//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "string_implicit_cast_pattern.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> string_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    if (exp.type && exp.type != env.get(builtin_eid::string))
    {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "a string type"sv));
    }

    entity_identifier teid = exp.type;
    if (!teid) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a runtime numeric result"sv));
    }

    auto call_session = call.new_session(ctx);
    std::pair<syntax_expression_t const*, size_t> arg_expr;
    auto src_arg = call_session.use_next_positioned_argument(&arg_expr);
    if (!src_arg) {
        if (src_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                std::move(src_arg.error())));
        } else {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result_t& src_arg_er = src_arg->first;
    entity_identifier source_type_id;
    entity const* source_type_entity = nullptr;
    if (src_arg_er.is_const_result) {
        source_type_entity = &get_entity(env, src_arg_er.value());
        source_type_id = source_type_entity->get_type();
    } else {
        source_type_id = src_arg_er.type();
    }
    if (source_type_id != env.get(builtin_eid::string)) {
        return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), source_type_id, "a string type"sv));
    }
    

    functional_match_descriptor_ptr pmd = sonia::make_shared<functional_match_descriptor>(call);
    pmd->emplace_back(0, src_arg_er);
    pmd->signature.emplace_back(src_arg_er.value_or_type, src_arg_er.is_const_result);
    if (can_be_only_runtime(exp.modifier)) {
        pmd->signature.result.emplace(source_type_id, false);
    } else if (can_be_only_constexpr(exp.modifier)) {
        if (!src_arg_er.is_const_result) {
            return std::unexpected(make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "a constexpr argument is required"sv));
        }
        pmd->signature.result.emplace(src_arg_er.value(), true);
    } else {
        pmd->signature.result.emplace(src_arg_er.value_or_type, src_arg_er.is_const_result);
    }
    return std::move(pmd);
}

std::expected<syntax_expression_result_t, error_storage> string_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& [_, src, loc] = md.matches.front();
    auto const& sig_res = *md.signature.result;
    if (!sig_res.is_const() && src.is_const_result) {
        // arg is constexpr and result is runtime
        environment& env = ctx.env();
        generic_literal_entity const& str_ent = static_cast<generic_literal_entity const&>(get_entity(env, src.value()));
        ctx.env().push_back_expression(el, src.expressions, semantic::push_value{ smart_blob{ str_ent.value() } });
        src.is_const_result = false;
        src.value_or_type = env.get(builtin_eid::string);
    }
    return std::move(src);
}

}
