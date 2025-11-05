//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
#include <expected>

#include "annium/semantic.hpp"
#include "annium/errors.hpp"

#include "annium/environment.hpp"

namespace annium {

class base_expression_visitor : public static_visitor<std::expected<std::pair<syntax_expression_result, bool>, error_storage>>
{
    friend struct array_expression_processor;

protected:
    fn_compiler_context& ctx;
    syntax_expression const& context_expression_;
    semantic::expression_list_t& expressions;
    expected_result_t expected_result;

public:
    explicit base_expression_visitor(fn_compiler_context&, semantic::expression_list_t&, syntax_expression const&) noexcept;
    base_expression_visitor(fn_compiler_context&, semantic::expression_list_t&, expected_result_t er, syntax_expression const&) noexcept;

    static result_type visit(fn_compiler_context&, semantic::expression_list_t&, syntax_expression const&);
    static result_type visit(fn_compiler_context&, semantic::expression_list_t&, expected_result_t er, syntax_expression const&);

    result_type operator()(nil_expression const&) const;
    result_type operator()(bool) const;

    result_type operator()(numetron::integer_view const&) const;
    result_type operator()(numetron::decimal_view const&) const;
    result_type operator()(string_view) const;
    result_type operator()(identifier) const;
    result_type operator()(entity_identifier const&) const;

    result_type operator()(indirect_value const&) const;
    result_type operator()(name_reference_expression const&) const;
    result_type operator()(qname_reference_expression const&) const;
    result_type operator()(stack_value_reference_expression const&) const;

    result_type operator()(array_expression const&) const;
    result_type operator()(array_with_body_expression const&) const;

    result_type operator()(probe_expression const&) const;

    result_type operator()(bracket_expression const&) const;

    result_type operator()(member_expression const&) const;

    result_type operator()(unary_expression const& be) const;

    result_type operator()(function_call const&) const;

    result_type operator()(new_expression const&) const;

    result_type operator()(binary_expression const&) const;

    result_type operator()(index_expression const&) const;

    result_type operator()(lambda const&) const;

    template <typename FnIdT, std::derived_from<pure_call> ExprT>
    result_type operator()(FnIdT&& fnid, ExprT const& call) const;

    result_type operator()(annium_fn_type const&) const;
    result_type operator()(not_empty_expression const&) const;

    template <typename T>
    result_type operator()(T const&) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("base_expression_visitor not implemented expression");
    }
protected:
    environment& env() const noexcept;
#if 0
    result_type operator()(variant<entity_identifier, local_variable const&> const&);
#endif
    result_type do_logic_and(binary_expression const&) const;
    result_type do_logic_or(binary_expression const&) const;
    result_type do_assign(binary_expression const&) const;

    result_type apply_cast(entity const&, syntax_expression_result) const;
    result_type apply_cast(syntax_expression_result) const;

    result_type apply_cast(entity_identifier eid) const;
    result_type apply_cast(entity const& ent) const;

    result_type apply_cast(std::expected<syntax_expression_result, error_storage>) const;

};

}
