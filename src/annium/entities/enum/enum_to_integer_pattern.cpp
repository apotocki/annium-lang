//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "enum_to_integer_pattern.hpp"
#include "enum_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

#include "sonia/utility/scope_exit.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

class enum_to_string_match_descriptor : public functional_match_descriptor
{
public:
    inline enum_to_string_match_descriptor(prepared_call const& call, enum_entity const& enum_ent) noexcept
        : functional_match_descriptor{ call }
        , ent{ enum_ent }
    {}

    enum_entity const& ent;
    size_t which;
};

std::expected<functional_match_descriptor_ptr, error_storage> enum_to_integer_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    value_modifier_t arg_req_mod = can_be_only_constexpr(exp.modifier) ? exp.modifier : value_modifier_t::constexpr_or_runtime_value;
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t { .modifier = arg_req_mod }, &arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get<0>(arg_expr)->location, "invalid argument"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& argloc = get<0>(arg_expr)->location;
    syntax_expression_result& arg_er = arg->first;
    
    entity const* pcent;
    entity_identifier arg_type = get_result_type(env, arg_er, &pcent);
    enum_entity const* pe = dynamic_cast<enum_entity const*>(&get_entity(env, arg_type)); // check type existence
    if (!pe) {
        return std::unexpected(make_error<type_mismatch_error>(argloc, arg_type, "an enumeration"sv));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_er, argloc);

    if (can_be_only_constexpr(exp.modifier) || (arg_er.is_const_result && !can_be_only_runtime(exp.modifier))) {
        BOOST_ASSERT(arg_er.is_const_result);
        size_t which = static_cast<generic_literal_entity const&>(*pcent).value().as<size_t>();
        pmd->signature.result.emplace(env.make_integer_entity(static_cast<int64_t>(which)).id, true);
    } else {
        pmd->signature.result.emplace(env.get(builtin_eid::integer), false);
    }
    
    return pmd;
}

std::expected<syntax_expression_result, error_storage> enum_to_integer_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    auto const& res = *md.signature.result;
    syntax_expression_result result{
        .value_or_type = res.entity_id(),
        .is_const_result = res.is_const()
    };

    if (!res.is_const()) {
        environment& env = ctx.env();
        auto &[_, ser, argloc] = md.matches.front();
        if (ser.is_const_result) {
            smart_blob which = static_cast<generic_literal_entity const&>(get_entity(env, ser.value())).value();
            env.push_back_expression(el, result.expressions, semantic::push_value{ which });
        } else {
            append_semantic_result(el, ser, result); // arg
        }
    }
    return result;
}

}
