//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium_view_model.hpp"
#include "sonia/utility/scope_exit.hpp"
#include "sonia/exceptions.hpp"

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
    mr.register_method<&annium_view_model::set_invoker>("setInvoker"sv);
    //using load_annium_t = void(annium_view_model::*)(string_view);
    //using eval_annium_t = smart_blob(annium_view_model::*)(string_view);
    //mr.register_method<(eval_annium_t)&annium_view_model::eval_annium>("eval_annium"sv);
    //mr.register_method<&annium_view_model::append_inplace>("append_inplace"sv);
}

annium_view_model::annium_view_model(int32_t idval)
    : view_model{ idval }
{
    set_host(this);
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

// The code in the scope of what is loaded, compiled once as a function of no arguments (the result is `any`): the script
// hands the function over by assigning it to the extern __eval_fn (as it hands its callbacks to a host), it is called as
// a callable. (It
// used to be called by its name through language::call, which isn't implemented.)
smart_blob annium_view_model::eval(string_view code, bool no_return)
{
    std::string key = std::string{ no_return ? "s:"sv : "e:"sv } + std::string{ code };
    auto it = inplace_fns_.find(key);
    if (it == inplace_fns_.end()) {
        if (!eval_declared_) {
            load("extern var __eval_fn: callable;"sv);
            eval_declared_ = true;
        }
        // a named function cast to its function type converts to callable (as a script's `on_change = handler as
        // (integer, string)->();`); a lambda in a `let` of the function type came as a callable of no code
        std::string fname = "__eval_fn_" + std::to_string(eval_count_++);
        std::ostringstream fncodess;
        if (!no_return) {
            fncodess << "fn " << fname << "()->any => " << code << ";";
            fncodess << " __eval_fn = " << fname << " as ()->any;";
        } else {
            fncodess << "fn " << fname << "()->() { " << code << "; }";
            fncodess << " __eval_fn = " << fname << " as ()->();";
        }
        eval_fn_.reset();
        load((string_view)fncodess.str());
        if (!eval_fn_) {
            throw exception("eval: the code didn't make a function: %1%"_fmt % code);
        }
        it = inplace_fns_.insert(std::pair{ std::move(key), std::move(eval_fn_) }).first;
    }
    return it->second->invoke({});
}

void annium_view_model::set_invoker(smart_blob invoker)
{
    using wrapper_object_t = invocation::wrapper_object<shared_ptr<invocable>>;
    invoker_ftor_ = invoker.as<wrapper_object_t>().value;
}

bool annium_view_model::try_invoke(string_view methodname, span<const blob_result> args, smart_blob& result) noexcept
{
    if (view_model::try_invoke(methodname, args, result)) return true;
    if (!invoker_ftor_) return false;
    return invoker_ftor_->try_invoke(methodname, args, result);
}

bool annium_view_model::try_get_property(string_view propname, smart_blob& result) const
{
    if (view_model::try_get_property(propname, result)) return true;
    if (!invoker_ftor_) return false;
    return invoker_ftor_->try_get_property(propname, result);
}

bool annium_view_model::try_set_property(string_view propname, blob_result const& val)
{
    if (propname == "__eval_fn"sv) { // eval's function, see eval
        using namespace sonia::invocation;
        using wrapper_object_t = wrapper_object<shared_ptr<callable>>;
        eval_fn_ = as<wrapper_object_t>(val).value;
        return true;
    }
    if (view_model::try_set_property(propname, val)) return true;
    if (!invoker_ftor_) return false;
    return invoker_ftor_->try_set_property(propname, val);
}

}
