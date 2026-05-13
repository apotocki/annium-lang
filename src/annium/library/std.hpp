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

    blob_result regex_object(string_view pattern);
    blob_result regex_search(string_view target, smart_blob re);
};

}
