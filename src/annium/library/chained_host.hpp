//  Annium programming language (c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/small_vector.hpp"
#include "sonia/shared_ptr.hpp"
#include "sonia/variant.hpp"
#include "sonia/utility/invocation/invocation.hpp"
#include "sonia/utility/invocation/invocable_registry.hpp"

namespace annium {

using namespace sonia;

class chained_host
    : public invocation::invocable
    , public invocation::registrar<chained_host, invocation::invocable>
{
    using registrar_base_t = invocation::registrar<chained_host, invocation::invocable>;
    using registrar_type = registrar_base_t::registrar_type;
    friend registrar_base_t;

    static void do_registration(registrar_type&);

public:
    chained_host();

    bool has_method(string_view methodname) const override;
    bool try_invoke(string_view methodname, span<const blob_result> args, smart_blob& result) noexcept override;
    bool try_get_property(string_view propname, smart_blob& result) const override;
    bool try_set_property(string_view propname, blob_result const& val) override;

    using parent_ref = variant<
        shared_ptr<invocation::invocable>,
        weak_ptr<invocation::invocable>,
        invocation::invocable*
    >;

    void extend(parent_ref);

protected:
    small_vector<parent_ref, 2> parents_;

    shared_ptr<invocation::invocable> std_;
};

}
