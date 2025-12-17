//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"

#include <algorithm>
#include <memory>
#include <utility>

#include "sonia/config.hpp"
#include "functional_binding.hpp"

namespace annium {

basic_functional_binding::basic_functional_binding()
    : resource_{ nullptr }
    , items_{ nullptr }
    , size_{ 0 }
{}

basic_functional_binding::basic_functional_binding(item* pitem, size_t sz, std::pmr::memory_resource* resource)
    : resource_{ resource ? resource : std::pmr::get_default_resource() }
    , items_{ pitem }
    , size_{ sz }
{
    BOOST_ASSERT(items_ != nullptr || size_ == 0);

    if (size_ > 1 && items_) {
        std::sort(items_, items_ + size_, [](item const& lhs, item const& rhs) {
            return lhs.name < rhs.name;
        });
    }
}

basic_functional_binding::basic_functional_binding(basic_functional_binding const& other)
    : resource_{ other.resource_ }
    , items_{ nullptr }
    , size_{ 0 }
{
    copy_from(other);
}

basic_functional_binding::basic_functional_binding(basic_functional_binding&& other) noexcept
    : resource_{ other.resource_ }
    , items_{ other.items_ }
    , size_{ other.size_ }
{
    other.items_ = nullptr;
    other.size_ = 0;
}

basic_functional_binding::~basic_functional_binding()
{
    destroy_items();
}

basic_functional_binding& basic_functional_binding::operator=(basic_functional_binding const& other)
{
    if (this == &other) {
        return *this;
    }

    basic_functional_binding tmp(other);
    swap(tmp);
    return *this;
}

basic_functional_binding& basic_functional_binding::operator=(basic_functional_binding&& other) noexcept
{
    if (this == &other) {
        return *this;
    }

    destroy_items();
    resource_ = other.resource_;
    items_ = other.items_;
    size_ = other.size_;
    other.items_ = nullptr;
    other.size_ = 0;
    return *this;
}

functional_binding::value_type const* basic_functional_binding::lookup(identifier name, resource_location const** location) const noexcept
{
    if (!items_ || size_ == 0) {
        return nullptr;
    }

    auto first = items_;
    auto last = items_ + size_;
    auto it = std::lower_bound(first, last, name, [](item const& lhs, identifier rhs) {
        return lhs.name < rhs;
    });

    if (it == last || !(it->name == name)) {
        return nullptr;
    }

    if (location) {
        *location = &it->location;
    }

    return &it->value;
}

void basic_functional_binding::destroy_items() noexcept
{
    if (!items_) {
        return;
    }

    std::destroy_n(items_, size_);
    resource_->deallocate(items_, size_ * sizeof(item), alignof(item));
    items_ = nullptr;
    size_ = 0;
}

void basic_functional_binding::copy_from(basic_functional_binding const& other)
{
    if (!other.items_ || other.size_ == 0) {
        return;
    }

    item* new_items = static_cast<item*>(resource_->allocate(other.size_ * sizeof(item), alignof(item)));
    size_t constructed = 0;
    try {
        for (; constructed < other.size_; ++constructed) {
            std::construct_at(new_items + constructed, other.items_[constructed]);
        }
    } catch (...) {
        std::destroy_n(new_items, constructed);
        resource_->deallocate(new_items, other.size_ * sizeof(item), alignof(item));
        throw;
    }

    items_ = new_items;
    size_ = other.size_;
}

void basic_functional_binding::swap(basic_functional_binding& other) noexcept
{
    using std::swap;
    swap(resource_, other.resource_);
    swap(items_, other.items_);
    swap(size_, other.size_);
}

}
