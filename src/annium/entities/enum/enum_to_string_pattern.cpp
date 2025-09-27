//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "enum_to_string_pattern.hpp"
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

std::expected<functional_match_descriptor_ptr, error_storage> enum_to_string_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    value_modifier_t arg_req_mod = can_be_only_constexpr(exp.modifier) ? exp.modifier : value_modifier_t::constexpr_or_runtime_value;
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_expr;
    auto arg = call_session.use_next_positioned_argument(expected_result_t { .modifier = arg_req_mod }, &arg_expr);
    if (!arg) {
        if (arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                std::move(arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& argloc = get_start_location(*get<0>(arg_expr));
    syntax_expression_result& arg_er = arg->first;
    
    entity const* pcent;
    entity_identifier arg_type = get_result_type(env, arg_er, &pcent);
    enum_entity const* pe = dynamic_cast<enum_entity const*>(&get_entity(env, arg_type)); // check type existence
    if (!pe) {
        return std::unexpected(make_error<type_mismatch_error>(argloc, arg_type, "an enumeration"sv));
    }

    auto pmd = make_shared<enum_to_string_match_descriptor>(call, *pe);
    pmd->emplace_back(0, arg_er, argloc);
    pmd->signature.emplace_back(arg_er.value_or_type, arg_er.is_const_result);

    if (arg_er.is_const_result) {
        BOOST_ASSERT(pcent);
        size_t which = static_cast<generic_literal_entity const&>(*pcent).value().as<size_t>();
        BOOST_ASSERT(which < pe->case_count());
        if (can_be_only_runtime(exp.modifier)) {
            pmd->signature.result.emplace(env.get(builtin_eid::string), false);
            pmd->which = which;
        } else {
            identifier case_id = pe->case_at(which);
            pmd->signature.result.emplace(env.make_string_entity(env.print(case_id)).id, true);
        }
    } else {
        pmd->signature.result.emplace(env.get(builtin_eid::string), false);
    }

    return pmd;
}


std::expected<syntax_expression_result, error_storage> enum_to_string_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    enum_to_string_match_descriptor& emd = static_cast<enum_to_string_match_descriptor&>(md);
    auto &[_, ser, argloc] = emd.matches.front();

    auto const& rfd = *emd.signature.result;
    syntax_expression_result result{
        .value_or_type = rfd.entity_id(),
        .is_const_result = rfd.is_const()
    };
    if (!result.is_const_result) {
        if (ser.is_const_result) {
            identifier case_id = emd.ent.case_at(emd.which);
            env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ string_blob_result(env.print(case_id)) } });
        } else {
            // create array of strings with enum case names
            small_vector<blob_result, 16> case_names;
            SCOPE_EXIT([&case_names] { for (auto& cn : case_names) blob_result_unpin(&cn); });
            case_names.reserve(emd.ent.case_count());
            for (size_t i = 0; i < emd.ent.case_count(); ++i) {
                identifier case_id = emd.ent.case_at(i);
                case_names.push_back(string_blob_result(env.print(case_id)));
            }
            smart_blob cases_arr{ array_blob_result(span{ case_names }) };
            cases_arr.allocate();
            case_names.clear(); // we can clear it now, because array_blob_result made copies of string blobs
            env.push_back_expression(el, result.expressions, semantic::push_value{ cases_arr });
            append_semantic_result(el, ser, result); // which
            env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::array_at) });
        }
    }
    return result;
}

}
