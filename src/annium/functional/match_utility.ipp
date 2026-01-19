//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <expected>

#include "annium/functional/functional.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

template <typename HandlerT>
std::expected<syntax_expression_result, error_storage> match_type(fn_compiler_context& caller_ctx, semantic::expression_list_t& expressions,
    syntax_expression const& expr, entity_identifier const& eid, resource_location eidloc, HandlerT const& hf)
{
    auto res = apply_visitor(base_expression_visitor{ caller_ctx, expressions, { eid, eidloc } }, expr);
    if (!res) return std::unexpected(std::move(res.error()));
    syntax_expression_result& ser = res->first;
    if (ser.is_const_result) {
        entity const& ent = get_entity(caller_ctx.env(), ser.value());
        if (auto err = hf(ent.get_type(), res->second); err) return std::unexpected(std::move(err));
    } else {
        if (auto err = hf(ser.type(), res->second); err) return std::unexpected(std::move(err));
    }
    return std::move(ser);
}

}
