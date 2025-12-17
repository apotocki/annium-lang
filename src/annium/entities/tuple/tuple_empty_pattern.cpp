//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_empty_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> tuple_empty_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t arg_descr;
    auto arg = call_session.use_next_positioned_argument(&arg_descr);
    if (!arg && arg.error()) return std::unexpected(arg.error());
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    entity_identifier argtype;
    shared_ptr<functional_match_descriptor> pmd;

    syntax_expression_result& er = arg->first;
    if (er.is_const_result) {
        entity const& arg_entity = get_entity(e, er.value());
        if (auto psig = arg_entity.signature(); psig && psig->name == e.get(builtin_qnid::tuple)) {
            // argument is typename tuple
            pmd = make_shared<functional_match_descriptor>(call);
            pmd->signature.result.emplace(e.make_bool_entity(psig->fields().empty()).id, true);
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
            return std::unexpected(make_error<type_mismatch_error>(arg_descr.expression->location, er.value_or_type, "a tuple"sv));
        }
        pmd = make_shared<functional_match_descriptor>(call);
        pmd->signature.result.emplace(e.make_bool_entity(psig->fields().empty()).id, true);
    }
    pmd->emplace_back(0, er);
    
    return pmd;
}

std::expected<syntax_expression_result, error_storage> tuple_empty_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    syntax_expression_result result {
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };

    if (!md.matches.empty()) {
        syntax_expression_result& arg = get<1>(md.matches.front());
        result.temporaries = std::move(arg.temporaries);
        result.branches_expressions = std::move(arg.branches_expressions);
    }

    return result;
}

}
