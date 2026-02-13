//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "internal_function_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/declaration_visitor.hpp"

#include "annium/auxiliary.hpp"
//#define ANNIUM_NO_INLINE_FUNCTIONS 1

namespace annium {

#ifdef ANNIUM_NO_INLINE_FUNCTIONS
    [[nodiscard]] bool internal_function_entity::is_inline() const noexcept { return false; }
#else
    [[nodiscard]] bool internal_function_entity::is_inline() const noexcept
    {
        return get_flag(mask_is_inline, std::memory_order_relaxed);
    }
#endif // ANNIUM_NO_INLINE_FUNCTIONS

internal_function_entity::internal_function_entity(environment& env, qname&& name, entity_signature&& sig, resource_location loc, field_descriptor r)
    : name_{ std::move(name) }
    , sig_{ std::move(sig) }
    , result{ std::move(r) }
{
    location = std::move(loc);

    // by default all internal functions are provisions
    set_provision(true);
    set_built(false);
    set_inline(false);
    set_need_framepointer(false);

    // non-empty by default
    set_flag(mask_is_empty, false, std::memory_order_relaxed);

    context_ = make_shared<fn_compiler_context>(env, *this);
}

void internal_function_entity::set_captured_end_offset() noexcept
{
    update_state_cas([&](uint64_t cur) {
        state_fields flds = std::bit_cast<state_fields>(cur);
        flds.captured_offset = static_cast<uint64_t>(context().scoped_locals_count());
        return std::bit_cast<uint64_t>(flds);
    });
}

void internal_function_entity::set_argument_variables() noexcept
{
    update_state_cas([&](uint64_t cur) {
        state_fields flds = std::bit_cast<state_fields>(cur);
        flds.arg_count = flds.variable_count;
        return std::bit_cast<uint64_t>(flds);
    });
}

//size_t internal_function_entity::hash() const noexcept
//{
//    return hasher{}(sig_, location_);
//}
//
//bool internal_function_entity::equal(entity const& rhs) const noexcept
//{
//    if (auto pr = dynamic_cast<internal_function_entity const*>(&rhs); pr) {
//        return sig_ == pr->sig_ && location_ == pr->location_;
//    }
//    return false;
//}

std::ostream& internal_function_entity::print_to(std::ostream& os, environment const& e) const
{
    return os << "fn "sv << e.print(sig_);
}

//void internal_function_entity::push_argument(variable_identifier varid)
//{
//    auto it = variables_.find(varid);
//    if (it == variables_.end()) {
//        variables_.emplace_hint(it, std::pair{ varid, (uint64_t)arg_count_});
//        ++arg_count_;
//    }
//}

void internal_function_entity::push_variable(variable_identifier varid, intptr_t index)
{
    if (varid) {
        BOOST_VERIFY(variables_.insert(std::pair{ varid, index }).second);
    }

    update_state_cas([&](uint64_t cur) {
        state_fields flds = std::bit_cast<state_fields>(cur);
        ++flds.variable_count;
        return std::bit_cast<uint64_t>(flds);
    });
}

//void internal_function_entity::push_capture(environment& e, identifier name, entity_identifier type, intptr_t index)
//{
//    variable_identifier varid = e.new_variable_identifier();
//    captured_bindings.emplace_back(annotated_identifier{ name }, local_variable{ .type = type, .varid = varid });
//    variables_.insert(std::pair{ varid, index });
//}

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

bool internal_function_entity::need_framepointer() const noexcept
{
    return !variables_.empty() || get_flag(mask_force_fp, std::memory_order_relaxed);
}

intptr_t internal_function_entity::resolve_variable_index(variable_identifier varid) const
{
    auto it = variables_.find(varid);
    if (it == variables_.end()) {
        THROW_INTERNAL_ERROR("internal_function_entity::resolve_variable_index (%1%) variable not found"_fmt % varid);
    }
    return it->second - static_cast<intptr_t>(arg_count());
}

error_storage internal_function_entity::build()
{
    context().push_binding(bindings);
    return build(context());
}

error_storage internal_function_entity::build(fn_compiler_context& fnctx)
{
    BOOST_ASSERT(!is_built());

    if (result.entity_id()) {
        fnctx.result_type = get_entity_type(fnctx.env(), result);
    }

    declaration_visitor dvis{ fnctx };
    if (auto res = dvis.apply(sts_); !res) return res.error();

    auto fres = fnctx.finish_frame(*this);
    if (!fres) return fres.error();

    auto [value_or_type, is_value, is_empty] = fres.value();
    result = field_descriptor{ value_or_type, is_value };

    BOOST_ASSERT(fnctx.expressions_branch() == 1);
    body = fnctx.expressions();
    fnctx.env().store(std::move(fnctx.expression_store()));

    BOOST_ASSERT(!fnctx.expression_store());

    // publish build results
    set_flag(mask_is_empty, result.is_const() && is_empty, std::memory_order_relaxed);
    sts_ = {};
    set_built(true);

    return {};
}

bool internal_function_entity::is_const_eval(environment&) const noexcept
{
    return result.is_const() && is_empty();
}

}
