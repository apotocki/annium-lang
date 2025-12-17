//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <memory_resource>
#include <variant>

#include "annium/ast_terms.hpp"
#include "annium/semantic_fwd.hpp"

namespace annium {

class functional_binding
{
public:
    virtual ~functional_binding() = default;

    using value_type = std::variant<entity_identifier, local_variable>;

    virtual value_type const* lookup(identifier, resource_location const** = nullptr) const noexcept = 0;
    //virtual void emplace_back(annotated_identifier, value_type) = 0;
};

class basic_functional_binding : public functional_binding
{
public:
    struct item
    {
        identifier name;
        value_type value;
        resource_location location;
    };

    basic_functional_binding();
    basic_functional_binding(item * pitem, size_t sz, std::pmr::memory_resource* = nullptr);
    basic_functional_binding(basic_functional_binding const&);
    basic_functional_binding(basic_functional_binding&&) noexcept;
    ~basic_functional_binding() override;

    basic_functional_binding& operator=(basic_functional_binding const&);
    basic_functional_binding& operator=(basic_functional_binding&&) noexcept;

    value_type const* lookup(identifier, resource_location const** = nullptr) const noexcept override;

    template <typename FT>
    requires std::is_invocable_v<FT, identifier, resource_location const&, value_type&>
    void for_each(FT&& ftor)
    {
        for (auto it = items_, eit = items_ + size_; it != eit; ++it) {
            std::forward<FT>(ftor)(it->name, it->location, it->value);
        }
    }

private:
    std::pmr::memory_resource* resource_;
    item* items_;
    size_t size_;

    void destroy_items() noexcept;
    void copy_from(basic_functional_binding const&);
    void swap(basic_functional_binding&) noexcept;
};

}
