//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "basic_fn_pattern.hpp"

namespace annium {

// pattern for a natively declared `extern fn NAME(...)`. Calls are compiled as a
// synthesized __extern_invoke(name, args..., argcount) -- the callee is resolved
// by name in the hosting environment at runtime, exactly like an explicit
// __extern_invoke(...) call, just without requiring the user to spell it out.
class extern_fn_pattern : public basic_fn_pattern
{
    small_string fnname_; // fully qualified runtime lookup name, qname parts joined with "::"

public:
    extern_fn_pattern() = default;

    // parses the declaration (like basic_fn_pattern::init) and resolves the fully
    // qualified name used to look the function up in the hosting environment at runtime.
    // fnname is the functional's own qname.
    error_storage init(fn_compiler_context&, fn_pure const&, qname_identifier fnname);

    std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;
};

}
