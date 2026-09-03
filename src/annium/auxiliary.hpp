//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/terms.hpp"
#include "annium/semantic.hpp"

namespace annium {

class environment;
class entity;
struct syntax_expression_result;
struct field_descriptor;

entity const& get_entity(environment const&, entity_identifier);
entity_identifier get_entity_type(environment const&, field_descriptor const&);

inline entity const& get_entity(environment const& e, annotated_entity_identifier const& aeid)
{
    return get_entity(e, aeid.value);
}

entity_identifier get_result_type(environment const&, syntax_expression_result const&, entity const** ppe = nullptr);

bool all_paths_return(semantic::expression_span span);

// Per-element entity ids of a compile-time-known array value (`array_value_eid`), regardless of
// how it's actually represented. The common case is a `data`-signature entity (array literals,
// fixed_array_make_pattern, ...), whose fields are exactly this already. A CTFE-folded array
// (evaluate_consteval / environment::make_generic_entity, see IMPLEMENTATION_NOTES.md's `consteval`
// section) has no such signature -- it's a raw blob wrapped in a generic_literal_entity, since
// evaluate_consteval deliberately doesn't decompose composite results (doing so there would change
// the folded value's own reported type, e.g. `[string]` becoming `string[N]`). This decomposes that
// case straight from the blob instead, mirroring annium_unfold's own element-reading logic
// (annium_library.cpp) but at compile time (collecting entity ids, each tagged with
// `element_type_eid`) rather than pushing to the VM stack.
small_vector<entity_identifier, 8> const_array_element_ids(environment&, entity_identifier array_value_eid, entity_identifier element_type_eid);

}
