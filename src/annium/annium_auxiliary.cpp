//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "auxiliary.hpp"
#include "ast_terms.hpp"
#include "environment.hpp"
#include "semantic.hpp"

namespace annium {

entity const& get_entity(environment const& env, entity_identifier const& eid)
{
    return env.eregistry_get(eid);
}

entity_identifier get_result_type(environment const& env, syntax_expression_result const& er, entity const** ppe)
{
    if (er.is_const_result) {
        entity const& ent = get_entity(env, er.value());
        if (ppe) *ppe = &ent;
        return ent.get_type();
    }
    return er.type();
}

#if 0
struct expression_location_visitor : static_visitor<resource_location const&>
{
    expression_location_visitor() = default;

    inline result_type operator()(name_reference_expression const& v) const noexcept { return v.name.location; }
    inline result_type operator()(qname_reference_expression const& v) const noexcept { return v.name.location; }
    inline result_type operator()(stack_value_reference_expression const& v) const noexcept { return v.name.location; }

    //inline result_type operator()(annium_fn_type_t const& b) const noexcept
    //{
    //    return this->operator()(b.arg);
    //}

    //inline result_type operator()(index_expression_t const& ie) const noexcept
    //{
    //    return apply_visitor(*this, ie.base);
    //}

    //inline result_type operator()(annium_union_t const& bu) const noexcept
    //{
    //    return apply_visitor(*this, bu.members.front());
    //}

    inline result_type operator()(not_empty_expression_t const& me) const noexcept { return apply_visitor(*this, me.value); }
    inline result_type operator()(member_expression const& me) const noexcept { return me.start(); }
    //inline result_type operator()(lambda_t const& le) const noexcept { return le.location(); }

    //inline result_type operator()(unary_expression_t const& ue) const noexcept { return ue.start(); }
    //inline result_type operator()(binary_expression_t const& be) const noexcept { return be.start(); }

    //inline result_type operator()(expression_vector_t const& v) const noexcept { return v.start; }
    //inline result_type operator()(function_call_t const& f) const noexcept { return f.start(); }

    template <typename T>
    inline resource_location const& operator()(T const& e) const
    {
        if constexpr (requires{ std::declval<T const&>().location(); }) {
            return e.location();
        } else {
            return e.location;
        }
    }
};

resource_location const& get_start_location(syntax_expression const& e)
{
    return apply_visitor(expression_location_visitor{}, e);
}
#endif

resource_location get_start_location(syntax_pattern const& ptrn)
{
    return visit([](auto const& d)->resource_location {
        if constexpr (std::is_same_v<placeholder, std::decay_t<decltype(d)>>) {
            return d.location;
        } else if constexpr (std::is_same_v<context_identifier, std::decay_t<decltype(d)>>) {
            return d.name.location;
        } else if constexpr (std::is_same_v<syntax_pattern::signature_descriptor, std::decay_t<decltype(d)>>) {
            return visit([](auto && f)->resource_location {
                if constexpr (std::is_same_v<syntax_expression const*, std::decay_t<decltype(f)>>) {
                    return f->location;
                } else if constexpr (std::is_same_v<annotated_qname_view, std::decay_t<decltype(f)>>) {
                    return f.location;
                } else if constexpr (std::is_same_v<placeholder, std::decay_t<decltype(f)>>) {
                    return f.location;
                } else { // context_identifier
                    return f.name.location;
                }
            }, d.name);
        } else { // syntax_expression
            return d->location;
        }
    }, ptrn.descriptor);
}

}
