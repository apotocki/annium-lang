//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/semantic_fwd.hpp"
#include "annium/environment.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

template <typename ValueT>
class literal_entity : public entity
{
    ValueT value_;
    entity_identifier type_;

public:
    template <typename ArgT>
    literal_entity(ArgT&& v, entity_identifier t)
        : value_{ std::forward<ArgT>(v) }
        , type_{ std::move(t) }
    {}

    template <typename ArgT>
    requires(!is_same_v<literal_entity, remove_cvref_t<ArgT>>)
    explicit literal_entity(ArgT&& v)
        : value_{ std::forward<ArgT>(v) }
    {}

    void visit(entity_visitor const& v) const override { v(*this); }

    entity_identifier get_type() const noexcept override { return type_; }
    inline void set_type(entity_identifier type) noexcept { type_ = type; }

    ValueT const& value() const { return value_; }

    size_t hash() const noexcept override { return hasher{}(value_, type_); }

    bool equal(entity const& rhs) const noexcept override
    {
        if (literal_entity const* pr = dynamic_cast<literal_entity const*>(&rhs); pr) {
            return pr->value_ == value_ && pr->type_ == type_;
        }
        return false;
    }

    std::ostream& print_to(std::ostream& os, environment const& e) const override
    {
        if constexpr (std::is_same_v<ValueT, identifier> || std::is_same_v<ValueT, qname_identifier> || std::is_same_v<ValueT, qname>) {
            os << '\'';
            e.print_to(os, value_);
            os << '\'';
        } else if constexpr (std::is_same_v<ValueT, bool>) {
            os << (value_ ? "true"sv : "false"sv);
        } else if constexpr (std::is_same_v<ValueT, small_string>) {
            os << '"' << value_ << "\""sv;
        } else {
            os << value_;
        }
        os << "^^"sv;
        return e.print_to(os, type_);
    }
};

// typed empty_entity: entities with different types are not equal
template <>
class literal_entity<void> : public entity
{
    entity_identifier type_;

public:
    inline explicit literal_entity(entity_identifier t) noexcept
        : type_{ t }
    {}

    void visit(entity_visitor const& v) const override { v(*this); }

    entity_identifier get_type() const noexcept override { return type_; }
    inline void set_type(entity_identifier type) noexcept { type_ = type; }

    size_t hash() const noexcept override { return hasher{}(type_); }

    bool equal(entity const& rhs) const noexcept override
    {
        if (literal_entity const* pr = dynamic_cast<literal_entity const*>(&rhs); pr) {
            return pr->type_ == type_;
        }
        return false;
    }
    
    std::ostream& print_to(std::ostream& os, environment const& e) const override
    {
        return get_entity(e, type_).print_to(os << "unit^^"sv, e);
    }
};

}
