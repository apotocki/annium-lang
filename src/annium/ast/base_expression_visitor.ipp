//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "base_expression_visitor.hpp"

#include "fn_compiler_context.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

template <typename FnIdT, std::derived_from<pure_call> ExprT>
inline base_expression_visitor::result_type base_expression_visitor::operator()(FnIdT&& fnid, ExprT const& call) const
{
    auto match = ctx.find(std::forward<FnIdT>(fnid), context_expression_.location, call.args, expressions, expected_result);
    if (!match) return std::unexpected(match.error());
    return apply_cast(match->apply(ctx));
}

}
