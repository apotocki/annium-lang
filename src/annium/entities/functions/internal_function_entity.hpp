//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <unordered_map>
//#include <boost/multi_index_container.hpp>
//#include <boost/multi_index/random_access_index.hpp>
//#include <boost/multi_index/ordered_index.hpp>
//#include <boost/multi_index/member.hpp>

#include "annium/semantic.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/functional.hpp"

namespace annium {

class indirect_internal_function_entity : public tagged_signatured_entity<resource_location>
{
    entity_signature const& sig_;

protected:
    resource_location const& get_tag() const noexcept override final { return location; }
    entity_signature const* signature() const noexcept override final { return &sig_; }

public:
    inline indirect_internal_function_entity(entity_signature const& sig, resource_location const& loc) noexcept
        : sig_{ sig }
    {
        location = loc;
    }
};

class internal_function_entity : public tagged_signatured_entity<resource_location>
{
    using var_set_t = std::unordered_map<variable_identifier, intptr_t, sonia::hash<variable_identifier>>;
    /*
    using var_set_t = boost::multi_index::multi_index_container<
        varibale,
        boost::multi_index::indexed_by<
            boost::multi_index::random_access<>,
            boost::multi_index::ordered_unique<
                boost::multi_index::member<varibale, variable_identifier, &varibale::id>
            >
        >
    >;
    */
    //small_vector<intptr_t, 16> scope_thresholds_;

protected:
    qname name_;
    entity_signature sig_;

public:
    semantic::expression_span body;
    functional_binding_set bindings;
    functional_binding_set captured_bindings;
    error_storage build_errors;
    field_descriptor result;

    internal_function_entity(qname&& name, entity_signature&& sig, resource_location loc, field_descriptor r);

    void set_body(span<const statement> bd) noexcept { sts_ = std::move(bd); }

    void push_argument(variable_identifier);
    void push_variable(variable_identifier varid, intptr_t index);
    void push_capture(environment&, identifier name, entity_identifier type, intptr_t index);
    //void push_argument(annotated_identifier, local_variable &&);
    //void push_variable(variable_identifier, intptr_t);
    [[nodiscard]] intptr_t resolve_variable_index(variable_identifier) const;

    void visit(entity_visitor const& v) const override { v(*this); }

    //size_t hash() const noexcept override final;
    //bool equal(entity const& rhs) const noexcept override final;
    
    inline void set_arg_count(uint64_t count) noexcept { arg_count_ = count; }
    [[nodiscard]] inline uint64_t arg_count() const noexcept { return arg_count_; }

    inline void set_captured_var_count(uint64_t count) noexcept { captured_var_count_ = count; }
    [[nodiscard]] inline uint64_t captured_var_count() const noexcept { return captured_var_count_; }

    [[nodiscard]] bool is_inline() const noexcept;

    inline void set_inline(bool val = true) noexcept { is_inline_ = val ? 1 : 0; }
    inline void set_provision(bool val = true) noexcept { is_provision_ = val ? 1 : 0; }

    [[nodiscard]] inline bool is_provision() const noexcept { return !!is_provision_; }
    [[nodiscard]] inline bool is_built() const noexcept { return !!is_built_; }
    [[nodiscard]] inline bool is_empty() const noexcept { return !!is_empty_; }

    std::ostream& print_to(std::ostream& os, environment const& e) const override;

    [[nodiscard]] error_storage build(environment&);
    [[nodiscard]] error_storage build(fn_compiler_context&);

    [[nodiscard]] inline qname_view name() const noexcept { return name_; }

    [[nodiscard]] bool is_const_eval(environment&) const noexcept;

    [[nodiscard]] inline size_t variables_count() const noexcept { return variables_.size(); }

    [[nodiscard]] size_t parameter_count() const noexcept;

    [[nodiscard]] inline size_t scope_offset() const noexcept { return variables_count() - captured_var_count_; }

    entity_signature const* signature() const noexcept override { return &sig_; }
        
protected:
    resource_location const& get_tag() const noexcept override final { return location; }

private:
    var_set_t variables_;
    //qname_view ns_;
    span<const statement> sts_;
    uint64_t arg_count_ : 16; // number of runtime arguments
    uint64_t captured_var_count_ : 16; // number of runtime captured variables
    uint64_t is_provision_ : 1;
    uint64_t is_built_ : 1;
    uint64_t is_inline_ : 1;
    uint64_t is_empty_ : 1;
    //uint64_t is_void_ : 1;
};

}
