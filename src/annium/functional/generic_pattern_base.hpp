//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"

namespace annium {

template <typename DerivedT>
class generic_pattern_base : public functional::pattern
{
public:
    generic_pattern_base() = default;

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

protected:
    struct arg_context_type;

    template <typename CookieT>
    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, CookieT&&) const;

    DerivedT const& derived() const { return static_cast<DerivedT const&>(*this); }
};

}
