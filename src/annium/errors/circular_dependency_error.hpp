//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/entities/functional.hpp"

namespace annium {

class circular_dependency_error : public error
{
public:
    std::vector<error_storage> circle_items;
    void visit(error_visitor& vis) const override { vis(*this); }

    explicit circular_dependency_error(std::vector<error_storage> errs)
        : circle_items{ std::move(errs) }
    {}

    explicit circular_dependency_error(error_storage err)
        : circle_items{ std::move(err) }
    {}
};

}
