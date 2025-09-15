//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "builder_view_model.hpp"

namespace sonia {

void builder_view_model::do_registration(registrar_type& mr)
{
    mr.register_method<&builder_view_model::create>("create"sv);
}

shared_ptr<invocation::invocable> builder_view_model::create(string_view type)
{
    return factory_.create(type);
}

}
