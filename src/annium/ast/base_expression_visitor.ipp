//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "base_expression_visitor.hpp"

#include "fn_compiler_context.hpp"

#include "annium/auxiliary.hpp"

// make_functional_identifier_entity(...).id below needs functional_identifier_entity's complete
// type (semantic_fwd.hpp only forward-declares literal_entity<T>) -- GCC (unlike MSVC, which
// apparently tolerated it as long as some other header completed the type later in the same TU)
// warns "invalid use of incomplete type" without this.
#include "annium/entities/literals/literal_entity.hpp"

namespace annium {

template <typename FnIdT>
inline base_expression_visitor::result_type base_expression_visitor::operator()(FnIdT&& fnid, span<const opt_named_expression_t> args) const
{
    auto match = ctx.find(std::forward<FnIdT>(fnid), context_expression_.location, args, expressions, expected_result);
    if (match) return apply_cast(match->apply(ctx));

    // Fallback: the direct call found nothing. Before giving up, ask deref_call (functional/
    // general/deref_call_pattern.cpp) to retry the SAME functional with any ref(of: T)-typed
    // argument transparently dereferenced -- covers every current and future operator/function
    // uniformly (`y + 1`, `y + z` with both ref, ...) without any of them needing to know about
    // ref(T) themselves. Routed through an ordinary, low-weight, overridable pattern (rather than
    // hardcoded here) so an `.ann`-declared `deref_call` overload can intercept specific cases if
    // ever needed. See IMPLEMENTATION_NOTES.md's `ref(T)` section. The original `match.error()` is
    // what's surfaced either way if this doesn't pan out, not whatever deref_call itself failed
    // with -- a confusing secondary error would be worse than none.
    qname_identifier target_qnid;
    if constexpr (std::is_same_v<std::decay_t<FnIdT>, builtin_qnid>) target_qnid = env().get(fnid);
    else target_qnid = fnid;

    call_builder fallback_call{ context_expression_.location };
    fallback_call.emplace_back(env().get(builtin_id::method), context_expression_.location,
        env().make_functional_identifier_entity(target_qnid).id);
    for (opt_named_expression_t const& a : args) fallback_call.arguments.emplace_back(a);

    auto fallback_res = ctx.find_and_apply(builtin_qnid::deref_call, fallback_call, expressions, expected_result);
    if (fallback_res) return apply_cast(std::move(*fallback_res));
    return std::unexpected(match.error());
}

}
