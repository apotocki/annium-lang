//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <boost/unordered_map.hpp>

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

protected:
    // methods routine
    static void do_registration(registrar_type& mr);

private:
    boost::unordered_map<std::string, std::string, hasher, string_equal_to> inplace_fns_;
};

}
