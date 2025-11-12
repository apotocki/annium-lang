//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "typefn_pattern.hpp"

#include "annium/environment.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/circular_dependency_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

error_storage typefn_pattern::init(fn_compiler_context& ctx, fn_decl const& fnd)
{
    return basic_fn_pattern::init(ctx, fnd);
    // if (auto err = init(ctx, static_cast<fn_pure const&>(fnd))) return err;
}

std::expected<syntax_expression_result, error_storage> typefn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    md.signature.result.emplace(env.get(builtin_eid::typename_));
    return syntax_expression_result {
        .value_or_type = env.make_basic_signatured_entity(std::move(md.signature)).id,
        .is_const_result = true
    };
}

}
