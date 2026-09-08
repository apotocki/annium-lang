//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "base_expression_visitor.hpp"

#include "fn_compiler_context.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

template <typename FnIdT>
inline base_expression_visitor::result_type base_expression_visitor::operator()(FnIdT&& fnid, span<const opt_named_expression_t> args) const
{
    auto match = ctx.find(std::forward<FnIdT>(fnid), context_expression_.location, args, expressions, expected_result);
    if (match) return apply_cast(match->apply(ctx));

    // Fallback: the direct call found nothing. Before giving up, retry with any argument whose OWN
    // type is ref(of: T) transparently dereferenced -- covers every current and future operator/
    // function uniformly (`y + 1`, `y + z` with both ref, ...) without any of them needing to know
    // about ref(T) themselves. See try_deref_ref_arguments and IMPLEMENTATION_NOTES.md's `ref(T)`
    // section. Cheap when it doesn't apply (no ref-typed argument -> nullopt, no retry attempted);
    // the original `match.error()` is what's surfaced either way if this doesn't pan out, not
    // whatever the retry itself failed with -- a confusing secondary error would be worse than none.
    if (auto deref_args = try_deref_ref_arguments(args); deref_args) {
        auto retry = ctx.find(fnid, context_expression_.location, *deref_args, expressions, expected_result);
        if (retry) return apply_cast(retry->apply(ctx));
    }
    return std::unexpected(match.error());
}

}
