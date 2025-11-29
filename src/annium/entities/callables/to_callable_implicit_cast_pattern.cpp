//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "to_callable_implicit_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/ast/arena.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/circular_dependency_error.hpp"
#include "annium/auxiliary.hpp"

#include "sonia/utility/scope_exit.hpp"

namespace annium {

class to_callable_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    inline to_callable_implicit_cast_match_descriptor(prepared_call const& pcall, syntax_expression_result&& c, entity_signature const& fs, size_t arg_count, value_modifier_t mod) noexcept
        : functional_match_descriptor{ pcall } // pcall.caller_ctx.env().get(builtin_qnid::callable), pcall.location }
        , function_signature{ fs }
        , code{ std::move(c) }
        , callable_arg_count{ arg_count }
        , result_modifier{ mod }
    {}
    entity_signature const& function_signature;
    syntax_expression_result code;
    size_t callable_arg_count;
    value_modifier_t result_modifier;
};


std::expected<functional_match_descriptor_ptr, error_storage> to_callable_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a function result"sv));
    }
    environment& env = ctx.env();
    entity const& fn_ent = get_entity(env, exp.type);
    entity_signature const* psig = fn_ent.signature();
    if (!psig || psig->name != env.get(builtin_qnid::function)) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a function type"sv));
    }

    auto call_session = call.new_session(ctx);
    
    prepared_call::argument_descriptor_t arg_descr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t{}, &arg_descr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(arg_descr)->location, "invalid argument"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "implicit_cast requires one argument"sv));
    }

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "implicit_cast accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg->first;
    resource_location arg_loc = get<0>(arg_descr)->location;

    auto args_span = psig->fields().first(psig->fields().size() - 1);
    auto result_fd = psig->fields().back();

    // retrieve non const fields count
    size_t callable_arg_count = 0;
    for (field_descriptor const& fd : args_span) {
        if (!fd.is_const()) {
            ++callable_arg_count;
        }
    }

    small_vector<opt_named_expression_t, 8> ftor_args;
    
    expected_result_t callable_expected_result {
        .type = result_fd.is_const() ? get_entity(env, result_fd.entity_id()).get_type() : result_fd.entity_id(),
        .location = call.location,
        .modifier = result_fd.is_const() ? value_modifier_t::constexpr_value : value_modifier_t::runtime_value
    };
    
    for (field_descriptor const& fd : args_span) {
        if (fd.is_const()) continue; // skip const fields for now
        intptr_t offset = (intptr_t)ftor_args.size() - callable_arg_count;
        if (auto field_name = fd.name(); field_name) {
            ftor_args.emplace_back(fd.name(), syntax_expression{ arg_loc, stack_frame_value_reference_expression{ .type = fd.entity_id(), .offset = offset } });
        } else {
            ftor_args.emplace_back(syntax_expression{ arg_loc, stack_frame_value_reference_expression{ .type = fd.entity_id(), .offset = offset } });
        }
    }

    base_expression_visitor vis{ ctx, call.expressions, callable_expected_result, *get<0>(arg_descr) };
    
    syntax_expression_result arg_er_ref{
        .value_or_type = arg_er.value_or_type,
        .is_const_result = arg_er.is_const_result
    };
    if (!arg_er.is_const_result) {
        env.push_back_expression(call.expressions, arg_er_ref.expressions, semantic::push_by_offset{ -(intptr_t)callable_arg_count - 1, semantic::push_by_base::frame_bottom });
    }

    auto res = vis.make_function_call(arg_er_ref, arg_loc, pure_call{ ftor_args });
    if (!res) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(arg_loc, "can't convert argument to callable"sv),
            std::move(res.error())
        ));
    }

    functional_match_descriptor_ptr pmd = make_shared<to_callable_implicit_cast_match_descriptor>(call, std::move(res->first), *psig, callable_arg_count, exp.modifier);
    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    pmd->signature.result.emplace(exp.type, false);
    return pmd;
}

shared_ptr<internal_function_entity> to_callable_implicit_cast_pattern::build(fn_compiler_context& ctx, semantic::expression_list_t& el, to_callable_implicit_cast_match_descriptor& md) const
{
    environment& env = ctx.env();
    qname_view fnqn = env.fregistry_resolve(md.signature.name).name();
    field_descriptor function_result_fd = md.function_signature.fields().back();
    auto pife = make_shared<internal_function_entity>(
        qname(fnqn), // we don't need a separate (nested) namespace for this particular proxy function
        std::move(md.signature),
        md.call_location,
        function_result_fd);
    pife->set_arg_count(md.callable_arg_count);
    optional<statement> rst;
    if (!function_result_fd.is_const()) {
        rst.emplace(return_statement{ .expression = make_indirect_value(env, el, std::move(md.code), md.call_location), .location = md.call_location });
    } else {
        rst.emplace(expression_statement{ .expression = make_indirect_expression(env, el, std::move(md.code), md.call_location) });
    }
    pife->set_body(span<const statement>{ &*rst, 1 });
    pife->set_provision(false);
    if (!get<1>(md.matches.front()).is_const_result) pife->set_captured_var_count(1);
    // the function implementation is just proxying to another function call, so no circular dependencies or other errors should occur here
    auto err = pife->build(env);
    BOOST_ASSERT(!err);

    return pife;
}

std::expected<syntax_expression_result, error_storage> to_callable_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& tmd = static_cast<to_callable_implicit_cast_match_descriptor&>(md);

    indirect_internal_function_entity smpl{ tmd.signature, tmd.call_location };

    internal_function_entity& fne = static_cast<internal_function_entity&>(env.eregistry_find_or_create(smpl, [this, &ctx, &el, &tmd]() {
        return build(ctx, el, tmd);
    }));

    auto &[_, ser, argloc] = tmd.matches.front();
    if (ser.is_const_result && can_be_constexpr(tmd.result_modifier)) {
        return syntax_expression_result{
            .value_or_type = fne.id,
            .is_const_result = true
        };
    }
    
    intptr_t rt_id = env.retrieve_function_rt_identifier(fne);

    syntax_expression_result result{
        .value_or_type = fne.get_type(),
        .is_const_result = false
    };

    if (ser.is_const_result) {
        env.push_back_expression(el, result.expressions, semantic::push_value{ i64_blob_result(rt_id) });
    } else {
        append_semantic_result(el, ser, result);
        env.push_back_expression(el, result.expressions, semantic::push_value{ i64_blob_result(rt_id) });
        env.push_back_expression(el, result.expressions, semantic::push_value{ ui64_blob_result(2) });
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));
    }
    return result;
}

}
