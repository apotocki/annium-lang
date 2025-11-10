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
#line 330 "annium.y"
                 { }
#line 1843 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1849 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1855 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1861 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 330 "annium.y"
                 { }
#line 1867 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 330 "annium.y"
                 { }
#line 1873 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 330 "annium.y"
                 { }
#line 1879 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 330 "annium.y"
                 { }
#line 1885 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 330 "annium.y"
                 { }
#line 1891 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 330 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 330 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 330 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 330 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 330 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 330 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 330 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 330 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 330 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 330 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 330 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 330 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 330 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 330 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 330 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 330 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 330 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 330 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 330 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 330 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 330 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 330 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 330 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 330 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 330 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 330 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 330 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 330 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 330 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 330 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 330 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 330 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 330 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 330 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 330 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 330 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_114_finished_statement_any: // finished-statement-any
#line 330 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 330 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_116_let_decl: // let-decl
#line 330 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl_start: // let-decl-start
#line 330 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 330 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_infunction_statement_any: // infunction-statement-any
#line 330 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_finished_infunction_statement_any: // finished-infunction-statement-any
#line 330 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_function_body: // function-body
#line 330 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_braced_statements: // braced-statements
#line 330 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_finished_statement: // finished-statement
#line 330 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_infunction_statement_set: // infunction-statement-set
#line 330 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_generic_statement: // generic-statement
#line 330 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_infunction_statement: // infunction-statement
#line 330 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 330 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_128_internal_identifier: // internal-identifier
#line 330 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 330 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_130_fn_kind: // fn-kind
#line 330 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_fn_kind_set: // fn-kind-set
#line 330 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_fn_prefix_decl: // fn-prefix-decl
#line 330 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_name: // fn-name
#line 330 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_start_decl: // fn-start-decl
#line 330 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_requirement_opt: // fn-requirement-opt
#line 330 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_decl: // fn-decl
#line 330 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_enum_decl: // enum-decl
#line 330 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_case_list_opt: // case-list-opt
#line 330 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_case_list: // case-list
#line 330 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_case_decl: // case-decl
#line 330 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_struct_decl: // struct-decl
#line 330 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_using_decl: // using-decl
#line 330 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_expression_list: // expression-list
#line 330 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_argument_list_opt: // argument-list-opt
#line 330 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_argument_list: // argument-list
#line 330 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 330 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_147_argument_name: // argument-name
#line 330 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_field_list_opt: // field-list-opt
#line 330 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_field_list: // field-list
#line 330 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_field_default_value_opt: // field-default-value-opt
#line 330 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 330 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_152_parameter_list_opt: // parameter-list-opt
#line 330 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_parameter_list: // parameter-list
#line 330 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_internal_identifier_opt: // internal-identifier-opt
#line 330 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_parameter_default_value_opt: // parameter-default-value-opt
#line 330 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_decl: // parameter-decl
#line 330 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 330 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_constraint_expression_specified: // constraint-expression-specified
#line 330 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_constraint_expression_mod: // constraint-expression-mod
#line 330 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_constraint_expression: // constraint-expression
#line 330 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 330 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_162_pattern_list: // pattern-list
#line 330 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_pattern_field_sfx: // pattern-field-sfx
#line 330 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_pattern_field: // pattern-field
#line 330 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_pattern_mod: // pattern-mod
#line 330 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_sfx: // pattern-sfx
#line 330 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 330 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_168_concept_expression: // concept-expression
#line 330 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_concept_expression_list_opt: // concept-expression-list-opt
#line 330 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_concept_expression_list: // concept-expression-list
#line 330 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_reference_expression: // reference-expression
#line 330 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_any_reference_expression: // any-reference-expression
#line 330 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_syntax_expression_base: // syntax-expression-base
#line 330 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_grouped_expression: // grouped-expression
#line 330 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_new_expression: // new-expression
#line 330 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_call_expression: // call-expression
#line 330 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_syntax_expression: // syntax-expression
#line 330 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_lambda_start_decl: // lambda-start-decl
#line 330 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_lambda_expression: // lambda-expression
#line 330 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_pack_expression_opt: // pack-expression-opt
#line 330 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_pack_expression: // pack-expression
#line 330 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_compound_expression: // compound-expression
#line 330 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_type_expr: // type-expr
#line 330 "annium.y"
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
#line 335 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3017 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 336 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3023 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 341 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3029 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 343 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3035 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 345 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3041 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 362 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3047 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 363 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3053 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 365 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3059 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 367 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3065 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 372 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3071 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 374 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3077 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 376 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3083 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 378 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3089 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 380 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3095 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 384 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3101 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 386 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3107 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 391 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3113 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 393 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3119 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 397 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3125 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 399 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3131 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 404 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3137 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 406 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3143 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 408 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3149 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 413 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3155 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 414 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3161 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 416 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3167 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 418 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3173 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 423 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3179 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression
#line 427 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3185 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 438 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3191 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 443 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3197 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 445 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), std::move(yystack_[1].value.as < syntax_expression > ()) } }; }
#line 3203 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 447 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3209 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 449 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3215 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 451 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[3].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[2].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3221 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 453 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3231 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 463 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3237 "annium.tab.cpp"
    break;

  case 39: // infunction-statement-set: infunction-statement-any
#line 467 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3243 "annium.tab.cpp"
    break;

  case 40: // infunction-statement-set: finished-infunction-statement-any
#line 468 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3249 "annium.tab.cpp"
    break;

  case 41: // generic-statement: LET let-decl
#line 473 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3255 "annium.tab.cpp"
    break;

  case 42: // generic-statement: "`typefn`" fn-start-decl
#line 475 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3261 "annium.tab.cpp"
    break;

  case 43: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 477 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3272 "annium.tab.cpp"
    break;

  case 44: // generic-statement: USING using-decl
#line 484 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3278 "annium.tab.cpp"
    break;

  case 45: // generic-statement: compound-expression
#line 486 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3284 "annium.tab.cpp"
    break;

  case 46: // generic-statement: syntax-expression "`=`" syntax-expression
#line 488 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3293 "annium.tab.cpp"
    break;

  case 47: // infunction-statement: generic-statement
#line 495 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3299 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: "`break`"
#line 497 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3305 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`continue`"
#line 499 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3311 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`return`"
#line 501 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3317 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`" syntax-expression
#line 503 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3323 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`yield`" syntax-expression
#line 505 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3329 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 510 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3335 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 518 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3341 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 533 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3347 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 535 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3353 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 537 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3359 "annium.tab.cpp"
    break;

  case 58: // fn-kind: INLINE
#line 542 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3365 "annium.tab.cpp"
    break;

  case 59: // fn-kind: VIABLE
#line 543 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3371 "annium.tab.cpp"
    break;

  case 60: // fn-kind-set: fn-kind
#line 547 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3377 "annium.tab.cpp"
    break;

  case 61: // fn-kind-set: fn-kind-set fn-kind
#line 548 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3383 "annium.tab.cpp"
    break;

  case 62: // fn-prefix-decl: "`fn`"
#line 553 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3389 "annium.tab.cpp"
    break;

  case 63: // fn-prefix-decl: fn-kind-set "`fn`"
#line 555 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3395 "annium.tab.cpp"
    break;

  case 64: // fn-name: qname
#line 560 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3401 "annium.tab.cpp"
    break;

  case 65: // fn-name: "`new`"
#line 562 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3407 "annium.tab.cpp"
    break;

  case 66: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 567 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3413 "annium.tab.cpp"
    break;

  case 67: // fn-requirement-opt: %empty
#line 584 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3419 "annium.tab.cpp"
    break;

  case 68: // fn-requirement-opt: REQUIRES syntax-expression
#line 586 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3425 "annium.tab.cpp"
    break;

  case 69: // fn-decl: fn-start-decl
#line 597 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3431 "annium.tab.cpp"
    break;

  case 70: // fn-decl: fn-start-decl "`->`" type-expr
#line 599 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3437 "annium.tab.cpp"
    break;

  case 71: // fn-decl: fn-start-decl "`~>`" pattern
#line 601 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3443 "annium.tab.cpp"
    break;

  case 72: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 608 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3449 "annium.tab.cpp"
    break;

  case 73: // case-list-opt: %empty
#line 612 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3455 "annium.tab.cpp"
    break;

  case 74: // case-list-opt: case-list
#line 613 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3461 "annium.tab.cpp"
    break;

  case 75: // case-list: case-decl
#line 618 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3467 "annium.tab.cpp"
    break;

  case 76: // case-list: case-list "," case-decl
#line 620 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3473 "annium.tab.cpp"
    break;

  case 77: // case-decl: identifier
#line 625 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3479 "annium.tab.cpp"
    break;

  case 78: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 631 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3485 "annium.tab.cpp"
    break;

  case 79: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 633 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3491 "annium.tab.cpp"
    break;

  case 80: // using-decl: qname "`=>`" syntax-expression
#line 656 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3501 "annium.tab.cpp"
    break;

  case 81: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 662 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3512 "annium.tab.cpp"
    break;

  case 82: // expression-list: syntax-expression
#line 679 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3518 "annium.tab.cpp"
    break;

  case 83: // expression-list: expression-list "," syntax-expression
#line 681 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3524 "annium.tab.cpp"
    break;

  case 84: // argument-list-opt: %empty
#line 686 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3530 "annium.tab.cpp"
    break;

  case 85: // argument-list-opt: argument-list
#line 687 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3536 "annium.tab.cpp"
    break;

  case 86: // argument-list: argument
#line 692 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3542 "annium.tab.cpp"
    break;

  case 87: // argument-list: argument-list "," argument
#line 694 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3548 "annium.tab.cpp"
    break;

  case 88: // argument: argument-name syntax-expression
#line 699 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3554 "annium.tab.cpp"
    break;

  case 89: // argument: syntax-expression
#line 701 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3560 "annium.tab.cpp"
    break;

  case 90: // argument-name: identifier "`=`"
#line 706 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3566 "annium.tab.cpp"
    break;

  case 91: // argument-name: identifier "`:`"
#line 708 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3572 "annium.tab.cpp"
    break;

  case 92: // field-list-opt: %empty
#line 713 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3578 "annium.tab.cpp"
    break;

  case 93: // field-list-opt: field-list
#line 714 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3584 "annium.tab.cpp"
    break;

  case 94: // field-list: field
#line 719 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3590 "annium.tab.cpp"
    break;

  case 95: // field-list: field-list "," field
#line 721 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3596 "annium.tab.cpp"
    break;

  case 96: // field-default-value-opt: %empty
#line 725 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3602 "annium.tab.cpp"
    break;

  case 97: // field-default-value-opt: "`=`" syntax-expression
#line 726 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3608 "annium.tab.cpp"
    break;

  case 98: // field: identifier "`:`" type-expr field-default-value-opt
#line 731 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3614 "annium.tab.cpp"
    break;

  case 99: // field: identifier "`=>`" syntax-expression
#line 733 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::any_constexpr_type, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3620 "annium.tab.cpp"
    break;

  case 100: // parameter-list-opt: %empty
#line 739 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3626 "annium.tab.cpp"
    break;

  case 101: // parameter-list-opt: parameter-list
#line 740 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3632 "annium.tab.cpp"
    break;

  case 102: // parameter-list: parameter-decl
#line 745 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3638 "annium.tab.cpp"
    break;

  case 103: // parameter-list: parameter-list "," parameter-decl
#line 747 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3644 "annium.tab.cpp"
    break;

  case 104: // internal-identifier-opt: %empty
#line 751 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3650 "annium.tab.cpp"
    break;

  case 105: // internal-identifier-opt: internal-identifier
#line 752 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3656 "annium.tab.cpp"
    break;

  case 106: // parameter-default-value-opt: %empty
#line 756 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3662 "annium.tab.cpp"
    break;

  case 107: // parameter-default-value-opt: "`=`" syntax-expression
#line 757 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3668 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 762 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3674 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 764 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3680 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 766 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3686 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 768 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3692 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: pattern-mod parameter-default-value-opt
#line 770 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3698 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: identifier internal-identifier-opt concept-expression-list-opt parameter-default-value-opt
#line 774 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annotated_identifier > ()), std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3704 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 778 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3710 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: "`_`" parameter-default-value-opt
#line 780 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3716 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 782 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3722 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: "`...`" parameter-default-value-opt
#line 784 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::const_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
#line 3728 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 789 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3734 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 791 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3740 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 793 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3746 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 795 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3752 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 797 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3758 "annium.tab.cpp"
    break;

  case 123: // constraint-expression-specified-mod: "constexpr modifier"
#line 801 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::any_constexpr_type }; }
#line 3764 "annium.tab.cpp"
    break;

  case 124: // constraint-expression-specified-mod: "runctime modifier"
#line 802 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3770 "annium.tab.cpp"
    break;

  case 125: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 807 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3776 "annium.tab.cpp"
    break;

  case 126: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 809 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3782 "annium.tab.cpp"
    break;

  case 127: // constraint-expression-specified: constraint-expression-specified-mod
#line 813 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3788 "annium.tab.cpp"
    break;

  case 128: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 815 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3794 "annium.tab.cpp"
    break;

  case 129: // constraint-expression-mod: %empty
#line 820 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::const_or_runtime_type };
        }
#line 3803 "annium.tab.cpp"
    break;

  case 130: // constraint-expression-mod: constraint-expression-specified-mod
#line 824 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 3809 "annium.tab.cpp"
    break;

  case 131: // constraint-expression: constraint-expression-mod type-expr
#line 829 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3815 "annium.tab.cpp"
    break;

  case 132: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 831 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3821 "annium.tab.cpp"
    break;

  case 133: // constraint-expression: constraint-expression-mod
#line 835 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3827 "annium.tab.cpp"
    break;

  case 134: // constraint-expression: constraint-expression-mod "`...`"
#line 837 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::ellipsis }; }
#line 3833 "annium.tab.cpp"
    break;

  case 135: // subpatterns: "`(`" pattern-list "`)`"
#line 847 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3839 "annium.tab.cpp"
    break;

  case 136: // pattern-list: pattern-field
#line 852 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 3845 "annium.tab.cpp"
    break;

  case 137: // pattern-list: pattern-list "," pattern-field
#line 854 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 3851 "annium.tab.cpp"
    break;

  case 138: // pattern-field-sfx: concept-expression-list-opt
#line 860 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3857 "annium.tab.cpp"
    break;

  case 139: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 862 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3863 "annium.tab.cpp"
    break;

  case 140: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 865 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3869 "annium.tab.cpp"
    break;

  case 141: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 867 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3875 "annium.tab.cpp"
    break;

  case 142: // pattern-field-sfx: "`=`" pattern-sfx
#line 871 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3881 "annium.tab.cpp"
    break;

  case 143: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 874 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3887 "annium.tab.cpp"
    break;

  case 144: // pattern-field: identifier pattern-field-sfx
#line 880 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3893 "annium.tab.cpp"
    break;

  case 145: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 883 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3899 "annium.tab.cpp"
    break;

  case 146: // pattern-field: pattern-field-sfx
#line 896 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 3905 "annium.tab.cpp"
    break;

  case 147: // pattern-field: "`_`" pattern-field-sfx
#line 899 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 3911 "annium.tab.cpp"
    break;

  case 148: // pattern-mod: "`~`" pattern-sfx
#line 903 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::const_or_runtime_type }; }
#line 3917 "annium.tab.cpp"
    break;

  case 149: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 904 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_value_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3923 "annium.tab.cpp"
    break;

  case 150: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 905 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3929 "annium.tab.cpp"
    break;

  case 151: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 906 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3935 "annium.tab.cpp"
    break;

  case 152: // pattern-mod: "`~`" "typename modifier"
#line 907 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3941 "annium.tab.cpp"
    break;

  case 153: // pattern-mod: "typename modifier" pattern-sfx
#line 908 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3947 "annium.tab.cpp"
    break;

  case 154: // pattern-mod: "typename modifier"
#line 909 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_type }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3953 "annium.tab.cpp"
    break;

  case 155: // pattern-sfx: pattern
#line 913 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 3959 "annium.tab.cpp"
    break;

  case 156: // pattern-sfx: pattern "`...`"
#line 914 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3965 "annium.tab.cpp"
    break;

  case 157: // pattern-sfx: "`...`"
#line 915 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3971 "annium.tab.cpp"
    break;

  case 158: // pattern: qname
#line 920 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 3977 "annium.tab.cpp"
    break;

  case 159: // pattern: qname subpatterns concept-expression-list-opt
#line 922 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 3983 "annium.tab.cpp"
    break;

  case 160: // pattern: internal-identifier concept-expression-list-opt
#line 924 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 3989 "annium.tab.cpp"
    break;

  case 161: // pattern: "`_`" concept-expression-list-opt
#line 926 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 3995 "annium.tab.cpp"
    break;

  case 162: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 928 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4001 "annium.tab.cpp"
    break;

  case 163: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 930 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4007 "annium.tab.cpp"
    break;

  case 164: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 932 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4013 "annium.tab.cpp"
    break;

  case 165: // pattern: concept-expression-list
#line 934 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4019 "annium.tab.cpp"
    break;

  case 166: // concept-expression: "`@`" qname
#line 939 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4025 "annium.tab.cpp"
    break;

  case 167: // concept-expression-list-opt: %empty
#line 944 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4031 "annium.tab.cpp"
    break;

  case 168: // concept-expression-list-opt: concept-expression-list
#line 945 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4037 "annium.tab.cpp"
    break;

  case 169: // concept-expression-list: concept-expression
#line 950 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4043 "annium.tab.cpp"
    break;

  case 170: // concept-expression-list: concept-expression-list concept-expression
#line 952 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4049 "annium.tab.cpp"
    break;

  case 171: // reference-expression: CONTEXT_IDENTIFIER
#line 958 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4055 "annium.tab.cpp"
    break;

  case 172: // reference-expression: qname
#line 960 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4061 "annium.tab.cpp"
    break;

  case 173: // any-reference-expression: RESERVED_IDENTIFIER
#line 965 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4067 "annium.tab.cpp"
    break;

  case 174: // any-reference-expression: CONTEXT_IDENTIFIER
#line 967 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4073 "annium.tab.cpp"
    break;

  case 175: // any-reference-expression: qname
#line 969 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4079 "annium.tab.cpp"
    break;

  case 176: // any-reference-expression: any-reference-expression "`.`" identifier
#line 971 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4085 "annium.tab.cpp"
    break;

  case 177: // any-reference-expression: call-expression "`.`" identifier
#line 973 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4091 "annium.tab.cpp"
    break;

  case 178: // syntax-expression-base: "nil"
#line 978 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4097 "annium.tab.cpp"
    break;

  case 179: // syntax-expression-base: "true"
#line 980 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4103 "annium.tab.cpp"
    break;

  case 180: // syntax-expression-base: "false"
#line 982 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4109 "annium.tab.cpp"
    break;

  case 181: // syntax-expression-base: INTEGER
#line 984 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4115 "annium.tab.cpp"
    break;

  case 182: // syntax-expression-base: DECIMAL
#line 986 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4121 "annium.tab.cpp"
    break;

  case 183: // syntax-expression-base: DECIMAL_S
#line 988 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4127 "annium.tab.cpp"
    break;

  case 184: // syntax-expression-base: INTEGER_INDEX
#line 990 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4133 "annium.tab.cpp"
    break;

  case 185: // syntax-expression-base: STRING
#line 992 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4139 "annium.tab.cpp"
    break;

  case 186: // syntax-expression-base: CT_IDENTIFIER
#line 994 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4145 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-base: any-reference-expression
#line 995 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4151 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-base: "`(`" "`)`"
#line 997 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_void() }; }
#line 4157 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 999 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4166 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1005 "annium.y"
        { 
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4178 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1013 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4184 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: "`[[`" expression-list "`]]`"
#line 1015 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } }; }
#line 4190 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1017 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4196 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: PROBE braced-statements
#line 1019 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4202 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: "`.`" identifier
#line 1021 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4208 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1028 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4218 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: "`-`" syntax-expression
#line 1035 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4224 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: "`!`" syntax-expression
#line 1037 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4230 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`*`" syntax-expression
#line 1039 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4236 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1044 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4242 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1046 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4248 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1050 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4254 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1052 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4260 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1054 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4266 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1057 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4272 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1061 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4278 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1064 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4284 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1067 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4290 "annium.tab.cpp"
    break;

  case 209: // grouped-expression: "`(`" pack-expression "`)`"
#line 1072 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4303 "annium.tab.cpp"
    break;

  case 210: // new-expression: "`new`" qname
#line 1084 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4309 "annium.tab.cpp"
    break;

  case 211: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1088 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4315 "annium.tab.cpp"
    break;

  case 212: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1095 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4321 "annium.tab.cpp"
    break;

  case 213: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1097 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4327 "annium.tab.cpp"
    break;

  case 214: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1099 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4333 "annium.tab.cpp"
    break;

  case 215: // syntax-expression: syntax-expression-base
#line 1103 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4339 "annium.tab.cpp"
    break;

  case 216: // syntax-expression: new-expression
#line 1104 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4345 "annium.tab.cpp"
    break;

  case 217: // syntax-expression: compound-expression
#line 1105 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4351 "annium.tab.cpp"
    break;

  case 218: // syntax-expression: lambda-expression
#line 1106 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4357 "annium.tab.cpp"
    break;

  case 219: // syntax-expression: grouped-expression
#line 1107 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4363 "annium.tab.cpp"
    break;

  case 220: // lambda-start-decl: fn-prefix-decl
#line 1112 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4369 "annium.tab.cpp"
    break;

  case 221: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1114 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4375 "annium.tab.cpp"
    break;

  case 222: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1119 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4386 "annium.tab.cpp"
    break;

  case 223: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1126 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4398 "annium.tab.cpp"
    break;

  case 224: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1134 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4410 "annium.tab.cpp"
    break;

  case 225: // pack-expression-opt: %empty
#line 1145 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4416 "annium.tab.cpp"
    break;

  case 226: // pack-expression-opt: pack-expression
#line 1147 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4422 "annium.tab.cpp"
    break;

  case 227: // pack-expression: syntax-expression
#line 1152 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4428 "annium.tab.cpp"
    break;

  case 228: // pack-expression: identifier "`:`" syntax-expression
#line 1154 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4438 "annium.tab.cpp"
    break;

  case 229: // pack-expression: pack-expression "," syntax-expression
#line 1160 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4447 "annium.tab.cpp"
    break;

  case 230: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1165 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4456 "annium.tab.cpp"
    break;

  case 231: // compound-expression: syntax-expression "`...`"
#line 1173 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4462 "annium.tab.cpp"
    break;

  case 232: // compound-expression: call-expression
#line 1174 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4468 "annium.tab.cpp"
    break;

  case 233: // type-expr: qname
#line 1215 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4474 "annium.tab.cpp"
    break;

  case 234: // type-expr: RESERVED_IDENTIFIER
#line 1217 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4480 "annium.tab.cpp"
    break;

  case 235: // type-expr: CONTEXT_IDENTIFIER
#line 1219 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4486 "annium.tab.cpp"
    break;

  case 236: // type-expr: call-expression
#line 1220 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4492 "annium.tab.cpp"
    break;

  case 237: // type-expr: "`[`" type-expr "`]`"
#line 1224 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4498 "annium.tab.cpp"
    break;

  case 238: // type-expr: "`(`" "`)`"
#line 1226 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_void() }; }
#line 4504 "annium.tab.cpp"
    break;

  case 239: // type-expr: "`(`" pack-expression "`)`"
#line 1228 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4510 "annium.tab.cpp"
    break;

  case 240: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1230 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4516 "annium.tab.cpp"
    break;

  case 241: // type-expr: type-expr "`|`" type-expr
#line 1232 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4522 "annium.tab.cpp"
    break;

  case 242: // type-expr: type-expr "`->`" type-expr
#line 1234 "annium.y"
        { 
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, annium_fn_type{ .arg = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())) } };
        }
#line 4530 "annium.tab.cpp"
    break;


#line 4534 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -273;

  const short parser::yytable_ninf_ = -210;

  const short
  parser::yypact_[] =
  {
     737,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
      47,   843,   864,   987,    47,   987,   987,   987,    -1,    65,
      19,   987,   145,   987,    19,    66,  -273,  -273,  -273,    13,
      19,    19,  -273,  -273,  -273,    48,   106,    39,   419,  -273,
    -273,  -273,  -273,    68,  -273,   349,    16,    57,  -273,   101,
    -273,   240,   529,   128,  -273,    43,  -273,   987,  -273,    83,
     142,   833,   111,  -273,   631,   148,   173,   833,   232,  -273,
      36,    36,    36,    47,  -273,   168,   219,  -273,    47,    13,
     267,   490,  -273,    68,   174,   596,    25,  -273,  -273,  -273,
      68,   215,  -273,   221,  -273,   197,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,    47,  -273,  -273,   987,   207,
      26,   987,    47,   987,   987,    47,  -273,   987,   987,   987,
     987,   987,   987,  -273,   987,   987,   987,   987,   987,   332,
     423,   987,  -273,   987,  -273,  -273,   987,   987,   218,   525,
    -273,   238,  -273,  -273,  -273,  -273,   987,  -273,  -273,   611,
     987,   272,  -273,   987,   987,  -273,   987,   210,   987,   332,
     332,    47,   250,   332,  -273,   271,   262,   611,   915,   987,
    -273,   278,  -273,   317,   155,  -273,   833,   252,   252,  1041,
     955,   159,   635,    36,    36,   430,   536,  -273,   322,   322,
     285,   337,  1038,  -273,  -273,   366,    45,   330,   325,  -273,
     369,   322,   322,  -273,   833,   346,   833,   833,   833,  -273,
    -273,  -273,  -273,  -273,   833,   263,   335,   970,   611,   246,
      57,   101,   240,   130,   262,   611,    -4,   353,   339,  -273,
     987,   833,   596,   596,    48,   833,   356,   358,  -273,   363,
     348,  -273,    47,   371,  -273,   130,    19,    41,   987,   405,
     387,  -273,  -273,   405,   833,  -273,  -273,  -273,  -273,   987,
    -273,  -273,  -273,   717,   322,   322,  -273,  1038,  1038,  1038,
    -273,   412,  -273,  -273,    15,   322,   285,   322,   405,   166,
     332,  -273,   281,  -273,  -273,   987,  -273,   190,   316,   611,
     987,   611,   130,  -273,  -273,  -273,   987,   833,  -273,  -273,
    -273,   427,   338,  -273,    47,    38,   400,   380,  -273,   438,
      68,   249,   405,  -273,   702,  -273,   405,  -273,   833,  -273,
     345,  -273,  -273,  -273,  -273,  -273,  -273,   285,   416,   322,
    -273,   322,   322,  -273,   611,   987,   915,  -273,  -273,  -273,
    -273,   833,   415,  -273,  -273,   741,    29,  -273,   987,   987,
    -273,  -273,   987,   611,  -273,    47,   417,  1038,   391,   366,
     391,   313,   192,  -273,  -273,   433,  -273,    41,  -273,  -273,
     322,   322,   285,  -273,  -273,  -273,   257,   833,   187,  -273,
     833,   833,   833,   305,  -273,    47,  -273,  -273,   391,  -273,
    1038,   434,  -273,   249,  -273,   405,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,   987,  -273,   421,  -273,  -273,  -273,  -273,
    -273,   833,  -273
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   185,    53,   174,   173,   184,   181,   182,   183,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    62,     0,
       0,     0,   178,   179,   180,     0,     0,     0,     0,     5,
       7,    14,    56,   175,    60,     0,   220,   187,   215,   219,
     216,   232,     0,     0,   218,   217,    55,     0,   188,    56,
     220,   227,     0,   217,    22,     0,     0,    82,     0,   195,
     197,   199,   198,     0,    41,    20,    16,    18,     0,     0,
     210,     0,   171,   172,     0,     0,     0,    44,    13,    65,
      64,     0,    42,     0,    38,     0,    15,   194,     1,     2,
      10,     3,     8,     6,     9,     0,    63,    61,   225,    69,
       0,   225,     0,   225,     0,     0,   196,     0,     0,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,   100,
       0,     0,   209,     0,    49,    48,    50,     0,    39,    40,
      25,     0,    47,    23,   191,   190,     0,   192,    19,     0,
       0,     0,    12,    84,     0,    32,     0,    35,     0,   100,
     100,    73,     0,   100,    57,     0,   226,     0,     0,     0,
      37,     0,   176,     0,     0,   177,    46,   202,   203,   207,
     208,   204,     0,   200,   201,   205,   206,    54,   106,   106,
     129,     0,   154,   123,   124,   104,   167,     0,   101,   102,
     127,   106,   106,   189,   228,    56,   229,    51,    52,    28,
      26,    27,    24,    31,    83,   235,   234,     0,     0,   233,
       0,     0,   236,    21,    17,     0,    56,     0,    85,    86,
       0,    89,     0,     0,     0,    80,     0,     0,    77,     0,
      74,    75,    92,     0,   221,    70,     0,   167,     0,   167,
     158,    71,   169,   165,    43,   212,   214,   213,   193,     0,
     115,   117,   130,   133,   106,   106,   157,   152,     0,     0,
     148,   155,   153,   105,   167,   106,   129,   106,   168,     0,
       0,   128,   125,   122,   112,     0,   238,     0,     0,     0,
       0,     0,    11,    90,    91,   211,     0,    88,    33,    34,
      36,     0,    67,    72,     0,     0,     0,    93,    94,     0,
     166,   167,   167,   161,     0,   160,   167,   170,   107,   134,
     131,   121,   111,   151,   149,   150,   156,   129,     0,   106,
     116,   106,   106,   114,     0,     0,     0,   222,    29,   103,
     126,   230,   239,   237,   242,     0,   241,    87,     0,     0,
      66,    76,     0,     0,    78,     0,     0,     0,   167,     0,
     167,   167,     0,   146,   136,   138,   162,   167,   159,   132,
     106,   106,   129,   113,   120,   110,     0,    30,     0,   240,
      81,    68,    99,    96,    95,    92,   142,   147,   167,   144,
       0,   140,   135,   167,   139,   167,   163,   118,   108,   119,
     109,   223,   224,     0,    98,     0,   145,   143,   141,   137,
     164,    97,    79
  };

  const short
  parser::yypgoto_[] =
  {
    -273,  -273,  -273,  -273,   436,  -273,  -273,  -273,  -273,  -273,
      10,   -11,   -35,  -273,   -56,   340,    30,  -109,     6,   431,
    -273,    18,  -273,   456,  -273,   408,  -273,  -273,  -273,   188,
    -273,  -273,   481,  -273,  -273,   205,  -273,   117,  -273,  -273,
     149,   201,  -273,  -273,    81,   223,  -163,  -273,  -273,  -272,
    -244,  -273,  -155,   112,  -115,  -190,  -161,  -146,  -182,  -158,
    -273,   -53,  -273,    17,  -273,    28,     0,  -273,  -273,   288,
      -2,    31,    40
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    36,    37,    38,    39,    74,    75,    76,   138,   139,
     337,   338,    40,   141,    41,   143,    42,   249,    43,    44,
      45,    60,    91,   109,   350,   110,    94,   239,   240,   241,
      96,    87,    66,   227,   228,   229,   230,   306,   307,   404,
     308,   197,   198,   274,   260,   199,   200,   201,   263,   264,
     312,   362,   363,   364,   202,   270,   271,   252,   365,   278,
      84,    47,    48,    49,    50,    51,    61,    53,    54,   165,
     166,    63,   223
  };

  const short
  parser::yytable_[] =
  {
      52,    65,   272,   104,   331,     2,   316,   251,   142,    62,
     253,   293,    67,    67,   277,    70,    71,    72,    46,     2,
     196,    81,     2,    85,    97,     2,    80,   262,    83,   140,
      86,    55,   246,   253,   253,    90,    93,    95,    52,    99,
      56,    59,   294,   -45,    69,   116,   158,   169,    77,   289,
     196,   196,    90,     2,   196,   370,    46,   130,   246,   352,
      10,   327,   246,    10,    52,   313,    10,   315,   108,    55,
     155,    88,   105,   159,   157,   265,    64,   323,   324,   325,
     275,   290,    46,   142,   353,    90,   273,   328,   124,   311,
      89,   276,   329,    89,   -45,    55,   220,   100,    64,   170,
     399,   -45,    73,   148,   211,   111,    98,   317,   151,   253,
     253,   253,   174,   262,   220,   105,   112,   176,   177,   178,
     179,   180,   181,   395,   182,   183,   184,   185,   186,   131,
     366,   204,   317,   206,   368,   164,   207,   208,    59,    52,
      78,    59,   172,    59,    59,   175,   214,   220,   224,   113,
     289,     2,    82,   231,   232,   219,   233,    46,   235,   195,
     132,   332,    79,   205,   262,   220,   221,   386,   116,   254,
      55,   196,   220,   219,   250,   378,   129,   222,   253,   391,
      59,   133,   290,   226,   221,   396,   334,   335,   336,   195,
     195,   238,    10,   195,   108,   222,   291,   250,   250,   253,
     407,   144,   361,   387,   257,   389,   219,   245,   335,   262,
     220,   124,   371,   410,   149,   287,    64,   221,   162,   125,
     126,   298,   299,   300,   219,   133,   145,   167,   222,   168,
     297,   219,   253,   406,   150,   221,   220,    64,   220,   342,
     282,   392,   221,   146,   105,   163,   222,    59,   314,   361,
     388,   361,   310,   222,   156,     2,   187,   400,   288,   318,
     133,   116,   393,   160,   357,   292,   246,   358,   105,   219,
     261,   161,   305,   250,   250,   250,   209,   289,   335,   361,
     221,   220,   283,   284,   361,   341,   122,   147,   114,   213,
     345,   222,   234,   105,  -175,   219,   231,   219,   242,   115,
     220,   289,   146,   320,   124,  -175,   221,    64,   221,   290,
     195,  -174,   125,   126,   105,   153,   340,   222,   225,   222,
     403,   359,  -174,   291,   244,   289,   226,   255,   390,   344,
     246,   346,   133,   290,   238,   377,   289,   259,     2,   187,
     219,   360,   250,     2,   187,   321,   322,   291,   380,   381,
     188,   221,   382,   191,   246,   247,   330,   290,   333,   219,
     236,   237,   222,   250,   243,   289,   256,   189,   290,   343,
     221,   291,   266,   187,   376,     2,   215,   216,   190,   279,
     369,   222,   291,  -173,    10,   305,   401,   248,   402,   192,
     193,   194,   285,   383,  -173,   280,   250,   290,   187,   171,
     191,   173,   295,   411,   281,   301,   357,   302,   246,   296,
     373,   291,   374,   375,   303,   305,    10,   217,   304,   101,
     309,   218,   246,   360,     1,     2,     3,     4,     5,     6,
       7,     8,   116,     9,   105,   311,   192,   193,   194,   116,
     349,   267,   268,   269,    26,    27,   106,   326,   348,   354,
     355,   397,   398,   118,   119,   120,   121,   122,   123,   356,
     118,   119,   372,  -209,   122,   385,    10,    11,   394,   408,
     412,    12,   203,    13,   103,   124,   107,   102,    14,   212,
      15,    16,   124,   125,   126,    92,    17,   152,   127,   128,
     125,   126,   351,    18,    68,    19,    20,    21,    22,   116,
      23,   347,   405,   339,   384,   409,     0,    24,     0,     0,
       0,     0,     0,    25,    26,    27,    28,    29,    30,    31,
     118,   119,   120,   121,   122,   123,    32,    33,    34,    35,
       1,     2,     3,     4,     5,     6,     7,     8,   116,     9,
      64,     0,   124,     0,   117,   116,     0,     0,   154,     0,
     125,   126,     0,     0,     0,   127,   128,     0,     0,   118,
     119,   120,   121,   122,   123,     0,   118,   119,     0,     0,
     122,     0,    10,    11,     0,     0,     0,    12,     0,    13,
       0,   124,     0,   210,    14,     0,    15,    16,   124,   125,
     126,     0,    17,     0,   127,   128,   125,   126,     0,    18,
       0,   127,    20,    21,    22,   116,    23,     0,   134,   135,
     136,   137,     0,    24,     0,     0,     0,     2,   215,   216,
      26,    27,    28,    29,    30,     0,   118,   119,   120,   121,
     122,   123,    32,    33,    34,    35,     1,     2,     3,     4,
       5,     6,     7,     8,   116,     9,    64,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   125,   126,    10,   217,
       0,   127,   128,   218,     0,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    12,     0,    13,     0,   124,   258,     0,
      14,     0,    15,    16,     0,   125,   126,     0,    17,     0,
     127,   128,     0,     0,     0,    18,     0,     0,    20,    21,
      22,   116,    23,     0,   134,   135,   136,   137,     0,    24,
       0,     0,     0,     2,   215,   216,    26,    27,    28,    29,
      30,     0,   118,   119,   120,   121,   122,   123,    32,    33,
      34,    35,     1,     2,     3,     4,     5,     6,     7,     8,
     116,     9,   319,   367,   124,     0,     0,     0,     0,     0,
       0,     0,   125,   126,    10,   217,     0,   127,   128,   218,
       0,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,    12,
       0,    13,     0,   124,   379,     0,    14,     0,    15,    16,
       0,   125,   126,     0,    17,     0,   127,   128,     0,     0,
       0,    18,     0,    19,    20,    21,    22,     0,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,    31,     0,     0,
       0,     0,   116,     0,    32,    33,    34,    35,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,   123,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,    57,
      10,    11,    58,   125,   126,    12,     0,    13,   127,   128,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,    10,    11,     0,    64,     0,    12,     0,    13,     0,
      20,     2,   187,    14,     0,    15,    16,     0,     0,     0,
       0,    17,   246,   247,     0,     0,     0,     0,    26,    27,
      28,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,    26,
      27,    28,    10,     0,   116,   248,     0,     0,     0,     0,
       0,    32,    33,    34,    35,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,   118,   119,   120,     0,   122,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,   125,   126,    10,    11,   286,
     127,   128,    12,     0,    13,     0,     0,     0,     0,    14,
       0,    15,    16,     0,    10,    11,     0,    17,     0,    12,
       0,    13,     0,     0,     2,   187,    14,    20,    15,    16,
     116,     0,     0,     0,    17,   246,   247,     0,     0,     0,
       0,     0,     0,     0,    20,    26,    27,    28,     0,     0,
       0,   118,   119,   266,     0,   122,     0,    32,    33,    34,
      35,     0,    26,    27,    28,    10,     0,     0,   248,     0,
       0,     0,     0,   124,    32,    33,    34,    35,     0,     0,
       0,   125,   126,     0,     0,     0,   127,   128
  };

  const short
  parser::yycheck_[] =
  {
       0,    12,   192,    38,   276,     6,   250,   168,    64,    11,
     168,    15,    12,    13,   196,    15,    16,    17,     0,     6,
     129,    21,     6,    23,    35,     6,    20,   190,    22,    64,
      24,     0,    17,   191,   192,    29,    30,    31,    38,     0,
      10,    11,    46,     0,    14,     9,    21,    21,    18,    20,
     159,   160,    46,     6,   163,   327,    38,    57,    17,    21,
      47,    46,    17,    47,    64,   247,    47,   249,    52,    38,
      81,     5,    47,    48,    85,   190,    50,   267,   268,   269,
      35,    52,    64,   139,    46,    79,   195,    72,    52,    48,
      77,    46,   274,    77,    51,    64,   149,    58,    50,   110,
     372,    58,   103,    73,   139,    48,     0,   253,    78,   267,
     268,   269,   114,   276,   167,    47,    59,   117,   118,   119,
     120,   121,   122,   367,   124,   125,   126,   127,   128,    46,
     312,   131,   278,   133,   316,   105,   136,   137,   108,   139,
      75,   111,   112,   113,   114,   115,   146,   200,   150,    48,
      20,     6,     7,   153,   154,   149,   156,   139,   158,   129,
      49,   276,    97,   133,   327,   218,   149,   357,     9,   169,
     139,   280,   225,   167,   168,   336,    48,   149,   336,   361,
     150,    70,    52,   153,   167,   367,    20,    21,    22,   159,
     160,   161,    47,   163,    52,   167,    66,   191,   192,   357,
     390,    53,   311,   358,    49,   360,   200,   167,    21,   372,
     263,    52,   327,   395,    46,   217,    50,   200,    21,    60,
      61,   232,   233,   234,   218,    70,    53,    20,   200,    22,
     230,   225,   390,   388,    15,   218,   289,    50,   291,    49,
     200,    49,   225,    70,    47,    48,   218,   217,   248,   358,
     359,   360,   246,   225,    80,     6,     7,   372,   218,   259,
      70,     9,    70,    48,    15,   225,    17,    18,    47,   263,
     189,    50,   242,   267,   268,   269,    58,    20,    21,   388,
     263,   334,   201,   202,   393,   285,    34,    55,    48,    51,
     290,   263,    82,    47,    48,   289,   296,   291,    48,    59,
     353,    20,    70,   263,    52,    59,   289,    50,   291,    52,
     280,    48,    60,    61,    47,    48,    35,   289,    46,   291,
      15,    72,    59,    66,    53,    20,   296,    49,    15,   289,
      17,   291,    70,    52,   304,   335,    20,    15,     6,     7,
     334,   311,   336,     6,     7,   264,   265,    66,   348,   349,
      18,   334,   352,    68,    17,    18,   275,    52,   277,   353,
     159,   160,   334,   357,   163,    20,    49,    35,    52,    53,
     353,    66,    35,     7,   334,     6,     7,     8,    46,    49,
      35,   353,    66,    48,    47,   355,   376,    50,   378,   104,
     105,   106,    46,   353,    59,    70,   390,    52,     7,   111,
      68,   113,    49,   403,    35,    49,    15,    49,    17,    70,
     329,    66,   331,   332,    51,   385,    47,    48,    70,     0,
      49,    52,    17,   393,     5,     6,     7,     8,     9,    10,
      11,    12,     9,    14,    47,    48,   104,   105,   106,     9,
     102,   104,   105,   106,    95,    96,    97,    35,    21,    49,
      70,   370,   371,    30,    31,    32,    33,    34,    35,    21,
      30,    31,    46,    48,    34,    48,    47,    48,    35,    35,
      49,    52,    49,    54,    38,    52,    45,    58,    59,   139,
      61,    62,    52,    60,    61,    29,    67,    79,    65,    66,
      60,    61,   304,    74,    13,    76,    77,    78,    79,     9,
      81,   296,   385,   280,   355,   393,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
      30,    31,    32,    33,    34,    35,   107,   108,   109,   110,
       5,     6,     7,     8,     9,    10,    11,    12,     9,    14,
      50,    -1,    52,    -1,    15,     9,    -1,    -1,    58,    -1,
      60,    61,    -1,    -1,    -1,    65,    66,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    30,    31,    -1,    -1,
      34,    -1,    47,    48,    -1,    -1,    -1,    52,    -1,    54,
      -1,    52,    -1,    58,    59,    -1,    61,    62,    52,    60,
      61,    -1,    67,    -1,    65,    66,    60,    61,    -1,    74,
      -1,    65,    77,    78,    79,     9,    81,    -1,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,     6,     7,     8,
      95,    96,    97,    98,    99,    -1,    30,    31,    32,    33,
      34,    35,   107,   108,   109,   110,     5,     6,     7,     8,
       9,    10,    11,    12,     9,    14,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    47,    48,
      -1,    65,    66,    52,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    52,    -1,    54,    -1,    52,    53,    -1,
      59,    -1,    61,    62,    -1,    60,    61,    -1,    67,    -1,
      65,    66,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,     9,    81,    -1,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,     6,     7,     8,    95,    96,    97,    98,
      99,    -1,    30,    31,    32,    33,    34,    35,   107,   108,
     109,   110,     5,     6,     7,     8,     9,    10,    11,    12,
       9,    14,    35,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    47,    48,    -1,    65,    66,    52,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,
      -1,    54,    -1,    52,    53,    -1,    59,    -1,    61,    62,
      -1,    60,    61,    -1,    67,    -1,    65,    66,    -1,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,     9,    -1,   107,   108,   109,   110,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    46,
      47,    48,    49,    60,    61,    52,    -1,    54,    65,    66,
      -1,    -1,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    47,    48,    -1,    50,    -1,    52,    -1,    54,    -1,
      77,     6,     7,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    17,    18,    -1,    -1,    -1,    -1,    95,    96,
      97,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    47,    -1,     9,    50,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    30,    31,    32,    -1,    34,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    47,    48,    49,
      65,    66,    52,    -1,    54,    -1,    -1,    -1,    -1,    59,
      -1,    61,    62,    -1,    47,    48,    -1,    67,    -1,    52,
      -1,    54,    -1,    -1,     6,     7,    59,    77,    61,    62,
       9,    -1,    -1,    -1,    67,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    95,    96,    97,    -1,    -1,
      -1,    30,    31,    35,    -1,    34,    -1,   107,   108,   109,
     110,    -1,    95,    96,    97,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    52,   107,   108,   109,   110,    -1,    -1,
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
      46,    68,   104,   105,   106,   127,   128,   152,   153,   156,
     157,   158,   165,    49,   177,   127,   177,   177,   177,    58,
      58,   123,   126,    51,   177,     7,     8,    48,    52,   129,
     172,   174,   176,   183,   181,    46,   127,   144,   145,   146,
     147,   177,   177,   177,    82,   177,   152,   152,   127,   138,
     139,   140,    48,   152,    53,   183,    17,    18,    50,   128,
     129,   167,   168,   170,   177,    49,    49,    49,    53,    15,
     155,   155,   157,   159,   160,   165,    35,   104,   105,   106,
     166,   167,   166,   128,   154,    35,    46,   169,   170,    49,
      70,    35,   183,   155,   155,    46,    49,   181,   183,    20,
      52,    66,   183,    15,    46,    49,    70,   177,   122,   122,
     122,    49,    49,    51,    70,   127,   148,   149,   151,    49,
     129,    48,   161,   169,   177,   169,   161,   168,   177,    35,
     183,   155,   155,   166,   166,   166,    35,    46,    72,   169,
     155,   160,   165,   155,    20,    21,    22,   121,   122,   156,
      35,   177,    49,    53,   183,   177,   183,   146,    21,   102,
     135,   140,    21,    46,    49,    70,    21,    15,    18,    72,
     127,   128,   162,   163,   164,   169,   169,    51,   169,    35,
     160,   165,    46,   155,   155,   155,   183,   177,   167,    53,
     177,   177,   177,   183,   151,    48,   166,   163,   128,   163,
      15,   169,    49,    70,    35,   161,   169,   155,   155,   160,
     165,   121,   121,    15,   150,   148,   163,   166,    35,   164,
     169,   177,    49
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
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     175,   175,   176,   176,   176,   177,   177,   177,   177,   177,
     178,   178,   179,   179,   179,   180,   180,   181,   181,   181,
     181,   182,   182,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183
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
       4,     3,     2,     4,     3,     2,     3,     2,     5,     5,
       4,     3,     2,     1,     1,     2,     3,     1,     2,     0,
       1,     2,     3,     1,     2,     3,     1,     3,     1,     2,
       2,     3,     2,     3,     2,     3,     1,     2,     2,     3,
       3,     3,     2,     2,     1,     1,     2,     1,     1,     3,
       2,     2,     3,     4,     5,     1,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     3,     3,     4,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     5,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     4,     5,     7,     7,     0,     1,     1,     3,     3,
       5,     2,     1,     1,     1,     1,     1,     3,     2,     3,
       4,     3,     3
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
       0,   335,   335,   336,   340,   342,   344,   361,   363,   364,
     366,   371,   373,   375,   377,   379,   384,   385,   390,   392,
     397,   398,   403,   405,   407,   412,   414,   415,   417,   423,
     426,   437,   442,   444,   446,   448,   450,   452,   462,   467,
     468,   472,   474,   476,   483,   485,   487,   495,   496,   498,
     500,   502,   504,   509,   517,   532,   534,   536,   542,   543,
     547,   548,   552,   554,   559,   561,   566,   584,   585,   597,
     598,   600,   607,   612,   613,   617,   619,   624,   630,   632,
     655,   661,   678,   680,   686,   687,   691,   693,   698,   700,
     705,   707,   713,   714,   718,   720,   725,   726,   730,   732,
     739,   740,   744,   746,   751,   752,   756,   757,   761,   763,
     765,   767,   769,   773,   777,   779,   781,   783,   788,   790,
     792,   794,   796,   801,   802,   806,   808,   812,   814,   819,
     824,   828,   830,   834,   836,   846,   851,   853,   859,   861,
     864,   866,   870,   873,   879,   882,   895,   898,   903,   904,
     905,   906,   907,   908,   909,   913,   914,   915,   919,   921,
     923,   925,   927,   929,   931,   933,   938,   943,   945,   949,
     951,   957,   959,   964,   966,   968,   970,   972,   977,   979,
     981,   983,   985,   987,   989,   991,   993,   995,   996,   998,
    1004,  1012,  1014,  1016,  1018,  1020,  1027,  1034,  1036,  1038,
    1043,  1045,  1049,  1051,  1053,  1056,  1060,  1063,  1066,  1071,
    1083,  1087,  1094,  1096,  1098,  1103,  1104,  1105,  1106,  1107,
    1111,  1113,  1118,  1125,  1133,  1144,  1146,  1151,  1153,  1159,
    1164,  1172,  1174,  1214,  1216,  1218,  1220,  1223,  1225,  1227,
    1229,  1231,  1233
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
#line 5522 "annium.tab.cpp"

#line 1556 "annium.y"

