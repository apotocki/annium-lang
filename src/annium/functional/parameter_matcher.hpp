//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <utility>

#include "sonia/small_vector.hpp"
#include "annium/ast_terms.hpp"

#include "basic_fn_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

namespace annium {

class parameter_matcher
{
public:
    using parameter_descriptor = basic_fn_pattern::parameter_descriptor;
    using parameter_iterator = parameter_descriptor const*;
    parameter_iterator param_bit, param_it, param_end;
    uint32_t argindex_for_default = (std::numeric_limits<uint32_t>::max)() - 1;

    prepared_call const& call;
    prepared_call::session call_session;
    functional_match_descriptor& md;

    parameter_matcher(fn_compiler_context& caller_ctx, prepared_call const&, span<const parameter_descriptor>, functional_match_descriptor&);
    error_storage match(fn_compiler_context& callee_ctx);

protected:
    bool try_backtrack(fn_compiler_context& callee_ctx);
    std::expected<expected_result_t, error_storage> resolve_expression_expected_result(fn_compiler_context& callee_ctx, annotated_identifier const&, parameter_constraint_modifier_t, syntax_expression const&, entity_identifier& pconstraint_value_eid);
    void finalize_ellipsis(fn_compiler_context& callee_ctx);

    struct star_frame
    {
        parameter_iterator param_it;
        entity_signature signature;
    };
    small_vector<star_frame, 2> star_stack;

    std::vector<uint32_t> argindices_stack;
};

}
