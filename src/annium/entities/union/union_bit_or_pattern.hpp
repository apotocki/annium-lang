//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/functional/generic_pattern_base.hpp"

namespace annium {

// fn union(=> ... @typename) -> typename => implementation defined
class union_bit_or_pattern : public generic_pattern_base<union_bit_or_pattern>
{
    friend class generic_pattern_base<union_bit_or_pattern>;

public:
    union_bit_or_pattern() = default;

    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "union(...)"sv; }

protected:

    error_storage accept_argument(std::nullptr_t, functional_match_descriptor_ptr&, arg_context_type&, syntax_expression_result_t&) const;
};

}
