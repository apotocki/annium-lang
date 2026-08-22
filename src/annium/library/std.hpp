//  Annium programming language (c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/utility/invocation/invocable_registry.hpp"

namespace annium {

using namespace sonia;

class std_object 
    : public invocation::invocable
    , public invocation::registrar<std_object, invocation::invocable>
{
    using registrar_base_t = invocation::registrar<std_object, invocation::invocable>;
    using registrar_type = registrar_base_t::registrar_type;
    friend registrar_base_t;

    static void do_registration(registrar_type&);

public:
    std_object() = default;

    // numers
    blob_result to_integer(string_view);

    // strings
    bool starts_with(string_view target, string_view prefix) const;
    string_view substring(string_view target, uint32_t start, int32_t length = -1) const;

    // regex
    blob_result regex_object(string_view pattern);
    blob_result regex_search(string_view target, smart_blob re);

    blob_result clone_value(blob_result val);
};

}
