//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "to_external_callable_implicit_cast_pattern.hpp"

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

class to_external_callable_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    inline to_external_callable_implicit_cast_match_descriptor(prepared_call const& pcall, entity_signature const& fs) noexcept
        : functional_match_descriptor{ pcall }
        , function_signature{ fs }
    {}

    entity_signature const& function_signature;
};


std::expected<functional_match_descriptor_ptr, error_storage> to_external_callable_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type || !can_be_runtime(exp.modifier)) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a runtime callable result"sv));
    }
    
    environment& env = ctx.env();
    if (exp.type != env.get(builtin_eid::callable)) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a callable type"sv));
    }

    auto call_session = call.new_session(ctx);
    
    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::runtime_value });
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "implicit_cast accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg_descr->result;
    resource_location arg_loc = arg_descr->expression->location;

    entity const& fn_ent = get_entity(env, arg_er.type());
    entity_signature const* psig = fn_ent.signature();
    if (!psig || psig->name != env.get(builtin_qnid::function)) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a function type"sv));
    }

    auto pmd = make_shared<to_external_callable_implicit_cast_match_descriptor>(call, *psig);
    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    pmd->signature.result.emplace(exp.type, false);

    return pmd;
}

std::expected<syntax_expression_result, error_storage> to_external_callable_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& tmd = static_cast<to_external_callable_implicit_cast_match_descriptor&>(md);

    auto &[_, ser, argloc] = tmd.matches.front();
    
    syntax_expression_result result{
        .value_or_type = env.get(builtin_eid::callable),
        .is_const_result = false
    };

    append_semantic_result(el, ser, result);

    size_t arg_count = tmd.function_signature.field_count() - 1; // skip result type
    auto result_fd = tmd.function_signature.fields().back();
    BOOST_ASSERT(!result_fd.is_const() || result_fd.entity_id() == env.get(builtin_eid::void_));
    //bool is_void_result = result_fd.entity_id() == env.get(builtin_eid::void_);
    
    env.push_back_expression(el, result.expressions, semantic::push_value{ ui64_blob_result(arg_count) });
    //env.push_back_expression(el, result.expressions, semantic::push_value{ bool_blob_result(is_void_result) });
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::create_callable)));

    return result;
}

}
