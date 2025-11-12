//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "assign_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t assign_error::object(environment const& env) const noexcept
{
    return env.print(lhs_);
}

general_error::string_t assign_error::description(environment const&) const noexcept
{
    return "not a lvalue expression"sv;
}

}
