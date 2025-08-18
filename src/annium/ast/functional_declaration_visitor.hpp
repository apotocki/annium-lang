//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/small_vector.hpp"

#include "annium/semantic.hpp"
#include "annium/errors.hpp"

namespace annium {

class functional;
class function_entity;

class functional_declaration_visitor : public static_visitor<error_storage>
{
    fn_compiler_context& ctx;
    mutable small_vector<span<const statement>, 4> decl_stack_;

public:
    inline explicit functional_declaration_visitor(fn_compiler_context& c) noexcept
        : ctx{ c }
    {}

    [[nodiscard]] error_storage apply(span<const statement>) const;

/*

    [[nodiscard]] result_type operator()(include_decl const&) const;

    [[nodiscard]] result_type operator()(extern_var const&) const;

    [[nodiscard]] result_type operator()(using_decl const&) const;

    [[nodiscard]] result_type operator()(struct_decl const&) const;

    [[nodiscard]] result_type operator()(fn_pure const&) const;

    [[nodiscard]] result_type operator()(fn_decl_t const&) const;

    [[nodiscard]] result_type operator()(if_decl const&) const;
    [[nodiscard]] result_type operator()(while_decl const&) const;
    [[nodiscard]] result_type operator()(for_decl const&) const;
    [[nodiscard]] result_type operator()(continue_statement_t const&) const;
    [[nodiscard]] result_type operator()(break_statement_t const&) const;

    [[nodiscard]] result_type operator()(let_statement const&) const;
    //void operator()(assign_decl_t const&) const;

    [[nodiscard]] result_type operator()(expression_statement_t const&) const;

    [[nodiscard]] result_type operator()(return_decl_t const&) const;

    void append_fnsig(fn_pure&, functional** ppf = nullptr) const;
    
    //function_entity& append_fnent(fn_pure&, function_signature& sig, span<infunction_declaration_t>) const;

    //void operator()(type_decl const&) const { THROW_INTERNAL_ERROR(); }
    //void operator()(include_decl const&) const { THROW_INTERNAL_ERROR(); }
    */

    template <typename T>
    result_type operator()(T const& d) const {
        THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor");
    }

    environment& env() const noexcept;
};

}
