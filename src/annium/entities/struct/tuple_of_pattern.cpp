//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_of_pattern.hpp"
#include "struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class tuple_of_match_descriptor : public functional_match_descriptor
{
public:
    inline tuple_of_match_descriptor(prepared_call const& pcall, struct_entity const& ent) noexcept
        : functional_match_descriptor{ pcall }
        , sent{ ent }
    {}

    struct_entity const& sent;

    // True when the argument was already `ref(of: StructType)` rather than a plain struct value --
    // apply() then relabels it to `ref(of: TupleType)` instead of plain `TupleType`. Either way this
    // is a zero-cost type relabel: a struct and its underlying tuple share the exact same runtime
    // representation, and a reference doesn't store the type it points at (that's purely a
    // compile-time label), so reinterpreting the referent's type costs nothing at runtime either.
    bool is_ref = false;
};

std::expected<functional_match_descriptor_ptr, error_storage> tuple_of_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);
    
    auto arg_descr = call_session.get_next_positioned_argument();
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), 
            "is_struct accepts exactly one argument"sv, std::move(argterm.value())));
    }

    syntax_expression_result& arg_er = arg_descr->result;
    resource_location arg_loc = arg_descr->expression->location;

    entity const* arg_entity;
    entity_identifier arg_type = get_result_type(env, arg_er, &arg_entity);
    // Reference-aware: `ref(structval).field` (via the `get`/`set` overloads below) passes a
    // `ref(of: StructType)` self here, not a plain struct value -- decompose it first and check
    // struct-ness against the unwrapped type, same as tuple_get_pattern/fixed_array_get_pattern
    // already do for their own `self`.
    entity_identifier ref_of = try_decompose_ref_of(env, arg_type);
    entity_identifier struct_type = ref_of ? ref_of : arg_type;
    struct_entity const* arg_as_struct = dynamic_cast<struct_entity const*>(&get_entity(env, struct_type));
    if (!arg_as_struct) {
        return std::unexpected(make_error<type_mismatch_error>(arg_loc, struct_type, "a struct type"sv));
    }

    // Create match descriptor
    auto pmd = make_shared<tuple_of_match_descriptor>(call, *arg_as_struct);
    pmd->is_ref = (bool)ref_of;
    pmd->append_arg(std::move(arg_er), std::move(arg_loc));
    return pmd;
}

std::expected<syntax_expression_result, error_storage> tuple_of_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    auto& tmd = static_cast<tuple_of_match_descriptor&>(md);
    auto res = tmd.sent.underlying_tuple_eid(ctx);
    if (!res) {
        return std::unexpected(std::move(res.error()));
    }
    auto& arg_er = std::get<1>(md.matches.front());
    BOOST_ASSERT(!arg_er.is_const_result);
    arg_er.value_or_type = tmd.is_ref ? make_ref_of_type(ctx.env(), *res) : *res;

    return std::move(arg_er);
}

}
