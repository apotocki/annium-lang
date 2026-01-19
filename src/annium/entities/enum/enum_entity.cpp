//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"

#include "enum_entity.hpp"

#include "annium/environment.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

enum_entity::enum_entity(environment& e, functional& fn, span<const identifier> cases)
    : name_{ fn.name() }
    , cases_{ cases.begin(), cases.end() }
{
    sig_.name = fn.id();
    sig_.result.emplace(e.get(builtin_eid::typename_));
}

optional<size_t> enum_entity::find(identifier val) const
{
    auto it = std::find(cases_.begin(), cases_.end(), val);
    if (it != cases_.end()) {
        return std::distance(cases_.begin(), it);
    }
    return nullopt;
}
//enum_entity::enum_case const* enum_entity::find(identifier id)
//{
//    auto it = std::ranges::lower_bound(cases, id, {}, [](auto const& e) { return e.name; });
//    return it == cases.end() ? nullptr : &*it;
//}

}
