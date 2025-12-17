//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "create_identifier_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

// __id(const string)
std::expected<functional_match_descriptor_ptr, error_storage> create_identifier_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_descr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t{ .type = ctx.env().get(builtin_eid::string), .modifier = value_modifier_t::constexpr_value }, &arg_descr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(arg_descr.expression->location, "invalid argument"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing argument"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg->first, arg_descr.expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> create_identifier_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& [_, ser, loc] = md.matches.front();
    //entity_identifier strid = ser.value();
    generic_literal_entity const& str_ent = static_cast<generic_literal_entity const&>(get_entity(e, ser.value()));
    identifier id = e.slregistry().resolve(str_ent.value().as<string_view>());
    semantic::managed_expression_list rel{ e };
    rel.splice_back(el, ser.expressions);
        
    return syntax_expression_result{
        .expressions = std::move(rel),
        .value_or_type = e.make_identifier_entity(id).id,
        .is_const_result = true
    };
}

}
