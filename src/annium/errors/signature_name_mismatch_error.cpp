//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "signature_name_mismatch_error.hpp"
#include "utility.hpp"

#include "annium/environment.hpp"

namespace annium {

general_error::string_t signature_name_mismatch_error::description(environment const& e) const noexcept
{
    std::ostringstream ss;
    ss << "error: signature name mismatch: expected '"sv;
    e.print_to(ss, expected_);
    ss << "', but got '"sv;
    e.print_to(ss, actual_);
    ss << "'"sv;
    if (string_view d = apply_visitor(string_resolver_visitor{}, description_); !d.empty()) {
        ss << " "sv << d;
    }
    return ss.str();
}

}
