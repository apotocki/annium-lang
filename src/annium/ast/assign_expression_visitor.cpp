//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "assign_expression_visitor.hpp"
#include "fn_compiler_context.hpp"
#include "base_expression_visitor.hpp"

namespace annium {

inline environment& assign_expression_visitor::env() const noexcept { return ctx_.env(); }

assign_expression_visitor::result_type assign_expression_visitor::operator()(qname_reference_expression const& v) const
{
    auto e = ctx_.lookup_entity(v.name);
    return visit([this, &v](auto & eid_or_var) -> result_type
    {
        entity_identifier assign_type;
        if constexpr (std::is_same_v<std::decay_t<decltype(eid_or_var)>, local_variable>) {
            assign_type = eid_or_var.type;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(eid_or_var)>, functional_variable>) {
            assign_type = eid_or_var.type;
        } else {
            static_assert(std::is_same_v<std::decay_t<decltype(eid_or_var)>, entity_identifier>);
            if (!eid_or_var) return std::unexpected(make_error<undeclared_identifier_error>(lhs_.location, v.name));
            return std::unexpected(make_error<assign_error>(assign_location_, lhs_));
            /*
            if (!eid_or_var) return std::unexpected(make_error<undeclared_identifier_error>(lhs_.location, v.name));
            if (peve = dynamic_cast<extern_variable_entity const*>(&env().eregistry_get(eid_or_var)); peve) {
                assign_type = peve->get_type();
            } else {
                return std::unexpected(make_error<assign_error>(assign_location_, lhs_));
            }
            */
        }
        auto res = base_expression_visitor::visit(
            ctx_,
            expressions,
            expected_result_t{
                .type = assign_type,
                .location = assign_location_,
                .modifier = value_modifier_t::runtime_value },
            rhs_);

        if (!res) return std::unexpected(std::move(res.error()));
        auto& ser = res->first;
        BOOST_ASSERT(!ser.is_const_result);

        if constexpr (std::is_same_v<std::decay_t<decltype(eid_or_var)>, local_variable>) {
            if (eid_or_var.is_weak) {
                THROW_NOT_IMPLEMENTED_ERROR("expression_visitor binary_operator_type::ASSIGN weak");
                //ctx.append_expression(semantic::invoke_function{ ctx.env().get_builtin_function(unit::builtin_fn::weak_create) });
            }
            env().push_back_expression(expressions, ser.expressions, semantic::set_local_variable::create(eid_or_var));
            //if (eid_or_var.is_weak) {
            //    ctx_.append_expression(semantic::truncate_values(1, 0));
            //}
        } else if constexpr (std::is_same_v<std::decay_t<decltype(eid_or_var)>, functional_variable>) {
            env().push_back_expression(expressions, ser.expressions, semantic::set_variable{ eid_or_var });
            //ctx_.append_expression(semantic::truncate_values(1, 0));
        } else {
            THROW_INTERNAL_ERROR("unhandled assign_expression_visitor qname_reference_expression case");
        }
        //ser.value_or_type = env().get(builtin_eid::void_);
        //ser.is_const_result = true;
        return std::move(ser);
    }, e);
    //    if constexpr (std::is_same_v<std::decay_t<decltype(eid_or_var)>, local_variable>) {
    //        base_expression_visitor rvis{ ctx_, annotated_entity_identifier{ eid_or_var.type, assign_location_ } };
    //        auto res = apply_visitor(rvis, rhs_);
    //        if (!res) return std::move(res.error());
    //        if (eid_or_var.is_weak) {
    //            THROW_NOT_IMPLEMENTED_ERROR("expression_visitor binary_operator_type::ASSIGN weak");
    //            //ctx.append_expression(semantic::invoke_function{ ctx.env().get_builtin_function(unit::builtin_fn::weak_create) });
    //        }
    //        ctx_.append_expression(semantic::set_local_variable{ eid_or_var.index });
    //        if (eid_or_var.is_weak) {
    //            ctx_.append_expression(semantic::truncate_values(1, false));
    //        }
    //        return error_storage{};
    //    } else { // external variable case
    //        if (!eid_or_var) return make_error<undeclared_identifier_error>(v.name);
    //        if (auto const* peve = dynamic_cast<extern_variable_entity const*>(&env().eregistry_get(eid_or_var)); peve) {
    //            expression_visitor rvis{ ctx_, annotated_entity_identifier{ peve->get_type(), assign_location_ } };
    //            auto res = apply_visitor(rvis, rhs_);
    //            if (!res) return std::move(res.error());
    //            ctx_.append_expression(semantic::set_variable{ peve });
    //            return error_storage{};
    //        }
    //        return make_error<assign_error>(assign_location_, syntax_expression{ v });
    //    }
    
}

assign_expression_visitor::result_type assign_expression_visitor::operator()(member_expression const& me) const
{
    //if (auto res = apply_visitor(expression_visitor{ ctx_ }, me.object); !res) {
    //    return std::move(res.error());
    //}

    call_builder set_call{ assign_location_ };
    set_call.emplace_back(env().get(builtin_id::self), *me.object);
    set_call.emplace_back(env().get(builtin_id::property), *me.property);
    set_call.emplace_back(rhs_);

    auto match = ctx_.find(builtin_qnid::set, set_call, expressions);
    if (!match) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(assign_location_, "can't assign"sv, lhs_),
            std::move(match.error())
        ));
    }

    return match->apply(ctx_);
    
    /*
    if (auto* uotype = ctx.context_type.as<annium_union_t>(); me.is_object_optional && uotype && uotype->has(annium_tuple_t{})) {
        ctx.append_expression(std::move(semantic::not_empty_condition_t{}));
        ctx.push_chain(get<semantic::not_empty_condition_t>(ctx.expressions().back()).branch);
        ctx.context_type = *uotype - annium_tuple_t{};
    }
    */
    //return handle_property_set(me.property);
}

#if 0
//lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_qname const&) const
//{
//    THROW_NOT_IMPLEMENTED_ERROR("lvalue_expression_visitor annotated_qname");
//}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(qname_reference const& v) const
{
    functional const* pfn = ctx.lookup_functional(v.name.value);
    if (pfn && pfn->default_entity()) {
        return &ctx.env().eregistry_get(pfn->default_entity());
    }
    return std::unexpected(make_error<undeclared_identifier_error>(v.name));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(context_value const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR("lvalue_expression_visitor context_value");
}

std::expected<entity const*, error_storage> lvalue_expression_visitor::handle_property_set(annotated_identifier id) const
{
    THROW_NOT_IMPLEMENTED_ERROR("lvalue_expression_visitor::handle_property_set");
#if 0
    if (auto const* po = sonia::get<annium_object_t>(&ctx.context_type); po) {
        if (auto const& pte = dynamic_cast<type_entity const*>(po->value); pte) {
            return pte->find_field_setter(ctx, id);
        } else {
            THROW_NOT_IMPLEMENTED_ERROR();
        }
    }
    
    return std::unexpected(make_error<left_not_an_object_error>(id.location, id.value, ctx.context_type));
#endif
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annium_parameter_pack_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(not_empty_expression_t const& ne) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
    /*
    if (auto opterr = apply_visitor(expression_visitor{ ctx, nullptr }, me.value); opterr) {
        return std::unexpected(std::move(opterr));
    }
    if (auto* uotype = ctx.context_type.as<annium_union_t>(); uotype && uotype->has(annium_tuple_t{})) {
        ctx.append_expression(std::move(semantic::not_empty_condition_t{}));
        ctx.push_chain(get<semantic::not_empty_condition_t>(ctx.expressions().back()).branch);
        ctx.context_type = *uotype - annium_tuple_t{};
    }
    return std::unexpected(make_error<basic_general_error>(get_start_location(me), "the expression type is not optional"sv, me));
    */
}



lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(property_expression const& pe) const
{
    return handle_property_set(pe.name);
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(lambda_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(case_expression const& ce) const
{
    return std::unexpected(make_error<wrong_lvalue_error>(ce));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_bool const& ab) const
{
    return std::unexpected(make_error<wrong_lvalue_error>(ab));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_integer const& ai) const
{
    return std::unexpected(make_error<wrong_lvalue_error>(ai));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_decimal const& ad) const
{
    return std::unexpected(make_error<wrong_lvalue_error>(ad));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_string const& as) const
{
    return std::unexpected(make_error<wrong_lvalue_error>(as));
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(expression_vector_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(function_call_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(unary_expression_t const& be) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_expression_t const& be) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
    //return annium_binary_switcher(be, *this);
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::ASSIGN>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::LOGIC_AND>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::LOGIC_OR>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::CONCAT>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::PLUS>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::EQ>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(binary_operator_t<binary_operator_type::NE>, binary_expression_t const&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(chained_expression_t&) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(annotated_entity_identifier const& ee) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}

lvalue_expression_visitor::result_type lvalue_expression_visitor::operator()(opt_named_syntax_expression_list_t const& el) const
{
    THROW_NOT_IMPLEMENTED_ERROR();
}
#endif

}
