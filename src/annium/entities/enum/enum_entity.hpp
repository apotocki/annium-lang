//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/optional.hpp"
#include "annium/entities/signatured_entity.hpp"

namespace annium {

class functional;

class enum_entity : public basic_signatured_entity
{
    qname name_;
    std::vector<identifier> cases_;

public:
    enum_entity(environment& e, functional& fn, std::vector<identifier> cases);

    inline qname_view name() const noexcept { return name_; }

    optional<size_t> find(identifier) const;
    inline identifier const& case_at(size_t which) const noexcept { return cases_[which]; }
    inline size_t case_count() const noexcept { return cases_.size(); }
    /*
    struct enum_case
    {
        identifier name;
        value_t value;

        template <typename VArgT>
        enum_case(identifier n, VArgT && v) : name{ std::move(n) }, value{ std::forward<VArgT>(v) } {}

        friend inline bool operator==(enum_case const& l, enum_case const& r) { return l.name == r.name; }
        friend inline auto operator<=>(enum_case const& l, enum_case const& r) { return l.name <=> r.name; }
    };

    std::vector<enum_case> cases;

    
    */
};

}
