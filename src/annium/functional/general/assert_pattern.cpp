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

std::expected<functional_match_descriptor_ptr, error_storage> assert_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto call_session = call.new_session(ctx);
    expected_result_t bool_exp{ ctx.env().get(builtin_eid::boolean), call.location };
    std::pair<syntax_expression const*, size_t> argexpr;
    auto firstarg = call_session.use_next_positioned_argument(bool_exp, &argexpr);
    if (!firstarg) return std::unexpected(firstarg.error());
    auto pmd = make_shared<assert_match_descriptor>(call);
    size_t argnum = 0;

    auto append_arg = [&pmd, &argnum, &argexpr](environment& e, syntax_expression_result& res) {
        pmd->emplace_back(argnum++, res);
        if (res.is_const_result && res.value() == e.get(builtin_eid::true_)) {
            pmd->reserved_errors.emplace_back(); // just dummy, no error doesn't need details
        } else {
           // assert failed
            pmd->reserved_errors.emplace_back(
                make_error<basic_general_error>(get<0>(argexpr)->location, "Assertion failed!"sv, *get<0>(argexpr))
            );
        }
    };
    append_arg(ctx.env(), firstarg->first);
    
    while (call_session.has_more_positioned_arguments()) {
        auto nextarg = call_session.use_next_positioned_argument(bool_exp, &argexpr);
        if (!nextarg) return std::unexpected(nextarg.error());
        append_arg(ctx.env(), nextarg->first);
    }
    
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "Argument mismatch!"sv, std::move(argterm.value())));
    }
    
    return std::move(pmd);
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
    return std::move(res);
}

}
