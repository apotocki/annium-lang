//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/variant.hpp"
#include "sonia/optional.hpp"
#include "sonia/utility/scope_exit.hpp"

#include "../semantic.hpp"
#include "expression_visitor.hpp"
#include "fn_compiler_context.hpp"

namespace annium {

struct expression_vector_visitor_obs : static_visitor<optional<annium_type>>
{
    fn_compiler_context& ctx;
    expression_vector_t & vec;
    resource_location const& loc_;

    expression_vector_visitor_obs(fn_compiler_context& c, expression_vector_t & v, resource_location const& loc)
        : ctx{ c }
        , vec{ v }
        , loc_{ loc }
    {}
#if 0
    result_type operator()(annium_vector_t const& v) const
    {
        auto estate = ctx.expressions_state();
        expression_visitor elemvis{ ctx, expected_result_t{ v.type, loc_ } };
        for (expression_t & e : vec.elements) {
            if (!apply_visitor(elemvis, e)) {
                return nullopt;
            }
        }
        ctx.append_expression(semantic::push_value{ mp::integer{ vec.elements.size() } });
        ctx.append_expression(ctx.env().get_builtin_function(unit::builtin_fn::arrayify));
        estate.detach();
        return v;
    }

    result_type operator()(annium_array_t const& ar) const
    {
        if (ar.size != vec.elements.size() || !this->operator()(annium_vector_t{ ar.type })) return nullopt;
        return ar;
    }

    result_type operator()(annium_union_t const& v) const
    {
        for (annium_type const& ut : v) {
            if (auto optrest = apply_visitor(*this, ut); optrest) {
                return *optrest;
            }
        }
        return nullopt;
    }

    inline result_type operator()(annium_bool_t const& v) const { return nullopt; }
    inline result_type operator()(annium_int_t const& v) const { return nullopt; }
    inline result_type operator()(annium_float_t const& v) const { return nullopt; }
    inline result_type operator()(annium_decimal_t const& v) const { return nullopt; }
    inline result_type operator()(annium_string_t const& v) const { return nullopt; }
    inline result_type operator()(annium_object_t const& v) const { return nullopt; }
#endif
    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

}
