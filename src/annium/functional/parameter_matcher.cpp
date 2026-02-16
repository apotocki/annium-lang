//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "parameter_matcher.hpp"

#include "numetron/limbs_from_string.hpp"
//#include "sonia/utility/scope_exit.hpp"

#include "annium/environment.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

#include "pattern_matcher.hpp"

#include "annium/errors/value_mismatch_error.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

parameter_matcher::parameter_matcher(
    fn_compiler_context& caller_ctx,
    prepared_call const& c,
    span<const parameter_descriptor> ps,
    functional_match_descriptor &mdval)
        : param_bit{ ps.data() }, param_it{ ps.data() }, param_end{ ps.data() + ps.size() }
        , call{ c }
        , call_session{ c.new_session(caller_ctx) }
        , md{ mdval }
{
    handled_arguments_stack.reserve(c.args.size());
}

struct constraint_matcher
{
    parameter_matcher& pmatcher;
    fn_compiler_context& callee_ctx;

    basic_fn_pattern::parameter_descriptor const& pd;
    expected_result_t argexp;
    syntax_expression_result arg_er;
    prepared_call::argument_descriptor_t arg_descr;
    entity_identifier pconstraint_value_eid; // empty means no constraint value (any value is allowed)
    bool has_cast; // = res->second;

    constraint_matcher(parameter_matcher& pmatcher_val, fn_compiler_context& callee_ctx_val, basic_fn_pattern::parameter_descriptor const& pd_val)
        : pmatcher{ pmatcher_val }
        , callee_ctx{ callee_ctx_val }
        , pd{ pd_val }
        , argexp{ .modifier = to_value_modifier(pd.modifier()) }
    {}

    std::expected<bool, error_storage> do_retrieve_next_argument()
    {
        if (annotated_identifier ename = pd.ename()) {
            return pmatcher.call_session.use_named_argument(ename.value, argexp, &arg_descr);
        } else if (!has(pd.modifier(), parameter_constraint_modifier_t::variadic)) {
            return pmatcher.call_session.use_next_positioned_argument(argexp, &arg_descr);
        } else { // unnamed ellipsis eats any next argument
            return pmatcher.call_session.use_next_argument(argexp, &arg_descr);
        }
    }

    std::expected<std::pair<syntax_expression_result, bool>, error_storage> retrieve_next_argument()
    {
        auto res = do_retrieve_next_argument();
        if (!res) return std::unexpected(res.error());
        if (!*res) return std::unexpected(error_storage{}); // no more arguments
        arg_er = arg_descr.result;
        has_cast = !!arg_descr.has_been_casted;
        return std::pair{ arg_descr.result, !!arg_descr.has_been_casted };
    }

    std::expected<match_penalty, error_storage> operator()(syntax_expression const* constraint) const
    {
        if (has(pd.modifier(), parameter_constraint_modifier_t::constexpr_value)) {
            BOOST_ASSERT(pconstraint_value_eid); // shuld be set by resolve_expression_expected_result call
            if (arg_er.value() != pconstraint_value_eid) {
                return std::unexpected(make_error<value_mismatch_error>(arg_descr.expression->location, arg_er.value(), pconstraint_value_eid, constraint->location));
                //return append_cause(
                //    make_error<basic_general_error>(call.location, "argument value does not match constraint"sv, param_name.value, param_name.location),
                //    make_error<value_mismatch_error>(arg_descr.expression->location, arg_er.value(), pconstraint_value_eid, get_start_location(constraint))
                //);
            }
        } // else it's just a type constraint that has met by successful call_session.use_*** call
        return match_penalty{ .casts = has_cast, .cast_allowances = 1 };
    }

    std::expected<match_penalty, error_storage> operator()(syntax_pattern const* constraint) const
    {
        environment& env = callee_ctx.env();
        entity_identifier type_to_match;
        if (arg_er.is_const_result) {
            entity const& arg_res_entity = get_entity(env, arg_er.value());
            if (has(pd.modifier(), parameter_constraint_modifier_t::typename_value)) { // typename as constexpr value matching
                if (arg_res_entity.get_type() != env.get(builtin_eid::typename_)) {
                    return std::unexpected(make_error<type_mismatch_error>(arg_descr.expression->location, arg_er.value(), "a typename"sv));
                }
                type_to_match = arg_er.value();
            } else {
                type_to_match = arg_res_entity.get_type();
            }
        } else {
            type_to_match = arg_er.type();
        }
        match_penalty pattern_penalty;
        error_storage err = pattern_matcher{ callee_ctx, pmatcher.md.bindings, pmatcher.call.expressions, pattern_penalty }
            .match(*constraint, annotated_entity_identifier{ type_to_match, arg_descr.expression->location });
        if (err) {
            annotated_identifier param_name = pd.name();
            return std::unexpected(append_cause(
                make_error<basic_general_error>(param_name.location, "cannot match argument pattern"sv, param_name.value),
                std::move(err)
            ));
        }
        return std::expected<match_penalty, error_storage>{
            std::in_place, std::move(pattern_penalty)
        };
    }
};

// annotated_entity_identifier const& type, functional_binding_set& binding, semantic::expression_list_t& expressions) const
error_storage parameter_matcher::match(fn_compiler_context& callee_ctx)
{
    environment& env = callee_ctx.env();
    alt_error match_errors;
    auto result_error = [&match_errors]() -> error_storage {
        if (match_errors.alternatives.size() > 1) {
            return make_error<alt_error>(std::move(match_errors));
        } else {
            return std::move(match_errors.alternatives.front());
        }
    };

    while (param_it != param_end) {
        constraint_matcher cmatcher{ *this, callee_ctx, *param_it };
        annotated_identifier param_name = param_it->name();
        //entity_identifier pconstraint_value_eid; // empty means no constraint value (any value is allowed)
        
        // resolve the parameter constraint value if it is specified
        if (param_it->has_expression_constraint()) {
            syntax_expression const* param_expr = param_it->expression_constraint(); // get_if<syntax_expression const*>(&param_it->constraint)) {
            auto argexp_res = resolve_expression_expected_result(callee_ctx, param_name, param_it->modifier(), *param_expr, cmatcher.pconstraint_value_eid);
            if (!argexp_res) {
                match_errors.alternatives.emplace_back(std::move(argexp_res.error()));
                if (try_backtrack(callee_ctx)) continue;
                return result_error();
            }
            cmatcher.argexp = std::move(*argexp_res);
        }

        bool is_variadic_param = has(param_it->modifier(), parameter_constraint_modifier_t::variadic);
        if (is_variadic_param && (star_stack.empty() || star_stack.back().param_it != param_it)) {
            star_stack.emplace_back(param_it, entity_signature{ env.get(builtin_qnid::tuple), env.get(builtin_eid::typename_) });
        }

        uint32_t argindex;
        auto res = cmatcher.retrieve_next_argument();
        if (!res) {
            if (!is_variadic_param) {
                if (res.error()) {
                    match_errors.alternatives.emplace_back(append_cause(
                        make_error<basic_general_error>(param_name.location, "cannot match argument"sv, param_name.value, cmatcher.arg_descr.expression->location),
                        std::move(res.error())
                    ));
                    if (param_it != param_bit) --param_it;
                    if (try_backtrack(callee_ctx)) continue;
                    return result_error();
                // no more arguments
                } else if (syntax_expression const* default_expr =  param_it->default_value(); default_expr) {
                    // try default value
                    res = base_expression_visitor::visit(callee_ctx, call.expressions, cmatcher.argexp, *default_expr);
                    if (!res) {
                        match_errors.alternatives.emplace_back(append_cause(
                            make_error<basic_general_error>(param_name.location, "cannot evaluate default value for argument"sv, param_name.value),
                            std::move(res.error())
                        ));
                        if (param_it != param_bit) --param_it;
                        if (try_backtrack(callee_ctx)) continue;
                        return result_error();
                    }
                    cmatcher.arg_er = std::move(res->first);
                    cmatcher.has_cast = res->second;
                    argindex = argindex_for_default--;
                } else if (param_it->is_required_value()) {
                    match_errors.alternatives.emplace_back(make_error<basic_general_error>(param_name.location, "missing required argument"sv, param_name.value));
                    if (param_it != param_bit) --param_it;
                    if (try_backtrack(callee_ctx)) continue;
                    return result_error();
                } else { // else optional, continue
                    // ?? bind inames to ()
                    // ?? do we really have optional parameters without default value?
                    handled_arguments_stack.push_back({.penalty = {/* penalty for not existed argument*/}, .index = argindex_for_default--});
                    continue;
                }
            } else {
                if (res.error()) {
                    call_session.reuse_argument(cmatcher.arg_descr.arg_index);
                    match_errors.alternatives.emplace_back(std::move(res.error()));
                } // else no more arguments
                finalize_variadic(callee_ctx);
                ++param_it;
                continue;
            }
        } else {
            argindex = static_cast<uint32_t>(cmatcher.arg_descr.arg_index);
        }

        BOOST_ASSERT(res);
        handled_arguments_stack.push_back({.index = argindex});
        md.bindings.set_current_layer(argindex);
        auto penalty = [&cmatcher](parameter_descriptor const& pd) {
            if (pd.has_expression_constraint()) {
                return cmatcher(pd.expression_constraint());
            } else if (pd.has_pattern_constraint()) {
                return cmatcher(pd.pattern_constraint());
            } else {
                THROW_INTERNAL_ERROR("unknown parameter constraint type");
            }
        }(*param_it);
            
        if (!penalty) {
            if (!is_variadic_param) {
                match_errors.alternatives.emplace_back(std::move(penalty.error()));
                if (try_backtrack(callee_ctx)) continue;
                return result_error();
            } else {
                if (argindex < argindex_for_default) {
                    call_session.reuse_argument(argindex);
                } else {
                    BOOST_ASSERT(argindex == argindex_for_default + 1);
                    ++argindex_for_default; // to reuse index
                }
                finalize_variadic(callee_ctx);
                ++param_it;
                continue;
            }
        }

        penalty->variadics = is_variadic_param;
        handled_arguments_stack.back().penalty = std::move(*penalty);

        if (cmatcher.arg_descr.name) {
            md.append_arg(cmatcher.arg_descr.name.value, cmatcher.arg_er, cmatcher.arg_descr.expression->location);
        } else {
            md.append_arg(cmatcher.arg_er, cmatcher.arg_descr.expression->location);
        }

        if (is_variadic_param) {
            entity_signature& variadic_type_sig = star_stack.back().signature;
            if (cmatcher.arg_er.is_const_result) {
                if (cmatcher.arg_descr.name) {
                    variadic_type_sig.emplace_back(cmatcher.arg_descr.name.value, cmatcher.arg_er.value(), true);
                } else {
                    variadic_type_sig.emplace_back(cmatcher.arg_er.value(), true);
                }
            } else {
                identifier unnamedid = env.new_identifier(); // it's not a part of signature
                entity_identifier unnamedid_entid = env.make_qname_entity(qname{ unnamedid, false }).id;

                if (cmatcher.arg_descr.name) {
                    variadic_type_sig.emplace_back(cmatcher.arg_descr.name.value, unnamedid_entid, true);
                } else {
                    variadic_type_sig.emplace_back(unnamedid_entid, true);
                }
                local_variable var{ .type = cmatcher.arg_er.type(), .varid = env.new_variable_identifier(), .is_weak = false };
                md.bindings.emplace_back(argindex, annotated_identifier{ unnamedid, cmatcher.arg_descr.expression->location }, var);
            }
        } else {
            if (cmatcher.arg_er.is_const_result) {
                if (annotated_identifier name = param_it->name()) {
                    md.bindings.emplace_back(argindex, name, cmatcher.arg_er.value());
                }
                if (annotated_identifier alias_name = param_it->alias_name()) {
                    md.bindings.emplace_back(argindex, alias_name, cmatcher.arg_er.value());
                }
            } else {
                local_variable var{ .type = cmatcher.arg_er.type(), .varid = env.new_variable_identifier(), .is_weak = false };
                if (annotated_identifier name = param_it->name()) {
                    md.bindings.emplace_back(argindex, name, var);
                }
                if (annotated_identifier alias_name = param_it->alias_name()) {
                    md.bindings.emplace_back(argindex, alias_name, var);
                }
            }
            ++param_it;
        }
    }

    // Check if there are any unused arguments
    if (auto argterm = call_session.unused_argument(); argterm) {
        if (annotated_identifier const* name = argterm.name()) {
            match_errors.alternatives.emplace_back(make_error<basic_general_error>(argterm.location(),
                "argument mismatch"sv, *name));
        } else {
            match_errors.alternatives.emplace_back(make_error<basic_general_error>(argterm.location(),
                "argument mismatch"sv, std::move(argterm.value())));
        }
        return result_error();
    }

    // summarize penalties
    for (auto const& arg : handled_arguments_stack) {
        md.penalty += arg.penalty;
    }
    if (!star_stack.empty()) {
        // consider each ellipsis as an implicit placeholder
        auto& phs = md.penalty.placeholders;
        if (phs.empty()) {
            phs.push_back(static_cast<unsigned int>(star_stack.size()));
        } else {
            phs.front() += static_cast<unsigned int>(star_stack.size());
        }
    }
    
    return {};
}

bool parameter_matcher::try_backtrack(fn_compiler_context& callee_ctx)
{
    while (!star_stack.empty()) {
        star_frame& frame = star_stack.back();
        while (param_it != frame.param_it) {
            BOOST_ASSERT(!handled_arguments_stack.empty());
            auto argindex = handled_arguments_stack.back().index;
            if (argindex < argindex_for_default) {
                call_session.reuse_argument(argindex);
            } else {
                BOOST_ASSERT(argindex == argindex_for_default + 1);
                ++argindex_for_default; // to reuse index
            }
            handled_arguments_stack.pop_back();
            md.remove_last_arg();
            md.bindings.remove_layer(argindex);
            --param_it;
        }
        if (!frame.signature.empty()) {
            BOOST_ASSERT(!handled_arguments_stack.empty());
            auto argindex = handled_arguments_stack.back().index;
            call_session.reuse_argument(argindex);
            handled_arguments_stack.pop_back();
            md.bindings.remove_layer(argindex);
            md.remove_last_arg();
            frame.signature.pop_back();
            finalize_variadic(callee_ctx);
            ++param_it;
            return true;
        }
        // star is empty, remove it
        star_stack.pop_back();
        md.remove_last_arg();
        // to do: pop star binding
        if (param_it == param_bit) {
            BOOST_ASSERT(star_stack.empty());
            break;
        }
        --param_it;
    }
    return false;
}

std::expected<expected_result_t, error_storage>
parameter_matcher::resolve_expression_expected_result(fn_compiler_context& callee_ctx, annotated_identifier const& pn, parameter_constraint_modifier_t param_mod, syntax_expression const& constraint, entity_identifier& pconstraint_value_eid)
{
    environment& e = callee_ctx.env();
    auto cnt_res = base_expression_visitor::visit(callee_ctx, call.expressions, expected_result_t{ .modifier = value_modifier_t::constexpr_value }, constraint);
    if (!cnt_res) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(call.location, "Cannot evaluate constraint for parameter"sv, pn.value, pn.location),
            std::move(cnt_res.error())
        ));
    }
    expected_result_t expr_exp{ .location = constraint.location, .modifier = to_value_modifier(param_mod) };
    syntax_expression_result& cnt_res_er = cnt_res->first;
    entity const& cnt_res_ent = get_entity(e, cnt_res_er.value());

    if (has(param_mod, parameter_constraint_modifier_t::constexpr_value)) {
        expr_exp.type = cnt_res_ent.get_type();
        pconstraint_value_eid = cnt_res_er.value();
    } else {
        if (cnt_res_ent.get_type() != e.get(builtin_eid::typename_)) {
            return std::unexpected(make_error<basic_general_error>(
                pn.location, "Constraint value is not a type name, but the modifier requires type name"sv, nullptr, constraint.location));
        }
        expr_exp.type = cnt_res_ent.id;
    }
    return expr_exp;
}

void parameter_matcher::finalize_variadic(fn_compiler_context& callee_ctx)
{
    environment& env = callee_ctx.env();
    star_frame& sf = star_stack.back();
    
    basic_signatured_entity const& ellipsis_type = env.make_basic_signatured_entity(entity_signature{ sf.signature });
    entity_identifier ellipsis_type_unit_eid = env.make_empty_entity(ellipsis_type).id;

    uint32_t argindex = handled_arguments_stack.empty() ? (std::numeric_limits<uint32_t>::max)() : handled_arguments_stack.back().index;
    if (annotated_identifier name = param_it->name()) {
        md.bindings.emplace_back(argindex, name, ellipsis_type_unit_eid);
    }
    if (annotated_identifier alias_name = param_it->alias_name()) {
        md.bindings.emplace_back(argindex, alias_name, ellipsis_type_unit_eid);
    }
}

}
