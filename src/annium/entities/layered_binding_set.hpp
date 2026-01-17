//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

#include "annium/entities/functional_binding.hpp"

namespace annium {

class layered_binding_set : public functional_binding
{
    struct binding_item
    {
        identifier name;
        functional_binding::value_type value;
        resource_location location;
        uint32_t layer;
    };

    using set_t = boost::multi_index::multi_index_container<
        binding_item,
        boost::multi_index::indexed_by<
            boost::multi_index::hashed_unique<
                boost::multi_index::member<binding_item, identifier, &binding_item::name>
            >,
            boost::multi_index::hashed_non_unique<
                boost::multi_index::member<binding_item, uint32_t, &binding_item::layer>
            >
        >
    >;

    set_t set_;
    size_t bound_variables_count_{ 0 };
    uint32_t current_layer_ = (std::numeric_limits<uint32_t>::max)();

public:
    value_type const* lookup(identifier, resource_location const** = nullptr) const noexcept override;
    void emplace_back(annotated_identifier, value_type);

    void emplace_back(uint32_t, annotated_identifier, value_type);
    void remove_layer(uint32_t layer);

    inline size_t variables_count() const noexcept { return bound_variables_count_; }

    inline void set_current_layer(uint32_t layer) noexcept { current_layer_ = layer; }

    inline size_t size() const noexcept { return set_.size(); }
    inline bool empty() const noexcept { return set_.empty(); }

    basic_functional_binding to_basic_functional_binding(std::pmr::memory_resource* = nullptr) const;
};

}
