 //  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <unordered_map>

#include "sonia/utility/mvvm/view_model.hpp"
#include "sonia/utility/invocation/invocable_registry.hpp"
#include "annium/annium.hpp"

namespace sonia {

// it's abstract class, still virtual: get_manager, set(manager), self_as_content_view_shared
class annium_view_model
    : public virtual view_model
    , public annium::language
    , public invocation::registrar<annium_view_model, view_model>
{
    using registrar_type = invocation::registrar<annium_view_model, view_model>::registrar_type;
    friend class invocation::registrar<annium_view_model, view_model>;

public:
    explicit annium_view_model(int32_t idval = 0);

    // scripting
    void load_code(string_view code);
    void load_file(string_view path);
    smart_blob eval(string_view code, bool no_return);

    void set_invoker(smart_blob);

    bool try_invoke(string_view methodname, span<const blob_result> args, smart_blob& result) noexcept override;
    bool try_get_property(string_view propname, smart_blob& result) const override;
    bool try_set_property(string_view propname, blob_result const& val) override;

protected:
    // methods routine
    static void do_registration(registrar_type& mr);

private:
    std::unordered_map<std::string, std::string, hasher, string_equal_to> inplace_fns_;
    shared_ptr<invocable> invoker_ftor_;
};

}
