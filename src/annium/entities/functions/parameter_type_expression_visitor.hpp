//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <expected>

#include "annium/functional/functional.hpp"
#include "annium/ast/fn_compiler_context.hpp"

namespace annium {

class basic_fn_pattern;
class genetic_parameter_matcher;

class parameter_type_expression_visitor : public static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    basic_fn_pattern const& pattern;
    genetic_parameter_matcher& matcher;

public:
    explicit parameter_type_expression_visitor(fn_compiler_context& c, basic_fn_pattern const& ptrn, genetic_parameter_matcher& m) //, function_descriptor& fd)
        : ctx{ c }, pattern{ ptrn }, matcher{ m }
    {}

    result_type operator()(annotated_entity_identifier const&);
    result_type operator()(qname_reference const&);
    result_type operator()(annium_parameter_pack_t const&);
    

    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("parameter_type_expression_visitor()");
    }

private:
    inline environment& env() const noexcept { return ctx.env(); }
};

}
