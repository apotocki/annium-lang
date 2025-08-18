//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "metaobject_argument_pattern.hpp"

namespace annium {

class metaobject_head_pattern : public metaobject_argument_pattern
{
public:
    metaobject_head_pattern() = default;

    std::expected<syntax_expression_result_t, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override { return s << "head(metaobject)"sv; }
};

}
