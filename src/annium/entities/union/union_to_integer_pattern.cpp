//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "union_to_integer_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

class union_to_integer_match_descriptor : public functional_match_descriptor
{
public:
    inline union_to_integer_match_descriptor(prepared_call const& call, bool enum_union_val, optional<size_t> which_val) noexcept
        : functional_match_descriptor{ call }
        , enum_union{ enum_union_val }
        , which{ which_val }
    {}

    bool enum_union;
    optional<size_t> which; // known only when the argument is itself a constexpr member value
};

std::expected<functional_match_descriptor_ptr, error_storage> union_to_integer_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    value_modifier_t arg_req_mod = can_be_only_constexpr(exp.modifier) ? exp.modifier : value_modifier_t::constexpr_or_runtime_value;
    auto call_session = call.new_session(ctx);

    auto arg_descr = call_session.get_next_positioned_argument(expected_result_t{ .modifier = arg_req_mod });
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    resource_location const& argloc = arg_descr->expression->location;
    syntax_expression_result& arg_er = arg_descr->result;

    entity_identifier arg_type = arg_er.is_const_result ? get_entity(env, arg_er.value()).get_type() : arg_er.type();
    entity_signature const* union_sig = get_entity(env, arg_type).signature();
    if (!union_sig || union_sig->name != env.get(builtin_qnid::union_)) {
        return std::unexpected(make_error<type_mismatch_error>(argloc, arg_type, "a union"sv));
    }

    bool enum_union = true;
    for (field_descriptor const& fd : union_sig->fields()) {
        if (!fd.is_const()) { enum_union = false; break; }
    }

    // known only for a constexpr argument that is itself one of the union's own const (atom)
    // members -- matches the same const-match search to_union_implicit_cast_pattern.cpp uses.
    optional<size_t> which;
    if (arg_er.is_const_result) {
        auto it = std::ranges::find_if(union_sig->fields(), [val = arg_er.value()](field_descriptor const& fd) noexcept {
            return fd.is_const() && fd.entity_id() == val;
        });
        if (it != union_sig->fields().end()) {
            which = static_cast<size_t>(it - union_sig->fields().begin());
        }
    }

    auto pmd = make_shared<union_to_integer_match_descriptor>(call, enum_union, which);
    pmd->append_arg(arg_er, argloc);

    if (which && !can_be_only_runtime(exp.modifier)) {
        pmd->signature.result.emplace(env.make_integer_entity(static_cast<int64_t>(*which)).id, true);
    } else {
        pmd->signature.result.emplace(env.get(builtin_eid::integer), false);
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage> union_to_integer_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& umd = static_cast<union_to_integer_match_descriptor&>(md);
    auto const& res = *md.signature.result;
    syntax_expression_result result{
        .value_or_type = res.entity_id(),
        .is_const_result = res.is_const()
    };

    if (!res.is_const()) {
        auto& [_, ser, argloc] = md.matches.front();
        if (ser.is_const_result) {
            // which is known at compile time, but the caller wants a materialized runtime value
            BOOST_ASSERT(umd.which);
            env.push_back_expression(el, result.expressions, semantic::push_value{ ui64_blob_result(*umd.which) });
        } else {
            append_semantic_result(el, ser, result); // self's own runtime representation
            if (!umd.enum_union) {
                // mixed union: runtime layout is [value, which] -- unfold, then drop 'value',
                // keeping just 'which' (top of stack) -- see union_apply_pattern.cpp's own unfold
                // for the same layout, and IMPLEMENTATION_NOTES.md's "Retiring enum_entity" section.
                env.push_back_expression(el, result.expressions, semantic::invoke_function{ env.get(builtin_eid::unfold) });
                env.push_back_expression(el, result.expressions, semantic::truncate_values{ .count = 1, .keep_back = 1 });
            }
            // else: an all-const (enum_union) member's own runtime representation already IS the
            // ordinal -- no unfold needed, same as union_apply_pattern.cpp's enum_union branch.
        }
    }
    return result;
}

}
