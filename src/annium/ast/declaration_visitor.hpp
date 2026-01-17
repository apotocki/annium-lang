//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/small_vector.hpp"

#include "annium/semantic.hpp"
#include "annium/errors.hpp"

namespace annium {

class functional;
class internal_function_entity;

class declaration_visitor
{
    fn_compiler_context& ctx;
    mutable small_vector<span<const statement>, 4> decl_stack_;

    enum class break_scope_kind : int
    {
        none = 0,
        loop,
        function
    };

    using result_type = std::expected<break_scope_kind, error_storage>;

public:
    inline explicit declaration_visitor(fn_compiler_context& c) noexcept
        : ctx{ c }
    {}

    [[nodiscard]] result_type apply(span<const statement>) const;

    //void operator()(empty_t const&) const {}

    [[nodiscard]] result_type operator()(include_decl const&) const;

    [[nodiscard]] result_type operator()(extern_var const&) const;

    [[nodiscard]] result_type operator()(using_decl const&) const;

    [[nodiscard]] result_type operator()(struct_decl const&) const;
    [[nodiscard]] result_type operator()(enum_decl const&) const;

    // extern function declaration
    [[nodiscard]] result_type operator()(fn_pure const&) const;

    [[nodiscard]] result_type operator()(fn_decl const&) const;
    [[nodiscard]] result_type operator()(typefn_decl const&) const;

    [[nodiscard]] result_type operator()(if_decl const&) const;
    [[nodiscard]] result_type operator()(while_decl const&) const;
    [[nodiscard]] result_type operator()(for_statement const&) const;
    [[nodiscard]] result_type operator()(continue_statement const&) const;
    [[nodiscard]] result_type operator()(break_statement const&) const;
    [[nodiscard]] result_type operator()(yield_statement const&) const;

    [[nodiscard]] result_type operator()(let_statement const&) const;
    //void operator()(assign_decl_t const&) const;

    [[nodiscard]] result_type operator()(expression_statement const&) const;

    [[nodiscard]] result_type operator()(return_statement const&) const;

    template <typename T>
    result_type operator()(T const& d) const {
        (void)d;
        THROW_NOT_IMPLEMENTED_ERROR("declaration_visitor");
    }

    //function_entity& append_fnent(fn_pure&, function_signature& sig, span<infunction_declaration_t>) const;

    //void operator()(type_decl const&) const { THROW_INTERNAL_ERROR(); }
    //void operator()(include_decl const&) const { THROW_INTERNAL_ERROR(); }

private:
    environment& env() const noexcept;

    // for the case when condition is a runtime evaluated expression
    [[nodiscard]] result_type do_rt_if_decl(if_decl const&) const;
};

}
