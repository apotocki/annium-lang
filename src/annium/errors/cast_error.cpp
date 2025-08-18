//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "cast_error.hpp"
#include "utility.hpp"

#include "annium/environment.hpp"

namespace annium {

general_error::string_t cast_error::description(environment const& e) const noexcept
{
    std::ostringstream ss;
    ss << "error: cannot cast '"sv;
    e.print_to(ss, src_);
    ss << "' to '"sv;
    e.print_to(ss, dest_);
    ss << "'"sv;
    if (string_view d = apply_visitor(string_resolver_visitor{}, description_); !d.empty()) {
        ss << " "sv << d;
    }
    return ss.str();
}

}
