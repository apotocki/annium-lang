//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <compare>

#include "sonia/small_vector.hpp"

namespace annium {

class match_penalty
{
public:
    sonia::small_vector<unsigned int, 4> placeholders;
    unsigned int casts{ 0 };
    unsigned int variadics{ 0 };
    unsigned int cast_allowances{ 0 };

    friend bool operator==(match_penalty const& lhs, match_penalty const& rhs) noexcept;
    friend std::strong_ordering operator<=>(match_penalty const& lhs, match_penalty const& rhs) noexcept;

    match_penalty& operator+=(match_penalty const& other) noexcept;
};

}
