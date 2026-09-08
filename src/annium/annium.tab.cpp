// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   annium_langlex

// First part of user prologue.
#line 25 "annium.y"

#include "sonia/config.hpp"
#include <iostream>
#include "parser.hpp"

using namespace sonia;
using namespace annium;

#include "annium.tab.hpp"

#include "environment.hpp"
#include "annium/utility/linked_list.ipp"

using YYSTYPE = annium_lang::parser::semantic_type;
using YYLTYPE = annium_lang::parser::location_type;

int annium_langlex(YYSTYPE * yylval_param, YYLTYPE * yylloc_param, parser_context & ctx, void* yyscanner);

void annium_lang::parser::error(const location_type& loc, const std::string& msg)
{
    ctx.append_error(loc.begin.line, loc.begin.column, loc.end.line, loc.end.column, msg);
}

#define IGNORE_TERM(...)


#line 70 "annium.tab.cpp"


#include "annium.tab.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if ANNIUM_LANGDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !ANNIUM_LANGDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !ANNIUM_LANGDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace annium_lang {
#line 167 "annium.tab.cpp"

  /// Build a parser object.
  parser::parser (void * scanner_yyarg, parser_context & ctx_yyarg)
#if ANNIUM_LANGDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      ctx (ctx_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.copy< annium::annotated_decimal_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.copy< annium::annotated_qname_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.copy< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.copy< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.copy< reference_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.copy< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.copy< using_decl > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.move< annium::annotated_decimal_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.move< annium::annotated_qname_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.move< reference_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.move< using_decl > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.YY_MOVE_OR_COPY< annium::annotated_decimal_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< annium::annotated_integer_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.YY_MOVE_OR_COPY< annium::annotated_qname_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.YY_MOVE_OR_COPY< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.YY_MOVE_OR_COPY< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.YY_MOVE_OR_COPY< reference_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.YY_MOVE_OR_COPY< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.YY_MOVE_OR_COPY< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.YY_MOVE_OR_COPY< using_decl > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.move< annium::annotated_decimal_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.move< annium::annotated_qname_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.move< reference_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.move< using_decl > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.copy< annium::annotated_decimal_view > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer_view > (that.value);
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.copy< annium::annotated_qname_view > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.copy< annium::annotated_string_view > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (that.value);
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.copy< identifier > (that.value);
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.copy< reference_expression > (that.value);
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (that.value);
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (that.value);
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.copy< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.copy< using_decl > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        value.move< annium::annotated_decimal_view > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (that.value);
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        value.move< annium::annotated_qname_view > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (that.value);
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< identifier > (that.value);
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        value.move< reference_expression > (that.value);
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (that.value);
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > (that.value);
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        value.move< using_decl > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if ANNIUM_LANGDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_STRING: // STRING
#line 351 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 351 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 351 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 351 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 351 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 351 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 351 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 351 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 351 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 351 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 351 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 351 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 351 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 351 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 351 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 351 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 351 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 351 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 351 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 351 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 351 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 351 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 351 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 351 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 351 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 351 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 351 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 351 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 351 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 351 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 351 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 351 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 351 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 351 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 351 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 351 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 351 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 351 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 351 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 351 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 351 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 351 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 351 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 351 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 351 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
#line 351 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 351 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_REFERENCE: // "reference modifier"
#line 351 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 351 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 351 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 351 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 351 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 351 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
#line 351 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 351 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl: // let-decl
#line 351 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start: // let-decl-start
#line 351 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 351 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
#line 351 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
#line 351 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_function_body: // function-body
#line 351 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_braced_statements: // braced-statements
#line 351 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_finished_statement: // finished-statement
#line 351 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_if_else_tail: // if-else-tail
#line 351 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
#line 351 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_expression_statement: // expression-statement
#line 351 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_generic_statement: // generic-statement
#line 351 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_infunction_statement: // infunction-statement
#line 351 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 351 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
#line 351 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 351 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
#line 351 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
#line 351 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
#line 351 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_name: // fn-name
#line 351 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
#line 351 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
#line 351 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_decl: // fn-decl
#line 351 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
#line 351 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
#line 351 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list: // case-list
#line 351 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_decl: // case-decl
#line 351 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
#line 351 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_using_decl: // using-decl
#line 351 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_expression_list: // expression-list
#line 351 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
#line 351 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list: // argument-list
#line 351 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 351 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_argument_name: // argument-name
#line 351 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
#line 351 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list: // field-list
#line 351 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
#line 351 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 351 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
#line 351 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list: // parameter-list
#line 351 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
#line 351 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
#line 351 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
#line 351 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
#line 351 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 351 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
#line 351 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
#line 351 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_constraint_expression: // constraint-expression
#line 351 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 351 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_list: // pattern-list
#line 351 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
#line 351 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_field: // pattern-field
#line 351 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
#line 351 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
#line 351 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 351 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
#line 351 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
#line 351 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
#line 351 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
#line 351 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
#line 351 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
#line 351 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_grouped_expression: // grouped-expression
#line 351 "annium.y"
                 { }
#line 2641 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_new_expression: // new-expression
#line 351 "annium.y"
                 { }
#line 2647 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_call_expression: // call-expression
#line 351 "annium.y"
                 { }
#line 2653 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_syntax_expression: // syntax-expression
#line 351 "annium.y"
                 { }
#line 2659 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
#line 351 "annium.y"
                 { }
#line 2665 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_lambda_expression: // lambda-expression
#line 351 "annium.y"
                 { }
#line 2671 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
#line 351 "annium.y"
                 { }
#line 2677 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_pack_expression: // pack-expression
#line 351 "annium.y"
                 { }
#line 2683 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_compound_expression: // compound-expression
#line 351 "annium.y"
                 { }
#line 2689 "annium.tab.cpp"
        break;

      case symbol_kind::S_188_type_expr: // type-expr
#line 351 "annium.y"
                 { }
#line 2695 "annium.tab.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if ANNIUM_LANGDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // ANNIUM_LANGDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, ctx, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
        yylhs.value.emplace< annium::annotated_decimal_view > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< annium::annotated_integer_view > ();
        break;

      case symbol_kind::S_137_fn_name: // fn-name
        yylhs.value.emplace< annium::annotated_qname_view > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        yylhs.value.emplace< annium::annotated_string_view > ();
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        yylhs.value.emplace< annotated_bool > ();
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_151_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
      case symbol_kind::S_140_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_144_case_decl: // case-decl
        yylhs.value.emplace< identifier > ();
        break;

      case symbol_kind::S_118_let_decl: // let-decl
      case symbol_kind::S_119_let_decl_start: // let-decl-start
      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
      case symbol_kind::S_149_argument_list: // argument-list
      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_186_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
        yylhs.value.emplace< reference_expression > ();
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
      case symbol_kind::S_UNDERSCORE: // "`_`"
      case symbol_kind::S_EQ: // "`==`"
      case symbol_kind::S_NE: // "`!=`"
      case symbol_kind::S_LESS: // "`<`"
      case symbol_kind::S_LESS_EQ: // "`<=`"
      case symbol_kind::S_GREATER: // "`>`"
      case symbol_kind::S_GREATER_EQ: // "`>=`"
      case symbol_kind::S_LOGIC_AND: // "`&&`"
      case symbol_kind::S_LOGIC_OR: // "`||`"
      case symbol_kind::S_CONCAT: // "`..`"
      case symbol_kind::S_ELLIPSIS: // "`...`"
      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
      case symbol_kind::S_OPEN_BRACE: // "`{`"
      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
      case symbol_kind::S_POINT: // "`.`"
      case symbol_kind::S_PLUS: // "`+`"
      case symbol_kind::S_MINUS: // "`-`"
      case symbol_kind::S_ASTERISK: // "`*`"
      case symbol_kind::S_SLASH: // "`/`"
      case symbol_kind::S_AMPERSAND: // "`&`"
      case symbol_kind::S_BITOR: // "`|`"
      case symbol_kind::S_EXCLPT: // "`!`"
      case symbol_kind::S_QMARK: // "`?`"
      case symbol_kind::S_AS: // "`as`"
      case symbol_kind::S_NEW: // "`new`"
      case symbol_kind::S_CONTINUE: // "`continue`"
      case symbol_kind::S_BREAK: // "`break`"
      case symbol_kind::S_RETURN: // "`return`"
      case symbol_kind::S_YIELD: // "`yield`"
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPEFN: // "`typefn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_REFERENCE: // "reference modifier"
      case symbol_kind::S_PROBE: // PROBE
        yylhs.value.emplace< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_125_finished_statement: // finished-statement
      case symbol_kind::S_128_expression_statement: // expression-statement
      case symbol_kind::S_129_generic_statement: // generic-statement
      case symbol_kind::S_130_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_123_function_body: // function-body
      case symbol_kind::S_124_braced_statements: // braced-statements
      case symbol_kind::S_126_if_else_tail: // if-else-tail
      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        yylhs.value.emplace< std::pair<resource_location, parameter::default_spec> > ();
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_165_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
        yylhs.value.emplace< std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ();
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        yylhs.value.emplace< std::vector<identifier> > ();
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_179_grouped_expression: // grouped-expression
      case symbol_kind::S_180_new_expression: // new-expression
      case symbol_kind::S_181_call_expression: // call-expression
      case symbol_kind::S_182_syntax_expression: // syntax-expression
      case symbol_kind::S_184_lambda_expression: // lambda-expression
      case symbol_kind::S_187_compound_expression: // compound-expression
      case symbol_kind::S_188_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_169_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_167_pattern_list: // pattern-list
        yylhs.value.emplace< syntax_pattern_field_list_t > ();
        break;

      case symbol_kind::S_146_using_decl: // using-decl
        yylhs.value.emplace< using_decl > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // begin: statement_any "end of file"
#line 356 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3202 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 357 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3208 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 362 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3214 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 364 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3220 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 366 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3226 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 383 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3232 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 384 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3238 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 386 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3244 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 388 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3250 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 393 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3256 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 395 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3269 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 404 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3275 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 406 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3281 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 410 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3287 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 412 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3293 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 417 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3299 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 419 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3305 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 423 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3311 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 425 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3317 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 430 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3323 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 432 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3329 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 434 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3335 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 439 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3341 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 440 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3347 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 442 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3353 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 444 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3359 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 449 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3365 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 453 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3371 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 464 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3377 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 469 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3383 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 471 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3389 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 473 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3395 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 475 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3401 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 477 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3407 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 479 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3413 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 481 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3423 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 491 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3429 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 496 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3435 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 498 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3441 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 502 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3447 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 503 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3453 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 508 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3459 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 510 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3468 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 518 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3474 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 520 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3480 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 522 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3491 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 529 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3497 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 530 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3503 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 534 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3509 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 536 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3515 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 538 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3521 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 540 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3527 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 542 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3533 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 544 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3539 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 549 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3545 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 557 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3551 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 572 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3557 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 574 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3563 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 576 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3569 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 581 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3575 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 582 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3581 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 586 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3587 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 587 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3593 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 592 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3599 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 594 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3605 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 599 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3611 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 601 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3617 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 606 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3623 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 623 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3629 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 626 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3635 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 637 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3641 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 639 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3647 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 641 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3653 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 648 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3659 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 652 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3665 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 653 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3671 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 658 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3677 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 660 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3683 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 665 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3689 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 671 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3695 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 673 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3701 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 696 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3711 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 702 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3722 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 719 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3728 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 721 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3734 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 726 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3740 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 727 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3746 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 732 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3752 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 734 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3758 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 739 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3764 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 741 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3770 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 746 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3776 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 748 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3782 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 753 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3788 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 754 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3794 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 759 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3800 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 761 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3806 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 765 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3812 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 766 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3818 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 771 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3824 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 773 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3830 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 779 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3836 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 780 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3842 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 785 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3848 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 787 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3854 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 791 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3860 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 792 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3866 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 796 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3872 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 797 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3878 "annium.tab.cpp"
    break;

  case 111: // ellipsis-opt-assign-value-opt: %empty
#line 801 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 3884 "annium.tab.cpp"
    break;

  case 112: // ellipsis-opt-assign-value-opt: "`...`"
#line 802 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 3890 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 803 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3896 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 804 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3902 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 810 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3908 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 814 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3914 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 820 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3920 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 822 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3930 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 829 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3939 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 835 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 3949 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 841 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ())) }; }
#line 3955 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 843 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3961 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 845 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3967 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 847 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()), .reference_condition = std::move(get<2>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ())) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3973 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 850 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ())) }; }
#line 3979 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 852 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3988 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 857 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3994 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 859 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ())) }; }
#line 4000 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: pattern-mod parameter-default-value-opt
#line 861 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > ())) }; }
#line 4006 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 869 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4015 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 874 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4024 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 879 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4033 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`...`" parameter-default-value-opt
#line 884 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4039 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 889 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4045 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified-mod: "constexpr modifier"
#line 895 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4051 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified-mod: "runctime modifier"
#line 896 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4057 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 901 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4063 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 903 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4069 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod
#line 907 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4075 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 909 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4081 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-mod: %empty
#line 914 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4090 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-mod: constraint-expression-specified-mod
#line 918 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4096 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod type-expr
#line 923 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4102 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 925 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4108 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod
#line 929 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4114 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod "`...`"
#line 931 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4120 "annium.tab.cpp"
    break;

  case 147: // subpatterns: "`(`" pattern-list "`)`"
#line 941 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4126 "annium.tab.cpp"
    break;

  case 148: // pattern-list: pattern-field
#line 946 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4132 "annium.tab.cpp"
    break;

  case 149: // pattern-list: pattern-list "," pattern-field
#line 948 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4138 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: concept-expression-list-opt
#line 954 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4144 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 956 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4150 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 959 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4156 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 961 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4162 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: "`=`" pattern-sfx
#line 965 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4168 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 968 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4174 "annium.tab.cpp"
    break;

  case 156: // pattern-field: identifier pattern-field-sfx
#line 974 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4180 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 977 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4186 "annium.tab.cpp"
    break;

  case 158: // pattern-field: pattern-field-sfx
#line 990 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4192 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`_`" pattern-field-sfx
#line 993 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4198 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" pattern-sfx
#line 997 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type, annotated_identifier{} }; }
#line 4204 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 998 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type, annotated_identifier{} }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4210 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 999 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type, annotated_identifier{} }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4216 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "reference modifier" pattern-sfx
#line 1000 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, annotated_identifier{} }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4222 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "reference modifier" "`(`" identifier "`)`" pattern-sfx
#line 1006 "annium.y"
        { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, std::move(yystack_[2].value.as < annotated_identifier > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4228 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "consteval modifier" syntax-expression
#line 1007 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value, annotated_identifier{} }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4234 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "typename modifier" pattern-sfx
#line 1008 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value, annotated_identifier{} }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4240 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "typename modifier"
#line 1009 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, annotated_identifier> > () = std::tuple{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value, annotated_identifier{} }; }
#line 4246 "annium.tab.cpp"
    break;

  case 168: // pattern-sfx: pattern
#line 1013 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4252 "annium.tab.cpp"
    break;

  case 169: // pattern-sfx: pattern "`...`"
#line 1014 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4258 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: "`...`"
#line 1015 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4264 "annium.tab.cpp"
    break;

  case 171: // pattern: qname
#line 1020 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4270 "annium.tab.cpp"
    break;

  case 172: // pattern: qname subpatterns concept-expression-list-opt
#line 1022 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4276 "annium.tab.cpp"
    break;

  case 173: // pattern: internal-identifier concept-expression-list-opt
#line 1024 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4282 "annium.tab.cpp"
    break;

  case 174: // pattern: "`_`" concept-expression-list-opt
#line 1026 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4288 "annium.tab.cpp"
    break;

  case 175: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1028 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4294 "annium.tab.cpp"
    break;

  case 176: // pattern: "`(`" "`)`"
#line 1030 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4300 "annium.tab.cpp"
    break;

  case 177: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1032 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4306 "annium.tab.cpp"
    break;

  case 178: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1034 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4312 "annium.tab.cpp"
    break;

  case 179: // pattern: concept-expression-list
#line 1036 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4318 "annium.tab.cpp"
    break;

  case 180: // concept-expression: "`@`" qname
#line 1041 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4324 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list-opt: %empty
#line 1046 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4330 "annium.tab.cpp"
    break;

  case 182: // concept-expression-list-opt: concept-expression-list
#line 1047 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4336 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list: concept-expression
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4342 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list: concept-expression-list concept-expression
#line 1054 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4348 "annium.tab.cpp"
    break;

  case 185: // reference-expression: CONTEXT_IDENTIFIER
#line 1060 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4354 "annium.tab.cpp"
    break;

  case 186: // reference-expression: qname
#line 1062 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4360 "annium.tab.cpp"
    break;

  case 187: // any-reference-expression: RESERVED_IDENTIFIER
#line 1067 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4366 "annium.tab.cpp"
    break;

  case 188: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1069 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4372 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: qname
#line 1071 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4378 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "nil"
#line 1076 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4384 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: "true"
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4390 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "false"
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4396 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: INTEGER
#line 1082 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4402 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: DECIMAL
#line 1084 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4408 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: DECIMAL_S
#line 1086 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4414 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: INTEGER_INDEX
#line 1088 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4420 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: STRING
#line 1090 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4426 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: CT_IDENTIFIER
#line 1092 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4432 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: any-reference-expression
#line 1093 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4438 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`(`" "`)`"
#line 1095 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4444 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1097 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4453 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1103 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4465 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1114 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4471 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1116 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4477 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1118 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4483 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: PROBE braced-statements
#line 1120 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4489 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`.`" identifier
#line 1122 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4495 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1129 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4505 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`-`" syntax-expression
#line 1136 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4511 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1138 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4517 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1152 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4523 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "`!`" syntax-expression
#line 1154 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4529 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: "`*`" syntax-expression
#line 1156 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4535 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1159 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4541 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1161 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4547 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1165 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4553 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1167 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4559 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1171 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4565 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1173 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4571 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1175 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4577 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1177 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4583 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4589 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1181 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4595 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1183 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4601 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1186 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4607 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1190 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4613 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1193 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4619 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1196 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4625 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1198 "annium.y"
        {
            annium_fn_type fnt{ .result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) };
            if (function_call const* fn_type = get_if<function_call>(&yystack_[2].value.as < syntax_expression > ().value)) {
                fnt.args = fn_type->args;
            } else if (entity_identifier const* peid = get_if<entity_identifier>(&yystack_[2].value.as < syntax_expression > ().value); !peid || *peid != ctx.make_entity_identifier(builtin_eid::void_)) {
                opt_named_expression_list_t args{ opt_named_expression_t{ std::move(yystack_[2].value.as < syntax_expression > ()) } };
                fnt.args = ctx.make_array<opt_named_expression_t>(args);
            } // else void args
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, std::move(fnt) }; 
        }
#line 4640 "annium.tab.cpp"
    break;

  case 230: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1210 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4646 "annium.tab.cpp"
    break;

  case 231: // grouped-expression: "`(`" pack-expression "`)`"
#line 1230 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4659 "annium.tab.cpp"
    break;

  case 232: // new-expression: "`new`" qname
#line 1243 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4665 "annium.tab.cpp"
    break;

  case 233: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1247 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4671 "annium.tab.cpp"
    break;

  case 234: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1254 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4677 "annium.tab.cpp"
    break;

  case 235: // call-expression: any-reference-expression "`.`" identifier
#line 1256 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4683 "annium.tab.cpp"
    break;

  case 236: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1258 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4692 "annium.tab.cpp"
    break;

  case 237: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1263 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4698 "annium.tab.cpp"
    break;

  case 238: // call-expression: call-expression "`.`" identifier
#line 1265 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4704 "annium.tab.cpp"
    break;

  case 239: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1267 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4713 "annium.tab.cpp"
    break;

  case 240: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1272 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4719 "annium.tab.cpp"
    break;

  case 241: // syntax-expression: syntax-expression-base
#line 1276 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4725 "annium.tab.cpp"
    break;

  case 242: // syntax-expression: new-expression
#line 1277 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4731 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: compound-expression
#line 1278 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4737 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: lambda-expression
#line 1279 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4743 "annium.tab.cpp"
    break;

  case 245: // syntax-expression: grouped-expression
#line 1280 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4749 "annium.tab.cpp"
    break;

  case 246: // lambda-start-decl: fn-prefix-decl
#line 1286 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4755 "annium.tab.cpp"
    break;

  case 247: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1288 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4761 "annium.tab.cpp"
    break;

  case 248: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1293 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4772 "annium.tab.cpp"
    break;

  case 249: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1300 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4784 "annium.tab.cpp"
    break;

  case 250: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1308 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4796 "annium.tab.cpp"
    break;

  case 251: // pack-expression-opt: %empty
#line 1319 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4802 "annium.tab.cpp"
    break;

  case 252: // pack-expression-opt: pack-expression
#line 1321 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4808 "annium.tab.cpp"
    break;

  case 253: // pack-expression: syntax-expression
#line 1326 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4814 "annium.tab.cpp"
    break;

  case 254: // pack-expression: identifier "`:`" syntax-expression
#line 1328 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4824 "annium.tab.cpp"
    break;

  case 255: // pack-expression: pack-expression "," syntax-expression
#line 1334 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4833 "annium.tab.cpp"
    break;

  case 256: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1339 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4842 "annium.tab.cpp"
    break;

  case 257: // compound-expression: syntax-expression "`...`"
#line 1347 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4848 "annium.tab.cpp"
    break;

  case 258: // compound-expression: call-expression
#line 1348 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4854 "annium.tab.cpp"
    break;

  case 259: // type-expr: qname
#line 1389 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4860 "annium.tab.cpp"
    break;

  case 260: // type-expr: RESERVED_IDENTIFIER
#line 1391 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4866 "annium.tab.cpp"
    break;

  case 261: // type-expr: CONTEXT_IDENTIFIER
#line 1393 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4872 "annium.tab.cpp"
    break;

  case 262: // type-expr: call-expression
#line 1394 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4878 "annium.tab.cpp"
    break;

  case 263: // type-expr: "`[`" type-expr "`]`"
#line 1396 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4884 "annium.tab.cpp"
    break;

  case 264: // type-expr: "`(`" "`)`"
#line 1398 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4890 "annium.tab.cpp"
    break;

  case 265: // type-expr: grouped-expression
#line 1399 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4896 "annium.tab.cpp"
    break;

  case 266: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1401 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4902 "annium.tab.cpp"
    break;

  case 267: // type-expr: type-expr "`|`" type-expr
#line 1403 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4908 "annium.tab.cpp"
    break;

  case 268: // type-expr: type-expr "`->`" type-expr
#line 1405 "annium.y"
        {
            annium_fn_type fnt{ .result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) };
            if (function_call const* fn_type = get_if<function_call>(&yystack_[2].value.as < syntax_expression > ().value)) {
                fnt.args = fn_type->args;
            } else if (entity_identifier const* peid = get_if<entity_identifier>(&yystack_[2].value.as < syntax_expression > ().value); !peid || *peid != ctx.make_entity_identifier(builtin_eid::void_)) {
                opt_named_expression_list_t args{ opt_named_expression_t{ std::move(yystack_[2].value.as < syntax_expression > ()) } };
                fnt.args = ctx.make_array<opt_named_expression_t>(args);
            } // else void args
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, std::move(fnt) }; 
        }
#line 4923 "annium.tab.cpp"
    break;


#line 4927 "annium.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -344;

  const short parser::yytable_ninf_ = -190;

  const short
  parser::yypact_[] =
  {
     905,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
      46,  1013,  1034,    46,  1271,  1271,  1271,     5,    58,    51,
    1271,   245,  1271,    51,    65,  -344,  -344,  -344,    22,    51,
      51,  1271,    -6,  -344,  -344,  -344,    27,    90,    17,   581,
    -344,  -344,  -344,  -344,  -344,    60,  -344,   387,    20,   163,
    -344,   124,  -344,   238,  1279,   175,  -344,    29,  -344,  1271,
    -344,   272,   191,  1688,   -14,  -344,   797,   301,   138,  1688,
    -344,   162,   162,   162,    46,  -344,   277,   278,  -344,    46,
      22,   281,   915,  -344,    60,   295,  1359,   183,  -344,  -344,
    -344,    60,   328,  -344,   270,  -344,   341,  -344,   162,  1271,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,    46,  -344,
    -344,  1271,   252,    97,  1271,    46,  1271,  1271,    46,  -344,
    1271,   326,  1271,  1271,  1271,  1271,  1271,  1271,  1271,  1271,
    1271,  -344,  1271,  1271,  1271,  1271,  1271,  1271,  1271,   326,
     441,  1406,  1271,  -344,  1271,  -344,  -344,  1271,  1271,   344,
     689,  -344,   329,  -344,  -344,  -344,  -344,  1142,  -344,   326,
    1271,   357,  -344,  1271,  1271,  -344,  1271,   340,  1271,   441,
     441,    46,   376,   441,  1453,  -344,   398,   401,   326,   600,
    1271,  -344,   420,   427,   429,   151,   437,  1688,   261,   415,
    1163,   326,   386,   163,   124,   238,     7,   476,   476,   476,
     476,   476,   476,   807,   699,   495,  1500,   306,   306,    21,
      21,  1749,  1735,   249,  -344,    51,   471,   477,    55,   326,
     321,   533,  -344,  1271,  -344,    43,   128,   320,   440,   426,
    -344,   560,   477,   477,  -344,   393,  -344,  1688,   449,  1688,
    1688,  1688,  -344,  -344,  -344,  -344,  -344,  -344,  1688,   249,
     401,   326,    38,   454,   438,  -344,  1271,  1688,    27,  1359,
     956,  -344,  1688,   457,   458,  -344,   464,   443,  -344,    46,
     467,  1271,  -344,   249,    18,   468,  1271,   471,   425,  -344,
     471,  1688,  -344,  1271,  -344,  -344,  1271,  -344,   244,   326,
    1271,   326,  -344,    60,    74,   471,  1271,  -344,   477,   297,
    -344,   533,   533,   773,  -344,   483,  -344,  1688,  -344,   289,
     197,    74,  1271,   506,  -344,   366,   441,  -344,   393,   132,
    -344,  -344,  -344,  -344,  1271,   249,  -344,  -344,  -344,  1271,
    1688,  -344,  -344,  -344,  -344,    22,   502,   424,  -344,    46,
      12,   478,   470,  -344,   521,   162,   274,   471,  -344,  -344,
    1547,  -344,   471,   492,   496,  -344,     7,  1594,     7,  -344,
    1688,  -344,    74,  -344,  -344,    37,  -344,  -344,   197,   504,
     471,   260,   477,   477,   393,  -344,  1688,  1271,   326,  1271,
     600,  -344,  -344,  -344,  -344,  -344,  1688,  -344,    27,  1271,
     507,  -344,  -344,  1271,   326,  -344,    46,   508,   533,   434,
     552,   434,   382,   255,  -344,  -344,   524,  -344,    18,  -344,
    -344,  -344,  -344,  -344,   511,   471,   477,   477,   400,   396,
     400,  -344,   348,  -344,  -344,  -344,  1688,   177,  1688,   169,
    1688,  1271,  1688,   185,  -344,    46,  -344,  -344,   434,  -344,
     533,   526,  -344,   274,  -344,   471,  -344,   533,   400,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,  1641,
    1271,  -344,   513,  -344,  -344,  -344,  -344,  -344,  -344,  -344,
    -344,  1688,  -344
  };

  const short
  parser::yydefact_[] =
  {
       4,   197,    56,   188,   187,   196,   193,   194,   195,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    65,     0,     0,
       0,     0,     0,   190,   191,   192,     0,     0,     0,     0,
       5,     7,    49,    13,    59,   189,    63,     0,   246,   199,
     241,   245,   242,   258,     0,     0,   244,   243,    58,     0,
     200,    59,   246,   253,     0,   243,    21,     0,     0,    85,
     207,   209,   213,   212,     0,    45,    19,    15,    17,     0,
       0,   232,     0,   185,   186,     0,     0,     0,    48,    31,
      68,    67,     0,    46,     0,    38,     0,    14,   210,     0,
     206,     1,     2,    10,     3,     8,     6,     9,     0,    66,
      64,   251,    72,     0,   251,     0,   251,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   231,     0,    52,    51,    53,     0,    41,
      42,    24,     0,    50,    22,   204,   202,     0,    18,     0,
       0,     0,    12,    87,     0,    32,     0,    35,     0,   103,
     103,    76,     0,   103,     0,    60,     0,   252,     0,     0,
       0,    37,     0,   235,     0,     0,   238,    44,   261,   260,
       0,     0,   259,     0,   265,   262,   229,   218,   219,   220,
     221,   222,   223,   227,   228,   224,     0,   216,   217,   214,
     215,   225,   226,   230,    57,     0,   181,   109,     0,     0,
       0,   167,   135,     0,   136,    59,   181,   111,     0,   104,
     105,   139,   109,   109,   183,   111,   201,   254,    59,   255,
      54,    55,    27,    25,    26,    23,    30,   203,    86,    20,
      16,     0,    59,     0,    88,    89,     0,    92,     0,     0,
       0,    36,    83,     0,     0,    80,     0,    77,    78,    95,
       0,     0,   247,    73,   181,     0,     0,   181,   171,    74,
     179,    47,   234,   251,   240,   237,   251,   264,     0,     0,
       0,     0,   205,   180,   111,   182,     0,   133,   109,     0,
     170,     0,     0,     0,   160,   168,   166,   165,   108,     0,
     141,   111,     0,   112,   120,     0,     0,   140,   111,   137,
     117,   129,   132,   184,     0,    11,    93,    94,   233,     0,
      91,    33,    34,    39,    40,     0,     0,    70,    75,     0,
       0,     0,    96,    97,     0,   211,   181,   181,   174,   176,
       0,   173,   181,     0,     0,   263,   268,     0,   267,   131,
     110,   128,   111,   161,   162,     0,   163,   169,   141,     0,
     142,   145,   109,   109,   111,   130,   113,     0,     0,     0,
       0,   248,    28,   106,   119,   138,   256,    90,     0,     0,
       0,    69,    79,     0,     0,    81,     0,     0,     0,   181,
       0,   181,   181,     0,   158,   148,   150,   175,   181,   172,
     236,   239,   266,   118,     0,   142,   109,   109,   109,   141,
     109,   146,   143,   116,   125,   126,   114,     0,    29,     0,
      84,     0,   102,    99,    98,    95,   154,   159,   181,   156,
       0,   152,   147,   181,   151,   181,   177,     0,   109,   115,
     121,   122,   142,   134,   124,   127,   144,   249,   250,     0,
       0,   101,     0,   157,   155,   153,   149,   178,   164,   123,
      71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -344,  -344,  -344,  -344,   530,  -344,  -344,  -344,  -344,  -344,
      28,    26,   -34,  -344,  -344,   407,   -58,   422,    67,  -122,
     225,   518,  -344,     1,  -344,   545,  -344,   -73,  -344,  -344,
    -344,   235,  -344,  -344,  -344,  -344,  -344,   246,  -344,   141,
    -344,  -344,   182,   269,  -344,  -344,    50,  -201,   263,  -254,
    -344,  -344,  -343,  -268,  -344,  -336,   137,  -209,  -197,  -177,
    -231,  -180,    39,  -344,    56,  -344,   233,  -344,   242,     0,
    -344,  -344,   -95,     2,     6,  -136
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    75,    76,    77,   149,   150,
     381,   382,    41,   261,   152,    42,    43,   154,    44,   277,
      45,    46,    47,    62,    92,   112,   391,   113,    95,   266,
     267,   268,    97,    88,    68,   253,   254,   255,   256,   341,
     342,   461,   343,   228,   229,   309,   297,   314,   230,   231,
     232,   371,   372,   347,   403,   404,   405,   233,   304,   305,
     234,   406,   295,    85,    49,    50,    51,    52,    53,    63,
      55,    56,   176,   177,    65,   196
  };

  const short
  parser::yytable_[] =
  {
      54,    48,   279,   213,   323,   107,    57,   162,   153,   298,
     352,     2,    69,    64,    71,    72,    73,   102,   226,   182,
      82,   184,    86,   249,   306,   416,     2,   289,     2,   -43,
     119,    98,   151,   393,   322,   215,   294,   143,    67,    54,
      48,   121,   273,     2,    99,    57,   311,   226,   226,   323,
     214,   226,     2,   326,   144,   288,   370,     2,   131,   141,
     394,   290,   100,   437,   323,   439,    54,    48,   346,    10,
      89,    10,    57,   103,   111,   132,   453,    58,    61,    66,
      70,   -43,   -43,   299,    78,   -43,   327,   323,   349,   312,
     101,  -107,   153,   359,   348,   319,    90,   351,    90,   174,
      10,   373,   463,   308,   363,   364,   366,    74,   165,   108,
     375,   313,   167,  -107,   415,   325,   244,   384,   180,   185,
     187,   220,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    79,   206,   207,   208,   209,   210,   211,   212,   181,
     445,   158,   237,   323,   239,   215,   161,   240,   241,    66,
      54,    48,   289,   356,    80,   358,    57,   248,   221,   417,
     223,   413,   250,   257,    54,   452,   259,   407,   262,   385,
      57,   119,   409,   425,   116,   175,   310,   193,    61,   235,
     281,    61,   183,    61,    61,   186,   290,   323,   353,   323,
     379,   354,    64,   156,   226,   193,   291,   289,   379,   131,
     460,   436,   285,   429,   168,   289,   157,   225,   235,   235,
     454,   238,   235,   114,   215,   193,   132,   323,   280,   144,
     115,    66,   441,   307,   402,   140,   334,    61,   446,    66,
     252,   290,   108,   169,   193,   422,   225,   225,   265,   290,
     225,   291,   427,   464,    81,   111,    84,   193,    87,   291,
     468,     2,    83,    91,    94,    96,   330,    61,   433,   280,
     280,   335,   388,   220,   289,   467,     2,   188,   189,   289,
     318,   345,   178,    91,   179,   193,   350,   402,   438,   402,
       2,   214,   320,   321,   331,   332,   333,   193,   117,   398,
     357,   215,   399,   160,    10,   118,   360,   421,   290,   355,
     221,   222,   223,   290,   224,    91,   442,   193,   291,    10,
     190,  -188,   376,   291,   191,   119,   402,   289,  -188,   108,
     142,   402,   171,   443,   386,   159,   121,     2,   214,   257,
     108,   163,     2,   188,   189,   312,   340,   368,   215,   274,
     280,   280,   280,   131,   400,   193,   192,   193,   361,   374,
      61,   290,   362,    61,   194,   235,   155,   313,   300,   369,
     132,   291,   172,   195,   192,   227,   135,   136,   289,   108,
      10,   275,   194,   276,   166,    10,   190,   426,   170,   428,
     191,   195,   246,   225,   192,   456,   378,   379,   380,   430,
     108,   173,   194,   432,   227,   227,   252,   440,   227,   215,
     242,   195,   290,   192,   278,   251,   265,   418,   312,   420,
     215,   194,   291,   401,   181,   296,   192,   215,    66,   280,
     195,   260,   423,   424,   194,   301,   269,   193,   302,   303,
     313,   459,   414,   195,   193,   108,  -189,   280,   263,   264,
     293,   214,   270,  -189,   192,   278,   278,     2,   214,   398,
     193,   215,   194,   272,   448,   457,   192,   458,   215,   216,
     471,   195,   220,   340,   194,  -187,   449,   450,   451,   144,
     455,   282,  -187,   195,   108,   346,   192,   283,   217,   280,
     284,    25,    26,   109,   194,   119,   280,   286,   215,   218,
      10,   315,   296,   195,   316,   219,   121,   324,   469,   221,
     222,   223,   340,   224,   119,   328,   329,   220,   336,   337,
     401,   339,   130,   131,   192,   121,   192,   338,   344,   349,
     367,   377,   194,   389,   194,   390,   278,   278,   278,   395,
     132,   195,   131,   195,   133,   134,   135,   136,   396,     2,
     214,   227,   397,   410,   221,   222,   223,   411,   224,   132,
     215,   274,   419,   133,   134,   135,   136,   431,   435,   214,
      91,   444,   447,   465,   472,   110,     2,   188,   189,   106,
     300,   258,   245,    93,   392,   387,   462,   215,   434,   383,
     466,   104,    10,   275,     0,   276,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,   192,   317,     0,     0,
       0,     0,     0,   192,   194,   278,     2,   214,     0,    10,
     190,   194,     0,   195,   191,     0,     0,   215,   274,   192,
     195,     0,     0,   278,     0,     0,     0,   194,     0,     0,
      10,    11,     0,     0,     0,    12,   195,   105,    13,     0,
      14,    15,     0,     0,     0,     0,    16,     0,     0,    10,
     275,     0,   276,    17,     0,     0,    18,    19,    20,    21,
       0,    22,     0,     0,     0,   278,     0,     0,    23,     0,
       0,     0,   278,     0,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,    35,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,     0,   130,   131,     0,    10,    11,
       0,     0,     0,    12,     0,   243,    13,     0,    14,    15,
       0,     0,     0,   132,    16,     0,     0,   133,   134,   135,
     136,    17,   137,   138,     0,    19,    20,    21,     0,    22,
       0,   145,   146,   147,   148,     0,    23,     0,     0,     2,
     214,     0,    24,    25,    26,    27,    28,    29,     0,     0,
     215,   274,     0,     0,    31,    32,     0,     0,    33,    34,
      35,    36,     1,     2,     3,     4,     5,     6,     7,     8,
     300,     9,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,    10,   365,     0,   276,     0,   121,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   130,   131,     0,    10,    11,     0,     0,
       0,    12,     0,     0,    13,     0,    14,    15,     0,     0,
       0,   132,    16,     0,     0,   133,   134,   135,   136,    17,
     137,   138,     0,    19,    20,    21,     0,    22,     0,   145,
     146,   147,   148,     0,    23,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,    66,     0,   132,
      16,   164,     0,   133,   134,   135,   136,    17,   137,   138,
      18,    19,    20,    21,     0,    22,     0,     0,     0,   139,
       0,     0,    23,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,     0,     0,     0,    66,     0,
      31,    32,     0,     0,    33,    34,    35,    36,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,    20,    21,     0,    22,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,    24,
      25,    26,    27,     0,    29,     0,     0,     0,     0,     0,
       0,    59,    10,    11,    60,     0,     0,    12,     0,     0,
      13,     0,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,    10,    11,     0,    66,     0,    12,    19,
       0,    13,     0,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      19,     0,     0,     0,     0,     0,     0,     0,    31,    32,
       0,     0,    33,    34,    35,    36,     0,     0,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,     0,    33,    34,    35,    36,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,    12,   247,     0,    13,
       0,    14,    15,     0,     0,     0,     0,    16,     0,     0,
       0,     0,    10,    11,   287,     0,     0,    12,    19,     0,
      13,     0,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    19,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
       0,    33,    34,    35,    36,     0,     0,    25,    26,    27,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
       0,     0,    33,    34,    35,    36,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   119,     0,
       0,     0,     0,     0,   120,     0,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
      10,    11,     0,     0,     0,    12,     0,     0,    13,     0,
      14,    15,     0,   132,     0,     0,    16,   133,   134,   135,
     136,     0,   137,   138,     0,     0,     0,    19,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,   119,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   121,
      33,    34,    35,    36,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,   132,     0,   119,     0,   133,   134,   135,
     136,     0,   137,   138,     0,     0,   121,     0,     0,     0,
       0,     0,     0,   139,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
     132,     0,   119,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,   121,     0,     0,     0,     0,     0,     0,
     139,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,   132,     0,   119,
       0,   133,   134,   135,   136,     0,   137,   138,     0,     0,
     121,     0,     0,     0,     0,     0,     0,   139,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   292,   119,     0,   133,   134,
     135,   136,     0,   137,   138,     0,     0,   121,     0,     0,
       0,     0,     0,     0,   139,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   132,     0,   119,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   139,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   412,
     119,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   470,     0,     0,   132,     0,   119,     0,   133,
     134,   135,   136,     0,   137,   138,     0,     0,   121,     0,
       0,     0,     0,     0,     0,   139,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,   119,     0,   133,   134,   135,   136,
       0,   137,   138,     0,     0,   121,     0,     0,   119,     0,
       0,     0,   139,   122,   123,   124,   125,   126,   127,   121,
       0,   130,   131,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,     0,     0,   130,   131,     0,     0,   132,
       0,     0,     0,   133,   134,   135,   136,     0,   137,     0,
       0,     0,     0,   132,     0,     0,     0,   133,   134,   135,
     136
  };

  const short
  parser::yycheck_[] =
  {
       0,     0,   179,   139,   235,    39,     0,    80,    66,   218,
     278,     6,    12,    11,    14,    15,    16,     0,   140,   114,
      20,   116,    22,   159,   221,   368,     6,    20,     6,     0,
       9,    31,    66,    21,   235,    17,   216,    51,    12,    39,
      39,    20,   178,     6,    50,    39,   226,   169,   170,   280,
       7,   173,     6,    15,    68,   191,   310,     6,    37,    59,
      48,    54,    36,   399,   295,   401,    66,    66,    50,    49,
       5,    49,    66,    56,    54,    54,   419,    10,    11,    52,
      13,    52,    53,   219,    17,    56,    48,   318,    51,    15,
       0,    48,   150,   294,   274,   231,    76,   277,    76,    99,
      49,   310,   438,   225,   301,   302,   303,   102,    82,    49,
     311,    37,    86,    70,   368,   251,   150,   318,    21,   117,
     120,    66,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    73,   132,   133,   134,   135,   136,   137,   138,   113,
     408,    74,   142,   374,   144,    17,    79,   147,   148,    52,
     150,   150,    20,   289,    96,   291,   150,   157,   103,   368,
     105,   362,   160,   163,   164,   419,   166,   347,   168,    37,
     164,     9,   352,   374,    50,   108,    48,   121,   111,   140,
     180,   114,   115,   116,   117,   118,    54,   418,   283,   420,
      21,   286,   190,    55,   316,   139,    64,    20,    21,    37,
      15,   398,    51,   380,    21,    20,    68,   140,   169,   170,
     419,   144,   173,    50,    17,   159,    54,   448,   179,    68,
      57,    52,   402,   223,   346,    50,   260,   160,   408,    52,
     163,    54,    49,    50,   178,   371,   169,   170,   171,    54,
     173,    64,   378,   440,    19,    54,    21,   191,    23,    64,
     447,     6,     7,    28,    29,    30,   256,   190,   394,   220,
     221,   260,   335,    66,    20,   445,     6,     7,     8,    20,
     231,   271,    20,    48,    22,   219,   276,   399,   400,   401,
       6,     7,   232,   233,   258,   259,   260,   231,    50,    15,
     290,    17,    18,    15,    49,    57,   296,    37,    54,    55,
     103,   104,   105,    54,   107,    80,    51,   251,    64,    49,
      50,    50,   312,    64,    54,     9,   438,    20,    57,    49,
      48,   443,    52,    68,   324,    48,    20,     6,     7,   329,
      49,    50,     6,     7,     8,    15,   269,    48,    17,    18,
     301,   302,   303,    37,    70,   289,   121,   291,   298,   310,
     283,    54,    55,   286,   121,   316,    55,    37,    37,    70,
      54,    64,    21,   121,   139,   140,    60,    61,    20,    49,
      49,    50,   139,    52,    79,    49,    50,   377,    50,   379,
      54,   139,    53,   316,   159,    37,    20,    21,    22,   389,
      49,    50,   159,   393,   169,   170,   329,    15,   173,    17,
      56,   159,    54,   178,   179,    48,   339,   368,    15,   370,
      17,   178,    64,   346,   388,    15,   191,    17,    52,   380,
     178,    81,   372,   373,   191,   104,    50,   371,   107,   108,
      37,   431,   365,   191,   378,    49,    50,   398,   169,   170,
     215,     7,   173,    57,   219,   220,   221,     6,     7,    15,
     394,    17,   219,    55,   415,   427,   231,   429,    17,    18,
     460,   219,    66,   396,   231,    50,   416,   417,   418,    68,
     420,    51,    57,   231,    49,    50,   251,    50,    37,   440,
      51,    94,    95,    96,   251,     9,   447,    50,    17,    48,
      49,    51,    15,   251,    68,    54,    20,    48,   448,   103,
     104,   105,   435,   107,     9,    51,    68,    66,    51,    51,
     443,    68,    36,    37,   289,    20,   291,    53,    51,    51,
      37,    15,   289,    21,   291,   101,   301,   302,   303,    51,
      54,   289,    37,   291,    58,    59,    60,    61,    68,     6,
       7,   316,    21,    51,   103,   104,   105,    51,   107,    54,
      17,    18,    48,    58,    59,    60,    61,    50,    50,     7,
     335,    37,    51,    37,    51,    47,     6,     7,     8,    39,
      37,   164,   150,    28,   339,   329,   435,    17,   396,   316,
     443,     0,    49,    50,    -1,    52,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,   371,    37,    -1,    -1,
      -1,    -1,    -1,   378,   371,   380,     6,     7,    -1,    49,
      50,   378,    -1,   371,    54,    -1,    -1,    17,    18,   394,
     378,    -1,    -1,   398,    -1,    -1,    -1,   394,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,   394,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    49,
      50,    -1,    52,    72,    -1,    -1,    75,    76,    77,    78,
      -1,    80,    -1,    -1,    -1,   440,    -1,    -1,    87,    -1,
      -1,    -1,   447,    -1,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    54,    65,    -1,    -1,    58,    59,    60,
      61,    72,    63,    64,    -1,    76,    77,    78,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    87,    -1,    -1,     6,
       7,    -1,    93,    94,    95,    96,    97,    98,    -1,    -1,
      17,    18,    -1,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,     5,     6,     7,     8,     9,    10,    11,    12,
      37,    14,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    37,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    54,    65,    -1,    -1,    58,    59,    60,    61,    72,
      63,    64,    -1,    76,    77,    78,    -1,    80,    -1,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    52,    -1,    54,
      65,    56,    -1,    58,    59,    60,    61,    72,    63,    64,
      75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,    74,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    52,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    80,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    93,
      94,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    54,    76,
      -1,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,   109,   110,   111,   112,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    54,    76,    -1,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,    -1,    -1,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    54,    -1,    -1,    65,    58,    59,    60,
      61,    -1,    63,    64,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    20,
     109,   110,   111,   112,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,     9,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,     9,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,     9,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,     9,    -1,    58,    59,
      60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,     9,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
       9,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,     9,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,     9,    -1,    58,    59,    60,    61,
      -1,    63,    64,    -1,    -1,    20,    -1,    -1,     9,    -1,
      -1,    -1,    74,    28,    29,    30,    31,    32,    33,    20,
      -1,    36,    37,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    37,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,    60,
      61
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      49,    50,    54,    57,    59,    60,    65,    72,    75,    76,
      77,    78,    80,    87,    93,    94,    95,    96,    97,    98,
      99,   105,   106,   109,   110,   111,   112,   114,   115,   116,
     117,   125,   128,   129,   131,   133,   134,   135,   136,   177,
     178,   179,   180,   181,   182,   183,   184,   187,   131,    48,
      51,   131,   136,   182,   186,   187,    52,   124,   147,   182,
     131,   182,   182,   182,   102,   118,   119,   120,   131,    73,
      96,   133,   182,     7,   133,   176,   182,   133,   146,     5,
      76,   133,   137,   138,   133,   141,   133,   145,   182,    50,
     124,     0,     0,    56,     0,    56,   117,   125,    49,    96,
     134,    54,   138,   140,    50,    57,    50,    50,    57,     9,
      15,    20,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    54,    58,    59,    60,    61,    63,    64,    74,
      50,   182,    48,    51,    68,    82,    83,    84,    85,   121,
     122,   125,   127,   129,   130,    55,    55,    68,   131,    48,
      15,   131,   140,    50,    56,   124,    79,   124,    21,    50,
      50,    52,    21,    50,   182,   131,   185,   186,    20,    22,
      21,   124,   185,   131,   185,   186,   131,   182,     7,     8,
      50,    54,   133,   177,   179,   181,   188,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   188,     7,    17,    18,    37,    48,    54,
      66,   103,   104,   105,   107,   131,   132,   133,   156,   157,
     161,   162,   163,   170,   173,   175,    51,   182,   131,   182,
     182,   182,    56,    56,   125,   130,    53,    55,   182,   188,
     186,    48,   131,   148,   149,   150,   151,   182,   128,   182,
      81,   126,   182,   156,   156,   131,   142,   143,   144,    50,
     156,    51,    55,   188,    18,    50,    52,   132,   133,   172,
     175,   182,    51,    50,    51,    51,    50,    51,   188,    20,
      54,    64,    55,   133,   174,   175,    15,   159,   170,   188,
      37,   104,   107,   108,   171,   172,   171,   182,   132,   158,
      48,   174,    15,    37,   160,    51,    68,    37,   175,   188,
     159,   159,   160,   173,    48,   188,    15,    48,    51,    68,
     182,   124,   124,   124,   125,   136,    51,    51,    53,    68,
     131,   152,   153,   155,    51,   182,    50,   166,   174,    51,
     182,   174,   166,   185,   185,    55,   188,   182,   188,   160,
     182,   159,    55,   171,   171,    50,   171,    37,    48,    70,
     162,   164,   165,   170,   175,   160,   182,    15,    20,    21,
      22,   123,   124,   161,   160,    37,   182,   150,   140,    21,
     101,   139,   144,    21,    48,    51,    68,    21,    15,    18,
      70,   131,   132,   167,   168,   169,   174,   174,    53,   174,
      51,    51,    55,   160,   131,   162,   165,   170,   175,    48,
     175,    37,   188,   159,   159,   160,   182,   188,   182,   172,
     182,    50,   182,   188,   155,    50,   171,   168,   132,   168,
      15,   174,    51,    68,    37,   166,   174,    51,   175,   159,
     159,   159,   162,   165,   170,   159,    37,   123,   123,   182,
      15,   154,   152,   168,   171,    37,   169,   174,   171,   159,
      51,   182,    51
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   113,   114,   114,   115,   115,   115,   116,   116,   116,
     116,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   122,   122,   123,   123,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   131,   132,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     139,   139,   140,   140,   140,   141,   142,   142,   143,   143,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   160,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   163,
     163,   164,   164,   165,   165,   165,   165,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   177,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   179,   180,   180,   181,   181,   181,   181,   181,   181,
     181,   182,   182,   182,   182,   182,   183,   183,   184,   184,
     184,   185,   185,   186,   186,   186,   186,   187,   187,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     1,     2,     1,     3,     1,     2,     1,
       3,     0,     1,     2,     1,     2,     2,     2,     1,     2,
       3,     2,     3,     5,     5,     3,     4,     3,     2,     2,
       2,     1,     1,     1,     3,     2,     2,     4,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     1,     2,     1,     1,     5,
       0,     4,     1,     3,     3,     4,     0,     1,     1,     3,
       1,     5,     8,     3,     6,     1,     3,     0,     1,     1,
       3,     2,     1,     2,     2,     0,     1,     1,     3,     0,
       2,     4,     3,     0,     1,     1,     3,     0,     1,     0,
       2,     0,     1,     2,     3,     5,     4,     2,     4,     3,
       2,     5,     5,     6,     5,     4,     4,     5,     3,     2,
       3,     3,     2,     2,     5,     1,     1,     2,     3,     1,
       2,     0,     1,     2,     3,     1,     2,     3,     1,     3,
       1,     2,     2,     3,     2,     3,     2,     3,     1,     2,
       2,     3,     3,     3,     6,     2,     2,     1,     1,     2,
       1,     1,     3,     2,     2,     3,     2,     4,     5,     1,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     4,     3,     4,     2,     2,     2,     2,
       2,     5,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     5,     4,     3,     6,     4,     3,     6,
       4,     1,     1,     1,     1,     1,     1,     4,     5,     7,
       7,     0,     1,     1,     3,     3,     5,     2,     1,     1,
       1,     1,     1,     3,     2,     1,     4,     3,     3
  };


#if ANNIUM_LANGDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "COMMENT_BEGIN",
  "COMMENT_END", "STRING", "IDENTIFIER", "CONTEXT_IDENTIFIER",
  "RESERVED_IDENTIFIER", "INTEGER_INDEX", "INTEGER", "DECIMAL",
  "DECIMAL_S", "OPERATOR_TERM", "CT_IDENTIFIER", "\"`=`\"",
  "\"APOSTROPHE\"", "\"`@`\"", "\"`_`\"", "\"`->*`\"", "\"`->`\"",
  "\"`=>`\"", "\"`~>`\"", "\"`.*`\"", "\"`++`\"", "\"`--`\"", "\"`<<`\"",
  "\"`>>`\"", "\"`==`\"", "\"`!=`\"", "\"`<`\"", "\"`<=`\"", "\"`>`\"",
  "\"`>=`\"", "\"`&&`\"", "\"`||`\"", "\"`..`\"", "\"`...`\"", "\"`+=`\"",
  "\"`-=`\"", "\"`*=`\"", "\"`/=`\"", "\"`%=`\"", "\"`<<=`\"", "\"`>>=`\"",
  "\"`&=`\"", "\"`|=`\"", "\"`^=`\"", "\"`:`\"", "\"`::`\"", "\"`(`\"",
  "\"`)`\"", "\"`{`\"", "\"`}`\"", "\"`[`\"", "\"`]`\"", "\"`;`\"",
  "\"`.`\"", "\"`+`\"", "\"`-`\"", "\"`*`\"", "\"`/`\"", "\"`%`\"",
  "\"`&`\"", "\"`|`\"", "\"`!`\"", "\"`~`\"", "\"`^`\"", "\",\"",
  "\"`$`\"", "\"`?`\"", "\"`#`\"", "LET", "VAR", "\"`as`\"", "EXTERN",
  "\"`new`\"", "\"`while`\"", "\"`for`\"", "\"`in`\"", "\"`if`\"",
  "\"`else`\"", "\"`continue`\"", "\"`break`\"", "\"`return`\"",
  "\"`yield`\"", "AUTO", "USING", "THROW", "SIZEOF", "LOWEST", "DEREF",
  "PREFIXMINUS", "INCLUDE", "INLINE", "VIABLE", "\"`fn`\"", "\"`typefn`\"",
  "ENUM", "STRUCT", "EXTENDS", "REQUIRES", "\"weak modifier\"",
  "\"typename modifier\"", "\"constexpr modifier\"",
  "\"consteval modifier\"", "\"guarded consteval modifier\"",
  "\"runctime modifier\"", "\"reference modifier\"", "\"nil\"", "\"true\"",
  "\"false\"", "PROBE", "$accept", "begin", "statement_any",
  "finished-statement-any", "statement", "let-decl", "let-decl-start",
  "let-decl-start-with-opt-type", "infunction-statement-any",
  "finished-infunction-statement-any", "function-body",
  "braced-statements", "finished-statement", "if-else-tail",
  "infunction-statement-set", "expression-statement", "generic-statement",
  "infunction-statement", "identifier", "internal-identifier", "qname",
  "fn-kind", "fn-kind-set", "fn-prefix-decl", "fn-name", "fn-start-decl",
  "fn-requirement-opt", "fn-decl", "enum-decl", "case-list-opt",
  "case-list", "case-decl", "struct-decl", "using-decl", "expression-list",
  "argument-list-opt", "argument-list", "argument", "argument-name",
  "field-list-opt", "field-list", "field-default-value-opt", "field",
  "parameter-list-opt", "parameter-list", "internal-identifier-opt",
  "parameter-default-value-opt", "ellipsis-opt-assign-value-opt",
  "parameter-decl", "constraint-expression-specified-mod",
  "constraint-expression-specified", "constraint-expression-mod",
  "constraint-expression", "subpatterns", "pattern-list",
  "pattern-field-sfx", "pattern-field", "pattern-mod", "pattern-sfx",
  "pattern", "concept-expression", "concept-expression-list-opt",
  "concept-expression-list", "reference-expression",
  "any-reference-expression", "syntax-expression-base",
  "grouped-expression", "new-expression", "call-expression",
  "syntax-expression", "lambda-start-decl", "lambda-expression",
  "pack-expression-opt", "pack-expression", "compound-expression",
  "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   356,   356,   357,   361,   363,   365,   382,   384,   385,
     387,   392,   394,   403,   405,   410,   411,   416,   418,   423,
     424,   429,   431,   433,   438,   440,   441,   443,   449,   452,
     463,   468,   470,   472,   474,   476,   478,   480,   490,   495,
     497,   502,   503,   507,   509,   517,   519,   521,   528,   530,
     534,   535,   537,   539,   541,   543,   548,   556,   571,   573,
     575,   581,   582,   586,   587,   591,   593,   598,   600,   605,
     623,   625,   637,   638,   640,   647,   652,   653,   657,   659,
     664,   670,   672,   695,   701,   718,   720,   726,   727,   731,
     733,   738,   740,   745,   747,   753,   754,   758,   760,   765,
     766,   770,   772,   779,   780,   784,   786,   791,   792,   796,
     797,   801,   802,   803,   804,   809,   813,   819,   821,   828,
     834,   840,   842,   844,   846,   849,   851,   856,   858,   860,
     868,   873,   878,   883,   888,   895,   896,   900,   902,   906,
     908,   913,   918,   922,   924,   928,   930,   940,   945,   947,
     953,   955,   958,   960,   964,   967,   973,   976,   989,   992,
     997,   998,   999,  1000,  1005,  1007,  1008,  1009,  1013,  1014,
    1015,  1019,  1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,
    1040,  1045,  1047,  1051,  1053,  1059,  1061,  1066,  1068,  1070,
    1075,  1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,
    1094,  1096,  1102,  1113,  1115,  1117,  1119,  1121,  1128,  1135,
    1137,  1151,  1153,  1155,  1158,  1160,  1164,  1166,  1170,  1172,
    1174,  1176,  1178,  1180,  1182,  1185,  1189,  1192,  1195,  1197,
    1209,  1229,  1242,  1246,  1253,  1255,  1257,  1262,  1264,  1266,
    1271,  1276,  1277,  1278,  1279,  1280,  1285,  1287,  1292,  1299,
    1307,  1318,  1320,  1325,  1327,  1333,  1338,  1346,  1348,  1388,
    1390,  1392,  1394,  1395,  1397,  1399,  1400,  1402,  1404
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // ANNIUM_LANGDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112
    };
    // Last valid token kind.
    const int code_max = 367;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 6083 "annium.tab.cpp"

#line 1599 "annium.y"

