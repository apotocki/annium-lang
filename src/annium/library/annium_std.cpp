//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "std.hpp"

#include <regex>

namespace annium {

void std_object::do_registration(registrar_type& mr)
{
    //mr.register_readonly_property("std", [](std_object const& self) -> blob_result {
    //    return smart_blob{ }.detach();
    //});
    mr.register_method<&std_object::regex_object>("regex_object"sv);
    mr.register_method<&std_object::regex_search>("regex_search"sv);
}

class regex_object : public invocation::object
{

};

blob_result std_object::regex_object(string_view pattern)
{
    using regex_object_t = invocation::wrapper_object<std::regex>;
    return object_blob_result<regex_object_t>(pattern.data(), pattern.size(), std::regex_constants::ECMAScript);
}

blob_result std_object::regex_search(string_view target, smart_blob re)
{
    optional<std::regex> opreg;
    std::smatch base_match;
    std::regex* pre = nullptr;
    if (re->type == blob_type::string) {
        string_view re_str = as<string_view>(*re);
        opreg.emplace(re_str.data(), re_str.size(), std::regex_constants::ECMAScript);
        pre = &*opreg;
    } else {
        using regex_object_t = invocation::wrapper_object<std::regex>;
        pre = &re.as<regex_object_t>().value;
    }
    
    std::string target_str{ target.begin(), target.end() };
    if (!std::regex_search(target_str, base_match, *pre)) {
        return array_blob_result(span<blob_result>{});
    }
    std::vector<blob_result> pieces;
    pieces.reserve(base_match.size());
    for (std::size_t i = 0; i < base_match.size(); ++i)
    {
        std::ssub_match sub_match = base_match[i];
        std::string piece = sub_match.str();
        pieces.push_back(string_blob_result(piece));
        blob_result_allocate(&pieces.back(), false);
    }
    return array_blob_result(span<blob_result>{ pieces }, true);
}

}
