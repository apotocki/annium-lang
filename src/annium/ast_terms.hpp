//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

// implementation notes:
// if an ast term can embed other ast terms recursively, use pointer to arena-allocated term to avoid large struct sizes,
// e.g.: statement const* and expression const*,
// and collections of them are spans of pointers,
// e.g: span<statement const*> and span<syntax_expression const*>

#pragma once

#include <vector>
#include <cstdlib>
#include <tuple>
#include <variant>

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/cat.hpp>

#include "sonia/exceptions.hpp"
#include "sonia/optional.hpp"
#include "sonia/shared_ptr.hpp"
#include "sonia/function.hpp"
#include "sonia/small_vector.hpp"
#include "sonia/utility/functional/variant_compare_three_way.hpp"

#include "sonia/utility/automatic_polymorphic.hpp"

#include "annium/utility/linked_list.hpp"
#include "terms.hpp"
#include "annium/semantic_fwd.hpp"

#define ANNIUM_AST_INDIRECT_STORE_SIZE (8 * sizeof(void*))

namespace annium {

using namespace std::string_view_literals;
using namespace sonia;

class environment;
struct statement;
struct syntax_expression;

using statement_list_t = small_vector<statement, 1>;
using syntax_expression_list_t = small_vector<syntax_expression, 1>;
template <typename TermT> struct opt_named_term;
using opt_named_expression_t = opt_named_term<syntax_expression>;
using opt_named_expression_list_t = small_vector<opt_named_expression_t, 2>;

// e.g. fn (externalName: string); fn (externalName $internalName: string);
struct named_parameter_name
{
    annotated_identifier external_name; // can not be empty
    annotated_identifier internal_name; // can be empty
};

// e.g. $varName, $0, $$
struct context_identifier
{
    annotated_identifier name; // can not be empty
};

// e.g. fn ($internalName: string); fn (string);
struct unnamed_parameter_name
{
    annotated_identifier internal_name; // can be empty
};

using parameter_name = std::variant<named_parameter_name, unnamed_parameter_name>;

struct param_name_retriever : static_visitor<std::tuple<annotated_identifier const*, annotated_identifier const*>>
{
    param_name_retriever() = default;

    inline result_type operator()(named_parameter_name const& np) const
    {
        return { &np.external_name, np.internal_name ? &np.internal_name : nullptr };
    }

    inline result_type operator()(unnamed_parameter_name const& np) const
    {
        return { nullptr, np.internal_name ? &np.internal_name : nullptr };
    }
};

struct annium_fn_type
{
    span<const opt_named_expression_t> args;
    syntax_expression const* result;
};

// ========================================================================

#define ANNIUM_PRINT_SIMPLE_ENUM(r, data, elem) elem,

/*
#define OPERATOR_ENUM (POSTFIX_INCREMENT)(POSTFIX_DECREMENT)(PERIOD)(ARROW)(DBLCOLON)(POSTFIX_CLOSE_BROKET)(POSTFIX_RIGHTSHIFT) \
    (PREFIX_INCREMENT)(PREFIX_DECREMENT)(PREFIX_PLUS)(PREFIX_MINUS)(PREFIX_INV)(PREFIX_BITINV)(TYPE_CAST)(PREFIX_DEREF)(PREFIX_ADDRESS)(SIZEOF) \
    (MBPTR)(PTRMBPTR)\
    (MUL)(DIV)(MOD)\
    (PLUS)(MINUS)\
    (LEFTSHIFT)(RIGHTSHIFT)\
    (LESS)(LE)(GREATER)(GE)\
    (EQ)(NE)\
    (BITAND)(BITXOR)(BITOR)\
    (AND)(OR)\
    (IFF)(ASSIGN)(ADDASSIGN)(SUBASSIGN)(MULASSIGN)(DIVASSIGN)(MODASSIGN)(LSHIFTSSIGN)(RSHIFTSSIGN)(BITANDASSIGN)(BITORASSIGN)(BITXORASSIGN)(THROW)\
    (COMMA)
*/

#define ANNIUM_UNARY_OPERATOR_ENUM (NEGATE)(DEREF)(ELLIPSIS)(MINUS)
#define ANNIUM_BINARY_OPERATOR_ENUM (ASSIGN)(LOGIC_AND)(LOGIC_OR)(BIT_OR)(BIT_AND)(CONCAT)(PLUS)(MINUS)(EQ)(NE)
enum class unary_operator_type
{
    BOOST_PP_SEQ_FOR_EACH(ANNIUM_PRINT_SIMPLE_ENUM, _, ANNIUM_UNARY_OPERATOR_ENUM)
};

enum class binary_operator_type
{
    BOOST_PP_SEQ_FOR_EACH(ANNIUM_PRINT_SIMPLE_ENUM, _, ANNIUM_BINARY_OPERATOR_ENUM)
};

template <binary_operator_type Op>
using binary_operator_t = std::integral_constant<binary_operator_type, Op>;

#define ANNIUM_PRINT_BOP_CASE(r, data, elem) case binary_operator_type::elem: return BOOST_PP_CAT(BOOST_PP_STRINGIZE(elem), sv);
inline string_view to_string(binary_operator_type op) {
    switch (op) {
    BOOST_PP_SEQ_FOR_EACH(ANNIUM_PRINT_BOP_CASE, _, ANNIUM_BINARY_OPERATOR_ENUM)
    default: return "unknown"sv;
    }
}

#define ANNIUM_PRINT_BOP_CASE_VISIT(r, data, elem) case binary_operator_type::elem: return std::forward<VisitorT>(vis)(binary_operator_t<binary_operator_type::elem>{}, std::forward<BinaryExprT>(exp));
template <typename BinaryExprT, typename VisitorT>
inline auto annium_binary_switcher(BinaryExprT && exp, VisitorT && vis) {
    switch (exp.op) {
    BOOST_PP_SEQ_FOR_EACH(ANNIUM_PRINT_BOP_CASE_VISIT, _, ANNIUM_BINARY_OPERATOR_ENUM)
    }
    THROW_INTERNAL_ERROR("unknown binary operator '%1%'"_fmt % to_string(exp.op));
}

#undef ANNIUM_PRINT_BOP_CASE_VISIT
#undef ANNIUM_PRINT_BOP_CASE
#undef ANNIUM_UNARY_OPERATOR_ENUM
#undef ANNIUM_BINARY_OPERATOR_ENUM
#undef ANNIUM_PRINT_SIMPLE_ENUM

struct pure_call
{
    span<const opt_named_expression_t> args;

    inline explicit pure_call(span<const opt_named_expression_t> args_val) noexcept
        : args{ std::move(args_val) }
    {}

    //pure_call(resource_location loc, opt_named_term_list<ExprT> && args)
    //    : location_{ std::move(loc) }
    //{
    //    for (opt_named_term<ExprT> & narg : args) {
    //        if (auto const* pure_expr = get<ExprT>(&narg.term); pure_expr) {
    //            positioned_args.emplace_back(std::move(*pure_expr));
    //        } else if (auto const* named_expr = get<std::tuple<annotated_identifier, ExprT>>(&narg.term); named_expr) {
    //            named_args.emplace_back(std::move(std::get<0>(*named_expr)), std::move(std::get<1>(*named_expr)));
    //        } else {
    //            THROW_INTERNAL_ERROR();
    //        }
    //    }
    //    std::ranges::sort(named_args, {}, [](auto const& pair) { return std::get<0>(pair).value; });
    //    // to do: check for repeated named args
    //}


    //inline void emplace_back(annotated_identifier name, ExprT expr) { args.emplace_back(std::move(name), std::move(expr)); }
    //inline void emplace_back(ExprT expr) { args.emplace_back(std::move(expr)); }

    //inline opt_named_term<ExprT> const& operator[](size_t index) const noexcept { return args_[index]; }
    //inline std::span<const opt_named_term<ExprT>> args() const noexcept { return args_; }
    //inline resource_location const& location() const noexcept { return location_; }
};

struct function_call : pure_call
{
    syntax_expression const* fn_object;
    inline function_call(syntax_expression const* n, span<const opt_named_expression_t> args = {}) noexcept
        : pure_call{ std::move(args) }
        , fn_object{ n }
    {}
};

struct unary_expression : pure_call
{
    unary_operator_type op;

    template <size_t N>
    requires(N == 1 || N == std::dynamic_extent)
    inline unary_expression(unary_operator_type opval, bool /*is_prefix*/, std::span<const opt_named_expression_t, N> args) noexcept
        : pure_call{ args }
        , op{ opval }
    {
        if constexpr (N == std::dynamic_extent) {
            BOOST_ASSERT(args.size() == 1);
        }
        //if (!base_t::location) base_t::location_ = get_start_location(base_t::args);
    }
};

struct binary_expression : pure_call
{
    binary_operator_type op;

    template <size_t N>
    requires(N == 2 || N == std::dynamic_extent)
    inline binary_expression(binary_operator_type opval, std::span<const opt_named_expression_t, N> lrargs) noexcept
        : pure_call{ lrargs }
        , op{ opval }
    {
        if constexpr (N == std::dynamic_extent) {
            BOOST_ASSERT(lrargs.size() == 2);
        }
    }
};

using opt_chain_link = std::variant<annotated_identifier, pure_call>;

using opt_chain = std::vector<opt_chain_link>;

struct chained_expression
{
    syntax_expression const& expression;
    opt_chain chaining;
};

// e.g. backgroundColor: .red
//struct context_identifier
//{
//    annotated_identifier name;
//    resource_location location;
//};

struct member_expression
{
    syntax_expression const* object;
    syntax_expression const* property;
};

struct placeholder
{
    resource_location location;
};

using indirect_expression_store_t = automatic_polymorphic<indirect, ANNIUM_AST_INDIRECT_STORE_SIZE>;

struct indirect_value
{
    entity_identifier type;
    indirect_expression_store_t store;
};

struct indirect_expression
{
    entity_identifier value;
    indirect_expression_store_t store;
};

struct not_empty_expression
{
    syntax_expression const* value;
};

struct new_expression
{
    syntax_expression const* name;
    span<const opt_named_expression_t> arguments;
};

struct index_expression
{
    syntax_expression const* base;
    syntax_expression const* index;
};

struct required_t {};
struct optional_t {};

struct syntax_pattern
{
    struct field
    {
        // unnamed, any name, particular name, bind name to identifier, name is the result of an expression
        std::variant<nullptr_t, placeholder, annotated_identifier, context_identifier, syntax_expression const*> name;
        // used for binding the value to a variable
        annotated_identifier bound_variable;
        syntax_pattern const* value;
        bool ellipsis = false;
    };

    struct signature_descriptor
    {
        std::variant<placeholder, annotated_qname_view, syntax_expression const*> name;
        std::span<const field> fields;
    };

    std::variant<placeholder, context_identifier, signature_descriptor, syntax_expression const*> descriptor;
    span<const syntax_expression> concepts;
};

using syntax_pattern_field_list_t = small_vector<syntax_pattern::field, 1>;

struct parameter
{
    using default_spec = std::variant<required_t, optional_t, syntax_expression const*>;

    parameter_name name;

    std::variant<syntax_expression const*, syntax_pattern const*> constraint;

    default_spec default_value = required_t{};

    parameter_constraint_modifier_t modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type;
};

using parameter_list_t = small_vector<parameter, 4>;

enum class fn_kind : int8_t
{
    DEFAULT = 0,
    INLINE = 1,
    VIABLE = 2
};

inline fn_kind operator|(fn_kind l, fn_kind r) noexcept
{
    return static_cast<fn_kind>(static_cast<int8_t>(l) | static_cast<int8_t>(r));
}

inline bool has(fn_kind value, fn_kind flag) noexcept
{
    return (static_cast<int8_t>(value) & static_cast<int8_t>(flag)) != 0;
}

//struct viable_clause
//{
//    resource_location location;
//    span<statement const*> body; // may be empty
//};

struct fn_pure
{
    qname_view name;
    resource_location location; // used when as a statement
    span<const parameter> parameters;
    syntax_expression const* requirement; // optional
    std::variant<nullptr_t, syntax_expression const*, syntax_pattern const*> result; // undefined or type expression or pattern

    fn_kind kind = fn_kind::DEFAULT;
};

struct typefn_decl : fn_pure {};

// used for both function declaration and lambda expression
struct fn_decl : fn_pure
{
    span<const statement> body;
    span<const opt_named_expression_t> captures;
};

using lambda = fn_decl;

struct probe_expression
{
    span<const statement> body;
};

struct nil_expression {};

struct local_variable_expression
{
    entity_identifier type;
    variable_identifier varid;

    inline static local_variable_expression from_var(local_variable const& var) noexcept
    {
        return { var.type, var.varid };
    }
};

struct name_reference_expression { identifier name; }; // e.g. for identifiers started with $ or #, e.g.: $0, $$, #call_location
struct qname_reference_expression { qname_view name; };

struct top_stack_value_expression
{
    entity_identifier type;
};

struct stack_value_reference_expression
{
    identifier name;
    entity_identifier type;
    intptr_t offset = 0; // offset from the stack top
};
struct stack_frame_value_reference_expression
{
    identifier name;
    entity_identifier type;
    intptr_t offset; // offset from the stack frame base
};

struct array_expression
{
    span<const syntax_expression> elements;
};
struct array_with_body_expression
{
    span<const statement> body;
};
struct bracket_expression
{
    syntax_expression const* type;
};

struct syntax_expression
{
    resource_location location;
    std::variant<
        // literals
        nil_expression, bool, numetron::integer_view, numetron::decimal_view, string_view, identifier, entity_identifier,
        
        // references
        local_variable_expression, name_reference_expression, qname_reference_expression,
        
        // on stack reference
        top_stack_value_expression,
        stack_value_reference_expression,
        stack_frame_value_reference_expression,

        // constructors
        array_expression, // like [value1, value2, ...]
        array_with_body_expression, // like [ { ... } ]

        // types
        bracket_expression, // like [ElementType]
        fn_decl, // like fn (args) -> result { body }
        annium_fn_type, // like (args) -> result

        // sugar
        index_expression, // like base[index]
        member_expression, // like object.property
        new_expression, // like new Type(args)
        unary_expression, // like -value
        binary_expression, // like left + right
        /*not_empty_expression, // like value?

        // special statements
        */probe_expression,

        // auxiliary
        indirect_value, indirect_expression,

        //assign_expression<>, logic_and_expression<>, logic_or_expression<>, concat_expression<>,
        //expression_vector<recursive_variant_>,

        function_call
        
        //, opt_named_term_list<recursive_variant_>
        //, chained_expression<recursive_variant_>
        //, ctprocedure
        
    > value;
};

template <typename TermT>
struct opt_named_term
{
    using named_pair_t = std::tuple<annotated_identifier, TermT>;
    std::variant<named_pair_t, TermT, nullptr_t> term;

    inline opt_named_term() noexcept : term{ nullptr } {
        BOOST_ASSERT(term.index() >= 0);
    }

    template <typename TermArgT>
    requires(std::is_constructible_v<TermT, std::decay_t<TermArgT>>)
    inline opt_named_term(TermArgT&& t) noexcept : term{ std::forward<TermArgT>(t) } {
        BOOST_ASSERT(term.index() >= 0);
    }
    
    //inline opt_named_term(opt_named_term const& rhs)
    //    : term{ rhs.term }
    //{
    //    BOOST_ASSERT(term.index() >= 0);
    //}

    //inline opt_named_term& operator=(opt_named_term const& rhs)
    //{
    //    term = rhs.term;
    //    BOOST_ASSERT(term.index() >= 0);
    //    return *this;
    //}

    template <typename NameT, typename TermArgT>
    requires(std::is_constructible_v<TermT, std::decay_t<TermArgT>>)
    inline explicit opt_named_term(NameT&& narg, TermArgT&& t) noexcept
        : term{ named_pair_t{std::forward<NameT>(narg), std::forward<TermArgT>(t)} }
    {
        BOOST_ASSERT(get<0>(get<named_pair_t>(term)));
    }

    inline explicit operator bool() const noexcept { return !std::holds_alternative<nullptr_t>(term); }

    inline bool has_name() const noexcept { return std::holds_alternative<named_pair_t>(term); }
    inline const annotated_identifier * name() const noexcept
    {
        if (named_pair_t const* p = get_if<named_pair_t>(&term); p) return &get<0>(*p);
        return nullptr;
    }

    std::tuple<annotated_identifier const*, TermT const&> operator*() const noexcept
    {
        if (named_pair_t const* p = get_if<named_pair_t>(&term); p) return { &get<0>(*p), get<1>(*p) };
        return { nullptr, get<TermT>(term) };
    }

    std::tuple<annotated_identifier const*, TermT &> operator*() noexcept
    {
        if (named_pair_t * p = get_if<named_pair_t>(&term); p) return { &get<0>(*p), get<1>(*p) };
        return { nullptr, get<TermT>(term) };
    }

    inline TermT const& value() const noexcept
    {
        if (named_pair_t const* p = get_if<named_pair_t>(&term); p) return get<1>(*p);
        return get<TermT>(term);
    }

    inline TermT & value() noexcept
    {
        if (named_pair_t * p = get_if<named_pair_t>(&term); p) return get<1>(*p);
        return get<TermT>(term);
    }

    inline resource_location const& location() const noexcept
    {
        if (named_pair_t const* p = get_if<named_pair_t>(&term); p) return get<0>(*p).location;
        return get<TermT>(term).location;
    }
};

#if 0
using syntax_expression = make_recursive_variant<
    // literals
    annotated_nil, annotated_bool, annotated_integer, annotated_decimal, annotated_string, annotated_identifier,
    
    // named references
    name_reference, qname_reference,
    
    // on stack reference
    stack_value_reference,

    // constructors
    array_expression<recursive_variant_>, // like [value1, value2, ...]
    array_with_body_expression<recursive_variant_>, // like [ { ... } ]
    // types
    bracket_expression<recursive_variant_>, // like [ElementType]
    fn_decl<recursive_variant_>, // like fn (args) -> result { body }
    annium_fn_type<recursive_variant_>, // like (args) -> result

    // sugar
    index_expression<recursive_variant_>, // like base[index]
    member_expression<recursive_variant_>, // like object.property
    new_expression<recursive_variant_>, // like new Type(args)
    unary_expression<recursive_variant_>, // like -value
    binary_expression<recursive_variant_>, // like left + right
    not_empty_expression<recursive_variant_>, // like value?

    // special statements
    probe_expression,

    // auxiliary
    indirect_value,
    
    //assign_expression<>, logic_and_expression<>, logic_or_expression<>, concat_expression<>,
    //expression_vector<recursive_variant_>,
    function_call<recursive_variant_>,
    
    annotated_entity_identifier
    //, opt_named_term_list<recursive_variant_>
    //, chained_expression<recursive_variant_>
    //, ctprocedure
>::type;

#endif

struct field
{
    using default_spec = std::variant<required_t, syntax_expression>;

    annotated_identifier name;
    parameter_constraint_modifier_t modifier;
    syntax_expression type_or_value;
    default_spec value = required_t{};
};


#if 0
using parameter_list_t = parameter_list<syntax_expression>;

using expression_list_t = expression_list<syntax_expression>;
using opt_chain_t = opt_chain<syntax_expression>;
using opt_chain_link_t = opt_chain_link<syntax_expression>;
using chained_expression_t = chained_expression<syntax_expression>;
using named_expression_t = opt_named_term<syntax_expression>;
using named_expression_list_t = opt_named_term_list<syntax_expression>;
using not_empty_expression_t = not_empty_expression<syntax_expression>;
using member_expression = member_expression<syntax_expression>;
using unary_expression_t = unary_expression<syntax_expression>;
using binary_expression_t = binary_expression<syntax_expression>;
using pure_call = pure_call<syntax_expression>;
using new_expression_t = new_expression<syntax_expression>;
using function_call_t = function_call<syntax_expression>;
//using expression_vector_t = expression_vector<syntax_expression>;
//template <unary_operator_type Op> using unary_expression_t = unary_expression<Op, syntax_expression>;
#endif

template <typename T> struct is_unary_expression : false_type {};
template <typename T> requires(std::is_same_v<decltype(T::op), const unary_operator_type>) struct is_unary_expression<T> : true_type {};

//resource_location const& get_start_location(syntax_expression const&); // auxiliary

// {particular location or expression, optional reference location}
struct error_context
{
    std::variant<resource_location, syntax_expression const*> loc_or_expr;
    resource_location refloc;

    resource_location const& location() const
    {
        return std::visit([](auto const& v) -> resource_location const& {
            using VType = std::decay_t<decltype(v)>;
            if constexpr (std::is_same_v<VType, resource_location>) {
                return v;
            } else {
                return v->location;
            }
        }, loc_or_expr);
    }

    syntax_expression const* expression() const
    {
        auto const* opt_se = get_if<syntax_expression const*>(&loc_or_expr);
        return opt_se ? *opt_se : nullptr;
    }
};

resource_location get_start_location(syntax_pattern const&);

using context_locator_t = function<error_context()>;

using extension_list_t = std::vector<annotated_qname_identifier>;

struct using_decl : fn_decl
{
    //annotated_qname aname;
    //optional<parameter_list_t> parameters;
    //syntax_expression expression;

    //qname_view name() const { return aname.value; }
    //resource_location const& location() const { return aname.location; }
};

struct struct_decl
{
    annotated_qname_view name;
    span<const parameter> parameters;
    //std::variant<field_list_t, statement_span> body;
    span<const field> body;

    inline resource_location const& location() const noexcept
    {
        return name.location;
    }
};

struct enum_decl
{
    annotated_qname_view name;
    span<const identifier> cases;
};

struct extern_var
{
    annotated_identifier name;
    syntax_expression type;
};

struct include_decl
{
    annotated_string_view path;
};

struct let_statement
{
    annotated_identifier aname;
    span<const opt_named_expression_t> expressions;
    optional<syntax_expression> type;
    resource_location assign_location; // location of '=' operator
    bool weakness;

    identifier const& name() const { return aname.value; }
    resource_location const& location() const { return assign_location; }
};

//using yield_statement_t = yield_statement<syntax_expression>;
//using return_statement_t = return_statement<syntax_expression>;
//using expression_statement_t = expression_decl<syntax_expression>;
//using assign_decl_t = assign_decl<syntax_expression>;

//using fn_decl = fn_decl<infunction_declaration_t>;

struct if_decl
{
    syntax_expression condition;
    span<const statement> true_body;
    span<const statement> false_body;
};

struct while_decl
{
    syntax_expression condition;
    span<const statement> body;
    optional<syntax_expression> continue_expression; // called before condition starting with second condition check (like c/c++ for expression)
};

struct reference_expression
{
    resource_location location;
    std::variant<name_reference_expression, qname_reference_expression> value;
};

struct for_statement
{
    reference_expression iter;
    syntax_expression coll;
    span<const statement> body;
};

struct expression_statement
{
    syntax_expression expression;
};

struct return_statement
{
    optional<syntax_expression> expression;
    resource_location location;
};

struct break_statement
{
    resource_location location;
};

struct continue_statement
{
    resource_location location;
};

struct yield_statement
{
    syntax_expression expression;
    resource_location location;
};

struct statement
{
    using statement_value_type = std::variant<
        extern_var, let_statement, expression_statement, fn_pure,
        include_decl, struct_decl, using_decl, enum_decl, return_statement,
        fn_decl, typefn_decl, if_decl, while_decl, for_statement, break_statement, continue_statement, yield_statement
    >;
    statement_value_type value;
};

template <typename LocationT>
void update_location(LocationT & loc, const char* text)
{
    loc.begin.line = loc.end.line;
    loc.begin.column = loc.end.column;
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] == '\n') {
            loc.end.line++;
            loc.end.column = 1;
        } else {
            loc.end.column++;
        }
    }
}

}
