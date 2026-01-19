//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class value_mismatch_error : public basic_general_error
{
    variant<entity_identifier, qname_identifier, std::string, string_view> expected_;

public:
    template <typename ExpectedArgT>
    value_mismatch_error(resource_location loc, entity_identifier actual, ExpectedArgT && expected, resource_location refloc = {})
        : basic_general_error{ std::move(loc), ""sv, actual, std::move(refloc) }
        , expected_{ std::forward<ExpectedArgT>(expected) }
    {
    }

    string_t description(environment const&) const noexcept override;
};

}
