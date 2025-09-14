//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "generic_pattern_base.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/entities/prepared_call.hpp"

#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

template <typename DerivedT>
struct generic_pattern_base<DerivedT>::arg_context_type
{
    fn_compiler_context& ctx;
    prepared_call const& call;
    annotated_identifier const* pargname;
    syntax_expression_t const& argexpr;

    environment& env() const { return ctx.env(); }

    error_storage make_argument_mismatch_error() const
    {
        return make_error<basic_general_error>(pargname ? pargname->location : get_start_location(argexpr), "argument mismatch"sv, argexpr);
    }
};

template <typename DerivedT>
std::expected<functional_match_descriptor_ptr, error_storage> generic_pattern_base<DerivedT>::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    return try_match(ctx, call, nullptr);
}

template <typename DerivedT>
template <typename CookieT>
std::expected<functional_match_descriptor_ptr, error_storage> generic_pattern_base<DerivedT>::try_match(fn_compiler_context& ctx, prepared_call const& call, CookieT&& cookie) const
{
    environment& e = ctx.env();
    shared_ptr<functional_match_descriptor> pmd;
    for (auto const& arg : call.args) {
        annotated_identifier const* pargname = arg.name();
        auto const& argexpr = arg.value();

        auto res = apply_visitor(base_expression_visitor{ ctx, call.expressions }, argexpr);
        if (!res) return std::unexpected(std::move(res.error()));
        arg_context_type argctx{ ctx, call, pargname, argexpr };
        if (auto err = derived().accept_argument(std::forward<CookieT>(cookie), pmd, argctx, res->first); err)
            return std::unexpected(std::move(err));
    }
    if (!pmd) {
        return std::unexpected(make_error<basic_general_error>(call.location, "unmatched parameter(s)"sv));
    }
    return pmd;
}

} // namespace annium
