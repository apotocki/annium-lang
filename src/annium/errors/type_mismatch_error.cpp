//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "type_mismatch_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t type_mismatch_error::description(environment const& e) const noexcept
{
    std::ostringstream ss;
    ss << "type mismatch error, expected: "sv;
    std::visit([&e, &ss](auto const& val) {
        if constexpr (std::is_same_v<std::decay_t<decltype(val)>, std::string> || 
            std::is_same_v<std::decay_t<decltype(val)>, string_view>) {
            ss << val;
        } else {
            ss << e.print(val);
        }
    }, expected_);
        
    return ss.str();
}

}
