//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "ref_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> ref_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    // Ask for a reference directly via `runtime_reference` -- a hard requirement, not a preference:
    // if the argument can't be turned into a reference (not a plain, non-weak local variable, or
    // already something else entirely), this resolve fails outright and that failure is the real
    // error (no separate cast-failure step needed). try_take_reference derives ref(of:...) from
    // whatever the argument actually resolves to, so its plain type never needs to be known up front
    // -- unlike the old two-request retry (resolve unconstrained, learn the type, resolve again with
    // ref(of: <that type>)), which cost a full second resolution of the argument every time. If the
    // argument is already a reference, this is a no-op pass-through, same as before. Never inspect
    // the argument's raw expression. See IMPLEMENTATION_NOTES.md's `ref(T)` section.
    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::runtime_reference }, "self"sv);
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    // `runtime_reference` only enables producing a reference where possible -- it doesn't by itself
    // reject a resolution that came back without one (apply_cast never objects when `.type` is left
    // unconstrained, which it must be here, since the argument's plain type isn't known up front).
    // Since ref(x) has nothing useful to return otherwise, check explicitly.
    entity_identifier argtype = get_result_type(e, arg_descr->result);
    if (!try_decompose_ref_of(e, argtype)) {
        return std::unexpected(make_error<type_mismatch_error>(arg_descr->expression->location, argtype, "an addressable value (a reference could not be taken)"sv));
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
