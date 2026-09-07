//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "ref_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> ref_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    // Resolve the sole argument unconstrained first -- through the normal, sanctioned argument
    // resolution path, never by inspecting its raw expression. If it isn't already a reference,
    // build ref(of: <the type just learned>) and resolve the SAME argument again with that as the
    // expected type: this re-runs base_expression_visitor::visit on the unchanged raw expression,
    // and if it's a plain, non-weak local variable, the existing try_take_reference fires naturally
    // inside that second, ordinary visit -- see IMPLEMENTATION_NOTES.md's `ref(T)` section.
    auto arg_descr = call_session.get_next_positioned_argument("self"sv);
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    entity_identifier argtype = get_result_type(e, arg_descr->result);
    if (!try_decompose_ref_of(e, argtype)) {
        entity_identifier ref_type = make_ref_of_type(e, argtype);
        call_session.reuse_argument(arg_descr->arg_index);
        auto retry = call_session.get_next_positioned_argument(expected_result_t{ .type = ref_type, .modifier = value_modifier_t::runtime_value }, "self"sv);
        if (!retry) return std::unexpected(std::move(retry.error())); // not addressable -- the cast failure already says so
        arg_descr = std::move(retry);
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> ref_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    auto& [_, er, loc] = md.matches.front();
    return std::move(er);
}

}
