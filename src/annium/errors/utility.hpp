//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/environment.hpp"

namespace annium {

struct printer_resolver_visitor : static_visitor<std::string>
{
    environment const& e_;
    explicit printer_resolver_visitor(environment const& e) : e_{ e } {}

    inline result_type operator()(nullptr_t const&) const { return {}; }
    //inline result_type operator()(null_t const&) const { return {}; }

    template <typename T>
    inline result_type operator()(T const& val) const
    {
        return e_.print(val);
    }
};

struct string_resolver_visitor : static_visitor<string_view>
{
    string_resolver_visitor() = default;

    inline result_type operator()(std::string const& str) const { return str; }
    inline result_type operator()(string_view str) const { return str; }
};

}
