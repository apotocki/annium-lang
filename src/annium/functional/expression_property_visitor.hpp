//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <boost/container/flat_set.hpp>

#include "sonia/variant.hpp"
#include "sonia/span.hpp"
#include "annium/ast_terms.hpp"

namespace annium {

class fn_compiler_context;

struct expression_analysis_result
{
    uint8_t is_pattern : 1;
    uint8_t use_parameters : 1;

    inline static expression_analysis_result this_is_pattern() noexcept
    {
        return expression_analysis_result{ 1,  1 };
    }

    inline static expression_analysis_result this_is_not_pattern() noexcept
    {
        return expression_analysis_result{ 0, 0 };
    }
};

// returns true if pattern is clarified, false otherwise (expression)
class expression_property_visitor : public static_visitor<expression_analysis_result>
{
protected:
    fn_compiler_context& ctx;
    span<const identifier> parameters; // sorted
    mutable boost::container::small_flat_set<identifier, 8> expression_variables;

public:
    inline explicit expression_property_visitor(fn_compiler_context& ctx, span<const identifier> ps) noexcept
        : ctx{ ctx }
        , parameters{ ps }
    {}

    inline result_type operator()(bool) const { return expression_analysis_result::this_is_not_pattern(); }
    inline result_type operator()(numetron::integer_view const&) const { return expression_analysis_result::this_is_not_pattern(); }
    inline result_type operator()(numetron::decimal_view const&) const { return expression_analysis_result::this_is_not_pattern(); }
    inline result_type operator()(string_view) const { return expression_analysis_result::this_is_not_pattern(); }
    inline result_type operator()(identifier) const { return expression_analysis_result::this_is_not_pattern(); }
    inline result_type operator()(entity_identifier const&) const { return expression_analysis_result::this_is_not_pattern(); }
    //inline result_type operator()(annotated_qname const&) const { return expression_analysis_result::this_is_not_pattern(); }

    result_type operator()(name_reference_expression const&) const;
    result_type operator()(qname_reference_expression const&) const;

    result_type operator()(member_expression const&) const;
    result_type operator()(unary_expression const&) const;
    result_type operator()(binary_expression const&) const;
    result_type operator()(pure_call const&) const;

    result_type operator()(function_call const&) const;

    template <typename T>
    result_type operator()(T const& v) const
    {
        (void)v;
        THROW_NOT_IMPLEMENTED_ERROR("Expression property visitor does not implemented this type of value: %1%"_fmt % typeid(T).name());
    }

};

}
