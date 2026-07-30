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
    // Count of parameters matched via a path that is *capable* of falling back to implicit_cast
    // (currently: plain type-expression constraints, `constraint_matcher::operator()(syntax_expression const*)`),
    // regardless of whether a cast actually happened for any of them -- NOT a tally of casts used or allowed.
    // Lowest-priority tie-break: a candidate whose parameters were all matched via more specific means
    // (e.g. structural @concept/pattern constraints, which never set this) is preferred at equal `casts`.
    unsigned int cast_capable_matches{ 0 };

    friend bool operator==(match_penalty const& lhs, match_penalty const& rhs) noexcept;
    friend std::strong_ordering operator<=>(match_penalty const& lhs, match_penalty const& rhs) noexcept;

    match_penalty& operator+=(match_penalty const& other) noexcept;
};

}
