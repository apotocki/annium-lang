//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "struct_fn_pattern.hpp"
#include "struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"
#include "annium/errors/circular_dependency_error.hpp"

namespace annium {

struct_fn_pattern::struct_fn_pattern(struct_body_t const& body)
    : body_{ body }
{}

error_storage struct_fn_pattern::init(fn_compiler_context& ctx, annotated_qname const& name, parameter_list_t const& pl)
{
    fn_pure_t fn{ .nameval = (qname_view)name.value,
                  .location = name.location,
                  .parameters = pl,
                  .result = nullptr,
                  .kind = fn_kind::DEFAULT };
    return basic_fn_pattern::init(ctx, fn);
}

std::expected<syntax_expression_result, error_storage> struct_fn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    md.signature.result.emplace(e.get(builtin_eid::typename_));
    indirect_signatured_entity smpl{ md.signature };

    entity const& struct_end = e.eregistry_find_or_create(smpl, [this, &ctx, &md]() {
        environment& e = ctx.env();
        functional& fnl = e.fregistry_resolve(md.signature.name);
        qname struct_ns = fnl.name() / e.new_identifier();
        //fn_compiler_context struct_ctx{ ctx, struct_ns };
        //internal_function_entity fent{ qname{ struct_ns }, entity_signature{ md.signature }, statement_span{} };
        // build_scope(e, md, fent);
        // e.fregistry().resolve(struct_ns).name() // do we need a functional to store qname?
        auto res = sonia::make_shared<struct_entity>(std::move(struct_ns), std::move(md.signature), body_);
        res->context_bindings() = std::move(md.bindings);
        res->location = location();
        return res;
    });

    return syntax_expression_result{
        .value_or_type = struct_end.id,
        .is_const_result = true
    };
}

}
