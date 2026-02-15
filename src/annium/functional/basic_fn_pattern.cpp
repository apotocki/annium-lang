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

error_storage basic_fn_pattern::init(fn_compiler_context& ctx, fn_pure const& fnd)
{
    location = fnd.location;
    visit([this](auto&& expr) {
        if constexpr (std::is_same_v<std::decay_t<decltype(expr)>, nullptr_t>) {
            result_ = nullptr;
        } else {
            static_assert(
                std::is_same_v<std::decay_t<decltype(expr)>, syntax_expression const*> ||
                std::is_same_v<std::decay_t<decltype(expr)>, syntax_pattern const*>
            );
            result_ = *expr;
        }
    }, fnd.result);

    parameters_.reserve(fnd.parameters.size());

    boost::container::small_flat_map<identifier, resource_location, 8> parameter_names_; // all parameters to bind during the call

    auto check_param_name = [&](auto& map, annotated_identifier const& name) -> error_storage {
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
        auto [external_name, internal_name] = visit(param_name_retriever{}, param.name);

        annotated_identifier iname;
        annotated_identifier alias_name;

        if (!external_name) {
            bool reversed = false;
            char* epos = numetron::to_string(span{ &argindex, 1 }, argname.data() + 1, reversed);
            if (reversed) std::reverse(argname.data() + 1, epos);
            identifier alias_id = ctx.env().slregistry().resolve(string_view{ argname.data(), epos });
            ++argindex;
            auto loc = visit([](auto && f) -> resource_location {
                if constexpr (std::is_same_v<std::decay_t<decltype(f)>, syntax_expression const*>) {
                    return f->location;
                } else {
                    return get_start_location(*f);
                }
            }, param.constraint);
            if (!internal_name) {
                iname = annotated_identifier{ alias_id, loc };
            } else {
                if (auto err = check_param_name(parameter_names_, *internal_name); err) return err;
                if (internal_name->value != alias_id) {
                    alias_name = annotated_identifier{ alias_id, loc }; 
                } // else no need to bind the same name twice
            }
        } else {
            if (auto err = check_param_name(parameter_names_, *external_name); err) return err;
            if (internal_name) {
                if (auto err = check_param_name(parameter_names_, *internal_name); err) return err;
            }
        }

        parameters_.emplace_back(
            external_name ? *external_name : annotated_identifier{},
            internal_name ? *internal_name : iname,
            param.constraint,
            param.default_value,
            param.modifier);

        if (alias_name) {
            parameters_.back().set_alias(alias_name);
        }
    }
    return {};
}

std::expected<functional_match_descriptor_ptr, error_storage> basic_fn_pattern::try_match(fn_compiler_context& caller_ctx, prepared_call const& call, expected_result_t const& exp) const
{
    // quick mismatch check
    syntax_pattern const* rpattern = get_if<syntax_pattern>(&result_);
    if (rpattern && !exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "Cannot match pattern without expected result"sv, nullptr, get_start_location(*rpattern)));
    }

    environment& e = caller_ctx.env();

    // prepare binding
    layered_binding_set ct_call_binding; // binding for builtin call constants, e.g. #call_location
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
    if (rpattern) {
        BOOST_ASSERT(exp);
        error_storage err = pattern_matcher{ callee_ctx, pmd->bindings, call.expressions, pmd->penalty }.match(*rpattern, annotated_entity_identifier{ exp.type, exp.location });
        if (err) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "Cannot match result pattern"sv, nullptr, get_start_location(*rpattern)),
                std::move(err)
            ));
        }
        //pmd->weight -= static_cast<int>(pmd->bindings.size());
        // to do: not only void_type can produce only constexpr result
        if (exp.type == e.get(builtin_eid::void_type)) {
            call_sig.result.emplace(e.get(builtin_eid::void_), true);
        } else {
            call_sig.result.emplace(exp.type, false);
        }
    }

    parameter_matcher pmatcher{ caller_ctx, call, parameters_, *pmd };
    auto err = pmatcher.match(callee_ctx);
    if (err) {
        return std::unexpected(std::move(err));
    }

    if (syntax_expression const* rexpr = get_if<syntax_expression>(&result_)) {
        auto res = base_expression_visitor::visit(callee_ctx, call.expressions, expected_result_t{ .modifier = value_modifier_t::constexpr_value }, *rexpr);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(call.location, "Cannot evaluate result expression"sv, nullptr, rexpr->location),
                std::move(res.error())
            ));
        }
        syntax_expression_result& res_er = res->first;
        entity const& res_ent = get_entity(e, res_er.value());
        call_sig.result.emplace(res_er.value(), res_ent.get_type() != e.get(builtin_eid::typename_));
    }

    return pmd;
}

std::pair<syntax_expression_result, size_t> basic_fn_pattern::apply_arguments(fn_compiler_context&, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    size_t count = 0;
    syntax_expression_result result{};
    for (auto& [_, mr, loc] : md.matches) {
        if (!mr.is_const_result) {
            append_semantic_result(el, mr, result);
            ++count;
        }
    }
    result.is_const_result = !count;
    return { result, count };
}

shared_ptr<internal_function_entity> basic_fn_pattern::build(fn_compiler_context& ctx, entity_signature&& signature, basic_functional_binding&& mdbindings) const
{
    environment& env = ctx.env();

    qname_view fnqn = env.fregistry_resolve(signature.name).name();
    qname fn_ns = fnqn / env.new_identifier();

    // if the signature has a result, it's the function result.
    // If the signature has no result, the function result should be set later by analizing the body of the function.
    field_descriptor result_field;
    if (signature.result) {
        result_field = *signature.result;
    }
    auto pife = make_shared<internal_function_entity>(
        env,
        std::move(fn_ns),
        std::move(signature),
        location,
        std::move(result_field));

    build_scope(env, std::move(mdbindings), *pife);

    return pife;
}

void basic_fn_pattern::build_scope(environment& e, basic_functional_binding&& mdbindings, internal_function_entity& fent) const
{
    // bind variables (rt arguments)
    for (parameter_descriptor const& pd : parameters_) {
        functional_binding::value_type const* bsp = mdbindings.lookup(pd.name().value);
        BOOST_ASSERT(bsp);

        if (!has(pd.modifier(), parameter_constraint_modifier_t::variadic)) {
            if (local_variable const* plv = get_if<local_variable>(bsp); plv) {
                fent.context().push_scope_variable(*plv);
            } // else arg is constant
            continue;
        }

        entity_identifier const* peid = get_if<entity_identifier>(bsp);
        if (!peid) {
            THROW_INTERNAL_ERROR("internal_fn_pattern::build_scope: expected entity_identifier in functional_binding::value_type for ellipsis");
        }

        entity const& ellipsis_unit = get_entity(e, *peid);
        entity_identifier ellipsis_unit_type_id = ellipsis_unit.get_type();
        entity const& ellipsis_unit_type = get_entity(e, ellipsis_unit_type_id);
        entity_signature const* pellipsis_sig = ellipsis_unit_type.signature();
        BOOST_ASSERT(pellipsis_sig && pellipsis_sig->name == e.get(builtin_qnid::tuple));
        for (field_descriptor const& fd : pellipsis_sig->fields()) {
            BOOST_ASSERT(fd.is_const());
            entity const& fd_ent = get_entity(e, fd.entity_id());
            if (qname_entity const* pqent = dynamic_cast<qname_entity const*>(&fd_ent); pqent) {
                qname const& qn = pqent->value();
                BOOST_ASSERT(qn.size() == 1);
                identifier varname = qn.parts().front();
                functional_binding::value_type const* bvar = mdbindings.lookup(varname);
                BOOST_ASSERT(bvar);
                local_variable const* plv = get_if<local_variable>(bvar);
                BOOST_ASSERT(plv);
                fent.context().push_scope_variable(*plv);
            }
        }
    }

    // bind constants
    mdbindings.for_each([&e, &fent](identifier name, resource_location const& loc, functional_binding::value_type& value) {
        if (entity_identifier const* peid = get_if<entity_identifier>(&value); peid) {
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
    fent.bindings = std::move(mdbindings);
    fent.set_argument_variables();
    //fent.context().push_scope();
}

std::ostream& basic_fn_pattern::print(environment const& e, std::ostream& ss) const
{
    bool first = true;
    ss << '(';
    for (parameter_descriptor const& pd : parameters_) {
        if (first) first = false;
        else ss << ", "sv;

        bool first_id = true;
        if (annotated_identifier ename = pd.ename()) {
            e.print_to(ss, ename.value);
            first_id = false;
        }
        if (annotated_identifier iname = pd.iname()) {
            if (!first_id) ss << ' ';
            e.print_to(ss, iname.value);
            first_id = false;
        }
        if (identifier alias_name = pd.alias_name()) {
            if (!first_id) ss << ' ';
            e.print_to(ss, alias_name);
        }

        if (pd.has_expression_constraint()) {
            e.print_to(ss << ": "sv, *pd.expression_constraint());
        } else if (pd.has_pattern_constraint()) {
            e.print_to(ss << ":~ "sv, *pd.pattern_constraint());
        }
        if (has(pd.modifier(), parameter_constraint_modifier_t::variadic)) {
            ss << "... "sv;
        } 
        if (syntax_expression const* default_value = pd.default_value()) {
            e.print_to(ss << " = "sv, *default_value);
        }
    }
    
    visit([&ss, &e](auto&& v) {
        if constexpr (std::is_same_v<std::decay_t<decltype(v)>, nullptr_t>) {
            ss << ")->auto"sv;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(v)>, syntax_expression>) {
            e.print_to(ss << ")->"sv, v);
        } else if constexpr (std::is_same_v<std::decay_t<decltype(v)>, syntax_pattern>) {
            e.print_to(ss << ")~>"sv, v);
        } else {
            static_assert(false);
        }
    }, result_);
    
    return ss;
}

}
