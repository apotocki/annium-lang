//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <unordered_map>

#include "annium_view_model.hpp"
//#include "builder_view_model.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace sonia {

class bunch_builder_view_model 
    : public annium_view_model
    , public invocation::registrar<bunch_builder_view_model, annium_view_model>
{
    using base_t = invocation::registrar<bunch_builder_view_model, annium_view_model>;
    using registrar_type = base_t::registrar_type;
    friend base_t;

public:
    class factory
    {
    public:
        virtual ~factory() = default;
        virtual shared_ptr<invocation::invocable> create(string_view type, string_view id) = 0;
    };

    explicit bunch_builder_view_model(factory& f) : factory_{ f } {}

    shared_ptr<invocation::invocable> create(string_view type, string_view id);
    //void set_property(string_view propname, blob_result const& value) override;
    
    virtual shared_ptr<invocation::invocable> root_element() const = 0;

    shared_ptr<invocation::invocable> get_element_by(string_view id) const;
    shared_ptr<invocation::invocable> try_get_element_by(string_view id) const noexcept;

protected:
    // methods routine
    static void do_registration(registrar_type& mr);

    std::unordered_map<std::string, shared_ptr<invocation::invocable>, hasher, string_equal_to> elements_;
    factory& factory_;
};

}
