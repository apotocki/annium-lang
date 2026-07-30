//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "numeric_cast_constexpr_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

namespace {

// mirrors annium_numeric_cast<T> in library/annium_library.cpp: static_cast-like truncation,
// bits of the source value are kept regardless of precision loss.
template <typename T>
T numeric_cast_truncate(smart_blob const& arg)
{
    if (::is_floating_point(arg->type)) {
        return static_cast<T>(arg.as<numetron::decimal_view>());
    }
    return static_cast<T>(arg.as<numetron::integer_view>());
}

smart_blob numeric_cast_truncate_to(smart_blob const& arg, builtin_eid target_type)
{
    switch (target_type) {
    case builtin_eid::i8:  return smart_blob{ i8_blob_result(numeric_cast_truncate<int8_t>(arg)) };
    case builtin_eid::u8:  return smart_blob{ ui8_blob_result(numeric_cast_truncate<uint8_t>(arg)) };
    case builtin_eid::i16: return smart_blob{ i16_blob_result(numeric_cast_truncate<int16_t>(arg)) };
    case builtin_eid::u16: return smart_blob{ ui16_blob_result(numeric_cast_truncate<uint16_t>(arg)) };
    case builtin_eid::i32: return smart_blob{ i32_blob_result(numeric_cast_truncate<int32_t>(arg)) };
    case builtin_eid::u32: return smart_blob{ ui32_blob_result(numeric_cast_truncate<uint32_t>(arg)) };
    case builtin_eid::i64: return smart_blob{ i64_blob_result(numeric_cast_truncate<int64_t>(arg)) };
    case builtin_eid::u64: return smart_blob{ ui64_blob_result(numeric_cast_truncate<uint64_t>(arg)) };
    default:
        THROW_NOT_IMPLEMENTED_ERROR("numeric_cast_constexpr_pattern: unsupported target type"sv);
    }
}

}

std::expected<functional_match_descriptor_ptr, error_storage>
numeric_cast_constexpr_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();

    bool valid_target = exp.type == env.get(builtin_eid::i8) || exp.type == env.get(builtin_eid::u8) ||
        exp.type == env.get(builtin_eid::i16) || exp.type == env.get(builtin_eid::u16) ||
        exp.type == env.get(builtin_eid::i32) || exp.type == env.get(builtin_eid::u32) ||
        exp.type == env.get(builtin_eid::i64) || exp.type == env.get(builtin_eid::u64);
    if (!valid_target) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "a fixed-width integer type"sv));
    }
    builtin_eid target_type = static_cast<builtin_eid>(exp.type.value);

    auto call_session = call.new_session(ctx);
    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = value_modifier_t::constexpr_value });
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(),
            "numeric_cast accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg_descr->result;
    resource_location arg_loc = arg_descr->expression->location;

    entity const& arg_entity = get_entity(env, arg_er.value());
    entity_identifier source_type_id = arg_entity.get_type();

    switch (static_cast<builtin_eid>(source_type_id.value)) {
    case builtin_eid::boolean:
    case builtin_eid::integer:
    case builtin_eid::decimal:
    case builtin_eid::f16:
    case builtin_eid::f32:
    case builtin_eid::f64:
    case builtin_eid::i8:
    case builtin_eid::u8:
    case builtin_eid::i16:
    case builtin_eid::u16:
    case builtin_eid::i32:
    case builtin_eid::u32:
    case builtin_eid::i64:
    case builtin_eid::u64:
        break;
    default:
        return std::unexpected(make_error<type_mismatch_error>(arg_loc, source_type_id, "a numeric literal type"sv));
    }

    generic_literal_entity const& src_literal = dynamic_cast<generic_literal_entity const&>(arg_entity);
    smart_blob result_blob = numeric_cast_truncate_to(src_literal.value(), target_type);

    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->signature.result.emplace(env.make_generic_entity(std::move(result_blob), exp.type).id, true);
    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
numeric_cast_constexpr_pattern::apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    return syntax_expression_result{
        .value_or_type = md.signature.result->entity_id(),
        .is_const_result = true
    };
}

}
