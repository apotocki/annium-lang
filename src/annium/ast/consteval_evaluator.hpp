//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <expected>

#include "annium/semantic.hpp"
#include "annium/errors.hpp"

namespace annium {

class fn_compiler_context;

// Executes `operand` -- the already-resolved (ordinary overload resolution, no special
// treatment -- see CONSTEVAL_CTFE_PLAN.md section 3.1) semantic form of a `consteval <expr>`
// operand -- on the compiler's own VM, right now, and folds the result into a constexpr entity.
// `operand` must be a non-const (runtime) result; a caller that already got a constexpr result
// back from evaluating the operand has nothing to hand this function.
std::expected<syntax_expression_result, error_storage> evaluate_consteval(
    fn_compiler_context& ctx, resource_location const& loc, syntax_expression_result operand);

}
