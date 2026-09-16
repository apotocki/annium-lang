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
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 354 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 354 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 354 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 354 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 354 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 354 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 354 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 354 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 354 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 354 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS: // "`<`"
#line 354 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_LESS_EQ: // "`<=`"
#line 354 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER: // "`>`"
#line 354 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_GREATER_EQ: // "`>=`"
#line 354 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 354 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 354 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 354 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 354 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 354 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 354 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 354 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 354 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 354 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 354 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 354 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_SLASH: // "`/`"
#line 354 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 354 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 354 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 354 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 354 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_AS: // "`as`"
#line 354 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 354 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 354 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 354 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 354 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 354 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_MATCH: // "`match`"
#line 354 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 354 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 354 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 354 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 354 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 354 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL_GUARD: // "guarded consteval modifier"
#line 354 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 354 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_REFERENCE: // "reference modifier"
#line 354 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 354 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 354 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 354 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 354 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 354 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_finished_statement_any: // finished-statement-any
#line 354 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 354 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl: // let-decl
#line 354 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_let_decl_start: // let-decl-start
#line 354 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 354 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_infunction_statement_any: // infunction-statement-any
#line 354 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_infunction_statement_any: // finished-infunction-statement-any
#line 354 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_function_body: // function-body
#line 354 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_braced_statements: // braced-statements
#line 354 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_finished_statement: // finished-statement
#line 354 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_if_else_tail: // if-else-tail
#line 354 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_infunction_statement_set: // infunction-statement-set
#line 354 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_expression_statement: // expression-statement
#line 354 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_generic_statement: // generic-statement
#line 354 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_infunction_statement: // infunction-statement
#line 354 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 354 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_internal_identifier: // internal-identifier
#line 354 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 354 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_kind: // fn-kind
#line 354 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_kind_set: // fn-kind-set
#line 354 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_prefix_decl: // fn-prefix-decl
#line 354 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_fn_name: // fn-name
#line 354 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_fn_start_decl: // fn-start-decl
#line 354 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_fn_requirement_opt: // fn-requirement-opt
#line 354 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_fn_decl: // fn-decl
#line 354 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_enum_decl: // enum-decl
#line 354 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_case_list_opt: // case-list-opt
#line 354 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_case_list: // case-list
#line 354 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_case_decl: // case-decl
#line 354 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_struct_decl: // struct-decl
#line 354 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_using_decl: // using-decl
#line 354 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_expression_list: // expression-list
#line 354 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_argument_list_opt: // argument-list-opt
#line 354 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_argument_list: // argument-list
#line 354 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 354 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_argument_name: // argument-name
#line 354 "annium.y"
                 { }
#line 2545 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_field_list_opt: // field-list-opt
#line 354 "annium.y"
                 { }
#line 2551 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_field_list: // field-list
#line 354 "annium.y"
                 { }
#line 2557 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_field_default_value_opt: // field-default-value-opt
#line 354 "annium.y"
                 { }
#line 2563 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 354 "annium.y"
                 { }
#line 2569 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_list_opt: // parameter-list-opt
#line 354 "annium.y"
                 { }
#line 2575 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_parameter_list: // parameter-list
#line 354 "annium.y"
                 { }
#line 2581 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_internal_identifier_opt: // internal-identifier-opt
#line 354 "annium.y"
                 { }
#line 2587 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_parameter_default_value_opt: // parameter-default-value-opt
#line 354 "annium.y"
                 { }
#line 2593 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_ellipsis_opt_assign_value_opt: // ellipsis-opt-assign-value-opt
#line 354 "annium.y"
                 { }
#line 2599 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_parameter_decl: // parameter-decl
#line 354 "annium.y"
                 { }
#line 2605 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 354 "annium.y"
                 { }
#line 2611 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_constraint_expression_specified: // constraint-expression-specified
#line 354 "annium.y"
                 { }
#line 2617 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_constraint_expression_mod: // constraint-expression-mod
#line 354 "annium.y"
                 { }
#line 2623 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_constraint_expression: // constraint-expression
#line 354 "annium.y"
                 { }
#line 2629 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 354 "annium.y"
                 { }
#line 2635 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_pattern_list: // pattern-list
#line 354 "annium.y"
                 { }
#line 2641 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_pattern_field_sfx: // pattern-field-sfx
#line 354 "annium.y"
                 { }
#line 2647 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_pattern_field: // pattern-field
#line 354 "annium.y"
                 { }
#line 2653 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_pattern_mod: // pattern-mod
#line 354 "annium.y"
                 { }
#line 2659 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_pattern_sfx: // pattern-sfx
#line 354 "annium.y"
                 { }
#line 2665 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 354 "annium.y"
                 { }
#line 2671 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_concept_expression: // concept-expression
#line 354 "annium.y"
                 { }
#line 2677 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_concept_expression_list_opt: // concept-expression-list-opt
#line 354 "annium.y"
                 { }
#line 2683 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_concept_expression_list: // concept-expression-list
#line 354 "annium.y"
                 { }
#line 2689 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_reference_expression: // reference-expression
#line 354 "annium.y"
                 { }
#line 2695 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_any_reference_expression: // any-reference-expression
#line 354 "annium.y"
                 { }
#line 2701 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_syntax_expression_base: // syntax-expression-base
#line 354 "annium.y"
                 { }
#line 2707 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_grouped_expression: // grouped-expression
#line 354 "annium.y"
                 { }
#line 2713 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_new_expression: // new-expression
#line 354 "annium.y"
                 { }
#line 2719 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_call_expression: // call-expression
#line 354 "annium.y"
                 { }
#line 2725 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_syntax_expression: // syntax-expression
#line 354 "annium.y"
                 { }
#line 2731 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_match_expression: // match-expression
#line 354 "annium.y"
                 { }
#line 2737 "annium.tab.cpp"
        break;

      case symbol_kind::S_185_match_arm_list_opt: // match-arm-list-opt
#line 354 "annium.y"
                 { }
#line 2743 "annium.tab.cpp"
        break;

      case symbol_kind::S_186_match_arm_list: // match-arm-list
#line 354 "annium.y"
                 { }
#line 2749 "annium.tab.cpp"
        break;

      case symbol_kind::S_187_match_arm: // match-arm
#line 354 "annium.y"
                 { }
#line 2755 "annium.tab.cpp"
        break;

      case symbol_kind::S_188_lambda_start_decl: // lambda-start-decl
#line 354 "annium.y"
                 { }
#line 2761 "annium.tab.cpp"
        break;

      case symbol_kind::S_189_lambda_expression: // lambda-expression
#line 354 "annium.y"
                 { }
#line 2767 "annium.tab.cpp"
        break;

      case symbol_kind::S_190_pack_expression_opt: // pack-expression-opt
#line 354 "annium.y"
                 { }
#line 2773 "annium.tab.cpp"
        break;

      case symbol_kind::S_191_pack_expression: // pack-expression
#line 354 "annium.y"
                 { }
#line 2779 "annium.tab.cpp"
        break;

      case symbol_kind::S_192_compound_expression: // compound-expression
#line 354 "annium.y"
                 { }
#line 2785 "annium.tab.cpp"
        break;

      case symbol_kind::S_193_type_expr: // type-expr
#line 354 "annium.y"
                 { }
#line 2791 "annium.tab.cpp"
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
#line 3309 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 360 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3315 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 365 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3321 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 367 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3327 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 369 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3333 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 386 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3339 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 387 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3345 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 389 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3351 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 391 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3357 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 396 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3363 "annium.tab.cpp"
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
#line 3376 "annium.tab.cpp"
    break;

  case 13: // statement: generic-statement
#line 407 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3382 "annium.tab.cpp"
    break;

  case 14: // let-decl: let-decl-start-with-opt-type
#line 411 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3388 "annium.tab.cpp"
    break;

  case 15: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 413 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3394 "annium.tab.cpp"
    break;

  case 16: // let-decl-start: identifier
#line 418 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3400 "annium.tab.cpp"
    break;

  case 17: // let-decl-start: "weak modifier" identifier
#line 420 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3406 "annium.tab.cpp"
    break;

  case 18: // let-decl-start-with-opt-type: let-decl-start
#line 424 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3412 "annium.tab.cpp"
    break;

  case 19: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 426 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3418 "annium.tab.cpp"
    break;

  case 20: // infunction-statement-any: %empty
#line 431 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3424 "annium.tab.cpp"
    break;

  case 21: // infunction-statement-any: infunction-statement
#line 433 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3430 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 435 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3436 "annium.tab.cpp"
    break;

  case 23: // finished-infunction-statement-any: finished-statement
#line 440 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3442 "annium.tab.cpp"
    break;

  case 24: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 441 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3448 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 443 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3454 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 445 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3460 "annium.tab.cpp"
    break;

  case 27: // function-body: braced-statements
#line 450 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3466 "annium.tab.cpp"
    break;

  case 28: // function-body: "`=>`" syntax-expression
#line 454 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3472 "annium.tab.cpp"
    break;

  case 29: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 465 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3478 "annium.tab.cpp"
    break;

  case 30: // finished-statement: INCLUDE STRING
#line 470 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3484 "annium.tab.cpp"
    break;

  case 31: // finished-statement: "`while`" syntax-expression braced-statements
#line 472 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3490 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression "`;`" expression-statement braced-statements
#line 474 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), ctx.make<statement>(std::move(yystack_[1].value.as < statement > ())) } }; }
#line 3496 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 476 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3502 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`if`" syntax-expression braced-statements
#line 478 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3508 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements if-else-tail
#line 480 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[2].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3514 "annium.tab.cpp"
    break;

  case 36: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 482 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3524 "annium.tab.cpp"
    break;

  case 37: // finished-statement: ENUM enum-decl
#line 492 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3530 "annium.tab.cpp"
    break;

  case 38: // finished-statement: STRUCT struct-decl
#line 494 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3536 "annium.tab.cpp"
    break;

  case 39: // if-else-tail: "`else`" braced-statements
#line 499 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[0].value.as < statement_list_t > ()); }
#line 3542 "annium.tab.cpp"
    break;

  case 40: // if-else-tail: "`else`" finished-statement
#line 501 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3548 "annium.tab.cpp"
    break;

  case 41: // infunction-statement-set: infunction-statement-any
#line 505 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3554 "annium.tab.cpp"
    break;

  case 42: // infunction-statement-set: finished-infunction-statement-any
#line 506 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3560 "annium.tab.cpp"
    break;

  case 43: // expression-statement: compound-expression
#line 511 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3566 "annium.tab.cpp"
    break;

  case 44: // expression-statement: syntax-expression "`=`" syntax-expression
#line 513 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3575 "annium.tab.cpp"
    break;

  case 45: // generic-statement: LET let-decl
#line 521 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3581 "annium.tab.cpp"
    break;

  case 46: // generic-statement: "`typefn`" fn-start-decl
#line 523 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3587 "annium.tab.cpp"
    break;

  case 47: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 525 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3598 "annium.tab.cpp"
    break;

  case 48: // generic-statement: USING using-decl
#line 532 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3604 "annium.tab.cpp"
    break;

  case 49: // generic-statement: expression-statement
#line 533 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3610 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: generic-statement
#line 537 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3616 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`break`"
#line 539 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3622 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`continue`"
#line 541 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3628 "annium.tab.cpp"
    break;

  case 53: // infunction-statement: "`return`"
#line 543 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3634 "annium.tab.cpp"
    break;

  case 54: // infunction-statement: "`return`" syntax-expression
#line 545 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3640 "annium.tab.cpp"
    break;

  case 55: // infunction-statement: "`yield`" syntax-expression
#line 547 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3646 "annium.tab.cpp"
    break;

  case 56: // identifier: IDENTIFIER
#line 552 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3652 "annium.tab.cpp"
    break;

  case 57: // internal-identifier: CONTEXT_IDENTIFIER
#line 560 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3658 "annium.tab.cpp"
    break;

  case 58: // qname: "`::`" identifier
#line 575 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3664 "annium.tab.cpp"
    break;

  case 59: // qname: identifier
#line 577 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3670 "annium.tab.cpp"
    break;

  case 60: // qname: qname "`::`" identifier
#line 579 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3676 "annium.tab.cpp"
    break;

  case 61: // fn-kind: INLINE
#line 584 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3682 "annium.tab.cpp"
    break;

  case 62: // fn-kind: VIABLE
#line 585 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3688 "annium.tab.cpp"
    break;

  case 63: // fn-kind-set: fn-kind
#line 589 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3694 "annium.tab.cpp"
    break;

  case 64: // fn-kind-set: fn-kind-set fn-kind
#line 590 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3700 "annium.tab.cpp"
    break;

  case 65: // fn-prefix-decl: "`fn`"
#line 595 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3706 "annium.tab.cpp"
    break;

  case 66: // fn-prefix-decl: fn-kind-set "`fn`"
#line 597 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3712 "annium.tab.cpp"
    break;

  case 67: // fn-name: qname
#line 602 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3718 "annium.tab.cpp"
    break;

  case 68: // fn-name: "`new`"
#line 604 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3724 "annium.tab.cpp"
    break;

  case 69: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 609 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3730 "annium.tab.cpp"
    break;

  case 70: // fn-requirement-opt: %empty
#line 626 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3736 "annium.tab.cpp"
    break;

  case 71: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 629 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3742 "annium.tab.cpp"
    break;

  case 72: // fn-decl: fn-start-decl
#line 640 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3748 "annium.tab.cpp"
    break;

  case 73: // fn-decl: fn-start-decl "`->`" type-expr
#line 642 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3754 "annium.tab.cpp"
    break;

  case 74: // fn-decl: fn-start-decl "`~>`" pattern
#line 644 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3760 "annium.tab.cpp"
    break;

  case 75: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 651 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<enum_case>(yystack_[1].value.as < std::vector<enum_case> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3766 "annium.tab.cpp"
    break;

  case 76: // case-list-opt: %empty
#line 655 "annium.y"
             { yylhs.value.as < std::vector<enum_case> > () = {}; }
#line 3772 "annium.tab.cpp"
    break;

  case 77: // case-list-opt: case-list
#line 656 "annium.y"
      { yylhs.value.as < std::vector<enum_case> > () = yystack_[0].value.as < std::vector<enum_case> > (); }
#line 3778 "annium.tab.cpp"
    break;

  case 78: // case-list: case-decl
#line 661 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::vector<enum_case>{ std::move(yystack_[0].value.as < enum_case > ()) }; }
#line 3784 "annium.tab.cpp"
    break;

  case 79: // case-list: case-list "," case-decl
#line 663 "annium.y"
        { yylhs.value.as < std::vector<enum_case> > () = std::move(yystack_[2].value.as < std::vector<enum_case> > ()); yylhs.value.as < std::vector<enum_case> > ().emplace_back(std::move(yystack_[0].value.as < enum_case > ())); }
#line 3790 "annium.tab.cpp"
    break;

  case 80: // case-decl: identifier
#line 668 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[0].value.as < annotated_identifier > ().value }; }
#line 3796 "annium.tab.cpp"
    break;

  case 81: // case-decl: identifier "`(`" field-list-opt "`)`"
#line 670 "annium.y"
        { yylhs.value.as < enum_case > () = enum_case{ .name = yystack_[3].value.as < annotated_identifier > ().value, .fields = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3802 "annium.tab.cpp"
    break;

  case 82: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 676 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3808 "annium.tab.cpp"
    break;

  case 83: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 678 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3814 "annium.tab.cpp"
    break;

  case 84: // using-decl: qname "`=>`" syntax-expression
#line 701 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3824 "annium.tab.cpp"
    break;

  case 85: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 707 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3835 "annium.tab.cpp"
    break;

  case 86: // expression-list: syntax-expression
#line 724 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3841 "annium.tab.cpp"
    break;

  case 87: // expression-list: expression-list "," syntax-expression
#line 726 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3847 "annium.tab.cpp"
    break;

  case 88: // argument-list-opt: %empty
#line 731 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3853 "annium.tab.cpp"
    break;

  case 89: // argument-list-opt: argument-list
#line 732 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3859 "annium.tab.cpp"
    break;

  case 90: // argument-list: argument
#line 737 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3865 "annium.tab.cpp"
    break;

  case 91: // argument-list: argument-list "," argument
#line 739 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3871 "annium.tab.cpp"
    break;

  case 92: // argument: argument-name syntax-expression
#line 744 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3877 "annium.tab.cpp"
    break;

  case 93: // argument: syntax-expression
#line 746 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3883 "annium.tab.cpp"
    break;

  case 94: // argument-name: identifier "`=`"
#line 751 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3889 "annium.tab.cpp"
    break;

  case 95: // argument-name: identifier "`:`"
#line 753 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3895 "annium.tab.cpp"
    break;

  case 96: // field-list-opt: %empty
#line 758 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3901 "annium.tab.cpp"
    break;

  case 97: // field-list-opt: field-list
#line 759 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3907 "annium.tab.cpp"
    break;

  case 98: // field-list: field
#line 764 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3913 "annium.tab.cpp"
    break;

  case 99: // field-list: field-list "," field
#line 766 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3919 "annium.tab.cpp"
    break;

  case 100: // field-default-value-opt: %empty
#line 770 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3925 "annium.tab.cpp"
    break;

  case 101: // field-default-value-opt: "`=`" syntax-expression
#line 771 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3931 "annium.tab.cpp"
    break;

  case 102: // field: identifier "`:`" type-expr field-default-value-opt
#line 776 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3937 "annium.tab.cpp"
    break;

  case 103: // field: identifier "`=>`" syntax-expression
#line 778 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3943 "annium.tab.cpp"
    break;

  case 104: // field: type-expr field-default-value-opt
#line 783 "annium.y"
        { yylhs.value.as < field > () = field{ .name = annotated_identifier{}, .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3949 "annium.tab.cpp"
    break;

  case 105: // parameter-list-opt: %empty
#line 789 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3955 "annium.tab.cpp"
    break;

  case 106: // parameter-list-opt: parameter-list
#line 790 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3961 "annium.tab.cpp"
    break;

  case 107: // parameter-list: parameter-decl
#line 795 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3967 "annium.tab.cpp"
    break;

  case 108: // parameter-list: parameter-list "," parameter-decl
#line 797 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3973 "annium.tab.cpp"
    break;

  case 109: // internal-identifier-opt: %empty
#line 801 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3979 "annium.tab.cpp"
    break;

  case 110: // internal-identifier-opt: internal-identifier
#line 802 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3985 "annium.tab.cpp"
    break;

  case 111: // parameter-default-value-opt: %empty
#line 806 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3991 "annium.tab.cpp"
    break;

  case 112: // parameter-default-value-opt: "`=`" syntax-expression
#line 807 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3997 "annium.tab.cpp"
    break;

  case 113: // ellipsis-opt-assign-value-opt: %empty
#line 811 "annium.y"
             { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, required_t{} }; }
#line 4003 "annium.tab.cpp"
    break;

  case 114: // ellipsis-opt-assign-value-opt: "`...`"
#line 812 "annium.y"
               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[0].value.as < resource_location > (), required_t{} }; }
#line 4009 "annium.tab.cpp"
    break;

  case 115: // ellipsis-opt-assign-value-opt: "`=`" syntax-expression
#line 813 "annium.y"
                                      { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ resource_location{}, ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4015 "annium.tab.cpp"
    break;

  case 116: // ellipsis-opt-assign-value-opt: "`...`" "`=`" syntax-expression
#line 814 "annium.y"
                                               { yylhs.value.as < std::pair<resource_location, parameter::default_spec> > () = std::pair{ yystack_[2].value.as < resource_location > (), ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4021 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 820 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4027 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 824 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4033 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 830 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 4039 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: "`[`" type-expr "`]`" ellipsis-opt-assign-value-opt
#line 832 "annium.y"
        { 
            auto * constraint = ctx.make<syntax_expression>(syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4049 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: constraint-expression-specified-mod concept-expression-list ellipsis-opt-assign-value-opt
#line 839 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic : get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ());
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4058 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: qname ellipsis-opt-assign-value-opt
#line 845 "annium.y"
        {
            auto * constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second),.modifier = modifier };
        }
#line 4068 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 851 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4074 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 853 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 4080 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 855 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 4086 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 857 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[0].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4092 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 860 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4098 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: internal-identifier "`:`" concept-expression-list ellipsis-opt-assign-value-opt
#line 862 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4107 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 867 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4113 "annium.tab.cpp"
    break;

  case 130: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 869 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4119 "annium.tab.cpp"
    break;

  case 131: // parameter-decl: pattern-mod parameter-default-value-opt
#line 871 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ()), .reference_condition = std::move(get<2>(yystack_[1].value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > ())) }; }
#line 4125 "annium.tab.cpp"
    break;

  case 132: // parameter-decl: internal-identifier concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 879 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4134 "annium.tab.cpp"
    break;

  case 133: // parameter-decl: "`_`" concept-expression-list-opt ellipsis-opt-assign-value-opt
#line 884 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4143 "annium.tab.cpp"
    break;

  case 134: // parameter-decl: concept-expression-list ellipsis-opt-assign-value-opt
#line 889 "annium.y"
        {
            auto modifier = yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().first ? parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic : parameter_constraint_modifier_t::constexpr_or_runtime_type;
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ yystack_[1].value.as < syntax_expression_list_t > ().front().location }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < std::pair<resource_location, parameter::default_spec> > ().second), .modifier = modifier };
        }
#line 4152 "annium.tab.cpp"
    break;

  case 135: // parameter-decl: "`...`" parameter-default-value-opt
#line 894 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 4158 "annium.tab.cpp"
    break;

  case 136: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 899 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4164 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-specified-mod: "constexpr modifier"
#line 905 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 4170 "annium.tab.cpp"
    break;

  case 138: // constraint-expression-specified-mod: "runctime modifier"
#line 906 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 4176 "annium.tab.cpp"
    break;

  case 139: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 911 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4182 "annium.tab.cpp"
    break;

  case 140: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 913 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4188 "annium.tab.cpp"
    break;

  case 141: // constraint-expression-specified: constraint-expression-specified-mod
#line 917 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4194 "annium.tab.cpp"
    break;

  case 142: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 919 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4200 "annium.tab.cpp"
    break;

  case 143: // constraint-expression-mod: %empty
#line 924 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 4209 "annium.tab.cpp"
    break;

  case 144: // constraint-expression-mod: constraint-expression-specified-mod
#line 928 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 4215 "annium.tab.cpp"
    break;

  case 145: // constraint-expression: constraint-expression-mod type-expr
#line 933 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4221 "annium.tab.cpp"
    break;

  case 146: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 935 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4227 "annium.tab.cpp"
    break;

  case 147: // constraint-expression: constraint-expression-mod
#line 939 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 4233 "annium.tab.cpp"
    break;

  case 148: // constraint-expression: constraint-expression-mod "`...`"
#line 941 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 4239 "annium.tab.cpp"
    break;

  case 149: // subpatterns: "`(`" pattern-list "`)`"
#line 951 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4245 "annium.tab.cpp"
    break;

  case 150: // pattern-list: pattern-field
#line 956 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 4251 "annium.tab.cpp"
    break;

  case 151: // pattern-list: pattern-list "," pattern-field
#line 958 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 4257 "annium.tab.cpp"
    break;

  case 152: // pattern-field-sfx: concept-expression-list-opt
#line 964 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4263 "annium.tab.cpp"
    break;

  case 153: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 966 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4269 "annium.tab.cpp"
    break;

  case 154: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 969 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 4275 "annium.tab.cpp"
    break;

  case 155: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 971 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4281 "annium.tab.cpp"
    break;

  case 156: // pattern-field-sfx: "`=`" pattern-sfx
#line 975 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4287 "annium.tab.cpp"
    break;

  case 157: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 978 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4293 "annium.tab.cpp"
    break;

  case 158: // pattern-field: identifier pattern-field-sfx
#line 984 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 4299 "annium.tab.cpp"
    break;

  case 159: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 987 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4305 "annium.tab.cpp"
    break;

  case 160: // pattern-field: pattern-field-sfx
#line 1000 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 4311 "annium.tab.cpp"
    break;

  case 161: // pattern-field: "`_`" pattern-field-sfx
#line 1003 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 4317 "annium.tab.cpp"
    break;

  case 162: // pattern-mod: "`~`" pattern-sfx
#line 1007 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type, static_cast<syntax_expression const*>(nullptr) }; }
#line 4323 "annium.tab.cpp"
    break;

  case 163: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 1008 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4329 "annium.tab.cpp"
    break;

  case 164: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 1009 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4335 "annium.tab.cpp"
    break;

  case 165: // pattern-mod: "`~`" "reference modifier" pattern-sfx
#line 1010 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4341 "annium.tab.cpp"
    break;

  case 166: // pattern-mod: "`~`" "reference modifier" "`(`" syntax-expression "`)`" pattern-sfx
#line 1017 "annium.y"
        { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::reference_type, ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4347 "annium.tab.cpp"
    break;

  case 167: // pattern-mod: "consteval modifier" syntax-expression
#line 1018 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) }, parameter_constraint_modifier_t::constexpr_not_a_typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4353 "annium.tab.cpp"
    break;

  case 168: // pattern-mod: "typename modifier" pattern-sfx
#line 1019 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4359 "annium.tab.cpp"
    break;

  case 169: // pattern-mod: "typename modifier"
#line 1020 "annium.y"
                                              { yylhs.value.as < std::tuple<syntax_pattern, parameter_constraint_modifier_t, syntax_expression const*> > () = std::tuple{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value, static_cast<syntax_expression const*>(nullptr) }; }
#line 4365 "annium.tab.cpp"
    break;

  case 170: // pattern-sfx: pattern
#line 1024 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4371 "annium.tab.cpp"
    break;

  case 171: // pattern-sfx: pattern "`...`"
#line 1025 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4377 "annium.tab.cpp"
    break;

  case 172: // pattern-sfx: "`...`"
#line 1026 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4383 "annium.tab.cpp"
    break;

  case 173: // pattern: qname
#line 1031 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4389 "annium.tab.cpp"
    break;

  case 174: // pattern: qname subpatterns concept-expression-list-opt
#line 1033 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4395 "annium.tab.cpp"
    break;

  case 175: // pattern: internal-identifier concept-expression-list-opt
#line 1035 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4401 "annium.tab.cpp"
    break;

  case 176: // pattern: "`_`" concept-expression-list-opt
#line 1037 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4407 "annium.tab.cpp"
    break;

  case 177: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 1039 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4413 "annium.tab.cpp"
    break;

  case 178: // pattern: "`(`" "`)`"
#line 1041 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4419 "annium.tab.cpp"
    break;

  case 179: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 1043 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4425 "annium.tab.cpp"
    break;

  case 180: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 1045 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4431 "annium.tab.cpp"
    break;

  case 181: // pattern: concept-expression-list
#line 1047 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4437 "annium.tab.cpp"
    break;

  case 182: // concept-expression: "`@`" qname
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4443 "annium.tab.cpp"
    break;

  case 183: // concept-expression-list-opt: %empty
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4449 "annium.tab.cpp"
    break;

  case 184: // concept-expression-list-opt: concept-expression-list
#line 1058 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4455 "annium.tab.cpp"
    break;

  case 185: // concept-expression-list: concept-expression
#line 1063 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4461 "annium.tab.cpp"
    break;

  case 186: // concept-expression-list: concept-expression-list concept-expression
#line 1065 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4467 "annium.tab.cpp"
    break;

  case 187: // reference-expression: CONTEXT_IDENTIFIER
#line 1071 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4473 "annium.tab.cpp"
    break;

  case 188: // reference-expression: qname
#line 1073 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4479 "annium.tab.cpp"
    break;

  case 189: // any-reference-expression: RESERVED_IDENTIFIER
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4485 "annium.tab.cpp"
    break;

  case 190: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1080 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4491 "annium.tab.cpp"
    break;

  case 191: // any-reference-expression: qname
#line 1082 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4497 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "nil"
#line 1087 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4503 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: "true"
#line 1089 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4509 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: "false"
#line 1091 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4515 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: INTEGER
#line 1093 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4521 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: DECIMAL
#line 1095 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4527 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: DECIMAL_S
#line 1097 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4533 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: INTEGER_INDEX
#line 1099 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4539 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: STRING
#line 1101 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4545 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: CT_IDENTIFIER
#line 1103 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4551 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: any-reference-expression
#line 1104 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4557 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`(`" "`)`"
#line 1106 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4563 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1108 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4572 "annium.tab.cpp"
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
#line 4584 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: "`[`" expression-list "," "`]`"
#line 1125 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[3].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[2].value.as < syntax_expression_list_t > ()) } }; }
#line 4590 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1127 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4596 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1129 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4602 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: PROBE braced-statements
#line 1131 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4608 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: "`.`" identifier
#line 1133 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4614 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1140 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4624 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: "`-`" syntax-expression
#line 1147 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4630 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: "consteval modifier" syntax-expression
#line 1149 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4636 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: "guarded consteval modifier" "`(`" syntax-expression "`)`" syntax-expression
#line 1163 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), consteval_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())) } }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4642 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: "`!`" syntax-expression
#line 1165 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4648 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: "`*`" syntax-expression
#line 1167 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4654 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`*`" syntax-expression
#line 1170 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MUL, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4660 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`/`" syntax-expression
#line 1172 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::DIV, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4666 "annium.tab.cpp"
    break;

  case 218: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1176 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4672 "annium.tab.cpp"
    break;

  case 219: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1178 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4678 "annium.tab.cpp"
    break;

  case 220: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1182 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4684 "annium.tab.cpp"
    break;

  case 221: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1184 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4690 "annium.tab.cpp"
    break;

  case 222: // syntax-expression-base: syntax-expression "`<`" syntax-expression
#line 1186 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4696 "annium.tab.cpp"
    break;

  case 223: // syntax-expression-base: syntax-expression "`<=`" syntax-expression
#line 1188 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LESS_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4702 "annium.tab.cpp"
    break;

  case 224: // syntax-expression-base: syntax-expression "`>`" syntax-expression
#line 1190 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4708 "annium.tab.cpp"
    break;

  case 225: // syntax-expression-base: syntax-expression "`>=`" syntax-expression
#line 1192 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::GREATER_EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4714 "annium.tab.cpp"
    break;

  case 226: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1194 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4720 "annium.tab.cpp"
    break;

  case 227: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1197 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4726 "annium.tab.cpp"
    break;

  case 228: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1201 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4732 "annium.tab.cpp"
    break;

  case 229: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1204 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4738 "annium.tab.cpp"
    break;

  case 230: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1207 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4744 "annium.tab.cpp"
    break;

  case 231: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1209 "annium.y"
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
#line 4759 "annium.tab.cpp"
    break;

  case 232: // syntax-expression-base: syntax-expression "`as`" type-expr
#line 1221 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CAST, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4765 "annium.tab.cpp"
    break;

  case 233: // grouped-expression: "`(`" pack-expression "`)`"
#line 1241 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4778 "annium.tab.cpp"
    break;

  case 234: // new-expression: "`new`" qname
#line 1254 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4784 "annium.tab.cpp"
    break;

  case 235: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1258 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4790 "annium.tab.cpp"
    break;

  case 236: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1265 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4796 "annium.tab.cpp"
    break;

  case 237: // call-expression: any-reference-expression "`.`" identifier
#line 1267 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4802 "annium.tab.cpp"
    break;

  case 238: // call-expression: any-reference-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1269 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4811 "annium.tab.cpp"
    break;

  case 239: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1274 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4817 "annium.tab.cpp"
    break;

  case 240: // call-expression: call-expression "`.`" identifier
#line 1276 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4823 "annium.tab.cpp"
    break;

  case 241: // call-expression: call-expression "`.`" identifier "`(`" pack-expression-opt "`)`"
#line 1278 "annium.y"
        {
            syntax_expression mb{ std::move(yystack_[3].value.as < annotated_identifier > ().location), std::move(yystack_[3].value.as < annotated_identifier > ().value) };
            yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), member_call{ ctx.make<syntax_expression>(std::move(yystack_[5].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(mb)), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ());
        }
#line 4832 "annium.tab.cpp"
    break;

  case 242: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1283 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4838 "annium.tab.cpp"
    break;

  case 243: // syntax-expression: syntax-expression-base
#line 1287 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4844 "annium.tab.cpp"
    break;

  case 244: // syntax-expression: new-expression
#line 1288 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4850 "annium.tab.cpp"
    break;

  case 245: // syntax-expression: compound-expression
#line 1289 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4856 "annium.tab.cpp"
    break;

  case 246: // syntax-expression: lambda-expression
#line 1290 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4862 "annium.tab.cpp"
    break;

  case 247: // syntax-expression: match-expression
#line 1291 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4868 "annium.tab.cpp"
    break;

  case 248: // syntax-expression: grouped-expression
#line 1292 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4874 "annium.tab.cpp"
    break;

  case 249: // match-expression: "`match`" syntax-expression "`{`" match-arm-list-opt "`}`"
#line 1308 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), match_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<match_arm>(yystack_[1].value.as < std::vector<match_arm> > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4880 "annium.tab.cpp"
    break;

  case 250: // match-arm-list-opt: %empty
#line 1312 "annium.y"
             { yylhs.value.as < std::vector<match_arm> > () = {}; }
#line 4886 "annium.tab.cpp"
    break;

  case 251: // match-arm-list-opt: match-arm-list
#line 1313 "annium.y"
      { yylhs.value.as < std::vector<match_arm> > () = yystack_[0].value.as < std::vector<match_arm> > (); }
#line 4892 "annium.tab.cpp"
    break;

  case 252: // match-arm-list: match-arm
#line 1337 "annium.y"
        { yylhs.value.as < std::vector<match_arm> > () = std::vector<match_arm>{ std::move(yystack_[0].value.as < match_arm > ()) }; }
#line 4898 "annium.tab.cpp"
    break;

  case 253: // match-arm-list: match-arm-list "," match-arm
#line 1339 "annium.y"
        { yylhs.value.as < std::vector<match_arm> > () = std::move(yystack_[2].value.as < std::vector<match_arm> > ()); yylhs.value.as < std::vector<match_arm> > ().emplace_back(std::move(yystack_[0].value.as < match_arm > ())); }
#line 4904 "annium.tab.cpp"
    break;

  case 254: // match-arm: pattern function-body
#line 1344 "annium.y"
        { yylhs.value.as < match_arm > () = match_arm{ .pattern = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ())), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) }; }
#line 4910 "annium.tab.cpp"
    break;

  case 255: // match-arm: internal-identifier "`:`" pattern function-body
#line 1346 "annium.y"
        { yylhs.value.as < match_arm > () = match_arm{ .bind_name = std::move(yystack_[3].value.as < context_identifier > ().name), .pattern = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ())), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) }; }
#line 4916 "annium.tab.cpp"
    break;

  case 256: // lambda-start-decl: fn-prefix-decl
#line 1351 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4922 "annium.tab.cpp"
    break;

  case 257: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1353 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4928 "annium.tab.cpp"
    break;

  case 258: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1358 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4939 "annium.tab.cpp"
    break;

  case 259: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1365 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4951 "annium.tab.cpp"
    break;

  case 260: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1373 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4963 "annium.tab.cpp"
    break;

  case 261: // pack-expression-opt: %empty
#line 1384 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4969 "annium.tab.cpp"
    break;

  case 262: // pack-expression-opt: pack-expression
#line 1386 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4975 "annium.tab.cpp"
    break;

  case 263: // pack-expression: syntax-expression
#line 1391 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4981 "annium.tab.cpp"
    break;

  case 264: // pack-expression: identifier "`:`" syntax-expression
#line 1393 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4991 "annium.tab.cpp"
    break;

  case 265: // pack-expression: pack-expression "," syntax-expression
#line 1399 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 5000 "annium.tab.cpp"
    break;

  case 266: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1404 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 5009 "annium.tab.cpp"
    break;

  case 267: // compound-expression: syntax-expression "`...`"
#line 1412 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 5015 "annium.tab.cpp"
    break;

  case 268: // compound-expression: call-expression
#line 1413 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5021 "annium.tab.cpp"
    break;

  case 269: // type-expr: qname
#line 1454 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 5027 "annium.tab.cpp"
    break;

  case 270: // type-expr: RESERVED_IDENTIFIER
#line 1456 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 5033 "annium.tab.cpp"
    break;

  case 271: // type-expr: CONTEXT_IDENTIFIER
#line 1458 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 5039 "annium.tab.cpp"
    break;

  case 272: // type-expr: call-expression
#line 1459 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5045 "annium.tab.cpp"
    break;

  case 273: // type-expr: "`[`" type-expr "`]`"
#line 1461 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 5051 "annium.tab.cpp"
    break;

  case 274: // type-expr: "`(`" "`)`"
#line 1463 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 5057 "annium.tab.cpp"
    break;

  case 275: // type-expr: grouped-expression
#line 1464 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 5063 "annium.tab.cpp"
    break;

  case 276: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1466 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 5069 "annium.tab.cpp"
    break;

  case 277: // type-expr: type-expr "`|`" type-expr
#line 1468 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 5075 "annium.tab.cpp"
    break;

  case 278: // type-expr: type-expr "`->`" type-expr
#line 1470 "annium.y"
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
#line 5090 "annium.tab.cpp"
    break;


#line 5094 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -367;

  const short parser::yytable_ninf_ = -192;

  const short
  parser::yypact_[] =
  {
    1028,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
      41,  1137,  1160,    41,  1424,  1424,  1424,     2,   -42,    54,
    1424,    66,  1424,  1424,    54,    16,  -367,  -367,  -367,     7,
      54,    54,  1424,    57,  -367,  -367,  -367,   121,   165,    38,
     701,  -367,  -367,  -367,  -367,  -367,   130,  -367,   375,    21,
      -6,  -367,   139,  -367,   111,  1513,  -367,   180,  -367,    29,
    -367,  1424,  -367,   186,   203,  1983,   -18,  -367,   919,   218,
     216,  1983,  -367,   155,   155,   155,    41,  -367,   267,   301,
    -367,    41,     7,   228,  1038,  -367,   130,   273,  1560,  1607,
     197,  -367,  -367,  -367,   130,   275,  -367,   299,  -367,   246,
    -367,   155,  1424,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,    41,  -367,  -367,  1424,   366,    32,  1424,    41,  1424,
    1424,    41,  -367,  1424,   357,  1424,  1424,  1424,  1424,  1424,
    1424,  1424,  1424,  1424,  -367,  1424,  1424,  1424,  1424,  1424,
    1424,  1424,   357,   726,  1654,  1424,  -367,  1424,  -367,  -367,
    1424,  1424,   304,   810,  -367,   320,  -367,  -367,  -367,  -367,
    1269,  -367,   357,  1424,   335,  -367,  1424,  1424,  -367,  1424,
     317,   462,  1424,   726,   726,    41,   354,   726,  1701,  -367,
     361,   341,   357,   462,  1424,  -367,   383,   385,   389,   154,
     391,  1983,   113,   269,  1292,   357,   280,    -6,   139,   111,
       5,   439,   439,   439,   439,   439,   439,   929,   820,   554,
    1748,   263,   263,   302,   302,   540,  1232,    45,  -367,    54,
     427,   431,   -27,   357,   291,   895,  -367,  1424,  -367,    10,
      94,   134,   396,   384,  -367,   633,   431,   431,  -367,   376,
    -367,  1983,   410,  1983,  1983,  1983,  -367,  -367,  -367,  -367,
    -367,  -367,  1983,    45,   341,   357,    15,   409,   398,  -367,
    1424,  1983,   121,  1560,   641,  -367,   161,   422,  1424,   168,
     257,   214,   427,   424,   414,  -367,  1983,   435,   436,   444,
     449,   441,  -367,   357,   457,  1424,  -367,    45,   427,  -367,
    1983,  -367,  1424,  -367,  -367,  1424,  -367,   249,   357,  1424,
     357,  -367,   130,   239,   427,  1424,  -367,   431,   281,  -367,
     895,   895,  1004,  -367,   473,  -367,  1983,  -367,    43,   182,
     239,  1424,   500,  -367,   429,   726,  -367,   376,    34,  -367,
    -367,  -367,  -367,  1424,    45,  -367,  -367,  -367,  1424,  1983,
    -367,  -367,  -367,  -367,     7,   340,   427,  -367,  -367,  1795,
     462,  -367,   427,  1424,  -367,  -367,  -367,   462,   499,   432,
     357,  -367,    41,   196,   475,   461,  -367,    42,   510,   155,
     484,   485,  -367,     5,  1842,     5,  -367,  1983,  -367,   239,
    -367,  -367,  1401,  -367,  -367,   182,   489,   427,   368,   431,
     431,   376,  -367,  1983,  1424,   357,   462,  -367,  -367,  -367,
    -367,  1983,  -367,   121,   895,   380,   531,   380,   412,   293,
    -367,  -367,   502,  -367,   161,   214,  -367,  1983,  -367,  1424,
     490,  -367,   496,  -367,  1424,   357,  -367,   357,  1424,  -367,
     491,  -367,  -367,  -367,  -367,  1889,   427,   431,   431,   440,
     417,   440,  -367,   400,  -367,  -367,  -367,  1983,   160,   214,
    -367,  -367,   380,  -367,   895,   513,  -367,   340,  -367,   427,
    -367,  -367,  1983,  1424,  -367,  1983,    42,  -367,  1983,   357,
     895,   440,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  1936,  -367,   501,
    -367,  -367,  -367,  -367
  };

  const short
  parser::yydefact_[] =
  {
       4,   199,    56,   190,   189,   198,   195,   196,   197,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    65,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
       0,     5,     7,    49,    13,    59,   191,    63,     0,   256,
     201,   243,   248,   244,   268,     0,   247,     0,   246,   245,
      58,     0,   202,    59,   256,   263,     0,   245,    20,     0,
       0,    86,   209,   211,   215,   214,     0,    45,    18,    14,
      16,     0,     0,   234,     0,   187,   188,     0,     0,     0,
       0,    48,    30,    68,    67,     0,    46,     0,    37,     0,
      38,   212,     0,   208,     1,     2,    10,     3,     8,     6,
       9,     0,    66,    64,   261,    72,     0,   261,     0,   261,
       0,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,   233,     0,    52,    51,
      53,     0,    41,    42,    23,     0,    50,    21,   206,   204,
       0,    17,     0,     0,     0,    12,    88,     0,    31,     0,
      34,   250,     0,   105,   105,    76,     0,   105,     0,    60,
       0,   262,     0,     0,     0,    36,     0,   237,     0,     0,
     240,    44,   271,   270,     0,     0,   269,     0,   275,   272,
     231,   220,   221,   222,   223,   224,   225,   229,   230,   226,
       0,   218,   219,   216,   217,   227,   228,   232,    57,     0,
     183,   111,     0,     0,     0,   169,   137,     0,   138,    59,
     183,   113,     0,   106,   107,   141,   111,   111,   185,   113,
     203,   264,    59,   265,    54,    55,    26,    24,    25,    22,
      29,   205,    87,    19,    15,     0,    59,     0,    89,    90,
       0,    93,     0,     0,     0,    35,   183,     0,     0,   183,
     173,     0,   181,     0,   251,   252,    84,     0,     0,    80,
       0,    77,    78,    96,     0,     0,   257,    73,   183,    74,
      47,   236,   261,   242,   239,   261,   274,     0,     0,     0,
       0,   207,   182,   113,   184,     0,   135,   111,     0,   172,
       0,     0,     0,   162,   170,   168,   167,   110,     0,   143,
     113,     0,   114,   122,     0,     0,   142,   113,   139,   119,
     131,   134,   186,     0,    11,    94,    95,   235,     0,    92,
      32,    33,    39,    40,     0,   183,   183,   176,   178,     0,
       0,   175,   183,     0,   254,    27,   249,     0,     0,    70,
      96,    75,     0,    59,     0,    97,    98,   100,     0,   213,
       0,     0,   273,   278,     0,   277,   133,   112,   130,   113,
     163,   164,     0,   165,   171,   143,     0,   144,   147,   111,
     111,   113,   132,   115,     0,     0,     0,   258,   108,   121,
     140,   266,    91,     0,     0,   183,     0,   183,   183,     0,
     160,   150,   152,   177,   183,     0,   174,    28,   253,     0,
       0,    69,     0,    79,     0,     0,    82,     0,     0,   104,
       0,   238,   241,   276,   120,     0,   144,   111,   111,   111,
     143,   111,   148,   145,   118,   127,   128,   116,     0,     0,
     156,   161,   183,   158,     0,   154,   149,   183,   153,   183,
     179,   255,    85,     0,    81,   103,   100,    99,   101,    96,
       0,   111,   117,   123,   124,   144,   136,   126,   129,   146,
     259,   260,   159,   157,   155,   151,   180,     0,   102,     0,
     166,   125,    71,    83
  };

  const short
  parser::yypgoto_[] =
  {
    -367,  -367,  -367,  -367,   514,  -367,  -367,  -367,  -367,  -367,
    -190,    30,   -31,  -367,  -367,   388,   -58,   403,    76,  -125,
     207,   517,  -367,     1,  -367,   529,  -367,   -80,  -367,  -367,
    -367,   200,  -367,  -367,  -367,  -367,  -367,   237,  -367,  -353,
    -367,   100,   151,   193,  -367,  -367,  -231,  -203,   254,  -284,
    -367,  -367,  -366,  -266,  -367,  -362,   123,  -211,  -191,  -105,
    -129,   258,   318,  -367,    79,  -367,   230,  -367,   261,     0,
    -367,  -367,  -367,   224,  -367,  -367,   -91,    -8,    24,    20
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    38,    39,    40,    41,    77,    78,    79,   152,   153,
     354,   355,    42,   265,   155,    43,    44,   157,    45,   288,
      46,    47,    48,    64,    95,   115,   421,   116,    98,   280,
     281,   282,   100,    91,    70,   257,   258,   259,   260,   364,
     365,   429,   366,   232,   233,   318,   306,   323,   234,   235,
     236,   388,   389,   346,   409,   410,   411,   237,   313,   314,
     238,   412,   304,    87,    50,    51,    52,    53,    54,    65,
      56,   273,   274,   275,    57,    58,   180,   181,    67,   367
  };

  const short
  parser::yytable_[] =
  {
      55,    49,   165,    66,   352,   329,   330,   422,     2,   110,
     156,   307,    71,     2,    73,    74,    75,   218,   230,   437,
      84,    92,    88,    89,    59,   298,   186,     2,   188,   -43,
     335,    81,   101,   146,   315,   387,   331,   154,   105,   224,
      55,    49,    69,   451,   117,   453,   269,     2,   230,   230,
     147,   118,   230,   184,   298,    82,    10,   428,  -109,   299,
       2,   144,   298,   336,    59,   298,   271,   103,    55,    49,
      10,   400,     2,    85,   476,   114,   378,   225,   289,   227,
    -109,   -43,   -43,    93,    68,   -43,    60,    63,   299,    72,
     482,   385,    59,    80,   106,   156,   299,    93,   300,   299,
     376,   436,   178,    10,   317,    76,   300,   102,   390,   300,
     332,   219,   189,   386,   168,    10,   489,   392,   170,   380,
     381,   383,   248,   191,   399,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   397,   210,   211,   212,   213,   214,
     215,   216,   319,   332,   200,   241,   185,   243,   459,   321,
     244,   245,   161,    55,    49,   254,   475,   164,   444,   445,
     252,   120,   217,  -190,   122,   104,   261,    55,   121,   263,
    -190,   322,   276,    68,   438,   332,   434,    59,   219,   111,
     298,   353,   253,   111,   290,   219,    66,   179,   446,   119,
      63,    59,   134,    63,   187,    63,    63,   190,   332,   219,
     230,   370,   287,   197,   371,   294,   472,   473,   474,   135,
     478,   345,    68,   450,   299,   297,   350,   424,   172,   229,
     408,   197,   147,   242,   300,   461,    83,   316,    86,   477,
     143,    90,   269,   343,   145,   353,    94,    97,    99,    63,
     491,   197,   256,   308,   425,   415,   111,   173,   224,   229,
     229,   279,   271,   229,   321,   328,    94,   114,   480,   481,
     339,   197,   332,   483,   403,   344,    68,   176,   349,   298,
      63,   159,   122,   158,   197,   334,   322,   111,   166,   490,
     408,   452,   408,   124,   160,   369,   225,   226,   227,    94,
     228,   449,   340,   341,   342,   111,   177,     2,   218,   374,
     134,   298,   197,   299,   372,   377,   111,   345,   219,   266,
     332,   122,   332,   300,   197,   162,   163,   135,   373,  -189,
     375,   393,   124,   138,   139,   174,  -189,   408,   309,   111,
    -191,   196,   408,   401,   197,   299,   379,  -191,   261,   134,
      10,   267,   332,   268,   456,   300,     2,   218,   111,   196,
     231,   175,   169,   417,   198,   404,   135,   219,   405,   363,
     246,   457,   197,     2,   192,   193,   277,   278,    63,   196,
     284,    63,   198,   250,     2,   192,   193,   197,   270,   197,
     231,   231,   435,   255,   231,   199,   182,   218,   183,   196,
     270,   321,   198,   219,   447,   404,   310,   219,   264,   311,
     312,   229,   196,   199,   283,   442,    10,   194,   443,   147,
     406,   195,   198,   322,   256,   448,   286,    10,   194,   462,
     298,   407,   195,   199,   465,   198,   302,   454,   468,   219,
     196,   270,   270,   185,   291,   292,   363,   479,   279,   197,
     293,   295,   196,   199,   219,   466,   305,   324,   122,   395,
     353,   396,   325,   198,   299,   305,   199,   219,   333,   124,
     337,   239,   196,   487,   300,   198,   338,   197,     2,   218,
      26,    27,   112,   348,   197,   133,   134,   356,   303,   219,
     266,    68,   357,   224,   199,   198,   358,   359,   320,   272,
     196,   239,   239,   135,   360,   239,   199,   136,   137,   138,
     139,   272,   361,   363,   197,   196,   197,   196,   368,   362,
     384,    10,   267,   198,   268,   394,   199,   270,   270,   270,
     419,   225,   226,   227,   347,   228,   426,   351,   198,   427,
     198,   430,   231,   407,   420,   431,   432,   440,   218,   458,
     463,   469,   272,   272,   199,   363,   351,   464,   197,   122,
     484,    94,   493,   327,   109,   262,   249,   270,    96,   199,
     124,   199,   423,   122,   270,   113,   488,   196,   125,   126,
     127,   128,   129,   130,   124,   402,   133,   134,   467,   398,
     485,   418,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   134,     0,     0,   135,   196,     0,     0,   136,   137,
     138,   139,   196,   270,   413,     0,     0,     0,   135,     0,
     416,   270,   136,   137,   138,   139,     0,     0,   198,     0,
       0,   199,     0,     0,     0,   198,     0,     0,   272,   272,
     272,     0,   196,     0,   196,     0,     0,   391,     0,     2,
     192,   193,     0,   239,     0,     0,     0,     0,     0,   199,
     219,     0,     0,     0,     0,   198,   199,   198,     0,     0,
       0,   270,     0,     0,     0,     0,   455,     0,   272,     0,
     326,     0,   460,     0,     0,   272,   196,   270,     0,     0,
       0,     0,    10,   194,     0,     0,   199,   195,   199,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,   198,
       0,   107,     0,   439,     0,   441,     1,     2,     3,     4,
       5,     6,     7,     8,   272,     9,     0,   486,    20,    21,
       0,    22,   272,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     2,   218,     0,    25,    26,    27,    28,     0,
      30,    31,     0,   219,   220,     0,     0,     0,     0,     0,
      10,    11,     0,     0,   471,    12,     0,   108,    13,     0,
      14,    15,     0,   221,     0,     0,    16,     0,     0,     0,
       0,     0,   272,    17,   222,    10,    18,    19,    20,    21,
     223,    22,     0,     0,     0,     0,     0,    23,   272,    24,
       0,     0,   224,     0,     0,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,   122,
     225,   226,   227,     0,   228,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     127,   128,   129,   130,   131,     0,   133,   134,     0,    10,
      11,     0,     0,     0,    12,     0,   247,    13,     0,    14,
      15,     0,     0,     0,   135,    16,     0,     0,   136,   137,
     138,   139,    17,   140,   141,     0,    19,    20,    21,     0,
      22,     0,   148,   149,   150,   151,    23,     0,    24,     0,
       0,     2,   218,     0,    25,    26,    27,    28,    29,    30,
      31,     0,   219,   266,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,     1,     2,     3,     4,     5,     6,
       7,     8,   309,     9,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,    10,   267,     0,   268,     0,   124,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,   130,     0,     0,   133,   134,     0,    10,    11,
       0,     0,     0,    12,     0,     0,    13,     0,    14,    15,
       0,     0,     0,   135,    16,     0,     0,   136,   137,   138,
     139,    17,   140,   141,     0,    19,    20,    21,     0,    22,
       0,   148,   149,   150,   151,    23,     0,    24,     0,     0,
       2,   218,     0,    25,    26,    27,    28,    29,    30,    31,
       0,   219,   266,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,     1,     2,     3,     4,     5,     6,     7,
       8,   309,     9,     0,     0,     0,     0,   122,     0,     0,
       0,     0,     0,    10,   382,     0,   268,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,    10,    11,     0,
       0,     0,    12,     0,     0,    13,     0,    14,    15,     0,
      68,     0,   135,    16,   167,     0,   136,   137,   138,   139,
      17,   140,   141,    18,    19,    20,    21,     0,    22,     0,
       0,     0,   142,     0,    23,     0,    24,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,    37,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    10,    11,    62,     0,
       0,    12,     0,     0,    13,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    10,
      11,     0,    68,    19,    12,     0,     0,    13,     0,    14,
      15,     0,     0,    23,     0,    16,     0,     0,     0,     0,
       0,     0,    26,    27,    28,     0,    19,     0,     0,     0,
       0,   122,     0,    32,    33,     0,    23,    34,    35,    36,
      37,     0,   124,     0,     0,    26,    27,    28,     0,     0,
     125,   126,   127,   128,   129,   130,    32,    33,   133,   134,
      34,    35,    36,    37,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,   135,     0,     0,     0,
     136,   137,   138,   139,     0,   140,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    12,   251,     0,    13,     0,    14,    15,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,    10,    11,   296,     0,    19,    12,     0,     0,    13,
       0,    14,    15,     0,     0,    23,     0,    16,     0,     0,
       0,     0,     0,     0,    26,    27,    28,     0,    19,     0,
       0,     0,     0,     0,     0,    32,    33,     0,    23,    34,
      35,    36,    37,     0,     0,     0,     0,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,   348,     0,     0,    12,     0,     0,    13,     0,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,    19,    12,     0,
       0,    13,     0,    14,    15,     0,     0,    23,     0,    16,
       0,     0,     0,     0,     0,     0,    26,    27,    28,     0,
      19,     0,     0,     0,     0,     0,     0,    32,    33,     0,
      23,    34,    35,    36,    37,     0,     0,     0,     0,    26,
      27,    28,   122,     0,     0,     0,     0,     0,   123,     0,
      32,    33,     0,   124,    34,    35,    36,    37,     0,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   122,
       0,   136,   137,   138,   139,     0,   140,   141,     0,     0,
     124,     0,     0,     0,     0,     0,     0,   142,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,   135,     0,   122,     0,   136,   137,
     138,   139,     0,   140,   141,     0,     0,   124,     0,     0,
       0,     0,     0,     0,   142,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
       0,   135,     0,   122,     0,   136,   137,   138,   139,     0,
     140,   141,     0,     0,   124,     0,     0,     0,     0,     0,
       0,   142,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,   135,     0,
     122,     0,   136,   137,   138,   139,     0,   140,   141,     0,
       0,   124,     0,     0,     0,     0,     0,     0,   142,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,     0,     0,   135,     0,   122,     0,   136,
     137,   138,   139,     0,   140,   141,     0,     0,   124,     0,
       0,     0,     0,     0,     0,   142,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   301,   122,     0,   136,   137,   138,   139,
       0,   140,   141,     0,     0,   124,     0,     0,     0,     0,
       0,     0,   142,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   414,   135,
       0,   122,     0,   136,   137,   138,   139,     0,   140,   141,
       0,     0,   124,     0,     0,     0,     0,     0,     0,   142,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   433,   122,     0,
     136,   137,   138,   139,     0,   140,   141,     0,     0,   124,
       0,     0,     0,     0,     0,     0,   142,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,     0,     0,   135,     0,   122,     0,   136,   137,   138,
     139,     0,   140,   141,     0,     0,   124,     0,     0,     0,
       0,     0,     0,   142,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
     135,     0,   122,     0,   136,   137,   138,   139,     0,   140,
     141,     0,     0,   124,     0,     0,     0,     0,     0,     0,
     142,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   136,   137,   138,   139,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142
  };

  const short
  parser::yycheck_[] =
  {
       0,     0,    82,    11,   270,   236,   237,   360,     6,    40,
      68,   222,    12,     6,    14,    15,    16,     7,   143,   385,
      20,     5,    22,    23,     0,    20,   117,     6,   119,     0,
      15,    73,    32,    51,   225,   319,   239,    68,     0,    66,
      40,    40,    12,   405,    50,   407,   171,     6,   173,   174,
      68,    57,   177,    21,    20,    97,    49,    15,    48,    54,
       6,    61,    20,    48,    40,    20,   171,    37,    68,    68,
      49,    37,     6,     7,   440,    54,   307,   104,   183,   106,
      70,    52,    53,    76,    52,    56,    10,    11,    54,    13,
     452,    48,    68,    17,    56,   153,    54,    76,    64,    54,
     303,   385,   102,    49,   229,   103,    64,    50,   319,    64,
     239,    17,   120,    70,    84,    49,   469,   320,    88,   310,
     311,   312,   153,   123,   327,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   324,   135,   136,   137,   138,   139,
     140,   141,    48,   272,   124,   145,   116,   147,   414,    15,
     150,   151,    76,   153,   153,   163,   440,    81,   389,   390,
     160,    50,   142,    50,     9,     0,   166,   167,    57,   169,
      57,    37,   172,    52,   385,   304,   379,   153,    17,    49,
      20,    21,   162,    49,   184,    17,   194,   111,   391,    50,
     114,   167,    37,   117,   118,   119,   120,   121,   327,    17,
     325,   292,   182,   124,   295,    51,   437,   438,   439,    54,
     441,    50,    52,   404,    54,   195,    48,    21,    21,   143,
     345,   142,    68,   147,    64,   415,    19,   227,    21,   440,
      50,    24,   357,   264,    48,    21,    29,    30,    31,   163,
     471,   162,   166,   223,    48,   350,    49,    50,    66,   173,
     174,   175,   357,   177,    15,   235,    49,    54,   448,   449,
     260,   182,   391,   454,   344,   264,    52,    21,   268,    20,
     194,    55,     9,    55,   195,   255,    37,    49,    50,   470,
     405,   406,   407,    20,    68,   285,   104,   105,   106,    82,
     108,   396,   262,   263,   264,    49,    50,     6,     7,   299,
      37,    20,   223,    54,    55,   305,    49,    50,    17,    18,
     439,     9,   441,    64,   235,    48,    15,    54,   298,    50,
     300,   321,    20,    60,    61,    50,    57,   452,    37,    49,
      50,   124,   457,   333,   255,    54,    55,    57,   338,    37,
      49,    50,   471,    52,    51,    64,     6,     7,    49,   142,
     143,    52,    79,   353,   124,    15,    54,    17,    18,   283,
      56,    68,   283,     6,     7,     8,   173,   174,   292,   162,
     177,   295,   142,    53,     6,     7,     8,   298,   171,   300,
     173,   174,   382,    48,   177,   124,    20,     7,    22,   182,
     183,    15,   162,    17,   394,    15,   105,    17,    81,   108,
     109,   325,   195,   142,    50,    37,    49,    50,   388,    68,
      70,    54,   182,    37,   338,   395,    55,    49,    50,   419,
      20,   345,    54,   162,   424,   195,   219,    15,   428,    17,
     223,   224,   225,   403,    51,    50,   360,    37,   362,   360,
      51,    50,   235,   182,    17,   425,    15,    51,     9,    20,
      21,    22,    68,   223,    54,    15,   195,    17,    48,    20,
      51,   143,   255,   463,    64,   235,    68,   388,     6,     7,
      95,    96,    97,    51,   395,    36,    37,    53,   220,    17,
      18,    52,    68,    66,   223,   255,    51,    51,   230,   171,
     283,   173,   174,    54,    50,   177,   235,    58,    59,    60,
      61,   183,    53,   427,   425,   298,   427,   300,    51,    68,
      37,    49,    50,   283,    52,    15,   255,   310,   311,   312,
      21,   104,   105,   106,   266,   108,    51,   269,   298,    68,
     300,    21,   325,   457,   102,    51,    51,    48,     7,    37,
      50,    50,   224,   225,   283,   469,   288,    51,   469,     9,
      37,   344,    51,   235,    40,   167,   153,   350,    29,   298,
      20,   300,   362,     9,   357,    48,   466,   360,    28,    29,
      30,    31,    32,    33,    20,   338,    36,    37,   427,   325,
     457,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,    37,    -1,    -1,    54,   388,    -1,    -1,    58,    59,
      60,    61,   395,   396,   346,    -1,    -1,    -1,    54,    -1,
     352,   404,    58,    59,    60,    61,    -1,    -1,   388,    -1,
      -1,   360,    -1,    -1,    -1,   395,    -1,    -1,   310,   311,
     312,    -1,   425,    -1,   427,    -1,    -1,   319,    -1,     6,
       7,     8,    -1,   325,    -1,    -1,    -1,    -1,    -1,   388,
      17,    -1,    -1,    -1,    -1,   425,   395,   427,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,   408,    -1,   350,    -1,
      37,    -1,   414,    -1,    -1,   357,   469,   470,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,   425,    54,   427,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,   469,
      -1,     0,    -1,   385,    -1,   387,     5,     6,     7,     8,
       9,    10,    11,    12,   396,    14,    -1,   459,    77,    78,
      -1,    80,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,    -1,     6,     7,    -1,    94,    95,    96,    97,    -1,
      99,   100,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,   436,    54,    -1,    56,    57,    -1,
      59,    60,    -1,    37,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,   454,    72,    48,    49,    75,    76,    77,    78,
      54,    80,    -1,    -1,    -1,    -1,    -1,    86,   470,    88,
      -1,    -1,    66,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,
      -1,   110,   111,   112,   113,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,     9,
     104,   105,   106,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    54,    65,    -1,    -1,    58,    59,
      60,    61,    72,    63,    64,    -1,    76,    77,    78,    -1,
      80,    -1,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,     6,     7,    -1,    94,    95,    96,    97,    98,    99,
     100,    -1,    17,    18,    -1,    -1,   106,   107,    -1,    -1,
     110,   111,   112,   113,     5,     6,     7,     8,     9,    10,
      11,    12,    37,    14,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    37,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    -1,    -1,    54,    65,    -1,    -1,    58,    59,    60,
      61,    72,    63,    64,    -1,    76,    77,    78,    -1,    80,
      -1,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
       6,     7,    -1,    94,    95,    96,    97,    98,    99,   100,
      -1,    17,    18,    -1,    -1,   106,   107,    -1,    -1,   110,
     111,   112,   113,     5,     6,     7,     8,     9,    10,    11,
      12,    37,    14,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      52,    -1,    54,    65,    56,    -1,    58,    59,    60,    61,
      72,    63,    64,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    -1,    74,    -1,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,   110,   111,
     112,   113,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    76,    54,    -1,    -1,    57,    -1,    59,
      60,    -1,    -1,    86,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    -1,    76,    -1,    -1,    -1,
      -1,     9,    -1,   106,   107,    -1,    86,   110,   111,   112,
     113,    -1,    20,    -1,    -1,    95,    96,    97,    -1,    -1,
      28,    29,    30,    31,    32,    33,   106,   107,    36,    37,
     110,   111,   112,   113,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    63,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    55,    -1,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    76,    54,    -1,    -1,    57,
      -1,    59,    60,    -1,    -1,    86,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    86,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
      -1,    -1,   110,   111,   112,   113,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    76,    54,    -1,
      -1,    57,    -1,    59,    60,    -1,    -1,    86,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,
      86,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    95,
      96,    97,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,
     106,   107,    -1,    20,   110,   111,   112,   113,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,     9,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    74,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    -1,     9,    -1,    58,    59,
      60,    61,    -1,    63,    64,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    28,    29,    30,    31,    32,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,     9,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74
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
     132,    48,    51,   132,   137,   183,   191,   192,    52,   125,
     148,   183,   132,   183,   183,   183,   103,   119,   120,   121,
     132,    73,    97,   134,   183,     7,   134,   177,   183,   183,
     134,   147,     5,    76,   134,   138,   139,   134,   142,   134,
     146,   183,    50,   125,     0,     0,    56,     0,    56,   118,
     126,    49,    97,   135,    54,   139,   141,    50,    57,    50,
      50,    57,     9,    15,    20,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    54,    58,    59,    60,    61,
      63,    64,    74,    50,   183,    48,    51,    68,    82,    83,
      84,    85,   122,   123,   126,   128,   130,   131,    55,    55,
      68,   132,    48,    15,   132,   141,    50,    56,   125,    79,
     125,    52,    21,    50,    50,    52,    21,    50,   183,   132,
     190,   191,    20,    22,    21,   125,   190,   132,   190,   191,
     132,   183,     7,     8,    50,    54,   134,   178,   180,   182,
     193,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   193,     7,    17,
      18,    37,    48,    54,    66,   104,   105,   106,   108,   132,
     133,   134,   157,   158,   162,   163,   164,   171,   174,   176,
      51,   183,   132,   183,   183,   183,    56,    56,   126,   131,
      53,    55,   183,   193,   191,    48,   132,   149,   150,   151,
     152,   183,   129,   183,    81,   127,    18,    50,    52,   133,
     134,   173,   176,   185,   186,   187,   183,   157,   157,   132,
     143,   144,   145,    50,   157,    51,    55,   193,   133,   173,
     183,    51,    50,    51,    51,    50,    51,   193,    20,    54,
      64,    55,   134,   175,   176,    15,   160,   171,   193,    37,
     105,   108,   109,   172,   173,   172,   183,   133,   159,    48,
     175,    15,    37,   161,    51,    68,    37,   176,   193,   160,
     160,   161,   174,    48,   193,    15,    48,    51,    68,   183,
     125,   125,   125,   126,   137,    50,   167,   175,    51,   183,
      48,   175,   167,    21,   124,   125,    53,    68,    51,    51,
      50,    53,    68,   132,   153,   154,   156,   193,    51,   183,
     190,   190,    55,   193,   183,   193,   161,   183,   160,    55,
     172,   172,    50,   172,    37,    48,    70,   163,   165,   166,
     171,   176,   161,   183,    15,    20,    22,   124,   162,   161,
      37,   183,   151,   141,    15,    18,    70,   132,   133,   168,
     169,   170,   175,   175,    53,   173,   175,   183,   187,    21,
     102,   140,   153,   145,    21,    48,    51,    68,    15,   155,
      21,    51,    51,    55,   161,   183,   163,   166,   171,   176,
      48,   176,    37,   193,   160,   160,   161,   183,   193,   173,
     172,   169,   133,   169,    15,   175,    51,    68,    37,   167,
     175,   124,   183,    50,    51,   183,   193,   156,   183,    50,
      51,   176,   160,   160,   160,   163,   166,   171,   160,    37,
     124,   124,   169,   172,    37,   170,   175,   183,   155,   153,
     172,   160,    51,    51
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
     179,   179,   179,   180,   181,   181,   182,   182,   182,   182,
     182,   182,   182,   183,   183,   183,   183,   183,   183,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     189,   190,   190,   191,   191,   191,   191,   192,   192,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193
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
       3,     3,     3,     3,     2,     5,     4,     3,     6,     4,
       3,     6,     4,     1,     1,     1,     1,     1,     1,     5,
       0,     1,     1,     3,     2,     4,     1,     4,     5,     7,
       7,     0,     1,     1,     3,     3,     5,     2,     1,     1,
       1,     1,     1,     3,     2,     1,     4,     3,     3
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
    1139,  1146,  1148,  1162,  1164,  1166,  1169,  1171,  1175,  1177,
    1181,  1183,  1185,  1187,  1189,  1191,  1193,  1196,  1200,  1203,
    1206,  1208,  1220,  1240,  1253,  1257,  1264,  1266,  1268,  1273,
    1275,  1277,  1282,  1287,  1288,  1289,  1290,  1291,  1292,  1307,
    1312,  1313,  1336,  1338,  1343,  1345,  1350,  1352,  1357,  1364,
    1372,  1383,  1385,  1390,  1392,  1398,  1403,  1411,  1413,  1453,
    1455,  1457,  1459,  1460,  1462,  1464,  1465,  1467,  1469
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
#line 6308 "annium.tab.cpp"

#line 1664 "annium.y"

