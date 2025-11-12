//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "pattern_match_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t pattern_match_error::object(environment const& e) const noexcept
{
    std::ostringstream ss;
    pattern_.print(e, ss);
    return ss.str();
}

general_error::string_t pattern_match_error::description(environment const&) const noexcept
{
    return "can't match the call"sv;
}

}
