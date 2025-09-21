//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "base_expression_visitor.hpp"

#include "fn_compiler_context.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

template <typename FnIdT, std::derived_from<pure_call_t> ExprT>
inline base_expression_visitor::result_type base_expression_visitor::operator()(FnIdT&& fnid, ExprT const& call) const
{
    auto match = ctx.find(std::forward<FnIdT>(fnid), call, expressions, expected_result);
    if (!match) return std::unexpected(match.error());
    return apply_cast(match->apply(ctx), call);
}

template <typename ExprT>
inline base_expression_visitor::result_type base_expression_visitor::apply_cast(entity_identifier eid, ExprT const& e) const
{
    return apply_cast(get_entity(env(), eid), syntax_expression_result{ .value_or_type = eid, .is_const_result = true }, e);
}

template <typename ExprT>
inline base_expression_visitor::result_type base_expression_visitor::apply_cast(entity const& ent, ExprT const& e) const
{
    return apply_cast(ent, syntax_expression_result{ .value_or_type = ent.id, .is_const_result = true }, syntax_expression_t{ e });
}

template <typename ExprT>
inline base_expression_visitor::result_type base_expression_visitor::apply_cast(syntax_expression_result er, ExprT const& e) const
{
    return apply_cast(std::move(er), syntax_expression_t{ e });
}

template <typename ExprT>
inline base_expression_visitor::result_type base_expression_visitor::apply_cast(std::expected<syntax_expression_result, error_storage> r, ExprT const& e) const
{
    if (!r) return std::unexpected(std::move(r.error()));
    syntax_expression_t se = e;
    return apply_cast(std::move(*r), se);
    //return apply_visitor(make_functional_visitor<result_type>([this, e](auto& v) -> result_type {
    //    return apply_cast(std::move(v), e);
    //}), *r);
}

}
