//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "union_typeof_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/struct/struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> union_typeof_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    auto slf_arg = call_session.get_next_positioned_argument(builtin_eid::typename_, value_modifier_t::constexpr_value, "a union typename"sv);
    if (!slf_arg) return std::unexpected(std::move(slf_arg.error()));

    resource_location const& slf_loc = slf_arg->expression->location;
    syntax_expression_result& slf_er = slf_arg->result;
    if (!slf_er.is_const_result) {
        return std::unexpected(make_error<type_mismatch_error>(slf_loc, slf_er.value_or_type, "a union typename"sv));
    }
    entity const& slf_type_entity = get_entity(e, slf_er.value());
    entity_signature const* union_sig = slf_type_entity.signature();
    if (!union_sig || union_sig->name != e.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(slf_loc, slf_er.value(), "a union typename"sv));
    }

    prepared_call::argument_descriptor_t prop_arg_descr;
    alt_error prop_errors;
    auto property_arg = call_session.use_next_positioned_argument(expected_result_t{ .type = e.get(builtin_eid::integer), .modifier = value_modifier_t::constexpr_value }, &prop_arg_descr);
    if (!property_arg) {
        prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
        call_session.reuse_argument(prop_arg_descr.arg_index);
        property_arg = call_session.use_next_positioned_argument(expected_result_t{ .type = e.get(builtin_eid::identifier), .modifier = value_modifier_t::constexpr_value }, &prop_arg_descr);
    }
    if (!property_arg) {
        if (prop_errors.alternatives.empty()) {
            return std::unexpected(std::move(property_arg.error()));
        } else {
            prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
            return std::unexpected(make_error<alt_error>(std::move(prop_errors)));
        }
    }
    if (!*property_arg) {
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: case index or name"sv));
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& prop_loc = prop_arg_descr.expression->location;
    syntax_expression_result& prop_er = prop_arg_descr.result;
    entity const& prop_entity = get_entity(e, prop_er.value());
    entity_identifier const identifier_type_eid = e.get(builtin_eid::identifier);

    // a bare/const case is only ever the atom itself -- it has no type of its own beyond that,
    // so report the honest, uniform `typename ::__identifier` rather than something case-specific.
    auto field_result_type = [&](field_descriptor const& fd) -> entity_identifier {
        return fd.is_const() ? identifier_type_eid : fd.entity_id();
    };

    small_vector<entity_identifier, 4> matches;

    if (auto const* int_lit = dynamic_cast<generic_literal_entity const*>(&prop_entity)) {
        size_t idx = int_lit->value().as<size_t>();
        field_descriptor const* fd = union_sig->get_field(idx);
        if (!fd) {
            return std::unexpected(make_error<basic_general_error>(prop_loc, "union case index out of range"sv, prop_er.value()));
        }
        matches.push_back(field_result_type(*fd));
    } else if (auto const* id_lit = dynamic_cast<identifier_entity const*>(&prop_entity)) {
        // exactly the short-name search `match`'s own scrutinee reflection does -- see
        // base_expression_visitor.cpp's operator()(match_expression const&) -- just collecting
        // every match instead of stopping at the first (see union_typeof_pattern.hpp).
        for (field_descriptor const& fd : union_sig->fields()) {
            if (fd.is_const()) {
                if (identifier_entity const* case_id = dynamic_cast<identifier_entity const*>(&get_entity(e, fd.entity_id()));
                    case_id && case_id->value() == id_lit->value())
                {
                    matches.push_back(identifier_type_eid);
                }
            } else if (struct_entity const* sent = dynamic_cast<struct_entity const*>(&get_entity(e, fd.entity_id()))) {
                if (qname_view qn = sent->name(); qn && qn.back() == id_lit->value()) {
                    matches.push_back(fd.entity_id());
                }
            }
        }
        if (matches.empty()) {
            return std::unexpected(make_error<value_mismatch_error>(prop_loc, prop_er.value(),
                ("a case of %1%"_fmt % e.print(slf_er.value())).str()));
        }
    } else {
        return std::unexpected(make_error<type_mismatch_error>(prop_loc, prop_er.value(), "an integer or identifier"sv));
    }

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->append_arg(slf_er, slf_loc);
    pmd->append_arg(prop_er, prop_loc);
    pmd->signature.result.emplace(e.make_union_type_entity(matches).id, true);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> union_typeof_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return syntax_expression_result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

}
