//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class cast_error : public basic_general_error
{
    entity_identifier src_;
    entity_identifier dest_;

public:
    cast_error(resource_location loc, entity_identifier src, entity_identifier dest, string_t descr = ""sv, resource_location refloc = {})
        : basic_general_error{ std::move(loc), std::move(descr), nullptr, std::move(refloc) }
        , src_{ src }
        , dest_{ dest }
    {}

    string_t description(environment const&) const noexcept override;
};

}
