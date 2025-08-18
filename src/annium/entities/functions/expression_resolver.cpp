//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "expression_resolver.hpp"
#include "annium/ast/ct_expression_visitor.hpp"
#include "annium/ast/fn_compiler_context.hpp"

namespace annium {

expression_resolver::expression_resolver(resource_location loc, syntax_expression_t const& expr)
    : location_{ std::move(loc) }
    , expression_{ expr }
{}

std::expected<entity_identifier, error_storage> expression_resolver::const_resolve(fn_compiler_context& ctx) const
{
    semantic::managed_expression_list el{ ctx.env() };
    ct_expression_visitor evis{ ctx, el };
    auto res = apply_visitor(evis, expression_);
    if (!res) return std::unexpected(res.error());
    if (res->expressions) THROW_NOT_IMPLEMENTED_ERROR("expression_resolver::const_resolve");
    return res->value;
    //THROW_NOT_IMPLEMENTED_ERROR("expression_resolver::resolve");
}

resource_location const& expression_resolver::location() const
{
    return location_;
}

}
