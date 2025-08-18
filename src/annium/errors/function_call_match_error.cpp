//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "function_call_match_error.hpp"
#include "annium/environment.hpp"

namespace annium {

general_error::string_t function_call_match_error::object(environment const& e) const noexcept
{
    return e.print(functional_.value);
}

general_error::string_t function_call_match_error::description(environment const& e) const noexcept
{
    std::ostringstream ss;
    //if (signature_) {
    //    ss << "can't match the function signature: "sv;
    //    ss << e.print(signature_->fn_type);
    //} else {
    ss << "can't match the function call";
    //}
    if (reason_) {
        ss << ", caused by: \n" << e.print(*reason_);
    }
    return ss.str();
}

}
