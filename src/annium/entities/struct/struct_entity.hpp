//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <atomic>

//#include "sonia/concurrency.hpp"
#include "sonia/shared_ptr.hpp"

#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/functional.hpp"
#include "annium/errors.hpp"

namespace annium {

class functional_match_descriptor;

class struct_entity : public basic_signatured_entity
{
    friend class struct_builder_visitor;

public:
    struct field
    {
        annotated_identifier name;
        entity_identifier type;
        variant<required_t, syntax_expression_t> default_value;
    };

private:

    qname name_;
    field_list_t body_;
    functional_binding_set context_bindings_;

    mutable std::vector<field> fields_;

    mutable entity_identifier underlying_tuple_eid_;
    
    enum class build_state : long
    {
        not_built,
        underlying_tuple_built = 1
    };

    mutable std::atomic<build_state> built_{ build_state::not_built };

    error_storage build(fn_compiler_context& struct_ctx, field_list_t const&, semantic::expression_list_t&) const;
    error_storage build(fn_compiler_context& struct_ctx, statement_span const&, semantic::expression_list_t&) const;

public:
    struct_entity(environment&, functional&, field_list_t const&);
    struct_entity(qname, entity_signature&&, field_list_t const&);

    inline qname_view name() const noexcept { return name_; }
    inline functional_binding_set const& context_bindings() const noexcept { return context_bindings_; }
    inline functional_binding_set& context_bindings() noexcept { return context_bindings_; }

    std::expected<span<field const>, error_storage> fields(fn_compiler_context&) const;

    //std::expected<functional::match, error_storage> find_init(fn_compiler_context&, pure_call_t const&) const;
    std::expected<entity_identifier, error_storage> underlying_tuple_eid(fn_compiler_context&) const;
    //std::expected<functional_match_descriptor const*, error_storage> underlying_tuple_initializer(fn_compiler_context&) const;

    error_storage build(fn_compiler_context& external_ctx, field_list_t const&) const;
    error_storage build(fn_compiler_context& external_ctx, semantic::expression_list_t&) const;
    //std::expected<function_entity const*, error_storage> find_field_getter(fn_compiler_context&, annotated_identifier const&) const;
    //std::expected<function_entity const*, error_storage> find_field_setter(fn_compiler_context&, annotated_identifier const&) const;
    //std::expected<function_signature const*, error_storage> find(fn_compiler_context&, pure_call_t&) const override;
    //bool try_cast(fn_compiler_context& ctx, annium_type const& rtype) const;
    //void treat(fn_compiler_context&);
};

}
