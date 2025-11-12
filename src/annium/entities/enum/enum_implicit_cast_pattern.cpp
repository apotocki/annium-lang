//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "enum_implicit_cast_pattern.hpp"
#include "enum_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

class enum_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    inline enum_implicit_cast_match_descriptor(prepared_call const& call, size_t which_val) noexcept
        : functional_match_descriptor{ call }
        , which{ which_val }
    {}

    size_t which;
};

std::expected<functional_match_descriptor_ptr, error_storage> enum_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected an enumeration result"sv));
    }
    environment& env = ctx.env();
    entity const& enum_ent = get_entity(env, exp.type);
    //entity_signature const* psig = enum_ent.signature();
    enum_entity const* penum = dynamic_cast<enum_entity const*>(&enum_ent);
    if (!penum) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "an enumeration"sv));
    }

    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t{ .type = env.get(builtin_eid::identifier), .modifier = value_modifier_t::constexpr_value }, &arg_expr);
    if (!arg) {
        if (!arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
        }
        return std::unexpected(std::move(arg.error()));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& argloc = get<0>(arg_expr)->location;
    syntax_expression_result& arg_er = arg->first;
    entity const& ent = get_entity(env, arg_er.value());
    identifier_entity const* pident = dynamic_cast<identifier_entity const*>(&ent);
    BOOST_ASSERT(pident);
    
    // check identifier value
    auto optpos = penum->find(pident->value());
    if (!optpos) {
        return std::unexpected(make_error<basic_general_error>(argloc, "not an enumeration identifier"sv, pident->id));
    }

    functional_match_descriptor_ptr pmd = make_shared<enum_implicit_cast_match_descriptor>(call, *optpos);
    pmd->emplace_back(0, arg_er, argloc);
    pmd->signature.emplace_back(arg_er.value_or_type, arg_er.is_const_result);
    bool is_runtime = can_be_only_runtime(exp.modifier);
    pmd->signature.result.emplace(is_runtime ? exp.type : env.make_integer_entity(*optpos, exp.type).id, !is_runtime);
    return pmd;
}


std::expected<syntax_expression_result, error_storage> enum_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    enum_implicit_cast_match_descriptor& emd = static_cast<enum_implicit_cast_match_descriptor&>(md);
    //auto &[_, ser, argloc] = emd.matches.front();

    auto const& rfd = *emd.signature.result;
    syntax_expression_result result{
        .value_or_type = rfd.entity_id(),
        .is_const_result = rfd.is_const()
    };
    if (!result.is_const_result) {
        e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(emd.which) } });
    }
    return result;
}

}
