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

}
