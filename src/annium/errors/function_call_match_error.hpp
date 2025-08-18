//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/errors.hpp"

namespace annium {

class function_call_match_error : public general_error
{
public:
    annotated_qname_identifier functional_;
    //function_signature const* signature_;
    error_storage reason_;

    function_call_match_error(annotated_qname_identifier f, /*function_signature const* signature,*/ error_storage reason)
        : functional_{ f }
        //, signature_{ signature }
        , reason_{ reason }
    {}

    void visit(error_visitor& vis) const override { vis(*this); }

    location_t location() const noexcept override { return functional_.location; }
    string_t object(environment const&) const noexcept override;
    string_t description(environment const&) const noexcept override;
};

}
