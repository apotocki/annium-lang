//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "union_bit_or_pattern.hpp"

#include <boost/container/flat_set.hpp>

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage>
union_bit_or_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);

    auto pmd = make_shared<functional_match_descriptor>(call);

    for (size_t argnum = 0;; ++argnum) {
        prepared_call::argument_descriptor_t arg_expr;
        auto arg = call_session.use_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::constexpr_value }, &arg_expr);
        if (!arg) {
            if (!arg.error()) break; // no more arguments
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                std::move(arg.error())));
        }
        syntax_expression_result& er = arg->first;
        if (!er.is_const_result) {
            return std::unexpected(make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "argument must be a constant expression"sv));
        }

        pmd->emplace_back(argnum, er, get_start_location(*get<0>(arg_expr)));
        pmd->signature.emplace_back(er.value(), true);
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage> union_bit_or_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();

    boost::container::small_flat_set<entity_identifier, 8> elements;
    small_vector<entity_identifier, 8> elements_vec;

    for (auto const& m : md.matches) {
        auto & [_, er, loc] = m;
        
        entity const& arg_entity = get_entity(env, er.value());
        if (arg_entity.get_type() == ctx.env().get(builtin_eid::typename_)) {
            if (entity_signature const* psig = arg_entity.signature(); psig && psig->name == env.get(builtin_qnid::union_)) {
                for (field_descriptor const& fd : psig->fields()) {
                    if (elements.insert(fd.entity_id()).second) {
                        elements_vec.push_back(fd.entity_id());
                    }
                }
                continue;
            }
        }
        if (elements.insert(er.value()).second) {
            elements_vec.push_back(er.value());
        }
    }

    return syntax_expression_result{
        .value_or_type = env.make_union_type_entity(elements_vec).id,
        .is_const_result = true
    };
}

} // namespace annium
