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

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.copy< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.copy< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.copy< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (YY_MOVE (that.value));
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
        value.move< annium::annotated_decimal_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.move< resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (s.value));
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
        value.YY_MOVE_OR_COPY< annium::annotated_decimal_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< annium::annotated_integer_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.YY_MOVE_OR_COPY< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< syntax_pattern_field_list_t > (YY_MOVE (that.value));
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
        value.move< annium::annotated_decimal_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.move< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (that.value));
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
        value.copy< annium::annotated_decimal_view > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< annium::annotated_integer_view > (that.value);
        break;

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.copy< identifier > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.copy< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.copy< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (that.value);
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
        value.move< annium::annotated_decimal_view > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< annium::annotated_integer_view > (that.value);
        break;

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        value.move< identifier > (that.value);
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        value.move< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        value.move< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (that.value);
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
#line 334 "annium.y"
                 { }
#line 1843 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 334 "annium.y"
                 { }
#line 1849 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 334 "annium.y"
                 { }
#line 1855 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 334 "annium.y"
                 { }
#line 1861 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 334 "annium.y"
                 { }
#line 1867 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 334 "annium.y"
                 { }
#line 1873 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 334 "annium.y"
                 { }
#line 1879 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 334 "annium.y"
                 { }
#line 1885 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 334 "annium.y"
                 { }
#line 1891 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 334 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 334 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 334 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 334 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 334 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 334 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 334 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 334 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 334 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 334 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 334 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 334 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 334 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 334 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 334 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 334 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 334 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 334 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 334 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 334 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 334 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 334 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 334 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 334 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 334 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 334 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 334 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 334 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 334 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 334 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 334 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 334 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 334 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 334 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 334 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 334 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
#line 334 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 334 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_let_decl: // let-decl
#line 334 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl_start: // let-decl-start
#line 334 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 334 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
#line 334 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
#line 334 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_function_body: // function-body
#line 334 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_braced_statements: // braced-statements
#line 334 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
#line 334 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
#line 334 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
#line 334 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_infunction_statement: // infunction-statement
#line 334 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 334 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
#line 334 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 334 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
#line 334 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
#line 334 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
#line 334 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_name: // fn-name
#line 334 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
#line 334 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
#line 334 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_decl: // fn-decl
#line 334 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
#line 334 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
#line 334 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_case_list: // case-list
#line 334 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_case_decl: // case-decl
#line 334 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
#line 334 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_using_decl: // using-decl
#line 334 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_expression_list: // expression-list
#line 334 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
#line 334 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_argument_list: // argument-list
#line 334 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 334 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_argument_name: // argument-name
#line 334 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
#line 334 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_field_list: // field-list
#line 334 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
#line 334 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 334 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
#line 334 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_parameter_list: // parameter-list
#line 334 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
#line 334 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
#line 334 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
#line 334 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 334 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
#line 334 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
#line 334 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_constraint_expression: // constraint-expression
#line 334 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 334 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_pattern_list: // pattern-list
#line 334 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
#line 334 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_pattern_field: // pattern-field
#line 334 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
#line 334 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
#line 334 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 334 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
#line 334 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
#line 334 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
#line 334 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
#line 334 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
#line 334 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
#line 334 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_grouped_expression: // grouped-expression
#line 334 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_new_expression: // new-expression
#line 334 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_call_expression: // call-expression
#line 334 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_syntax_expression: // syntax-expression
#line 334 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
#line 334 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_lambda_expression: // lambda-expression
#line 334 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
#line 334 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_pack_expression: // pack-expression
#line 334 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_compound_expression: // compound-expression
#line 334 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_type_expr: // type-expr
#line 334 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
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

      case symbol_kind::S_133_fn_name: // fn-name
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
      case symbol_kind::S_147_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
      case symbol_kind::S_136_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_140_case_decl: // case-decl
        yylhs.value.emplace< identifier > ();
        break;

      case symbol_kind::S_116_let_decl: // let-decl
      case symbol_kind::S_117_let_decl_start: // let-decl-start
      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
      case symbol_kind::S_145_argument_list: // argument-list
      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_181_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_153_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
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
        yylhs.value.emplace< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_123_finished_statement: // finished-statement
      case symbol_kind::S_125_generic_statement: // generic-statement
      case symbol_kind::S_126_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_121_function_body: // function-body
      case symbol_kind::S_122_braced_statements: // braced-statements
      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_160_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
      case symbol_kind::S_149_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
      case symbol_kind::S_139_case_list: // case-list
        yylhs.value.emplace< std::vector<identifier> > ();
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_174_grouped_expression: // grouped-expression
      case symbol_kind::S_175_new_expression: // new-expression
      case symbol_kind::S_176_call_expression: // call-expression
      case symbol_kind::S_177_syntax_expression: // syntax-expression
      case symbol_kind::S_179_lambda_expression: // lambda-expression
      case symbol_kind::S_182_compound_expression: // compound-expression
      case symbol_kind::S_183_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_143_expression_list: // expression-list
      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_164_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_162_pattern_list: // pattern-list
        yylhs.value.emplace< syntax_pattern_field_list_t > ();
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
#line 339 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3017 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 340 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3023 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 345 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3029 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 347 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3035 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 349 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3041 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 366 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3047 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 367 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3053 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 369 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3059 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 371 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3065 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 376 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3071 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 378 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3077 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 380 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3083 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 382 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3089 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 384 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3095 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 388 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3101 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 390 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3107 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 395 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3113 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 397 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3119 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 401 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3125 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 403 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3131 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 408 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3137 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 410 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3143 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 412 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3149 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 417 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3155 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 418 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3161 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 420 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3167 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 422 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3173 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 427 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3179 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression
#line 431 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3185 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 442 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3191 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 447 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3197 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 449 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), std::move(yystack_[1].value.as < syntax_expression > ()) } }; }
#line 3203 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 451 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3209 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 453 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3215 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 455 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[3].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[2].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3221 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 457 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3231 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 467 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3237 "annium.tab.cpp"
    break;

  case 39: // infunction-statement-set: infunction-statement-any
#line 471 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3243 "annium.tab.cpp"
    break;

  case 40: // infunction-statement-set: finished-infunction-statement-any
#line 472 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3249 "annium.tab.cpp"
    break;

  case 41: // generic-statement: LET let-decl
#line 477 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3255 "annium.tab.cpp"
    break;

  case 42: // generic-statement: "`typefn`" fn-start-decl
#line 479 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3261 "annium.tab.cpp"
    break;

  case 43: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 481 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3272 "annium.tab.cpp"
    break;

  case 44: // generic-statement: USING using-decl
#line 488 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3278 "annium.tab.cpp"
    break;

  case 45: // generic-statement: compound-expression
#line 490 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3284 "annium.tab.cpp"
    break;

  case 46: // generic-statement: syntax-expression "`=`" syntax-expression
#line 492 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3293 "annium.tab.cpp"
    break;

  case 47: // infunction-statement: generic-statement
#line 499 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3299 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: "`break`"
#line 501 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3305 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`continue`"
#line 503 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3311 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`return`"
#line 505 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3317 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`" syntax-expression
#line 507 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3323 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`yield`" syntax-expression
#line 509 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3329 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 514 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3335 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 522 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3341 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 537 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3347 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 539 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3353 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 541 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3359 "annium.tab.cpp"
    break;

  case 58: // fn-kind: INLINE
#line 546 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3365 "annium.tab.cpp"
    break;

  case 59: // fn-kind: VIABLE
#line 547 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3371 "annium.tab.cpp"
    break;

  case 60: // fn-kind-set: fn-kind
#line 551 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3377 "annium.tab.cpp"
    break;

  case 61: // fn-kind-set: fn-kind-set fn-kind
#line 552 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3383 "annium.tab.cpp"
    break;

  case 62: // fn-prefix-decl: "`fn`"
#line 557 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3389 "annium.tab.cpp"
    break;

  case 63: // fn-prefix-decl: fn-kind-set "`fn`"
#line 559 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3395 "annium.tab.cpp"
    break;

  case 64: // fn-name: qname
#line 564 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3401 "annium.tab.cpp"
    break;

  case 65: // fn-name: "`new`"
#line 566 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3407 "annium.tab.cpp"
    break;

  case 66: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 571 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3413 "annium.tab.cpp"
    break;

  case 67: // fn-requirement-opt: %empty
#line 588 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3419 "annium.tab.cpp"
    break;

  case 68: // fn-requirement-opt: REQUIRES syntax-expression
#line 590 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3425 "annium.tab.cpp"
    break;

  case 69: // fn-decl: fn-start-decl
#line 601 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3431 "annium.tab.cpp"
    break;

  case 70: // fn-decl: fn-start-decl "`->`" type-expr
#line 603 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3437 "annium.tab.cpp"
    break;

  case 71: // fn-decl: fn-start-decl "`~>`" pattern
#line 605 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3443 "annium.tab.cpp"
    break;

  case 72: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 612 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3449 "annium.tab.cpp"
    break;

  case 73: // case-list-opt: %empty
#line 616 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3455 "annium.tab.cpp"
    break;

  case 74: // case-list-opt: case-list
#line 617 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3461 "annium.tab.cpp"
    break;

  case 75: // case-list: case-decl
#line 622 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3467 "annium.tab.cpp"
    break;

  case 76: // case-list: case-list "," case-decl
#line 624 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3473 "annium.tab.cpp"
    break;

  case 77: // case-decl: identifier
#line 629 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3479 "annium.tab.cpp"
    break;

  case 78: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 635 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3485 "annium.tab.cpp"
    break;

  case 79: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 637 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3491 "annium.tab.cpp"
    break;

  case 80: // using-decl: qname "`=>`" syntax-expression
#line 660 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3501 "annium.tab.cpp"
    break;

  case 81: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 666 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3512 "annium.tab.cpp"
    break;

  case 82: // expression-list: syntax-expression
#line 683 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3518 "annium.tab.cpp"
    break;

  case 83: // expression-list: expression-list "," syntax-expression
#line 685 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3524 "annium.tab.cpp"
    break;

  case 84: // argument-list-opt: %empty
#line 690 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3530 "annium.tab.cpp"
    break;

  case 85: // argument-list-opt: argument-list
#line 691 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3536 "annium.tab.cpp"
    break;

  case 86: // argument-list: argument
#line 696 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3542 "annium.tab.cpp"
    break;

  case 87: // argument-list: argument-list "," argument
#line 698 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3548 "annium.tab.cpp"
    break;

  case 88: // argument: argument-name syntax-expression
#line 703 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3554 "annium.tab.cpp"
    break;

  case 89: // argument: syntax-expression
#line 705 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3560 "annium.tab.cpp"
    break;

  case 90: // argument-name: identifier "`=`"
#line 710 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3566 "annium.tab.cpp"
    break;

  case 91: // argument-name: identifier "`:`"
#line 712 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3572 "annium.tab.cpp"
    break;

  case 92: // field-list-opt: %empty
#line 717 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3578 "annium.tab.cpp"
    break;

  case 93: // field-list-opt: field-list
#line 718 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3584 "annium.tab.cpp"
    break;

  case 94: // field-list: field
#line 723 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3590 "annium.tab.cpp"
    break;

  case 95: // field-list: field-list "," field
#line 725 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3596 "annium.tab.cpp"
    break;

  case 96: // field-default-value-opt: %empty
#line 729 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3602 "annium.tab.cpp"
    break;

  case 97: // field-default-value-opt: "`=`" syntax-expression
#line 730 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3608 "annium.tab.cpp"
    break;

  case 98: // field: identifier "`:`" type-expr field-default-value-opt
#line 735 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3614 "annium.tab.cpp"
    break;

  case 99: // field: identifier "`=>`" syntax-expression
#line 737 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::any_constexpr_type, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3620 "annium.tab.cpp"
    break;

  case 100: // parameter-list-opt: %empty
#line 743 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3626 "annium.tab.cpp"
    break;

  case 101: // parameter-list-opt: parameter-list
#line 744 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3632 "annium.tab.cpp"
    break;

  case 102: // parameter-list: parameter-decl
#line 749 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3638 "annium.tab.cpp"
    break;

  case 103: // parameter-list: parameter-list "," parameter-decl
#line 751 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3644 "annium.tab.cpp"
    break;

  case 104: // internal-identifier-opt: %empty
#line 755 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3650 "annium.tab.cpp"
    break;

  case 105: // internal-identifier-opt: internal-identifier
#line 756 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3656 "annium.tab.cpp"
    break;

  case 106: // parameter-default-value-opt: %empty
#line 760 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3662 "annium.tab.cpp"
    break;

  case 107: // parameter-default-value-opt: "`=`" syntax-expression
#line 761 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3668 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 766 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3674 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 768 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type };  }
#line 3680 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 770 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3686 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 772 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3692 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 774 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3698 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: internal-identifier "`:`" concept-expression-list parameter-default-value-opt
#line 776 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type };   }
#line 3704 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 778 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3710 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 780 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3716 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: pattern-mod parameter-default-value-opt
#line 782 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3722 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 790 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3728 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: "`_`" parameter-default-value-opt
#line 792 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3734 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 794 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3740 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: "`...`" parameter-default-value-opt
#line 796 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3746 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 801 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3752 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 803 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3758 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 805 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3764 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 807 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3770 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: qname parameter-default-value-opt
#line 809 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3779 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 814 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3785 "annium.tab.cpp"
    break;

  case 127: // constraint-expression-specified-mod: "constexpr modifier"
#line 818 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::any_constexpr_type }; }
#line 3791 "annium.tab.cpp"
    break;

  case 128: // constraint-expression-specified-mod: "runctime modifier"
#line 819 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3797 "annium.tab.cpp"
    break;

  case 129: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 824 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3803 "annium.tab.cpp"
    break;

  case 130: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 826 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3809 "annium.tab.cpp"
    break;

  case 131: // constraint-expression-specified: constraint-expression-specified-mod
#line 830 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3815 "annium.tab.cpp"
    break;

  case 132: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 832 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3821 "annium.tab.cpp"
    break;

  case 133: // constraint-expression-mod: %empty
#line 837 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3830 "annium.tab.cpp"
    break;

  case 134: // constraint-expression-mod: constraint-expression-specified-mod
#line 841 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 3836 "annium.tab.cpp"
    break;

  case 135: // constraint-expression: constraint-expression-mod type-expr
#line 846 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3842 "annium.tab.cpp"
    break;

  case 136: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 848 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3848 "annium.tab.cpp"
    break;

  case 137: // constraint-expression: constraint-expression-mod
#line 852 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3854 "annium.tab.cpp"
    break;

  case 138: // constraint-expression: constraint-expression-mod "`...`"
#line 854 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3860 "annium.tab.cpp"
    break;

  case 139: // subpatterns: "`(`" pattern-list "`)`"
#line 864 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3866 "annium.tab.cpp"
    break;

  case 140: // pattern-list: pattern-field
#line 869 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 3872 "annium.tab.cpp"
    break;

  case 141: // pattern-list: pattern-list "," pattern-field
#line 871 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 3878 "annium.tab.cpp"
    break;

  case 142: // pattern-field-sfx: concept-expression-list-opt
#line 877 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3884 "annium.tab.cpp"
    break;

  case 143: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 879 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3890 "annium.tab.cpp"
    break;

  case 144: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 882 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3896 "annium.tab.cpp"
    break;

  case 145: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 884 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3902 "annium.tab.cpp"
    break;

  case 146: // pattern-field-sfx: "`=`" pattern-sfx
#line 888 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3908 "annium.tab.cpp"
    break;

  case 147: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 891 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3914 "annium.tab.cpp"
    break;

  case 148: // pattern-field: identifier pattern-field-sfx
#line 897 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3920 "annium.tab.cpp"
    break;

  case 149: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 900 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3926 "annium.tab.cpp"
    break;

  case 150: // pattern-field: pattern-field-sfx
#line 913 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 3932 "annium.tab.cpp"
    break;

  case 151: // pattern-field: "`_`" pattern-field-sfx
#line 916 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 3938 "annium.tab.cpp"
    break;

  case 152: // pattern-mod: "`~`" pattern-sfx
#line 920 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3944 "annium.tab.cpp"
    break;

  case 153: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 921 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3950 "annium.tab.cpp"
    break;

  case 154: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 922 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3956 "annium.tab.cpp"
    break;

  case 155: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 923 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3962 "annium.tab.cpp"
    break;

  case 156: // pattern-mod: "`~`" "typename modifier"
#line 924 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3968 "annium.tab.cpp"
    break;

  case 157: // pattern-mod: "typename modifier" pattern-sfx
#line 925 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3974 "annium.tab.cpp"
    break;

  case 158: // pattern-mod: "typename modifier"
#line 926 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3980 "annium.tab.cpp"
    break;

  case 159: // pattern-sfx: pattern
#line 930 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 3986 "annium.tab.cpp"
    break;

  case 160: // pattern-sfx: pattern "`...`"
#line 931 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3992 "annium.tab.cpp"
    break;

  case 161: // pattern-sfx: "`...`"
#line 932 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3998 "annium.tab.cpp"
    break;

  case 162: // pattern: qname
#line 937 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4004 "annium.tab.cpp"
    break;

  case 163: // pattern: qname subpatterns concept-expression-list-opt
#line 939 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4010 "annium.tab.cpp"
    break;

  case 164: // pattern: internal-identifier concept-expression-list-opt
#line 941 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4016 "annium.tab.cpp"
    break;

  case 165: // pattern: "`_`" concept-expression-list-opt
#line 943 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4022 "annium.tab.cpp"
    break;

  case 166: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 945 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4028 "annium.tab.cpp"
    break;

  case 167: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 947 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4034 "annium.tab.cpp"
    break;

  case 168: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 949 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4040 "annium.tab.cpp"
    break;

  case 169: // pattern: concept-expression-list
#line 951 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4046 "annium.tab.cpp"
    break;

  case 170: // concept-expression: "`@`" qname
#line 956 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4052 "annium.tab.cpp"
    break;

  case 171: // concept-expression-list-opt: %empty
#line 961 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4058 "annium.tab.cpp"
    break;

  case 172: // concept-expression-list-opt: concept-expression-list
#line 962 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4064 "annium.tab.cpp"
    break;

  case 173: // concept-expression-list: concept-expression
#line 967 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4070 "annium.tab.cpp"
    break;

  case 174: // concept-expression-list: concept-expression-list concept-expression
#line 969 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4076 "annium.tab.cpp"
    break;

  case 175: // reference-expression: CONTEXT_IDENTIFIER
#line 975 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4082 "annium.tab.cpp"
    break;

  case 176: // reference-expression: qname
#line 977 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4088 "annium.tab.cpp"
    break;

  case 177: // any-reference-expression: RESERVED_IDENTIFIER
#line 982 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4094 "annium.tab.cpp"
    break;

  case 178: // any-reference-expression: CONTEXT_IDENTIFIER
#line 984 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4100 "annium.tab.cpp"
    break;

  case 179: // any-reference-expression: qname
#line 986 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4106 "annium.tab.cpp"
    break;

  case 180: // any-reference-expression: any-reference-expression "`.`" identifier
#line 988 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4112 "annium.tab.cpp"
    break;

  case 181: // any-reference-expression: call-expression "`.`" identifier
#line 990 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4118 "annium.tab.cpp"
    break;

  case 182: // syntax-expression-base: "nil"
#line 995 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4124 "annium.tab.cpp"
    break;

  case 183: // syntax-expression-base: "true"
#line 997 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4130 "annium.tab.cpp"
    break;

  case 184: // syntax-expression-base: "false"
#line 999 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4136 "annium.tab.cpp"
    break;

  case 185: // syntax-expression-base: INTEGER
#line 1001 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4142 "annium.tab.cpp"
    break;

  case 186: // syntax-expression-base: DECIMAL
#line 1003 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4148 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-base: DECIMAL_S
#line 1005 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4154 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-base: INTEGER_INDEX
#line 1007 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4160 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: STRING
#line 1009 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4166 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: CT_IDENTIFIER
#line 1011 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4172 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: any-reference-expression
#line 1012 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4178 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "`(`" "`)`"
#line 1014 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_void() }; }
#line 4184 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1016 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4193 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1022 "annium.y"
        { 
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4205 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1030 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4211 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: "`[[`" expression-list "`]]`"
#line 1032 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } }; }
#line 4217 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1034 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4223 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: PROBE braced-statements
#line 1036 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4229 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`.`" identifier
#line 1038 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4235 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1045 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4245 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: "`-`" syntax-expression
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4251 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: "`!`" syntax-expression
#line 1054 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4257 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`*`" syntax-expression
#line 1056 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4263 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1061 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4269 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1063 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4275 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1067 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4281 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1069 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4287 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1071 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4293 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1074 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4299 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4305 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1081 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4311 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1084 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4317 "annium.tab.cpp"
    break;

  case 213: // grouped-expression: "`(`" pack-expression "`)`"
#line 1104 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4330 "annium.tab.cpp"
    break;

  case 214: // new-expression: "`new`" qname
#line 1117 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4336 "annium.tab.cpp"
    break;

  case 215: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1121 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4342 "annium.tab.cpp"
    break;

  case 216: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1128 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4348 "annium.tab.cpp"
    break;

  case 217: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1130 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4354 "annium.tab.cpp"
    break;

  case 218: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1132 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4360 "annium.tab.cpp"
    break;

  case 219: // syntax-expression: syntax-expression-base
#line 1136 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4366 "annium.tab.cpp"
    break;

  case 220: // syntax-expression: new-expression
#line 1137 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4372 "annium.tab.cpp"
    break;

  case 221: // syntax-expression: compound-expression
#line 1138 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4378 "annium.tab.cpp"
    break;

  case 222: // syntax-expression: lambda-expression
#line 1139 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4384 "annium.tab.cpp"
    break;

  case 223: // syntax-expression: grouped-expression
#line 1140 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4390 "annium.tab.cpp"
    break;

  case 224: // lambda-start-decl: fn-prefix-decl
#line 1146 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4396 "annium.tab.cpp"
    break;

  case 225: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1148 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4402 "annium.tab.cpp"
    break;

  case 226: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1153 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4413 "annium.tab.cpp"
    break;

  case 227: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1160 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4425 "annium.tab.cpp"
    break;

  case 228: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1168 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4437 "annium.tab.cpp"
    break;

  case 229: // pack-expression-opt: %empty
#line 1179 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4443 "annium.tab.cpp"
    break;

  case 230: // pack-expression-opt: pack-expression
#line 1181 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4449 "annium.tab.cpp"
    break;

  case 231: // pack-expression: syntax-expression
#line 1186 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4455 "annium.tab.cpp"
    break;

  case 232: // pack-expression: identifier "`:`" syntax-expression
#line 1188 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4465 "annium.tab.cpp"
    break;

  case 233: // pack-expression: pack-expression "," syntax-expression
#line 1194 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4474 "annium.tab.cpp"
    break;

  case 234: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1199 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4483 "annium.tab.cpp"
    break;

  case 235: // compound-expression: syntax-expression "`...`"
#line 1207 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4489 "annium.tab.cpp"
    break;

  case 236: // compound-expression: call-expression
#line 1208 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4495 "annium.tab.cpp"
    break;

  case 237: // type-expr: qname
#line 1249 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4501 "annium.tab.cpp"
    break;

  case 238: // type-expr: RESERVED_IDENTIFIER
#line 1251 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4507 "annium.tab.cpp"
    break;

  case 239: // type-expr: CONTEXT_IDENTIFIER
#line 1253 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4513 "annium.tab.cpp"
    break;

  case 240: // type-expr: call-expression
#line 1254 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4519 "annium.tab.cpp"
    break;

  case 241: // type-expr: "`[`" type-expr "`]`"
#line 1256 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4525 "annium.tab.cpp"
    break;

  case 242: // type-expr: "`(`" "`)`"
#line 1258 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_void() }; }
#line 4531 "annium.tab.cpp"
    break;

  case 243: // type-expr: grouped-expression
#line 1259 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4537 "annium.tab.cpp"
    break;

  case 244: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1261 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4543 "annium.tab.cpp"
    break;

  case 245: // type-expr: type-expr "`|`" type-expr
#line 1263 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4549 "annium.tab.cpp"
    break;

  case 246: // type-expr: type-expr "`->`" type-expr
#line 1267 "annium.y"
        {
            annium_fn_type fnt{ .result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) };
            if (function_call const* fn_type = get_if<function_call>(&yystack_[2].value.as < syntax_expression > ().value)) {
                fnt.args = fn_type->args;
            } else if (entity_identifier const* peid = get_if<entity_identifier>(&yystack_[2].value.as < syntax_expression > ().value); !peid || *peid != ctx.make_void()) {
                opt_named_expression_list_t args{ opt_named_expression_t{ std::move(yystack_[2].value.as < syntax_expression > ()) } };
                fnt.args = ctx.make_array<opt_named_expression_t>(args);
            } // else void args
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, std::move(fnt) }; 
        }
#line 4564 "annium.tab.cpp"
    break;


#line 4568 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -274;

  const short parser::yytable_ninf_ = -180;

  const short
  parser::yypact_[] =
  {
     760,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
      28,   866,   887,  1010,    28,  1010,  1010,  1010,     8,    13,
      27,  1010,    24,  1010,    27,    90,  -274,  -274,  -274,    14,
      27,    27,  -274,  -274,  -274,    50,   107,    19,   442,  -274,
    -274,  -274,  -274,    67,  -274,   318,     2,   218,  -274,    86,
    -274,   304,   552,   118,  -274,    97,  -274,  1010,  -274,   128,
     130,   978,   151,  -274,   654,   159,   -25,   978,   -23,  -274,
      34,    34,    34,    28,  -274,   171,   224,  -274,    28,    14,
       4,   619,  -274,    67,   162,   427,   131,  -274,  -274,  -274,
      67,   228,  -274,   182,  -274,   354,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,    28,  -274,  -274,  1010,   166,
       3,  1010,    28,  1010,  1010,    28,  -274,  1010,  1010,  1010,
    1010,  1010,  1010,  -274,  1010,  1010,  1010,  1010,  1010,   460,
     658,  1010,  -274,  1010,  -274,  -274,  1010,  1010,   222,   548,
    -274,   235,  -274,  -274,  -274,  -274,  1010,  -274,  -274,   282,
    1010,   247,  -274,  1010,  1010,  -274,  1010,   221,  1010,   460,
     460,    28,   263,   460,  -274,   278,   262,   282,   458,  1010,
    -274,   287,  -274,   316,   174,  -274,   978,   153,   153,  1101,
    1064,   158,   725,    34,    34,   559,   339,  -274,   346,   346,
     190,   467,   528,  -274,  -274,    22,   239,    12,   334,   336,
    -274,   740,   346,   346,  -274,   978,   365,   978,   978,   978,
    -274,  -274,  -274,  -274,  -274,   978,   309,   333,   993,   282,
     312,   218,    86,   304,    26,   262,   282,    35,   382,   359,
    -274,  1010,   978,   427,   427,    50,   978,   383,   385,  -274,
     331,   367,  -274,    28,   386,  -274,    26,    27,   -12,  1010,
     421,   216,  -274,  -274,   421,   978,  -274,  -274,  -274,  -274,
    1010,  -274,  -274,  -274,   797,   346,   346,  -274,   528,   528,
     528,  -274,   405,  -274,  -274,   125,   346,    45,   346,   421,
    -274,   294,   460,  -274,   288,  -274,  -274,  1010,  -274,   272,
     282,  1010,   282,    26,  -274,  -274,  -274,  1010,   978,  -274,
    -274,  -274,   420,   342,  -274,    28,   194,   397,   393,  -274,
     434,    67,   349,   421,  -274,   764,  -274,   421,  -274,   978,
    -274,   327,  -274,  -274,  -274,  -274,  -274,  -274,    45,   426,
    -274,   421,   346,   346,   219,  -274,   282,  1010,   458,  -274,
    -274,  -274,  -274,   978,  -274,   109,   856,   109,  -274,  1010,
    1010,  -274,  -274,  1010,   282,  -274,    28,   432,   528,   380,
     474,   380,   244,   181,  -274,  -274,   447,  -274,   -12,  -274,
    -274,   421,   346,   346,   219,   190,   219,  -274,  -274,  -274,
     232,   978,    66,  -274,   978,   978,   978,   191,  -274,    28,
    -274,  -274,   380,  -274,   528,   448,  -274,   349,  -274,   421,
    -274,   219,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    1010,  -274,   449,  -274,  -274,  -274,  -274,  -274,  -274,   978,
    -274
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   189,    53,   178,   177,   188,   185,   186,   187,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    62,     0,
       0,     0,   182,   183,   184,     0,     0,     0,     0,     5,
       7,    14,    56,   179,    60,     0,   224,   191,   219,   223,
     220,   236,     0,     0,   222,   221,    55,     0,   192,    56,
     224,   231,     0,   221,    22,     0,     0,    82,     0,   199,
     201,   203,   202,     0,    41,    20,    16,    18,     0,     0,
     214,     0,   175,   176,     0,     0,     0,    44,    13,    65,
      64,     0,    42,     0,    38,     0,    15,   198,     1,     2,
      10,     3,     8,     6,     9,     0,    63,    61,   229,    69,
       0,   229,     0,   229,     0,     0,   200,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,   100,
       0,     0,   213,     0,    49,    48,    50,     0,    39,    40,
      25,     0,    47,    23,   195,   194,     0,   196,    19,     0,
       0,     0,    12,    84,     0,    32,     0,    35,     0,   100,
     100,    73,     0,   100,    57,     0,   230,     0,     0,     0,
      37,     0,   180,     0,     0,   181,    46,   206,   207,   211,
     212,   208,     0,   204,   205,   209,   210,    54,   106,   106,
     133,     0,   158,   127,   128,    56,   171,   106,     0,   101,
     102,   131,   106,   106,   193,   232,    56,   233,    51,    52,
      28,    26,    27,    24,    31,    83,   239,   238,     0,     0,
     237,     0,   243,   240,    21,    17,     0,    56,     0,    85,
      86,     0,    89,     0,     0,     0,    80,     0,     0,    77,
       0,    74,    75,    92,     0,   225,    70,     0,   171,     0,
     171,   162,    71,   173,   169,    43,   216,   218,   217,   197,
       0,   118,   120,   134,   137,   106,   106,   161,   156,     0,
       0,   152,   159,   157,   105,     0,   106,   133,   106,   172,
     125,     0,     0,   132,   129,   126,   116,     0,   242,     0,
       0,     0,     0,    11,    90,    91,   215,     0,    88,    33,
      34,    36,     0,    67,    72,     0,     0,     0,    93,    94,
       0,   170,   171,   171,   165,     0,   164,   171,   174,   107,
     138,   135,   124,   115,   155,   153,   154,   160,   133,     0,
     119,   134,   106,   106,   106,   117,     0,     0,     0,   226,
      29,   103,   130,   234,   241,   246,     0,   245,    87,     0,
       0,    66,    76,     0,     0,    78,     0,     0,     0,   171,
       0,   171,   171,     0,   150,   140,   142,   166,   171,   163,
     136,   134,   106,   106,   106,   133,   106,   123,   112,   113,
       0,    30,     0,   244,    81,    68,    99,    96,    95,    92,
     146,   151,   171,   148,     0,   144,   139,   171,   143,   171,
     167,   106,   121,   108,   109,   122,   111,   114,   227,   228,
       0,    98,     0,   149,   147,   145,   141,   168,   110,    97,
      79
  };

  const short
  parser::yypgoto_[] =
  {
    -274,  -274,  -274,  -274,   453,  -274,  -274,  -274,  -274,  -274,
      43,    -9,   -27,  -274,   -46,   358,    30,   -90,    36,   454,
    -274,    25,  -274,   481,  -274,   433,  -274,  -274,  -274,   206,
    -274,  -274,   500,  -274,  -274,   225,  -274,   135,  -274,  -274,
     169,   249,  -274,  -274,    44,   245,  -181,  -274,  -274,  -273,
    -245,  -274,  -191,   129,  -168,  -185,  -166,  -244,    71,   -93,
    -274,    49,  -274,    53,  -274,   132,     0,  -274,  -274,   315,
     -10,    42,   179
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    36,    37,    38,    39,    74,    75,    76,   138,   139,
     339,   340,    40,   141,    41,   143,    42,   250,    43,    44,
      45,    60,    91,   109,   351,   110,    94,   240,   241,   242,
      96,    87,    66,   228,   229,   230,   231,   307,   308,   411,
     309,   198,   199,   275,   261,   200,   201,   202,   264,   265,
     313,   363,   364,   365,   203,   271,   272,   253,   366,   279,
      84,    47,    48,    49,    50,    51,    61,    53,    54,   165,
     166,    63,   224
  };

  const short
  parser::yytable_[] =
  {
      52,    62,   252,    65,   332,   247,   317,   273,     2,   263,
     318,   104,    67,    67,     2,    70,    71,    72,   142,    99,
       2,    81,   266,    85,   169,    46,    97,   260,   145,   187,
       2,    82,   147,     2,     2,   318,   312,   140,    52,   196,
      56,    59,    55,   116,    69,   146,   290,   146,    77,    10,
     294,   105,   153,    64,   108,   372,    80,   130,    83,   105,
      86,    10,   247,    46,    52,    90,    93,    95,  -104,   196,
     196,    10,   155,   196,    10,   254,   157,   100,   291,    89,
      55,   295,    90,   324,   325,   326,   124,   337,    78,    46,
     318,    89,   292,   142,  -104,    88,   331,   -45,   254,   254,
      64,   170,   405,   148,   174,   274,    55,    98,   151,   333,
      79,    73,   212,   191,   105,    90,    64,   176,   177,   178,
     179,   180,   181,   399,   182,   183,   184,   185,   186,   290,
     318,   205,   318,   207,   113,   164,   208,   209,    59,    52,
     225,    59,   172,    59,    59,   175,   215,   371,   -45,   192,
     193,   194,   158,   232,   233,   -45,   234,   318,   236,   195,
     373,   291,   116,   206,    46,   197,   129,   116,   391,   255,
     393,   328,   382,   390,   131,   254,   254,   254,   105,   159,
      59,    55,   108,   227,   334,   220,   167,   122,   168,   195,
     195,   239,   196,   195,   263,   197,   197,   329,   221,   197,
     132,   413,   222,   220,   251,   124,   410,   406,    62,   414,
     124,   290,   144,   125,   126,   353,   221,   149,   125,   126,
     222,   133,   362,   258,   299,   300,   301,   251,   251,   105,
     396,   298,   161,   262,   260,   374,   247,   220,   376,   150,
     354,   280,   156,   291,   133,   254,   285,   286,    59,   315,
     221,   397,   290,   337,   222,   220,   247,   292,   191,   394,
     319,   247,   220,   105,   312,   254,   111,   278,   221,   362,
     392,   362,   222,   306,   276,   221,   160,   112,   401,   222,
     210,   223,    64,   311,   291,   277,   214,   343,     2,   216,
     217,   346,   290,   226,   192,   193,   194,   232,   292,   223,
     220,   254,   362,   235,   251,   251,   251,   362,   290,   322,
     323,   243,   195,   221,   336,   337,   338,   222,   197,   314,
     330,   316,   335,   342,   291,   344,   220,   227,   220,    10,
     218,   245,   133,   223,   219,   239,   256,   381,   292,   221,
     291,   221,   361,   222,    64,   222,   246,   290,   116,   384,
     385,   223,   114,   386,   292,     2,   187,  -178,   223,   105,
    -179,   260,   370,   115,   358,   257,   247,   359,  -178,   118,
     119,  -179,   220,   122,   251,   162,   377,   378,   379,   291,
     284,  -177,   304,   281,   367,   221,   306,   187,   369,   222,
     220,   124,  -177,   292,   251,   358,   223,   247,   289,   125,
     126,   105,   163,   221,   127,   293,   282,   222,   237,   238,
     419,   287,   244,    26,    27,   106,   402,   403,   404,   306,
     407,   360,   223,   408,   223,   409,   171,   361,   173,   297,
     251,   296,   302,   395,   303,   310,   116,   305,   247,   400,
     327,   349,   101,   321,   350,   418,   355,     1,     2,     3,
       4,     5,     6,     7,     8,   357,     9,   118,   119,   120,
     121,   122,   123,   356,     2,   187,     2,   187,   223,   345,
     417,   347,   375,     2,   187,   247,   248,    64,   188,   124,
     389,   187,   398,   415,   247,   248,   223,   125,   126,    10,
      11,   103,   127,   128,    12,   189,    13,   213,   420,   107,
     102,    14,   267,    15,    16,    10,   190,    10,   249,    17,
      92,   352,   152,    68,    10,   380,    18,   249,    19,    20,
      21,    22,   348,    23,   412,   388,   416,   341,   191,     0,
      24,     0,     0,   387,     2,   187,    25,    26,    27,    28,
      29,    30,    31,     0,     0,   247,   248,     0,     0,    32,
      33,    34,    35,     1,     2,     3,     4,     5,     6,     7,
       8,   116,     9,   267,   192,   193,   194,   117,   116,     0,
       0,   268,   269,   270,     0,    10,     0,     0,   249,     0,
       0,     0,   118,   119,   120,   121,   122,   123,     0,   118,
     119,     0,     0,   122,     0,    10,    11,     0,     0,     0,
      12,     0,    13,     0,   124,     0,   211,    14,     0,    15,
      16,   124,   125,   126,     0,    17,     0,   127,   128,   125,
     126,     0,    18,     0,     0,    20,    21,    22,   116,    23,
       0,   134,   135,   136,   137,     0,    24,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,     0,   118,
     119,   120,   121,   122,   123,    32,    33,    34,    35,     1,
       2,     3,     4,     5,     6,     7,     8,   116,     9,    64,
       0,   124,     0,     0,     0,     0,     0,   154,     0,   125,
     126,     0,     0,     0,   127,   128,     0,     0,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,    12,   204,    13,     0,
     124,     0,     0,    14,     0,    15,    16,     0,   125,   126,
       0,    17,     0,   127,   128,     0,     0,     0,    18,     0,
       0,    20,    21,    22,   116,    23,     0,   134,   135,   136,
     137,     0,    24,     0,     0,     0,     2,   216,   217,    26,
      27,    28,    29,    30,     0,   118,   119,   120,   121,   122,
     123,    32,    33,    34,    35,     1,     2,     3,     4,     5,
       6,     7,     8,   116,     9,   283,     0,   124,   259,     0,
       0,     0,     0,     0,     0,   125,   126,    10,   218,     0,
     127,   128,   219,     0,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     2,   216,   217,     0,    10,    11,     0,
       0,     0,    12,     0,    13,   368,   124,     0,     0,    14,
       0,    15,    16,     0,   125,   126,     0,    17,     0,   127,
     128,     0,   320,     0,    18,     0,    19,    20,    21,    22,
       0,    23,     0,     0,    10,   218,     0,     0,    24,   219,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,     0,   116,     0,    32,    33,    34,
      35,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,   118,   119,   120,   121,
     122,   123,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,     0,   124,   383,
       0,     0,    57,    10,    11,    58,   125,   126,    12,     0,
      13,   127,   128,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,    17,    10,    11,     0,    64,     0,    12,
       0,    13,     0,    20,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    20,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,     0,     0,     0,
       0,     0,    26,    27,    28,     0,     0,   116,     0,     0,
       0,     0,     0,     0,    32,    33,    34,    35,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,   118,   119,
     120,   121,   122,   123,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   125,   126,
      10,    11,   288,   127,   128,    12,     0,    13,     0,     0,
       0,     0,    14,     0,    15,    16,     0,    10,    11,     0,
      17,     0,    12,     0,    13,     0,     0,     0,     0,    14,
      20,    15,    16,   116,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    26,    27,
      28,     0,     0,     0,   118,   119,   120,     0,   122,     0,
      32,    33,    34,    35,     0,    26,    27,    28,     0,     0,
     116,     0,     0,     0,     0,     0,   124,    32,    33,    34,
      35,     0,     0,     0,   125,   126,     0,     0,     0,   127,
     128,   118,   119,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,   125,   126,     0,     0,     0,   127,   128
  };

  const short
  parser::yycheck_[] =
  {
       0,    11,   168,    12,   277,    17,   251,   192,     6,   190,
     254,    38,    12,    13,     6,    15,    16,    17,    64,     0,
       6,    21,   190,    23,    21,     0,    35,    15,    53,     7,
       6,     7,    55,     6,     6,   279,    48,    64,    38,   129,
      10,    11,     0,     9,    14,    70,    20,    70,    18,    47,
      15,    47,    48,    50,    52,   328,    20,    57,    22,    47,
      24,    47,    17,    38,    64,    29,    30,    31,    46,   159,
     160,    47,    81,   163,    47,   168,    85,    58,    52,    77,
      38,    46,    46,   268,   269,   270,    52,    21,    75,    64,
     334,    77,    66,   139,    72,     5,   277,     0,   191,   192,
      50,   110,   375,    73,   114,   195,    64,     0,    78,   277,
      97,   103,   139,    68,    47,    79,    50,   117,   118,   119,
     120,   121,   122,   368,   124,   125,   126,   127,   128,    20,
     374,   131,   376,   133,    48,   105,   136,   137,   108,   139,
     150,   111,   112,   113,   114,   115,   146,   328,    51,   104,
     105,   106,    21,   153,   154,    58,   156,   401,   158,   129,
     328,    52,     9,   133,   139,   129,    48,     9,   359,   169,
     361,    46,   338,   358,    46,   268,   269,   270,    47,    48,
     150,   139,    52,   153,   277,   149,    20,    34,    22,   159,
     160,   161,   282,   163,   375,   159,   160,    72,   149,   163,
      49,   392,   149,   167,   168,    52,    15,   375,   218,   394,
      52,    20,    53,    60,    61,    21,   167,    46,    60,    61,
     167,    70,   312,    49,   233,   234,   235,   191,   192,    47,
      49,   231,    50,   189,    15,   328,    17,   201,   331,    15,
      46,   197,    80,    52,    70,   338,   202,   203,   218,   249,
     201,    70,    20,    21,   201,   219,    17,    66,    68,    15,
     260,    17,   226,    47,    48,   358,    48,   196,   219,   359,
     360,   361,   219,   243,    35,   226,    48,    59,   371,   226,
      58,   149,    50,   247,    52,    46,    51,   287,     6,     7,
       8,   291,    20,    46,   104,   105,   106,   297,    66,   167,
     264,   394,   392,    82,   268,   269,   270,   397,    20,   265,
     266,    48,   282,   264,    20,    21,    22,   264,   282,   248,
     276,   250,   278,    35,    52,    53,   290,   297,   292,    47,
      48,    53,    70,   201,    52,   305,    49,   337,    66,   290,
      52,   292,   312,   290,    50,   292,   167,    20,     9,   349,
     350,   219,    48,   353,    66,     6,     7,    48,   226,    47,
      48,    15,    35,    59,    15,    49,    17,    18,    59,    30,
      31,    59,   336,    34,   338,    21,   332,   333,   334,    52,
     201,    48,    51,    49,   313,   336,   356,     7,   317,   336,
     354,    52,    59,    66,   358,    15,   264,    17,   219,    60,
      61,    47,    48,   354,    65,   226,    70,   354,   159,   160,
     410,    46,   163,    95,    96,    97,   372,   373,   374,   389,
     376,    72,   290,   380,   292,   382,   111,   397,   113,    70,
     394,    49,    49,   362,    49,    49,     9,    70,    17,   368,
      35,    21,     0,   264,   102,   401,    49,     5,     6,     7,
       8,     9,    10,    11,    12,    21,    14,    30,    31,    32,
      33,    34,    35,    70,     6,     7,     6,     7,   336,   290,
     399,   292,    46,     6,     7,    17,    18,    50,    18,    52,
      48,     7,    35,    35,    17,    18,   354,    60,    61,    47,
      48,    38,    65,    66,    52,    35,    54,   139,    49,    45,
      58,    59,    35,    61,    62,    47,    46,    47,    50,    67,
      29,   305,    79,    13,    47,   336,    74,    50,    76,    77,
      78,    79,   297,    81,   389,   356,   397,   282,    68,    -1,
      88,    -1,    -1,   354,     6,     7,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    17,    18,    -1,    -1,   107,
     108,   109,   110,     5,     6,     7,     8,     9,    10,    11,
      12,     9,    14,    35,   104,   105,   106,    15,     9,    -1,
      -1,   104,   105,   106,    -1,    47,    -1,    -1,    50,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    -1,    30,
      31,    -1,    -1,    34,    -1,    47,    48,    -1,    -1,    -1,
      52,    -1,    54,    -1,    52,    -1,    58,    59,    -1,    61,
      62,    52,    60,    61,    -1,    67,    -1,    65,    66,    60,
      61,    -1,    74,    -1,    -1,    77,    78,    79,     9,    81,
      -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,    -1,    30,
      31,    32,    33,    34,    35,   107,   108,   109,   110,     5,
       6,     7,     8,     9,    10,    11,    12,     9,    14,    50,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    -1,    -1,    -1,    65,    66,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    52,    49,    54,    -1,
      52,    -1,    -1,    59,    -1,    61,    62,    -1,    60,    61,
      -1,    67,    -1,    65,    66,    -1,    -1,    -1,    74,    -1,
      -1,    77,    78,    79,     9,    81,    -1,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,     6,     7,     8,    95,
      96,    97,    98,    99,    -1,    30,    31,    32,    33,    34,
      35,   107,   108,   109,   110,     5,     6,     7,     8,     9,
      10,    11,    12,     9,    14,    35,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    47,    48,    -1,
      65,    66,    52,    -1,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,     6,     7,     8,    -1,    47,    48,    -1,
      -1,    -1,    52,    -1,    54,    51,    52,    -1,    -1,    59,
      -1,    61,    62,    -1,    60,    61,    -1,    67,    -1,    65,
      66,    -1,    35,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    47,    48,    -1,    -1,    88,    52,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,     9,    -1,   107,   108,   109,
     110,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    46,    47,    48,    49,    60,    61,    52,    -1,
      54,    65,    66,    -1,    -1,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    47,    48,    -1,    50,    -1,    52,
      -1,    54,    -1,    77,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    30,    31,
      32,    33,    34,    35,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      47,    48,    49,    65,    66,    52,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    61,    62,    -1,    47,    48,    -1,
      67,    -1,    52,    -1,    54,    -1,    -1,    -1,    -1,    59,
      77,    61,    62,     9,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    95,    96,
      97,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
     107,   108,   109,   110,    -1,    95,    96,    97,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    52,   107,   108,   109,
     110,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,
      66,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      47,    48,    52,    54,    59,    61,    62,    67,    74,    76,
      77,    78,    79,    81,    88,    94,    95,    96,    97,    98,
      99,   100,   107,   108,   109,   110,   112,   113,   114,   115,
     123,   125,   127,   129,   130,   131,   132,   172,   173,   174,
     175,   176,   177,   178,   179,   182,   127,    46,    49,   127,
     132,   177,   181,   182,    50,   122,   143,   177,   143,   127,
     177,   177,   177,   103,   116,   117,   118,   127,    75,    97,
     129,   177,     7,   129,   171,   177,   129,   142,     5,    77,
     129,   133,   134,   129,   137,   129,   141,   122,     0,     0,
      58,     0,    58,   115,   123,    47,    97,   130,    52,   134,
     136,    48,    59,    48,    48,    59,     9,    15,    30,    31,
      32,    33,    34,    35,    52,    60,    61,    65,    66,    48,
     177,    46,    49,    70,    83,    84,    85,    86,   119,   120,
     123,   124,   125,   126,    53,    53,    70,    55,   127,    46,
      15,   127,   136,    48,    58,   122,    80,   122,    21,    48,
      48,    50,    21,    48,   127,   180,   181,    20,    22,    21,
     122,   180,   127,   180,   181,   127,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,     7,    18,    35,
      46,    68,   104,   105,   106,   127,   128,   129,   152,   153,
     156,   157,   158,   165,    49,   177,   127,   177,   177,   177,
      58,    58,   123,   126,    51,   177,     7,     8,    48,    52,
     129,   172,   174,   176,   183,   181,    46,   127,   144,   145,
     146,   147,   177,   177,   177,    82,   177,   152,   152,   127,
     138,   139,   140,    48,   152,    53,   183,    17,    18,    50,
     128,   129,   167,   168,   170,   177,    49,    49,    49,    53,
      15,   155,   155,   157,   159,   160,   165,    35,   104,   105,
     106,   166,   167,   166,   128,   154,    35,    46,   169,   170,
     155,    49,    70,    35,   183,   155,   155,    46,    49,   183,
      20,    52,    66,   183,    15,    46,    49,    70,   177,   122,
     122,   122,    49,    49,    51,    70,   127,   148,   149,   151,
      49,   129,    48,   161,   169,   177,   169,   161,   168,   177,
      35,   183,   155,   155,   166,   166,   166,    35,    46,    72,
     155,   157,   160,   165,   170,   155,    20,    21,    22,   121,
     122,   156,    35,   177,    53,   183,   177,   183,   146,    21,
     102,   135,   140,    21,    46,    49,    70,    21,    15,    18,
      72,   127,   128,   162,   163,   164,   169,   169,    51,   169,
      35,   157,   160,   165,   170,    46,   170,   155,   155,   155,
     183,   177,   167,    53,   177,   177,   177,   183,   151,    48,
     166,   163,   128,   163,    15,   169,    49,    70,    35,   161,
     169,   170,   155,   155,   155,   160,   165,   155,   121,   121,
      15,   150,   148,   163,   166,    35,   164,   169,   155,   177,
      49
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
     156,   156,   156,   156,   156,   156,   156,   157,   157,   158,
     158,   158,   158,   159,   159,   160,   160,   160,   160,   161,
     162,   162,   163,   163,   163,   163,   163,   163,   164,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   172,
     172,   172,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   175,   175,   176,   176,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   179,   180,
     180,   181,   181,   181,   181,   182,   182,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       2,     5,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     3,     0,     1,     2,     1,     2,     2,     2,     1,
       2,     3,     3,     5,     5,     3,     5,     3,     2,     1,
       1,     2,     2,     4,     2,     1,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     5,     0,     2,     1,
       3,     3,     4,     0,     1,     1,     3,     1,     5,     8,
       3,     6,     1,     3,     0,     1,     1,     3,     2,     1,
       2,     2,     0,     1,     1,     3,     0,     2,     4,     3,
       0,     1,     1,     3,     0,     1,     0,     2,     5,     5,
       6,     5,     4,     4,     5,     3,     2,     3,     2,     3,
       2,     5,     5,     4,     3,     2,     2,     1,     1,     2,
       3,     1,     2,     0,     1,     2,     3,     1,     2,     3,
       1,     3,     1,     2,     2,     3,     2,     3,     2,     3,
       1,     2,     2,     3,     3,     3,     2,     2,     1,     1,
       2,     1,     1,     3,     2,     2,     3,     4,     5,     1,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     3,     3,     4,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     4,     4,     4,     1,
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
  "\"`>>`\"", "\"`<=`\"", "\"`>=`\"", "\"`==`\"", "\"`!=`\"", "\"`&&`\"",
  "\"`||`\"", "\"`..`\"", "\"`...`\"", "\"`+=`\"", "\"`-=`\"", "\"`*=`\"",
  "\"`/=`\"", "\"`%=`\"", "\"`<<=`\"", "\"`>>=`\"", "\"`&=`\"", "\"`|=`\"",
  "\"`^=`\"", "\"`:`\"", "\"`::`\"", "\"`(`\"", "\"`)`\"", "\"`{`\"",
  "\"`}`\"", "\"`[`\"", "\"`]`\"", "\"`[[`\"", "\"`]]`\"", "\"`<`\"",
  "\"`>`\"", "\"`;`\"", "\"`.`\"", "\"`+`\"", "\"`-`\"", "\"`*`\"",
  "\"`/`\"", "\"`%`\"", "\"`&`\"", "\"`|`\"", "\"`!`\"", "\"`~`\"",
  "\"`^`\"", "\",\"", "\"`$`\"", "\"`?`\"", "\"`#`\"", "LET", "VAR",
  "EXTERN", "\"`new`\"", "\"`while`\"", "\"`for`\"", "\"`in`\"",
  "\"`if`\"", "\"`else`\"", "\"`continue`\"", "\"`break`\"",
  "\"`return`\"", "\"`yield`\"", "AUTO", "USING", "THROW", "SIZEOF",
  "LOWEST", "DEREF", "PREFIXMINUS", "INCLUDE", "INLINE", "VIABLE",
  "\"`fn`\"", "\"`typefn`\"", "ENUM", "STRUCT", "EXTENDS", "REQUIRES",
  "\"weak modifier\"", "\"typename modifier\"", "\"constexpr modifier\"",
  "\"runctime modifier\"", "\"nil\"", "\"true\"", "\"false\"", "PROBE",
  "$accept", "begin", "statement_any", "finished-statement-any",
  "statement", "let-decl", "let-decl-start",
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
       0,   339,   339,   340,   344,   346,   348,   365,   367,   368,
     370,   375,   377,   379,   381,   383,   388,   389,   394,   396,
     401,   402,   407,   409,   411,   416,   418,   419,   421,   427,
     430,   441,   446,   448,   450,   452,   454,   456,   466,   471,
     472,   476,   478,   480,   487,   489,   491,   499,   500,   502,
     504,   506,   508,   513,   521,   536,   538,   540,   546,   547,
     551,   552,   556,   558,   563,   565,   570,   588,   589,   601,
     602,   604,   611,   616,   617,   621,   623,   628,   634,   636,
     659,   665,   682,   684,   690,   691,   695,   697,   702,   704,
     709,   711,   717,   718,   722,   724,   729,   730,   734,   736,
     743,   744,   748,   750,   755,   756,   760,   761,   765,   767,
     769,   771,   773,   775,   777,   779,   781,   789,   791,   793,
     795,   800,   802,   804,   806,   808,   813,   818,   819,   823,
     825,   829,   831,   836,   841,   845,   847,   851,   853,   863,
     868,   870,   876,   878,   881,   883,   887,   890,   896,   899,
     912,   915,   920,   921,   922,   923,   924,   925,   926,   930,
     931,   932,   936,   938,   940,   942,   944,   946,   948,   950,
     955,   960,   962,   966,   968,   974,   976,   981,   983,   985,
     987,   989,   994,   996,   998,  1000,  1002,  1004,  1006,  1008,
    1010,  1012,  1013,  1015,  1021,  1029,  1031,  1033,  1035,  1037,
    1044,  1051,  1053,  1055,  1060,  1062,  1066,  1068,  1070,  1073,
    1077,  1080,  1083,  1103,  1116,  1120,  1127,  1129,  1131,  1136,
    1137,  1138,  1139,  1140,  1145,  1147,  1152,  1159,  1167,  1178,
    1180,  1185,  1187,  1193,  1198,  1206,  1208,  1248,  1250,  1252,
    1254,  1255,  1257,  1259,  1260,  1262,  1266
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
#line 5571 "annium.tab.cpp"

#line 1600 "annium.y"

