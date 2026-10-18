//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <cstdint>
#include <vector>

#include "sonia/string.hpp"
#include "sonia/span.hpp"

namespace annium {

using namespace sonia;

class virtual_stack_machine;

// A precompiled program image (.annc): sonia::vm's image (sonia/utility/lang/vm_image.hpp, the
// layout is described there) with the magic "ANNC". Loading an image skips parsing and semantic
// analysis entirely, the program is just run from the entry point of its main function.
//
// Any version mismatch, or an extern function the image refers to and the runtime doesn't provide,
// fails the load with an exception - there is no fallback to sources by design (a mismatch means
// the build is broken). The builtin_fn functions are bound by index, the rest by signature.

inline constexpr string_view image_file_extension = ".annc";

// Bump whenever the image layout (sonia::vm's) or the contract between annium's compiled code and
// its runtime (builtin_fn indices, calling convention, ...) changes. The VM's own encoding has its
// separate sonia::vm::bytecode_version.
inline constexpr uint32_t image_format_version = 2;

std::vector<uint8_t> save_image(virtual_stack_machine const& vm, size_t entry_address, string_view source_name);

// Replaces the code, constants and extern function table of `vm` with the image's ones, binding
// the image's extern functions to the ones `vm` already has (builtins by index, the rest by
// signature). Returns the entry address. `image_name` is used in error messages only.
size_t load_image(virtual_stack_machine& vm, span<const uint8_t> image, string_view image_name);

}
