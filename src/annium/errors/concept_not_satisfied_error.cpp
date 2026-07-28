//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "concept_not_satisfied_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t concept_not_satisfied_error::description(environment const& e) const noexcept
{
    std::ostringstream ss;
    ss << "type '"sv;
    e.print_to(ss, actual_);
    ss << "' does not satisfy concept '@"sv;
    e.print_to(ss, concept_);
    ss << "'"sv;
    return ss.str();
}

}
