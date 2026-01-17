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
    
    auto arg_descr = call_session.get_next_positioned_argument(builtin_eid::string, value_modifier_t::constexpr_value);
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));
        
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(arg_descr->result, arg_descr->expression->location);
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
