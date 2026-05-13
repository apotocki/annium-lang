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
    if (!match) return std::unexpected(match.error());
    return apply_cast(match->apply(ctx));
}

}
