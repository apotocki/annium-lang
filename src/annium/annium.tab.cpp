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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
#line 339 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 339 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 339 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 339 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 339 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 339 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 339 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 339 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 339 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 339 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 339 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 339 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 339 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 339 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 339 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 339 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 339 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 339 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 339 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 339 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 339 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 339 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 339 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 339 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 339 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 339 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 339 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 339 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 339 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 339 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 339 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 339 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 339 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 339 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 339 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 339 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 339 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 339 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 339 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 339 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 339 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 339 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 339 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 339 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 339 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 339 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 339 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 339 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
#line 339 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 339 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl: // let-decl
#line 339 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start: // let-decl-start
#line 339 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 339 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
#line 339 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
#line 339 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_function_body: // function-body
#line 339 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_braced_statements: // braced-statements
#line 339 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_finished_statement: // finished-statement
#line 339 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_if_else_tail: // if-else-tail
#line 339 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
#line 339 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_expression_statement: // expression-statement
#line 339 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_generic_statement: // generic-statement
#line 339 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_infunction_statement: // infunction-statement
#line 339 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 339 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
#line 339 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 339 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
#line 339 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
#line 339 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
#line 339 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_name: // fn-name
#line 339 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
#line 339 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
#line 339 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_decl: // fn-decl
#line 339 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
#line 339 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
#line 339 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list: // case-list
#line 339 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_decl: // case-decl
#line 339 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
#line 339 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_using_decl: // using-decl
#line 339 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_expression_list: // expression-list
#line 339 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
#line 339 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list: // argument-list
#line 339 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 339 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_argument_name: // argument-name
#line 339 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
#line 339 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list: // field-list
#line 339 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
#line 339 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 339 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
#line 339 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list: // parameter-list
#line 339 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
#line 339 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
#line 339 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
#line 339 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 339 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
#line 339 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
#line 339 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression: // constraint-expression
#line 339 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 339 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_list: // pattern-list
#line 339 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
#line 339 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_field: // pattern-field
#line 339 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
#line 339 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
#line 339 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 339 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_concept_expression: // concept-expression
#line 339 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
#line 339 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
#line 339 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
#line 339 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
#line 339 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
#line 339 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_grouped_expression: // grouped-expression
#line 339 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_new_expression: // new-expression
#line 339 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_call_expression: // call-expression
#line 339 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_syntax_expression: // syntax-expression
#line 339 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
#line 339 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_lambda_expression: // lambda-expression
#line 339 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
#line 339 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_pack_expression: // pack-expression
#line 339 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_compound_expression: // compound-expression
#line 339 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_type_expr: // type-expr
#line 339 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
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
      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_185_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_157_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
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
      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
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

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_164_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
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

      case symbol_kind::S_172_concept_expression: // concept-expression
      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_178_grouped_expression: // grouped-expression
      case symbol_kind::S_179_new_expression: // new-expression
      case symbol_kind::S_180_call_expression: // call-expression
      case symbol_kind::S_181_syntax_expression: // syntax-expression
      case symbol_kind::S_183_lambda_expression: // lambda-expression
      case symbol_kind::S_186_compound_expression: // compound-expression
      case symbol_kind::S_187_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_147_expression_list: // expression-list
      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_168_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_166_pattern_list: // pattern-list
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
#line 344 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3134 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 345 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3140 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 350 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3146 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 352 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3152 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 354 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3158 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 371 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3164 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 372 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3170 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 374 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3176 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 376 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3182 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 381 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3188 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 383 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3201 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 392 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3207 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 394 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3213 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 398 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3219 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 400 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3225 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 405 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3231 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 407 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3237 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 411 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3243 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 413 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3249 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 418 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3255 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 420 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3261 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 422 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3267 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 427 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3273 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 428 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3279 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 430 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3285 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 432 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3291 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 437 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3297 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 441 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3303 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 452 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3309 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 457 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3315 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 459 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3321 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 461 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3327 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 463 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3333 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 465 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3339 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 467 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3345 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 469 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3355 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 479 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3361 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 484 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3367 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 486 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3373 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 490 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3379 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 491 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3385 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 496 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3391 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 498 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3400 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 506 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3406 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 508 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3412 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 510 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3423 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 517 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3429 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 518 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3435 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 522 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3441 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 524 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3447 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 526 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3453 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 528 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3459 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 530 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3465 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 532 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3471 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 537 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3477 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 545 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3483 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 560 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3489 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 562 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3495 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 564 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3501 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 569 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3507 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 570 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3513 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 574 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3519 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 575 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3525 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 580 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3531 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 582 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3537 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 587 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3543 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 589 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3549 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 594 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3555 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 611 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3561 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 614 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3567 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 625 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3573 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 627 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3579 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 629 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3585 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 636 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3591 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 640 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3597 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 641 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3603 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 646 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3609 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 648 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3615 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 653 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3621 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 659 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3627 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 661 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3633 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 684 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3643 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 690 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3654 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 707 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3660 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 709 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3666 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 714 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3672 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 715 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3678 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 720 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3684 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 722 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3690 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 727 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3696 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 729 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3702 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 734 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3708 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 736 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3714 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 741 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3720 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 742 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3726 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 747 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3732 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 749 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3738 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 753 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3744 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 754 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3750 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 759 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3756 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 761 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3762 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 767 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3768 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 768 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3774 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 773 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3780 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 775 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3786 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 779 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3792 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 780 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3798 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 784 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3804 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 785 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3810 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 791 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3816 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 795 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3822 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 797 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3828 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 801 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3834 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 804 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3840 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: qname parameter-default-value-opt
#line 807 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3849 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: qname "`...`" parameter-default-value-opt
#line 812 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3859 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 820 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3865 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 822 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3871 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 824 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3877 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 826 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3883 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`=>`" syntax-expression
#line 829 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annotated_identifier > ()), std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3889 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: internal-identifier "`=>`" syntax-expression
#line 831 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3895 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 834 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3901 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" concept-expression-list parameter-default-value-opt
#line 836 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };   }
#line 3907 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 838 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3913 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 840 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3919 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: pattern-mod parameter-default-value-opt
#line 842 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3925 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 850 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3931 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: "`_`" concept-expression-list-opt parameter-default-value-opt
#line 852 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3937 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: concept-expression-list parameter-default-value-opt
#line 854 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3943 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 856 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3949 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`...`" parameter-default-value-opt
#line 858 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3955 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 863 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3961 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified-mod: "constexpr modifier"
#line 869 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 3967 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified-mod: "runctime modifier"
#line 870 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3973 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 875 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3979 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 877 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3985 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod
#line 881 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3991 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 883 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3997 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-mod: %empty
#line 888 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4006 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-mod: constraint-expression-specified-mod
#line 892 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4012 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod type-expr
#line 897 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4018 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 899 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4024 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod
#line 903 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4030 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod "`...`"
#line 905 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4036 "annium.tab.cpp"
    break;

  case 147: // subpatterns: "`(`" pattern-list "`)`"
#line 915 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4042 "annium.tab.cpp"
    break;

  case 148: // pattern-list: pattern-field
#line 920 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4048 "annium.tab.cpp"
    break;

  case 149: // pattern-list: pattern-list "," pattern-field
#line 922 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4054 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: concept-expression-list-opt
#line 928 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4060 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 930 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4066 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 933 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4072 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 935 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4078 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: "`=`" pattern-sfx
#line 939 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4084 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 942 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4090 "annium.tab.cpp"
    break;

  case 156: // pattern-field: identifier pattern-field-sfx
#line 948 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4096 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 951 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4102 "annium.tab.cpp"
    break;

  case 158: // pattern-field: pattern-field-sfx
#line 964 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4108 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`_`" pattern-field-sfx
#line 967 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4114 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" pattern-sfx
#line 971 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 4120 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 972 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4126 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 973 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4132 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 974 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4138 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "typename modifier"
#line 975 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4144 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "`~`" "consteval modifier" syntax-expression
#line 976 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4150 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "typename modifier" pattern-sfx
#line 977 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4156 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "typename modifier"
#line 978 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4162 "annium.tab.cpp"
    break;

  case 168: // pattern-sfx: pattern
#line 982 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4168 "annium.tab.cpp"
    break;

  case 169: // pattern-sfx: pattern "`...`"
#line 983 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4174 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: "`...`"
#line 984 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4180 "annium.tab.cpp"
    break;

  case 171: // pattern: qname
#line 989 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4186 "annium.tab.cpp"
    break;

  case 172: // pattern: qname subpatterns concept-expression-list-opt
#line 991 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4192 "annium.tab.cpp"
    break;

  case 173: // pattern: internal-identifier concept-expression-list-opt
#line 993 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4198 "annium.tab.cpp"
    break;

  case 174: // pattern: "`_`" concept-expression-list-opt
#line 995 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4204 "annium.tab.cpp"
    break;

  case 175: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 997 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4210 "annium.tab.cpp"
    break;

  case 176: // pattern: "`(`" "`)`"
#line 999 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4216 "annium.tab.cpp"
    break;

  case 177: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1001 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4222 "annium.tab.cpp"
    break;

  case 178: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1003 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4228 "annium.tab.cpp"
    break;

  case 179: // pattern: concept-expression-list
#line 1005 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4234 "annium.tab.cpp"
    break;

  case 180: // concept-expression: "`@`" qname
#line 1010 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4240 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list-opt: %empty
#line 1015 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4246 "annium.tab.cpp"
    break;

  case 182: // concept-expression-list-opt: concept-expression-list
#line 1016 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4252 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list: concept-expression
#line 1021 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4258 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list: concept-expression-list concept-expression
#line 1023 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4264 "annium.tab.cpp"
    break;

  case 185: // reference-expression: CONTEXT_IDENTIFIER
#line 1029 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4270 "annium.tab.cpp"
    break;

  case 186: // reference-expression: qname
#line 1031 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4276 "annium.tab.cpp"
    break;

  case 187: // any-reference-expression: RESERVED_IDENTIFIER
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4282 "annium.tab.cpp"
    break;

  case 188: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1038 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4288 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: qname
#line 1040 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4294 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "nil"
#line 1045 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4300 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: "true"
#line 1047 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4306 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "false"
#line 1049 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4312 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: INTEGER
#line 1051 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4318 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: DECIMAL
#line 1053 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4324 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: DECIMAL_S
#line 1055 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4330 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: INTEGER_INDEX
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4336 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: STRING
#line 1059 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4342 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: CT_IDENTIFIER
#line 1061 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4348 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: any-reference-expression
#line 1062 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4354 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`(`" "`)`"
#line 1064 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4360 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1066 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4369 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1072 "annium.y"
        { 
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4381 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4387 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`[[`" expression-list "`]]`"
#line 1082 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } }; }
#line 4393 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1084 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4399 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: PROBE braced-statements
#line 1086 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4405 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`.`" identifier
#line 1088 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4411 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1095 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4421 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`-`" syntax-expression
#line 1102 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4427 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1104 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4433 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`!`" syntax-expression
#line 1106 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4439 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "`*`" syntax-expression
#line 1108 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4445 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1111 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4451 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1113 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4457 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1117 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4463 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1119 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4469 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1123 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4475 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1125 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4481 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1127 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4487 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1129 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4493 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1131 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4499 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1133 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4505 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1135 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4511 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1138 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4517 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1142 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4523 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1145 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4529 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1148 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4535 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1150 "annium.y"
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
#line 4550 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1162 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4556 "annium.tab.cpp"
    break;

  case 230: // grouped-expression: "`(`" pack-expression "`)`"
#line 1182 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4569 "annium.tab.cpp"
    break;

  case 231: // new-expression: "`new`" qname
#line 1195 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4575 "annium.tab.cpp"
    break;

  case 232: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1199 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4581 "annium.tab.cpp"
    break;

  case 233: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1206 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4587 "annium.tab.cpp"
    break;

  case 234: // call-expression: any-reference-expression "`.`" identifier
#line 1208 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4593 "annium.tab.cpp"
    break;

  case 235: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1210 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4602 "annium.tab.cpp"
    break;

  case 236: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1215 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4608 "annium.tab.cpp"
    break;

  case 237: // call-expression: call-expression "`.`" identifier
#line 1217 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4614 "annium.tab.cpp"
    break;

  case 238: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1219 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4623 "annium.tab.cpp"
    break;

  case 239: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1224 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4629 "annium.tab.cpp"
    break;

  case 240: // syntax-expression: syntax-expression-base
#line 1228 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4635 "annium.tab.cpp"
    break;

  case 241: // syntax-expression: new-expression
#line 1229 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4641 "annium.tab.cpp"
    break;

  case 242: // syntax-expression: compound-expression
#line 1230 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4647 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: lambda-expression
#line 1231 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4653 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: grouped-expression
#line 1232 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4659 "annium.tab.cpp"
    break;

  case 245: // lambda-start-decl: fn-prefix-decl
#line 1238 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4665 "annium.tab.cpp"
    break;

  case 246: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1240 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4671 "annium.tab.cpp"
    break;

  case 247: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1245 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4682 "annium.tab.cpp"
    break;

  case 248: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1252 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4694 "annium.tab.cpp"
    break;

  case 249: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1260 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4706 "annium.tab.cpp"
    break;

  case 250: // pack-expression-opt: %empty
#line 1271 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4712 "annium.tab.cpp"
    break;

  case 251: // pack-expression-opt: pack-expression
#line 1273 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4718 "annium.tab.cpp"
    break;

  case 252: // pack-expression: syntax-expression
#line 1278 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4724 "annium.tab.cpp"
    break;

  case 253: // pack-expression: identifier "`:`" syntax-expression
#line 1280 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4734 "annium.tab.cpp"
    break;

  case 254: // pack-expression: pack-expression "," syntax-expression
#line 1286 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4743 "annium.tab.cpp"
    break;

  case 255: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1291 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4752 "annium.tab.cpp"
    break;

  case 256: // compound-expression: syntax-expression "`...`"
#line 1299 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4758 "annium.tab.cpp"
    break;

  case 257: // compound-expression: call-expression
#line 1300 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4764 "annium.tab.cpp"
    break;

  case 258: // type-expr: qname
#line 1341 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4770 "annium.tab.cpp"
    break;

  case 259: // type-expr: RESERVED_IDENTIFIER
#line 1343 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4776 "annium.tab.cpp"
    break;

  case 260: // type-expr: CONTEXT_IDENTIFIER
#line 1345 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4782 "annium.tab.cpp"
    break;

  case 261: // type-expr: call-expression
#line 1346 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4788 "annium.tab.cpp"
    break;

  case 262: // type-expr: "`[`" type-expr "`]`"
#line 1348 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4794 "annium.tab.cpp"
    break;

  case 263: // type-expr: "`(`" "`)`"
#line 1350 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4800 "annium.tab.cpp"
    break;

  case 264: // type-expr: grouped-expression
#line 1351 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4806 "annium.tab.cpp"
    break;

  case 265: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1353 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4812 "annium.tab.cpp"
    break;

  case 266: // type-expr: type-expr "`|`" type-expr
#line 1355 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4818 "annium.tab.cpp"
    break;

  case 267: // type-expr: type-expr "`->`" type-expr
#line 1357 "annium.y"
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
#line 4833 "annium.tab.cpp"
    break;


#line 4837 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -306;

  const short parser::yytable_ninf_ = -190;

  const short
  parser::yypact_[] =
  {
     884,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
      40,   992,  1013,  1128,    40,  1128,  1128,  1128,    -4,   -38,
      45,  1128,   232,  1128,    45,    52,  -306,  -306,  -306,    41,
      45,    45,  1128,  -306,  -306,  -306,    11,    99,    22,   560,
    -306,  -306,  -306,  -306,  -306,    62,  -306,   355,    19,     3,
    -306,    71,  -306,   212,   894,   109,  -306,   236,  -306,  1128,
    -306,   118,   119,  1557,    42,  -306,   776,   145,   -12,  1557,
     195,  -306,    27,    27,    27,    40,  -306,   178,   217,  -306,
      40,    41,   359,  1213,  -306,    62,   170,  1263,   233,  -306,
    -306,  -306,    62,   220,  -306,   225,  -306,   370,  -306,    27,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,    40,  -306,
    -306,  1128,   335,    33,  1128,    40,  1128,  1128,    40,  -306,
    1128,   442,  1128,  1128,  1128,  1128,  1128,  1128,  1128,  1128,
    1128,  -306,  1128,  1128,  1128,  1128,  1128,  1128,  1128,   442,
     379,  1312,  1128,  -306,  1128,  -306,  -306,  1128,  1128,   227,
     668,  -306,   238,  -306,  -306,  -306,  -306,  1128,  -306,  -306,
     442,  1128,   254,  -306,  1128,  1128,  -306,  1128,   226,  1128,
     379,   379,    40,   265,   379,  -306,   279,   270,   442,   546,
    1128,  -306,   294,   311,   316,   123,   327,  1557,   257,   276,
    1107,   442,   210,     3,    71,   212,   121,   485,   485,   485,
     485,   485,   485,   786,   678,   338,  1361,    15,    15,    18,
      18,  1634,  1596,   175,  -306,    45,   366,   391,   243,   483,
     492,  -306,  -306,    23,   315,   275,   364,   348,  -306,   458,
     391,   391,  -306,   280,  -306,  1557,   376,  1557,  1557,  1557,
    -306,  -306,  -306,  -306,  -306,  1557,   175,   270,   442,    68,
     375,   363,  -306,  1128,  1557,    11,  1263,   505,  -306,  1557,
     385,   388,  -306,   404,   398,  -306,    40,   419,  -306,   175,
      24,   422,  1128,   366,   413,  -306,   366,  1557,  -306,  1128,
    -306,  -306,  1128,  -306,   165,   442,  1128,   442,  -306,    62,
     391,   366,  1128,  -306,  -306,   754,   391,   391,  -306,   492,
     492,  1128,   492,  -306,   439,  -306,  -306,    34,  1128,   391,
       2,   391,   391,  -306,   382,   379,  -306,   280,   213,  -306,
    -306,  -306,  -306,  1128,   175,  -306,  -306,  -306,  1128,  1557,
    -306,  -306,  -306,  -306,    41,   457,   377,  -306,    40,    83,
     430,   416,  -306,   462,   228,   366,  -306,  -306,  1410,  -306,
     366,   437,   451,  -306,   121,  1459,   121,  -306,  1557,  -306,
     256,  -306,  -306,  -306,  -306,  1557,  -306,  -306,  1128,     2,
     463,  1557,  -306,   366,   391,   391,   280,  -306,  -306,   442,
    1128,   546,  -306,  -306,  -306,  -306,  -306,  1557,  -306,    11,
    1128,   464,  -306,  -306,  1128,   442,  -306,    40,   467,   492,
     324,   506,   324,   372,   126,  -306,  -306,   486,  -306,    24,
    -306,  -306,  -306,  -306,  -306,  1557,   366,   391,   391,   280,
     243,   280,  -306,  -306,  -306,   151,  1557,   149,  1557,  1128,
    1557,    30,  -306,    40,  -306,  -306,   324,  -306,   492,   488,
    -306,   228,  -306,   366,  -306,   280,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  1508,  1128,  -306,   475,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  1557,  -306
  };

  const short
  parser::yydefact_[] =
  {
       4,   197,    56,   188,   187,   196,   193,   194,   195,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    65,     0,
       0,     0,     0,   190,   191,   192,     0,     0,     0,     0,
       5,     7,    49,    13,    59,   189,    63,     0,   245,   199,
     240,   244,   241,   257,     0,     0,   243,   242,    58,     0,
     200,    59,   245,   252,     0,   242,    21,     0,     0,    85,
       0,   207,   209,   212,   211,     0,    45,    19,    15,    17,
       0,     0,   231,     0,   185,   186,     0,     0,     0,    48,
      31,    68,    67,     0,    46,     0,    38,     0,    14,   210,
     206,     1,     2,    10,     3,     8,     6,     9,     0,    66,
      64,   250,    72,     0,   250,     0,   250,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   230,     0,    52,    51,    53,     0,    41,
      42,    24,     0,    50,    22,   203,   202,     0,   204,    18,
       0,     0,     0,    12,    87,     0,    32,     0,    35,     0,
     103,   103,    76,     0,   103,    60,     0,   251,     0,     0,
       0,    37,     0,   234,     0,     0,   237,    44,   260,   259,
       0,     0,   258,     0,   264,   261,   228,   217,   218,   219,
     220,   221,   222,   226,   227,   223,     0,   215,   216,   213,
     214,   224,   225,   229,    57,     0,   181,   109,   141,     0,
     167,   135,   136,    59,   181,   109,     0,   104,   105,   139,
     109,   109,   183,   109,   201,   253,    59,   254,    54,    55,
      27,    25,    26,    23,    30,    86,    20,    16,     0,    59,
       0,    88,    89,     0,    92,     0,     0,     0,    36,    83,
       0,     0,    80,     0,    77,    78,    95,     0,   246,    73,
     181,     0,     0,   181,   171,    74,   179,    47,   233,   250,
     239,   236,   250,   263,     0,     0,     0,     0,   205,   180,
     109,   182,     0,   133,   142,   145,   109,   109,   170,   164,
       0,     0,     0,   160,   168,   166,   108,     0,     0,   109,
     141,   109,   109,   116,     0,     0,   140,   109,   137,   114,
     128,   131,   184,     0,    11,    93,    94,   232,     0,    91,
      33,    34,    39,    40,     0,     0,    70,    75,     0,     0,
       0,    96,    97,     0,   181,   181,   174,   176,     0,   173,
     181,     0,     0,   262,   267,     0,   266,   130,   110,   146,
     143,   113,   127,   163,   161,   165,   162,   169,     0,   141,
       0,   123,   132,   142,   109,   109,   109,   129,   117,     0,
       0,     0,   247,    28,   106,   115,   138,   255,    90,     0,
       0,     0,    69,    79,     0,     0,    81,     0,     0,     0,
     181,     0,   181,   181,     0,   158,   148,   150,   175,   181,
     172,   235,   238,   265,   144,   122,   142,   109,   109,   109,
     141,   109,   112,   124,   125,     0,    29,     0,    84,     0,
     102,    99,    98,    95,   154,   159,   181,   156,     0,   152,
     147,   181,   151,   181,   177,   109,   111,   118,   119,   134,
     121,   126,   248,   249,     0,     0,   101,     0,   157,   155,
     153,   149,   178,   120,    71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -306,  -306,  -306,  -306,   489,  -306,  -306,  -306,  -306,  -306,
     -32,    -8,   -33,  -306,  -306,   362,   -52,   380,    38,   -31,
     159,   487,  -306,     1,  -306,   507,  -306,   -78,  -306,  -306,
    -306,   199,  -306,  -306,   530,  -306,  -306,   221,  -306,   117,
    -306,  -306,   154,   271,  -306,  -306,   207,   240,  -209,  -306,
    -306,  -305,  -264,  -306,  -158,   115,  -207,  -213,  -159,  -215,
    -182,    44,  -306,    77,  -306,   136,  -306,   182,     0,  -306,
    -306,   -85,    -3,    26,   127
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    76,    77,    78,   149,   150,
     382,   383,    41,   258,   152,    42,    43,   154,    44,   273,
      45,    46,    47,    62,    93,   112,   392,   113,    96,   263,
     264,   265,    98,    89,    68,   250,   251,   252,   253,   340,
     341,   456,   342,   226,   227,   307,   293,   228,   229,   230,
     295,   296,   345,   404,   405,   406,   231,   303,   304,   232,
     407,   291,    86,    49,    50,    51,    52,    53,    63,    55,
      56,   176,   177,    65,   196
  };

  const short
  parser::yytable_[] =
  {
      54,    48,     2,   163,    67,   374,   107,   305,    64,   294,
     350,   297,    69,    69,   153,    72,    73,    74,   322,   215,
     275,    83,   102,    87,   119,     2,    57,   119,   100,   182,
     214,   184,    99,   151,   290,   121,   119,    80,   121,    54,
      48,   215,   311,   156,  -107,   455,     2,     2,    58,    61,
     285,     2,    71,   114,   180,   368,    79,    90,   157,   141,
      81,   322,   115,    66,   417,    57,    54,    48,    10,   132,
     219,  -107,   132,   111,   344,   166,   322,   135,   136,   168,
     103,   132,   369,   325,   286,    66,   363,   364,   346,   366,
      10,   349,    57,   143,    10,  -107,   287,    91,   153,   101,
      75,   373,   322,   375,   394,   181,   370,   220,   221,   224,
     222,   108,   144,   159,   185,   449,   326,   242,   162,    91,
     187,   116,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   395,   206,   207,   208,   209,   210,   211,   212,   224,
     224,   285,   235,   224,   237,   443,   175,   238,   239,    61,
      54,    48,    61,   183,    61,    61,   186,   245,   247,   140,
     416,   322,   418,   408,   254,    54,   142,   256,   410,   259,
     380,   285,   380,   111,   281,   286,    57,   440,   223,    82,
     277,    85,   236,    88,   233,   285,   434,    64,    92,    95,
      97,    57,   306,   144,   351,   285,   441,   352,   193,    61,
     155,    66,   249,    66,   322,   286,   322,    92,   223,   223,
     262,   294,   223,   450,   233,   233,   193,   287,   233,   286,
     353,   439,   427,   276,   333,   459,   160,   444,    61,   286,
     322,   287,   161,   285,     2,   214,   -43,   193,     2,    84,
      92,   287,   435,   399,   437,   215,   400,   330,   331,   332,
     386,   167,   158,   329,   169,   193,   389,   194,   334,   108,
    -189,   462,   117,   276,   276,   157,   213,   286,   193,  -189,
     171,   118,   348,   317,   108,   194,   285,   172,   458,   287,
     192,    10,   108,   170,   224,   240,   355,   246,   -43,   -43,
     292,   244,   358,   414,   -43,   292,   194,   215,   192,   225,
     401,   365,   248,   195,   339,   269,   193,  -188,   371,   257,
     286,   219,   312,   403,   194,   266,  -188,    61,   284,   192,
      61,   195,   287,   387,   108,   193,  -187,   194,   254,   225,
     225,   214,   215,   225,   268,  -187,   308,   192,   274,   399,
     144,   215,   195,   276,   276,   278,   276,   119,   220,   221,
     192,   222,   309,   223,   376,   178,   318,   179,   121,   233,
     195,   279,   193,   310,   193,   194,   249,   280,   415,   403,
     436,   403,   193,   195,   289,   324,   262,   282,   274,   274,
     426,   181,   402,   215,   194,     2,   214,   438,   192,   215,
     428,   173,   132,   452,   430,   453,   215,   216,   133,   134,
     135,   136,   379,   380,   381,   403,   292,   192,   108,   164,
     403,   195,   354,   419,   356,   314,   217,   421,   315,   108,
     174,   194,   360,   194,   323,   276,   327,   218,    10,   454,
     195,   194,   313,   328,    66,   339,   335,   319,   320,   336,
     321,   260,   261,   276,   192,   267,   192,   219,     2,   188,
     189,    26,    27,   109,   192,   465,   193,   337,   274,   274,
     445,   274,   108,   344,     2,   188,   189,   195,   338,   195,
     343,   339,   193,   347,   225,   215,   367,   195,   390,   402,
     391,   396,   276,   398,   220,   221,   397,   222,   411,     2,
     214,    10,   190,    92,   119,   316,   191,   357,     2,   214,
     215,   270,   412,   361,   362,   121,   425,    10,   190,   215,
     270,   420,   191,   214,   429,   194,   372,   433,   377,   378,
     298,   130,   431,   442,   385,   460,   466,   255,   106,   298,
     243,   194,    10,   271,   110,   272,    94,   393,   192,   132,
     274,    10,   271,    70,   272,   133,   134,   135,   136,   388,
     457,   432,     2,   214,   192,   384,   461,    66,   274,     0,
     104,   195,     0,   215,   270,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,   195,     0,     0,
       0,   422,   423,   424,    21,    22,     0,    23,   299,   300,
     301,   302,     0,     0,     0,    10,   271,   274,   272,     0,
      25,    26,    27,    28,     0,    30,     0,     0,     0,    10,
      11,     0,     0,     0,    12,     0,    13,     0,   105,    14,
       0,    15,    16,     0,   446,   447,   448,    17,   451,     0,
       0,     0,     0,     0,    18,     0,     0,    19,    20,    21,
      22,     0,    23,     0,     0,     0,     0,     0,     0,    24,
       0,     0,   463,     0,     0,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,    32,     0,    33,
      34,    35,    36,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,   128,     0,   130,     0,     0,    10,    11,     0,
       0,     0,    12,     0,    13,     0,   241,    14,     0,    15,
      16,     0,   132,     0,     0,    17,     0,     0,   133,   134,
     135,   136,    18,   137,   138,     0,    20,    21,    22,     0,
      23,     0,   145,   146,   147,   148,     0,    24,     0,     0,
       2,   188,   189,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,    32,     0,    33,    34,    35,
      36,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   359,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,    10,   190,     0,   121,     0,   191,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
       0,     0,   130,     0,     0,    10,    11,     0,     0,     0,
      12,     0,    13,     0,     0,    14,     0,    15,    16,     0,
     132,     0,     0,    17,     0,     0,   133,   134,   135,   136,
      18,   137,   138,     0,    20,    21,    22,     0,    23,     0,
     145,   146,   147,   148,     0,    24,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,    32,     0,    33,    34,    35,    36,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,    10,    11,     0,     0,     0,    12,     0,
      13,     0,     0,    14,     0,    15,    16,     0,   132,     0,
       0,    17,     0,     0,   133,   134,   135,   136,    18,   137,
     138,    19,    20,    21,    22,     0,    23,     0,     0,     0,
     139,     0,     0,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,    32,     0,    33,    34,    35,    36,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    10,    11,    60,     0,     0,    12,     0,    13,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
       0,     0,    10,    11,     0,    66,     0,    12,     0,    13,
      20,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    20,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    33,    34,    35,    36,     0,     0,     0,     0,    26,
      27,    28,     1,     2,     3,     4,     5,     6,     7,     8,
      32,     9,    33,    34,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,   283,     0,
       0,    12,     0,    13,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,     0,     0,    10,    11,     0,
       0,     0,    12,     0,    13,    20,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    20,     0,     0,     0,
       0,     0,     0,     0,    32,     0,    33,    34,    35,    36,
       0,     0,   119,     0,    26,    27,    28,     0,     0,     0,
       0,     0,     0,   121,     0,    32,     0,    33,    34,    35,
      36,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,   132,     0,     0,
       0,   165,   119,   133,   134,   135,   136,     0,   137,   138,
       0,     0,     0,   121,     0,     0,     0,     0,     0,   139,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,   132,     0,     0,
       0,   119,     0,   133,   134,   135,   136,     0,   137,   138,
       0,     0,   121,     0,     0,     0,     0,     0,     0,   139,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,   132,     0,     0,     0,
     119,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   288,     0,     0,   119,
       0,   133,   134,   135,   136,     0,   137,   138,     0,     0,
     121,     0,     0,     0,     0,     0,     0,   139,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   409,   132,     0,     0,     0,   119,     0,
     133,   134,   135,   136,     0,   137,   138,     0,     0,   121,
       0,     0,     0,     0,     0,     0,   139,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   413,     0,     0,   119,     0,   133,
     134,   135,   136,     0,   137,   138,     0,     0,   121,     0,
       0,     0,     0,     0,     0,   139,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,   132,     0,     0,     0,   119,     0,   133,   134,
     135,   136,     0,   137,   138,     0,     0,   121,     0,     0,
       0,     0,     0,     0,   139,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,     0,     0,     0,     0,
       0,   132,     0,     0,     0,     0,   121,   133,   134,   135,
     136,     0,   137,   138,   122,   123,   124,   125,   126,   127,
       0,     0,   130,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,   121,     0,   133,   134,   135,   136,
       0,   137,   122,   123,   124,   125,   126,   127,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,     0,     0,   133,   134,   135,   136
  };

  const short
  parser::yycheck_[] =
  {
       0,     0,     6,    81,    12,   310,    39,   220,    11,   218,
     274,   218,    12,    13,    66,    15,    16,    17,   233,    17,
     179,    21,     0,    23,     9,     6,     0,     9,    36,   114,
       7,   116,    32,    66,   216,    20,     9,    75,    20,    39,
      39,    17,   224,    55,    21,    15,     6,     6,    10,    11,
      20,     6,    14,    50,    21,    21,    18,     5,    70,    59,
      98,   276,    59,    52,   369,    39,    66,    66,    49,    54,
      68,    48,    54,    54,    50,    83,   291,    62,    63,    87,
      58,    54,    48,    15,    54,    52,   299,   300,   270,   302,
      49,   273,    66,    51,    49,    72,    66,    78,   150,     0,
     104,   310,   317,   310,    21,   113,    72,   105,   106,   140,
     108,    49,    70,    75,   117,   420,    48,   150,    80,    78,
     120,    50,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    48,   132,   133,   134,   135,   136,   137,   138,   170,
     171,    20,   142,   174,   144,   409,   108,   147,   148,   111,
     150,   150,   114,   115,   116,   117,   118,   157,   161,    50,
     369,   376,   369,   345,   164,   165,    48,   167,   350,   169,
      21,    20,    21,    54,    51,    54,   150,    51,   140,    20,
     180,    22,   144,    24,   140,    20,   399,   190,    29,    30,
      31,   165,   223,    70,   279,    20,    70,   282,   121,   161,
      55,    52,   164,    52,   419,    54,   421,    48,   170,   171,
     172,   420,   174,   420,   170,   171,   139,    66,   174,    54,
      55,   403,   381,   179,   257,   438,    48,   409,   190,    54,
     445,    66,    15,    20,     6,     7,     0,   160,     6,     7,
      81,    66,   400,    15,   402,    17,    18,   255,   256,   257,
      37,    81,    57,   253,    21,   178,   334,   121,   257,    49,
      50,   443,    50,   219,   220,    70,   139,    54,   191,    59,
      50,    59,   272,   229,    49,   139,    20,    52,   436,    66,
     121,    49,    49,    50,   315,    58,   286,   160,    52,    53,
      15,    53,   292,    37,    58,    15,   160,    17,   139,   140,
      72,   301,    48,   121,   266,   178,   229,    50,   308,    83,
      54,    68,    37,   344,   178,    50,    59,   279,   191,   160,
     282,   139,    66,   323,    49,   248,    50,   191,   328,   170,
     171,     7,    17,   174,    55,    59,    21,   178,   179,    15,
      70,    17,   160,   299,   300,    51,   302,     9,   105,   106,
     191,   108,    37,   315,   310,    20,   229,    22,    20,   315,
     178,    50,   285,    48,   287,   229,   328,    51,   368,   400,
     401,   402,   295,   191,   215,   248,   338,    50,   219,   220,
     380,   389,   344,    17,   248,     6,     7,    15,   229,    17,
     390,    21,    54,   425,   394,   427,    17,    18,    60,    61,
      62,    63,    20,    21,    22,   436,    15,   248,    49,    50,
     441,   229,   285,   369,   287,    51,    37,   373,    70,    49,
      50,   285,   295,   287,    48,   381,    51,    48,    49,   429,
     248,   295,   225,    70,    52,   397,    51,   230,   231,    51,
     233,   170,   171,   399,   285,   174,   287,    68,     6,     7,
       8,    96,    97,    98,   295,   455,   379,    53,   299,   300,
     416,   302,    49,    50,     6,     7,     8,   285,    70,   287,
      51,   433,   395,    51,   315,    17,    37,   295,    21,   441,
     103,    51,   438,    21,   105,   106,    70,   108,    51,     6,
       7,    49,    50,   334,     9,    37,    54,   290,     6,     7,
      17,    18,    51,   296,   297,    20,   379,    49,    50,    17,
      18,    48,    54,     7,    50,   379,   309,    50,   311,   312,
      37,    36,   395,    37,   317,    37,    51,   165,    39,    37,
     150,   395,    49,    50,    47,    52,    29,   338,   379,    54,
     381,    49,    50,    13,    52,    60,    61,    62,    63,   328,
     433,   397,     6,     7,   395,   315,   441,    52,   399,    -1,
       0,   379,    -1,    17,    18,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,   395,    -1,    -1,
      -1,   374,   375,   376,    79,    80,    -1,    82,   105,   106,
     107,   108,    -1,    -1,    -1,    49,    50,   438,    52,    -1,
      95,    96,    97,    98,    -1,   100,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      -1,    61,    62,    -1,   417,   418,   419,    67,   421,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,   445,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
     110,   111,   112,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    -1,    61,
      62,    -1,    54,    -1,    -1,    67,    -1,    -1,    60,    61,
      62,    63,    74,    65,    66,    -1,    78,    79,    80,    -1,
      82,    -1,    84,    85,    86,    87,    -1,    89,    -1,    -1,
       6,     7,     8,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,   110,   111,
     112,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    37,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    20,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    -1,    59,    -1,    61,    62,    -1,
      54,    -1,    -1,    67,    -1,    -1,    60,    61,    62,    63,
      74,    65,    66,    -1,    78,    79,    80,    -1,    82,    -1,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,   110,   111,   112,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    -1,    59,    -1,    61,    62,    -1,    54,    -1,
      -1,    67,    -1,    -1,    60,    61,    62,    63,    74,    65,
      66,    77,    78,    79,    80,    -1,    82,    -1,    -1,    -1,
      76,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,   107,    -1,   109,   110,   111,   112,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      -1,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    49,    50,    -1,    52,    -1,    54,    -1,    56,
      78,    -1,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    96,
      97,    98,     5,     6,     7,     8,     9,    10,    11,    12,
     107,    14,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    78,    -1,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,   110,   111,   112,
      -1,    -1,     9,    -1,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,   107,    -1,   109,   110,   111,
     112,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    -1,
      -1,    58,     9,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    -1,
      -1,     9,    -1,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    -1,
       9,    -1,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    76,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,     9,
      -1,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    76,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,     9,    -1,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,     9,    -1,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    -1,     9,    -1,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    20,    60,    61,    62,
      63,    -1,    65,    66,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    20,    -1,    60,    61,    62,    63,
      -1,    65,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      49,    50,    54,    56,    59,    61,    62,    67,    74,    77,
      78,    79,    80,    82,    89,    95,    96,    97,    98,    99,
     100,   101,   107,   109,   110,   111,   112,   114,   115,   116,
     117,   125,   128,   129,   131,   133,   134,   135,   136,   176,
     177,   178,   179,   180,   181,   182,   183,   186,   131,    48,
      51,   131,   136,   181,   185,   186,    52,   124,   147,   181,
     147,   131,   181,   181,   181,   104,   118,   119,   120,   131,
      75,    98,   133,   181,     7,   133,   175,   181,   133,   146,
       5,    78,   133,   137,   138,   133,   141,   133,   145,   181,
     124,     0,     0,    58,     0,    58,   117,   125,    49,    98,
     134,    54,   138,   140,    50,    59,    50,    50,    59,     9,
      15,    20,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    54,    60,    61,    62,    63,    65,    66,    76,
      50,   181,    48,    51,    70,    84,    85,    86,    87,   121,
     122,   125,   127,   129,   130,    55,    55,    70,    57,   131,
      48,    15,   131,   140,    50,    58,   124,    81,   124,    21,
      50,    50,    52,    21,    50,   131,   184,   185,    20,    22,
      21,   124,   184,   131,   184,   185,   131,   181,     7,     8,
      50,    54,   133,   176,   178,   180,   187,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   187,     7,    17,    18,    37,    48,    68,
     105,   106,   108,   131,   132,   133,   156,   157,   160,   161,
     162,   169,   172,   174,    51,   181,   131,   181,   181,   181,
      58,    58,   125,   130,    53,   181,   187,   185,    48,   131,
     148,   149,   150,   151,   181,   128,   181,    83,   126,   181,
     156,   156,   131,   142,   143,   144,    50,   156,    55,   187,
      18,    50,    52,   132,   133,   171,   174,   181,    51,    50,
      51,    51,    50,    51,   187,    20,    54,    66,    55,   133,
     173,   174,    15,   159,   161,   163,   164,   169,    37,   105,
     106,   107,   108,   170,   171,   170,   132,   158,    21,    37,
      48,   173,    37,   159,    51,    70,    37,   174,   187,   159,
     159,   159,   172,    48,   187,    15,    48,    51,    70,   181,
     124,   124,   124,   125,   136,    51,    51,    53,    70,   131,
     152,   153,   155,    51,    50,   165,   173,    51,   181,   173,
     165,   184,   184,    55,   187,   181,   187,   159,   181,    37,
     187,   159,   159,   170,   170,   181,   170,    37,    21,    48,
      72,   181,   159,   161,   164,   169,   174,   159,   159,    20,
      21,    22,   123,   124,   160,   159,    37,   181,   150,   140,
      21,   103,   139,   144,    21,    48,    51,    70,    21,    15,
      18,    72,   131,   132,   166,   167,   168,   173,   173,    53,
     173,    51,    51,    55,    37,   181,   161,   164,   169,   174,
      48,   174,   159,   159,   159,   187,   181,   171,   181,    50,
     181,   187,   155,    50,   170,   167,   132,   167,    15,   173,
      51,    70,    37,   165,   173,   174,   159,   159,   159,   164,
     169,   159,   123,   123,   181,    15,   154,   152,   167,   170,
      37,   168,   173,   159,    51,   181,    51
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
     159,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   162,
     162,   163,   163,   164,   164,   164,   164,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   176,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     178,   179,   179,   180,   180,   180,   180,   180,   180,   180,
     181,   181,   181,   181,   181,   182,   182,   183,   183,   183,
     184,   184,   185,   185,   185,   185,   186,   186,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187
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
       2,     5,     4,     3,     2,     3,     2,     3,     5,     5,
       6,     5,     4,     3,     4,     4,     5,     3,     2,     3,
       3,     2,     3,     2,     5,     1,     1,     2,     3,     1,
       2,     0,     1,     2,     3,     1,     2,     3,     1,     3,
       1,     2,     2,     3,     2,     3,     2,     3,     1,     2,
       2,     3,     3,     3,     2,     3,     2,     1,     1,     2,
       1,     1,     3,     2,     2,     3,     2,     4,     5,     1,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     3,     3,     4,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     5,     4,     3,     6,     4,     3,     6,     4,
       1,     1,     1,     1,     1,     1,     4,     5,     7,     7,
       0,     1,     1,     3,     3,     5,     2,     1,     1,     1,
       1,     1,     3,     2,     1,     4,     3,     3
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
  "\"`)`\"", "\"`{`\"", "\"`}`\"", "\"`[`\"", "\"`]`\"", "\"`[[`\"",
  "\"`]]`\"", "\"`;`\"", "\"`.`\"", "\"`+`\"", "\"`-`\"", "\"`*`\"",
  "\"`/`\"", "\"`%`\"", "\"`&`\"", "\"`|`\"", "\"`!`\"", "\"`~`\"",
  "\"`^`\"", "\",\"", "\"`$`\"", "\"`?`\"", "\"`#`\"", "LET", "VAR",
  "\"`as`\"", "EXTERN", "\"`new`\"", "\"`while`\"", "\"`for`\"",
  "\"`in`\"", "\"`if`\"", "\"`else`\"", "\"`continue`\"", "\"`break`\"",
  "\"`return`\"", "\"`yield`\"", "AUTO", "USING", "THROW", "SIZEOF",
  "LOWEST", "DEREF", "PREFIXMINUS", "INCLUDE", "INLINE", "VIABLE",
  "\"`fn`\"", "\"`typefn`\"", "ENUM", "STRUCT", "EXTENDS", "REQUIRES",
  "\"weak modifier\"", "\"typename modifier\"", "\"constexpr modifier\"",
  "\"consteval modifier\"", "\"runctime modifier\"", "\"nil\"", "\"true\"",
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
  "parameter-default-value-opt", "parameter-decl",
  "constraint-expression-specified-mod", "constraint-expression-specified",
  "constraint-expression-mod", "constraint-expression", "subpatterns",
  "pattern-list", "pattern-field-sfx", "pattern-field", "pattern-mod",
  "pattern-sfx", "pattern", "concept-expression",
  "concept-expression-list-opt", "concept-expression-list",
  "reference-expression", "any-reference-expression",
  "syntax-expression-base", "grouped-expression", "new-expression",
  "call-expression", "syntax-expression", "lambda-start-decl",
  "lambda-expression", "pack-expression-opt", "pack-expression",
  "compound-expression", "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   344,   344,   345,   349,   351,   353,   370,   372,   373,
     375,   380,   382,   391,   393,   398,   399,   404,   406,   411,
     412,   417,   419,   421,   426,   428,   429,   431,   437,   440,
     451,   456,   458,   460,   462,   464,   466,   468,   478,   483,
     485,   490,   491,   495,   497,   505,   507,   509,   516,   518,
     522,   523,   525,   527,   529,   531,   536,   544,   559,   561,
     563,   569,   570,   574,   575,   579,   581,   586,   588,   593,
     611,   613,   625,   626,   628,   635,   640,   641,   645,   647,
     652,   658,   660,   683,   689,   706,   708,   714,   715,   719,
     721,   726,   728,   733,   735,   741,   742,   746,   748,   753,
     754,   758,   760,   767,   768,   772,   774,   779,   780,   784,
     785,   790,   794,   796,   800,   803,   806,   811,   819,   821,
     823,   825,   828,   830,   833,   835,   837,   839,   841,   849,
     851,   853,   855,   857,   862,   869,   870,   874,   876,   880,
     882,   887,   892,   896,   898,   902,   904,   914,   919,   921,
     927,   929,   932,   934,   938,   941,   947,   950,   963,   966,
     971,   972,   973,   974,   975,   976,   977,   978,   982,   983,
     984,   988,   990,   992,   994,   996,   998,  1000,  1002,  1004,
    1009,  1014,  1016,  1020,  1022,  1028,  1030,  1035,  1037,  1039,
    1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,
    1063,  1065,  1071,  1079,  1081,  1083,  1085,  1087,  1094,  1101,
    1103,  1105,  1107,  1110,  1112,  1116,  1118,  1122,  1124,  1126,
    1128,  1130,  1132,  1134,  1137,  1141,  1144,  1147,  1149,  1161,
    1181,  1194,  1198,  1205,  1207,  1209,  1214,  1216,  1218,  1223,
    1228,  1229,  1230,  1231,  1232,  1237,  1239,  1244,  1251,  1259,
    1270,  1272,  1277,  1279,  1285,  1290,  1298,  1300,  1340,  1342,
    1344,  1346,  1347,  1349,  1351,  1352,  1354,  1356
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
#line 5964 "annium.tab.cpp"

#line 1551 "annium.y"

