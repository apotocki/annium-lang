//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"

namespace annium {

class identifier_redefinition_error : public general_error
{
    variant<qname_identifier, identifier> name_;
    resource_location location_;
    resource_location reflocation_;

public:
    template <typename SomethingT>
    identifier_redefinition_error(annotated<SomethingT> n, resource_location refloc)
        : name_{ std::move(n.value) }, location_{ std::move(n.location) }, reflocation_{ std::move(refloc) }
    {
    }

    void visit(error_visitor& vis) const override { vis(*this); }

    location_t location() const noexcept override { return location_; }
    string_t object(environment const&) const noexcept override;
    string_t description(environment const&) const noexcept override { return "identifier redefinition"sv; }
    resource_location const* ref_location() const noexcept override { return &reflocation_; }
};

}
