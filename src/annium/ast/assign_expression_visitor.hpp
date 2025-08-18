//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
//#include <expected>

//#include "sonia/optional.hpp"
#include "sonia/variant.hpp"

#include "annium/semantic.hpp"
//#include "annium/environment.hpp"

#include "annium/errors/assign_error.hpp"

namespace annium {

class variable_entity;

struct assign_expression_visitor : static_visitor<std::expected<syntax_expression_result_t, error_storage>>
{
    fn_compiler_context& ctx_;
    semantic::expression_list_t& expressions;
    resource_location assign_location_;
    syntax_expression_t const& rhs_;

    inline assign_expression_visitor(fn_compiler_context& c, semantic::expression_list_t& ael, resource_location const& l, syntax_expression_t const& rhs) noexcept
        : ctx_{ c }
        , expressions{ ael }
        , assign_location_{ l }
        , rhs_{ rhs }
    {}

    template <typename T>
    result_type operator()(T const& v) const
    {
        return std::unexpected(make_error<assign_error>(assign_location_, syntax_expression_t{ v }));
        //THROW_NOT_IMPLEMENTED_ERROR("assign_expression_visitor not implemented expression");
    }

    result_type operator()(variable_reference const&) const;

    result_type operator()(member_expression_t const&) const;
    
#if 0
    result_type operator()(annotated_qname const&) const;

    

    result_type operator()(context_value const&) const;
    result_type operator()(case_expression const&) const;
    result_type operator()(not_empty_expression_t const&) const;
    
    result_type operator()(property_expression const&) const; |

    result_type operator()(annium_parameter_pack_t const&) const;

    result_type operator()(annotated_bool const&) const;
    result_type operator()(annotated_integer const&) const;
    result_type operator()(annotated_decimal const&) const;
    result_type operator()(annotated_string const&) const;
    
    result_type operator()(expression_vector_t const&) const;
    result_type operator()(chained_expression_t&) const;

    result_type operator()(lambda_t const&) const;
    result_type operator()(function_call_t const&) const;
    result_type operator()(annotated_entity_identifier const&) const;

    result_type operator()(unary_expression_t const&) const;
    result_type operator()(binary_expression_t const&) const;

    result_type operator()(binary_operator_t<binary_operator_type::ASSIGN>, binary_expression_t const&) const;
    result_type operator()(binary_operator_t<binary_operator_type::PLUS>, binary_expression_t const&) const;
    result_type operator()(binary_operator_t<binary_operator_type::LOGIC_AND>, binary_expression_t const&) const;
    result_type operator()(binary_operator_t<binary_operator_type::LOGIC_OR>, binary_expression_t const&) const;
    result_type operator()(binary_operator_t<binary_operator_type::CONCAT>, binary_expression_t const&) const;
   
    result_type operator()(binary_operator_t<binary_operator_type::EQ>, binary_expression_t const&) const;
    result_type operator()(binary_operator_t<binary_operator_type::NE>, binary_expression_t const&) const;

    result_type operator()(opt_named_syntax_expression_list_t const&) const;

    std::expected<entity const*, error_storage> handle_property_set(annotated_identifier id) const;
#endif
private:
    inline environment& env() const noexcept;
};

}
