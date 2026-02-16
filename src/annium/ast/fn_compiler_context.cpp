//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "fn_compiler_context.hpp"

#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/range/adaptor/reversed.hpp>

#include "annium/functional/functional.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"

#include "annium/ast/base_expression_visitor.hpp"

#include "annium/errors/identifier_redefinition_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

namespace {

bool has_procedures(semantic::expression_span span);

struct procedures_lookup_visitor
{
    bool operator()(semantic::expression_span nested) const
    {
        return has_procedures(nested);
    }

    bool operator()(semantic::return_statement const& rst) const noexcept
    { 
        return has_procedures(rst.scope_deconstruction);
    }

    bool operator()(semantic::conditional_t const& cond) const
    {
        return has_procedures(cond.true_branch) || has_procedures(cond.false_branch);
    }

    bool operator()(semantic::switch_t const& sw) const
    {
        for (auto const& branch : sw.branches) {
            if (has_procedures(branch)) return true;
        }
        return false;
    }

    bool operator()(semantic::not_empty_condition_t const& nec) const
    {
        return has_procedures(nec.branch);
    }

    bool operator()(semantic::loop_scope_t const& loop) const
    {
        return has_procedures(loop.branch) || has_procedures(loop.continue_branch);
    }

    bool operator()(semantic::invoke_function const& ifn) const
    {
        (void)ifn;
        return true;
    }

    template <typename T>
    bool operator()(T const& t) const noexcept
    {
        (void)t;
        return false;
    }
};

bool has_procedures(semantic::expression_span span)
{
    while (span) {
        if (visit(procedures_lookup_visitor{}, span.front())) {
            return true;
        }
        span.pop_front();
    }
    return false;
}

} // namespace

#if 0
struct parameter_pack_element_type_visitor : static_visitor<std::expected<pattern_expression_t, error_storage>>
{
    fn_compiler_context& ctx;
    syntax_expression const& element_type_expression_;

    explicit parameter_pack_element_type_visitor(fn_compiler_context& c, syntax_expression const& et)
        : ctx{ c }
        , element_type_expression_{ et }
    {}

    inline environment& env() const noexcept { return ctx.env(); }

    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("parameter_pack_element_type_visitor not implemented expression");
    }

    result_type operator()(annotated_qname_identifier const& aqi)
    {
        functional const& fnl = ctx.env().fregistry().resolve(aqi.value);
        entity_identifier element_type = fnl.default_entity();
        if (!element_type) {
            return std::unexpected(make_error<basic_general_error>(
                aqi.location, //get_start_location(element_type_expression_),
                "identifier is not a type"sv));
        }
        return this->operator()(element_type);
    }

    result_type operator()(entity_identifier eid)
    {
        functional& ellipsis_fnl = env().fregistry().resolve(env().get_ellipsis_qname_identifier());
        named_expression_list_t ellipsis_args;
        ellipsis_args.emplace_back(annotated_entity_identifier{ eid });
        pure_call ellipsis_call{ resource_location{}, std::move(ellipsis_args) };
        functional::match_descriptor md;
        auto ptrn = ellipsis_fnl.find(ctx, ellipsis_call, {}, md);
        if (!ptrn.has_value()) {
            return std::unexpected(std::move(ptrn.error()));
        }
        auto r = ptrn.value()->const_apply(ctx, md);
        if (!r.has_value()) {
            return std::unexpected(std::move(r.error()));
        }
        return r.value();
    }
};

struct parameter_visitor : static_visitor<std::expected<pattern_expression_t, error_storage>>
{
    fn_compiler_context& ctx;
    function_descriptor& fd_;
    explicit parameter_visitor(fn_compiler_context& c, function_descriptor& fd)
        : ctx{ c }, fd_{ fd }
    {}

    inline environment& env() const noexcept { return ctx.env(); }

    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("parameter_visitor not implemented expression");
    }

    result_type operator()(annotated_entity_identifier const& ee)
    {
        return ee.value;
    }

    result_type operator()(qname_reference const& var)
    {
        if (var.implicit || (var.name.value.is_relative() && var.name.value.size() == 1)) {
            // check for function parameter
            identifier varid = *var.name.value.begin();
            if (auto it = fd_.varparams().find(varid); it != fd_.varparams().end()) {
                return pattern_variable{ varid };
            }
        }

        functional const* f = ctx.lookup_functional(var.name.value);
        if (f) return annotated_qname_identifier{ f->id(), var.name.location };
        
        if (var.name.value.is_absolute() || !var.implicit || var.name.value.size() != 1) {
            return std::unexpected(make_error<undeclared_identifier_error>(var.name));
        }
        identifier varid = *var.name.value.begin();
        //GLOBAL_LOG_INFO() << env().print(varid);
        fd_.variables().insert(varid);
        return pattern_variable{ varid };
    }

    result_type operator()(annium_parameter_pack_t const& ppack)
    {
        result_type elem = apply_visitor(*this, ppack.type);
        if (!elem.has_value()) return std::unexpected(std::move(elem.error()));

        parameter_pack_element_type_visitor vis{ ctx, ppack.type };
        return apply_visitor(vis, elem.value());

        //functional const** pptypevar = get<functional const*>(&elem.value());
        //if (pptypevar) {
        //    entity_identifier element_type = (*pptypevar)->default_entity();
        //    if (!element_type) {
        //        return std::unexpected(make_error<basic_general_error>(get_start_location(ppack.type),
        //            ("identifier is not a type, see declaration at %1%"_fmt % env().print((*pptypevar)->location())).str()));
        //    }
        //    functional& ellipsis_fnl = env().fregistry().resolve(env().get_ellipsis_qname_identifier());
        //    named_expression_term_list_t ellipsis_args;
        //    ellipsis_args.emplace_back(entity_expression{ element_type, });
        //    pure_call ellipsis_call{ resource_location{}, std::move(ellipsis_args) };
        //    auto ptrn = ellipsis_fnl.find(ctx, ellipsis_call);
        //    if (!ptrn.has_value()) {
        //        return std::unexpected(std::move(ptrn.error()));
        //    }
        //    auto r = ptrn.value()->const_apply(ctx);
        //    if (!r.has_value()) {
        //        return std::unexpected(std::move(r.error()));
        //    }
        //    return r.value();
        //}
    }
};
#endif

//std::expected<int, error_storage> fn_compiler_context::build_fieldset(fn_pure const& pure_decl, patern_fieldset_t& fs)
//{
////    THROW_NOT_IMPLEMENTED_ERROR("function_descriptor::build_fieldset");
//    
//    auto& params = pure_decl.parameters;
//    std::vector<function_descriptor::named_field> nfields;
//    std::vector<function_descriptor::positioned_field> pfields;
//    boost::container::small_vector<pattern_expression_t, 1> temp_constraint_patterns;
//
//    boost::container::small_vector<annotated_identifier, 16> aux;
//    aux.reserve(params.size());
//
//    parameter_visitor pvis{ *this };
//    for (auto& param : params) {
//        temp_constraint_patterns.clear();
//        parameter_constraint_list_t const& constraints = param.constraints;
//        for (syntax_expression const& expr : param.constraints) {
//            auto res = apply_visitor(pvis, expr);
//            if (!res.has_value()) return std::unexpected(std::move(res.error()));
//            temp_constraint_patterns.emplace_back(res.value());
//        }
//        //bool constraint_is_typename = constraint_entity.is(*this, environment_.get_typename_entity_identifier());
//        //param_constraint_type ct = constraint_is_typename ?
//        //    (parampair.type.is_const ? param_constraint_type::const_constraint : param_constraint_type::type_constaint)
//        //    : param_constraint_type::value_constaint;
//        param_constraint_type ct = param_constraint_type::value_type_constaint; // to do: resolve constraint type
//
//        if (param.name.external_name) {
//            aux.push_back(*param.name.external_name);
//            nfields.emplace_back(
//                *param.name.external_name,
//                param.name.internal_name,
//                std::move(temp_constraint_patterns),
//                ct);
//        } else {
//            pfields.emplace_back(
//                param.name.internal_name,
//                std::move(temp_constraint_patterns),
//                ct);
//        }
//    }
//
//    // check for name duplicates
//    std::stable_sort(aux.begin(), aux.end(), [](auto const& l, auto const& r) {
//        return l.value < r.value;
//        //return l.ename && (!r.ename || l.ename->value < r.ename->value);wa
//    });
//    auto it = std::unique(aux.begin(), aux.end(), [](auto const& l, auto const& r) {
//        return l.value == r.value;
//    });
//    if (it != aux.end()) {
//        return std::unexpected(make_error<basic_general_error>(it->location, "duplicate parameter name"sv));
//    }
//
//    std::sort(nfields.begin(), nfields.end(), [](auto const& l, auto const& r) {
//        return l.ename.value < r.ename.value;
//        //return l.ename && (!r.ename || l.ename->value < r.ename->value);wa
//    });
//
//    fs.set_nfields(std::move(nfields));
//    fs.set_pfields(std::move(pfields));
//
//    return 0;
//}

fn_compiler_context::fn_compiler_context(environment& e, internal_function_entity& fent)
    : environment_{ e }
    , fent_{ &fent }
    , ns_{ fent.name() }
    , expression_store_{ e }
{
    init();
}

fn_compiler_context::fn_compiler_context(environment& e, qname ns_val)
    : environment_{ e }
    , fent_{ nullptr }
    , ns_{ std::move(ns_val) }
    , expression_store_{ e }
{
    init();
}

void fn_compiler_context::init()
{
    assert(ns_.is_absolute());
    base_ns_size_ = ns_.parts().size();
    expr_stack_.emplace_back();
    scope_states_.emplace_back(0, 0); // initial scope before captures and arguments
    scope_states_.emplace_back(0, 0); // captures and arguments scope
}

fn_compiler_context::~fn_compiler_context()
{
    // move expressions to remove
    //expression_store_.splice_back(root_expressions_);
}

optional<std::variant<entity_identifier, local_variable>> fn_compiler_context::get_bound(identifier name) const noexcept
{
    // then look for bound entities
    for (functional_binding const* binding : boost::adaptors::reverse(bindings_)) {
        if (auto optval = binding->lookup(name); optval) {
            return *optval;
            //if (entity_identifier const* eid = get<entity_identifier>(optval); eid) return *eid;
            //if (local_variable const* lv = get<local_variable>(optval); lv) return *lv;
        }
    }
    for (auto const& scope_locals_stack_item : boost::adaptors::reverse(scoped_locals_)) {
        if (scope_locals_stack_item.name.value == name) {
            return scope_locals_stack_item.value;
        }
    }
    //for (auto const& scope_descriptor : boost::adaptors::reverse(scoped_locals_)) {
    //    if (auto optval = scope_descriptor.named_set.lookup(name); optval) {
    //        if (entity_identifier const* eid = get_if<entity_identifier>(optval); eid) return *eid;
    //        if (local_variable const* lv = get_if<local_variable>(optval); lv) return *lv;
    //    }
    //}

    return nullopt;
}

sonia::lang::compiler_task_tracer::task_guard fn_compiler_context::try_lock_task(sonia::lang::compiler_task_id const& tid)
{
    return environment_.task_tracer().try_lock_task(tid, worker_id_);
}

void fn_compiler_context::append_variables(semantic::expression_list_t& el, span<const std::tuple<local_variable, semantic::expression_span>> vars)
{
    for (auto& [var, sp] : vars) {
        if (!sp) {
            semantic::expression_span reserve_expression;
            env().push_back_expression(el, reserve_expression, semantic::push_value{ smart_blob{} });
            append_expressions(el, reserve_expression);
        } else {
            append_expressions(el, sp);
        }
        push_scope_variable(var);
    }
}

void fn_compiler_context::append_result_inplace(semantic::expression_list_t& el, syntax_expression_result& er, annotated_identifier name)
{
    append_stored_expressions(el, er.branches_expressions);
    append_variables(el, er.temporaries);
    append_expressions(el, er.expressions);

    if (!er.is_const_result) { // er.type() != env().get(builtin_eid::void_type)
        push_scope_variable(name, er.type());
    } else if (name) {
        push_scope_constant(std::move(name), er.value());
    }
}

void fn_compiler_context::append_result(semantic::expression_list_t& el, syntax_expression_result& er, annotated_identifier name)
{
    if (!er.temporaries.empty()) push_scope();
    append_result_inplace(el, er, annotated_identifier{});
    if (!er.temporaries.empty()) pop_scope(!er.is_const_result);
    if (!er.is_const_result && name) {
        scoped_locals_.back().name = std::move(name);
        local_variable& lv = get<local_variable>(scoped_locals_.back().value);
        BOOST_ASSERT(!lv.varid);
        lv.varid = environment_.new_variable_identifier();
        BOOST_ASSERT(fent_);
        fent_->push_variable(lv.varid, scope_states_.back().next_variable_index - 1);
    }

    //if (er.temporaries.empty()) {
    //    append_result_inplace(el, er, std::move(name));
    //} else {
    //    push_scope();
    //    append_stored_expressions(el, er.branches_expressions);
    //    append_variables(el, er.temporaries);
    //    append_expressions(el, er.expressions);
    //    pop_scope(!er.is_const_result);
    //    if (!er.is_const_result) { // er.type() != env().get(builtin_eid::void_type)
    //        push_scope_variable(name, er.type());
    //    } else if (name) {
    //        push_scope_constant(std::move(name), er.value());
    //    }
    //}
}

void fn_compiler_context::push_scopes_to_stash()
{
    stash_state so{
        .locals_size = static_cast<uint32_t>(scoped_locals_.size()),
        .states_size = static_cast<uint32_t>(scope_states_.size())
    };
    stash_states_.push_back(so);
    scoped_locals_stash_.insert(scoped_locals_stash_.end(), scoped_locals_.begin(), scoped_locals_.end());
    scope_states_stash_.insert(scope_states_stash_.end(), scope_states_.begin(), scope_states_.end());
}

void fn_compiler_context::pop_scopes_from_stash()
{
    BOOST_ASSERT(!stash_states_.empty());
    stash_state so = stash_states_.back();
    stash_states_.pop_back();
    scoped_locals_.clear();
    scoped_locals_.insert(scoped_locals_.end(),
        scoped_locals_stash_.end() - so.locals_size,
        scoped_locals_stash_.end());
    scoped_locals_stash_.resize(scoped_locals_stash_.size() - so.locals_size);
    scope_states_.clear();
    scope_states_.insert(scope_states_.end(),
        scope_states_stash_.end() - so.states_size,
        scope_states_stash_.end());
    scope_states_stash_.resize(scope_states_stash_.size() - so.states_size);
}

void fn_compiler_context::peek_scopes_from_stash()
{
    BOOST_ASSERT(!stash_states_.empty());
    stash_state so = stash_states_.back();
    scoped_locals_.clear();
    scoped_locals_.insert(scoped_locals_.end(),
        scoped_locals_stash_.end() - so.locals_size,
        scoped_locals_stash_.end());
    scope_states_.clear();
    scope_states_.insert(scope_states_.end(),
        scope_states_stash_.end() - so.states_size,
        scope_states_stash_.end());
}

void fn_compiler_context::pop_dismiss_scopes_from_stash()
{
    BOOST_ASSERT(!stash_states_.empty());
    stash_state so = stash_states_.back();
    stash_states_.pop_back();
    scoped_locals_stash_.resize(scoped_locals_stash_.size() - so.locals_size);
    scope_states_stash_.resize(scope_states_stash_.size() - so.states_size);
}

void fn_compiler_context::push_scope()
{
    ns_ = ns_ / environment_.new_identifier();
    scope_states_.emplace_back(static_cast<uint32_t>(scoped_locals_.size()), scope_states_.back().next_variable_index);
    //scope_offset_ += scoped_locals_.back().total_variables_count();
    //scoped_locals_.emplace_back();
}

void fn_compiler_context::pop_scope(bool move_top_to_parent)
{
    pop_scope(expression_store_, expressions(), move_top_to_parent);
}

void fn_compiler_context::pop_scope(semantic::expression_list_t& el, semantic::expression_span& rout, bool move_top_to_parent)
{
    if (!ns_.parts().empty()) {
        //assert(ns_.parts().size() > base_ns_size_);
        ns_.truncate(ns_.parts().size() - 1);
    }

    auto [scope_offset, upper_variable_index] = scope_states_.back();
    scope_states_.pop_back();
    
    uint32_t local_index_threshold_to_remove = static_cast<uint32_t>(scoped_locals_.size());
    auto lit = scoped_locals_.end();
    int32_t skipped_top_variable_index = move_top_to_parent ? -1 : -2;
    //local_variable* moving_var = nullptr;
    while (local_index_threshold_to_remove > scope_offset) {
        --lit;
        --local_index_threshold_to_remove;
        local_variable * lv = get_if<local_variable>(&lit->value);
        if (lv) {
            if (skipped_top_variable_index == -1) {
                //moving_var = lv;
                skipped_top_variable_index = static_cast<int32_t>(local_index_threshold_to_remove);
                BOOST_ASSERT(!lit->name); // to ensure we're moving unnamed variable
                BOOST_ASSERT(!lv->varid); // to ensure we're moving unbound variable
            } else {
                // to do: call destructor for local variables    
            }
        }
    }
    BOOST_ASSERT(!scope_states_.empty());
    uint32_t variables_to_clear = upper_variable_index - scope_states_.back().next_variable_index;
    if (move_top_to_parent) {
        BOOST_ASSERT(skipped_top_variable_index >= 0); // to ensure we've found the top variable to skip
        --variables_to_clear;
        //++scope_states_.back().next_variable_index; // update upper variable index for parent scope to account for moved variable
    }
    if (variables_to_clear) {
        env().push_back_expression(el, rout,
            semantic::truncate_values{
                .count = static_cast<uint16_t>(variables_to_clear),
                .keep_back = static_cast<uint16_t>(move_top_to_parent ? 1u : 0u)
            });
    }
    if (skipped_top_variable_index >= 0) {
        if (skipped_top_variable_index != static_cast<int32_t>(scope_offset)) {
            scoped_locals_[scope_offset] = scoped_locals_[skipped_top_variable_index];
        }
        ++scope_states_.back().next_variable_index; // update upper variable index for parent scope to account for moved variable
        /*
        BOOST_ASSERT(moving_var);
        variable_identifier varid = environment_.new_variable_identifier();
        scoped_locals_[scope_offset] = scope_locals_stack_item{
            .name = {},
            .value = local_variable{ .type = moving_var->type, .varid = varid, .is_weak = moving_var->is_weak }
        };
        fent_.push_variable(varid, scope_states_.back().next_variable_index++);
        */
    }
    scoped_locals_.resize(scope_offset + (move_top_to_parent ? 1 : 0));
}

void fn_compiler_context::pop_all_scopes(semantic::expression_list_t& el, semantic::expression_span& rout, bool move_top_to_parent)
{
    while (scope_states_.size() > 1) {
        pop_scope(el, rout, move_top_to_parent);
    }
}

void fn_compiler_context::push_scope_variable(annotated_identifier name, local_variable var)
{
    variable_identifier varid = var.varid;
    BOOST_ASSERT(varid);
    if (name) {
        check_scope_name_conflict(name);
    }
    scoped_locals_.emplace_back(std::move(name), std::move(var));
    uint32_t& next_variable_index = scope_states_.back().next_variable_index;
    if (fent_) fent_->push_variable(varid, next_variable_index);
    ++next_variable_index;
}

void fn_compiler_context::push_scope_variable(local_variable var)
{
    variable_identifier varid = var.varid;
    BOOST_ASSERT(varid);
    scoped_locals_.emplace_back(annotated_identifier{}, std::move(var));
    uint32_t& next_variable_index = scope_states_.back().next_variable_index;
    if (fent_) fent_->push_variable(varid, next_variable_index);
    ++next_variable_index;
}

void fn_compiler_context::push_scope_variable(entity_identifier vartype)
{
    variable_identifier varid = environment_.new_variable_identifier();
    scoped_locals_.emplace_back(annotated_identifier{}, local_variable{ .type = std::move(vartype), .varid = varid, .is_weak = false });
    uint32_t& next_variable_index = scope_states_.back().next_variable_index;
    if (fent_) fent_->push_variable(varid, next_variable_index);
    ++next_variable_index;

    //scoped_locals_.emplace_back(annotated_identifier{}, std::move(lv));
    //uint32_t& next_variable_index = scope_states_.back().next_variable_index;
    //fent_.push_variable(lv.varid, scope_offset_ + next_variable_index);
    //++next_variable_index;
    
    //int64_t index = scope_offset_ + scoped_locals_.back().total_variables_count();
    //fent_.push_variable(lv.varid, index);
    //++scoped_locals_.back().unnamed_count;
}

void fn_compiler_context::check_scope_name_conflict(annotated_identifier const& name) const
{
    auto& current_scope_state = scope_states_.back();
    for (size_t i = current_scope_state.offset; i < scoped_locals_.size(); ++i) {
        if (scoped_locals_[i].name.value == name.value) {
            throw identifier_redefinition_error(name, scoped_locals_[i].name.location);
        }
    }
}

void fn_compiler_context::pop_scope_variable()
{
    // it's allowed to pop only boolean variables, because they are used for control flow and don't require destructor calls, so we can guarantee that the top variable is the one we want to pop without additional checks
    BOOST_ASSERT(!scoped_locals_.empty());
    BOOST_ASSERT(std::holds_alternative<local_variable>(scoped_locals_.back().value));
    BOOST_ASSERT(std::get<local_variable>(scoped_locals_.back().value).type == env().get(builtin_eid::boolean));
    scoped_locals_.pop_back();
    --scope_states_.back().next_variable_index;
}

void fn_compiler_context::push_scope_variable(annotated_identifier name, entity_identifier type)
{
    variable_identifier varid;
    if (name) {
        check_scope_name_conflict(name);
        varid = environment_.new_variable_identifier();
    }
    scoped_locals_.emplace_back(std::move(name), local_variable{ .type = std::move(type), .varid = varid, .is_weak = false });
    uint32_t& next_variable_index = scope_states_.back().next_variable_index;
    if (varid && fent_) fent_->push_variable(varid, next_variable_index);
    ++next_variable_index;
}

void fn_compiler_context::push_chain()
{
    expr_stack_.emplace_back();
}

void fn_compiler_context::pop_chain()
{
    semantic::expression_span exprs = branches_expressions();
    expr_stack_.pop_back();
    branches_expressions() = expression_store_.concat(branches_expressions(), std::move(exprs));
}

#if 0
error_storage fn_compiler_context::build_function_descriptor(fn_pure const& pure_decl, function_descriptor& fd)
{
    THROW_NOT_IMPLEMENTED_ERROR("fn_compiler_context::build_function_descriptor");
#if 0
    qname fn_qname = ns() / pure_decl.name();

    //if (!fn_qname.has_prefix(ns())) {
    //    return std::unexpected(make_error<basic_general_error>(pure_decl.location(), "not a nested scope identifier"sv, (qname)pure_decl.name()));
    //}

    functional& fnl = env().fregistry().resolve(fn_qname);
    qname_identifier fn_qname_id_ = fnl.id();
    fd.set_id(fn_qname_id_);
    
    auto& params = pure_decl.parameters;
    std::vector<function_descriptor::named_field> nfields;
    std::vector<function_descriptor::positioned_field> pfields;

    // get function parameter ids

    auto put_var = [&fd](annotated_identifier const& aid) -> error_storage {
        if (auto pair = fd.varparams().insert(aid.value); !pair.second) {
            return make_error<basic_general_error>(aid.location, "duplicate parameter name"sv, aid.value);
        }
        return {};
    };

    boost::container::small_flat_map<identifier, resource_location, 16> aux;
    auto check_name = [&aux](annotated_identifier const& aid) -> error_storage {
        if (auto pair = aux.insert(std::pair{ aid.value, aid.location }); !pair.second) {
            return make_error<general_with_see_location_error>(aid.location, "duplicate parameter name"sv, pair.first->second, aid.value);
        }
        return {};
    };

    for (auto& param : params) {
        auto [external_name, internal_name, varname] = apply_visitor(param_name_retriever{}, param.name);
        
        if (param.modifier == parameter_constraint_modifier_t::typename_constraint || param.modifier == parameter_constraint_modifier_t::value_constraint) {
            if (internal_name) {
                if (auto err = put_var(*internal_name); err) { return err; }
            } else if (external_name) {
                if (auto err = put_var(*external_name); err) { return err; }
            }
        }
        if (external_name) {
            if (auto err = check_name(*external_name); err) { return err; }
        }
        if (internal_name) {
            if (auto err = check_name(*internal_name); err) { return err; }
        }
    }

    fn_compiler_context fnctx{ env(), fn_qname };
    parameter_visitor pvis{ fnctx, fd };

    for (auto& param : params) {
        auto [external_name, internal_name, varname] = apply_visitor(param_name_retriever{}, param.name);

        function_descriptor::generic_field fld;
        parameter_constraint_set_t const& constraints = param.constraints;
        if (constraints.type_expression) {
            auto res = apply_visitor(pvis, *constraints.type_expression);
            if (!res.has_value()) return std::move(res.error());
            fld.constraint = res.value();
        }
        for (syntax_expression const& ce : constraints.concepts) {
            auto res = apply_visitor(pvis, ce);
            if (!res.has_value()) return std::move(res.error());
            fld.concepts.emplace_back(res.value());
        }
        fld.bindings.reserve(constraints.bindings.size());
        std::ranges::copy(constraints.bindings, std::back_inserter(fld.bindings));
        fld.constraint_type = param.modifier;
        if (internal_name) fld.iname = *internal_name;
        //bool constraint_is_typename = constraint_entity.is(*this, environment_.get_typename_entity_identifier());
        //param_constraint_type ct = constraint_is_typename ?
        //    (parampair.type.is_const ? param_constraint_type::const_constraint : param_constraint_type::type_constaint)
        //    : param_constraint_type::value_constaint;

        if (external_name) {
            nfields.emplace_back(*external_name, std::move(fld));
        } else {
            pfields.emplace_back(std::move(fld));
        }
    }

    std::sort(nfields.begin(), nfields.end(), [](auto const& l, auto const& r) {
        return l.ename.value < r.ename.value;
        //return l.ename && (!r.ename || l.ename->value < r.ename->value);wa
    });

    fd.set_nfields(std::move(nfields));
    fd.set_pfields(std::move(pfields));


    if (pure_decl.result) {
        auto rtres = apply_visitor(pvis, *pure_decl.result);
        if (!rtres.has_value()) return std::move(rtres.error());
        fd.set_result_type(rtres.value());
    }
#endif
    return {};

    //boost::container::small_vector<annotated_identifier, 16> aux;
    //aux.reserve(params.size());

    //for (auto& parampair : params) {
    //    entity_identifier constraint_eid = apply_visitor(tqvis, parampair.type.value);
    //    entity const& constraint_entity = environment_.eregistry_get(constraint_eid);
    //    bool constraint_is_typename = constraint_entity.is(*this, environment_.get_typename_entity_identifier());
    //    param_constraint_type ct = constraint_is_typename ? 
    //          (parampair.type.is_const ? param_constraint_type::const_constraint : param_constraint_type::type_constaint)
    //        : param_constraint_type::value_constaint;

    //    if (parampair.name.internal_name) aux.push_back(*parampair.name.internal_name);

    //    if (parampair.name.external_name) {
    //        aux.push_back(*parampair.name.external_name);
    //        nfields.emplace_back(
    //            *parampair.name.external_name,
    //            parampair.name.internal_name,
    //            constraint_eid,
    //            ct);
    //    } else {
    //        pfields.emplace_back(
    //            parampair.name.internal_name,
    //            constraint_eid,
    //            ct);
    //    }
    //}

    //// check for name duplicates
    //std::stable_sort(aux.begin(), aux.end(), [](auto const& l, auto const& r) {
    //    return l.value < r.value;
    //    //return l.ename && (!r.ename || l.ename->value < r.ename->value);wa
    //});
    //auto it = std::unique(aux.begin(), aux.end(), [](auto const& l, auto const& r) {
    //    return l.value == r.value;
    //});
    //if (it != aux.end()) {
    //    return std::unexpected(make_error<basic_general_error>(it->location, "duplicate parameter name"sv));
    //}

    //std::sort(nfields.begin(), nfields.end(), [](auto const& l, auto const& r) {
    //    return l.ename.value < r.ename.value;
    //    //return l.ename && (!r.ename || l.ename->value < r.ename->value);wa
    //});

    //res.set_nfields(std::move(nfields));
    //res.set_pfields(std::move(pfields));
    //return res;
    ////THROW_NOT_IMPLEMENTED_ERROR("function_descriptor::function_descriptor");
}
#endif

functional const* fn_compiler_context::lookup_functional(qname_view name) const
{
    if (name.is_absolute()) {
        return environment_.fregistry_find(name);
    }
    qname checkns = ns_;
    size_t sz = checkns.parts().size();
    for (;;) {
        checkns.append(name);
        functional* f = environment_.fregistry_find(checkns);
        if (f || !sz) return f;
        --sz;
        checkns.truncate(sz);
    }
}

std::expected<qname_identifier, error_storage> fn_compiler_context::lookup_qname(annotated_qname_view name) const
{
    functional const* pfn = lookup_functional(name.value);
    if (pfn) return pfn->id();
    return std::unexpected(make_error<undeclared_identifier_error>(name));
}

fn_compiler_context::lookup_entity_result_t fn_compiler_context::lookup_entity(identifier name) const
{
    auto optbv = get_bound(name);
    if (optbv) return visit([](auto&& bv) -> lookup_entity_result_t { return std::move(bv); }, *optbv);

    qname checkns = ns_;
    size_t sz = checkns.parts().size();
    for (;;) {
        checkns.append(name);
        functional* f = environment_.fregistry_find(checkns);
        if (f) return visit([](auto&& bv) -> lookup_entity_result_t { return std::move(bv); },
                            f->default_entity(const_cast<fn_compiler_context&>(*this)));
        if (!sz) break;
        --sz;
        checkns.truncate(sz);
    }
    return entity_identifier{}; // undeclared
}

fn_compiler_context::lookup_entity_result_t fn_compiler_context::lookup_entity(qname_view name) const
{
    if (name.is_relative() && name.size() == 1) {
        identifier varid = *name.begin();
        auto optbv = get_bound(varid);
        if (optbv) return visit([](auto&& bv) -> lookup_entity_result_t { return std::move(bv); }, *optbv);
    }

    functional const* pfn = lookup_functional(name);
    if (pfn) 
        return visit([](auto&& bv) -> lookup_entity_result_t { return std::move(bv); },
                     pfn->default_entity(const_cast<fn_compiler_context&>(*this)));
    return entity_identifier{}; // undeclared
}

std::expected<functional::match, error_storage> fn_compiler_context::find(builtin_qnid qnid, resource_location const& call_location, span<const opt_named_expression_t> const& call_args, semantic::expression_list_t& el, expected_result_t const& expected_result)
{
    functional const& fn = env().fget(qnid);
    return fn.find(*this, nullptr, call_location, call_args, el, expected_result);
}

std::expected<syntax_expression_result, error_storage> fn_compiler_context::find_and_apply(builtin_qnid qnid, call_builder const& cb, semantic::expression_list_t& el, expected_result_t const& expected_result)
{
    auto match = find(qnid, cb.location, cb, el, expected_result);
    if (!match) return std::unexpected(std::move(match.error()));
    return match->apply(*this);
}

std::expected<functional::match, error_storage> fn_compiler_context::find(qname_identifier qnid, resource_location const& call_location, span<const opt_named_expression_t> const& call_args, semantic::expression_list_t& el, expected_result_t const& expected_result)
{
    functional const& fn = env().fregistry_resolve(qnid);
    return fn.find(*this, nullptr, call_location, call_args, el, expected_result);
}


/*
local_variable & fn_compiler_context::new_variable(annotated_identifier name, entity_identifier t)
{
    resource_location const* ploc;
    functional_binding::value_type const* pv = scoped_locals_.back().lookup(name.value, &ploc);
    if (pv) {
        throw identifier_redefinition_error(name, *ploc);
    }
    return get<local_variable>(scoped_locals_.back().emplace_back(name,
        local_variable{ .type = std::move(t), .varid = environment_.new_variable_identifier(), .is_weak = false }));
}
*/

void fn_compiler_context::push_scope_constant(annotated_identifier name, entity_identifier eid)
{
    check_scope_name_conflict(name);
    scoped_locals_.emplace_back(std::move(name), std::move(eid));

    //resource_location const* ploc;
    //functional_binding::value_type const* pv = scoped_locals_.back().named_set.lookup(name.value, &ploc);
    //if (pv) {
    //    throw identifier_redefinition_error(name, *ploc);
    //}
    //scoped_locals_.back().named_set.emplace_back(name, eid);
}

#if 0
variable_entity& fn_compiler_context::create_captured_variable_chain(variable_entity& v)
{
    if (!parent_) {
        THROW_INTERNAL_ERROR("can't find fn context for variable: '%1%', current context ns: '%2%'"_fmt %
            env().print(v.name) % env().print(ns())
        );
    }
    qname_view name_qv = env().fregistry().resolve(v.name).name();
    qname_view vardefscope = name_qv.parent();
    if (vardefscope.has_prefix(parent_->base_ns())) {
        return new_captured_variable(name_qv.back(), v.get_type(), v);
    } else {
        variable_entity& parentvar = parent_->create_captured_variable_chain(v);
        return new_captured_variable(name_qv.back(), v.get_type(), parentvar);
    }
}
#endif

error_storage fn_compiler_context::finish_scope()
{
    boost::container::small_flat_set<entity_identifier, 4> const_values;
    boost::container::small_flat_set<entity_identifier, 4> types;
    for (semantic::yield_statement* rts : yield_statements_) {
        if (rts->is_const_value_result) {
            const_values.insert(rts->value_or_type);
            if (!types.empty() || const_values.size() > 1) {
                types.insert(get_entity(env(), rts->value_or_type).get_type());
            }
        } else {
            types.insert(rts->value_or_type);
        }
    }
    return {};
}

// result value or type, is value, is empty function
std::expected<std::tuple<entity_identifier, bool, bool>, error_storage> fn_compiler_context::finish_frame(internal_function_entity const& fent, resource_location finish_location)
{
    entity_identifier const_value_result; // empty if not a const value result

    if (!result_type) {
        // result type is not defined, so we need to deduce it from return statements
        boost::container::small_flat_set<entity_identifier, 4> result_elements;
        small_vector<entity_identifier, 4> stable_result_types_set;
        small_vector<entity_identifier, 4> stable_result_values_set;

        for (auto & [rts, loc, value_or_type, is_const_result] : return_statements_) {
            if (is_const_result) {
                if (result_elements.insert(value_or_type).second) {
                    stable_result_values_set.push_back(value_or_type);
                }
            } else if (result_elements.insert(value_or_type).second) {
                /*
                entity_signature const* psig = get_entity(env(), er.type()).signature();
                if (psig && psig->name == env().get(builtin_qnid::union_)) {
                    for (field_descriptor const& fd : psig->fields()) {
                        if (result_elements.insert(fd.entity_id()).second) {
                            if (fd.is_const()) {
                                stable_result_values_set.push_back(fd.entity_id());
                            } else {
                                stable_result_types_set.push_back(fd.entity_id());
                            }
                        }
                    }
                } else {
                    stable_result_types_set.push_back(er.type());
                }
                */
                stable_result_types_set.push_back(value_or_type);
            }
        }

        if (stable_result_types_set.empty() && stable_result_values_set.empty()) {
            result_type = env().get(builtin_eid::void_type);
        } else {
            if (stable_result_types_set.empty() && stable_result_values_set.size() == 1) {
                const_value_result = stable_result_values_set.front();
                result_type = get_entity(env(), stable_result_values_set.front()).get_type();
            } else if (stable_result_types_set.size() == 1 && stable_result_values_set.empty()) {
                result_type = stable_result_types_set.front();
                // const_value_result is empty
            } else {
                // build union
                entity_signature usig(env().get(builtin_qnid::union_), env().get(builtin_eid::typename_));
                for (entity_identifier const& eid : stable_result_values_set) {
                    usig.push_back(field_descriptor{ eid, true });
                }
                for (entity_identifier const& eid : stable_result_types_set) {
                    usig.push_back(field_descriptor{ eid, false });
                }
                result_type = env().make_basic_signatured_entity(std::move(usig)).id;
                // const_value_result is empty, union type can't be const value even if all return statements are const values (union of const values)
            }
        }
    } else {
        // deduce const_value_result from return statements if possible
        for (auto& [rts, loc, value_or_type, is_const_result] : return_statements_) {
            if (!is_const_result) {
                const_value_result = entity_identifier{}; // if there is at least one non-const return, the result is not const
                break;
            }
            if (!const_value_result) {
                if (get_entity(env(), value_or_type).get_type() != result_type) {
                    const_value_result = entity_identifier{}; // different return types, so the result is not const
                    break;
                }
                const_value_result = value_or_type;
            } else if (const_value_result != value_or_type) {
                const_value_result = entity_identifier{}; // different const return values, so the result is not const
                break;
            }
        }
    }

    BOOST_ASSERT(result_type);

    const bool need_return = !all_paths_return(expressions());
    if (need_return) {
        if (result_type != env().get(builtin_eid::void_type)) {
            return std::unexpected(make_error<basic_general_error>(
                fent.location, "not all control paths return a value, but result type is not void"sv, fent.id));
        }
        const_value_result = env().get(builtin_eid::void_);
        semantic::expression_span scope_destruction_expressions;
        pop_all_scopes(expression_store_, scope_destruction_expressions, false);
        append_expression(semantic::return_statement{ .scope_deconstruction = std::move(scope_destruction_expressions) });
        semantic::return_statement* pretst = &get<semantic::return_statement>(expressions().back());
        return_statements_.emplace_back(return_statement_descriptor{
            .stmt = pretst,
            .location = std::move(finish_location),
            .value_or_type = const_value_result,
            .is_const_result = true
        });
        BOOST_ASSERT(all_paths_return(expressions()));
    }

    if (const_value_result) {
        //bool is_empty_function = fent.arg_count() == 0 && !has_procedures(expressions());
        bool is_empty_function = !has_procedures(expressions());
        //if (!is_empty_function) {
        //    // e.g. to handle: return print( <something> );
        //    for (auto& [rts, el, er, loc] : return_statements_) {

        //        push_scopes_to_stash();
        //        semantic::expression_span dsp;
        //        pop_all_scopes(expression_store_, dsp, !er.is_const_result);
        //        rts->scope_deconstruction = expressions();
        //        pop_scopes_from_stash();
        //        pop_chain();
        //    }
        //}

        return std::tuple{ const_value_result, true, is_empty_function };
    }

    expected_result_t expected_result{ .type = result_type, .modifier = value_modifier_t::runtime_value };
    // append cast to result union type for each return statement if needed
    for (auto& [rts, loc, value_or_type, is_const_result] : return_statements_) {
        if (!is_const_result && value_or_type == result_type) {
            // no cast needed
            //push_chain();
            //append_result_inplace(el, er);
            //rts->result = expressions();
            //pop_chain();
            //push_chain();
            //pop_all_scopes(!er.is_const_result);
            //rts->scope_deconstruction = expressions();
            //pop_chain();
            continue;
        }
        call_builder cast_call{ loc };
        expected_result.location = loc;
        //rts->value_or_type = result_union_eid;
        //rts->is_const_value_result = false;
        if (is_const_result) {
            cast_call.emplace_back(syntax_expression{ loc, entity_identifier{ value_or_type } });
        } else {
            cast_call.emplace_back(loc, top_stack_value_expression{
                //.name = env().new_identifier(),
                .type = value_or_type
            });
        }
        auto res = find_and_apply(builtin_qnid::implicit_cast, cast_call, expression_store_, expected_result);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(loc, "failed to cast return value to function result type"sv, result_type),
                std::move(res.error())
            ));
        }
        // this is to union cast => no const result possible, no branches expressions possible, no temporaries possible
        BOOST_ASSERT(!res->is_const_result);
        BOOST_ASSERT(!res->branches_expressions);
        BOOST_ASSERT(res->temporaries.empty());
        if (is_const_result) {
            // runtime cast of constexpr value can be placed after scope deconstruction, but it must be before return statement, so we put it at the end of scope deconstruction expressions
            rts->scope_deconstruction = expression_store_.concat(rts->scope_deconstruction, res->expressions);
        } else {
            // runtime cast of non-constexpr value must be placed before scope deconstruction, so we put it at the beginning of scope deconstruction expressions
            rts->scope_deconstruction = expression_store_.concat(res->expressions, rts->scope_deconstruction);
        }
    }

    return std::tuple{ result_type, false, false };
#if 0
    if (result_type) {
        if (need_return) {
            if (result_type != env().get(builtin_eid::void_type)) {
                return std::unexpected(make_error<basic_general_error>(
                    fent.location, "not all control paths return a value, but result type is not void"sv, fent.id));
            }
            syntax_expression void_expr{ .location = finish_location, .value = env().get(builtin_eid::void_) };
            auto err = append_return(void_expr);
            if (err) return std::unexpected(std::move(err));
        }
        //bool is_empty_function = is_const_value_result && fent.arg_count() == 0 && !has_procedures(expressions());
        //return std::tuple{ result_value_or_type, is_const_value_result, is_empty_function };
    } else {

        

        if (need_return) { // just add a return statement at the end of function 
            append_expression(semantic::return_statement{});
            semantic::return_statement* pretst = &get<semantic::return_statement>(expressions().back());
            syntax_expression_result er{ .value_or_type = env().get(builtin_eid::void_), .is_const_result = true };
            return_statements_.emplace_back(pretst, semantic::managed_expression_list{ environment_ }, std::move(er), finish_location);
        }

    BOOST_ASSERT(!return_statements_.empty());

    if (return_statements_.size() == 1) { // single return statement at the end of function => use its type
        auto& [rts, el, er, loc] = return_statements_.front();
        result_value_or_type = er.value_or_type;
        is_const_value_result = er.is_const_result;
        push_chain();
        size_t scope_sz = append_result(el, er);
        auto return_expressions = expressions();
        pop_chain();
        rts->result = return_expressions;
        rts->scope_size = scope_sz;
        rts->value_or_type = result_value_or_type;
        rts->is_const_value_result = is_const_value_result;
        bool is_empty_function = is_const_value_result && fent.arg_count() == 0 && !has_procedures(expressions());
        return std::tuple{ result_value_or_type, is_const_value_result, is_empty_function };
    }

    boost::container::small_flat_set<entity_identifier, 4> result_elements;
    small_vector<entity_identifier, 4> stable_result_types_set;
    small_vector<entity_identifier, 4> stable_result_values_set;

    for (auto & [rts, el, er, loc] : return_statements_) {
        if (er.is_const_result) {
            if (result_elements.insert(er.value()).second) {
                stable_result_values_set.push_back(er.value());
            }
        } else if (result_elements.insert(er.type()).second) {
            entity_signature const* psig = get_entity(env(), er.type()).signature();
            if (psig && psig->name == env().get(builtin_qnid::union_)) {
                for (field_descriptor const& fd : psig->fields()) {
                    if (result_elements.insert(fd.entity_id()).second) {
                        if (fd.is_const()) {
                            stable_result_values_set.push_back(fd.entity_id());
                        } else {
                            stable_result_types_set.push_back(fd.entity_id());
                        }
                    }
                }
            } else {
                stable_result_types_set.push_back(er.type());
            }
        }
    }

    if (stable_result_types_set.empty() && stable_result_values_set.size() == 1) {
        result_value_or_type = stable_result_values_set.front();
        is_const_value_result = true;
        for (auto& [rts, el, er, loc] : return_statements_) {
            BOOST_ASSERT(!er.expressions);
            rts->result = {};
            rts->scope_size = 0;
            rts->value_or_type = result_value_or_type;
            rts->is_const_value_result = is_const_value_result;
        }
        bool is_empty_function = fent.arg_count() == 0 && !has_procedures(expressions());
        return std::tuple{ result_value_or_type, is_const_value_result, is_empty_function };
    }

    if (stable_result_types_set.size() == 1 && stable_result_values_set.empty()) {
        result_value_or_type = stable_result_types_set.front();
        is_const_value_result = false;
        for (auto& [rts, el, er, loc] : return_statements_) {
            push_chain();
            size_t scope_sz = append_result(el, er);
            auto return_expressions = expressions();
            pop_chain();
            rts->result = std::move(return_expressions);
            rts->scope_size = scope_sz;
            rts->value_or_type = result_value_or_type;
            rts->is_const_value_result = is_const_value_result;
        }
        return std::tuple{ result_value_or_type, is_const_value_result, false };
    }

    // build union
    entity_signature usig(env().get(builtin_qnid::union_), env().get(builtin_eid::typename_));
    for (entity_identifier const& eid : stable_result_values_set) {
        usig.push_back(field_descriptor{ eid, true });
    }
    for (entity_identifier const& eid : stable_result_types_set) {
        usig.push_back(field_descriptor{ eid, false });
    }

    entity_identifier result_union_eid = env().make_basic_signatured_entity(std::move(usig)).id;
    expected_result_t expected_result { .type = result_union_eid, .modifier = value_modifier_t::runtime_value };
    // append cast to result union type for each return statement
    for (auto & [rts, el, er, loc] : return_statements_) {
        call_builder cast_call{ loc };
        expected_result.location = loc;
        rts->value_or_type = result_union_eid;
        rts->is_const_value_result = false;
        if (er.is_const_result) {
            cast_call.emplace_back(syntax_expression{ loc, entity_identifier{ er.value() } });
        } else {
            if (rts->value_or_type == result_union_eid) {
                push_chain();
                size_t scope_sz = append_result(el, er);
                auto return_expressions = expressions();
                pop_chain();
                rts->result = std::move(return_expressions);
                rts->scope_size = scope_sz;
                continue;
            }
            cast_call.emplace_back(make_indirect_value(environment_, el, std::move(er), loc));
        }

        auto res = find_and_apply(builtin_qnid::implicit_cast, cast_call, el, expected_result);
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(loc, "internal error, cannot perform implicit cast to result union type"sv),
                std::move(res.error())
            ));
        }
        push_chain();
        size_t scope_sz = append_result(el, *res);
        auto return_expressions = expressions();
        pop_chain();
        rts->result = std::move(return_expressions);
        rts->scope_size = scope_sz;
    }

    return std::tuple{ result_union_eid, false, false };
#endif
}


#if 0
entity_identifier fn_compiler_context::compute_result_type()
{
    if (result) { return result; }
    else if (!accum_result) {
        accum_result = environment_.get(builtin_eid::void_);
    }
    return accum_result;
}

fn_compiler_context::expressions_state_type::expressions_state_type(fn_compiler_context& ctx) noexcept
    : pctx_{ &ctx }
    , cursize_{ ctx.expressions().size() }
    , stack_size_{ ctx.expr_stack_.size() }
    , cur_type_{ ctx.context_type }
{}

fn_compiler_context::expressions_state_type::expressions_state_type(expressions_state_type&& rhs) noexcept
    : pctx_{ rhs.pctx_ }
    , cursize_{ rhs.cursize_ }
    , stack_size_{ rhs.stack_size_ }
    , cur_type_{ rhs.cur_type_ }
{
    rhs.pctx_ = nullptr;
}

fn_compiler_context::expressions_state_type::~expressions_state_type()
{
    if (pctx_) {
        restore();
    }
}

void fn_compiler_context::expressions_state_type::detach() noexcept
{
    pctx_ = nullptr;
}

void fn_compiler_context::expressions_state_type::restore_and_detach()
{
    restore();
    detach();
}

void fn_compiler_context::expressions_state_type::restore()
{
    pctx_->expr_stack_.resize(stack_size_);
    auto& elist = pctx_->expressions();
    while (elist.size() > cursize_) {
        pctx_->env().release(elist.pop_back());
    }
    //pctx_->expressions().resize(cursize_);
    pctx_->context_type = cur_type_;
}
#endif

semantic::expression_span fn_compiler_context::store_semantic_expressions(semantic::managed_expression_list&& el)
{
    semantic::expression_span res = el;
    expression_store_.splice_back(el);
    return res;
}

void fn_compiler_context::append_expression(semantic::expression&& e)
{
    environment_.push_back_expression(expression_store_, expressions(), std::move(e));
}

void fn_compiler_context::append_expressions(semantic::expression_list_t& el, semantic::expression_span sp)
{
    expression_store().splice_back(el, sp);
    expressions() = expression_store_.concat(expressions(), std::move(sp));
}

void fn_compiler_context::append_stored_expressions(semantic::expression_list_t& el, semantic::expression_span sp)
{
    expression_store().splice_back(el, sp);
    branches_expressions() = expression_store_.concat(branches_expressions(), std::move(sp));
}

error_storage fn_compiler_context::append_return(syntax_expression const& expr)
{
    expected_result_t exp{ .type = result_type, .location = expr.location, .modifier = value_modifier_t::constexpr_or_runtime_value };
    
    semantic::managed_expression_list el{ environment_ };
    auto res = base_expression_visitor::visit(*this, el, exp, expr);
    if (!res) return std::move(res.error());

    syntax_expression_result& er = res->first;
    append_result_inplace(el, er);
    
    semantic::expression_span scope_destruction_expressions;
    pop_all_scopes(expression_store_, scope_destruction_expressions, !er.is_const_result);
    
    // we don't know here wether result is finally constexpr or runtime value

    //er.expressions.for_each([this](semantic::expression const& e) {
    //    GLOBAL_LOG_INFO() << env().print(e);
    //});

    append_expression(semantic::return_statement{
        .scope_deconstruction = scope_destruction_expressions,
    });

    semantic::return_statement* pretst = &get<semantic::return_statement>(expressions().back());
    return_statements_.emplace_back(return_statement_descriptor{
        .stmt = pretst,
        .location = std::move(expr.location),
        .value_or_type = er.value_or_type,
        .is_const_result = er.is_const_result
    });
    
    return {};
}

void fn_compiler_context::append_yield(semantic::expression_span return_expressions, size_t scope_sz, entity_identifier value_or_type, bool is_const_value_result)
{
    append_expression(semantic::yield_statement{
        .result = return_expressions,
        .scope_size = scope_sz,
        .value_or_type = value_or_type,
        .is_const_value_result = is_const_value_result
    });
    semantic::yield_statement* pretst = &get<semantic::yield_statement>(expressions().back());
    yield_statements_.emplace_back(pretst);
}

//void fn_compiler_context::adopt_and_append(semantic::expression_list_t& el, syntax_expression_result& er)
//{
//    append_stored_expressions(el, er.branches_expressions);
//    append_expressions(el, er.expressions);
//}

fn_compiler_context_scope::fn_compiler_context_scope(fn_compiler_context& ctx)
    : ctx_{ ctx }
{
    ctx_.push_scope();
    ctx_.push_binding(bound_temporaries_);
}

fn_compiler_context_scope::~fn_compiler_context_scope()
{
    ctx_.pop_binding(&bound_temporaries_);
    ctx_.pop_scope();
}

local_variable fn_compiler_context_scope::new_temporary(identifier name, entity_identifier type)
{
    local_variable lv{ .type = std::move(type), .varid = ctx_.env().new_variable_identifier(), .is_weak = false };
    bound_temporaries_.emplace_back(annotated_identifier(name), lv);
    return lv;
}

std::pair<identifier, local_variable> fn_compiler_context_scope::push_scope_variable(entity_identifier type)
{
    environment& env = ctx_.env();
    identifier unnamedid = env.new_identifier();
    ctx_.push_scope_variable(annotated_identifier{ unnamedid }, type);
    local_variable lv{ .type = type, .varid = {} /*env.new_variable_identifier()*/, .is_weak = false };
    return { std::move(unnamedid), std::move(lv) };
}

void fn_compiler_context_scope::skip_scope_variables()
{
    ctx_.push_scope_variable(
        annotated_identifier{},
        entity_identifier{}); // local_variable{ .type = {}, .varid = {}, .is_weak = false }
}

}
