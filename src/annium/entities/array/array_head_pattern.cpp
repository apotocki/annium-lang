//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "array_head_pattern.hpp"

#include <algorithm>

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/value_mismatch_error.hpp"

namespace annium {

class array_head_pattern_match_descriptor : public functional_match_descriptor
{
public:
    inline array_head_pattern_match_descriptor(prepared_call const& call, entity_signature const* sig) noexcept
        : functional_match_descriptor{ call }
        , arg_sig{ sig }
    {}

    entity_signature const* arg_sig;
};

std::expected<functional_match_descriptor_ptr, error_storage> array_head_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);
    std::pair<syntax_expression_t const*, size_t> arg_expr;
    auto arg = call_session.use_next_positioned_argument(&arg_expr);
    if (!arg) {
        if (!arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing argument"sv));
        }
        return std::unexpected(arg.error());
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    syntax_expression_result_t& er = arg->first;
    entity_identifier argtype;
    shared_ptr<functional_match_descriptor> pmd;
    if (er.is_const_result) {
        entity const& arg_entity = get_entity(e, er.value());
        if (auto psig = arg_entity.signature(); psig && psig->name == e.get(builtin_qnid::data)) {
            argtype = arg_entity.get_type();
            pmd = make_shared<array_head_pattern_match_descriptor>(call, psig);
        } else {
            return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), er.value(), "an array type"sv));
        }
    } else {
        argtype = er.type();
        pmd = make_shared<array_head_pattern_match_descriptor>(call, nullptr);
    }

    entity const& arg_type_entity = get_entity(e, argtype);
    if (auto psig = arg_type_entity.signature(); !psig || psig->name != e.get(builtin_qnid::array)) {
        return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), argtype, "an array type"sv));
    }

    pmd->emplace_back(0, er, get_start_location(*get<0>(arg_expr)));
    return pmd;
}

std::expected<syntax_expression_result_t, error_storage> array_head_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& amd = static_cast<array_head_pattern_match_descriptor&>(md);
    auto& [_, er, loc] = md.matches.front();

    if (er.is_const_result) {
        field_descriptor const* pfd = amd.arg_sig->get_field(0);
        if (!pfd) {
            return std::unexpected(make_error<value_mismatch_error>(loc, er.value(), "empty array type"sv));
        }
        er.value_or_type = pfd->entity_id();
    } else {
        entity const& arg_type_entity = get_entity(e, er.type());
        field_descriptor const* tfd = arg_type_entity.signature()->find_field(e.get(builtin_id::of));
        if (!tfd) {
            THROW_INTERNAL_ERROR("array_head_pattern::apply: expected 'of' field in array type"sv);
        }
        er.value_or_type = tfd->entity_id();
        field_descriptor const* szfd = arg_type_entity.signature()->find_field(e.get(builtin_id::size));
        if (!szfd) {
            THROW_INTERNAL_ERROR("array_head_pattern::apply: expected 'size' field in array type"sv);
        }
        generic_literal_entity const* pszent = dynamic_cast<generic_literal_entity const*>(&get_entity(e, szfd->entity_id()));
        if (!pszent) {
            THROW_INTERNAL_ERROR("array_head_pattern::apply: expected 'size' field to be a literal entity"sv);
        }
        size_t arrsz = pszent->value().as<size_t>();
        if (arrsz > 1) {
            e.push_back_expression(el, er.expressions, semantic::push_by_offset{ 0 });
            e.push_back_expression(el, er.expressions, semantic::invoke_function(e.get(builtin_eid::array_at)));
        }
    }
    return std::move(er);
}

}
