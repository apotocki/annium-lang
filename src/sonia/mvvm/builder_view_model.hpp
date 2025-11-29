//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium_view_model.hpp"

namespace sonia {
 
class builder_view_model
    : public annium_view_model
    , public invocation::registrar<builder_view_model, annium_view_model>
{
    using registrar_base_t = invocation::registrar<builder_view_model, annium_view_model>;
    using registrar_type = registrar_base_t::registrar_type;
    friend registrar_base_t;

public:
    class factory
    {
    public:
        virtual ~factory() = default;
        virtual shared_ptr<invocation::invocable> create(string_view type) = 0;
    };

    inline explicit builder_view_model(factory& f) noexcept : factory_{ f } {}

    shared_ptr<invocation::invocable> create(string_view type);

protected:
    // methods routine
    static void do_registration(registrar_type& mr);

    factory& factory_;
};

}
