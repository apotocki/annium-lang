//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "string_concat_pattern.hpp"

#include "annium/entities/prepared_call.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage>
string_concat_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    
    // Verify expected result type is string
    if (exp && exp.type != e.get(builtin_eid::string)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "string"sv));
    }
    
    auto call_session = call.new_session(ctx);
    auto pmd = sonia::make_shared<functional_match_descriptor>(call);
    
    // Process all string arguments
    expected_result_t string_exp{ e.get(builtin_eid::string), call.location };
    std::pair<syntax_expression const*, size_t> arg_expr;
    for (size_t arg_idx = 0;; ++arg_idx) {
        auto arg = call_session.use_next_positioned_argument(string_exp, &arg_expr);
        if (!arg) {
            if (auto err = arg.error()) return std::unexpected(std::move(err));
            break; // No more arguments
        }
        // Add arg to match results for later use in apply
        pmd->emplace_back(arg_idx, arg->first);
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage>
string_concat_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    
    syntax_expression_result result{ };
    size_t concat_runtime_arg_count = 0;
    std::ostringstream concat_stream;
    for (auto& [idx, er, loc] : md.matches) {
        // Check if the argument is a const string literal
        if (er.is_const_result) {
            generic_literal_entity const* psle = dynamic_cast<generic_literal_entity const*>(&get_entity(e, er.value()));
            BOOST_ASSERT(psle);
            concat_stream << psle->value().as<string_view>();
        } else {
            // if concat_stream is not empty, convert to runtime string
            auto prev_str = concat_stream.str();
            if (!prev_str.empty()) {
                smart_blob strval{ string_blob_result(std::move(prev_str)) }; // will allocate
                e.push_back_expression(el, result.expressions,
                    semantic::push_value{ std::move(strval) });
                ++concat_runtime_arg_count;
                concat_stream.str(""); // Clear the stream
            }
            result.expressions = el.concat(result.expressions, er.expressions);
            ++concat_runtime_arg_count;
        }
    }

    auto prev_str = concat_stream.str();
    if (concat_runtime_arg_count) {
        if (!prev_str.empty()) {
            smart_blob strval{ string_blob_result(std::move(prev_str)) }; // will allocate
            e.push_back_expression(el, result.expressions, semantic::push_value{ std::move(strval) });
            ++concat_runtime_arg_count;
        }
        result.value_or_type = e.get(builtin_eid::string);
        result.is_const_result = false;
        if (concat_runtime_arg_count > 1) {
            // If we have multiple runtime arguments, we need to use the concat builtin
            e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(concat_runtime_arg_count) } });
            e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::concat)));
        } // else only one runtime argument, just return it as is
    } else {
        // If no runtime arguments, we can return a const string result
        result.is_const_result = true;
        result.value_or_type = e.make_string_entity(small_string{ prev_str }).id;
    }

    return result;
}

} // namespace annium
