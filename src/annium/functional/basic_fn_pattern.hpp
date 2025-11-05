//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/small_vector.hpp"
#include "annium/entities/functional.hpp"

namespace annium {

class internal_function_entity;

class basic_fn_pattern : public functional::pattern
{
    friend class parameter_matcher;

protected:
    struct parameter_descriptor
    {
        annotated_identifier ename;
        small_vector<annotated_identifier, 2> inames;
        std::variant<syntax_expression const*, syntax_pattern const*> constraint;
        std::variant<required_t, optional_t, syntax_expression const*> default_value;
        parameter_constraint_modifier_t modifier;
    };

    // in the order of declaration (fn_pure)
    using parameters_t = small_vector<parameter_descriptor, 8>;
    parameters_t parameters_;

    std::variant<nullptr_t, syntax_expression, syntax_pattern> result_; // auto or type/value expression or pattern

public:
    basic_fn_pattern() = default;

    error_storage init(fn_compiler_context&, fn_pure const&);

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override;

protected:
    std::pair<syntax_expression_result, size_t> apply_arguments(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const;
    
    // builds entity that represents the function
    virtual shared_ptr<internal_function_entity> build(fn_compiler_context&, entity_signature&&, functional_binding_set&&) const;
    virtual void build_scope(environment&, functional_binding_set&&, internal_function_entity& /* out */) const;
};

}
