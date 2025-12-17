//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/utility/polymorphic_traits.hpp"

#include "sonia/utility/lang/utility.hpp"
#include "sonia/utility/lang/qname.hpp"

#include "sonia/string.hpp"
#include "numetron/basic_decimal.hpp"

namespace annium {

using namespace sonia;

struct lex_tag;
struct entity_tag;
struct variable_tag;

using identifier = sonia::lang::identifier<uint32_t, lex_tag>;
using qname = sonia::lang::qname<identifier>;
using qname_view = sonia::lang::qname_view<identifier>;
using qname_identifier = sonia::lang::qname_identifier;
using entity_identifier = sonia::lang::identifier<uint32_t, entity_tag>;
using variable_identifier = sonia::lang::identifier<uint32_t, variable_tag>;

using resource_identifier = sonia::lang::lex::resource_identifier;
using resource_location = sonia::lang::lex::resource_location;
using code_resource = sonia::lang::lex::code_resource;
using resource_print_mode_t = sonia::lang::lex::resource_print_mode_t;

template <typename T>
struct annotated
{
    T value;
    resource_location location;

    inline bool operator==(annotated const& r) const noexcept { return value == r.value; }
    inline auto operator<=>(annotated const& r) const noexcept { return value <=> r.value; }

    inline explicit operator bool() const noexcept { return (bool)value; }

    operator T const& () const noexcept { return value; }

    inline annotated const& self_or(annotated const& def) const noexcept { return value ? *this : def; }
    inline T const& value_or(T const& def) const noexcept { return value ? value : def; }
};

using annotated_string_view = annotated<string_view>;
using annotated_identifier = annotated<identifier>;
using annotated_qname = annotated<qname>;
using annotated_qname_view = annotated<qname_view>;
using annotated_qname_identifier = annotated<qname_identifier>;
using annotated_entity_identifier = annotated<entity_identifier>;
using annotated_bool = annotated<bool>;
using annotated_integer = annotated<numetron::integer>;
using annotated_decimal = annotated<numetron::decimal>;
using annotated_integer_view = annotated<numetron::integer_view>;
using annotated_decimal_view = annotated<numetron::decimal_view>;
using annotated_string = annotated<small_string>;

struct annotated_nil
{
    resource_location location;
};

enum class value_modifier_t : uint8_t
{
    none = 0,
    runtime_value = 1,
    constexpr_value = 6,
    constexpr_or_runtime_value = 7
};

inline value_modifier_t operator|(value_modifier_t lhs, value_modifier_t rhs) noexcept
{
    return static_cast<value_modifier_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}

inline value_modifier_t operator&(value_modifier_t lhs, value_modifier_t rhs) noexcept
{
    return static_cast<value_modifier_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

inline bool can_be_constexpr(value_modifier_t m) noexcept
{
    return (m & value_modifier_t::constexpr_value) != value_modifier_t::none;
}

inline bool can_be_runtime(value_modifier_t m) noexcept
{
    return (m & value_modifier_t::runtime_value) == value_modifier_t::runtime_value;
}

inline bool can_be_only_constexpr(value_modifier_t m) noexcept
{
    return can_be_constexpr(m) && !can_be_runtime(m);
}

inline bool can_be_only_runtime(value_modifier_t m) noexcept
{
    return can_be_runtime(m) && !can_be_constexpr(m);
}

inline bool can_be_constexpr_and_runtime(value_modifier_t m) noexcept
{
    return can_be_constexpr(m) && can_be_runtime(m);
}

enum class parameter_constraint_modifier_t : uint8_t
{
    none = 0,
    runtime_type = 1,
    constexpr_type = 2,
    constexpr_or_runtime_type = 3,
    typename_value = 4,
    constexpr_not_a_typename_value = 8,
    constexpr_value = 12,
    any_constexpr = 14,
    ellipsis = 16
};

inline parameter_constraint_modifier_t operator|(parameter_constraint_modifier_t lhs, parameter_constraint_modifier_t rhs) noexcept
{
    return static_cast<parameter_constraint_modifier_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}

inline parameter_constraint_modifier_t operator&(parameter_constraint_modifier_t lhs, parameter_constraint_modifier_t rhs) noexcept
{
    return static_cast<parameter_constraint_modifier_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

inline bool has(parameter_constraint_modifier_t tested, parameter_constraint_modifier_t feature) noexcept
{
    return (tested & feature) == feature;
}

inline bool can_be_constexpr(parameter_constraint_modifier_t m) noexcept
{
    return (m & parameter_constraint_modifier_t::any_constexpr) != parameter_constraint_modifier_t::none;
}

inline bool can_be_runtime(parameter_constraint_modifier_t m) noexcept
{
    return (m & parameter_constraint_modifier_t::runtime_type) == parameter_constraint_modifier_t::runtime_type;
}

inline bool can_be_only_constexpr(parameter_constraint_modifier_t m) noexcept
{
    return can_be_constexpr(m) && !can_be_runtime(m);
}

inline bool can_be_only_runtime(parameter_constraint_modifier_t m) noexcept
{
    return can_be_runtime(m) && !can_be_constexpr(m);
}

inline bool can_be_constexpr_and_runtime(parameter_constraint_modifier_t m) noexcept
{
    return can_be_constexpr(m) && can_be_runtime(m);
}

inline value_modifier_t to_value_modifier(parameter_constraint_modifier_t m) noexcept
{
    return can_be_runtime(m) ? 
        (can_be_constexpr(m) ? value_modifier_t::constexpr_or_runtime_value : value_modifier_t::runtime_value) :
        (can_be_constexpr(m) ? value_modifier_t::constexpr_value : value_modifier_t::none);
}

class indirect : public sonia::polymorphic_clonable_and_movable
{
public:
    virtual ~indirect() = default;
};

}
