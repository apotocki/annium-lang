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
    to_union_cast_match_descriptor(prepared_call const& pcall, size_t which_val, entity_signature const& sig, bool no_cast)
        : functional_match_descriptor{ pcall }
        , which{ which_val }
        , usig{ sig }
        , exact_case{ no_cast }
    {}

    inline field_descriptor const& which_field() const noexcept { return usig.field(which); }

    size_t which;
    entity_signature const& usig;
    bool exact_case;
};

std::expected<functional_match_descriptor_ptr, error_storage> to_union_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a union result"sv));
    }
    environment& env = ctx.env();
    entity const& ent = get_entity(env, exp.type);
    entity_signature const* pusig = ent.signature();
    if (!pusig || pusig->name != env.get(builtin_qnid::union_)) {
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

    resource_location arg_loc = get_start_location(*get<0>(arg_expr));
    syntax_expression_result& er = arg->first;
    entity_identifier er_type;
    optional<std::pair<size_t, bool>> type_index_and_kind; // index and 'no cast needed'
    

    if (er.is_const_result) { // first try to match constant value
        auto it = std::ranges::find_if(pusig->fields(), [val = er.value()](field_descriptor const& fd) noexcept {
            return fd.is_const() && fd.entity_id() == val;
        });
        if (it != pusig->fields().end()) {
            type_index_and_kind.emplace((size_t)(it - pusig->fields().begin()), true);
        } else {
            er_type = get_entity(env, er.value()).get_type();
        }
    } else {
        er_type = er.type();
    }
    if (!type_index_and_kind) { // then try to match by type
        auto it = std::ranges::find_if(pusig->fields(), [er_type](field_descriptor const& fd) noexcept {
            return !fd.is_const() && fd.entity_id() == er_type;
        });
        if (it != pusig->fields().end()) {
            type_index_and_kind.emplace((size_t)(it - pusig->fields().begin()), true);
        }
    }
    if (!type_index_and_kind) {
        // try cast
        alt_error errors;
        pure_call_t cast_call{ call.location };
        if (er.is_const_result) {
            cast_call.emplace_back(annotated_entity_identifier{ er.value(), arg_loc });
        } else {
            // fake stack reference
            cast_call.emplace_back(stack_value_reference{ .name = annotated_identifier{ .location = arg_loc }, .type = er_type, .offset = 0 });
        }

        for (size_t i = 0; i < pusig->field_count(); ++i) {
            field_descriptor const& fd = pusig->field(i);
            auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, call.expressions,
                expected_result_t{ .type = fd.entity_id(), .location = exp.location });
            if (match) {
                type_index_and_kind.emplace(i, false);
                break;
            }
            errors.alternatives.emplace_back(std::move(match.error()));
        }
        if (!type_index_and_kind) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "cannot cast argument to any of the union types"sv),
                make_error<alt_error>(std::move(errors))
            ));
        }
    }
    
    functional_match_descriptor_ptr pmd = make_shared<to_union_cast_match_descriptor>(call, get<0>(*type_index_and_kind), *pusig, get<1>(*type_index_and_kind));
    pmd->emplace_back(0, er, arg_loc);
    pmd->signature.emplace_back(er.value_or_type, er.is_const_result);
    
    if (can_be_only_runtime(exp.modifier) || !er.is_const_result) {
        pmd->signature.result.emplace(exp.type, false);
    } else {
        pmd->signature.result.emplace(er.value(), true);
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage> to_union_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& umd = static_cast<to_union_cast_match_descriptor&>(md);

    auto & [_, arg_er, arg_loc] = md.matches.front();

    syntax_expression_result result{
        //.temporaries = std::move(arg_er.temporaries),
        //.expressions = arg_er.expressions,
        .value_or_type = umd.signature.result->entity_id(),
        .is_const_result = umd.signature.result->is_const()
    };

    if (!umd.exact_case || (arg_er.is_const_result != result.is_const_result)) {
        // need cast
        function_call_t cast_call{ md.call_location, qname_reference{} };
        if (arg_er.is_const_result) {
            cast_call.emplace_back(annotated_entity_identifier{ arg_er.value(), arg_loc });
        } else {
            cast_call.emplace_back(make_indirect_value(env, el, std::move(arg_er), arg_loc));
        }
        auto res = base_expression_visitor{ ctx, el, 
            expected_result_t{
                .type = umd.which_field().entity_id(),
                .modifier = result.is_const_result ? value_modifier_t::constexpr_value : value_modifier_t::runtime_value
            }
        }(builtin_qnid::implicit_cast, cast_call);
        if (!res) {
            return std::unexpected(std::move(res.error()));
        }
        append_semantic_result(el, res->first, result);
    } else {
        // no cast needed, just move expressions
        append_semantic_result(el, arg_er, result);
    }

    // do not build union value if constexpr result
    if (result.is_const_result) return std::move(result);

    size_t which = static_cast<to_union_cast_match_descriptor&>(md).which;
    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(which) } });
    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(2) } });
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));

    return result;
}

}
