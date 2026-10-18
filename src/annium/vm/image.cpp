//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "image.hpp"

#include "sonia/utility/lang/vm_image.hpp"

#include "annium_vm.hpp"

namespace annium {

namespace {

constexpr sonia::vm::image_traits annium_image_traits{
    .magic = { 'A', 'N', 'N', 'C' },
    .format_version = image_format_version,
    .language = string_view{ "annium" },
    .indexed_efn_count = (size_t)virtual_stack_machine::builtin_fn::eof_type
};

}

std::vector<uint8_t> save_image(virtual_stack_machine const& vm, size_t entry_address, string_view source_name, bool with_descriptions)
{
    return sonia::vm::save_image(vm, annium_image_traits, entry_address, source_name, with_descriptions);
}

size_t load_image(virtual_stack_machine& vm, span<const uint8_t> image, string_view image_name)
{
    return sonia::vm::load_image(vm, annium_image_traits, image, image_name);
}

}
