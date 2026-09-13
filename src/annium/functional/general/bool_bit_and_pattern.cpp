//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "bool_bit_and_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

namespace {

// Deliberately does NOT pass an expected_result_t{boolean} hint to get_next_positioned_argument:
// bootstrap.ann declares `implicit_cast(@numeric) ~> bool => $0 != 0` (truthy numeric-to-bool
// conversion, used by e.g. `if`/`!`/`&&`/`||`) under the very qname (implicit_cast) that hint
// would steer through -- so a numeric argument like `i32 & i32` would get silently truthy-cast
// to bool and "match" here too (see BUGFIXES.md), producing a bogus bit_and(bool,bool) candidate
// that competes with numeric_literal_bit_and_pattern instead of losing to it. Fetching with no
// type hint at all returns the argument in its own natural type, which this then checks strictly.
entity_identifier actual_type(environment& e, syntax_expression_result const& er)
{
    return er.is_const_result ? get_entity(e, er.value()).get_type() : er.type();
}

} // anonymous namespace

std::expected<functional_match_descriptor_ptr, error_storage>
bool_bit_and_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);

    auto lhs_descr = call_session.get_next_positioned_argument();
    if (!lhs_descr) return std::unexpected(std::move(lhs_descr.error()));
    entity_identifier lhs_type_id = actual_type(env, lhs_descr->result);
    if (lhs_type_id != env.get(builtin_eid::boolean)) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_descr->expression->location, lhs_type_id, "a bool value"sv));
    }

    auto rhs_descr = call_session.get_next_positioned_argument();
    if (!rhs_descr) return std::unexpected(std::move(rhs_descr.error()));
    entity_identifier rhs_type_id = actual_type(env, rhs_descr->result);
    if (rhs_type_id != env.get(builtin_eid::boolean)) {
        return std::unexpected(make_error<type_mismatch_error>(rhs_descr->expression->location, rhs_type_id, "a bool value"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(),
            "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(lhs_descr->result, lhs_descr->expression->location);
    pmd->append_arg(rhs_descr->result, rhs_descr->expression->location);
    bool both_const = lhs_descr->result.is_const_result && rhs_descr->result.is_const_result;
    pmd->signature.result.emplace(env.get(builtin_eid::boolean), both_const);

    return pmd;
}

std::expected<syntax_expression_result, error_storage>
bool_bit_and_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& [_, lhs_er, lhs_loc] = md.matches[0];
    auto& [__, rhs_er, rhs_loc] = md.matches[1];

    if (lhs_er.is_const_result && rhs_er.is_const_result) {
        bool l = lhs_er.value() == e.get(builtin_eid::true_);
        bool r = rhs_er.value() == e.get(builtin_eid::true_);
        return syntax_expression_result{
            .value_or_type = (l & r) ? e.get(builtin_eid::true_) : e.get(builtin_eid::false_),
            .is_const_result = true
        };
    }

    syntax_expression_result result{
        .value_or_type = e.get(builtin_eid::boolean),
        .is_const_result = false
    };

    // Either side may still be a compile-time bool constant even though the other is runtime
    // (e.g. `flag & true`) -- materialize such a side as a plain runtime bool blob directly,
    // there's no widening/casting concern the way numeric literals have.
    auto append_operand = [&](syntax_expression_result& src) {
        if (src.is_const_result) {
            bool v = src.value() == e.get(builtin_eid::true_);
            e.push_back_expression(el, result.expressions, semantic::push_value{ bool_blob_result(v) });
        } else {
            append_semantic_result(el, src, result);
        }
    };

    append_operand(lhs_er);
    append_operand(rhs_er);

    e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::bitand_bool)));

    return result;
}

} // namespace annium
