//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/entities/functional.hpp"

namespace annium {

class no_position_argument_error : public general_error
{
    location_t location_;
    size_t arg_index_;

public:
    no_position_argument_error(location_t loc, size_t arg_index_val)
        : location_{ std::move(loc) }
        , arg_index_{ arg_index_val }
    {}

    void visit(error_visitor& vis) const override { vis(*this); }
    location_t location() const noexcept override { return location_; }
    string_t object(environment const&) const noexcept override;
    string_t description(environment const&) const noexcept override;
};

}
