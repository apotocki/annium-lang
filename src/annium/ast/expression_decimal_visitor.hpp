//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/variant.hpp"
#include "sonia/optional.hpp"
#include "../semantic.hpp"
#include "fn_compiler_context.hpp"

namespace annium {

struct expression_decimal_visitor : static_visitor<optional<annium_type>>
{
    fn_compiler_context& ctx;
    decimal const& dec;
    std::vector<semantic::expression_type>& result;

    expression_decimal_visitor(fn_compiler_context& c, decimal const& d, std::vector<semantic::expression_type>& r)
        : ctx{ c }
        , dec{ d }
        , result{ r }
    {}

    inline result_type operator()(annium_decimal_t const&) const
    {
        result.emplace_back(semantic::push_value{ dec });
        return annium_decimal_t{};
    }

    inline result_type operator()(annium_int_t const&) const
    {
        result.emplace_back(semantic::push_value{ dec });
        return annium_int_t{};
    }

    inline result_type operator()(annium_float_t const&) const
    {
        result.emplace_back(semantic::push_value{ dec });
        return annium_float_t{};
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
    inline result_type operator()(annium_string_t const& v) const { return nullopt; }
    inline result_type operator()(annium_preliminary_object_t const& v) const { return nullopt; } // to do: from_decimal?
    /*
    inline result_type operator()(annium_preliminary_array_t const& v) const { return nullopt; }
    inline result_type operator()(annium_preliminary_vector_t const& v) const { return nullopt; }
    inline result_type operator()(annium_preliminary_tuple_t const& v) const { return nullopt; }
    inline result_type operator()(annium_preliminary_fn_t const& v) const { return nullopt; }
    */
    ///*
    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }
    //*/
};

}

