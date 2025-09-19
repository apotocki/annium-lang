//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"
//#include "annium/errors.hpp"

namespace annium {

class signature_matcher_visitor : public static_visitor<error_storage>
{
    fn_compiler_context & ctx_;
    functional_binding& binding_;
    entity_identifier eid_;

public:
    signature_matcher_visitor(fn_compiler_context&, functional_binding&, entity_identifier);

    result_type operator()(qname_reference const&) const;
    //result_type operator()(function_call_t const& sp) const;

    // returns true if implicit cast was applied
    //std::expected<bool, error_storage> try_match(fn_compiler_context&, syntax_expression_t const&) const;

    template <typename T>
    result_type operator()(T const& v) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("signature_matcher_visitor not implemented expression");
    }
};

}
