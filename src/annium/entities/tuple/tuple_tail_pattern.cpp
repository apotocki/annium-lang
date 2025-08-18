//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_tail_pattern.hpp"
#include "tuple_pattern_base.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/ct_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> tuple_tail_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    // Use shared base logic
    return try_match_tuple(ctx, call, exp);
}

std::expected<syntax_expression_result_t, error_storage> tuple_tail_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& tmd = static_cast<tuple_pattern_match_descriptor&>(md);

    entity_signature result_sig{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
    entity_signature const& arg_sig = tmd.arg_sig;

    auto bit = arg_sig.fields().begin(), eit = arg_sig.fields().end();
    BOOST_ASSERT(bit != eit);
    field_descriptor const& first_field = *bit;

    size_t mut_field_count = 0;
    for (++bit; bit != eit; ++bit) {
        result_sig.push_back(*bit);
        if (!bit->is_const()) {
            ++mut_field_count;
        }
    }
    entity const& result_tuple = e.make_basic_signatured_entity(std::move(result_sig));
    auto & [_, ser, loc] = tmd.matches.front();
    
    if (tmd.is_argument_typename) {
        // return typename tuple
        ser.value_or_type = result_tuple.id;
        BOOST_ASSERT(ser.is_const_result);
        return ser;
    }
    if (!first_field.is_const()) {
        BOOST_ASSERT(ser.expressions);
        if (mut_field_count) {
            e.push_back_expression(el, ser.expressions, semantic::invoke_function(e.get(builtin_eid::array_tail)));
        } else {
            e.push_back_expression(el, ser.expressions, semantic::truncate_values(1, false));
        }
    }
    if (mut_field_count) {
        ser.value_or_type = result_tuple.id;
        BOOST_ASSERT(!ser.is_const_result);
        return std::move(ser);
    }
    ser.value_or_type = e.make_empty_entity(result_tuple).id;
    ser.is_const_result = true;
    return std::move(ser);
}

}
