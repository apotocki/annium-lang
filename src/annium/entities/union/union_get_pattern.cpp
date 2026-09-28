//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "union_get_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

class union_get_match_descriptor : public functional_match_descriptor
{
public:
    inline union_get_match_descriptor(prepared_call const& call, bool enum_union_val, size_t which_val) noexcept
        : functional_match_descriptor{ call }
        , enum_union{ enum_union_val }
        , which{ which_val }
    {}

    bool enum_union;
    size_t which;
};

std::expected<functional_match_descriptor_ptr, error_storage> union_get_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    (void)exp;

    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);

    auto slf_arg_descr = call_session.get_named_argument(builtin_id::self);
    if (!slf_arg_descr) return std::unexpected(std::move(slf_arg_descr.error()));

    resource_location const& slfargloc = slf_arg_descr->expression->location;
    syntax_expression_result& slf_arg_er = slf_arg_descr->result;
    if (!slf_arg_er.is_const_result) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slf_arg_er.value_or_type, "a union typename"sv));
    }
    entity const& slf_type_entity = get_entity(env, slf_arg_er.value());
    entity_signature const* union_sig = slf_type_entity.signature();
    if (!union_sig || union_sig->name != env.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slf_arg_er.value(), "a union typename"sv));
    }

    auto prop_arg_descr = call_session.get_named_argument(builtin_id::property, builtin_eid::identifier, value_modifier_t::constexpr_value);
    if (!prop_arg_descr) return std::unexpected(std::move(prop_arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& propargloc = prop_arg_descr->expression->location;
    syntax_expression_result& prop_arg_er = prop_arg_descr->result;
    identifier_entity const& ident = dynamic_cast<identifier_entity const&>(get_entity(env, prop_arg_er.value()));

    // only a bare (const/atom) case has a meaningful no-argument form here -- a structural case
    // needs its own field values, see union_get_pattern.hpp.
    optional<size_t> which;
    bool enum_union = true;
    for (size_t i = 0; i < union_sig->field_count(); ++i) {
        field_descriptor const& fd = union_sig->field(i);
        if (!fd.is_const()) {
            enum_union = false;
            continue;
        }
        if (!which) {
            if (identifier_entity const* id_ent = dynamic_cast<identifier_entity const*>(&get_entity(env, fd.entity_id()));
                id_ent && id_ent->value() == ident.value())
            {
                which = i;
            }
        }
    }
    if (!which) {
        return std::unexpected(make_error<value_mismatch_error>(propargloc, prop_arg_er.value(),
            ("a bare case of %1%"_fmt % env.print(slf_arg_er.value())).str()));
    }

    auto pmd = make_shared<union_get_match_descriptor>(call, enum_union, *which);

    pmd->append_arg(env.get(builtin_id::self), slf_arg_er, slfargloc);
    pmd->append_arg(env.get(builtin_id::property), prop_arg_er, propargloc);

    // always the union type, never const -- matches to_union_implicit_cast_pattern's own
    // convention (any value actually cast into a union is runtime-classified from that point on).
    pmd->signature.result.emplace(slf_arg_er.value(), false);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> union_get_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& umd = static_cast<union_get_match_descriptor&>(md);
    field_descriptor const& rfd = *md.signature.result;
    syntax_expression_result result{
        .value_or_type = rfd.entity_id(),
        .is_const_result = false
    };

    // exactly the same runtime construction to_union_implicit_cast_pattern::apply() emits for a
    // constexpr atom that exactly matches one of the union's own const fields -- see
    // to_union_implicit_cast_pattern.cpp:141-186 (the enum_union / exact-const-case branches).
    if (umd.enum_union) {
        env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(umd.which) } });
        return result;
    }

    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{} }); // dummy value for a const union element
    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(umd.which) } });
    env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(2) } });
    env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::arrayify)));

    return result;
}

}
