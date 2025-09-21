//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_pattern_base.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage>
tuple_pattern_base::try_match_tuple(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);
    std::pair<syntax_expression_t const*, size_t> arg_expr;
    auto arg = call_session.use_next_positioned_argument(exp, &arg_expr);
    if (!arg) {
        if (!arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing argument"sv));
        }
        return std::unexpected(arg.error());
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    syntax_expression_result& er = arg->first;
    entity_identifier argtype;
    shared_ptr<tuple_pattern_match_descriptor> pmd;
    if (er.is_const_result) {
        entity const& arg_entity = get_entity(e, er.value());
        if (auto psig = arg_entity.signature(); psig && psig->name == e.get(builtin_qnid::tuple)) {
            // argument is typename tuple
            if (psig->empty()) {
                return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), er.value(), "a not empty tuple type"sv));
            }
            pmd = make_shared<tuple_pattern_match_descriptor>(call, *psig, true);
        } else {
            argtype = arg_entity.get_type();
        }
    } else {
        argtype = er.type();
    }

    if (!pmd) {
        entity const& tpl_entity = get_entity(e, argtype);
        entity_signature const* psig = tpl_entity.signature();
        if (!psig || psig->name != e.get(builtin_qnid::tuple)) {
            return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), argtype, "a tuple"sv));
        }
        if (psig->empty()) {
            return std::unexpected(make_error<type_mismatch_error>(get_start_location(*get<0>(arg_expr)), argtype, "a not empty tuple"sv));
        }
        pmd = make_shared<tuple_pattern_match_descriptor>(call , *tpl_entity.signature(), false);
    }
    pmd->emplace_back(0, er);
    return pmd;
}

}
