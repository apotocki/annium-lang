//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "basic_fn_pattern.hpp"

#include <array>
#include <boost/container/flat_set.hpp>

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/functions/internal_function_entity.hpp" // used as a provisional

#include "annium/errors/value_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

#include "pattern_matcher.hpp"
#include "parameter_matcher.hpp"

namespace annium {

//error_storage basic_fn_pattern::init(fn_compiler_context& ctx, parameter_list_t const& parameters)
//{
//    THROW_NOT_IMPLEMENTED_ERROR("basic_fn_pattern::init is not implemented yet");
//}

error_storage basic_fn_pattern::init(fn_compiler_context& ctx, fn_pure_t const& fnd)
{
    location_ = fnd.location;
    result_ = fnd.result;

    parameters_.reserve(fnd.parameters.size());

    boost::container::small_flat_map<identifier, resource_location, 8> parameter_ext_names_; // all external names of parameters
    boost::container::small_flat_map<identifier, resource_location, 8> parameter_names_; // all parameters to bind during the call

    auto insert_param_name = [&](auto& map, annotated_identifier const& name) -> error_storage {
        if (auto pair = map.emplace(name.value, name.location); !pair.second) {
            // If the external name is already used, return the error
            return make_error<basic_general_error>(
                name.location, "Duplicate parameter name"sv, name.value, pair.first->second);
        }
        return error_storage{};
    };

    // to do: try to precompile expressions and patterns if possible
    
    // auxiliary
    std::array<char, 16> argname = { '$' };
    size_t argindex = 0;

    for (auto& param : fnd.parameters) {
        auto [external_name, internal_name] = apply_visitor(param_name_retriever{}, param.name);
        parameters_.emplace_back(
            external_name ? *external_name : annotated_identifier{},
            std::initializer_list<annotated_identifier>{},
            param.constraint,
            param.default_value,
            param.modifier);

        parameter_descriptor& pd = parameters_.back();
        pd.constraint = param.constraint;

        if (!external_name) {
            bool reversed = false;
            char* epos = numetron::to_string(span{ &argindex, 1 }, argname.data() + 1, reversed);
            if (reversed) std::reverse(argname.data() + 1, epos);
            identifier nid = ctx.env().slregistry().resolve(string_view{ argname.data(), epos });
            
            if (internal_name) {
                if (auto err = insert_param_name(parameter_names_, *internal_name); err) return err;
                pd.inames.emplace_back(*internal_name);
            }

            if (!internal_name || internal_name->value != nid) {
                auto loc = apply_visitor(make_functional_visitor<resource_location>([](auto const& f) {
                    return get_start_location(f);
                }), param.constraint);
                if (auto err = insert_param_name(parameter_names_, annotated_identifier{ nid, loc }); err) return err;
                pd.inames.emplace_back(annotated_identifier{ nid, loc });
            }
            
            ++argindex;
        } else {
            if (auto err = insert_param_name(parameter_ext_names_, *external_name); err) return err;

            annotated_identifier const& iname = internal_name ? *internal_name : *external_name;
            if (auto err = insert_param_name(parameter_names_, iname); err) return err;
            pd.inames.emplace_back(internal_name ? *internal_name : *external_name);
        }
    }
    return {};
}

std::expected<functional_match_descriptor_ptr, error_storage> basic_fn_pattern::try_match(fn_compiler_context& caller_ctx, prepared_call const& call, expected_result_t const& exp) const
{
    // quick mismatch check
    if (pattern_t const* rpattern = get<pattern_t>(&result_)) {
        if (!exp.type) {
            return std::unexpected(make_error<basic_general_error>(call.location, "Cannot match pattern without expected result"sv, nullptr, get_start_location(*rpattern)));
        }
    }

    environment& e = caller_ctx.env();

    // prepare binding
    functional_binding_set ct_call_binding; // binding for builtin call constants, e.g. #call_location
    ct_call_binding.emplace_back(
        annotated_identifier{ e.get(builtin_id::call_location) },
        e.make_string_entity(e.print(call.location)).id
    );
    fn_compiler_context callee_ctx{ caller_ctx, call.functional_name() };
    auto pmd = make_shared<functional_match_descriptor>(call);
    callee_ctx.push_binding(ct_call_binding);
    callee_ctx.push_binding(pmd->bindings);
    //SCOPE_EXIT([&ctx] { ctx.pop_binding(); }); // no need, temporary context
    
    entity_signature& call_sig = pmd->signature;

    // If the result is a pattern, we should handle it first.
    if (pattern_t const* rpattern = get<pattern_t>(&result_)) {
        BOOST_ASSERT(exp);
        auto err = pattern_matcher{ callee_ctx, pmd->bindings, call.expressions }.match(*rpattern, annotated_entity_identifier{ exp.type, exp.location });
        if (err) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "Cannot match result pattern"sv, nullptr, get_start_location(*rpattern)),
                std::move(err)
            ));
        }
        call_sig.result.emplace( exp.type, false );
    }

    parameter_matcher pmatcher{ caller_ctx, call, parameters_, *pmd };
    auto err = pmatcher.match(callee_ctx);
    if (err) {
        return std::unexpected(std::move(err));
    }

    if (syntax_expression_t const* rexpr = get<syntax_expression_t>(&result_)) {
        auto res = apply_visitor(base_expression_visitor{ callee_ctx, call.expressions, expected_result_t{ .modifier = value_modifier_t::constexpr_value } }, *rexpr);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "Cannot evaluate result expression"sv, nullptr, get_start_location(*rexpr)),
                std::move(res.error())
            ));
        }
        syntax_expression_result& res_er = res->first;
        entity const& res_ent = get_entity(e, res_er.value());
        call_sig.result.emplace(res_er.value(), res_ent.get_type() != e.get(builtin_eid::typename_));
    }

    return pmd;
}

std::pair<syntax_expression_result, size_t> basic_fn_pattern::apply_arguments(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    size_t count = 0;
    syntax_expression_result result{ };
    for (auto& [_, mr, loc] : md.matches) {
        append_semantic_result(el, mr, result);
        if (!mr.is_const_result) ++count;
    }
    result.is_const_result = !count;
    return { result, count };
}

shared_ptr<internal_function_entity> basic_fn_pattern::build(fn_compiler_context& ctx, functional_match_descriptor& md, entity_signature signature) const
{
    environment& e = ctx.env();

    qname_view fnqn = e.fregistry_resolve(signature.name).name();
    qname fn_ns = fnqn / e.new_identifier();

    auto pife = make_shared<internal_function_entity>(
        std::move(fn_ns),
        std::move(signature));

    pife->location = location();
    build_scope(e, md, *pife);

    return pife;
}

void basic_fn_pattern::build_scope(environment& e, functional_match_descriptor& md, internal_function_entity& fent) const
{
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
    md.bindings.for_each([&e, &fent](identifier name, resource_location const& loc, functional_binding::value_type& value) {
        entity_identifier eid = apply_visitor(make_functional_visitor<entity_identifier>([&e](auto const& e) {
            if constexpr (std::is_same_v<std::decay_t<decltype(e)>, entity_identifier>) {
                return e;
            }
            else if constexpr (std::is_same_v<std::decay_t<decltype(e)>, entity_ptr>) {
                if (e->id) return e->id;
                //if (e->get_type() == e.get(builtin_eid::metaobject)) {
                //    return e.eregistry_find_or_create(*e, [&e]() { return std::move(e); }).id();
                //}
                return e.eregistry_find_or_create(*e, [&e]() { return std::move(e); }).id;
            }
            else { // else skip variables
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

std::ostream& basic_fn_pattern::print(environment const& e, std::ostream& ss) const
{
    size_t posargnum = 0;
    bool first = true;
    ss << '(';
    for (parameter_descriptor const& pd : parameters_) {
        if (first) first = false;
        else ss << ", "sv;

        bool first_id = true;
        if (pd.ename) {
            e.print_to(ss, pd.ename.value);
            first_id = false;
        }
        for (auto const& iname : pd.inames) {
            if (!pd.ename || iname != pd.ename) {
                if (!first_id) ss << ' ';
                e.print_to(ss, iname.value);
                first_id = false;
            }
        }
        
        apply_visitor(make_functional_visitor<void>([&e, &ss](auto const& m) {
            if constexpr (std::is_same_v<pattern_t, std::decay_t<decltype(m)>>) {
                e.print_to(ss << ":~ "sv, m);
            } else if constexpr (std::is_same_v<syntax_expression_t, std::decay_t<decltype(m)>>) {
                e.print_to(ss << ": "sv, m);
            }
        }), pd.constraint);
        if ((pd.modifier & parameter_constraint_modifier_t::ellipsis) == parameter_constraint_modifier_t::ellipsis) {
            ss << "... "sv;
        }
    }
    
    if (0 == result_.which()) {
        ss << ")->auto"sv;
    } else if (auto const* pexpr = get<syntax_expression_t>(&result_)) {
        e.print_to(ss << ")->"sv, *pexpr);
    } else if (auto const* rpattern = get<pattern_t>(&result_)) {
        e.print_to(ss << ")~>"sv, *rpattern);
    }
    return ss;
}

}
