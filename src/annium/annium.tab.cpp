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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.copy< enum_case > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.copy< match_arm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.copy< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.copy< std::vector<match_arm> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.move< enum_case > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.move< match_arm > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.move< std::vector<enum_case> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.move< std::vector<match_arm> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< enum_case > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.YY_MOVE_OR_COPY< match_arm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.YY_MOVE_OR_COPY< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.YY_MOVE_OR_COPY< std::vector<match_arm> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.move< enum_case > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.move< match_arm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.move< std::vector<enum_case> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.move< std::vector<match_arm> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.copy< enum_case > (that.value);
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.copy< match_arm > (that.value);
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.copy< std::pair<resource_location, parameter::default_spec> > (that.value);
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.copy< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (that.value);
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.copy< std::vector<enum_case> > (that.value);
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.copy< std::vector<match_arm> > (that.value);
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        value.move< enum_case > (that.value);
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        value.move< match_arm > (that.value);
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        value.move< std::pair<resource_location, parameter::default_spec> > (that.value);
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        value.move< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > (that.value);
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        value.move< std::vector<enum_case> > (that.value);
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        value.move< std::vector<match_arm> > (that.value);
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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
#line 354 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 354 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 354 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 354 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 354 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 354 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 354 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 354 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 354 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 354 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 354 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 354 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 354 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 354 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 354 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 354 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 354 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 354 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 354 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 354 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 354 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 354 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 354 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 354 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 354 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 354 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_PERCENT: // "`%`"
#line 354 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 354 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 354 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 354 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 354 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 354 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 354 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 354 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 354 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 354 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 354 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_MATCH: // "`match`"
#line 354 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 354 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 354 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 354 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 354 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 354 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
#line 354 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 354 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_REFERENCE: // "reference modifier"
#line 354 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 354 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 354 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 354 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 354 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 354 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
#line 354 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 354 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl: // let-decl
#line 354 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start: // let-decl-start
#line 354 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 354 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
#line 354 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
#line 354 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_function_body: // function-body
#line 354 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_braced_statements: // braced-statements
#line 354 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_finished_statement: // finished-statement
#line 354 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_if_else_tail: // if-else-tail
#line 354 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
#line 354 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_expression_statement: // expression-statement
#line 354 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_generic_statement: // generic-statement
#line 354 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_infunction_statement: // infunction-statement
#line 354 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 354 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
#line 354 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 354 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
#line 354 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
#line 354 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
#line 354 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_name: // fn-name
#line 354 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
#line 354 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
#line 354 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_fn_decl: // fn-decl
#line 354 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
#line 354 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
#line 354 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_list: // case-list
#line 354 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_case_decl: // case-decl
#line 354 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
#line 354 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_using_decl: // using-decl
#line 354 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_expression_list: // expression-list
#line 354 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
#line 354 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_argument_list: // argument-list
#line 354 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 354 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_argument_name: // argument-name
#line 354 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
#line 354 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_list: // field-list
#line 354 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
#line 354 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 354 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
#line 354 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_parameter_list: // parameter-list
#line 354 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
#line 354 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
#line 354 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
#line 354 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
#line 354 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 354 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
#line 354 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
#line 354 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_constraint_expression: // constraint-expression
#line 354 "annium.y"
                 { }
#line 2641 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 354 "annium.y"
                 { }
#line 2647 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_list: // pattern-list
#line 354 "annium.y"
                 { }
#line 2653 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
#line 354 "annium.y"
                 { }
#line 2659 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_field: // pattern-field
#line 354 "annium.y"
                 { }
#line 2665 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
#line 354 "annium.y"
                 { }
#line 2671 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
#line 354 "annium.y"
                 { }
#line 2677 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 354 "annium.y"
                 { }
#line 2683 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
#line 354 "annium.y"
                 { }
#line 2689 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
#line 354 "annium.y"
                 { }
#line 2695 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
#line 354 "annium.y"
                 { }
#line 2701 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
#line 354 "annium.y"
                 { }
#line 2707 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
#line 354 "annium.y"
                 { }
#line 2713 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
#line 354 "annium.y"
                 { }
#line 2719 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_grouped_expression: // grouped-expression
#line 354 "annium.y"
                 { }
#line 2725 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_new_expression: // new-expression
#line 354 "annium.y"
                 { }
#line 2731 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_call_expression: // call-expression
#line 354 "annium.y"
                 { }
#line 2737 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_syntax_expression: // syntax-expression
#line 354 "annium.y"
                 { }
#line 2743 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_match_expression: // match-expression
#line 354 "annium.y"
                 { }
#line 2749 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
#line 354 "annium.y"
                 { }
#line 2755 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_match_arm_list: // match-arm-list
#line 354 "annium.y"
                 { }
#line 2761 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_match_arm: // match-arm
#line 354 "annium.y"
                 { }
#line 2767 "annium.tab.cpp"
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
#line 354 "annium.y"
                 { }
#line 2773 "annium.tab.cpp"
        break;

      case symbol_kind::S_189_lambda_expression: // lambda-expression
#line 354 "annium.y"
                 { }
#line 2779 "annium.tab.cpp"
        break;

      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
#line 354 "annium.y"
                 { }
#line 2785 "annium.tab.cpp"
        break;

      case symbol_kind::S_191_pack_expression: // pack-expression
#line 354 "annium.y"
                 { }
#line 2791 "annium.tab.cpp"
        break;

      case symbol_kind::S_192_compound_expression: // compound-expression
#line 354 "annium.y"
                 { }
#line 2797 "annium.tab.cpp"
        break;

      case symbol_kind::S_193_type_expr: // type-expr
#line 354 "annium.y"
                 { }
#line 2803 "annium.tab.cpp"
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

      case symbol_kind::S_138_fn_name: // fn-name
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
      case symbol_kind::S_152_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_145_case_decl: // case-decl
        yylhs.value.emplace< enum_case > ();
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
      case symbol_kind::S_141_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_119_let_decl: // let-decl
      case symbol_kind::S_120_let_decl_start: // let-decl-start
      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_187_match_arm: // match-arm
        yylhs.value.emplace< match_arm > ();
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
      case symbol_kind::S_150_argument_list: // argument-list
      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_191_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_158_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
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
      case symbol_kind::S_PERCENT: // "`%`"
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
      case symbol_kind::S_MATCH: // "`match`"
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
      case symbol_kind::S_126_finished_statement: // finished-statement
      case symbol_kind::S_129_expression_statement: // expression-statement
      case symbol_kind::S_130_generic_statement: // generic-statement
      case symbol_kind::S_131_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_124_function_body: // function-body
      case symbol_kind::S_125_braced_statements: // braced-statements
      case symbol_kind::S_127_if_else_tail: // if-else-tail
      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
        yylhs.value.emplace< std::pair<resource_location, parameter::default_spec> > ();
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_166_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
        yylhs.value.emplace< std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ();
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
      case symbol_kind::S_144_case_list: // case-list
        yylhs.value.emplace< std::vector<enum_case> > ();
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
      case symbol_kind::S_154_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
      case symbol_kind::S_186_match_arm_list: // match-arm-list
        yylhs.value.emplace< std::vector<match_arm> > ();
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_180_grouped_expression: // grouped-expression
      case symbol_kind::S_181_new_expression: // new-expression
      case symbol_kind::S_182_call_expression: // call-expression
      case symbol_kind::S_183_syntax_expression: // syntax-expression
      case symbol_kind::S_184_match_expression: // match-expression
      case symbol_kind::S_189_lambda_expression: // lambda-expression
      case symbol_kind::S_192_compound_expression: // compound-expression
      case symbol_kind::S_193_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_148_expression_list: // expression-list
      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_170_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_168_pattern_list: // pattern-list
        yylhs.value.emplace< syntax_pattern_field_list_t > ();
        break;

      case symbol_kind::S_147_using_decl: // using-decl
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
#line 359 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3322 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 360 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3328 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 365 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3334 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 367 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3340 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 369 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3346 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 386 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3352 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 387 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3358 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 389 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3364 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 391 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3370 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 396 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3376 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 398 "annium.y"
        {
            yystack_[0].value.as < fn_pure > ().kind = fn_kind::EXTERN;
            if (!yystack_[0].value.as < fn_pure > ().result.index()) { // no declared result => implicitly void
                yystack_[0].value.as < fn_pure > ().result = ctx.make<syntax_expression>(yystack_[0].value.as < fn_pure > ().location, ctx.make_entity_identifier(builtin_eid::void_));
            }
            yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3389 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 407 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3395 "annium.tab.cpp"
    break;

  case 14: // let-decl: let-decl-start-with-opt-type
#line 411 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3401 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 413 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3407 "annium.tab.cpp"
    break;

  case 16: // let-decl-start: identifier
#line 418 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3413 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: "weak modifier" identifier
#line 420 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3419 "annium.tab.cpp"
    break;

  case 18: // let-decl-start-with-opt-type: let-decl-start
#line 424 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3425 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 426 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3431 "annium.tab.cpp"
    break;

  case 20: // infunction-statement-any: %empty
#line 431 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3437 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: infunction-statement
#line 433 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3443 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 435 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3449 "annium.tab.cpp"
    break;

  case 23: // finished-infunction-statement-any: finished-statement
#line 440 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3455 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 441 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3461 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 443 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3467 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 445 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3473 "annium.tab.cpp"
    break;

  case 27: // function-body: braced-statements
#line 450 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3479 "annium.tab.cpp"
    break;

  case 28: // function-body: "`=>`" syntax-expression
#line 454 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3485 "annium.tab.cpp"
    break;

  case 29: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 465 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3491 "annium.tab.cpp"
    break;

  case 30: // finished-statement: INCLUDE STRING
#line 470 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3497 "annium.tab.cpp"
    break;

  case 31: // finished-statement: "`while`" syntax-expression braced-statements
#line 472 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3503 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 474 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3509 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 476 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3515 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`if`" syntax-expression braced-statements
#line 478 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3521 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 480 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3527 "annium.tab.cpp"
    break;

  case 36: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 482 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3537 "annium.tab.cpp"
    break;

  case 37: // finished-statement: ENUM enum-decl
#line 492 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3543 "annium.tab.cpp"
    break;

  case 38: // finished-statement: STRUCT struct-decl
#line 494 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3549 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 499 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3555 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 501 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3561 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 505 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3567 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 506 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3573 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 511 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3579 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 513 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3588 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 521 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3594 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 523 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3600 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 525 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3611 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 532 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3617 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 533 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3623 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 537 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3629 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 539 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3635 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 541 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3641 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 543 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3647 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 545 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3653 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 547 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3659 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 552 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3665 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 560 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3671 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 575 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3677 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 577 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3683 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 579 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3689 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 584 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3695 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 585 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3701 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 589 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3707 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 590 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3713 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 595 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3719 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 597 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3725 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 602 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3731 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 604 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3737 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 609 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3743 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 626 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3749 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 629 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3755 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 640 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3761 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 642 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3767 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 644 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3773 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 651 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<enum_case>(yystack_[1].value.as < std::vector<enum_case> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3779 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 655 "annium.y"
             { yylhs.value.as < std::vector<enum_case> > () = {}; }
#line 3785 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 656 "annium.y"
      { yylhs.value.as < std::vector<enum_case> > () = yystack_[0].value.as < std::vector<enum_case> > (); }
#line 3791 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 661 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::vector<enum_case>{ std::move(yystack_[0].value.as < enum_case > ()) }; }
#line 3797 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 663 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::move(yystack_[2].value.as < std::vector<enum_case> > ()); yylhs.value.as < std::vector<enum_case> > ().emplace_back(std::move(yystack_[0].value.as < enum_case > ())); }
#line 3803 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 668 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[0].value.as < annotated_identifier > ().value }; }
#line 3809 "annium.tab.cpp"
    break;

  case 81: // case-decl: identifier "`(`" field-list-opt "`)`"
#line 670 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[3].value.as < annotated_identifier > ().value, .fields = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3815 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 676 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3821 "annium.tab.cpp"
    break;

  case 83: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 678 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3827 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`=>`" syntax-expression
#line 701 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3837 "annium.tab.cpp"
    break;

  case 85: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 707 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3848 "annium.tab.cpp"
    break;

  case 86: // expression-list: syntax-expression
#line 724 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3854 "annium.tab.cpp"
    break;

  case 87: // expression-list: expression-list "," syntax-expression
#line 726 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3860 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: %empty
#line 731 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3866 "annium.tab.cpp"
    break;

  case 89: // argument-list-opt: argument-list
#line 732 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3872 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument
#line 737 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3878 "annium.tab.cpp"
    break;

  case 91: // argument-list: argument-list "," argument
#line 739 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3884 "annium.tab.cpp"
    break;

  case 92: // argument: argument-name syntax-expression
#line 744 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3890 "annium.tab.cpp"
    break;

  case 93: // argument: syntax-expression
#line 746 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3896 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`=`"
#line 751 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3902 "annium.tab.cpp"
    break;

  case 95: // argument-name: identifier "`:`"
#line 753 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3908 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: %empty
#line 758 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3914 "annium.tab.cpp"
    break;

  case 97: // field-list-opt: field-list
#line 759 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3920 "annium.tab.cpp"
    break;

  case 98: // field-list: field
#line 764 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3926 "annium.tab.cpp"
    break;

  case 99: // field-list: field-list "," field
#line 766 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3932 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: %empty
#line 770 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3938 "annium.tab.cpp"
    break;

  case 101: // field-default-value-opt: "`=`" syntax-expression
#line 771 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3944 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`:`" type-expr field-default-value-opt
#line 776 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3950 "annium.tab.cpp"
    break;

  case 103: // field: identifier "`=>`" syntax-expression
#line 778 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3956 "annium.tab.cpp"
    break;

  case 104: // field: type-expr field-default-value-opt
#line 783 "annium.y"
        { yylhs.value.as < field > () = field{ .name = annotated_identifier{}, .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3962 "annium.tab.cpp"
    break;

  case 105: // parameter-list-opt: %empty
#line 789 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3968 "annium.tab.cpp"
    break;

  case 106: // parameter-list-opt: parameter-list
#line 790 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3974 "annium.tab.cpp"
    break;

  case 107: // parameter-list: parameter-decl
#line 795 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3980 "annium.tab.cpp"
    break;

  case 108: // parameter-list: parameter-list "," parameter-decl
#line 797 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3986 "annium.tab.cpp"
    break;

  case 109: // internal-identifier-opt: %empty
#line 801 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3992 "annium.tab.cpp"
    break;

  case 110: // internal-identifier-opt: internal-identifier
#line 802 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3998 "annium.tab.cpp"
    break;

  case 111: // parameter-default-value-opt: %empty
#line 806 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 4004 "annium.tab.cpp"
    break;

  case 112: // parameter-default-value-opt: "`=`" syntax-expression
#line 807 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4010 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: %empty
#line 811 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 4016 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`"
#line 812 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 4022 "annium.tab.cpp"
    break;

  case 115: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 813 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4028 "annium.tab.cpp"
    break;

  case 116: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 814 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4034 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 820 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4040 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 824 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4046 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 830 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4052 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 832 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4062 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 839 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4071 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 845 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 4081 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 851 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4087 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 853 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 4093 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 855 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 4099 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 857 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4105 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 860 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4111 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 862 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4120 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 867 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4126 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 869 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4132 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: pattern-mod parameter-default-value-opt
#line 871 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4138 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 879 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4147 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 884 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4156 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 889 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4165 "annium.tab.cpp"
    break;

  case 135: // parameter-decl: "`...`" parameter-default-value-opt
#line 894 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4171 "annium.tab.cpp"
    break;

  case 136: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 899 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4177 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified-mod: "constexpr modifier"
#line 905 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4183 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified-mod: "runctime modifier"
#line 906 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4189 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 911 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4195 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 913 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4201 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-specified: constraint-expression-specified-mod
#line 917 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4207 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 919 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4213 "annium.tab.cpp"
    break;

  case 143: // constraint-expression-mod: %empty
#line 924 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4222 "annium.tab.cpp"
    break;

  case 144: // constraint-expression-mod: constraint-expression-specified-mod
#line 928 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4228 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod type-expr
#line 933 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4234 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 935 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4240 "annium.tab.cpp"
    break;

  case 147: // constraint-expression: constraint-expression-mod
#line 939 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4246 "annium.tab.cpp"
    break;

  case 148: // constraint-expression: constraint-expression-mod "`...`"
#line 941 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4252 "annium.tab.cpp"
    break;

  case 149: // subpatterns: "`(`" pattern-list "`)`"
#line 951 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4258 "annium.tab.cpp"
    break;

  case 150: // pattern-list: pattern-field
#line 956 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4264 "annium.tab.cpp"
    break;

  case 151: // pattern-list: pattern-list "," pattern-field
#line 958 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4270 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: concept-expression-list-opt
#line 964 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4276 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 966 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4282 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 969 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4288 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 971 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4294 "annium.tab.cpp"
    break;

  case 156: // pattern-field-sfx: "`=`" pattern-sfx
#line 975 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4300 "annium.tab.cpp"
    break;

  case 157: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 978 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4306 "annium.tab.cpp"
    break;

  case 158: // pattern-field: identifier pattern-field-sfx
#line 984 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4312 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 987 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4318 "annium.tab.cpp"
    break;

  case 160: // pattern-field: pattern-field-sfx
#line 1000 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4324 "annium.tab.cpp"
    break;

  case 161: // pattern-field: "`_`" pattern-field-sfx
#line 1003 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4330 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" pattern-sfx
#line 1007 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type, static_cast<syntax_expression const*>(nullptr) }; }
#line 4336 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 1008 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4342 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 1009 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4348 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "`~`" "reference modifier" pattern-sfx
#line 1010 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4354 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "`~`" "reference modifier" "`(`" syntax-expression "`)`" pattern-sfx
#line 1017 "annium.y"
        { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4360 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "consteval modifier" syntax-expression
#line 1018 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4366 "annium.tab.cpp"
    break;

  case 168: // pattern-mod: "typename modifier" pattern-sfx
#line 1019 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4372 "annium.tab.cpp"
    break;

  case 169: // pattern-mod: "typename modifier"
#line 1020 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; }
#line 4378 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: pattern
#line 1024 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4384 "annium.tab.cpp"
    break;

  case 171: // pattern-sfx: pattern "`...`"
#line 1025 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4390 "annium.tab.cpp"
    break;

  case 172: // pattern-sfx: "`...`"
#line 1026 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4396 "annium.tab.cpp"
    break;

  case 173: // pattern: qname
#line 1031 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4402 "annium.tab.cpp"
    break;

  case 174: // pattern: qname subpatterns concept-expression-list-opt
#line 1033 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4408 "annium.tab.cpp"
    break;

  case 175: // pattern: internal-identifier concept-expression-list-opt
#line 1035 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4414 "annium.tab.cpp"
    break;

  case 176: // pattern: "`_`" concept-expression-list-opt
#line 1037 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4420 "annium.tab.cpp"
    break;

  case 177: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1039 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4426 "annium.tab.cpp"
    break;

  case 178: // pattern: "`(`" "`)`"
#line 1041 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4432 "annium.tab.cpp"
    break;

  case 179: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1043 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4438 "annium.tab.cpp"
    break;

  case 180: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1045 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4444 "annium.tab.cpp"
    break;

  case 181: // pattern: concept-expression-list
#line 1047 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4450 "annium.tab.cpp"
    break;

  case 182: // concept-expression: "`@`" qname
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4456 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list-opt: %empty
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4462 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list-opt: concept-expression-list
#line 1058 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4468 "annium.tab.cpp"
    break;

  case 185: // concept-expression-list: concept-expression
#line 1063 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4474 "annium.tab.cpp"
    break;

  case 186: // concept-expression-list: concept-expression-list concept-expression
#line 1065 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4480 "annium.tab.cpp"
    break;

  case 187: // reference-expression: CONTEXT_IDENTIFIER
#line 1071 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4486 "annium.tab.cpp"
    break;

  case 188: // reference-expression: qname
#line 1073 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4492 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: RESERVED_IDENTIFIER
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4498 "annium.tab.cpp"
    break;

  case 190: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4504 "annium.tab.cpp"
    break;

  case 191: // any-reference-expression: qname
#line 1082 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4510 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "nil"
#line 1087 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4516 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: "true"
#line 1089 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4522 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: "false"
#line 1091 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4528 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: INTEGER
#line 1093 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4534 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: DECIMAL
#line 1095 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4540 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: DECIMAL_S
#line 1097 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4546 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: INTEGER_INDEX
#line 1099 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4552 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: STRING
#line 1101 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4558 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: CT_IDENTIFIER
#line 1103 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4564 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: any-reference-expression
#line 1104 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4570 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`(`" "`)`"
#line 1106 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4576 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1108 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4585 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1114 "annium.y"
        {
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4597 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1125 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4603 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1127 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4609 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1129 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4615 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: PROBE braced-statements
#line 1131 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4621 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`.`" identifier
#line 1133 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4627 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1140 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4637 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`-`" syntax-expression
#line 1147 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4643 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1149 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4649 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1163 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4655 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: "`!`" syntax-expression
#line 1165 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4661 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: "`*`" syntax-expression
#line 1167 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4667 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1170 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4673 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1172 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4679 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`%`" syntax-expression
#line 1174 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MOD, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4685 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1178 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4691 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1180 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4697 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1184 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4703 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1186 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4709 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1188 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4715 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1190 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4721 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1192 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4727 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1194 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4733 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1196 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4739 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1199 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4745 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1203 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4751 "annium.tab.cpp"
    break;

  case 230: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1206 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4757 "annium.tab.cpp"
    break;

  case 231: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1209 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4763 "annium.tab.cpp"
    break;

  case 232: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1211 "annium.y"
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
#line 4778 "annium.tab.cpp"
    break;

  case 233: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1223 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4784 "annium.tab.cpp"
    break;

  case 234: // grouped-expression: "`(`" pack-expression "`)`"
#line 1243 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4797 "annium.tab.cpp"
    break;

  case 235: // new-expression: "`new`" qname
#line 1256 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4803 "annium.tab.cpp"
    break;

  case 236: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1260 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4809 "annium.tab.cpp"
    break;

  case 237: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1267 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4815 "annium.tab.cpp"
    break;

  case 238: // call-expression: any-reference-expression "`.`" identifier
#line 1269 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4821 "annium.tab.cpp"
    break;

  case 239: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1271 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4830 "annium.tab.cpp"
    break;

  case 240: // call-expression: STRING "`.`" identifier
#line 1286 "annium.y"
        {
            syntax_expression obj_expr{ yystack_[2].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[2].value.as < annium::annotated_string_view > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ obj_expr.location, member_expression{ ctx.make<syntax_expression>(std::move(obj_expr)), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 4839 "annium.tab.cpp"
    break;

  case 241: // call-expression: STRING "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1291 "annium.y"
        {
            syntax_expression obj_expr{ yystack_[5].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[5].value.as < annium::annotated_string_view > ().value) };
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(obj_expr)), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4849 "annium.tab.cpp"
    break;

  case 242: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1297 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4855 "annium.tab.cpp"
    break;

  case 243: // call-expression: call-expression "`.`" identifier
#line 1299 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4861 "annium.tab.cpp"
    break;

  case 244: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1301 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4870 "annium.tab.cpp"
    break;

  case 245: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1306 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4876 "annium.tab.cpp"
    break;

  case 246: // syntax-expression: syntax-expression-base
#line 1310 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4882 "annium.tab.cpp"
    break;

  case 247: // syntax-expression: new-expression
#line 1311 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4888 "annium.tab.cpp"
    break;

  case 248: // syntax-expression: compound-expression
#line 1312 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4894 "annium.tab.cpp"
    break;

  case 249: // syntax-expression: lambda-expression
#line 1313 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4900 "annium.tab.cpp"
    break;

  case 250: // syntax-expression: match-expression
#line 1314 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4906 "annium.tab.cpp"
    break;

  case 251: // syntax-expression: grouped-expression
#line 1315 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4912 "annium.tab.cpp"
    break;

  case 252: // match-expression: "`match`" syntax-expression "`{`" match-arm-list-opt "`}`"
#line 1331 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), match_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<match_arm>(yystack_[1].value.as < std::vector<match_arm> > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4918 "annium.tab.cpp"
    break;

  case 253: // match-arm-list-opt: %empty
#line 1335 "annium.y"
             { yylhs.value.as < std::vector<match_arm> > () = {}; }
#line 4924 "annium.tab.cpp"
    break;

  case 254: // match-arm-list-opt: match-arm-list
#line 1336 "annium.y"
      { yylhs.value.as < std::vector<match_arm> > () = yystack_[0].value.as < std::vector<match_arm> > (); }
#line 4930 "annium.tab.cpp"
    break;

  case 255: // match-arm-list: match-arm
#line 1360 "annium.y"
        { yylhs.value.as < std::vector<match_arm> > () = std::vector<match_arm>{ std::move(yystack_[0].value.as < match_arm > ()) }; }
#line 4936 "annium.tab.cpp"
    break;

  case 256: // match-arm-list: match-arm-list "," match-arm
#line 1362 "annium.y"
        { yylhs.value.as < std::vector<match_arm> > () = std::move(yystack_[2].value.as < std::vector<match_arm> > ()); yylhs.value.as < std::vector<match_arm> > ().emplace_back(std::move(yystack_[0].value.as < match_arm > ())); }
#line 4942 "annium.tab.cpp"
    break;

  case 257: // match-arm: pattern function-body
#line 1367 "annium.y"
        { yylhs.value.as < match_arm > () = match_arm{ .pattern = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ())), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) }; }
#line 4948 "annium.tab.cpp"
    break;

  case 258: // match-arm: internal-identifier "`:`" pattern function-body
#line 1369 "annium.y"
        { yylhs.value.as < match_arm > () = match_arm{ .bind_name = std::move(yystack_[3].value.as < context_identifier > ().name), .pattern = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ())), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) }; }
#line 4954 "annium.tab.cpp"
    break;

  case 259: // lambda-start-decl: fn-prefix-decl
#line 1374 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4960 "annium.tab.cpp"
    break;

  case 260: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1376 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4966 "annium.tab.cpp"
    break;

  case 261: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1381 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4977 "annium.tab.cpp"
    break;

  case 262: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1388 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4989 "annium.tab.cpp"
    break;

  case 263: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1396 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 5001 "annium.tab.cpp"
    break;

  case 264: // pack-expression-opt: %empty
#line 1407 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 5007 "annium.tab.cpp"
    break;

  case 265: // pack-expression-opt: pack-expression
#line 1409 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 5013 "annium.tab.cpp"
    break;

  case 266: // pack-expression: syntax-expression
#line 1414 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 5019 "annium.tab.cpp"
    break;

  case 267: // pack-expression: identifier "`:`" syntax-expression
#line 1416 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 5029 "annium.tab.cpp"
    break;

  case 268: // pack-expression: pack-expression "," syntax-expression
#line 1422 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 5038 "annium.tab.cpp"
    break;

  case 269: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1427 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 5047 "annium.tab.cpp"
    break;

  case 270: // compound-expression: syntax-expression "`...`"
#line 1435 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 5053 "annium.tab.cpp"
    break;

  case 271: // compound-expression: call-expression
#line 1436 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5059 "annium.tab.cpp"
    break;

  case 272: // type-expr: qname
#line 1477 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 5065 "annium.tab.cpp"
    break;

  case 273: // type-expr: RESERVED_IDENTIFIER
#line 1479 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 5071 "annium.tab.cpp"
    break;

  case 274: // type-expr: CONTEXT_IDENTIFIER
#line 1481 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 5077 "annium.tab.cpp"
    break;

  case 275: // type-expr: call-expression
#line 1482 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5083 "annium.tab.cpp"
    break;

  case 276: // type-expr: "`[`" type-expr "`]`"
#line 1484 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 5089 "annium.tab.cpp"
    break;

  case 277: // type-expr: "`(`" "`)`"
#line 1486 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 5095 "annium.tab.cpp"
    break;

  case 278: // type-expr: grouped-expression
#line 1487 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5101 "annium.tab.cpp"
    break;

  case 279: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1489 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 5107 "annium.tab.cpp"
    break;

  case 280: // type-expr: type-expr "`|`" type-expr
#line 1491 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 5113 "annium.tab.cpp"
    break;

  case 281: // type-expr: type-expr "`->`" type-expr
#line 1493 "annium.y"
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
#line 5128 "annium.tab.cpp"
    break;


#line 5132 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -364;

  const short parser::yytable_ninf_ = -192;

  const short
  parser::yypact_[] =
  {
    1024,    52,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
     173,  1133,  1156,   173,  1420,  1420,  1420,     7,   132,    37,
    1420,   312,  1420,  1420,    37,   177,  -364,  -364,  -364,     5,
      37,    37,  1420,   152,  -364,  -364,  -364,   189,   245,    17,
     696,  -364,  -364,  -364,  -364,  -364,   207,  -364,   291,    18,
     -15,  -364,   217,  -364,   126,  1565,  -364,   225,  -364,   248,
     173,  -364,  1420,  -364,   216,   240,  2035,   -13,  -364,   915,
     257,    57,  2035,  -364,    21,    21,    21,   173,  -364,   260,
     298,  -364,   173,     5,   118,  1509,  -364,   207,   246,  1612,
    1659,   309,  -364,  -364,  -364,   207,   272,  -364,    66,  -364,
     369,  -364,    21,  1420,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,   173,  -364,  -364,  1420,   429,   205,  1420,   173,
    1420,  1420,   173,  -364,  1420,   781,  1420,  1420,  1420,  1420,
    1420,  1420,  1420,  1420,  1420,  -364,  1420,  1420,  1420,  1420,
    1420,  1420,  1420,  1420,   781,   532,   278,  1706,  1420,  -364,
    1420,  -364,  -364,  1420,  1420,   277,   806,  -364,   286,  -364,
    -364,  -364,  -364,  1265,  -364,   781,  1420,   305,  -364,  1420,
    1420,  -364,  1420,   276,   460,  1420,   532,   532,   173,   316,
     532,  1753,  -364,   324,   299,   781,   460,  1420,  -364,   331,
     346,   354,    -5,   347,  2035,    52,   320,   423,  1288,   781,
     403,   -15,   217,   126,    11,   814,   814,   814,   814,   814,
     814,   657,  2082,   567,  1800,   402,   402,   269,   269,   269,
     705,   923,    25,  -364,    37,   391,   405,    -2,   781,   541,
     190,  -364,  1420,  -364,    12,   214,    34,   370,   356,  -364,
     891,   405,   405,  -364,   206,  1420,  -364,  2035,   377,  2035,
    2035,  2035,  -364,  -364,  -364,  -364,  -364,  -364,  2035,    25,
     299,   781,    98,   378,   362,  -364,  1420,  2035,   189,  1612,
     579,  -364,   160,   418,  1420,   273,   253,   244,   391,   431,
     414,  -364,  2035,   434,   438,   441,   437,   425,  -364,   781,
     444,  1420,  -364,    25,   391,  -364,  2035,  -364,  1420,  -364,
    -364,  1420,  -364,    41,   781,  1420,   781,  -364,   207,    19,
     391,  1420,  -364,   405,   262,  -364,   190,   190,   593,  -364,
     462,  -364,  2035,  -364,     4,    -7,    19,  1420,   487,  -364,
     392,   532,  -364,   206,   161,  -364,  -364,  -364,  -364,   455,
    1420,    25,  -364,  -364,  -364,  1420,  2035,  -364,  -364,  -364,
    -364,     5,   266,   391,  -364,  -364,  1847,   460,  -364,   391,
    1420,  -364,  -364,  -364,   460,   483,   406,   781,  -364,   173,
      99,   463,   445,  -364,    24,   494,    21,   465,   467,  -364,
      11,  1894,    11,  -364,  2035,  -364,    19,  -364,  -364,  1397,
    -364,  -364,    -7,   471,   391,   792,   405,   405,   206,  -364,
    2035,  1420,   781,   460,  -364,  -364,  -364,  -364,  -364,  2035,
    -364,   189,   190,   317,   513,   317,   440,   200,  -364,  -364,
     486,  -364,   160,   244,  -364,  2035,  -364,  1420,   476,  -364,
     477,  -364,  1420,   781,  -364,   781,  1420,  -364,   479,  -364,
    -364,  -364,  -364,  1941,   391,   405,   405,   453,   329,   453,
    -364,   243,  -364,  -364,  -364,  2035,   352,   244,  -364,  -364,
     317,  -364,   190,   495,  -364,   266,  -364,   391,  -364,  -364,
    2035,  1420,  -364,  2035,    24,  -364,  2035,   781,   190,   453,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  1988,  -364,   480,  -364,  -364,
    -364,  -364
  };

  const short
  parser::yydefact_[] =
  {
       4,   199,    56,   190,   189,   198,   195,   196,   197,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    65,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
       0,     5,     7,    49,    13,    59,   191,    63,     0,   259,
     201,   246,   251,   247,   271,     0,   250,     0,   249,   248,
       0,    58,     0,   202,    59,   259,   266,     0,   248,    20,
       0,     0,    86,   209,   211,   215,   214,     0,    45,    18,
      14,    16,     0,     0,   235,     0,   187,   188,     0,     0,
       0,     0,    48,    30,    68,    67,     0,    46,     0,    37,
       0,    38,   212,     0,   208,     1,     2,    10,     3,     8,
       6,     9,     0,    66,    64,   264,    72,     0,   264,     0,
     264,     0,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   240,     0,     0,   234,
       0,    52,    51,    53,     0,    41,    42,    23,     0,    50,
      21,   206,   204,     0,    17,     0,     0,     0,    12,    88,
       0,    31,     0,    34,   253,     0,   105,   105,    76,     0,
     105,     0,    60,     0,   265,     0,     0,     0,    36,     0,
     238,     0,     0,   243,    44,     0,   274,   273,     0,     0,
     272,     0,   278,   275,   232,   221,   222,   223,   224,   225,
     226,   230,   231,   227,     0,   219,   220,   216,   217,   218,
     228,   229,   233,    57,     0,   183,   111,     0,     0,     0,
     169,   137,     0,   138,    59,   183,   113,     0,   106,   107,
     141,   111,   111,   185,   113,   264,   203,   267,    59,   268,
      54,    55,    26,    24,    25,    22,    29,   205,    87,    19,
      15,     0,    59,     0,    89,    90,     0,    93,     0,     0,
       0,    35,   183,     0,     0,   183,   173,     0,   181,     0,
     254,   255,    84,     0,     0,    80,     0,    77,    78,    96,
       0,     0,   260,    73,   183,    74,    47,   237,   264,   245,
     242,   264,   277,     0,     0,     0,     0,   207,   182,   113,
     184,     0,   135,   111,     0,   172,     0,     0,     0,   162,
     170,   168,   167,   110,     0,   143,   113,     0,   114,   122,
       0,     0,   142,   113,   139,   119,   131,   134,   186,     0,
       0,    11,    94,    95,   236,     0,    92,    32,    33,    39,
      40,     0,   183,   183,   176,   178,     0,     0,   175,   183,
       0,   257,    27,   252,     0,     0,    70,    96,    75,     0,
      59,     0,    97,    98,   100,     0,   213,     0,     0,   276,
     281,     0,   280,   133,   112,   130,   113,   163,   164,     0,
     165,   171,   143,     0,   144,   147,   111,   111,   113,   132,
     115,     0,     0,     0,   261,   108,   121,   140,   241,   269,
      91,     0,     0,   183,     0,   183,   183,     0,   160,   150,
     152,   177,   183,     0,   174,    28,   256,     0,     0,    69,
       0,    79,     0,     0,    82,     0,     0,   104,     0,   239,
     244,   279,   120,     0,   144,   111,   111,   111,   143,   111,
     148,   145,   118,   127,   128,   116,     0,     0,   156,   161,
     183,   158,     0,   154,   149,   183,   153,   183,   179,   258,
      85,     0,    81,   103,   100,    99,   101,    96,     0,   111,
     117,   123,   124,   144,   136,   126,   129,   146,   262,   263,
     159,   157,   155,   151,   180,     0,   102,     0,   166,   125,
      71,    83
  };

  const short
  parser::yypgoto_[] =
  {
    -364,  -364,  -364,  -364,   493,  -364,  -364,  -364,  -364,  -364,
    -312,    -9,   -33,  -364,  -364,   371,   -42,   388,    40,   204,
     170,   497,  -364,     1,  -364,   522,  -364,   -81,  -364,  -364,
    -364,   184,  -364,  -364,  -364,  -364,  -364,   209,  -364,  -361,
    -364,    81,   122,   265,  -364,  -364,    51,    42,   229,  -299,
    -364,  -364,  -363,  -271,  -364,  -294,    96,  -218,  -226,  -153,
     -56,  -188,   366,  -364,    48,  -364,    59,  -364,   218,     0,
    -364,  -364,  -364,   198,  -364,  -364,   -52,    14,     8,    70
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    38,    39,    40,    41,    78,    79,    80,   155,   156,
     361,   362,    42,   271,   158,    43,    44,   160,    45,   294,
      46,    47,    48,    65,    96,   116,   429,   117,    99,   286,
     287,   288,   101,    92,    71,   263,   264,   265,   266,   371,
     372,   437,   373,   237,   238,   324,   312,   329,   239,   240,
     241,   395,   396,   353,   417,   418,   419,   242,   319,   320,
     243,   420,   310,    88,    50,    51,    52,    53,    54,    66,
      56,   279,   280,   281,    57,    58,   183,   184,    68,   374
  };

  const short
  parser::yytable_[] =
  {
      55,    49,   168,    70,   321,   359,   430,   111,    59,   313,
     224,     2,    72,     2,    74,    75,    76,   106,   404,   223,
      85,   277,    89,    90,     2,    67,   394,   159,   104,   445,
     123,   304,   102,   295,   327,   118,   157,   309,   149,   436,
      55,    49,   119,     2,   304,   304,   300,   326,    59,   327,
      61,    64,   392,    73,    10,   150,   328,    81,   135,   229,
    -109,   304,   147,   150,   229,   305,   189,    10,   191,    55,
      49,   328,   115,   107,   393,   136,   171,    59,   305,   305,
     173,    94,  -109,   112,   354,   484,    10,   358,   306,   306,
     387,   388,   390,   444,    94,   305,   379,   230,   231,   232,
     146,   233,   230,   181,   232,   306,   358,   397,   188,    60,
      77,   469,   162,   342,   159,   112,   497,   164,   178,   459,
     432,   461,   167,   254,   194,   163,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   192,   214,   215,   216,   217,
     218,   219,   220,   221,   488,   489,   343,   433,   247,   483,
     249,   467,   182,   250,   251,    64,    55,    49,    64,   190,
      64,    64,   193,   258,    59,   421,   490,   112,   169,   267,
      55,   424,   269,   201,   446,   282,   121,   224,    59,     2,
     260,   304,    93,   122,   202,   234,   458,   296,   338,    84,
     248,    87,   201,   339,    91,   204,     2,   223,   407,    95,
      98,   100,   103,   202,   423,    82,    64,   224,   272,   262,
     352,   277,    67,   201,   222,   305,   234,   234,   285,    95,
     234,   327,   338,   224,   202,   306,   187,   315,   463,    83,
     485,   224,   322,   201,   468,   259,   491,   350,    64,    10,
     273,    69,   274,   328,   202,   105,   377,   201,   -43,   378,
     457,   464,   498,    95,   338,   293,   112,    69,   202,   347,
     348,   349,   325,   304,   148,   360,   346,   120,   465,   303,
     411,   351,     2,   223,   356,   145,   201,   338,   123,   494,
     487,   412,   304,   224,   413,    64,   337,   202,   201,   125,
     224,   376,   335,   336,   115,   200,    69,   305,   314,   202,
     -43,   -43,   112,   352,   -43,   381,   135,   306,   165,   201,
     334,   384,   161,   166,   200,   236,   305,   386,     2,    86,
     202,   357,   177,   136,   223,   172,   306,   400,   245,   370,
     175,   341,   412,   252,   224,   200,   414,   201,    64,   256,
     409,    64,   338,   203,   276,   267,   236,   236,   202,   235,
     236,   383,   201,   261,   201,   200,   276,   270,   112,   176,
     425,    10,   203,   202,   385,   202,   289,   150,   399,   200,
    -190,   234,   304,   360,   380,   406,   382,  -190,   275,   292,
     235,   235,   297,   203,   235,   262,    26,    27,   113,   443,
     179,   338,   415,   338,   308,   229,   298,   301,   200,   276,
     276,   455,   188,   203,    69,   299,   305,   370,   224,   285,
     200,   123,   402,   360,   403,   201,   306,   203,   112,   180,
     311,   330,   125,   338,   331,   340,   202,   470,   442,   344,
     345,   200,   473,   230,   231,   232,   476,   233,   323,   135,
     454,   283,   284,   201,    69,   290,   203,   452,   453,   185,
     201,   186,   112,  -191,   202,   462,   136,   224,   203,   200,
    -191,   202,   139,   140,   141,   451,     2,   223,   311,   355,
     224,   495,   456,  -189,   200,   370,   200,   224,   272,   203,
    -189,   201,   364,   201,   363,   365,   276,   276,   276,   366,
     368,   367,   202,   369,   202,   375,   480,   481,   482,   391,
     486,   236,   401,   474,   427,   415,   408,   203,   428,    10,
     273,   244,   274,   435,   434,   438,   439,   370,   440,   448,
     223,    95,   203,   466,   203,   201,   471,   276,   472,   477,
     499,   501,   492,   110,   276,   235,   202,   200,     2,   223,
     278,   268,   244,   244,   255,   114,   244,     2,   223,   224,
     225,    97,   278,   431,   410,   496,   416,   475,   224,   272,
     405,   493,   426,     0,     0,   200,     0,     0,   275,   226,
       0,     0,   200,   276,     0,     0,   123,     0,   315,     0,
     227,    10,   276,     0,     0,   203,   228,   125,     0,     0,
      10,   273,     0,   274,     0,   278,   278,     0,   229,     2,
     223,     0,     0,   200,   135,   200,   333,     0,     0,     0,
     224,   272,     0,   203,     0,     0,     0,   416,   460,   416,
     203,   136,     0,     0,     0,   137,   138,   139,   140,   141,
     315,    69,   276,     0,     0,     0,   230,   231,   232,     0,
     233,     0,    10,   389,     0,   274,   316,   200,   276,   317,
     318,   203,     0,   203,     0,     0,    20,    21,     0,    22,
       0,     0,     0,     0,   416,     0,   123,     0,     0,   416,
       0,     0,     0,    25,    26,    27,    28,   125,    30,    31,
       0,     0,   278,   278,   278,   126,   127,   128,   129,   130,
     131,   398,     0,   134,   135,   203,   108,   244,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,   136,     0,     0,   123,   137,   138,   139,   140,   141,
     142,   143,     0,   278,     0,   125,     0,     0,     0,     0,
     278,     0,     0,   126,   127,   128,   129,   130,   131,     0,
       0,   134,   135,     0,     0,    10,    11,     0,     0,     0,
      12,     0,   109,    13,     0,    14,    15,     0,   447,   136,
     449,    16,     0,   137,   138,   139,   140,   141,    17,   278,
       0,    18,    19,    20,    21,     0,    22,     0,   278,     0,
       0,     0,    23,     0,    24,     0,   195,     2,   196,   197,
      25,    26,    27,    28,    29,    30,    31,   195,     2,   196,
     197,     0,    32,    33,     0,     0,    34,    35,    36,    37,
     479,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,   123,     0,     0,     0,     0,   278,   450,
      10,   198,     0,     0,   125,   199,     0,     0,     0,     0,
       0,    10,   198,     0,   278,     0,   199,     0,     0,     0,
     134,   135,     0,     0,     0,    10,    11,     0,     0,     0,
      12,     0,   253,    13,     0,    14,    15,     0,   136,     0,
       0,    16,   137,   138,   139,   140,   141,     0,    17,     0,
       0,     0,    19,    20,    21,     0,    22,     0,   151,   152,
     153,   154,    23,     0,    24,     0,   195,     2,   196,   197,
      25,    26,    27,    28,    29,    30,    31,     0,   224,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,    37,
       1,     2,     3,     4,     5,     6,     7,     8,   332,     9,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
      10,   198,     0,   125,     0,   199,     0,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,     0,     0,   134,
     135,     0,     0,     0,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    15,     0,   136,     0,     0,
      16,   137,   138,   139,   140,   141,   142,    17,     0,     0,
       0,    19,    20,    21,     0,    22,     0,   151,   152,   153,
     154,    23,     0,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,    12,     0,
       0,    13,     0,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,    17,     0,     0,    18,
      19,    20,    21,     0,    22,     0,     0,     0,     0,     0,
      23,     0,    24,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    10,    11,    63,     0,     0,    12,     0,     0,
      13,     0,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,    10,    11,     0,    69,    19,
      12,     0,     0,    13,     0,    14,    15,     0,     0,    23,
       0,    16,     0,     0,     0,     0,     0,     0,    26,    27,
      28,     0,    19,     0,     0,     0,     0,     0,     0,    32,
      33,     0,    23,    34,    35,    36,    37,     0,     0,     0,
       0,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,    37,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,    12,
     257,     0,    13,     0,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    10,    11,   302,
       0,    19,    12,     0,     0,    13,     0,    14,    15,     0,
       0,    23,     0,    16,     0,     0,     0,     0,     0,     0,
      26,    27,    28,     0,    19,     0,     0,     0,     0,     0,
       0,    32,    33,     0,    23,    34,    35,    36,    37,     0,
       0,     0,     0,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,    37,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,   355,     0,
       0,    12,     0,     0,    13,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,    19,    12,     0,     0,    13,     0,    14,
      15,     0,     0,    23,     0,    16,     0,     0,     0,     0,
       0,     0,    26,    27,    28,     0,    19,     0,     0,     0,
       0,     0,     0,    32,    33,     0,    23,    34,    35,    36,
      37,     0,     0,     0,     0,    26,    27,    28,   123,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,   125,
      34,    35,    36,    37,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,   136,     0,   170,     0,   137,   138,   139,
     140,   141,   142,   143,   123,     0,     0,     0,     0,     0,
     124,     0,     0,   144,     0,   125,     0,     0,     0,     0,
       0,     0,     0,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   123,     0,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   125,     0,     0,     0,     0,     0,     0,   144,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,   136,     0,   123,     0,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   125,
       0,     0,     0,     0,     0,     0,   144,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,   136,     0,   123,     0,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   125,     0,     0,     0,
       0,     0,     0,   144,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,     0,     0,
     136,     0,   123,     0,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   125,     0,     0,     0,     0,     0,     0,
     144,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,   136,     0,   123,
       0,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     125,     0,     0,     0,     0,     0,     0,   144,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   307,   123,     0,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   125,     0,     0,
       0,     0,     0,     0,   144,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     422,   136,     0,   123,     0,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   125,     0,     0,     0,     0,     0,
       0,   144,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   441,
     123,     0,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   125,     0,     0,     0,     0,     0,     0,   144,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   478,     0,     0,   136,     0,   123,     0,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   125,     0,
       0,     0,     0,     0,     0,   144,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,   136,     0,   123,     0,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   125,     0,     0,     0,     0,
       0,     0,   144,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   123,     0,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   125,     0,     0,     0,     0,     0,     0,   144,
     126,   127,   128,   129,   130,   131,   132,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143
  };

  const short
  parser::yycheck_[] =
  {
       0,     0,    83,    12,   230,   276,   367,    40,     0,   227,
      17,     6,    12,     6,    14,    15,    16,     0,   330,     7,
      20,   174,    22,    23,     6,    11,   325,    69,    37,   392,
       9,    20,    32,   186,    15,    50,    69,   225,    51,    15,
      40,    40,    57,     6,    20,    20,    51,   235,    40,    15,
      10,    11,    48,    13,    49,    68,    37,    17,    37,    66,
      48,    20,    62,    68,    66,    54,   118,    49,   120,    69,
      69,    37,    54,    56,    70,    54,    85,    69,    54,    54,
      89,    76,    70,    49,   272,   448,    49,   275,    64,    64,
     316,   317,   318,   392,    76,    54,    55,   104,   105,   106,
      60,   108,   104,   103,   106,    64,   294,   325,   117,    57,
     103,   423,    55,    15,   156,    49,   477,    77,    52,   413,
      21,   415,    82,   156,   124,    68,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   121,   136,   137,   138,   139,
     140,   141,   142,   143,   456,   457,    48,    48,   148,   448,
     150,   422,   112,   153,   154,   115,   156,   156,   118,   119,
     120,   121,   122,   163,   156,   353,   460,    49,    50,   169,
     170,   359,   172,   125,   392,   175,    50,    17,   170,     6,
     166,    20,     5,    57,   125,   145,   412,   187,   244,    19,
     150,    21,   144,   245,    24,   125,     6,     7,    37,    29,
      30,    31,    50,   144,   357,    73,   166,    17,    18,   169,
      50,   364,   198,   165,   144,    54,   176,   177,   178,    49,
     180,    15,   278,    17,   165,    64,    21,    37,   416,    97,
     448,    17,   232,   185,   422,   165,   462,   270,   198,    49,
      50,    52,    52,    37,   185,     0,   298,   199,     0,   301,
     403,    51,   478,    83,   310,   185,    49,    52,   199,   268,
     269,   270,    48,    20,    48,    21,   266,    50,    68,   199,
     351,   270,     6,     7,   274,    50,   228,   333,     9,   467,
      37,    15,    20,    17,    18,   245,   244,   228,   240,    20,
      17,   291,   241,   242,    54,   125,    52,    54,   228,   240,
      52,    53,    49,    50,    56,   305,    37,    64,    48,   261,
     240,   311,    55,    15,   144,   145,    54,    55,     6,     7,
     261,    48,    50,    54,     7,    79,    64,   327,    50,   289,
      21,   261,    15,    56,    17,   165,    70,   289,   298,    53,
     340,   301,   398,   125,   174,   345,   176,   177,   289,   145,
     180,   309,   304,    48,   306,   185,   186,    81,    49,    50,
     360,    49,   144,   304,   313,   306,    50,    68,   326,   199,
      50,   331,    20,    21,   304,   333,   306,    57,   174,    55,
     176,   177,    51,   165,   180,   345,    95,    96,    97,   389,
      21,   447,   352,   449,   224,    66,    50,    50,   228,   229,
     230,   401,   411,   185,    52,    51,    54,   367,    17,   369,
     240,     9,    20,    21,    22,   367,    64,   199,    49,    50,
      15,    51,    20,   479,    68,    48,   367,   427,   386,    51,
      68,   261,   432,   104,   105,   106,   436,   108,   234,    37,
     398,   176,   177,   395,    52,   180,   228,   396,   397,    20,
     402,    22,    49,    50,   395,    15,    54,    17,   240,   289,
      57,   402,    60,    61,    62,   395,     6,     7,    15,    51,
      17,   471,   402,    50,   304,   435,   306,    17,    18,   261,
      57,   433,    68,   435,    53,    51,   316,   317,   318,    51,
      53,    50,   433,    68,   435,    51,   445,   446,   447,    37,
     449,   331,    15,   433,    21,   465,    51,   289,   102,    49,
      50,   145,    52,    68,    51,    21,    51,   477,    51,    48,
       7,   351,   304,    37,   306,   477,    50,   357,    51,    50,
     479,    51,    37,    40,   364,   331,   477,   367,     6,     7,
     174,   170,   176,   177,   156,    48,   180,     6,     7,    17,
      18,    29,   186,   369,   345,   474,   352,   435,    17,    18,
     331,   465,   364,    -1,    -1,   395,    -1,    -1,   364,    37,
      -1,    -1,   402,   403,    -1,    -1,     9,    -1,    37,    -1,
      48,    49,   412,    -1,    -1,   367,    54,    20,    -1,    -1,
      49,    50,    -1,    52,    -1,   229,   230,    -1,    66,     6,
       7,    -1,    -1,   433,    37,   435,   240,    -1,    -1,    -1,
      17,    18,    -1,   395,    -1,    -1,    -1,   413,   414,   415,
     402,    54,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      37,    52,   462,    -1,    -1,    -1,   104,   105,   106,    -1,
     108,    -1,    49,    50,    -1,    52,   105,   477,   478,   108,
     109,   433,    -1,   435,    -1,    -1,    77,    78,    -1,    80,
      -1,    -1,    -1,    -1,   460,    -1,     9,    -1,    -1,   465,
      -1,    -1,    -1,    94,    95,    96,    97,    20,    99,   100,
      -1,    -1,   316,   317,   318,    28,    29,    30,    31,    32,
      33,   325,    -1,    36,    37,   477,     0,   331,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    54,    -1,    -1,     9,    58,    59,    60,    61,    62,
      63,    64,    -1,   357,    -1,    20,    -1,    -1,    -1,    -1,
     364,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    37,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    57,    -1,    59,    60,    -1,   392,    54,
     394,    65,    -1,    58,    59,    60,    61,    62,    72,   403,
      -1,    75,    76,    77,    78,    -1,    80,    -1,   412,    -1,
      -1,    -1,    86,    -1,    88,    -1,     5,     6,     7,     8,
      94,    95,    96,    97,    98,    99,   100,     5,     6,     7,
       8,    -1,   106,   107,    -1,    -1,   110,   111,   112,   113,
     444,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,     9,    -1,    -1,    -1,    -1,   462,    37,
      49,    50,    -1,    -1,    20,    54,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,   478,    -1,    54,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    54,    -1,
      -1,    65,    58,    59,    60,    61,    62,    -1,    72,    -1,
      -1,    -1,    76,    77,    78,    -1,    80,    -1,    82,    83,
      84,    85,    86,    -1,    88,    -1,     5,     6,     7,     8,
      94,    95,    96,    97,    98,    99,   100,    -1,    17,    -1,
      -1,    -1,   106,   107,    -1,    -1,   110,   111,   112,   113,
       5,     6,     7,     8,     9,    10,    11,    12,    37,    14,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    20,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    54,    -1,    -1,
      65,    58,    59,    60,    61,    62,    63,    72,    -1,    -1,
      -1,    76,    77,    78,    -1,    80,    -1,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    -1,   110,   111,   112,   113,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    75,
      76,    77,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
     106,   107,    -1,    -1,   110,   111,   112,   113,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,    76,
      54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,    86,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,    -1,    86,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,    -1,    -1,   110,   111,   112,   113,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      -1,    76,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    86,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    86,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,   110,   111,
     112,   113,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    76,    54,    -1,    -1,    57,    -1,    59,
      60,    -1,    -1,    86,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,    -1,    86,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    95,    96,    97,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    20,
     110,   111,   112,   113,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,     9,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    74,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,     9,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,     9,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,     9,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,     9,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,     9,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,     9,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,     9,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
       9,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,     9,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,     9,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,     9,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      49,    50,    54,    57,    59,    60,    65,    72,    75,    76,
      77,    78,    80,    86,    88,    94,    95,    96,    97,    98,
      99,   100,   106,   107,   110,   111,   112,   113,   115,   116,
     117,   118,   126,   129,   130,   132,   134,   135,   136,   137,
     178,   179,   180,   181,   182,   183,   184,   188,   189,   192,
      57,   132,    48,    51,   132,   137,   183,   191,   192,    52,
     125,   148,   183,   132,   183,   183,   183,   103,   119,   120,
     121,   132,    73,    97,   134,   183,     7,   134,   177,   183,
     183,   134,   147,     5,    76,   134,   138,   139,   134,   142,
     134,   146,   183,    50,   125,     0,     0,    56,     0,    56,
     118,   126,    49,    97,   135,    54,   139,   141,    50,    57,
      50,    50,    57,     9,    15,    20,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    54,    58,    59,    60,
      61,    62,    63,    64,    74,    50,   132,   183,    48,    51,
      68,    82,    83,    84,    85,   122,   123,   126,   128,   130,
     131,    55,    55,    68,   132,    48,    15,   132,   141,    50,
      56,   125,    79,   125,    52,    21,    50,    50,    52,    21,
      50,   183,   132,   190,   191,    20,    22,    21,   125,   190,
     132,   190,   191,   132,   183,     5,     7,     8,    50,    54,
     134,   178,   180,   182,   193,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   193,     7,    17,    18,    37,    48,    54,    66,
     104,   105,   106,   108,   132,   133,   134,   157,   158,   162,
     163,   164,   171,   174,   176,    50,    51,   183,   132,   183,
     183,   183,    56,    56,   126,   131,    53,    55,   183,   193,
     191,    48,   132,   149,   150,   151,   152,   183,   129,   183,
      81,   127,    18,    50,    52,   133,   134,   173,   176,   185,
     186,   187,   183,   157,   157,   132,   143,   144,   145,    50,
     157,    51,    55,   193,   133,   173,   183,    51,    50,    51,
      51,    50,    51,   193,    20,    54,    64,    55,   134,   175,
     176,    15,   160,   171,   193,    37,   105,   108,   109,   172,
     173,   172,   183,   133,   159,    48,   175,    15,    37,   161,
      51,    68,    37,   176,   193,   160,   160,   161,   174,   190,
      48,   193,    15,    48,    51,    68,   183,   125,   125,   125,
     126,   137,    50,   167,   175,    51,   183,    48,   175,   167,
      21,   124,   125,    53,    68,    51,    51,    50,    53,    68,
     132,   153,   154,   156,   193,    51,   183,   190,   190,    55,
     193,   183,   193,   161,   183,   160,    55,   172,   172,    50,
     172,    37,    48,    70,   163,   165,   166,   171,   176,   161,
     183,    15,    20,    22,   124,   162,   161,    37,    51,   183,
     151,   141,    15,    18,    70,   132,   133,   168,   169,   170,
     175,   175,    53,   173,   175,   183,   187,    21,   102,   140,
     153,   145,    21,    48,    51,    68,    15,   155,    21,    51,
      51,    55,   161,   183,   163,   166,   171,   176,    48,   176,
      37,   193,   160,   160,   161,   183,   193,   173,   172,   169,
     133,   169,    15,   175,    51,    68,    37,   167,   175,   124,
     183,    50,    51,   183,   193,   156,   183,    50,    51,   176,
     160,   160,   160,   163,   166,   171,   160,    37,   124,   124,
     169,   172,    37,   170,   175,   183,   155,   153,   172,   160,
      51,    51
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   114,   115,   115,   116,   116,   116,   117,   117,   117,
     117,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   123,   123,   123,   123,   124,   124,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   131,   132,   133,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     140,   140,   141,   141,   141,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   161,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   163,   163,   164,
     164,   164,   164,   165,   165,   166,   166,   166,   166,   167,
     168,   168,   169,   169,   169,   169,   169,   169,   170,   170,
     170,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     172,   172,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   181,   181,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   183,   183,   183,   183,
     183,   183,   184,   185,   185,   186,   186,   187,   187,   188,
     188,   189,   189,   189,   190,   190,   191,   191,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     1,     1,     3,     1,     2,     1,     3,
       0,     1,     2,     1,     2,     2,     2,     1,     2,     3,
       2,     3,     5,     5,     3,     4,     3,     2,     2,     2,
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
       3,     3,     3,     3,     3,     2,     5,     4,     3,     6,
       3,     6,     4,     3,     6,     4,     1,     1,     1,     1,
       1,     1,     5,     0,     1,     1,     3,     2,     4,     1,
       4,     5,     7,     7,     0,     1,     1,     3,     3,     5,
       2,     1,     1,     1,     1,     1,     3,     2,     1,     4,
       3,     3
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
  "\"`yield`\"", "\"`match`\"", "AUTO", "USING", "THROW", "SIZEOF",
  "LOWEST", "DEREF", "PREFIXMINUS", "INCLUDE", "INLINE", "VIABLE",
  "\"`fn`\"", "\"`typefn`\"", "ENUM", "STRUCT", "EXTENDS", "REQUIRES",
  "\"weak modifier\"", "\"typename modifier\"", "\"constexpr modifier\"",
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
  "syntax-expression", "match-expression", "match-arm-list-opt",
  "match-arm-list", "match-arm", "lambda-start-decl", "lambda-expression",
  "pack-expression-opt", "pack-expression", "compound-expression",
  "type-expr", YY_NULLPTR
  };
#endif


#if ANNIUM_LANGDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   359,   359,   360,   364,   366,   368,   385,   387,   388,
     390,   395,   397,   406,   411,   412,   417,   419,   424,   425,
     430,   432,   434,   439,   441,   442,   444,   450,   453,   464,
     469,   471,   473,   475,   477,   479,   481,   491,   493,   498,
     500,   505,   506,   510,   512,   520,   522,   524,   531,   533,
     537,   538,   540,   542,   544,   546,   551,   559,   574,   576,
     578,   584,   585,   589,   590,   594,   596,   601,   603,   608,
     626,   628,   640,   641,   643,   650,   655,   656,   660,   662,
     667,   669,   675,   677,   700,   706,   723,   725,   731,   732,
     736,   738,   743,   745,   750,   752,   758,   759,   763,   765,
     770,   771,   775,   777,   782,   789,   790,   794,   796,   801,
     802,   806,   807,   811,   812,   813,   814,   819,   823,   829,
     831,   838,   844,   850,   852,   854,   856,   859,   861,   866,
     868,   870,   878,   883,   888,   893,   898,   905,   906,   910,
     912,   916,   918,   923,   928,   932,   934,   938,   940,   950,
     955,   957,   963,   965,   968,   970,   974,   977,   983,   986,
     999,  1002,  1007,  1008,  1009,  1010,  1016,  1018,  1019,  1020,
    1024,  1025,  1026,  1030,  1032,  1034,  1036,  1038,  1040,  1042,
    1044,  1046,  1051,  1056,  1058,  1062,  1064,  1070,  1072,  1077,
    1079,  1081,  1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,
    1102,  1104,  1105,  1107,  1113,  1124,  1126,  1128,  1130,  1132,
    1139,  1146,  1148,  1162,  1164,  1166,  1169,  1171,  1173,  1177,
    1179,  1183,  1185,  1187,  1189,  1191,  1193,  1195,  1198,  1202,
    1205,  1208,  1210,  1222,  1242,  1255,  1259,  1266,  1268,  1270,
    1285,  1290,  1296,  1298,  1300,  1305,  1310,  1311,  1312,  1313,
    1314,  1315,  1330,  1335,  1336,  1359,  1361,  1366,  1368,  1373,
    1375,  1380,  1387,  1395,  1406,  1408,  1413,  1415,  1421,  1426,
    1434,  1436,  1476,  1478,  1480,  1482,  1483,  1485,  1487,  1488,
    1490,  1492
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
     105,   106,   107,   108,   109,   110,   111,   112,   113
    };
    // Last valid token kind.
    const int code_max = 368;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // annium_lang
#line 6370 "annium.tab.cpp"

#line 1687 "annium.y"

