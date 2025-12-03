//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "library.hpp"
#include "sonia/logger/logger.hpp"
#include "sonia/utility/scope_exit.hpp"
#include "numetron/basic_integer.hpp"
#include "numetron/basic_decimal.hpp"

#include <sstream>

namespace annium {

void annium_error(vm::context& ctx)
{
    std::string err = ctx.stack_back().as<std::string>();
    std::string loc = ctx.stack_back(1).as<std::string>();
    throw exception((std::ostringstream{} << loc << ": "sv << err).str());
}

void annium_assert(vm::context& ctx)
{
    if (!ctx.stack_back(1).as<bool>()) {
        std::string err = ctx.stack_back().as<std::string>();
        throw exception(err);
    }
    ctx.stack_pop(2);
}

void annium_any_equal(vm::context& ctx)
{
    bool result = ctx.stack_back() == ctx.stack_back(1);
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(result) });
}

void annium_decimal_equal(vm::context& ctx)
{
    numetron::decimal r = ctx.stack_back().as<numetron::decimal>();
    numetron::decimal l = ctx.stack_back(1).as<numetron::decimal>();
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(l == r) });
}

void annium_tostring(vm::context & ctx)
{
    std::ostringstream res;
    print_to_stream(res, *ctx.stack_back(), false);
    ctx.stack_pop(1);
    smart_blob r{ string_blob_result(res.str()) };
    r.allocate();
    ctx.stack_push(std::move(r));
}

void annium_print_string(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    environment & e = ctx.get_environment();
    std::ostringstream res;
    for (size_t i = argcount; i > 0; --i) {
        print_to_stream(res, *ctx.stack_back(i), false);
    }
    e.write_cout(res.str());
    ctx.stack_pop(argcount + 1);
}

void annium_concat(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    std::ostringstream res;
    for (size_t i = argcount; i > 0; --i) {
        print_to_stream(res, *ctx.stack_back(i), false);
    }
    ctx.stack_pop(argcount + 1);
    smart_blob r{ string_blob_result(res.str()) };
    r.allocate();
    ctx.stack_push(std::move(r));
}

void annium_arrayify(vm::context& ctx)
{
    small_vector<blob_result, 4> elements;
    size_t argcount = ctx.stack_back().as<size_t>();
    elements.reserve(argcount);

    SCOPE_EXCEPTIONAL_EXIT([&elements]() {
        for (auto& e : elements) blob_result_unpin(&e);
    });

    for (size_t i = argcount; i > 0; --i) {
        elements.emplace_back(*ctx.stack_back(i));
        blob_result_pin(&elements.back());
    }
    smart_blob r{ array_blob_result(span{ elements.data(), elements.size() }) };
    r.allocate();
    elements.clear();
    ctx.stack_pop(argcount + 1);
    ctx.stack_push(std::move(r));
}

void annium_unfold(vm::context& ctx)
{
    auto& arg = ctx.stack_back();
    if (!is_array(arg.as<blob_result>())) {
        // considering not an array as the array with one element => do nothing and return
        return;
        //throw exception("expected array, got %1%"_fmt % arg.as<blob_result>());
    }
    smart_blob arr = std::move(arg);
    // Pop the array from stack
    ctx.stack_pop(1);

    blob_type_selector(arr.as<blob_result>(), [&ctx](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_integral_v<type> || std::is_floating_point_v<type> ||
            std::is_same_v<type, numetron::float16> || std::is_same_v<type, blob_result>)
        { 
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t array_size = array_size_of<fstype>(b);
            const fstype* data = data_of<fstype>(b);
            
            // Push each element to the stack
            for (size_t i = 0; i < array_size; ++i) {
                if constexpr (std::is_same_v<fstype, blob_result>) {
                    ctx.stack_push(smart_blob{ std::move(data[i]) });
                } else {
                    ctx.stack_push(smart_blob{ particular_blob_result(data[i]) });
                }
            }
            
            // Push the array size at the end
            //ctx.stack_push(smart_blob{ ui64_blob_result(array_size) });
        } else {
            THROW_INTERNAL_ERROR("unexpected array element type");
        }
    });
}

void annium_array_size(vm::context& ctx)
{
    auto arr = ctx.stack_back(1).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    size_t sz = blob_type_selector(arr, [](auto ident, blob_result b) -> size_t {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            return array_size_of<fstype>(b);
        }
    });
    ctx.stack_back().replace(smart_blob{ ui64_blob_result(sz) });
}

void annium_array_at(vm::context& ctx)
{
    auto idx = ctx.stack_back().as<size_t>();
    auto arr = ctx.stack_back(1).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    smart_blob result;
    blob_type_selector(arr, [idx, &result](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t sz = array_size_of<fstype>(b);
            if (idx >= sz) {
                throw exception("index out of range");
            }
            fstype const& e = data_of<fstype>(b)[idx];
            blob_result res = particular_blob_result(e);
            result = res;
        }
    });

    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ result });
}

void annium_array_set_at(vm::context& ctx)
{
    auto value = ctx.stack_back().as<blob_result>();
    auto idx = ctx.stack_back(1).as<size_t>();
    auto arr = ctx.stack_back(2).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    blob_type_selector(arr, [idx, &value](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t sz = array_size_of<fstype>(b);
            if (idx >= sz) {
                throw exception("index out of range");
            }
            fstype & e = mutable_data_of<fstype>(b)[idx];
            if constexpr (std::is_same_v<fstype, blob_result>) {
                blob_result_unpin(&e);
                e = value;
                blob_result_pin(&e);
            } else {
                e = as<fstype>(value);
            }
        }
    });
    ctx.stack_pop(2);
}

void annium_array_tail(vm::context& ctx)
{
    auto arr = ctx.stack_back().as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }

    blob_type_selector(arr, [&ctx](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t>) { }
        else if constexpr (std::is_void_v<type>) { }
        else if constexpr (numetron::is_basic_integer_view_v<type>) { 
            THROW_NOT_IMPLEMENTED_ERROR("bigint tail"); }
        else if constexpr (numetron::is_basic_decimal_view_v<type>) {
            THROW_NOT_IMPLEMENTED_ERROR("decimal tail");
        } else if constexpr (std::is_same_v<type, sonia::basic_string_view<char>>) {
            THROW_NOT_IMPLEMENTED_ERROR("string tail");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t argcount = array_size_of<fstype>(b);

            if (argcount == 2) {
                smart_blob result = particular_blob_result(data_of<fstype>(b)[1]);
                blob_result_pin(&*result);
                ctx.stack_back().replace(std::move(result));
                return;
            }
            small_vector<fstype, 4> elements;
            elements.reserve(argcount - 1);

            for (size_t i = 1; i < argcount; ++i) {
                elements.push_back(data_of<fstype>(b)[i]);
                if constexpr (std::is_same_v<fstype, blob_result>) {
                    blob_result_pin(&elements.back());
                }
            }

            smart_blob r{ array_blob_result(span{elements.data(), elements.size()}) };
            r.allocate();
            elements.clear();
            ctx.stack_back().replace(std::move(r));
        }
    });
}

void annium_logical_not(vm::context& ctx)
{
    auto val = *ctx.stack_back();
    while (val.type == blob_type::blob_reference) {
        val = *data_of<blob_result>(val);
    }
    val = blob_type_selector(val, [](auto ident, blob_result const& b) {
        using type = typename decltype(ident)::type;
        if (!is_array(b)) {
            if constexpr (std::is_same_v<type, bool>) { return bool_blob_result(!b.bp.i8value); }
            else if constexpr (std::is_integral_v<type> || numetron::is_basic_integer_view_v<type>) { return bool_blob_result(!as<type>(b)); }
            else {
                throw exception("Logical not operation cannot be applied to the provided argument: %1%"_fmt % b);
            }
        } else if (contains_string(b)) {
            auto sv = as<std::string_view>(b);
            return bool_blob_result(sv.empty());
        } else {
            throw exception("Logical not operation cannot be applied to the provided argument: %1%"_fmt % b);
        }
    });
    ctx.stack_pop(1);
    ctx.stack_push(val);
}

void annium_unary_minus(vm::context& ctx)
{
    auto val = *ctx.stack_back();
    while (val.type == blob_type::blob_reference) {
        val = *data_of<blob_result>(val);
    }
    val = blob_type_selector(val, [](auto ident, blob_result const& b) -> blob_result {
        using type = typename decltype(ident)::type;
        if (!is_array(b)) {
            if constexpr (std::is_same_v<type, bool>) { return b; }
            else if constexpr (std::is_unsigned_v<type>) {
                return particular_blob_result(static_cast<type>(-as<std::make_signed_t<type>>(b))); }
            else if constexpr (std::is_signed_v<type> || numetron::is_basic_integer_view_v<type> || std::is_floating_point_v<type> || std::is_same_v<type, numetron::float16>) {
                return particular_blob_result(-as<type>(b)); }
            else if constexpr (numetron::is_basic_decimal_view_v<type>) {
                return particular_blob_result(-as<type>(b)); }
        }
        throw exception("Unary minus operation cannot be applied to the provided argument: %1%"_fmt % b);
    });
    ctx.stack_pop(1);
    ctx.stack_push(val);
}

//void annium_concat_string(vm::context& ctx)
//{
//    auto l = ctx.stack_back(1).as<string_view>();
//    auto r = ctx.stack_back().as<string_view>();
//    auto res = make_blob_result(blob_type::string, nullptr, static_cast<uint32_t>(l.size() + r.size()));
//    blob_result_allocate(&res);
//    char * buff = mutable_data_of<char>(res);
//    std::memcpy(buff, l.data(), l.size());
//    std::memcpy(buff + l.size(), r.data(), r.size());
//    ctx.stack_pop();
//    ctx.stack_back().replace( smart_blob{ std::move(res) } );
//}

void annium_operator_plus_integer(vm::context& ctx)
{
    auto l = ctx.stack_back(1).as<numetron::integer>();
    auto r = ctx.stack_back().as<numetron::integer_view>();
    auto sum = l + r;
    smart_blob res{ bigint_blob_result(sum) };
    res.allocate();

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_plus_decimal(vm::context& ctx)
{
    auto l = ctx.stack_back(1).as<numetron::decimal>();
    auto r = ctx.stack_back().as<numetron::decimal_view>();
    auto sum = l + r;
    smart_blob res{ decimal_blob_result(sum) };
    res.allocate();
    
    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_minus_integer(vm::context& ctx)
{
    auto l = ctx.stack_back(1).as<numetron::integer>();
    auto r = ctx.stack_back().as<numetron::integer_view>();
    auto sum = l - r;
    smart_blob res{ bigint_blob_result(sum) };
    res.allocate();

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_to_integer(vm::context& ctx)
{
    auto& arg = ctx.stack_back();
    if (arg->type == blob_type::bigint) return;
    smart_blob result;
    if (arg->type == blob_type::boolean || is_basic_integral(arg->type)) {
        result = smart_blob{ bigint_blob_result(arg.as<numetron::integer>()) };
    }
    if (::is_floating_point(arg->type)) {
        numetron::decimal_view dv = arg.as<numetron::decimal_view>();
        result = smart_blob{ bigint_blob_result((numetron::integer)dv) };
    } else {
        THROW_INTERNAL_ERROR("cannot convert to integer: %1%"_fmt % arg);
    }
    arg.replace(std::move(result));
}

void annium_str2dec(vm::context& ctx)
{
    auto str = ctx.stack_back().as<string_view>();
    try {
        numetron::decimal d{ str };
        smart_blob res{ decimal_blob_result(d) };
        res.allocate();
        ctx.stack_back().replace(std::move(res));
    } catch (std::exception const& e) {
        ctx.stack_back().replace(error_blob_result(e.what())); // nil_blob_result()
        ctx.stack_back().allocate();
    }
}

void annium_int2dec(vm::context& ctx)
{
    auto ival = ctx.stack_back().as<numetron::integer_view>();
    numetron::decimal dval{ ival };
    smart_blob res{ decimal_blob_result(dval) };
    res.allocate();
    ctx.stack_back().replace(std::move(res));
}

void annium_int2flt(vm::context& ctx)
{
    auto ival = ctx.stack_back().as<numetron::integer_view>();
    ctx.stack_back().replace(smart_blob{ f32_blob_result((float)ival) });
}

void annium_create_extern_object(vm::context& ctx)
{
    string_view name = ctx.stack_back().as<string_view>();
    if (name.starts_with("::"sv)) {
        name = name.substr(2);
        name = name.substr(2);
    }

    smart_blob resobj = ctx.env().invoke("create"sv, { string_blob_result(ctx.camel2kebab(name)) });
    if (resobj->type == blob_type::error) {
        throw exception(resobj.as<std::string>());
    }
    using wobj_t = invocation::wrapper_object<shared_ptr<invocation::invocable>>;
    GLOBAL_LOG_DEBUG() << "Creating extern object: %1%, address: %2%"_fmt % name % resobj.as<wobj_t>().value.get();
    ctx.stack_back().replace(std::move(resobj));
}

// (obj, propName, value)->obj
void annium_set_object_property(vm::context& ctx)
{
    using namespace sonia::invocation;
    shared_ptr<invocable> obj = ctx.stack_back(2).as<wrapper_object<shared_ptr<invocable>>>().value;
    string_view prop_name = ctx.stack_back(1).as<string_view>();
    obj->set_property(ctx.camel2kebab(prop_name), *ctx.stack_back());
    ctx.stack_pop(2);
}

void annium_invoke(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    small_vector<blob_result, 16> args;
    args.reserve(argcount);
    for (size_t i = argcount; i > 0; --i) {
        args.emplace_back(*ctx.stack_back(i));
    }
    
    string_view name = ctx.stack_back(argcount + 1).as<string_view>();
    smart_blob resobj = ctx.env().invoke(name, span{ args });
    auto tstr = (std::ostringstream{} << resobj).str();
    ctx.stack_pop(argcount + 1);
    ctx.stack_back().replace(std::move(resobj));
}

void annium_invoke_void(vm::context& ctx)
{
    annium_invoke(ctx);
    ctx.stack_pop();
}

}
