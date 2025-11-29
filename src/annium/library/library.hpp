//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/vm/annium_vm.hpp"

namespace annium {

void annium_error(vm::context&);
void annium_assert(vm::context&);
void annium_any_equal(vm::context&);
void annium_decimal_equal(vm::context&);
void annium_tostring(vm::context&);
void annium_print_string(vm::context&);
void annium_concat(vm::context&);
void annium_arrayify(vm::context&);
void annium_unfold(vm::context&);
void annium_array_size(vm::context&);
void annium_array_tail(vm::context&);
void annium_array_at(vm::context&);
void annium_array_set_at(vm::context&);

void annium_create_extern_object(vm::context&);
void annium_set_object_property(vm::context&);
void annium_invoke(vm::context&);

void annium_logical_not(vm::context&);
void annium_unary_minus(vm::context&);
//void annium_concat_string(vm::context&);

void annium_operator_plus_integer(vm::context&);
void annium_operator_plus_decimal(vm::context&);

void annium_operator_minus_integer(vm::context&);

void annium_str2dec(vm::context&);
void annium_int2dec(vm::context&);
void annium_int2flt(vm::context&);

}
