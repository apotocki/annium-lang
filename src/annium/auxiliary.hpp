//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/terms.hpp"
//#include "annium/semantic.hpp"

namespace annium {

class environment;
class entity;
struct syntax_expression_result;
struct field_descriptor;

entity const& get_entity(environment const&, entity_identifier const&);
entity_identifier get_entity_type(environment const&, field_descriptor const&);

inline entity const& get_entity(environment const& e, annotated_entity_identifier const& aeid)
{
    return get_entity(e, aeid.value);
}

entity_identifier get_result_type(environment const&, syntax_expression_result const&, entity const** ppe = nullptr);

}
