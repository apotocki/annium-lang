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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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
#line 350 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 350 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 350 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 350 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 350 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 350 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 350 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 350 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 350 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 350 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 350 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 350 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 350 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 350 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 350 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 350 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 350 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 350 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 350 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 350 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 350 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 350 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 350 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 350 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 350 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 350 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 350 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 350 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 350 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 350 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 350 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 350 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 350 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 350 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 350 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 350 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 350 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 350 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 350 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 350 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 350 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 350 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 350 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 350 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 350 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
#line 350 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 350 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_REFERENCE: // "reference modifier"
#line 350 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 350 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 350 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 350 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 350 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 350 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_finished_statement_any: // finished-statement-any
#line 350 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 350 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl: // let-decl
#line 350 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start: // let-decl-start
#line 350 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 350 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_infunction_statement_any: // infunction-statement-any
#line 350 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_finished_infunction_statement_any: // finished-infunction-statement-any
#line 350 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_function_body: // function-body
#line 350 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_braced_statements: // braced-statements
#line 350 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_finished_statement: // finished-statement
#line 350 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_if_else_tail: // if-else-tail
#line 350 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_infunction_statement_set: // infunction-statement-set
#line 350 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_expression_statement: // expression-statement
#line 350 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_generic_statement: // generic-statement
#line 350 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_infunction_statement: // infunction-statement
#line 350 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 350 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_internal_identifier: // internal-identifier
#line 350 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 350 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_kind: // fn-kind
#line 350 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind_set: // fn-kind-set
#line 350 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_prefix_decl: // fn-prefix-decl
#line 350 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_name: // fn-name
#line 350 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_start_decl: // fn-start-decl
#line 350 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_requirement_opt: // fn-requirement-opt
#line 350 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_decl: // fn-decl
#line 350 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_enum_decl: // enum-decl
#line 350 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
#line 350 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list: // case-list
#line 350 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_decl: // case-decl
#line 350 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_struct_decl: // struct-decl
#line 350 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_using_decl: // using-decl
#line 350 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_expression_list: // expression-list
#line 350 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_list_opt: // argument-list-opt
#line 350 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list: // argument-list
#line 350 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 350 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_argument_name: // argument-name
#line 350 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
#line 350 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list: // field-list
#line 350 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_default_value_opt: // field-default-value-opt
#line 350 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 350 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_list_opt: // parameter-list-opt
#line 350 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list: // parameter-list
#line 350 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_internal_identifier_opt: // internal-identifier-opt
#line 350 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_parameter_default_value_opt: // parameter-default-value-opt
#line 350 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
#line 350 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_parameter_decl: // parameter-decl
#line 350 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 350 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_specified: // constraint-expression-specified
#line 350 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression_mod: // constraint-expression-mod
#line 350 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_constraint_expression: // constraint-expression
#line 350 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 350 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_list: // pattern-list
#line 350 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_field_sfx: // pattern-field-sfx
#line 350 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_field: // pattern-field
#line 350 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_mod: // pattern-mod
#line 350 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
#line 350 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 350 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_concept_expression: // concept-expression
#line 350 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression_list_opt: // concept-expression-list-opt
#line 350 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_concept_expression_list: // concept-expression-list
#line 350 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_reference_expression: // reference-expression
#line 350 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_any_reference_expression: // any-reference-expression
#line 350 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_syntax_expression_base: // syntax-expression-base
#line 350 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_grouped_expression: // grouped-expression
#line 350 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_new_expression: // new-expression
#line 350 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_call_expression: // call-expression
#line 350 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_syntax_expression: // syntax-expression
#line 350 "annium.y"
                 { }
#line 2641 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_lambda_start_decl: // lambda-start-decl
#line 350 "annium.y"
                 { }
#line 2647 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_lambda_expression: // lambda-expression
#line 350 "annium.y"
                 { }
#line 2653 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_pack_expression_opt: // pack-expression-opt
#line 350 "annium.y"
                 { }
#line 2659 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_pack_expression: // pack-expression
#line 350 "annium.y"
                 { }
#line 2665 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_compound_expression: // compound-expression
#line 350 "annium.y"
                 { }
#line 2671 "annium.tab.cpp"
        break;

      case symbol_kind::S_188_type_expr: // type-expr
#line 350 "annium.y"
                 { }
#line 2677 "annium.tab.cpp"
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

      case symbol_kind::S_170_pattern_mod: // pattern-mod
      case symbol_kind::S_171_pattern_sfx: // pattern-sfx
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
#line 355 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3181 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 356 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3187 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 361 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3193 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 363 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3199 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 365 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3205 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 382 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3211 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 383 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3217 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 385 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3223 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 387 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3229 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 392 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3235 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 394 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3248 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 403 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3254 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 405 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3260 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 409 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3266 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 411 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3272 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 416 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3278 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 418 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3284 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 422 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3290 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 424 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3296 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 429 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3302 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 431 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3308 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 433 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3314 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 438 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3320 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 439 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3326 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 441 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3332 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 443 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3338 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 448 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3344 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 452 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3350 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 463 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3356 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 468 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3362 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 470 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3368 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 472 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3374 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 474 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3380 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 476 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3386 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 478 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3392 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 480 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3402 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 490 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3408 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 495 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3414 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 497 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3420 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 501 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3426 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 502 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3432 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 507 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3438 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 509 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3447 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 517 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3453 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 519 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3459 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 521 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3470 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 528 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3476 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 529 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3482 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 533 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3488 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 535 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3494 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 537 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3500 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 539 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3506 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 541 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3512 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 543 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3518 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 548 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3524 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 556 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3530 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 571 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3536 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 573 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3542 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 575 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3548 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 580 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3554 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 581 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3560 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 585 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3566 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 586 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3572 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 591 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3578 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 593 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3584 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 598 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3590 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 600 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3596 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 605 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3602 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 622 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3608 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 625 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3614 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 636 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3620 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 638 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3626 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 640 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3632 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 647 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3638 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 651 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3644 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 652 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3650 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 657 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3656 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 659 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3662 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 664 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3668 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 670 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3674 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 672 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3680 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 695 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3690 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 701 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3701 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 718 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3707 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 720 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3713 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 725 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3719 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 726 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3725 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 731 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3731 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 733 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3737 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 738 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3743 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 740 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3749 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 745 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3755 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 747 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3761 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 752 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3767 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 753 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3773 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 758 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3779 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 760 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3785 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 764 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3791 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 765 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3797 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 770 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3803 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 772 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3809 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 778 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3815 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 779 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3821 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 784 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3827 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 786 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3833 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 790 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3839 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 791 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3845 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 795 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3851 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 796 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3857 "annium.tab.cpp"
    break;

  case 111: // ellipsis-opt-assign-value-opt: %empty
#line 800 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 3863 "annium.tab.cpp"
    break;

  case 112: // ellipsis-opt-assign-value-opt: "`...`"
#line 801 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 3869 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 802 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3875 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 803 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3881 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 809 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3887 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 813 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3893 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 819 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3899 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 821 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3909 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 828 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3918 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 834 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 3928 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 840 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3934 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 842 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3940 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 844 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3946 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 846 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3952 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 849 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3958 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 851 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3967 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 856 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3973 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 858 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3979 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: pattern-mod parameter-default-value-opt
#line 860 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3985 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 868 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3994 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 873 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4003 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 878 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4012 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`...`" parameter-default-value-opt
#line 883 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4018 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 888 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4024 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified-mod: "constexpr modifier"
#line 894 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4030 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified-mod: "runctime modifier"
#line 895 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4036 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 900 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4042 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 902 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4048 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod
#line 906 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4054 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 908 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4060 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-mod: %empty
#line 913 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4069 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-mod: constraint-expression-specified-mod
#line 917 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4075 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod type-expr
#line 922 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4081 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 924 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4087 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod
#line 928 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4093 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod "`...`"
#line 930 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4099 "annium.tab.cpp"
    break;

  case 147: // subpatterns: "`(`" pattern-list "`)`"
#line 940 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4105 "annium.tab.cpp"
    break;

  case 148: // pattern-list: pattern-field
#line 945 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4111 "annium.tab.cpp"
    break;

  case 149: // pattern-list: pattern-list "," pattern-field
#line 947 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4117 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: concept-expression-list-opt
#line 953 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4123 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 955 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4129 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 958 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4135 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 960 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4141 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: "`=`" pattern-sfx
#line 964 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4147 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 967 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4153 "annium.tab.cpp"
    break;

  case 156: // pattern-field: identifier pattern-field-sfx
#line 973 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4159 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 976 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4165 "annium.tab.cpp"
    break;

  case 158: // pattern-field: pattern-field-sfx
#line 989 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4171 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`_`" pattern-field-sfx
#line 992 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4177 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" pattern-sfx
#line 996 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 4183 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 997 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4189 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 998 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4195 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "reference modifier" pattern-sfx
#line 999 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4201 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "consteval modifier" syntax-expression
#line 1000 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4207 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "typename modifier" pattern-sfx
#line 1001 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4213 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "typename modifier"
#line 1002 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4219 "annium.tab.cpp"
    break;

  case 167: // pattern-sfx: pattern
#line 1006 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4225 "annium.tab.cpp"
    break;

  case 168: // pattern-sfx: pattern "`...`"
#line 1007 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4231 "annium.tab.cpp"
    break;

  case 169: // pattern-sfx: "`...`"
#line 1008 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4237 "annium.tab.cpp"
    break;

  case 170: // pattern: qname
#line 1013 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4243 "annium.tab.cpp"
    break;

  case 171: // pattern: qname subpatterns concept-expression-list-opt
#line 1015 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4249 "annium.tab.cpp"
    break;

  case 172: // pattern: internal-identifier concept-expression-list-opt
#line 1017 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4255 "annium.tab.cpp"
    break;

  case 173: // pattern: "`_`" concept-expression-list-opt
#line 1019 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4261 "annium.tab.cpp"
    break;

  case 174: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1021 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4267 "annium.tab.cpp"
    break;

  case 175: // pattern: "`(`" "`)`"
#line 1023 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4273 "annium.tab.cpp"
    break;

  case 176: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1025 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4279 "annium.tab.cpp"
    break;

  case 177: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1027 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4285 "annium.tab.cpp"
    break;

  case 178: // pattern: concept-expression-list
#line 1029 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4291 "annium.tab.cpp"
    break;

  case 179: // concept-expression: "`@`" qname
#line 1034 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4297 "annium.tab.cpp"
    break;

  case 180: // concept-expression-list-opt: %empty
#line 1039 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4303 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list-opt: concept-expression-list
#line 1040 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4309 "annium.tab.cpp"
    break;

  case 182: // concept-expression-list: concept-expression
#line 1045 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4315 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list: concept-expression-list concept-expression
#line 1047 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4321 "annium.tab.cpp"
    break;

  case 184: // reference-expression: CONTEXT_IDENTIFIER
#line 1053 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4327 "annium.tab.cpp"
    break;

  case 185: // reference-expression: qname
#line 1055 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4333 "annium.tab.cpp"
    break;

  case 186: // any-reference-expression: RESERVED_IDENTIFIER
#line 1060 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4339 "annium.tab.cpp"
    break;

  case 187: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1062 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4345 "annium.tab.cpp"
    break;

  case 188: // any-reference-expression: qname
#line 1064 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4351 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: "nil"
#line 1069 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4357 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "true"
#line 1071 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4363 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: "false"
#line 1073 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4369 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: INTEGER
#line 1075 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4375 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: DECIMAL
#line 1077 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4381 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: DECIMAL_S
#line 1079 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4387 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: INTEGER_INDEX
#line 1081 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4393 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: STRING
#line 1083 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4399 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: CT_IDENTIFIER
#line 1085 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4405 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: any-reference-expression
#line 1086 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4411 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`(`" "`)`"
#line 1088 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4417 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1090 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4426 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1096 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4438 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1107 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4444 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1109 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4450 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1111 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4456 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: PROBE braced-statements
#line 1113 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4462 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`.`" identifier
#line 1115 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4468 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1122 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4478 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: "`-`" syntax-expression
#line 1129 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4484 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1131 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4490 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1145 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4496 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`!`" syntax-expression
#line 1147 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4502 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "`*`" syntax-expression
#line 1149 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4508 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1152 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4514 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1154 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4520 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1158 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4526 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1160 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4532 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1164 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4538 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1166 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4544 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1168 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4550 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1170 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4556 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1172 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4562 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1174 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4568 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1176 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4574 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4580 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1183 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4586 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1186 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4592 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1189 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4598 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1191 "annium.y"
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
#line 4613 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1203 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4619 "annium.tab.cpp"
    break;

  case 230: // grouped-expression: "`(`" pack-expression "`)`"
#line 1223 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4632 "annium.tab.cpp"
    break;

  case 231: // new-expression: "`new`" qname
#line 1236 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4638 "annium.tab.cpp"
    break;

  case 232: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1240 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4644 "annium.tab.cpp"
    break;

  case 233: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1247 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4650 "annium.tab.cpp"
    break;

  case 234: // call-expression: any-reference-expression "`.`" identifier
#line 1249 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4656 "annium.tab.cpp"
    break;

  case 235: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1251 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4665 "annium.tab.cpp"
    break;

  case 236: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1256 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4671 "annium.tab.cpp"
    break;

  case 237: // call-expression: call-expression "`.`" identifier
#line 1258 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4677 "annium.tab.cpp"
    break;

  case 238: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1260 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4686 "annium.tab.cpp"
    break;

  case 239: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1265 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4692 "annium.tab.cpp"
    break;

  case 240: // syntax-expression: syntax-expression-base
#line 1269 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4698 "annium.tab.cpp"
    break;

  case 241: // syntax-expression: new-expression
#line 1270 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4704 "annium.tab.cpp"
    break;

  case 242: // syntax-expression: compound-expression
#line 1271 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4710 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: lambda-expression
#line 1272 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4716 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: grouped-expression
#line 1273 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4722 "annium.tab.cpp"
    break;

  case 245: // lambda-start-decl: fn-prefix-decl
#line 1279 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4728 "annium.tab.cpp"
    break;

  case 246: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1281 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4734 "annium.tab.cpp"
    break;

  case 247: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1286 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4745 "annium.tab.cpp"
    break;

  case 248: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1293 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4757 "annium.tab.cpp"
    break;

  case 249: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1301 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4769 "annium.tab.cpp"
    break;

  case 250: // pack-expression-opt: %empty
#line 1312 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4775 "annium.tab.cpp"
    break;

  case 251: // pack-expression-opt: pack-expression
#line 1314 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4781 "annium.tab.cpp"
    break;

  case 252: // pack-expression: syntax-expression
#line 1319 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4787 "annium.tab.cpp"
    break;

  case 253: // pack-expression: identifier "`:`" syntax-expression
#line 1321 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4797 "annium.tab.cpp"
    break;

  case 254: // pack-expression: pack-expression "," syntax-expression
#line 1327 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4806 "annium.tab.cpp"
    break;

  case 255: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1332 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4815 "annium.tab.cpp"
    break;

  case 256: // compound-expression: syntax-expression "`...`"
#line 1340 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4821 "annium.tab.cpp"
    break;

  case 257: // compound-expression: call-expression
#line 1341 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4827 "annium.tab.cpp"
    break;

  case 258: // type-expr: qname
#line 1382 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4833 "annium.tab.cpp"
    break;

  case 259: // type-expr: RESERVED_IDENTIFIER
#line 1384 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4839 "annium.tab.cpp"
    break;

  case 260: // type-expr: CONTEXT_IDENTIFIER
#line 1386 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4845 "annium.tab.cpp"
    break;

  case 261: // type-expr: call-expression
#line 1387 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4851 "annium.tab.cpp"
    break;

  case 262: // type-expr: "`[`" type-expr "`]`"
#line 1389 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4857 "annium.tab.cpp"
    break;

  case 263: // type-expr: "`(`" "`)`"
#line 1391 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4863 "annium.tab.cpp"
    break;

  case 264: // type-expr: grouped-expression
#line 1392 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4869 "annium.tab.cpp"
    break;

  case 265: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1394 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4875 "annium.tab.cpp"
    break;

  case 266: // type-expr: type-expr "`|`" type-expr
#line 1396 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4881 "annium.tab.cpp"
    break;

  case 267: // type-expr: type-expr "`->`" type-expr
#line 1398 "annium.y"
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
#line 4896 "annium.tab.cpp"
    break;


#line 4900 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -347;

  const short parser::yytable_ninf_ = -189;

  const short
  parser::yypact_[] =
  {
     893,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,
      47,  1001,  1022,    47,  1259,  1259,  1259,     1,   128,    61,
    1259,    40,  1259,    61,    39,  -347,  -347,  -347,    20,    61,
      61,  1259,    12,  -347,  -347,  -347,     6,    54,    30,   569,
    -347,  -347,  -347,  -347,  -347,    25,  -347,   472,    19,   222,
    -347,    81,  -347,   248,  1267,    93,  -347,     8,  -347,  1259,
    -347,    49,   151,  1676,   142,  -347,   785,    94,   205,  1676,
    -347,    28,    28,    28,    47,  -347,   165,   204,  -347,    47,
      20,   244,   903,  -347,    25,   166,  1347,    90,  -347,  -347,
    -347,    25,   234,  -347,   299,  -347,   146,  -347,    28,  1259,
    -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,    47,  -347,
    -347,  1259,    95,    24,  1259,    47,  1259,  1259,    47,  -347,
    1259,   410,  1259,  1259,  1259,  1259,  1259,  1259,  1259,  1259,
    1259,  -347,  1259,  1259,  1259,  1259,  1259,  1259,  1259,   410,
     603,  1394,  1259,  -347,  1259,  -347,  -347,  1259,  1259,   246,
     677,  -347,   258,  -347,  -347,  -347,  -347,  1130,  -347,   410,
    1259,   267,  -347,  1259,  1259,  -347,  1259,   247,  1259,   603,
     603,    47,   287,   603,  1441,  -347,   292,   275,   410,   759,
    1259,  -347,   310,   327,   330,   174,   337,  1676,   313,   345,
    1151,   410,   285,   222,    81,   248,    36,   349,   349,   349,
     349,   349,   349,  1723,   795,   418,  1488,   438,   438,    18,
      18,  1737,   685,   262,  -347,    61,   374,   382,    85,   410,
     500,   154,  -347,  1259,  -347,    35,    33,   229,   353,   332,
    -347,  1036,   382,   382,  -347,   357,  -347,  1676,   367,  1676,
    1676,  1676,  -347,  -347,  -347,  -347,  -347,  -347,  1676,   262,
     275,   410,     9,   354,   362,  -347,  1259,  1676,     6,  1347,
     464,  -347,  1676,   371,   375,  -347,   390,   377,  -347,    47,
     398,  1259,  -347,   262,    68,   399,  1259,   374,   387,  -347,
     374,  1676,  -347,  1259,  -347,  -347,  1259,  -347,   300,   410,
    1259,   410,  -347,    25,   240,   374,  1259,  -347,   382,   302,
    -347,   154,   154,   154,  -347,   419,  -347,  1676,  -347,   211,
     214,   240,  1259,   446,  -347,   288,   603,  -347,   357,   476,
    -347,  -347,  -347,  -347,  1259,   262,  -347,  -347,  -347,  1259,
    1676,  -347,  -347,  -347,  -347,    20,   449,   366,  -347,    47,
     178,   422,   412,  -347,   460,    28,    34,   374,  -347,  -347,
    1535,  -347,   374,   432,   435,  -347,    36,  1582,    36,  -347,
    1676,  -347,   240,  -347,  -347,  -347,  -347,   214,   440,   374,
     497,   382,   382,   357,  -347,  1676,  1259,   410,  1259,   759,
    -347,  -347,  -347,  -347,  -347,  1676,  -347,     6,  1259,   444,
    -347,  -347,  1259,   410,  -347,    47,   451,   154,   316,   495,
     316,   358,   224,  -347,  -347,   473,  -347,    68,  -347,  -347,
    -347,  -347,  -347,   374,   382,   382,   416,   386,   416,  -347,
     528,  -347,  -347,  -347,  1676,   249,  1676,   148,  1676,  1259,
    1676,   101,  -347,    47,  -347,  -347,   316,  -347,   154,   482,
    -347,    34,  -347,   374,  -347,   416,  -347,  -347,  -347,  -347,
    -347,  -347,  -347,  -347,  -347,  -347,  1629,  1259,  -347,   469,
    -347,  -347,  -347,  -347,  -347,  -347,  -347,  1676,  -347
  };

  const short
  parser::yydefact_[] =
  {
       4,   196,    56,   187,   186,   195,   192,   193,   194,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    65,     0,     0,
       0,     0,     0,   189,   190,   191,     0,     0,     0,     0,
       5,     7,    49,    13,    59,   188,    63,     0,   245,   198,
     240,   244,   241,   257,     0,     0,   243,   242,    58,     0,
     199,    59,   245,   252,     0,   242,    21,     0,     0,    85,
     206,   208,   212,   211,     0,    45,    19,    15,    17,     0,
       0,   231,     0,   184,   185,     0,     0,     0,    48,    31,
      68,    67,     0,    46,     0,    38,     0,    14,   209,     0,
     205,     1,     2,    10,     3,     8,     6,     9,     0,    66,
      64,   250,    72,     0,   250,     0,   250,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   230,     0,    52,    51,    53,     0,    41,
      42,    24,     0,    50,    22,   203,   201,     0,    18,     0,
       0,     0,    12,    87,     0,    32,     0,    35,     0,   103,
     103,    76,     0,   103,     0,    60,     0,   251,     0,     0,
       0,    37,     0,   234,     0,     0,   237,    44,   260,   259,
       0,     0,   258,     0,   264,   261,   228,   217,   218,   219,
     220,   221,   222,   226,   227,   223,     0,   215,   216,   213,
     214,   224,   225,   229,    57,     0,   180,   109,     0,     0,
       0,   166,   135,     0,   136,    59,   180,   111,     0,   104,
     105,   139,   109,   109,   182,   111,   200,   253,    59,   254,
      54,    55,    27,    25,    26,    23,    30,   202,    86,    20,
      16,     0,    59,     0,    88,    89,     0,    92,     0,     0,
       0,    36,    83,     0,     0,    80,     0,    77,    78,    95,
       0,     0,   246,    73,   180,     0,     0,   180,   170,    74,
     178,    47,   233,   250,   239,   236,   250,   263,     0,     0,
       0,     0,   204,   179,   111,   181,     0,   133,   109,     0,
     169,     0,     0,     0,   160,   167,   165,   164,   108,     0,
     141,   111,     0,   112,   120,     0,     0,   140,   111,   137,
     117,   129,   132,   183,     0,    11,    93,    94,   232,     0,
      91,    33,    34,    39,    40,     0,     0,    70,    75,     0,
       0,     0,    96,    97,     0,   210,   180,   180,   173,   175,
       0,   172,   180,     0,     0,   262,   267,     0,   266,   131,
     110,   128,   111,   161,   162,   163,   168,   141,     0,   142,
     145,   109,   109,   111,   130,   113,     0,     0,     0,     0,
     247,    28,   106,   119,   138,   255,    90,     0,     0,     0,
      69,    79,     0,     0,    81,     0,     0,     0,   180,     0,
     180,   180,     0,   158,   148,   150,   174,   180,   171,   235,
     238,   265,   118,   142,   109,   109,   109,   141,   109,   146,
     143,   116,   125,   126,   114,     0,    29,     0,    84,     0,
     102,    99,    98,    95,   154,   159,   180,   156,     0,   152,
     147,   180,   151,   180,   176,   109,   115,   121,   122,   142,
     134,   124,   127,   144,   248,   249,     0,     0,   101,     0,
     157,   155,   153,   149,   177,   123,    71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -347,  -347,  -347,  -347,   487,  -347,  -347,  -347,  -347,  -347,
      38,    -7,   -38,  -347,  -347,   363,   -48,   379,    67,  -137,
     220,   485,  -347,     4,  -347,   505,  -347,   -70,  -347,  -347,
    -347,   196,  -347,  -347,  -347,  -347,  -347,   209,  -347,   106,
    -347,  -347,   150,   355,  -347,  -347,  -198,  -141,   227,  -304,
    -347,  -347,  -346,  -255,  -347,  -291,   112,  -209,  -210,  -177,
      50,  -118,   118,  -347,    55,  -347,    76,  -347,   193,     0,
    -347,  -347,   -97,     2,    48,   223
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    75,    76,    77,   149,   150,
     380,   381,    41,   261,   152,    42,    43,   154,    44,   277,
      45,    46,    47,    62,    92,   112,   390,   113,    95,   266,
     267,   268,    97,    88,    68,   253,   254,   255,   256,   341,
     342,   458,   343,   228,   229,   309,   297,   314,   230,   231,
     232,   370,   371,   347,   402,   403,   404,   233,   304,   305,
     234,   405,   295,    85,    49,    50,    51,    52,    53,    63,
      55,    56,   176,   177,    65,   196
  };

  const short
  parser::yytable_[] =
  {
      54,   107,   279,   226,    48,    67,   369,     2,   -43,   298,
     162,   306,    69,    64,    71,    72,    73,   182,   153,   184,
      82,   414,    86,   352,   326,     2,     2,   119,   151,   100,
     102,    98,   226,   226,   320,   321,   226,   119,   121,    54,
       2,   214,   214,    48,    89,   180,     2,    83,    57,   397,
     215,   215,   398,     2,   101,   131,   289,   327,    66,   141,
     -43,   -43,    99,   413,   -43,   131,    54,     2,    10,    10,
      48,   450,   132,   111,   108,   165,    66,    58,    61,   167,
      70,   310,   132,  -107,    78,   215,   103,    57,   308,    10,
     290,   363,   364,   365,   322,    90,    90,   142,   294,   174,
     361,   372,   153,    74,   399,  -107,   181,   435,   311,   437,
      10,   168,   244,   449,    57,   178,   457,   179,   346,   185,
     187,   289,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   116,   206,   207,   208,   209,   210,   211,   212,   108,
     169,   158,   237,   140,   239,   460,   161,   240,   241,   155,
      54,   220,   443,   359,    48,   290,   348,   248,   415,   351,
       2,   214,   250,   257,    54,   291,   259,   172,   262,   378,
     374,   215,   274,   421,   422,   175,   193,   383,    61,   226,
     281,    61,   183,    61,    61,   186,   353,   434,   221,   354,
     223,   300,    64,   143,   193,   108,   173,   194,    57,   392,
      66,    79,   427,    10,   275,   111,   276,   225,   451,   401,
     144,   238,    57,   159,   193,   194,   446,   447,   448,   160,
     452,   412,   334,   307,    80,   285,   393,    61,   461,   406,
     252,   215,   423,   193,   408,   194,   225,   225,   265,    81,
     225,    84,   144,    87,   312,   166,   193,   465,    91,    94,
      96,   331,   332,   333,   194,   312,   330,    61,   235,   367,
     156,   401,   436,   401,   335,   387,   313,   194,    91,   289,
     378,   345,   114,   157,   193,   440,   350,   313,   108,   115,
     220,   368,   289,   439,   170,   323,   193,   235,   235,   444,
     357,   235,   441,   108,   163,   194,   360,   280,   117,   401,
      91,    66,   242,   290,   401,   118,   193,   194,   377,   378,
     379,   246,   375,   291,   195,   251,   290,   221,   222,   223,
     289,   224,   289,   214,   385,   464,   291,   194,   260,   257,
     323,   397,   195,   215,   108,  -188,   340,   269,   280,   280,
      66,   192,  -188,   144,   193,   323,   193,   272,   108,   318,
      61,   171,   195,    61,   290,   355,   290,   362,   119,   192,
     227,   282,   213,  -187,   291,   194,   291,   194,   323,   121,
    -187,   195,   312,   438,   215,   215,   424,   283,   426,   192,
     181,   284,   249,   225,   195,   130,   131,   286,   428,   227,
     227,   215,   430,   227,   313,  -186,   252,   296,   192,   278,
     316,   273,  -186,   132,   315,   328,   265,   133,   134,   135,
     136,   192,   195,   400,   288,   324,     2,   188,   189,   280,
     280,   280,   336,   323,   195,   193,   337,   119,   373,   456,
     329,   296,   193,   215,   235,   293,   108,   346,   121,   192,
     278,   278,   299,   338,   195,   339,   194,   119,   193,   344,
     349,   192,   220,   194,   319,   131,   366,   467,   121,    10,
     190,   376,   340,   454,   191,   455,   323,   389,   323,   194,
     388,   192,   132,   394,   325,   131,   133,   134,   135,   136,
     395,   396,   195,   409,   195,   416,   410,   418,   417,   221,
     222,   223,   132,   224,   429,   323,   289,   280,   135,   136,
     340,   433,   214,     2,   188,   189,     2,   214,   400,   192,
     442,   192,   356,   384,   358,   280,    66,   215,   274,   462,
     468,   278,   278,   278,   263,   264,   106,   258,   270,   245,
     290,   445,   110,    93,   419,   391,   227,   300,   386,   459,
     291,    20,    21,   382,    22,   432,    10,   190,   289,    10,
     275,   191,   276,   463,     0,    91,   280,    24,    25,    26,
      27,     0,    29,   195,     0,   453,    25,    26,   109,   104,
     195,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,   290,     9,     0,     0,   195,     0,     0,     0,
     192,     0,   291,   420,     0,     0,     0,   192,     0,   278,
     425,     0,     0,     0,   301,     0,     0,   302,   303,     2,
     214,     0,     0,   192,     0,     0,   431,   278,    10,    11,
     215,   216,     0,    12,     0,   105,    13,     0,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     217,    17,     0,     0,    18,    19,    20,    21,     0,    22,
       0,   218,    10,     0,     0,     0,    23,   219,   278,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,   220,
       0,     0,     0,     0,    31,    32,     0,     0,    33,    34,
      35,    36,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   221,   222,   223,     0,
     224,     0,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   130,   131,     0,     0,     0,    10,    11,     0,     0,
       0,    12,     0,   243,    13,     0,    14,    15,     0,   132,
       0,     0,    16,   133,   134,   135,   136,     0,   137,    17,
       0,     0,     0,    19,    20,    21,     0,    22,     0,   145,
     146,   147,   148,     0,    23,     2,   214,     0,     0,     0,
      24,    25,    26,    27,    28,    29,   215,   274,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,   119,     0,     0,     0,    10,   275,
       0,   276,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
       0,   130,   131,     0,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,     0,     0,   132,
      16,     0,     0,   133,   134,   135,   136,    17,   137,   138,
       0,    19,    20,    21,     0,    22,     0,   145,   146,   147,
     148,     0,    23,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
      31,    32,     0,     0,    33,    34,    35,    36,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,    10,    11,     0,     0,     0,    12,     0,     0,
      13,     0,    14,    15,     0,    66,     0,   132,    16,   164,
       0,   133,   134,   135,   136,    17,   137,   138,    18,    19,
      20,    21,     0,    22,     0,     0,     0,   139,     0,     0,
      23,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,    31,    32,
       0,     0,    33,    34,    35,    36,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     2,   188,   189,     0,     0,     0,     0,    59,
      10,    11,    60,   215,     0,    12,     0,     0,    13,     0,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,    10,    11,   317,    66,     0,    12,    19,     0,    13,
       0,    14,    15,     0,     0,    10,   190,    16,     0,     0,
     191,     0,     0,     0,     0,    25,    26,    27,    19,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,    35,    36,     0,     0,    25,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
       0,    33,    34,    35,    36,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,    12,   247,     0,    13,     0,    14,
      15,     0,     0,     0,     0,    16,     0,     0,     0,     0,
      10,    11,   287,     0,     0,    12,    19,     0,    13,     0,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    19,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,     0,    33,
      34,    35,    36,     0,     0,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,    35,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   119,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,    10,    11,
       0,     0,     0,    12,     0,     0,    13,     0,    14,    15,
       0,   132,     0,     0,    16,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,    19,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,   119,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,   121,    33,    34,
      35,    36,     0,     0,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,   132,     0,   119,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   139,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,   132,     0,
     119,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,   132,     0,   119,     0,   133,
     134,   135,   136,     0,   137,   138,     0,     0,   121,     0,
       0,     0,     0,     0,     0,   139,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   292,   119,     0,   133,   134,   135,   136,
       0,   137,   138,     0,     0,   121,     0,     0,     0,     0,
       0,     0,   139,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,   132,
       0,   119,     0,   133,   134,   135,   136,     0,   137,   138,
       0,     0,   121,     0,     0,     0,     0,     0,     0,   139,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   411,   119,     0,
     133,   134,   135,   136,     0,   137,   138,     0,     0,   121,
       0,     0,     0,     0,     0,     0,   139,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,     0,     0,   132,     0,   119,     0,   133,   134,   135,
     136,     0,   137,   138,     0,     0,   121,     0,     0,     0,
       0,     0,     0,   139,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,     0,   119,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,   121,     0,     0,   119,     0,     0,     0,
     139,   122,   123,   124,   125,   126,   127,   121,     0,   130,
     131,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127,     0,     0,   130,   131,     0,     0,   132,     0,     0,
       0,   133,   134,   135,   136,     0,   137,   138,     0,     0,
       0,   132,     0,     0,     0,   133,   134,   135,   136
  };

  const short
  parser::yycheck_[] =
  {
       0,    39,   179,   140,     0,    12,   310,     6,     0,   218,
      80,   221,    12,    11,    14,    15,    16,   114,    66,   116,
      20,   367,    22,   278,    15,     6,     6,     9,    66,    36,
       0,    31,   169,   170,   232,   233,   173,     9,    20,    39,
       6,     7,     7,    39,     5,    21,     6,     7,     0,    15,
      17,    17,    18,     6,     0,    37,    20,    48,    52,    59,
      52,    53,    50,   367,    56,    37,    66,     6,    49,    49,
      66,   417,    54,    54,    49,    82,    52,    10,    11,    86,
      13,    48,    54,    48,    17,    17,    56,    39,   225,    49,
      54,   301,   302,   303,   235,    76,    76,    48,   216,    99,
     298,   310,   150,   102,    70,    70,   113,   398,   226,   400,
      49,    21,   150,   417,    66,    20,    15,    22,    50,   117,
     120,    20,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    50,   132,   133,   134,   135,   136,   137,   138,    49,
      50,    74,   142,    50,   144,   436,    79,   147,   148,    55,
     150,    66,   407,   294,   150,    54,   274,   157,   367,   277,
       6,     7,   160,   163,   164,    64,   166,    21,   168,    21,
     311,    17,    18,   371,   372,   108,   121,   318,   111,   316,
     180,   114,   115,   116,   117,   118,   283,   397,   103,   286,
     105,    37,   190,    51,   139,    49,    50,   121,   150,    21,
      52,    73,   379,    49,    50,    54,    52,   140,   417,   346,
      68,   144,   164,    48,   159,   139,   414,   415,   416,    15,
     418,   362,   260,   223,    96,    51,    48,   160,   438,   347,
     163,    17,   373,   178,   352,   159,   169,   170,   171,    19,
     173,    21,    68,    23,    15,    79,   191,   445,    28,    29,
      30,   258,   259,   260,   178,    15,   256,   190,   140,    48,
      55,   398,   399,   400,   260,   335,    37,   191,    48,    20,
      21,   271,    50,    68,   219,    51,   276,    37,    49,    57,
      66,    70,    20,   401,    50,   235,   231,   169,   170,   407,
     290,   173,    68,    49,    50,   219,   296,   179,    50,   436,
      80,    52,    56,    54,   441,    57,   251,   231,    20,    21,
      22,    53,   312,    64,   121,    48,    54,   103,   104,   105,
      20,   107,    20,     7,   324,   443,    64,   251,    81,   329,
     280,    15,   139,    17,    49,    50,   269,    50,   220,   221,
      52,   121,    57,    68,   289,   295,   291,    55,    49,   231,
     283,    52,   159,   286,    54,    55,    54,    55,     9,   139,
     140,    51,   139,    50,    64,   289,    64,   291,   318,    20,
      57,   178,    15,    15,    17,    17,   376,    50,   378,   159,
     387,    51,   159,   316,   191,    36,    37,    50,   388,   169,
     170,    17,   392,   173,    37,    50,   329,    15,   178,   179,
      68,   178,    57,    54,    51,    51,   339,    58,    59,    60,
      61,   191,   219,   346,   191,    48,     6,     7,     8,   301,
     302,   303,    51,   373,   231,   370,    51,     9,   310,   429,
      68,    15,   377,    17,   316,   215,    49,    50,    20,   219,
     220,   221,   219,    53,   251,    68,   370,     9,   393,    51,
      51,   231,    66,   377,   231,    37,    37,   457,    20,    49,
      50,    15,   395,   425,    54,   427,   416,   101,   418,   393,
      21,   251,    54,    51,   251,    37,    58,    59,    60,    61,
      68,    21,   289,    51,   291,   367,    51,   369,    48,   103,
     104,   105,    54,   107,    50,   445,    20,   379,    60,    61,
     433,    50,     7,     6,     7,     8,     6,     7,   441,   289,
      37,   291,   289,    37,   291,   397,    52,    17,    18,    37,
      51,   301,   302,   303,   169,   170,    39,   164,   173,   150,
      54,   413,    47,    28,    37,   339,   316,    37,   329,   433,
      64,    77,    78,   316,    80,   395,    49,    50,    20,    49,
      50,    54,    52,   441,    -1,   335,   438,    93,    94,    95,
      96,    -1,    98,   370,    -1,    37,    94,    95,    96,     0,
     377,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    54,    14,    -1,    -1,   393,    -1,    -1,    -1,
     370,    -1,    64,   370,    -1,    -1,    -1,   377,    -1,   379,
     377,    -1,    -1,    -1,   104,    -1,    -1,   107,   108,     6,
       7,    -1,    -1,   393,    -1,    -1,   393,   397,    49,    50,
      17,    18,    -1,    54,    -1,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      37,    72,    -1,    -1,    75,    76,    77,    78,    -1,    80,
      -1,    48,    49,    -1,    -1,    -1,    87,    54,   438,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    66,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,   103,   104,   105,    -1,
     107,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,    54,
      -1,    -1,    65,    58,    59,    60,    61,    -1,    63,    72,
      -1,    -1,    -1,    76,    77,    78,    -1,    80,    -1,    82,
      83,    84,    85,    -1,    87,     6,     7,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    17,    18,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    49,    50,
      -1,    52,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,    54,
      65,    -1,    -1,    58,    59,    60,    61,    72,    63,    64,
      -1,    76,    77,    78,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    52,    -1,    54,    65,    56,
      -1,    58,    59,    60,    61,    72,    63,    64,    75,    76,
      77,    78,    -1,    80,    -1,    -1,    -1,    74,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    17,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    49,    50,    37,    52,    -1,    54,    76,    -1,    57,
      -1,    59,    60,    -1,    -1,    49,    50,    65,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    94,    95,    96,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    54,    76,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,    94,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    54,    -1,    -1,    65,    58,    59,    60,    61,    -1,
      63,    64,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    20,   109,   110,
     111,   112,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    -1,     9,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
       9,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,     9,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,     9,    -1,    58,    59,    60,    61,
      -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      -1,     9,    -1,    58,    59,    60,    61,    -1,    63,    64,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,     9,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,     9,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,     9,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    20,    -1,    -1,     9,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    20,    -1,    36,
      37,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    37,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    60,    61
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
     182,   159,    55,   171,   171,   171,    37,    48,    70,   162,
     164,   165,   170,   175,   160,   182,    15,    20,    21,    22,
     123,   124,   161,   160,    37,   182,   150,   140,    21,   101,
     139,   144,    21,    48,    51,    68,    21,    15,    18,    70,
     131,   132,   167,   168,   169,   174,   174,    53,   174,    51,
      51,    55,   160,   162,   165,   170,   175,    48,   175,    37,
     188,   159,   159,   160,   182,   188,   182,   172,   182,    50,
     182,   188,   155,    50,   171,   168,   132,   168,    15,   174,
      51,    68,    37,   166,   174,   175,   159,   159,   159,   162,
     165,   170,   159,    37,   123,   123,   182,    15,   154,   152,
     168,   171,    37,   169,   174,   159,    51,   182,    51
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
     170,   170,   170,   170,   170,   170,   170,   171,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   177,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     179,   180,   180,   181,   181,   181,   181,   181,   181,   181,
     182,   182,   182,   182,   182,   183,   183,   184,   184,   184,
     185,   185,   186,   186,   186,   186,   187,   187,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188
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
       2,     3,     3,     3,     2,     2,     1,     1,     2,     1,
       1,     3,     2,     2,     3,     2,     4,     5,     1,     2,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     4,     3,     4,     2,     2,     2,     2,     2,
       5,     2,     2,     3,     3,     3,     3,     3,     3,     3,
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
       0,   355,   355,   356,   360,   362,   364,   381,   383,   384,
     386,   391,   393,   402,   404,   409,   410,   415,   417,   422,
     423,   428,   430,   432,   437,   439,   440,   442,   448,   451,
     462,   467,   469,   471,   473,   475,   477,   479,   489,   494,
     496,   501,   502,   506,   508,   516,   518,   520,   527,   529,
     533,   534,   536,   538,   540,   542,   547,   555,   570,   572,
     574,   580,   581,   585,   586,   590,   592,   597,   599,   604,
     622,   624,   636,   637,   639,   646,   651,   652,   656,   658,
     663,   669,   671,   694,   700,   717,   719,   725,   726,   730,
     732,   737,   739,   744,   746,   752,   753,   757,   759,   764,
     765,   769,   771,   778,   779,   783,   785,   790,   791,   795,
     796,   800,   801,   802,   803,   808,   812,   818,   820,   827,
     833,   839,   841,   843,   845,   848,   850,   855,   857,   859,
     867,   872,   877,   882,   887,   894,   895,   899,   901,   905,
     907,   912,   917,   921,   923,   927,   929,   939,   944,   946,
     952,   954,   957,   959,   963,   966,   972,   975,   988,   991,
     996,   997,   998,   999,  1000,  1001,  1002,  1006,  1007,  1008,
    1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,  1033,
    1038,  1040,  1044,  1046,  1052,  1054,  1059,  1061,  1063,  1068,
    1070,  1072,  1074,  1076,  1078,  1080,  1082,  1084,  1086,  1087,
    1089,  1095,  1106,  1108,  1110,  1112,  1114,  1121,  1128,  1130,
    1144,  1146,  1148,  1151,  1153,  1157,  1159,  1163,  1165,  1167,
    1169,  1171,  1173,  1175,  1178,  1182,  1185,  1188,  1190,  1202,
    1222,  1235,  1239,  1246,  1248,  1250,  1255,  1257,  1259,  1264,
    1269,  1270,  1271,  1272,  1273,  1278,  1280,  1285,  1292,  1300,
    1311,  1313,  1318,  1320,  1326,  1331,  1339,  1341,  1381,  1383,
    1385,  1387,  1388,  1390,  1392,  1393,  1395,  1397
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
#line 6049 "annium.tab.cpp"

#line 1592 "annium.y"

