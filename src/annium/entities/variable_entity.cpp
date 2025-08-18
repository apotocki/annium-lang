//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "variable_entity.hpp"

#include "annium/environment.hpp"

namespace annium {

std::ostream& extern_variable_entity::print_to(std::ostream& os, environment const& e) const
{
    return os << "EXTREN VAR "sv << e.print(name);
}

}
