//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

class array_get_pattern : public functional::pattern
{
public:
    array_get_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;
    
    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "get(self: array(...), property: integer)~>auto"sv; }

protected:
    class array_get_match_descriptor : public functional_match_descriptor
    {
    public:
        inline array_get_match_descriptor(prepared_call const& call, entity_signature const& arr_type_sig_val) noexcept
            : functional_match_descriptor{ call }
            , arr_type_sig{ arr_type_sig_val }
        {}

        entity_signature const& arr_type_sig;
    };
};

}