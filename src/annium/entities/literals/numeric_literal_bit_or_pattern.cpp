//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_literal_bit_or_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/literals/numeric_promotion.hpp"

#include "annium/auxiliary.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

class numeric_literal_bit_or_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    numeric_literal_bit_or_match_descriptor(prepared_call const& call, generic_literal_entity const* lhs_arg, generic_literal_entity const* rhs_arg) noexcept
        : functional_match_descriptor{ call }
        , lhs_arg{ lhs_arg }
        , rhs_arg{ rhs_arg }
    {}

    generic_literal_entity const* lhs_arg = nullptr; // nullptr for runtime arguments
    generic_literal_entity const* rhs_arg = nullptr; // nullptr for runtime arguments
};

namespace {

// See numeric_literal_bit_and_pattern.cpp's identical helper for the rationale (integral-only
// candidate set, unlike the +/-/*  patterns' widen_literal_for_runtime_peer).
builtin_eid widen_literal_for_runtime_peer(generic_literal_entity const& lit, builtin_eid lit_type, builtin_eid runtime_type)
{
    numetron::integer_view v = lit.value().as<numetron::integer_view>();
    if (can_convert_constexpr_value_safely(v, lit_type, runtime_type)) return runtime_type;

    constexpr builtin_eid integral_eids[] = {
        builtin_eid::i8, builtin_eid::u8, builtin_eid::i16, builtin_eid::u16,
        builtin_eid::i32, builtin_eid::u32, builtin_eid::i64, builtin_eid::u64,
        builtin_eid::integer
    };
    for (builtin_eid candidate : integral_eids) {
        if (candidate == runtime_type) continue;
        if (!is_always_safe_runtime_conversion(runtime_type, candidate)) continue;
        if (!can_convert_constexpr_value_safely(v, lit_type, candidate)) continue;
        return candidate;
    }

    THROW_INTERNAL_ERROR("numeric_literal_bit_or_pattern: no common safe integer type"sv);
}

} // anonymous namespace

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_literal_bit_or_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    auto lhs_descr = call_session.get_next_positioned_argument();
    if (!lhs_descr) return std::unexpected(std::move(lhs_descr.error()));

    syntax_expression_result& lhs_er = lhs_descr->result;
    entity_identifier lhs_type_id;
    entity const* lhs_type_entity = nullptr;
    if (lhs_er.is_const_result) {
        lhs_type_entity = &get_entity(e, lhs_er.value());
        lhs_type_id = lhs_type_entity->get_type();
    } else {
        lhs_type_id = lhs_er.type();
    }
    builtin_eid lhs_type = static_cast<builtin_eid>(lhs_type_id.value);
    resource_location lhs_loc = lhs_descr->expression->location;
    if (!is_integral_kind_eid(lhs_type)) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_loc, lhs_type_id, "an integer type"sv));
    }

    auto rhs_descr = call_session.get_next_positioned_argument();
    if (!rhs_descr) return std::unexpected(std::move(rhs_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result& rhs_er = rhs_descr->result;
    entity_identifier rhs_type_id;
    entity const* rhs_type_entity = nullptr;
    if (rhs_er.is_const_result) {
        rhs_type_entity = &get_entity(e, rhs_er.value());
        rhs_type_id = rhs_type_entity->get_type();
    } else {
        rhs_type_id = rhs_er.type();
    }
    builtin_eid rhs_type = static_cast<builtin_eid>(rhs_type_id.value);
    resource_location rhs_loc = rhs_descr->expression->location;
    if (!is_integral_kind_eid(rhs_type)) {
        return std::unexpected(make_error<type_mismatch_error>(rhs_loc, rhs_type_id, "an integer type"sv));
    }

    generic_literal_entity const* lhs_literal = lhs_er.is_const_result ?
        dynamic_cast<generic_literal_entity const*>(lhs_type_entity) : nullptr;
    generic_literal_entity const* rhs_literal = rhs_er.is_const_result ?
        dynamic_cast<generic_literal_entity const*>(rhs_type_entity) : nullptr;

    auto pmd = sonia::make_shared<numeric_literal_bit_or_match_descriptor>(call, lhs_literal, rhs_literal);
    pmd->append_arg(lhs_er, lhs_loc);
    pmd->append_arg(rhs_er, rhs_loc);

    if (lhs_literal && rhs_literal) {
        // Both constexpr: fold entirely at compile time.
        builtin_eid result_type = strongest_numeric_type(lhs_type, rhs_type);
        smart_blob disj = bit_or_numeric(lhs_literal->value(), rhs_literal->value(), result_type);
        pmd->signature.result.emplace(e.make_generic_entity(std::move(disj), e.get(result_type)).id, true);
    } else if (lhs_literal || rhs_literal) {
        bool lhs_is_literal = lhs_literal != nullptr;
        builtin_eid runtime_type = lhs_is_literal ? rhs_type : lhs_type;
        generic_literal_entity const& lit = lhs_is_literal ? *lhs_literal : *rhs_literal;
        builtin_eid lit_type = lhs_is_literal ? lhs_type : rhs_type;

        builtin_eid result_type = widen_literal_for_runtime_peer(lit, lit_type, runtime_type);
        pmd->signature.result.emplace(e.get(result_type), false);
    } else {
        // Both runtime.
        builtin_eid result_type = strongest_numeric_type(lhs_type, rhs_type);
        pmd->signature.result.emplace(e.get(result_type), false);
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage>
numeric_literal_bit_or_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& nmd = static_cast<numeric_literal_bit_or_match_descriptor&>(md);
    auto& [_, lhs_src, lhs_loc] = md.matches[0];
    auto& [__, rhs_src, rhs_loc] = md.matches[1];

    environment& e = ctx.env();

    if (nmd.lhs_arg && nmd.rhs_arg) {
        // Both operands were constexpr; try_match already folded the result into signature.result.
        return syntax_expression_result{
            .value_or_type = md.signature.result->entity_id(),
            .is_const_result = true
        };
    }

    builtin_eid result_type = static_cast<builtin_eid>(md.signature.result->entity_id().value);
    syntax_expression_result result{
        .value_or_type = e.get(result_type),
        .is_const_result = false
    };

    auto append_operand = [&](syntax_expression_result& src, generic_literal_entity const* literal) {
        if (literal) {
            smart_blob materialized = integer_view_to_numeric(literal->value().as<numetron::integer_view>(), result_type);
            e.push_back_expression(el, result.expressions, semantic::push_value{ std::move(materialized) });
        } else {
            append_semantic_result(el, src, result);
        }
    };

    append_operand(lhs_src, nmd.lhs_arg);
    append_operand(rhs_src, nmd.rhs_arg);

    e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::bitor_numeric)));

    return result;
}

} // namespace annium
