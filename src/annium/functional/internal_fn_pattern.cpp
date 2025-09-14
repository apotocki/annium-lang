//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "internal_fn_pattern.hpp"

#include "annium/environment.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/circular_dependency_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

error_storage internal_fn_pattern::init(fn_compiler_context& ctx, fn_decl_t const& fnd)
{
    body_ = fnd.body;
    kind_ = fnd.kind;
    return basic_fn_pattern::init(ctx, fnd);
    // if (auto err = init(ctx, static_cast<fn_pure_t const&>(fnd))) return err;
}

shared_ptr<entity> internal_fn_pattern::build(fn_compiler_context& ctx, functional_match_descriptor& md, entity_signature&& signature) const
{
    environment& e = ctx.env();

    qname_view fnqn = e.fregistry_resolve(signature.name).name();
    qname fn_ns = fnqn / e.new_identifier();

    auto pife = make_shared<internal_function_entity>(
        std::move(fn_ns),
        std::move(signature),
        /*std::move(md.bindings),*/ body_);

    pife->location = location();
    build_scope(e, md, *pife);

    pife->set_inline(kind_ == fn_kind::INLINE);

    return pife;
}

void internal_fn_pattern::build_scope(environment& e, functional_match_descriptor& md, internal_function_entity& fent) const
{
    // setup captures
    if (captures_) {
        entity_signature const* psig = captures_->signature();
        BOOST_ASSERT(psig);
        span<const field_descriptor> fields = psig->fields().subspan(1); // skip 'this'
        // calculate runtime size of captures
        size_t rt_size = std::ranges::count_if(fields, [](field_descriptor const& fd) { return !fd.is_const(); });
        fent.set_captured_var_count(rt_size);
        int64_t capture_var_offset = -static_cast<int64_t>(rt_size);
        for (field_descriptor const& fd : fields) {
            if (!fd.is_const()) {
                fent.push_capture(e, fd.name(), fd.entity_id(), capture_var_offset++);
            }
        }
        // to do: for multivalued names bound constexpr vector of captures
    }

    // bind variables (rt arguments)
    for (parameter_descriptor const& pd : parameters_) {
        functional_binding::value_type const* bsp = md.bindings.lookup(pd.inames.front().value);
        BOOST_ASSERT(bsp);
        
        if (!has(pd.modifier, parameter_constraint_modifier_t::ellipsis)) {
            if (local_variable const* plv = get<local_variable>(bsp); plv) {
                fent.push_argument(plv->varid);
            } // else arg is constant
            continue;
        }

        entity_identifier const* peid = get<entity_identifier>(bsp);
        if (!peid) {
            THROW_INTERNAL_ERROR("internal_fn_pattern::build_scope: expected entity_identifier in functional_binding::value_type for ellipsis");
        }

        entity const& ellipsis_unit = get_entity(e, *peid);
        entity const& ellipsis_unit_type = get_entity(e, ellipsis_unit.get_type());
        entity_signature const* pellipsis_sig = ellipsis_unit_type.signature();
        BOOST_ASSERT(pellipsis_sig && pellipsis_sig->name == e.get(builtin_qnid::tuple));
        for (field_descriptor const& fd : pellipsis_sig->fields()) {
            BOOST_ASSERT(fd.is_const());
            entity const& fd_ent = get_entity(e, fd.entity_id());
            if (qname_entity const* pqent = dynamic_cast<qname_entity const*>(&fd_ent); pqent) {
                qname const& qn = pqent->value();
                BOOST_ASSERT(qn.size() == 1);
                identifier varname = qn.parts().front();
                functional_binding::value_type const* bvar = md.bindings.lookup(varname);
                BOOST_ASSERT(bvar);
                local_variable const* plv = get<local_variable>(bvar);
                BOOST_ASSERT(plv);
                fent.push_argument(plv->varid);
            }
        }
    }

    // bind constants
    md.bindings.for_each([&e, &fent](identifier name, resource_location const& loc, functional_binding::value_type& value) {
        if (entity_identifier const* peid = get<entity_identifier>(&value); peid) {
            qname infn_name = fent.name() / name;
            functional& fnl = e.fregistry_resolve(infn_name);
            fnl.set_default_entity(annotated_entity_identifier{ *peid, loc });
        }
    });

    //for (auto& [argindex, mr] : md.matches) {
    //    parameter_descriptor const& pd = parameters_[argindex];
    //    functional_binding::value_type const* bsp = md.bindings.lookup(pd.inames.front().value);
    //    BOOST_ASSERT(bsp);
    //    if (local_variable const* plv = get<local_variable>(bsp); plv) {
    //        fent.push_argument(plv->varid);
    //    } else {
    //        THROW_INTERNAL_ERROR("internal_fn_pattern::build_scope: expected local_variable in functional_binding::value_type");
    //    }
    //}
    
#if 0
    // bind consts
    md.bindings.for_each([&e, &fent](identifier name, resource_location const& loc, functional_binding::value_type & value) {
        entity_identifier eid = apply_visitor(make_functional_visitor<entity_identifier>([&e](auto const& e) {
            if constexpr (std::is_same_v<std::decay_t<decltype(e)>, entity_identifier>) {
                return e;
            } else if constexpr (std::is_same_v<std::decay_t<decltype(e)>, entity_ptr>) {
                if (e->id) return e->id;
                //if (e->get_type() == e.get(builtin_eid::metaobject)) {
                //    return e.eregistry_find_or_create(*e, [&e]() { return std::move(e); }).id();
                //}
                return e.eregistry_find_or_create(*e, [&e]() { return std::move(e); }).id;
            } else { // else skip variables
                return entity_identifier{};
            }
        }), value);

        if (eid) {
            qname infn_name = fent.name() / name;
            functional& fnl = e.fregistry_resolve(infn_name);
            fnl.set_default_entity(annotated_entity_identifier{ eid, loc });
        }
    });
#endif
    fent.bindings = std::move(md.bindings);
}

std::expected<syntax_expression_result_t, error_storage> internal_fn_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto [result, mut_arg_cnt] = apply_arguments(ctx, el, md);

    indirect_signatured_entity smpl{ md.signature };

    entity& e = env.eregistry_find_or_create(smpl, [this, &ctx, &md]() {
        return build(ctx, md, std::move(md.signature));
    });

    BOOST_ASSERT(dynamic_cast<internal_function_entity*>(&e));
    internal_function_entity& fne = static_cast<internal_function_entity&>(e);

    if (!fne.result) { // we need building to resolve result type
        sonia::lang::compiler_task_tracer::task_guard tg = ctx.try_lock_task(entity_task_id{ e });
        if (!tg) return std::unexpected(
            make_error<circular_dependency_error>(make_error<basic_general_error>(location_, "resolving function result type"sv, e.id))
        );
        if (!fne.result) {
            if (auto err = fne.build(env)) {
                return std::unexpected(std::move(err));
            }
        }

        BOOST_ASSERT(fne.result);
    }

    result.value_or_type = fne.result.entity_id();
    result.is_const_result = fne.result.is_const();

    if (mut_arg_cnt || !fne.is_const_eval(env)) {
        env.push_back_expression(el, result.expressions, semantic::invoke_function(e.id));
        return result;
    }

    return result;
}

}
