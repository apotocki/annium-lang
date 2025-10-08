//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <ostream>

#include "annium/semantic_fwd.hpp"
//#include "annium/semantic.hpp"
//#include "annium/entities/functional.hpp"

namespace annium {

class environment;

// it's not a signatured entity becase an external function can have different signatures,
// depending on the values of arguments
class external_function_entity : public entity
{
    uint32_t extfnid_;

public:
    inline explicit external_function_entity(size_t fnid)
        : extfnid_{ static_cast<uint32_t>(fnid) }
    {
    }

    inline size_t extfnid() const noexcept { return extfnid_; }

    void visit(entity_visitor const& v) const override { v(*this); }

    inline size_t hash() const noexcept override final
    {
        return sonia::hasher{}(extfnid_);
    }

    inline bool equal(entity const& rhs) const noexcept override
    {
        if (auto const* pent = dynamic_cast<external_function_entity const*>(&rhs)) {
            return pent->extfnid_ == extfnid_;
        }
        return false;
    }

    inline std::ostream& print_to(std::ostream& os, environment const&) const override
    {
        return os << "external fn(id: "sv << extfnid_ << ")"sv;
    }
};

}
