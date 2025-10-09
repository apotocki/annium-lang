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
      case symbol_kind::S_147_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.copy< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.copy< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.copy< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.copy< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.copy< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.copy< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.copy< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.copy< optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.copy< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.copy< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.copy< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.copy< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
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
        value.copy< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< optional<syntax_expression_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
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
        value.move< syntax_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.YY_MOVE_OR_COPY< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.YY_MOVE_OR_COPY< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.YY_MOVE_OR_COPY< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.YY_MOVE_OR_COPY< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.YY_MOVE_OR_COPY< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.YY_MOVE_OR_COPY< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annium::annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< annium::identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.move< expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.move< finished_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.move< generic_statement_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.move< named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< optional<syntax_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< pattern_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< pattern_t::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< sonia::lang::lex::resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<annium::identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
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
        value.move< syntax_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.copy< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.copy< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.copy< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.copy< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.copy< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.copy< expression_list_t > (that.value);
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.copy< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field_t > (that.value);
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.copy< field_t::default_spec > (that.value);
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.copy< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.copy< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.copy< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.copy< lambda_t > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.copy< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.copy< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< named_expression_t > (that.value);
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.copy< optional<syntax_expression_t> > (that.value);
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.copy< parameter_t > (that.value);
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter_t::default_spec > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.copy< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< pattern_t > (that.value);
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.copy< pattern_t::field > (that.value);
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.copy< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.copy< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.copy< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.copy< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
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
        value.copy< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annium::annotated_identifier > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer > (that.value);
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< annium::context_identifier > (that.value);
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< annium::identifier > (that.value);
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        value.move< annotated_bool > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< concept_expression_list_t > (that.value);
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        value.move< expression_list_t > (that.value);
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< field_list_t > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field_t > (that.value);
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field_t::default_spec > (that.value);
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        value.move< finished_statement_type > (that.value);
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure_t > (that.value);
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        value.move< generic_statement_type > (that.value);
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        value.move< lambda_t > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< managed_statement_list > (that.value);
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        value.move< named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< named_expression_t > (that.value);
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< optional<syntax_expression_t> > (that.value);
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter_t > (that.value);
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter_t::default_spec > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< pattern_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< pattern_t > (that.value);
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< pattern_t::field > (that.value);
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< sonia::lang::lex::resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<pattern_t, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<sonia::lang::lex::resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<annium::identifier> > (that.value);
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
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
        value.move< syntax_expression_t > (that.value);
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
#line 332 "annium.y"
                 { }
#line 1876 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 332 "annium.y"
                 { }
#line 1882 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 332 "annium.y"
                 { }
#line 1888 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 332 "annium.y"
                 { }
#line 1894 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 332 "annium.y"
                 { }
#line 1900 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 332 "annium.y"
                 { }
#line 1906 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 332 "annium.y"
                 { }
#line 1912 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 332 "annium.y"
                 { }
#line 1918 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 332 "annium.y"
                 { }
#line 1924 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 332 "annium.y"
                 { }
#line 1930 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 332 "annium.y"
                 { }
#line 1936 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 332 "annium.y"
                 { }
#line 1942 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 332 "annium.y"
                 { }
#line 1948 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 332 "annium.y"
                 { }
#line 1954 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 332 "annium.y"
                 { }
#line 1960 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 332 "annium.y"
                 { }
#line 1966 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 332 "annium.y"
                 { }
#line 1972 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 332 "annium.y"
                 { }
#line 1978 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 332 "annium.y"
                 { }
#line 1984 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 332 "annium.y"
                 { }
#line 1990 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 332 "annium.y"
                 { }
#line 1996 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 332 "annium.y"
                 { }
#line 2002 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 332 "annium.y"
                 { }
#line 2008 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 332 "annium.y"
                 { }
#line 2014 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 332 "annium.y"
                 { }
#line 2020 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 332 "annium.y"
                 { }
#line 2026 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 332 "annium.y"
                 { }
#line 2032 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 332 "annium.y"
                 { }
#line 2038 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 332 "annium.y"
                 { }
#line 2044 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 332 "annium.y"
                 { }
#line 2050 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 332 "annium.y"
                 { }
#line 2056 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 332 "annium.y"
                 { }
#line 2062 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 332 "annium.y"
                 { }
#line 2068 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 332 "annium.y"
                 { }
#line 2074 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 332 "annium.y"
                 { }
#line 2080 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 332 "annium.y"
                 { }
#line 2086 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 332 "annium.y"
                 { }
#line 2092 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 332 "annium.y"
                 { }
#line 2098 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 332 "annium.y"
                 { }
#line 2104 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 332 "annium.y"
                 { }
#line 2110 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 332 "annium.y"
                 { }
#line 2116 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 332 "annium.y"
                 { }
#line 2122 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 332 "annium.y"
                 { }
#line 2128 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 332 "annium.y"
                 { }
#line 2134 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 332 "annium.y"
                 { }
#line 2140 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
#line 332 "annium.y"
                 { }
#line 2146 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 332 "annium.y"
                 { }
#line 2152 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_let_decl: // let-decl
#line 332 "annium.y"
                 { }
#line 2158 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl_start: // let-decl-start
#line 332 "annium.y"
                 { }
#line 2164 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 332 "annium.y"
                 { }
#line 2170 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
#line 332 "annium.y"
                 { }
#line 2176 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
#line 332 "annium.y"
                 { }
#line 2182 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_function_body: // function-body
#line 332 "annium.y"
                 { }
#line 2188 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_braced_statements: // braced-statements
#line 332 "annium.y"
                 { }
#line 2194 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
#line 332 "annium.y"
                 { }
#line 2200 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
#line 332 "annium.y"
                 { }
#line 2206 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
#line 332 "annium.y"
                 { }
#line 2212 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_infunction_statement: // infunction-statement
#line 332 "annium.y"
                 { }
#line 2218 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 332 "annium.y"
                 { }
#line 2224 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
#line 332 "annium.y"
                 { }
#line 2230 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 332 "annium.y"
                 { }
#line 2236 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
#line 332 "annium.y"
                 { }
#line 2242 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
#line 332 "annium.y"
                 { }
#line 2248 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
#line 332 "annium.y"
                 { }
#line 2254 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_name: // fn-name
#line 332 "annium.y"
                 { }
#line 2260 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
#line 332 "annium.y"
                 { }
#line 2266 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
#line 332 "annium.y"
                 { }
#line 2272 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_decl: // fn-decl
#line 332 "annium.y"
                 { }
#line 2278 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
#line 332 "annium.y"
                 { }
#line 2284 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
#line 332 "annium.y"
                 { }
#line 2290 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_case_list: // case-list
#line 332 "annium.y"
                 { }
#line 2296 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_case_decl: // case-decl
#line 332 "annium.y"
                 { }
#line 2302 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
#line 332 "annium.y"
                 { }
#line 2308 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_using_decl: // using-decl
#line 332 "annium.y"
                 { }
#line 2314 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_expression_list: // expression-list
#line 332 "annium.y"
                 { }
#line 2320 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
#line 332 "annium.y"
                 { }
#line 2326 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_argument_list: // argument-list
#line 332 "annium.y"
                 { }
#line 2332 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 332 "annium.y"
                 { }
#line 2338 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_argument_name: // argument-name
#line 332 "annium.y"
                 { }
#line 2344 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
#line 332 "annium.y"
                 { }
#line 2350 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_field_list: // field-list
#line 332 "annium.y"
                 { }
#line 2356 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
#line 332 "annium.y"
                 { }
#line 2362 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 332 "annium.y"
                 { }
#line 2368 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
#line 332 "annium.y"
                 { }
#line 2374 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_parameter_list: // parameter-list
#line 332 "annium.y"
                 { }
#line 2380 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
#line 332 "annium.y"
                 { }
#line 2386 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
#line 332 "annium.y"
                 { }
#line 2392 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
#line 332 "annium.y"
                 { }
#line 2398 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 332 "annium.y"
                 { }
#line 2404 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
#line 332 "annium.y"
                 { }
#line 2410 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
#line 332 "annium.y"
                 { }
#line 2416 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_constraint_expression: // constraint-expression
#line 332 "annium.y"
                 { }
#line 2422 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 332 "annium.y"
                 { }
#line 2428 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_pattern_list: // pattern-list
#line 332 "annium.y"
                 { }
#line 2434 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
#line 332 "annium.y"
                 { }
#line 2440 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_pattern_field: // pattern-field
#line 332 "annium.y"
                 { }
#line 2446 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
#line 332 "annium.y"
                 { }
#line 2452 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
#line 332 "annium.y"
                 { }
#line 2458 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 332 "annium.y"
                 { }
#line 2464 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
#line 332 "annium.y"
                 { }
#line 2470 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
#line 332 "annium.y"
                 { }
#line 2476 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
#line 332 "annium.y"
                 { }
#line 2482 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
#line 332 "annium.y"
                 { }
#line 2488 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
#line 332 "annium.y"
                 { }
#line 2494 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_syntax_expression: // syntax-expression
#line 332 "annium.y"
                 { }
#line 2500 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_apostrophe_expression: // apostrophe-expression
#line 332 "annium.y"
                 { }
#line 2506 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_new_expression: // new-expression
#line 332 "annium.y"
                 { }
#line 2512 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_call_expression: // call-expression
#line 332 "annium.y"
                 { }
#line 2518 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
#line 332 "annium.y"
                 { }
#line 2524 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_lambda_expression: // lambda-expression
#line 332 "annium.y"
                 { }
#line 2530 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
#line 332 "annium.y"
                 { }
#line 2536 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_pack_expression: // pack-expression
#line 332 "annium.y"
                 { }
#line 2542 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_compound_expression: // compound-expression
#line 332 "annium.y"
                 { }
#line 2548 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_type_expr: // type-expr
#line 332 "annium.y"
                 { }
#line 2554 "annium.tab.cpp"
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
      case symbol_kind::S_147_argument_name: // argument-name
        yylhs.value.emplace< annium::annotated_identifier > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< annium::annotated_integer > ();
        break;

      case symbol_kind::S_qname: // qname
      case symbol_kind::S_133_fn_name: // fn-name
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

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< annium::context_identifier > ();
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        yylhs.value.emplace< annium::identifier > ();
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
      case symbol_kind::S_FALSE_WORD: // "false"
        yylhs.value.emplace< annotated_bool > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< concept_expression_list_t > ();
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_143_expression_list: // expression-list
        yylhs.value.emplace< expression_list_t > ();
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        yylhs.value.emplace< field_list_t > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field_t > ();
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field_t::default_spec > ();
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
        yylhs.value.emplace< finished_statement_type > ();
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure_t > ();
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
        yylhs.value.emplace< generic_statement_type > ();
        break;

      case symbol_kind::S_177_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< lambda_t > ();
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< managed_statement_list > ();
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_179_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_180_pack_expression: // pack-expression
        yylhs.value.emplace< named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< named_expression_t > ();
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< optional<syntax_expression_t> > ();
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter_t > ();
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter_t::default_spec > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        yylhs.value.emplace< pattern_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< pattern_t > ();
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        yylhs.value.emplace< pattern_t::field > ();
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
      case symbol_kind::S_PROBE: // PROBE
        yylhs.value.emplace< sonia::lang::lex::resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<pattern_t, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        yylhs.value.emplace< std::vector<annium::identifier> > ();
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
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
        yylhs.value.emplace< syntax_expression_t > ();
        break;

      case symbol_kind::S_142_using_decl: // using-decl
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
#line 337 "annium.y"
                            { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 3049 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 338 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < managed_statement_list > ())); }
#line 3055 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 343 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 3061 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 345 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3067 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 347 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3073 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 364 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 3079 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 365 "annium.y"
                                                { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3085 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 367 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3091 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 369 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3097 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 374 "annium.y"
        { yylhs.value.as < statement > () = extern_var{ std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3103 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 376 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < fn_pure_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3109 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 378 "annium.y"
        { yylhs.value.as < statement > () = include_decl{ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3115 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 380 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3121 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 382 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < struct_decl > ()); }
#line 3127 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 387 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3133 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 389 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = std::move(yystack_[0].value.as < named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3139 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 394 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = false }; }
#line 3145 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 396 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annium::annotated_identifier > ()), .weakness = true }; }
#line 3151 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 400 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3157 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 402 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 3163 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 407 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); }
#line 3169 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 409 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3175 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 411 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3181 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 416 "annium.y"
        { yylhs.value.as < managed_statement_list > () = ctx.new_statement_list(); yylhs.value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); }
#line 3187 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 417 "annium.y"
                                                           { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3193 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 419 "annium.y"
        { yystack_[1].value.as < managed_statement_list > ().emplace_back(std::move(yystack_[0].value.as < finished_statement_type > ())); yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3199 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 421 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); }
#line 3205 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 427 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3211 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression "APOSTROPHE"
#line 429 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[1].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ yystack_[1].value.as < syntax_expression_t > (), std::move(loc) });
            yylhs.value.as < managed_statement_list > () = std::move(sts);
        }
#line 3222 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 439 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[1].value.as < managed_statement_list > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3228 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 444 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3234 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 446 "annium.y"
        { yylhs.value.as < finished_statement_type > () = while_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; }
#line 3240 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 448 "annium.y"
        { yylhs.value.as < finished_statement_type > () = for_statement{ std::move(yystack_[3].value.as < reference_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3246 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 450 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[1].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3252 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 452 "annium.y"
        { yylhs.value.as < finished_statement_type > () = if_decl{ std::move(yystack_[3].value.as < syntax_expression_t > ()), ctx.push(std::move(yystack_[2].value.as < managed_statement_list > ())), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 3258 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 454 "annium.y"
        {   
            yystack_[1].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure_t > ().kind = get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < finished_statement_type > () = fn_decl_t{ std::move(yystack_[1].value.as < fn_pure_t > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) };
        }
#line 3268 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 464 "annium.y"
        { yylhs.value.as < finished_statement_type > () = std::move(yystack_[0].value.as < enum_decl > ()); }
#line 3274 "annium.tab.cpp"
    break;

  case 39: // infunction-statement-set: infunction-statement-any
#line 469 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3280 "annium.tab.cpp"
    break;

  case 40: // infunction-statement-set: finished-infunction-statement-any
#line 471 "annium.y"
        { yylhs.value.as < managed_statement_list > () = std::move(yystack_[0].value.as < managed_statement_list > ()); }
#line 3286 "annium.tab.cpp"
    break;

  case 41: // generic-statement: LET let-decl
#line 476 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < let_statement > ()); }
#line 3292 "annium.tab.cpp"
    break;

  case 42: // generic-statement: "`typefn`" fn-start-decl
#line 478 "annium.y"
        { yylhs.value.as < generic_statement_type > () = typefn_decl_t{ std::move(yystack_[0].value.as < fn_pure_t > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3298 "annium.tab.cpp"
    break;

  case 43: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 480 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yystack_[2].value.as < fn_pure_t > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure_t > ().kind = get<1>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ());
            yylhs.value.as < generic_statement_type > () = fn_decl_t{ std::move(yystack_[2].value.as < fn_pure_t > ()), ctx.push(std::move(sts)) };
        }
#line 3311 "annium.tab.cpp"
    break;

  case 44: // generic-statement: USING using-decl
#line 489 "annium.y"
        { yylhs.value.as < generic_statement_type > () = std::move(yystack_[0].value.as < using_decl > ()); }
#line 3317 "annium.tab.cpp"
    break;

  case 45: // generic-statement: compound-expression
#line 491 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3323 "annium.tab.cpp"
    break;

  case 46: // generic-statement: syntax-expression "`=`" syntax-expression
#line 493 "annium.y"
        { yylhs.value.as < generic_statement_type > () = expression_statement_t{ binary_expression_t{ binary_operator_type::ASSIGN, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) } }; }
#line 3329 "annium.tab.cpp"
    break;

  case 47: // infunction-statement: generic-statement
#line 498 "annium.y"
        { yylhs.value.as < statement > () = apply_visitor(statement_adopt_visitor<statement>{}, yystack_[0].value.as < generic_statement_type > ()); }
#line 3335 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: "`break`"
#line 500 "annium.y"
        { yylhs.value.as < statement > () = break_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3341 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`continue`"
#line 502 "annium.y"
        { yylhs.value.as < statement > () = continue_statement_t{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3347 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`return`"
#line 504 "annium.y"
        { yylhs.value.as < statement > () = return_statement_t{ .location = std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3353 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`" syntax-expression
#line 506 "annium.y"
        { yylhs.value.as < statement > () = return_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3359 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`yield`" syntax-expression
#line 508 "annium.y"
        { yylhs.value.as < statement > () = yield_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3365 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 513 "annium.y"
      { yylhs.value.as < annium::annotated_identifier > () = ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 3371 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 521 "annium.y"
        { yylhs.value.as < annium::context_identifier > () = context_identifier { ctx.make_identifier(yystack_[0].value.as < annium::annotated_string_view > ()) }; }
#line 3377 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 536 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3383 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 538 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annium::annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annium::annotated_identifier > ().location) }; }
#line 3389 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 540 "annium.y"
        { yylhs.value.as < annium::annotated_qname > () = std::move(yystack_[2].value.as < annium::annotated_qname > ()); yylhs.value.as < annium::annotated_qname > ().value.append(std::move(yystack_[0].value.as < annium::annotated_identifier > ().value)); }
#line 3395 "annium.tab.cpp"
    break;

  case 58: // fn-kind: INLINE
#line 545 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3401 "annium.tab.cpp"
    break;

  case 59: // fn-kind: VIABLE
#line 546 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3407 "annium.tab.cpp"
    break;

  case 60: // fn-kind-set: fn-kind
#line 550 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3413 "annium.tab.cpp"
    break;

  case 61: // fn-kind-set: fn-kind-set fn-kind
#line 551 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3419 "annium.tab.cpp"
    break;

  case 62: // fn-prefix-decl: "`fn`"
#line 556 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), fn_kind::DEFAULT }; }
#line 3425 "annium.tab.cpp"
    break;

  case 63: // fn-prefix-decl: fn-kind-set "`fn`"
#line 558 "annium.y"
        { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3431 "annium.tab.cpp"
    break;

  case 64: // fn-name: qname
#line 562 "annium.y"
      { yylhs.value.as < annium::annotated_qname > () = yystack_[0].value.as < annium::annotated_qname > (); }
#line 3437 "annium.tab.cpp"
    break;

  case 65: // fn-name: "`new`"
#line 563 "annium.y"
          { yylhs.value.as < annium::annotated_qname > () = ctx.make_qname(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }); }
#line 3443 "annium.tab.cpp"
    break;

  case 66: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 568 "annium.y"
        { yylhs.value.as < fn_pure_t > () = fn_pure_t{ .nameval = std::move(yystack_[4].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[4].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < optional<syntax_expression_t> > ()) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 3449 "annium.tab.cpp"
    break;

  case 67: // fn-requirement-opt: %empty
#line 585 "annium.y"
             { yylhs.value.as < optional<syntax_expression_t> > () = {}; }
#line 3455 "annium.tab.cpp"
    break;

  case 68: // fn-requirement-opt: REQUIRES syntax-expression
#line 587 "annium.y"
        { yylhs.value.as < optional<syntax_expression_t> > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 3461 "annium.tab.cpp"
    break;

  case 69: // fn-decl: fn-start-decl
#line 598 "annium.y"
      { yylhs.value.as < fn_pure_t > () = yystack_[0].value.as < fn_pure_t > (); }
#line 3467 "annium.tab.cpp"
    break;

  case 70: // fn-decl: fn-start-decl "`->`" type-expr
#line 600 "annium.y"
        { yylhs.value.as < fn_pure_t > () = yystack_[2].value.as < fn_pure_t > (); yylhs.value.as < fn_pure_t > ().result = std::move(yystack_[0].value.as < syntax_expression_t > ()); }
#line 3473 "annium.tab.cpp"
    break;

  case 71: // fn-decl: fn-start-decl "`~>`" pattern
#line 602 "annium.y"
        { yylhs.value.as < fn_pure_t > () = yystack_[2].value.as < fn_pure_t > (); yylhs.value.as < fn_pure_t > ().result = std::move(yystack_[0].value.as < pattern_t > ()); }
#line 3479 "annium.tab.cpp"
    break;

  case 72: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 609 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ std::move(yystack_[3].value.as < annium::annotated_qname > ()), std::move(yystack_[1].value.as < std::vector<annium::identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3485 "annium.tab.cpp"
    break;

  case 73: // case-list-opt: %empty
#line 613 "annium.y"
             { yylhs.value.as < std::vector<annium::identifier> > () = {}; }
#line 3491 "annium.tab.cpp"
    break;

  case 74: // case-list-opt: case-list
#line 614 "annium.y"
      { yylhs.value.as < std::vector<annium::identifier> > () = yystack_[0].value.as < std::vector<annium::identifier> > (); }
#line 3497 "annium.tab.cpp"
    break;

  case 75: // case-list: case-decl
#line 619 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::vector<annium::identifier>{std::move(yystack_[0].value.as < annium::identifier > ())}; }
#line 3503 "annium.tab.cpp"
    break;

  case 76: // case-list: case-list "," case-decl
#line 621 "annium.y"
        { yylhs.value.as < std::vector<annium::identifier> > () = std::move(yystack_[2].value.as < std::vector<annium::identifier> > ()); yylhs.value.as < std::vector<annium::identifier> > ().emplace_back(std::move(yystack_[0].value.as < annium::identifier > ())); }
#line 3509 "annium.tab.cpp"
    break;

  case 77: // case-decl: identifier
#line 626 "annium.y"
        { yylhs.value.as < annium::identifier > () = yystack_[0].value.as < annium::annotated_identifier > ().value; }
#line 3515 "annium.tab.cpp"
    break;

  case 78: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 632 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[4].value.as < annium::annotated_qname > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3521 "annium.tab.cpp"
    break;

  case 79: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 634 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = std::move(yystack_[7].value.as < annium::annotated_qname > ()), .parameters = std::move(yystack_[5].value.as < parameter_list_t > ()), .body = std::move(yystack_[1].value.as < field_list_t > ()) }; IGNORE_TERM(yystack_[6].value.as < sonia::lang::lex::resource_location > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3527 "annium.tab.cpp"
    break;

  case 80: // using-decl: qname "`=>`" syntax-expression
#line 657 "annium.y"
        { 
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ .expression = std::move(yystack_[0].value.as < syntax_expression_t > ()), .location = std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[2].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[2].value.as < annium::annotated_qname > ().location), .result = nullptr }, ctx.push(std::move(sts)) } };
        }
#line 3538 "annium.tab.cpp"
    break;

  case 81: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 664 "annium.y"
        {
            auto sts = ctx.new_statement_list();
            auto loc = get_start_location(yystack_[0].value.as < syntax_expression_t > ());
            sts.emplace_back(return_statement_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) });
            yylhs.value.as < using_decl > () = using_decl{ fn_decl_t{ fn_pure_t{ .nameval = std::move(yystack_[5].value.as < annium::annotated_qname > ().value), .location = std::move(yystack_[5].value.as < annium::annotated_qname > ().location), .parameters = std::move(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.push(std::move(sts)) } };
            IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ());
        }
#line 3550 "annium.tab.cpp"
    break;

  case 82: // expression-list: syntax-expression
#line 682 "annium.y"
        { yylhs.value.as < expression_list_t > () = expression_list_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3556 "annium.tab.cpp"
    break;

  case 83: // expression-list: expression-list "," syntax-expression
#line 684 "annium.y"
        { yylhs.value.as < expression_list_t > () = std::move(yystack_[2].value.as < expression_list_t > ()); yylhs.value.as < expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 3562 "annium.tab.cpp"
    break;

  case 84: // argument-list-opt: %empty
#line 689 "annium.y"
              { yylhs.value.as < named_expression_list_t > () = {}; }
#line 3568 "annium.tab.cpp"
    break;

  case 85: // argument-list-opt: argument-list
#line 690 "annium.y"
      { yylhs.value.as < named_expression_list_t > () = yystack_[0].value.as < named_expression_list_t > (); }
#line 3574 "annium.tab.cpp"
    break;

  case 86: // argument-list: argument
#line 695 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{std::move(yystack_[0].value.as < named_expression_t > ())}; }
#line 3580 "annium.tab.cpp"
    break;

  case 87: // argument-list: argument-list "," argument
#line 697 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ()); yylhs.value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < named_expression_t > ())); }
#line 3586 "annium.tab.cpp"
    break;

  case 88: // argument: argument-name syntax-expression
#line 702 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[1].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3592 "annium.tab.cpp"
    break;

  case 89: // argument: syntax-expression
#line 704 "annium.y"
        { yylhs.value.as < named_expression_t > () = named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3598 "annium.tab.cpp"
    break;

  case 90: // argument-name: identifier "`=`"
#line 709 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3604 "annium.tab.cpp"
    break;

  case 91: // argument-name: identifier "`:`"
#line 711 "annium.y"
        { yylhs.value.as < annium::annotated_identifier > () = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3610 "annium.tab.cpp"
    break;

  case 92: // field-list-opt: %empty
#line 716 "annium.y"
              { yylhs.value.as < field_list_t > () = {}; }
#line 3616 "annium.tab.cpp"
    break;

  case 93: // field-list-opt: field-list
#line 717 "annium.y"
      { yylhs.value.as < field_list_t > () = yystack_[0].value.as < field_list_t > (); }
#line 3622 "annium.tab.cpp"
    break;

  case 94: // field-list: field
#line 722 "annium.y"
        { yylhs.value.as < field_list_t > () = field_list_t{std::move(yystack_[0].value.as < field_t > ())}; }
#line 3628 "annium.tab.cpp"
    break;

  case 95: // field-list: field-list "," field
#line 724 "annium.y"
        { yylhs.value.as < field_list_t > () = std::move(yystack_[2].value.as < field_list_t > ()); yylhs.value.as < field_list_t > ().emplace_back(std::move(yystack_[0].value.as < field_t > ())); }
#line 3634 "annium.tab.cpp"
    break;

  case 96: // field-default-value-opt: %empty
#line 728 "annium.y"
             { yylhs.value.as < field_t::default_spec > () = required_t{}; }
#line 3640 "annium.tab.cpp"
    break;

  case 97: // field-default-value-opt: "`=`" syntax-expression
#line 729 "annium.y"
                                      { yylhs.value.as < field_t::default_spec > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3646 "annium.tab.cpp"
    break;

  case 98: // field: identifier "`:`" type-expr field-default-value-opt
#line 734 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ .name = std::move(yystack_[3].value.as < annium::annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression_t > ()), .value = std::move(yystack_[0].value.as < field_t::default_spec > ()) }; }
#line 3652 "annium.tab.cpp"
    break;

  case 99: // field: identifier "`=>`" syntax-expression
#line 736 "annium.y"
        { yylhs.value.as < field_t > () = field_t{ .name = std::move(yystack_[2].value.as < annium::annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::any_constexpr_type, .type_or_value = std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 3658 "annium.tab.cpp"
    break;

  case 100: // parameter-list-opt: %empty
#line 742 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3664 "annium.tab.cpp"
    break;

  case 101: // parameter-list-opt: parameter-list
#line 743 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3670 "annium.tab.cpp"
    break;

  case 102: // parameter-list: parameter-decl
#line 748 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ parameter_t{std::move(yystack_[0].value.as < parameter_t > ())} }; }
#line 3676 "annium.tab.cpp"
    break;

  case 103: // parameter-list: parameter-list "," parameter-decl
#line 750 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter_t > ())); }
#line 3682 "annium.tab.cpp"
    break;

  case 104: // internal-identifier-opt: %empty
#line 754 "annium.y"
             { yylhs.value.as < annium::context_identifier > () = context_identifier{}; }
#line 3688 "annium.tab.cpp"
    break;

  case 105: // internal-identifier-opt: internal-identifier
#line 755 "annium.y"
                                 { yylhs.value.as < annium::context_identifier > () = std::move(yystack_[0].value.as < annium::context_identifier > ()); }
#line 3694 "annium.tab.cpp"
    break;

  case 106: // parameter-default-value-opt: %empty
#line 759 "annium.y"
             { yylhs.value.as < parameter_t::default_spec > () = required_t{}; }
#line 3700 "annium.tab.cpp"
    break;

  case 107: // parameter-default-value-opt: "`=`" syntax-expression
#line 760 "annium.y"
                                      { yylhs.value.as < parameter_t::default_spec > () = std::move(yystack_[0].value.as < syntax_expression_t > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3706 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 765 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3712 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 767 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3718 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 769 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3724 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 771 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3730 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: pattern-mod parameter-default-value-opt
#line 773 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) }; }
#line 3736 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: identifier internal-identifier-opt concept-expression-list-opt parameter-default-value-opt
#line 777 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annium::annotated_identifier > ()), std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[2].value.as < annium::context_identifier > ().name.location) }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3742 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 781 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[2].value.as < annium::context_identifier > ().name.location) }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3748 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: "`_`" parameter-default-value-opt
#line 783 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3754 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 785 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < annium::context_identifier > ().name) }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3760 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: "`...`" parameter-default-value-opt
#line 787 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }}, .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3766 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 792 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3772 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 794 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annium::annotated_identifier > ()), std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3778 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 796 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < annium::context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3784 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 798 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3790 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 800 "annium.y"
        { yylhs.value.as < parameter_t > () = parameter_t{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter_t::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > ()) }; }
#line 3796 "annium.tab.cpp"
    break;

  case 123: // constraint-expression-specified-mod: "constexpr modifier"
#line 804 "annium.y"
                { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::any_constexpr_type }; }
#line 3802 "annium.tab.cpp"
    break;

  case 124: // constraint-expression-specified-mod: "runctime modifier"
#line 805 "annium.y"
              { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3808 "annium.tab.cpp"
    break;

  case 125: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 810 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3814 "annium.tab.cpp"
    break;

  case 126: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 812 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3820 "annium.tab.cpp"
    break;

  case 127: // constraint-expression-specified: constraint-expression-specified-mod
#line 816 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ())) }}, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3826 "annium.tab.cpp"
    break;

  case 128: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 818 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3832 "annium.tab.cpp"
    break;

  case 129: // constraint-expression-mod: %empty
#line 823 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = std::pair{ sonia::lang::lex::resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource() }, parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3841 "annium.tab.cpp"
    break;

  case 130: // constraint-expression-mod: constraint-expression-specified-mod
#line 827 "annium.y"
      { yylhs.value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > (); }
#line 3847 "annium.tab.cpp"
    break;

  case 131: // constraint-expression: constraint-expression-mod type-expr
#line 832 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_expression_t > ()), get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3853 "annium.tab.cpp"
    break;

  case 132: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 834 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_expression_t > ()), get<1>(yystack_[2].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3859 "annium.tab.cpp"
    break;

  case 133: // constraint-expression: constraint-expression-mod
#line 838 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) } }, get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3865 "annium.tab.cpp"
    break;

  case 134: // constraint-expression: constraint-expression-mod "`...`"
#line 840 "annium.y"
        { yylhs.value.as < std::pair<variant<syntax_expression_t, pattern_t>, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, get<1>(yystack_[1].value.as < std::pair<sonia::lang::lex::resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3871 "annium.tab.cpp"
    break;

  case 135: // subpatterns: "`(`" pattern-list "`)`"
#line 850 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[1].value.as < pattern_list_t > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3877 "annium.tab.cpp"
    break;

  case 136: // pattern-list: pattern-field
#line 855 "annium.y"
        { yylhs.value.as < pattern_list_t > () = pattern_list_t{ std::move(yystack_[0].value.as < pattern_t::field > ()) }; }
#line 3883 "annium.tab.cpp"
    break;

  case 137: // pattern-list: pattern-list "," pattern-field
#line 857 "annium.y"
        { yylhs.value.as < pattern_list_t > () = std::move(yystack_[2].value.as < pattern_list_t > ()); yylhs.value.as < pattern_list_t > ().emplace_back(std::move(yystack_[0].value.as < pattern_t::field > ())); }
#line 3889 "annium.tab.cpp"
    break;

  case 138: // pattern-field-sfx: concept-expression-list-opt
#line 863 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3895 "annium.tab.cpp"
    break;

  case 139: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 865 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3901 "annium.tab.cpp"
    break;

  case 140: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 868 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) } }; }
#line 3907 "annium.tab.cpp"
    break;

  case 141: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 870 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = pattern_t{ .descriptor = placeholder{ }, .concepts = std::move(yystack_[1].value.as < concept_expression_list_t > ()) }, .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3913 "annium.tab.cpp"
    break;

  case 142: // pattern-field-sfx: "`=`" pattern-sfx
#line 874 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3919 "annium.tab.cpp"
    break;

  case 143: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 877 "annium.y"
        { yylhs.value.as < pattern_t::field > () = pattern_t::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < annium::context_identifier > ().name), .value = std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3925 "annium.tab.cpp"
    break;

  case 144: // pattern-field: identifier pattern-field-sfx
#line 883 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::annotated_identifier > ()); }
#line 3931 "annium.tab.cpp"
    break;

  case 145: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 886 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = std::move(yystack_[1].value.as < annium::context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 3937 "annium.tab.cpp"
    break;

  case 146: // pattern-field: pattern-field-sfx
#line 899 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ }; }
#line 3943 "annium.tab.cpp"
    break;

  case 147: // pattern-field: "`_`" pattern-field-sfx
#line 902 "annium.y"
        { yylhs.value.as < pattern_t::field > () = std::move(yystack_[0].value.as < pattern_t::field > ()); yylhs.value.as < pattern_t::field > ().name = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 3949 "annium.tab.cpp"
    break;

  case 148: // pattern-mod: "`~`" pattern-sfx
#line 906 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3955 "annium.tab.cpp"
    break;

  case 149: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 907 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3961 "annium.tab.cpp"
    break;

  case 150: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 908 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3967 "annium.tab.cpp"
    break;

  case 151: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 909 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3973 "annium.tab.cpp"
    break;

  case 152: // pattern-mod: "`~`" "typename modifier"
#line 910 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3979 "annium.tab.cpp"
    break;

  case 153: // pattern-mod: "typename modifier" pattern-sfx
#line 911 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 3985 "annium.tab.cpp"
    break;

  case 154: // pattern-mod: "typename modifier"
#line 912 "annium.y"
                                              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{ std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }}, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 3991 "annium.tab.cpp"
    break;

  case 155: // pattern-sfx: pattern
#line 916 "annium.y"
              { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < pattern_t > ()), parameter_constraint_modifier_t::none }; }
#line 3997 "annium.tab.cpp"
    break;

  case 156: // pattern-sfx: pattern "`...`"
#line 917 "annium.y"
                       { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < pattern_t > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 4003 "annium.tab.cpp"
    break;

  case 157: // pattern-sfx: "`...`"
#line 918 "annium.y"
               { yylhs.value.as < std::pair<pattern_t, parameter_constraint_modifier_t> > () = std::pair{ pattern_t{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < sonia::lang::lex::resource_location > ()); }
#line 4009 "annium.tab.cpp"
    break;

  case 158: // pattern: qname
#line 923 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 4015 "annium.tab.cpp"
    break;

  case 159: // pattern: qname subpatterns concept-expression-list-opt
#line 925 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[2].value.as < annium::annotated_qname > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 4021 "annium.tab.cpp"
    break;

  case 160: // pattern: internal-identifier concept-expression-list-opt
#line 927 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[1].value.as < annium::context_identifier > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 4027 "annium.tab.cpp"
    break;

  case 161: // pattern: "`_`" concept-expression-list-opt
#line 929 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 4033 "annium.tab.cpp"
    break;

  case 162: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 931 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }, .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 4039 "annium.tab.cpp"
    break;

  case 163: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 933 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = std::move(yystack_[2].value.as < syntax_expression_t > ()), .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ()); }
#line 4045 "annium.tab.cpp"
    break;

  case 164: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 935 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = pattern_t::signature_descriptor{ .name = std::move(yystack_[3].value.as < syntax_expression_t > ()), .fields = std::move(yystack_[1].value.as < pattern_list_t > ()) }, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < sonia::lang::lex::resource_location > ()); }
#line 4051 "annium.tab.cpp"
    break;

  case 165: // pattern: concept-expression-list
#line 937 "annium.y"
        { yylhs.value.as < pattern_t > () = pattern_t{ .descriptor = placeholder{}, .concepts = std::move(yystack_[0].value.as < concept_expression_list_t > ()) }; }
#line 4057 "annium.tab.cpp"
    break;

  case 166: // concept-expression: "`@`" qname
#line 942 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = syntax_expression_t{ qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 4063 "annium.tab.cpp"
    break;

  case 167: // concept-expression-list-opt: %empty
#line 947 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = {}; }
#line 4069 "annium.tab.cpp"
    break;

  case 168: // concept-expression-list-opt: concept-expression-list
#line 948 "annium.y"
      { yylhs.value.as < concept_expression_list_t > () = yystack_[0].value.as < concept_expression_list_t > (); }
#line 4075 "annium.tab.cpp"
    break;

  case 169: // concept-expression-list: concept-expression
#line 953 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = concept_expression_list_t{std::move(yystack_[0].value.as < syntax_expression_t > ())}; }
#line 4081 "annium.tab.cpp"
    break;

  case 170: // concept-expression-list: concept-expression-list concept-expression
#line 955 "annium.y"
        { yylhs.value.as < concept_expression_list_t > () = std::move(yystack_[1].value.as < concept_expression_list_t > ()); yylhs.value.as < concept_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ())); }
#line 4087 "annium.tab.cpp"
    break;

  case 171: // reference-expression: CONTEXT_IDENTIFIER
#line 961 "annium.y"
        { yylhs.value.as < reference_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4093 "annium.tab.cpp"
    break;

  case 172: // reference-expression: qname
#line 963 "annium.y"
        { yylhs.value.as < reference_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4099 "annium.tab.cpp"
    break;

  case 173: // any-reference-expression: RESERVED_IDENTIFIER
#line 968 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4105 "annium.tab.cpp"
    break;

  case 174: // any-reference-expression: CONTEXT_IDENTIFIER
#line 970 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4111 "annium.tab.cpp"
    break;

  case 175: // any-reference-expression: qname
#line 972 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4117 "annium.tab.cpp"
    break;

  case 176: // any-reference-expression: any-reference-expression "`.`" identifier
#line 974 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < annium::annotated_identifier > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4123 "annium.tab.cpp"
    break;

  case 177: // any-reference-expression: call-expression "`.`" identifier
#line 976 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < annium::annotated_identifier > ()) }; IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4129 "annium.tab.cpp"
    break;

  case 178: // syntax-expression: "nil"
#line 981 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_nil > ()); }
#line 4135 "annium.tab.cpp"
    break;

  case 179: // syntax-expression: "true"
#line 983 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 4141 "annium.tab.cpp"
    break;

  case 180: // syntax-expression: "false"
#line 985 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annotated_bool > ()); }
#line 4147 "annium.tab.cpp"
    break;

  case 181: // syntax-expression: INTEGER
#line 987 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_integer > ()); }
#line 4153 "annium.tab.cpp"
    break;

  case 182: // syntax-expression: DECIMAL
#line 989 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 4159 "annium.tab.cpp"
    break;

  case 183: // syntax-expression: DECIMAL_S
#line 991 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_decimal > ()); }
#line 4165 "annium.tab.cpp"
    break;

  case 184: // syntax-expression: INTEGER_INDEX
#line 993 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = annotated_decimal{ ctx.make_decimal(yystack_[0].value.as < annium::annotated_string_view > ().value), yystack_[0].value.as < annium::annotated_string_view > ().location }; }
#line 4171 "annium.tab.cpp"
    break;

  case 185: // syntax-expression: STRING
#line 995 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_string(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 4177 "annium.tab.cpp"
    break;

  case 186: // syntax-expression: CT_IDENTIFIER
#line 997 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4183 "annium.tab.cpp"
    break;

  case 187: // syntax-expression: any-reference-expression
#line 998 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4189 "annium.tab.cpp"
    break;

  case 188: // syntax-expression: "`(`" "`)`"
#line 1001 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4195 "annium.tab.cpp"
    break;

  case 189: // syntax-expression: "`(`" "`:`" syntax-expression "`)`"
#line 1003 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[3].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, named_expression_list_t{ named_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()) } } };
        }
#line 4204 "annium.tab.cpp"
    break;

  case 190: // syntax-expression: "`(`" pack-expression "`)`"
#line 1008 "annium.y"
        {
            if (yystack_[1].value.as < named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) };
            }
        }
#line 4217 "annium.tab.cpp"
    break;

  case 191: // syntax-expression: "`[`" expression-list "`]`"
#line 1017 "annium.y"
        { 
            if (yystack_[1].value.as < expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression_t > () = bracket_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > ().front()) };
            } else {
                yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )};
            }
        }
#line 4229 "annium.tab.cpp"
    break;

  case 192: // syntax-expression: "`[`" braced-statements "`]`"
#line 1025 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_with_body_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), ctx.push(std::move(yystack_[1].value.as < managed_statement_list > ())) }; }
#line 4235 "annium.tab.cpp"
    break;

  case 193: // syntax-expression: "`[[`" expression-list "`]]`"
#line 1027 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = array_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < expression_list_t > () )}; }
#line 4241 "annium.tab.cpp"
    break;

  case 194: // syntax-expression: syntax-expression "`[`" syntax-expression "`]`"
#line 1029 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4247 "annium.tab.cpp"
    break;

  case 195: // syntax-expression: PROBE braced-statements
#line 1031 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = probe_expression{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ())) }; }
#line 4253 "annium.tab.cpp"
    break;

  case 196: // syntax-expression: "`.`" identifier
#line 1033 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[0].value.as < annium::annotated_identifier > ()); IGNORE_TERM(yystack_[1].value.as < sonia::lang::lex::resource_location > ()); }
#line 4259 "annium.tab.cpp"
    break;

  case 197: // syntax-expression: syntax-expression INTEGER_INDEX
#line 1040 "annium.y"
         { yylhs.value.as < syntax_expression_t > () = member_expression_t{ std::move(yystack_[1].value.as < syntax_expression_t > ()), annotated_integer{ ctx.make_integer(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1)), yystack_[0].value.as < annium::annotated_string_view > ().location } }; IGNORE_TERM(yystack_[0].value.as < annium::annotated_string_view > ()); }
#line 4265 "annium.tab.cpp"
    break;

  case 198: // syntax-expression: "`-`" syntax-expression
#line 1043 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::MINUS, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4271 "annium.tab.cpp"
    break;

  case 199: // syntax-expression: "`!`" syntax-expression
#line 1045 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::NEGATE, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4277 "annium.tab.cpp"
    break;

  case 200: // syntax-expression: "`*`" syntax-expression
#line 1047 "annium.y"
                { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::DEREF, true, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4283 "annium.tab.cpp"
    break;

  case 201: // syntax-expression: syntax-expression "`+`" syntax-expression
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::PLUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4289 "annium.tab.cpp"
    break;

  case 202: // syntax-expression: syntax-expression "`-`" syntax-expression
#line 1054 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::MINUS, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4295 "annium.tab.cpp"
    break;

  case 203: // syntax-expression: syntax-expression "`==`" syntax-expression
#line 1058 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::EQ, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4301 "annium.tab.cpp"
    break;

  case 204: // syntax-expression: syntax-expression "`!=`" syntax-expression
#line 1060 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::NE, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4307 "annium.tab.cpp"
    break;

  case 205: // syntax-expression: syntax-expression "`..`" syntax-expression
#line 1062 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::CONCAT, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4313 "annium.tab.cpp"
    break;

  case 206: // syntax-expression: syntax-expression "`&`" syntax-expression
#line 1065 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4319 "annium.tab.cpp"
    break;

  case 207: // syntax-expression: syntax-expression "`|`" syntax-expression
#line 1069 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4325 "annium.tab.cpp"
    break;

  case 208: // syntax-expression: syntax-expression "`&&`" syntax-expression
#line 1072 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_AND, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4331 "annium.tab.cpp"
    break;

  case 209: // syntax-expression: syntax-expression "`||`" syntax-expression
#line 1075 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::LOGIC_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4337 "annium.tab.cpp"
    break;

  case 210: // syntax-expression: apostrophe-expression
#line 1077 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4343 "annium.tab.cpp"
    break;

  case 211: // syntax-expression: new-expression
#line 1078 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4349 "annium.tab.cpp"
    break;

  case 212: // syntax-expression: compound-expression
#line 1079 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4355 "annium.tab.cpp"
    break;

  case 213: // syntax-expression: lambda-expression
#line 1080 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4361 "annium.tab.cpp"
    break;

  case 214: // apostrophe-expression: "APOSTROPHE" syntax-expression "APOSTROPHE"
#line 1085 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = std::move(yystack_[1].value.as < syntax_expression_t > ()); }
#line 4367 "annium.tab.cpp"
    break;

  case 215: // new-expression: "`new`" qname
#line 1090 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) } }; }
#line 4373 "annium.tab.cpp"
    break;

  case 216: // new-expression: "`new`" apostrophe-expression
#line 1092 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()) }; }
#line 4379 "annium.tab.cpp"
    break;

  case 217: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1094 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), qname_reference{ std::move(yystack_[3].value.as < annium::annotated_qname > ()) }, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4385 "annium.tab.cpp"
    break;

  case 218: // new-expression: "`new`" apostrophe-expression "`(`" argument-list-opt "`)`"
#line 1096 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = new_expression_t{ std::move(yystack_[4].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4391 "annium.tab.cpp"
    break;

  case 219: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1101 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4397 "annium.tab.cpp"
    break;

  case 220: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1103 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4403 "annium.tab.cpp"
    break;

  case 221: // call-expression: lambda-expression "`(`" pack-expression "`)`"
#line 1105 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4409 "annium.tab.cpp"
    break;

  case 222: // lambda-start-decl: fn-prefix-decl
#line 1117 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) | fn_kind::VIABLE } }; }
#line 4415 "annium.tab.cpp"
    break;

  case 223: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1119 "annium.y"
        { yylhs.value.as < lambda_t > () = lambda_t{ fn_pure_t{ .location = std::move(get<0>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ())), .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<sonia::lang::lex::resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4421 "annium.tab.cpp"
    break;

  case 224: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1124 "annium.y"
        { 
            yystack_[4].value.as < lambda_t > ().parameters = std::move(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[4].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[3].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4432 "annium.tab.cpp"
    break;

  case 225: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1131 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < syntax_expression_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4444 "annium.tab.cpp"
    break;

  case 226: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1139 "annium.y"
        {
            yystack_[6].value.as < lambda_t > ().parameters = std::move(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < lambda_t > ().result = std::move(yystack_[1].value.as < pattern_t > ());
            yystack_[6].value.as < lambda_t > ().body = ctx.push(std::move(yystack_[0].value.as < managed_statement_list > ()));
            yylhs.value.as < syntax_expression_t > () = std::move(yystack_[6].value.as < lambda_t > ());
            IGNORE_TERM(yystack_[5].value.as < sonia::lang::lex::resource_location > ());
        }
#line 4456 "annium.tab.cpp"
    break;

  case 227: // pack-expression-opt: %empty
#line 1150 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{}; }
#line 4462 "annium.tab.cpp"
    break;

  case 228: // pack-expression-opt: pack-expression
#line 1152 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = std::move(yystack_[0].value.as < named_expression_list_t > ()); }
#line 4468 "annium.tab.cpp"
    break;

  case 229: // pack-expression: syntax-expression
#line 1157 "annium.y"
        { yylhs.value.as < named_expression_list_t > () = named_expression_list_t{ named_expression_t{ std::move(yystack_[0].value.as < syntax_expression_t > ()) } }; }
#line 4474 "annium.tab.cpp"
    break;

  case 230: // pack-expression: identifier "`:`" syntax-expression
#line 1159 "annium.y"
        {
            named_expression_list_t list{};
            list.emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(list);
        }
#line 4484 "annium.tab.cpp"
    break;

  case 231: // pack-expression: pack-expression "," syntax-expression
#line 1165 "annium.y"
        {
            yystack_[2].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[2].value.as < named_expression_list_t > ());
        }
#line 4493 "annium.tab.cpp"
    break;

  case 232: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1170 "annium.y"
        {
            yystack_[4].value.as < named_expression_list_t > ().emplace_back(std::move(yystack_[2].value.as < annium::annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()));
            yylhs.value.as < named_expression_list_t > () = std::move(yystack_[4].value.as < named_expression_list_t > ());
        }
#line 4502 "annium.tab.cpp"
    break;

  case 233: // compound-expression: syntax-expression "`...`"
#line 1178 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = unary_expression_t{ unary_operator_type::ELLIPSIS, false, std::move(yystack_[1].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4508 "annium.tab.cpp"
    break;

  case 234: // compound-expression: call-expression
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4514 "annium.tab.cpp"
    break;

  case 235: // type-expr: qname
#line 1221 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = qname_reference{ std::move(yystack_[0].value.as < annium::annotated_qname > ()) }; }
#line 4520 "annium.tab.cpp"
    break;

  case 236: // type-expr: RESERVED_IDENTIFIER
#line 1223 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4526 "annium.tab.cpp"
    break;

  case 237: // type-expr: CONTEXT_IDENTIFIER
#line 1225 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = name_reference{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 4532 "annium.tab.cpp"
    break;

  case 238: // type-expr: call-expression
#line 1226 "annium.y"
      { yylhs.value.as < syntax_expression_t > () = yystack_[0].value.as < syntax_expression_t > (); }
#line 4538 "annium.tab.cpp"
    break;

  case 239: // type-expr: "`[`" type-expr "`]`"
#line 1230 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = bracket_expression_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), std::move(yystack_[1].value.as < syntax_expression_t > ())}; }
#line 4544 "annium.tab.cpp"
    break;

  case 240: // type-expr: "`(`" "`)`"
#line 1232 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = ctx.make_void(std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ())); }
#line 4550 "annium.tab.cpp"
    break;

  case 241: // type-expr: "`(`" pack-expression "`)`"
#line 1234 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = function_call_t{ std::move(yystack_[2].value.as < sonia::lang::lex::resource_location > ()), qname_reference{}, std::move(yystack_[1].value.as < named_expression_list_t > ()) }; }
#line 4556 "annium.tab.cpp"
    break;

  case 242: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1236 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = index_expression_t{ std::move(yystack_[3].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < syntax_expression_t > ()) }; IGNORE_TERM(yystack_[2].value.as < sonia::lang::lex::resource_location > ()); }
#line 4562 "annium.tab.cpp"
    break;

  case 243: // type-expr: type-expr "`|`" type-expr
#line 1238 "annium.y"
        { yylhs.value.as < syntax_expression_t > () = binary_expression_t{ binary_operator_type::BIT_OR, std::move(yystack_[2].value.as < syntax_expression_t > ()), std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(yystack_[1].value.as < sonia::lang::lex::resource_location > ()) }; }
#line 4568 "annium.tab.cpp"
    break;

  case 244: // type-expr: type-expr "`->`" type-expr
#line 1240 "annium.y"
        { 
            auto loc = get_start_location(yystack_[2].value.as < syntax_expression_t > ());
            yylhs.value.as < syntax_expression_t > () = annium_fn_type_t{ named_expression_list_t{ named_expression_t{ std::move(yystack_[2].value.as < syntax_expression_t > ()) } }, std::move(yystack_[0].value.as < syntax_expression_t > ()), std::move(loc) };
        }
#line 4577 "annium.tab.cpp"
    break;


#line 4581 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -325;

  const short parser::yytable_ninf_ = -176;

  const short
  parser::yypact_[] =
  {
     731,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
     981,    27,   837,   858,   981,    27,   981,   981,   981,    -4,
     -34,   135,   981,   161,   981,    49,   149,  -325,  -325,  -325,
       9,    49,    49,  -325,  -325,  -325,     3,    98,    21,   413,
    -325,  -325,  -325,  -325,   132,  -325,   310,     5,   193,  1034,
    -325,  -325,   235,   145,   150,    43,   164,  1071,  -325,  -325,
     981,  -325,   156,  1177,   206,   625,   173,    44,  1177,    76,
    -325,    41,    41,    41,    27,  -325,   186,   223,  -325,    27,
       9,   237,   219,   736,  -325,   132,   200,   615,   170,  -325,
    -325,  -325,   132,   254,  -325,   124,  -325,   260,  -325,  -325,
    -325,  -325,  -325,  -325,  -325,  -325,  -325,    27,  -325,  -325,
     981,   139,   -14,   981,    27,  -325,   981,   981,   981,   981,
     981,   981,  -325,   981,   981,   981,   981,   981,   981,    27,
     435,   981,  -325,   827,   981,  -325,   981,  -325,  -325,   981,
     981,   285,   519,  -325,   302,  -325,  -325,  -325,  -325,   981,
    -325,  -325,   653,   981,   298,  -325,   981,   981,   981,  -325,
     981,   286,   981,   435,   435,    27,   340,   435,  -325,   349,
     307,   653,   604,   981,  -325,   359,  -325,  1177,   197,   197,
    1205,   897,   143,  1082,    41,    41,   304,   527,   248,  -325,
    -325,   388,   388,   280,   292,   344,  -325,  -325,   402,   346,
     365,   345,  -325,   450,   388,   388,   262,  -325,  1177,   382,
    1177,  1177,  1177,  -325,  -325,  -325,  -325,  -325,  1177,   342,
     352,   964,   653,   324,   193,   235,   150,   271,   307,   653,
       8,   385,   361,  -325,   981,  1177,   391,   615,   615,     3,
    1177,   394,   395,  -325,   397,   375,  -325,    27,   401,  -325,
     271,    49,    13,   981,   429,   282,  -325,  -325,   429,  1177,
    -325,  -325,  -325,   981,  -325,  -325,  -325,   547,   388,   388,
    -325,   344,   344,   344,  -325,   416,  -325,  -325,    20,   388,
     280,   388,   429,   354,   435,  -325,   234,  -325,  -325,  -325,
     981,  -325,   297,   226,   653,   981,   653,   271,  -325,  -325,
    -325,   981,  1177,  -325,  -325,  -325,  -325,   433,   357,  -325,
      27,    69,   414,   392,  -325,   443,   132,   244,   429,  -325,
    1119,  -325,   429,  -325,  1177,  -325,   293,  -325,  -325,  -325,
    -325,  -325,  -325,   280,   422,   388,  -325,   388,   388,  -325,
     653,   981,   604,  -325,  -325,  -325,  -325,  1177,  -325,  -325,
    -325,  1129,     7,  -325,   981,   981,  -325,  -325,   981,   653,
    -325,    27,   418,   344,   420,   402,   420,   415,   329,  -325,
    -325,   434,  -325,    13,  -325,  -325,   388,   388,   280,  -325,
    -325,  -325,   222,  1167,   131,  -325,  1177,  1177,  1177,    29,
    -325,    27,  -325,  -325,   420,  -325,   344,   438,  -325,   244,
    -325,   429,  -325,  -325,  -325,  -325,  -325,  -325,  -325,  -325,
     981,  -325,   427,  -325,  -325,  -325,  -325,  -325,  1177,  -325
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   185,    53,   174,   173,   186,   184,   181,   182,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    62,
       0,     0,     0,   178,   179,   180,     0,     0,     0,     0,
       5,     7,    14,    56,   175,    60,     0,   222,   187,     0,
     210,   211,   234,     0,   213,   212,   222,     0,   212,    55,
       0,   188,    56,   229,     0,    22,     0,     0,    82,     0,
     196,   198,   200,   199,     0,    41,    20,    16,    18,     0,
       0,   215,   216,     0,   171,   172,     0,     0,     0,    44,
      13,    65,    64,     0,    42,     0,    38,     0,    15,   195,
       1,     2,    10,     3,     8,     6,     9,     0,    63,    61,
     227,    69,     0,   227,     0,   197,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     100,     0,   214,     0,     0,   190,     0,    49,    48,    50,
       0,    39,    40,    25,     0,    47,    23,   192,   191,     0,
     193,    19,     0,     0,     0,    12,    84,    84,     0,    32,
       0,    35,     0,   100,   100,    73,     0,   100,    57,     0,
     228,     0,     0,     0,    37,     0,   176,    46,   203,   204,
     208,   209,   205,     0,   201,   202,   206,   207,     0,   177,
      54,   106,   106,   129,     0,   154,   123,   124,   104,   167,
       0,   101,   102,   127,   106,   106,     0,   189,   230,    56,
     231,    51,    52,    28,    26,    27,    24,    31,    83,   237,
     236,     0,     0,   235,     0,   238,     0,    21,    17,     0,
      56,     0,    85,    86,     0,    89,     0,     0,     0,     0,
      80,     0,     0,    77,     0,    74,    75,    92,     0,   223,
      70,     0,   167,     0,   167,   158,    71,   169,   165,    43,
     219,   194,   220,     0,   115,   117,   130,   133,   106,   106,
     157,   152,     0,     0,   148,   155,   153,   105,   167,   106,
     129,   106,   168,     0,     0,   128,   125,   122,   112,   221,
       0,   240,     0,     0,     0,     0,     0,    11,    90,    91,
     217,     0,    88,   218,    33,    34,    36,     0,    67,    72,
       0,     0,     0,    93,    94,     0,   166,   167,   167,   161,
       0,   160,   167,   170,   107,   134,   131,   121,   111,   151,
     149,   150,   156,   129,     0,   106,   116,   106,   106,   114,
       0,     0,     0,   224,    29,   103,   126,   232,   241,   239,
     244,     0,   243,    87,     0,     0,    66,    76,     0,     0,
      78,     0,     0,     0,   167,     0,   167,   167,     0,   146,
     136,   138,   162,   167,   159,   132,   106,   106,   129,   113,
     120,   110,     0,     0,     0,   242,    81,    68,    99,    96,
      95,    92,   142,   147,   167,   144,     0,   140,   135,   167,
     139,   167,   163,   118,   108,   119,   109,   225,    30,   226,
       0,    98,     0,   145,   143,   141,   137,   164,    97,    79
  };

  const short
  parser::yypgoto_[] =
  {
    -325,  -325,  -325,  -325,   440,  -325,  -325,  -325,  -325,  -325,
     -63,   -10,   -20,  -325,   -53,   341,    56,  -129,    53,   436,
    -325,    48,  -325,   454,  -325,   406,  -325,  -325,  -325,   178,
    -325,  -325,   479,   338,  -325,   195,  -325,   108,  -325,  -325,
     144,  -117,  -325,  -325,   101,   216,  -189,  -325,  -325,  -275,
    -235,  -325,  -324,   105,  -168,  -163,  -164,  -178,  -190,  -166,
    -325,   -23,     0,   485,  -325,    -7,  -325,    93,   403,    19,
      72,   -28
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    75,    76,    77,   141,   142,
     343,   344,    41,   144,    42,   146,    43,   254,    44,    45,
      46,    56,    93,   111,   356,   112,    96,   244,   245,   246,
      98,    89,    67,   231,   232,   233,   234,   312,   313,   411,
     314,   200,   201,   278,   264,   202,   203,   204,   267,   268,
     318,   368,   369,   370,   205,   274,   275,   257,   371,   282,
      86,    48,    63,    50,    51,    52,    53,    54,   169,   170,
      58,   227
  };

  const short
  parser::yytable_[] =
  {
      49,   199,     2,    66,   266,   337,   258,   173,   256,   281,
      57,     2,   145,    68,    68,     2,    71,    72,    73,   106,
     322,   101,    83,   298,    87,   269,    99,   294,   258,   258,
     251,    64,   276,     2,   199,   199,    65,   251,   199,    49,
     393,    79,   395,   -45,   410,   143,   241,   242,    47,   294,
     248,   115,    11,    65,   299,     2,    11,   110,   376,   295,
     133,   317,   319,    80,   321,    49,   333,    59,    62,   277,
     413,    70,    55,   159,    81,    78,    85,   161,    88,   102,
     323,   295,    91,    92,    95,    97,    91,    47,   335,   145,
     358,   266,   334,   123,   -45,   296,    11,   148,   100,    74,
      92,   -45,   174,   405,   323,   258,   258,   258,   329,   330,
     331,    55,   338,    47,   149,   359,   177,   178,   179,   180,
     181,   182,   215,   183,   184,   185,   186,   187,   372,   224,
     151,   150,   374,    92,   208,   154,   210,    55,   401,   211,
     212,     2,    49,   250,   266,   225,   149,   188,   224,   218,
     206,    10,   341,   115,    90,   199,   235,   235,   237,   171,
     238,   172,   240,   168,   225,   377,    62,     2,    84,    62,
     176,   107,   228,   259,   165,   286,   258,   397,   384,   107,
     224,    65,    11,   402,    62,   189,   198,    62,   367,   266,
      47,   162,   209,   130,   293,   123,   225,   258,   131,   224,
     392,   297,   134,   124,   125,   223,   224,   115,    11,    62,
     406,   417,   230,   230,    55,   225,   110,   107,   163,   198,
     198,   243,   225,   198,   223,   255,   147,   304,   305,   306,
     258,   121,   152,   414,   302,   367,   394,   367,   153,   326,
     292,   113,   294,   341,   224,   226,   294,   255,   255,   123,
       2,   190,   114,   320,   294,   135,   223,   124,   125,   363,
     225,   251,   364,   324,   226,   367,   350,   157,   352,   346,
     367,   224,    65,   224,   295,   223,   136,    62,   295,   349,
     160,   166,   223,   128,   107,   156,   295,   225,   296,   225,
     347,   294,   296,   265,   129,   351,   226,   262,     2,   190,
     296,   235,   164,   311,   316,   287,   288,   107,   167,   251,
     252,   289,   382,   294,   115,   226,   365,   224,   136,   407,
     223,   409,   226,   295,   255,   255,   255,   270,   375,   107,
     317,   389,   136,   225,   117,   118,   224,   296,   121,    11,
     198,   383,   253,   213,   229,   295,   348,   223,   194,   223,
       2,   190,   225,   217,   386,   387,   123,   230,   388,   296,
     226,   251,   252,   251,   124,   125,   243,   136,   239,   327,
     328,   107,  -175,   366,   340,   341,   342,   136,   398,   270,
     336,   279,   339,  -175,   195,   196,   197,   226,   247,   226,
    -174,    11,   280,   223,   253,   255,   271,   272,   273,   399,
    -173,  -174,   249,   263,    65,    27,    28,   108,   260,   190,
     418,  -173,   223,   103,   283,   284,   255,   311,     1,     2,
       3,     4,     5,     6,     7,     8,     9,   190,   290,    10,
     396,   301,   251,   226,   300,   363,   379,   251,   380,   381,
     303,     2,   190,   307,   308,   310,   251,   311,   309,   255,
     315,   332,   226,   191,   354,   366,     2,   219,   220,   355,
      11,    12,   361,   360,   362,    13,   391,    14,   378,   400,
     192,   104,    15,   415,    16,    17,   419,   403,   404,   105,
      18,   193,   109,   216,    94,   285,   155,    19,   357,    20,
      21,    22,    23,    69,    24,   236,   353,    11,   221,   412,
     345,    25,   222,   194,   416,   390,    82,    26,    27,    28,
      29,    30,    31,    32,     0,     0,   175,     0,     0,     0,
      33,    34,    35,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    10,     0,   115,     0,   195,
     196,   197,     0,     0,     0,    27,    28,    29,     0,     0,
       0,     0,     0,     2,   219,   220,     0,   117,   118,     0,
       0,   121,     0,     0,     0,     0,    11,    12,     0,     0,
       0,    13,     0,    14,     0,     0,     0,   214,    15,   123,
      16,    17,   325,     0,     0,     0,    18,   124,   125,     0,
       0,     0,   126,    19,    11,   221,    21,    22,    23,   222,
      24,     0,   137,   138,   139,   140,     0,    25,     0,     0,
       2,   190,     0,     0,    27,    28,    29,    30,    31,     0,
       0,   251,   252,     0,     0,   115,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,    10,    27,    28,    29,   117,   118,   119,   120,   121,
     122,    11,     0,     0,   253,     0,     0,     0,     0,     2,
     219,   220,     0,     0,     0,    65,     0,   123,     0,     0,
       0,     0,    11,    12,     0,   124,   125,    13,     0,    14,
     126,   127,     0,     0,    15,     0,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     0,    19,
      11,   221,    21,    22,    23,   222,    24,     0,   137,   138,
     139,   140,     0,    25,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,   115,    10,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,    13,     0,    14,    65,     0,   123,     0,
      15,     0,    16,    17,   158,     0,   124,   125,    18,     0,
       0,   126,   127,     0,     0,    19,     0,    20,    21,    22,
      23,     0,    24,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,     0,     0,     0,     0,     0,   115,    33,    34,
      35,    36,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    10,     0,   207,     0,     0,   123,
       0,     0,     0,    60,    11,    12,    61,   124,   125,    13,
       0,    14,   126,   127,     0,     0,    15,     0,    16,    17,
       0,     0,     0,     0,    18,    11,    12,   115,    65,     0,
      13,     0,    14,     0,    21,     0,     0,    15,     0,    16,
      17,     0,     0,     0,     0,    18,     0,   117,   118,   119,
       0,   121,    27,    28,    29,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,     0,   123,
       0,     0,     0,    27,    28,    29,     0,   124,   125,     0,
       0,     0,   126,   127,     0,    33,    34,    35,    36,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      10,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,   291,     0,     0,    13,     0,    14,     0,
       0,     0,     0,    15,     0,    16,    17,     0,    11,    12,
       0,    18,     0,    13,     0,    14,     0,     0,     0,     0,
      15,    21,    16,    17,   115,     0,     0,     0,    18,   116,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    27,
      28,    29,     0,     0,   117,   118,   119,   120,   121,   122,
       0,    33,    34,    35,    36,     0,    27,    28,    29,     0,
       0,   115,     0,     0,     0,     0,   123,   132,    33,    34,
      35,    36,   115,     0,   124,   125,     0,     0,     0,   126,
     127,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,   115,
       0,   124,   125,     0,   123,   261,   126,   127,     0,   115,
       0,     0,   124,   125,     0,     0,     0,   126,   127,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
     373,   123,     0,     0,     0,     0,     0,   115,     0,   124,
     125,   123,   385,   408,   126,   127,     0,   115,     0,   124,
     125,     0,     0,     0,   126,   127,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,   115,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   123,
       0,     0,   126,   127,     0,   117,   118,   124,   125,   121,
       0,     0,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
     126,   127
  };

  const short
  parser::yycheck_[] =
  {
       0,   130,     6,    13,   193,   280,   172,    21,   172,   199,
      10,     6,    65,    13,    14,     6,    16,    17,    18,    39,
     255,     0,    22,    15,    24,   193,    36,    20,   194,   195,
      17,    12,   195,     6,   163,   164,    50,    17,   167,    39,
     364,    75,   366,     0,    15,    65,   163,   164,     0,    20,
     167,    10,    47,    50,    46,     6,    47,    52,   333,    52,
      60,    48,   252,    97,   254,    65,    46,    11,    12,   198,
     394,    15,     0,    83,    21,    19,    23,    87,    25,    58,
     258,    52,    77,    30,    31,    32,    77,    39,   278,   142,
      21,   280,    72,    52,    51,    66,    47,    53,     0,   103,
      47,    58,   112,   378,   282,   271,   272,   273,   271,   272,
     273,    39,   280,    65,    70,    46,   116,   117,   118,   119,
     120,   121,   142,   123,   124,   125,   126,   127,   318,   152,
      74,    55,   322,    80,   134,    79,   136,    65,   373,   139,
     140,     6,   142,   171,   333,   152,    70,   128,   171,   149,
     131,    16,    21,    10,     5,   284,   156,   157,   158,    20,
     160,    22,   162,   107,   171,   333,   110,     6,     7,   113,
     114,    47,   153,   173,    50,   203,   342,   367,   342,    47,
     203,    50,    47,   373,   128,   129,   130,   131,   317,   378,
     142,    21,   136,    48,   222,    52,   203,   363,    48,   222,
     363,   229,    46,    60,    61,   152,   229,    10,    47,   153,
     378,   401,   156,   157,   142,   222,    52,    47,    48,   163,
     164,   165,   229,   167,   171,   172,    53,   237,   238,   239,
     396,    34,    46,   396,   234,   364,   365,   366,    15,   267,
     221,    48,    20,    21,   267,   152,    20,   194,   195,    52,
       6,     7,    59,   253,    20,    49,   203,    60,    61,    15,
     267,    17,    18,   263,   171,   394,   294,    48,   296,    35,
     399,   294,    50,   296,    52,   222,    70,   221,    52,    53,
      80,    21,   229,    48,    47,    48,    52,   294,    66,   296,
     290,    20,    66,   192,    59,   295,   203,    49,     6,     7,
      66,   301,    48,   247,   251,   204,   205,    47,    48,    17,
      18,    49,   340,    20,    10,   222,    72,   340,    70,   382,
     267,   384,   229,    52,   271,   272,   273,    35,    35,    47,
      48,   359,    70,   340,    30,    31,   359,    66,    34,    47,
     284,   341,    50,    58,    46,    52,    49,   294,    68,   296,
       6,     7,   359,    51,   354,   355,    52,   301,   358,    66,
     267,    17,    18,    17,    60,    61,   310,    70,    82,   268,
     269,    47,    48,   317,    20,    21,    22,    70,    49,    35,
     279,    35,   281,    59,   104,   105,   106,   294,    48,   296,
      48,    47,    46,   340,    50,   342,   104,   105,   106,    70,
      48,    59,    53,    15,    50,    95,    96,    97,    49,     7,
     410,    59,   359,     0,    49,    70,   363,   361,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     7,    46,    16,
      15,    70,    17,   340,    49,    15,   335,    17,   337,   338,
      49,     6,     7,    49,    49,    70,    17,   391,    51,   396,
      49,    35,   359,    18,    21,   399,     6,     7,     8,   102,
      47,    48,    70,    49,    21,    52,    48,    54,    46,    35,
      35,    58,    59,    35,    61,    62,    49,   376,   377,    39,
      67,    46,    46,   142,    30,    35,    80,    74,   310,    76,
      77,    78,    79,    14,    81,   157,   301,    47,    48,   391,
     284,    88,    52,    68,   399,   361,    21,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   113,    -1,    -1,    -1,
     107,   108,   109,   110,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    10,    -1,   104,
     105,   106,    -1,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    52,    -1,    54,    -1,    -1,    -1,    58,    59,    52,
      61,    62,    35,    -1,    -1,    -1,    67,    60,    61,    -1,
      -1,    -1,    65,    74,    47,    48,    77,    78,    79,    52,
      81,    -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,
       6,     7,    -1,    -1,    95,    96,    97,    98,    99,    -1,
      -1,    17,    18,    -1,    -1,    10,   107,   108,   109,   110,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,    95,    96,    97,    30,    31,    32,    33,    34,
      35,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,
      -1,    -1,    47,    48,    -1,    60,    61,    52,    -1,    54,
      65,    66,    -1,    -1,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      47,    48,    77,    78,    79,    52,    81,    -1,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    10,    16,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    52,    -1,    54,    50,    -1,    52,    -1,
      59,    -1,    61,    62,    58,    -1,    60,    61,    67,    -1,
      -1,    65,    66,    -1,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    10,   107,   108,
     109,   110,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    -1,    49,    -1,    -1,    52,
      -1,    -1,    -1,    46,    47,    48,    49,    60,    61,    52,
      -1,    54,    65,    66,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    47,    48,    10,    50,    -1,
      52,    -1,    54,    -1,    77,    -1,    -1,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    30,    31,    32,
      -1,    34,    95,    96,    97,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    52,
      -1,    -1,    -1,    95,    96,    97,    -1,    60,    61,    -1,
      -1,    -1,    65,    66,    -1,   107,   108,   109,   110,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    52,    -1,    54,    -1,
      -1,    -1,    -1,    59,    -1,    61,    62,    -1,    47,    48,
      -1,    67,    -1,    52,    -1,    54,    -1,    -1,    -1,    -1,
      59,    77,    61,    62,    10,    -1,    -1,    -1,    67,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    95,
      96,    97,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,   107,   108,   109,   110,    -1,    95,    96,    97,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    52,    16,   107,   108,
     109,   110,    10,    -1,    60,    61,    -1,    -1,    -1,    65,
      66,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    60,    61,    -1,    52,    53,    65,    66,    -1,    10,
      -1,    -1,    60,    61,    -1,    -1,    -1,    65,    66,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    10,    -1,    60,
      61,    52,    53,    16,    65,    66,    -1,    10,    -1,    60,
      61,    -1,    -1,    -1,    65,    66,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    10,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    52,
      -1,    -1,    65,    66,    -1,    30,    31,    60,    61,    34,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    47,    48,    52,    54,    59,    61,    62,    67,    74,
      76,    77,    78,    79,    81,    88,    94,    95,    96,    97,
      98,    99,   100,   107,   108,   109,   110,   112,   113,   114,
     115,   123,   125,   127,   129,   130,   131,   132,   172,   173,
     174,   175,   176,   177,   178,   181,   132,   173,   181,   127,
      46,    49,   127,   173,   180,    50,   122,   143,   173,   143,
     127,   173,   173,   173,   103,   116,   117,   118,   127,    75,
      97,   129,   174,   173,     7,   129,   171,   173,   129,   142,
       5,    77,   129,   133,   134,   129,   137,   129,   141,   122,
       0,     0,    58,     0,    58,   115,   123,    47,    97,   130,
      52,   134,   136,    48,    59,    10,    15,    30,    31,    32,
      33,    34,    35,    52,    60,    61,    65,    66,    48,    59,
      48,    48,    16,   173,    46,    49,    70,    83,    84,    85,
      86,   119,   120,   123,   124,   125,   126,    53,    53,    70,
      55,   127,    46,    15,   127,   136,    48,    48,    58,   122,
      80,   122,    21,    48,    48,    50,    21,    48,   127,   179,
     180,    20,    22,    21,   122,   179,   127,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   180,   127,
       7,    18,    35,    46,    68,   104,   105,   106,   127,   128,
     152,   153,   156,   157,   158,   165,   180,    49,   173,   127,
     173,   173,   173,    58,    58,   123,   126,    51,   173,     7,
       8,    48,    52,   129,   172,   176,   178,   182,   180,    46,
     127,   144,   145,   146,   147,   173,   144,   173,   173,    82,
     173,   152,   152,   127,   138,   139,   140,    48,   152,    53,
     182,    17,    18,    50,   128,   129,   167,   168,   170,   173,
      49,    53,    49,    15,   155,   155,   157,   159,   160,   165,
      35,   104,   105,   106,   166,   167,   166,   128,   154,    35,
      46,   169,   170,    49,    70,    35,   182,   155,   155,    49,
      46,    49,   180,   182,    20,    52,    66,   182,    15,    46,
      49,    70,   173,    49,   122,   122,   122,    49,    49,    51,
      70,   127,   148,   149,   151,    49,   129,    48,   161,   169,
     173,   169,   161,   168,   173,    35,   182,   155,   155,   166,
     166,   166,    35,    46,    72,   169,   155,   160,   165,   155,
      20,    21,    22,   121,   122,   156,    35,   173,    49,    53,
     182,   173,   182,   146,    21,   102,   135,   140,    21,    46,
      49,    70,    21,    15,    18,    72,   127,   128,   162,   163,
     164,   169,   169,    51,   169,    35,   160,   165,    46,   155,
     155,   155,   182,   173,   167,    53,   173,   173,   173,   182,
     151,    48,   166,   163,   128,   163,    15,   169,    49,    70,
      35,   161,   169,   155,   155,   160,   165,   121,    16,   121,
      15,   150,   148,   163,   166,    35,   164,   169,   173,    49
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   111,   112,   112,   113,   113,   113,   114,   114,   114,
     114,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   121,
     121,   122,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   128,   129,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   135,   135,   136,
     136,   136,   137,   138,   138,   139,   139,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   158,   158,   158,   158,   159,
     159,   160,   160,   160,   160,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   164,   164,   164,   164,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   166,   167,   167,
     167,   167,   167,   167,   167,   167,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   174,   175,   175,   175,   175,   176,
     176,   176,   177,   177,   178,   178,   178,   179,   179,   180,
     180,   180,   180,   181,   181,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     3,     0,     1,     2,     1,     2,     2,     2,     1,
       3,     3,     3,     5,     5,     3,     5,     3,     2,     1,
       1,     2,     2,     4,     2,     1,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     5,     0,     2,     1,
       3,     3,     4,     0,     1,     1,     3,     1,     5,     8,
       3,     6,     1,     3,     0,     1,     1,     3,     2,     1,
       2,     2,     0,     1,     1,     3,     0,     2,     4,     3,
       0,     1,     1,     3,     0,     1,     0,     2,     5,     5,
       4,     3,     2,     4,     3,     2,     3,     2,     5,     5,
       4,     3,     2,     1,     1,     2,     3,     1,     2,     0,
       1,     2,     3,     1,     2,     3,     1,     3,     1,     2,
       2,     3,     2,     3,     2,     3,     1,     2,     2,     3,
       3,     3,     2,     2,     1,     1,     2,     1,     1,     3,
       2,     2,     3,     4,     5,     1,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     3,     3,     3,     4,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     2,     2,     5,     5,     4,
       4,     4,     1,     4,     5,     7,     7,     0,     1,     1,
       3,     3,     5,     2,     1,     1,     1,     1,     1,     3,
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
  "\"`continue`\"", "\"`break`\"", "\"`return`\"", "\"`yield`\"", "AUTO",
  "USING", "THROW", "SIZEOF", "LOWEST", "DEREF", "PREFIXMINUS", "INCLUDE",
  "INLINE", "VIABLE", "\"`fn`\"", "\"`typefn`\"", "ENUM", "STRUCT",
  "EXTENDS", "REQUIRES", "\"weak modifier\"", "\"typename modifier\"",
  "\"constexpr modifier\"", "\"runctime modifier\"", "\"nil\"", "\"true\"",
  "\"false\"", "PROBE", "$accept", "begin", "statement_any",
  "finished-statement-any", "statement", "let-decl", "let-decl-start",
  "let-decl-start-with-opt-type", "infunction-statement-any",
  "finished-infunction-statement-any", "function-body",
  "braced-statements", "finished-statement", "infunction-statement-set",
  "generic-statement", "infunction-statement", "identifier",
  "internal-identifier", "qname", "fn-kind", "fn-kind-set",
  "fn-prefix-decl", "fn-name", "fn-start-decl", "fn-requirement-opt",
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
  "reference-expression", "any-reference-expression", "syntax-expression",
  "apostrophe-expression", "new-expression", "call-expression",
  "lambda-start-decl", "lambda-expression", "pack-expression-opt",
  "pack-expression", "compound-expression", "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   337,   337,   338,   342,   344,   346,   363,   365,   366,
     368,   373,   375,   377,   379,   381,   386,   388,   393,   395,
     400,   401,   406,   408,   410,   415,   417,   418,   420,   426,
     428,   438,   443,   445,   447,   449,   451,   453,   463,   468,
     470,   475,   477,   479,   488,   490,   492,   497,   499,   501,
     503,   505,   507,   512,   520,   535,   537,   539,   545,   546,
     550,   551,   555,   557,   562,   563,   567,   585,   586,   598,
     599,   601,   608,   613,   614,   618,   620,   625,   631,   633,
     656,   663,   681,   683,   689,   690,   694,   696,   701,   703,
     708,   710,   716,   717,   721,   723,   728,   729,   733,   735,
     742,   743,   747,   749,   754,   755,   759,   760,   764,   766,
     768,   770,   772,   776,   780,   782,   784,   786,   791,   793,
     795,   797,   799,   804,   805,   809,   811,   815,   817,   822,
     827,   831,   833,   837,   839,   849,   854,   856,   862,   864,
     867,   869,   873,   876,   882,   885,   898,   901,   906,   907,
     908,   909,   910,   911,   912,   916,   917,   918,   922,   924,
     926,   928,   930,   932,   934,   936,   941,   946,   948,   952,
     954,   960,   962,   967,   969,   971,   973,   975,   980,   982,
     984,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1007,  1016,  1024,  1026,  1028,  1030,  1032,  1039,  1042,  1044,
    1046,  1051,  1053,  1057,  1059,  1061,  1064,  1068,  1071,  1074,
    1077,  1078,  1079,  1080,  1084,  1089,  1091,  1093,  1095,  1100,
    1102,  1104,  1116,  1118,  1123,  1130,  1138,  1149,  1151,  1156,
    1158,  1164,  1169,  1177,  1179,  1220,  1222,  1224,  1226,  1229,
    1231,  1233,  1235,  1237,  1239
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
     105,   106,   107,   108,   109,   110
    };
    // Last valid token kind.
    const int code_max = 365;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 5601 "annium.tab.cpp"

#line 1566 "annium.y"

