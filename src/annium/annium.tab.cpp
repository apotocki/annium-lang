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
#line 26 "annium.y"

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
//#include "annium.yy.hpp"

void annium_lang::parser::error(const location_type& loc, const std::string& msg)
{
    ctx.append_error(
        resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource() },
        resource_location{ loc.end.line, loc.end.column, ctx.get_resource() },
        msg);
}

#define IGNORE_TERM(...)


#line 74 "annium.tab.cpp"


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
#line 171 "annium.tab.cpp"

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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.copy< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.copy< generic_statement_type > (YY_MOVE (that.value));
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.copy< parameter_constraint_modifier_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (s.value));
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< parameter_constraint_modifier_t > (YY_MOVE (s.value));
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.YY_MOVE_OR_COPY< generic_statement_type > (YY_MOVE (that.value));
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< parameter_constraint_modifier_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (that.value));
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< parameter_constraint_modifier_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.copy< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.copy< generic_statement_type > (that.value);
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (that.value);
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.copy< parameter_constraint_modifier_t > (that.value);
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        value.move< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        value.move< generic_statement_type > (that.value);
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        value.move< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (that.value);
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        value.move< parameter_constraint_modifier_t > (that.value);
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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
#line 329 "annium.y"
                 { }
#line 1715 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 329 "annium.y"
                 { }
#line 1721 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 329 "annium.y"
                 { }
#line 1727 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 329 "annium.y"
                 { }
#line 1733 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 329 "annium.y"
                 { }
#line 1739 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 329 "annium.y"
                 { }
#line 1745 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 329 "annium.y"
                 { }
#line 1751 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 329 "annium.y"
                 { }
#line 1757 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 329 "annium.y"
                 { }
#line 1763 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 329 "annium.y"
                 { }
#line 1769 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 329 "annium.y"
                 { }
#line 1775 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 329 "annium.y"
                 { }
#line 1781 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 329 "annium.y"
                 { }
#line 1787 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 329 "annium.y"
                 { }
#line 1793 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 329 "annium.y"
                 { }
#line 1799 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 329 "annium.y"
                 { }
#line 1805 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 329 "annium.y"
                 { }
#line 1811 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 329 "annium.y"
                 { }
#line 1817 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 329 "annium.y"
                 { }
#line 1823 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 329 "annium.y"
                 { }
#line 1829 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 329 "annium.y"
                 { }
#line 1835 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 329 "annium.y"
                 { }
#line 1841 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 329 "annium.y"
                 { }
#line 1847 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 329 "annium.y"
                 { }
#line 1853 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 329 "annium.y"
                 { }
#line 1859 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 329 "annium.y"
                 { }
#line 1865 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 329 "annium.y"
                 { }
#line 1871 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 329 "annium.y"
                 { }
#line 1877 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 329 "annium.y"
                 { }
#line 1883 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 329 "annium.y"
                 { }
#line 1889 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 329 "annium.y"
                 { }
#line 1895 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 329 "annium.y"
                 { }
#line 1901 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 329 "annium.y"
                 { }
#line 1907 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 329 "annium.y"
                 { }
#line 1913 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 329 "annium.y"
                 { }
#line 1919 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 329 "annium.y"
                 { }
#line 1925 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 329 "annium.y"
                 { }
#line 1931 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 329 "annium.y"
                 { }
#line 1937 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 329 "annium.y"
                 { }
#line 1943 "annium.tab.cpp"
        break;

      case symbol_kind::S_108_finished_statement_any: // finished-statement-any
#line 329 "annium.y"
                 { }
#line 1949 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 329 "annium.y"
                 { }
#line 1955 "annium.tab.cpp"
        break;

      case symbol_kind::S_110_let_decl: // let-decl
#line 329 "annium.y"
                 { }
#line 1961 "annium.tab.cpp"
        break;

      case symbol_kind::S_111_let_decl_start: // let-decl-start
#line 329 "annium.y"
                 { }
#line 1967 "annium.tab.cpp"
        break;

      case symbol_kind::S_112_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 329 "annium.y"
                 { }
#line 1973 "annium.tab.cpp"
        break;

      case symbol_kind::S_113_infunction_statement_any: // infunction-statement-any
#line 329 "annium.y"
                 { }
#line 1979 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_infunction_statement_any: // finished-infunction-statement-any
#line 329 "annium.y"
                 { }
#line 1985 "annium.tab.cpp"
        break;

      case symbol_kind::S_115_function_body: // function-body
#line 329 "annium.y"
                 { }
#line 1991 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_braced_statements: // braced-statements
#line 329 "annium.y"
                 { }
#line 1997 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_finished_statement: // finished-statement
#line 329 "annium.y"
                 { }
#line 2003 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_infunction_statement_set: // infunction-statement-set
#line 329 "annium.y"
                 { }
#line 2009 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
#line 329 "annium.y"
                 { }
#line 2015 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_infunction_statement: // infunction-statement
#line 329 "annium.y"
                 { }
#line 2021 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 329 "annium.y"
                 { }
#line 2027 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_internal_identifier: // internal-identifier
#line 329 "annium.y"
                 { }
#line 2033 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 329 "annium.y"
                 { }
#line 2039 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
#line 329 "annium.y"
                 { }
#line 2045 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_fn_name: // fn-name
#line 329 "annium.y"
                 { }
#line 2051 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
#line 329 "annium.y"
                 { }
#line 2057 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_enum_decl: // enum-decl
#line 329 "annium.y"
                 { }
#line 2063 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_case_list_opt: // case-list-opt
#line 329 "annium.y"
                 { }
#line 2069 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_case_list: // case-list
#line 329 "annium.y"
                 { }
#line 2075 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_case_decl: // case-decl
#line 329 "annium.y"
                 { }
#line 2081 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_struct_decl: // struct-decl
#line 329 "annium.y"
                 { }
#line 2087 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_using_decl: // using-decl
#line 329 "annium.y"
                 { }
#line 2093 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_expression_list: // expression-list
#line 329 "annium.y"
                 { }
#line 2099 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_argument_list_opt: // argument-list-opt
#line 329 "annium.y"
                 { }
#line 2105 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_argument_list: // argument-list
#line 329 "annium.y"
                 { }
#line 2111 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 329 "annium.y"
                 { }
#line 2117 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_argument_name: // argument-name
#line 329 "annium.y"
                 { }
#line 2123 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_field_list_opt: // field-list-opt
#line 329 "annium.y"
                 { }
#line 2129 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_field_list: // field-list
#line 329 "annium.y"
                 { }
#line 2135 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_field_default_value_opt: // field-default-value-opt
#line 329 "annium.y"
                 { }
#line 2141 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 329 "annium.y"
                 { }
#line 2147 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_parameter_list_opt: // parameter-list-opt
#line 329 "annium.y"
                 { }
#line 2153 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_parameter_list: // parameter-list
#line 329 "annium.y"
                 { }
#line 2159 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_internal_identifier_opt: // internal-identifier-opt
#line 329 "annium.y"
                 { }
#line 2165 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_parameter_default_value_opt: // parameter-default-value-opt
#line 329 "annium.y"
                 { }
#line 2171 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_parameter_decl: // parameter-decl
#line 329 "annium.y"
                 { }
#line 2177 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 329 "annium.y"
                 { }
#line 2183 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_constraint_expression_specified: // constraint-expression-specified
#line 329 "annium.y"
                 { }
#line 2189 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
#line 329 "annium.y"
                 { }
#line 2195 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_constraint_expression: // constraint-expression
#line 329 "annium.y"
                 { }
#line 2201 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 329 "annium.y"
                 { }
#line 2207 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_pattern_list: // pattern-list
#line 329 "annium.y"
                 { }
#line 2213 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_pattern_field_sfx: // pattern-field-sfx
#line 329 "annium.y"
                 { }
#line 2219 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_pattern_field: // pattern-field
#line 329 "annium.y"
                 { }
#line 2225 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_pattern_mod: // pattern-mod
#line 329 "annium.y"
                 { }
#line 2231 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_pattern_sfx: // pattern-sfx
#line 329 "annium.y"
                 { }
#line 2237 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 329 "annium.y"
                 { }
#line 2243 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_concept_expression: // concept-expression
#line 329 "annium.y"
                 { }
#line 2249 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_concept_expression_list_opt: // concept-expression-list-opt
#line 329 "annium.y"
                 { }
#line 2255 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_concept_expression_list: // concept-expression-list
#line 329 "annium.y"
                 { }
#line 2261 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_syntax_expression: // syntax-expression
#line 329 "annium.y"
                 { }
#line 2267 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_syntax_expression_wo_ii: // syntax-expression-wo-ii
#line 329 "annium.y"
                 { }
#line 2273 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_apostrophe_expression: // apostrophe-expression
#line 329 "annium.y"
                 { }
#line 2279 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_new_expression: // new-expression
#line 329 "annium.y"
                 { }
#line 2285 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_call_expression: // call-expression
#line 329 "annium.y"
                 { }
#line 2291 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_lambda_expression: // lambda-expression
#line 329 "annium.y"
                 { }
#line 2297 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
#line 329 "annium.y"
                 { }
#line 2303 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pack_expression: // pack-expression
#line 329 "annium.y"
                 { }
#line 2309 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_compound_expression: // compound-expression
#line 329 "annium.y"
                 { }
#line 2315 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_type_expr: // type-expr
#line 329 "annium.y"
                 { }
#line 2321 "annium.tab.cpp"
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

      case symbol_kind::S_124_fn_start_decl: // fn-start-decl
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_126_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure_t > ();
        break;

      case symbol_kind::S_119_generic_statement: // generic-statement
        yylhs.value.emplace< generic_statement_type > ();
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
      case symbol_kind::S_167_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_168_pack_expression: // pack-expression
        yylhs.value.emplace< named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< named_expression_t > ();
        break;

      case symbol_kind::S_147_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_149_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< parameter_constraint_modifier_t > ();
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
      case symbol_kind::S_166_lambda_expression: // lambda-expression
      case symbol_kind::S_169_compound_expression: // compound-expression
      case symbol_kind::S_170_type_expr: // type-expr
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
#line 334 "annium.y"
                            { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2789 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 335 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2795 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 340 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 2801 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 342 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 2807 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 344 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2813 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 361 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 2819 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 362 "annium.y"
                                                { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2825 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 364 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2831 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 366 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2837 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 371 "annium.y"
        { yylhs.value.as < statement > () = extern_var{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 2843 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 373 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < fn_pure_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 2849 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 375 "annium.y"
        { yylhs.value.as < statement > () = include_decl{ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 2855 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 388 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 2861 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 390 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < struct_decl > ()); }
#line 2867 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 395 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 2873 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 397 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = std::move(yystack_[0].value.as < named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 2879 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 402 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = false }; }
#line 2885 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 404 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = true }; }
#line 2891 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 408 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 2897 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 410 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 2903 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 415 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 2909 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 417 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 2915 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 419 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2921 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 424 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 2927 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 425 "annium.y"
                                                           { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2933 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 427 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2939 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 429 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2945 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 435 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 2951 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression "APOSTROPHE"
#line 437 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ yystack_[1].value.as < syntax_expression_t > (), std::move(loc) });
            yylhs.value.as < managed_statement_list > () = std::move(sts);
        }
#line 2962 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 447 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 2968 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 452 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 2974 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 454 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; }
#line 2980 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" syntax-expression "`in`" syntax-expression braced-statements
#line 456 "annium.y"
        { yylhs.value.as < finished_statement_type > () = for_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 2986 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 458 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 2992 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 460 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[2].value.as < managed_statement_list > ())), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 2998 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-start-decl fn-decl braced-statements
#line 462 "annium.y"
        { yystack_[1].value.as < fn_pure_t > ().kind = yystack_[2].value.as < fn_kind > (); yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[1].value.as < fn_pure_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3004 "annium.tab.cpp"
    break;

  case 38: // finished-statement: fn-start-decl fn-decl "`=>`" syntax-expression "`;`"
#line 464 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(loc) });
            yystack_[3].value.as < fn_pure_t > ().kind = yystack_[4].value.as < fn_kind > ();
            yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[3].value.as < fn_pure_t > ()), ctx.push(std::move(sts)) };
        }
#line 3016 "annium.tab.cpp"
    break;

  case 39: // finished-statement: STRUCT qname braced-statements
#line 472 "annium.y"
        { yylhs.value.as < finished_statement_type > () = struct_decl{ .name = std::move(yystack_[1].value.as < annium::annotated_qname > ()), .body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3022 "annium.tab.cpp"
    break;

  case 40: // finished-statement: STRUCT qname "`(`" parameter-list-opt "`)`" braced-statements
#line 474 "annium.y"
        { yylhs.value.as < finished_statement_type > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[2].value.as < parameter_list_t > ()), .body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3028 "annium.tab.cpp"
    break;

  case 41: // finished-statement: ENUM enum-decl
#line 476 "annium.y"
        { yylhs.value.as < finished_statement_type > () = std::move(yystack_[0].value.as < enum_decl > ()); }
#line 3034 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: infunction-statement-any
#line 481 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3040 "annium.tab.cpp"
    break;

  case 43: // infunction-statement-set: finished-infunction-statement-any
#line 483 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3046 "annium.tab.cpp"
    break;

  case 44: // generic-statement: LET let-decl
#line 488 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3052 "annium.tab.cpp"
    break;

  case 45: // generic-statement: USING using-decl
#line 490 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < using_decl > ()); }
#line 3058 "annium.tab.cpp"
    break;

  case 46: // generic-statement: compound-expression
#line 492 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3064 "annium.tab.cpp"
    break;

  case 47: // generic-statement: syntax-expression "`=`" syntax-expression
#line 494 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ binary_expression_t{ binary_operator_type::ASSIGN, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) } }; }
#line 3070 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: generic-statement
#line 499 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3076 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`break`"
#line 501 "annium.y"
        { yylhs.value.as < statement > () = break_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3082 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`continue`"
#line 503 "annium.y"
        { yylhs.value.as < statement > () = continue_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3088 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`"
#line 505 "annium.y"
        { yylhs.value.as < statement > () = return_decl_t{ .location = std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3094 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`return`" syntax-expression
#line 507 "annium.y"
        { yylhs.value.as < statement > () = return_decl_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3100 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 512 "annium.y"
      { yylhs.value.as < annium::annotated_identifier > () = ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3106 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 520 "annium.y"
        { yylhs.value.as < annium::context_identifier > () = context_identifier { ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()) }; }
#line 3112 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 535 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3118 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 537 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3124 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 539 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = std::move(yystack_[2].value.as < annium::annotated_qname > ()); yylhs.value.as < annium::annotated_qname > ().value.append(std::move(yystack_[0].value.as < annium::annotated_identifier > ().value)); }
#line 3130 "annium.tab.cpp"
    break;

  case 58: // fn-start-decl: "`fn`"
#line 545 "annium.y"
        { yylhs.value.as < fn_kind > () = fn_kind::DEFAULT; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3136 "annium.tab.cpp"
    break;

  case 59: // fn-start-decl: INLINE "`fn`"
#line 547 "annium.y"
        { yylhs.value.as < fn_kind > () = fn_kind::INLINE; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3142 "annium.tab.cpp"
    break;

  case 60: // fn-name: qname
#line 551 "annium.y"
      { yylhs.value.as < annium::annotated_qname > () = yystack_[0].value.as < annium::annotated_qname > (); }
#line 3148 "annium.tab.cpp"
    break;

  case 61: // fn-name: "`new`"
#line 552 "annium.y"
          { yylhs.value.as < annium::annotated_qname > () = ctx.make_qname(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }); }
#line 3154 "annium.tab.cpp"
    break;

  case 62: // fn-decl: fn-name "`(`" parameter-list-opt "`)`"
#line 557 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[3].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[3].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[1].value.as < parameter_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3160 "annium.tab.cpp"
    break;

  case 63: // fn-decl: fn-name "`(`" parameter-list-opt "`)`" "`->`" type-expr
#line 559 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = std::move(yystack_[0].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3166 "annium.tab.cpp"
    break;

  case 64: // fn-decl: fn-name "`(`" parameter-list-opt "`)`" "`~>`" pattern
#line 561 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = std::move(yystack_[0].value.as < pattern_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3172 "annium.tab.cpp"
    break;

  case 65: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 567 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ std::move(yystack_[3].value.as < annium::annotated_qname > ()), std::move(yystack_[1].value.as < std::vector<annium::identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3178 "annium.tab.cpp"
    break;

  case 66: // case-list-opt: %empty
#line 571 "annium.y"
             { yylhs.value.as < std::vector<annium::identifier> > () = {}; }
#line 3184 "annium.tab.cpp"
    break;

  case 67: // case-list-opt: case-list
#line 572 "annium.y"
      { yylhs.value.as < std::vector<annium::identifier> > () = yystack_[0].value.as < std::vector<annium::identifier> > (); }
#line 3190 "annium.tab.cpp"
    break;

  case 68: // case-list: case-decl
#line 577 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::vector<annium::identifier>{std::move(yystack_[0].value.as < annium::identifier > ())}; }
#line 3196 "annium.tab.cpp"
    break;

  case 69: // case-list: case-list "," case-decl
#line 579 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::move(yystack_[2].value.as < std::vector<annium::identifier> > ()); yylhs.value.as < std::vector<annium::identifier> > ().emplace_back(std::move(yystack_[0].value.as < annium::identifier > ())); }
#line 3202 "annium.tab.cpp"
    break;

  case 70: // case-decl: identifier
#line 584 "annium.y"
        { yylhs.value.as < annium::identifier > () = yystack_[0].value.as < annium::annotated_identifier > ().value; }
#line 3208 "annium.tab.cpp"
    break;

  case 71: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 590 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3214 "annium.tab.cpp"
    break;

  case 72: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 592 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[7].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[5].value.as < parameter_list_t > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[6].value.as < sonia::lang::lex::resource_location > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3220 "annium.tab.cpp"
    break;

  case 73: // using-decl: qname "`=>`" syntax-expression
#line 615 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[2].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[2].value.as < annium::annotated_qname > ().location), .result = nullptr }, ctx.push(std::move(sts)) } };
        }
#line 3231 "annium.tab.cpp"
    break;

  case 74: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 622 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_decl_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.push(std::move(sts)) } };
            IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ());
        }
#line 3243 "annium.tab.cpp"
    break;

  case 75: // expression-list: syntax-expression
#line 640 "annium.y"
        { yylhs.value.as < expression_list_t > () = expression_list_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3249 "annium.tab.cpp"
    break;

  case 76: // expression-list: expression-list "," syntax-expression
#line 642 "annium.y"
        { yylhs.value.as < expression_list_t > () = std::move(yystack_[2].value.as < expression_list_t > ()); yylhs.value.as < expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3255 "annium.tab.cpp"
    break;

  case 77: // argument-list-opt: %empty
#line 647 "annium.y"
              { yylhs.value.as < named_expression_list_t > () = {}; }
#line 3261 "annium.tab.cpp"
    break;

  case 78: // argument-list-opt: argument-list
#line 648 "annium.y"
      { yylhs.value.as < named_expression_list_t > () = yystack_[0].value.as < named_expression_list_t > (); }
#line 3267 "annium.tab.cpp"
    break;

  case 79: // argument-list: argument
#line 653 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{std::move(yystack_[0].value.as < named_expression_t > ())}; }
#line 3273 "annium.tab.cpp"
    break;

  case 80: // argument-list: argument-list "," argument
#line 655 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ()); yylhs.value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < named_expression_t > ())); }
#line 3279 "annium.tab.cpp"
    break;

  case 81: // argument: argument-name syntax-expression
#line 660 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[1].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3285 "annium.tab.cpp"
    break;

  case 82: // argument: syntax-expression
#line 662 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3291 "annium.tab.cpp"
    break;

  case 83: // argument-name: identifier "`=`"
#line 667 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3297 "annium.tab.cpp"
    break;

  case 84: // argument-name: identifier "`:`"
#line 669 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3303 "annium.tab.cpp"
    break;

  case 85: // field-list-opt: %empty
#line 674 "annium.y"
              { yylhs.value.as < field_list_t > () = {}; }
#line 3309 "annium.tab.cpp"
    break;

  case 86: // field-list-opt: field-list
#line 675 "annium.y"
      { yylhs.value.as < field_list_t > () = yystack_[0].value.as < field_list_t > (); }
#line 3315 "annium.tab.cpp"
    break;

  case 87: // field-list: field
#line 680 "annium.y"
        { yylhs.value.as < field_list_t > () = field_list_t{std::move(yystack_[0].value.as < field_t > ())}; }
#line 3321 "annium.tab.cpp"
    break;

  case 88: // field-list: field-list "," field
#line 682 "annium.y"
        { yylhs.value.as < field_list_t > () = std::move(yystack_[2].value.as < field_list_t > ()); yylhs.value.as < field_list_t > ().emplace_back(std::move(yystack_[0].value.as < field_t > ())); }
#line 3327 "annium.tab.cpp"
    break;

  case 89: // field-default-value-opt: %empty
#line 686 "annium.y"
             { yylhs.value.as < sonia::optional<syntax_expression_t> > () = nullopt; }
#line 3333 "annium.tab.cpp"
    break;

  case 90: // field-default-value-opt: "`=`" syntax-expression
#line 687 "annium.y"
                                      { yylhs.value.as < sonia::optional<syntax_expression_t> > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3339 "annium.tab.cpp"
    break;

  case 91: // field: identifier "`:`" type-expr field-default-value-opt
#line 692 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ std::move(yystack_[3].value.as < annium::annotated_identifier > ()), parameter_constraint_modifier_t::runtime_type, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()) }; }
#line 3345 "annium.tab.cpp"
    break;

  case 92: // field: identifier "`=>`" syntax-expression
#line 694 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), parameter_constraint_modifier_t::any_constexpr_type, std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3351 "annium.tab.cpp"
    break;

  case 93: // parameter-list-opt: %empty
#line 700 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3357 "annium.tab.cpp"
    break;

  case 94: // parameter-list-opt: parameter-list
#line 701 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3363 "annium.tab.cpp"
    break;

  case 95: // parameter-list: parameter-decl
#line 706 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ parameter_t{std::move(yystack_[0].value.as < parameter_t > ())} }; }
#line 3369 "annium.tab.cpp"
    break;

  case 96: // parameter-list: parameter-list "," parameter-decl
#line 708 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter_t > ())); }
#line 3375 "annium.tab.cpp"
    break;

  case 97: // internal-identifier-opt: %empty
#line 712 "annium.y"
             { yylhs.value.as < annium::context_identifier > () = context_identifier{}; }
#line 3381 "annium.tab.cpp"
    break;

  case 98: // internal-identifier-opt: internal-identifier
#line 713 "annium.y"
                                 { yylhs.value.as < annium::context_identifier > () = std::move(yystack_[0].value.as < annium::context_identifier > ()); }
#line 3387 "annium.tab.cpp"
    break;

  case 99: // parameter-default-value-opt: %empty
#line 717 "annium.y"
             { yylhs.value.as < sonia::optional<syntax_expression_t> > () = nullopt; }
#line 3393 "annium.tab.cpp"
    break;

  case 100: // parameter-default-value-opt: "`=`" syntax-expression
#line 718 "annium.y"
                                      { yylhs.value.as < sonia::optional<syntax_expression_t> > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3399 "annium.tab.cpp"
    break;

  case 101: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 723 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3405 "annium.tab.cpp"
    break;

  case 102: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 725 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3411 "annium.tab.cpp"
    break;

  case 103: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 727 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3417 "annium.tab.cpp"
    break;

  case 104: // parameter-decl: pattern-mod parameter-default-value-opt
#line 729 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3423 "annium.tab.cpp"
    break;

  case 105: // parameter-decl: identifier internal-identifier parameter-default-value-opt
#line 732 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3429 "annium.tab.cpp"
    break;

  case 106: // parameter-decl: internal-identifier parameter-default-value-opt
#line 734 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3435 "annium.tab.cpp"
    break;

  case 107: // parameter-decl: "`_`" parameter-default-value-opt
#line 736 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3441 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 738 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3447 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: "`...`" parameter-default-value-opt
#line 740 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3453 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 745 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3459 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 747 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3465 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 749 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3471 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 751 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < sonia::optional<syntax_expression_t> > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3477 "annium.tab.cpp"
    break;

  case 114: // constraint-expression-specified-mod: "constexpr modifier"
#line 755 "annium.y"
                { yylhs.value.as < parameter_constraint_modifier_t > () = parameter_constraint_modifier_t::any_constexpr_type; }
#line 3483 "annium.tab.cpp"
    break;

  case 115: // constraint-expression-specified-mod: "runctime modifier"
#line 756 "annium.y"
              { yylhs.value.as < parameter_constraint_modifier_t > () = parameter_constraint_modifier_t::runtime_type; }
#line 3489 "annium.tab.cpp"
    break;

  case 116: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 761 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), yystack_[1].value.as < parameter_constraint_modifier_t > () }; }
#line 3495 "annium.tab.cpp"
    break;

  case 117: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 763 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), yystack_[2].value.as < parameter_constraint_modifier_t > () | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3501 "annium.tab.cpp"
    break;

  case 118: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 765 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, yystack_[1].value.as < parameter_constraint_modifier_t > () | parameter_constraint_modifier_t::ellipsis }; }
#line 3507 "annium.tab.cpp"
    break;

  case 119: // constraint-expression-mod: %empty
#line 769 "annium.y"
             { yylhs.value.as < parameter_constraint_modifier_t > () = parameter_constraint_modifier_t::const_or_runtime_type; }
#line 3513 "annium.tab.cpp"
    break;

  case 120: // constraint-expression-mod: constraint-expression-specified-mod
#line 770 "annium.y"
      { yylhs.value.as < parameter_constraint_modifier_t > () = yystack_[0].value.as < parameter_constraint_modifier_t > (); }
#line 3519 "annium.tab.cpp"
    break;

  case 121: // constraint-expression: constraint-expression-mod type-expr
#line 775 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), yystack_[1].value.as < parameter_constraint_modifier_t > () }; }
#line 3525 "annium.tab.cpp"
    break;

  case 122: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 777 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), yystack_[2].value.as < parameter_constraint_modifier_t > () | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3531 "annium.tab.cpp"
    break;

  case 123: // constraint-expression: constraint-expression-mod "`...`"
#line 779 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, yystack_[1].value.as < parameter_constraint_modifier_t > () | parameter_constraint_modifier_t::ellipsis }; }
#line 3537 "annium.tab.cpp"
    break;

  case 124: // subpatterns: "`(`" pattern-list "`)`"
#line 785 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[1].value.as < pattern_list_t > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3543 "annium.tab.cpp"
    break;

  case 125: // pattern-list: pattern-field
#line 790 "annium.y"
        { yylhs.value.as < pattern_list_t > () = pattern_list_t{ std::move(yystack_[0].value.as < pattern_t::field > ()) }; }
#line 3549 "annium.tab.cpp"
    break;

  case 126: // pattern-list: pattern-list "," pattern-field
#line 792 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[2].value.as < pattern_list_t > ()); yylhs.value.as < pattern_list_t > ().emplace_back(std::move(yystack_[0].value.as < pattern_t::field > ())); }
#line 3555 "annium.tab.cpp"
    break;

  case 127: // pattern-field-sfx: concept-expression-list-opt
#line 798 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3561 "annium.tab.cpp"
    break;

  case 128: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 800 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3567 "annium.tab.cpp"
    break;

  case 129: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 803 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3573 "annium.tab.cpp"
    break;

  case 130: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 805 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3579 "annium.tab.cpp"
    break;

  case 131: // pattern-field-sfx: "`=`" pattern-sfx
#line 809 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3585 "annium.tab.cpp"
    break;

  case 132: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 812 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3591 "annium.tab.cpp"
    break;

  case 133: // pattern-field: identifier pattern-field-sfx
#line 818 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3597 "annium.tab.cpp"
    break;

  case 134: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 821 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3603 "annium.tab.cpp"
    break;

  case 135: // pattern-field: pattern-field-sfx
#line 834 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ }; }
#line 3609 "annium.tab.cpp"
    break;

  case 136: // pattern-field: "`_`" pattern-field-sfx
#line 837 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3615 "annium.tab.cpp"
    break;

  case 137: // pattern-mod: "`~`" pattern-sfx
#line 841 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3621 "annium.tab.cpp"
    break;

  case 138: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 842 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; }
#line 3627 "annium.tab.cpp"
    break;

  case 139: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 843 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; }
#line 3633 "annium.tab.cpp"
    break;

  case 140: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 844 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; }
#line 3639 "annium.tab.cpp"
    break;

  case 141: // pattern-sfx: pattern
#line 848 "annium.y"
              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < pattern_t > ()), parameter_constraint_modifier_t::none }; }
#line 3645 "annium.tab.cpp"
    break;

  case 142: // pattern-sfx: pattern "`...`"
#line 849 "annium.y"
                       { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < pattern_t > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3651 "annium.tab.cpp"
    break;

  case 143: // pattern-sfx: "`...`"
#line 850 "annium.y"
               { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3657 "annium.tab.cpp"
    break;

  case 144: // pattern: qname
#line 855 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3663 "annium.tab.cpp"
    break;

  case 145: // pattern: qname subpatterns concept-expression-list-opt
#line 857 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[2].value.as < annium::annotated_qname > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3669 "annium.tab.cpp"
    break;

  case 146: // pattern: internal-identifier concept-expression-list-opt
#line 859 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[1].value.as < annium::context_identifier > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3675 "annium.tab.cpp"
    break;

  case 147: // pattern: "`_`" concept-expression-list-opt
#line 861 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3681 "annium.tab.cpp"
    break;

  case 148: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 863 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }, .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3687 "annium.tab.cpp"
    break;

  case 149: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 865 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[2].value.as < syntax_expression_t > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3693 "annium.tab.cpp"
    break;

  case 150: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 867 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[3].value.as < syntax_expression_t > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3699 "annium.tab.cpp"
    break;

  case 151: // pattern: concept-expression-list
#line 869 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{}, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3705 "annium.tab.cpp"
    break;

  case 152: // concept-expression: "`@`" qname
#line 874 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = syntax_expression_t{ variable_reference{std::move(yystack_[0].value.as < annium::annotated_qname > ()), false} }; }
#line 3711 "annium.tab.cpp"
    break;

  case 153: // concept-expression-list-opt: %empty
#line 879 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = {}; }
#line 3717 "annium.tab.cpp"
    break;

  case 154: // concept-expression-list-opt: concept-expression-list
#line 880 "annium.y"
      { yylhs.value.as < concept_expression_list_t > () = yystack_[0].value.as < concept_expression_list_t > (); }
#line 3723 "annium.tab.cpp"
    break;

  case 155: // concept-expression-list: concept-expression
#line 885 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = concept_expression_list_t{std::move(yystack_[0].value.as < syntax_expression_t > ())}; }
#line 3729 "annium.tab.cpp"
    break;

  case 156: // concept-expression-list: concept-expression-list concept-expression
#line 887 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = std::move(yystack_[1].value.as < concept_expression_list_t > ()); yylhs.value.as < concept_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3735 "annium.tab.cpp"
    break;

  case 157: // syntax-expression: CONTEXT_IDENTIFIER
#line 895 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ ctx.make_qname(std::move(yystack_[0].value.as < annium::annotated_string_view > ())), true }; }
#line 3741 "annium.tab.cpp"
    break;

  case 158: // syntax-expression: CT_IDENTIFIER
#line 897 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ ctx.make_qname(std::move(yystack_[0].value.as < annium::annotated_string_view > ())), true }; }
#line 3747 "annium.tab.cpp"
    break;

  case 159: // syntax-expression: syntax-expression-wo-ii
#line 898 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3753 "annium.tab.cpp"
    break;

  case 160: // syntax-expression-wo-ii: "nil"
#line 904 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_nil > ()); }
#line 3759 "annium.tab.cpp"
    break;

  case 161: // syntax-expression-wo-ii: "true"
#line 906 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3765 "annium.tab.cpp"
    break;

  case 162: // syntax-expression-wo-ii: "false"
#line 908 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3771 "annium.tab.cpp"
    break;

  case 163: // syntax-expression-wo-ii: INTEGER
#line 910 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_integer > ()); }
#line 3777 "annium.tab.cpp"
    break;

  case 164: // syntax-expression-wo-ii: DECIMAL
#line 912 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3783 "annium.tab.cpp"
    break;

  case 165: // syntax-expression-wo-ii: DECIMAL_S
#line 914 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3789 "annium.tab.cpp"
    break;

  case 166: // syntax-expression-wo-ii: INTEGER_INDEX
#line 916 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annotated_decimal{ ctx.make_decimal(yystack_[0].value.as < annium::annotated_string_view > ().value), yystack_[0].value.as < annium::annotated_string_view > ().location }; }
#line 3795 "annium.tab.cpp"
    break;

  case 167: // syntax-expression-wo-ii: STRING
#line 918 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3801 "annium.tab.cpp"
    break;

  case 168: // syntax-expression-wo-ii: RESERVED_IDENTIFIER
#line 920 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ ctx.make_qname(std::move(yystack_[0].value.as < annium::annotated_string_view > ())), true }; }
#line 3807 "annium.tab.cpp"
    break;

  case 169: // syntax-expression-wo-ii: qname
#line 922 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 3813 "annium.tab.cpp"
    break;

  case 170: // syntax-expression-wo-ii: "`(`" "`)`"
#line 924 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 3819 "annium.tab.cpp"
    break;

  case 171: // syntax-expression-wo-ii: "`(`" "`:`" syntax-expression "`)`"
#line 926 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[3].value.as < sonia::lang::lex::resource_location > ()), annotated_qname{}, named_expression_list_t{ named_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()) } } }; }
#line 3825 "annium.tab.cpp"
    break;

  case 172: // syntax-expression-wo-ii: "`(`" pack-expression "`)`"
#line 928 "annium.y"
        {
            if (yystack_[1].value.as < named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), annotated_qname{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) };
            }
        }
#line 3838 "annium.tab.cpp"
    break;

  case 173: // syntax-expression-wo-ii: "`[`" expression-list "`]`"
#line 937 "annium.y"
        { 
            if (yystack_[1].value.as < expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression_t > () = annium_vector_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > ().front()) };
            } else {
                yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )};
            }
        }
#line 3850 "annium.tab.cpp"
    break;

  case 174: // syntax-expression-wo-ii: "`[[`" expression-list "`]]`"
#line 945 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )}; }
#line 3856 "annium.tab.cpp"
    break;

  case 175: // syntax-expression-wo-ii: syntax-expression "`[`" syntax-expression "`]`"
#line 947 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3862 "annium.tab.cpp"
    break;

  case 176: // syntax-expression-wo-ii: "`.`" identifier
#line 949 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3868 "annium.tab.cpp"
    break;

  case 177: // syntax-expression-wo-ii: syntax-expression "`.`" identifier
#line 953 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < annium::annotated_identifier > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3874 "annium.tab.cpp"
    break;

  case 178: // syntax-expression-wo-ii: syntax-expression "`.`" apostrophe-expression
#line 955 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3880 "annium.tab.cpp"
    break;

  case 179: // syntax-expression-wo-ii: syntax-expression INTEGER_INDEX
#line 957 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), annotated_integer{ ctx.make_integer(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1)), yystack_[0].value.as < annium::annotated_string_view > ().location } }; IGNORE_TERM(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3886 "annium.tab.cpp"
    break;

  case 180: // syntax-expression-wo-ii: "`!`" syntax-expression
#line 960 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::NEGATE, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3892 "annium.tab.cpp"
    break;

  case 181: // syntax-expression-wo-ii: "`*`" syntax-expression
#line 962 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::DEREF, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3898 "annium.tab.cpp"
    break;

  case 182: // syntax-expression-wo-ii: syntax-expression "`+`" syntax-expression
#line 967 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::PLUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3904 "annium.tab.cpp"
    break;

  case 183: // syntax-expression-wo-ii: syntax-expression "`-`" syntax-expression
#line 969 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::MINUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3910 "annium.tab.cpp"
    break;

  case 184: // syntax-expression-wo-ii: syntax-expression "`==`" syntax-expression
#line 973 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::EQ, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3916 "annium.tab.cpp"
    break;

  case 185: // syntax-expression-wo-ii: syntax-expression "`!=`" syntax-expression
#line 975 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::NE, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3922 "annium.tab.cpp"
    break;

  case 186: // syntax-expression-wo-ii: syntax-expression "`..`" syntax-expression
#line 977 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::CONCAT, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3928 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-wo-ii: syntax-expression "`&`" syntax-expression
#line 980 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3934 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-wo-ii: syntax-expression "`|`" syntax-expression
#line 984 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3940 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-wo-ii: syntax-expression "`&&`" syntax-expression
#line 987 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3946 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-wo-ii: syntax-expression "`||`" syntax-expression
#line 990 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3952 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-wo-ii: apostrophe-expression
#line 992 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3958 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-wo-ii: new-expression
#line 993 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3964 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-wo-ii: compound-expression
#line 994 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3970 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-wo-ii: lambda-expression
#line 995 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 3976 "annium.tab.cpp"
    break;

  case 195: // apostrophe-expression: "APOSTROPHE" syntax-expression "APOSTROPHE"
#line 1000 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < syntax_expression_t > ()); }
#line 3982 "annium.tab.cpp"
    break;

  case 196: // new-expression: "`new`" qname
#line 1005 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), variable_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3988 "annium.tab.cpp"
    break;

  case 197: // new-expression: "`new`" apostrophe-expression
#line 1007 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3994 "annium.tab.cpp"
    break;

  case 198: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1009 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), variable_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4000 "annium.tab.cpp"
    break;

  case 199: // new-expression: "`new`" apostrophe-expression "`(`" argument-list-opt "`)`"
#line 1011 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4006 "annium.tab.cpp"
    break;

  case 200: // call-expression: qname "`(`" pack-expression-opt "`)`"
#line 1016 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < annium::annotated_qname > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4012 "annium.tab.cpp"
    break;

  case 201: // call-expression: CONTEXT_IDENTIFIER "`(`" pack-expression-opt "`)`"
#line 1018 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), variable_reference{ ctx.make_qname(std::move(yystack_[3].value.as < annium::annotated_string_view > ())), true }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4018 "annium.tab.cpp"
    break;

  case 202: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1026 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4024 "annium.tab.cpp"
    break;

  case 203: // call-expression: apostrophe-expression "`(`" pack-expression "`)`"
#line 1028 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4030 "annium.tab.cpp"
    break;

  case 204: // call-expression: lambda-expression "`(`" pack-expression "`)`"
#line 1030 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4036 "annium.tab.cpp"
    break;

  case 205: // lambda-expression: fn-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1035 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = lambda_t{ fn_pure_t{ .location = std::move(yystack_[3].value.as < sonia::lang::lex::resource_location > ()), .parameters = std::move(yystack_[2].value.as < parameter_list_t > ()), .result = nullptr, .kind = yystack_[4].value.as < fn_kind > () }, ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 4042 "annium.tab.cpp"
    break;

  case 206: // lambda-expression: fn-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1037 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = lambda_t{ fn_pure_t{ .location = std::move(yystack_[5].value.as < sonia::lang::lex::resource_location > ()), .parameters = std::move(yystack_[4].value.as < parameter_list_t > ()), .result = std::move(yystack_[1].value.as < syntax_expression_t > ()), .kind = yystack_[6].value.as < fn_kind > () }, ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 4048 "annium.tab.cpp"
    break;

  case 207: // lambda-expression: fn-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1039 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = lambda_t{ fn_pure_t{ .location = std::move(yystack_[5].value.as < sonia::lang::lex::resource_location > ()), .parameters = std::move(yystack_[4].value.as < parameter_list_t > ()), .result = std::move(yystack_[1].value.as < pattern_t > ()), .kind = yystack_[6].value.as < fn_kind > () }, ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 4054 "annium.tab.cpp"
    break;

  case 208: // pack-expression-opt: %empty
#line 1044 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{}; }
#line 4060 "annium.tab.cpp"
    break;

  case 209: // pack-expression-opt: pack-expression
#line 1046 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[0].value.as < named_expression_list_t > ()); }
#line 4066 "annium.tab.cpp"
    break;

  case 210: // pack-expression: syntax-expression
#line 1051 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{ named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) } }; }
#line 4072 "annium.tab.cpp"
    break;

  case 211: // pack-expression: identifier "`:`" syntax-expression
#line 1060 "annium.y"
        {
            named_expression_list_t list{};
            list.emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(list);
        }
#line 4082 "annium.tab.cpp"
    break;

  case 212: // pack-expression: pack-expression "," syntax-expression
#line 1066 "annium.y"
        {
            yystack_[2].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ());
        }
#line 4091 "annium.tab.cpp"
    break;

  case 213: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1071 "annium.y"
        {
            yystack_[4].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[4].value.as < named_expression_list_t > ());
        }
#line 4100 "annium.tab.cpp"
    break;

  case 214: // compound-expression: syntax-expression "`...`"
#line 1079 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::ELLIPSIS, false, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4106 "annium.tab.cpp"
    break;

  case 215: // compound-expression: call-expression
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4112 "annium.tab.cpp"
    break;

  case 216: // type-expr: qname
#line 1122 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4118 "annium.tab.cpp"
    break;

  case 217: // type-expr: call-expression
#line 1123 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4124 "annium.tab.cpp"
    break;

  case 218: // type-expr: CONTEXT_IDENTIFIER
#line 1125 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = variable_reference{ ctx.make_qname(std::move(yystack_[0].value.as < annium::annotated_string_view > ())), true }; }
#line 4130 "annium.tab.cpp"
    break;

  case 219: // type-expr: "`[`" type-expr "`]`"
#line 1129 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annium_vector_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < syntax_expression_t > ())}; }
#line 4136 "annium.tab.cpp"
    break;

  case 220: // type-expr: "`(`" "`)`"
#line 1131 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4142 "annium.tab.cpp"
    break;

  case 221: // type-expr: "`(`" pack-expression "`)`"
#line 1134 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), annotated_qname{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4148 "annium.tab.cpp"
    break;

  case 222: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1136 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4154 "annium.tab.cpp"
    break;

  case 223: // type-expr: type-expr "`|`" type-expr
#line 1138 "annium.y"
        {
            annium_union_t uni{};
            uni.members.emplace_back(std::move(yystack_[2].value.as < syntax_expression_t > ()));
            uni.members.emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(uni);
            IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4166 "annium.tab.cpp"
    break;

  case 224: // type-expr: type-expr "`->`" type-expr
#line 1146 "annium.y"
        { 
            auto loc = get_start_location(yystack_[2].value.as < syntax_expression_t > ());
            yylhs.value.as < syntax_expression_t > () = annium_fn_type_t{ named_expression_list_t{ named_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()) } }, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) };
        }
#line 4175 "annium.tab.cpp"
    break;


#line 4179 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -284;

  const signed char parser::yytable_ninf_ = -99;

  const short
  parser::yypact_[] =
  {
     717,  -284,  -284,   -33,  -284,  -284,  -284,  -284,  -284,  -284,
     838,    49,   817,   838,   838,    49,   838,   838,    -3,   -36,
     107,   838,   838,   838,    37,    58,   -38,  -284,    37,    37,
    -284,  -284,  -284,    74,    40,   417,  -284,  -284,  -284,  -284,
     267,    19,   945,  -284,    38,  -284,    66,    73,    34,   838,
     119,   957,  -284,  -284,   838,  -284,   133,  1139,   -20,   127,
    1139,   183,  -284,     1,     1,    49,  -284,   139,   176,  -284,
      49,    31,   337,   150,   904,   892,   707,   247,  -284,  -284,
    -284,   246,  -284,   213,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,    49,   838,   223,  -284,   175,   180,   109,  -284,
     838,   838,   838,   838,   838,   838,  -284,   838,   269,   838,
     838,   838,   838,   838,   838,   838,   199,   211,  -284,   997,
     838,  -284,   838,  -284,   838,  -284,  -284,   281,   838,   252,
    -284,   838,   838,   617,   838,  -284,   838,   220,   838,   223,
      49,   278,   223,  -284,  -284,   292,  -284,   331,   331,    25,
     435,  -284,  -284,   347,    42,   311,   303,  -284,   538,   331,
     331,   223,   838,  -284,  1139,   297,   297,   847,  1176,   343,
    1034,  -284,  -284,     1,     1,   317,   507,    70,   146,   166,
    -284,  -284,  1139,   340,  1139,  1139,   -33,   738,   281,   267,
      38,    66,    73,   123,   211,   281,    60,   313,   324,  -284,
     838,  1139,   349,  -284,  -284,   838,    37,   338,   517,  -284,
     350,  -284,  -284,   707,   707,   357,  1139,   365,  -284,   360,
     351,  -284,    49,   370,  -284,   838,  -284,  -284,  -284,   545,
     331,   331,    37,    35,  -284,   838,   455,   455,   455,   414,
     362,  -284,   399,  -284,   414,   114,   389,   331,    25,  -284,
     322,   223,  -284,   380,  -284,  -284,   387,  1044,  -284,  -284,
    -284,  -284,   838,  -284,   174,   212,   281,   838,   281,   123,
    -284,  -284,  -284,   838,  1139,  -284,  1139,   316,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,   418,  -284,    49,    30,
     391,   373,  -284,   120,  1139,  -284,   385,  -284,  -284,   175,
      55,   414,  -284,   414,  1081,  -284,  -284,  -284,  -284,   414,
    -284,  -284,  -284,    25,  -284,   331,   331,   281,   838,   599,
    -284,  -284,  -284,  -284,   288,  -284,  1139,  -284,  -284,  -284,
    1091,    29,  -284,   223,   838,  -284,   838,   281,  -284,    49,
     396,  -284,  -284,   455,   275,   347,   275,   323,   182,  -284,
    -284,   410,  -284,    35,  -284,   331,   331,  -284,  -284,   136,
    1129,   134,   281,   599,  -284,   398,  1139,  1139,   138,  -284,
      49,  -284,  -284,   275,  -284,   455,   413,  -284,    55,  -284,
     414,  -284,  -284,  -284,  -284,  -284,  -284,   123,  -284,   357,
     838,  -284,   401,  -284,  -284,  -284,  -284,  -284,  1139,  -284
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   167,    53,   157,   168,   158,   166,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
     160,   161,   162,     0,     0,     0,     5,     7,    14,    56,
     169,     0,     0,   159,   191,   192,   215,   194,   193,   208,
       0,     0,   193,    55,     0,   170,    56,   210,     0,     0,
      75,     0,   176,   181,   180,     0,    44,    20,    16,    18,
       0,     0,   196,   197,     0,     0,     0,     0,    45,    13,
      59,     0,    41,     0,    15,     1,     2,    10,     3,     8,
       6,     9,     0,   208,    93,    61,    60,     0,     0,   179,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   195,     0,
       0,   172,     0,   173,     0,   174,    19,     0,     0,     0,
      12,    77,    77,    22,     0,    32,     0,    35,     0,    93,
      66,     0,    93,    39,    57,     0,    54,    99,    99,   119,
       0,   114,   115,    97,    99,     0,    94,    95,     0,    99,
      99,    93,     0,    37,    47,   184,   185,   189,   190,   186,
       0,   177,   178,   182,   183,   187,   188,     0,     0,     0,
     201,   171,   211,    56,   212,    76,   218,     0,     0,   216,
       0,   217,     0,    21,    17,     0,    56,     0,    78,    79,
       0,    82,     0,    50,    49,    51,     0,    42,    43,    25,
       0,    48,    23,     0,     0,     0,    73,     0,    70,     0,
      67,    68,    85,     0,   200,     0,   107,   109,   120,     0,
      99,    99,     0,   153,   143,     0,     0,     0,     0,   153,
     144,   137,   141,   155,   151,    99,     0,    99,   119,   106,
       0,     0,   118,   116,   113,   104,     0,     0,   175,   203,
     202,   204,     0,   220,     0,     0,     0,     0,     0,    11,
      83,    84,   198,     0,    81,   199,    52,     0,    28,    26,
      27,    24,    31,    33,    34,    36,     0,    65,     0,     0,
       0,    86,    87,     0,   100,   123,   121,   112,   103,   152,
     153,   153,   147,   154,     0,   140,   138,   139,   146,   153,
     142,   156,   105,   119,   108,    99,    99,     0,     0,     0,
     205,    29,    96,   117,    62,    38,   213,   221,   219,   224,
       0,   223,    80,    93,     0,    69,     0,     0,    71,     0,
       0,    40,   122,     0,   153,     0,   153,   153,     0,   135,
     125,   127,   148,   153,   145,    99,    99,   111,   102,     0,
       0,     0,     0,     0,   222,     0,    74,    92,    89,    88,
      85,   131,   136,   153,   133,     0,   129,   124,   153,   128,
     153,   149,   110,   101,   206,    30,   207,    63,    64,     0,
       0,    91,     0,   134,   132,   130,   126,   150,    90,    72
  };

  const short
  parser::yypgoto_[] =
  {
    -284,  -284,  -284,  -284,   419,  -284,  -284,  -284,  -284,  -284,
      47,   -50,   -34,  -284,  -126,   248,    79,   -74,    18,     6,
    -284,   384,  -284,  -284,  -284,   171,  -284,  -284,   446,   334,
    -284,   190,  -284,   104,  -284,  -284,   141,  -134,  -284,  -284,
     152,   226,  -131,  -284,  -284,  -244,  -238,  -284,   -41,   100,
    -130,  -206,  -283,  -232,    12,   -86,     0,  -284,     8,  -284,
      51,    54,   388,    33,     9,   121
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    33,    34,    35,    36,    66,    67,    68,   207,   208,
     320,   321,    37,   210,    38,   212,    39,   239,    40,    50,
      97,    98,    82,   219,   220,   221,    84,    78,    59,   197,
     198,   199,   200,   290,   291,   391,   292,   155,   156,   246,
     226,   157,   158,   159,   229,   230,   301,   348,   349,   350,
     160,   241,   242,   243,   351,   303,    57,    43,    44,    45,
      46,    47,   116,   117,    52,   193
  };

  const short
  parser::yytable_[] =
  {
      42,    91,   309,     2,   315,   217,    41,   211,   223,    48,
      51,    99,   311,    60,    60,    49,    63,    64,   228,   231,
     154,    74,    75,    76,   135,     2,   137,   256,    73,   121,
     305,   306,   307,   143,   -46,    42,   361,     2,    72,    70,
      86,    41,    77,     2,    48,    58,    81,    83,   163,   266,
     122,   336,   232,   107,   119,     2,    80,   225,    71,    96,
     108,     2,   146,    79,   244,   154,    11,    94,   154,   355,
     343,   311,   232,   344,    85,   270,   337,   247,    11,   245,
     388,   267,   211,   300,    11,   -46,   113,   154,   248,    96,
      53,    56,   -46,   150,    62,    65,    95,    69,    87,   209,
     164,   165,   166,   167,   168,   169,   271,   170,    95,   173,
     174,   175,   176,     2,   114,   380,   172,   228,   316,   259,
     182,   115,   184,    10,   185,   151,   152,   345,    56,   225,
     162,   201,   201,    42,   213,   190,   214,   371,   216,    41,
     122,   340,    48,   266,   126,   189,   177,   178,   179,   129,
     244,   244,   244,   390,    11,   318,   266,   318,   266,   133,
     -98,   194,   257,   283,   284,   285,   190,    94,   240,   394,
     133,   144,    56,   153,   280,   267,   189,   154,   191,   120,
     123,   192,   228,   356,   133,   127,   133,   171,   267,   268,
     267,   128,    56,    56,    56,   260,   190,   124,   132,   365,
     274,   183,   268,   190,   268,   276,   189,    56,    42,   191,
     196,   196,   192,   189,    41,   261,   122,    48,   153,   218,
     264,   153,    92,   327,   277,   294,   347,   143,   161,     2,
     146,   377,   266,   244,   141,   304,   122,   190,   125,   191,
     153,   147,   192,   341,   122,   302,   191,   189,   180,   192,
     299,   308,   378,   124,   240,   240,   240,   244,   148,   154,
      92,   142,   326,   133,   267,   328,    56,   330,   138,   149,
     347,   373,   347,   201,   190,     2,   190,   244,   268,   253,
     191,   122,   146,   192,   189,    10,   189,     2,   186,   244,
     343,   150,   232,    92,    92,   139,   140,    10,   195,   347,
     227,   289,   215,   372,   347,   374,   249,    99,   362,   265,
     363,   254,   255,   352,    92,    93,   269,   191,   360,   191,
     192,   354,   192,   151,   152,   190,   222,    99,    11,   187,
     153,   105,   393,   188,   366,   189,   367,   240,   375,   341,
     232,   224,   317,   318,   319,   190,   225,   101,   102,   107,
     296,   105,   196,    99,   146,   189,   108,   109,   110,   376,
     250,   240,   272,    92,   333,   381,   133,   218,   191,   107,
     190,   192,   133,   251,    26,    27,   108,   109,   110,   346,
     189,   240,   297,   298,    92,   131,   262,   329,   191,   331,
     398,   192,   397,   240,   273,   107,   278,   312,   275,   314,
     266,   282,   108,   109,   110,   266,   384,   133,   386,    92,
     300,   287,   153,   191,   286,   323,   192,    88,   289,   293,
     342,   288,     1,     2,     3,     4,     5,     6,     7,     8,
       9,   232,   267,    10,   310,   313,   324,   267,   359,   334,
     338,     2,   146,   339,   370,   379,   268,   389,   395,   289,
     399,   268,   232,   233,    90,   130,   281,   346,   368,   335,
      61,     2,   146,   332,    11,    12,   202,   357,   358,    13,
     234,    14,   232,   233,   392,    89,    15,   322,   396,    16,
     369,   145,    11,   387,    17,   235,     0,     0,     0,     0,
     234,    18,     0,    19,    20,    21,    22,     0,    23,     0,
       0,     0,    11,     0,    24,   235,     0,   382,   383,    25,
      26,    27,    28,    29,     0,     0,     0,    99,     0,    30,
      31,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,   236,   237,   238,   101,   102,     0,
       0,   105,     0,     0,     2,   186,     0,     0,     0,     0,
       0,     2,   186,     0,    10,     0,     0,     0,     0,   107,
       0,    10,     0,     0,    11,    12,   108,   109,   110,    13,
       0,    14,   111,   252,     0,   279,    15,     0,     0,    16,
     295,     0,     0,     0,    17,    11,   187,     0,     0,     0,
     188,    18,    11,   187,    20,    21,    22,   188,    23,     0,
     203,   204,   205,     0,    24,     2,   146,     0,     0,     0,
      26,    27,    28,   206,     0,     0,   232,   233,     0,    30,
      31,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    26,    27,    10,     0,     0,     0,     0,    26,    27,
       0,     0,     0,     0,     0,     0,    11,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,    13,
       0,    14,     0,     0,     0,     0,    15,     0,     0,    16,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    20,    21,    22,     0,    23,     0,
     203,   204,   205,     0,    24,     0,     0,     0,     0,     0,
      26,    27,    28,   206,     0,     0,     0,    99,     0,    30,
      31,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,   101,   102,   103,
     104,   105,   106,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,     0,     0,   133,     0,   107,
       0,     0,     0,     0,    11,    12,   108,   109,   110,    13,
       0,    14,   111,   112,     0,     0,    15,     0,     0,    16,
       0,     0,     0,     0,    17,    11,    12,   263,     0,     0,
      13,    18,    14,    19,    20,    21,    22,    15,    23,     0,
      16,     0,     0,     0,    24,    17,     0,     0,     0,    25,
      26,    27,    28,    29,     0,    20,     0,     0,     0,    30,
      31,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    26,    27,    10,     0,     0,     0,     0,     0,     0,
      30,    31,    32,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,     0,     0,    99,     0,     0,
       0,     0,     0,    54,    11,    12,    55,     0,     0,    13,
       0,    14,     0,     0,     0,     0,    15,   101,   102,    16,
       0,   105,     0,     0,    17,    11,    12,     0,     0,     0,
      13,     0,    14,     0,    20,     0,     0,    15,     0,   107,
      16,     0,    99,     0,     0,    17,   108,   109,   110,     0,
      26,    27,   111,   112,    99,    20,     0,     0,     0,    30,
      31,    32,   101,   102,   103,   104,   105,   106,     0,     0,
       0,    26,    27,     0,   101,   102,   103,   104,   105,   106,
      30,    31,    32,     0,   107,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   133,    99,   107,   111,   112,     0,
     100,     0,   134,   108,   109,   110,     0,    99,     0,   111,
     112,     0,   136,   118,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,   108,   109,   110,    99,     0,   107,
     111,   112,     0,     0,     0,     0,   108,   109,   110,     0,
       0,     0,   111,   112,     0,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,   181,     0,     0,   107,
       0,     0,     0,     0,    99,     0,   108,   109,   110,     0,
       0,     0,   111,   112,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   107,   258,     0,     0,
       0,    99,     0,   108,   109,   110,   107,     0,     0,   111,
     112,    99,   325,   108,   109,   110,     0,     0,     0,   111,
     112,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,   353,   107,     0,     0,     0,     0,     0,    99,
     108,   109,   110,   107,   364,   385,   111,   112,     0,    99,
     108,   109,   110,     0,     0,     0,   111,   112,     0,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,    99,     0,   108,   109,
     110,   107,     0,     0,   111,   112,     0,     0,   108,   109,
     110,     0,     0,     0,   111,   112,   101,   102,   103,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,   108,   109,   110,     0,     0,
       0,   111,   112
  };

  const short
  parser::yycheck_[] =
  {
       0,    35,   240,     6,   248,   139,     0,   133,   142,     0,
      10,    10,   244,    13,    14,    48,    16,    17,   149,   149,
      94,    21,    22,    23,    74,     6,    76,   161,    20,    49,
     236,   237,   238,    83,     0,    35,   319,     6,    20,    75,
       0,    35,    24,     6,    35,    12,    28,    29,    98,    20,
      70,    21,    17,    52,    54,     6,    94,    15,    94,    41,
      59,     6,     7,     5,   150,   139,    47,    48,   142,   313,
      15,   303,    17,    18,     0,    15,    46,    35,    47,   153,
     363,    52,   208,    48,    47,    51,    48,   161,    46,    71,
      11,    12,    58,    68,    15,    98,    77,    18,    58,   133,
     100,   101,   102,   103,   104,   105,    46,   107,    77,   109,
     110,   111,   112,     6,    48,   353,   108,   248,   248,    49,
     120,    48,   122,    16,   124,   100,   101,    72,    49,    15,
      21,   131,   132,   133,   134,   127,   136,   343,   138,   133,
      70,    21,   133,    20,    65,   127,   113,   114,   115,    70,
     236,   237,   238,    15,    47,    21,    20,    21,    20,    50,
      46,   128,   162,   213,   214,   215,   158,    48,   150,   375,
      50,    92,    93,    94,   208,    52,   158,   251,   127,    46,
      53,   127,   313,   313,    50,    46,    50,   108,    52,    66,
      52,    15,   113,   114,   115,    49,   188,    70,    48,   333,
     200,   122,    66,   195,    66,   205,   188,   128,   208,   158,
     131,   132,   158,   195,   208,    49,    70,   208,   139,   140,
     187,   142,    47,    49,   206,   225,   300,   277,    48,     6,
       7,    49,    20,   319,    21,   235,    70,   229,    55,   188,
     161,    18,   188,   293,    70,   233,   195,   229,    49,   195,
     232,   239,    70,    70,   236,   237,   238,   343,    35,   333,
      47,    48,   262,    50,    52,    53,   187,   267,    21,    46,
     344,   345,   346,   273,   266,     6,   268,   363,    66,   158,
     229,    70,     7,   229,   266,    16,   268,     6,     7,   375,
      15,    68,    17,    47,    47,    48,    50,    16,    46,   373,
     148,   222,    82,   344,   378,   346,   154,    10,    20,   188,
      22,   159,   160,   301,    47,    48,   195,   266,   318,   268,
     266,   309,   268,   100,   101,   317,    48,    10,    47,    48,
     251,    34,   373,    52,   334,   317,   336,   319,    15,   389,
      17,    49,    20,    21,    22,   337,    15,    30,    31,    52,
     229,    34,   273,    10,     7,   337,    59,    60,    61,   347,
      49,   343,    49,    47,    48,   353,    50,   288,   317,    52,
     362,   317,    50,    70,    93,    94,    59,    60,    61,   300,
     362,   363,   230,   231,    47,    48,    46,   266,   337,   268,
     390,   337,   380,   375,    70,    52,    58,   245,    49,   247,
      20,    51,    59,    60,    61,    20,   359,    50,   361,    47,
      48,    51,   333,   362,    49,    35,   362,     0,   339,    49,
      35,    70,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    17,    52,    16,    35,    46,    49,    52,   317,    21,
      49,     6,     7,    70,    48,    35,    66,    49,    35,   370,
      49,    66,    17,    18,    35,    71,   208,   378,   337,   288,
      14,     6,     7,   273,    47,    48,   132,   315,   316,    52,
      35,    54,    17,    18,   370,    58,    59,   251,   378,    62,
     339,    93,    47,   362,    67,    50,    -1,    -1,    -1,    -1,
      35,    74,    -1,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    47,    -1,    87,    50,    -1,   355,   356,    92,
      93,    94,    95,    96,    -1,    -1,    -1,    10,    -1,   102,
     103,   104,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    99,   100,   101,    30,    31,    -1,
      -1,    34,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    16,    -1,    -1,    -1,    -1,    52,
      -1,    16,    -1,    -1,    47,    48,    59,    60,    61,    52,
      -1,    54,    65,    35,    -1,    58,    59,    -1,    -1,    62,
      35,    -1,    -1,    -1,    67,    47,    48,    -1,    -1,    -1,
      52,    74,    47,    48,    77,    78,    79,    52,    81,    -1,
      83,    84,    85,    -1,    87,     6,     7,    -1,    -1,    -1,
      93,    94,    95,    96,    -1,    -1,    17,    18,    -1,   102,
     103,   104,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    93,    94,    16,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    78,    79,    -1,    81,    -1,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    -1,    -1,    -1,    10,    -1,   102,
     103,   104,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    -1,    -1,    50,    -1,    52,
      -1,    -1,    -1,    -1,    47,    48,    59,    60,    61,    52,
      -1,    54,    65,    66,    -1,    -1,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    67,    47,    48,    49,    -1,    -1,
      52,    74,    54,    76,    77,    78,    79,    59,    81,    -1,
      62,    -1,    -1,    -1,    87,    67,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    -1,    77,    -1,    -1,    -1,   102,
     103,   104,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    93,    94,    16,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,
      -1,    54,    -1,    -1,    -1,    -1,    59,    30,    31,    62,
      -1,    34,    -1,    -1,    67,    47,    48,    -1,    -1,    -1,
      52,    -1,    54,    -1,    77,    -1,    -1,    59,    -1,    52,
      62,    -1,    10,    -1,    -1,    67,    59,    60,    61,    -1,
      93,    94,    65,    66,    10,    77,    -1,    -1,    -1,   102,
     103,   104,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    93,    94,    -1,    30,    31,    32,    33,    34,    35,
     102,   103,   104,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    50,    10,    52,    65,    66,    -1,
      15,    -1,    58,    59,    60,    61,    -1,    10,    -1,    65,
      66,    -1,    80,    16,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    10,    -1,    52,
      65,    66,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    10,    -1,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    10,    -1,    59,    60,    61,    52,    -1,    -1,    65,
      66,    10,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    10,
      59,    60,    61,    52,    53,    16,    65,    66,    -1,    10,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    10,    -1,    59,    60,
      61,    52,    -1,    -1,    65,    66,    -1,    -1,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    47,    48,    52,    54,    59,    62,    67,    74,    76,
      77,    78,    79,    81,    87,    92,    93,    94,    95,    96,
     102,   103,   104,   106,   107,   108,   109,   117,   119,   121,
     123,   124,   161,   162,   163,   164,   165,   166,   169,    48,
     124,   161,   169,   121,    46,    49,   121,   161,   168,   133,
     161,   133,   121,   161,   161,    98,   110,   111,   112,   121,
      75,    94,   123,   163,   161,   161,   161,   123,   132,     5,
      94,   123,   127,   123,   131,     0,     0,    58,     0,    58,
     109,   117,    47,    48,    48,    77,   123,   125,   126,    10,
      15,    30,    31,    32,    33,    34,    35,    52,    59,    60,
      61,    65,    66,    48,    48,    48,   167,   168,    16,   161,
      46,    49,    70,    53,    70,    55,   121,    46,    15,   121,
     126,    48,    48,    50,    58,   116,    80,   116,    21,    48,
      50,    21,    48,   116,   121,   167,     7,    18,    35,    46,
      68,   100,   101,   121,   122,   142,   143,   146,   147,   148,
     155,    48,    21,   116,   161,   161,   161,   161,   161,   161,
     161,   121,   163,   161,   161,   161,   161,   168,   168,   168,
      49,    49,   161,   121,   161,   161,     7,    48,    52,   123,
     163,   165,   166,   170,   168,    46,   121,   134,   135,   136,
     137,   161,   134,    83,    84,    85,    96,   113,   114,   117,
     118,   119,   120,   161,   161,    82,   161,   142,   121,   128,
     129,   130,    48,   142,    49,    15,   145,   145,   147,   149,
     150,   155,    17,    18,    35,    50,    99,   100,   101,   122,
     123,   156,   157,   158,   160,   122,   144,    35,    46,   145,
      49,    70,    35,   170,   145,   145,   142,   161,    53,    49,
      49,    49,    46,    49,   168,   170,    20,    52,    66,   170,
      15,    46,    49,    70,   161,    49,   161,   123,    58,    58,
     117,   120,    51,   116,   116,   116,    49,    51,    70,   121,
     138,   139,   141,    49,   161,    35,   170,   145,   145,   123,
      48,   151,   159,   160,   161,   156,   156,   156,   159,   151,
      35,   158,   145,    46,   145,   150,   155,    20,    21,    22,
     115,   116,   146,    35,    49,    58,   161,    49,    53,   170,
     161,   170,   136,    48,    21,   130,    21,    46,    49,    70,
      21,   116,    35,    15,    18,    72,   121,   122,   152,   153,
     154,   159,   159,    51,   159,   150,   155,   145,   145,   170,
     161,   157,    20,    22,    53,   142,   161,   161,   170,   141,
      48,   156,   153,   122,   153,    15,   159,    49,    70,    35,
     151,   159,   145,   145,   115,    16,   115,   170,   157,    49,
      15,   140,   138,   153,   156,    35,   154,   159,   161,    49
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
     146,   146,   146,   146,   147,   147,   148,   148,   148,   149,
     149,   150,   150,   150,   151,   152,   152,   153,   153,   153,
     153,   153,   153,   154,   154,   154,   154,   155,   155,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   157,   157,
     157,   157,   158,   159,   159,   160,   160,   161,   161,   161,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   163,   164,   164,   164,   164,
     165,   165,   165,   165,   165,   166,   166,   166,   167,   167,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170
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
       5,     4,     3,     2,     1,     1,     2,     3,     2,     0,
       1,     2,     3,     2,     3,     1,     3,     1,     2,     2,
       3,     2,     3,     2,     3,     1,     2,     2,     3,     3,
       3,     1,     2,     1,     1,     3,     2,     2,     3,     4,
       5,     1,     2,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     3,     3,     4,     2,     3,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     2,     2,     5,     5,
       4,     4,     4,     4,     4,     5,     7,     7,     0,     1,
       1,     3,     3,     5,     2,     1,     1,     1,     1,     3,
       2,     3,     4,     3,     3
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
  "new-expression", "call-expression", "lambda-expression",
  "pack-expression-opt", "pack-expression", "compound-expression",
  "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   334,   334,   335,   339,   341,   343,   360,   362,   363,
     365,   370,   372,   374,   387,   389,   394,   396,   401,   403,
     408,   409,   414,   416,   418,   423,   425,   426,   428,   434,
     436,   446,   451,   453,   455,   457,   459,   461,   463,   471,
     473,   475,   480,   482,   487,   489,   491,   493,   498,   500,
     502,   504,   506,   511,   519,   534,   536,   538,   544,   546,
     551,   552,   556,   558,   560,   566,   571,   572,   576,   578,
     583,   589,   591,   614,   621,   639,   641,   647,   648,   652,
     654,   659,   661,   666,   668,   674,   675,   679,   681,   686,
     687,   691,   693,   700,   701,   705,   707,   712,   713,   717,
     718,   722,   724,   726,   728,   731,   733,   735,   737,   739,
     744,   746,   748,   750,   755,   756,   760,   762,   764,   769,
     770,   774,   776,   778,   784,   789,   791,   797,   799,   802,
     804,   808,   811,   817,   820,   833,   836,   841,   842,   843,
     844,   848,   849,   850,   854,   856,   858,   860,   862,   864,
     866,   868,   873,   878,   880,   884,   886,   894,   896,   898,
     903,   905,   907,   909,   911,   913,   915,   917,   919,   921,
     923,   925,   927,   936,   944,   946,   948,   952,   954,   956,
     959,   961,   966,   968,   972,   974,   976,   979,   983,   986,
     989,   992,   993,   994,   995,   999,  1004,  1006,  1008,  1010,
    1015,  1017,  1025,  1027,  1029,  1034,  1036,  1038,  1043,  1045,
    1050,  1059,  1065,  1070,  1078,  1080,  1121,  1123,  1124,  1128,
    1130,  1133,  1135,  1137,  1145
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
#line 5176 "annium.tab.cpp"

#line 1472 "annium.y"

