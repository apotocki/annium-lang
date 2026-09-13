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

      case symbol_kind::S_144_case_decl: // case-decl
        value.copy< enum_case > (YY_MOVE (that.value));
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
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.copy< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
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

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< enum_case > (YY_MOVE (s.value));
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
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<enum_case> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
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

      case symbol_kind::S_144_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< enum_case > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
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

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< enum_case > (YY_MOVE (that.value));
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
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
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

      case symbol_kind::S_144_case_decl: // case-decl
        value.copy< enum_case > (that.value);
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
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (that.value);
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.copy< std::vector<enum_case> > (that.value);
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
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

      case symbol_kind::S_144_case_decl: // case-decl
        value.move< enum_case > (that.value);
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
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (that.value);
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        value.move< std::vector<enum_case> > (that.value);
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        value.move< std::vector<field> > (that.value);
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

      case symbol_kind::S_144_case_decl: // case-decl
        yylhs.value.emplace< enum_case > ();
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
        yylhs.value.emplace< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ();
        break;

      case symbol_kind::S_142_case_list_opt: // case-list-opt
      case symbol_kind::S_143_case_list: // case-list
        yylhs.value.emplace< std::vector<enum_case> > ();
        break;

      case symbol_kind::S_152_field_list_opt: // field-list-opt
      case symbol_kind::S_153_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
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
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<enum_case>(yystack_[1].value.as < std::vector<enum_case> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3659 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 652 "annium.y"
             { yylhs.value.as < std::vector<enum_case> > () = {}; }
#line 3665 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 653 "annium.y"
      { yylhs.value.as < std::vector<enum_case> > () = yystack_[0].value.as < std::vector<enum_case> > (); }
#line 3671 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 658 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::vector<enum_case>{ std::move(yystack_[0].value.as < enum_case > ()) }; }
#line 3677 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 660 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::move(yystack_[2].value.as < std::vector<enum_case> > ()); yylhs.value.as < std::vector<enum_case> > ().emplace_back(std::move(yystack_[0].value.as < enum_case > ())); }
#line 3683 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 665 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[0].value.as < annotated_identifier > ().value }; }
#line 3689 "annium.tab.cpp"
    break;

  case 81: // case-decl: identifier "`(`" field-list-opt "`)`"
#line 667 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[3].value.as < annotated_identifier > ().value, .fields = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3695 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 673 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3701 "annium.tab.cpp"
    break;

  case 83: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 675 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3707 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`=>`" syntax-expression
#line 698 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3717 "annium.tab.cpp"
    break;

  case 85: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 704 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3728 "annium.tab.cpp"
    break;

  case 86: // expression-list: syntax-expression
#line 721 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3734 "annium.tab.cpp"
    break;

  case 87: // expression-list: expression-list "," syntax-expression
#line 723 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3740 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: %empty
#line 728 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3746 "annium.tab.cpp"
    break;

  case 89: // argument-list-opt: argument-list
#line 729 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3752 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument
#line 734 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3758 "annium.tab.cpp"
    break;

  case 91: // argument-list: argument-list "," argument
#line 736 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3764 "annium.tab.cpp"
    break;

  case 92: // argument: argument-name syntax-expression
#line 741 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3770 "annium.tab.cpp"
    break;

  case 93: // argument: syntax-expression
#line 743 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3776 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`=`"
#line 748 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3782 "annium.tab.cpp"
    break;

  case 95: // argument-name: identifier "`:`"
#line 750 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3788 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: %empty
#line 755 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3794 "annium.tab.cpp"
    break;

  case 97: // field-list-opt: field-list
#line 756 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3800 "annium.tab.cpp"
    break;

  case 98: // field-list: field
#line 761 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3806 "annium.tab.cpp"
    break;

  case 99: // field-list: field-list "," field
#line 763 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3812 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: %empty
#line 767 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3818 "annium.tab.cpp"
    break;

  case 101: // field-default-value-opt: "`=`" syntax-expression
#line 768 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3824 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`:`" type-expr field-default-value-opt
#line 773 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3830 "annium.tab.cpp"
    break;

  case 103: // field: identifier "`=>`" syntax-expression
#line 775 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3836 "annium.tab.cpp"
    break;

  case 104: // field: type-expr field-default-value-opt
#line 780 "annium.y"
        { yylhs.value.as < field > () = field{ .name = annotated_identifier{}, .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3842 "annium.tab.cpp"
    break;

  case 105: // parameter-list-opt: %empty
#line 786 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3848 "annium.tab.cpp"
    break;

  case 106: // parameter-list-opt: parameter-list
#line 787 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3854 "annium.tab.cpp"
    break;

  case 107: // parameter-list: parameter-decl
#line 792 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3860 "annium.tab.cpp"
    break;

  case 108: // parameter-list: parameter-list "," parameter-decl
#line 794 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3866 "annium.tab.cpp"
    break;

  case 109: // internal-identifier-opt: %empty
#line 798 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3872 "annium.tab.cpp"
    break;

  case 110: // internal-identifier-opt: internal-identifier
#line 799 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3878 "annium.tab.cpp"
    break;

  case 111: // parameter-default-value-opt: %empty
#line 803 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3884 "annium.tab.cpp"
    break;

  case 112: // parameter-default-value-opt: "`=`" syntax-expression
#line 804 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3890 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: %empty
#line 808 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 3896 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`"
#line 809 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 3902 "annium.tab.cpp"
    break;

  case 115: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 810 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3908 "annium.tab.cpp"
    break;

  case 116: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 811 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3914 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 817 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3920 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 821 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3926 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 827 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3932 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 829 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3942 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 836 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3951 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 842 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 3961 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 848 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 3967 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 850 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3973 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 852 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3979 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 854 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3985 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 857 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 3991 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 859 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4000 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 864 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4006 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 866 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4012 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: pattern-mod parameter-default-value-opt
#line 868 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4018 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 876 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4027 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 881 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4036 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 886 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4045 "annium.tab.cpp"
    break;

  case 135: // parameter-decl: "`...`" parameter-default-value-opt
#line 891 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4051 "annium.tab.cpp"
    break;

  case 136: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 896 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4057 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified-mod: "constexpr modifier"
#line 902 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4063 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified-mod: "runctime modifier"
#line 903 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4069 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 908 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4075 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 910 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4081 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-specified: constraint-expression-specified-mod
#line 914 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4087 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 916 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4093 "annium.tab.cpp"
    break;

  case 143: // constraint-expression-mod: %empty
#line 921 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4102 "annium.tab.cpp"
    break;

  case 144: // constraint-expression-mod: constraint-expression-specified-mod
#line 925 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4108 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod type-expr
#line 930 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4114 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 932 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4120 "annium.tab.cpp"
    break;

  case 147: // constraint-expression: constraint-expression-mod
#line 936 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4126 "annium.tab.cpp"
    break;

  case 148: // constraint-expression: constraint-expression-mod "`...`"
#line 938 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4132 "annium.tab.cpp"
    break;

  case 149: // subpatterns: "`(`" pattern-list "`)`"
#line 948 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4138 "annium.tab.cpp"
    break;

  case 150: // pattern-list: pattern-field
#line 953 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4144 "annium.tab.cpp"
    break;

  case 151: // pattern-list: pattern-list "," pattern-field
#line 955 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4150 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: concept-expression-list-opt
#line 961 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4156 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 963 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4162 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 966 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4168 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 968 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4174 "annium.tab.cpp"
    break;

  case 156: // pattern-field-sfx: "`=`" pattern-sfx
#line 972 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4180 "annium.tab.cpp"
    break;

  case 157: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 975 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4186 "annium.tab.cpp"
    break;

  case 158: // pattern-field: identifier pattern-field-sfx
#line 981 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4192 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 984 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4198 "annium.tab.cpp"
    break;

  case 160: // pattern-field: pattern-field-sfx
#line 997 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4204 "annium.tab.cpp"
    break;

  case 161: // pattern-field: "`_`" pattern-field-sfx
#line 1000 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4210 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" pattern-sfx
#line 1004 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type, static_cast<syntax_expression const*>(nullptr) }; }
#line 4216 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 1005 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4222 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 1006 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4228 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "`~`" "reference modifier" pattern-sfx
#line 1007 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4234 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "`~`" "reference modifier" "`(`" syntax-expression "`)`" pattern-sfx
#line 1014 "annium.y"
        { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4240 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "consteval modifier" syntax-expression
#line 1015 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4246 "annium.tab.cpp"
    break;

  case 168: // pattern-mod: "typename modifier" pattern-sfx
#line 1016 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4252 "annium.tab.cpp"
    break;

  case 169: // pattern-mod: "typename modifier"
#line 1017 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; }
#line 4258 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: pattern
#line 1021 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4264 "annium.tab.cpp"
    break;

  case 171: // pattern-sfx: pattern "`...`"
#line 1022 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4270 "annium.tab.cpp"
    break;

  case 172: // pattern-sfx: "`...`"
#line 1023 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4276 "annium.tab.cpp"
    break;

  case 173: // pattern: qname
#line 1028 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4282 "annium.tab.cpp"
    break;

  case 174: // pattern: qname subpatterns concept-expression-list-opt
#line 1030 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4288 "annium.tab.cpp"
    break;

  case 175: // pattern: internal-identifier concept-expression-list-opt
#line 1032 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4294 "annium.tab.cpp"
    break;

  case 176: // pattern: "`_`" concept-expression-list-opt
#line 1034 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4300 "annium.tab.cpp"
    break;

  case 177: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1036 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4306 "annium.tab.cpp"
    break;

  case 178: // pattern: "`(`" "`)`"
#line 1038 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4312 "annium.tab.cpp"
    break;

  case 179: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1040 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4318 "annium.tab.cpp"
    break;

  case 180: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1042 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4324 "annium.tab.cpp"
    break;

  case 181: // pattern: concept-expression-list
#line 1044 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4330 "annium.tab.cpp"
    break;

  case 182: // concept-expression: "`@`" qname
#line 1049 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4336 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list-opt: %empty
#line 1054 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4342 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list-opt: concept-expression-list
#line 1055 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4348 "annium.tab.cpp"
    break;

  case 185: // concept-expression-list: concept-expression
#line 1060 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4354 "annium.tab.cpp"
    break;

  case 186: // concept-expression-list: concept-expression-list concept-expression
#line 1062 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4360 "annium.tab.cpp"
    break;

  case 187: // reference-expression: CONTEXT_IDENTIFIER
#line 1068 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4366 "annium.tab.cpp"
    break;

  case 188: // reference-expression: qname
#line 1070 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4372 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: RESERVED_IDENTIFIER
#line 1075 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4378 "annium.tab.cpp"
    break;

  case 190: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1077 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4384 "annium.tab.cpp"
    break;

  case 191: // any-reference-expression: qname
#line 1079 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4390 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "nil"
#line 1084 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4396 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: "true"
#line 1086 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4402 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: "false"
#line 1088 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4408 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: INTEGER
#line 1090 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4414 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: DECIMAL
#line 1092 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4420 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: DECIMAL_S
#line 1094 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4426 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: INTEGER_INDEX
#line 1096 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4432 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: STRING
#line 1098 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4438 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: CT_IDENTIFIER
#line 1100 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4444 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: any-reference-expression
#line 1101 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4450 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`(`" "`)`"
#line 1103 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4456 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1105 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4465 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1111 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4477 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1122 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4483 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1124 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4489 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1126 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4495 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: PROBE braced-statements
#line 1128 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4501 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`.`" identifier
#line 1130 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4507 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1137 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4517 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`-`" syntax-expression
#line 1144 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4523 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1146 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4529 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1160 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4535 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: "`!`" syntax-expression
#line 1162 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4541 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: "`*`" syntax-expression
#line 1164 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4547 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1167 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4553 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1169 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4559 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1173 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4565 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1175 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4571 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1179 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4577 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1181 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4583 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1183 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4589 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1185 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4595 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1187 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4601 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1189 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4607 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1191 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4613 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1194 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4619 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1198 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4625 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1201 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4631 "annium.tab.cpp"
    break;

  case 230: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1204 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4637 "annium.tab.cpp"
    break;

  case 231: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1206 "annium.y"
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
#line 4652 "annium.tab.cpp"
    break;

  case 232: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1218 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4658 "annium.tab.cpp"
    break;

  case 233: // grouped-expression: "`(`" pack-expression "`)`"
#line 1238 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4671 "annium.tab.cpp"
    break;

  case 234: // new-expression: "`new`" qname
#line 1251 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4677 "annium.tab.cpp"
    break;

  case 235: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1255 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4683 "annium.tab.cpp"
    break;

  case 236: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1262 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4689 "annium.tab.cpp"
    break;

  case 237: // call-expression: any-reference-expression "`.`" identifier
#line 1264 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4695 "annium.tab.cpp"
    break;

  case 238: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1266 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4704 "annium.tab.cpp"
    break;

  case 239: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1271 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4710 "annium.tab.cpp"
    break;

  case 240: // call-expression: call-expression "`.`" identifier
#line 1273 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4716 "annium.tab.cpp"
    break;

  case 241: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1275 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4725 "annium.tab.cpp"
    break;

  case 242: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1280 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4731 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: syntax-expression-base
#line 1284 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4737 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: new-expression
#line 1285 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4743 "annium.tab.cpp"
    break;

  case 245: // syntax-expression: compound-expression
#line 1286 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4749 "annium.tab.cpp"
    break;

  case 246: // syntax-expression: lambda-expression
#line 1287 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4755 "annium.tab.cpp"
    break;

  case 247: // syntax-expression: grouped-expression
#line 1288 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4761 "annium.tab.cpp"
    break;

  case 248: // lambda-start-decl: fn-prefix-decl
#line 1294 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4767 "annium.tab.cpp"
    break;

  case 249: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1296 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4773 "annium.tab.cpp"
    break;

  case 250: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1301 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4784 "annium.tab.cpp"
    break;

  case 251: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1308 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4796 "annium.tab.cpp"
    break;

  case 252: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1316 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4808 "annium.tab.cpp"
    break;

  case 253: // pack-expression-opt: %empty
#line 1327 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4814 "annium.tab.cpp"
    break;

  case 254: // pack-expression-opt: pack-expression
#line 1329 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4820 "annium.tab.cpp"
    break;

  case 255: // pack-expression: syntax-expression
#line 1334 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4826 "annium.tab.cpp"
    break;

  case 256: // pack-expression: identifier "`:`" syntax-expression
#line 1336 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4836 "annium.tab.cpp"
    break;

  case 257: // pack-expression: pack-expression "," syntax-expression
#line 1342 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4845 "annium.tab.cpp"
    break;

  case 258: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1347 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4854 "annium.tab.cpp"
    break;

  case 259: // compound-expression: syntax-expression "`...`"
#line 1355 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4860 "annium.tab.cpp"
    break;

  case 260: // compound-expression: call-expression
#line 1356 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4866 "annium.tab.cpp"
    break;

  case 261: // type-expr: qname
#line 1397 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4872 "annium.tab.cpp"
    break;

  case 262: // type-expr: RESERVED_IDENTIFIER
#line 1399 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4878 "annium.tab.cpp"
    break;

  case 263: // type-expr: CONTEXT_IDENTIFIER
#line 1401 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4884 "annium.tab.cpp"
    break;

  case 264: // type-expr: call-expression
#line 1402 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4890 "annium.tab.cpp"
    break;

  case 265: // type-expr: "`[`" type-expr "`]`"
#line 1404 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4896 "annium.tab.cpp"
    break;

  case 266: // type-expr: "`(`" "`)`"
#line 1406 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4902 "annium.tab.cpp"
    break;

  case 267: // type-expr: grouped-expression
#line 1407 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4908 "annium.tab.cpp"
    break;

  case 268: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1409 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4914 "annium.tab.cpp"
    break;

  case 269: // type-expr: type-expr "`|`" type-expr
#line 1411 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4920 "annium.tab.cpp"
    break;

  case 270: // type-expr: type-expr "`->`" type-expr
#line 1413 "annium.y"
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
#line 4935 "annium.tab.cpp"
    break;


#line 4939 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -358;

  const short parser::yytable_ninf_ = -192;

  const short
  parser::yypact_[] =
  {
     999,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
     121,  1107,  1128,   121,  1386,  1386,  1386,    16,   138,    24,
    1386,    28,  1386,    24,   137,  -358,  -358,  -358,    34,    24,
      24,  1386,   -11,  -358,  -358,  -358,   219,   240,    25,   672,
    -358,  -358,  -358,  -358,  -358,   235,  -358,   334,     9,    -6,
    -358,   249,  -358,    71,  1474,   293,  -358,   268,  -358,  1386,
    -358,   245,   298,  1897,   264,  -358,   891,   302,   -19,  1897,
    -358,    20,    20,    20,   121,  -358,   305,   343,  -358,   121,
      34,    83,  1009,  -358,   235,   292,  1521,   127,  -358,  -358,
    -358,   235,   322,  -358,   187,  -358,   148,  -358,    20,  1386,
    -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,   121,  -358,
    -358,  1386,   368,    99,  1386,   121,  1386,  1386,   121,  -358,
    1386,   361,  1386,  1386,  1386,  1386,  1386,  1386,  1386,  1386,
    1386,  -358,  1386,  1386,  1386,  1386,  1386,  1386,  1386,   361,
     554,  1568,  1386,  -358,  1386,  -358,  -358,  1386,  1386,   325,
     783,  -358,   349,  -358,  -358,  -358,  -358,  1236,  -358,   361,
    1386,   330,  -358,  1386,  1386,  -358,  1386,   315,  1386,   554,
     554,   121,   353,   554,  1615,  -358,   357,   340,   361,   865,
    1386,  -358,   365,   373,   383,   280,   374,  1897,   142,   188,
    1257,   361,   229,    -6,   249,    71,    -1,   490,   490,   490,
     490,   490,   490,   901,   793,   572,  1662,   104,   104,   134,
     134,   557,  1944,   213,  -358,    24,   420,   423,    65,   361,
     471,   638,  -358,  1386,  -358,    17,   130,    11,   390,   381,
    -358,   377,   423,   423,  -358,   265,  -358,  1897,   402,  1897,
    1897,  1897,  -358,  -358,  -358,  -358,  -358,  -358,  1897,   213,
     340,   361,   101,   407,   392,  -358,  1386,  1897,   219,  1521,
     616,  -358,  1897,   411,   412,   414,   413,   399,  -358,   361,
     417,  1386,  -358,   213,    29,   419,  1386,   420,   263,  -358,
     420,  1897,  -358,  1386,  -358,  -358,  1386,  -358,   243,   361,
    1386,   361,  -358,   235,    18,   420,  1386,  -358,   423,   285,
    -358,   638,   638,   768,  -358,   435,  -358,  1897,  -358,   181,
      33,    18,  1386,   459,  -358,   135,   554,  -358,   265,   246,
    -358,  -358,  -358,  -358,  1386,   213,  -358,  -358,  -358,  1386,
    1897,  -358,  -358,  -358,  -358,    34,   454,   378,   361,  -358,
     121,   153,   431,   416,  -358,    22,   470,    20,   327,   420,
    -358,  -358,  1709,  -358,   420,   441,   443,  -358,    -1,  1756,
      -1,  -358,  1897,  -358,    18,  -358,  -358,  1365,  -358,  -358,
      33,   448,   420,   310,   423,   423,   265,  -358,  1897,  1386,
     361,  1386,   865,  -358,  -358,  -358,  -358,  -358,  1897,  -358,
     219,  1386,   451,  -358,   447,  -358,  1386,   361,  -358,   361,
    1386,  -358,   463,   638,   348,   507,   348,    30,   286,  -358,
    -358,   478,  -358,    29,  -358,  -358,  -358,  -358,  -358,  1803,
     420,   423,   423,   376,   314,   376,  -358,   271,  -358,  -358,
    -358,  1897,     7,  1897,   141,  1897,  1386,  -358,  1897,    22,
    -358,  1897,   361,  -358,  -358,   348,  -358,   638,   481,  -358,
     327,  -358,   420,  -358,   638,   376,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,  -358,  1850,  -358,   468,  -358,
    -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358
  };

  const short
  parser::yydefact_[] =
  {
       4,   199,    56,   190,   189,   198,   195,   196,   197,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    65,     0,     0,
       0,     0,     0,   192,   193,   194,     0,     0,     0,     0,
       5,     7,    49,    13,    59,   191,    63,     0,   248,   201,
     243,   247,   244,   260,     0,     0,   246,   245,    58,     0,
     202,    59,   248,   255,     0,   245,    21,     0,     0,    86,
     209,   211,   215,   214,     0,    45,    19,    15,    17,     0,
       0,   234,     0,   187,   188,     0,     0,     0,    48,    31,
      68,    67,     0,    46,     0,    38,     0,    14,   212,     0,
     208,     1,     2,    10,     3,     8,     6,     9,     0,    66,
      64,   253,    72,     0,   253,     0,   253,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,   233,     0,    52,    51,    53,     0,    41,
      42,    24,     0,    50,    22,   206,   204,     0,    18,     0,
       0,     0,    12,    88,     0,    32,     0,    35,     0,   105,
     105,    76,     0,   105,     0,    60,     0,   254,     0,     0,
       0,    37,     0,   237,     0,     0,   240,    44,   263,   262,
       0,     0,   261,     0,   267,   264,   231,   220,   221,   222,
     223,   224,   225,   229,   230,   226,     0,   218,   219,   216,
     217,   227,   228,   232,    57,     0,   183,   111,     0,     0,
       0,   169,   137,     0,   138,    59,   183,   113,     0,   106,
     107,   141,   111,   111,   185,   113,   203,   256,    59,   257,
      54,    55,    27,    25,    26,    23,    30,   205,    87,    20,
      16,     0,    59,     0,    89,    90,     0,    93,     0,     0,
       0,    36,    84,     0,     0,    80,     0,    77,    78,    96,
       0,     0,   249,    73,   183,     0,     0,   183,   173,    74,
     181,    47,   236,   253,   242,   239,   253,   266,     0,     0,
       0,     0,   207,   182,   113,   184,     0,   135,   111,     0,
     172,     0,     0,     0,   162,   170,   168,   167,   110,     0,
     143,   113,     0,   114,   122,     0,     0,   142,   113,   139,
     119,   131,   134,   186,     0,    11,    94,    95,   235,     0,
      92,    33,    34,    39,    40,     0,     0,    70,    96,    75,
       0,    59,     0,    97,    98,   100,     0,   213,   183,   183,
     176,   178,     0,   175,   183,     0,     0,   265,   270,     0,
     269,   133,   112,   130,   113,   163,   164,     0,   165,   171,
     143,     0,   144,   147,   111,   111,   113,   132,   115,     0,
       0,     0,     0,   250,    28,   108,   121,   140,   258,    91,
       0,     0,     0,    69,     0,    79,     0,     0,    82,     0,
       0,   104,     0,     0,   183,     0,   183,   183,     0,   160,
     150,   152,   177,   183,   174,   238,   241,   268,   120,     0,
     144,   111,   111,   111,   143,   111,   148,   145,   118,   127,
     128,   116,     0,    29,     0,    85,     0,    81,   103,   100,
      99,   101,    96,   156,   161,   183,   158,     0,   154,   149,
     183,   153,   183,   179,     0,   111,   117,   123,   124,   144,
     136,   126,   129,   146,   251,   252,     0,   102,     0,   159,
     157,   155,   151,   180,   166,   125,    71,    83
  };

  const short
  parser::yypgoto_[] =
  {
    -358,  -358,  -358,  -358,   483,  -358,  -358,  -358,  -358,  -358,
      19,    -4,   -28,  -358,  -358,   360,   -62,   379,   -10,    50,
     266,   484,  -358,     2,  -358,   504,  -358,   -74,  -358,  -358,
    -358,   193,  -358,  -358,  -358,  -358,  -358,   205,  -358,  -317,
    -358,    97,   139,   273,  -358,  -358,   -48,   -53,   221,  -298,
    -358,  -358,  -357,  -268,  -358,  -352,    89,  -198,  -212,  -161,
    -151,  -160,   333,  -358,   110,  -358,   131,  -358,   274,    80,
    -358,  -358,  -100,     6,    31,  -116
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    75,    76,    77,   149,   150,
     383,   384,    41,   261,   152,    42,    43,   154,    44,   277,
      45,    46,    47,    62,    92,   112,   393,   113,    95,   266,
     267,   268,    97,    88,    68,   253,   254,   255,   256,   342,
     343,   401,   344,   228,   229,   309,   297,   314,   230,   231,
     232,   373,   374,   349,   408,   409,   410,   233,   304,   305,
     234,   411,   295,    85,    49,    50,    51,    52,    53,    63,
      55,    56,   176,   177,    65,   345
  };

  const short
  parser::yytable_[] =
  {
      58,    61,    48,    70,   153,   196,   162,    78,    67,   306,
     354,   107,   372,   421,   182,     2,   184,    64,   279,   289,
     298,   394,     2,   213,   214,   102,   312,   289,   381,   119,
       2,    57,   100,   312,     2,    83,   156,   400,   151,    99,
       2,    48,   289,   249,   114,   447,   215,   215,   313,   157,
     215,   115,   444,   290,   446,   313,   294,   131,    10,    66,
     108,   290,   273,   111,   158,  -109,   311,   460,    48,   161,
      57,   291,   420,    10,   132,   288,   290,    10,   165,   348,
      54,   103,   167,    10,   323,    90,   291,  -109,   153,   365,
     366,   368,    69,   469,    71,    72,    73,    57,   175,   220,
      82,    61,    86,   299,    61,   183,    61,    61,   186,   181,
      90,    98,   375,   119,   350,   319,   326,   353,    74,    54,
     180,   117,   244,   185,   121,   468,   459,     2,   118,   323,
     225,   220,   108,   163,   238,   325,   221,   222,   223,   141,
     224,   131,    89,   119,   323,   452,    54,   215,   168,   327,
      61,    66,    48,   252,   121,   380,   381,   382,   132,   225,
     225,   265,   381,   225,   135,   136,   250,   323,   221,   172,
     223,   131,   422,   358,   396,   360,   108,   169,   310,   174,
      61,    57,   322,   355,   320,   321,   356,    66,   132,   412,
     226,   443,  -190,    66,   414,    57,    64,   108,   173,  -190,
     187,   397,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    79,   206,   207,   208,   209,   210,   211,   212,   226,
     226,   434,   237,   226,   239,   323,   461,   240,   241,   370,
      54,   193,   334,   289,    80,   470,   108,   248,  -189,   171,
     101,   361,   474,   257,    54,  -189,   259,   448,   262,   193,
     363,   371,   194,   453,   331,   332,   333,   427,   377,   341,
     281,   390,   335,   289,   432,   386,   289,   290,   -43,   193,
     194,    66,   323,    61,   323,   308,    61,   291,   108,  -191,
     312,   439,   215,   387,   108,    81,  -191,    84,   193,    87,
     194,   289,   473,   142,    91,    94,    96,   290,   357,   116,
     290,   193,   313,   307,   323,   289,   225,   291,   463,   194,
     291,   418,   108,   348,    91,   143,     2,   188,   189,   252,
     -43,   -43,   194,   430,   -43,   290,   428,   429,   341,   193,
     265,   285,   144,     2,   214,   291,   330,   449,   406,   290,
     364,   193,   403,   140,   215,   404,    91,   426,   144,   291,
     194,   347,   111,   159,   450,   214,   352,   155,   160,    10,
     190,   193,   194,   403,   191,   215,   226,     2,   188,   189,
     359,   166,   170,   456,   457,   458,   362,   462,   251,   193,
     220,   242,   194,     2,   188,   189,   181,   192,   178,   341,
     179,   296,   378,   215,   215,   195,   260,   405,   407,   193,
     194,   193,   246,   269,   388,   192,   227,   475,   144,   257,
      10,   190,   272,   195,   317,   191,   282,   221,   222,   223,
     194,   224,   194,   283,   286,   192,    10,   190,    25,    26,
     109,   191,   341,   195,   284,   227,   227,   215,   296,   227,
     406,   315,   263,   264,   192,   278,   270,   419,   193,   316,
     324,   464,   195,   465,   407,   445,   407,   192,   328,   431,
     329,   433,   336,   337,   338,   195,   339,   340,   346,   194,
     351,   435,   369,   235,   379,   391,   438,     2,   214,   392,
     441,   293,   398,   193,   399,   192,   278,   278,   215,   274,
     193,   402,   415,   195,   416,   407,   424,   192,   437,   119,
     407,   436,   235,   235,   194,   195,   235,   193,   300,   193,
     121,   194,   280,   442,   214,   451,   466,   192,   471,   477,
      10,   275,   106,   276,   258,   195,   130,   131,   194,   245,
     194,   110,    93,   395,   389,   192,   467,   385,   440,   472,
       0,     0,     0,   195,   132,     0,     0,     0,   133,   134,
     135,   136,   193,   280,   280,   192,     0,   192,     0,     0,
       2,   214,     0,   195,   318,   195,   119,   278,   278,   278,
       0,   215,   216,   194,     0,   301,     0,   121,   302,   303,
       0,   119,   227,     0,     0,   122,   123,   124,   125,   126,
     127,   217,   121,   130,   131,     0,     0,     0,     0,     0,
       0,    91,   218,    10,   192,     0,     0,     0,   219,   131,
       0,   132,   195,     0,     0,   133,   134,   135,   136,     0,
     220,     0,     0,     0,     0,     0,   132,     0,     0,     0,
     133,   134,   135,   136,   280,   280,   280,     0,     0,   192,
       0,     0,     0,   376,     2,   214,   192,   195,   278,   235,
       0,     0,     0,     0,   195,   215,   274,   221,   222,   223,
       0,   224,     0,   192,     0,   192,     0,     0,    66,   278,
       0,   195,   104,   195,     0,   300,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,    10,   275,     0,
     276,     0,     0,    20,    21,     0,    22,     0,     0,     0,
       0,     0,     0,   423,     0,   425,     0,     0,   192,    24,
      25,    26,    27,   278,    29,   280,   195,     0,     0,     0,
     278,    10,    11,     0,     0,     0,    12,     0,   105,    13,
       0,    14,    15,     0,     0,     0,   280,    16,     0,     0,
       0,     0,     0,     0,    17,     0,     0,    18,    19,    20,
      21,     0,    22,   455,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     2,   214,     0,    31,    32,     0,
     280,    33,    34,    35,    36,   215,   274,   280,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,   119,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,    10,   367,     0,
     276,   122,   123,   124,   125,   126,   127,   128,     0,   130,
     131,     0,    10,    11,     0,     0,     0,    12,     0,   243,
      13,     0,    14,    15,     0,     0,     0,   132,    16,     0,
       0,   133,   134,   135,   136,    17,   137,   138,     0,    19,
      20,    21,     0,    22,     0,   145,   146,   147,   148,     0,
      23,     2,   214,     0,     0,     0,    24,    25,    26,    27,
      28,    29,   215,   274,     0,     0,     0,     0,    31,    32,
       0,     0,    33,    34,    35,    36,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
     119,     0,     0,     0,    10,   275,     0,   276,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,     0,     0,   130,   131,     0,
      10,    11,     0,     0,     0,    12,     0,     0,    13,     0,
      14,    15,     0,     0,     0,   132,    16,     0,     0,   133,
     134,   135,   136,    17,   137,   138,     0,    19,    20,    21,
       0,    22,     0,   145,   146,   147,   148,     0,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,    35,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,    10,    11,
       0,     0,     0,    12,     0,     0,    13,     0,    14,    15,
       0,    66,     0,   132,    16,   164,     0,   133,   134,   135,
     136,    17,   137,   138,    18,    19,    20,    21,     0,    22,
       0,     0,     0,   139,     0,     0,    23,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,    31,    32,     0,     0,    33,    34,
      35,    36,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    10,    11,    60,     0,
       0,    12,     0,     0,    13,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,    10,    11,     0,
      66,     0,    12,    19,     0,    13,     0,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,    19,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,    35,    36,
       0,     0,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,     0,    33,    34,    35,
      36,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
      12,   247,     0,    13,     0,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    10,    11,   287,     0,
       0,    12,    19,     0,    13,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    19,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,     0,    33,    34,    35,    36,     0,
       0,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,   351,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,    10,    11,     0,     0,     0,
      12,    19,     0,    13,     0,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    19,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,     0,    33,    34,    35,    36,     0,     0,
      25,    26,    27,   119,     0,     0,     0,     0,     0,   120,
       0,    31,    32,     0,   121,    33,    34,    35,    36,     0,
       0,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
     119,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,   132,     0,   119,     0,   133,
     134,   135,   136,     0,   137,   138,     0,     0,   121,     0,
       0,     0,     0,     0,     0,   139,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,   132,     0,   119,     0,   133,   134,   135,   136,
       0,   137,   138,     0,     0,   121,     0,     0,     0,     0,
       0,     0,   139,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   132,
       0,   119,     0,   133,   134,   135,   136,     0,   137,   138,
       0,     0,   121,     0,     0,     0,     0,     0,     0,   139,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   292,   119,     0,
     133,   134,   135,   136,     0,   137,   138,     0,     0,   121,
       0,     0,     0,     0,     0,     0,   139,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,   132,     0,   119,     0,   133,   134,   135,
     136,     0,   137,   138,     0,     0,   121,     0,     0,     0,
       0,     0,     0,   139,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   417,   119,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,   121,     0,     0,     0,     0,     0,     0,
     139,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   454,     0,     0,   132,     0,   119,
       0,   133,   134,   135,   136,     0,   137,   138,     0,     0,
     121,     0,     0,     0,     0,     0,     0,   139,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   476,     0,     0,   132,     0,   119,     0,   133,   134,
     135,   136,     0,   137,   138,     0,     0,   121,     0,     0,
       0,     0,     0,     0,   139,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,     0,   119,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   139,   122,   123,   124,   125,   126,   127,     0,     0,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,   133,   134,   135,   136,     0,   137
  };

  const short
  parser::yycheck_[] =
  {
      10,    11,     0,    13,    66,   121,    80,    17,    12,   221,
     278,    39,   310,   370,   114,     6,   116,    11,   179,    20,
     218,   338,     6,   139,     7,     0,    15,    20,    21,     9,
       6,     0,    36,    15,     6,     7,    55,    15,    66,    50,
       6,    39,    20,   159,    50,    15,    17,    17,    37,    68,
      17,    57,   404,    54,   406,    37,   216,    37,    49,    52,
      49,    54,   178,    54,    74,    48,   226,   424,    66,    79,
      39,    64,   370,    49,    54,   191,    54,    49,    82,    50,
       0,    56,    86,    49,   235,    76,    64,    70,   150,   301,
     302,   303,    12,   445,    14,    15,    16,    66,   108,    66,
      20,   111,    22,   219,   114,   115,   116,   117,   118,   113,
      76,    31,   310,     9,   274,   231,    15,   277,   102,    39,
      21,    50,   150,   117,    20,   442,   424,     6,    57,   280,
     140,    66,    49,    50,   144,   251,   103,   104,   105,    59,
     107,    37,     5,     9,   295,   413,    66,    17,    21,    48,
     160,    52,   150,   163,    20,    20,    21,    22,    54,   169,
     170,   171,    21,   173,    60,    61,   160,   318,   103,    21,
     105,    37,   370,   289,    21,   291,    49,    50,    48,    99,
     190,   150,   235,   283,   232,   233,   286,    52,    54,   349,
     140,   403,    50,    52,   354,   164,   190,    49,    50,    57,
     120,    48,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    73,   132,   133,   134,   135,   136,   137,   138,   169,
     170,   382,   142,   173,   144,   376,   424,   147,   148,    48,
     150,   121,   260,    20,    96,   447,    49,   157,    50,    52,
       0,   294,   454,   163,   164,    57,   166,   407,   168,   139,
     298,    70,   121,   413,   258,   259,   260,   373,   311,   269,
     180,   335,   260,    20,   380,   318,    20,    54,     0,   159,
     139,    52,   423,   283,   425,   225,   286,    64,    49,    50,
      15,   397,    17,    37,    49,    19,    57,    21,   178,    23,
     159,    20,   452,    48,    28,    29,    30,    54,    55,    50,
      54,   191,    37,   223,   455,    20,   316,    64,    37,   178,
      64,   364,    49,    50,    48,    51,     6,     7,     8,   329,
      52,    53,   191,   376,    56,    54,   374,   375,   338,   219,
     340,    51,    68,     6,     7,    64,   256,    51,   348,    54,
      55,   231,    15,    50,    17,    18,    80,    37,    68,    64,
     219,   271,    54,    48,    68,     7,   276,    55,    15,    49,
      50,   251,   231,    15,    54,    17,   316,     6,     7,     8,
     290,    79,    50,   421,   422,   423,   296,   425,    48,   269,
      66,    56,   251,     6,     7,     8,   390,   121,    20,   399,
      22,    15,   312,    17,    17,   121,    81,    70,   348,   289,
     269,   291,    53,    50,   324,   139,   140,   455,    68,   329,
      49,    50,    55,   139,    37,    54,    51,   103,   104,   105,
     289,   107,   291,    50,    50,   159,    49,    50,    94,    95,
      96,    54,   442,   159,    51,   169,   170,    17,    15,   173,
     450,    51,   169,   170,   178,   179,   173,   367,   338,    68,
      48,   432,   178,   434,   404,   405,   406,   191,    51,   379,
      68,   381,    51,    51,    50,   191,    53,    68,    51,   338,
      51,   391,    37,   140,    15,    21,   396,     6,     7,   101,
     400,   215,    51,   373,    68,   219,   220,   221,    17,    18,
     380,    21,    51,   219,    51,   445,    48,   231,    51,     9,
     450,    50,   169,   170,   373,   231,   173,   397,    37,   399,
      20,   380,   179,    50,     7,    37,   436,   251,    37,    51,
      49,    50,    39,    52,   164,   251,    36,    37,   397,   150,
     399,    47,    28,   340,   329,   269,   439,   316,   399,   450,
      -1,    -1,    -1,   269,    54,    -1,    -1,    -1,    58,    59,
      60,    61,   442,   220,   221,   289,    -1,   291,    -1,    -1,
       6,     7,    -1,   289,   231,   291,     9,   301,   302,   303,
      -1,    17,    18,   442,    -1,   104,    -1,    20,   107,   108,
      -1,     9,   316,    -1,    -1,    28,    29,    30,    31,    32,
      33,    37,    20,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,   335,    48,    49,   338,    -1,    -1,    -1,    54,    37,
      -1,    54,   338,    -1,    -1,    58,    59,    60,    61,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    60,    61,   301,   302,   303,    -1,    -1,   373,
      -1,    -1,    -1,   310,     6,     7,   380,   373,   382,   316,
      -1,    -1,    -1,    -1,   380,    17,    18,   103,   104,   105,
      -1,   107,    -1,   397,    -1,   399,    -1,    -1,    52,   403,
      -1,   397,     0,   399,    -1,    37,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    49,    50,    -1,
      52,    -1,    -1,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,   370,    -1,   372,    -1,    -1,   442,    93,
      94,    95,    96,   447,    98,   382,   442,    -1,    -1,    -1,
     454,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,    -1,   403,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    75,    76,    77,
      78,    -1,    80,   420,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,     6,     7,    -1,   105,   106,    -1,
     447,   109,   110,   111,   112,    17,    18,   454,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    49,    50,    -1,
      52,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      57,    -1,    59,    60,    -1,    -1,    -1,    54,    65,    -1,
      -1,    58,    59,    60,    61,    72,    63,    64,    -1,    76,
      77,    78,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      87,     6,     7,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    17,    18,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    54,    65,    -1,    -1,    58,
      59,    60,    61,    72,    63,    64,    -1,    76,    77,    78,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    52,    -1,    54,    65,    56,    -1,    58,    59,    60,
      61,    72,    63,    64,    75,    76,    77,    78,    -1,    80,
      -1,    -1,    -1,    74,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    -1,    54,    76,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
      -1,    -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,
     112,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    55,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    54,    76,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    76,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,    -1,    -1,
      94,    95,    96,     9,    -1,    -1,    -1,    -1,    -1,    15,
      -1,   105,   106,    -1,    20,   109,   110,   111,   112,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
       9,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    -1,     9,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,     9,    -1,    58,    59,    60,    61,
      -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      -1,     9,    -1,    58,    59,    60,    61,    -1,    63,    64,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,     9,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,     9,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,     9,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,     9,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,     9,    -1,    58,    59,
      60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,     9,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    63
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
     182,   124,   124,   124,   125,   136,    51,    51,    50,    53,
      68,   131,   152,   153,   155,   188,    51,   182,    50,   166,
     174,    51,   182,   174,   166,   185,   185,    55,   188,   182,
     188,   160,   182,   159,    55,   171,   171,    50,   171,    37,
      48,    70,   162,   164,   165,   170,   175,   160,   182,    15,
      20,    21,    22,   123,   124,   161,   160,    37,   182,   150,
     140,    21,   101,   139,   152,   144,    21,    48,    51,    68,
      15,   154,    21,    15,    18,    70,   131,   132,   167,   168,
     169,   174,   174,    53,   174,    51,    51,    55,   160,   182,
     162,   165,   170,   175,    48,   175,    37,   188,   159,   159,
     160,   182,   188,   182,   172,   182,    50,    51,   182,   188,
     155,   182,    50,   171,   168,   132,   168,    15,   174,    51,
      68,    37,   166,   174,    51,   175,   159,   159,   159,   162,
     165,   170,   159,    37,   123,   123,   182,   154,   152,   168,
     171,    37,   169,   174,   171,   159,    51,    51
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
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   160,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   162,   163,
     163,   163,   163,   164,   164,   165,   165,   165,   165,   166,
     167,   167,   168,   168,   168,   168,   168,   168,   169,   169,
     169,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     171,   171,   171,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   177,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   179,   180,   180,   181,   181,   181,   181,
     181,   181,   181,   182,   182,   182,   182,   182,   183,   183,
     184,   184,   184,   185,   185,   186,   186,   186,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188
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
       1,     4,     5,     8,     3,     6,     1,     3,     0,     1,
       1,     3,     2,     1,     2,     2,     0,     1,     1,     3,
       0,     2,     4,     3,     2,     0,     1,     1,     3,     0,
       1,     0,     2,     0,     1,     2,     3,     5,     4,     2,
       4,     3,     2,     5,     5,     6,     5,     4,     4,     5,
       3,     2,     3,     3,     2,     2,     5,     1,     1,     2,
       3,     1,     2,     0,     1,     2,     3,     1,     2,     3,
       1,     3,     1,     2,     2,     3,     2,     3,     2,     3,
       1,     2,     2,     3,     3,     3,     6,     2,     2,     1,
       1,     2,     1,     1,     3,     2,     2,     3,     2,     4,
       5,     1,     2,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     4,     3,     4,     2,     2,
       2,     2,     2,     5,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     4,     3,     6,     4,
       3,     6,     4,     1,     1,     1,     1,     1,     1,     4,
       5,     7,     7,     0,     1,     1,     3,     3,     5,     2,
       1,     1,     1,     1,     1,     3,     2,     1,     4,     3,
       3
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
     664,   666,   672,   674,   697,   703,   720,   722,   728,   729,
     733,   735,   740,   742,   747,   749,   755,   756,   760,   762,
     767,   768,   772,   774,   779,   786,   787,   791,   793,   798,
     799,   803,   804,   808,   809,   810,   811,   816,   820,   826,
     828,   835,   841,   847,   849,   851,   853,   856,   858,   863,
     865,   867,   875,   880,   885,   890,   895,   902,   903,   907,
     909,   913,   915,   920,   925,   929,   931,   935,   937,   947,
     952,   954,   960,   962,   965,   967,   971,   974,   980,   983,
     996,   999,  1004,  1005,  1006,  1007,  1013,  1015,  1016,  1017,
    1021,  1022,  1023,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1048,  1053,  1055,  1059,  1061,  1067,  1069,  1074,
    1076,  1078,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1101,  1102,  1104,  1110,  1121,  1123,  1125,  1127,  1129,
    1136,  1143,  1145,  1159,  1161,  1163,  1166,  1168,  1172,  1174,
    1178,  1180,  1182,  1184,  1186,  1188,  1190,  1193,  1197,  1200,
    1203,  1205,  1217,  1237,  1250,  1254,  1261,  1263,  1265,  1270,
    1272,  1274,  1279,  1284,  1285,  1286,  1287,  1288,  1293,  1295,
    1300,  1307,  1315,  1326,  1328,  1333,  1335,  1341,  1346,  1354,
    1356,  1396,  1398,  1400,  1402,  1403,  1405,  1407,  1408,  1410,
    1412
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
#line 6136 "annium.tab.cpp"

#line 1607 "annium.y"

