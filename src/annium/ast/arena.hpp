//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/function.hpp"
#include "sonia/span.hpp"
#include <memory_resource>
#include <vector>
#include <string>
#include <new>
#include <type_traits>
#include <utility>

namespace annium {

class arena {
public:
    explicit arena(std::size_t initialBlock = 64 * 1024,
        std::pmr::memory_resource* upstream = std::pmr::new_delete_resource())
        : mono_(initialBlock, upstream)
        , mr_(&mono_)
        , finalizers_{ mr_ } {
    }

    std::pmr::memory_resource* resource() noexcept { return mr_; }

    // Construct T in the arena and return a stable pointer.
    template <class T, class... Args>
    T* make(Args&&... args)
    {
        static_assert(!std::is_array_v<T>);
        std::pmr::polymorphic_allocator<T> pa(mr_);
        T* p = pa.allocate(1);
        std::allocator_traits<decltype(pa)>::construct(pa, p, std::forward<Args>(args)...);
        return p;
    }

    template <class T>
    inline span<T> make_array(size_t sz)
    {
        std::pmr::polymorphic_allocator<T> pa(mr_);
        T* p = pa.allocate(sz);
        return {p, sz};
    }

    template <class T>
    span<T const*> make_array(span<T const*> src)
    {
        span<T*> result = make_array<T*>(src.size());
        std::memcpy(result.data(), src.data(), src.size_bytes());
        return result;
    }

    template <class T>
    span<T> make_array(span<const T> src)
    {
        span<T> result = make_array<T>(src.size());

        if constexpr (std::is_trivially_copyable_v<T>) {
            std::memcpy(result.data(), src.data(), src.size_bytes());
        } else {
            T const* srcplace = src.data();
            for (T* place = result.data(); place < result.data() + src.size(); ++place, ++srcplace) {
                new (place) T(*srcplace);
            }
        }
        return result;
    }
    
    // PMR-aware containers/strings should be constructed with resource().
    using PmrString = std::basic_string<char, std::char_traits<char>, std::pmr::polymorphic_allocator<char>>;
    template <class T>
    using PmrVector = std::vector<T, std::pmr::polymorphic_allocator<T>>;

    // Register a non-recursive finalizer (iterative teardown).
    template <class F>
    void add_finalizer(F&& f) {
        finalizers_.emplace_back(std::forward<F>(f));
    }

    // Release all memory in O(1). First run finalizers iteratively to avoid recursion.
    void clear() {
        // Run in reverse construction order if needed.
        for (auto it = finalizers_.rbegin(); it != finalizers_.rend(); ++it) {
            (*it)();
        }
        finalizers_.clear();
        mono_.release();
    }

private:
    std::pmr::monotonic_buffer_resource mono_;
    std::pmr::memory_resource* mr_;
    PmrVector<sonia::function<void()>> finalizers_;
};

} // namespace annium
