//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "to_union_implicit_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/cast_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class to_union_cast_match_descriptor : public functional_match_descriptor
{
public:
    to_union_cast_match_descriptor(prepared_call const& pcall, size_t which_val)
        : functional_match_descriptor{ pcall }
        , which{ which_val }
    {}

    size_t which;
};

std::expected<functional_match_descriptor_ptr, error_storage> to_union_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a union result"sv));
    }
    environment& e = ctx.env();
    entity const& ent = get_entity(e, exp.type);
    entity_signature const* pusig = ent.signature();
    if (!pusig || pusig->name != e.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a union"sv));
    }

    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(&arg_expr);
    if (!arg) {
        if (!arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
        return std::unexpected(std::move(arg.error()));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result_t& er = arg->first;
    entity_identifier er_type;
    optional<size_t> type_index;
    if (er.is_const_result) { // first try to match constant value
        er_type = get_entity(e, er.value()).get_type();
        auto it = std::ranges::find_if(pusig->fields(), [val = er.value()](field_descriptor const& fd) noexcept {
            return fd.is_const() && fd.entity_id() == val;
        });
        if (it != pusig->fields().end()) {
            type_index.emplace( (size_t)(it - pusig->fields().begin()) );
        }
    } else {
        er_type = er.type();
    }
    if (!type_index) {// then try to match by type
        auto it = std::ranges::find_if(pusig->fields(), [er_type](field_descriptor const& fd) noexcept {
            return !fd.is_const() && fd.entity_id() == er_type;
        });
        if (it == pusig->fields().end()) {
            return std::unexpected(make_error<cast_error>(get_start_location(*get<0>(arg_expr)), er.value_or_type, exp.type));
        }
        type_index = (size_t)(it - pusig->fields().begin());
    }
    
    functional_match_descriptor_ptr pmd = make_shared<to_union_cast_match_descriptor>(call, *type_index);
    pmd->emplace_back(0, er);
    pmd->signature.emplace_back(er.value_or_type, er.is_const_result);
    
    if (can_be_only_runtime(exp.modifier) || !er.is_const_result) {
        pmd->signature.result.emplace(exp.type, false);
    } else {
        pmd->signature.result.emplace(er.value(), true);
    }

    return pmd;
}

std::expected<syntax_expression_result_t, error_storage> to_union_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto & arg = md.matches.front();
    syntax_expression_result_t& ser = get<1>(arg);
    syntax_expression_result_t result{
        .temporaries = std::move(ser.temporaries),
        .expressions = ser.expressions,
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = md.signature.result->is_const()
    };

    if (!result.is_const_result) {
        if (ser.is_const_result) {
            // materialize the const value
            entity_identifier argtype = get_entity(env, ser.value()).get_type();
            pure_call_t cast_call{ md.call_location };
            cast_call.emplace_back(annotated_entity_identifier{ ser.value(), get<2>(arg) });
            auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, el,
                expected_result_t{ .type = argtype, .location = md.call_location, .modifier = value_modifier_t::runtime_value });
            if (!match) {
                return std::unexpected(std::move(match.error()));
            }
            auto res = match->apply(ctx);
            if (!res) {
                return std::unexpected(std::move(res.error()));
            }
            append_semantic_result(el, result, *res);
        }
        size_t which = static_cast<to_union_cast_match_descriptor&>(md).which;
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(which) } });
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(2) } });
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    }

    return result;
}

}
