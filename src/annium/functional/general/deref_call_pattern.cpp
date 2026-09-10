//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "deref_call_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

namespace {

class deref_call_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    // The retry (method(...) with ref-typed arguments dereferenced) is already fully resolved and
    // applied by the time try_match returns -- apply() just hands this back. See try_match below
    // for why doing the real work eagerly here (rather than deferring it to apply()) is fine: this
    // pattern is only ever reached as a deliberate, single last-resort attempt (base_expression_
    // visitor's fallback calls find_and_apply directly), never as one of several competing
    // candidates whose speculative work would otherwise go to waste.
    syntax_expression_result final_result;
};

}

std::expected<functional_match_descriptor_ptr, error_storage> deref_call_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    auto method_descr = call_session.get_named_argument(e.get(builtin_id::method), expected_result_t{ .type = e.get(builtin_eid::qname), .modifier = value_modifier_t::constexpr_value });
    if (!method_descr) return std::unexpected(std::move(method_descr.error()));

    entity const& method_ent = get_entity(e, method_descr->result.value());
    functional_identifier_entity const* pqnent = dynamic_cast<functional_identifier_entity const*>(&method_ent);
    if (!pqnent || !pqnent->value()) {
        return std::unexpected(make_error<basic_general_error>(method_descr->expression->location, "deref_call's `method` must name a real functional"sv));
    }
    qname_identifier target_qnid = pqnent->value();

    // Every remaining argument is one the ORIGINAL (failed) call was given, forwarded here as-is by
    // base_expression_visitor's fallback. Resolve each on its own -- unconstrained, exactly the way
    // the original call's own try_match would have resolved it in isolation -- and, for any whose
    // own type is ref(of: T), wrap it in get(self: ...) before re-packaging it as an argument for
    // the retry. A discarded resolution attempt is a dead, unspliced expression_list_t span, safe to
    // abandon (see IMPLEMENTATION_NOTES.md's `ref(T)` section, "A discarded resolution attempt...").
    call_builder retry_call{ call.location };
    bool any_deref = false;
    for (;;) {
        prepared_call::argument_descriptor_t adescr;
        auto has_more = call_session.use_next_argument(expected_result_t{}, &adescr);
        if (!has_more) return std::unexpected(std::move(has_more.error()));
        if (!*has_more) break;

        syntax_expression_result arg_result = std::move(adescr.result);
        entity_identifier ref_of = try_decompose_ref_of(e, get_result_type(e, arg_result));

        if (ref_of) {
            call_builder get_call{ adescr.expression->location };
            get_call.emplace_back(e.get(builtin_id::self), make_indirect_value(e, call.expressions, std::move(arg_result), adescr.expression->location));
            auto deref_res = ctx.find_and_apply(builtin_qnid::get, get_call, call.expressions, expected_result_t{});
            if (!deref_res) return std::unexpected(std::move(deref_res.error()));
            arg_result = std::move(*deref_res);
            any_deref = true;
        }

        syntax_expression new_expr = arg_result.is_const_result
            ? make_indirect_expression(e, call.expressions, std::move(arg_result), adescr.expression->location)
            : make_indirect_value(e, call.expressions, std::move(arg_result), adescr.expression->location);

        if (adescr.name) {
            retry_call.emplace_back(adescr.name, std::move(new_expr));
        } else {
            retry_call.emplace_back(std::move(new_expr));
        }
    }

    if (!any_deref) {
        // Nothing was actually ref-typed -- this fallback has nothing to offer that the original
        // call didn't already try itself; decline so the caller's ORIGINAL error is what surfaces.
        return std::unexpected(make_error<basic_general_error>(call.location, "deref_call: no ref(of: T) argument to dereference"sv));
    }

    // find_and_apply only has a builtin_qnid overload -- target_qnid is a plain qname_identifier
    // (deref_call itself is never reached with a builtin_qnid directly), so find()+apply() by hand,
    // the same two-step make_function_call's own qname branch uses.
    auto retry_match = ctx.find(target_qnid, call.location, retry_call, call.expressions, exp);
    if (!retry_match) return std::unexpected(std::move(retry_match.error()));
    auto retry_res = retry_match->apply(ctx);
    if (!retry_res) return std::unexpected(std::move(retry_res.error()));

    auto pmd = make_shared<deref_call_match_descriptor>(call);
    pmd->final_result = std::move(*retry_res);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> deref_call_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return std::move(static_cast<deref_call_match_descriptor&>(md).final_result);
}

}
