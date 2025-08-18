//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

class metaobject_argument_pattern : public functional::pattern
{
public:
    metaobject_argument_pattern() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

protected:
    entity_signature const& argument_signature(fn_compiler_context&, functional_match_descriptor&) const;
};

}
