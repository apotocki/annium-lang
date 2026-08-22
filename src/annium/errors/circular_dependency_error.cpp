//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "circular_dependency_error.hpp"
#include "annium/environment.hpp"

namespace annium {

void error_printer_visitor::operator()(circular_dependency_error const& err)
{
    s_ << "circular dependency error:"sv;
    inc_indent();
    bool first = true;
    for (auto const& e : err.circle_items) {
        s_ << '\n';
        if (!first) {
            s_ << indent() << "-------------- \n"sv;
        }
        first = false;
        print(*e); // print_general() below will emit the leading indent() itself
    }
    dec_indent();
}

}
