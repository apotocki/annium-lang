//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <sstream>

//#include "sonia/utility/scope_exit.hpp"

#include "annium/semantic.hpp"
//#include "expression_visitor.hpp"
//#include "expression_vector_visitor.hpp"
#include "annium/ast/fn_compiler_context.hpp"

//#include "../entities/type_entity.hpp"

#include "annium/errors.hpp"

namespace annium {

struct expression_cast_to_enum_visitor : static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    case_expression const& ce;
    context_locator_t cl_;

    expression_cast_to_enum_visitor(fn_compiler_context& c, case_expression const& e, context_locator_t const& cl)
        : ctx{ c }
        , ce { e }
        , cl_{ cl }
    {}

    /*
    result_type operator()(annium_vector_t const& v) const
    {
        size_t stored_pos = result.size();
        EXCEPTIONAL_SCOPE_EXIT([this, stored_pos](){ result.resize(stored_pos); });
        expression_visitor elemvis{ ctx, result, &e.type };
        for (expression_t const& e : vec.elements) {
            if (!apply_visitor(elemvis, e)) {
                result.resize(stored_pos);
                return nullopt;
            }
        }
        result.emplace_back(semantic::push_value{ decimal{ vec.elements.size() } });
        result.emplace_back(semantic::invoke_function{ ctx.env().arrayify_entity_name(), (uint32_t)vec.elements.size() + 1 });
        return v;
    }

    result_type operator()(annium_array_t const& ar) const
    {
        if (ar.size != vec.elements.size() || !this->operator()(annium_vector_t{ ar.type })) return nullopt;
        return ar;
    }

    result_type operator()(annium_union_t const& v) const
    {
        for (annium_generic_type const& ut : v.members) {
            if (auto optrest = apply_visitor(*this, ut); optrest) {
                return *optrest;
            }
        }
        return nullopt;
    }

    inline result_type operator()(annium_bool_t const& v) const { return nullopt; }
    inline result_type operator()(annium_int_t const& v) const { return nullopt; }
    inline result_type operator()(annium_float_t const& v) const { return nullopt; }
    inline result_type operator()(annium_decimal_t const& v) const { return nullopt; }
    inline result_type operator()(annium_string_t const& v) const { return nullopt; }
    inline result_type operator()(annium_object_t const& v) const { return nullopt; }
    

    inline result_type operator()(annium_object_t const& v) const
    {
        if (annium_type{ v } == expected_tp) return expected_tp;
        if (auto const* pte = dynamic_cast<type_entity const*>(v.value); pte) {
            if (pte->try_cast(ctx, result, expected_tp)) {
                return expected_tp;
            }
        }
        return nullopt;
    }

    inline result_type operator()(annium_vector_t const& v) const
    {
        expression_cast_to_vector_visitor vis{ ctx, v, result };
        return apply_visitor(vis, type2cast);
    }
    */

    //inline result_type operator()(annium_particular_bool_t const&) const
    //{
    //    return std::unexpected(cast_error{ loc, e, annium_particular_bool_t{}, ce });
    //}

    inline result_type operator()(annium_object_t const& obj) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("expression_cast_to_enum_visitor annium_object_t");
#if 0
        shared_ptr<entity> e = ctx.resolve_entity(obj.name());
        if (!e) [[unlikely]] {
            return make_error<basic_general_error>(ce.name.location, "unresolved context object"sv, obj.name());
        }
        shared_ptr<enum_entity> enum_ent = dynamic_pointer_cast<enum_entity>(e);
        if (!enum_ent) [[unlikely]] {
            return make_error<basic_general_error>(ce.name.location, "is not a enumeration"sv, obj.name());
        }
        auto const* enumcase = enum_ent->find(ce.name.value);
        if (!enumcase) [[unlikely]] {
            return make_error<unknown_case_error>(ce, obj.name());
        }
        ctx.append_expression(semantic::push_value{ enumcase->value });
        ctx.context_type = obj;
        return {};
#endif
    }

    //inline result_type operator()(annium_vector_t const& v) const
    //{
    //    THROW_NOT_IMPLEMENTED_ERROR();
    //    //if (target.type == v.type) return target;
    //    //return {};
    //}

    inline result_type operator()(annium_union_t const& v) const
    {
        alt_error err;
        for (annium_type const& t : v) {
            if (auto opterr = apply_visitor(*this, t); opterr) {
                err.alternatives.emplace_back(std::move(opterr));
            } else {
                return {};
            }
        }
        return make_error<alt_error>(std::move(err));
    }

    template <typename T>
    inline result_type operator()(T const&) const
    {
        // THROW_NOT_IMPLEMENTED_ERROR();
        return make_error<basic_general_error>(cl_(), "is not a enumeration"sv);
    }
};

}
