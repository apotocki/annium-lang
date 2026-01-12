//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"

#include <memory>
#include <memory_resource>

#include "sonia/config.hpp"
#include "layered_binding_set.hpp"

namespace annium {

functional_binding::value_type const* layered_binding_set::lookup(identifier id, resource_location const** pploc) const noexcept
{
    auto& index = set_.get<0>();
    auto it = index.find(id);
    if (it == index.end()) return nullptr;
    if (pploc) *pploc = &it->location;
    return &it->value;
}

void layered_binding_set::emplace_back(uint32_t layer, annotated_identifier id, value_type value)
{
    auto& index = set_.get<0>();
    auto it = index.find(id.value);
    if (it != index.end()) {
        THROW_INTERNAL_ERROR("layered_binding_set::emplace_back duplicate binding");
    }
    if (local_variable* pvar = get_if<local_variable>(&value); pvar) {
#ifdef SONIA_LANG_DEBUG
        pvar->debug_name = id;
#endif
        BOOST_ASSERT(pvar->type);
        ++bound_variables_count_;
    }
    index.emplace_hint(it, binding_item{ .name = id.value, .value = std::move(value), .location = id.location, .layer = layer });
}

void layered_binding_set::emplace_back(annotated_identifier id, value_type value)
{
    return emplace_back(current_layer_, id, value);
}

void layered_binding_set::remove_layer(uint32_t layer)
{
    auto& index = set_.get<1>();
    auto range = index.equal_range(layer);
    for (auto it = range.first; it != range.second; ++it) {
        binding_item const& bi = *it;
        if (local_variable const* pvar = get_if<local_variable>(&bi.value); pvar) {
            --bound_variables_count_;
        }
    }
    index.erase(range.first, range.second);
}

basic_functional_binding layered_binding_set::to_basic_functional_binding(std::pmr::memory_resource* resource) const
{
    auto* effective_resource = resource ? resource : std::pmr::get_default_resource();
    auto const size = set_.size();

    if (size == 0) {
        return basic_functional_binding(nullptr, 0, effective_resource);
    }

    std::pmr::polymorphic_allocator<basic_functional_binding::item> allocator{ effective_resource };
    auto* buffer = allocator.allocate(size);
    size_t constructed = 0;

    try {
        for (auto const& binding : set_) {
            std::construct_at(buffer + constructed,
                basic_functional_binding::item{ binding.name, binding.value, binding.location });
            ++constructed;
        }
    } catch (...) {
        std::destroy_n(buffer, constructed);
        allocator.deallocate(buffer, size);
        throw;
    }

    return basic_functional_binding(buffer, size, effective_resource);
}

}
