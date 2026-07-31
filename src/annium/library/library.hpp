//  Annium programming language (c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/vm/annium_vm.hpp"

namespace annium {

void annium_error(vm::context&);
void annium_assert(vm::context&);
void annium_get_frame_stack_height(vm::context&);

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

void annium_string_empty(vm::context&);
void annium_string_size(vm::context&);

void annium_create_callable(vm::context&);
void annium_create_extern_object(vm::context&);
void annium_set_object_property(vm::context&);
void annium_get_object_property(vm::context&);
void annium_invoke(vm::context&);
void annium_invoke_void(vm::context&);
void annium_invoke_object(vm::context&);
void annium_invoke_callable(vm::context&);

void annium_logical_not(vm::context&);
void annium_unary_minus(vm::context&);
//void annium_concat_string(vm::context&);

void annium_operator_plus_numeric(vm::context&);

void annium_operator_minus_integer(vm::context&);
void annium_operator_minus_numeric(vm::context&);
void annium_operator_mul_numeric(vm::context&);
void annium_operator_div_numeric(vm::context&);

void annium_to_integer(vm::context&);
void annium_str2dec(vm::context&);
void annium_int2dec(vm::context&);
void annium_int2flt(vm::context&);

void annium_numeric_to_i8(vm::context&);
void annium_numeric_to_ui8(vm::context&);
void annium_numeric_to_i16(vm::context&);
void annium_numeric_to_ui16(vm::context&);
void annium_numeric_to_i32(vm::context&);
void annium_numeric_to_ui32(vm::context&);
void annium_numeric_to_i64(vm::context&);
void annium_numeric_to_ui64(vm::context&);

void annium_numeric_to_f16(vm::context&);
void annium_numeric_to_f32(vm::context&);
void annium_numeric_to_f64(vm::context&);
void annium_numeric_to_decimal(vm::context&);

}
