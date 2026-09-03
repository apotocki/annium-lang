//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "auxiliary.hpp"
#include "ast_terms.hpp"
#include "environment.hpp"
#include "semantic.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

entity const& get_entity(environment const& env, entity_identifier eid)
{
    return env.eregistry_get(eid);
}

entity_identifier get_entity_type(environment const& env, field_descriptor const& fd)
{
    if (fd.is_const()) {
        return env.eregistry_get(fd.entity_id()).get_type(); 
    } else {
        return fd.entity_id();
    }
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

struct return_lookup_visitor
{
    bool operator()(semantic::return_statement const&) const noexcept { return true; }

    bool operator()(semantic::expression_span nested) const
    {
        return all_paths_return(nested);
    }

    bool operator()(semantic::conditional_t const& cond) const
    {
        return all_paths_return(cond.true_branch) && all_paths_return(cond.false_branch);
    }

    bool operator()(semantic::switch_t const& sw) const
    {
        for (auto const& branch : sw.branches) {
            if (!all_paths_return(branch)) {
                return false;
            }
        }
        return true;
    }

    bool operator()(semantic::not_empty_condition_t const& nec) const
    {
        return all_paths_return(nec.branch);
    }

    bool operator()(semantic::loop_scope_t const& loop) const
    {
        (void)loop;
        return false;
        //return all_paths_return(loop.branch) || all_paths_return(loop.continue_branch);
    }

    template <typename T>
    bool operator()(T const&) const noexcept
    {
        return false;
    }
};


bool all_paths_return(semantic::expression_span span)
{
    while (span) {
        if (visit(return_lookup_visitor{}, span.front())) {
            return true;
        }
        span.pop_front();
    }
    return false;
}

small_vector<entity_identifier, 8> const_array_element_ids(environment& env, entity_identifier array_value_eid, entity_identifier element_type_eid)
{
    entity const& arr_ent = get_entity(env, array_value_eid);
    entity_signature const* arr_data = arr_ent.signature();

    small_vector<entity_identifier, 8> element_ids;
    if (arr_data && arr_data->name == env.get(builtin_qnid::data)) {
        element_ids.reserve(arr_data->fields().size());
        for (field_descriptor const& fd : arr_data->fields()) {
            element_ids.push_back(fd.entity_id());
        }
        return element_ids;
    }

    // Raw-blob (generic_literal_entity) representation -- see the declaration's comment.
    auto const& arr_lit = static_cast<generic_literal_entity const&>(arr_ent);
    blob_result const& arr_blob = *arr_lit.value();
    BOOST_ASSERT(is_array(arr_blob));
    blob_type_selector(arr_blob, [&](auto ident, blob_result const& b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, blob_result>) {
            // Non-packable elements (string, bigint, decimal, nested array/tuple, ...) are stored
            // as an array of full blob_result envelopes, each independently typed.
            size_t n = array_size_of<blob_result>(b);
            blob_result const* data = data_of<blob_result>(b);
            element_ids.reserve(n);
            for (size_t i = 0; i < n; ++i) {
                element_ids.push_back(env.make_generic_entity(smart_blob{ data[i] }, element_type_eid).id);
            }
        } else if constexpr (std::is_integral_v<type> || std::is_floating_point_v<type> || std::is_same_v<type, numetron::float16>) {
            // Homogeneous numeric elements are packed tightly as a native array. `bool` is read
            // back as `uint8_t` (mirroring annium_unfold, annium_library.cpp) since the blob
            // storage isn't guaranteed to hold a strictly-valid `bool` bit pattern for a raw
            // `bool*` reinterpret -- the element's *entity* is still tagged with the real
            // `element_type_eid` regardless of the blob's own underlying tag.
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t n = array_size_of<fstype>(b);
            fstype const* data = data_of<fstype>(b);
            element_ids.reserve(n);
            for (size_t i = 0; i < n; ++i) {
                element_ids.push_back(env.make_generic_entity(smart_blob{ particular_blob_result(data[i]) }, element_type_eid).id);
            }
        } else {
            THROW_INTERNAL_ERROR("const_array_element_ids: unexpected constexpr array element blob type"sv);
        }
    });
    return element_ids;
}

}
