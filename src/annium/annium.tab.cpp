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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.copy< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.copy< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.YY_MOVE_OR_COPY< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.copy< identifier > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.copy< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        value.move< identifier > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        value.move< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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
#line 337 "annium.y"
                 { }
#line 1891 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 337 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 337 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 337 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 337 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 337 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 337 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 337 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 337 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 337 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 337 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 337 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 337 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 337 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 337 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 337 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 337 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 337 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 337 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 337 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 337 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 337 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 337 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 337 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 337 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 337 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 337 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 337 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 337 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 337 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 337 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 337 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 337 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 337 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 337 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 337 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 337 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 337 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 337 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 337 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 337 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 337 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 337 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 337 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 337 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 337 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 337 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 337 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 337 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 337 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 337 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
#line 337 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 337 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_let_decl: // let-decl
#line 337 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl_start: // let-decl-start
#line 337 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 337 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
#line 337 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
#line 337 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_function_body: // function-body
#line 337 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_braced_statements: // braced-statements
#line 337 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
#line 337 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_if_else_tail: // if-else-tail
#line 337 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
#line 337 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_expression_statement: // expression-statement
#line 337 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_generic_statement: // generic-statement
#line 337 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_infunction_statement: // infunction-statement
#line 337 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 337 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
#line 337 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 337 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
#line 337 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
#line 337 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
#line 337 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_name: // fn-name
#line 337 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
#line 337 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
#line 337 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_decl: // fn-decl
#line 337 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
#line 337 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
#line 337 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_case_list: // case-list
#line 337 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_decl: // case-decl
#line 337 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
#line 337 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_using_decl: // using-decl
#line 337 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_expression_list: // expression-list
#line 337 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
#line 337 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_argument_list: // argument-list
#line 337 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 337 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_name: // argument-name
#line 337 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
#line 337 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_field_list: // field-list
#line 337 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
#line 337 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 337 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
#line 337 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_parameter_list: // parameter-list
#line 337 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
#line 337 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
#line 337 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
#line 337 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 337 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
#line 337 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
#line 337 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression: // constraint-expression
#line 337 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 337 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_pattern_list: // pattern-list
#line 337 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
#line 337 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_field: // pattern-field
#line 337 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
#line 337 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
#line 337 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 337 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
#line 337 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
#line 337 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
#line 337 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
#line 337 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
#line 337 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
#line 337 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_grouped_expression: // grouped-expression
#line 337 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_new_expression: // new-expression
#line 337 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_call_expression: // call-expression
#line 337 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_syntax_expression: // syntax-expression
#line 337 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
#line 337 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_lambda_expression: // lambda-expression
#line 337 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
#line 337 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_pack_expression: // pack-expression
#line 337 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_compound_expression: // compound-expression
#line 337 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_type_expr: // type-expr
#line 337 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
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

      case symbol_kind::S_135_fn_name: // fn-name
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
      case symbol_kind::S_149_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_130_internal_identifier: // internal-identifier
      case symbol_kind::S_156_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_139_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_152_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_132_fn_kind: // fn-kind
      case symbol_kind::S_133_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_136_fn_start_decl: // fn-start-decl
      case symbol_kind::S_138_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_142_case_decl: // case-decl
        yylhs.value.emplace< identifier > ();
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_146_argument_list_opt: // argument-list-opt
      case symbol_kind::S_147_argument_list: // argument-list
      case symbol_kind::S_182_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_183_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_158_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_157_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_154_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_155_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_173_reference_expression: // reference-expression
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
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        yylhs.value.emplace< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_126_expression_statement: // expression-statement
      case symbol_kind::S_127_generic_statement: // generic-statement
      case symbol_kind::S_128_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_if_else_tail: // if-else-tail
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_134_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_180_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_159_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_161_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_160_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_162_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_167_pattern_mod: // pattern-mod
      case symbol_kind::S_168_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_150_field_list_opt: // field-list-opt
      case symbol_kind::S_151_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_140_case_list_opt: // case-list-opt
      case symbol_kind::S_141_case_list: // case-list
        yylhs.value.emplace< std::vector<identifier> > ();
        break;

      case symbol_kind::S_143_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_170_concept_expression: // concept-expression
      case symbol_kind::S_174_any_reference_expression: // any-reference-expression
      case symbol_kind::S_175_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_176_grouped_expression: // grouped-expression
      case symbol_kind::S_177_new_expression: // new-expression
      case symbol_kind::S_178_call_expression: // call-expression
      case symbol_kind::S_179_syntax_expression: // syntax-expression
      case symbol_kind::S_181_lambda_expression: // lambda-expression
      case symbol_kind::S_184_compound_expression: // compound-expression
      case symbol_kind::S_185_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_137_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_145_expression_list: // expression-list
      case symbol_kind::S_171_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_172_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_165_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_166_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_164_pattern_list: // pattern-list
        yylhs.value.emplace< syntax_pattern_field_list_t > ();
        break;

      case symbol_kind::S_144_using_decl: // using-decl
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
#line 342 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3121 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 343 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3127 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 348 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3133 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 350 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3139 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 352 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3145 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 369 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3151 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 370 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3157 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 372 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3163 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 374 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3169 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 379 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3175 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 381 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3188 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 390 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3194 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 392 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3200 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 396 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3206 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 398 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3212 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 403 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3218 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 405 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3224 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 409 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3230 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 411 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3236 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 416 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3242 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 418 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3248 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 420 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3254 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 425 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3260 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 426 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3266 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 428 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3272 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 430 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3278 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 435 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3284 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 439 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3290 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 450 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3296 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 455 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3302 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 457 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3308 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 459 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3314 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 461 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3320 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 463 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3326 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 465 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3332 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 467 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3342 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 477 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3348 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 482 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3354 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 484 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3360 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 488 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3366 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 489 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3372 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 494 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3378 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 496 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3387 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 504 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3393 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 506 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3399 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 508 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3410 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 515 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3416 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 516 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3422 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 520 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3428 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 522 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3434 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 524 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3440 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 526 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3446 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 528 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3452 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 530 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3458 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 535 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3464 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 543 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3470 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 558 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3476 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 560 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3482 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 562 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3488 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 567 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3494 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 568 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3500 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 572 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3506 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 573 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3512 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 578 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3518 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 580 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3524 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 585 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3530 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 587 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3536 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 592 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3542 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 609 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3548 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 612 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3554 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 623 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3560 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 625 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3566 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 627 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3572 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 634 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3578 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 638 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3584 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 639 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3590 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 644 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3596 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 646 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3602 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 651 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3608 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 657 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3614 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 659 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3620 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 682 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3630 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 688 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3641 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 705 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3647 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 707 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3653 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 712 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3659 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 713 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3665 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 718 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3671 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 720 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3677 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 725 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3683 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 727 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3689 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 732 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3695 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 734 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3701 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 739 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3707 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 740 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3713 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 745 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3719 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 747 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3725 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 751 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3731 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 752 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3737 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 757 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3743 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 759 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3749 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 765 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3755 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 766 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3761 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 771 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3767 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 773 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3773 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 777 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3779 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 778 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3785 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 782 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3791 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 783 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3797 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 789 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3803 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 793 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3809 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 795 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3815 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 799 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3821 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 802 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3827 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: qname parameter-default-value-opt
#line 805 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3836 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: qname "`...`" parameter-default-value-opt
#line 810 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3846 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 818 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3852 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 820 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3858 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 822 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3864 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 824 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3870 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`=>`" syntax-expression
#line 827 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annotated_identifier > ()), std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3876 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: internal-identifier "`=>`" syntax-expression
#line 829 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3882 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 832 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3888 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" concept-expression-list parameter-default-value-opt
#line 834 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };   }
#line 3894 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 836 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3900 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 838 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3906 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: pattern-mod parameter-default-value-opt
#line 840 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3912 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 848 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3918 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: "`_`" concept-expression-list-opt parameter-default-value-opt
#line 850 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3924 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: concept-expression-list parameter-default-value-opt
#line 852 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3930 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 854 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3936 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`...`" parameter-default-value-opt
#line 856 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3942 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 861 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3948 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified-mod: "constexpr modifier"
#line 867 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 3954 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified-mod: "runctime modifier"
#line 868 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3960 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 873 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3966 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 875 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3972 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod
#line 879 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3978 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 881 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3984 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-mod: %empty
#line 886 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3993 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-mod: constraint-expression-specified-mod
#line 890 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 3999 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod type-expr
#line 895 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4005 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 897 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4011 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod
#line 901 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4017 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod "`...`"
#line 903 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4023 "annium.tab.cpp"
    break;

  case 147: // subpatterns: "`(`" pattern-list "`)`"
#line 913 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4029 "annium.tab.cpp"
    break;

  case 148: // pattern-list: pattern-field
#line 918 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4035 "annium.tab.cpp"
    break;

  case 149: // pattern-list: pattern-list "," pattern-field
#line 920 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4041 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: concept-expression-list-opt
#line 926 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4047 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 928 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4053 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 931 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4059 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 933 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4065 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: "`=`" pattern-sfx
#line 937 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4071 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 940 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4077 "annium.tab.cpp"
    break;

  case 156: // pattern-field: identifier pattern-field-sfx
#line 946 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4083 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 949 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4089 "annium.tab.cpp"
    break;

  case 158: // pattern-field: pattern-field-sfx
#line 962 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4095 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`_`" pattern-field-sfx
#line 965 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4101 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" pattern-sfx
#line 969 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 4107 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 970 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4113 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 971 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4119 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 972 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4125 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "typename modifier"
#line 973 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4131 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "`~`" "consteval modifier" syntax-expression
#line 974 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4137 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "typename modifier" pattern-sfx
#line 975 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4143 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "typename modifier"
#line 976 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4149 "annium.tab.cpp"
    break;

  case 168: // pattern-sfx: pattern
#line 980 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4155 "annium.tab.cpp"
    break;

  case 169: // pattern-sfx: pattern "`...`"
#line 981 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4161 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: "`...`"
#line 982 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4167 "annium.tab.cpp"
    break;

  case 171: // pattern: qname
#line 987 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4173 "annium.tab.cpp"
    break;

  case 172: // pattern: qname subpatterns concept-expression-list-opt
#line 989 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4179 "annium.tab.cpp"
    break;

  case 173: // pattern: internal-identifier concept-expression-list-opt
#line 991 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4185 "annium.tab.cpp"
    break;

  case 174: // pattern: "`_`" concept-expression-list-opt
#line 993 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4191 "annium.tab.cpp"
    break;

  case 175: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 995 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4197 "annium.tab.cpp"
    break;

  case 176: // pattern: "`(`" "`)`"
#line 997 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4203 "annium.tab.cpp"
    break;

  case 177: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 999 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4209 "annium.tab.cpp"
    break;

  case 178: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1001 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4215 "annium.tab.cpp"
    break;

  case 179: // pattern: concept-expression-list
#line 1003 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4221 "annium.tab.cpp"
    break;

  case 180: // concept-expression: "`@`" qname
#line 1008 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4227 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list-opt: %empty
#line 1013 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4233 "annium.tab.cpp"
    break;

  case 182: // concept-expression-list-opt: concept-expression-list
#line 1014 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4239 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list: concept-expression
#line 1019 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4245 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list: concept-expression-list concept-expression
#line 1021 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4251 "annium.tab.cpp"
    break;

  case 185: // reference-expression: CONTEXT_IDENTIFIER
#line 1027 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4257 "annium.tab.cpp"
    break;

  case 186: // reference-expression: qname
#line 1029 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4263 "annium.tab.cpp"
    break;

  case 187: // any-reference-expression: RESERVED_IDENTIFIER
#line 1034 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4269 "annium.tab.cpp"
    break;

  case 188: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4275 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: qname
#line 1038 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4281 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "nil"
#line 1043 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4287 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: "true"
#line 1045 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4293 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "false"
#line 1047 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4299 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: INTEGER
#line 1049 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4305 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: DECIMAL
#line 1051 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4311 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: DECIMAL_S
#line 1053 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4317 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: INTEGER_INDEX
#line 1055 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4323 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: STRING
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4329 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: CT_IDENTIFIER
#line 1059 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4335 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: any-reference-expression
#line 1060 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4341 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`(`" "`)`"
#line 1062 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4347 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1064 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4356 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1070 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4368 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1081 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4374 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1083 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4380 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1085 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4386 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: PROBE braced-statements
#line 1087 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4392 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`.`" identifier
#line 1089 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4398 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1096 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4408 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`-`" syntax-expression
#line 1103 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4414 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1105 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4420 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`!`" syntax-expression
#line 1107 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4426 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "`*`" syntax-expression
#line 1109 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4432 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1112 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4438 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1114 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4444 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1118 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4450 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1120 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4456 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1124 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4462 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1126 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4468 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1128 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4474 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1130 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4480 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1132 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4486 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1134 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4492 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1136 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4498 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1139 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4504 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1143 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4510 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1146 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4516 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1149 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4522 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1151 "annium.y"
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
#line 4537 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1163 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4543 "annium.tab.cpp"
    break;

  case 230: // grouped-expression: "`(`" pack-expression "`)`"
#line 1183 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4556 "annium.tab.cpp"
    break;

  case 231: // new-expression: "`new`" qname
#line 1196 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4562 "annium.tab.cpp"
    break;

  case 232: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1200 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4568 "annium.tab.cpp"
    break;

  case 233: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1207 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4574 "annium.tab.cpp"
    break;

  case 234: // call-expression: any-reference-expression "`.`" identifier
#line 1209 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4580 "annium.tab.cpp"
    break;

  case 235: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1211 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4589 "annium.tab.cpp"
    break;

  case 236: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1216 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4595 "annium.tab.cpp"
    break;

  case 237: // call-expression: call-expression "`.`" identifier
#line 1218 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4601 "annium.tab.cpp"
    break;

  case 238: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1220 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4610 "annium.tab.cpp"
    break;

  case 239: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1225 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4616 "annium.tab.cpp"
    break;

  case 240: // syntax-expression: syntax-expression-base
#line 1229 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4622 "annium.tab.cpp"
    break;

  case 241: // syntax-expression: new-expression
#line 1230 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4628 "annium.tab.cpp"
    break;

  case 242: // syntax-expression: compound-expression
#line 1231 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4634 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: lambda-expression
#line 1232 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4640 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: grouped-expression
#line 1233 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4646 "annium.tab.cpp"
    break;

  case 245: // lambda-start-decl: fn-prefix-decl
#line 1239 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4652 "annium.tab.cpp"
    break;

  case 246: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1241 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4658 "annium.tab.cpp"
    break;

  case 247: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1246 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4669 "annium.tab.cpp"
    break;

  case 248: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1253 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4681 "annium.tab.cpp"
    break;

  case 249: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1261 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4693 "annium.tab.cpp"
    break;

  case 250: // pack-expression-opt: %empty
#line 1272 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4699 "annium.tab.cpp"
    break;

  case 251: // pack-expression-opt: pack-expression
#line 1274 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4705 "annium.tab.cpp"
    break;

  case 252: // pack-expression: syntax-expression
#line 1279 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4711 "annium.tab.cpp"
    break;

  case 253: // pack-expression: identifier "`:`" syntax-expression
#line 1281 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4721 "annium.tab.cpp"
    break;

  case 254: // pack-expression: pack-expression "," syntax-expression
#line 1287 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4730 "annium.tab.cpp"
    break;

  case 255: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1292 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4739 "annium.tab.cpp"
    break;

  case 256: // compound-expression: syntax-expression "`...`"
#line 1300 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4745 "annium.tab.cpp"
    break;

  case 257: // compound-expression: call-expression
#line 1301 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4751 "annium.tab.cpp"
    break;

  case 258: // type-expr: qname
#line 1342 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4757 "annium.tab.cpp"
    break;

  case 259: // type-expr: RESERVED_IDENTIFIER
#line 1344 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4763 "annium.tab.cpp"
    break;

  case 260: // type-expr: CONTEXT_IDENTIFIER
#line 1346 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4769 "annium.tab.cpp"
    break;

  case 261: // type-expr: call-expression
#line 1347 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4775 "annium.tab.cpp"
    break;

  case 262: // type-expr: "`[`" type-expr "`]`"
#line 1349 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4781 "annium.tab.cpp"
    break;

  case 263: // type-expr: "`(`" "`)`"
#line 1351 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4787 "annium.tab.cpp"
    break;

  case 264: // type-expr: grouped-expression
#line 1352 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4793 "annium.tab.cpp"
    break;

  case 265: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1354 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4799 "annium.tab.cpp"
    break;

  case 266: // type-expr: type-expr "`|`" type-expr
#line 1356 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4805 "annium.tab.cpp"
    break;

  case 267: // type-expr: type-expr "`->`" type-expr
#line 1358 "annium.y"
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
#line 4820 "annium.tab.cpp"
    break;


#line 4824 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -304;

  const short parser::yytable_ninf_ = -190;

  const short
  parser::yypact_[] =
  {
     860,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
      35,   966,   987,    35,  1192,  1192,  1192,     5,    -4,    30,
    1192,    36,  1192,    30,    48,  -304,  -304,  -304,    29,    30,
      30,  1192,  -304,  -304,  -304,    56,    71,    17,   536,  -304,
    -304,  -304,  -304,  -304,    70,  -304,   307,    26,   113,  -304,
      32,  -304,   128,  1202,    89,  -304,    10,  -304,  1192,  -304,
      95,   114,  1557,   107,  -304,   754,   118,    49,  1557,  -304,
      37,    37,    37,    35,  -304,   134,   173,  -304,    35,    29,
     169,   870,  -304,    70,   131,  1275,   179,  -304,  -304,  -304,
      70,   142,  -304,   308,  -304,   306,  -304,    37,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,    35,  -304,  -304,  1192,
     137,    31,  1192,    35,  1192,  1192,    35,  -304,  1192,   505,
    1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  -304,
    1192,  1192,  1192,  1192,  1192,  1192,  1192,   505,   674,  1322,
    1192,  -304,  1192,  -304,  -304,  1192,  1192,   167,   648,  -304,
     193,  -304,  -304,  -304,  -304,  1079,  -304,   505,  1192,   208,
    -304,  1192,  1192,  -304,  1192,   217,  1192,   674,   674,    35,
     239,   674,  -304,   258,   260,   505,   660,  1192,  -304,   282,
     273,   283,   147,   288,  1557,   211,   272,  1100,   505,   267,
     113,    32,   128,    39,   425,   425,   425,   425,   425,   425,
    1594,   764,   227,  1369,   129,   129,    41,    41,  1667,  1631,
     117,  -304,    30,   322,   350,   346,   633,   836,  -304,  -304,
      33,   360,   220,   310,   301,  -304,   483,   350,   350,  -304,
      81,  -304,  1557,   324,  1557,  1557,  1557,  -304,  -304,  -304,
    -304,  -304,  -304,  1557,   117,   260,   505,    12,   331,   326,
    -304,  1192,  1557,    56,  1275,   623,  -304,  1557,   347,   359,
    -304,   358,   348,  -304,    35,   377,  -304,   117,    27,   379,
    1192,   322,   182,  -304,   322,  1557,  -304,  1192,  -304,  -304,
    1192,  -304,   240,   505,  1192,   505,  -304,    70,   350,   322,
    1192,  -304,  -304,   515,   350,   350,  -304,   836,   836,  1192,
     836,  -304,   386,  -304,  -304,    -3,  1192,   350,     6,   350,
     350,  -304,   255,   674,  -304,    81,   271,  -304,  -304,  -304,
    -304,  1192,   117,  -304,  -304,  -304,  1192,  1557,  -304,  -304,
    -304,  -304,    29,   411,   334,  -304,    35,     8,   387,   374,
    -304,   419,   378,   322,  -304,  -304,  1416,  -304,   322,   393,
     395,  -304,    39,  1463,    39,  -304,  1557,  -304,   299,  -304,
    -304,  -304,  -304,  1557,  -304,  -304,  1192,     6,   399,  1557,
    -304,   322,   350,   350,    81,  -304,  -304,   505,  1192,   660,
    -304,  -304,  -304,  -304,  -304,  1557,  -304,    56,  1192,   401,
    -304,  -304,  1192,   505,  -304,    35,   404,   836,   372,   448,
     372,   235,   186,  -304,  -304,   421,  -304,    27,  -304,  -304,
    -304,  -304,  -304,  1557,   322,   350,   350,    81,   346,    81,
    -304,  -304,  -304,   228,  1557,    47,  1557,  1192,  1557,   219,
    -304,    35,  -304,  -304,   372,  -304,   836,   426,  -304,   378,
    -304,   322,  -304,    81,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  1510,  1192,  -304,   405,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  1557,  -304
  };

  const short
  parser::yydefact_[] =
  {
       4,   197,    56,   188,   187,   196,   193,   194,   195,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    65,     0,     0,
       0,     0,   190,   191,   192,     0,     0,     0,     0,     5,
       7,    49,    13,    59,   189,    63,     0,   245,   199,   240,
     244,   241,   257,     0,     0,   243,   242,    58,     0,   200,
      59,   245,   252,     0,   242,    21,     0,     0,    85,   207,
     209,   212,   211,     0,    45,    19,    15,    17,     0,     0,
     231,     0,   185,   186,     0,     0,     0,    48,    31,    68,
      67,     0,    46,     0,    38,     0,    14,   210,   206,     1,
       2,    10,     3,     8,     6,     9,     0,    66,    64,   250,
      72,     0,   250,     0,   250,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,   230,     0,    52,    51,    53,     0,    41,    42,    24,
       0,    50,    22,   204,   202,     0,    18,     0,     0,     0,
      12,    87,     0,    32,     0,    35,     0,   103,   103,    76,
       0,   103,    60,     0,   251,     0,     0,     0,    37,     0,
     234,     0,     0,   237,    44,   260,   259,     0,     0,   258,
       0,   264,   261,   228,   217,   218,   219,   220,   221,   222,
     226,   227,   223,     0,   215,   216,   213,   214,   224,   225,
     229,    57,     0,   181,   109,   141,     0,   167,   135,   136,
      59,   181,   109,     0,   104,   105,   139,   109,   109,   183,
     109,   201,   253,    59,   254,    54,    55,    27,    25,    26,
      23,    30,   203,    86,    20,    16,     0,    59,     0,    88,
      89,     0,    92,     0,     0,     0,    36,    83,     0,     0,
      80,     0,    77,    78,    95,     0,   246,    73,   181,     0,
       0,   181,   171,    74,   179,    47,   233,   250,   239,   236,
     250,   263,     0,     0,     0,     0,   205,   180,   109,   182,
       0,   133,   142,   145,   109,   109,   170,   164,     0,     0,
       0,   160,   168,   166,   108,     0,     0,   109,   141,   109,
     109,   116,     0,     0,   140,   109,   137,   114,   128,   131,
     184,     0,    11,    93,    94,   232,     0,    91,    33,    34,
      39,    40,     0,     0,    70,    75,     0,     0,     0,    96,
      97,     0,   181,   181,   174,   176,     0,   173,   181,     0,
       0,   262,   267,     0,   266,   130,   110,   146,   143,   113,
     127,   163,   161,   165,   162,   169,     0,   141,     0,   123,
     132,   142,   109,   109,   109,   129,   117,     0,     0,     0,
     247,    28,   106,   115,   138,   255,    90,     0,     0,     0,
      69,    79,     0,     0,    81,     0,     0,     0,   181,     0,
     181,   181,     0,   158,   148,   150,   175,   181,   172,   235,
     238,   265,   144,   122,   142,   109,   109,   109,   141,   109,
     112,   124,   125,     0,    29,     0,    84,     0,   102,    99,
      98,    95,   154,   159,   181,   156,     0,   152,   147,   181,
     151,   181,   177,   109,   111,   118,   119,   134,   121,   126,
     248,   249,     0,     0,   101,     0,   157,   155,   153,   149,
     178,   120,    71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -304,  -304,  -304,  -304,   424,  -304,  -304,  -304,  -304,  -304,
       1,   -11,   -35,  -304,  -304,   302,   -59,   317,    38,  -134,
     174,   427,  -304,    19,  -304,   442,  -304,   -77,  -304,  -304,
    -304,   139,  -304,  -304,  -304,  -304,  -304,   155,  -304,    61,
    -304,  -304,    98,   251,  -304,  -304,   209,   181,  -207,  -304,
    -304,  -303,  -251,  -304,   -97,    57,  -202,  -210,  -167,   -44,
    -174,    46,  -304,   121,  -304,   122,  -304,   195,     0,  -304,
    -304,   -86,    14,    76,   183
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    36,    37,    38,    39,    74,    75,    76,   147,   148,
     380,   381,    40,   256,   150,    41,    42,   152,    43,   271,
      44,    45,    46,    61,    91,   110,   390,   111,    94,   261,
     262,   263,    96,    87,    67,   248,   249,   250,   251,   338,
     339,   454,   340,   223,   224,   305,   291,   225,   226,   227,
     293,   294,   343,   402,   403,   404,   228,   301,   302,   229,
     405,   289,    84,    48,    49,    50,    51,    52,    62,    54,
      55,   173,   174,    64,   193
  };

  const short
  parser::yytable_[] =
  {
      53,    66,   160,   105,   221,   372,   151,   303,   292,   273,
     -43,     2,    68,   295,    70,    71,    72,   100,   366,    47,
      81,   348,    85,   212,    98,    63,   179,   323,   181,   392,
     149,    97,     2,   221,   221,     2,     2,   221,    53,   288,
     211,     2,     2,    82,   212,   367,   117,   309,    57,    60,
     117,    69,   177,    88,  -107,    77,   393,    47,   139,   283,
     324,   119,   -43,   -43,   415,    53,   -43,   368,   378,    78,
     163,    99,   216,   101,   165,    10,    56,   342,    10,    10,
     109,  -107,   114,    65,    47,    10,   304,   361,   362,   151,
     364,   130,    79,   284,   344,   130,   290,   347,   212,    65,
     178,   371,    89,  -107,   154,    89,   373,    73,    65,   217,
     218,   156,   219,   239,    56,   447,   159,   155,   184,   106,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   182,
     203,   204,   205,   206,   207,   208,   209,   283,   117,   138,
     232,    56,   234,   140,   172,   235,   236,    60,    53,   119,
      60,   180,    60,    60,   183,   243,   441,   175,   141,   176,
     414,   252,    53,   112,   254,   416,   257,    47,   109,   406,
     113,   284,   245,   153,   408,   142,   220,   275,   115,   221,
     233,   285,   157,   130,   230,   116,   320,   432,   158,   133,
     134,   349,   168,    80,   350,    83,    60,    86,   279,   247,
     166,    63,    90,    93,    95,   220,   220,   260,   401,   220,
     164,   292,   425,   230,   230,   142,   448,   230,   106,   161,
     331,    90,   274,   237,    56,    60,   457,   437,   106,   167,
     320,   106,   342,   442,   453,   290,   117,   438,    56,   283,
     190,   191,   328,   329,   330,   320,   241,   119,   283,   378,
     436,   327,   212,    90,   439,   387,   246,   310,   190,   191,
     283,  -188,   274,   274,   401,   434,   401,   460,  -188,   106,
     346,   320,   315,   284,   332,   377,   378,   379,   190,   191,
      65,   130,   284,   285,   353,   131,   132,   133,   134,   264,
     356,   283,   285,   189,   284,   351,   190,   191,   255,   363,
     401,   433,   337,   435,   285,   401,   369,    65,   384,   190,
     191,   189,   222,   266,   192,    60,   106,  -189,    60,   283,
     210,   385,  -187,   277,  -189,   284,   252,   170,   142,  -187,
     320,   189,   192,   276,   278,   285,   412,   456,   280,   212,
     244,   222,   222,   274,   274,   222,   274,   190,   191,   189,
     272,   220,   192,   284,   374,   106,   171,   106,   267,   230,
     169,   312,   189,   285,   247,   290,   413,   190,   191,   313,
     192,   282,   321,   320,   260,   320,   178,   212,   424,   211,
     400,   306,   325,   192,     2,   211,   287,   397,   426,   212,
     272,   272,   428,   397,   326,   212,   398,   307,   333,   320,
     189,    25,    26,   107,   190,   191,   190,   191,   308,   316,
     334,   335,   216,   417,   190,   191,   336,   419,   258,   259,
     189,   192,   265,   365,   450,   274,   451,   452,   341,   322,
     345,   311,   388,   337,   117,   389,   317,   318,   394,   319,
     396,   192,   395,   274,   409,   119,   410,   418,   399,   217,
     218,   427,   219,   463,   431,   211,   464,   189,   440,   189,
     443,   128,   104,   458,   253,   240,   352,   189,   354,   337,
      92,   272,   272,   108,   272,   391,   358,   400,   192,   130,
     192,   386,   274,   131,   132,   133,   134,   222,   192,     2,
     185,   186,   455,   430,   382,     0,   459,   355,   190,   191,
     212,     0,     0,   359,   360,     0,    90,     0,     0,     0,
       0,     2,   185,   186,   190,   191,   370,     0,   375,   376,
     314,     2,   185,   186,   383,     0,     0,     0,     0,     0,
       0,     0,    10,   187,     0,     0,   102,   188,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   189,   357,   272,    10,   187,     0,     0,     0,   188,
     423,     0,     0,     0,    10,   187,     0,   189,     0,   188,
       0,   272,   192,     0,     0,     0,   429,     0,     0,     0,
       0,   420,   421,   422,     0,    10,    11,     0,   192,     0,
      12,     0,   103,    13,     0,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,    17,     0,
     272,    18,    19,    20,    21,     0,    22,     0,     0,     0,
       0,     0,     0,    23,   444,   445,   446,     0,   449,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     2,
     211,    31,     0,    32,    33,    34,    35,     0,     0,     0,
     212,   268,   461,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     2,   211,     0,     0,
     296,     0,     0,     0,     0,    65,     0,   212,   268,     0,
       2,   211,    10,   269,     0,   270,     0,     0,     0,     0,
       0,   212,   213,     0,     0,     0,     0,    10,    11,     0,
      20,    21,    12,    22,   238,    13,     0,    14,    15,    10,
     269,   214,   270,    16,     0,     0,    24,    25,    26,    27,
      17,    29,   215,    10,    19,    20,    21,     0,    22,     0,
     143,   144,   145,   146,     0,    23,   297,   298,   299,   300,
     216,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,    32,    33,    34,    35,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,   117,     0,     0,     0,   217,   218,     0,
     219,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,     0,
     128,     0,     0,    10,    11,     0,     0,     0,    12,     0,
       0,    13,     0,    14,    15,     0,     0,     0,   130,    16,
       0,     0,   131,   132,   133,   134,    17,   135,   136,     0,
      19,    20,    21,     0,    22,     0,   143,   144,   145,   146,
       0,    23,     2,   211,     0,     0,     0,    24,    25,    26,
      27,    28,    29,   212,   268,     0,     0,     0,     0,    31,
       0,    32,    33,    34,    35,     1,     2,     3,     4,     5,
       6,     7,     8,   296,     9,     0,     0,     0,     0,   117,
       0,     0,     0,     0,     0,    10,   269,     0,   270,     0,
     119,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,    10,
      11,     0,     0,     0,    12,     0,     0,    13,     0,    14,
      15,     0,    65,     0,   130,    16,   162,     0,   131,   132,
     133,   134,    17,   135,   136,    18,    19,    20,    21,     0,
      22,     0,     0,     0,   137,     0,     0,    23,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,    32,    33,    34,
      35,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    10,    11,    59,     0,     0,
      12,     0,     0,    13,     0,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    10,    11,     0,    65,
       0,    12,    19,     0,    13,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    19,     0,     0,     0,     0,     0,     0,
       0,    31,     0,    32,    33,    34,    35,     0,     0,     0,
       0,    25,    26,    27,     1,     2,     3,     4,     5,     6,
       7,     8,    31,     9,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    12,   242,     0,    13,     0,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    10,
      11,   281,     0,     0,    12,    19,     0,    13,     0,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    19,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,    33,    34,    35,
       0,     0,     0,     0,    25,    26,    27,     1,     2,     3,
       4,     5,     6,     7,     8,    31,     9,    32,    33,    34,
      35,   117,     0,     0,     0,     0,     0,   118,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,    10,    11,     0,     0,     0,    12,     0,     0,    13,
       0,    14,    15,     0,     0,     0,   130,    16,     0,     0,
     131,   132,   133,   134,     0,   135,   136,     0,    19,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,     0,   117,     0,    25,    26,    27,     0,
       0,     0,     0,     0,     0,   119,     0,    31,     0,    32,
      33,    34,    35,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,   130,
       0,   117,     0,   131,   132,   133,   134,     0,   135,   136,
       0,     0,   119,     0,     0,     0,     0,     0,     0,   137,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,     0,     0,   130,     0,   117,     0,
     131,   132,   133,   134,     0,   135,   136,     0,     0,   119,
       0,     0,     0,     0,     0,     0,   137,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   286,   117,     0,   131,   132,   133,
     134,     0,   135,   136,     0,     0,   119,     0,     0,     0,
       0,     0,     0,   137,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
     130,     0,   117,     0,   131,   132,   133,   134,     0,   135,
     136,     0,     0,   119,     0,     0,     0,     0,     0,     0,
     137,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   411,   117,
       0,   131,   132,   133,   134,     0,   135,   136,     0,     0,
     119,     0,     0,     0,     0,     0,     0,   137,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,     0,     0,   130,     0,   117,     0,   131,   132,
     133,   134,     0,   135,   136,     0,     0,   119,     0,     0,
       0,     0,     0,     0,   137,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,   119,   131,   132,   133,   134,     0,
     135,   136,   120,   121,   122,   123,   124,   125,     0,     0,
     128,   137,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,   119,   131,   132,   133,   134,     0,   135,   136,   120,
     121,   122,   123,   124,   125,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,   119,     0,   131,
     132,   133,   134,     0,   135,   120,   121,   122,   123,   124,
     125,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   131,   132,   133,   134
  };

  const short
  parser::yycheck_[] =
  {
       0,    12,    79,    38,   138,   308,    65,   217,   215,   176,
       0,     6,    12,   215,    14,    15,    16,     0,    21,     0,
      20,   272,    22,    17,    35,    11,   112,    15,   114,    21,
      65,    31,     6,   167,   168,     6,     6,   171,    38,   213,
       7,     6,     6,     7,    17,    48,     9,   221,    10,    11,
       9,    13,    21,     5,    21,    17,    48,    38,    58,    20,
      48,    20,    52,    53,   367,    65,    56,    70,    21,    73,
      81,     0,    66,    56,    85,    49,     0,    50,    49,    49,
      54,    48,    50,    52,    65,    49,   220,   297,   298,   148,
     300,    54,    96,    54,   268,    54,    15,   271,    17,    52,
     111,   308,    76,    70,    55,    76,   308,   102,    52,   103,
     104,    73,   106,   148,    38,   418,    78,    68,   118,    49,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   115,
     130,   131,   132,   133,   134,   135,   136,    20,     9,    50,
     140,    65,   142,    48,   106,   145,   146,   109,   148,    20,
     112,   113,   114,   115,   116,   155,   407,    20,    51,    22,
     367,   161,   162,    50,   164,   367,   166,   148,    54,   343,
      57,    54,   158,    55,   348,    68,   138,   177,    50,   313,
     142,    64,    48,    54,   138,    57,   230,   397,    15,    60,
      61,   277,    50,    19,   280,    21,   158,    23,    51,   161,
      21,   187,    28,    29,    30,   167,   168,   169,   342,   171,
      79,   418,   379,   167,   168,    68,   418,   171,    49,    50,
     255,    47,   176,    56,   148,   187,   436,   401,    49,    50,
     274,    49,    50,   407,    15,    15,     9,    51,   162,    20,
     119,   119,   253,   254,   255,   289,    53,    20,    20,    21,
      15,   251,    17,    79,    68,   332,    48,    37,   137,   137,
      20,    50,   216,   217,   398,   399,   400,   441,    57,    49,
     270,   315,   226,    54,   255,    20,    21,    22,   157,   157,
      52,    54,    54,    64,   284,    58,    59,    60,    61,    50,
     290,    20,    64,   119,    54,    55,   175,   175,    81,   299,
     434,   398,   264,   400,    64,   439,   306,    52,    37,   188,
     188,   137,   138,    55,   119,   277,    49,    50,   280,    20,
     137,   321,    50,    50,    57,    54,   326,    21,    68,    57,
     374,   157,   137,    51,    51,    64,    37,   434,    50,    17,
     157,   167,   168,   297,   298,   171,   300,   226,   226,   175,
     176,   313,   157,    54,   308,    49,    50,    49,   175,   313,
      52,    51,   188,    64,   326,    15,   366,   246,   246,    68,
     175,   188,    48,   417,   336,   419,   387,    17,   378,     7,
     342,    21,    51,   188,     6,     7,   212,    15,   388,    17,
     216,   217,   392,    15,    68,    17,    18,    37,    51,   443,
     226,    94,    95,    96,   283,   283,   285,   285,    48,   226,
      51,    53,    66,   367,   293,   293,    68,   371,   167,   168,
     246,   226,   171,    37,   423,   379,   425,   427,    51,   246,
      51,   222,    21,   395,     9,   101,   227,   228,    51,   230,
      21,   246,    68,   397,    51,    20,    51,    48,    70,   103,
     104,    50,   106,   453,    50,     7,    51,   283,    37,   285,
     414,    36,    38,    37,   162,   148,   283,   293,   285,   431,
      28,   297,   298,    46,   300,   336,   293,   439,   283,    54,
     285,   326,   436,    58,    59,    60,    61,   313,   293,     6,
       7,     8,   431,   395,   313,    -1,   439,   288,   377,   377,
      17,    -1,    -1,   294,   295,    -1,   332,    -1,    -1,    -1,
      -1,     6,     7,     8,   393,   393,   307,    -1,   309,   310,
      37,     6,     7,     8,   315,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,     0,    54,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,   377,    37,   379,    49,    50,    -1,    -1,    -1,    54,
     377,    -1,    -1,    -1,    49,    50,    -1,   393,    -1,    54,
      -1,   397,   377,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,   372,   373,   374,    -1,    49,    50,    -1,   393,    -1,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
     436,    75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    87,   415,   416,   417,    -1,   419,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,     6,
       7,   105,    -1,   107,   108,   109,   110,    -1,    -1,    -1,
      17,    18,   443,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,     6,     7,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    52,    -1,    17,    18,    -1,
       6,     7,    49,    50,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    49,    50,    -1,
      77,    78,    54,    80,    56,    57,    -1,    59,    60,    49,
      50,    37,    52,    65,    -1,    -1,    93,    94,    95,    96,
      72,    98,    48,    49,    76,    77,    78,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    87,   103,   104,   105,   106,
      66,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,   107,   108,   109,   110,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,   103,   104,    -1,
     106,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    -1,    -1,    -1,    54,    65,
      -1,    -1,    58,    59,    60,    61,    72,    63,    64,    -1,
      76,    77,    78,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    87,     6,     7,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    17,    18,    -1,    -1,    -1,    -1,   105,
      -1,   107,   108,   109,   110,     5,     6,     7,     8,     9,
      10,    11,    12,    37,    14,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      60,    -1,    52,    -1,    54,    65,    56,    -1,    58,    59,
      60,    61,    72,    63,    64,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,    74,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,
     110,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      -1,    54,    76,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    94,    95,    96,     5,     6,     7,     8,     9,    10,
      11,    12,   105,    14,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    54,    76,    -1,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    94,    95,    96,     5,     6,     7,
       8,     9,    10,    11,    12,   105,    14,   107,   108,   109,
     110,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    60,    -1,    -1,    -1,    54,    65,    -1,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,   105,    -1,   107,
     108,   109,   110,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      -1,     9,    -1,    58,    59,    60,    61,    -1,    63,    64,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,     9,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,     9,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,     9,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,     9,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,     9,    -1,    58,    59,
      60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    20,    58,    59,    60,    61,    -1,
      63,    64,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    20,    58,    59,    60,    61,    -1,    63,    64,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    20,    -1,    58,
      59,    60,    61,    -1,    63,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    60,    61
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      49,    50,    54,    57,    59,    60,    65,    72,    75,    76,
      77,    78,    80,    87,    93,    94,    95,    96,    97,    98,
      99,   105,   107,   108,   109,   110,   112,   113,   114,   115,
     123,   126,   127,   129,   131,   132,   133,   134,   174,   175,
     176,   177,   178,   179,   180,   181,   184,   129,    48,    51,
     129,   134,   179,   183,   184,    52,   122,   145,   179,   129,
     179,   179,   179,   102,   116,   117,   118,   129,    73,    96,
     131,   179,     7,   131,   173,   179,   131,   144,     5,    76,
     131,   135,   136,   131,   139,   131,   143,   179,   122,     0,
       0,    56,     0,    56,   115,   123,    49,    96,   132,    54,
     136,   138,    50,    57,    50,    50,    57,     9,    15,    20,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      54,    58,    59,    60,    61,    63,    64,    74,    50,   179,
      48,    51,    68,    82,    83,    84,    85,   119,   120,   123,
     125,   127,   128,    55,    55,    68,   129,    48,    15,   129,
     138,    50,    56,   122,    79,   122,    21,    50,    50,    52,
      21,    50,   129,   182,   183,    20,    22,    21,   122,   182,
     129,   182,   183,   129,   179,     7,     8,    50,    54,   131,
     174,   176,   178,   185,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     185,     7,    17,    18,    37,    48,    66,   103,   104,   106,
     129,   130,   131,   154,   155,   158,   159,   160,   167,   170,
     172,    51,   179,   129,   179,   179,   179,    56,    56,   123,
     128,    53,    55,   179,   185,   183,    48,   129,   146,   147,
     148,   149,   179,   126,   179,    81,   124,   179,   154,   154,
     129,   140,   141,   142,    50,   154,    55,   185,    18,    50,
      52,   130,   131,   169,   172,   179,    51,    50,    51,    51,
      50,    51,   185,    20,    54,    64,    55,   131,   171,   172,
      15,   157,   159,   161,   162,   167,    37,   103,   104,   105,
     106,   168,   169,   168,   130,   156,    21,    37,    48,   171,
      37,   157,    51,    68,    37,   172,   185,   157,   157,   157,
     170,    48,   185,    15,    48,    51,    68,   179,   122,   122,
     122,   123,   134,    51,    51,    53,    68,   129,   150,   151,
     153,    51,    50,   163,   171,    51,   179,   171,   163,   182,
     182,    55,   185,   179,   185,   157,   179,    37,   185,   157,
     157,   168,   168,   179,   168,    37,    21,    48,    70,   179,
     157,   159,   162,   167,   172,   157,   157,    20,    21,    22,
     121,   122,   158,   157,    37,   179,   148,   138,    21,   101,
     137,   142,    21,    48,    51,    68,    21,    15,    18,    70,
     129,   130,   164,   165,   166,   171,   171,    53,   171,    51,
      51,    55,    37,   179,   159,   162,   167,   172,    48,   172,
     157,   157,   157,   185,   179,   169,   179,    50,   179,   185,
     153,    50,   168,   165,   130,   165,    15,   171,    51,    68,
      37,   163,   171,   172,   157,   157,   157,   162,   167,   157,
     121,   121,   179,    15,   152,   150,   165,   168,    37,   166,
     171,   157,    51,   179,    51
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   111,   112,   112,   113,   113,   113,   114,   114,   114,
     114,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   121,   121,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   128,   128,   129,   130,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     137,   137,   138,   138,   138,   139,   140,   140,   141,   141,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   159,   160,   160,   160,
     160,   161,   161,   162,   162,   162,   162,   163,   164,   164,
     165,   165,   165,   165,   165,   165,   166,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   168,   168,
     168,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     170,   171,   171,   172,   172,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   177,   177,   178,   178,   178,   178,   178,   178,   178,
     179,   179,   179,   179,   179,   180,   180,   181,   181,   181,
     182,   182,   183,   183,   183,   183,   184,   184,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185
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
       2,     4,     3,     4,     3,     4,     2,     2,     2,     2,
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
       0,   342,   342,   343,   347,   349,   351,   368,   370,   371,
     373,   378,   380,   389,   391,   396,   397,   402,   404,   409,
     410,   415,   417,   419,   424,   426,   427,   429,   435,   438,
     449,   454,   456,   458,   460,   462,   464,   466,   476,   481,
     483,   488,   489,   493,   495,   503,   505,   507,   514,   516,
     520,   521,   523,   525,   527,   529,   534,   542,   557,   559,
     561,   567,   568,   572,   573,   577,   579,   584,   586,   591,
     609,   611,   623,   624,   626,   633,   638,   639,   643,   645,
     650,   656,   658,   681,   687,   704,   706,   712,   713,   717,
     719,   724,   726,   731,   733,   739,   740,   744,   746,   751,
     752,   756,   758,   765,   766,   770,   772,   777,   778,   782,
     783,   788,   792,   794,   798,   801,   804,   809,   817,   819,
     821,   823,   826,   828,   831,   833,   835,   837,   839,   847,
     849,   851,   853,   855,   860,   867,   868,   872,   874,   878,
     880,   885,   890,   894,   896,   900,   902,   912,   917,   919,
     925,   927,   930,   932,   936,   939,   945,   948,   961,   964,
     969,   970,   971,   972,   973,   974,   975,   976,   980,   981,
     982,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1007,  1012,  1014,  1018,  1020,  1026,  1028,  1033,  1035,  1037,
    1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,
    1061,  1063,  1069,  1080,  1082,  1084,  1086,  1088,  1095,  1102,
    1104,  1106,  1108,  1111,  1113,  1117,  1119,  1123,  1125,  1127,
    1129,  1131,  1133,  1135,  1138,  1142,  1145,  1148,  1150,  1162,
    1182,  1195,  1199,  1206,  1208,  1210,  1215,  1217,  1219,  1224,
    1229,  1230,  1231,  1232,  1233,  1238,  1240,  1245,  1252,  1260,
    1271,  1273,  1278,  1280,  1286,  1291,  1299,  1301,  1341,  1343,
    1345,  1347,  1348,  1350,  1352,  1353,  1355,  1357
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
#line 5957 "annium.tab.cpp"

#line 1552 "annium.y"

