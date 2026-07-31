//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/functional.hpp"

namespace annium {

// numeric_cast(constexpr @numeric) ~> i8|u8|i16|u16|i32|u32|i64|u64|integer|f16|f32|f64|decimal
// constexpr counterpart of the `runtime @numeric` overloads declared in bootstrap.ann: when the argument
// is a compile-time constant, fold the same conversion at compile time instead of deferring to the
// __to_iN/__to_integer/__to_f16/__to_f32/__to_f64/__to_decimal ecall at VM runtime. Same semantics as
// those builtins, never rejects on precision loss (unlike numeric_literal_implicit_cast_pattern, which is
// a checked/rejecting conversion and is architecturally the wrong fit here). The 8 fixed-width integer
// targets bit-truncate; `integer` (arbitrary precision) and the floating/decimal targets only lose
// precision for a source with a fractional part or magnitude the target can't represent exactly.
//
// Plain default weight -- disambiguation against the 8 `runtime @numeric` overloads (both are structurally
// viable for a literal argument) happens via ordinary match_penalty comparison: matching a compile-time
// constant against this pattern costs 0 casts, while the runtime overloads need an implicit constexpr->
// runtime materialization (parameter_matcher.cpp's constraint_matcher now charges that the same way for
// pattern/@concept-constrained parameters as for plain type-constrained ones), so this pattern always wins
// on `casts` -- the first, most significant field match_penalty::operator<=> compares.
class numeric_cast_constexpr_pattern : public functional::pattern
{
public:
    explicit numeric_cast_constexpr_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "numeric_cast(constexpr @numeric)~>i8|u8|i16|u16|i32|u32|i64|u64|integer|f16|f32|f64|decimal"; }
};

}
