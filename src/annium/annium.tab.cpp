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
#line 1867 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1873 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1879 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1885 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 339 "annium.y"
                 { }
#line 1891 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 339 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 339 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 339 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 339 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 339 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 339 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 339 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 339 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 339 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 339 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 339 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 339 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 339 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 339 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 339 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 339 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 339 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 339 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 339 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 339 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 339 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 339 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 339 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 339 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 339 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 339 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 339 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 339 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 339 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 339 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 339 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 339 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 339 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 339 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 339 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 339 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 339 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 339 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 339 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 339 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 339 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 339 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
#line 339 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 339 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl: // let-decl
#line 339 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start: // let-decl-start
#line 339 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 339 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
#line 339 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
#line 339 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_function_body: // function-body
#line 339 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_braced_statements: // braced-statements
#line 339 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_finished_statement: // finished-statement
#line 339 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_if_else_tail: // if-else-tail
#line 339 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
#line 339 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_expression_statement: // expression-statement
#line 339 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_generic_statement: // generic-statement
#line 339 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_infunction_statement: // infunction-statement
#line 339 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 339 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
#line 339 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 339 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
#line 339 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
#line 339 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
#line 339 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_name: // fn-name
#line 339 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
#line 339 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
#line 339 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_decl: // fn-decl
#line 339 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
#line 339 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
#line 339 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list: // case-list
#line 339 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_decl: // case-decl
#line 339 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
#line 339 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_using_decl: // using-decl
#line 339 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_expression_list: // expression-list
#line 339 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
#line 339 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list: // argument-list
#line 339 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 339 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_argument_name: // argument-name
#line 339 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
#line 339 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list: // field-list
#line 339 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
#line 339 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 339 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
#line 339 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list: // parameter-list
#line 339 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
#line 339 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
#line 339 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
#line 339 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 339 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
#line 339 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
#line 339 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression: // constraint-expression
#line 339 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 339 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_list: // pattern-list
#line 339 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
#line 339 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_field: // pattern-field
#line 339 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
#line 339 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
#line 339 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 339 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_concept_expression: // concept-expression
#line 339 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
#line 339 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
#line 339 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
#line 339 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
#line 339 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
#line 339 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_grouped_expression: // grouped-expression
#line 339 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_new_expression: // new-expression
#line 339 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_call_expression: // call-expression
#line 339 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_syntax_expression: // syntax-expression
#line 339 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
#line 339 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_lambda_expression: // lambda-expression
#line 339 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
#line 339 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_pack_expression: // pack-expression
#line 339 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_compound_expression: // compound-expression
#line 339 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_type_expr: // type-expr
#line 339 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
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
#line 3069 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 345 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3075 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 350 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3081 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 352 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3087 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 354 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3093 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 371 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3099 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 372 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3105 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 374 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3111 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 376 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3117 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 381 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3123 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 383 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3129 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 385 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3135 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 387 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3141 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 391 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3147 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 393 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3153 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 398 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3159 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 400 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3165 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 404 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3171 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 406 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3177 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 411 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3183 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 413 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3189 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 415 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3195 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 420 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3201 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 421 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3207 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 423 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3213 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 425 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3219 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 430 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3225 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 434 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3231 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 445 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3237 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 450 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3243 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 452 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3249 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 454 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3255 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 456 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3261 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 458 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3267 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 460 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3273 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 462 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3283 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 472 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3289 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 477 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3295 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 479 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3301 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 483 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3307 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 484 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3313 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 489 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3319 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 491 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3328 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 499 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3334 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 501 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3340 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 503 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3351 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 510 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3357 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 511 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3363 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 515 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3369 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 517 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3375 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 519 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3381 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 521 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3387 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 523 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3393 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 525 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3399 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 530 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3405 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 538 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3411 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 553 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3417 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 555 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3423 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 557 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3429 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 562 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3435 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 563 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3441 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 567 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3447 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 568 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3453 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 573 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3459 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 575 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3465 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 580 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3471 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 582 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3477 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 587 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3483 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 604 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3489 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 607 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3495 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 618 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3501 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 620 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3507 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 622 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3513 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 629 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3519 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 633 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3525 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 634 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3531 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 639 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3537 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 641 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3543 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 646 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3549 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 652 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3555 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 654 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3561 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 677 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3571 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 683 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3582 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 700 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3588 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 702 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3594 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 707 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3600 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 708 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3606 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 713 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3612 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 715 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3618 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 720 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3624 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 722 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3630 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 727 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3636 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 729 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3642 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 734 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3648 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 735 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3654 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 740 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3660 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 742 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3666 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 746 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3672 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 747 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3678 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 752 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3684 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 754 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3690 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 760 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3696 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 761 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3702 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 766 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3708 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 768 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3714 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 772 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3720 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 773 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3726 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 777 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3732 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 778 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3738 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 784 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3744 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 788 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3750 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 790 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3756 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 794 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3762 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: qname parameter-default-value-opt
#line 797 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3771 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: qname "`...`" parameter-default-value-opt
#line 802 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3781 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 810 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3787 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 812 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3793 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 814 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3799 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 816 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3805 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`=>`" syntax-expression
#line 819 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annotated_identifier > ()), std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3811 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: internal-identifier "`=>`" syntax-expression
#line 821 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3817 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 824 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3823 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: internal-identifier "`:`" concept-expression-list parameter-default-value-opt
#line 826 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };   }
#line 3829 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 828 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3835 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 830 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3841 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: pattern-mod parameter-default-value-opt
#line 832 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3847 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 840 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3853 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: "`_`" parameter-default-value-opt
#line 842 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3859 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 844 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3865 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: "`...`" parameter-default-value-opt
#line 846 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3871 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 851 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3877 "annium.tab.cpp"
    break;

  case 133: // constraint-expression-specified-mod: "constexpr modifier"
#line 857 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 3883 "annium.tab.cpp"
    break;

  case 134: // constraint-expression-specified-mod: "runctime modifier"
#line 858 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3889 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 863 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3895 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 865 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3901 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod
#line 869 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3907 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 871 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3913 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-mod: %empty
#line 876 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3922 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-mod: constraint-expression-specified-mod
#line 880 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 3928 "annium.tab.cpp"
    break;

  case 141: // constraint-expression: constraint-expression-mod type-expr
#line 885 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3934 "annium.tab.cpp"
    break;

  case 142: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 887 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3940 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod
#line 891 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3946 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod "`...`"
#line 893 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3952 "annium.tab.cpp"
    break;

  case 145: // subpatterns: "`(`" pattern-list "`)`"
#line 903 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3958 "annium.tab.cpp"
    break;

  case 146: // pattern-list: pattern-field
#line 908 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 3964 "annium.tab.cpp"
    break;

  case 147: // pattern-list: pattern-list "," pattern-field
#line 910 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 3970 "annium.tab.cpp"
    break;

  case 148: // pattern-field-sfx: concept-expression-list-opt
#line 916 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3976 "annium.tab.cpp"
    break;

  case 149: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 918 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3982 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 921 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3988 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 923 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3994 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: "`=`" pattern-sfx
#line 927 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4000 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 930 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4006 "annium.tab.cpp"
    break;

  case 154: // pattern-field: identifier pattern-field-sfx
#line 936 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4012 "annium.tab.cpp"
    break;

  case 155: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 939 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4018 "annium.tab.cpp"
    break;

  case 156: // pattern-field: pattern-field-sfx
#line 952 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4024 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`_`" pattern-field-sfx
#line 955 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4030 "annium.tab.cpp"
    break;

  case 158: // pattern-mod: "`~`" pattern-sfx
#line 959 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 4036 "annium.tab.cpp"
    break;

  case 159: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 960 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4042 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 961 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4048 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 962 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4054 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "typename modifier"
#line 963 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4060 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "typename modifier" pattern-sfx
#line 964 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4066 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "typename modifier"
#line 965 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4072 "annium.tab.cpp"
    break;

  case 165: // pattern-sfx: pattern
#line 969 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4078 "annium.tab.cpp"
    break;

  case 166: // pattern-sfx: pattern "`...`"
#line 970 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4084 "annium.tab.cpp"
    break;

  case 167: // pattern-sfx: "`...`"
#line 971 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4090 "annium.tab.cpp"
    break;

  case 168: // pattern: qname
#line 976 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4096 "annium.tab.cpp"
    break;

  case 169: // pattern: qname subpatterns concept-expression-list-opt
#line 978 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4102 "annium.tab.cpp"
    break;

  case 170: // pattern: internal-identifier concept-expression-list-opt
#line 980 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4108 "annium.tab.cpp"
    break;

  case 171: // pattern: "`_`" concept-expression-list-opt
#line 982 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4114 "annium.tab.cpp"
    break;

  case 172: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 984 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4120 "annium.tab.cpp"
    break;

  case 173: // pattern: "`(`" "`)`"
#line 986 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4126 "annium.tab.cpp"
    break;

  case 174: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 988 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4132 "annium.tab.cpp"
    break;

  case 175: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 990 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4138 "annium.tab.cpp"
    break;

  case 176: // pattern: concept-expression-list
#line 992 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4144 "annium.tab.cpp"
    break;

  case 177: // concept-expression: "`@`" qname
#line 997 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4150 "annium.tab.cpp"
    break;

  case 178: // concept-expression-list-opt: %empty
#line 1002 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4156 "annium.tab.cpp"
    break;

  case 179: // concept-expression-list-opt: concept-expression-list
#line 1003 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4162 "annium.tab.cpp"
    break;

  case 180: // concept-expression-list: concept-expression
#line 1008 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4168 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list: concept-expression-list concept-expression
#line 1010 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4174 "annium.tab.cpp"
    break;

  case 182: // reference-expression: CONTEXT_IDENTIFIER
#line 1016 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4180 "annium.tab.cpp"
    break;

  case 183: // reference-expression: qname
#line 1018 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4186 "annium.tab.cpp"
    break;

  case 184: // any-reference-expression: RESERVED_IDENTIFIER
#line 1023 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4192 "annium.tab.cpp"
    break;

  case 185: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1025 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4198 "annium.tab.cpp"
    break;

  case 186: // any-reference-expression: qname
#line 1027 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4204 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-base: "nil"
#line 1032 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4210 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-base: "true"
#line 1034 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4216 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: "false"
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4222 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: INTEGER
#line 1038 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4228 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: DECIMAL
#line 1040 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4234 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: DECIMAL_S
#line 1042 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4240 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: INTEGER_INDEX
#line 1044 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4246 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: STRING
#line 1046 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4252 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: CT_IDENTIFIER
#line 1048 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4258 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: any-reference-expression
#line 1049 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4264 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: "`(`" "`)`"
#line 1051 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4270 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1053 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4279 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1059 "annium.y"
        { 
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4291 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1067 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4297 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`[[`" expression-list "`]]`"
#line 1069 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } }; }
#line 4303 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1071 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4309 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: PROBE braced-statements
#line 1073 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4315 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`.`" identifier
#line 1075 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4321 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1082 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4331 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`-`" syntax-expression
#line 1089 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4337 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`!`" syntax-expression
#line 1091 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4343 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: "`*`" syntax-expression
#line 1093 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4349 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1098 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4355 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1100 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4361 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1104 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4367 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1106 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4373 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1108 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4379 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1111 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4385 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1115 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4391 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1118 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4397 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1121 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4403 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1123 "annium.y"
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
#line 4418 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1135 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4424 "annium.tab.cpp"
    break;

  case 220: // grouped-expression: "`(`" pack-expression "`)`"
#line 1155 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4437 "annium.tab.cpp"
    break;

  case 221: // new-expression: "`new`" qname
#line 1168 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4443 "annium.tab.cpp"
    break;

  case 222: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1172 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4449 "annium.tab.cpp"
    break;

  case 223: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4455 "annium.tab.cpp"
    break;

  case 224: // call-expression: any-reference-expression "`.`" identifier
#line 1181 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4461 "annium.tab.cpp"
    break;

  case 225: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1183 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4470 "annium.tab.cpp"
    break;

  case 226: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1188 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4476 "annium.tab.cpp"
    break;

  case 227: // call-expression: call-expression "`.`" identifier
#line 1190 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4482 "annium.tab.cpp"
    break;

  case 228: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1192 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4491 "annium.tab.cpp"
    break;

  case 229: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1197 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4497 "annium.tab.cpp"
    break;

  case 230: // syntax-expression: syntax-expression-base
#line 1201 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4503 "annium.tab.cpp"
    break;

  case 231: // syntax-expression: new-expression
#line 1202 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4509 "annium.tab.cpp"
    break;

  case 232: // syntax-expression: compound-expression
#line 1203 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4515 "annium.tab.cpp"
    break;

  case 233: // syntax-expression: lambda-expression
#line 1204 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4521 "annium.tab.cpp"
    break;

  case 234: // syntax-expression: grouped-expression
#line 1205 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4527 "annium.tab.cpp"
    break;

  case 235: // lambda-start-decl: fn-prefix-decl
#line 1211 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4533 "annium.tab.cpp"
    break;

  case 236: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1213 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4539 "annium.tab.cpp"
    break;

  case 237: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1218 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4550 "annium.tab.cpp"
    break;

  case 238: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1225 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4562 "annium.tab.cpp"
    break;

  case 239: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1233 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4574 "annium.tab.cpp"
    break;

  case 240: // pack-expression-opt: %empty
#line 1244 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4580 "annium.tab.cpp"
    break;

  case 241: // pack-expression-opt: pack-expression
#line 1246 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4586 "annium.tab.cpp"
    break;

  case 242: // pack-expression: syntax-expression
#line 1251 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4592 "annium.tab.cpp"
    break;

  case 243: // pack-expression: identifier "`:`" syntax-expression
#line 1253 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4602 "annium.tab.cpp"
    break;

  case 244: // pack-expression: pack-expression "," syntax-expression
#line 1259 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4611 "annium.tab.cpp"
    break;

  case 245: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1264 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4620 "annium.tab.cpp"
    break;

  case 246: // compound-expression: syntax-expression "`...`"
#line 1272 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4626 "annium.tab.cpp"
    break;

  case 247: // compound-expression: call-expression
#line 1273 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4632 "annium.tab.cpp"
    break;

  case 248: // type-expr: qname
#line 1314 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4638 "annium.tab.cpp"
    break;

  case 249: // type-expr: RESERVED_IDENTIFIER
#line 1316 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4644 "annium.tab.cpp"
    break;

  case 250: // type-expr: CONTEXT_IDENTIFIER
#line 1318 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4650 "annium.tab.cpp"
    break;

  case 251: // type-expr: call-expression
#line 1319 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4656 "annium.tab.cpp"
    break;

  case 252: // type-expr: "`[`" type-expr "`]`"
#line 1321 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4662 "annium.tab.cpp"
    break;

  case 253: // type-expr: "`(`" "`)`"
#line 1323 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4668 "annium.tab.cpp"
    break;

  case 254: // type-expr: grouped-expression
#line 1324 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4674 "annium.tab.cpp"
    break;

  case 255: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1326 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4680 "annium.tab.cpp"
    break;

  case 256: // type-expr: type-expr "`|`" type-expr
#line 1328 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4686 "annium.tab.cpp"
    break;

  case 257: // type-expr: type-expr "`->`" type-expr
#line 1330 "annium.y"
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
#line 4701 "annium.tab.cpp"
    break;


#line 4705 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -251;

  const short parser::yytable_ninf_ = -187;

  const short
  parser::yypact_[] =
  {
     876,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
      30,   984,  1005,  1120,    30,  1120,  1120,  1120,    -2,   -25,
      47,  1120,   139,  1120,    47,     6,  -251,  -251,  -251,     4,
      47,    47,  -251,  -251,  -251,   -15,    40,    19,   552,  -251,
    -251,  -251,  -251,  -251,    66,  -251,   349,    53,   -18,  -251,
      36,  -251,   271,   624,    71,  -251,   284,  -251,  1120,  -251,
     121,   119,  1340,   177,  -251,   768,   124,    46,  1340,   227,
    -251,    18,    18,    18,    30,  -251,   137,   174,  -251,    30,
       4,   318,   478,  -251,    66,   130,  1192,   264,  -251,  -251,
    -251,    66,   194,  -251,   156,  -251,   277,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,    30,  -251,  -251,  1120,
     143,     5,  1120,    30,  1120,  1120,    30,  -251,  1120,   447,
    1120,  1120,  1120,  1120,  1120,  -251,  1120,  1120,  1120,  1120,
    1120,   447,   384,   732,  1120,  -251,  1120,  -251,  -251,  1120,
    1120,   157,   660,  -251,   171,  -251,  -251,  -251,  -251,  1120,
    -251,  -251,   447,  1120,   213,  -251,  1120,  1120,  -251,  1120,
     185,  1120,   384,   384,    30,   265,   384,  -251,   224,   259,
     447,   590,  1120,  -251,   306,   329,   333,   218,   338,  1340,
     273,   305,  1099,   447,   303,   -18,    36,   271,   138,   365,
     365,   779,   671,    54,   840,   167,   167,   564,   887,    37,
    -251,   374,   374,   -44,   426,  1138,  -251,  -251,    21,   392,
      63,   348,   330,  -251,   534,   374,   374,  -251,  1340,   359,
    1340,  1340,  1340,  -251,  -251,  -251,  -251,  -251,  1340,    37,
     259,   447,   163,   367,   351,  -251,  1120,  1340,   -15,  1192,
     884,  -251,  1340,   369,   393,  -251,   390,   378,  -251,    30,
     400,  -251,    37,    47,   168,   407,  1120,   440,   376,  -251,
    -251,   440,  1340,  -251,  1120,  -251,  -251,  1120,  -251,    -6,
     447,  1120,   447,  -251,  1120,  -251,  -251,  -251,   570,   374,
     374,  -251,  1138,  1138,  1138,  -251,   424,  -251,  -251,     8,
    1120,   374,    27,   374,   440,   374,  -251,   233,   384,  -251,
     228,  -251,  -251,  1120,    37,  -251,  -251,  -251,  1120,  1340,
    -251,  -251,  -251,  -251,     4,   439,   360,  -251,    30,   116,
     413,   394,  -251,   456,    66,   255,   440,  -251,  -251,  1229,
    -251,   440,  -251,   419,   430,  -251,   138,  1266,   138,  1340,
    -251,   229,  -251,  -251,  -251,  -251,  -251,  -251,  1120,    27,
     435,  1340,  -251,   440,   374,   374,   289,  -251,  -251,   447,
    1120,   590,  -251,  -251,  -251,  -251,  1340,  -251,   -15,  1120,
     443,  -251,  -251,  1120,   447,  -251,    30,   445,  1138,   364,
     476,   364,   355,   230,  -251,  -251,   453,  -251,   168,  -251,
    -251,  -251,  -251,  -251,  1340,   440,   374,   374,   289,   -44,
     289,  -251,  -251,  -251,   302,  1340,   134,  1340,  1120,  1340,
     295,  -251,    30,  -251,  -251,   364,  -251,  1138,   461,  -251,
     255,  -251,   440,  -251,   289,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  1303,  1120,  -251,   448,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  1340,  -251
  };

  const short
  parser::yydefact_[] =
  {
       4,   194,    56,   185,   184,   193,   190,   191,   192,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    65,     0,
       0,     0,   187,   188,   189,     0,     0,     0,     0,     5,
       7,    49,    13,    59,   186,    63,     0,   235,   196,   230,
     234,   231,   247,     0,     0,   233,   232,    58,     0,   197,
      59,   235,   242,     0,   232,    21,     0,     0,    85,     0,
     204,   206,   208,   207,     0,    45,    19,    15,    17,     0,
       0,   221,     0,   182,   183,     0,     0,     0,    48,    31,
      68,    67,     0,    46,     0,    38,     0,    14,   203,     1,
       2,    10,     3,     8,     6,     9,     0,    66,    64,   240,
      72,     0,   240,     0,   240,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,   103,     0,     0,   220,     0,    52,    51,    53,
       0,    41,    42,    24,     0,    50,    22,   200,   199,     0,
     201,    18,     0,     0,     0,    12,    87,     0,    32,     0,
      35,     0,   103,   103,    76,     0,   103,    60,     0,   241,
       0,     0,     0,    37,     0,   224,     0,     0,   227,    44,
     250,   249,     0,     0,   248,     0,   254,   251,   218,   211,
     212,   216,   217,   213,     0,   209,   210,   214,   215,   219,
      57,   109,   109,   139,     0,   164,   133,   134,    59,   178,
     109,     0,   104,   105,   137,   109,   109,   198,   243,    59,
     244,    54,    55,    27,    25,    26,    23,    30,    86,    20,
      16,     0,    59,     0,    88,    89,     0,    92,     0,     0,
       0,    36,    83,     0,     0,    80,     0,    77,    78,    95,
       0,   236,    73,     0,   178,     0,     0,   178,   168,    74,
     180,   176,    47,   223,   240,   229,   226,   240,   253,     0,
       0,     0,     0,   202,     0,   129,   131,   140,   143,   109,
     109,   167,   162,     0,     0,   158,   165,   163,   108,     0,
       0,   109,   139,   109,   179,   109,   115,     0,     0,   138,
     135,   114,   127,     0,    11,    93,    94,   222,     0,    91,
      33,    34,    39,    40,     0,     0,    70,    75,     0,     0,
       0,    96,    97,     0,   177,   178,   178,   171,   173,     0,
     170,   178,   181,     0,     0,   252,   257,     0,   256,   110,
     144,   141,   113,   126,   161,   159,   160,   166,     0,   139,
       0,   122,   130,   140,   109,   109,   109,   128,   116,     0,
       0,     0,   237,    28,   106,   136,   245,    90,     0,     0,
       0,    69,    79,     0,     0,    81,     0,     0,     0,   178,
       0,   178,   178,     0,   156,   146,   148,   172,   178,   169,
     225,   228,   255,   142,   121,   140,   109,   109,   109,   139,
     109,   112,   123,   124,     0,    29,     0,    84,     0,   102,
      99,    98,    95,   152,   157,   178,   154,     0,   150,   145,
     178,   149,   178,   174,   109,   111,   117,   118,   132,   120,
     125,   238,   239,     0,     0,   101,     0,   155,   153,   151,
     147,   175,   119,    71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -251,  -251,  -251,  -251,   463,  -251,  -251,  -251,  -251,  -251,
     -12,   -10,   -33,  -251,  -251,   345,   -45,   361,    38,  -129,
      61,   458,  -251,     1,  -251,   485,  -251,   -74,  -251,  -251,
    -251,   187,  -251,  -251,   494,  -251,  -251,   207,  -251,   104,
    -251,  -251,   141,   274,  -251,  -251,   191,   220,  -185,  -251,
    -251,  -224,  -250,  -251,  -146,    99,  -181,  -196,  -164,  -190,
      84,    34,  -251,    29,  -251,   106,  -251,   126,     0,  -251,
    -251,   -69,    64,    31,   197
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    36,    37,    38,    39,    75,    76,    77,   141,   142,
     362,   363,    40,   241,   144,    41,    42,   146,    43,   257,
      44,    45,    46,    61,    92,   110,   371,   111,    95,   246,
     247,   248,    97,    88,    67,   233,   234,   235,   236,   320,
     321,   435,   322,   211,   212,   289,   275,   213,   214,   215,
     278,   279,   326,   383,   384,   385,   216,   285,   286,   260,
     386,   294,    85,    48,    49,    50,    51,    52,    62,    54,
      55,   168,   169,    64,   188
  };

  const short
  parser::yytable_[] =
  {
      53,    47,    66,   209,     2,   105,   155,   259,   331,   287,
       2,    89,    68,    68,   270,    71,    72,    73,   277,   100,
     145,    82,   280,    86,   204,    98,   172,   117,   200,   348,
     112,    56,   143,   209,   209,    65,     2,   209,    53,    47,
      99,   113,  -107,   174,   253,   176,   271,   335,    57,    60,
      79,    10,    70,     2,   349,    65,    78,   270,   133,     2,
     272,   205,   206,   117,   207,    53,    47,  -107,   354,    56,
     126,   332,   158,    80,   119,    63,   160,   101,   274,   288,
     350,    81,    90,    84,   114,    87,   344,   345,   346,   271,
      91,    94,    96,  -107,    10,   204,    56,   145,   295,   148,
      10,   173,    74,   272,   332,   109,   126,   353,    91,   225,
     106,   355,   151,   106,   127,   128,   149,   154,   179,   132,
     189,   190,   191,   192,   193,   396,   194,   195,   196,   197,
     198,    90,   205,   206,   218,   207,   220,   373,   422,   221,
     222,    91,    53,    47,   167,     2,    83,    60,   185,   228,
      60,   175,    60,    60,   178,   360,   237,    53,   270,   239,
     185,   242,   374,   170,   395,   171,   332,   134,   397,   209,
     208,   109,   262,    56,   219,   428,   117,   147,   305,   177,
     184,   185,   413,   152,    65,   253,    10,   119,    56,   153,
     271,    60,   184,   210,   232,   333,   382,   406,   334,   185,
     208,   208,   245,   106,   208,   261,   164,   313,   332,   306,
     332,   159,   185,   184,   277,   223,   325,   230,   429,   126,
      60,   438,   227,   210,   210,   186,   135,   210,   310,   311,
     312,   184,   258,   414,   332,   416,   309,   186,   261,   261,
     368,   314,   163,   185,   184,   187,    63,   136,   270,   270,
     382,   415,   382,   359,   360,   361,   329,   187,   186,   231,
     185,     2,   200,   365,   393,   258,   258,   266,   240,   437,
     378,   337,   253,   379,   339,   184,   186,   251,   187,   419,
     271,   271,   150,    65,   -43,   161,   382,   319,   136,   186,
     351,   382,   184,   293,   272,   272,   187,   149,   165,   185,
     420,   185,    60,   366,   274,    60,   253,   185,   237,   187,
     434,   106,   162,   249,   324,   270,   261,   261,   261,   115,
     186,  -185,   270,   360,   106,   166,   356,   380,   199,   136,
     116,   184,  -185,   184,   -43,   -43,   208,   186,   327,   184,
     187,   330,   -43,   258,   258,   258,   232,   271,   394,   229,
     106,  -186,    65,  -184,   271,   263,   245,   187,   173,   210,
     405,   272,  -186,   381,  -184,   106,   156,   252,   272,   407,
     417,   200,   253,   409,   117,    91,   186,   264,   186,   378,
     269,   253,   265,   398,   186,   119,   267,   400,   185,   274,
       2,   200,   431,   276,   432,   261,   187,   297,   187,   124,
     298,   296,   201,   185,   187,   303,   301,   302,   433,   253,
     387,   300,   261,   290,   319,   389,   307,   126,   315,   202,
     184,   308,   258,   106,   325,   127,   128,   291,   304,   424,
     203,    10,     2,   200,   444,   184,   243,   244,   292,   258,
     250,   317,   316,   253,   254,    26,    27,   107,   318,   323,
     319,   261,   204,     2,   180,   181,   328,   253,   381,   347,
     369,   281,   375,   370,   376,   186,   418,   336,   390,   338,
     342,   343,   423,    10,   255,   341,   256,   377,   258,   391,
     186,   399,   352,   200,   357,   187,   358,   117,   421,   205,
     206,   408,   207,   412,    10,   182,   439,   445,   119,   183,
     187,   104,   238,   226,   108,   372,   441,    69,   120,   121,
     122,   123,   124,   125,    93,   367,   436,   411,   364,   440,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
     126,   282,   283,     0,   284,     0,   157,     0,   127,   128,
       2,   180,   181,   129,   130,   401,   402,   403,     0,     0,
       0,     0,   102,     0,   131,     0,   404,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,   299,
       0,   410,     0,   117,     0,     0,     2,   180,   181,     0,
       0,    10,   182,     0,   119,     0,   183,   425,   426,   427,
       0,   430,     0,     0,   120,   121,     2,   200,   124,    10,
      11,     0,     0,     0,    12,   340,    13,   253,   254,     0,
     103,    14,     0,    15,    16,   442,   126,    10,   182,    17,
       0,     0,   183,     0,   127,   128,    18,     0,     0,    19,
      20,    21,    22,   117,    23,     0,     0,    10,   255,   118,
     256,    24,     0,     0,   119,     0,     0,    25,    26,    27,
      28,    29,    30,    31,   120,   121,   122,   123,   124,   125,
       0,    32,    33,    34,    35,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,   126,     0,     0,     0,
     117,     0,     0,     0,   127,   128,     0,     0,     0,   129,
     130,   119,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   120,   121,   122,     0,   124,     0,    10,    11,     0,
       0,     0,    12,     0,    13,     0,     0,     0,   224,    14,
       0,    15,    16,   126,     0,     0,     0,    17,     0,     0,
       0,   127,   128,     0,    18,     0,   129,   130,    20,    21,
      22,   117,    23,     0,   137,   138,   139,   140,     0,    24,
       0,     0,   119,     0,     0,    25,    26,    27,    28,    29,
      30,     0,   120,   121,   122,   123,   124,   125,     0,    32,
      33,    34,    35,     1,     2,     3,     4,     5,     6,     7,
       8,   217,     9,     0,   126,     0,     0,     0,   117,     0,
       0,     0,   127,   128,     0,     0,     0,   129,   130,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   120,
     121,     0,     0,   124,     0,    10,    11,     0,     0,     0,
      12,     0,    13,     0,     0,     0,     0,    14,     0,    15,
      16,   126,     0,     0,     0,    17,     0,     0,     0,   127,
     128,     0,    18,     0,   129,   130,    20,    21,    22,   117,
      23,     0,   137,   138,   139,   140,     0,    24,     0,     0,
     119,     0,     0,    25,    26,    27,    28,    29,    30,     0,
     120,   121,   122,   123,   124,   125,     0,    32,    33,    34,
      35,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,   126,   273,     0,     0,   117,     0,     0,     0,
     127,   128,     0,     0,     0,   129,   130,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   120,   121,     0,
       0,   124,     0,    10,    11,     0,     0,     0,    12,     0,
      13,     0,     0,     0,    65,    14,     0,    15,    16,   126,
       0,     0,     0,    17,     0,     0,     0,   127,   128,     0,
      18,     0,   129,    19,    20,    21,    22,     0,    23,     0,
       0,     0,     0,    21,    22,    24,    23,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,    31,     0,    25,
      26,    27,    28,     0,    30,    32,    33,    34,    35,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    10,    11,    59,     0,     0,    12,     0,    13,     0,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,    10,    11,     0,    65,     0,    12,     0,    13,
       0,     0,    20,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,     0,     0,     0,
       0,    26,    27,    28,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,   200,    10,    11,   268,     0,
       0,    12,     0,    13,     0,   253,   254,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,    10,    11,     0,
       0,     0,    12,   281,    13,     0,     0,    20,     0,    14,
       0,    15,    16,     0,     0,    10,   255,    17,   256,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    20,     0,
       0,   117,     0,     0,     0,     0,     0,     0,    32,    33,
      34,    35,   119,     0,     0,     0,    26,    27,    28,     0,
       0,     0,   120,   121,   122,   123,   124,   125,     0,    32,
      33,    34,    35,     0,     0,     0,     0,     0,   117,     0,
       0,     0,    65,     0,   126,     0,     0,     0,     0,   119,
       0,     0,   127,   128,     0,     0,     0,   129,   130,   120,
     121,   122,   123,   124,   125,     0,     0,     0,   131,     0,
       0,     0,     0,     0,     0,   117,     0,     0,     0,     0,
     388,   126,     0,     0,     0,     0,   119,     0,     0,   127,
     128,     0,     0,     0,   129,   130,   120,   121,   122,   123,
     124,   125,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,   126,   392,
       0,     0,     0,   119,     0,     0,   127,   128,     0,     0,
       0,   129,   130,   120,   121,   122,   123,   124,   125,     0,
       0,     0,   131,     0,     0,     0,     0,     0,     0,   117,
       0,     0,   443,     0,     0,   126,     0,     0,     0,     0,
     119,     0,     0,   127,   128,     0,     0,     0,   129,   130,
     120,   121,   122,   123,   124,   125,     0,     0,     0,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,     0,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131
  };

  const short
  parser::yycheck_[] =
  {
       0,     0,    12,   132,     6,    38,    80,   171,   258,   205,
       6,     5,    12,    13,    20,    15,    16,    17,   203,     0,
      65,    21,   203,    23,    68,    35,    21,     9,     7,    21,
      48,     0,    65,   162,   163,    50,     6,   166,    38,    38,
       0,    59,    21,   112,    17,   114,    52,    53,    10,    11,
      75,    47,    14,     6,    46,    50,    18,    20,    58,     6,
      66,   105,   106,     9,   108,    65,    65,    46,   292,    38,
      52,   261,    82,    98,    20,    11,    86,    58,    15,   208,
      72,    20,    78,    22,    48,    24,   282,   283,   284,    52,
      29,    30,    31,    72,    47,    68,    65,   142,    35,    53,
      47,   111,   104,    66,   294,    52,    52,   292,    47,   142,
      47,   292,    74,    47,    60,    61,    70,    79,   118,    48,
     120,   121,   122,   123,   124,   349,   126,   127,   128,   129,
     130,    78,   105,   106,   134,   108,   136,    21,   388,   139,
     140,    80,   142,   142,   106,     6,     7,   109,   119,   149,
     112,   113,   114,   115,   116,    21,   156,   157,    20,   159,
     131,   161,    46,    20,   349,    22,   356,    46,   349,   298,
     132,    52,   172,   142,   136,   399,     9,    53,    15,   115,
     119,   152,   378,    46,    50,    17,    47,    20,   157,    15,
      52,   153,   131,   132,   156,   264,   325,   361,   267,   170,
     162,   163,   164,    47,   166,   171,    50,   240,   398,    46,
     400,    81,   183,   152,   399,    58,    48,   153,   399,    52,
     182,   417,    51,   162,   163,   119,    49,   166,   238,   239,
     240,   170,   171,   379,   424,   381,   236,   131,   204,   205,
     314,   240,    48,   214,   183,   119,   182,    70,    20,    20,
     379,   380,   381,    20,    21,    22,   256,   131,   152,    46,
     231,     6,     7,    35,    35,   204,   205,    49,    83,   415,
      15,   271,    17,    18,   274,   214,   170,    53,   152,    49,
      52,    52,    55,    50,     0,    21,   415,   249,    70,   183,
     290,   420,   231,   209,    66,    66,   170,    70,    21,   270,
      70,   272,   264,   303,    15,   267,    17,   278,   308,   183,
      15,    47,    48,    48,   253,    20,   282,   283,   284,    48,
     214,    48,    20,    21,    47,    48,   292,    72,   131,    70,
      59,   270,    59,   272,    50,    51,   298,   231,   254,   278,
     214,   257,    58,   282,   283,   284,   308,    52,   348,   152,
      47,    48,    50,    48,    52,    49,   318,   231,   368,   298,
     360,    66,    59,   325,    59,    47,    48,   170,    66,   369,
      15,     7,    17,   373,     9,   314,   270,    48,   272,    15,
     183,    17,    49,   349,   278,    20,    48,   353,   359,    15,
       6,     7,   404,   202,   406,   361,   270,    49,   272,    34,
      70,   210,    18,   374,   278,    46,   215,   216,   408,    17,
     326,   214,   378,    21,   376,   331,    49,    52,    49,    35,
     359,    70,   361,    47,    48,    60,    61,    35,   231,   395,
      46,    47,     6,     7,   434,   374,   162,   163,    46,   378,
     166,    51,    49,    17,    18,    96,    97,    98,    70,    49,
     412,   417,    68,     6,     7,     8,    49,    17,   420,    35,
      21,    35,    49,   103,    70,   359,   382,   270,    49,   272,
     279,   280,   388,    47,    48,   278,    50,    21,   417,    49,
     374,    46,   291,     7,   293,   359,   295,     9,    35,   105,
     106,    48,   108,    48,    47,    48,    35,    49,    20,    52,
     374,    38,   157,   142,    46,   318,   422,    13,    30,    31,
      32,    33,    34,    35,    29,   308,   412,   376,   298,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,   105,   106,    -1,   108,    -1,    58,    -1,    60,    61,
       6,     7,     8,    65,    66,   354,   355,   356,    -1,    -1,
      -1,    -1,     0,    -1,    76,    -1,   359,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    35,
      -1,   374,    -1,     9,    -1,    -1,     6,     7,     8,    -1,
      -1,    47,    48,    -1,    20,    -1,    52,   396,   397,   398,
      -1,   400,    -1,    -1,    30,    31,     6,     7,    34,    47,
      48,    -1,    -1,    -1,    52,    35,    54,    17,    18,    -1,
      58,    59,    -1,    61,    62,   424,    52,    47,    48,    67,
      -1,    -1,    52,    -1,    60,    61,    74,    -1,    -1,    77,
      78,    79,    80,     9,    82,    -1,    -1,    47,    48,    15,
      50,    89,    -1,    -1,    20,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,    30,    31,    32,    33,    34,    35,
      -1,   109,   110,   111,   112,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    52,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,
      66,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    30,    31,    32,    -1,    34,    -1,    47,    48,    -1,
      -1,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,    59,
      -1,    61,    62,    52,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    60,    61,    -1,    74,    -1,    65,    66,    78,    79,
      80,     9,    82,    -1,    84,    85,    86,    87,    -1,    89,
      -1,    -1,    20,    -1,    -1,    95,    96,    97,    98,    99,
     100,    -1,    30,    31,    32,    33,    34,    35,    -1,   109,
     110,   111,   112,     5,     6,     7,     8,     9,    10,    11,
      12,    49,    14,    -1,    52,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    65,    66,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    30,
      31,    -1,    -1,    34,    -1,    47,    48,    -1,    -1,    -1,
      52,    -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    52,    -1,    -1,    -1,    67,    -1,    -1,    -1,    60,
      61,    -1,    74,    -1,    65,    66,    78,    79,    80,     9,
      82,    -1,    84,    85,    86,    87,    -1,    89,    -1,    -1,
      20,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      30,    31,    32,    33,    34,    35,    -1,   109,   110,   111,
     112,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    52,    53,    -1,    -1,     9,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    65,    66,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    30,    31,    -1,
      -1,    34,    -1,    47,    48,    -1,    -1,    -1,    52,    -1,
      54,    -1,    -1,    -1,    50,    59,    -1,    61,    62,    52,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    60,    61,    -1,
      74,    -1,    65,    77,    78,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    79,    80,    89,    82,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,    -1,    95,
      96,    97,    98,    -1,   100,   109,   110,   111,   112,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    52,    -1,    54,    -1,
      -1,    -1,    -1,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    47,    48,    -1,    50,    -1,    52,    -1,    54,
      -1,    -1,    78,    -1,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    96,    97,    98,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    47,    48,    49,    -1,
      -1,    52,    -1,    54,    -1,    17,    18,    -1,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    47,    48,    -1,
      -1,    -1,    52,    35,    54,    -1,    -1,    78,    -1,    59,
      -1,    61,    62,    -1,    -1,    47,    48,    67,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    78,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,    20,    -1,    -1,    -1,    96,    97,    98,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    60,    61,    -1,    -1,    -1,    65,    66,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    20,    -1,    -1,    60,
      61,    -1,    -1,    -1,    65,    66,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    20,    -1,    -1,    60,    61,    -1,    -1,
      -1,    65,    66,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,    66,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      47,    48,    52,    54,    59,    61,    62,    67,    74,    77,
      78,    79,    80,    82,    89,    95,    96,    97,    98,    99,
     100,   101,   109,   110,   111,   112,   114,   115,   116,   117,
     125,   128,   129,   131,   133,   134,   135,   136,   176,   177,
     178,   179,   180,   181,   182,   183,   186,   131,    46,    49,
     131,   136,   181,   185,   186,    50,   124,   147,   181,   147,
     131,   181,   181,   181,   104,   118,   119,   120,   131,    75,
      98,   133,   181,     7,   133,   175,   181,   133,   146,     5,
      78,   133,   137,   138,   133,   141,   133,   145,   124,     0,
       0,    58,     0,    58,   117,   125,    47,    98,   134,    52,
     138,   140,    48,    59,    48,    48,    59,     9,    15,    20,
      30,    31,    32,    33,    34,    35,    52,    60,    61,    65,
      66,    76,    48,   181,    46,    49,    70,    84,    85,    86,
      87,   121,   122,   125,   127,   129,   130,    53,    53,    70,
      55,   131,    46,    15,   131,   140,    48,    58,   124,    81,
     124,    21,    48,    48,    50,    21,    48,   131,   184,   185,
      20,    22,    21,   124,   184,   131,   184,   185,   131,   181,
       7,     8,    48,    52,   133,   176,   178,   180,   187,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   187,
       7,    18,    35,    46,    68,   105,   106,   108,   131,   132,
     133,   156,   157,   160,   161,   162,   169,    49,   181,   131,
     181,   181,   181,    58,    58,   125,   130,    51,   181,   187,
     185,    46,   131,   148,   149,   150,   151,   181,   128,   181,
      83,   126,   181,   156,   156,   131,   142,   143,   144,    48,
     156,    53,   187,    17,    18,    48,    50,   132,   133,   171,
     172,   174,   181,    49,    48,    49,    49,    48,    49,   187,
      20,    52,    66,    53,    15,   159,   159,   161,   163,   164,
     169,    35,   105,   106,   108,   170,   171,   170,   132,   158,
      21,    35,    46,   173,   174,    35,   159,    49,    70,    35,
     187,   159,   159,    46,   187,    15,    46,    49,    70,   181,
     124,   124,   124,   125,   136,    49,    49,    51,    70,   131,
     152,   153,   155,    49,   133,    48,   165,   173,    49,   181,
     173,   165,   172,   184,   184,    53,   187,   181,   187,   181,
      35,   187,   159,   159,   170,   170,   170,    35,    21,    46,
      72,   181,   159,   161,   164,   169,   174,   159,   159,    20,
      21,    22,   123,   124,   160,    35,   181,   150,   140,    21,
     103,   139,   144,    21,    46,    49,    70,    21,    15,    18,
      72,   131,   132,   166,   167,   168,   173,   173,    51,   173,
      49,    49,    53,    35,   181,   161,   164,   169,   174,    46,
     174,   159,   159,   159,   187,   181,   171,   181,    48,   181,
     187,   155,    48,   170,   167,   132,   167,    15,   173,    49,
      70,    35,   165,   173,   174,   159,   159,   159,   164,   169,
     159,   123,   123,   181,    15,   154,   152,   167,   170,    35,
     168,   173,   159,    49,   181,    49
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
     160,   160,   160,   161,   161,   162,   162,   162,   162,   163,
     163,   164,   164,   164,   164,   165,   166,   166,   167,   167,
     167,   167,   167,   167,   168,   168,   168,   168,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   177,   177,   177,
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
       2,     5,     4,     3,     2,     2,     3,     5,     5,     6,
       5,     4,     3,     4,     4,     5,     3,     2,     3,     2,
       3,     2,     5,     1,     1,     2,     3,     1,     2,     0,
       1,     2,     3,     1,     2,     3,     1,     3,     1,     2,
       2,     3,     2,     3,     2,     3,     1,     2,     2,     3,
       3,     3,     2,     2,     1,     1,     2,     1,     1,     3,
       2,     2,     3,     2,     4,     5,     1,     2,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     3,
       3,     3,     4,     2,     2,     2,     2,     2,     2,     3,
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
  "\"`>>`\"", "\"`<=`\"", "\"`>=`\"", "\"`==`\"", "\"`!=`\"", "\"`&&`\"",
  "\"`||`\"", "\"`..`\"", "\"`...`\"", "\"`+=`\"", "\"`-=`\"", "\"`*=`\"",
  "\"`/=`\"", "\"`%=`\"", "\"`<<=`\"", "\"`>>=`\"", "\"`&=`\"", "\"`|=`\"",
  "\"`^=`\"", "\"`:`\"", "\"`::`\"", "\"`(`\"", "\"`)`\"", "\"`{`\"",
  "\"`}`\"", "\"`[`\"", "\"`]`\"", "\"`[[`\"", "\"`]]`\"", "\"`<`\"",
  "\"`>`\"", "\"`;`\"", "\"`.`\"", "\"`+`\"", "\"`-`\"", "\"`*`\"",
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
     375,   380,   382,   384,   386,   391,   392,   397,   399,   404,
     405,   410,   412,   414,   419,   421,   422,   424,   430,   433,
     444,   449,   451,   453,   455,   457,   459,   461,   471,   476,
     478,   483,   484,   488,   490,   498,   500,   502,   509,   511,
     515,   516,   518,   520,   522,   524,   529,   537,   552,   554,
     556,   562,   563,   567,   568,   572,   574,   579,   581,   586,
     604,   606,   618,   619,   621,   628,   633,   634,   638,   640,
     645,   651,   653,   676,   682,   699,   701,   707,   708,   712,
     714,   719,   721,   726,   728,   734,   735,   739,   741,   746,
     747,   751,   753,   760,   761,   765,   767,   772,   773,   777,
     778,   783,   787,   789,   793,   796,   801,   809,   811,   813,
     815,   818,   820,   823,   825,   827,   829,   831,   839,   841,
     843,   845,   850,   857,   858,   862,   864,   868,   870,   875,
     880,   884,   886,   890,   892,   902,   907,   909,   915,   917,
     920,   922,   926,   929,   935,   938,   951,   954,   959,   960,
     961,   962,   963,   964,   965,   969,   970,   971,   975,   977,
     979,   981,   983,   985,   987,   989,   991,   996,  1001,  1003,
    1007,  1009,  1015,  1017,  1022,  1024,  1026,  1031,  1033,  1035,
    1037,  1039,  1041,  1043,  1045,  1047,  1049,  1050,  1052,  1058,
    1066,  1068,  1070,  1072,  1074,  1081,  1088,  1090,  1092,  1097,
    1099,  1103,  1105,  1107,  1110,  1114,  1117,  1120,  1122,  1134,
    1154,  1167,  1171,  1178,  1180,  1182,  1187,  1189,  1191,  1196,
    1201,  1202,  1203,  1204,  1205,  1210,  1212,  1217,  1224,  1232,
    1243,  1245,  1250,  1252,  1258,  1263,  1271,  1273,  1313,  1315,
    1317,  1319,  1320,  1322,  1324,  1325,  1327,  1329
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
#line 5767 "annium.tab.cpp"

#line 1524 "annium.y"

