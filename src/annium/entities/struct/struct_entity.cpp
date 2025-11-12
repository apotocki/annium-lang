//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/ast/declaration_visitor.hpp"

#include "annium/errors/circular_dependency_error.hpp"

namespace annium {

struct_entity::struct_entity(environment& env, functional& fn, span<const annium::field> body)
    : name_{ fn.name() }, body_{ body }
{
    sig_.name = fn.id();
    sig_.result.emplace(env.get(builtin_eid::typename_));
}

struct_entity::struct_entity(qname qn, entity_signature&& sgn, span<const annium::field> body)
    : basic_signatured_entity{ std::move(sgn) }
    , name_{ std::move(qn) }
    , body_{ body }
{}

error_storage struct_entity::build(fn_compiler_context& extctx, semantic::expression_list_t& el) const
{
    sonia::lang::compiler_task_tracer::task_guard tg = extctx.try_lock_task(entity_task_id{ *this });
    if (!tg) {
        return make_error<circular_dependency_error>(make_error<basic_general_error>(location, "build struct"sv, id));
    }
    if (built_.load() == build_state::underlying_tuple_built) return {}; // double check

    // prepare context
    fn_compiler_context ctx{ extctx, name_ };
    if (!context_bindings_.empty()) {
        ctx.push_binding(context_bindings_);
    }
    
    auto err = build(ctx, body_, el);
    //auto err = apply_visitor(make_functional_visitor<error_storage>([&ctx, &el, this](auto const& body) -> error_storage {
    //    return build(ctx, body, el);
    //}), body_);
    if (!err) {
        built_.store(build_state::underlying_tuple_built);
    }
    return err;
}

error_storage struct_entity::build(fn_compiler_context& ctx, span<const annium::field> fl, semantic::expression_list_t& el) const
{
    environment& e = ctx.env();
    std::vector<field> fields;
    fields.reserve(fl.size());
    entity_signature tuple_signature{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
    for (annium::field const& f : fl) {
        auto res = base_expression_visitor::visit(ctx, el, expected_result_t{ .modifier = value_modifier_t::constexpr_value }, f.type_or_value);
        if (!res) return std::move(res.error());
        bool is_const = can_be_constexpr(f.modifier);
        if (f.name) {
            tuple_signature.emplace_back(f.name.value, res->first.value(), is_const);
        } else {
            tuple_signature.emplace_back(res->first.value(), is_const);
        }
        if (!is_const) {
            fields.emplace_back(field{ f.name, res->first.value(), f.value });
        }
    }

    underlying_tuple_eid_ = e.make_basic_signatured_entity(std::move(tuple_signature)).id;
    fields_ = std::move(fields);
    return {};
}

error_storage struct_entity::build(fn_compiler_context&, span<const statement>, semantic::expression_list_t&) const
{
    THROW_NOT_IMPLEMENTED_ERROR("struct_entity::build(statement_set_t)");
    //declaration_visitor dvis{ ctx };
    //if (auto err = dvis.apply(sts); err) return std::move(err);
}

//error_storage struct_entity::build(fn_compiler_context& ctx, field_list_t const& fl) const
//{
//    environment& e = ctx.env();
//
//    pmd_ = make_shared<functional_match_descriptor>(e);
//    // no need to store the context expression state here
//    ctx.push_chain(pmd_->call_expressions);
//
//    //small_vector<std::tuple<field_t const&, syntax_expression>, 16> initializers; // [field, field name expression]
//    size_t pos_arg_num = 0;
//    entity_signature tuple_signature{ e.get(builtin_qnid::tuple) };
//    for (field_t const& f : fl) {
//        ct_expression_visitor evis{ ctx };
//        auto res = apply_visitor(evis, f.type);
//        if (!res) return std::move(res.error());
//        bool is_const = f.modifier != field_modifier_t::value;
//        if (f.name) {
//            tuple_signature.push_back(f.name.value, field_descriptor{ *res, is_const });
//        } else {
//            tuple_signature.push_back(field_descriptor{ *res, is_const });
//            if (!is_const) ++pos_arg_num;
//        }
//        if (!is_const) {
//            parameter_match_result* pmr = f.name ? &pmd_->get_match_result(f.name.value) : &pmd_->get_match_result(pos_arg_num - 1);
//            if (f.value) {
//                auto last_expr_it = ctx.expressions().last();
//                expression_visitor evis{ ctx, annotated_entity_identifier{ *res, get_start_location(f.type) } };
//                auto res = apply_visitor(evis, *f.value);
//                if (!res) return std::move(res.error());
//                pmr->append_result(false, ctx.context_type, last_expr_it, ctx.expressions());
//                // annotated_entity_identifier{ *res, get_start_location(f.type) }
//            }
//        }
//        else {
//            BOOST_ASSERT(!f.value);
//        }
//    }
//
//    indirect_signatured_entity smplsig{ tuple_signature };
//
//    entity const& e = e.eregistry_find_or_create(smplsig, [&e, &tuple_signature]() {
//        return make_shared<basic_signatured_entity>(e.get(builtin_eid::typename_), std::move(tuple_signature));
//    });
//
//    underlying_tuple_eid_ = e.id();
//    return {};
//}



//std::expected<functional::match, error_storage> struct_entity::find_init(fn_compiler_context& ctx, pure_call const& call) const
//{
//    if (built_.load() == build_state::not_built) {
//        if (auto err = build(ctx); err) return std::unexpected(std::move(err));
//    }
//    functional const* ifn = ctx.env().fregistry().find(name() / ctx.env().get(builtin_id::init));
//    if (!ifn) return std::unexpected(make_error<basic_general_error>(location(), "no constructuctor"sv, id()));
//    return ifn->find(ctx, call, annotated_entity_identifier{ id(), location() });
//}

std::expected<span<struct_entity::field const>, error_storage> struct_entity::fields(fn_compiler_context& ctx) const
{
    if (built_.load() == build_state::not_built) {
        semantic::managed_expression_list el{ ctx.env() };
        if (auto err = build(ctx, el); err) return std::unexpected(std::move(err));
    }
    return span{ fields_ };
}

std::expected<entity_identifier, error_storage> struct_entity::underlying_tuple_eid(fn_compiler_context& ctx) const
{
    if (built_.load() == build_state::not_built) {
        semantic::managed_expression_list el{ ctx.env() };
        if (auto err = build(ctx, el); err) return std::unexpected(std::move(err));
    }
    return underlying_tuple_eid_;
}


//std::expected<functional_match_descriptor const*, error_storage> struct_entity::underlying_tuple_initializer(fn_compiler_context& ctx) const
//{
//    if (built_.load() == build_state::not_built) {
//        if (auto err = build(ctx); err) return std::unexpected(std::move(err));
//    }
//    return pmd_.get();
//}

}
