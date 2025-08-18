//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "circular_dependency_error.hpp"
#include "annium/environment.hpp"

namespace annium {

void error_printer_visitor::operator()(circular_dependency_error const& err)
{
    bool first = true;
    s_ << "circular dependency error: "sv;
    for (auto const& e : err.circle_items) {
        if (!first) {
            s_ << "\n -------------- \n";
        }
        else { first = false; }
        e->visit(*this);
    }
}

}
