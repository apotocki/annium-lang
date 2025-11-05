// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file annium.tab.hpp
 ** Define the annium_lang::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_ANNIUM_LANG_ANNIUM_TAB_HPP_INCLUDED
# define YY_ANNIUM_LANG_ANNIUM_TAB_HPP_INCLUDED


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef ANNIUM_LANGDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ANNIUM_LANGDEBUG 1
#  else
#   define ANNIUM_LANGDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ANNIUM_LANGDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ANNIUM_LANGDEBUG */

namespace annium_lang {
#line 190 "annium.tab.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef ANNIUM_LANGSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define ANNIUM_LANGSTYPE in C++, use %define api.value.type"
# endif
    typedef ANNIUM_LANGSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // DECIMAL
      // DECIMAL_S
      char dummy1[sizeof (annium::annotated_decimal_view)];

      // INTEGER
      char dummy2[sizeof (annium::annotated_integer_view)];

      // fn-name
      char dummy3[sizeof (annium::annotated_qname_view)];

      // STRING
      // IDENTIFIER
      // CONTEXT_IDENTIFIER
      // RESERVED_IDENTIFIER
      // INTEGER_INDEX
      char dummy4[sizeof (annium::annotated_string_view)];

      // "true"
      // "false"
      char dummy5[sizeof (annotated_bool)];

      // CT_IDENTIFIER
      // identifier
      // argument-name
      char dummy6[sizeof (annotated_identifier)];

      // "nil"
      char dummy7[sizeof (annotated_nil)];

      // qname
      char dummy8[sizeof (annotated_qname)];

      // internal-identifier
      // internal-identifier-opt
      char dummy9[sizeof (context_identifier)];

      // enum-decl
      char dummy10[sizeof (enum_decl)];

      // field
      char dummy11[sizeof (field)];

      // field-default-value-opt
      char dummy12[sizeof (field::default_spec)];

      // fn-kind
      // fn-kind-set
      char dummy13[sizeof (fn_kind)];

      // fn-start-decl
      // fn-decl
      char dummy14[sizeof (fn_pure)];

      // case-decl
      char dummy15[sizeof (identifier)];

      // let-decl
      // let-decl-start
      // let-decl-start-with-opt-type
      char dummy16[sizeof (let_statement)];

      // argument-list-opt
      // argument-list
      // pack-expression-opt
      // pack-expression
      char dummy17[sizeof (opt_named_expression_list_t)];

      // argument
      char dummy18[sizeof (opt_named_expression_t)];

      // parameter-decl
      char dummy19[sizeof (parameter)];

      // parameter-default-value-opt
      char dummy20[sizeof (parameter::default_spec)];

      // parameter-list-opt
      // parameter-list
      char dummy21[sizeof (parameter_list_t)];

      // reference-expression
      char dummy22[sizeof (reference_expression)];

      // "`=`"
      // "`_`"
      // "`==`"
      // "`!=`"
      // "`&&`"
      // "`||`"
      // "`..`"
      // "`...`"
      // "`(`"
      // "`{`"
      // "`[`"
      // "`[[`"
      // "`.`"
      // "`+`"
      // "`-`"
      // "`*`"
      // "`&`"
      // "`|`"
      // "`!`"
      // "`?`"
      // "`new`"
      // "`continue`"
      // "`break`"
      // "`return`"
      // "`yield`"
      // "`fn`"
      // "`typefn`"
      // "typename modifier"
      // "constexpr modifier"
      // "runctime modifier"
      // PROBE
      char dummy23[sizeof (resource_location)];

      // OPERATOR_TERM
      char dummy24[sizeof (sonia::string_view)];

      // statement
      // finished-statement
      // generic-statement
      // infunction-statement
      char dummy25[sizeof (statement)];

      // statement_any
      // finished-statement-any
      // infunction-statement-any
      // finished-infunction-statement-any
      // function-body
      // braced-statements
      // infunction-statement-set
      char dummy26[sizeof (statement_list_t)];

      // fn-prefix-decl
      char dummy27[sizeof (std::pair<resource_location, fn_kind>)];

      // lambda-start-decl
      char dummy28[sizeof (std::pair<resource_location, lambda>)];

      // constraint-expression-specified-mod
      // constraint-expression-mod
      char dummy29[sizeof (std::pair<resource_location, parameter_constraint_modifier_t>)];

      // constraint-expression-specified
      // constraint-expression
      char dummy30[sizeof (std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t>)];

      // pattern-mod
      // pattern-sfx
      char dummy31[sizeof (std::pair<syntax_pattern, parameter_constraint_modifier_t>)];

      // field-list-opt
      // field-list
      char dummy32[sizeof (std::vector<field>)];

      // case-list-opt
      // case-list
      char dummy33[sizeof (std::vector<identifier>)];

      // struct-decl
      char dummy34[sizeof (struct_decl)];

      // concept-expression
      // any-reference-expression
      // syntax-expression
      // apostrophe-expression
      // new-expression
      // call-expression
      // lambda-expression
      // compound-expression
      // type-expr
      char dummy35[sizeof (syntax_expression)];

      // fn-requirement-opt
      char dummy36[sizeof (syntax_expression const*)];

      // expression-list
      // concept-expression-list-opt
      // concept-expression-list
      char dummy37[sizeof (syntax_expression_list_t)];

      // pattern
      char dummy38[sizeof (syntax_pattern)];

      // pattern-field-sfx
      // pattern-field
      char dummy39[sizeof (syntax_pattern::field)];

      // subpatterns
      // pattern-list
      char dummy40[sizeof (syntax_pattern_field_list_t)];

      // using-decl
      char dummy41[sizeof (using_decl)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        ANNIUM_LANGEMPTY = -2,
    END = 0,                       // "end of file"
    ANNIUM_LANGerror = 256,        // error
    ANNIUM_LANGUNDEF = 257,        // "invalid token"
    COMMENT_BEGIN = 258,           // COMMENT_BEGIN
    COMMENT_END = 259,             // COMMENT_END
    STRING = 260,                  // STRING
    IDENTIFIER = 261,              // IDENTIFIER
    CONTEXT_IDENTIFIER = 262,      // CONTEXT_IDENTIFIER
    RESERVED_IDENTIFIER = 263,     // RESERVED_IDENTIFIER
    INTEGER_INDEX = 264,           // INTEGER_INDEX
    INTEGER = 265,                 // INTEGER
    DECIMAL = 266,                 // DECIMAL
    DECIMAL_S = 267,               // DECIMAL_S
    OPERATOR_TERM = 268,           // OPERATOR_TERM
    CT_IDENTIFIER = 269,           // CT_IDENTIFIER
    ASSIGN = 270,                  // "`=`"
    APOSTROPHE = 271,              // "APOSTROPHE"
    AT_SYMBOL = 272,               // "`@`"
    UNDERSCORE = 273,              // "`_`"
    ARROWAST = 274,                // "`->*`"
    ARROW = 275,                   // "`->`"
    ARROWEXPR = 276,               // "`=>`"
    FARROW = 277,                  // "`~>`"
    PTAST = 278,                   // "`.*`"
    DBLPLUS = 279,                 // "`++`"
    DBLMINUS = 280,                // "`--`"
    LEFTSHIFT = 281,               // "`<<`"
    RIGHTSHIFT = 282,              // "`>>`"
    LE = 283,                      // "`<=`"
    GE = 284,                      // "`>=`"
    EQ = 285,                      // "`==`"
    NE = 286,                      // "`!=`"
    LOGIC_AND = 287,               // "`&&`"
    LOGIC_OR = 288,                // "`||`"
    CONCAT = 289,                  // "`..`"
    ELLIPSIS = 290,                // "`...`"
    ADDASSIGN = 291,               // "`+=`"
    SUBASSIGN = 292,               // "`-=`"
    MULASSIGN = 293,               // "`*=`"
    DIVASSIGN = 294,               // "`/=`"
    MODASSIGN = 295,               // "`%=`"
    LSHIFTSSIGN = 296,             // "`<<=`"
    RSHIFTSSIGN = 297,             // "`>>=`"
    BITANDASSIGN = 298,            // "`&=`"
    BITORASSIGN = 299,             // "`|=`"
    BITXORASSIGN = 300,            // "`^=`"
    COLON = 301,                   // "`:`"
    DBLCOLON = 302,                // "`::`"
    OPEN_PARENTHESIS = 303,        // "`(`"
    CLOSE_PARENTHESIS = 304,       // "`)`"
    OPEN_BRACE = 305,              // "`{`"
    CLOSE_BRACE = 306,             // "`}`"
    OPEN_SQUARE_BRACKET = 307,     // "`[`"
    CLOSE_SQUARE_BRACKET = 308,    // "`]`"
    OPEN_SQUARE_DBL_BRACKET = 309, // "`[[`"
    CLOSE_SQUARE_DBL_BRACKET = 310, // "`]]`"
    OPEN_BROKET = 311,             // "`<`"
    CLOSE_BROKET = 312,            // "`>`"
    END_STATEMENT = 313,           // "`;`"
    POINT = 314,                   // "`.`"
    PLUS = 315,                    // "`+`"
    MINUS = 316,                   // "`-`"
    ASTERISK = 317,                // "`*`"
    SLASH = 318,                   // "`/`"
    PERCENT = 319,                 // "`%`"
    AMPERSAND = 320,               // "`&`"
    BITOR = 321,                   // "`|`"
    EXCLPT = 322,                  // "`!`"
    TILDA = 323,                   // "`~`"
    EXCL = 324,                    // "`^`"
    COMMA = 325,                   // ","
    DOLLAR = 326,                  // "`$`"
    QMARK = 327,                   // "`?`"
    HASHTAG = 328,                 // "`#`"
    LET = 329,                     // LET
    VAR = 330,                     // VAR
    EXTERN = 331,                  // EXTERN
    NEW = 332,                     // "`new`"
    WHILE = 333,                   // "`while`"
    FOR = 334,                     // "`for`"
    IN_ = 335,                     // "`in`"
    IF = 336,                      // "`if`"
    ELSE = 337,                    // "`else`"
    CONTINUE = 338,                // "`continue`"
    BREAK = 339,                   // "`break`"
    RETURN = 340,                  // "`return`"
    YIELD = 341,                   // "`yield`"
    AUTO = 342,                    // AUTO
    USING = 343,                   // USING
    THROW = 344,                   // THROW
    SIZEOF = 345,                  // SIZEOF
    LOWEST = 346,                  // LOWEST
    DEREF = 347,                   // DEREF
    PREFIXMINUS = 348,             // PREFIXMINUS
    INCLUDE = 349,                 // INCLUDE
    INLINE = 350,                  // INLINE
    VIABLE = 351,                  // VIABLE
    FN = 352,                      // "`fn`"
    TYPEFN = 353,                  // "`typefn`"
    ENUM = 354,                    // ENUM
    STRUCT = 355,                  // STRUCT
    EXTENDS = 356,                 // EXTENDS
    REQUIRES = 357,                // REQUIRES
    WEAK = 358,                    // "weak modifier"
    TYPENAME = 359,                // "typename modifier"
    CONSTEXPR = 360,               // "constexpr modifier"
    RUNTIME = 361,                 // "runctime modifier"
    NIL_WORD = 362,                // "nil"
    TRUE_WORD = 363,               // "true"
    FALSE_WORD = 364,              // "false"
    PROBE = 365                    // PROBE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 111, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_COMMENT_BEGIN = 3,                     // COMMENT_BEGIN
        S_COMMENT_END = 4,                       // COMMENT_END
        S_STRING = 5,                            // STRING
        S_IDENTIFIER = 6,                        // IDENTIFIER
        S_CONTEXT_IDENTIFIER = 7,                // CONTEXT_IDENTIFIER
        S_RESERVED_IDENTIFIER = 8,               // RESERVED_IDENTIFIER
        S_INTEGER_INDEX = 9,                     // INTEGER_INDEX
        S_INTEGER = 10,                          // INTEGER
        S_DECIMAL = 11,                          // DECIMAL
        S_DECIMAL_S = 12,                        // DECIMAL_S
        S_OPERATOR_TERM = 13,                    // OPERATOR_TERM
        S_CT_IDENTIFIER = 14,                    // CT_IDENTIFIER
        S_ASSIGN = 15,                           // "`=`"
        S_APOSTROPHE = 16,                       // "APOSTROPHE"
        S_AT_SYMBOL = 17,                        // "`@`"
        S_UNDERSCORE = 18,                       // "`_`"
        S_ARROWAST = 19,                         // "`->*`"
        S_ARROW = 20,                            // "`->`"
        S_ARROWEXPR = 21,                        // "`=>`"
        S_FARROW = 22,                           // "`~>`"
        S_PTAST = 23,                            // "`.*`"
        S_DBLPLUS = 24,                          // "`++`"
        S_DBLMINUS = 25,                         // "`--`"
        S_LEFTSHIFT = 26,                        // "`<<`"
        S_RIGHTSHIFT = 27,                       // "`>>`"
        S_LE = 28,                               // "`<=`"
        S_GE = 29,                               // "`>=`"
        S_EQ = 30,                               // "`==`"
        S_NE = 31,                               // "`!=`"
        S_LOGIC_AND = 32,                        // "`&&`"
        S_LOGIC_OR = 33,                         // "`||`"
        S_CONCAT = 34,                           // "`..`"
        S_ELLIPSIS = 35,                         // "`...`"
        S_ADDASSIGN = 36,                        // "`+=`"
        S_SUBASSIGN = 37,                        // "`-=`"
        S_MULASSIGN = 38,                        // "`*=`"
        S_DIVASSIGN = 39,                        // "`/=`"
        S_MODASSIGN = 40,                        // "`%=`"
        S_LSHIFTSSIGN = 41,                      // "`<<=`"
        S_RSHIFTSSIGN = 42,                      // "`>>=`"
        S_BITANDASSIGN = 43,                     // "`&=`"
        S_BITORASSIGN = 44,                      // "`|=`"
        S_BITXORASSIGN = 45,                     // "`^=`"
        S_COLON = 46,                            // "`:`"
        S_DBLCOLON = 47,                         // "`::`"
        S_OPEN_PARENTHESIS = 48,                 // "`(`"
        S_CLOSE_PARENTHESIS = 49,                // "`)`"
        S_OPEN_BRACE = 50,                       // "`{`"
        S_CLOSE_BRACE = 51,                      // "`}`"
        S_OPEN_SQUARE_BRACKET = 52,              // "`[`"
        S_CLOSE_SQUARE_BRACKET = 53,             // "`]`"
        S_OPEN_SQUARE_DBL_BRACKET = 54,          // "`[[`"
        S_CLOSE_SQUARE_DBL_BRACKET = 55,         // "`]]`"
        S_OPEN_BROKET = 56,                      // "`<`"
        S_CLOSE_BROKET = 57,                     // "`>`"
        S_END_STATEMENT = 58,                    // "`;`"
        S_POINT = 59,                            // "`.`"
        S_PLUS = 60,                             // "`+`"
        S_MINUS = 61,                            // "`-`"
        S_ASTERISK = 62,                         // "`*`"
        S_SLASH = 63,                            // "`/`"
        S_PERCENT = 64,                          // "`%`"
        S_AMPERSAND = 65,                        // "`&`"
        S_BITOR = 66,                            // "`|`"
        S_EXCLPT = 67,                           // "`!`"
        S_TILDA = 68,                            // "`~`"
        S_EXCL = 69,                             // "`^`"
        S_COMMA = 70,                            // ","
        S_DOLLAR = 71,                           // "`$`"
        S_QMARK = 72,                            // "`?`"
        S_HASHTAG = 73,                          // "`#`"
        S_LET = 74,                              // LET
        S_VAR = 75,                              // VAR
        S_EXTERN = 76,                           // EXTERN
        S_NEW = 77,                              // "`new`"
        S_WHILE = 78,                            // "`while`"
        S_FOR = 79,                              // "`for`"
        S_IN_ = 80,                              // "`in`"
        S_IF = 81,                               // "`if`"
        S_ELSE = 82,                             // "`else`"
        S_CONTINUE = 83,                         // "`continue`"
        S_BREAK = 84,                            // "`break`"
        S_RETURN = 85,                           // "`return`"
        S_YIELD = 86,                            // "`yield`"
        S_AUTO = 87,                             // AUTO
        S_USING = 88,                            // USING
        S_THROW = 89,                            // THROW
        S_SIZEOF = 90,                           // SIZEOF
        S_LOWEST = 91,                           // LOWEST
        S_DEREF = 92,                            // DEREF
        S_PREFIXMINUS = 93,                      // PREFIXMINUS
        S_INCLUDE = 94,                          // INCLUDE
        S_INLINE = 95,                           // INLINE
        S_VIABLE = 96,                           // VIABLE
        S_FN = 97,                               // "`fn`"
        S_TYPEFN = 98,                           // "`typefn`"
        S_ENUM = 99,                             // ENUM
        S_STRUCT = 100,                          // STRUCT
        S_EXTENDS = 101,                         // EXTENDS
        S_REQUIRES = 102,                        // REQUIRES
        S_WEAK = 103,                            // "weak modifier"
        S_TYPENAME = 104,                        // "typename modifier"
        S_CONSTEXPR = 105,                       // "constexpr modifier"
        S_RUNTIME = 106,                         // "runctime modifier"
        S_NIL_WORD = 107,                        // "nil"
        S_TRUE_WORD = 108,                       // "true"
        S_FALSE_WORD = 109,                      // "false"
        S_PROBE = 110,                           // PROBE
        S_YYACCEPT = 111,                        // $accept
        S_begin = 112,                           // begin
        S_statement_any = 113,                   // statement_any
        S_114_finished_statement_any = 114,      // finished-statement-any
        S_statement = 115,                       // statement
        S_116_let_decl = 116,                    // let-decl
        S_117_let_decl_start = 117,              // let-decl-start
        S_118_let_decl_start_with_opt_type = 118, // let-decl-start-with-opt-type
        S_119_infunction_statement_any = 119,    // infunction-statement-any
        S_120_finished_infunction_statement_any = 120, // finished-infunction-statement-any
        S_121_function_body = 121,               // function-body
        S_122_braced_statements = 122,           // braced-statements
        S_123_finished_statement = 123,          // finished-statement
        S_124_infunction_statement_set = 124,    // infunction-statement-set
        S_125_generic_statement = 125,           // generic-statement
        S_126_infunction_statement = 126,        // infunction-statement
        S_identifier = 127,                      // identifier
        S_128_internal_identifier = 128,         // internal-identifier
        S_qname = 129,                           // qname
        S_130_fn_kind = 130,                     // fn-kind
        S_131_fn_kind_set = 131,                 // fn-kind-set
        S_132_fn_prefix_decl = 132,              // fn-prefix-decl
        S_133_fn_name = 133,                     // fn-name
        S_134_fn_start_decl = 134,               // fn-start-decl
        S_135_fn_requirement_opt = 135,          // fn-requirement-opt
        S_136_fn_decl = 136,                     // fn-decl
        S_137_enum_decl = 137,                   // enum-decl
        S_138_case_list_opt = 138,               // case-list-opt
        S_139_case_list = 139,                   // case-list
        S_140_case_decl = 140,                   // case-decl
        S_141_struct_decl = 141,                 // struct-decl
        S_142_using_decl = 142,                  // using-decl
        S_143_expression_list = 143,             // expression-list
        S_144_argument_list_opt = 144,           // argument-list-opt
        S_145_argument_list = 145,               // argument-list
        S_argument = 146,                        // argument
        S_147_argument_name = 147,               // argument-name
        S_148_field_list_opt = 148,              // field-list-opt
        S_149_field_list = 149,                  // field-list
        S_150_field_default_value_opt = 150,     // field-default-value-opt
        S_field = 151,                           // field
        S_152_parameter_list_opt = 152,          // parameter-list-opt
        S_153_parameter_list = 153,              // parameter-list
        S_154_internal_identifier_opt = 154,     // internal-identifier-opt
        S_155_parameter_default_value_opt = 155, // parameter-default-value-opt
        S_156_parameter_decl = 156,              // parameter-decl
        S_157_constraint_expression_specified_mod = 157, // constraint-expression-specified-mod
        S_158_constraint_expression_specified = 158, // constraint-expression-specified
        S_159_constraint_expression_mod = 159,   // constraint-expression-mod
        S_160_constraint_expression = 160,       // constraint-expression
        S_subpatterns = 161,                     // subpatterns
        S_162_pattern_list = 162,                // pattern-list
        S_163_pattern_field_sfx = 163,           // pattern-field-sfx
        S_164_pattern_field = 164,               // pattern-field
        S_165_pattern_mod = 165,                 // pattern-mod
        S_166_pattern_sfx = 166,                 // pattern-sfx
        S_pattern = 167,                         // pattern
        S_168_concept_expression = 168,          // concept-expression
        S_169_concept_expression_list_opt = 169, // concept-expression-list-opt
        S_170_concept_expression_list = 170,     // concept-expression-list
        S_171_reference_expression = 171,        // reference-expression
        S_172_any_reference_expression = 172,    // any-reference-expression
        S_173_syntax_expression = 173,           // syntax-expression
        S_174_apostrophe_expression = 174,       // apostrophe-expression
        S_175_new_expression = 175,              // new-expression
        S_176_call_expression = 176,             // call-expression
        S_177_lambda_start_decl = 177,           // lambda-start-decl
        S_178_lambda_expression = 178,           // lambda-expression
        S_179_pack_expression_opt = 179,         // pack-expression-opt
        S_180_pack_expression = 180,             // pack-expression
        S_181_compound_expression = 181,         // compound-expression
        S_182_type_expr = 182                    // type-expr
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.move< annium::annotated_decimal_view > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (std::move (that.value));
        break;

      case symbol_kind::S_133_fn_name: // fn-name
        value.move< annium::annotated_qname_view > (std::move (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (std::move (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (std::move (that.value));
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annotated_identifier > (std::move (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (std::move (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (std::move (that.value));
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (std::move (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (std::move (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (std::move (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (std::move (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (std::move (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure > (std::move (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< identifier > (std::move (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (std::move (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (std::move (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (std::move (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter > (std::move (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (std::move (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (std::move (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
        value.move< reference_expression > (std::move (that.value));
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (std::move (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (std::move (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (std::move (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (std::move (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (std::move (that.value));
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (std::move (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (std::move (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (std::move (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (std::move (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< std::vector<field> > (std::move (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<identifier> > (std::move (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (std::move (that.value));
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression: // syntax-expression
      case symbol_kind::S_174_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_178_lambda_expression: // lambda-expression
      case symbol_kind::S_181_compound_expression: // compound-expression
      case symbol_kind::S_182_type_expr: // type-expr
        value.move< syntax_expression > (std::move (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (std::move (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (std::move (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (std::move (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (std::move (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (std::move (that.value));
        break;

      case symbol_kind::S_142_using_decl: // using-decl
        value.move< using_decl > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annium::annotated_decimal_view&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annium::annotated_decimal_view& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annium::annotated_integer_view&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annium::annotated_integer_view& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annium::annotated_qname_view&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annium::annotated_qname_view& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annium::annotated_string_view&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annium::annotated_string_view& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annotated_bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annotated_bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annotated_identifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annotated_identifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annotated_nil&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annotated_nil& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, annotated_qname&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const annotated_qname& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, context_identifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const context_identifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, enum_decl&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const enum_decl& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, field&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const field& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, field::default_spec&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const field::default_spec& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, fn_kind&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const fn_kind& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, fn_pure&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const fn_pure& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, identifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const identifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, let_statement&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const let_statement& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, opt_named_expression_list_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const opt_named_expression_list_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, opt_named_expression_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const opt_named_expression_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, parameter&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const parameter& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, parameter::default_spec&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const parameter::default_spec& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, parameter_list_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const parameter_list_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, reference_expression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const reference_expression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, resource_location&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const resource_location& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sonia::string_view&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sonia::string_view& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, statement&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const statement& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, statement_list_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const statement_list_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<resource_location, fn_kind>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<resource_location, fn_kind>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<resource_location, lambda>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<resource_location, lambda>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<resource_location, parameter_constraint_modifier_t>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<resource_location, parameter_constraint_modifier_t>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<syntax_pattern, parameter_constraint_modifier_t>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<syntax_pattern, parameter_constraint_modifier_t>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<field>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<field>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<identifier>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<identifier>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, struct_decl&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const struct_decl& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_expression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_expression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_expression const*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_expression const*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_expression_list_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_expression_list_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_pattern&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_pattern& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_pattern::field&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_pattern::field& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, syntax_pattern_field_list_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const syntax_pattern_field_list_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, using_decl&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const using_decl& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
      case symbol_kind::S_STRING: // STRING
#line 328 "annium.y"
                    { }
#line 1829 "annium.tab.hpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 328 "annium.y"
                    { }
#line 1835 "annium.tab.hpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 328 "annium.y"
                    { }
#line 1841 "annium.tab.hpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 328 "annium.y"
                    { }
#line 1847 "annium.tab.hpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 328 "annium.y"
                    { }
#line 1853 "annium.tab.hpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 328 "annium.y"
                    { }
#line 1859 "annium.tab.hpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 328 "annium.y"
                    { }
#line 1865 "annium.tab.hpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 328 "annium.y"
                    { }
#line 1871 "annium.tab.hpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 328 "annium.y"
                    { }
#line 1877 "annium.tab.hpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 328 "annium.y"
                    { }
#line 1883 "annium.tab.hpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 328 "annium.y"
                    { }
#line 1889 "annium.tab.hpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 328 "annium.y"
                    { }
#line 1895 "annium.tab.hpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 328 "annium.y"
                    { }
#line 1901 "annium.tab.hpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 328 "annium.y"
                    { }
#line 1907 "annium.tab.hpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 328 "annium.y"
                    { }
#line 1913 "annium.tab.hpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 328 "annium.y"
                    { }
#line 1919 "annium.tab.hpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 328 "annium.y"
                    { }
#line 1925 "annium.tab.hpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 328 "annium.y"
                    { }
#line 1931 "annium.tab.hpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 328 "annium.y"
                    { }
#line 1937 "annium.tab.hpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 328 "annium.y"
                    { }
#line 1943 "annium.tab.hpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 328 "annium.y"
                    { }
#line 1949 "annium.tab.hpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 328 "annium.y"
                    { }
#line 1955 "annium.tab.hpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 328 "annium.y"
                    { }
#line 1961 "annium.tab.hpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 328 "annium.y"
                    { }
#line 1967 "annium.tab.hpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 328 "annium.y"
                    { }
#line 1973 "annium.tab.hpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 328 "annium.y"
                    { }
#line 1979 "annium.tab.hpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 328 "annium.y"
                    { }
#line 1985 "annium.tab.hpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 328 "annium.y"
                    { }
#line 1991 "annium.tab.hpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 328 "annium.y"
                    { }
#line 1997 "annium.tab.hpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 328 "annium.y"
                    { }
#line 2003 "annium.tab.hpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 328 "annium.y"
                    { }
#line 2009 "annium.tab.hpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 328 "annium.y"
                    { }
#line 2015 "annium.tab.hpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 328 "annium.y"
                    { }
#line 2021 "annium.tab.hpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 328 "annium.y"
                    { }
#line 2027 "annium.tab.hpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 328 "annium.y"
                    { }
#line 2033 "annium.tab.hpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 328 "annium.y"
                    { }
#line 2039 "annium.tab.hpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 328 "annium.y"
                    { }
#line 2045 "annium.tab.hpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 328 "annium.y"
                    { }
#line 2051 "annium.tab.hpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 328 "annium.y"
                    { }
#line 2057 "annium.tab.hpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 328 "annium.y"
                    { }
#line 2063 "annium.tab.hpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 328 "annium.y"
                    { }
#line 2069 "annium.tab.hpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 328 "annium.y"
                    { }
#line 2075 "annium.tab.hpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 328 "annium.y"
                    { }
#line 2081 "annium.tab.hpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 328 "annium.y"
                    { }
#line 2087 "annium.tab.hpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 328 "annium.y"
                    { }
#line 2093 "annium.tab.hpp"
        break;

      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
#line 328 "annium.y"
                    { }
#line 2099 "annium.tab.hpp"
        break;

      case symbol_kind::S_statement: // statement
#line 328 "annium.y"
                    { }
#line 2105 "annium.tab.hpp"
        break;

      case symbol_kind::S_116_let_decl: // let-decl
#line 328 "annium.y"
                    { }
#line 2111 "annium.tab.hpp"
        break;

      case symbol_kind::S_117_let_decl_start: // let-decl-start
#line 328 "annium.y"
                    { }
#line 2117 "annium.tab.hpp"
        break;

      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 328 "annium.y"
                    { }
#line 2123 "annium.tab.hpp"
        break;

      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
#line 328 "annium.y"
                    { }
#line 2129 "annium.tab.hpp"
        break;

      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
#line 328 "annium.y"
                    { }
#line 2135 "annium.tab.hpp"
        break;

      case symbol_kind::S_121_function_body: // function-body
#line 328 "annium.y"
                    { }
#line 2141 "annium.tab.hpp"
        break;

      case symbol_kind::S_122_braced_statements: // braced-statements
#line 328 "annium.y"
                    { }
#line 2147 "annium.tab.hpp"
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
#line 328 "annium.y"
                    { }
#line 2153 "annium.tab.hpp"
        break;

      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
#line 328 "annium.y"
                    { }
#line 2159 "annium.tab.hpp"
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
#line 328 "annium.y"
                    { }
#line 2165 "annium.tab.hpp"
        break;

      case symbol_kind::S_126_infunction_statement: // infunction-statement
#line 328 "annium.y"
                    { }
#line 2171 "annium.tab.hpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 328 "annium.y"
                    { }
#line 2177 "annium.tab.hpp"
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
#line 328 "annium.y"
                    { }
#line 2183 "annium.tab.hpp"
        break;

      case symbol_kind::S_qname: // qname
#line 328 "annium.y"
                    { }
#line 2189 "annium.tab.hpp"
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
#line 328 "annium.y"
                    { }
#line 2195 "annium.tab.hpp"
        break;

      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
#line 328 "annium.y"
                    { }
#line 2201 "annium.tab.hpp"
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
#line 328 "annium.y"
                    { }
#line 2207 "annium.tab.hpp"
        break;

      case symbol_kind::S_133_fn_name: // fn-name
#line 328 "annium.y"
                    { }
#line 2213 "annium.tab.hpp"
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
#line 328 "annium.y"
                    { }
#line 2219 "annium.tab.hpp"
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
#line 328 "annium.y"
                    { }
#line 2225 "annium.tab.hpp"
        break;

      case symbol_kind::S_136_fn_decl: // fn-decl
#line 328 "annium.y"
                    { }
#line 2231 "annium.tab.hpp"
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
#line 328 "annium.y"
                    { }
#line 2237 "annium.tab.hpp"
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
#line 328 "annium.y"
                    { }
#line 2243 "annium.tab.hpp"
        break;

      case symbol_kind::S_139_case_list: // case-list
#line 328 "annium.y"
                    { }
#line 2249 "annium.tab.hpp"
        break;

      case symbol_kind::S_140_case_decl: // case-decl
#line 328 "annium.y"
                    { }
#line 2255 "annium.tab.hpp"
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
#line 328 "annium.y"
                    { }
#line 2261 "annium.tab.hpp"
        break;

      case symbol_kind::S_142_using_decl: // using-decl
#line 328 "annium.y"
                    { }
#line 2267 "annium.tab.hpp"
        break;

      case symbol_kind::S_143_expression_list: // expression-list
#line 328 "annium.y"
                    { }
#line 2273 "annium.tab.hpp"
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
#line 328 "annium.y"
                    { }
#line 2279 "annium.tab.hpp"
        break;

      case symbol_kind::S_145_argument_list: // argument-list
#line 328 "annium.y"
                    { }
#line 2285 "annium.tab.hpp"
        break;

      case symbol_kind::S_argument: // argument
#line 328 "annium.y"
                    { }
#line 2291 "annium.tab.hpp"
        break;

      case symbol_kind::S_147_argument_name: // argument-name
#line 328 "annium.y"
                    { }
#line 2297 "annium.tab.hpp"
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
#line 328 "annium.y"
                    { }
#line 2303 "annium.tab.hpp"
        break;

      case symbol_kind::S_149_field_list: // field-list
#line 328 "annium.y"
                    { }
#line 2309 "annium.tab.hpp"
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
#line 328 "annium.y"
                    { }
#line 2315 "annium.tab.hpp"
        break;

      case symbol_kind::S_field: // field
#line 328 "annium.y"
                    { }
#line 2321 "annium.tab.hpp"
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
#line 328 "annium.y"
                    { }
#line 2327 "annium.tab.hpp"
        break;

      case symbol_kind::S_153_parameter_list: // parameter-list
#line 328 "annium.y"
                    { }
#line 2333 "annium.tab.hpp"
        break;

      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
#line 328 "annium.y"
                    { }
#line 2339 "annium.tab.hpp"
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
#line 328 "annium.y"
                    { }
#line 2345 "annium.tab.hpp"
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
#line 328 "annium.y"
                    { }
#line 2351 "annium.tab.hpp"
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 328 "annium.y"
                    { }
#line 2357 "annium.tab.hpp"
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
#line 328 "annium.y"
                    { }
#line 2363 "annium.tab.hpp"
        break;

      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
#line 328 "annium.y"
                    { }
#line 2369 "annium.tab.hpp"
        break;

      case symbol_kind::S_160_constraint_expression: // constraint-expression
#line 328 "annium.y"
                    { }
#line 2375 "annium.tab.hpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 328 "annium.y"
                    { }
#line 2381 "annium.tab.hpp"
        break;

      case symbol_kind::S_162_pattern_list: // pattern-list
#line 328 "annium.y"
                    { }
#line 2387 "annium.tab.hpp"
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
#line 328 "annium.y"
                    { }
#line 2393 "annium.tab.hpp"
        break;

      case symbol_kind::S_164_pattern_field: // pattern-field
#line 328 "annium.y"
                    { }
#line 2399 "annium.tab.hpp"
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
#line 328 "annium.y"
                    { }
#line 2405 "annium.tab.hpp"
        break;

      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
#line 328 "annium.y"
                    { }
#line 2411 "annium.tab.hpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 328 "annium.y"
                    { }
#line 2417 "annium.tab.hpp"
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
#line 328 "annium.y"
                    { }
#line 2423 "annium.tab.hpp"
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
#line 328 "annium.y"
                    { }
#line 2429 "annium.tab.hpp"
        break;

      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
#line 328 "annium.y"
                    { }
#line 2435 "annium.tab.hpp"
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
#line 328 "annium.y"
                    { }
#line 2441 "annium.tab.hpp"
        break;

      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
#line 328 "annium.y"
                    { }
#line 2447 "annium.tab.hpp"
        break;

      case symbol_kind::S_173_syntax_expression: // syntax-expression
#line 328 "annium.y"
                    { }
#line 2453 "annium.tab.hpp"
        break;

      case symbol_kind::S_174_apostrophe_expression: // apostrophe-expression
#line 328 "annium.y"
                    { }
#line 2459 "annium.tab.hpp"
        break;

      case symbol_kind::S_175_new_expression: // new-expression
#line 328 "annium.y"
                    { }
#line 2465 "annium.tab.hpp"
        break;

      case symbol_kind::S_176_call_expression: // call-expression
#line 328 "annium.y"
                    { }
#line 2471 "annium.tab.hpp"
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
#line 328 "annium.y"
                    { }
#line 2477 "annium.tab.hpp"
        break;

      case symbol_kind::S_178_lambda_expression: // lambda-expression
#line 328 "annium.y"
                    { }
#line 2483 "annium.tab.hpp"
        break;

      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
#line 328 "annium.y"
                    { }
#line 2489 "annium.tab.hpp"
        break;

      case symbol_kind::S_180_pack_expression: // pack-expression
#line 328 "annium.y"
                    { }
#line 2495 "annium.tab.hpp"
        break;

      case symbol_kind::S_181_compound_expression: // compound-expression
#line 328 "annium.y"
                    { }
#line 2501 "annium.tab.hpp"
        break;

      case symbol_kind::S_182_type_expr: // type-expr
#line 328 "annium.y"
                    { }
#line 2507 "annium.tab.hpp"
        break;

       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.template destroy< annium::annotated_decimal_view > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.template destroy< annium::annotated_integer_view > ();
        break;

      case symbol_kind::S_133_fn_name: // fn-name
        value.template destroy< annium::annotated_qname_view > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.template destroy< annium::annotated_string_view > ();
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.template destroy< annotated_bool > ();
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_147_argument_name: // argument-name
        value.template destroy< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.template destroy< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        value.template destroy< annotated_qname > ();
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.template destroy< context_identifier > ();
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.template destroy< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        value.template destroy< field > ();
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.template destroy< field::default_spec > ();
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.template destroy< fn_kind > ();
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.template destroy< fn_pure > ();
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.template destroy< identifier > ();
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.template destroy< let_statement > ();
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.template destroy< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        value.template destroy< opt_named_expression_t > ();
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.template destroy< parameter > ();
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.template destroy< parameter::default_spec > ();
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.template destroy< parameter_list_t > ();
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
        value.template destroy< reference_expression > ();
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.template destroy< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.template destroy< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.template destroy< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.template destroy< statement_list_t > ();
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.template destroy< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.template destroy< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.template destroy< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.template destroy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.template destroy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.template destroy< std::vector<field> > ();
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.template destroy< std::vector<identifier> > ();
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.template destroy< struct_decl > ();
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression: // syntax-expression
      case symbol_kind::S_174_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_178_lambda_expression: // lambda-expression
      case symbol_kind::S_181_compound_expression: // compound-expression
      case symbol_kind::S_182_type_expr: // type-expr
        value.template destroy< syntax_expression > ();
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.template destroy< syntax_expression const* > ();
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.template destroy< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        value.template destroy< syntax_pattern > ();
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.template destroy< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.template destroy< syntax_pattern_field_list_t > ();
        break;

      case symbol_kind::S_142_using_decl: // using-decl
        value.template destroy< using_decl > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annium::annotated_decimal_view v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annium::annotated_decimal_view& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annium::annotated_integer_view v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annium::annotated_integer_view& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annium::annotated_string_view v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annium::annotated_string_view& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annotated_bool v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annotated_bool& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annotated_identifier v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annotated_identifier& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, annotated_nil v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const annotated_nil& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, resource_location v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const resource_location& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, sonia::string_view v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const sonia::string_view& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (void * scanner_yyarg, parser_context & ctx_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if ANNIUM_LANGDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNIUM_LANGerror (location_type l)
      {
        return symbol_type (token::ANNIUM_LANGerror, std::move (l));
      }
#else
      static
      symbol_type
      make_ANNIUM_LANGerror (const location_type& l)
      {
        return symbol_type (token::ANNIUM_LANGerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNIUM_LANGUNDEF (location_type l)
      {
        return symbol_type (token::ANNIUM_LANGUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_ANNIUM_LANGUNDEF (const location_type& l)
      {
        return symbol_type (token::ANNIUM_LANGUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT_BEGIN (location_type l)
      {
        return symbol_type (token::COMMENT_BEGIN, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT_BEGIN (const location_type& l)
      {
        return symbol_type (token::COMMENT_BEGIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT_END (location_type l)
      {
        return symbol_type (token::COMMENT_END, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT_END (const location_type& l)
      {
        return symbol_type (token::COMMENT_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (annium::annotated_string_view v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const annium::annotated_string_view& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (annium::annotated_string_view v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const annium::annotated_string_view& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTEXT_IDENTIFIER (annium::annotated_string_view v, location_type l)
      {
        return symbol_type (token::CONTEXT_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTEXT_IDENTIFIER (const annium::annotated_string_view& v, const location_type& l)
      {
        return symbol_type (token::CONTEXT_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESERVED_IDENTIFIER (annium::annotated_string_view v, location_type l)
      {
        return symbol_type (token::RESERVED_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RESERVED_IDENTIFIER (const annium::annotated_string_view& v, const location_type& l)
      {
        return symbol_type (token::RESERVED_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER_INDEX (annium::annotated_string_view v, location_type l)
      {
        return symbol_type (token::INTEGER_INDEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER_INDEX (const annium::annotated_string_view& v, const location_type& l)
      {
        return symbol_type (token::INTEGER_INDEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (annium::annotated_integer_view v, location_type l)
      {
        return symbol_type (token::INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const annium::annotated_integer_view& v, const location_type& l)
      {
        return symbol_type (token::INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECIMAL (annium::annotated_decimal_view v, location_type l)
      {
        return symbol_type (token::DECIMAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DECIMAL (const annium::annotated_decimal_view& v, const location_type& l)
      {
        return symbol_type (token::DECIMAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECIMAL_S (annium::annotated_decimal_view v, location_type l)
      {
        return symbol_type (token::DECIMAL_S, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DECIMAL_S (const annium::annotated_decimal_view& v, const location_type& l)
      {
        return symbol_type (token::DECIMAL_S, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPERATOR_TERM (sonia::string_view v, location_type l)
      {
        return symbol_type (token::OPERATOR_TERM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPERATOR_TERM (const sonia::string_view& v, const location_type& l)
      {
        return symbol_type (token::OPERATOR_TERM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CT_IDENTIFIER (annotated_identifier v, location_type l)
      {
        return symbol_type (token::CT_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CT_IDENTIFIER (const annotated_identifier& v, const location_type& l)
      {
        return symbol_type (token::CT_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (resource_location v, location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_APOSTROPHE (location_type l)
      {
        return symbol_type (token::APOSTROPHE, std::move (l));
      }
#else
      static
      symbol_type
      make_APOSTROPHE (const location_type& l)
      {
        return symbol_type (token::APOSTROPHE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT_SYMBOL (location_type l)
      {
        return symbol_type (token::AT_SYMBOL, std::move (l));
      }
#else
      static
      symbol_type
      make_AT_SYMBOL (const location_type& l)
      {
        return symbol_type (token::AT_SYMBOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDERSCORE (resource_location v, location_type l)
      {
        return symbol_type (token::UNDERSCORE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNDERSCORE (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::UNDERSCORE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROWAST (location_type l)
      {
        return symbol_type (token::ARROWAST, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROWAST (const location_type& l)
      {
        return symbol_type (token::ARROWAST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (location_type l)
      {
        return symbol_type (token::ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const location_type& l)
      {
        return symbol_type (token::ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROWEXPR (location_type l)
      {
        return symbol_type (token::ARROWEXPR, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROWEXPR (const location_type& l)
      {
        return symbol_type (token::ARROWEXPR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FARROW (location_type l)
      {
        return symbol_type (token::FARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_FARROW (const location_type& l)
      {
        return symbol_type (token::FARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTAST (location_type l)
      {
        return symbol_type (token::PTAST, std::move (l));
      }
#else
      static
      symbol_type
      make_PTAST (const location_type& l)
      {
        return symbol_type (token::PTAST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DBLPLUS (location_type l)
      {
        return symbol_type (token::DBLPLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_DBLPLUS (const location_type& l)
      {
        return symbol_type (token::DBLPLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DBLMINUS (location_type l)
      {
        return symbol_type (token::DBLMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_DBLMINUS (const location_type& l)
      {
        return symbol_type (token::DBLMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFTSHIFT (location_type l)
      {
        return symbol_type (token::LEFTSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFTSHIFT (const location_type& l)
      {
        return symbol_type (token::LEFTSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHTSHIFT (location_type l)
      {
        return symbol_type (token::RIGHTSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHTSHIFT (const location_type& l)
      {
        return symbol_type (token::RIGHTSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (resource_location v, location_type l)
      {
        return symbol_type (token::EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (resource_location v, location_type l)
      {
        return symbol_type (token::NE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::NE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGIC_AND (resource_location v, location_type l)
      {
        return symbol_type (token::LOGIC_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGIC_AND (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::LOGIC_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGIC_OR (resource_location v, location_type l)
      {
        return symbol_type (token::LOGIC_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGIC_OR (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::LOGIC_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONCAT (resource_location v, location_type l)
      {
        return symbol_type (token::CONCAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONCAT (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::CONCAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (resource_location v, location_type l)
      {
        return symbol_type (token::ELLIPSIS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::ELLIPSIS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDASSIGN (location_type l)
      {
        return symbol_type (token::ADDASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ADDASSIGN (const location_type& l)
      {
        return symbol_type (token::ADDASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBASSIGN (location_type l)
      {
        return symbol_type (token::SUBASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBASSIGN (const location_type& l)
      {
        return symbol_type (token::SUBASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULASSIGN (location_type l)
      {
        return symbol_type (token::MULASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MULASSIGN (const location_type& l)
      {
        return symbol_type (token::MULASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVASSIGN (location_type l)
      {
        return symbol_type (token::DIVASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVASSIGN (const location_type& l)
      {
        return symbol_type (token::DIVASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODASSIGN (location_type l)
      {
        return symbol_type (token::MODASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MODASSIGN (const location_type& l)
      {
        return symbol_type (token::MODASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSHIFTSSIGN (location_type l)
      {
        return symbol_type (token::LSHIFTSSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_LSHIFTSSIGN (const location_type& l)
      {
        return symbol_type (token::LSHIFTSSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSHIFTSSIGN (location_type l)
      {
        return symbol_type (token::RSHIFTSSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_RSHIFTSSIGN (const location_type& l)
      {
        return symbol_type (token::RSHIFTSSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITANDASSIGN (location_type l)
      {
        return symbol_type (token::BITANDASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_BITANDASSIGN (const location_type& l)
      {
        return symbol_type (token::BITANDASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITORASSIGN (location_type l)
      {
        return symbol_type (token::BITORASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_BITORASSIGN (const location_type& l)
      {
        return symbol_type (token::BITORASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITXORASSIGN (location_type l)
      {
        return symbol_type (token::BITXORASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_BITXORASSIGN (const location_type& l)
      {
        return symbol_type (token::BITXORASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DBLCOLON (location_type l)
      {
        return symbol_type (token::DBLCOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_DBLCOLON (const location_type& l)
      {
        return symbol_type (token::DBLCOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_PARENTHESIS (resource_location v, location_type l)
      {
        return symbol_type (token::OPEN_PARENTHESIS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_PARENTHESIS (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::OPEN_PARENTHESIS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_PARENTHESIS (location_type l)
      {
        return symbol_type (token::CLOSE_PARENTHESIS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSE_PARENTHESIS (const location_type& l)
      {
        return symbol_type (token::CLOSE_PARENTHESIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_BRACE (resource_location v, location_type l)
      {
        return symbol_type (token::OPEN_BRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_BRACE (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::OPEN_BRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_BRACE (location_type l)
      {
        return symbol_type (token::CLOSE_BRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSE_BRACE (const location_type& l)
      {
        return symbol_type (token::CLOSE_BRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_SQUARE_BRACKET (resource_location v, location_type l)
      {
        return symbol_type (token::OPEN_SQUARE_BRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_SQUARE_BRACKET (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::OPEN_SQUARE_BRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_SQUARE_BRACKET (location_type l)
      {
        return symbol_type (token::CLOSE_SQUARE_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSE_SQUARE_BRACKET (const location_type& l)
      {
        return symbol_type (token::CLOSE_SQUARE_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_SQUARE_DBL_BRACKET (resource_location v, location_type l)
      {
        return symbol_type (token::OPEN_SQUARE_DBL_BRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_SQUARE_DBL_BRACKET (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::OPEN_SQUARE_DBL_BRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_SQUARE_DBL_BRACKET (location_type l)
      {
        return symbol_type (token::CLOSE_SQUARE_DBL_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSE_SQUARE_DBL_BRACKET (const location_type& l)
      {
        return symbol_type (token::CLOSE_SQUARE_DBL_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_BROKET (location_type l)
      {
        return symbol_type (token::OPEN_BROKET, std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_BROKET (const location_type& l)
      {
        return symbol_type (token::OPEN_BROKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_BROKET (location_type l)
      {
        return symbol_type (token::CLOSE_BROKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSE_BROKET (const location_type& l)
      {
        return symbol_type (token::CLOSE_BROKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_STATEMENT (location_type l)
      {
        return symbol_type (token::END_STATEMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_END_STATEMENT (const location_type& l)
      {
        return symbol_type (token::END_STATEMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POINT (resource_location v, location_type l)
      {
        return symbol_type (token::POINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_POINT (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::POINT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (resource_location v, location_type l)
      {
        return symbol_type (token::PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (resource_location v, location_type l)
      {
        return symbol_type (token::MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASTERISK (resource_location v, location_type l)
      {
        return symbol_type (token::ASTERISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASTERISK (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::ASTERISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (location_type l)
      {
        return symbol_type (token::PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT (const location_type& l)
      {
        return symbol_type (token::PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND (resource_location v, location_type l)
      {
        return symbol_type (token::AMPERSAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AMPERSAND (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::AMPERSAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITOR (resource_location v, location_type l)
      {
        return symbol_type (token::BITOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BITOR (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::BITOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLPT (resource_location v, location_type l)
      {
        return symbol_type (token::EXCLPT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLPT (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::EXCLPT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDA (location_type l)
      {
        return symbol_type (token::TILDA, std::move (l));
      }
#else
      static
      symbol_type
      make_TILDA (const location_type& l)
      {
        return symbol_type (token::TILDA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCL (location_type l)
      {
        return symbol_type (token::EXCL, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCL (const location_type& l)
      {
        return symbol_type (token::EXCL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR (location_type l)
      {
        return symbol_type (token::DOLLAR, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR (const location_type& l)
      {
        return symbol_type (token::DOLLAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QMARK (resource_location v, location_type l)
      {
        return symbol_type (token::QMARK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QMARK (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::QMARK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HASHTAG (location_type l)
      {
        return symbol_type (token::HASHTAG, std::move (l));
      }
#else
      static
      symbol_type
      make_HASHTAG (const location_type& l)
      {
        return symbol_type (token::HASHTAG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (location_type l)
      {
        return symbol_type (token::VAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const location_type& l)
      {
        return symbol_type (token::VAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN (location_type l)
      {
        return symbol_type (token::EXTERN, std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERN (const location_type& l)
      {
        return symbol_type (token::EXTERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (resource_location v, location_type l)
      {
        return symbol_type (token::NEW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::NEW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN_ (location_type l)
      {
        return symbol_type (token::IN_, std::move (l));
      }
#else
      static
      symbol_type
      make_IN_ (const location_type& l)
      {
        return symbol_type (token::IN_, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (resource_location v, location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::CONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (resource_location v, location_type l)
      {
        return symbol_type (token::BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (resource_location v, location_type l)
      {
        return symbol_type (token::RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YIELD (resource_location v, location_type l)
      {
        return symbol_type (token::YIELD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_YIELD (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::YIELD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO (location_type l)
      {
        return symbol_type (token::AUTO, std::move (l));
      }
#else
      static
      symbol_type
      make_AUTO (const location_type& l)
      {
        return symbol_type (token::AUTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USING (location_type l)
      {
        return symbol_type (token::USING, std::move (l));
      }
#else
      static
      symbol_type
      make_USING (const location_type& l)
      {
        return symbol_type (token::USING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THROW (location_type l)
      {
        return symbol_type (token::THROW, std::move (l));
      }
#else
      static
      symbol_type
      make_THROW (const location_type& l)
      {
        return symbol_type (token::THROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (location_type l)
      {
        return symbol_type (token::SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const location_type& l)
      {
        return symbol_type (token::SIZEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWEST (location_type l)
      {
        return symbol_type (token::LOWEST, std::move (l));
      }
#else
      static
      symbol_type
      make_LOWEST (const location_type& l)
      {
        return symbol_type (token::LOWEST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEREF (location_type l)
      {
        return symbol_type (token::DEREF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEREF (const location_type& l)
      {
        return symbol_type (token::DEREF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIXMINUS (location_type l)
      {
        return symbol_type (token::PREFIXMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIXMINUS (const location_type& l)
      {
        return symbol_type (token::PREFIXMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCLUDE (location_type l)
      {
        return symbol_type (token::INCLUDE, std::move (l));
      }
#else
      static
      symbol_type
      make_INCLUDE (const location_type& l)
      {
        return symbol_type (token::INCLUDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE (location_type l)
      {
        return symbol_type (token::INLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE (const location_type& l)
      {
        return symbol_type (token::INLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIABLE (location_type l)
      {
        return symbol_type (token::VIABLE, std::move (l));
      }
#else
      static
      symbol_type
      make_VIABLE (const location_type& l)
      {
        return symbol_type (token::VIABLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FN (resource_location v, location_type l)
      {
        return symbol_type (token::FN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FN (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::FN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEFN (resource_location v, location_type l)
      {
        return symbol_type (token::TYPEFN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEFN (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::TYPEFN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (location_type l)
      {
        return symbol_type (token::ENUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const location_type& l)
      {
        return symbol_type (token::ENUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (location_type l)
      {
        return symbol_type (token::EXTENDS, std::move (l));
      }
#else
      static
      symbol_type
      make_EXTENDS (const location_type& l)
      {
        return symbol_type (token::EXTENDS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REQUIRES (location_type l)
      {
        return symbol_type (token::REQUIRES, std::move (l));
      }
#else
      static
      symbol_type
      make_REQUIRES (const location_type& l)
      {
        return symbol_type (token::REQUIRES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WEAK (location_type l)
      {
        return symbol_type (token::WEAK, std::move (l));
      }
#else
      static
      symbol_type
      make_WEAK (const location_type& l)
      {
        return symbol_type (token::WEAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPENAME (resource_location v, location_type l)
      {
        return symbol_type (token::TYPENAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPENAME (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::TYPENAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTEXPR (resource_location v, location_type l)
      {
        return symbol_type (token::CONSTEXPR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONSTEXPR (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::CONSTEXPR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUNTIME (resource_location v, location_type l)
      {
        return symbol_type (token::RUNTIME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUNTIME (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::RUNTIME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NIL_WORD (annotated_nil v, location_type l)
      {
        return symbol_type (token::NIL_WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NIL_WORD (const annotated_nil& v, const location_type& l)
      {
        return symbol_type (token::NIL_WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE_WORD (annotated_bool v, location_type l)
      {
        return symbol_type (token::TRUE_WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE_WORD (const annotated_bool& v, const location_type& l)
      {
        return symbol_type (token::TRUE_WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE_WORD (annotated_bool v, location_type l)
      {
        return symbol_type (token::FALSE_WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE_WORD (const annotated_bool& v, const location_type& l)
      {
        return symbol_type (token::FALSE_WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROBE (resource_location v, location_type l)
      {
        return symbol_type (token::PROBE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PROBE (const resource_location& v, const location_type& l)
      {
        return symbol_type (token::PROBE, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if ANNIUM_LANGDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1289,     ///< Last index in yytable_.
      yynnts_ = 72,  ///< Number of nonterminal symbols.
      yyfinal_ = 100 ///< Termination state number.
    };


    // User arguments.
    void * scanner;
    parser_context & ctx;

  };


} // annium_lang
#line 4971 "annium.tab.hpp"




#endif // !YY_ANNIUM_LANG_ANNIUM_TAB_HPP_INCLUDED
