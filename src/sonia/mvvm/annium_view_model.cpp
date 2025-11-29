//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium_view_model.hpp"
#include "sonia/utility/scope_exit.hpp"

namespace sonia {

void annium_view_model::do_registration(registrar_type& mr)
{
    //using load_annium_t = void(annium::language::*)(string_view, span<string_view>);
    ////mr.register_method<(load_annium_t)&annium_view_model::build>("load_annium"sv);
    //mr.register_method<(load_annium_t)&annium_view_model::build>("load_code"sv);
    //mr.register_method<(load_annium_t)&lang::annium::language::load>("load_code"sv);
    
    mr.register_method<&annium_view_model::load_code>("load_code"sv);
    mr.register_method<&annium_view_model::load_file>("load_file"sv);
    mr.register_method<&annium_view_model::eval>("eval"sv);
    //using load_annium_t = void(annium_view_model::*)(string_view);
    //using eval_annium_t = smart_blob(annium_view_model::*)(string_view);
    //mr.register_method<(eval_annium_t)&annium_view_model::eval_annium>("eval_annium"sv);
    //mr.register_method<&annium_view_model::append_inplace>("append_inplace"sv);
}

annium_view_model::annium_view_model(int32_t idval)
    : view_model{ idval }
{
    set_environment(this);
}

void annium_view_model::load_code(string_view code)
{
    load(code);
}

void annium_view_model::load_file(string_view pathstr)
{
    fs::path path{ u8string_view{reinterpret_cast<char8_t const*>(pathstr.data()), pathstr.size()} };
    load(path);
}

smart_blob annium_view_model::eval(string_view code, bool no_return)
{
    auto it = inplace_fns_.find(code, hasher{}, string_equal_to{});
    if (it == inplace_fns_.end()) {
        std::ostringstream fnnamess;
        fnnamess << "inplace_"sv << inplace_fns_.size() << "()"sv;
        std::string fnname = fnnamess.str();

        std::ostringstream fncodess;
        fncodess << "fn " << fnname << " { ";
        if (!no_return) {
            fncodess << "return " << code << "; }";
        } else {
            fncodess << code << "; }";
        }
        load((string_view)fncodess.str());
        
        it = inplace_fns_.insert(std::pair{ std::string{code}, std::move(fnname) }).first;
    }

    std::string const& fnname = it->second;
    return call(fnname);
}

}
