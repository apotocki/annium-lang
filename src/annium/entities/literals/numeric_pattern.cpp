//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> numeric_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);

    // Get the type argument
    auto arg_descr = call_session.get_next_positioned_argument();
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(),
            "numeric accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg_descr->result;
    resource_location arg_loc = arg_descr->expression->location;

    // Create match descriptor
    auto pmd = make_shared<functional_match_descriptor>(call);

    // Resolve the type being checked: either the argument itself is a typename value,
    // or the argument is an ordinary value and its own type is what we check.
    entity_identifier arg_type = get_result_type(env, arg_er);
    entity_identifier checked_type = (arg_type == env.get(builtin_eid::typename_))
        ? (arg_er.is_const_result ? arg_er.value() : entity_identifier{})
        : arg_type;

    bool is_numeric = false;
    if (checked_type) {
        switch (static_cast<builtin_eid>(checked_type.value)) {
        case builtin_eid::i8: case builtin_eid::u8: case builtin_eid::i16: case builtin_eid::u16:
        case builtin_eid::i32: case builtin_eid::u32: case builtin_eid::i64: case builtin_eid::u64:
        case builtin_eid::f16: case builtin_eid::f32: case builtin_eid::f64:
        case builtin_eid::integer: case builtin_eid::decimal:
            is_numeric = true;
            break;
        default:
            break;
        }
    }
    pmd->signature.result.emplace(env.get(is_numeric ? builtin_eid::true_ : builtin_eid::false_), true);

    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    return pmd;
}

std::expected<syntax_expression_result, error_storage> numeric_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return syntax_expression_result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

}
