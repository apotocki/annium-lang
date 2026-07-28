//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class concept_not_satisfied_error : public basic_general_error
{
    entity_identifier actual_;
    qname_identifier concept_;

public:
    concept_not_satisfied_error(resource_location loc, entity_identifier actual, qname_identifier concept_name, resource_location refloc = {})
        : basic_general_error{ std::move(loc), ""sv, actual, std::move(refloc) }
        , actual_{ actual }
        , concept_{ concept_name }
    {}

    string_t description(environment const&) const noexcept override;
};

}
