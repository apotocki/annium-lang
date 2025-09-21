//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_implicit_cast_pattern.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

class numeric_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    inline explicit numeric_implicit_cast_match_descriptor(generic_literal_entity const& arg) noexcept
        : arg{ &arg }
    {}

    generic_literal_entity const* arg = nullptr;
};

std::expected<functional_match_descriptor_ptr, error_storage> numeric_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    entity_identifier teid = exp.type;
    if (!teid) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a runtime numeric result"sv));
    }

    int ntype = 0;

    if (teid == e.get(builtin_eid::f16)) { ntype = 1; }
    else if (teid == e.get(builtin_eid::f32)) { ntype = 2; }
    else if (teid == e.get(builtin_eid::f64)) { ntype = 3; }
    else if (teid == e.get(builtin_eid::decimal)) { ntype = 4; }
    else if (teid == e.get(builtin_eid::integer)) { ntype = 5; }
    else {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a numeric result"sv, exp.type));
    }

    auto call_session = call.new_session(ctx);
    std::pair<syntax_expression_t const*, size_t> self_expr;
    auto src_arg = call_session.use_next_positioned_argument(&self_expr);
    if (!src_arg) {
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result& src_arg_er = src_arg->first;
    // Only allow compatible argument
    if (!exp.is_modifier_compatible(src_arg_er)) {
        return std::unexpected(make_error<basic_general_error>(get_start_location(*get<0>(self_expr)), "argument and result must be both constexpr or both runtime"sv));
    }

    functional_match_descriptor_ptr pmd;
    if (src_arg_er.is_const_result) {
        entity const& argent = get_entity(e, src_arg_er.value());
        entity_identifier argtype = argent.get_type();
        if (argtype && argtype != e.get(builtin_eid::any) &&
            argtype != e.get(builtin_eid::integer) && argtype != ctx.env().get(builtin_eid::decimal) &&
            argtype != e.get(builtin_eid::string) &&
            argtype != e.get(builtin_eid::f16) &&
            argtype != e.get(builtin_eid::f32) &&
            argtype != e.get(builtin_eid::f64) &&
            argtype != e.get(builtin_eid::boolean) &&
            argtype != e.get(builtin_eid::i8) &&
            argtype != e.get(builtin_eid::u8) &&
            argtype != e.get(builtin_eid::i16) &&
            argtype != e.get(builtin_eid::u16) &&
            argtype != e.get(builtin_eid::i32) &&
            argtype != e.get(builtin_eid::u32) &&
            argtype != e.get(builtin_eid::i64) &&
            argtype != e.get(builtin_eid::u64))
        {
            return std::unexpected(make_error<value_mismatch_error>(get_start_location(*get<0>(self_expr)), src_arg_er.value(), "a numeric literal"sv));
        }

        if (argent.get_type() == teid) {
            return std::unexpected(make_error<basic_general_error>(get_start_location(*get<0>(self_expr)), "argument and result types must be different"sv, teid));
        }
        generic_literal_entity const& src_arg_literal = dynamic_cast<generic_literal_entity const&>(argent);
        pmd = sonia::make_shared<numeric_implicit_cast_match_descriptor>(src_arg_literal);
        --pmd->weight; // lower weight for implicit casts
    } else {
        if (src_arg_er.type() == teid) {
            return std::unexpected(make_error<basic_general_error>(get_start_location(*get<0>(self_expr)), "argument and result types must be different"sv, teid));
        }
        if (src_arg_er.type() == e.get(builtin_eid::integer)) {
            pmd = make_shared<numeric_implicit_cast_match_descriptor>();
        } else {
            return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(self_expr)), src_arg_er.type(), "integer"sv));
        }
    }
    pmd->emplace_back(0, src_arg_er);
    pmd->signature.result.emplace(exp.type, can_be_only_constexpr(exp.modifier));
    return std::move(pmd);
}

std::expected<syntax_expression_result, error_storage> numeric_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto& nmd = static_cast<numeric_implicit_cast_match_descriptor&>(md);
    auto& [_, src, loc] = md.matches.front();
    
    THROW_NOT_IMPLEMENTED_ERROR("numeric_implicit_cast_pattern::apply, not implemented for non-constexpr result"sv);
    /*
    if (auto& result = *nmd.signature.result; result.is_const()) {
        entity_identifier rid = apply_visitor(make_functional_visitor<entity_identifier>([&ctx, type = result.entity_id()](auto const& v) -> entity_identifier {
            if constexpr (std::is_same_v<integer_literal_entity, std::decay_t<decltype(v)>>) {
                return ctx.env().make_integer_entity(v.value(), type).id;
            } else if constexpr (std::is_same_v<decimal_literal_entity, std::decay_t<decltype(v)>>) {
                return ctx.env().make_decimal_entity(v.value(), type).id;
            } else {
                THROW_INTERNAL_ERROR("numeric_implicit_cast_pattern::apply, null is not expected");
            }
        }), nmd.arg);
        src.value_or_type = rid;
        src.is_const_result = true;
        return syntax_expression_result {
            .temporaries = std::move(src.temporaries),
            .expressions = md.merge_void_spans(el),
            .value_or_type = rid,
            .is_const_result = true
        };
    } else {
        apply_visitor(make_functional_visitor<void>([&ctx, &el, &src](auto const& v) {
            if constexpr (std::is_same_v<integer_literal_entity, std::decay_t<decltype(v)>>) {
                ctx.env().push_back_expression(el, src.expressions, semantic::push_value{ smart_blob{ bigint_blob_result(v.value()) } });
            } else if constexpr (std::is_same_v<decimal_literal_entity, std::decay_t<decltype(v)>>) {
                ctx.env().push_back_expression(el, src.expressions, semantic::push_value{ smart_blob{ decimal_blob_result(v.value()) } });
            } else {
                THROW_INTERNAL_ERROR("numeric_implicit_cast_pattern::apply, null is not expected");
            }
        }), nmd.arg);
        src.value_or_type = result.entity_id(),
        src.is_const_result = false;
    }
    return std::move(src);
    //entity_identifier rid = (ctx.env(), apply_visitor(make_functional_visitor<entity_identifier>([&ctx, type = nmd.result.entity_id()](auto const& v) -> entity_identifier {
    //    if constexpr (std::is_same_v<integer_literal_entity, std::decay_t<decltype(v)>>) {
    //        return ctx.env().make_integer_entity(v.value(), type).id;
    //    } else if constexpr (std::is_same_v<decimal_literal_entity, std::decay_t<decltype(v)>>) {
    //        return ctx.env().make_decimal_entity(v.value(), type).id;
    //    } else {
    //        THROW_INTERNAL_ERROR("numeric_implicit_cast_pattern::apply, null is not expected");
    //    }
    //}), nmd.arg));
    */
}

}
