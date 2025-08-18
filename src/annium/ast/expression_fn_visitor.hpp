//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/variant.hpp"
#include "fn_compiler_context.hpp"

#include "../semantic.hpp"
#include "../entities/functional_entity.hpp"
#include "annium/errors.hpp"

namespace annium {

struct expression_fn_visitor : static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    functional_entity const& fn;
    context_locator_t cl_;

    expression_fn_visitor(fn_compiler_context& c, functional_entity const& f, context_locator_t const& cl)
        : ctx{ c }
        , fn{ f }
        , cl_{ cl }
    {}

    //inline result_type operator()(annium_bool_t const& v) const
    //{
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}

    //inline result_type operator()(annium_string_t const& v) const
    //{
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}

    //inline result_type operator()(annium_decimal_t const& v) const
    //{
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}

    //inline result_type operator()(annium_int_t const& v) const
    //{
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}

    //inline result_type operator()(annium_float_t const& v) const
    //{
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}

    //inline result_type operator()(annium_object_t const& v) const
    //{
    //    // to do: from_fn?
    //    return std::unexpected(ctx.error_cannot_convert(el_, v));
    //}
    
    result_type operator()(annium_union_t const& v) const
    {
        alt_error aerr;
        for (annium_type const& ut : v) {
            if (auto opterr = apply_visitor(*this, ut); opterr) {
                aerr.alternatives.emplace_back(std::move(opterr));
            } else {
                return {};
            }
        }
        return make_error<alt_error>(std::move(aerr));
    }

    inline result_type operator()(annium_fn_t const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("expression_fn_visitor annium_fn_t");
#if 0
        span<const annium_type> position_params = v.arg.fields;
        span<const std::tuple<annotated_identifier, annium_type>> named_params = v.arg.named_fields;
        
        function_signature const* fs = fn.find(ctx, position_params, named_params);
        if (!fs || fs->fn_type.result != v.result) {
            return make_error<cast_error>(cl_(), v, nullopt);
        }
        qname_identifier fnm = ctx.env().qnregistry().concat(fn.name(), fs->mangled_id);
        variable_entity const* pv = ctx.resolve_variable(fnm);
        if (pv) {
            ctx.append_expression(semantic::push_variable{ pv });
        } else {
            // delayed binding
            //small_string fnmangled = ctx.env().as_string(fnm);
            //ctx.append_expression(semantic::push_value{ fnmangled });
            //ctx.append_expression(ctx.env().get_builtin_function(unit::builtin_fn::extern_function_call));
            THROW_INTERNAL_ERROR("function '%1%' is not materialized"_fmt % ctx.env().print(fnm));
            //result.emplace_back(semantic::push_value{ function_value { std::move(fnm) } });
        }
        ctx.context_type = v;
        return {};
#endif
    }

    ///*
    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR();
        //return make_error<cast_error>(cl_(), v);
    }
    //*/
};

}
