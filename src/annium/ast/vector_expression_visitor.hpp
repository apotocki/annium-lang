//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/semantic.hpp"

#include "fn_compiler_context.hpp"

namespace annium {

struct vector_expression_visitor : static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    expression_vector_t& vec;
    resource_location const& type_decl_location;

    vector_expression_visitor(fn_compiler_context& c, expression_vector_t& v, resource_location const& loc)
        : ctx{c}, vec{v}, type_decl_location{ loc }
    {}
#if 0
    result_type operator()(annium_vector_t const& v) const
    {
        expression_visitor elemvis{ ctx, expected_result_t{v.type, type_decl_location} };
        for (expression_t& e : vec.elements) {
            if (auto opterr = apply_visitor(elemvis, e); opterr) return std::move(opterr);
        }
        ctx.append_expression(semantic::push_value{ mp::integer{ vec.elements.size() } });
        ctx.append_expression(ctx.env().get_builtin_function(unit::builtin_fn::arrayify));
        ctx.context_type = v;
        return {};
    }

    result_type operator()(annium_array_t const& v) const
    {
        if (v.size != vec.elements.size()) {
            return make_error<cast_error>(type_decl_location, v, nullopt, vec);
        }
        expression_visitor elemvis{ ctx, expected_result_t{v.type, type_decl_location} };
        for (expression_t& e : vec.elements) {
            if (auto opterr = apply_visitor(elemvis, e); opterr) return std::move(opterr);
        }
        ctx.append_expression(semantic::push_value{ mp::integer{ vec.elements.size() } });
        ctx.append_expression(ctx.env().get_builtin_function(unit::builtin_fn::arrayify));
        ctx.context_type = v;
        return {};
    }

    result_type operator()(annium_union_t const& v) const
    {
        alt_error aerr;
        for (annium_type const& t : v) {
            if (auto opt = apply_visitor(*this, t); opt) {
                aerr.alternatives.emplace_back(std::move(opt));
            } else {
                return {};
            }
        }
        return make_error<alt_error>(std::move(aerr));
    }

    inline result_type operator()(annium_float_t const& v) const
    {
        return make_error<cast_error>(type_decl_location, v, nullopt, vec);
    }
#endif
    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

}