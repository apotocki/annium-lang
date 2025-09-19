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
    ctx.append_error(
        resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource() },
        resource_location{ loc.end.line, loc.end.column, ctx.get_resource() },
        msg);
}

#define IGNORE_TERM(...)


#line 73 "annium.tab.cpp"


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
#line 170 "annium.tab.cpp"

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
        value.copy< annium::annotated_decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.copy< annium::annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.copy< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.copy< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.copy< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.copy< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.copy< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.copy< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.copy< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.copy< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.copy< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.copy< pattern_t::field > (YY_MOVE (that.value));
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.copy< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< sonia::optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.copy< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
        value.move< annium::annotated_decimal > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.move< annium::annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (s.value));
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.move< sonia::optional<syntax_expression_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.move< syntax_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
        value.YY_MOVE_OR_COPY< annium::annotated_decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.YY_MOVE_OR_COPY< annium::annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.YY_MOVE_OR_COPY< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.YY_MOVE_OR_COPY< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.YY_MOVE_OR_COPY< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.YY_MOVE_OR_COPY< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.YY_MOVE_OR_COPY< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.YY_MOVE_OR_COPY< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< pattern_t::field > (YY_MOVE (that.value));
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.YY_MOVE_OR_COPY< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< sonia::optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
        value.move< annium::annotated_decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.move< annium::annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (that.value));
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.move< sonia::optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.move< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
        value.copy< annium::annotated_decimal > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.copy< annium::annotated_qname > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.copy< annium::annotated_string_view > (that.value);
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.copy< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.copy< expression_list_t > (that.value);
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.copy< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (that.value);
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.copy< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.copy< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.copy< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (that.value);
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (that.value);
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.copy< parameter_t > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.copy< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (that.value);
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.copy< pattern_t::field > (that.value);
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.copy< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< sonia::optional<syntax_expression_t> > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.copy< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
        value.move< annium::annotated_decimal > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        value.move< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        value.move< annium::annotated_qname > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        value.move< annium::annotated_string_view > (that.value);
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        value.move< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        value.move< expression_list_t > (that.value);
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        value.move< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (that.value);
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        value.move< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (that.value);
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        value.move< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (that.value);
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        value.move< parameter_t > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        value.move< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (that.value);
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        value.move< pattern_t::field > (that.value);
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        value.move< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        value.move< sonia::optional<syntax_expression_t> > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        value.move< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        value.move< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
#line 330 "annium.y"
                 { }
#line 1756 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1762 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1768 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1774 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1780 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 330 "annium.y"
                 { }
#line 1786 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 330 "annium.y"
                 { }
#line 1792 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 330 "annium.y"
                 { }
#line 1798 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 330 "annium.y"
                 { }
#line 1804 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 330 "annium.y"
                 { }
#line 1810 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 330 "annium.y"
                 { }
#line 1816 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 330 "annium.y"
                 { }
#line 1822 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 330 "annium.y"
                 { }
#line 1828 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 330 "annium.y"
                 { }
#line 1834 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 330 "annium.y"
                 { }
#line 1840 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 330 "annium.y"
                 { }
#line 1846 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 330 "annium.y"
                 { }
#line 1852 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 330 "annium.y"
                 { }
#line 1858 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 330 "annium.y"
                 { }
#line 1864 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 330 "annium.y"
                 { }
#line 1870 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 330 "annium.y"
                 { }
#line 1876 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 330 "annium.y"
                 { }
#line 1882 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 330 "annium.y"
                 { }
#line 1888 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 330 "annium.y"
                 { }
#line 1894 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 330 "annium.y"
                 { }
#line 1900 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 330 "annium.y"
                 { }
#line 1906 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 330 "annium.y"
                 { }
#line 1912 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 330 "annium.y"
                 { }
#line 1918 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 330 "annium.y"
                 { }
#line 1924 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 330 "annium.y"
                 { }
#line 1930 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 330 "annium.y"
                 { }
#line 1936 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 330 "annium.y"
                 { }
#line 1942 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 330 "annium.y"
                 { }
#line 1948 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 330 "annium.y"
                 { }
#line 1954 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 330 "annium.y"
                 { }
#line 1960 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 330 "annium.y"
                 { }
#line 1966 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 330 "annium.y"
                 { }
#line 1972 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 330 "annium.y"
                 { }
#line 1978 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 330 "annium.y"
                 { }
#line 1984 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 330 "annium.y"
                 { }
#line 1990 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 330 "annium.y"
                 { }
#line 1996 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 330 "annium.y"
                 { }
#line 2002 "annium.tab.cpp"
        break;

      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
#line 330 "annium.y"
                 { }
#line 2008 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 330 "annium.y"
                 { }
#line 2014 "annium.tab.cpp"
        break;

      case symbol_kind::S_110_let_decl: // let-decl
#line 330 "annium.y"
                 { }
#line 2020 "annium.tab.cpp"
        break;

      case symbol_kind::S_111_let_decl_start: // let-decl-start
#line 330 "annium.y"
                 { }
#line 2026 "annium.tab.cpp"
        break;

      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 330 "annium.y"
                 { }
#line 2032 "annium.tab.cpp"
        break;

      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
#line 330 "annium.y"
                 { }
#line 2038 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
#line 330 "annium.y"
                 { }
#line 2044 "annium.tab.cpp"
        break;

      case symbol_kind::S_115_function_body: // function-body
#line 330 "annium.y"
                 { }
#line 2050 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_braced_statements: // braced-statements
#line 330 "annium.y"
                 { }
#line 2056 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
#line 330 "annium.y"
                 { }
#line 2062 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
#line 330 "annium.y"
                 { }
#line 2068 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
#line 330 "annium.y"
                 { }
#line 2074 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_infunction_statement: // infunction-statement
#line 330 "annium.y"
                 { }
#line 2080 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 330 "annium.y"
                 { }
#line 2086 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
#line 330 "annium.y"
                 { }
#line 2092 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 330 "annium.y"
                 { }
#line 2098 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
#line 330 "annium.y"
                 { }
#line 2104 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_fn_name: // fn-name
#line 330 "annium.y"
                 { }
#line 2110 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
#line 330 "annium.y"
                 { }
#line 2116 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
#line 330 "annium.y"
                 { }
#line 2122 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
#line 330 "annium.y"
                 { }
#line 2128 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_case_list: // case-list
#line 330 "annium.y"
                 { }
#line 2134 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_case_decl: // case-decl
#line 330 "annium.y"
                 { }
#line 2140 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
#line 330 "annium.y"
                 { }
#line 2146 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_using_decl: // using-decl
#line 330 "annium.y"
                 { }
#line 2152 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_expression_list: // expression-list
#line 330 "annium.y"
                 { }
#line 2158 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
#line 330 "annium.y"
                 { }
#line 2164 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_argument_list: // argument-list
#line 330 "annium.y"
                 { }
#line 2170 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 330 "annium.y"
                 { }
#line 2176 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_argument_name: // argument-name
#line 330 "annium.y"
                 { }
#line 2182 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
#line 330 "annium.y"
                 { }
#line 2188 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_field_list: // field-list
#line 330 "annium.y"
                 { }
#line 2194 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
#line 330 "annium.y"
                 { }
#line 2200 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 330 "annium.y"
                 { }
#line 2206 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
#line 330 "annium.y"
                 { }
#line 2212 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_parameter_list: // parameter-list
#line 330 "annium.y"
                 { }
#line 2218 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
#line 330 "annium.y"
                 { }
#line 2224 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
#line 330 "annium.y"
                 { }
#line 2230 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
#line 330 "annium.y"
                 { }
#line 2236 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 330 "annium.y"
                 { }
#line 2242 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
#line 330 "annium.y"
                 { }
#line 2248 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
#line 330 "annium.y"
                 { }
#line 2254 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_constraint_expression: // constraint-expression
#line 330 "annium.y"
                 { }
#line 2260 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 330 "annium.y"
                 { }
#line 2266 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_pattern_list: // pattern-list
#line 330 "annium.y"
                 { }
#line 2272 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
#line 330 "annium.y"
                 { }
#line 2278 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_pattern_field: // pattern-field
#line 330 "annium.y"
                 { }
#line 2284 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
#line 330 "annium.y"
                 { }
#line 2290 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
#line 330 "annium.y"
                 { }
#line 2296 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 330 "annium.y"
                 { }
#line 2302 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
#line 330 "annium.y"
                 { }
#line 2308 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
#line 330 "annium.y"
                 { }
#line 2314 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
#line 330 "annium.y"
                 { }
#line 2320 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_syntax_expression: // syntax-expression
#line 330 "annium.y"
                 { }
#line 2326 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
#line 330 "annium.y"
                 { }
#line 2332 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
#line 330 "annium.y"
                 { }
#line 2338 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_new_expression: // new-expression
#line 330 "annium.y"
                 { }
#line 2344 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_call_expression: // call-expression
#line 330 "annium.y"
                 { }
#line 2350 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
#line 330 "annium.y"
                 { }
#line 2356 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_lambda_expression: // lambda-expression
#line 330 "annium.y"
                 { }
#line 2362 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
#line 330 "annium.y"
                 { }
#line 2368 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pack_expression: // pack-expression
#line 330 "annium.y"
                 { }
#line 2374 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_compound_expression: // compound-expression
#line 330 "annium.y"
                 { }
#line 2380 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_type_expr: // type-expr
#line 330 "annium.y"
                 { }
#line 2386 "annium.tab.cpp"
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
        yylhs.value.emplace< annium::annotated_decimal > ();
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_137_argument_name: // argument-name
        yylhs.value.emplace< annium::annotated_identifier > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< annium::annotated_integer > ();
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_125_fn_name: // fn-name
        yylhs.value.emplace< annium::annotated_qname > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
        yylhs.value.emplace< annium::annotated_string_view > ();
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< annium::context_identifier > ();
        break;

      case symbol_kind::S_130_case_decl: // case-decl
        yylhs.value.emplace< annium::identifier > ();
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        yylhs.value.emplace< annotated_bool > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< concept_expression_list_t > ();
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_133_expression_list: // expression-list
        yylhs.value.emplace< expression_list_t > ();
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
      case symbol_kind::S_139_field_list: // field-list
        yylhs.value.emplace< field_list_t > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field_t > ();
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
        yylhs.value.emplace< finished_statement_type > ();
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure_t > ();
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        yylhs.value.emplace< generic_statement_type > ();
        break;

      case symbol_kind::S_166_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< lambda_t > ();
        break;

      case symbol_kind::S_110_let_decl: // let-decl
      case symbol_kind::S_111_let_decl_start: // let-decl-start
      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_115_function_body: // function-body
      case symbol_kind::S_116_braced_statements: // braced-statements
      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< managed_statement_list > ();
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
      case symbol_kind::S_135_argument_list: // argument-list
      case symbol_kind::S_168_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_169_pack_expression: // pack-expression
        yylhs.value.emplace< named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< named_expression_t > ();
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_143_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter_t > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_152_pattern_list: // pattern-list
        yylhs.value.emplace< pattern_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< pattern_t > ();
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_154_pattern_field: // pattern-field
        yylhs.value.emplace< pattern_t::field > ();
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
      case symbol_kind::S_FN: // "`fn`"
      case symbol_kind::S_TYPENAME: // "typename modifier"
      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
        yylhs.value.emplace< sonia::lang::lex::resource_location > ();
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< sonia::optional<syntax_expression_t> > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_120_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<pattern_t, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_150_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
      case symbol_kind::S_129_case_list: // case-list
        yylhs.value.emplace< std::vector<annium::identifier> > ();
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
      case symbol_kind::S_161_syntax_expression: // syntax-expression
      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_164_new_expression: // new-expression
      case symbol_kind::S_165_call_expression: // call-expression
      case symbol_kind::S_167_lambda_expression: // lambda-expression
      case symbol_kind::S_170_compound_expression: // compound-expression
      case symbol_kind::S_171_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression_t > ();
        break;

      case symbol_kind::S_132_using_decl: // using-decl
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
#line 335 "annium.y"
                            { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2861 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 336 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2867 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 341 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 2873 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 343 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 2879 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 345 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2885 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 362 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 2891 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 363 "annium.y"
                                                { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2897 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 365 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2903 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 367 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2909 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 372 "annium.y"
        { yylhs.value.as < statement > () = extern_var{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 2915 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 374 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < fn_pure_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 2921 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 376 "annium.y"
        { yylhs.value.as < statement > () = include_decl{ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 2927 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 389 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 2933 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 391 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < struct_decl > ()); }
#line 2939 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 396 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 2945 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 398 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = std::move(yystack_[0].value.as < named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 2951 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 403 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = false }; }
#line 2957 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 405 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = true }; }
#line 2963 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 409 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 2969 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 411 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 2975 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 416 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 2981 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 418 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 2987 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 420 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2993 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 425 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 2999 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 426 "annium.y"
                                                           { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3005 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 428 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3011 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 430 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3017 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 436 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3023 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression "APOSTROPHE"
#line 438 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ yystack_[1].value.as < syntax_expression_t > (), std::move(loc) });
            yylhs.value.as < managed_statement_list > () = std::move(sts);
        }
#line 3034 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 448 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3040 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 453 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3046 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 455 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; }
#line 3052 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" syntax-expression "`in`" syntax-expression braced-statements
#line 457 "annium.y"
        { yylhs.value.as < finished_statement_type > () = for_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3058 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 459 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3064 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 461 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[2].value.as < managed_statement_list > ())), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3070 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-start-decl fn-decl braced-statements
#line 463 "annium.y"
        {   
            yystack_[1].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure_t > ().kind = get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[1].value.as < fn_pure_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) };
        }
#line 3080 "annium.tab.cpp"
    break;

  case 38: // finished-statement: fn-start-decl fn-decl "`=>`" syntax-expression "`;`"
#line 469 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(loc) });
            yystack_[3].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[4].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[3].value.as < fn_pure_t > ().kind = get<1>(yystack_[4].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[3].value.as < fn_pure_t > ()), ctx.push(std::move(sts)) };
        }
#line 3093 "annium.tab.cpp"
    break;

  case 39: // finished-statement: STRUCT qname braced-statements
#line 478 "annium.y"
        { yylhs.value.as < finished_statement_type > () = struct_decl{ .name = std::move(yystack_[1].value.as < annium::annotated_qname > ()), .body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3099 "annium.tab.cpp"
    break;

  case 40: // finished-statement: STRUCT qname "`(`" parameter-list-opt "`)`" braced-statements
#line 480 "annium.y"
        { yylhs.value.as < finished_statement_type > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[2].value.as < parameter_list_t > ()), .body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3105 "annium.tab.cpp"
    break;

  case 41: // finished-statement: ENUM enum-decl
#line 482 "annium.y"
        { yylhs.value.as < finished_statement_type > () = std::move(yystack_[0].value.as < enum_decl > ()); }
#line 3111 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: infunction-statement-any
#line 487 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3117 "annium.tab.cpp"
    break;

  case 43: // infunction-statement-set: finished-infunction-statement-any
#line 489 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3123 "annium.tab.cpp"
    break;

  case 44: // generic-statement: LET let-decl
#line 494 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3129 "annium.tab.cpp"
    break;

  case 45: // generic-statement: USING using-decl
#line 496 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < using_decl > ()); }
#line 3135 "annium.tab.cpp"
    break;

  case 46: // generic-statement: compound-expression
#line 498 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3141 "annium.tab.cpp"
    break;

  case 47: // generic-statement: syntax-expression "`=`" syntax-expression
#line 500 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ binary_expression_t{ binary_operator_type::ASSIGN, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) } }; }
#line 3147 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: generic-statement
#line 505 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3153 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`break`"
#line 507 "annium.y"
        { yylhs.value.as < statement > () = break_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3159 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`continue`"
#line 509 "annium.y"
        { yylhs.value.as < statement > () = continue_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3165 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`"
#line 511 "annium.y"
        { yylhs.value.as < statement > () = return_decl_t{ .location = std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3171 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`return`" syntax-expression
#line 513 "annium.y"
        { yylhs.value.as < statement > () = return_decl_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3177 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 518 "annium.y"
      { yylhs.value.as < annium::annotated_identifier > () = ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3183 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 526 "annium.y"
        { yylhs.value.as < annium::context_identifier > () = context_identifier { ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()) }; }
#line 3189 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 541 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3195 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 543 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3201 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 545 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = std::move(yystack_[2].value.as < annium::annotated_qname > ()); yylhs.value.as < annium::annotated_qname > ().value.append(std::move(yystack_[0].value.as < annium::annotated_identifier > ().value)); }
#line 3207 "annium.tab.cpp"
    break;

  case 58: // fn-start-decl: "`fn`"
#line 551 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), fn_kind::DEFAULT }; }
#line 3213 "annium.tab.cpp"
    break;

  case 59: // fn-start-decl: INLINE "`fn`"
#line 553 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), fn_kind::INLINE }; }
#line 3219 "annium.tab.cpp"
    break;

  case 60: // fn-name: qname
#line 557 "annium.y"
      { yylhs.value.as < annium::annotated_qname > () = yystack_[0].value.as < annium::annotated_qname > (); }
#line 3225 "annium.tab.cpp"
    break;

  case 61: // fn-name: "`new`"
#line 558 "annium.y"
          { yylhs.value.as < annium::annotated_qname > () = ctx.make_qname(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }); }
#line 3231 "annium.tab.cpp"
    break;

  case 62: // fn-decl: fn-name "`(`" parameter-list-opt "`)`"
#line 563 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[3].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[3].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[1].value.as < parameter_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3237 "annium.tab.cpp"
    break;

  case 63: // fn-decl: fn-name "`(`" parameter-list-opt "`)`" "`->`" type-expr
#line 565 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = std::move(yystack_[0].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3243 "annium.tab.cpp"
    break;

  case 64: // fn-decl: fn-name "`(`" parameter-list-opt "`)`" "`~>`" pattern
#line 567 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = std::move(yystack_[0].value.as < pattern_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3249 "annium.tab.cpp"
    break;

  case 65: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 573 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ std::move(yystack_[3].value.as < annium::annotated_qname > ()), std::move(yystack_[1].value.as < std::vector<annium::identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3255 "annium.tab.cpp"
    break;

  case 66: // case-list-opt: %empty
#line 577 "annium.y"
             { yylhs.value.as < std::vector<annium::identifier> > () = {}; }
#line 3261 "annium.tab.cpp"
    break;

  case 67: // case-list-opt: case-list
#line 578 "annium.y"
      { yylhs.value.as < std::vector<annium::identifier> > () = yystack_[0].value.as < std::vector<annium::identifier> > (); }
#line 3267 "annium.tab.cpp"
    break;

  case 68: // case-list: case-decl
#line 583 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::vector<annium::identifier>{std::move(yystack_[0].value.as < annium::identifier > ())}; }
#line 3273 "annium.tab.cpp"
    break;

  case 69: // case-list: case-list "," case-decl
#line 585 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::move(yystack_[2].value.as < std::vector<annium::identifier> > ()); yylhs.value.as < std::vector<annium::identifier> > ().emplace_back(std::move(yystack_[0].value.as < annium::identifier > ())); }
#line 3279 "annium.tab.cpp"
    break;

  case 70: // case-decl: identifier
#line 590 "annium.y"
        { yylhs.value.as < annium::identifier > () = yystack_[0].value.as < annium::annotated_identifier > ().value; }
#line 3285 "annium.tab.cpp"
    break;

  case 71: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 596 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3291 "annium.tab.cpp"
    break;

  case 72: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 598 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[7].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[5].value.as < parameter_list_t > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[6].value.as < sonia::lang::lex::resource_location > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3297 "annium.tab.cpp"
    break;

  case 73: // using-decl: qname "`=>`" syntax-expression
#line 621 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[2].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[2].value.as < annium::annotated_qname > ().location), .result = nullptr }, ctx.push(std::move(sts)) } };
        }
#line 3308 "annium.tab.cpp"
    break;

  case 74: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 628 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.push(std::move(sts)) } };
            IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ());
        }
#line 3320 "annium.tab.cpp"
    break;

  case 75: // expression-list: syntax-expression
#line 646 "annium.y"
        { yylhs.value.as < expression_list_t > () = expression_list_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3326 "annium.tab.cpp"
    break;

  case 76: // expression-list: expression-list "," syntax-expression
#line 648 "annium.y"
        { yylhs.value.as < expression_list_t > () = std::move(yystack_[2].value.as < expression_list_t > ()); yylhs.value.as < expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3332 "annium.tab.cpp"
    break;

  case 77: // argument-list-opt: %empty
#line 653 "annium.y"
              { yylhs.value.as < named_expression_list_t > () = {}; }
#line 3338 "annium.tab.cpp"
    break;

  case 78: // argument-list-opt: argument-list
#line 654 "annium.y"
      { yylhs.value.as < named_expression_list_t > () = yystack_[0].value.as < named_expression_list_t > (); }
#line 3344 "annium.tab.cpp"
    break;

  case 79: // argument-list: argument
#line 659 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{std::move(yystack_[0].value.as < named_expression_t > ())}; }
#line 3350 "annium.tab.cpp"
    break;

  case 80: // argument-list: argument-list "," argument
#line 661 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ()); yylhs.value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < named_expression_t > ())); }
#line 3356 "annium.tab.cpp"
    break;

  case 81: // argument: argument-name syntax-expression
#line 666 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[1].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3362 "annium.tab.cpp"
    break;

  case 82: // argument: syntax-expression
#line 668 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3368 "annium.tab.cpp"
    break;

  case 83: // argument-name: identifier "`=`"
#line 673 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3374 "annium.tab.cpp"
    break;

  case 84: // argument-name: identifier "`:`"
#line 675 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3380 "annium.tab.cpp"
    break;

  case 85: // field-list-opt: %empty
#line 680 "annium.y"
              { yylhs.value.as < field_list_t > () = {}; }
#line 3386 "annium.tab.cpp"
    break;

  case 86: // field-list-opt: field-list
#line 681 "annium.y"
      { yylhs.value.as < field_list_t > () = yystack_[0].value.as < field_list_t > (); }
#line 3392 "annium.tab.cpp"
    break;

  case 87: // field-list: field
#line 686 "annium.y"
        { yylhs.value.as < field_list_t > () = field_list_t{std::move(yystack_[0].value.as < field_t > ())}; }
#line 3398 "annium.tab.cpp"
    break;

  case 88: // field-list: field-list "," field
#line 688 "annium.y"
        { yylhs.value.as < field_list_t > () = std::move(yystack_[2].value.as < field_list_t > ()); yylhs.value.as < field_list_t > ().emplace_back(std::move(yystack_[0].value.as < field_t > ())); }
#line 3404 "annium.tab.cpp"
    break;

  case 89: // field-default-value-opt: %empty
#line 692 "annium.y"
             { yylhs.value.as < sonia::optional<syntax_expression_t> > () = nullopt; }
#line 3410 "annium.tab.cpp"
    break;

  case 90: // field-default-value-opt: "`=`" syntax-expression
#line 693 "annium.y"
                                      { yylhs.value.as < sonia::optional<syntax_expression_t> > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3416 "annium.tab.cpp"
    break;

  case 91: // field: identifier "`:`" type-expr field-default-value-opt
#line 698 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ std::move(yystack_[3].value.as < annium::annotated_identifier > ()), parameter_constraint_modifier_t::runtime_type, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()) }; }
#line 3422 "annium.tab.cpp"
    break;

  case 92: // field: identifier "`=>`" syntax-expression
#line 700 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), parameter_constraint_modifier_t::any_constexpr_type, std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3428 "annium.tab.cpp"
    break;

  case 93: // parameter-list-opt: %empty
#line 706 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3434 "annium.tab.cpp"
    break;

  case 94: // parameter-list-opt: parameter-list
#line 707 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3440 "annium.tab.cpp"
    break;

  case 95: // parameter-list: parameter-decl
#line 712 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ parameter_t{std::move(yystack_[0].value.as < parameter_t > ())} }; }
#line 3446 "annium.tab.cpp"
    break;

  case 96: // parameter-list: parameter-list "," parameter-decl
#line 714 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter_t > ())); }
#line 3452 "annium.tab.cpp"
    break;

  case 97: // internal-identifier-opt: %empty
#line 718 "annium.y"
             { yylhs.value.as < annium::context_identifier > () = context_identifier{}; }
#line 3458 "annium.tab.cpp"
    break;

  case 98: // internal-identifier-opt: internal-identifier
#line 719 "annium.y"
                                 { yylhs.value.as < annium::context_identifier > () = std::move(yystack_[0].value.as < annium::context_identifier > ()); }
#line 3464 "annium.tab.cpp"
    break;

  case 99: // parameter-default-value-opt: %empty
#line 723 "annium.y"
             { yylhs.value.as < sonia::optional<syntax_expression_t> > () = nullopt; }
#line 3470 "annium.tab.cpp"
    break;

  case 100: // parameter-default-value-opt: "`=`" syntax-expression
#line 724 "annium.y"
                                      { yylhs.value.as < sonia::optional<syntax_expression_t> > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3476 "annium.tab.cpp"
    break;

  case 101: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 729 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3482 "annium.tab.cpp"
    break;

  case 102: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 731 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3488 "annium.tab.cpp"
    break;

  case 103: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 733 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3494 "annium.tab.cpp"
    break;

  case 104: // parameter-decl: pattern-mod parameter-default-value-opt
#line 735 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3500 "annium.tab.cpp"
    break;

  case 105: // parameter-decl: identifier internal-identifier parameter-default-value-opt
#line 738 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3506 "annium.tab.cpp"
    break;

  case 106: // parameter-decl: internal-identifier parameter-default-value-opt
#line 740 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3512 "annium.tab.cpp"
    break;

  case 107: // parameter-decl: "`_`" parameter-default-value-opt
#line 742 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3518 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 744 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3524 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: "`...`" parameter-default-value-opt
#line 746 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3530 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 751 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3536 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 753 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3542 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 755 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3548 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 757 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3554 "annium.tab.cpp"
    break;

  case 114: // constraint-expression-specified-mod: "constexpr modifier"
#line 761 "annium.y"
                { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::any_constexpr_type }; }
#line 3560 "annium.tab.cpp"
    break;

  case 115: // constraint-expression-specified-mod: "runctime modifier"
#line 762 "annium.y"
              { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3566 "annium.tab.cpp"
    break;

  case 116: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 767 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3572 "annium.tab.cpp"
    break;

  case 117: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 769 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3578 "annium.tab.cpp"
    break;

  case 118: // constraint-expression-specified: constraint-expression-specified-mod
#line 773 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ())) }}, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3584 "annium.tab.cpp"
    break;

  case 119: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 775 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3590 "annium.tab.cpp"
    break;

  case 120: // constraint-expression-mod: %empty
#line 780 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ sonia::lang::lex::resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource() }, parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3599 "annium.tab.cpp"
    break;

  case 121: // constraint-expression-mod: constraint-expression-specified-mod
#line 784 "annium.y"
      { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (); }
#line 3605 "annium.tab.cpp"
    break;

  case 122: // constraint-expression: constraint-expression-mod type-expr
#line 789 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3611 "annium.tab.cpp"
    break;

  case 123: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 791 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3617 "annium.tab.cpp"
    break;

  case 124: // constraint-expression: constraint-expression-mod
#line 795 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) } }, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3623 "annium.tab.cpp"
    break;

  case 125: // constraint-expression: constraint-expression-mod "`...`"
#line 797 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3629 "annium.tab.cpp"
    break;

  case 126: // subpatterns: "`(`" pattern-list "`)`"
#line 803 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[1].value.as < pattern_list_t > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3635 "annium.tab.cpp"
    break;

  case 127: // pattern-list: pattern-field
#line 808 "annium.y"
        { yylhs.value.as < pattern_list_t > () = pattern_list_t{ std::move(yystack_[0].value.as < pattern_t::field > ()) }; }
#line 3641 "annium.tab.cpp"
    break;

  case 128: // pattern-list: pattern-list "," pattern-field
#line 810 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[2].value.as < pattern_list_t > ()); yylhs.value.as < pattern_list_t > ().emplace_back(std::move(yystack_[0].value.as < pattern_t::field > ())); }
#line 3647 "annium.tab.cpp"
    break;

  case 129: // pattern-field-sfx: concept-expression-list-opt
#line 816 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3653 "annium.tab.cpp"
    break;

  case 130: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 818 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3659 "annium.tab.cpp"
    break;

  case 131: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 821 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3665 "annium.tab.cpp"
    break;

  case 132: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 823 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3671 "annium.tab.cpp"
    break;

  case 133: // pattern-field-sfx: "`=`" pattern-sfx
#line 827 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3677 "annium.tab.cpp"
    break;

  case 134: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 830 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3683 "annium.tab.cpp"
    break;

  case 135: // pattern-field: identifier pattern-field-sfx
#line 836 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3689 "annium.tab.cpp"
    break;

  case 136: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 839 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3695 "annium.tab.cpp"
    break;

  case 137: // pattern-field: pattern-field-sfx
#line 852 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ }; }
#line 3701 "annium.tab.cpp"
    break;

  case 138: // pattern-field: "`_`" pattern-field-sfx
#line 855 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3707 "annium.tab.cpp"
    break;

  case 139: // pattern-mod: "`~`" pattern-sfx
#line 859 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3713 "annium.tab.cpp"
    break;

  case 140: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 860 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3719 "annium.tab.cpp"
    break;

  case 141: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 861 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3725 "annium.tab.cpp"
    break;

  case 142: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 862 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3731 "annium.tab.cpp"
    break;

  case 143: // pattern-sfx: pattern
#line 866 "annium.y"
              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < pattern_t > ()), parameter_constraint_modifier_t::none }; }
#line 3737 "annium.tab.cpp"
    break;

  case 144: // pattern-sfx: pattern "`...`"
#line 867 "annium.y"
                       { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < pattern_t > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3743 "annium.tab.cpp"
    break;

  case 145: // pattern-sfx: "`...`"
#line 868 "annium.y"
               { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3749 "annium.tab.cpp"
    break;

  case 146: // pattern: qname
#line 873 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3755 "annium.tab.cpp"
    break;

  case 147: // pattern: qname subpatterns concept-expression-list-opt
#line 875 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[2].value.as < annium::annotated_qname > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3761 "annium.tab.cpp"
    break;

  case 148: // pattern: internal-identifier concept-expression-list-opt
#line 877 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[1].value.as < annium::context_identifier > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3767 "annium.tab.cpp"
    break;

  case 149: // pattern: "`_`" concept-expression-list-opt
#line 879 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3773 "annium.tab.cpp"
    break;

  case 150: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 881 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }, .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3779 "annium.tab.cpp"
    break;

  case 151: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 883 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[2].value.as < syntax_expression_t > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3785 "annium.tab.cpp"
    break;

  case 152: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 885 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[3].value.as < syntax_expression_t > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3791 "annium.tab.cpp"
    break;

  case 153: // pattern: concept-expression-list
#line 887 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{}, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3797 "annium.tab.cpp"
    break;

  case 154: // concept-expression: "`@`" qname
#line 892 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = syntax_expression_t{ qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3803 "annium.tab.cpp"
    break;

  case 155: // concept-expression-list-opt: %empty
#line 897 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = {}; }
#line 3809 "annium.tab.cpp"
    break;

  case 156: // concept-expression-list-opt: concept-expression-list
#line 898 "annium.y"
      { yylhs.value.as < concept_expression_list_t > () = yystack_[0].value.as < concept_expression_list_t > (); }
#line 3815 "annium.tab.cpp"
    break;

  case 157: // concept-expression-list: concept-expression
#line 903 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = concept_expression_list_t{std::move(yystack_[0].value.as < syntax_expression_t > ())}; }
#line 3821 "annium.tab.cpp"
    break;

  case 158: // concept-expression-list: concept-expression-list concept-expression
#line 905 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = std::move(yystack_[1].value.as < concept_expression_list_t > ()); yylhs.value.as < concept_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3827 "annium.tab.cpp"
    break;

  case 159: // syntax-expression: CONTEXT_IDENTIFIER
#line 912 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3833 "annium.tab.cpp"
    break;

  case 160: // syntax-expression: CT_IDENTIFIER
#line 914 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3839 "annium.tab.cpp"
    break;

  case 161: // syntax-expression: syntax-expression-wo-ii
#line 915 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3845 "annium.tab.cpp"
    break;

  case 162: // syntax-expression-wo-ii: "nil"
#line 921 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_nil > ()); }
#line 3851 "annium.tab.cpp"
    break;

  case 163: // syntax-expression-wo-ii: "true"
#line 923 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3857 "annium.tab.cpp"
    break;

  case 164: // syntax-expression-wo-ii: "false"
#line 925 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3863 "annium.tab.cpp"
    break;

  case 165: // syntax-expression-wo-ii: INTEGER
#line 927 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_integer > ()); }
#line 3869 "annium.tab.cpp"
    break;

  case 166: // syntax-expression-wo-ii: DECIMAL
#line 929 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3875 "annium.tab.cpp"
    break;

  case 167: // syntax-expression-wo-ii: DECIMAL_S
#line 931 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3881 "annium.tab.cpp"
    break;

  case 168: // syntax-expression-wo-ii: INTEGER_INDEX
#line 933 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annotated_decimal{ ctx.make_decimal(yystack_[0].value.as < annium::annotated_string_view > ().value), yystack_[0].value.as < annium::annotated_string_view > ().location }; }
#line 3887 "annium.tab.cpp"
    break;

  case 169: // syntax-expression-wo-ii: STRING
#line 935 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3893 "annium.tab.cpp"
    break;

  case 170: // syntax-expression-wo-ii: RESERVED_IDENTIFIER
#line 937 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3899 "annium.tab.cpp"
    break;

  case 171: // syntax-expression-wo-ii: qname
#line 939 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 3905 "annium.tab.cpp"
    break;

  case 172: // syntax-expression-wo-ii: "`(`" "`)`"
#line 941 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 3911 "annium.tab.cpp"
    break;

  case 173: // syntax-expression-wo-ii: "`(`" "`:`" syntax-expression "`)`"
#line 943 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[3].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, named_expression_list_t{ named_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()) } } };
        }
#line 3920 "annium.tab.cpp"
    break;

  case 174: // syntax-expression-wo-ii: "`(`" pack-expression "`)`"
#line 948 "annium.y"
        {
            if (yystack_[1].value.as < named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) };
            }
        }
#line 3933 "annium.tab.cpp"
    break;

  case 175: // syntax-expression-wo-ii: "`[`" expression-list "`]`"
#line 957 "annium.y"
        { 
            if (yystack_[1].value.as < expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression_t > () = annium_vector_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > ().front()) };
            } else {
                yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )};
            }
        }
#line 3945 "annium.tab.cpp"
    break;

  case 176: // syntax-expression-wo-ii: "`[[`" expression-list "`]]`"
#line 965 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )}; }
#line 3951 "annium.tab.cpp"
    break;

  case 177: // syntax-expression-wo-ii: syntax-expression "`[`" syntax-expression "`]`"
#line 967 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3957 "annium.tab.cpp"
    break;

  case 178: // syntax-expression-wo-ii: "`.`" identifier
#line 969 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3963 "annium.tab.cpp"
    break;

  case 179: // syntax-expression-wo-ii: syntax-expression "`.`" identifier
#line 973 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < annium::annotated_identifier > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3969 "annium.tab.cpp"
    break;

  case 180: // syntax-expression-wo-ii: syntax-expression "`.`" apostrophe-expression
#line 975 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3975 "annium.tab.cpp"
    break;

  case 181: // syntax-expression-wo-ii: syntax-expression INTEGER_INDEX
#line 977 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), annotated_integer{ ctx.make_integer(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1)), yystack_[0].value.as < annium::annotated_string_view > ().location } }; IGNORE_TERM(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3981 "annium.tab.cpp"
    break;

  case 182: // syntax-expression-wo-ii: "`!`" syntax-expression
#line 980 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::NEGATE, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3987 "annium.tab.cpp"
    break;

  case 183: // syntax-expression-wo-ii: "`*`" syntax-expression
#line 982 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::DEREF, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3993 "annium.tab.cpp"
    break;

  case 184: // syntax-expression-wo-ii: syntax-expression "`+`" syntax-expression
#line 987 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::PLUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3999 "annium.tab.cpp"
    break;

  case 185: // syntax-expression-wo-ii: syntax-expression "`-`" syntax-expression
#line 989 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::MINUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4005 "annium.tab.cpp"
    break;

  case 186: // syntax-expression-wo-ii: syntax-expression "`==`" syntax-expression
#line 993 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::EQ, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4011 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-wo-ii: syntax-expression "`!=`" syntax-expression
#line 995 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::NE, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4017 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-wo-ii: syntax-expression "`..`" syntax-expression
#line 997 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::CONCAT, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4023 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-wo-ii: syntax-expression "`&`" syntax-expression
#line 1000 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4029 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-wo-ii: syntax-expression "`|`" syntax-expression
#line 1004 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4035 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-wo-ii: syntax-expression "`&&`" syntax-expression
#line 1007 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4041 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-wo-ii: syntax-expression "`||`" syntax-expression
#line 1010 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4047 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-wo-ii: apostrophe-expression
#line 1012 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4053 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-wo-ii: new-expression
#line 1013 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4059 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-wo-ii: compound-expression
#line 1014 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4065 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-wo-ii: lambda-expression
#line 1015 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4071 "annium.tab.cpp"
    break;

  case 197: // apostrophe-expression: "APOSTROPHE" syntax-expression "APOSTROPHE"
#line 1020 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < syntax_expression_t > ()); }
#line 4077 "annium.tab.cpp"
    break;

  case 198: // new-expression: "`new`" qname
#line 1025 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 4083 "annium.tab.cpp"
    break;

  case 199: // new-expression: "`new`" apostrophe-expression
#line 1027 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 4089 "annium.tab.cpp"
    break;

  case 200: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1029 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4095 "annium.tab.cpp"
    break;

  case 201: // new-expression: "`new`" apostrophe-expression "`(`" argument-list-opt "`)`"
#line 1031 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4101 "annium.tab.cpp"
    break;

  case 202: // call-expression: qname "`(`" pack-expression-opt "`)`"
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4107 "annium.tab.cpp"
    break;

  case 203: // call-expression: CONTEXT_IDENTIFIER "`(`" pack-expression-opt "`)`"
#line 1038 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), name_reference{ ctx.make_identifier(std::move(yystack_[3].value.as < annium::annotated_string_view > ())) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4113 "annium.tab.cpp"
    break;

  case 204: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1040 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4119 "annium.tab.cpp"
    break;

  case 205: // call-expression: apostrophe-expression "`(`" pack-expression "`)`"
#line 1042 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4125 "annium.tab.cpp"
    break;

  case 206: // call-expression: lambda-expression "`(`" pack-expression "`)`"
#line 1044 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4131 "annium.tab.cpp"
    break;

  case 207: // lambda-start-decl: fn-start-decl
#line 1050 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) } }; }
#line 4137 "annium.tab.cpp"
    break;

  case 208: // lambda-start-decl: fn-start-decl "`[`" pack-expression-opt "`]`"
#line 1052 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) }, {}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4143 "annium.tab.cpp"
    break;

  case 209: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1057 "annium.y"
        { 
            yystack_[4].value.as < lambda_t > ().parameters = std::move(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[4].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4154 "annium.tab.cpp"
    break;

  case 210: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1064 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < syntax_expression_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4166 "annium.tab.cpp"
    break;

  case 211: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1072 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < pattern_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4178 "annium.tab.cpp"
    break;

  case 212: // pack-expression-opt: %empty
#line 1083 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{}; }
#line 4184 "annium.tab.cpp"
    break;

  case 213: // pack-expression-opt: pack-expression
#line 1085 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[0].value.as < named_expression_list_t > ()); }
#line 4190 "annium.tab.cpp"
    break;

  case 214: // pack-expression: syntax-expression
#line 1090 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{ named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) } }; }
#line 4196 "annium.tab.cpp"
    break;

  case 215: // pack-expression: identifier "`:`" syntax-expression
#line 1092 "annium.y"
        {
            named_expression_list_t list{};
            list.emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(list);
        }
#line 4206 "annium.tab.cpp"
    break;

  case 216: // pack-expression: pack-expression "," syntax-expression
#line 1098 "annium.y"
        {
            yystack_[2].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ());
        }
#line 4215 "annium.tab.cpp"
    break;

  case 217: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1103 "annium.y"
        {
            yystack_[4].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[4].value.as < named_expression_list_t > ());
        }
#line 4224 "annium.tab.cpp"
    break;

  case 218: // compound-expression: syntax-expression "`...`"
#line 1111 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::ELLIPSIS, false, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4230 "annium.tab.cpp"
    break;

  case 219: // compound-expression: call-expression
#line 1112 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4236 "annium.tab.cpp"
    break;

  case 220: // type-expr: qname
#line 1154 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4242 "annium.tab.cpp"
    break;

  case 221: // type-expr: call-expression
#line 1155 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4248 "annium.tab.cpp"
    break;

  case 222: // type-expr: CONTEXT_IDENTIFIER
#line 1157 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4254 "annium.tab.cpp"
    break;

  case 223: // type-expr: "`[`" type-expr "`]`"
#line 1161 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annium_vector_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < syntax_expression_t > ())}; }
#line 4260 "annium.tab.cpp"
    break;

  case 224: // type-expr: "`(`" "`)`"
#line 1163 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4266 "annium.tab.cpp"
    break;

  case 225: // type-expr: "`(`" pack-expression "`)`"
#line 1165 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4272 "annium.tab.cpp"
    break;

  case 226: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1167 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4278 "annium.tab.cpp"
    break;

  case 227: // type-expr: type-expr "`|`" type-expr
#line 1169 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4284 "annium.tab.cpp"
    break;

  case 228: // type-expr: type-expr "`->`" type-expr
#line 1171 "annium.y"
        { 
            auto loc = get_start_location(yystack_[2].value.as < syntax_expression_t > ());
            yylhs.value.as < syntax_expression_t > () = annium_fn_type_t{ named_expression_list_t{ named_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()) } }, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) };
        }
#line 4293 "annium.tab.cpp"
    break;


#line 4297 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -294;

  const signed char parser::yytable_ninf_ = -99;

  const short
  parser::yypact_[] =
  {
     746,  -294,  -294,   -14,  -294,  -294,  -294,  -294,  -294,  -294,
     867,    40,   846,   867,   867,    40,   867,   867,    -5,   214,
     165,   867,   867,   867,    25,    86,     1,  -294,    25,    25,
    -294,  -294,  -294,   130,    26,   446,  -294,  -294,  -294,  -294,
     348,     5,   921,  -294,    89,  -294,   119,   146,   183,     8,
     867,   197,   958,  -294,  -294,   867,  -294,   207,  1115,    27,
     -23,  1115,   252,  -294,    55,    55,    40,  -294,   216,   254,
    -294,    40,     9,   367,   245,   651,   536,   736,   189,  -294,
    -294,  -294,   226,  -294,   208,  -294,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,    40,   867,   867,  -294,   249,   253,   134,
    -294,   867,   867,   867,   867,   867,   867,  -294,   867,    42,
     867,   867,   867,   867,   867,   867,   395,   867,   266,   263,
    -294,   973,   867,  -294,   867,  -294,   867,  -294,  -294,   304,
     867,   273,  -294,   867,   867,   646,   867,  -294,   867,   255,
     867,   395,    40,   312,   395,  -294,  -294,   295,   316,   395,
     867,  -294,  1115,   351,   351,   451,  1152,   318,  1010,  -294,
    -294,    55,    55,   576,   857,   129,   155,  -294,   356,   356,
     -32,   430,  -294,  -294,   376,    81,   338,   319,  -294,   374,
     356,   356,   202,  -294,  -294,  1115,   347,  1115,  1115,   -14,
     767,   304,   348,    89,   119,   183,    57,   263,   304,    79,
     355,   337,  -294,   867,  1115,   370,  -294,  -294,   867,    25,
     360,   546,  -294,   373,  -294,  -294,   736,   736,   375,  1115,
     371,  -294,   377,   359,  -294,    40,   385,  -294,  -294,   386,
    1020,  -294,  -294,  -294,   867,  -294,  -294,  -294,   467,   356,
     356,    25,   152,  -294,   867,   657,   657,   657,   421,   369,
    -294,   404,  -294,   421,   160,   396,   356,   -32,  -294,   296,
     395,  -294,   157,  -294,  -294,  -294,   867,  -294,   229,   166,
     304,   867,   304,    57,  -294,  -294,  -294,   867,  1115,  -294,
    1115,   325,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,
     422,  -294,    40,   111,   400,   390,  -294,   195,   305,  -294,
    1115,  -294,   232,  -294,  -294,   249,    56,   421,  -294,   421,
    1057,  -294,  -294,  -294,  -294,   421,  -294,  -294,  -294,   -32,
    -294,   356,   356,   304,   867,   341,  -294,  -294,  -294,  -294,
    1115,  -294,  -294,  -294,  1067,    33,  -294,   395,   867,  -294,
     867,   304,  -294,    40,   416,  -294,   304,   341,  -294,   657,
     306,   376,   306,   317,   233,  -294,  -294,   409,  -294,   152,
    -294,   356,   356,  -294,  -294,   176,  1105,   220,  -294,   417,
    1115,  1115,    23,  -294,    40,    57,  -294,  -294,  -294,   306,
    -294,   657,   434,  -294,    56,  -294,   421,  -294,  -294,  -294,
    -294,  -294,  -294,   375,   867,  -294,   426,  -294,  -294,  -294,
    -294,  -294,  1115,  -294
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   169,    53,   159,   170,   160,   168,   165,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
     162,   163,   164,     0,     0,     0,     5,     7,    14,    56,
     171,   207,     0,   161,   193,   194,   219,     0,   196,   195,
     212,   207,     0,   195,    55,     0,   172,    56,   214,     0,
       0,    75,     0,   178,   183,   182,     0,    44,    20,    16,
      18,     0,     0,   198,   199,     0,     0,     0,     0,    45,
      13,    59,     0,    41,     0,    15,     1,     2,    10,     3,
       8,     6,     9,     0,   212,   212,    61,    60,     0,     0,
     181,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,   213,
     197,     0,     0,   174,     0,   175,     0,   176,    19,     0,
       0,     0,    12,    77,    77,    22,     0,    32,     0,    35,
       0,    93,    66,     0,    93,    39,    57,     0,     0,    93,
       0,    37,    47,   186,   187,   191,   192,   188,     0,   179,
     180,   184,   185,   189,   190,     0,     0,    54,    99,    99,
     120,     0,   114,   115,    97,    99,     0,    94,    95,   118,
      99,    99,     0,   203,   173,   215,    56,   216,    76,   222,
       0,     0,   220,     0,   221,     0,    21,    17,     0,    56,
       0,    78,    79,     0,    82,     0,    50,    49,    51,     0,
      42,    43,    25,     0,    48,    23,     0,     0,     0,    73,
       0,    70,     0,    67,    68,    85,     0,   202,   208,     0,
       0,   177,   205,   204,     0,   107,   109,   121,   124,    99,
      99,     0,   155,   145,     0,     0,     0,     0,   155,   146,
     139,   143,   157,   153,    99,     0,    99,   120,   106,     0,
       0,   119,   116,   113,   104,   206,     0,   224,     0,     0,
       0,     0,     0,    11,    83,    84,   200,     0,    81,   201,
      52,     0,    28,    26,    27,    24,    31,    33,    34,    36,
       0,    65,     0,     0,     0,    86,    87,     0,    62,    38,
     100,   125,   122,   112,   103,   154,   155,   155,   149,   156,
       0,   142,   140,   141,   148,   155,   144,   158,   105,   120,
     108,    99,    99,     0,     0,     0,   209,    29,    96,   117,
     217,   225,   223,   228,     0,   227,    80,    93,     0,    69,
       0,     0,    71,     0,     0,    40,     0,     0,   123,     0,
     155,     0,   155,   155,     0,   137,   127,   129,   150,   155,
     147,    99,    99,   111,   102,     0,     0,     0,   226,     0,
      74,    92,    89,    88,    85,    63,    64,   133,   138,   155,
     135,     0,   131,   126,   155,   130,   155,   151,   110,   101,
     210,    30,   211,     0,     0,    91,     0,   136,   134,   132,
     128,   152,    90,    72
  };

  const short
  parser::yypgoto_[] =
  {
    -294,  -294,  -294,  -294,   435,  -294,  -294,  -294,  -294,  -294,
    -193,   -57,    -6,  -294,  -133,   265,    49,  -104,    59,     4,
    -294,   406,  -294,  -294,  -294,   187,  -294,  -294,   470,   352,
    -294,   210,  -294,   114,  -294,  -294,   147,  -116,  -294,  -294,
     110,   231,  -167,  -294,  -294,  -238,  -242,  -294,  -231,   105,
    -165,  -196,  -293,  -229,   -72,    18,     0,  -294,   -11,  -294,
      16,  -294,    22,   259,    32,     6,   104
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    33,    34,    35,    36,    67,    68,    69,   210,   211,
     326,   327,    37,   213,    38,   215,    39,   248,    40,    51,
      98,    99,    83,   222,   223,   224,    85,    79,    60,   200,
     201,   202,   203,   294,   295,   395,   296,   176,   177,   255,
     235,   178,   179,   180,   238,   239,   307,   354,   355,   356,
     181,   250,   251,   252,   357,   309,    58,    43,    44,    45,
      46,    47,    48,   118,   119,    53,   196
  };

  const short
  parser::yytable_[] =
  {
      42,     2,   214,   237,    41,   240,    49,   315,   -46,    74,
      52,     2,   175,    61,    61,     2,    64,    65,   137,   321,
     139,    75,    76,    77,   317,   220,    87,   145,   226,    92,
     125,     2,   367,   229,    50,    42,   171,   175,   394,    41,
     175,    49,   151,   270,    59,   175,     2,   126,     2,   311,
     312,   313,    11,   270,   376,   121,    11,    95,    10,   -46,
      54,    57,     2,   167,    63,   100,   -46,    70,   172,   173,
     254,   349,    11,   241,   350,   271,   123,   270,   214,    73,
     317,   361,    96,    78,    88,   271,    96,    82,    84,   272,
     237,    80,   322,    66,   274,    81,   234,   124,   160,    57,
      97,   152,   153,   154,   155,   156,   157,   108,   158,   271,
     161,   162,   163,   164,   109,   128,   256,   386,   193,   378,
     131,   380,   185,   272,   187,   275,   188,   257,   351,   212,
      86,    97,   340,   204,   204,    42,   216,   114,   217,    41,
     219,    49,   146,    57,    57,   194,   165,   166,   397,   182,
     230,   195,   237,   377,   362,   150,   175,   341,   159,   287,
     288,   289,   197,    57,    57,   174,    57,   115,   193,   241,
     308,     2,   390,   186,   392,   234,   314,   270,   232,    57,
     193,    10,   199,   199,   135,   398,   270,   193,   192,   253,
     174,   221,   329,   174,   116,   194,   270,   324,   174,   124,
     306,   195,   353,   278,   233,   284,   -98,   194,   280,   271,
     140,    42,    11,   195,   194,    41,   344,    49,   271,   332,
     195,   369,   268,   272,   145,   124,   135,   193,   271,   143,
     249,   117,   272,   175,   300,   358,    93,   141,   192,    57,
     345,   324,   272,   360,   310,   135,   353,   379,   353,    95,
     192,   265,   270,   122,   194,    93,   144,   192,   135,   193,
     195,   193,   129,   253,   253,   253,   330,   348,   281,   130,
     135,   334,   124,    93,   293,   353,   142,   204,   331,   236,
     353,   382,   383,   262,   271,   258,   194,   387,   194,    71,
     263,   264,   195,   134,   195,   269,    93,   192,   272,   124,
     305,   149,   273,   384,   249,   249,   249,   127,    72,   174,
       2,   189,   193,   167,   401,   183,   323,   324,   325,   198,
      10,   349,   126,   241,   366,   346,   199,   347,   100,   192,
     193,   192,   381,   124,   241,   193,   345,   218,   370,   194,
     371,   221,   302,   253,   227,   195,   135,     2,   167,   303,
     304,    11,   190,   147,   148,   352,   191,   194,   241,   242,
     225,   100,   194,   195,   318,   253,   320,   253,   195,   228,
     108,   234,    93,   337,   333,   135,   335,   109,   110,   111,
       2,   189,   192,   167,   249,   106,   174,   259,    11,   260,
      10,   244,   293,   266,   402,    93,    94,    26,    27,   253,
     192,     2,   167,   108,   276,   192,   249,   277,   249,   261,
     109,   110,   111,   168,    93,   133,    93,   306,   282,   279,
     290,    11,   190,   293,   286,   135,   191,   365,   291,   292,
     169,   363,   364,   352,   297,   298,     2,   167,   241,   316,
     249,   170,   319,   338,   385,   372,    89,   241,   242,   342,
     375,     1,     2,     3,     4,     5,     6,     7,     8,     9,
     343,   100,    10,   171,   374,   243,   393,    26,    27,   399,
      91,   388,   389,     2,   189,   403,   285,    11,   132,   339,
     244,   102,   103,    10,    62,   106,   205,   336,   396,   400,
     373,   328,     0,    11,    12,   172,   173,     0,    13,     0,
      14,     0,   301,   108,    90,    15,     0,     0,    16,     0,
     109,   110,   111,    17,    11,   190,   112,   113,     0,   191,
      18,     0,    19,    20,    21,    22,     0,    23,     0,   245,
     246,   247,     0,    24,     0,     0,     0,     0,    25,    26,
      27,    28,    29,     0,     0,     0,   100,     0,    30,    31,
      32,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      26,    27,    10,     0,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,   108,     0,
       0,     0,     0,    11,    12,   109,   110,   111,    13,     0,
      14,   112,   113,     0,   283,    15,   102,   103,    16,     0,
     106,     0,     0,    17,     0,     0,   138,     0,     0,     0,
      18,     0,     0,    20,    21,    22,     0,    23,   108,   206,
     207,   208,     0,    24,     0,   109,   110,   111,     0,    26,
      27,    28,   209,     0,     0,     0,     0,     0,    30,    31,
      32,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,   100,    10,     2,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,   243,    11,    12,     0,     0,     0,    13,     0,
      14,   135,     0,   108,    11,    15,     0,   244,    16,   136,
     109,   110,   111,    17,     0,     0,   112,   113,     0,     0,
      18,     0,     0,    20,    21,    22,     0,    23,     0,   206,
     207,   208,     0,    24,     0,     0,     0,     0,     0,    26,
      27,    28,   209,     0,     0,     0,   100,     0,    30,    31,
      32,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    10,     0,     0,     0,   102,   103,   104,   105,
     106,   107,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,   135,     0,   108,     0,
       0,     0,     0,    11,    12,   109,   110,   111,    13,     0,
      14,   112,   113,     0,     0,    15,     0,     0,    16,     0,
       0,     0,     0,    17,    11,    12,   267,     0,     0,    13,
      18,    14,    19,    20,    21,    22,    15,    23,     0,    16,
       0,     0,     0,    24,    17,     0,     0,     0,    25,    26,
      27,    28,    29,     0,    20,     0,     0,     0,    30,    31,
      32,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      26,    27,    10,     0,     0,     0,     0,   100,     0,    30,
      31,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,   102,   103,     0,
       0,   106,    55,    11,    12,    56,     0,     0,    13,     0,
      14,     0,     0,     0,     0,    15,     0,     0,    16,   108,
       0,     0,     0,    17,    11,    12,   109,   110,   111,    13,
       0,    14,   112,    20,     0,     0,    15,     0,     0,    16,
       0,   100,     0,     0,    17,     0,   101,     0,     0,    26,
      27,     0,     0,     0,    20,     0,     0,     0,    30,    31,
      32,   102,   103,   104,   105,   106,   107,     0,     0,     0,
      26,    27,     0,     0,     0,     0,     0,     0,   100,    30,
      31,    32,     0,   108,   120,     0,     0,     0,     0,     0,
     109,   110,   111,   100,     0,     0,   112,   113,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,     0,
     108,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     100,     0,   184,   112,   113,   108,     0,     0,     0,     0,
     100,     0,   109,   110,   111,     0,     0,     0,   112,   113,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   108,   231,     0,     0,     0,   100,     0,   109,
     110,   111,   108,     0,     0,   112,   113,   100,   299,   109,
     110,   111,     0,     0,     0,   112,   113,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,   359,   108,
       0,     0,     0,     0,     0,   100,   109,   110,   111,   108,
     368,   391,   112,   113,     0,   100,   109,   110,   111,     0,
       0,     0,   112,   113,     0,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,   100,     0,   109,   110,   111,   108,     0,     0,
     112,   113,     0,     0,   109,   110,   111,     0,     0,     0,
     112,   113,   102,   103,   104,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   109,   110,   111,     0,     0,     0,   112,   113
  };

  const short
  parser::yycheck_[] =
  {
       0,     6,   135,   170,     0,   170,     0,   249,     0,    20,
      10,     6,   116,    13,    14,     6,    16,    17,    75,   257,
      77,    21,    22,    23,   253,   141,     0,    84,   144,    35,
      53,     6,   325,   149,    48,    35,    68,   141,    15,    35,
     144,    35,    99,    20,    12,   149,     6,    70,     6,   245,
     246,   247,    47,    20,   347,    55,    47,    52,    16,    51,
      11,    12,     6,     7,    15,    10,    58,    18,   100,   101,
     174,    15,    47,    17,    18,    52,    49,    20,   211,    20,
     309,   319,    77,    24,    58,    52,    77,    28,    29,    66,
     257,     5,   257,    98,    15,    94,    15,    70,   109,    50,
      41,   101,   102,   103,   104,   105,   106,    52,   108,    52,
     110,   111,   112,   113,    59,    66,    35,   359,   129,   350,
      71,   352,   122,    66,   124,    46,   126,    46,    72,   135,
       0,    72,    21,   133,   134,   135,   136,    48,   138,   135,
     140,   135,    93,    94,    95,   129,   114,   115,   379,   117,
     150,   129,   319,   349,   319,    21,   260,    46,   109,   216,
     217,   218,   130,   114,   115,   116,   117,    48,   179,    17,
     242,     6,   365,   124,   367,    15,   248,    20,    49,   130,
     191,    16,   133,   134,    50,   381,    20,   198,   129,   171,
     141,   142,    35,   144,    48,   179,    20,    21,   149,    70,
      48,   179,   306,   203,    49,   211,    46,   191,   208,    52,
      21,   211,    47,   191,   198,   211,    21,   211,    52,    53,
     198,   337,   190,    66,   281,    70,    50,   238,    52,    21,
     171,    48,    66,   337,   234,   307,    47,    48,   179,   190,
     297,    21,    66,   315,   244,    50,   350,   351,   352,    52,
     191,    49,    20,    46,   238,    47,    48,   198,    50,   270,
     238,   272,    46,   245,   246,   247,   266,    35,   209,    15,
      50,   271,    70,    47,   225,   379,    50,   277,    49,   169,
     384,   353,    49,   179,    52,   175,   270,   359,   272,    75,
     180,   181,   270,    48,   272,   191,    47,   238,    66,    70,
     241,    48,   198,    70,   245,   246,   247,    55,    94,   260,
       6,     7,   323,     7,   386,    49,    20,    21,    22,    46,
      16,    15,    70,    17,   324,    20,   277,    22,    10,   270,
     341,   272,    15,    70,    17,   346,   393,    82,   338,   323,
     340,   292,   238,   325,    49,   323,    50,     6,     7,   239,
     240,    47,    48,    94,    95,   306,    52,   341,    17,    18,
      48,    10,   346,   341,   254,   347,   256,   349,   346,    53,
      52,    15,    47,    48,   270,    50,   272,    59,    60,    61,
       6,     7,   323,     7,   325,    34,   337,    49,    47,    70,
      16,    50,   343,    46,   394,    47,    48,    93,    94,   381,
     341,     6,     7,    52,    49,   346,   347,    70,   349,    35,
      59,    60,    61,    18,    47,    48,    47,    48,    58,    49,
      49,    47,    48,   374,    51,    50,    52,   323,    51,    70,
      35,   321,   322,   384,    49,    49,     6,     7,    17,    35,
     381,    46,    46,    21,    35,   341,     0,    17,    18,    49,
     346,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      70,    10,    16,    68,    48,    35,    49,    93,    94,    35,
      35,   361,   362,     6,     7,    49,   211,    47,    72,   292,
      50,    30,    31,    16,    14,    34,   134,   277,   374,   384,
     343,   260,    -1,    47,    48,   100,   101,    -1,    52,    -1,
      54,    -1,    35,    52,    58,    59,    -1,    -1,    62,    -1,
      59,    60,    61,    67,    47,    48,    65,    66,    -1,    52,
      74,    -1,    76,    77,    78,    79,    -1,    81,    -1,    99,
     100,   101,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    10,    -1,   102,   103,
     104,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      93,    94,    16,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    52,    -1,
      -1,    -1,    -1,    47,    48,    59,    60,    61,    52,    -1,
      54,    65,    66,    -1,    58,    59,    30,    31,    62,    -1,
      34,    -1,    -1,    67,    -1,    -1,    80,    -1,    -1,    -1,
      74,    -1,    -1,    77,    78,    79,    -1,    81,    52,    83,
      84,    85,    -1,    87,    -1,    59,    60,    61,    -1,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    10,    16,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    35,    47,    48,    -1,    -1,    -1,    52,    -1,
      54,    50,    -1,    52,    47,    59,    -1,    50,    62,    58,
      59,    60,    61,    67,    -1,    -1,    65,    66,    -1,    -1,
      74,    -1,    -1,    77,    78,    79,    -1,    81,    -1,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    -1,    -1,    10,    -1,   102,   103,
     104,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    50,    -1,    52,    -1,
      -1,    -1,    -1,    47,    48,    59,    60,    61,    52,    -1,
      54,    65,    66,    -1,    -1,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    67,    47,    48,    49,    -1,    -1,    52,
      74,    54,    76,    77,    78,    79,    59,    81,    -1,    62,
      -1,    -1,    -1,    87,    67,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    77,    -1,    -1,    -1,   102,   103,
     104,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      93,    94,    16,    -1,    -1,    -1,    -1,    10,    -1,   102,
     103,   104,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    46,    47,    48,    49,    -1,    -1,    52,    -1,
      54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    52,
      -1,    -1,    -1,    67,    47,    48,    59,    60,    61,    52,
      -1,    54,    65,    77,    -1,    -1,    59,    -1,    -1,    62,
      -1,    10,    -1,    -1,    67,    -1,    15,    -1,    -1,    93,
      94,    -1,    -1,    -1,    77,    -1,    -1,    -1,   102,   103,
     104,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    10,   102,
     103,   104,    -1,    52,    16,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    10,    -1,    -1,    65,    66,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      10,    -1,    49,    65,    66,    52,    -1,    -1,    -1,    -1,
      10,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    10,    -1,    59,
      60,    61,    52,    -1,    -1,    65,    66,    10,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    10,    59,    60,    61,    52,
      53,    16,    65,    66,    -1,    10,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    10,    -1,    59,    60,    61,    52,    -1,    -1,
      65,    66,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    -1,    65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    47,    48,    52,    54,    59,    62,    67,    74,    76,
      77,    78,    79,    81,    87,    92,    93,    94,    95,    96,
     102,   103,   104,   106,   107,   108,   109,   117,   119,   121,
     123,   124,   161,   162,   163,   164,   165,   166,   167,   170,
      48,   124,   161,   170,   121,    46,    49,   121,   161,   169,
     133,   161,   133,   121,   161,   161,    98,   110,   111,   112,
     121,    75,    94,   123,   163,   161,   161,   161,   123,   132,
       5,    94,   123,   127,   123,   131,     0,     0,    58,     0,
      58,   109,   117,    47,    48,    52,    77,   123,   125,   126,
      10,    15,    30,    31,    32,    33,    34,    35,    52,    59,
      60,    61,    65,    66,    48,    48,    48,    48,   168,   169,
      16,   161,    46,    49,    70,    53,    70,    55,   121,    46,
      15,   121,   126,    48,    48,    50,    58,   116,    80,   116,
      21,    48,    50,    21,    48,   116,   121,   168,   168,    48,
      21,   116,   161,   161,   161,   161,   161,   161,   161,   121,
     163,   161,   161,   161,   161,   169,   169,     7,    18,    35,
      46,    68,   100,   101,   121,   122,   142,   143,   146,   147,
     148,   155,   169,    49,    49,   161,   121,   161,   161,     7,
      48,    52,   123,   163,   165,   167,   171,   169,    46,   121,
     134,   135,   136,   137,   161,   134,    83,    84,    85,    96,
     113,   114,   117,   118,   119,   120,   161,   161,    82,   161,
     142,   121,   128,   129,   130,    48,   142,    49,    53,   142,
     161,    53,    49,    49,    15,   145,   145,   147,   149,   150,
     155,    17,    18,    35,    50,    99,   100,   101,   122,   123,
     156,   157,   158,   160,   122,   144,    35,    46,   145,    49,
      70,    35,   171,   145,   145,    49,    46,    49,   169,   171,
      20,    52,    66,   171,    15,    46,    49,    70,   161,    49,
     161,   123,    58,    58,   117,   120,    51,   116,   116,   116,
      49,    51,    70,   121,   138,   139,   141,    49,    49,    58,
     161,    35,   171,   145,   145,   123,    48,   151,   159,   160,
     161,   156,   156,   156,   159,   151,    35,   158,   145,    46,
     145,   150,   155,    20,    21,    22,   115,   116,   146,    35,
     161,    49,    53,   171,   161,   171,   136,    48,    21,   130,
      21,    46,    49,    70,    21,   116,    20,    22,    35,    15,
      18,    72,   121,   122,   152,   153,   154,   159,   159,    51,
     159,   150,   155,   145,   145,   171,   161,   157,    53,   142,
     161,   161,   171,   141,    48,   171,   157,   156,   153,   122,
     153,    15,   159,    49,    70,    35,   151,   159,   145,   145,
     115,    16,   115,    49,    15,   140,   138,   153,   156,    35,
     154,   159,   161,    49
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   105,   106,   106,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   121,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   127,   128,   128,   129,   129,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   148,   148,
     149,   149,   150,   150,   150,   150,   151,   152,   152,   153,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   155,
     155,   155,   155,   156,   156,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   159,   159,   160,   160,   161,
     161,   161,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   163,   164,   164,
     164,   164,   165,   165,   165,   165,   165,   166,   166,   167,
     167,   167,   168,   168,   169,   169,   169,   169,   170,   170,
     171,   171,   171,   171,   171,   171,   171,   171,   171
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     3,     0,     1,     2,     1,     2,     2,     2,     1,
       3,     3,     3,     5,     5,     3,     5,     3,     5,     3,
       6,     2,     1,     1,     2,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     4,     6,     6,     4,     0,     1,     1,     3,
       1,     5,     8,     3,     6,     1,     3,     0,     1,     1,
       3,     2,     1,     2,     2,     0,     1,     1,     3,     0,
       2,     4,     3,     0,     1,     1,     3,     0,     1,     0,
       2,     5,     4,     3,     2,     3,     2,     2,     3,     2,
       5,     4,     3,     2,     1,     1,     2,     3,     1,     2,
       0,     1,     2,     3,     1,     2,     3,     1,     3,     1,
       2,     2,     3,     2,     3,     2,     3,     1,     2,     2,
       3,     3,     3,     1,     2,     1,     1,     3,     2,     2,
       3,     4,     5,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     3,     3,     4,     2,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     3,     2,     2,
       5,     5,     4,     4,     4,     4,     4,     1,     4,     5,
       7,     7,     0,     1,     1,     3,     3,     5,     2,     1,
       1,     1,     1,     3,     2,     3,     4,     3,     3
  };


#if ANNIUM_LANGDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "COMMENT_BEGIN",
  "COMMENT_END", "STRING", "IDENTIFIER", "CONTEXT_IDENTIFIER",
  "RESERVED_IDENTIFIER", "CT_IDENTIFIER", "INTEGER_INDEX", "INTEGER",
  "DECIMAL", "DECIMAL_S", "OPERATOR_TERM", "\"`=`\"", "\"APOSTROPHE\"",
  "\"`@`\"", "\"`_`\"", "\"`->*`\"", "\"`->`\"", "\"`=>`\"", "\"`~>`\"",
  "\"`.*`\"", "\"`++`\"", "\"`--`\"", "\"`<<`\"", "\"`>>`\"", "\"`<=`\"",
  "\"`>=`\"", "\"`==`\"", "\"`!=`\"", "\"`&&`\"", "\"`||`\"", "\"`..`\"",
  "\"`...`\"", "\"`+=`\"", "\"`-=`\"", "\"`*=`\"", "\"`/=`\"", "\"`%=`\"",
  "\"`<<=`\"", "\"`>>=`\"", "\"`&=`\"", "\"`|=`\"", "\"`^=`\"", "\"`:`\"",
  "\"`::`\"", "\"`(`\"", "\"`)`\"", "\"`{`\"", "\"`}`\"", "\"`[`\"",
  "\"`]`\"", "\"`[[`\"", "\"`]]`\"", "\"`<`\"", "\"`>`\"", "\"`;`\"",
  "\"`.`\"", "\"`+`\"", "\"`-`\"", "\"`*`\"", "\"`/`\"", "\"`%`\"",
  "\"`&`\"", "\"`|`\"", "\"`!`\"", "\"`~`\"", "\"`^`\"", "\",\"",
  "\"`$`\"", "\"`?`\"", "\"`#`\"", "LET", "VAR", "EXTERN", "\"`new`\"",
  "\"`while`\"", "\"`for`\"", "\"`in`\"", "\"`if`\"", "\"`else`\"",
  "\"`continue`\"", "\"`break`\"", "\"`return`\"", "AUTO", "USING",
  "THROW", "SIZEOF", "LOWEST", "DEREF", "INCLUDE", "INLINE", "\"`fn`\"",
  "ENUM", "STRUCT", "EXTENDS", "\"weak modifier\"",
  "\"typename modifier\"", "\"constexpr modifier\"",
  "\"runctime modifier\"", "\"nil\"", "\"true\"", "\"false\"", "$accept",
  "begin", "statement_any", "finished-statement-any", "statement",
  "let-decl", "let-decl-start", "let-decl-start-with-opt-type",
  "infunction-statement-any", "finished-infunction-statement-any",
  "function-body", "braced-statements", "finished-statement",
  "infunction-statement-set", "generic-statement", "infunction-statement",
  "identifier", "internal-identifier", "qname", "fn-start-decl", "fn-name",
  "fn-decl", "enum-decl", "case-list-opt", "case-list", "case-decl",
  "struct-decl", "using-decl", "expression-list", "argument-list-opt",
  "argument-list", "argument", "argument-name", "field-list-opt",
  "field-list", "field-default-value-opt", "field", "parameter-list-opt",
  "parameter-list", "internal-identifier-opt",
  "parameter-default-value-opt", "parameter-decl",
  "constraint-expression-specified-mod", "constraint-expression-specified",
  "constraint-expression-mod", "constraint-expression", "subpatterns",
  "pattern-list", "pattern-field-sfx", "pattern-field", "pattern-mod",
  "pattern-sfx", "pattern", "concept-expression",
  "concept-expression-list-opt", "concept-expression-list",
  "syntax-expression", "syntax-expression-wo-ii", "apostrophe-expression",
  "new-expression", "call-expression", "lambda-start-decl",
  "lambda-expression", "pack-expression-opt", "pack-expression",
  "compound-expression", "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   335,   335,   336,   340,   342,   344,   361,   363,   364,
     366,   371,   373,   375,   388,   390,   395,   397,   402,   404,
     409,   410,   415,   417,   419,   424,   426,   427,   429,   435,
     437,   447,   452,   454,   456,   458,   460,   462,   468,   477,
     479,   481,   486,   488,   493,   495,   497,   499,   504,   506,
     508,   510,   512,   517,   525,   540,   542,   544,   550,   552,
     557,   558,   562,   564,   566,   572,   577,   578,   582,   584,
     589,   595,   597,   620,   627,   645,   647,   653,   654,   658,
     660,   665,   667,   672,   674,   680,   681,   685,   687,   692,
     693,   697,   699,   706,   707,   711,   713,   718,   719,   723,
     724,   728,   730,   732,   734,   737,   739,   741,   743,   745,
     750,   752,   754,   756,   761,   762,   766,   768,   772,   774,
     779,   784,   788,   790,   794,   796,   802,   807,   809,   815,
     817,   820,   822,   826,   829,   835,   838,   851,   854,   859,
     860,   861,   862,   866,   867,   868,   872,   874,   876,   878,
     880,   882,   884,   886,   891,   896,   898,   902,   904,   911,
     913,   915,   920,   922,   924,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   947,   956,   964,   966,   968,   972,
     974,   976,   979,   981,   986,   988,   992,   994,   996,   999,
    1003,  1006,  1009,  1012,  1013,  1014,  1015,  1019,  1024,  1026,
    1028,  1030,  1035,  1037,  1039,  1041,  1043,  1049,  1051,  1056,
    1063,  1071,  1082,  1084,  1089,  1091,  1097,  1102,  1110,  1112,
    1153,  1155,  1156,  1160,  1162,  1164,  1166,  1168,  1170
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
    };
    // Last valid token kind.
    const int code_max = 359;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 5291 "annium.tab.cpp"

#line 1497 "annium.y"

