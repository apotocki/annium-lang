//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "extern_fn_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

namespace annium {

namespace {

// joins every part of a (presumably absolute) qname with the C++-style "::" separator,
// without a leading "::" -- e.g. `foo::bar` for a function `bar` declared inside `namespace foo`,
// or just `bar` for one declared at the top level.
small_string join_qualified_name(environment& e, qname_view qn)
{
    std::string joined;
    bool first = true;
    for (identifier const& id : qn) {
        if (!first) joined += "::"sv;
        first = false;
        small_string const* part = e.slregistry().resolve(id);
        BOOST_ASSERT(part);
        joined.append(part->data(), part->size());
    }
    return small_string{ joined };
}

}

error_storage extern_fn_pattern::init(fn_compiler_context& ctx, fn_pure const& fnd, qname_identifier fnname)
{
    if (error_storage err = basic_fn_pattern::init(ctx, fnd); err) return err;

    environment& e = ctx.env();
    fnname_ = join_qualified_name(e, e.fregistry_resolve(fnname).name());
    return {};
}

std::expected<syntax_expression_result, error_storage> extern_fn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    syntax_expression_result result{};

    // __extern_invoke's calling convention: name, then every runtime argument, then the trailing arg count.
    e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ string_blob_result(fnname_) } });

    for (auto& [_, mr, loc] : md.matches) {
        BOOST_ASSERT(!mr.is_const_result); // guaranteed: extern fn parameters must be declared `runtime` (declaration_visitor)
        append_semantic_result(el, mr, result);
    }

    e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui32_blob_result(static_cast<uint32_t>(md.matches.size())) } });

    BOOST_ASSERT(md.signature.result);
    bool has_result = md.signature.result->entity_id() != e.get(builtin_eid::void_);
    e.push_back_expression(el, result.expressions,
        semantic::invoke_function(e.get(has_result ? builtin_eid::extern_invoke : builtin_eid::extern_invoke_void)));

    result.value_or_type = md.signature.result->entity_id();
    result.is_const_result = md.signature.result->is_const();
    return result;
}

}
