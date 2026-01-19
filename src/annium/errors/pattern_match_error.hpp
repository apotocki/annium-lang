//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class pattern_match_error : public general_error
{
    functional::pattern const& pattern_;

public:
    pattern_match_error(functional::pattern const& pattern, error_storage reason)
        : pattern_{ pattern }
    {
        set_cause(reason);
    }

    void visit(error_visitor& vis) const override { vis(*this); }
    location_t location() const noexcept override { return pattern_.location; }
    string_t object(environment const&) const noexcept override;
    string_t description(environment const&) const noexcept override;
};

}
