//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "assert_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

class assert_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;

    small_vector<error_storage, 4> reserved_errors;
};

std::expected<functional_match_descriptor_ptr, error_storage> assert_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);
    expected_result_t bool_exp{ ctx.env().get(builtin_eid::boolean), call.location };
    
    auto first_arg_descr = call_session.get_next_positioned_argument(bool_exp);
    if (!first_arg_descr) return std::unexpected(first_arg_descr.error());
    auto pmd = make_shared<assert_match_descriptor>(call);

    auto append_arg = [&pmd, &first_arg_descr](environment& e, prepared_call::argument_descriptor_t& arg_descr) {
        pmd->append_arg(arg_descr.result, arg_descr.expression->location);
        if (arg_descr.result.is_const_result && arg_descr.result.value() == e.get(builtin_eid::true_)) {
            pmd->reserved_errors.emplace_back(); // just dummy, no error doesn't need details
        } else {
           // assert failed
            pmd->reserved_errors.emplace_back(
                make_error<basic_general_error>(first_arg_descr->expression->location, "Assertion failed!"sv, *arg_descr.expression)
            );
        }
    };
    append_arg(ctx.env(), *first_arg_descr);
    
    while (call_session.has_more_positioned_arguments()) {
        prepared_call::argument_descriptor_t arg_descr;
        auto nextarg = call_session.use_next_positioned_argument(bool_exp, &arg_descr);
        if (!nextarg) return std::unexpected(nextarg.error());
        append_arg(ctx.env(), arg_descr);
    }
    
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "Argument mismatch!"sv, std::move(argterm.value())));
    }
    
    return pmd;
}

std::expected<syntax_expression_result, error_storage> assert_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    assert_match_descriptor& amd = static_cast<assert_match_descriptor&>(md);
    alt_error errs;
    syntax_expression_result res{
        .value_or_type = e.get(builtin_eid::void_),
        .is_const_result = true
    };
    
    for (size_t arg_i = 0; arg_i < amd.reserved_errors.size(); ++arg_i) {
        auto& [_, arg_er, loc] = amd.matches[arg_i];

        if (arg_er.is_const_result) {
            if (arg_er.value() == e.get(builtin_eid::false_)) {
                // assert failed, we have error already
                errs.alternatives.emplace_back(std::move(amd.reserved_errors[arg_i]));
            }
        } else if (errs.alternatives.empty()) {
            res.temporaries.insert(res.temporaries.end(), arg_er.temporaries.begin(), arg_er.temporaries.end());
            res.expressions = el.concat(res.expressions, arg_er.expressions);
            res.branches_expressions = el.concat(res.branches_expressions, arg_er.branches_expressions);
            std::ostringstream msgss;
            e.print_to(msgss, *amd.reserved_errors[arg_i]);
            e.push_back_expression(el, res.expressions, semantic::push_value{ smart_blob{ string_blob_result(msgss.str()) } });
            e.push_back_expression(el, res.expressions, semantic::invoke_function(e.get(builtin_eid::assert)));
        }
    }

    if (!errs.alternatives.empty()) {
        return std::unexpected(make_error<alt_error>(std::move(errs)));
    }
    return res;
}

}
