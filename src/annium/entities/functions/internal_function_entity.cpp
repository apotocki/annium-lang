//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "internal_function_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/declaration_visitor.hpp"

namespace annium {

internal_function_entity::internal_function_entity(qname&& name, entity_signature&& sig)
    : function_entity{ std::move(name), std::move(sig) }
    , captured_var_count_{ 0 }
    , is_provision_{ 1 } // by default all internal functions are provisions
    , is_inline_{ 0 }
    , is_built_{ 0 }
    , arg_count_{ 0 }
{
    // if the signature has a result, it's the function result.
    // If the signature has no result, the function result should be set later by analizing the body of the function.
    if (sig_.result) {
        result = *sig_.result;
    }
}

void internal_function_entity::push_argument(variable_identifier varid)
{
    auto it = variables_.find(varid);
    if (it == variables_.end()) {
        variables_.emplace_hint(it, std::pair{ varid, (uint64_t)arg_count_});
        ++arg_count_;
    }
}

void internal_function_entity::push_variable(variable_identifier varid, intptr_t index)
{
    BOOST_VERIFY(variables_.insert(std::pair{ varid, index }).second);
}

void internal_function_entity::push_capture(environment& e, identifier name, entity_identifier type, intptr_t index)
{
    variable_identifier varid = e.new_variable_identifier();
    captured_bindings.emplace_back(annotated_identifier{ name }, local_variable{ .type = type, .varid = varid });
    variables_.insert(std::pair{ varid, index });
}

//void internal_function_entity::push_argument(annotated_identifier name, local_variable&& lv)
//{
//    variables_.insert(lv.varid, std::move(lv));
//    variables_.emplace_back(lv.varid);
//    bound_arguments.emplace_back(name, std::move(lv));
//}
//
//void internal_function_entity::push_variable(local_variable&& lv)
//{
//    variables_.emplace_back(lv.varid);
//}

intptr_t internal_function_entity::resolve_variable_index(variable_identifier varid) const
{
    auto it = variables_.find(varid);
    if (it == variables_.end()) {
        THROW_INTERNAL_ERROR("internal_function_entity::resolve_variable_index (%1%) variable not found"_fmt % varid);
    }
    return it->second - arg_count_;
    //auto it = variables_.get<1>().find(varid);
    //if (it == variables_.get<1>().end()) {
    //    THROW_INTERNAL_ERROR("internal_function_entity::resolve_variable_index (%1%) variable not found"_fmt % varid);
    //}
    //auto pos = variables_.project<0>(it) - variables_.get<0>().begin();
    //return static_cast<intptr_t>(bound_arguments.size()) - static_cast<intptr_t>(pos) - 1;
}

error_storage internal_function_entity::build(environment& e)
{
    fn_compiler_context fnctx{ e, *this };
    if (captured_var_count_) {
        fnctx.push_binding(captured_bindings);
    }
    fnctx.push_binding(bindings);
    return build(fnctx);
}

error_storage internal_function_entity::build(fn_compiler_context& fnctx)
{
    BOOST_ASSERT(!is_built_);

    if (result.entity_id()) {
        fnctx.result_value_or_type = result.entity_id();
        fnctx.is_const_value_result = result.is_const();
    }

    //GLOBAL_LOG_INFO() << fnctx.env().print(sts_);
    declaration_visitor dvis{ fnctx };
    if (auto err = dvis.apply(sts_); err) return err;

    auto fres = fnctx.finish_frame(*this); // unknown result type is resolving here
    if (!fres) return fres.error();
        
    auto [value_or_type, is_value, is_empty] = fres.value();
    if (!result.entity_id()) {
        result = field_descriptor{ value_or_type, is_value };
    }
    
    BOOST_ASSERT(fnctx.expressions_branch() == 1);
    body = fnctx.expressions();
    fnctx.env().store(std::move(fnctx.expression_store()));

    BOOST_ASSERT(!fnctx.expression_store());

    //GLOBAL_LOG_INFO() << "built inline function begin: " << e.print(*this);
    //body.for_each([&e](semantic::expression const& e) {
    //    GLOBAL_LOG_INFO() << e.print(e);
    //});
    //GLOBAL_LOG_INFO() << "built inline function end: " << e.print(*this);
    //sts_.reset();
    is_built_ = 1;
    is_empty_ = result.is_const() && is_empty;
    //is_empty_ = 0;
    return {};
}

bool internal_function_entity::is_const_eval(environment& e) const noexcept
{
    if (!result.is_const()) return false;
    // to do: traverse expressions
    return result.entity_id() != e.get(builtin_eid::void_);
}

}
