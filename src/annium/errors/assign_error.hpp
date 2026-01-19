//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class assign_error : public general_error
{
    location_t location_;
    syntax_expression lhs_;

public:
    assign_error(location_t loc, syntax_expression const& expr)
        : location_{ std::move(loc) }
        , lhs_{ expr }
    {}

    void visit(error_visitor& vis) const override { vis(*this); }
    location_t location() const noexcept override { return location_; }
    string_t object(environment const&) const noexcept override;
    string_t description(environment const&) const noexcept override;
};

}
