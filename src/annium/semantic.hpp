//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <bit>
#include <vector>
#include <utility>

#include "sonia/variant.hpp"
#include "sonia/string.hpp"

#include "annium/utility/linked_list.hpp"
#include "annium/utility/linked_list.ipp"

#include "semantic_fwd.hpp"
#include "ast_terms.hpp"
//#include "annium/entities/variable_entity.hpp"

namespace annium {

// ======================================================================== types
#if 0
struct annium_object_t
{
    entity const* value;

    inline bool operator==(annium_object_t const& rhs) const { return value == rhs.value; };
    auto operator<=>(annium_object_t const& rhs) const;

    entity_identifier id() const;
};

template <typename T> struct annium_tuple
{
    std::vector<T> fields;
    std::vector<std::tuple<annotated_identifier, T>> named_fields;
    bool unpacked = false;

    inline bool operator==(annium_tuple const&) const = default;
    inline auto operator<=>(annium_tuple const& r) const
    {
        if (auto res = std::lexicographical_compare_three_way(
            fields.begin(), fields.end(), r.fields.begin(), r.fields.end(), variant_compare_three_way{});
            res != std::strong_ordering::equivalent) return res;
        return std::lexicographical_compare_three_way(
            named_fields.begin(), named_fields.end(), r.named_fields.begin(), r.named_fields.end(),
            [](auto const& ltpl, auto const& rtpl) {
                if (auto res = std::get<0>(ltpl).value <=> std::get<0>(rtpl).value; res != std::strong_ordering::equivalent) return res;
                return variant_compare_three_way{}(std::get<1>(ltpl), std::get<1>(ltpl));
            });
    }

    inline bool empty() const noexcept { return fields.empty() && named_fields.empty(); }
};
#endif

//template <typename T> using annium_fn = annium_fn_base<annium_tuple<T>, T>;

//struct annium_particular_bool_t
//{
//    bool value;
//    inline bool operator==(annium_particular_bool_t const&) const = default;
//    inline auto operator<=>(annium_particular_bool_t const&) const = default;
//};

template <typename T> struct annium_bunion
{
    T true_type;
    T false_type;

    inline bool operator==(annium_bunion const& rhs) const = default; // { return true_type == rhs.true_type && false_type == rhs.false_type; };
    inline auto operator<=>(annium_bunion const& rhs) const = default;
    /*
    {
        if (auto res = true_type <=> rhs.true_type; res != std::strong_ordering::equivalent) return res;
        return false_type <=> rhs.false_type;
    }
    */
};

#if 0
template <typename T> struct annium_union
{
    boost::container::small_vector<T, 8> other_members;
    // 1 reserved for initial state value -1
    enum class basic_type : uint16_t {
        nothing_e = 0, nil_e = 2, bool_e = 4, int_e = 8, float_e = 16, decimal_e = 32, string_e = 64,
        any_e = 128,
        max_type_e = 128
    };
    uint16_t basic_members = 0;
    
    struct member_iterator
    {
        using value_type = T;

        annium_union const* un_;
        T store_ = annium_any_t{};
        int state_;

        member_iterator() : un_ {nullptr} {}

        member_iterator(annium_union const& un, int state) : un_{ &un }, state_{ state }
        {
            next();
        }
        //  (int)basic_type::max_type_e
        void next()
        {
            while (un_) {
                if (state_ >= 0) {
                    if (++state_ >= un_->other_members.size()) {
                        un_ = nullptr;
                    }
                    return;
                } else {
                    state_ *= 2;
                }
                if (-state_ > (int)basic_type::max_type_e) {
                    state_ = 0;
                    if (un_->other_members.empty()) {
                        un_ = nullptr;
                    }
                    return;
                }
                if (un_->basic_members & (-state_)) {
                    switch((basic_type)(-state_)) {
                    case basic_type::nil_e:
                        store_ = annium_tuple<T>{};
                        return;
                    //case basic_type::bool_e:
                    //    store_ = annium_bool_t{};
                    //    return;
                    //case basic_type::int_e:
                    //    store_ = annium_int_t{};
                    //    return;
                    //case basic_type::float_e:
                    //    store_ = annium_float_t{};
                    //    return;
                    //case basic_type::decimal_e:
                    //    store_ = annium_decimal_t{};
                    //    return;
                    //case basic_type::string_e:
                    //    store_ = annium_string_t{};
                    //    return;
                    //case basic_type::any_e:
                    //    store_ = annium_any_t{};
                    //    return;
                    default:
                        THROW_INTERNAL_ERROR("unknown union member type");
                    }
                }
            }
        }

        T const& operator*() const
        {
            if (state_ < 0) {
                return store_;
            } else {
                return un_->other_members[state_];
            }
        }

        void operator++()
        {
            next();
        }

        inline bool operator==(member_iterator const& rhs) const { return !un_ ? !rhs.un_ : (un_ == rhs.un_ && state_ == rhs.state_); }
    };

    member_iterator begin() const { return member_iterator(*this, -1); }
    member_iterator end() const { return member_iterator(); }

    //inline auto to_tuple() const noexcept { std::tuple{ bool_member }; }

    inline bool operator==(annium_union const& r) const
    {
        return basic_members == r.basic_members && other_members == r.other_members;
    }

    inline auto operator<=>(annium_union const& r) const
    {
        if (auto res = basic_members <=> r.basic_members; res != std::strong_ordering::equivalent) return res;
        return std::lexicographical_compare_three_way(other_members.begin(), other_members.end(), r.other_members.begin(), r.other_members.end(), variant_compare_three_way{});
    }

    size_t size() const
    {
        return other_members.size() + std::popcount(basic_members);
    }

    struct appender_visitor : static_visitor<void>
    {
        annium_union & un_;
        explicit appender_visitor(annium_union & e) : un_{e} {}

        //inline void operator()(annium_bool_t) const { un_.basic_members |= (uint8_t)basic_type::bool_e; }
        //inline void operator()(annium_int_t) const { un_.basic_members |= (uint8_t)basic_type::int_e; }
        //inline void operator()(annium_float_t) const { un_.basic_members |= (uint8_t)basic_type::float_e; }
        //inline void operator()(annium_decimal_t) const { un_.basic_members |= (uint8_t)basic_type::decimal_e; }
        //inline void operator()(annium_string_t) const { un_.basic_members |= (uint8_t)basic_type::string_e; }
        //inline void operator()(annium_any_t) const { un_.basic_members |= (uint8_t)basic_type::any_e; }

        inline void operator()(annium_union e) const
        {
            for (auto const& m : e) { this->operator()(m); }
        }

        inline void operator()(annium_tuple<T> t) const
        {
            if (t.empty()) {
                un_.basic_members |= (uint8_t)basic_type::nil_e;
            } else {
                append(std::move(t));
            }
        }

        inline void operator()(T arg) const
        {
            apply_visitor(*this, std::move(arg));
        }

        template <typename TypeT>
        inline void operator()(TypeT arg) const
        {
            append(std::move(arg));
        }

        void append(T arg) const
        {
            auto it = std::lower_bound(un_.other_members.begin(), un_.other_members.end(), arg);
            if (it != un_.other_members.end() && *it == arg) return; // already exists
            un_.other_members.insert(it, std::move(arg));
        }
    };

    template <typename ArgT>
    inline void append(ArgT && m)
    {
        appender_visitor{ *this }(std::forward<ArgT>(m));
    }

    //inline bool has(annium_bool_t const&) const { return !!(basic_members & (uint16_t)basic_type::bool_e); }
    //inline bool has(annium_int_t const&) const { return !!(basic_members & (uint16_t)basic_type::int_e); }
    //inline bool has(annium_float_t const&) const { return !!(basic_members & (uint16_t)basic_type::float_e); }
    //inline bool has(annium_decimal_t const&) const { return !!(basic_members & (uint16_t)basic_type::decimal_e); }
    //inline bool has(annium_string_t const&) const { return !!(basic_members & (uint16_t)basic_type::string_e); }
    inline bool has(annium_tuple<T> const& t) const
    {
        if (t.empty()) return !!(basic_members & (uint16_t)basic_type::nil_e);
        auto it = std::lower_bound(other_members.begin(), other_members.end(), T{t});
        return it != other_members.end() && *it == t;
    }
    template <typename ArgT>
    bool has(T const& t)
    {
        auto it = std::lower_bound(other_members.begin(), other_members.end(), T{t});
        return it != other_members.end() && *it == t;
    }
};
#endif

//using annium_type_variant = make_recursive_variant<
//    annium_any_t, annium_bool_t, annium_int_t, annium_float_t, annium_decimal_t, annium_string_t, annium_object_t,
//    annium_fn<recursive_variant_>,
//    annium_vector<recursive_variant_>,
//    annium_array<recursive_variant_>,
//    annium_tuple<recursive_variant_>,
//    annium_union<recursive_variant_>,
//    annium_bunion<recursive_variant_>
//>::type;


#if 0
struct annium_type;
using annium_type_variant = variant<
    annium_any_t, annium_object_t,
    recursive_wrapper<annium_fn<annium_type>>,
    recursive_wrapper<annium_vector<annium_type>>,
    recursive_wrapper<anniumarray<annium_type>>,
    recursive_wrapper<annium_tuple<annium_type>>,
    recursive_wrapper<annium_union<annium_type>>,
    recursive_wrapper<annium_bunion<annium_type>>
>;

struct annium_type : annium_type_variant
{
    template <typename T>
    requires(!std::is_same_v<annium_type, std::remove_cvref_t<T>>)
    annium_type(T && val) : annium_type_variant(std::forward<T>(val)) {}

    annium_type(annium_type const&) = default;
    annium_type(annium_type &&) = default;
    annium_type& operator=(annium_type const&) = default;
    annium_type& operator=(annium_type&&) = default;

    template <typename T>
    annium_type& operator=(T&& val) { annium_type_variant::operator= (std::forward<T>(val)); return *this; }

    template <typename T>
    inline bool operator==(T const& rhs) const { return annium_type_variant::operator==(annium_type_variant{rhs}); }
    inline bool operator==(annium_type const& rhs) const { return annium_type_variant::operator==(static_cast<annium_type_variant const&>(rhs)); }

    inline auto operator<=>(annium_type const& rhs) const { return variant_compare_three_way{}(*this, rhs); }

    template <typename T>
    T const* as() const { return get<T>(static_cast<annium_type_variant const*>(this)); }
};

//using annium_vector_t = annium_vector<annium_type>;
//using annium_array_t = annium_array<annium_type>;
//using annium_tuple_t = annium_tuple<annium_type>;
//using annium_union_t = annium_union<annium_type>;
//using annium_bunion_t = annium_bunion<annium_type>;
using annium_fn_t = annium_fn<annium_type>;

annium_type make_union_type(annium_type, annium_type const*);
annium_type operator|| (annium_type const& l, annium_type const& r);
annium_type operator- (annium_union_t const& l, annium_type const& r);
#endif
// ======================================================================== function

//class symbol
//{
//public:
//    explicit symbol(qname_identifier id) : id_{ id } {}
//
//private:
//    qname_identifier id_;
//    boost::container::small_vector<entity_identifier, 4> entities_;
//    boost::container::small_vector<identifier, 4> names_;
//
//    // entities_.size() >= names_.size();
//};

namespace semantic {

enum class push_by_base : uint8_t
{
    stack_top,
    frame_bottom
};

struct push_by_offset { intptr_t offset; push_by_base base = push_by_base::stack_top; }; // offset from the stack top
struct push_value
{
    value_t value;
    explicit push_value(value_t v) : value { std::move(v) }
    {
        //if (auto* bv = get_if<smart_blob>(&value); bv) {
        //    std::ostringstream ss;
        //    print_type(ss, bv->get());
        //    //BOOST_ASSERT((uint8_t)(*bv)->type != 0xcd);
        //}
    }
};
struct push_local_variable
{
    variable_identifier varid;

    inline static push_local_variable create(local_variable const& v) noexcept
    {
        return push_local_variable{ .varid = v.varid };
    }
};

struct push_special_value
{
    enum class kind_type : uint8_t
    {
        stack_size
    };

    kind_type kind;
};

struct set_local_variable
{
    variable_identifier varid;

    inline static set_local_variable create(local_variable const& v) noexcept
    {
        return set_local_variable{ .varid = v.varid };
    }
};

//struct stack_frame_begin {};
//struct stack_frame_end {};
struct push_variable { functional_variable var; };
struct dup_stack_top {};
struct set_variable { functional_variable var; };
struct set_by_offset { size_t offset; }; // offset from the stack top
struct truncate_values
{
    uint16_t count;
    uint16_t keep_back = 0;
};

// takes the value on top of the stack as an integer, applies shift to it,
// and replaces the value on top of the stack with the stacked value at that offset
// stack.back() = stack[stack.back() + shift]
struct indexs
{
    int64_t shift;
};

struct invoke_function
{
    //qname_identifier varname;
    entity_identifier fn;
};

struct invoke_context_function
{

};
//enum class condition_type : uint8_t
//{
//    logic,
//    optionality
//};


//template <typename SemanticExpressionT>
//struct logic_tree_node
//{
//    std::vector<SemanticExpressionT> condition_expression;
//    annium_type expression_type = annium_tuple_t{};
//    shared_ptr<logic_tree_node> true_branch;
//    shared_ptr<logic_tree_node> false_branch;
//};

struct expression_entry;
using expression_span = linked_list_node_span<expression_entry>;

struct return_statement
{
    expression_span scope_deconstruction; // Expressions to be evaluated for scope destruction after (or before) evaluation of result expressions
};

struct yield_statement
{
    expression_span result;
    size_t scope_size; // Numebr of elements on stack after evaluation of result expressions
    entity_identifier value_or_type;
    bool is_const_value_result;
};

struct conditional_t
{
    //condition_type type;
    expression_span true_branch;
    expression_span false_branch;
    uint8_t true_branch_finished : 1;
    uint8_t false_branch_finished : 1;

    conditional_t() : true_branch_finished{ 0 }, false_branch_finished{ 0 } {}
};

struct switch_t
{
    std::vector<expression_span> branches;
};

struct not_empty_condition_t
{
    expression_span branch;
};

struct loop_scope_t
{
    expression_span branch;
    expression_span continue_branch;
};

struct loop_continuer {};
struct loop_breaker {};

using expression = std::variant<
    empty_t, // no op
    push_value, push_local_variable, push_by_offset, push_special_value, push_variable, dup_stack_top, truncate_values,
    set_local_variable, set_variable, set_by_offset,
    //stack_frame_begin, stack_frame_end,
    invoke_context_function,
    invoke_function, return_statement, yield_statement, loop_breaker, loop_continuer,
    indexs,
    expression_span,
    conditional_t, switch_t,
    not_empty_condition_t,
    loop_scope_t
    //logic_tree_node<recursive_variant_>
>;

using expression_entry_type = linked_list_node<expression>;
struct expression_entry : expression_entry_type { using expression_entry_type::expression_entry_type; };

//using conditional_t = conditional<expression>;
//using not_empty_condition_t = not_empty_condition<expression>;
//using loop_scope_t = loop_scope<expression>;
//using logic_tree_node_t = logic_tree_node<expression_t>;

using expression_list_t = linked_list<expression>;
using managed_expression_list = managed_linked_list<expression, environment>;

}

struct syntax_expression_result
{
    // {variable, initilizing expressions}
    small_vector<std::tuple<local_variable, semantic::expression_span>, 2> temporaries;

    // because expressions with branches like if, for, while, etc. don't own their expressions, we need to store them separately
    semantic::expression_span branches_expressions;

    semantic::expression_span expressions;

    entity_identifier value_or_type;
    bool is_const_result;

    // if is_const_result is true, value_or_type is a value entity identifier and we ignore temporaries, expressions, and branches_expressions

    inline entity_identifier const& type() const
    {
        BOOST_ASSERT(!is_const_result);
        return value_or_type;
    }

    inline entity_identifier const& value() const
    {
        BOOST_ASSERT(is_const_result);
        return value_or_type;
    }
};

struct syntax_expression_const_result
{
    semantic::expression_span expressions;
    entity_identifier value;
};

//using syntax_expression_result = syntax_expression_result<semantic::managed_expression_list>;
//using syntax_expression_result_reference_t = syntax_expression_result<semantic::expression_span>;

using syntax_expression_const_result_t = syntax_expression_const_result; // syntax_expression_const_result<semantic::managed_expression_list>;

void append_semantic_result(semantic::expression_list_t & el, syntax_expression_result& src, syntax_expression_result& dest);
void append_semantic_result_to_branch(semantic::expression_list_t& el, syntax_expression_result& src, syntax_expression_result& dest, semantic::expression_span &dest_branch);
void append_branch_semantic_result(semantic::expression_list_t& el, syntax_expression_result& src, syntax_expression_result& dest);

syntax_expression make_indirect_value(environment&, semantic::expression_list_t&, syntax_expression_result && res, resource_location loc);
syntax_expression_result retrieve_indirect(environment&, semantic::expression_list_t&, indirect_value const&);

syntax_expression make_indirect_expression(environment&, semantic::expression_list_t&, syntax_expression_result&& res, resource_location loc);
syntax_expression_result retrieve_indirect(environment&, semantic::expression_list_t&, indirect_expression const&);

}
