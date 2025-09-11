//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/terms.hpp"

namespace annium {

class environment;
class entity;

entity const& get_entity(environment const &, entity_identifier const&);

inline entity const& get_entity(environment const& e, annotated_entity_identifier const& aeid)
{
    return get_entity(e, aeid.value);
}

}
