//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "identifier_redefinition_error.hpp"
#include "utility.hpp"

namespace annium {

general_error::string_t identifier_redefinition_error::object(environment const& e) const noexcept
{
    return apply_visitor(printer_resolver_visitor{ e }, name_);
}

}
