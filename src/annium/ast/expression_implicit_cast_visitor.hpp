//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <sstream>

//#include "sonia/utility/scope_exit.hpp"

#include "../semantic.hpp"
//#include "expression_visitor.hpp"
#include "casts/expression_cast_to_bool_visitor.hpp"
#include "casts/expression_cast_to_int_visitor.hpp"
#include "casts/expression_cast_to_float_visitor.hpp"

#include "casts/expression_cast_to_array_visitor.hpp"
#include "casts/expression_cast_to_vector_visitor.hpp"
#include "casts/expression_cast_to_object_visitor.hpp"
#include "casts/expression_cast_to_string_visitor.hpp"

#include "fn_compiler_context.hpp"

#include "annium/errors.hpp"

namespace annium {

struct expression_implicit_cast_visitor : static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    annium_type const& type2cast;
    context_locator_t cl_;
    
    expression_implicit_cast_visitor(fn_compiler_context& c, annium_type const& t, context_locator_t const& cl)
        : ctx{ c }
        , type2cast{ t }
        , cl_{ cl }
    {}

    // return std::unexpected(ctx.error_cannot_convert(var.location, ctx.env().print(var.name), varptr->type(), *expected_result));

    /*
    result_type operator()(annium_vector_t const& v) const
    {
        size_t stored_pos = result.size();
        EXCEPTIONAL_SCOPE_EXIT([this, stored_pos](){ result.resize(stored_pos); });
        expression_visitor elemvis{ ctx, result, &e.type };
        for (expression_t const& e : vec.elements) {
            if (!apply_visitor(elemvis, e)) {
                result.resize(stored_pos);
                return nullopt;
            }
        }
        result.emplace_back(semantic::push_value{ decimal{ vec.elements.size() } });
        result.emplace_back(semantic::invoke_function{ ctx.env().arrayify_entity_name(), (uint32_t)vec.elements.size() + 1 });
        return v;
    }

    result_type operator()(annium_union_t const& v) const
    {
        for (annium_generic_type const& ut : v.members) {
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
    */
#if 0
    inline result_type operator()(annium_int_t const&) const
    {
        return apply_visitor(expression_cast_to_int_visitor{ ctx, cl_ }, type2cast);
    }

    inline result_type operator()(annium_float_t const&) const
    {
        return apply_visitor(expression_cast_to_float_visitor{ ctx, cl_ }, type2cast);
    }

    inline result_type operator()(annium_object_t const& v) const
    {
        return apply_visitor(expression_cast_to_object_visitor{ ctx, v, cl_ }, type2cast);
    }

    inline result_type operator()(annium_vector_t const& v) const
    {
        return apply_visitor(expression_cast_to_vector_visitor{ ctx, v, cl_ }, type2cast);
    }

    inline result_type operator()(annium_array_t const& ar) const
    {
        return apply_visitor(expression_cast_to_array_visitor{ ctx, ar, cl_ }, type2cast);
    }

    inline result_type operator()(annium_string_t const& v) const
    {
        ctx.append_expression(ctx.env().get_builtin_function(unit::builtin_fn::tostring));
        ctx.context_type = annium_string_t{};
        return {};
        //expression_cast_to_string_visitor vis{ ctx, result };
        //return apply_visitor(vis, type2cast);
    }

    inline result_type operator()(annium_union_t const& v) const
    {
        alt_error aerr;
        for (annium_type const& t : v) {
            if (auto opterr = apply_visitor(*this, t); opterr) {
                aerr.alternatives.emplace_back(std::move(opterr));
            } else {
                return {};
            }
        }
        return make_error<alt_error>(std::move(aerr));
    }

    inline result_type operator()(annium_bool_t const&) const
    {
        return apply_visitor(expression_cast_to_bool_visitor{ ctx, cl_ }, type2cast);
    }

    inline result_type operator()(annium_any_t const&) const
    {
        ctx.context_type = type2cast;
        return {};
    }
#endif
    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

}
