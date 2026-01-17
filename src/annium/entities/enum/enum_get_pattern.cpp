//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium/entities/enum/enum_get_pattern.hpp"
#include "annium/entities/enum/enum_entity.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class enum_get_match_descriptor : public functional_match_descriptor
{
public:
    inline enum_get_match_descriptor(prepared_call const& call, size_t which_val) noexcept
        : functional_match_descriptor{ call }
        , which{ which_val }
    {
    }

    size_t which;
};

std::expected<functional_match_descriptor_ptr, error_storage> enum_get_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    
    auto slf_arg_descr = call_session.get_named_argument(builtin_id::self);
    if (!slf_arg_descr) return std::unexpected(std::move(slf_arg_descr.error()));

    resource_location const& slfargloc = slf_arg_descr->expression->location;
    syntax_expression_result& slf_arg_er = slf_arg_descr->result;
    if (!slf_arg_er.is_const_result) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slf_arg_er.value_or_type, "an enumeration typename"sv));
    }
    entity const& slf_type_entity = get_entity(env, slf_arg_er.value());
    enum_entity const* pe = dynamic_cast<enum_entity const*>(&slf_type_entity);
    if (!pe) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slf_arg_er.value(), "an enumeration typename"sv));
    }
    
    auto prop_arg_descr = call_session.get_named_argument(builtin_id::property, builtin_eid::identifier, value_modifier_t::constexpr_value);
        
    if (!prop_arg_descr) return std::unexpected(std::move(prop_arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& propargloc = prop_arg_descr->expression->location;
    syntax_expression_result& prop_arg_er = prop_arg_descr->result;
    identifier_entity const& ident = dynamic_cast<identifier_entity const&>(get_entity(env, prop_arg_er.value()));
    auto opt_which = pe->find(ident.value());
    if (!opt_which) {
        return std::unexpected(make_error<value_mismatch_error>(propargloc, prop_arg_er.value(), ("an enumeration case of %1%"_fmt % env.print(pe->name())).str()));
    }

    auto pmd = make_shared<enum_get_match_descriptor>(call, *opt_which);
    
    pmd->append_arg(env.get(builtin_id::self), slf_arg_er, slfargloc);
    pmd->append_arg(env.get(builtin_id::property), prop_arg_er, propargloc);
    
    entity_signature& call_sig = pmd->signature;
    
    if (can_be_only_runtime(exp.modifier)) {
        call_sig.result.emplace(slf_arg_er.value(), false);
    } else {
        call_sig.result.emplace(env.make_integer_entity(*opt_which, slf_arg_er.value()), true);
    }
    return pmd;
}

std::expected<syntax_expression_result, error_storage> enum_get_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    field_descriptor const& rfd = *md.signature.result;
    syntax_expression_result result{
        .value_or_type = rfd.entity_id(),
        .is_const_result = rfd.is_const()
    };
    if (!rfd.is_const()) {
        auto& emd = static_cast<enum_get_match_descriptor&>(md);
        env.push_back_expression(el, result.expressions, semantic::push_value{ ui64_blob_result(emd.which) });
    }
    return result;
}

}
