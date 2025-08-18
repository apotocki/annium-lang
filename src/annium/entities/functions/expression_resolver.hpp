//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

class expression_resolver : public functional::entity_resolver
{
    resource_location location_;
    syntax_expression_t expression_;

public:
    expression_resolver(resource_location, syntax_expression_t const& expr);

    std::expected<entity_identifier, error_storage> const_resolve(fn_compiler_context&) const override;
    resource_location const& location() const override;
};

}
