//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "no_position_argument_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t no_position_argument_error::object(environment const& e) const noexcept
{
    return ""sv;
}

general_error::string_t no_position_argument_error::description(environment const& e) const noexcept
{
    return ("no argument at position: %1%"_fmt % arg_index_).str() ;
}

}
