//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_implicit_cast_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/errors/type_mismatch_error.hpp"
#include "annium/errors/cast_error.hpp"

#include "annium/auxiliary.hpp"

namespace annium {

class tuple_implicit_cast_match_descriptor : public functional_match_descriptor
{
public:
    inline explicit tuple_implicit_cast_match_descriptor(prepared_call const& call)
        : functional_match_descriptor{ call }
        , src_entity_type{ nullptr }
        , dst_sig{ nullptr }
    {}

    inline tuple_implicit_cast_match_descriptor(prepared_call const& call, entity const& src, entity_signature const& dst) noexcept
        : functional_match_descriptor{ call }
        , src_entity_type{ &src }
        , dst_sig{ &dst }
    {}

    entity const* src_entity_type;
    
    entity_signature const* dst_sig;
};

std::expected<functional_match_descriptor_ptr, error_storage>
tuple_implicit_cast_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "missing destination type for implicit cast"sv));
    }
    environment& e = ctx.env();
    entity const& dest_type_entity = get_entity(e, exp.type);
    auto* dst_sig = dest_type_entity.signature();
    if (!dst_sig || dst_sig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, exp.type, "a tuple"sv));
    }

    auto call_session = call.new_session(ctx);
    // Get (source tuple)
    auto arg_descr = call_session.get_next_positioned_argument();
    if (!arg_descr) return std::unexpected(std::move(arg_descr.error()));
    
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    // Both must be tuple types
    entity_identifier src_type;
    syntax_expression_result& src_arg_er = arg_descr->result;
    if (src_arg_er.is_const_result) {
        entity const& src_entity = get_entity(e, src_arg_er.value());
        src_type = src_entity.get_type();
    } else {
        src_type = src_arg_er.type();
    }

    if (src_type == exp.type) {
        // No cast needed, just return the source as is
        auto pmd = make_shared<tuple_implicit_cast_match_descriptor>(call);
        pmd->append_arg(src_arg_er, arg_descr->expression->location);
        return pmd;
    }

    entity const& src_entity_type = get_entity(e, src_type);
    auto* src_sig = src_entity_type.signature();

    if (!src_sig || src_sig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(call.location, src_entity_type.id, "a tuple"sv));
    }

    // Check field count and names
    if (src_sig->field_count() != dst_sig->field_count()) {
        return std::unexpected(make_error<basic_general_error>(call.location, "tuple field count mismatch"sv));
    }
    for (size_t i = 0; i < src_sig->field_count(); ++i) {
        auto const& src_field = *src_sig->get_field(i);
        auto const& dst_field = *dst_sig->get_field(i);
        if (src_field.name() != dst_field.name()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "tuple field name mismatch"sv));
        }
    }

    auto pmd = make_shared<tuple_implicit_cast_match_descriptor>(call, src_entity_type, *dst_sig); // ?location = get_start_location(*pself_expr))
    pmd->append_arg(src_arg_er, arg_descr->expression->location);
    pmd->signature.result.emplace(exp.type, can_be_only_constexpr(exp.modifier));
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
tuple_implicit_cast_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    tuple_implicit_cast_match_descriptor& self_md = static_cast<tuple_implicit_cast_match_descriptor&>(md);
    auto& [_, src_er, loc] = md.matches.front();

    if (!self_md.src_entity_type) {
        return std::move(src_er);
    }
    entity_signature const& src_sig = *self_md.src_entity_type->signature();
    fn_compiler_context_scope fn_scope{ ctx };

    semantic::expression_span fn_code;
    //local_variable* src_tuple_var = nullptr;
    identifier src_tuple_var_name;
    size_t mut_field_count = 0;
    for (size_t i = 0; i < src_sig.field_count(); ++i) {
        auto const& src_field = src_sig.field(i);
        auto const& dst_field = self_md.dst_sig->field(i);

        if (!dst_field.is_const()) {
            ++mut_field_count;
        }

        if (src_field.entity_id() == dst_field.entity_id() && src_field.is_const() == dst_field.is_const() && src_field.is_const()) {
            continue; // No cast needed, boath are const and same type
        }

        call_builder cast_call{ md.call_location };
        if (src_field.is_const()) {
            cast_call.emplace_back(md.call_location, src_field.entity_id());
        } else {
            if (!src_tuple_var_name) {
                src_tuple_var_name = e.new_identifier();
                local_variable src_tuple_var = fn_scope.new_temporary(src_tuple_var_name, self_md.src_entity_type->id);
                src_er.temporaries.emplace_back(src_tuple_var_name, std::move(src_tuple_var), src_er.expressions);
            }

            call_builder get_call{ md.call_location };
            get_call.emplace_back(e.get(builtin_id::self), md.call_location, name_reference_expression{ src_tuple_var_name });
            get_call.emplace_back(e.get(builtin_id::property), md.call_location, numetron::integer_view{ i });
            auto match = ctx.find(builtin_qnid::get, get_call, el);
            if (!match) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(md.call_location, "internal error: can't get tuple element"sv, syntax_expression{ .value = numetron::integer_view{ i } }),
                    std::move(match.error())));
            }
            auto res = match->apply(ctx);
            if (!res) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(md.call_location, "internal error: can't get tuple element"sv, syntax_expression{ .value = numetron::integer_view{ i } }),
                    std::move(res.error())));
            }

            if (src_field.entity_id() == dst_field.entity_id() && !dst_field.is_const() && !res->is_const_result) {
                fn_code = el.concat(fn_code, res->expressions);
                continue; // No cast needed
            }
            cast_call.emplace_back(make_indirect_value(e, el, std::move(*res), md.call_location));
        }
        entity_identifier dest_field_type = dst_field.is_const() ? get_entity(e, dst_field.entity_id()).id : dst_field.entity_id();
        auto match = ctx.find(builtin_qnid::implicit_cast, cast_call, el, expected_result_t{ .type = dest_field_type, .modifier  = dst_field.is_const() ? value_modifier_t::constexpr_value : value_modifier_t::runtime_value });
        if (!match) {
            return std::unexpected(append_cause(
                make_error<cast_error>(md.call_location, dest_field_type, src_field.entity_id()),
                std::move(match.error())));
        }
        auto fld_res = match->apply(ctx);
        if (!fld_res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(md.call_location, "internal error: can't apply implicit cast for tuple field"sv, src_field.entity_id()),
                std::move(fld_res.error())));
        }
        fn_code = el.concat(fn_code, fld_res->expressions);
    }

    if (mut_field_count > 1) {
        e.push_back_expression(el, fn_code, semantic::push_value{ smart_blob{ ui64_blob_result(mut_field_count) } });
        e.push_back_expression(el, fn_code, semantic::invoke_function(e.get(builtin_eid::arrayify)));
    }
    //if (src_tuple_var) {
    //    src_er.temporaries.emplace_back(src_tuple_var_name, std::move(*src_tuple_var), src_er.expressions);
    //}

    src_er.expressions = fn_code;
    src_er.value_or_type = self_md.signature.result->entity_id();
    src_er.is_const_result = !mut_field_count;

    return std::move(src_er);
}

} // namespace annium
