//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/small_vector.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class internal_function_entity;

class basic_fn_pattern : public functional::pattern
{
    friend class parameter_matcher;

public:
    class parameter_descriptor
    {
        identifier ename_or_alias_;
        identifier iname_;
        resource_location ename_or_alias_loc_;
        resource_location iname_loc_;
        union {
            syntax_expression const* expression_constraint_;
            syntax_pattern const* pattern_constraint_;
        };
        syntax_expression const* default_value_;
        uint8_t has_ename_ : 1;
        uint8_t has_expression_constraint_ : 1;
        uint8_t is_required_value_ : 1; // otherwise default_value or optional

        parameter_constraint_modifier_t modifier_;

    public:
        inline parameter_descriptor(
            annotated_identifier ename,
            annotated_identifier iname,
            std::variant<syntax_expression const*, syntax_pattern const*> const& constraint,
            std::variant<required_t, optional_t, syntax_expression const*> const& default_value,
            parameter_constraint_modifier_t m) noexcept
            : ename_or_alias_{ ename.value }, iname_{ iname.value }
            , has_ename_{ 0 }, has_expression_constraint_{ 0 }, is_required_value_{ 1 }
            , modifier_{ m }
        {
            if (ename) {
                ename_or_alias_loc_ = std::move(ename.location);
                has_ename_ = 1;
            }
            if (iname) {
                iname_loc_ = std::move(iname.location);
            }
            std::visit([this](auto const* pc) {
                if constexpr (std::is_same_v<decltype(pc), syntax_expression const*>) {
                    expression_constraint_ = pc;
                    has_expression_constraint_ = 1;
                } else {
                    pattern_constraint_ = pc;
                    has_expression_constraint_ = 0;
                }
            }, constraint);
            std::visit([this](auto pc) {
                if constexpr (std::is_same_v<decltype(pc), required_t>) {
                    is_required_value_ = 1;
                    default_value_ = nullptr;
                } else if constexpr (std::is_same_v<decltype(pc), optional_t>) {
                    is_required_value_ = 0;
                    default_value_ = nullptr;
                } else {
                    is_required_value_ = 0;
                    default_value_ = pc;
                }
            }, default_value);
        }

        inline void set_alias(annotated_identifier alias_name) noexcept
        {
            BOOST_ASSERT(!has_ename_);
            ename_or_alias_ = alias_name;
            ename_or_alias_loc_ = alias_name.location;
        }

        inline annotated_identifier ename() const noexcept
        {
            if (has_ename_) {
                return annotated_identifier{ ename_or_alias_, ename_or_alias_loc_ };
            } else {
                return annotated_identifier{};
            }
        }

        inline annotated_identifier iname() const noexcept
        {
            return annotated_identifier{ iname_, iname_loc_ };
        }

        inline annotated_identifier name() const noexcept
        {
            if (iname_) {
                return annotated_identifier{ iname_, iname_loc_ };
            } else {
                BOOST_ASSERT(has_ename_);
                return annotated_identifier{ ename_or_alias_, ename_or_alias_loc_ };
            }
        }

        inline annotated_identifier alias_name() const noexcept
        {
            if (!has_ename_) {
                return annotated_identifier{ ename_or_alias_, ename_or_alias_loc_ };
            } else {
                return annotated_identifier{};
            }
        }

        inline bool has_expression_constraint() const noexcept { return has_expression_constraint_; }
        inline bool has_pattern_constraint() const noexcept { return !has_expression_constraint_; }
        inline syntax_expression const* expression_constraint() const noexcept { BOOST_ASSERT(has_expression_constraint_); return expression_constraint_; }
        inline syntax_pattern const* pattern_constraint() const noexcept { BOOST_ASSERT(!has_expression_constraint_); return pattern_constraint_; }
        inline syntax_expression const* default_value() const noexcept { return default_value_; }
        inline bool is_required_value() const noexcept { return is_required_value_; }
        inline parameter_constraint_modifier_t modifier() const noexcept { return modifier_; }
    };
    
    struct parameter_descriptor_obs
    {
        annotated_identifier ename;
        small_vector<annotated_identifier, 2> inames;
        std::variant<syntax_expression const*, syntax_pattern const*> constraint;
        std::variant<required_t, optional_t, syntax_expression const*> default_value;
        parameter_constraint_modifier_t modifier;

        inline annotated_identifier name() const noexcept { return inames.front(); }
    };
    
protected:
    // in the order of declaration (fn_pure)
    using parameters_t = small_vector<parameter_descriptor, 8>;
    parameters_t parameters_;

    std::variant<nullptr_t, syntax_expression, syntax_pattern> result_; // auto or type/value expression or pattern

public:
    basic_fn_pattern() = default;

    error_storage init(fn_compiler_context&, fn_pure const&);

    std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const override;

    std::ostream& print(environment const&, std::ostream& s) const override;

protected:
    std::pair<syntax_expression_result, size_t> apply_arguments(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const;
    
    // builds entity that represents the function
    virtual shared_ptr<internal_function_entity> build(fn_compiler_context&, entity_signature&&, basic_functional_binding&&) const;
    virtual void build_scope(environment&, basic_functional_binding&&, internal_function_entity& /* out */) const;
};

}
