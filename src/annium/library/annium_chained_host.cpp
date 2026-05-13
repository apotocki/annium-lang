//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "chained_host.hpp"
#include "std.hpp"

namespace annium {

void chained_host::do_registration(registrar_type& mr)
{
    mr.register_readonly_property("std", [](chained_host const& self) -> blob_result {
        return object_blob_result(self.std_);
    });
    //mr.register_method<&std_host::eftor_call>("eftor_call");
}

chained_host::chained_host()
    : std_{ make_shared<std_object>() }
{}

void chained_host::extend(parent_ref parent)
{
    parents_.push_back(std::move(parent));
}

template <typename FunctorT>
inline bool use_parent(chained_host::parent_ref const& b, FunctorT&& ftor)
{
    return visit(match(
        [&ftor](shared_ptr<invocation::invocable> const& p) { return ftor(*p); },
        [&ftor](weak_ptr<invocation::invocable> const& p) { if (auto sp = p.lock()) return ftor(*sp); else return false; },
        [&ftor](invocation::invocable* p) { return p ? ftor(*p) : false; }
    ), b);
}

bool chained_host::has_method(string_view methodname) const
{
    if (invocation::invocable::has_method(methodname)) return true;
    for (auto const& p : parents_) {
        if (use_parent(p, [methodname](auto& parent) { return parent.has_method(methodname); })) return true;
    }
    return false;
}

bool chained_host::try_invoke(string_view methodname, span<const blob_result> args, smart_blob& result) noexcept
{
    if (invocation::invocable::try_invoke(methodname, args, result)) return true;
    for (auto const& p : parents_) {
        if (use_parent(p, [&](auto& parent) { return parent.try_invoke(methodname, args, result); })) return true;
    }
    return false;
}

bool chained_host::try_get_property(string_view propname, smart_blob& result) const
{
    if (invocation::invocable::try_get_property(propname, result)) return true;
    for (auto const& p : parents_) {
        if (use_parent(p, [&](auto& parent) { return parent.try_get_property(propname, result); })) return true;
    }
    return false;
}

bool chained_host::try_set_property(string_view propname, blob_result const& val)
{
    if (invocation::invocable::try_set_property(propname, val)) return true;
    for (auto const& p : parents_) {
        if (use_parent(p, [&](auto& parent) { return parent.try_set_property(propname, val); })) return true;
    }
    return false;
}

}
