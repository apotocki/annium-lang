//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_head_pattern.hpp"
#include "tuple_pattern_base.hpp"

#include <algorithm>

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/auxiliary.hpp"

#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

// head( make_tuple(name0: value0, ...) ) => make_tuple(name0^^::identifier, value0)
// head( make_tuple(const value0, ...) ) => const value0
// head( make_tuple(value0, ...) ) => value0

// head( typename tuple(name0: value0, ...) ) => typename tuple(name0^^::identifier, value0)
// head( typename tuple(const value0, ...) ) => const value0
// head( typename tuple(type, ...) ) => type

std::expected<functional_match_descriptor_ptr, error_storage> tuple_head_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    // Use shared base logic
    return try_match_tuple(ctx, call, {});
}

std::expected<syntax_expression_result, error_storage> tuple_head_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& tmd = static_cast<tuple_pattern_match_descriptor&>(md);
    auto& [_, ser, loc] = md.matches.front();

    entity_identifier rtype;
    field_descriptor const& head_field = tmd.arg_sig.fields().front();
    if (head_field.name()) {
        entity_signature rsig{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
        rsig.emplace_back(e.make_identifier_entity(head_field.name()).id, true);
        rsig.emplace_back(head_field.entity_id(), head_field.is_const());
        rtype = e.make_basic_signatured_entity(std::move(rsig)).id;
    } else {
        rtype = head_field.entity_id();
    }

    if (tmd.is_argument_typename) {
        return syntax_expression_result{
            .value_or_type = rtype,
            .is_const_result = true
        };
    }
    if (ser.is_const_result || head_field.is_const()) {
        return syntax_expression_result{
            .value_or_type = head_field.name() ? e.make_empty_entity(rtype).id : rtype,
            .is_const_result = true
        };
    }
    
    ser.value_or_type = rtype; // single non-const field, so use it as result
    size_t src_size = std::ranges::count_if(tmd.arg_sig.fields(), [](field_descriptor const& fd) { return !fd.is_const(); });
    if (src_size > 1) {
        e.push_back_expression(el, ser.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(0) } });
        e.push_back_expression(el, ser.expressions, semantic::invoke_function(e.get(builtin_eid::array_at)));
    }
    return std::move(ser);
}

}
