//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "match_penalty.hpp"

namespace annium {

bool operator==(match_penalty const& lhs, match_penalty const& rhs) noexcept
{
    return lhs.placeholders == rhs.placeholders
        && lhs.casts == rhs.casts
        && lhs.variadics == rhs.variadics
        && lhs.cast_allowances == rhs.cast_allowances;
}

std::strong_ordering operator<=>(match_penalty const& lhs, match_penalty const& rhs) noexcept
{
    if (auto cmp = lhs.casts <=> rhs.casts; cmp != 0) {
        return cmp;
    }

    for (size_t len = std::min(lhs.placeholders.size(), rhs.placeholders.size()), i = 0; i < len; ++i) {
        if (auto cmp = lhs.placeholders[i] <=> rhs.placeholders[i]; cmp != 0) {
            return cmp;
        }
    }
    if (auto cmp = lhs.placeholders.size() <=> rhs.placeholders.size(); cmp != 0) {
        return cmp;
    }

    if (auto cmp = lhs.variadics <=> rhs.variadics; cmp != 0) {
        return cmp;
    }
    return lhs.cast_allowances <=> rhs.cast_allowances;
}

match_penalty& match_penalty::operator+=(match_penalty const& other) noexcept
{
    size_t max_placeholders = std::max(placeholders.size(), other.placeholders.size());
    placeholders.resize(max_placeholders, 0);
    for (size_t i = 0; i < other.placeholders.size(); ++i) {
        placeholders[i] += other.placeholders[i];
    }
    casts += other.casts;
    variadics += other.variadics;
    cast_allowances += other.cast_allowances;
    return *this;
}

} // namespace annium
