//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "declaration_visitor.hpp"

#include <boost/container/flat_map.hpp>
#include "sonia/utility/scope_exit.hpp"

#include "fn_compiler_context.hpp"
#include "base_expression_visitor.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/struct/struct_entity.hpp"
#include "annium/entities/struct/struct_fn_pattern.hpp"
#include "annium/entities/enum/enum_entity.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"

#include "annium/functional/basic_fn_pattern.hpp"
#include "annium/functional/internal_fn_pattern.hpp"
#include "annium/functional/typefn_pattern.hpp"

#include "annium/entities/literals/literal_entity.hpp"

#include "annium/parser.hpp"

#include "annium/entities/functions/expression_resolver.hpp"

#include "annium/errors/identifier_redefinition_error.hpp"

namespace annium {

inline environment& declaration_visitor::env() const noexcept { return ctx.env(); }

declaration_visitor::result_type declaration_visitor::apply(span<const statement> initial_decls) const
{
    size_t initial_stack_size = decl_stack_.size();
    decl_stack_.emplace_back(initial_decls);
    do {
        if (decl_stack_.back().empty()) {
            decl_stack_.pop_back();
            continue;
        }
        size_t index = decl_stack_.size() - 1;
        auto res = visit(*this, decl_stack_.back().front().value);
        if (!res || *res != break_scope_kind::none) {
            decl_stack_.resize(initial_stack_size);
            return res;
        }
        decl_stack_[index] = decl_stack_[index].subspan(1);
    } while (decl_stack_.size() > initial_stack_size);
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(include_decl const& d) const
{
    fs::path fpath{ u8string_view{reinterpret_cast<char8_t const*>(d.path.value.data()), d.path.value.size() } };

    parser_context pctx{ env() };
    auto exp_decls = pctx.parse(fpath);
    if (!exp_decls.has_value()) {
        return std::unexpected(make_error<basic_general_error>(d.path.location, exp_decls.error()));
    }
    decl_stack_.emplace_back(*exp_decls);
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(extern_var const& d) const
{
    semantic::managed_expression_list el{ env() };
    auto vartype = base_expression_visitor::visit(ctx, el, expected_result_t{ .modifier = value_modifier_t::constexpr_value }, d.type);
    if (!vartype) {
        return std::unexpected(std::move(vartype.error()));
    }
    BOOST_ASSERT(!el);

    qname var_qname = ctx.ns() / d.name.value;
    functional& fnl = env().fregistry_resolve(var_qname);
    fnl.set_default_result(functional_variable{ .name = d.name, .type = vartype->first.value() });
    //auto ve = sonia::make_shared<extern_variable_entity>(vartype->first.value(), fnl.id());
    //ve->location = d.name.location;
    //env().eregistry_insert(ve);
    //fnl.set_default_entity(annotated_entity_identifier{ ve->id, d.name.location });

    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(using_decl const& ud) const
{
    // to do: check the allowence of absolute qname
    qname uqn = ctx.ns() / ud.name;
    functional& fnl = env().resolve_functional(uqn);
    if (ud.parameters.empty()) {
        fnl.set_default_entity(sonia::make_shared<expression_resolver>(ud.location, *get<return_statement>(ud.body.front().value).expression));
    } else {
        auto fnptrn = make_shared<internal_fn_pattern>();
        error_storage err = fnptrn->init(ctx, static_cast<fn_decl const&>(ud));
        if (err) {
            return std::unexpected(std::move(err));
        }
        
        //fnptrn->result_constraints.emplace(parameter_constraint_set_t{ .expression = ud.expression }, parameter_constraint_modifier_t::const_value);
        fnl.push(std::move(fnptrn));
        return std::unexpected(std::move(err));
    }
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(expression_statement const& ed) const
{
    //auto bst = ctx.expressions_branch(); // store branch
    semantic::managed_expression_list el{ env() };
    expected_result_t exp{
        .type = env().get(builtin_eid::void_type),
        .location = ed.expression.location,
        .modifier = value_modifier_t::constexpr_value };
    auto res = base_expression_visitor::visit(ctx, el, exp, ed.expression);
    if (!res) return std::unexpected(std::move(res.error()));

    ctx.push_scope();
    ctx.append_result_inplace(el, res->first);
    ctx.pop_scope(false);
    
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::do_rt_if_decl(if_decl const& stm) const
{
    ctx.append_expression(semantic::conditional_t{});
    semantic::conditional_t& cond = get<semantic::conditional_t>(ctx.expressions().back());
    ctx.pop_scope_variable(); // remove the condition variable from the scope (because it's consumed by conditional jump)
    break_scope_kind break_result_value = break_scope_kind::none;

    ctx.push_scopes_to_stash();
    if (!stm.true_body.empty()) {
        
        ctx.push_scope();
        
        ctx.push_chain();
        auto res = apply(stm.true_body);
        if (!res) return res;
        break_result_value = *res;
        if (break_result_value == break_scope_kind::none) {
            ctx.pop_scope();
        } // else the scope has been popped by break/continue/return statement, so do not pop it again
        cond.true_branch = ctx.expressions();
        ctx.pop_chain();
        
        if (!stm.false_body.empty()) {
            cond.true_branch_finished = all_paths_return(cond.true_branch);
        }
    }

    if (break_result_value != break_scope_kind::none) { // scope locals destroyed by break/continue/return statement, we need to restore it
        ctx.peek_scopes_from_stash();
    }

    if (!stm.false_body.empty()) {

        ctx.push_scope();
        
        ctx.push_chain();
        auto res = apply(stm.false_body);
        if (!res) return res;
        if (*res == break_scope_kind::none) {
            ctx.pop_scope();
        }
        cond.false_branch = ctx.expressions();
        ctx.pop_chain();
        //cond.false_branch_finished = all_paths_return(cond.false_branch); // actually not used

        if (static_cast<int>(break_result_value) > static_cast<int>(*res)) {
            break_result_value = *res;
        }
        if (*res == break_scope_kind::none) {
            ctx.pop_dismiss_scopes_from_stash();
        } else if (break_result_value == break_scope_kind::none) {
            ctx.pop_scopes_from_stash();
        } else {
            // all branches destroyed by break/continue/return statement
            // no need to restore the scope
            ctx.pop_dismiss_scopes_from_stash();
        }
    } else {
        break_result_value = break_scope_kind::none;
        ctx.pop_dismiss_scopes_from_stash(); // because the false branch is empty, we won't execute it, so we can dismiss the popped scopes
    }
    
    return break_result_value;
}

declaration_visitor::result_type declaration_visitor::operator()(if_decl const& stm) const
{
    semantic::managed_expression_list el{ env() };
    auto res = base_expression_visitor::visit(ctx, el, { env().get(builtin_eid::boolean), stm.condition.location }, stm.condition);
    if (!res) return std::unexpected(std::move(res.error()));
    syntax_expression_result& er = res->first;
    
    //GLOBAL_LOG_INFO() << "-----------------";
    //er.expressions.for_each([this](semantic::expression const& e) {
    //    GLOBAL_LOG_INFO() << env().print(e);
    //});
    //GLOBAL_LOG_INFO() << "-----------------";

    
    ctx.append_result(el, er);
    
    if (er.is_const_result) { // constexpr result
        entity_identifier v = er.value();
        BOOST_ASSERT(v == env().get(builtin_eid::false_) || v == env().get(builtin_eid::true_));
        span<const statement> body = (v == env().get(builtin_eid::true_) ? stm.true_body : stm.false_body);
        ctx.push_scope();
        result_type result = apply(body);
        if (result && *result == break_scope_kind::none) {
            ctx.pop_scope();
        }
        return result;
    } else {
        return do_rt_if_decl(stm);
    }
}

declaration_visitor::result_type declaration_visitor::operator()(for_statement const& fd) const
{
    ctx.push_scope();
    
    semantic::managed_expression_list el{ env() };

    resource_location const& coll_expr_loc = fd.coll.location;
    // iterator(fd.coll) -> iterator_object
    call_builder iterator_call{ coll_expr_loc };
    iterator_call.emplace_back(fd.coll);
    
    auto iterator_result = ctx.find_and_apply(builtin_qnid::iterator, iterator_call, el);
    if (!iterator_result) {
        return std::unexpected(append_cause( 
            make_error<basic_general_error>(coll_expr_loc, "Cannot create iterator for the collection"sv),
            std::move(iterator_result.error())));
    }
    
    ctx.append_result(el, *iterator_result); // append iterator creation result
    // save iterator to local variable
    //identifier iterator_var_name = env().new_identifier();
    //
    //ctx.push_scope_variable(
    //    annotated_identifier{ iterator_var_name },
    //    local_variable{
    //        .type = iterator_result->type(),
    //        .varid = env().new_variable_identifier(),
    //        .is_weak = false
    //    });

    // has_next(iterator)
    call_builder has_next_call{ coll_expr_loc };
    if (iterator_result->is_const_result) {
        has_next_call.emplace_back(coll_expr_loc, iterator_result->value());
    } else {
        has_next_call.emplace_back(coll_expr_loc, top_stack_value_expression{
            //.name = env().new_identifier(),
            .type = iterator_result->type()
        });
    }
    auto has_next_result = ctx.find_and_apply(builtin_qnid::has_next, has_next_call, el,
        expected_result_t{ env().get(builtin_eid::boolean), coll_expr_loc });
    if (!has_next_result) {
        return std::unexpected(append_cause( 
            make_error<basic_general_error>(coll_expr_loc, "Cannot invoke has_next function for the iterator"sv),
            std::move(has_next_result.error())));
    }
    if (has_next_result->is_const_result && has_next_result->value() == env().get(builtin_eid::false_)) {
        // no iterations
        ctx.pop_scope();
        return break_scope_kind::none;
    }
    BOOST_ASSERT(!has_next_result->is_const_result); // not implemented yet

    ctx.append_expression(std::move(semantic::loop_scope_t{}));
    semantic::loop_scope_t& ls = get<semantic::loop_scope_t>(ctx.expressions().back());
    //ctx.append_expression(semantic::truncate_values{ .count = (uint16_t)scsz, .keep_back = 0 }); // remove iterator value

    ctx.push_chain();
        ctx.append_result(el, *has_next_result);
        ctx.append_expression(semantic::conditional_t{});
        semantic::conditional_t& cond = get<semantic::conditional_t>(ctx.expressions().back());
        ctx.push_chain();
            // push iterator variable on stack
            call_builder next_call{ coll_expr_loc };
            if (iterator_result->is_const_result) {
                next_call.emplace_back(coll_expr_loc, iterator_result->value());
            } else {
                next_call.emplace_back(coll_expr_loc, top_stack_value_expression{
                    //.name = env().new_identifier(),
                    .type = iterator_result->type()
                });
            }
            auto next_result = ctx.find_and_apply(builtin_qnid::next, next_call, el);
            if (!next_result) {
                return std::unexpected(append_cause( 
                    make_error<basic_general_error>(coll_expr_loc, "Cannot invoke next function for the iterator"sv),
                    std::move(next_result.error())));
            }

            ctx.push_scope(); // 'next' will be in scope
                // assign next_result to fd.iter variable
                if (auto const* name_ref = get_if<name_reference_expression>(&fd.iter.value); name_ref) {
                    ctx.append_result(el, *next_result, annotated_identifier{ name_ref->name, fd.iter.location });
                    //ctx.push_scope_variable(
                    //    annotated_identifier{ name_ref->name, fd.iter.location },
                    //    local_variable{ 
                    //        .type = next_result->type(), 
                    //        .varid = env().new_variable_identifier(), 
                    //        .is_weak = false 
                    //    });
                } else if (auto const* qname_ref = get_if<qname_reference_expression>(&fd.iter.value); qname_ref) {
                    BOOST_ASSERT(qname_ref->name.is_relative() && qname_ref->name.size() == 1);
                    identifier var_name = *qname_ref->name.begin();
                    ctx.append_result(el, *next_result, annotated_identifier{ var_name, fd.iter.location });
                    //ctx.push_scope_variable(
                    //    annotated_identifier{ var_name, fd.iter.location },
                    //    local_variable{ 
                    //        .type = next_result->type(), 
                    //        .varid = env().new_variable_identifier(), 
                    //        .is_weak = false 
                    //    });
                }
                if (auto err = apply(fd.body); err) return err;
            ctx.pop_scope(); // free 'next' variable
            
            ctx.append_expression(semantic::loop_continuer{});
            cond.true_branch = ctx.expressions();
        ctx.pop_chain();

        // False branch: break the loop
        ctx.push_chain();
            ctx.append_expression(semantic::loop_breaker{});
            cond.false_branch = ctx.expressions();
        ctx.pop_chain();

        ls.branch = ctx.expressions();
    ctx.pop_chain();
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(while_decl const& wd) const
{
    (void)wd;
    THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor while_decl");
#if 0
    ctx.push_scope();
    ctx.append_expression(std::move(semantic::loop_scope_t{}));
    semantic::loop_scope_t& ls = get<semantic::loop_scope_t>(ctx.expressions().back());
    
    semantic::managed_expression_list el{ env() };

    if (wd.continue_expression) {
        auto res = base_expression_visitor::visit(ctx, el, *wd.continue_expression);
        if (!res) return std::unexpected(std::move(res.error()));
        syntax_expression_result& er = res->first;

        ctx.push_chain();
        size_t scope_sz = ctx.append_result(el, er);
        (void)scope_sz;

        if (!er.is_const_result && er.value_or_type != env().get(builtin_eid::void_)) {
            ctx.append_expression(semantic::truncate_values(1, false));
        }
        ls.continue_branch = ctx.expressions(); // store continue branch
        ctx.pop_chain();
    }

    ctx.push_chain();
    
    auto res = base_expression_visitor::visit(ctx, el, { env().get(builtin_eid::boolean), wd.condition.location }, wd.condition);
    if (!res) return std::unexpected(std::move(res.error()));
    syntax_expression_result& er = res->first;
    
    size_t scope_sz = ctx.append_result(el, er);
    (void)scope_sz;
    THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor while_decl condition");
#endif
#if 0
    if (auto const* ppv = get<semantic::push_value>(&ctx.expressions().back())) {
        auto* pb = get<bool>(&ppv->value);
        if (!pb) THROW_INTERNAL_ERROR("a bool value is expected");
        if (!*pb) { // while(false) => skip the loop
            ctx.pop_scope(); // restore ns
            ctx.pop_chain(); // loop_scope_t chain
            ctx.expressions().pop_back(); // semantic::loop_scope_t{}
            return break_scope_kind::none;
        }
        ctx.expressions().pop_back(); // push_value(true)
        if (auto err = apply(wd.body); err) {
            return std::move(err);
        }
        //for (auto const& d : wd.body) {
        //    apply_visitor(*this, d);
        //}
        
        ctx.append_expression(semantic::loop_continuer{});
        ls.branch = ctx.store_semantic_expressions(std::move(branch));
        ctx.pop_scope(); // restore ns
        ctx.pop_chain(); // loop_scope_t chain
        return break_scope_kind::none;
    }
    ctx.append_expression(semantic::conditional_t{});
    semantic::conditional_t& cond = get<semantic::conditional_t>(ctx.expressions().back());

    auto bst = ctx.expressions_branch(); // store branch

    semantic::managed_expression_list true_branch{ env() };
    ctx.push_chain(true_branch);

    if (auto err = apply(wd.body); err) {
        return std::move(err);
    }
    //for (auto const& d : wd.body) {
    //    apply_visitor(*this, d);
    //}
    
    ctx.append_expression(semantic::loop_continuer{});
    cond.true_branch = ctx.store_semantic_expressions(std::move(true_branch));
    cond.true_branch_finished = 1;
    ctx.collapse_chains(bst);

    semantic::managed_expression_list false_branch{ env() };
    ctx.push_chain(false_branch);
    ctx.append_expression(semantic::loop_breaker{});
    cond.false_branch = ctx.store_semantic_expressions(std::move(false_branch));
    cond.false_branch_finished = 1;
    ctx.collapse_chains(bst);

    ls.branch = ctx.store_semantic_expressions(std::move(branch));
    ctx.pop_chain();
    ctx.pop_scope();

    return break_scope_kind::none;
#endif
}

declaration_visitor::result_type declaration_visitor::operator()(continue_statement const&) const
{
    // to do: check the existance of enclisong loop
    //THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor continue_statement_t");
    ctx.append_expression(semantic::loop_continuer{});
    return break_scope_kind::loop;
}

declaration_visitor::result_type declaration_visitor::operator()(break_statement const&) const
{
    // to do: check the existance of enclisong loop (or switch)
    //THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor break_statement_t");
    ctx.append_expression(semantic::loop_breaker{});
    return break_scope_kind::loop;
}

declaration_visitor::result_type declaration_visitor::operator()(yield_statement const& yst) const
{
    (void)yst;
    THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor yield_statement");
#if 0
    semantic::managed_expression_list el{ env() };
    expected_result_t exp{ .type = ctx.result_type, .location = yst.location };

    auto res = base_expression_visitor::visit(ctx, el, exp, yst.expression);
    if (!res) return std::unexpected(std::move(res.error()));
    syntax_expression_result& er = res->first;
    
    ctx.push_chain();
    size_t scope_sz = ctx.append_result(el, er);
    auto return_expressions = ctx.expressions();
    ctx.pop_chain();
    ctx.append_yield(return_expressions, scope_sz, er.value_or_type, er.is_const_result);

    return break_scope_kind::none;
#endif
}

// extern function declaration
declaration_visitor::result_type declaration_visitor::operator()(fn_pure const& /*fd*/) const
{
    THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor fn_pure");
#if 0
    shared_ptr<functional_entity> fe;
    function_signature& sig = append_fnsig(fd, fe);
    auto fnm = ctx.env().qnregistry().concat(fe->name(), sig.mangled_id);
    if (!ctx.env().eregistry().find(fnm)) { // external is not registered, will be trying to bind in runtime
        // create the description for late binding
        auto fnent = sonia::make_shared<function_entity>(fnm, function_signature{ sig });
        fnent->set_inline();
        
        // signature
        int64_t sigval = (sig.parameters_count() + 1) * (fnent->is_void() ? -1 : 1);
        fnent->body.emplace_back(semantic::push_value{ mp::integer{ sigval }});
        // name
        small_string fnmangled = ctx.env().as_string(fnm);
        fnent->body.emplace_back(semantic::push_value{ fnmangled });
        // call itself
        fnent->body.emplace_back(ctx.env().get_builtin_function(unit::builtin_fn::extern_function_call));

        ctx.env().eregistry_insert(fnent);

        // for not inline calls
        fnent->set_index(ctx.allocate_local_variable_index());
        ctx.append_expression(semantic::push_value{ function_value{ fnm } });
        ctx.append_expression(semantic::set_variable{ fnent.get() });
    }
    /*
    function_signature& sig = append_fnsig(fd);
    if (fd.result) {
        preliminary_type_visitor tqvis{ ctx };
        sig.fn_type.result = apply_visitor(tqvis, *fd.result);
    } else { // if result type isn't defined => void
        sig.fn_type.result = annium_tuple_t{};
    }
    */
#endif
}

#if 0
function_entity & declaration_visitor::append_fnent(fn_pure& fnd, function_signature& sig, span<infunction_declaration_t> body) const
{
    THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor append_fnent");
#if 0
    fn_compiler_context fnctx{ ctx, fnd.name() / sig.mangled_id };
    if (fnd.result) {
        fnctx.result = sig.fn_type.result;
    } // if result type isn't defined => void or defined by body expressions
        
    // setup parameters
    boost::container::small_vector<variable_entity*, 16> params;
    size_t paramnum = 0;
    for (auto const& type : sig.position_parameters()) {
        variable_entity& ve = fnctx.new_position_parameter(paramnum, type);
        params.emplace_back(&ve);
        ++paramnum;
    }
    for (auto const&[aname, type] : sig.named_parameters()) {
        variable_entity& ve = fnctx.new_variable(aname.value, type, variable_entity::kind::LOCAL);
        params.emplace_back(&ve);
    }

    declaration_visitor dvis{ fnctx };
    for (infunction_declaration_t & d : body) {
        apply_visitor(dvis, d);
    }
    // here all captured variables (if exist) are allocated
    fnctx.finish_frame();

    // assign indexes to parameters & captured variables
    paramnum = 0;
    size_t paramcount = params.size() + fnctx.captured_variables.size();
    for (variable_entity * var : params) {
        var->set_index(static_cast<intptr_t>(paramnum) - paramcount);
        ++paramnum;
    }
    for (auto [from, tovar] : fnctx.captured_variables) {
        tovar->set_index(static_cast<intptr_t>(paramnum) - paramcount);
        ++paramnum;
    }
    sig.fn_type.result = fnctx.compute_result_type();

    qname_identifier fnqnid = ctx.env().qnregistry().resolve(fnctx.ns());
    auto fnent = sonia::make_shared<function_entity>(fnqnid, function_signature{sig});
    
    fnent->body = std::move(fnctx.expressions());
    fnent->captured_variables = std::move(fnctx.captured_variables);
    ctx.env().eregistry_insert(fnent);

    fnent->set_index(ctx.allocate_local_variable_index());

    // initialize variable
    ctx.append_expression(semantic::push_value { function_value{ fnent->name() } });
    ctx.append_expression(semantic::set_variable{ fnent.get() });
    return *fnent;
#endif
}
#endif

declaration_visitor::result_type declaration_visitor::operator()(typefn_decl const& fnd) const
{
    qname fn_qname = ctx.ns() / fnd.name;
    functional& fnl = env().resolve_functional(fn_qname);

    auto typefnptrn = make_shared<typefn_pattern>();
    error_storage err = typefnptrn->init(ctx, fnd);
    if (err) return std::unexpected(std::move(err));
    fnl.push(std::move(typefnptrn));
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(fn_decl const& fnd) const
{
    qname fn_qname = ctx.ns() / fnd.name;
    functional& fnl = env().resolve_functional(fn_qname);

    auto fnptrn = make_shared<internal_fn_pattern>();
    error_storage err = fnptrn->init(ctx, fnd);
    if (err) return std::unexpected(std::move(err));
    fnl.push(std::move(fnptrn));
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(enum_decl const& ed) const
{
    environment& env = ctx.env();
    functional& fnl = env.fregistry_resolve(ctx.ns() / ed.name.value);
    auto eent = make_shared<enum_entity>(env, fnl, ed.cases);
    env.eregistry_insert(eent);
    annotated_entity_identifier aeid{ eent->id, ed.name.location };
    fnl.set_default_entity(aeid);
    return break_scope_kind::none;
}

declaration_visitor::result_type declaration_visitor::operator()(struct_decl const& sd) const
{
    environment& env = ctx.env();
    annotated_qname fn_qname = { ctx.ns() / sd.name.value, sd.name.location };
    // to do: check the allowence of absolute qname
    
    functional& fnl = env.fregistry_resolve(fn_qname.value);
    if (sd.parameters.empty()) {
        // case: struct STRUCT_NAME => ( fields )
        auto sent = sonia::make_shared<struct_entity>(env, fnl, sd.body);
        env.eregistry_insert(sent);
        annotated_entity_identifier aeid{ sent->id, sd.name.location };
        fnl.set_default_entity(aeid);
    } else {
        // case: struct STRUCT_NAME(parameters) => ( fields )
        auto ptrn = sonia::make_shared<struct_fn_pattern>(sd.body);
        if (error_storage err = ptrn->init(ctx, fn_qname, sd.parameters); err) return std::unexpected(std::move(err));
        fnl.push(std::move(ptrn));
    }

    return break_scope_kind::none;

    //return apply_visitor(make_functional_visitor<error_storage>([this, &sd](auto const& v) {
    //    environment& e = ctx.env();
    //    if constexpr (std::is_same_v<annotated_qname const&, decltype(v)>) {
    //        // case: struct STRUCT_NAME => ( fields )
    //        annotated_qname const& qn = v;

    //        functional& fnl = e.fregistry_resolve(ctx.ns() / qn.value);
    //        auto sent = sonia::make_shared<struct_entity>(e, fnl, sd.body);
    //        e.eregistry_insert(sent);
    //        annotated_entity_identifier aeid{ sent->id, qn.location };
    //        fnl.set_default_entity(aeid);

    //        functional& init_fnl = e.fregistry_resolve(e.get(builtin_qnid::init));
    //        auto initptrn = sonia::make_shared<struct_init_pattern>(sd.body);
    //        if (error_storage err = initptrn->init(ctx, aeid); err) return err;
    //        init_fnl.push(std::move(initptrn));
    //    } else { // if constexpr (std::is_same_v<fn_pure const&, decltype(v)>) {
    //        // case: struct STRUCT_NAME(parameters) => ( fields )
    //        
    //        // to do: check the allowence of absolute qname
    //        fn_pure const& fn = v;
    //        qname fn_qname = ctx.ns() / fn.name();
    //        functional& fnl = e.fregistry_resolve(fn_qname);
    //        auto ptrn = sonia::make_shared<struct_fn_pattern>(sd.body);
    //        if (error_storage err = ptrn->init(ctx, fn); err) return err;
    //        fnl.push(std::move(ptrn));

    //        functional& init_fnl = e.fregistry_resolve(e.get(builtin_qnid::init));
    //        auto initptrn = sonia::make_shared<struct_init_pattern>(sd.body);
    //        if (error_storage err = initptrn->init(ctx, fn_qname, fn); err) return err;
    //        //if (error_storage err = initptrn->init(ctx, annotated_qname{ fn_qname, fn.location() }, fn.parameters); err) return err;
    //        init_fnl.push(std::move(initptrn));
    //    }
    //    return error_storage{};
    //}), sd.decl);
}

declaration_visitor::result_type declaration_visitor::operator()(let_statement const& ld) const
{
    semantic::managed_expression_list el{ env() };

    entity_identifier vartype;
    if (ld.type) {
        auto optvartype = base_expression_visitor::visit(ctx, el, expected_result_t{ .modifier = value_modifier_t::constexpr_value }, *ld.type);
        if (!optvartype) {
            return std::unexpected(std::move(optvartype.error()));
        }
        BOOST_ASSERT(!optvartype->first.expressions);
        vartype = optvartype->first.value();
    }

    small_vector<std::pair<identifier, syntax_expression_result>, 1> results;

    prepared_call pcall{ ctx, nullptr, {}, ld.location(), el };
    for (auto const& e : ld.expressions) {
        pcall.args.emplace_back(e);
    }
    if (auto err = pcall.prepare(); err) return std::unexpected(std::move(err));

    for (auto const& e : pcall.args) {
        auto [pname, expr] = *e;
        auto res = base_expression_visitor::visit(ctx, el, expected_result_t{ .type = vartype, .location = ld.location() }, expr);
        if (!res) { return std::unexpected(std::move(res.error())); }
        syntax_expression_result& ser = res->first;
        //if (ser.is_const_result && ser.value() == env().get(builtin_eid::void_)) continue; // ignore void results
        identifier name = pname ? pname->value : identifier{};
        results.emplace_back(name, std::move(ser));
    }

    //auto push_temporaries = [&el, this](auto& temporaries) {
    //    for (auto& [var, sp] : temporaries) {
    //        if (!sp) {
    //            semantic::expression_span reserve_expression;
    //            env().push_back_expression(el, reserve_expression, semantic::push_value{ smart_blob{} });
    //            ctx.append_expressions(el, reserve_expression);
    //        } else {
    //            ctx.append_expressions(el, sp);
    //        }
    //        ctx.push_scope_variable(var);
    //    }
    //};

    if (results.size() == 1) {
        auto& [id, er] = results.front();
        basic_signatured_entity const* pelemsig = nullptr;
        if (id) {
            entity_signature element_sig{ env().get(builtin_qnid::tuple), env().get(builtin_eid::typename_) };
            element_sig.emplace_back(id, er.value_or_type, er.is_const_result);
            pelemsig = &env().make_basic_signatured_entity(std::move(element_sig));
        }
        if (er.is_const_result) {
            ctx.push_scope_constant(ld.aname, pelemsig ? pelemsig->id : er.value());
        } else {
            if (pelemsig) er.value_or_type = pelemsig->id;
            ctx.append_result(el, er, ld.aname);
            /*
            ctx.push_scope();
            push_temporaries(er.temporaries);
            ctx.append_expressions(el, er.expressions);
            ctx.append_stored_expressions(el, er.branches_expressions);
            size_t scope_sz = ctx.current_scope_binding().variables_count();
            ctx.pop_scope();
            ctx.push_scope_variable(
                ld.aname,
                local_variable{ .type = pelemsig ? pelemsig->id : er.type(), .varid = env().new_variable_identifier(), .is_weak = ld.weakness });
            if (scope_sz) {
                ctx.append_expression(semantic::truncate_values{ .count = (uint16_t)scope_sz, .keep_back = (uint16_t)(er.is_const_result ? 0 : 1u) });
            }
            */
        }
        return break_scope_kind::none;
    }

    entity_signature result_sig{ env().get(builtin_qnid::tuple), env().get(builtin_eid::typename_) };

    for (auto& [id, er] : results) {
        if (er.is_const_result) {
            result_sig.emplace_back(id, er.value(), true);
        } else {
            //ctx.push_scope();
            identifier unnamedid = env().new_identifier();
            ctx.append_result(el, er, annotated_identifier{ unnamedid });
            //push_temporaries(er.temporaries);
            //ctx.append_expressions(el, er.expressions);
            //ctx.append_stored_expressions(el, er.branches_expressions);
            //size_t scope_sz = ctx.current_scope_binding().variables_count();
            //ctx.pop_scope();
            //
            //ctx.push_scope_variable(
            //    annotated_identifier{ unnamedid },
            //    local_variable{ .type = er.type(), .varid = env().new_variable_identifier(), .is_weak = ld.weakness });
            //if (scope_sz) {
            //    ctx.append_expression(semantic::truncate_values{ .count = (uint16_t)scope_sz, .keep_back = (uint16_t)(er.is_const_result ? 0 : 1u) });
            //}
            result_sig.emplace_back(id, env().make_qname_entity(qname{ unnamedid, false }).id, true);
        }
    }
    entity const& result_tuple_type = env().make_basic_signatured_entity(std::move(result_sig));
    ctx.push_scope_constant(ld.aname, env().make_empty_entity(result_tuple_type.id).id);
    return break_scope_kind::none;
#if 0

    if (results.size() == 1) {
        auto& [id, er] = results.front();
        

        size_t scope_sz;
        if (!er.is_const_result) {
            ctx.push_scope();
            push_temporaries(er.temporaries);
            ctx.append_expressions(el, er.expressions);
            ctx.append_stored_expressions(el, er.branches_expressions);
            scope_sz = ctx.current_scope_binding().size();
            ctx.pop_scope();
        }

        if (vartype) {
            pure_call cast_call{ ld.location() };
            if (er.is_const_result) {
                cast_call.emplace_back(annotated_entity_identifier{ er.value(), ld.location() });
            } else {
                semantic::managed_expression_list mel{ e };
                mel.deep_copy(er.expressions);
                cast_call.emplace_back(indirect_value{
                    .location = ld.location(),
                    .type = er.type(),
                    .store = indirect_value_store_t{ in_place_type<semantic::indirect_expression_list>, std::move(mel) }
                });
            }
            auto match = ctx.find(builtin_qnid::eq, cast_call, el, expected_result_t{ vartype, er.is_const_result });
            if (!match) return std::move(match.error());
            auto res = match->apply(ctx);
            if (!res) return std::move(res.error());
            syntax_expression_result& fer = *res;
            if (fer.is_const_result) {
                ctx.new_constant(ld.aname, fer.value());
            } else {
                ctx.push_scope_variable(
                    ld.aname,
                    local_variable{ .type = vartype, .varid = env().new_variable_identifier(), .is_weak = ld.weakness },
                    fnent);
            }
        } else if (er.is_const_result) {
            ctx.new_constant(ld.aname, er.value());
        } else {
            ctx.push_scope_variable(
                ld.aname,
                local_variable{ .type = er.type(), .varid = env().new_variable_identifier(), .is_weak = ld.weakness },
                fnent);
        }
    }


    if (results.size() == 1 && !results.front().first) {
        syntax_expression_result& er = results.front().second;
        ctx.push_scope();
        push_temporaries(er.temporaries);
        ctx.append_expressions(el, er.expressions);
        ctx.append_stored_expressions(el, er.branches_expressions);

        auto scope_sz = ctx.current_scope_binding().size();
        ctx.pop_scope();

        if (er.is_const_result) {
            ctx.new_constant(ld.aname, er.value());
        } else {
            ctx.push_scope_variable(
                ld.aname,
                local_variable{ .type = er.type(), .varid = env().new_variable_identifier(), .is_weak = ld.weakness },
                fnent);
        }
        if (scope_sz) {
            ctx.append_expression(semantic::truncate_values(scope_sz, !er.is_const_result));
        }
        return break_scope_kind::none;
    }

    //small_vector<std::tuple<variable_identifier, entity_identifier, semantic::expression_span>, 2> temporaries;
    // we will return empty_entity with the tuple type
    // now build the type
    boost::container::small_flat_multimap<identifier, entity_identifier, 8> field_map;
    entity_signature sig{ env().get(builtin_qnid::tuple), env().get(builtin_eid::typename_) };
    for (auto & [id, er] : results) {
        ctx.push_scope();
        push_temporaries(er.temporaries);
        ctx.append_expressions(el, er.expressions);
        ctx.append_stored_expressions(el, er.branches_expressions);
        auto scope_sz = ctx.current_scope_binding().size();
        ctx.pop_scope();
        entity_identifier field_eid;
        if (er.is_const_result) {
            field_eid = er.value();
        } else {
            identifier unnamedid = env().new_identifier();
            ctx.push_scope_variable(
                annotated_identifier{ unnamedid },
                local_variable{ .type = er.type(), .varid = env().new_variable_identifier(), .is_weak = ld.weakness },
                fnent);
            field_eid = env().make_qname_entity(qname{ unnamedid, false }).id;
        }
        if (scope_sz) {
            ctx.append_expression(semantic::truncate_values(scope_sz, !er.is_const_result));
        }
            
        if (id) {
            field_map.emplace(id, field_eid);
        } else {
            sig.push_back(field_descriptor{ field_eid, true });
        }
    }
    // for each key in small_flat_multimap
    for (auto it = field_map.begin(); it != field_map.end();) {
        identifier name = it->first;
        auto range = field_map.equal_range(it->first);
        if (std::next(range.first) == range.second) {
            sig.emplace_back(name, it->second, true);
            ++it;
        } else {
            BOOST_ASSERT(it == range.first);
            entity_signature innersig{ env().get(builtin_qnid::tuple), env().get(builtin_eid::typename_) };
            for (; it != range.second; ++it) {
                innersig.emplace_back(it->second, true);
            }
            indirect_signatured_entity innersmpl{ innersig };
            entity const& const_inner_type = env().eregistry_find_or_create(innersmpl, [&innersig]() {
                return make_shared<basic_signatured_entity>(std::move(innersig));
            });
            sig.emplace_back(name, env().make_empty_entity(const_inner_type), true);
        }
    }
    entity const& tuple_type = env().make_basic_signatured_entity(std::move(sig));
    ctx.new_constant(ld.aname, env().make_empty_entity(tuple_type).id);
    return break_scope_kind::none;
#endif
}

//void declaration_visitor::operator()(assign_decl_t const& ad) const
//{
//    lvalue_expression_visitor lvis{ ctx };
//    auto e = apply_visitor(lvis, ad.lvalue);
//    if (!e.has_value()) throw exception(ctx.env().print(*e.error()));
//    
//    if (variable_entity const* ve = dynamic_cast<variable_entity const*>(e.value()); ve) {
//        auto opterr = base_expression_visitor::visit(ctx, { ve->get_type(), ad.location }, ad.rvalue);
//        if (ve->is_weak()) {
//            THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor assign_decl_t");
//            //ctx.append_expression(semantic::invoke_function{ ctx.env().get_builtin_function(unit::builtin_fn::weak_create) });
//        }
//        ctx.append_expression(semantic::set_variable{ ve });
//        if (ve->is_weak()) {
//            ctx.append_expression(semantic::truncate_values(1, false));
//        }
//        return std::move(opterr);
//    } else {
//        const entity* pe = e.value();
//        THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor assign_decl_t");
//    }
//}

declaration_visitor::result_type declaration_visitor::operator()(return_statement const& rd) const
{
    error_storage err;
    if (rd.expression) {
        err = ctx.append_return(*rd.expression);
    } else {
        syntax_expression void_expr{ .location = rd.location, .value = env().get(builtin_eid::void_) };
        err = ctx.append_return(void_expr);
    }
    if (err) return std::unexpected(std::move(err));
    return break_scope_kind::function;
#if 0
        semantic::managed_expression_list el{ env() };
        expected_result_t exp { };
        if (ctx.result_value_or_type) {
            exp.type = ctx.result_value_or_type;
            exp.modifier = ctx.is_const_value_result ? value_modifier_t::constexpr_value : value_modifier_t::runtime_value;
            exp.location = rd.expression->location;
        }
        
        auto res = base_expression_visitor::visit(ctx, el, exp, *rd.expression);
        if (!res) return std::move(res.error());
        syntax_expression_result& er = res->first;

        ctx.append_return(rd.expression->location, std::move(er));

        //ctx.push_chain();
        //size_t scope_sz = ctx.append_result(el, er);
        //auto return_expressions = ctx.expressions();
        //ctx.pop_chain();
        //ctx.append_return(rd.expression->location, return_expressions, scope_sz, er.value_or_type, er.is_const_result);
    } else {
        ctx.append_return(rd.location, syntax_expression_result{ .value_or_type = env().get(builtin_eid::void_), .is_const_result = true });
        //ctx.append_return(rd.location, {}, 0, env().get(builtin_eid::void_), true);
    }
    
    return break_scope_kind::none;
#endif
}

}
