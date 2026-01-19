//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class signature_name_mismatch_error : public basic_general_error
{
    qname_identifier actual_;
    //qname_identifier expected_;
    qname_view expected_;

public:
    signature_name_mismatch_error(resource_location loc, qname_identifier actual, qname_view expected, resource_location refloc = {})
        : basic_general_error{ std::move(loc), ""sv, nullptr, std::move(refloc) }
        , actual_{ actual }
        , expected_{ std::move(expected) }
    {}

    string_t description(environment const&) const noexcept override;
};

}
