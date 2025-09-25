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
      case symbol_kind::S_140_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.copy< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.copy< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.copy< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.copy< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.copy< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.copy< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.copy< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.copy< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.copy< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.copy< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.copy< reference_expression_t > (YY_MOVE (that.value));
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
        value.copy< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.copy< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
      case symbol_kind::S_140_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.move< reference_expression_t > (YY_MOVE (s.value));
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
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.move< syntax_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
      case symbol_kind::S_140_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.YY_MOVE_OR_COPY< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.YY_MOVE_OR_COPY< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.YY_MOVE_OR_COPY< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.YY_MOVE_OR_COPY< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.YY_MOVE_OR_COPY< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.YY_MOVE_OR_COPY< reference_expression_t > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
      case symbol_kind::S_140_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.move< reference_expression_t > (YY_MOVE (that.value));
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
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.move< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
      case symbol_kind::S_140_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.copy< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.copy< expression_list_t > (that.value);
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.copy< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (that.value);
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.copy< field_t::default_spec > (that.value);
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.copy< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.copy< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.copy< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (that.value);
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (that.value);
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.copy< parameter_t > (that.value);
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter_t::default_spec > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.copy< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (that.value);
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.copy< pattern_t::field > (that.value);
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.copy< reference_expression_t > (that.value);
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
        value.copy< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.copy< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
      case symbol_kind::S_140_argument_name: // argument-name
        value.move< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        value.move< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        value.move< expression_list_t > (that.value);
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        value.move< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (that.value);
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (that.value);
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        value.move< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        value.move< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        value.move< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (that.value);
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        value.move< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (that.value);
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        value.move< parameter_t > (that.value);
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        value.move< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (that.value);
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        value.move< pattern_t::field > (that.value);
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        value.move< reference_expression_t > (that.value);
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
        value.move< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        value.move< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        value.move< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
#line 333 "annium.y"
                 { }
#line 1810 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 333 "annium.y"
                 { }
#line 1816 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 333 "annium.y"
                 { }
#line 1822 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 333 "annium.y"
                 { }
#line 1828 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 333 "annium.y"
                 { }
#line 1834 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 333 "annium.y"
                 { }
#line 1840 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 333 "annium.y"
                 { }
#line 1846 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 333 "annium.y"
                 { }
#line 1852 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 333 "annium.y"
                 { }
#line 1858 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 333 "annium.y"
                 { }
#line 1864 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 333 "annium.y"
                 { }
#line 1870 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 333 "annium.y"
                 { }
#line 1876 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 333 "annium.y"
                 { }
#line 1882 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 333 "annium.y"
                 { }
#line 1888 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 333 "annium.y"
                 { }
#line 1894 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 333 "annium.y"
                 { }
#line 1900 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 333 "annium.y"
                 { }
#line 1906 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 333 "annium.y"
                 { }
#line 1912 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 333 "annium.y"
                 { }
#line 1918 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 333 "annium.y"
                 { }
#line 1924 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 333 "annium.y"
                 { }
#line 1930 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 333 "annium.y"
                 { }
#line 1936 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 333 "annium.y"
                 { }
#line 1942 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 333 "annium.y"
                 { }
#line 1948 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 333 "annium.y"
                 { }
#line 1954 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 333 "annium.y"
                 { }
#line 1960 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 333 "annium.y"
                 { }
#line 1966 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 333 "annium.y"
                 { }
#line 1972 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 333 "annium.y"
                 { }
#line 1978 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 333 "annium.y"
                 { }
#line 1984 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 333 "annium.y"
                 { }
#line 1990 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 333 "annium.y"
                 { }
#line 1996 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 333 "annium.y"
                 { }
#line 2002 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 333 "annium.y"
                 { }
#line 2008 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 333 "annium.y"
                 { }
#line 2014 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 333 "annium.y"
                 { }
#line 2020 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 333 "annium.y"
                 { }
#line 2026 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 333 "annium.y"
                 { }
#line 2032 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 333 "annium.y"
                 { }
#line 2038 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 333 "annium.y"
                 { }
#line 2044 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 333 "annium.y"
                 { }
#line 2050 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 333 "annium.y"
                 { }
#line 2056 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 333 "annium.y"
                 { }
#line 2062 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 333 "annium.y"
                 { }
#line 2068 "annium.tab.cpp"
        break;

      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
#line 333 "annium.y"
                 { }
#line 2074 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 333 "annium.y"
                 { }
#line 2080 "annium.tab.cpp"
        break;

      case symbol_kind::S_112_let_decl: // let-decl
#line 333 "annium.y"
                 { }
#line 2086 "annium.tab.cpp"
        break;

      case symbol_kind::S_113_let_decl_start: // let-decl-start
#line 333 "annium.y"
                 { }
#line 2092 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 333 "annium.y"
                 { }
#line 2098 "annium.tab.cpp"
        break;

      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
#line 333 "annium.y"
                 { }
#line 2104 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
#line 333 "annium.y"
                 { }
#line 2110 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_function_body: // function-body
#line 333 "annium.y"
                 { }
#line 2116 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_braced_statements: // braced-statements
#line 333 "annium.y"
                 { }
#line 2122 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
#line 333 "annium.y"
                 { }
#line 2128 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
#line 333 "annium.y"
                 { }
#line 2134 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
#line 333 "annium.y"
                 { }
#line 2140 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_infunction_statement: // infunction-statement
#line 333 "annium.y"
                 { }
#line 2146 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 333 "annium.y"
                 { }
#line 2152 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_internal_identifier: // internal-identifier
#line 333 "annium.y"
                 { }
#line 2158 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 333 "annium.y"
                 { }
#line 2164 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
#line 333 "annium.y"
                 { }
#line 2170 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_fn_name: // fn-name
#line 333 "annium.y"
                 { }
#line 2176 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
#line 333 "annium.y"
                 { }
#line 2182 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_fn_decl: // fn-decl
#line 333 "annium.y"
                 { }
#line 2188 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
#line 333 "annium.y"
                 { }
#line 2194 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
#line 333 "annium.y"
                 { }
#line 2200 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_case_list: // case-list
#line 333 "annium.y"
                 { }
#line 2206 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_case_decl: // case-decl
#line 333 "annium.y"
                 { }
#line 2212 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
#line 333 "annium.y"
                 { }
#line 2218 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_using_decl: // using-decl
#line 333 "annium.y"
                 { }
#line 2224 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_expression_list: // expression-list
#line 333 "annium.y"
                 { }
#line 2230 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
#line 333 "annium.y"
                 { }
#line 2236 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_argument_list: // argument-list
#line 333 "annium.y"
                 { }
#line 2242 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 333 "annium.y"
                 { }
#line 2248 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_argument_name: // argument-name
#line 333 "annium.y"
                 { }
#line 2254 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
#line 333 "annium.y"
                 { }
#line 2260 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_field_list: // field-list
#line 333 "annium.y"
                 { }
#line 2266 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
#line 333 "annium.y"
                 { }
#line 2272 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 333 "annium.y"
                 { }
#line 2278 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
#line 333 "annium.y"
                 { }
#line 2284 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_parameter_list: // parameter-list
#line 333 "annium.y"
                 { }
#line 2290 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
#line 333 "annium.y"
                 { }
#line 2296 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
#line 333 "annium.y"
                 { }
#line 2302 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
#line 333 "annium.y"
                 { }
#line 2308 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 333 "annium.y"
                 { }
#line 2314 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
#line 333 "annium.y"
                 { }
#line 2320 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
#line 333 "annium.y"
                 { }
#line 2326 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_constraint_expression: // constraint-expression
#line 333 "annium.y"
                 { }
#line 2332 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 333 "annium.y"
                 { }
#line 2338 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_pattern_list: // pattern-list
#line 333 "annium.y"
                 { }
#line 2344 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
#line 333 "annium.y"
                 { }
#line 2350 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_pattern_field: // pattern-field
#line 333 "annium.y"
                 { }
#line 2356 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
#line 333 "annium.y"
                 { }
#line 2362 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
#line 333 "annium.y"
                 { }
#line 2368 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 333 "annium.y"
                 { }
#line 2374 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
#line 333 "annium.y"
                 { }
#line 2380 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
#line 333 "annium.y"
                 { }
#line 2386 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
#line 333 "annium.y"
                 { }
#line 2392 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
#line 333 "annium.y"
                 { }
#line 2398 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_syntax_expression: // syntax-expression
#line 333 "annium.y"
                 { }
#line 2404 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
#line 333 "annium.y"
                 { }
#line 2410 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_new_expression: // new-expression
#line 333 "annium.y"
                 { }
#line 2416 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_call_expression: // call-expression
#line 333 "annium.y"
                 { }
#line 2422 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
#line 333 "annium.y"
                 { }
#line 2428 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_lambda_expression: // lambda-expression
#line 333 "annium.y"
                 { }
#line 2434 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
#line 333 "annium.y"
                 { }
#line 2440 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_pack_expression: // pack-expression
#line 333 "annium.y"
                 { }
#line 2446 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_compound_expression: // compound-expression
#line 333 "annium.y"
                 { }
#line 2452 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_type_expr: // type-expr
#line 333 "annium.y"
                 { }
#line 2458 "annium.tab.cpp"
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
      case symbol_kind::S_140_argument_name: // argument-name
        yylhs.value.emplace< annium::annotated_identifier > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< annium::annotated_integer > ();
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_127_fn_name: // fn-name
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

      case symbol_kind::S_124_internal_identifier: // internal-identifier
      case symbol_kind::S_147_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< annium::context_identifier > ();
        break;

      case symbol_kind::S_133_case_decl: // case-decl
        yylhs.value.emplace< annium::identifier > ();
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        yylhs.value.emplace< annotated_bool > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_162_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_163_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< concept_expression_list_t > ();
        break;

      case symbol_kind::S_130_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_136_expression_list: // expression-list
        yylhs.value.emplace< expression_list_t > ();
        break;

      case symbol_kind::S_141_field_list_opt: // field-list-opt
      case symbol_kind::S_142_field_list: // field-list
        yylhs.value.emplace< field_list_t > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field_t > ();
        break;

      case symbol_kind::S_143_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field_t::default_spec > ();
        break;

      case symbol_kind::S_119_finished_statement: // finished-statement
        yylhs.value.emplace< finished_statement_type > ();
        break;

      case symbol_kind::S_128_fn_start_decl: // fn-start-decl
      case symbol_kind::S_129_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure_t > ();
        break;

      case symbol_kind::S_121_generic_statement: // generic-statement
        yylhs.value.emplace< generic_statement_type > ();
        break;

      case symbol_kind::S_169_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< lambda_t > ();
        break;

      case symbol_kind::S_112_let_decl: // let-decl
      case symbol_kind::S_113_let_decl_start: // let-decl-start
      case symbol_kind::S_114_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_110_finished_statement_any: // finished-statement-any
      case symbol_kind::S_115_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_116_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_117_function_body: // function-body
      case symbol_kind::S_118_braced_statements: // braced-statements
      case symbol_kind::S_120_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< managed_statement_list > ();
        break;

      case symbol_kind::S_137_argument_list_opt: // argument-list-opt
      case symbol_kind::S_138_argument_list: // argument-list
      case symbol_kind::S_171_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_172_pack_expression: // pack-expression
        yylhs.value.emplace< named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< named_expression_t > ();
        break;

      case symbol_kind::S_145_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_146_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_149_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter_t > ();
        break;

      case symbol_kind::S_148_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter_t::default_spec > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_155_pattern_list: // pattern-list
        yylhs.value.emplace< pattern_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< pattern_t > ();
        break;

      case symbol_kind::S_156_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_157_pattern_field: // pattern-field
        yylhs.value.emplace< pattern_t::field > ();
        break;

      case symbol_kind::S_164_reference_expression: // reference-expression
        yylhs.value.emplace< reference_expression_t > ();
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
        yylhs.value.emplace< sonia::lang::lex::resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_122_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_158_pattern_mod: // pattern-mod
      case symbol_kind::S_159_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<pattern_t, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_126_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_150_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_152_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_151_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_153_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_131_case_list_opt: // case-list-opt
      case symbol_kind::S_132_case_list: // case-list
        yylhs.value.emplace< std::vector<annium::identifier> > ();
        break;

      case symbol_kind::S_134_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_161_concept_expression: // concept-expression
      case symbol_kind::S_165_syntax_expression: // syntax-expression
      case symbol_kind::S_166_apostrophe_expression: // apostrophe-expression
      case symbol_kind::S_167_new_expression: // new-expression
      case symbol_kind::S_168_call_expression: // call-expression
      case symbol_kind::S_170_lambda_expression: // lambda-expression
      case symbol_kind::S_173_compound_expression: // compound-expression
      case symbol_kind::S_174_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression_t > ();
        break;

      case symbol_kind::S_135_using_decl: // using-decl
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
#line 338 "annium.y"
                            { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2942 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 339 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 2948 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 344 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 2954 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 346 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 2960 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 348 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2966 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 365 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 2972 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 366 "annium.y"
                                                { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2978 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 368 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2984 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 370 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 2990 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 375 "annium.y"
        { yylhs.value.as < statement > () = extern_var{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 2996 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 377 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < fn_pure_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3002 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 379 "annium.y"
        { yylhs.value.as < statement > () = include_decl{ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3008 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 381 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3014 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 383 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < struct_decl > ()); }
#line 3020 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 388 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3026 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 390 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = std::move(yystack_[0].value.as < named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3032 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 395 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = false }; }
#line 3038 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 397 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = true }; }
#line 3044 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 401 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3050 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 403 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 3056 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 408 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 3062 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 410 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3068 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 412 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3074 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 417 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 3080 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 418 "annium.y"
                                                           { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3086 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 420 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3092 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 422 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3098 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 428 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3104 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression "APOSTROPHE"
#line 430 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ yystack_[1].value.as < syntax_expression_t > (), std::move(loc) });
            yylhs.value.as < managed_statement_list > () = std::move(sts);
        }
#line 3115 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 440 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3121 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 445 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3127 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 447 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; }
#line 3133 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 449 "annium.y"
        { yylhs.value.as < finished_statement_type > () = for_statement{ std::move(yystack_[3].value.as < reference_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3139 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 451 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3145 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 453 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[2].value.as < managed_statement_list > ())), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3151 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 455 "annium.y"
        {   
            yystack_[1].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure_t > ().kind = get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[1].value.as < fn_pure_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) };
        }
#line 3161 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 465 "annium.y"
        { yylhs.value.as < finished_statement_type > () = std::move(yystack_[0].value.as < enum_decl > ()); }
#line 3167 "annium.tab.cpp"
    break;

  case 39: // infunction-statement-set: infunction-statement-any
#line 470 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3173 "annium.tab.cpp"
    break;

  case 40: // infunction-statement-set: finished-infunction-statement-any
#line 472 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3179 "annium.tab.cpp"
    break;

  case 41: // generic-statement: LET let-decl
#line 477 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3185 "annium.tab.cpp"
    break;

  case 42: // generic-statement: "`typefn`" fn-start-decl
#line 479 "annium.y"
        { yylhs.value.as < generic_statement_type > () = typefn_decl_t{ std::move(yystack_[0].value.as < fn_pure_t > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3191 "annium.tab.cpp"
    break;

  case 43: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 481 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yystack_[2].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure_t > ().kind = get<1>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < generic_statement_type > () = fn_decl_t{ std::move(yystack_[2].value.as < fn_pure_t > ()), ctx.push(std::move(sts)) };
        }
#line 3204 "annium.tab.cpp"
    break;

  case 44: // generic-statement: USING using-decl
#line 490 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < using_decl > ()); }
#line 3210 "annium.tab.cpp"
    break;

  case 45: // generic-statement: compound-expression
#line 492 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3216 "annium.tab.cpp"
    break;

  case 46: // generic-statement: syntax-expression "`=`" syntax-expression
#line 494 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ binary_expression_t{ binary_operator_type::ASSIGN, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) } }; }
#line 3222 "annium.tab.cpp"
    break;

  case 47: // infunction-statement: generic-statement
#line 499 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3228 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: "`break`"
#line 501 "annium.y"
        { yylhs.value.as < statement > () = break_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3234 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`continue`"
#line 503 "annium.y"
        { yylhs.value.as < statement > () = continue_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3240 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`return`"
#line 505 "annium.y"
        { yylhs.value.as < statement > () = return_statement_t{ .location = std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3246 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`" syntax-expression
#line 507 "annium.y"
        { yylhs.value.as < statement > () = return_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3252 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`yield`" syntax-expression
#line 509 "annium.y"
        { yylhs.value.as < statement > () = yield_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3258 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 514 "annium.y"
      { yylhs.value.as < annium::annotated_identifier > () = ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3264 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 522 "annium.y"
        { yylhs.value.as < annium::context_identifier > () = context_identifier { ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()) }; }
#line 3270 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 537 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3276 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 539 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3282 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 541 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = std::move(yystack_[2].value.as < annium::annotated_qname > ()); yylhs.value.as < annium::annotated_qname > ().value.append(std::move(yystack_[0].value.as < annium::annotated_identifier > ().value)); }
#line 3288 "annium.tab.cpp"
    break;

  case 58: // fn-prefix-decl: "`fn`"
#line 547 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), fn_kind::DEFAULT }; }
#line 3294 "annium.tab.cpp"
    break;

  case 59: // fn-prefix-decl: INLINE "`fn`"
#line 549 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), fn_kind::INLINE }; }
#line 3300 "annium.tab.cpp"
    break;

  case 60: // fn-name: qname
#line 553 "annium.y"
      { yylhs.value.as < annium::annotated_qname > () = yystack_[0].value.as < annium::annotated_qname > (); }
#line 3306 "annium.tab.cpp"
    break;

  case 61: // fn-name: "`new`"
#line 554 "annium.y"
          { yylhs.value.as < annium::annotated_qname > () = ctx.make_qname(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }); }
#line 3312 "annium.tab.cpp"
    break;

  case 62: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`"
#line 559 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[3].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[3].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[1].value.as < parameter_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3318 "annium.tab.cpp"
    break;

  case 63: // fn-decl: fn-start-decl
#line 562 "annium.y"
      { yylhs.value.as < fn_pure_t > () = yystack_[0].value.as < fn_pure_t > (); }
#line 3324 "annium.tab.cpp"
    break;

  case 64: // fn-decl: fn-start-decl "`->`" type-expr
#line 564 "annium.y"
        { yylhs.value.as < fn_pure_t > () = yystack_[2].value.as < fn_pure_t > (); yylhs.value.as < fn_pure_t > ().result = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 3330 "annium.tab.cpp"
    break;

  case 65: // fn-decl: fn-start-decl "`~>`" pattern
#line 566 "annium.y"
        { yylhs.value.as < fn_pure_t > () = yystack_[2].value.as < fn_pure_t > (); yylhs.value.as < fn_pure_t > ().result = std::move(yystack_[0].value.as < pattern_t > ()); }
#line 3336 "annium.tab.cpp"
    break;

  case 66: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 573 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ std::move(yystack_[3].value.as < annium::annotated_qname > ()), std::move(yystack_[1].value.as < std::vector<annium::identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3342 "annium.tab.cpp"
    break;

  case 67: // case-list-opt: %empty
#line 577 "annium.y"
             { yylhs.value.as < std::vector<annium::identifier> > () = {}; }
#line 3348 "annium.tab.cpp"
    break;

  case 68: // case-list-opt: case-list
#line 578 "annium.y"
      { yylhs.value.as < std::vector<annium::identifier> > () = yystack_[0].value.as < std::vector<annium::identifier> > (); }
#line 3354 "annium.tab.cpp"
    break;

  case 69: // case-list: case-decl
#line 583 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::vector<annium::identifier>{std::move(yystack_[0].value.as < annium::identifier > ())}; }
#line 3360 "annium.tab.cpp"
    break;

  case 70: // case-list: case-list "," case-decl
#line 585 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::move(yystack_[2].value.as < std::vector<annium::identifier> > ()); yylhs.value.as < std::vector<annium::identifier> > ().emplace_back(std::move(yystack_[0].value.as < annium::identifier > ())); }
#line 3366 "annium.tab.cpp"
    break;

  case 71: // case-decl: identifier
#line 590 "annium.y"
        { yylhs.value.as < annium::identifier > () = yystack_[0].value.as < annium::annotated_identifier > ().value; }
#line 3372 "annium.tab.cpp"
    break;

  case 72: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 596 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3378 "annium.tab.cpp"
    break;

  case 73: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 598 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[7].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[5].value.as < parameter_list_t > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[6].value.as < sonia::lang::lex::resource_location > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3384 "annium.tab.cpp"
    break;

  case 74: // using-decl: qname "`=>`" syntax-expression
#line 621 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[2].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[2].value.as < annium::annotated_qname > ().location), .result = nullptr }, ctx.push(std::move(sts)) } };
        }
#line 3395 "annium.tab.cpp"
    break;

  case 75: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 628 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.push(std::move(sts)) } };
            IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ());
        }
#line 3407 "annium.tab.cpp"
    break;

  case 76: // expression-list: syntax-expression
#line 646 "annium.y"
        { yylhs.value.as < expression_list_t > () = expression_list_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3413 "annium.tab.cpp"
    break;

  case 77: // expression-list: expression-list "," syntax-expression
#line 648 "annium.y"
        { yylhs.value.as < expression_list_t > () = std::move(yystack_[2].value.as < expression_list_t > ()); yylhs.value.as < expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3419 "annium.tab.cpp"
    break;

  case 78: // argument-list-opt: %empty
#line 653 "annium.y"
              { yylhs.value.as < named_expression_list_t > () = {}; }
#line 3425 "annium.tab.cpp"
    break;

  case 79: // argument-list-opt: argument-list
#line 654 "annium.y"
      { yylhs.value.as < named_expression_list_t > () = yystack_[0].value.as < named_expression_list_t > (); }
#line 3431 "annium.tab.cpp"
    break;

  case 80: // argument-list: argument
#line 659 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{std::move(yystack_[0].value.as < named_expression_t > ())}; }
#line 3437 "annium.tab.cpp"
    break;

  case 81: // argument-list: argument-list "," argument
#line 661 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ()); yylhs.value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < named_expression_t > ())); }
#line 3443 "annium.tab.cpp"
    break;

  case 82: // argument: argument-name syntax-expression
#line 666 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[1].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3449 "annium.tab.cpp"
    break;

  case 83: // argument: syntax-expression
#line 668 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3455 "annium.tab.cpp"
    break;

  case 84: // argument-name: identifier "`=`"
#line 673 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3461 "annium.tab.cpp"
    break;

  case 85: // argument-name: identifier "`:`"
#line 675 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3467 "annium.tab.cpp"
    break;

  case 86: // field-list-opt: %empty
#line 680 "annium.y"
              { yylhs.value.as < field_list_t > () = {}; }
#line 3473 "annium.tab.cpp"
    break;

  case 87: // field-list-opt: field-list
#line 681 "annium.y"
      { yylhs.value.as < field_list_t > () = yystack_[0].value.as < field_list_t > (); }
#line 3479 "annium.tab.cpp"
    break;

  case 88: // field-list: field
#line 686 "annium.y"
        { yylhs.value.as < field_list_t > () = field_list_t{std::move(yystack_[0].value.as < field_t > ())}; }
#line 3485 "annium.tab.cpp"
    break;

  case 89: // field-list: field-list "," field
#line 688 "annium.y"
        { yylhs.value.as < field_list_t > () = std::move(yystack_[2].value.as < field_list_t > ()); yylhs.value.as < field_list_t > ().emplace_back(std::move(yystack_[0].value.as < field_t > ())); }
#line 3491 "annium.tab.cpp"
    break;

  case 90: // field-default-value-opt: %empty
#line 692 "annium.y"
             { yylhs.value.as < field_t::default_spec > () = required_t{}; }
#line 3497 "annium.tab.cpp"
    break;

  case 91: // field-default-value-opt: "`=`" syntax-expression
#line 693 "annium.y"
                                      { yylhs.value.as < field_t::default_spec > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3503 "annium.tab.cpp"
    break;

  case 92: // field: identifier "`:`" type-expr field-default-value-opt
#line 698 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ .name = std::move(yystack_[3].value.as < annium::annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression_t > ()), .value = std::move(yystack_[0].value.as < field_t::default_spec > ()) }; }
#line 3509 "annium.tab.cpp"
    break;

  case 93: // field: identifier "`=>`" syntax-expression
#line 700 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ .name = std::move(yystack_[2].value.as < annium::annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::any_constexpr_type, .type_or_value = std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3515 "annium.tab.cpp"
    break;

  case 94: // parameter-list-opt: %empty
#line 706 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3521 "annium.tab.cpp"
    break;

  case 95: // parameter-list-opt: parameter-list
#line 707 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3527 "annium.tab.cpp"
    break;

  case 96: // parameter-list: parameter-decl
#line 712 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ parameter_t{std::move(yystack_[0].value.as < parameter_t > ())} }; }
#line 3533 "annium.tab.cpp"
    break;

  case 97: // parameter-list: parameter-list "," parameter-decl
#line 714 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter_t > ())); }
#line 3539 "annium.tab.cpp"
    break;

  case 98: // internal-identifier-opt: %empty
#line 718 "annium.y"
             { yylhs.value.as < annium::context_identifier > () = context_identifier{}; }
#line 3545 "annium.tab.cpp"
    break;

  case 99: // internal-identifier-opt: internal-identifier
#line 719 "annium.y"
                                 { yylhs.value.as < annium::context_identifier > () = std::move(yystack_[0].value.as < annium::context_identifier > ()); }
#line 3551 "annium.tab.cpp"
    break;

  case 100: // parameter-default-value-opt: %empty
#line 723 "annium.y"
             { yylhs.value.as < parameter_t::default_spec > () = required_t{}; }
#line 3557 "annium.tab.cpp"
    break;

  case 101: // parameter-default-value-opt: "`=`" syntax-expression
#line 724 "annium.y"
                                      { yylhs.value.as < parameter_t::default_spec > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3563 "annium.tab.cpp"
    break;

  case 102: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 729 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3569 "annium.tab.cpp"
    break;

  case 103: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 731 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3575 "annium.tab.cpp"
    break;

  case 104: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 733 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3581 "annium.tab.cpp"
    break;

  case 105: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 735 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3587 "annium.tab.cpp"
    break;

  case 106: // parameter-decl: pattern-mod parameter-default-value-opt
#line 737 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3593 "annium.tab.cpp"
    break;

  case 107: // parameter-decl: identifier internal-identifier parameter-default-value-opt
#line 740 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3599 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: internal-identifier parameter-default-value-opt
#line 744 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[1].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < annium::context_identifier > ().name.location) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3605 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: "`_`" parameter-default-value-opt
#line 746 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3611 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 748 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3617 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: "`...`" parameter-default-value-opt
#line 750 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3623 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 755 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3629 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 757 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3635 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 759 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3641 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 761 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3647 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 763 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3653 "annium.tab.cpp"
    break;

  case 117: // constraint-expression-specified-mod: "constexpr modifier"
#line 767 "annium.y"
                { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::any_constexpr_type }; }
#line 3659 "annium.tab.cpp"
    break;

  case 118: // constraint-expression-specified-mod: "runctime modifier"
#line 768 "annium.y"
              { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3665 "annium.tab.cpp"
    break;

  case 119: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 773 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3671 "annium.tab.cpp"
    break;

  case 120: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 775 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3677 "annium.tab.cpp"
    break;

  case 121: // constraint-expression-specified: constraint-expression-specified-mod
#line 779 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ())) }}, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3683 "annium.tab.cpp"
    break;

  case 122: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 781 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3689 "annium.tab.cpp"
    break;

  case 123: // constraint-expression-mod: %empty
#line 786 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ sonia::lang::lex::resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource() }, parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3698 "annium.tab.cpp"
    break;

  case 124: // constraint-expression-mod: constraint-expression-specified-mod
#line 790 "annium.y"
      { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (); }
#line 3704 "annium.tab.cpp"
    break;

  case 125: // constraint-expression: constraint-expression-mod type-expr
#line 795 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3710 "annium.tab.cpp"
    break;

  case 126: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 797 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3716 "annium.tab.cpp"
    break;

  case 127: // constraint-expression: constraint-expression-mod
#line 801 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) } }, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3722 "annium.tab.cpp"
    break;

  case 128: // constraint-expression: constraint-expression-mod "`...`"
#line 803 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3728 "annium.tab.cpp"
    break;

  case 129: // subpatterns: "`(`" pattern-list "`)`"
#line 813 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[1].value.as < pattern_list_t > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3734 "annium.tab.cpp"
    break;

  case 130: // pattern-list: pattern-field
#line 818 "annium.y"
        { yylhs.value.as < pattern_list_t > () = pattern_list_t{ std::move(yystack_[0].value.as < pattern_t::field > ()) }; }
#line 3740 "annium.tab.cpp"
    break;

  case 131: // pattern-list: pattern-list "," pattern-field
#line 820 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[2].value.as < pattern_list_t > ()); yylhs.value.as < pattern_list_t > ().emplace_back(std::move(yystack_[0].value.as < pattern_t::field > ())); }
#line 3746 "annium.tab.cpp"
    break;

  case 132: // pattern-field-sfx: concept-expression-list-opt
#line 826 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3752 "annium.tab.cpp"
    break;

  case 133: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 828 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3758 "annium.tab.cpp"
    break;

  case 134: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 831 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3764 "annium.tab.cpp"
    break;

  case 135: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 833 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3770 "annium.tab.cpp"
    break;

  case 136: // pattern-field-sfx: "`=`" pattern-sfx
#line 837 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3776 "annium.tab.cpp"
    break;

  case 137: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 840 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3782 "annium.tab.cpp"
    break;

  case 138: // pattern-field: identifier pattern-field-sfx
#line 846 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3788 "annium.tab.cpp"
    break;

  case 139: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 849 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3794 "annium.tab.cpp"
    break;

  case 140: // pattern-field: pattern-field-sfx
#line 862 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ }; }
#line 3800 "annium.tab.cpp"
    break;

  case 141: // pattern-field: "`_`" pattern-field-sfx
#line 865 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3806 "annium.tab.cpp"
    break;

  case 142: // pattern-mod: "`~`" pattern-sfx
#line 869 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3812 "annium.tab.cpp"
    break;

  case 143: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 870 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3818 "annium.tab.cpp"
    break;

  case 144: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 871 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3824 "annium.tab.cpp"
    break;

  case 145: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 872 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3830 "annium.tab.cpp"
    break;

  case 146: // pattern-mod: "`~`" "typename modifier"
#line 873 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3836 "annium.tab.cpp"
    break;

  case 147: // pattern-mod: "typename modifier" pattern-sfx
#line 874 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3842 "annium.tab.cpp"
    break;

  case 148: // pattern-mod: "typename modifier"
#line 875 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3848 "annium.tab.cpp"
    break;

  case 149: // pattern-sfx: pattern
#line 879 "annium.y"
              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < pattern_t > ()), parameter_constraint_modifier_t::none }; }
#line 3854 "annium.tab.cpp"
    break;

  case 150: // pattern-sfx: pattern "`...`"
#line 880 "annium.y"
                       { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < pattern_t > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3860 "annium.tab.cpp"
    break;

  case 151: // pattern-sfx: "`...`"
#line 881 "annium.y"
               { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3866 "annium.tab.cpp"
    break;

  case 152: // pattern: qname
#line 886 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3872 "annium.tab.cpp"
    break;

  case 153: // pattern: qname subpatterns concept-expression-list-opt
#line 888 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[2].value.as < annium::annotated_qname > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3878 "annium.tab.cpp"
    break;

  case 154: // pattern: internal-identifier concept-expression-list-opt
#line 890 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[1].value.as < annium::context_identifier > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3884 "annium.tab.cpp"
    break;

  case 155: // pattern: "`_`" concept-expression-list-opt
#line 892 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3890 "annium.tab.cpp"
    break;

  case 156: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 894 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }, .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3896 "annium.tab.cpp"
    break;

  case 157: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 896 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[2].value.as < syntax_expression_t > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3902 "annium.tab.cpp"
    break;

  case 158: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 898 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[3].value.as < syntax_expression_t > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 3908 "annium.tab.cpp"
    break;

  case 159: // pattern: concept-expression-list
#line 900 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{}, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 3914 "annium.tab.cpp"
    break;

  case 160: // concept-expression: "`@`" qname
#line 905 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = syntax_expression_t{ qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 3920 "annium.tab.cpp"
    break;

  case 161: // concept-expression-list-opt: %empty
#line 910 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = {}; }
#line 3926 "annium.tab.cpp"
    break;

  case 162: // concept-expression-list-opt: concept-expression-list
#line 911 "annium.y"
      { yylhs.value.as < concept_expression_list_t > () = yystack_[0].value.as < concept_expression_list_t > (); }
#line 3932 "annium.tab.cpp"
    break;

  case 163: // concept-expression-list: concept-expression
#line 916 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = concept_expression_list_t{std::move(yystack_[0].value.as < syntax_expression_t > ())}; }
#line 3938 "annium.tab.cpp"
    break;

  case 164: // concept-expression-list: concept-expression-list concept-expression
#line 918 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = std::move(yystack_[1].value.as < concept_expression_list_t > ()); yylhs.value.as < concept_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3944 "annium.tab.cpp"
    break;

  case 165: // reference-expression: CONTEXT_IDENTIFIER
#line 924 "annium.y"
        { yylhs.value.as < reference_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3950 "annium.tab.cpp"
    break;

  case 166: // reference-expression: qname
#line 926 "annium.y"
        { yylhs.value.as < reference_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 3956 "annium.tab.cpp"
    break;

  case 167: // syntax-expression: "nil"
#line 931 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_nil > ()); }
#line 3962 "annium.tab.cpp"
    break;

  case 168: // syntax-expression: "true"
#line 933 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3968 "annium.tab.cpp"
    break;

  case 169: // syntax-expression: "false"
#line 935 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 3974 "annium.tab.cpp"
    break;

  case 170: // syntax-expression: INTEGER
#line 937 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_integer > ()); }
#line 3980 "annium.tab.cpp"
    break;

  case 171: // syntax-expression: DECIMAL
#line 939 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3986 "annium.tab.cpp"
    break;

  case 172: // syntax-expression: DECIMAL_S
#line 941 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 3992 "annium.tab.cpp"
    break;

  case 173: // syntax-expression: INTEGER_INDEX
#line 943 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annotated_decimal{ ctx.make_decimal(yystack_[0].value.as < annium::annotated_string_view > ().value), yystack_[0].value.as < annium::annotated_string_view > ().location }; }
#line 3998 "annium.tab.cpp"
    break;

  case 174: // syntax-expression: STRING
#line 945 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 4004 "annium.tab.cpp"
    break;

  case 175: // syntax-expression: RESERVED_IDENTIFIER
#line 947 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4010 "annium.tab.cpp"
    break;

  case 176: // syntax-expression: CONTEXT_IDENTIFIER
#line 949 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4016 "annium.tab.cpp"
    break;

  case 177: // syntax-expression: CT_IDENTIFIER
#line 951 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4022 "annium.tab.cpp"
    break;

  case 178: // syntax-expression: qname
#line 953 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4028 "annium.tab.cpp"
    break;

  case 179: // syntax-expression: "`(`" "`)`"
#line 955 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4034 "annium.tab.cpp"
    break;

  case 180: // syntax-expression: "`(`" "`:`" syntax-expression "`)`"
#line 957 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[3].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, named_expression_list_t{ named_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()) } } };
        }
#line 4043 "annium.tab.cpp"
    break;

  case 181: // syntax-expression: "`(`" pack-expression "`)`"
#line 962 "annium.y"
        {
            if (yystack_[1].value.as < named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) };
            }
        }
#line 4056 "annium.tab.cpp"
    break;

  case 182: // syntax-expression: "`[`" expression-list "`]`"
#line 971 "annium.y"
        { 
            if (yystack_[1].value.as < expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression_t > () = bracket_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > ().front()) };
            } else {
                yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )};
            }
        }
#line 4068 "annium.tab.cpp"
    break;

  case 183: // syntax-expression: "`[`" braced-statements "`]`"
#line 979 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_with_body_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), ctx.push(std::move(yystack_[1].value.as < managed_statement_list > ())) }; }
#line 4074 "annium.tab.cpp"
    break;

  case 184: // syntax-expression: "`[[`" expression-list "`]]`"
#line 981 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )}; }
#line 4080 "annium.tab.cpp"
    break;

  case 185: // syntax-expression: syntax-expression "`[`" syntax-expression "`]`"
#line 983 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4086 "annium.tab.cpp"
    break;

  case 186: // syntax-expression: "`.`" identifier
#line 985 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4092 "annium.tab.cpp"
    break;

  case 187: // syntax-expression: syntax-expression "`.`" identifier
#line 989 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < annium::annotated_identifier > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4098 "annium.tab.cpp"
    break;

  case 188: // syntax-expression: syntax-expression "`.`" apostrophe-expression
#line 991 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4104 "annium.tab.cpp"
    break;

  case 189: // syntax-expression: syntax-expression INTEGER_INDEX
#line 993 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), annotated_integer{ ctx.make_integer(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1)), yystack_[0].value.as < annium::annotated_string_view > ().location } }; IGNORE_TERM(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 4110 "annium.tab.cpp"
    break;

  case 190: // syntax-expression: "`!`" syntax-expression
#line 996 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::NEGATE, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4116 "annium.tab.cpp"
    break;

  case 191: // syntax-expression: "`*`" syntax-expression
#line 998 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::DEREF, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4122 "annium.tab.cpp"
    break;

  case 192: // syntax-expression: syntax-expression "`+`" syntax-expression
#line 1003 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::PLUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4128 "annium.tab.cpp"
    break;

  case 193: // syntax-expression: syntax-expression "`-`" syntax-expression
#line 1005 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::MINUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4134 "annium.tab.cpp"
    break;

  case 194: // syntax-expression: syntax-expression "`==`" syntax-expression
#line 1009 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::EQ, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4140 "annium.tab.cpp"
    break;

  case 195: // syntax-expression: syntax-expression "`!=`" syntax-expression
#line 1011 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::NE, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4146 "annium.tab.cpp"
    break;

  case 196: // syntax-expression: syntax-expression "`..`" syntax-expression
#line 1013 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::CONCAT, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4152 "annium.tab.cpp"
    break;

  case 197: // syntax-expression: syntax-expression "`&`" syntax-expression
#line 1016 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4158 "annium.tab.cpp"
    break;

  case 198: // syntax-expression: syntax-expression "`|`" syntax-expression
#line 1020 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4164 "annium.tab.cpp"
    break;

  case 199: // syntax-expression: syntax-expression "`&&`" syntax-expression
#line 1023 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4170 "annium.tab.cpp"
    break;

  case 200: // syntax-expression: syntax-expression "`||`" syntax-expression
#line 1026 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4176 "annium.tab.cpp"
    break;

  case 201: // syntax-expression: apostrophe-expression
#line 1028 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4182 "annium.tab.cpp"
    break;

  case 202: // syntax-expression: new-expression
#line 1029 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4188 "annium.tab.cpp"
    break;

  case 203: // syntax-expression: compound-expression
#line 1030 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4194 "annium.tab.cpp"
    break;

  case 204: // syntax-expression: lambda-expression
#line 1031 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4200 "annium.tab.cpp"
    break;

  case 205: // apostrophe-expression: "APOSTROPHE" syntax-expression "APOSTROPHE"
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < syntax_expression_t > ()); }
#line 4206 "annium.tab.cpp"
    break;

  case 206: // new-expression: "`new`" qname
#line 1041 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 4212 "annium.tab.cpp"
    break;

  case 207: // new-expression: "`new`" apostrophe-expression
#line 1043 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 4218 "annium.tab.cpp"
    break;

  case 208: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1045 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4224 "annium.tab.cpp"
    break;

  case 209: // new-expression: "`new`" apostrophe-expression "`(`" argument-list-opt "`)`"
#line 1047 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4230 "annium.tab.cpp"
    break;

  case 210: // call-expression: qname "`(`" pack-expression-opt "`)`"
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4236 "annium.tab.cpp"
    break;

  case 211: // call-expression: CONTEXT_IDENTIFIER "`(`" pack-expression-opt "`)`"
#line 1054 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), name_reference{ ctx.make_identifier(std::move(yystack_[3].value.as < annium::annotated_string_view > ())) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4242 "annium.tab.cpp"
    break;

  case 212: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1056 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4248 "annium.tab.cpp"
    break;

  case 213: // call-expression: apostrophe-expression "`(`" pack-expression "`)`"
#line 1058 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4254 "annium.tab.cpp"
    break;

  case 214: // call-expression: lambda-expression "`(`" pack-expression "`)`"
#line 1060 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4260 "annium.tab.cpp"
    break;

  case 215: // lambda-start-decl: fn-prefix-decl
#line 1066 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) } }; }
#line 4266 "annium.tab.cpp"
    break;

  case 216: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1068 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) }, {}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4272 "annium.tab.cpp"
    break;

  case 217: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1073 "annium.y"
        { 
            yystack_[4].value.as < lambda_t > ().parameters = std::move(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[4].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4283 "annium.tab.cpp"
    break;

  case 218: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1080 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < syntax_expression_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4295 "annium.tab.cpp"
    break;

  case 219: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1088 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < pattern_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4307 "annium.tab.cpp"
    break;

  case 220: // pack-expression-opt: %empty
#line 1099 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{}; }
#line 4313 "annium.tab.cpp"
    break;

  case 221: // pack-expression-opt: pack-expression
#line 1101 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[0].value.as < named_expression_list_t > ()); }
#line 4319 "annium.tab.cpp"
    break;

  case 222: // pack-expression: syntax-expression
#line 1106 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{ named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) } }; }
#line 4325 "annium.tab.cpp"
    break;

  case 223: // pack-expression: identifier "`:`" syntax-expression
#line 1108 "annium.y"
        {
            named_expression_list_t list{};
            list.emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(list);
        }
#line 4335 "annium.tab.cpp"
    break;

  case 224: // pack-expression: pack-expression "," syntax-expression
#line 1114 "annium.y"
        {
            yystack_[2].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ());
        }
#line 4344 "annium.tab.cpp"
    break;

  case 225: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1119 "annium.y"
        {
            yystack_[4].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[4].value.as < named_expression_list_t > ());
        }
#line 4353 "annium.tab.cpp"
    break;

  case 226: // compound-expression: syntax-expression "`...`"
#line 1127 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::ELLIPSIS, false, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4359 "annium.tab.cpp"
    break;

  case 227: // compound-expression: call-expression
#line 1128 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4365 "annium.tab.cpp"
    break;

  case 228: // type-expr: qname
#line 1170 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4371 "annium.tab.cpp"
    break;

  case 229: // type-expr: RESERVED_IDENTIFIER
#line 1172 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4377 "annium.tab.cpp"
    break;

  case 230: // type-expr: CONTEXT_IDENTIFIER
#line 1174 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4383 "annium.tab.cpp"
    break;

  case 231: // type-expr: call-expression
#line 1175 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4389 "annium.tab.cpp"
    break;

  case 232: // type-expr: "`[`" type-expr "`]`"
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = bracket_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < syntax_expression_t > ())}; }
#line 4395 "annium.tab.cpp"
    break;

  case 233: // type-expr: "`(`" "`)`"
#line 1181 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4401 "annium.tab.cpp"
    break;

  case 234: // type-expr: "`(`" pack-expression "`)`"
#line 1183 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4407 "annium.tab.cpp"
    break;

  case 235: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1185 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4413 "annium.tab.cpp"
    break;

  case 236: // type-expr: type-expr "`|`" type-expr
#line 1187 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4419 "annium.tab.cpp"
    break;

  case 237: // type-expr: type-expr "`->`" type-expr
#line 1189 "annium.y"
        { 
            auto loc = get_start_location(yystack_[2].value.as < syntax_expression_t > ());
            yylhs.value.as < syntax_expression_t > () = annium_fn_type_t{ named_expression_list_t{ named_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()) } }, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) };
        }
#line 4428 "annium.tab.cpp"
    break;


#line 4432 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -272;

  const signed char parser::yytable_ninf_ = -101;

  const short
  parser::yypact_[] =
  {
     725,  -272,  -272,   -10,  -272,  -272,  -272,  -272,  -272,  -272,
     961,    83,   827,   843,   961,    83,   961,   961,     2,   -41,
      31,   961,    33,   961,    29,    44,     4,  -272,    88,    29,
      29,  -272,  -272,  -272,   126,    30,   419,  -272,  -272,  -272,
    -272,   180,   149,   729,    89,  -272,    93,   105,   115,   131,
     961,   129,  1011,  -272,  -272,   961,  -272,   144,  1153,   -29,
     623,   193,   178,  1153,   138,  -272,   185,   185,    83,  -272,
     192,   182,  -272,    83,    88,   186,   203,   628,  -272,   222,
     201,   511,   278,  -272,  -272,  -272,  -272,   222,   249,  -272,
     210,  -272,   284,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,    83,   961,   961,   127,     7,  -272,   961,   961,   961,
     961,   961,   961,  -272,   961,    50,   961,   961,   961,   961,
     961,   961,   437,   961,   259,   248,  -272,  1048,   961,  -272,
     961,  -272,  -272,   961,   961,   271,   521,  -272,   282,  -272,
    -272,  -272,  -272,   961,  -272,  -272,   370,   961,   291,  -272,
     961,   961,   961,  -272,   961,   261,   961,   437,   437,    83,
     299,   437,  -272,   310,   287,   370,   452,   961,  -272,  1153,
     305,   305,  1200,  1190,   150,  1058,  -272,  -272,   185,   185,
     854,   715,   -17,   151,  -272,   354,   354,   373,   386,   605,
    -272,  -272,   365,   292,   330,   332,  -272,   276,   354,   354,
     155,  -272,  -272,  1153,   345,  1153,  1153,  1153,  -272,  -272,
    -272,  -272,  -272,  1153,   -10,  -272,   945,   370,   180,    89,
      93,   115,   235,   248,   370,    -4,   349,   342,  -272,   961,
    1153,   351,   511,   511,   363,  1153,   367,   371,  -272,   383,
     372,  -272,    83,   396,  -272,  -272,   235,    29,    10,   961,
     430,   337,  -272,  -272,   430,  1153,  -272,  -272,  -272,   961,
    -272,  -272,  -272,   549,   354,   354,  -272,   605,   605,   605,
    -272,   414,  -272,    14,    -2,   354,   373,  -272,   361,   437,
    -272,   328,  -272,  -272,  -272,   961,  -272,   173,   321,   370,
     961,   370,   235,  -272,  -272,  -272,   961,  1153,  -272,  -272,
    -272,  -272,   431,  -272,  -272,    83,    77,   405,   390,  -272,
     435,   222,   258,   430,  -272,   430,  1095,  -272,   430,  -272,
    1153,  -272,   428,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
     373,   411,  -272,   354,   354,   370,   961,   452,  -272,  -272,
    -272,  -272,  1153,  -272,  -272,  -272,  1105,    -1,  -272,   961,
    -272,   961,   370,  -272,    83,   413,   605,   382,   365,   382,
     338,   175,  -272,  -272,   427,  -272,    10,  -272,  -272,   354,
     354,   373,  -272,  -272,   387,  1143,    43,  -272,  1153,  1153,
     251,  -272,    83,  -272,  -272,   382,  -272,   605,   433,  -272,
     258,  -272,   430,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,   961,  -272,   436,  -272,  -272,  -272,  -272,  -272,  1153,
    -272
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   174,    53,   176,   175,   177,   173,   170,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,   167,   168,   169,     0,     0,     0,     5,     7,    14,
      56,   178,   215,     0,   201,   202,   227,     0,   204,   203,
     220,   215,     0,   203,    55,     0,   179,    56,   222,     0,
      22,     0,     0,    76,     0,   186,   191,   190,     0,    41,
      20,    16,    18,     0,     0,   206,   207,     0,   165,   166,
       0,     0,     0,    44,    13,    59,    61,    60,     0,    42,
       0,    38,     0,    15,     1,     2,    10,     3,     8,     6,
       9,     0,   220,   220,    63,     0,   189,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,   221,   205,     0,     0,   181,
       0,    49,    48,    50,     0,    39,    40,    25,     0,    47,
      23,   183,   182,     0,   184,    19,     0,     0,     0,    12,
      78,    78,     0,    32,     0,    35,     0,    94,    94,    67,
       0,    94,    57,     0,     0,     0,     0,     0,    37,    46,
     194,   195,   199,   200,   196,     0,   187,   188,   192,   193,
     197,   198,     0,     0,    54,   100,   100,   123,     0,   148,
     117,   118,    98,   100,     0,    95,    96,   121,   100,   100,
       0,   211,   180,   223,    56,   224,    51,    52,    28,    26,
      27,    24,    31,    77,   230,   229,     0,     0,   228,     0,
     231,     0,    21,    17,     0,    56,     0,    79,    80,     0,
      83,     0,     0,     0,     0,    74,     0,     0,    71,     0,
      68,    69,    86,     0,   210,   216,    64,     0,   161,     0,
     161,   152,    65,   163,   159,    43,   185,   213,   212,     0,
     109,   111,   124,   127,   100,   100,   151,   146,     0,     0,
     142,   149,   147,    99,     0,   100,   123,   108,     0,     0,
     122,   119,   116,   106,   214,     0,   233,     0,     0,     0,
       0,     0,    11,    84,    85,   208,     0,    82,   209,    33,
      34,    36,     0,    62,    66,     0,     0,     0,    87,    88,
       0,   160,   161,   161,   155,   162,     0,   154,   161,   164,
     101,   128,   125,   115,   105,   145,   143,   144,   150,   107,
     123,     0,   110,   100,   100,     0,     0,     0,   217,    29,
      97,   120,   225,   234,   232,   237,     0,   236,    81,     0,
      70,     0,     0,    72,     0,     0,     0,   161,     0,   161,
     161,     0,   140,   130,   132,   156,   161,   153,   126,   100,
     100,   123,   114,   104,     0,     0,     0,   235,    75,    93,
      90,    89,    86,   136,   141,   161,   138,     0,   134,   129,
     161,   133,   161,   157,   112,   102,   113,   103,   218,    30,
     219,     0,    92,     0,   139,   137,   135,   131,   158,    91,
      73
  };

  const short
  parser::yypgoto_[] =
  {
    -272,  -272,  -272,  -272,   443,  -272,  -272,  -272,  -272,  -272,
     -83,    20,   -14,  -272,   -45,   346,    56,   -96,    53,     9,
    -272,   456,   416,  -272,  -272,  -272,   187,  -272,  -272,   477,
     350,  -272,   207,  -272,   122,  -272,  -272,   154,   152,  -272,
    -272,    81,   227,  -186,  -272,  -272,  -271,  -245,  -272,  -187,
     119,  -184,  -182,  -162,  -236,  -198,  -164,  -272,     0,    23,
    -272,   -33,  -272,    15,   293,    19,    12,    71
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    34,    35,    36,    37,    69,    70,    71,   135,   136,
     338,   339,    38,   138,    39,   140,    40,   250,    41,    51,
      88,   104,   105,    91,   239,   240,   241,    93,    83,    62,
     226,   227,   228,   229,   307,   308,   402,   309,   194,   195,
     274,   260,   196,   197,   198,   263,   264,   313,   361,   362,
     363,   199,   270,   271,   253,   364,   315,    80,    58,    44,
      45,    46,    47,    48,   124,   125,    53,   222
  };

  const short
  parser::yytable_[] =
  {
      43,   262,   254,   265,   252,   333,   318,   272,     2,    42,
      52,   293,    49,    63,    63,   139,    66,    67,   319,   289,
     129,    77,   100,    81,   254,   254,   193,   247,   167,   259,
      95,    59,   257,    61,    73,     2,    43,     2,    50,     2,
      78,   130,   294,    76,   330,    42,   137,    10,    49,    84,
     314,   290,   317,   130,    74,   127,     2,    60,   312,   369,
      43,   193,   193,  -100,   336,   193,    10,    54,    57,    42,
     331,    65,    49,    75,    72,    79,    11,    82,    11,   319,
      11,    87,    90,    92,  -100,   325,   326,   327,    96,     2,
     262,   139,   334,    60,     2,    87,   273,   153,   351,    85,
     396,   155,    68,   254,   254,   254,    57,   169,   170,   171,
     172,   173,   174,   220,   175,   365,   178,   179,   180,   181,
     367,   392,   210,   352,   145,   168,    94,    87,   203,   148,
     205,   -45,   220,   206,   207,    11,    43,   120,   177,   182,
     183,   121,   200,   213,   262,    42,   370,   165,    49,   166,
     230,   230,   232,   122,   233,     2,   235,   162,    57,    57,
     106,   221,   388,   123,   220,    86,   223,   255,   393,   219,
     384,   176,   386,   254,   383,   376,    57,    57,   192,    57,
     221,   103,   -45,   193,   220,   262,   204,   397,   219,   -45,
     128,   220,   254,   144,   408,   106,    11,   147,   404,   218,
     258,   103,   114,    57,   284,   405,   225,   225,   143,   115,
     116,   117,   221,   192,   192,   238,   360,   192,   218,   251,
     219,   130,   343,   254,   389,   130,    86,   101,   102,   297,
     220,   142,   221,   101,   150,   287,   246,   114,   146,   221,
     219,   251,   251,   130,   115,   390,   141,   219,   143,   316,
     218,   151,   299,   300,   301,   289,   220,   101,   220,   320,
     159,   360,   385,   360,     2,   184,   401,   261,   281,   101,
     218,   289,    57,   356,   277,   247,   357,   218,   221,   282,
     283,   154,     2,   214,   215,   342,   219,   290,   288,   360,
     346,   398,    10,   400,   360,   292,   230,   158,   306,   156,
     311,   291,   220,   290,   221,   160,   221,   259,   201,   236,
     237,   280,   219,   243,   219,   106,   218,   291,   130,   220,
     251,   251,   251,    11,   216,   101,   157,   275,   217,   208,
     358,   101,   161,   212,   322,   192,   375,   224,   276,   112,
     245,   289,   218,   234,   218,   323,   324,   242,   289,   378,
     221,   379,   225,   387,   329,   247,   332,   114,   219,   244,
     345,   238,   347,   341,   115,   116,   117,   221,   359,   259,
      26,    27,   184,   290,   344,   219,     2,   214,   215,   278,
     290,   335,   336,   337,   101,   312,    10,   291,   218,   184,
     251,   285,     2,   184,   291,   163,   164,   356,   295,   247,
     298,   409,   279,   247,   248,   218,   374,   289,   336,   251,
     306,    60,   296,    60,   372,   373,   302,    11,   216,    97,
     303,   266,   217,   380,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    11,   304,    10,   249,    60,   306,   290,
     251,   188,   305,     2,   184,   310,   359,   247,   289,   328,
     394,   395,   349,   291,   353,   185,   355,   371,     2,   184,
     354,   382,   391,   368,    26,    27,    11,    12,   406,   247,
     248,    13,   186,    14,   189,   190,   191,    98,    15,    99,
     290,    16,   211,   187,    89,   410,    17,   267,   268,   269,
     149,    64,   350,    18,   291,    19,    20,    21,    22,    11,
      23,   231,   249,   348,   403,   188,   340,    24,   381,   407,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,   106,     0,    31,    32,    33,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    10,   189,   190,
     191,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     2,   214,   215,     0,     0,
       0,    60,     0,   114,     0,    10,     0,     0,    11,    12,
     115,   116,   117,    13,     0,    14,   118,   119,     0,   209,
      15,     0,     0,    16,   321,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    18,    11,   216,    20,    21,
      22,   217,    23,     0,   131,   132,   133,   134,     0,    24,
       0,     2,   184,     0,     0,    26,    27,    28,    29,     0,
       0,     0,   247,   248,     0,    31,    32,    33,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,   106,    10,
     266,     0,     0,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,   249,     0,     0,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,    13,     0,    14,    60,     0,
     114,     0,    15,     0,     0,    16,   152,   115,   116,   117,
      17,     0,     0,   118,   119,     0,     0,    18,     0,     0,
      20,    21,    22,     0,    23,     0,   131,   132,   133,   134,
       0,    24,     0,     0,     0,     0,     0,    26,    27,    28,
      29,     0,     0,     0,     0,   106,     0,    31,    32,    33,
       1,     2,     3,     4,     5,     6,     7,     8,     9,   106,
       0,    10,     0,     0,   107,   108,   109,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,     0,     0,   114,     0,     0,
       0,     0,    11,    12,   115,   116,   117,    13,     0,    14,
     118,   114,     0,     0,    15,     0,     0,    16,   115,   116,
     117,     0,    17,     0,   118,   119,     0,     0,     0,    18,
       0,    19,    20,    21,    22,     0,    23,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,    31,
      32,    33,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    10,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    11,    12,    56,     0,     0,    13,
       0,    14,     0,     0,   108,   109,    15,     0,   112,    16,
      11,    12,     0,    60,    17,    13,     0,    14,     0,     0,
       0,     0,    15,     0,    20,    16,   114,     0,     0,     0,
      17,     0,     0,   115,   116,   117,     0,     0,     0,     0,
      20,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     0,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    10,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,   286,     0,     0,    13,     0,    14,
       0,     0,     0,     0,    15,     0,     0,    16,    11,    12,
       0,     0,    17,    13,     0,    14,     0,     0,     0,     0,
      15,   106,    20,    16,     0,     0,     0,   126,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    26,
      27,   108,   109,   110,   111,   112,   113,     0,     0,    31,
      32,    33,     0,     0,     0,    26,    27,     0,   106,     0,
       0,     0,     0,   114,     0,    31,    32,    33,   106,     0,
     115,   116,   117,     0,     0,     0,   118,   119,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   202,     0,     0,
     114,     0,     0,     0,     0,   106,     0,   115,   116,   117,
     114,   256,     0,   118,   119,   106,     0,   115,   116,   117,
       0,     0,     0,   118,   119,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,   366,   114,     0,     0,
       0,     0,     0,   106,   115,   116,   117,   114,   377,   399,
     118,   119,     0,   106,   115,   116,   117,     0,     0,     0,
     118,   119,     0,   108,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
     106,     0,   115,   116,   117,   114,     0,     0,   118,   119,
     106,     0,   115,   116,   117,     0,     0,     0,   118,   119,
     108,   109,   110,     0,   112,     0,     0,     0,     0,     0,
     108,   109,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   114,     0,     0,   118,   119,     0,     0,   115,
     116,   117,     0,     0,     0,   118,   119
  };

  const short
  parser::yycheck_[] =
  {
       0,   187,   166,   187,   166,   276,   251,   189,     6,     0,
      10,    15,     0,    13,    14,    60,    16,    17,   254,    20,
      49,    21,    36,    23,   188,   189,   122,    17,    21,    15,
       0,    12,    49,    13,    75,     6,    36,     6,    48,     6,
       7,    70,    46,    20,    46,    36,    60,    16,    36,     5,
     248,    52,   250,    70,    95,    55,     6,    50,    48,   330,
      60,   157,   158,    49,    21,   161,    16,    11,    12,    60,
      72,    15,    60,    20,    18,    22,    47,    24,    47,   315,
      47,    28,    29,    30,    70,   267,   268,   269,    58,     6,
     276,   136,   276,    50,     6,    42,   192,    77,    21,    95,
     371,    81,   100,   267,   268,   269,    50,   107,   108,   109,
     110,   111,   112,   146,   114,   313,   116,   117,   118,   119,
     318,   366,   136,    46,    68,   105,     0,    74,   128,    73,
     130,     0,   165,   133,   134,    47,   136,    48,   115,   120,
     121,    48,   123,   143,   330,   136,   330,    20,   136,    22,
     150,   151,   152,    48,   154,     6,   156,   101,   102,   103,
      10,   146,   360,    48,   197,    77,   147,   167,   366,   146,
     357,   115,   359,   337,   356,   337,   120,   121,   122,   123,
     165,    52,    51,   279,   217,   371,   130,   371,   165,    58,
      46,   224,   356,    55,   392,    10,    47,    15,   385,   146,
      49,    52,    52,   147,    49,   387,   150,   151,    70,    59,
      60,    61,   197,   157,   158,   159,   312,   161,   165,   166,
     197,    70,    49,   387,    49,    70,    77,    47,    48,   229,
     263,    53,   217,    47,    48,   216,   165,    52,    46,   224,
     217,   188,   189,    70,    59,    70,    53,   224,    70,   249,
     197,    48,   232,   233,   234,    20,   289,    47,   291,   259,
      50,   357,   358,   359,     6,     7,    15,   186,   197,    47,
     217,    20,   216,    15,   193,    17,    18,   224,   263,   198,
     199,    80,     6,     7,     8,   285,   263,    52,   217,   385,
     290,   374,    16,   376,   390,   224,   296,    48,   242,    21,
     247,    66,   335,    52,   289,    21,   291,    15,    49,   157,
     158,    35,   289,   161,   291,    10,   263,    66,    70,   352,
     267,   268,   269,    47,    48,    47,    48,    35,    52,    58,
      72,    47,    48,    51,   263,   279,   336,    46,    46,    34,
      53,    20,   289,    82,   291,   264,   265,    48,    20,   349,
     335,   351,   296,    15,   273,    17,   275,    52,   335,    49,
     289,   305,   291,    35,    59,    60,    61,   352,   312,    15,
      94,    95,     7,    52,    53,   352,     6,     7,     8,    49,
      52,    20,    21,    22,    47,    48,    16,    66,   335,     7,
     337,    46,     6,     7,    66,   102,   103,    15,    49,    17,
      49,   401,    70,    17,    18,   352,   335,    20,    21,   356,
     354,    50,    70,    50,   333,   334,    49,    47,    48,     0,
      49,    35,    52,   352,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    47,    51,    16,    50,    50,   382,    52,
     387,    68,    70,     6,     7,    49,   390,    17,    20,    35,
     369,   370,    21,    66,    49,    18,    21,    46,     6,     7,
      70,    48,    35,    35,    94,    95,    47,    48,    35,    17,
      18,    52,    35,    54,   101,   102,   103,    58,    59,    36,
      52,    62,   136,    46,    28,    49,    67,   101,   102,   103,
      74,    14,   305,    74,    66,    76,    77,    78,    79,    47,
      81,   151,    50,   296,   382,    68,   279,    88,   354,   390,
      -1,    -1,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    10,    -1,   104,   105,   106,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,   101,   102,
     103,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    -1,
      -1,    50,    -1,    52,    -1,    16,    -1,    -1,    47,    48,
      59,    60,    61,    52,    -1,    54,    65,    66,    -1,    58,
      59,    -1,    -1,    62,    35,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    47,    48,    77,    78,
      79,    52,    81,    -1,    83,    84,    85,    86,    -1,    88,
      -1,     6,     7,    -1,    -1,    94,    95,    96,    97,    -1,
      -1,    -1,    17,    18,    -1,   104,   105,   106,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    10,    16,
      35,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    50,    -1,
      52,    -1,    59,    -1,    -1,    62,    58,    59,    60,    61,
      67,    -1,    -1,    65,    66,    -1,    -1,    74,    -1,    -1,
      77,    78,    79,    -1,    81,    -1,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    10,    -1,   104,   105,   106,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    10,
      -1,    16,    -1,    -1,    15,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    47,    48,    59,    60,    61,    52,    -1,    54,
      65,    52,    -1,    -1,    59,    -1,    -1,    62,    59,    60,
      61,    -1,    67,    -1,    65,    66,    -1,    -1,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,
      -1,    54,    -1,    -1,    30,    31,    59,    -1,    34,    62,
      47,    48,    -1,    50,    67,    52,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    77,    62,    52,    -1,    -1,    -1,
      67,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      77,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    -1,    54,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    47,    48,
      -1,    -1,    67,    52,    -1,    54,    -1,    -1,    -1,    -1,
      59,    10,    77,    62,    -1,    -1,    -1,    16,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    94,
      95,    30,    31,    32,    33,    34,    35,    -1,    -1,   104,
     105,   106,    -1,    -1,    -1,    94,    95,    -1,    10,    -1,
      -1,    -1,    -1,    52,    -1,   104,   105,   106,    10,    -1,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    10,    -1,    59,    60,    61,
      52,    53,    -1,    65,    66,    10,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    10,    59,    60,    61,    52,    53,    16,
      65,    66,    -1,    10,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      10,    -1,    59,    60,    61,    52,    -1,    -1,    65,    66,
      10,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    52,    -1,    -1,    65,    66,    -1,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    47,    48,    52,    54,    59,    62,    67,    74,    76,
      77,    78,    79,    81,    88,    93,    94,    95,    96,    97,
      98,   104,   105,   106,   108,   109,   110,   111,   119,   121,
     123,   125,   126,   165,   166,   167,   168,   169,   170,   173,
      48,   126,   165,   173,   123,    46,    49,   123,   165,   172,
      50,   118,   136,   165,   136,   123,   165,   165,   100,   112,
     113,   114,   123,    75,    95,   125,   166,   165,     7,   125,
     164,   165,   125,   135,     5,    95,    77,   125,   127,   128,
     125,   130,   125,   134,     0,     0,    58,     0,    58,   111,
     119,    47,    48,    52,   128,   129,    10,    15,    30,    31,
      32,    33,    34,    35,    52,    59,    60,    61,    65,    66,
      48,    48,    48,    48,   171,   172,    16,   165,    46,    49,
      70,    83,    84,    85,    86,   115,   116,   119,   120,   121,
     122,    53,    53,    70,    55,   123,    46,    15,   123,   129,
      48,    48,    58,   118,    80,   118,    21,    48,    48,    50,
      21,    48,   123,   171,   171,    20,    22,    21,   118,   165,
     165,   165,   165,   165,   165,   165,   123,   166,   165,   165,
     165,   165,   172,   172,     7,    18,    35,    46,    68,   101,
     102,   103,   123,   124,   145,   146,   149,   150,   151,   158,
     172,    49,    49,   165,   123,   165,   165,   165,    58,    58,
     119,   122,    51,   165,     7,     8,    48,    52,   125,   166,
     168,   170,   174,   172,    46,   123,   137,   138,   139,   140,
     165,   137,   165,   165,    82,   165,   145,   145,   123,   131,
     132,   133,    48,   145,    49,    53,   174,    17,    18,    50,
     124,   125,   160,   161,   163,   165,    53,    49,    49,    15,
     148,   148,   150,   152,   153,   158,    35,   101,   102,   103,
     159,   160,   159,   124,   147,    35,    46,   148,    49,    70,
      35,   174,   148,   148,    49,    46,    49,   172,   174,    20,
      52,    66,   174,    15,    46,    49,    70,   165,    49,   118,
     118,   118,    49,    49,    51,    70,   123,   141,   142,   144,
      49,   125,    48,   154,   162,   163,   165,   162,   154,   161,
     165,    35,   174,   148,   148,   159,   159,   159,    35,   148,
      46,    72,   148,   153,   158,    20,    21,    22,   117,   118,
     149,    35,   165,    49,    53,   174,   165,   174,   139,    21,
     133,    21,    46,    49,    70,    21,    15,    18,    72,   123,
     124,   155,   156,   157,   162,   162,    51,   162,    35,   153,
     158,    46,   148,   148,   174,   165,   160,    53,   165,   165,
     174,   144,    48,   159,   156,   124,   156,    15,   162,    49,
      70,    35,   154,   162,   148,   148,   153,   158,   117,    16,
     117,    15,   143,   141,   156,   159,    35,   157,   162,   165,
      49
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   107,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   117,
     117,   118,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   123,   124,   125,   125,   125,   126,   126,
     127,   127,   128,   129,   129,   129,   130,   131,   131,   132,
     132,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   151,
     151,   151,   151,   152,   152,   153,   153,   153,   153,   154,
     155,   155,   156,   156,   156,   156,   156,   156,   157,   157,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   159,
     159,   159,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   167,   167,   167,   167,
     168,   168,   168,   168,   168,   169,   169,   170,   170,   170,
     171,   171,   172,   172,   172,   172,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     3,     0,     1,     2,     1,     2,     2,     2,     1,
       3,     3,     3,     5,     5,     3,     5,     3,     2,     1,
       1,     2,     2,     4,     2,     1,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     4,     1,     3,     3,     4,     0,     1,     1,
       3,     1,     5,     8,     3,     6,     1,     3,     0,     1,
       1,     3,     2,     1,     2,     2,     0,     1,     1,     3,
       0,     2,     4,     3,     0,     1,     1,     3,     0,     1,
       0,     2,     5,     5,     4,     3,     2,     3,     2,     2,
       3,     2,     5,     5,     4,     3,     2,     1,     1,     2,
       3,     1,     2,     0,     1,     2,     3,     1,     2,     3,
       1,     3,     1,     2,     2,     3,     2,     3,     2,     3,
       1,     2,     2,     3,     3,     3,     2,     2,     1,     1,
       2,     1,     1,     3,     2,     2,     3,     4,     5,     1,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     3,     3,     3,     4,     2,     3,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     2,     2,     5,     5,
       4,     4,     4,     4,     4,     1,     4,     5,     7,     7,
       0,     1,     1,     3,     3,     5,     2,     1,     1,     1,
       1,     1,     3,     2,     3,     4,     3,     3
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
  "\"`continue`\"", "\"`break`\"", "\"`return`\"", "\"`yield`\"", "AUTO",
  "USING", "THROW", "SIZEOF", "LOWEST", "DEREF", "INCLUDE", "INLINE",
  "\"`fn`\"", "\"`typefn`\"", "ENUM", "STRUCT", "EXTENDS",
  "\"weak modifier\"", "\"typename modifier\"", "\"constexpr modifier\"",
  "\"runctime modifier\"", "\"nil\"", "\"true\"", "\"false\"", "$accept",
  "begin", "statement_any", "finished-statement-any", "statement",
  "let-decl", "let-decl-start", "let-decl-start-with-opt-type",
  "infunction-statement-any", "finished-infunction-statement-any",
  "function-body", "braced-statements", "finished-statement",
  "infunction-statement-set", "generic-statement", "infunction-statement",
  "identifier", "internal-identifier", "qname", "fn-prefix-decl",
  "fn-name", "fn-start-decl", "fn-decl", "enum-decl", "case-list-opt",
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
  "reference-expression", "syntax-expression", "apostrophe-expression",
  "new-expression", "call-expression", "lambda-start-decl",
  "lambda-expression", "pack-expression-opt", "pack-expression",
  "compound-expression", "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   338,   338,   339,   343,   345,   347,   364,   366,   367,
     369,   374,   376,   378,   380,   382,   387,   389,   394,   396,
     401,   402,   407,   409,   411,   416,   418,   419,   421,   427,
     429,   439,   444,   446,   448,   450,   452,   454,   464,   469,
     471,   476,   478,   480,   489,   491,   493,   498,   500,   502,
     504,   506,   508,   513,   521,   536,   538,   540,   546,   548,
     553,   554,   558,   562,   563,   565,   572,   577,   578,   582,
     584,   589,   595,   597,   620,   627,   645,   647,   653,   654,
     658,   660,   665,   667,   672,   674,   680,   681,   685,   687,
     692,   693,   697,   699,   706,   707,   711,   713,   718,   719,
     723,   724,   728,   730,   732,   734,   736,   739,   743,   745,
     747,   749,   754,   756,   758,   760,   762,   767,   768,   772,
     774,   778,   780,   785,   790,   794,   796,   800,   802,   812,
     817,   819,   825,   827,   830,   832,   836,   839,   845,   848,
     861,   864,   869,   870,   871,   872,   873,   874,   875,   879,
     880,   881,   885,   887,   889,   891,   893,   895,   897,   899,
     904,   909,   911,   915,   917,   923,   925,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   948,   950,   952,   954,
     956,   961,   970,   978,   980,   982,   984,   988,   990,   992,
     995,   997,  1002,  1004,  1008,  1010,  1012,  1015,  1019,  1022,
    1025,  1028,  1029,  1030,  1031,  1035,  1040,  1042,  1044,  1046,
    1051,  1053,  1055,  1057,  1059,  1065,  1067,  1072,  1079,  1087,
    1098,  1100,  1105,  1107,  1113,  1118,  1126,  1128,  1169,  1171,
    1173,  1175,  1178,  1180,  1182,  1184,  1186,  1188
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
     105,   106
    };
    // Last valid token kind.
    const int code_max = 361;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 5443 "annium.tab.cpp"

#line 1515 "annium.y"

