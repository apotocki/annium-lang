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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.copy< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.copy< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (s.value));
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.YY_MOVE_OR_COPY< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.copy< identifier > (that.value);
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (that.value);
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.copy< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        value.move< identifier > (that.value);
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (that.value);
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        value.move< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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
#line 346 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 346 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 346 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 346 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 346 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 346 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 346 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 346 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 346 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 346 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 346 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 346 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 346 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 346 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 346 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 346 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 346 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 346 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 346 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 346 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 346 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 346 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 346 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 346 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 346 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 346 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 346 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 346 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 346 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 346 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 346 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 346 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 346 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 346 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 346 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 346 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 346 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 346 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 346 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 346 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 346 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 346 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 346 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 346 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 346 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
#line 346 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 346 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 346 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 346 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 346 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 346 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 346 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
#line 346 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 346 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl: // let-decl
#line 346 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start: // let-decl-start
#line 346 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 346 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
#line 346 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
#line 346 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_function_body: // function-body
#line 346 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_braced_statements: // braced-statements
#line 346 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_finished_statement: // finished-statement
#line 346 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_if_else_tail: // if-else-tail
#line 346 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
#line 346 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_expression_statement: // expression-statement
#line 346 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_generic_statement: // generic-statement
#line 346 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_infunction_statement: // infunction-statement
#line 346 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 346 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
#line 346 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 346 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
#line 346 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
#line 346 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
#line 346 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_name: // fn-name
#line 346 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
#line 346 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
#line 346 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_decl: // fn-decl
#line 346 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
#line 346 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
#line 346 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_case_list: // case-list
#line 346 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_decl: // case-decl
#line 346 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
#line 346 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_using_decl: // using-decl
#line 346 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_expression_list: // expression-list
#line 346 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
#line 346 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_list: // argument-list
#line 346 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 346 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_argument_name: // argument-name
#line 346 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_field_list_opt: // field-list-opt
#line 346 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_field_list: // field-list
#line 346 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
#line 346 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 346 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
#line 346 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_list: // parameter-list
#line 346 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
#line 346 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
#line 346 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
#line 346 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_parameter_decl: // parameter-decl
#line 346 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 346 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_constraint_expression_specified: // constraint-expression-specified
#line 346 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_mod: // constraint-expression-mod
#line 346 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression: // constraint-expression
#line 346 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 346 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_list: // pattern-list
#line 346 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_field_sfx: // pattern-field-sfx
#line 346 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_field: // pattern-field
#line 346 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_mod: // pattern-mod
#line 346 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_sfx: // pattern-sfx
#line 346 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 346 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_concept_expression: // concept-expression
#line 346 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_concept_expression_list_opt: // concept-expression-list-opt
#line 346 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression_list: // concept-expression-list
#line 346 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_reference_expression: // reference-expression
#line 346 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_any_reference_expression: // any-reference-expression
#line 346 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_syntax_expression_base: // syntax-expression-base
#line 346 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_grouped_expression: // grouped-expression
#line 346 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_new_expression: // new-expression
#line 346 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_call_expression: // call-expression
#line 346 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_syntax_expression: // syntax-expression
#line 346 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
#line 346 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_lambda_expression: // lambda-expression
#line 346 "annium.y"
                 { }
#line 2641 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_pack_expression_opt: // pack-expression-opt
#line 346 "annium.y"
                 { }
#line 2647 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_pack_expression: // pack-expression
#line 346 "annium.y"
                 { }
#line 2653 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_compound_expression: // compound-expression
#line 346 "annium.y"
                 { }
#line 2659 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_type_expr: // type-expr
#line 346 "annium.y"
                 { }
#line 2665 "annium.tab.cpp"
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

      case symbol_kind::S_136_fn_name: // fn-name
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
      case symbol_kind::S_150_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_131_internal_identifier: // internal-identifier
      case symbol_kind::S_157_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_140_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_153_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_133_fn_kind: // fn-kind
      case symbol_kind::S_134_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_137_fn_start_decl: // fn-start-decl
      case symbol_kind::S_139_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_143_case_decl: // case-decl
        yylhs.value.emplace< identifier > ();
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_147_argument_list_opt: // argument-list-opt
      case symbol_kind::S_148_argument_list: // argument-list
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

      case symbol_kind::S_158_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_155_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_156_parameter_list: // parameter-list
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
      case symbol_kind::S_PROBE: // PROBE
        yylhs.value.emplace< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_127_expression_statement: // expression-statement
      case symbol_kind::S_128_generic_statement: // generic-statement
      case symbol_kind::S_129_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_if_else_tail: // if-else-tail
      case symbol_kind::S_126_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_135_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_182_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_159_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        yylhs.value.emplace< std::pair<resource_location, parameter::default_spec> > ();
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

      case symbol_kind::S_151_field_list_opt: // field-list-opt
      case symbol_kind::S_152_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_141_case_list_opt: // case-list-opt
      case symbol_kind::S_142_case_list: // case-list
        yylhs.value.emplace< std::vector<identifier> > ();
        break;

      case symbol_kind::S_144_struct_decl: // struct-decl
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

      case symbol_kind::S_138_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_146_expression_list: // expression-list
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

      case symbol_kind::S_145_using_decl: // using-decl
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
#line 351 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3168 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 352 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3174 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 357 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3180 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 359 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3186 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 361 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3192 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 378 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3198 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 379 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3204 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 381 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3210 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 383 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3216 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 388 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3222 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 390 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3235 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 399 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3241 "annium.tab.cpp"
    break;

  case 14: // statement: STRUCT struct-decl
#line 401 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3247 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type
#line 405 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3253 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 407 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3259 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: identifier
#line 412 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3265 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: "weak modifier" identifier
#line 414 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3271 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start
#line 418 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3277 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 420 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3283 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: %empty
#line 425 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3289 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: infunction-statement
#line 427 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3295 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 429 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3301 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-statement
#line 434 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3307 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 435 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3313 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 437 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3319 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 439 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3325 "annium.tab.cpp"
    break;

  case 28: // function-body: braced-statements
#line 444 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3331 "annium.tab.cpp"
    break;

  case 29: // function-body: "`=>`" syntax-expression
#line 448 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3337 "annium.tab.cpp"
    break;

  case 30: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 459 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3343 "annium.tab.cpp"
    break;

  case 31: // finished-statement: INCLUDE STRING
#line 464 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3349 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 466 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3355 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 468 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3361 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 470 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3367 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 472 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3373 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 474 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3379 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 476 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3389 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 486 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3395 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 491 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3401 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 493 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3407 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 497 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3413 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 498 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3419 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 503 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3425 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 505 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3434 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 513 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3440 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 515 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3446 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 517 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3457 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 524 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3463 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 525 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3469 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 529 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3475 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 531 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3481 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 533 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3487 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 535 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3493 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 537 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3499 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 539 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3505 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 544 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3511 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 552 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3517 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 567 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3523 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 569 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3529 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 571 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3535 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 576 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3541 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 577 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3547 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 581 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3553 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 582 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3559 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 587 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3565 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 589 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3571 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 594 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3577 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 596 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3583 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 601 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3589 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 618 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3595 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 621 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3601 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 632 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3607 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 634 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3613 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 636 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3619 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 643 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3625 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 647 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3631 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 648 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3637 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 653 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3643 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 655 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3649 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 660 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3655 "annium.tab.cpp"
    break;

  case 81: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 666 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3661 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 668 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3667 "annium.tab.cpp"
    break;

  case 83: // using-decl: qname "`=>`" syntax-expression
#line 691 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3677 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 697 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3688 "annium.tab.cpp"
    break;

  case 85: // expression-list: syntax-expression
#line 714 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3694 "annium.tab.cpp"
    break;

  case 86: // expression-list: expression-list "," syntax-expression
#line 716 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3700 "annium.tab.cpp"
    break;

  case 87: // argument-list-opt: %empty
#line 721 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3706 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: argument-list
#line 722 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3712 "annium.tab.cpp"
    break;

  case 89: // argument-list: argument
#line 727 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3718 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument-list "," argument
#line 729 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3724 "annium.tab.cpp"
    break;

  case 91: // argument: argument-name syntax-expression
#line 734 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3730 "annium.tab.cpp"
    break;

  case 92: // argument: syntax-expression
#line 736 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3736 "annium.tab.cpp"
    break;

  case 93: // argument-name: identifier "`=`"
#line 741 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3742 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`:`"
#line 743 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3748 "annium.tab.cpp"
    break;

  case 95: // field-list-opt: %empty
#line 748 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3754 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: field-list
#line 749 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3760 "annium.tab.cpp"
    break;

  case 97: // field-list: field
#line 754 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3766 "annium.tab.cpp"
    break;

  case 98: // field-list: field-list "," field
#line 756 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3772 "annium.tab.cpp"
    break;

  case 99: // field-default-value-opt: %empty
#line 760 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3778 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: "`=`" syntax-expression
#line 761 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3784 "annium.tab.cpp"
    break;

  case 101: // field: identifier "`:`" type-expr field-default-value-opt
#line 766 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3790 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`=>`" syntax-expression
#line 768 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3796 "annium.tab.cpp"
    break;

  case 103: // parameter-list-opt: %empty
#line 774 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3802 "annium.tab.cpp"
    break;

  case 104: // parameter-list-opt: parameter-list
#line 775 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3808 "annium.tab.cpp"
    break;

  case 105: // parameter-list: parameter-decl
#line 780 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3814 "annium.tab.cpp"
    break;

  case 106: // parameter-list: parameter-list "," parameter-decl
#line 782 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3820 "annium.tab.cpp"
    break;

  case 107: // internal-identifier-opt: %empty
#line 786 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3826 "annium.tab.cpp"
    break;

  case 108: // internal-identifier-opt: internal-identifier
#line 787 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3832 "annium.tab.cpp"
    break;

  case 109: // parameter-default-value-opt: %empty
#line 791 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3838 "annium.tab.cpp"
    break;

  case 110: // parameter-default-value-opt: "`=`" syntax-expression
#line 792 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3844 "annium.tab.cpp"
    break;

  case 111: // ellipsis-opt-assign-value-opt: %empty
#line 796 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 3850 "annium.tab.cpp"
    break;

  case 112: // ellipsis-opt-assign-value-opt: "`...`"
#line 797 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 3856 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 798 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3862 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 799 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3868 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 805 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3874 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 809 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3880 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 815 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3886 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 817 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3896 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 824 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3905 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 830 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 3915 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 836 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3921 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 838 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3927 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 840 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3933 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 842 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3939 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 845 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3945 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 847 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3954 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 852 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3960 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 854 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3966 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: pattern-mod parameter-default-value-opt
#line 856 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3972 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 864 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3981 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 869 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3990 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 874 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 3999 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`...`" parameter-default-value-opt
#line 879 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4005 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 884 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4011 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified-mod: "constexpr modifier"
#line 890 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4017 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-specified-mod: "runctime modifier"
#line 891 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4023 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 896 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4029 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 898 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4035 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod
#line 902 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4041 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 904 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4047 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-mod: %empty
#line 909 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4056 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-mod: constraint-expression-specified-mod
#line 913 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4062 "annium.tab.cpp"
    break;

  case 143: // constraint-expression: constraint-expression-mod type-expr
#line 918 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4068 "annium.tab.cpp"
    break;

  case 144: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 920 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4074 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod
#line 924 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4080 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod "`...`"
#line 926 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4086 "annium.tab.cpp"
    break;

  case 147: // subpatterns: "`(`" pattern-list "`)`"
#line 936 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4092 "annium.tab.cpp"
    break;

  case 148: // pattern-list: pattern-field
#line 941 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4098 "annium.tab.cpp"
    break;

  case 149: // pattern-list: pattern-list "," pattern-field
#line 943 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4104 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: concept-expression-list-opt
#line 949 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4110 "annium.tab.cpp"
    break;

  case 151: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 951 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4116 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 954 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4122 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 956 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4128 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: "`=`" pattern-sfx
#line 960 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4134 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 963 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4140 "annium.tab.cpp"
    break;

  case 156: // pattern-field: identifier pattern-field-sfx
#line 969 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4146 "annium.tab.cpp"
    break;

  case 157: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 972 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4152 "annium.tab.cpp"
    break;

  case 158: // pattern-field: pattern-field-sfx
#line 985 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4158 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`_`" pattern-field-sfx
#line 988 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4164 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "`~`" pattern-sfx
#line 992 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 4170 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 993 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4176 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 994 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4182 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "consteval modifier" syntax-expression
#line 995 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4188 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "typename modifier" pattern-sfx
#line 996 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4194 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "typename modifier"
#line 997 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; }
#line 4200 "annium.tab.cpp"
    break;

  case 166: // pattern-sfx: pattern
#line 1001 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4206 "annium.tab.cpp"
    break;

  case 167: // pattern-sfx: pattern "`...`"
#line 1002 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4212 "annium.tab.cpp"
    break;

  case 168: // pattern-sfx: "`...`"
#line 1003 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4218 "annium.tab.cpp"
    break;

  case 169: // pattern: qname
#line 1008 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4224 "annium.tab.cpp"
    break;

  case 170: // pattern: qname subpatterns concept-expression-list-opt
#line 1010 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4230 "annium.tab.cpp"
    break;

  case 171: // pattern: internal-identifier concept-expression-list-opt
#line 1012 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4236 "annium.tab.cpp"
    break;

  case 172: // pattern: "`_`" concept-expression-list-opt
#line 1014 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4242 "annium.tab.cpp"
    break;

  case 173: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1016 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4248 "annium.tab.cpp"
    break;

  case 174: // pattern: "`(`" "`)`"
#line 1018 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4254 "annium.tab.cpp"
    break;

  case 175: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1020 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4260 "annium.tab.cpp"
    break;

  case 176: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1022 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4266 "annium.tab.cpp"
    break;

  case 177: // pattern: concept-expression-list
#line 1024 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4272 "annium.tab.cpp"
    break;

  case 178: // concept-expression: "`@`" qname
#line 1029 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4278 "annium.tab.cpp"
    break;

  case 179: // concept-expression-list-opt: %empty
#line 1034 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4284 "annium.tab.cpp"
    break;

  case 180: // concept-expression-list-opt: concept-expression-list
#line 1035 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4290 "annium.tab.cpp"
    break;

  case 181: // concept-expression-list: concept-expression
#line 1040 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4296 "annium.tab.cpp"
    break;

  case 182: // concept-expression-list: concept-expression-list concept-expression
#line 1042 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4302 "annium.tab.cpp"
    break;

  case 183: // reference-expression: CONTEXT_IDENTIFIER
#line 1048 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4308 "annium.tab.cpp"
    break;

  case 184: // reference-expression: qname
#line 1050 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4314 "annium.tab.cpp"
    break;

  case 185: // any-reference-expression: RESERVED_IDENTIFIER
#line 1055 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4320 "annium.tab.cpp"
    break;

  case 186: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4326 "annium.tab.cpp"
    break;

  case 187: // any-reference-expression: qname
#line 1059 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4332 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-base: "nil"
#line 1064 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4338 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: "true"
#line 1066 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4344 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "false"
#line 1068 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4350 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: INTEGER
#line 1070 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4356 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: DECIMAL
#line 1072 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4362 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: DECIMAL_S
#line 1074 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4368 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: INTEGER_INDEX
#line 1076 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4374 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: STRING
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4380 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: CT_IDENTIFIER
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4386 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: any-reference-expression
#line 1081 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4392 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: "`(`" "`)`"
#line 1083 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4398 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1085 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4407 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1091 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4419 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1102 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4425 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1104 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4431 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1106 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4437 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: PROBE braced-statements
#line 1108 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4443 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: "`.`" identifier
#line 1110 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4449 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1117 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4459 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`-`" syntax-expression
#line 1124 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4465 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1126 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4471 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1140 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4477 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: "`!`" syntax-expression
#line 1142 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4483 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`*`" syntax-expression
#line 1144 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4489 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1147 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4495 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1149 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4501 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1153 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4507 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1155 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4513 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1159 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4519 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1161 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4525 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1163 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4531 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1165 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4537 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1167 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4543 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1169 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4549 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1171 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4555 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1174 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4561 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1178 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4567 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1181 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4573 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1184 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4579 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1186 "annium.y"
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
#line 4594 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1198 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4600 "annium.tab.cpp"
    break;

  case 229: // grouped-expression: "`(`" pack-expression "`)`"
#line 1218 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4613 "annium.tab.cpp"
    break;

  case 230: // new-expression: "`new`" qname
#line 1231 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4619 "annium.tab.cpp"
    break;

  case 231: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1235 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4625 "annium.tab.cpp"
    break;

  case 232: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1242 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4631 "annium.tab.cpp"
    break;

  case 233: // call-expression: any-reference-expression "`.`" identifier
#line 1244 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4637 "annium.tab.cpp"
    break;

  case 234: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1246 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4646 "annium.tab.cpp"
    break;

  case 235: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1251 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4652 "annium.tab.cpp"
    break;

  case 236: // call-expression: call-expression "`.`" identifier
#line 1253 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4658 "annium.tab.cpp"
    break;

  case 237: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1255 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4667 "annium.tab.cpp"
    break;

  case 238: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1260 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4673 "annium.tab.cpp"
    break;

  case 239: // syntax-expression: syntax-expression-base
#line 1264 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4679 "annium.tab.cpp"
    break;

  case 240: // syntax-expression: new-expression
#line 1265 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4685 "annium.tab.cpp"
    break;

  case 241: // syntax-expression: compound-expression
#line 1266 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4691 "annium.tab.cpp"
    break;

  case 242: // syntax-expression: lambda-expression
#line 1267 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4697 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: grouped-expression
#line 1268 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4703 "annium.tab.cpp"
    break;

  case 244: // lambda-start-decl: fn-prefix-decl
#line 1274 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4709 "annium.tab.cpp"
    break;

  case 245: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1276 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4715 "annium.tab.cpp"
    break;

  case 246: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1281 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4726 "annium.tab.cpp"
    break;

  case 247: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1288 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4738 "annium.tab.cpp"
    break;

  case 248: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1296 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4750 "annium.tab.cpp"
    break;

  case 249: // pack-expression-opt: %empty
#line 1307 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4756 "annium.tab.cpp"
    break;

  case 250: // pack-expression-opt: pack-expression
#line 1309 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4762 "annium.tab.cpp"
    break;

  case 251: // pack-expression: syntax-expression
#line 1314 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4768 "annium.tab.cpp"
    break;

  case 252: // pack-expression: identifier "`:`" syntax-expression
#line 1316 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4778 "annium.tab.cpp"
    break;

  case 253: // pack-expression: pack-expression "," syntax-expression
#line 1322 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4787 "annium.tab.cpp"
    break;

  case 254: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1327 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4796 "annium.tab.cpp"
    break;

  case 255: // compound-expression: syntax-expression "`...`"
#line 1335 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4802 "annium.tab.cpp"
    break;

  case 256: // compound-expression: call-expression
#line 1336 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4808 "annium.tab.cpp"
    break;

  case 257: // type-expr: qname
#line 1377 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4814 "annium.tab.cpp"
    break;

  case 258: // type-expr: RESERVED_IDENTIFIER
#line 1379 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4820 "annium.tab.cpp"
    break;

  case 259: // type-expr: CONTEXT_IDENTIFIER
#line 1381 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4826 "annium.tab.cpp"
    break;

  case 260: // type-expr: call-expression
#line 1382 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4832 "annium.tab.cpp"
    break;

  case 261: // type-expr: "`[`" type-expr "`]`"
#line 1384 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4838 "annium.tab.cpp"
    break;

  case 262: // type-expr: "`(`" "`)`"
#line 1386 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4844 "annium.tab.cpp"
    break;

  case 263: // type-expr: grouped-expression
#line 1387 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4850 "annium.tab.cpp"
    break;

  case 264: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1389 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4856 "annium.tab.cpp"
    break;

  case 265: // type-expr: type-expr "`|`" type-expr
#line 1391 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4862 "annium.tab.cpp"
    break;

  case 266: // type-expr: type-expr "`->`" type-expr
#line 1393 "annium.y"
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
#line 4877 "annium.tab.cpp"
    break;


#line 4881 "annium.tab.cpp"

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

  const short parser::yytable_ninf_ = -188;

  const short
  parser::yypact_[] =
  {
     862,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,
      44,   969,   990,    44,  1225,  1225,  1225,     2,    -9,    21,
    1225,   163,  1225,    21,    56,  -347,  -347,  -347,    22,    21,
      21,  1225,    55,  -347,  -347,  -347,    79,   143,    11,   541,
    -347,  -347,  -347,  -347,  -347,    70,  -347,   437,    32,   102,
    -347,   104,  -347,   208,  1233,   117,  -347,    40,  -347,  1225,
    -347,   166,   174,  1638,    -8,  -347,   755,   194,   118,  1638,
    -347,    64,    64,    64,    44,  -347,   216,   267,  -347,    44,
      22,   169,   872,  -347,    70,   221,  1309,   171,  -347,  -347,
    -347,    70,   255,  -347,   228,  -347,   321,  -347,    64,  1225,
    -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,    44,  -347,
    -347,  1225,   294,   119,  1225,    44,  1225,  1225,    44,  -347,
    1225,   193,  1225,  1225,  1225,  1225,  1225,  1225,  1225,  1225,
    1225,  -347,  1225,  1225,  1225,  1225,  1225,  1225,  1225,   193,
     520,  1356,  1225,  -347,  1225,  -347,  -347,  1225,  1225,   254,
     648,  -347,   260,  -347,  -347,  -347,  -347,  1097,  -347,   193,
    1225,   277,  -347,  1225,  1225,  -347,  1225,   259,  1225,   520,
     520,    44,   285,   520,  1403,  -347,   318,   271,   193,   624,
    1225,  -347,   328,   330,   334,    43,   343,  1638,   247,   306,
    1118,   193,   397,   102,   104,   208,    97,   464,   464,   464,
     464,   464,   464,   765,   658,   551,  1450,   297,   297,   357,
     357,  1699,  1685,    48,  -347,    21,   381,   387,   129,   193,
     400,   315,  -347,  1225,  -347,    37,   185,   244,   365,   355,
    -347,  1004,   387,   387,  -347,   258,  -347,  1638,   380,  1638,
    1638,  1638,  -347,  -347,  -347,  -347,  -347,  -347,  1638,    48,
     271,   193,    17,   382,   364,  -347,  1225,  1638,    79,  1309,
    1065,  -347,  1638,   388,   411,  -347,   395,   403,  -347,    44,
     412,  1225,  -347,    48,    24,   421,  1225,   381,   238,  -347,
     381,  1638,  -347,  1225,  -347,  -347,  1225,  -347,   230,   193,
    1225,   193,  -347,    70,   207,   381,  1225,  -347,   387,   376,
    -347,   315,   315,  -347,   440,  -347,  1638,  -347,   -12,   331,
     207,  1225,   459,  -347,   340,   520,  -347,   258,   441,  -347,
    -347,  -347,  -347,  1225,    48,  -347,  -347,  -347,  1225,  1638,
    -347,  -347,  -347,  -347,    22,   461,   379,  -347,    44,    14,
     434,   419,  -347,   468,    64,    39,   381,  -347,  -347,  1497,
    -347,   381,   442,   445,  -347,    97,  1544,    97,  -347,  1638,
    -347,   207,  -347,  -347,  -347,   331,   443,   381,  1084,   387,
     387,   258,  -347,  1638,  1225,   193,  1225,   624,  -347,  -347,
    -347,  -347,  -347,  1638,  -347,    79,  1225,   447,  -347,  -347,
    1225,   193,  -347,    44,   458,   315,   284,   502,   284,   405,
     178,  -347,  -347,   474,  -347,    24,  -347,  -347,  -347,  -347,
    -347,   381,   387,   387,   436,   409,   436,  -347,   466,  -347,
    -347,  -347,  1638,   404,  1638,   189,  1638,  1225,  1638,   101,
    -347,    44,  -347,  -347,   284,  -347,   315,   482,  -347,    39,
    -347,   381,  -347,   436,  -347,  -347,  -347,  -347,  -347,  -347,
    -347,  -347,  -347,  -347,  1591,  1225,  -347,   478,  -347,  -347,
    -347,  -347,  -347,  -347,  -347,  1638,  -347
  };

  const short
  parser::yydefact_[] =
  {
       4,   195,    56,   186,   185,   194,   191,   192,   193,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    65,     0,     0,
       0,     0,     0,   188,   189,   190,     0,     0,     0,     0,
       5,     7,    49,    13,    59,   187,    63,     0,   244,   197,
     239,   243,   240,   256,     0,     0,   242,   241,    58,     0,
     198,    59,   244,   251,     0,   241,    21,     0,     0,    85,
     205,   207,   211,   210,     0,    45,    19,    15,    17,     0,
       0,   230,     0,   183,   184,     0,     0,     0,    48,    31,
      68,    67,     0,    46,     0,    38,     0,    14,   208,     0,
     204,     1,     2,    10,     3,     8,     6,     9,     0,    66,
      64,   249,    72,     0,   249,     0,   249,     0,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   229,     0,    52,    51,    53,     0,    41,
      42,    24,     0,    50,    22,   202,   200,     0,    18,     0,
       0,     0,    12,    87,     0,    32,     0,    35,     0,   103,
     103,    76,     0,   103,     0,    60,     0,   250,     0,     0,
       0,    37,     0,   233,     0,     0,   236,    44,   259,   258,
       0,     0,   257,     0,   263,   260,   227,   216,   217,   218,
     219,   220,   221,   225,   226,   222,     0,   214,   215,   212,
     213,   223,   224,   228,    57,     0,   179,   109,     0,     0,
       0,   165,   135,     0,   136,    59,   179,   111,     0,   104,
     105,   139,   109,   109,   181,   111,   199,   252,    59,   253,
      54,    55,    27,    25,    26,    23,    30,   201,    86,    20,
      16,     0,    59,     0,    88,    89,     0,    92,     0,     0,
       0,    36,    83,     0,     0,    80,     0,    77,    78,    95,
       0,     0,   245,    73,   179,     0,     0,   179,   169,    74,
     177,    47,   232,   249,   238,   235,   249,   262,     0,     0,
       0,     0,   203,   178,   111,   180,     0,   133,   109,     0,
     168,     0,     0,   160,   166,   164,   163,   108,     0,   141,
     111,     0,   112,   120,     0,     0,   140,   111,   137,   117,
     129,   132,   182,     0,    11,    93,    94,   231,     0,    91,
      33,    34,    39,    40,     0,     0,    70,    75,     0,     0,
       0,    96,    97,     0,   209,   179,   179,   172,   174,     0,
     171,   179,     0,     0,   261,   266,     0,   265,   131,   110,
     128,   111,   161,   162,   167,   141,     0,   142,   145,   109,
     109,   111,   130,   113,     0,     0,     0,     0,   246,    28,
     106,   119,   138,   254,    90,     0,     0,     0,    69,    79,
       0,     0,    81,     0,     0,     0,   179,     0,   179,   179,
       0,   158,   148,   150,   173,   179,   170,   234,   237,   264,
     118,   142,   109,   109,   109,   141,   109,   146,   143,   116,
     125,   126,   114,     0,    29,     0,    84,     0,   102,    99,
      98,    95,   154,   159,   179,   156,     0,   152,   147,   179,
     151,   179,   175,   109,   115,   121,   122,   142,   134,   124,
     127,   144,   247,   248,     0,     0,   101,     0,   157,   155,
     153,   149,   176,   123,    71,   100,    82
  };

  const short
  parser::yypgoto_[] =
  {
    -347,  -347,  -347,  -347,   495,  -347,  -347,  -347,  -347,  -347,
      42,    -7,   -36,  -347,  -347,   375,   -40,   390,    67,  -136,
     168,   507,  -347,    10,  -347,   514,  -347,   -79,  -347,  -347,
    -347,   218,  -347,  -347,  -347,  -347,  -347,   233,  -347,   131,
    -347,  -347,   173,  -122,  -347,  -347,  -208,  -222,   249,  -302,
    -347,  -347,  -346,  -260,  -347,  -343,   128,  -212,  -219,  -162,
      74,  -174,    99,  -347,    35,  -347,   124,  -347,   153,     0,
    -347,  -347,   -93,    -2,   279,   190
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    37,    38,    39,    40,    75,    76,    77,   149,   150,
     378,   379,    41,   261,   152,    42,    43,   154,    44,   277,
      45,    46,    47,    62,    92,   112,   388,   113,    95,   266,
     267,   268,    97,    88,    68,   253,   254,   255,   256,   340,
     341,   456,   342,   228,   229,   308,   297,   313,   230,   231,
     232,   368,   369,   346,   400,   401,   402,   233,   303,   304,
     234,   403,   295,    85,    49,    50,    51,    52,    53,    63,
      55,    56,   176,   177,    65,   196
  };

  const short
  parser::yytable_[] =
  {
      54,   162,   305,   107,   226,    67,   298,   367,     2,    64,
      48,   102,    69,   321,    71,    72,    73,   279,   351,   412,
      82,   182,    86,   184,   319,   320,   153,     2,     2,   100,
     151,    98,   325,   226,   226,   390,   365,   226,     2,    54,
     -43,   215,   294,   143,   214,     2,   214,   263,   264,    48,
       2,   270,   310,   433,   395,   435,   215,   396,   366,   141,
     144,    89,   391,   411,    79,   326,    54,   103,   289,   448,
      10,    10,   358,   119,   345,   165,    48,    58,    61,   167,
      70,    10,   362,   363,    78,  -107,   111,    80,   372,   307,
     360,   458,   -43,   -43,   285,   381,   -43,   370,    90,   174,
     347,   131,   290,   350,    74,    99,   181,  -107,    90,   397,
     153,   144,   291,   447,   244,   185,   455,   289,   132,   108,
     187,   289,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    66,   206,   207,   208,   209,   210,   211,   212,   410,
     180,   158,   237,   101,   239,   441,   161,   240,   241,   421,
      54,   290,   114,   413,   116,   290,   193,   248,   250,   115,
      48,   419,   420,   257,    54,   291,   259,   140,   262,     2,
      83,    66,   404,   156,   193,   175,   432,   406,    61,   226,
     281,    61,   183,    61,    61,   186,   157,    81,    64,    84,
     352,    87,   168,   353,   193,   220,    91,    94,    96,     2,
     188,   189,   215,   449,   444,   445,   446,   225,   450,   399,
     376,   238,    10,   193,   142,   425,    91,   459,   108,   163,
     108,   169,   311,   306,   333,   437,   193,    61,   111,   438,
     252,   442,   221,   309,   223,   463,   225,   225,   265,   235,
     225,    66,    10,   190,   312,   194,   439,   191,    91,   155,
     289,   330,   331,   332,   193,   385,   329,    61,   117,   311,
     399,   434,   399,   194,   159,   118,   193,   462,   235,   235,
     334,   344,   235,   311,   195,   215,   349,   108,   280,    57,
     171,   312,   160,   194,   290,   354,   193,   108,   345,   192,
     356,   214,   195,   108,   291,   312,   359,  -186,   399,   395,
     166,   215,   194,   399,  -186,   170,   119,   192,   227,   322,
     242,   373,   195,   246,   178,   194,   179,   121,    57,   280,
     280,     2,   214,   383,   193,   251,   193,   192,   257,   213,
     317,   195,   215,   274,   131,   269,   339,   227,   227,   144,
     260,   227,   172,   194,   195,    57,   192,   278,   215,   249,
      61,   132,   300,    61,   322,   194,  -185,   135,   136,   192,
     375,   376,   377,  -185,    10,   275,   119,   276,   273,   322,
     108,   173,   195,   272,   422,   194,   424,   121,   181,   282,
     283,   288,   225,   293,   195,   284,   426,   192,   278,   278,
     428,   322,    66,   286,   131,   252,   289,   220,   215,   192,
     280,   280,   296,   193,   195,   265,     2,   214,   371,   299,
     193,   132,   398,   194,   235,   194,   314,   215,   274,   192,
     436,   318,   215,   315,   289,   376,   193,   454,   323,    57,
     290,   361,   328,   327,   221,   222,   223,   300,   224,   335,
     291,   324,   195,    57,   195,   322,   108,  -187,   337,    10,
     275,   296,   276,   215,  -187,   465,    66,   192,   290,   192,
     339,   289,   336,   343,   414,   452,   416,   453,   291,   278,
     278,   338,   348,   119,   374,   220,   280,   364,   382,   355,
     387,   357,   386,   227,   121,   392,   289,   393,   322,   394,
     322,   415,   194,   407,   280,   290,   408,   427,   339,   194,
     130,   131,    91,   451,   301,   291,   398,   302,   431,   214,
     443,   440,   221,   222,   223,   194,   224,   322,   132,   460,
     290,   195,   133,   134,   135,   136,     2,   214,   195,   466,
     291,    25,    26,   109,   106,   280,   192,   215,   216,   258,
     245,   104,    93,   192,   195,   278,     1,     2,     3,     4,
       5,     6,     7,     8,   110,     9,   389,   217,   418,   192,
     119,   384,   457,   278,   380,   423,   430,   461,   218,    10,
       0,   121,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   429,     0,     0,     0,     0,   220,     0,   131,     0,
      10,    11,     0,     0,     0,    12,     0,   105,    13,     0,
      14,    15,     0,     0,   278,   132,    16,     0,     0,   133,
     134,   135,   136,    17,     0,     0,    18,    19,    20,    21,
       0,    22,     0,   221,   222,   223,     0,   224,    23,     0,
       2,   214,     0,     0,    24,    25,    26,    27,    28,    29,
      30,   215,   274,     0,     0,     0,    31,    32,     0,    33,
      34,    35,    36,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,    10,   275,     0,   276,     0,   121,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     126,   127,   128,     0,   130,   131,     0,    10,    11,     0,
       0,     0,    12,     0,   243,    13,     0,    14,    15,     0,
       0,     0,   132,    16,     0,     0,   133,   134,   135,   136,
      17,   137,   138,     0,    19,    20,    21,     0,    22,     0,
     145,   146,   147,   148,     0,    23,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,     0,
       0,   130,   131,     0,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,     0,     0,   132,
      16,     0,     0,   133,   134,   135,   136,    17,   137,   138,
       0,    19,    20,    21,     0,    22,     0,   145,   146,   147,
     148,     0,    23,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
      31,    32,     0,    33,    34,    35,    36,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,    10,    11,     0,     0,     0,    12,     0,     0,    13,
       0,    14,    15,     0,    66,     0,   132,    16,   164,     0,
     133,   134,   135,   136,    17,   137,   138,    18,    19,    20,
      21,     0,    22,     0,     0,     0,   139,     0,     0,    23,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,    31,    32,     0,
      33,    34,    35,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       2,   188,   189,     0,     0,     0,     0,    59,    10,    11,
      60,   215,     0,    12,     0,     0,    13,     0,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    10,
      11,   316,    66,     0,    12,    19,     0,    13,     0,    14,
      15,     0,     0,    10,   190,    16,     0,     0,   191,     0,
       0,     0,     0,    25,    26,    27,    19,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,    35,
      36,     0,     0,     0,    25,    26,    27,     0,     0,     0,
       2,   188,   189,     0,     0,    31,    32,     0,    33,    34,
      35,    36,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,    66,     0,     0,
       0,   417,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,    10,   190,     0,     0,     0,   191,     0,
       0,     0,    20,    21,     0,    22,    10,    11,     0,     0,
       0,    12,   247,     0,    13,     0,    14,    15,    24,    25,
      26,    27,    16,    29,     0,     0,     0,    10,    11,   287,
       0,     0,    12,    19,     0,    13,     0,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,    25,    26,    27,    19,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,    33,    34,    35,    36,     0,
       0,     0,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   119,     0,     0,     0,     0,     0,   120,     0,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,   132,     0,     0,
      16,   133,   134,   135,   136,     0,   137,   138,     0,     0,
       0,    19,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,   121,
      31,    32,     0,    33,    34,    35,    36,   122,   123,   124,
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
     405,   132,     0,   119,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   139,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   409,
     119,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,     0,   132,     0,   119,     0,   133,
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
       0,    80,   221,    39,   140,    12,   218,   309,     6,    11,
       0,     0,    12,   235,    14,    15,    16,   179,   278,   365,
      20,   114,    22,   116,   232,   233,    66,     6,     6,    36,
      66,    31,    15,   169,   170,    21,    48,   173,     6,    39,
       0,    17,   216,    51,     7,     6,     7,   169,   170,    39,
       6,   173,   226,   396,    15,   398,    17,    18,    70,    59,
      68,     5,    48,   365,    73,    48,    66,    56,    20,   415,
      49,    49,   294,     9,    50,    82,    66,    10,    11,    86,
      13,    49,   301,   302,    17,    48,    54,    96,   310,   225,
     298,   434,    52,    53,    51,   317,    56,   309,    76,    99,
     274,    37,    54,   277,   102,    50,   113,    70,    76,    70,
     150,    68,    64,   415,   150,   117,    15,    20,    54,    49,
     120,    20,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    52,   132,   133,   134,   135,   136,   137,   138,   361,
      21,    74,   142,     0,   144,   405,    79,   147,   148,   371,
     150,    54,    50,   365,    50,    54,   121,   157,   160,    57,
     150,   369,   370,   163,   164,    64,   166,    50,   168,     6,
       7,    52,   346,    55,   139,   108,   395,   351,   111,   315,
     180,   114,   115,   116,   117,   118,    68,    19,   190,    21,
     283,    23,    21,   286,   159,    66,    28,    29,    30,     6,
       7,     8,    17,   415,   412,   413,   414,   140,   416,   345,
      21,   144,    49,   178,    48,   377,    48,   436,    49,    50,
      49,    50,    15,   223,   260,   399,   191,   160,    54,    51,
     163,   405,   103,    48,   105,   443,   169,   170,   171,   140,
     173,    52,    49,    50,    37,   121,    68,    54,    80,    55,
      20,   258,   259,   260,   219,   334,   256,   190,    50,    15,
     396,   397,   398,   139,    48,    57,   231,   441,   169,   170,
     260,   271,   173,    15,   121,    17,   276,    49,   179,     0,
      52,    37,    15,   159,    54,    55,   251,    49,    50,   121,
     290,     7,   139,    49,    64,    37,   296,    50,   434,    15,
      79,    17,   178,   439,    57,    50,     9,   139,   140,   235,
      56,   311,   159,    53,    20,   191,    22,    20,    39,   220,
     221,     6,     7,   323,   289,    48,   291,   159,   328,   139,
     231,   178,    17,    18,    37,    50,   269,   169,   170,    68,
      81,   173,    21,   219,   191,    66,   178,   179,    17,   159,
     283,    54,    37,   286,   280,   231,    50,    60,    61,   191,
      20,    21,    22,    57,    49,    50,     9,    52,   178,   295,
      49,    50,   219,    55,   374,   251,   376,    20,   385,    51,
      50,   191,   315,   215,   231,    51,   386,   219,   220,   221,
     390,   317,    52,    50,    37,   328,    20,    66,    17,   231,
     301,   302,    15,   368,   251,   338,     6,     7,   309,   219,
     375,    54,   345,   289,   315,   291,    51,    17,    18,   251,
      15,   231,    17,    68,    20,    21,   391,   427,    48,   150,
      54,    55,    68,    51,   103,   104,   105,    37,   107,    51,
      64,   251,   289,   164,   291,   371,    49,    50,    53,    49,
      50,    15,    52,    17,    57,   455,    52,   289,    54,   291,
     393,    20,    51,    51,   365,   423,   367,   425,    64,   301,
     302,    68,    51,     9,    15,    66,   377,    37,    37,   289,
     101,   291,    21,   315,    20,    51,    20,    68,   414,    21,
     416,    48,   368,    51,   395,    54,    51,    50,   431,   375,
      36,    37,   334,    37,   104,    64,   439,   107,    50,     7,
     411,    37,   103,   104,   105,   391,   107,   443,    54,    37,
      54,   368,    58,    59,    60,    61,     6,     7,   375,    51,
      64,    94,    95,    96,    39,   436,   368,    17,    18,   164,
     150,     0,    28,   375,   391,   377,     5,     6,     7,     8,
       9,    10,    11,    12,    47,    14,   338,    37,   368,   391,
       9,   328,   431,   395,   315,   375,   393,   439,    48,    49,
      -1,    20,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,    -1,    66,    -1,    37,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    -1,   436,    54,    65,    -1,    -1,    58,
      59,    60,    61,    72,    -1,    -1,    75,    76,    77,    78,
      -1,    80,    -1,   103,   104,   105,    -1,   107,    87,    -1,
       6,     7,    -1,    -1,    93,    94,    95,    96,    97,    98,
      99,    17,    18,    -1,    -1,    -1,   105,   106,    -1,   108,
     109,   110,   111,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    54,    65,    -1,    -1,    58,    59,    60,    61,
      72,    63,    64,    -1,    76,    77,    78,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,   108,   109,   110,   111,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    37,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,    54,
      65,    -1,    -1,    58,    59,    60,    61,    72,    63,    64,
      -1,    76,    77,    78,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,    -1,   108,   109,   110,   111,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    60,    -1,    52,    -1,    54,    65,    56,    -1,
      58,    59,    60,    61,    72,    63,    64,    75,    76,    77,
      78,    -1,    80,    -1,    -1,    -1,    74,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
     108,   109,   110,   111,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    17,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    49,
      50,    37,    52,    -1,    54,    76,    -1,    57,    -1,    59,
      60,    -1,    -1,    49,    50,    65,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    94,    95,    96,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
       6,     7,     8,    -1,    -1,   105,   106,    -1,   108,   109,
     110,   111,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    37,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    77,    78,    -1,    80,    49,    50,    -1,    -1,
      -1,    54,    55,    -1,    57,    -1,    59,    60,    93,    94,
      95,    96,    65,    98,    -1,    -1,    -1,    49,    50,    51,
      -1,    -1,    54,    76,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,   108,   109,   110,   111,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    54,    -1,    -1,
      65,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    94,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
     105,   106,    -1,   108,   109,   110,   111,    28,    29,    30,
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
      99,   105,   106,   108,   109,   110,   111,   113,   114,   115,
     116,   124,   127,   128,   130,   132,   133,   134,   135,   176,
     177,   178,   179,   180,   181,   182,   183,   186,   130,    48,
      51,   130,   135,   181,   185,   186,    52,   123,   146,   181,
     130,   181,   181,   181,   102,   117,   118,   119,   130,    73,
      96,   132,   181,     7,   132,   175,   181,   132,   145,     5,
      76,   132,   136,   137,   132,   140,   132,   144,   181,    50,
     123,     0,     0,    56,     0,    56,   116,   124,    49,    96,
     133,    54,   137,   139,    50,    57,    50,    50,    57,     9,
      15,    20,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    54,    58,    59,    60,    61,    63,    64,    74,
      50,   181,    48,    51,    68,    82,    83,    84,    85,   120,
     121,   124,   126,   128,   129,    55,    55,    68,   130,    48,
      15,   130,   139,    50,    56,   123,    79,   123,    21,    50,
      50,    52,    21,    50,   181,   130,   184,   185,    20,    22,
      21,   123,   184,   130,   184,   185,   130,   181,     7,     8,
      50,    54,   132,   176,   178,   180,   187,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   187,     7,    17,    18,    37,    48,    54,
      66,   103,   104,   105,   107,   130,   131,   132,   155,   156,
     160,   161,   162,   169,   172,   174,    51,   181,   130,   181,
     181,   181,    56,    56,   124,   129,    53,    55,   181,   187,
     185,    48,   130,   147,   148,   149,   150,   181,   127,   181,
      81,   125,   181,   155,   155,   130,   141,   142,   143,    50,
     155,    51,    55,   187,    18,    50,    52,   131,   132,   171,
     174,   181,    51,    50,    51,    51,    50,    51,   187,    20,
      54,    64,    55,   132,   173,   174,    15,   158,   169,   187,
      37,   104,   107,   170,   171,   170,   181,   131,   157,    48,
     173,    15,    37,   159,    51,    68,    37,   174,   187,   158,
     158,   159,   172,    48,   187,    15,    48,    51,    68,   181,
     123,   123,   123,   124,   135,    51,    51,    53,    68,   130,
     151,   152,   154,    51,   181,    50,   165,   173,    51,   181,
     173,   165,   184,   184,    55,   187,   181,   187,   159,   181,
     158,    55,   170,   170,    37,    48,    70,   161,   163,   164,
     169,   174,   159,   181,    15,    20,    21,    22,   122,   123,
     160,   159,    37,   181,   149,   139,    21,   101,   138,   143,
      21,    48,    51,    68,    21,    15,    18,    70,   130,   131,
     166,   167,   168,   173,   173,    53,   173,    51,    51,    55,
     159,   161,   164,   169,   174,    48,   174,    37,   187,   158,
     158,   159,   181,   187,   181,   171,   181,    50,   181,   187,
     154,    50,   170,   167,   131,   167,    15,   173,    51,    68,
      37,   165,   173,   174,   158,   158,   158,   161,   164,   169,
     158,    37,   122,   122,   181,    15,   153,   151,   167,   170,
      37,   168,   173,   158,    51,   181,    51
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   112,   113,   113,   114,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     129,   129,   129,   129,   129,   129,   130,   131,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     138,   138,   139,   139,   139,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   162,
     162,   163,   163,   164,   164,   164,   164,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     169,   169,   169,   169,   169,   169,   170,   170,   170,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     179,   179,   180,   180,   180,   180,   180,   180,   180,   181,
     181,   181,   181,   181,   182,   182,   183,   183,   183,   184,
     184,   185,   185,   185,   185,   186,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187
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
       2,     3,     3,     2,     2,     1,     1,     2,     1,     1,
       3,     2,     2,     3,     2,     4,     5,     1,     2,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     4,     3,     4,     2,     2,     2,     2,     2,     5,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     5,     4,     3,     6,     4,     3,     6,     4,     1,
       1,     1,     1,     1,     1,     4,     5,     7,     7,     0,
       1,     1,     3,     3,     5,     2,     1,     1,     1,     1,
       1,     3,     2,     1,     4,     3,     3
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
  "\"runctime modifier\"", "\"nil\"", "\"true\"", "\"false\"", "PROBE",
  "$accept", "begin", "statement_any", "finished-statement-any",
  "statement", "let-decl", "let-decl-start",
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
       0,   351,   351,   352,   356,   358,   360,   377,   379,   380,
     382,   387,   389,   398,   400,   405,   406,   411,   413,   418,
     419,   424,   426,   428,   433,   435,   436,   438,   444,   447,
     458,   463,   465,   467,   469,   471,   473,   475,   485,   490,
     492,   497,   498,   502,   504,   512,   514,   516,   523,   525,
     529,   530,   532,   534,   536,   538,   543,   551,   566,   568,
     570,   576,   577,   581,   582,   586,   588,   593,   595,   600,
     618,   620,   632,   633,   635,   642,   647,   648,   652,   654,
     659,   665,   667,   690,   696,   713,   715,   721,   722,   726,
     728,   733,   735,   740,   742,   748,   749,   753,   755,   760,
     761,   765,   767,   774,   775,   779,   781,   786,   787,   791,
     792,   796,   797,   798,   799,   804,   808,   814,   816,   823,
     829,   835,   837,   839,   841,   844,   846,   851,   853,   855,
     863,   868,   873,   878,   883,   890,   891,   895,   897,   901,
     903,   908,   913,   917,   919,   923,   925,   935,   940,   942,
     948,   950,   953,   955,   959,   962,   968,   971,   984,   987,
     992,   993,   994,   995,   996,   997,  1001,  1002,  1003,  1007,
    1009,  1011,  1013,  1015,  1017,  1019,  1021,  1023,  1028,  1033,
    1035,  1039,  1041,  1047,  1049,  1054,  1056,  1058,  1063,  1065,
    1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1082,  1084,
    1090,  1101,  1103,  1105,  1107,  1109,  1116,  1123,  1125,  1139,
    1141,  1143,  1146,  1148,  1152,  1154,  1158,  1160,  1162,  1164,
    1166,  1168,  1170,  1173,  1177,  1180,  1183,  1185,  1197,  1217,
    1230,  1234,  1241,  1243,  1245,  1250,  1252,  1254,  1259,  1264,
    1265,  1266,  1267,  1268,  1273,  1275,  1280,  1287,  1295,  1306,
    1308,  1313,  1315,  1321,  1326,  1334,  1336,  1376,  1378,  1380,
    1382,  1383,  1385,  1387,  1388,  1390,  1392
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
     105,   106,   107,   108,   109,   110,   111
    };
    // Last valid token kind.
    const int code_max = 366;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 6024 "annium.tab.cpp"

#line 1587 "annium.y"

