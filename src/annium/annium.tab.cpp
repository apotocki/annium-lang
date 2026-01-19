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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.copy< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.copy< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.copy< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.copy< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.copy< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.copy< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.copy< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.copy< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.copy< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.copy< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.copy< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.YY_MOVE_OR_COPY< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.YY_MOVE_OR_COPY< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.YY_MOVE_OR_COPY< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.YY_MOVE_OR_COPY< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.YY_MOVE_OR_COPY< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.YY_MOVE_OR_COPY< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.YY_MOVE_OR_COPY< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.YY_MOVE_OR_COPY< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.YY_MOVE_OR_COPY< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.YY_MOVE_OR_COPY< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.YY_MOVE_OR_COPY< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.YY_MOVE_OR_COPY< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.YY_MOVE_OR_COPY< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.YY_MOVE_OR_COPY< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.YY_MOVE_OR_COPY< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.YY_MOVE_OR_COPY< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.YY_MOVE_OR_COPY< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.YY_MOVE_OR_COPY< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.YY_MOVE_OR_COPY< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.YY_MOVE_OR_COPY< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.YY_MOVE_OR_COPY< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.YY_MOVE_OR_COPY< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.YY_MOVE_OR_COPY< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.YY_MOVE_OR_COPY< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.YY_MOVE_OR_COPY< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.YY_MOVE_OR_COPY< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.YY_MOVE_OR_COPY< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.YY_MOVE_OR_COPY< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.YY_MOVE_OR_COPY< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.YY_MOVE_OR_COPY< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.YY_MOVE_OR_COPY< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.YY_MOVE_OR_COPY< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.YY_MOVE_OR_COPY< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.move< annotated_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.move< enum_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field: // field
        value.move< field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.move< fn_pure > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.move< identifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.move< parameter > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.move< parameter_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.move< statement > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.move< std::vector<field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.move< std::vector<identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.move< struct_decl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.move< syntax_expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.copy< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.copy< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.copy< annotated_qname > (that.value);
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.copy< context_identifier > (that.value);
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.copy< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.copy< field > (that.value);
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.copy< field::default_spec > (that.value);
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.copy< fn_kind > (that.value);
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.copy< fn_pure > (that.value);
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.copy< identifier > (that.value);
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.copy< let_statement > (that.value);
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.copy< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.copy< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.copy< parameter > (that.value);
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.copy< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.copy< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.copy< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.copy< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.copy< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.copy< statement_list_t > (that.value);
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.copy< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.copy< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.copy< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.copy< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.copy< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.copy< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.copy< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.copy< struct_decl > (that.value);
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.copy< syntax_expression > (that.value);
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.copy< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.copy< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.copy< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.copy< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.copy< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        value.move< annotated_identifier > (that.value);
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        value.move< annotated_nil > (that.value);
        break;

      case symbol_kind::S_qname: // qname
        value.move< annotated_qname > (that.value);
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        value.move< context_identifier > (that.value);
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        value.move< enum_decl > (that.value);
        break;

      case symbol_kind::S_field: // field
        value.move< field > (that.value);
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        value.move< field::default_spec > (that.value);
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        value.move< fn_kind > (that.value);
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        value.move< fn_pure > (that.value);
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        value.move< identifier > (that.value);
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        value.move< let_statement > (that.value);
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        value.move< opt_named_expression_list_t > (that.value);
        break;

      case symbol_kind::S_argument: // argument
        value.move< opt_named_expression_t > (that.value);
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        value.move< parameter > (that.value);
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        value.move< parameter::default_spec > (that.value);
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        value.move< parameter_list_t > (that.value);
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        value.move< resource_location > (that.value);
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        value.move< sonia::string_view > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        value.move< statement > (that.value);
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        value.move< statement_list_t > (that.value);
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        value.move< std::pair<resource_location, fn_kind> > (that.value);
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        value.move< std::pair<resource_location, lambda> > (that.value);
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        value.move< std::pair<resource_location, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        value.move< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        value.move< std::pair<syntax_pattern, parameter_constraint_modifier_t> > (that.value);
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        value.move< std::vector<field> > (that.value);
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        value.move< std::vector<identifier> > (that.value);
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        value.move< struct_decl > (that.value);
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        value.move< syntax_expression > (that.value);
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        value.move< syntax_expression const* > (that.value);
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        value.move< syntax_expression_list_t > (that.value);
        break;

      case symbol_kind::S_pattern: // pattern
        value.move< syntax_pattern > (that.value);
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        value.move< syntax_pattern::field > (that.value);
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        value.move< syntax_pattern_field_list_t > (that.value);
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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
#line 335 "annium.y"
                 { }
#line 1849 "annium.tab.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 335 "annium.y"
                 { }
#line 1855 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTEXT_IDENTIFIER: // CONTEXT_IDENTIFIER
#line 335 "annium.y"
                 { }
#line 1861 "annium.tab.cpp"
        break;

      case symbol_kind::S_RESERVED_IDENTIFIER: // RESERVED_IDENTIFIER
#line 335 "annium.y"
                 { }
#line 1867 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER_INDEX: // INTEGER_INDEX
#line 335 "annium.y"
                 { }
#line 1873 "annium.tab.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 335 "annium.y"
                 { }
#line 1879 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 335 "annium.y"
                 { }
#line 1885 "annium.tab.cpp"
        break;

      case symbol_kind::S_DECIMAL_S: // DECIMAL_S
#line 335 "annium.y"
                 { }
#line 1891 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
#line 335 "annium.y"
                 { }
#line 1897 "annium.tab.cpp"
        break;

      case symbol_kind::S_CT_IDENTIFIER: // CT_IDENTIFIER
#line 335 "annium.y"
                 { }
#line 1903 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASSIGN: // "`=`"
#line 335 "annium.y"
                 { }
#line 1909 "annium.tab.cpp"
        break;

      case symbol_kind::S_UNDERSCORE: // "`_`"
#line 335 "annium.y"
                 { }
#line 1915 "annium.tab.cpp"
        break;

      case symbol_kind::S_EQ: // "`==`"
#line 335 "annium.y"
                 { }
#line 1921 "annium.tab.cpp"
        break;

      case symbol_kind::S_NE: // "`!=`"
#line 335 "annium.y"
                 { }
#line 1927 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_AND: // "`&&`"
#line 335 "annium.y"
                 { }
#line 1933 "annium.tab.cpp"
        break;

      case symbol_kind::S_LOGIC_OR: // "`||`"
#line 335 "annium.y"
                 { }
#line 1939 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONCAT: // "`..`"
#line 335 "annium.y"
                 { }
#line 1945 "annium.tab.cpp"
        break;

      case symbol_kind::S_ELLIPSIS: // "`...`"
#line 335 "annium.y"
                 { }
#line 1951 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_PARENTHESIS: // "`(`"
#line 335 "annium.y"
                 { }
#line 1957 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_BRACE: // "`{`"
#line 335 "annium.y"
                 { }
#line 1963 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_BRACKET: // "`[`"
#line 335 "annium.y"
                 { }
#line 1969 "annium.tab.cpp"
        break;

      case symbol_kind::S_OPEN_SQUARE_DBL_BRACKET: // "`[[`"
#line 335 "annium.y"
                 { }
#line 1975 "annium.tab.cpp"
        break;

      case symbol_kind::S_POINT: // "`.`"
#line 335 "annium.y"
                 { }
#line 1981 "annium.tab.cpp"
        break;

      case symbol_kind::S_PLUS: // "`+`"
#line 335 "annium.y"
                 { }
#line 1987 "annium.tab.cpp"
        break;

      case symbol_kind::S_MINUS: // "`-`"
#line 335 "annium.y"
                 { }
#line 1993 "annium.tab.cpp"
        break;

      case symbol_kind::S_ASTERISK: // "`*`"
#line 335 "annium.y"
                 { }
#line 1999 "annium.tab.cpp"
        break;

      case symbol_kind::S_AMPERSAND: // "`&`"
#line 335 "annium.y"
                 { }
#line 2005 "annium.tab.cpp"
        break;

      case symbol_kind::S_BITOR: // "`|`"
#line 335 "annium.y"
                 { }
#line 2011 "annium.tab.cpp"
        break;

      case symbol_kind::S_EXCLPT: // "`!`"
#line 335 "annium.y"
                 { }
#line 2017 "annium.tab.cpp"
        break;

      case symbol_kind::S_QMARK: // "`?`"
#line 335 "annium.y"
                 { }
#line 2023 "annium.tab.cpp"
        break;

      case symbol_kind::S_NEW: // "`new`"
#line 335 "annium.y"
                 { }
#line 2029 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONTINUE: // "`continue`"
#line 335 "annium.y"
                 { }
#line 2035 "annium.tab.cpp"
        break;

      case symbol_kind::S_BREAK: // "`break`"
#line 335 "annium.y"
                 { }
#line 2041 "annium.tab.cpp"
        break;

      case symbol_kind::S_RETURN: // "`return`"
#line 335 "annium.y"
                 { }
#line 2047 "annium.tab.cpp"
        break;

      case symbol_kind::S_YIELD: // "`yield`"
#line 335 "annium.y"
                 { }
#line 2053 "annium.tab.cpp"
        break;

      case symbol_kind::S_FN: // "`fn`"
#line 335 "annium.y"
                 { }
#line 2059 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPEFN: // "`typefn`"
#line 335 "annium.y"
                 { }
#line 2065 "annium.tab.cpp"
        break;

      case symbol_kind::S_TYPENAME: // "typename modifier"
#line 335 "annium.y"
                 { }
#line 2071 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEXPR: // "constexpr modifier"
#line 335 "annium.y"
                 { }
#line 2077 "annium.tab.cpp"
        break;

      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
#line 335 "annium.y"
                 { }
#line 2083 "annium.tab.cpp"
        break;

      case symbol_kind::S_RUNTIME: // "runctime modifier"
#line 335 "annium.y"
                 { }
#line 2089 "annium.tab.cpp"
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
#line 335 "annium.y"
                 { }
#line 2095 "annium.tab.cpp"
        break;

      case symbol_kind::S_TRUE_WORD: // "true"
#line 335 "annium.y"
                 { }
#line 2101 "annium.tab.cpp"
        break;

      case symbol_kind::S_FALSE_WORD: // "false"
#line 335 "annium.y"
                 { }
#line 2107 "annium.tab.cpp"
        break;

      case symbol_kind::S_PROBE: // PROBE
#line 335 "annium.y"
                 { }
#line 2113 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement_any: // statement_any
#line 335 "annium.y"
                 { }
#line 2119 "annium.tab.cpp"
        break;

      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
#line 335 "annium.y"
                 { }
#line 2125 "annium.tab.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 335 "annium.y"
                 { }
#line 2131 "annium.tab.cpp"
        break;

      case symbol_kind::S_117_let_decl: // let-decl
#line 335 "annium.y"
                 { }
#line 2137 "annium.tab.cpp"
        break;

      case symbol_kind::S_118_let_decl_start: // let-decl-start
#line 335 "annium.y"
                 { }
#line 2143 "annium.tab.cpp"
        break;

      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
#line 335 "annium.y"
                 { }
#line 2149 "annium.tab.cpp"
        break;

      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
#line 335 "annium.y"
                 { }
#line 2155 "annium.tab.cpp"
        break;

      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
#line 335 "annium.y"
                 { }
#line 2161 "annium.tab.cpp"
        break;

      case symbol_kind::S_122_function_body: // function-body
#line 335 "annium.y"
                 { }
#line 2167 "annium.tab.cpp"
        break;

      case symbol_kind::S_123_braced_statements: // braced-statements
#line 335 "annium.y"
                 { }
#line 2173 "annium.tab.cpp"
        break;

      case symbol_kind::S_124_finished_statement: // finished-statement
#line 335 "annium.y"
                 { }
#line 2179 "annium.tab.cpp"
        break;

      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
#line 335 "annium.y"
                 { }
#line 2185 "annium.tab.cpp"
        break;

      case symbol_kind::S_126_generic_statement: // generic-statement
#line 335 "annium.y"
                 { }
#line 2191 "annium.tab.cpp"
        break;

      case symbol_kind::S_127_infunction_statement: // infunction-statement
#line 335 "annium.y"
                 { }
#line 2197 "annium.tab.cpp"
        break;

      case symbol_kind::S_identifier: // identifier
#line 335 "annium.y"
                 { }
#line 2203 "annium.tab.cpp"
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
#line 335 "annium.y"
                 { }
#line 2209 "annium.tab.cpp"
        break;

      case symbol_kind::S_qname: // qname
#line 335 "annium.y"
                 { }
#line 2215 "annium.tab.cpp"
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
#line 335 "annium.y"
                 { }
#line 2221 "annium.tab.cpp"
        break;

      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
#line 335 "annium.y"
                 { }
#line 2227 "annium.tab.cpp"
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
#line 335 "annium.y"
                 { }
#line 2233 "annium.tab.cpp"
        break;

      case symbol_kind::S_134_fn_name: // fn-name
#line 335 "annium.y"
                 { }
#line 2239 "annium.tab.cpp"
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
#line 335 "annium.y"
                 { }
#line 2245 "annium.tab.cpp"
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
#line 335 "annium.y"
                 { }
#line 2251 "annium.tab.cpp"
        break;

      case symbol_kind::S_137_fn_decl: // fn-decl
#line 335 "annium.y"
                 { }
#line 2257 "annium.tab.cpp"
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
#line 335 "annium.y"
                 { }
#line 2263 "annium.tab.cpp"
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
#line 335 "annium.y"
                 { }
#line 2269 "annium.tab.cpp"
        break;

      case symbol_kind::S_140_case_list: // case-list
#line 335 "annium.y"
                 { }
#line 2275 "annium.tab.cpp"
        break;

      case symbol_kind::S_141_case_decl: // case-decl
#line 335 "annium.y"
                 { }
#line 2281 "annium.tab.cpp"
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
#line 335 "annium.y"
                 { }
#line 2287 "annium.tab.cpp"
        break;

      case symbol_kind::S_143_using_decl: // using-decl
#line 335 "annium.y"
                 { }
#line 2293 "annium.tab.cpp"
        break;

      case symbol_kind::S_144_expression_list: // expression-list
#line 335 "annium.y"
                 { }
#line 2299 "annium.tab.cpp"
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
#line 335 "annium.y"
                 { }
#line 2305 "annium.tab.cpp"
        break;

      case symbol_kind::S_146_argument_list: // argument-list
#line 335 "annium.y"
                 { }
#line 2311 "annium.tab.cpp"
        break;

      case symbol_kind::S_argument: // argument
#line 335 "annium.y"
                 { }
#line 2317 "annium.tab.cpp"
        break;

      case symbol_kind::S_148_argument_name: // argument-name
#line 335 "annium.y"
                 { }
#line 2323 "annium.tab.cpp"
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
#line 335 "annium.y"
                 { }
#line 2329 "annium.tab.cpp"
        break;

      case symbol_kind::S_150_field_list: // field-list
#line 335 "annium.y"
                 { }
#line 2335 "annium.tab.cpp"
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
#line 335 "annium.y"
                 { }
#line 2341 "annium.tab.cpp"
        break;

      case symbol_kind::S_field: // field
#line 335 "annium.y"
                 { }
#line 2347 "annium.tab.cpp"
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
#line 335 "annium.y"
                 { }
#line 2353 "annium.tab.cpp"
        break;

      case symbol_kind::S_154_parameter_list: // parameter-list
#line 335 "annium.y"
                 { }
#line 2359 "annium.tab.cpp"
        break;

      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
#line 335 "annium.y"
                 { }
#line 2365 "annium.tab.cpp"
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
#line 335 "annium.y"
                 { }
#line 2371 "annium.tab.cpp"
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
#line 335 "annium.y"
                 { }
#line 2377 "annium.tab.cpp"
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
#line 335 "annium.y"
                 { }
#line 2383 "annium.tab.cpp"
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
#line 335 "annium.y"
                 { }
#line 2389 "annium.tab.cpp"
        break;

      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
#line 335 "annium.y"
                 { }
#line 2395 "annium.tab.cpp"
        break;

      case symbol_kind::S_161_constraint_expression: // constraint-expression
#line 335 "annium.y"
                 { }
#line 2401 "annium.tab.cpp"
        break;

      case symbol_kind::S_subpatterns: // subpatterns
#line 335 "annium.y"
                 { }
#line 2407 "annium.tab.cpp"
        break;

      case symbol_kind::S_163_pattern_list: // pattern-list
#line 335 "annium.y"
                 { }
#line 2413 "annium.tab.cpp"
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
#line 335 "annium.y"
                 { }
#line 2419 "annium.tab.cpp"
        break;

      case symbol_kind::S_165_pattern_field: // pattern-field
#line 335 "annium.y"
                 { }
#line 2425 "annium.tab.cpp"
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
#line 335 "annium.y"
                 { }
#line 2431 "annium.tab.cpp"
        break;

      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
#line 335 "annium.y"
                 { }
#line 2437 "annium.tab.cpp"
        break;

      case symbol_kind::S_pattern: // pattern
#line 335 "annium.y"
                 { }
#line 2443 "annium.tab.cpp"
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
#line 335 "annium.y"
                 { }
#line 2449 "annium.tab.cpp"
        break;

      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
#line 335 "annium.y"
                 { }
#line 2455 "annium.tab.cpp"
        break;

      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
#line 335 "annium.y"
                 { }
#line 2461 "annium.tab.cpp"
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
#line 335 "annium.y"
                 { }
#line 2467 "annium.tab.cpp"
        break;

      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
#line 335 "annium.y"
                 { }
#line 2473 "annium.tab.cpp"
        break;

      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
#line 335 "annium.y"
                 { }
#line 2479 "annium.tab.cpp"
        break;

      case symbol_kind::S_175_grouped_expression: // grouped-expression
#line 335 "annium.y"
                 { }
#line 2485 "annium.tab.cpp"
        break;

      case symbol_kind::S_176_new_expression: // new-expression
#line 335 "annium.y"
                 { }
#line 2491 "annium.tab.cpp"
        break;

      case symbol_kind::S_177_call_expression: // call-expression
#line 335 "annium.y"
                 { }
#line 2497 "annium.tab.cpp"
        break;

      case symbol_kind::S_178_syntax_expression: // syntax-expression
#line 335 "annium.y"
                 { }
#line 2503 "annium.tab.cpp"
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
#line 335 "annium.y"
                 { }
#line 2509 "annium.tab.cpp"
        break;

      case symbol_kind::S_180_lambda_expression: // lambda-expression
#line 335 "annium.y"
                 { }
#line 2515 "annium.tab.cpp"
        break;

      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
#line 335 "annium.y"
                 { }
#line 2521 "annium.tab.cpp"
        break;

      case symbol_kind::S_182_pack_expression: // pack-expression
#line 335 "annium.y"
                 { }
#line 2527 "annium.tab.cpp"
        break;

      case symbol_kind::S_183_compound_expression: // compound-expression
#line 335 "annium.y"
                 { }
#line 2533 "annium.tab.cpp"
        break;

      case symbol_kind::S_184_type_expr: // type-expr
#line 335 "annium.y"
                 { }
#line 2539 "annium.tab.cpp"
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

      case symbol_kind::S_134_fn_name: // fn-name
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
      case symbol_kind::S_148_argument_name: // argument-name
        yylhs.value.emplace< annotated_identifier > ();
        break;

      case symbol_kind::S_NIL_WORD: // "nil"
        yylhs.value.emplace< annotated_nil > ();
        break;

      case symbol_kind::S_qname: // qname
        yylhs.value.emplace< annotated_qname > ();
        break;

      case symbol_kind::S_129_internal_identifier: // internal-identifier
      case symbol_kind::S_155_internal_identifier_opt: // internal-identifier-opt
        yylhs.value.emplace< context_identifier > ();
        break;

      case symbol_kind::S_138_enum_decl: // enum-decl
        yylhs.value.emplace< enum_decl > ();
        break;

      case symbol_kind::S_field: // field
        yylhs.value.emplace< field > ();
        break;

      case symbol_kind::S_151_field_default_value_opt: // field-default-value-opt
        yylhs.value.emplace< field::default_spec > ();
        break;

      case symbol_kind::S_131_fn_kind: // fn-kind
      case symbol_kind::S_132_fn_kind_set: // fn-kind-set
        yylhs.value.emplace< fn_kind > ();
        break;

      case symbol_kind::S_135_fn_start_decl: // fn-start-decl
      case symbol_kind::S_137_fn_decl: // fn-decl
        yylhs.value.emplace< fn_pure > ();
        break;

      case symbol_kind::S_141_case_decl: // case-decl
        yylhs.value.emplace< identifier > ();
        break;

      case symbol_kind::S_117_let_decl: // let-decl
      case symbol_kind::S_118_let_decl_start: // let-decl-start
      case symbol_kind::S_119_let_decl_start_with_opt_type: // let-decl-start-with-opt-type
        yylhs.value.emplace< let_statement > ();
        break;

      case symbol_kind::S_145_argument_list_opt: // argument-list-opt
      case symbol_kind::S_146_argument_list: // argument-list
      case symbol_kind::S_181_pack_expression_opt: // pack-expression-opt
      case symbol_kind::S_182_pack_expression: // pack-expression
        yylhs.value.emplace< opt_named_expression_list_t > ();
        break;

      case symbol_kind::S_argument: // argument
        yylhs.value.emplace< opt_named_expression_t > ();
        break;

      case symbol_kind::S_157_parameter_decl: // parameter-decl
        yylhs.value.emplace< parameter > ();
        break;

      case symbol_kind::S_156_parameter_default_value_opt: // parameter-default-value-opt
        yylhs.value.emplace< parameter::default_spec > ();
        break;

      case symbol_kind::S_153_parameter_list_opt: // parameter-list-opt
      case symbol_kind::S_154_parameter_list: // parameter-list
        yylhs.value.emplace< parameter_list_t > ();
        break;

      case symbol_kind::S_172_reference_expression: // reference-expression
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
      case symbol_kind::S_CONSTEVAL: // "consteval modifier"
      case symbol_kind::S_RUNTIME: // "runctime modifier"
      case symbol_kind::S_PROBE: // PROBE
        yylhs.value.emplace< resource_location > ();
        break;

      case symbol_kind::S_OPERATOR_TERM: // OPERATOR_TERM
        yylhs.value.emplace< sonia::string_view > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_124_finished_statement: // finished-statement
      case symbol_kind::S_126_generic_statement: // generic-statement
      case symbol_kind::S_127_infunction_statement: // infunction-statement
        yylhs.value.emplace< statement > ();
        break;

      case symbol_kind::S_statement_any: // statement_any
      case symbol_kind::S_115_finished_statement_any: // finished-statement-any
      case symbol_kind::S_120_infunction_statement_any: // infunction-statement-any
      case symbol_kind::S_121_finished_infunction_statement_any: // finished-infunction-statement-any
      case symbol_kind::S_122_function_body: // function-body
      case symbol_kind::S_123_braced_statements: // braced-statements
      case symbol_kind::S_125_infunction_statement_set: // infunction-statement-set
        yylhs.value.emplace< statement_list_t > ();
        break;

      case symbol_kind::S_133_fn_prefix_decl: // fn-prefix-decl
        yylhs.value.emplace< std::pair<resource_location, fn_kind> > ();
        break;

      case symbol_kind::S_179_lambda_start_decl: // lambda-start-decl
        yylhs.value.emplace< std::pair<resource_location, lambda> > ();
        break;

      case symbol_kind::S_158_constraint_expression_specified_mod: // constraint-expression-specified-mod
      case symbol_kind::S_160_constraint_expression_mod: // constraint-expression-mod
        yylhs.value.emplace< std::pair<resource_location, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_159_constraint_expression_specified: // constraint-expression-specified
      case symbol_kind::S_161_constraint_expression: // constraint-expression
        yylhs.value.emplace< std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_166_pattern_mod: // pattern-mod
      case symbol_kind::S_167_pattern_sfx: // pattern-sfx
        yylhs.value.emplace< std::pair<syntax_pattern, parameter_constraint_modifier_t> > ();
        break;

      case symbol_kind::S_149_field_list_opt: // field-list-opt
      case symbol_kind::S_150_field_list: // field-list
        yylhs.value.emplace< std::vector<field> > ();
        break;

      case symbol_kind::S_139_case_list_opt: // case-list-opt
      case symbol_kind::S_140_case_list: // case-list
        yylhs.value.emplace< std::vector<identifier> > ();
        break;

      case symbol_kind::S_142_struct_decl: // struct-decl
        yylhs.value.emplace< struct_decl > ();
        break;

      case symbol_kind::S_169_concept_expression: // concept-expression
      case symbol_kind::S_173_any_reference_expression: // any-reference-expression
      case symbol_kind::S_174_syntax_expression_base: // syntax-expression-base
      case symbol_kind::S_175_grouped_expression: // grouped-expression
      case symbol_kind::S_176_new_expression: // new-expression
      case symbol_kind::S_177_call_expression: // call-expression
      case symbol_kind::S_178_syntax_expression: // syntax-expression
      case symbol_kind::S_180_lambda_expression: // lambda-expression
      case symbol_kind::S_183_compound_expression: // compound-expression
      case symbol_kind::S_184_type_expr: // type-expr
        yylhs.value.emplace< syntax_expression > ();
        break;

      case symbol_kind::S_136_fn_requirement_opt: // fn-requirement-opt
        yylhs.value.emplace< syntax_expression const* > ();
        break;

      case symbol_kind::S_144_expression_list: // expression-list
      case symbol_kind::S_170_concept_expression_list_opt: // concept-expression-list-opt
      case symbol_kind::S_171_concept_expression_list: // concept-expression-list
        yylhs.value.emplace< syntax_expression_list_t > ();
        break;

      case symbol_kind::S_pattern: // pattern
        yylhs.value.emplace< syntax_pattern > ();
        break;

      case symbol_kind::S_164_pattern_field_sfx: // pattern-field-sfx
      case symbol_kind::S_165_pattern_field: // pattern-field
        yylhs.value.emplace< syntax_pattern::field > ();
        break;

      case symbol_kind::S_subpatterns: // subpatterns
      case symbol_kind::S_163_pattern_list: // pattern-list
        yylhs.value.emplace< syntax_pattern_field_list_t > ();
        break;

      case symbol_kind::S_143_using_decl: // using-decl
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
#line 340 "annium.y"
                                 { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3030 "annium.tab.cpp"
    break;

  case 3: // begin: finished-statement-any "end of file"
#line 341 "annium.y"
                                      { ctx.set_root_statements(std::move(yystack_[1].value.as < statement_list_t > ())); }
#line 3036 "annium.tab.cpp"
    break;

  case 4: // statement_any: %empty
#line 346 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3042 "annium.tab.cpp"
    break;

  case 5: // statement_any: statement
#line 348 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3048 "annium.tab.cpp"
    break;

  case 6: // statement_any: finished-statement-any statement
#line 350 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3054 "annium.tab.cpp"
    break;

  case 7: // finished-statement-any: finished-statement
#line 367 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3060 "annium.tab.cpp"
    break;

  case 8: // finished-statement-any: finished-statement-any "`;`"
#line 368 "annium.y"
                                                { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3066 "annium.tab.cpp"
    break;

  case 9: // finished-statement-any: finished-statement-any finished-statement
#line 370 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ()));  }
#line 3072 "annium.tab.cpp"
    break;

  case 10: // finished-statement-any: statement_any "`;`"
#line 372 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3078 "annium.tab.cpp"
    break;

  case 11: // statement: EXTERN VAR identifier "`:`" type-expr
#line 377 "annium.y"
        { yylhs.value.as < statement > () = statement{ extern_var{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .type = std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3084 "annium.tab.cpp"
    break;

  case 12: // statement: EXTERN "`fn`" fn-decl
#line 379 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < fn_pure > ()) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3090 "annium.tab.cpp"
    break;

  case 13: // statement: INCLUDE STRING
#line 381 "annium.y"
        { yylhs.value.as < statement > () = statement{ include_decl{ ctx.make_string_view(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) } }; }
#line 3096 "annium.tab.cpp"
    break;

  case 14: // statement: generic-statement
#line 383 "annium.y"
        { yylhs.value.as < statement > () = std::move(yystack_[0].value.as < statement > ()); }
#line 3102 "annium.tab.cpp"
    break;

  case 15: // statement: STRUCT struct-decl
#line 385 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < struct_decl > ()) }; }
#line 3108 "annium.tab.cpp"
    break;

  case 16: // let-decl: let-decl-start-with-opt-type
#line 389 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3114 "annium.tab.cpp"
    break;

  case 17: // let-decl: let-decl-start-with-opt-type "`=`" pack-expression
#line 391 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().expressions = ctx.make_array<opt_named_expression_t>(yystack_[0].value.as < opt_named_expression_list_t > ()); yylhs.value.as < let_statement > ().assign_location = std::move(yystack_[1].value.as < resource_location > ()); }
#line 3120 "annium.tab.cpp"
    break;

  case 18: // let-decl-start: identifier
#line 396 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = false }; }
#line 3126 "annium.tab.cpp"
    break;

  case 19: // let-decl-start: "weak modifier" identifier
#line 398 "annium.y"
        { yylhs.value.as < let_statement > () = let_statement{ .aname = std::move(yystack_[0].value.as < annotated_identifier > ()), .weakness = true }; }
#line 3132 "annium.tab.cpp"
    break;

  case 20: // let-decl-start-with-opt-type: let-decl-start
#line 402 "annium.y"
      { yylhs.value.as < let_statement > () = yystack_[0].value.as < let_statement > (); }
#line 3138 "annium.tab.cpp"
    break;

  case 21: // let-decl-start-with-opt-type: let-decl-start "`:`" type-expr
#line 404 "annium.y"
        { yylhs.value.as < let_statement > () = std::move(yystack_[2].value.as < let_statement > ()); yylhs.value.as < let_statement > ().type = std::move(yystack_[0].value.as < syntax_expression > ()); }
#line 3144 "annium.tab.cpp"
    break;

  case 22: // infunction-statement-any: %empty
#line 409 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{}; }
#line 3150 "annium.tab.cpp"
    break;

  case 23: // infunction-statement-any: infunction-statement
#line 411 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3156 "annium.tab.cpp"
    break;

  case 24: // infunction-statement-any: finished-infunction-statement-any infunction-statement
#line 413 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3162 "annium.tab.cpp"
    break;

  case 25: // finished-infunction-statement-any: finished-statement
#line 418 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ std::move(yystack_[0].value.as < statement > ()) }; }
#line 3168 "annium.tab.cpp"
    break;

  case 26: // finished-infunction-statement-any: finished-infunction-statement-any "`;`"
#line 419 "annium.y"
                                                           { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3174 "annium.tab.cpp"
    break;

  case 27: // finished-infunction-statement-any: finished-infunction-statement-any finished-statement
#line 421 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); yylhs.value.as < statement_list_t > ().emplace_back(std::move(yystack_[0].value.as < statement > ())); }
#line 3180 "annium.tab.cpp"
    break;

  case 28: // finished-infunction-statement-any: infunction-statement-any "`;`"
#line 423 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); }
#line 3186 "annium.tab.cpp"
    break;

  case 29: // function-body: braced-statements
#line 428 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3192 "annium.tab.cpp"
    break;

  case 30: // function-body: "`=>`" syntax-expression
#line 432 "annium.y"
        { yylhs.value.as < statement_list_t > () = statement_list_t{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } }; }
#line 3198 "annium.tab.cpp"
    break;

  case 31: // braced-statements: "`{`" infunction-statement-set "`}`"
#line 443 "annium.y"
        { yylhs.value.as < statement_list_t > () = std::move(yystack_[1].value.as < statement_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3204 "annium.tab.cpp"
    break;

  case 32: // finished-statement: "`while`" syntax-expression braced-statements
#line 448 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[1].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3210 "annium.tab.cpp"
    break;

  case 33: // finished-statement: "`while`" syntax-expression "`;`" syntax-expression braced-statements
#line 450 "annium.y"
        { yylhs.value.as < statement > () = statement{ while_decl{ std::move(yystack_[3].value.as < syntax_expression > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()), std::move(yystack_[1].value.as < syntax_expression > ()) } }; }
#line 3216 "annium.tab.cpp"
    break;

  case 34: // finished-statement: "`for`" reference-expression "`in`" syntax-expression braced-statements
#line 452 "annium.y"
        { yylhs.value.as < statement > () = statement{ for_statement{ .iter = std::move(yystack_[3].value.as < reference_expression > ()), .coll = std::move(yystack_[1].value.as < syntax_expression > ()), .body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3222 "annium.tab.cpp"
    break;

  case 35: // finished-statement: "`if`" syntax-expression braced-statements
#line 454 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[1].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3228 "annium.tab.cpp"
    break;

  case 36: // finished-statement: "`if`" syntax-expression braced-statements "`else`" braced-statements
#line 456 "annium.y"
        { yylhs.value.as < statement > () = statement{ if_decl{ .condition = std::move(yystack_[3].value.as < syntax_expression > ()), .true_body = ctx.make_array<statement>(yystack_[2].value.as < statement_list_t > ()), .false_body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 3234 "annium.tab.cpp"
    break;

  case 37: // finished-statement: fn-prefix-decl fn-decl braced-statements
#line 458 "annium.y"
        {   
            yystack_[1].value.as < fn_pure > ().location = std::move(get<0>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[1].value.as < fn_pure > ().kind = get<1>(yystack_[2].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[1].value.as < fn_pure > ()), ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } };
        }
#line 3244 "annium.tab.cpp"
    break;

  case 38: // finished-statement: ENUM enum-decl
#line 468 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < enum_decl > ()) }; }
#line 3250 "annium.tab.cpp"
    break;

  case 39: // infunction-statement-set: infunction-statement-any
#line 472 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3256 "annium.tab.cpp"
    break;

  case 40: // infunction-statement-set: finished-infunction-statement-any
#line 473 "annium.y"
      { yylhs.value.as < statement_list_t > () = yystack_[0].value.as < statement_list_t > (); }
#line 3262 "annium.tab.cpp"
    break;

  case 41: // generic-statement: LET let-decl
#line 478 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < let_statement > ()) }; }
#line 3268 "annium.tab.cpp"
    break;

  case 42: // generic-statement: "`typefn`" fn-start-decl
#line 480 "annium.y"
        { yylhs.value.as < statement > () = statement{ typefn_decl{ std::move(yystack_[0].value.as < fn_pure > ()) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3274 "annium.tab.cpp"
    break;

  case 43: // generic-statement: fn-prefix-decl fn-decl "`=>`" syntax-expression
#line 482 "annium.y"
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } } };
            yystack_[2].value.as < fn_pure > ().location = std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()));
            yystack_[2].value.as < fn_pure > ().kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ());
            yylhs.value.as < statement > () = statement{ fn_decl{ std::move(yystack_[2].value.as < fn_pure > ()), ctx.make_array<statement>(return_stmt) } };
        }
#line 3285 "annium.tab.cpp"
    break;

  case 44: // generic-statement: USING using-decl
#line 489 "annium.y"
        { yylhs.value.as < statement > () = statement{ std::move(yystack_[0].value.as < using_decl > ()) }; }
#line 3291 "annium.tab.cpp"
    break;

  case 45: // generic-statement: compound-expression
#line 491 "annium.y"
        { yylhs.value.as < statement > () = statement{ expression_statement{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 3297 "annium.tab.cpp"
    break;

  case 46: // generic-statement: syntax-expression "`=`" syntax-expression
#line 493 "annium.y"
        { 
            yylhs.value.as < statement > () = statement{ expression_statement{ syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } } } };
        }
#line 3306 "annium.tab.cpp"
    break;

  case 47: // infunction-statement: generic-statement
#line 500 "annium.y"
      { yylhs.value.as < statement > () = yystack_[0].value.as < statement > (); }
#line 3312 "annium.tab.cpp"
    break;

  case 48: // infunction-statement: "`break`"
#line 502 "annium.y"
        { yylhs.value.as < statement > () = statement{ break_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3318 "annium.tab.cpp"
    break;

  case 49: // infunction-statement: "`continue`"
#line 504 "annium.y"
        { yylhs.value.as < statement > () = statement{ continue_statement{ std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3324 "annium.tab.cpp"
    break;

  case 50: // infunction-statement: "`return`"
#line 506 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .location = std::move(yystack_[0].value.as < resource_location > ()) } }; }
#line 3330 "annium.tab.cpp"
    break;

  case 51: // infunction-statement: "`return`" syntax-expression
#line 508 "annium.y"
        { yylhs.value.as < statement > () = statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3336 "annium.tab.cpp"
    break;

  case 52: // infunction-statement: "`yield`" syntax-expression
#line 510 "annium.y"
        { yylhs.value.as < statement > () = statement{ yield_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(yystack_[1].value.as < resource_location > ()) } }; }
#line 3342 "annium.tab.cpp"
    break;

  case 53: // identifier: IDENTIFIER
#line 515 "annium.y"
      { yylhs.value.as < annotated_identifier > () = ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())); }
#line 3348 "annium.tab.cpp"
    break;

  case 54: // internal-identifier: CONTEXT_IDENTIFIER
#line 523 "annium.y"
        { yylhs.value.as < context_identifier > () = context_identifier { ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ())) }; }
#line 3354 "annium.tab.cpp"
    break;

  case 55: // qname: "`::`" identifier
#line 538 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3360 "annium.tab.cpp"
    break;

  case 56: // qname: identifier
#line 540 "annium.y"
        { yylhs.value.as < annotated_qname > () = annotated_qname{ qname{yystack_[0].value.as < annotated_identifier > ().value, false}, std::move(yystack_[0].value.as < annotated_identifier > ().location) }; }
#line 3366 "annium.tab.cpp"
    break;

  case 57: // qname: qname "`::`" identifier
#line 542 "annium.y"
        { yylhs.value.as < annotated_qname > () = std::move(yystack_[2].value.as < annotated_qname > ()); yylhs.value.as < annotated_qname > ().value.append(std::move(yystack_[0].value.as < annotated_identifier > ().value)); }
#line 3372 "annium.tab.cpp"
    break;

  case 58: // fn-kind: INLINE
#line 547 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::INLINE; }
#line 3378 "annium.tab.cpp"
    break;

  case 59: // fn-kind: VIABLE
#line 548 "annium.y"
             { yylhs.value.as < fn_kind > () = fn_kind::VIABLE; }
#line 3384 "annium.tab.cpp"
    break;

  case 60: // fn-kind-set: fn-kind
#line 552 "annium.y"
                    { yylhs.value.as < fn_kind > () = yystack_[0].value.as < fn_kind > (); }
#line 3390 "annium.tab.cpp"
    break;

  case 61: // fn-kind-set: fn-kind-set fn-kind
#line 553 "annium.y"
                                     { yylhs.value.as < fn_kind > () = yystack_[1].value.as < fn_kind > () | yystack_[0].value.as < fn_kind > (); }
#line 3396 "annium.tab.cpp"
    break;

  case 62: // fn-prefix-decl: "`fn`"
#line 558 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), fn_kind::DEFAULT }; }
#line 3402 "annium.tab.cpp"
    break;

  case 63: // fn-prefix-decl: fn-kind-set "`fn`"
#line 560 "annium.y"
        { yylhs.value.as < std::pair<resource_location, fn_kind> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), yystack_[1].value.as < fn_kind > () }; }
#line 3408 "annium.tab.cpp"
    break;

  case 64: // fn-name: qname
#line 565 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())); }
#line 3414 "annium.tab.cpp"
    break;

  case 65: // fn-name: "`new`"
#line 567 "annium.y"
        { yylhs.value.as < annium::annotated_qname_view > () = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move(yystack_[0].value.as < resource_location > ()) }); }
#line 3420 "annium.tab.cpp"
    break;

  case 66: // fn-start-decl: fn-name "`(`" parameter-list-opt "`)`" fn-requirement-opt
#line 572 "annium.y"
        { yylhs.value.as < fn_pure > () = fn_pure{ .name = yystack_[4].value.as < annium::annotated_qname_view > ().value, .location = std::move(yystack_[4].value.as < annium::annotated_qname_view > ().location), .parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ()), .requirement = std::move(yystack_[0].value.as < syntax_expression const* > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 3426 "annium.tab.cpp"
    break;

  case 67: // fn-requirement-opt: %empty
#line 589 "annium.y"
             { yylhs.value.as < syntax_expression const* > () = nullptr; }
#line 3432 "annium.tab.cpp"
    break;

  case 68: // fn-requirement-opt: REQUIRES "`(`" syntax-expression "`)`"
#line 592 "annium.y"
        { yylhs.value.as < syntax_expression const* > () = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3438 "annium.tab.cpp"
    break;

  case 69: // fn-decl: fn-start-decl
#line 603 "annium.y"
      { yylhs.value.as < fn_pure > () = yystack_[0].value.as < fn_pure > (); }
#line 3444 "annium.tab.cpp"
    break;

  case 70: // fn-decl: fn-start-decl "`->`" type-expr
#line 605 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3450 "annium.tab.cpp"
    break;

  case 71: // fn-decl: fn-start-decl "`~>`" pattern
#line 607 "annium.y"
        { yylhs.value.as < fn_pure > () = yystack_[2].value.as < fn_pure > (); yylhs.value.as < fn_pure > ().result = ctx.make<syntax_pattern>(std::move(yystack_[0].value.as < syntax_pattern > ())); }
#line 3456 "annium.tab.cpp"
    break;

  case 72: // enum-decl: qname "`{`" case-list-opt "`}`"
#line 614 "annium.y"
        { yylhs.value.as < enum_decl > () = enum_decl{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ())), ctx.make_array<identifier>(yystack_[1].value.as < std::vector<identifier> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3462 "annium.tab.cpp"
    break;

  case 73: // case-list-opt: %empty
#line 618 "annium.y"
             { yylhs.value.as < std::vector<identifier> > () = {}; }
#line 3468 "annium.tab.cpp"
    break;

  case 74: // case-list-opt: case-list
#line 619 "annium.y"
      { yylhs.value.as < std::vector<identifier> > () = yystack_[0].value.as < std::vector<identifier> > (); }
#line 3474 "annium.tab.cpp"
    break;

  case 75: // case-list: case-decl
#line 624 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::vector<identifier>{ std::move(yystack_[0].value.as < identifier > ()) }; }
#line 3480 "annium.tab.cpp"
    break;

  case 76: // case-list: case-list "," case-decl
#line 626 "annium.y"
        { yylhs.value.as < std::vector<identifier> > () = std::move(yystack_[2].value.as < std::vector<identifier> > ()); yylhs.value.as < std::vector<identifier> > ().emplace_back(std::move(yystack_[0].value.as < identifier > ())); }
#line 3486 "annium.tab.cpp"
    break;

  case 77: // case-decl: identifier
#line 631 "annium.y"
        { yylhs.value.as < identifier > () = yystack_[0].value.as < annotated_identifier > ().value; }
#line 3492 "annium.tab.cpp"
    break;

  case 78: // struct-decl: qname "`=>`" "`(`" field-list-opt "`)`"
#line 637 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[4].value.as < annotated_qname > ())), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3498 "annium.tab.cpp"
    break;

  case 79: // struct-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" "`(`" field-list-opt "`)`"
#line 639 "annium.y"
        { yylhs.value.as < struct_decl > () = struct_decl{ .name = ctx.make_qname_view(std::move(yystack_[7].value.as < annotated_qname > ())), .parameters = ctx.make_array<parameter>(yystack_[5].value.as < parameter_list_t > ()), .body = ctx.make_array<field>(yystack_[1].value.as < std::vector<field> > ()) }; IGNORE_TERM(yystack_[6].value.as < resource_location > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3504 "annium.tab.cpp"
    break;

  case 80: // using-decl: qname "`=>`" syntax-expression
#line 662 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ().value)), .location = std::move(yystack_[2].value.as < annotated_qname > ().location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
#line 3514 "annium.tab.cpp"
    break;

  case 81: // using-decl: qname "`(`" parameter-list-opt "`)`" "`=>`" syntax-expression
#line 668 "annium.y"
        {
            auto loc = yystack_[0].value.as < syntax_expression > ().location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move(yystack_[0].value.as < syntax_expression > ()), .location = std::move(loc) } } };
            yylhs.value.as < using_decl > () = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move(yystack_[5].value.as < annotated_qname > ().value)), .location = std::move(yystack_[5].value.as < annotated_qname > ().location), .parameters = ctx.make_array<parameter>(yystack_[3].value.as < parameter_list_t > ()), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM(yystack_[4].value.as < resource_location > ());
        }
#line 3525 "annium.tab.cpp"
    break;

  case 82: // expression-list: syntax-expression
#line 685 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ yystack_[0].value.as < syntax_expression > () }; }
#line 3531 "annium.tab.cpp"
    break;

  case 83: // expression-list: expression-list "," syntax-expression
#line 687 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[2].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 3537 "annium.tab.cpp"
    break;

  case 84: // argument-list-opt: %empty
#line 692 "annium.y"
              { yylhs.value.as < opt_named_expression_list_t > () = {}; }
#line 3543 "annium.tab.cpp"
    break;

  case 85: // argument-list-opt: argument-list
#line 693 "annium.y"
      { yylhs.value.as < opt_named_expression_list_t > () = yystack_[0].value.as < opt_named_expression_list_t > (); }
#line 3549 "annium.tab.cpp"
    break;

  case 86: // argument-list: argument
#line 698 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ std::move(yystack_[0].value.as < opt_named_expression_t > ()) }; }
#line 3555 "annium.tab.cpp"
    break;

  case 87: // argument-list: argument-list "," argument
#line 700 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ()); yylhs.value.as < opt_named_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < opt_named_expression_t > ())); }
#line 3561 "annium.tab.cpp"
    break;

  case 88: // argument: argument-name syntax-expression
#line 705 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[1].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3567 "annium.tab.cpp"
    break;

  case 89: // argument: syntax-expression
#line 707 "annium.y"
        { yylhs.value.as < opt_named_expression_t > () = opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3573 "annium.tab.cpp"
    break;

  case 90: // argument-name: identifier "`=`"
#line 712 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3579 "annium.tab.cpp"
    break;

  case 91: // argument-name: identifier "`:`"
#line 714 "annium.y"
        { yylhs.value.as < annotated_identifier > () = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3585 "annium.tab.cpp"
    break;

  case 92: // field-list-opt: %empty
#line 719 "annium.y"
              { yylhs.value.as < std::vector<field> > () = {}; }
#line 3591 "annium.tab.cpp"
    break;

  case 93: // field-list-opt: field-list
#line 720 "annium.y"
      { yylhs.value.as < std::vector<field> > () = yystack_[0].value.as < std::vector<field> > (); }
#line 3597 "annium.tab.cpp"
    break;

  case 94: // field-list: field
#line 725 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::vector<field>{ std::move(yystack_[0].value.as < field > ()) }; }
#line 3603 "annium.tab.cpp"
    break;

  case 95: // field-list: field-list "," field
#line 727 "annium.y"
        { yylhs.value.as < std::vector<field> > () = std::move(yystack_[2].value.as < std::vector<field> > ()); yylhs.value.as < std::vector<field> > ().emplace_back(std::move(yystack_[0].value.as < field > ())); }
#line 3609 "annium.tab.cpp"
    break;

  case 96: // field-default-value-opt: %empty
#line 731 "annium.y"
             { yylhs.value.as < field::default_spec > () = required_t{}; }
#line 3615 "annium.tab.cpp"
    break;

  case 97: // field-default-value-opt: "`=`" syntax-expression
#line 732 "annium.y"
                                      { yylhs.value.as < field::default_spec > () = std::move(yystack_[0].value.as < syntax_expression > ()); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3621 "annium.tab.cpp"
    break;

  case 98: // field: identifier "`:`" type-expr field-default-value-opt
#line 737 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[3].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move(yystack_[1].value.as < syntax_expression > ()), .value = std::move(yystack_[0].value.as < field::default_spec > ()) }; }
#line 3627 "annium.tab.cpp"
    break;

  case 99: // field: identifier "`=>`" syntax-expression
#line 739 "annium.y"
        { yylhs.value.as < field > () = field{ .name = std::move(yystack_[2].value.as < annotated_identifier > ()), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 3633 "annium.tab.cpp"
    break;

  case 100: // parameter-list-opt: %empty
#line 745 "annium.y"
              { yylhs.value.as < parameter_list_t > () = {}; }
#line 3639 "annium.tab.cpp"
    break;

  case 101: // parameter-list-opt: parameter-list
#line 746 "annium.y"
       { yylhs.value.as < parameter_list_t > () = yystack_[0].value.as < parameter_list_t > (); }
#line 3645 "annium.tab.cpp"
    break;

  case 102: // parameter-list: parameter-decl
#line 751 "annium.y"
        { yylhs.value.as < parameter_list_t > () = parameter_list_t{ std::move(yystack_[0].value.as < parameter > ()) }; }
#line 3651 "annium.tab.cpp"
    break;

  case 103: // parameter-list: parameter-list "," parameter-decl
#line 753 "annium.y"
        { yylhs.value.as < parameter_list_t > () = std::move(yystack_[2].value.as < parameter_list_t > ()); yylhs.value.as < parameter_list_t > ().emplace_back(std::move(yystack_[0].value.as < parameter > ())); }
#line 3657 "annium.tab.cpp"
    break;

  case 104: // internal-identifier-opt: %empty
#line 757 "annium.y"
             { yylhs.value.as < context_identifier > () = context_identifier{}; }
#line 3663 "annium.tab.cpp"
    break;

  case 105: // internal-identifier-opt: internal-identifier
#line 758 "annium.y"
                                 { yylhs.value.as < context_identifier > () = std::move(yystack_[0].value.as < context_identifier > ()); }
#line 3669 "annium.tab.cpp"
    break;

  case 106: // parameter-default-value-opt: %empty
#line 762 "annium.y"
             { yylhs.value.as < parameter::default_spec > () = required_t{}; }
#line 3675 "annium.tab.cpp"
    break;

  case 107: // parameter-default-value-opt: "`=`" syntax-expression
#line 763 "annium.y"
                                      { yylhs.value.as < parameter::default_spec > () = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())); IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3681 "annium.tab.cpp"
    break;

  case 108: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression parameter-default-value-opt
#line 769 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3687 "annium.tab.cpp"
    break;

  case 109: // parameter-decl: internal-identifier "`:`" constraint-expression parameter-default-value-opt
#line 773 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3693 "annium.tab.cpp"
    break;

  case 110: // parameter-decl: "`:`" constraint-expression parameter-default-value-opt
#line 775 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3699 "annium.tab.cpp"
    break;

  case 111: // parameter-decl: constraint-expression-specified parameter-default-value-opt
#line 779 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; }
#line 3705 "annium.tab.cpp"
    break;

  case 112: // parameter-decl: qname parameter-default-value-opt
#line 782 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[1].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3714 "annium.tab.cpp"
    break;

  case 113: // parameter-decl: qname "`...`" parameter-default-value-opt
#line 787 "annium.y"
        {
            auto constraint = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())) });
            yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic };
            IGNORE_TERM(yystack_[1].value.as < resource_location > ());
        }
#line 3724 "annium.tab.cpp"
    break;

  case 114: // parameter-decl: identifier internal-identifier-opt "`:`" pattern-mod parameter-default-value-opt
#line 795 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3730 "annium.tab.cpp"
    break;

  case 115: // parameter-decl: identifier internal-identifier-opt "`:`" concept-expression-list parameter-default-value-opt
#line 797 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
#line 3736 "annium.tab.cpp"
    break;

  case 116: // parameter-decl: identifier internal-identifier-opt "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 799 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[5].value.as < annotated_identifier > ()), std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[5].value.as < annotated_identifier > ().location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) };  }
#line 3742 "annium.tab.cpp"
    break;

  case 117: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" pattern-mod
#line 801 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3748 "annium.tab.cpp"
    break;

  case 118: // parameter-decl: identifier internal-identifier-opt "`=>`" syntax-expression
#line 804 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[3].value.as < annotated_identifier > ()), std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3754 "annium.tab.cpp"
    break;

  case 119: // parameter-decl: internal-identifier "`=>`" syntax-expression
#line 806 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
#line 3760 "annium.tab.cpp"
    break;

  case 120: // parameter-decl: internal-identifier "`:`" pattern-mod parameter-default-value-opt
#line 809 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3766 "annium.tab.cpp"
    break;

  case 121: // parameter-decl: internal-identifier "`:`" concept-expression-list parameter-default-value-opt
#line 811 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[3].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };   }
#line 3772 "annium.tab.cpp"
    break;

  case 122: // parameter-decl: internal-identifier "`:`" constraint-expression-specified-mod concept-expression-list parameter-default-value-opt
#line 813 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[4].value.as < context_identifier > ().name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[4].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3778 "annium.tab.cpp"
    break;

  case 123: // parameter-decl: "`:`" pattern-mod parameter-default-value-opt
#line 815 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3784 "annium.tab.cpp"
    break;

  case 124: // parameter-decl: pattern-mod parameter-default-value-opt
#line 817 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier = get<1>(yystack_[1].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) }; }
#line 3790 "annium.tab.cpp"
    break;

  case 125: // parameter-decl: internal-identifier concept-expression-list-opt parameter-default-value-opt
#line 825 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[2].value.as < context_identifier > ().name.location) }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3796 "annium.tab.cpp"
    break;

  case 126: // parameter-decl: "`_`" parameter-default-value-opt
#line 827 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3802 "annium.tab.cpp"
    break;

  case 127: // parameter-decl: internal-identifier "`...`" parameter-default-value-opt
#line 829 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ std::move(yystack_[2].value.as < context_identifier > ().name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3808 "annium.tab.cpp"
    break;

  case 128: // parameter-decl: "`...`" parameter-default-value-opt
#line 831 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) } } ), .default_value = std::move(yystack_[0].value.as < parameter::default_spec > ()), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::variadic }; }
#line 3814 "annium.tab.cpp"
    break;

  case 129: // parameter-decl: identifier internal-identifier-opt "`?`" "`:`" constraint-expression
#line 836 "annium.y"
        { yylhs.value.as < parameter > () = parameter{ .name = named_parameter_name{ std::move(yystack_[4].value.as < annotated_identifier > ()), std::move(yystack_[3].value.as < context_identifier > ().name) }, .constraint = std::move(get<0>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ())), .default_value = optional_t{}, .modifier = get<1>(yystack_[0].value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > ()) }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3820 "annium.tab.cpp"
    break;

  case 130: // constraint-expression-specified-mod: "constexpr modifier"
#line 842 "annium.y"
                { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::constexpr_type }; }
#line 3826 "annium.tab.cpp"
    break;

  case 131: // constraint-expression-specified-mod: "runctime modifier"
#line 843 "annium.y"
              { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < resource_location > ()), parameter_constraint_modifier_t::runtime_type }; }
#line 3832 "annium.tab.cpp"
    break;

  case 132: // constraint-expression-specified: constraint-expression-specified-mod type-expr
#line 848 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3838 "annium.tab.cpp"
    break;

  case 133: // constraint-expression-specified: constraint-expression-specified-mod type-expr "`...`"
#line 850 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3844 "annium.tab.cpp"
    break;

  case 134: // constraint-expression-specified: constraint-expression-specified-mod
#line 854 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ())) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3850 "annium.tab.cpp"
    break;

  case 135: // constraint-expression-specified: constraint-expression-specified-mod "`...`"
#line 856 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3856 "annium.tab.cpp"
    break;

  case 136: // constraint-expression-mod: %empty
#line 861 "annium.y"
        {
            location_type const& loc = yystack_[(0) - (-1)].location;
            yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
#line 3865 "annium.tab.cpp"
    break;

  case 137: // constraint-expression-mod: constraint-expression-specified-mod
#line 865 "annium.y"
      { yylhs.value.as < std::pair<resource_location, parameter_constraint_modifier_t> > () = yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > (); }
#line 3871 "annium.tab.cpp"
    break;

  case 138: // constraint-expression: constraint-expression-mod type-expr
#line 870 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < syntax_expression > ())), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3877 "annium.tab.cpp"
    break;

  case 139: // constraint-expression: constraint-expression-mod type-expr "`...`"
#line 872 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())), get<1>(yystack_[2].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3883 "annium.tab.cpp"
    break;

  case 140: // constraint-expression: constraint-expression-mod
#line 876 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) } }), get<1>(yystack_[0].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) }; }
#line 3889 "annium.tab.cpp"
    break;

  case 141: // constraint-expression: constraint-expression-mod "`...`"
#line 878 "annium.y"
        { yylhs.value.as < std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t> > () = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }), get<1>(yystack_[1].value.as < std::pair<resource_location, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::variadic }; }
#line 3895 "annium.tab.cpp"
    break;

  case 142: // subpatterns: "`(`" pattern-list "`)`"
#line 888 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[1].value.as < syntax_pattern_field_list_t > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3901 "annium.tab.cpp"
    break;

  case 143: // pattern-list: pattern-field
#line 893 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = syntax_pattern_field_list_t{ std::move(yystack_[0].value.as < syntax_pattern::field > ()) }; }
#line 3907 "annium.tab.cpp"
    break;

  case 144: // pattern-list: pattern-list "," pattern-field
#line 895 "annium.y"
        { yylhs.value.as < syntax_pattern_field_list_t > () = std::move(yystack_[2].value.as < syntax_pattern_field_list_t > ()); yylhs.value.as < syntax_pattern_field_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_pattern::field > ())); }
#line 3913 "annium.tab.cpp"
    break;

  case 145: // pattern-field-sfx: concept-expression-list-opt
#line 901 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3919 "annium.tab.cpp"
    break;

  case 146: // pattern-field-sfx: concept-expression-list-opt "`...`"
#line 903 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3925 "annium.tab.cpp"
    break;

  case 147: // pattern-field-sfx: internal-identifier concept-expression-list-opt
#line 906 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[1].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) } ) }; }
#line 3931 "annium.tab.cpp"
    break;

  case 148: // pattern-field-sfx: internal-identifier concept-expression-list-opt "`...`"
#line 908 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } ), .ellipsis = true }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 3937 "annium.tab.cpp"
    break;

  case 149: // pattern-field-sfx: "`=`" pattern-sfx
#line 912 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3943 "annium.tab.cpp"
    break;

  case 150: // pattern-field-sfx: internal-identifier "`=`" pattern-sfx
#line 915 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move(yystack_[2].value.as < context_identifier > ().name), .value = ctx.make<syntax_pattern>(std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()))), .ellipsis = has(get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()), parameter_constraint_modifier_t::variadic) }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3949 "annium.tab.cpp"
    break;

  case 151: // pattern-field: identifier pattern-field-sfx
#line 921 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < annotated_identifier > ()); }
#line 3955 "annium.tab.cpp"
    break;

  case 152: // pattern-field: "`?`" internal-identifier pattern-field-sfx
#line 924 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = std::move(yystack_[1].value.as < context_identifier > ()); IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 3961 "annium.tab.cpp"
    break;

  case 153: // pattern-field: pattern-field-sfx
#line 937 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ }; }
#line 3967 "annium.tab.cpp"
    break;

  case 154: // pattern-field: "`_`" pattern-field-sfx
#line 940 "annium.y"
        { yylhs.value.as < syntax_pattern::field > () = std::move(yystack_[0].value.as < syntax_pattern::field > ()); yylhs.value.as < syntax_pattern::field > ().name = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }; }
#line 3973 "annium.tab.cpp"
    break;

  case 155: // pattern-mod: "`~`" pattern-sfx
#line 944 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
#line 3979 "annium.tab.cpp"
    break;

  case 156: // pattern-mod: "`~`" "constexpr modifier" pattern-sfx
#line 945 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3985 "annium.tab.cpp"
    break;

  case 157: // pattern-mod: "`~`" "runctime modifier" pattern-sfx
#line 946 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3991 "annium.tab.cpp"
    break;

  case 158: // pattern-mod: "`~`" "typename modifier" pattern-sfx
#line 947 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 3997 "annium.tab.cpp"
    break;

  case 159: // pattern-mod: "`~`" "typename modifier"
#line 948 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4003 "annium.tab.cpp"
    break;

  case 160: // pattern-mod: "typename modifier" pattern-sfx
#line 949 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ())), get<1>(yystack_[0].value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > ()) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4009 "annium.tab.cpp"
    break;

  case 161: // pattern-mod: "typename modifier"
#line 950 "annium.y"
                                              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[0].value.as < resource_location > ()) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4015 "annium.tab.cpp"
    break;

  case 162: // pattern-sfx: pattern
#line 954 "annium.y"
              { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[0].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::none }; }
#line 4021 "annium.tab.cpp"
    break;

  case 163: // pattern-sfx: pattern "`...`"
#line 955 "annium.y"
                       { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ std::move(yystack_[1].value.as < syntax_pattern > ()), parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4027 "annium.tab.cpp"
    break;

  case 164: // pattern-sfx: "`...`"
#line 956 "annium.y"
               { yylhs.value.as < std::pair<syntax_pattern, parameter_constraint_modifier_t> > () = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::variadic }; IGNORE_TERM(yystack_[0].value.as < resource_location > ()); }
#line 4033 "annium.tab.cpp"
    break;

  case 165: // pattern: qname
#line 961 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ())) } }; }
#line 4039 "annium.tab.cpp"
    break;

  case 166: // pattern: qname subpatterns concept-expression-list-opt
#line 963 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move(yystack_[2].value.as < annotated_qname > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4045 "annium.tab.cpp"
    break;

  case 167: // pattern: internal-identifier concept-expression-list-opt
#line 965 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = std::move(yystack_[1].value.as < context_identifier > ()), .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4051 "annium.tab.cpp"
    break;

  case 168: // pattern: "`_`" concept-expression-list-opt
#line 967 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{ std::move(yystack_[1].value.as < resource_location > ()) }, .concepts = std::move(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4057 "annium.tab.cpp"
    break;

  case 169: // pattern: "`_`" subpatterns concept-expression-list-opt
#line 969 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move(yystack_[2].value.as < resource_location > ()) }, .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4063 "annium.tab.cpp"
    break;

  case 170: // pattern: "`(`" "`)`"
#line 971 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
#line 4069 "annium.tab.cpp"
    break;

  case 171: // pattern: "`{`" syntax-expression "`}`" concept-expression-list-opt
#line 973 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move(yystack_[2].value.as < syntax_expression > ())), .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[3].value.as < resource_location > ()); }
#line 4075 "annium.tab.cpp"
    break;

  case 172: // pattern: "`{`" syntax-expression "`}`" subpatterns concept-expression-list-opt
#line 975 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), .fields = ctx.make_array<syntax_pattern::field>(yystack_[1].value.as < syntax_pattern_field_list_t > ()) }, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; IGNORE_TERM(yystack_[4].value.as < resource_location > ()); }
#line 4081 "annium.tab.cpp"
    break;

  case 173: // pattern: concept-expression-list
#line 977 "annium.y"
        { yylhs.value.as < syntax_pattern > () = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>(yystack_[0].value.as < syntax_expression_list_t > ()) }; }
#line 4087 "annium.tab.cpp"
    break;

  case 174: // concept-expression: "`@`" qname
#line 982 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ .location = yystack_[0].value.as < annotated_qname > ().location, .value = qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4093 "annium.tab.cpp"
    break;

  case 175: // concept-expression-list-opt: %empty
#line 987 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = {}; }
#line 4099 "annium.tab.cpp"
    break;

  case 176: // concept-expression-list-opt: concept-expression-list
#line 988 "annium.y"
      { yylhs.value.as < syntax_expression_list_t > () = yystack_[0].value.as < syntax_expression_list_t > (); }
#line 4105 "annium.tab.cpp"
    break;

  case 177: // concept-expression-list: concept-expression
#line 993 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = syntax_expression_list_t{ std::move(yystack_[0].value.as < syntax_expression > ()) }; }
#line 4111 "annium.tab.cpp"
    break;

  case 178: // concept-expression-list: concept-expression-list concept-expression
#line 995 "annium.y"
        { yylhs.value.as < syntax_expression_list_t > () = std::move(yystack_[1].value.as < syntax_expression_list_t > ()); yylhs.value.as < syntax_expression_list_t > ().emplace_back(std::move(yystack_[0].value.as < syntax_expression > ())); }
#line 4117 "annium.tab.cpp"
    break;

  case 179: // reference-expression: CONTEXT_IDENTIFIER
#line 1001 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4123 "annium.tab.cpp"
    break;

  case 180: // reference-expression: qname
#line 1003 "annium.y"
        { yylhs.value.as < reference_expression > () = reference_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4129 "annium.tab.cpp"
    break;

  case 181: // any-reference-expression: RESERVED_IDENTIFIER
#line 1008 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4135 "annium.tab.cpp"
    break;

  case 182: // any-reference-expression: CONTEXT_IDENTIFIER
#line 1010 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4141 "annium.tab.cpp"
    break;

  case 183: // any-reference-expression: qname
#line 1012 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4147 "annium.tab.cpp"
    break;

  case 184: // any-reference-expression: any-reference-expression "`.`" identifier
#line 1014 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4153 "annium.tab.cpp"
    break;

  case 185: // any-reference-expression: call-expression "`.`" identifier
#line 1016 "annium.y"
         { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[2].value.as < syntax_expression > ().location, member_expression{ ctx.make<syntax_expression>(yystack_[2].value.as < syntax_expression > ()), ctx.make<syntax_expression>(yystack_[0].value.as < annotated_identifier > ().location, std::move(yystack_[0].value.as < annotated_identifier > ().value)) } }; IGNORE_TERM(yystack_[1].value.as < resource_location > ()); }
#line 4159 "annium.tab.cpp"
    break;

  case 186: // syntax-expression-base: "nil"
#line 1021 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_nil > ().location, nil_expression{ } }; }
#line 4165 "annium.tab.cpp"
    break;

  case 187: // syntax-expression-base: "true"
#line 1023 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4171 "annium.tab.cpp"
    break;

  case 188: // syntax-expression-base: "false"
#line 1025 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_bool > ().location, yystack_[0].value.as < annotated_bool > ().value }; }
#line 4177 "annium.tab.cpp"
    break;

  case 189: // syntax-expression-base: INTEGER
#line 1027 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_integer_view > ().location, std::move(yystack_[0].value.as < annium::annotated_integer_view > ().value) }; }
#line 4183 "annium.tab.cpp"
    break;

  case 190: // syntax-expression-base: DECIMAL
#line 1029 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4189 "annium.tab.cpp"
    break;

  case 191: // syntax-expression-base: DECIMAL_S
#line 1031 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_decimal_view > ().location, std::move(yystack_[0].value.as < annium::annotated_decimal_view > ().value) }; }
#line 4195 "annium.tab.cpp"
    break;

  case 192: // syntax-expression-base: INTEGER_INDEX
#line 1033 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_decimal_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4201 "annium.tab.cpp"
    break;

  case 193: // syntax-expression-base: STRING
#line 1035 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_string_view(yystack_[0].value.as < annium::annotated_string_view > ().value) }; }
#line 4207 "annium.tab.cpp"
    break;

  case 194: // syntax-expression-base: CT_IDENTIFIER
#line 1037 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[0].value.as < annotated_identifier > ().location, name_reference_expression{ std::move(yystack_[0].value.as < annotated_identifier > ().value) } }; }
#line 4213 "annium.tab.cpp"
    break;

  case 195: // syntax-expression-base: any-reference-expression
#line 1038 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4219 "annium.tab.cpp"
    break;

  case 196: // syntax-expression-base: "`(`" "`)`"
#line 1040 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4225 "annium.tab.cpp"
    break;

  case 197: // syntax-expression-base: "`(`" "`:`" syntax-expression "`)`"
#line 1042 "annium.y"
        {
            // one element tuple
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[3].value.as < resource_location > (), function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move(yystack_[1].value.as < syntax_expression > ()) }), 1 } } };
        }
#line 4234 "annium.tab.cpp"
    break;

  case 198: // syntax-expression-base: "`[`" expression-list "`]`"
#line 1048 "annium.y"
        { 
            if (yystack_[1].value.as < syntax_expression_list_t > ().size() == 1) {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression_list_t > ().front())) } };
            } else {
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } };
            }
        }
#line 4246 "annium.tab.cpp"
    break;

  case 199: // syntax-expression-base: "`[`" braced-statements "`]`"
#line 1056 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_with_body_expression{ ctx.make_array<statement>(yystack_[1].value.as < statement_list_t > ()) } }; }
#line 4252 "annium.tab.cpp"
    break;

  case 200: // syntax-expression-base: "`[[`" expression-list "`]]`"
#line 1058 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), array_expression{ ctx.make_array<syntax_expression>(yystack_[1].value.as < syntax_expression_list_t > ()) } }; }
#line 4258 "annium.tab.cpp"
    break;

  case 201: // syntax-expression-base: syntax-expression "`[`" syntax-expression "`]`"
#line 1060 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4264 "annium.tab.cpp"
    break;

  case 202: // syntax-expression-base: PROBE braced-statements
#line 1062 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), probe_expression{ ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ()) } }; }
#line 4270 "annium.tab.cpp"
    break;

  case 203: // syntax-expression-base: "`.`" identifier
#line 1064 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), std::move(yystack_[0].value.as < annotated_identifier > ().value) }; }
#line 4276 "annium.tab.cpp"
    break;

  case 204: // syntax-expression-base: syntax-expression INTEGER_INDEX
#line 1071 "annium.y"
        {
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[1].value.as < syntax_expression > ().location, member_expression{ 
                ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())),
                ctx.make<syntax_expression>(yystack_[0].value.as < annium::annotated_string_view > ().location, ctx.make_integer_view(yystack_[0].value.as < annium::annotated_string_view > ().value.substr(1))) } };
        }
#line 4286 "annium.tab.cpp"
    break;

  case 205: // syntax-expression-base: "`-`" syntax-expression
#line 1078 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4292 "annium.tab.cpp"
    break;

  case 206: // syntax-expression-base: "`!`" syntax-expression
#line 1080 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4298 "annium.tab.cpp"
    break;

  case 207: // syntax-expression-base: "`*`" syntax-expression
#line 1082 "annium.y"
                { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[0].value.as < syntax_expression > ())), 1 } } }; }
#line 4304 "annium.tab.cpp"
    break;

  case 208: // syntax-expression-base: syntax-expression "`+`" syntax-expression
#line 1087 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4310 "annium.tab.cpp"
    break;

  case 209: // syntax-expression-base: syntax-expression "`-`" syntax-expression
#line 1089 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4316 "annium.tab.cpp"
    break;

  case 210: // syntax-expression-base: syntax-expression "`==`" syntax-expression
#line 1093 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4322 "annium.tab.cpp"
    break;

  case 211: // syntax-expression-base: syntax-expression "`!=`" syntax-expression
#line 1095 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4328 "annium.tab.cpp"
    break;

  case 212: // syntax-expression-base: syntax-expression "`..`" syntax-expression
#line 1097 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4334 "annium.tab.cpp"
    break;

  case 213: // syntax-expression-base: syntax-expression "`&`" syntax-expression
#line 1100 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4340 "annium.tab.cpp"
    break;

  case 214: // syntax-expression-base: syntax-expression "`|`" syntax-expression
#line 1104 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4346 "annium.tab.cpp"
    break;

  case 215: // syntax-expression-base: syntax-expression "`&&`" syntax-expression
#line 1107 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4352 "annium.tab.cpp"
    break;

  case 216: // syntax-expression-base: syntax-expression "`||`" syntax-expression
#line 1110 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4358 "annium.tab.cpp"
    break;

  case 217: // syntax-expression-base: syntax-expression "`->`" type-expr
#line 1112 "annium.y"
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
#line 4373 "annium.tab.cpp"
    break;

  case 218: // grouped-expression: "`(`" pack-expression "`)`"
#line 1142 "annium.y"
        {
            if (yystack_[1].value.as < opt_named_expression_list_t > ().size() == 1 && !yystack_[1].value.as < opt_named_expression_list_t > ().front().has_name()) { // single unnamed expression => extract
                yylhs.value.as < syntax_expression > () = std::move(yystack_[1].value.as < opt_named_expression_list_t > ().front().value());
            } else {
                BOOST_ASSERT(!yystack_[1].value.as < opt_named_expression_list_t > ().empty());
                yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ nullptr, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } };
            }
        }
#line 4386 "annium.tab.cpp"
    break;

  case 219: // new-expression: "`new`" qname
#line 1155 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) }) } }; }
#line 4392 "annium.tab.cpp"
    break;

  case 220: // new-expression: "`new`" qname "`(`" argument-list-opt "`)`"
#line 1159 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[4].value.as < resource_location > ()), new_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[3].value.as < annotated_qname > ().value)) }), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4398 "annium.tab.cpp"
    break;

  case 221: // call-expression: any-reference-expression "`(`" pack-expression-opt "`)`"
#line 1166 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4404 "annium.tab.cpp"
    break;

  case 222: // call-expression: call-expression "`(`" pack-expression "`)`"
#line 1168 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4410 "annium.tab.cpp"
    break;

  case 223: // call-expression: grouped-expression "`(`" pack-expression-opt "`)`"
#line 1170 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), function_call{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; }
#line 4416 "annium.tab.cpp"
    break;

  case 224: // syntax-expression: syntax-expression-base
#line 1174 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4422 "annium.tab.cpp"
    break;

  case 225: // syntax-expression: new-expression
#line 1175 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4428 "annium.tab.cpp"
    break;

  case 226: // syntax-expression: compound-expression
#line 1176 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4434 "annium.tab.cpp"
    break;

  case 227: // syntax-expression: lambda-expression
#line 1177 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4440 "annium.tab.cpp"
    break;

  case 228: // syntax-expression: grouped-expression
#line 1178 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4446 "annium.tab.cpp"
    break;

  case 229: // lambda-start-decl: fn-prefix-decl
#line 1184 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[0].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE } } }; }
#line 4452 "annium.tab.cpp"
    break;

  case 230: // lambda-start-decl: fn-prefix-decl "`[`" pack-expression-opt "`]`"
#line 1186 "annium.y"
        { yylhs.value.as < std::pair<resource_location, lambda> > () = std::pair{ std::move(get<0>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ())), lambda{ fn_pure{ .result = nullptr, .kind = get<1>(yystack_[3].value.as < std::pair<resource_location, fn_kind> > ()) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>(yystack_[1].value.as < opt_named_expression_list_t > ()) } }; IGNORE_TERM(yystack_[2].value.as < resource_location > ()); }
#line 4458 "annium.tab.cpp"
    break;

  case 231: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" function-body
#line 1191 "annium.y"
        { 
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[2].value.as < parameter_list_t > ());
            yystack_[4].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[4].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[4].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[3].value.as < resource_location > ());
        }
#line 4469 "annium.tab.cpp"
    break;

  case 232: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`->`" type-expr function-body
#line 1198 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4481 "annium.tab.cpp"
    break;

  case 233: // lambda-expression: lambda-start-decl "`(`" parameter-list-opt "`)`" "`~>`" pattern function-body
#line 1206 "annium.y"
        {
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.parameters = ctx.make_array<parameter>(yystack_[4].value.as < parameter_list_t > ());
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.result = ctx.make<syntax_pattern>(std::move(yystack_[1].value.as < syntax_pattern > ()));
            yystack_[6].value.as < std::pair<resource_location, lambda> > ().second.body = ctx.make_array<statement>(yystack_[0].value.as < statement_list_t > ());
            yylhs.value.as < syntax_expression > () = syntax_expression{ yystack_[6].value.as < std::pair<resource_location, lambda> > ().first, std::move(yystack_[6].value.as < std::pair<resource_location, lambda> > ().second) };
            IGNORE_TERM(yystack_[5].value.as < resource_location > ());
        }
#line 4493 "annium.tab.cpp"
    break;

  case 234: // pack-expression-opt: %empty
#line 1217 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{}; }
#line 4499 "annium.tab.cpp"
    break;

  case 235: // pack-expression-opt: pack-expression
#line 1219 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[0].value.as < opt_named_expression_list_t > ()); }
#line 4505 "annium.tab.cpp"
    break;

  case 236: // pack-expression: syntax-expression
#line 1224 "annium.y"
        { yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t{ opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) } }; }
#line 4511 "annium.tab.cpp"
    break;

  case 237: // pack-expression: identifier "`:`" syntax-expression
#line 1226 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = opt_named_expression_list_t {
                opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) }
            };
        }
#line 4521 "annium.tab.cpp"
    break;

  case 238: // pack-expression: pack-expression "," syntax-expression
#line 1232 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[2].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4530 "annium.tab.cpp"
    break;

  case 239: // pack-expression: pack-expression "," identifier "`:`" syntax-expression
#line 1237 "annium.y"
        {
            yylhs.value.as < opt_named_expression_list_t > () = std::move(yystack_[4].value.as < opt_named_expression_list_t > ());
            yylhs.value.as < opt_named_expression_list_t > ().emplace_back(opt_named_expression_t{ std::move(yystack_[2].value.as < annotated_identifier > ()), std::move(yystack_[0].value.as < syntax_expression > ()) });
        }
#line 4539 "annium.tab.cpp"
    break;

  case 240: // compound-expression: syntax-expression "`...`"
#line 1245 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < resource_location > ()), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move(yystack_[1].value.as < syntax_expression > ())), 1 } } }; }
#line 4545 "annium.tab.cpp"
    break;

  case 241: // compound-expression: call-expression
#line 1246 "annium.y"
        { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4551 "annium.tab.cpp"
    break;

  case 242: // type-expr: qname
#line 1287 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annotated_qname > ().location), qname_reference_expression{ ctx.make_qname_view(std::move(yystack_[0].value.as < annotated_qname > ().value)) } }; }
#line 4557 "annium.tab.cpp"
    break;

  case 243: // type-expr: RESERVED_IDENTIFIER
#line 1289 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4563 "annium.tab.cpp"
    break;

  case 244: // type-expr: CONTEXT_IDENTIFIER
#line 1291 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[0].value.as < annium::annotated_string_view > ().location), name_reference_expression{ ctx.make_identifier(std::move(yystack_[0].value.as < annium::annotated_string_view > ().value)) } }; }
#line 4569 "annium.tab.cpp"
    break;

  case 245: // type-expr: call-expression
#line 1292 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4575 "annium.tab.cpp"
    break;

  case 246: // type-expr: "`[`" type-expr "`]`"
#line 1294 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), bracket_expression{ ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4581 "annium.tab.cpp"
    break;

  case 247: // type-expr: "`(`" "`)`"
#line 1296 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), ctx.make_entity_identifier(builtin_eid::void_) }; }
#line 4587 "annium.tab.cpp"
    break;

  case 248: // type-expr: grouped-expression
#line 1297 "annium.y"
      { yylhs.value.as < syntax_expression > () = yystack_[0].value.as < syntax_expression > (); }
#line 4593 "annium.tab.cpp"
    break;

  case 249: // type-expr: type-expr "`[`" syntax-expression "`]`"
#line 1299 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[2].value.as < resource_location > ()), index_expression{ ctx.make<syntax_expression>(std::move(yystack_[3].value.as < syntax_expression > ())), ctx.make<syntax_expression>(std::move(yystack_[1].value.as < syntax_expression > ())) } }; }
#line 4599 "annium.tab.cpp"
    break;

  case 250: // type-expr: type-expr "`|`" type-expr
#line 1301 "annium.y"
        { yylhs.value.as < syntax_expression > () = syntax_expression{ std::move(yystack_[1].value.as < resource_location > ()), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move(yystack_[2].value.as < syntax_expression > ()), std::move(yystack_[0].value.as < syntax_expression > ())) } }; }
#line 4605 "annium.tab.cpp"
    break;

  case 251: // type-expr: type-expr "`->`" type-expr
#line 1303 "annium.y"
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
#line 4620 "annium.tab.cpp"
    break;


#line 4624 "annium.tab.cpp"

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


  const short parser::yypact_ninf_ = -284;

  const short parser::yytable_ninf_ = -184;

  const short
  parser::yypact_[] =
  {
     795,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
      16,   902,   923,  1033,    16,  1033,  1033,  1033,    -1,   -51,
      45,  1033,    52,  1033,    45,    80,  -284,  -284,  -284,    13,
      45,    45,  -284,  -284,  -284,    57,    98,    11,   474,  -284,
    -284,  -284,  -284,   109,  -284,   276,    19,    46,  -284,   124,
    -284,   116,   585,   155,  -284,    26,  -284,  1033,  -284,   114,
     195,  1249,   127,  -284,   688,   205,    38,  1249,   -22,  -284,
      35,    35,    35,    16,  -284,   220,   290,  -284,    16,    13,
     181,  1087,  -284,   109,   229,  1126,   233,  -284,  -284,  -284,
     109,   264,  -284,   267,  -284,   280,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,    16,  -284,  -284,  1033,   273,
      74,  1033,    16,  1033,  1033,    16,  -284,  1033,   774,  1033,
    1033,  1033,  1033,  1033,  -284,  1033,  1033,  1033,  1033,  1033,
     285,   652,  1033,  -284,  1033,  -284,  -284,  1033,  1033,   242,
     581,  -284,   271,  -284,  -284,  -284,  -284,  1033,  -284,  -284,
     774,  1033,   283,  -284,  1033,  1033,  -284,  1033,   257,  1033,
     285,   285,    16,   301,   285,  -284,   303,   298,   774,   713,
    1033,  -284,   325,  -284,   333,   197,  -284,  1249,   153,   194,
    1016,   774,   287,    46,   124,   116,    48,   457,   457,   547,
     441,   654,   759,    54,    54,   485,   350,  -284,   368,   368,
     203,   358,   704,  -284,  -284,     7,   503,   216,   339,   321,
    -284,   412,   368,   368,  -284,  1249,   354,  1249,  1249,  1249,
    -284,  -284,  -284,  -284,  -284,  1249,   182,   298,   774,    15,
     364,   344,  -284,  1033,  1249,  1126,  1126,    57,  1249,   373,
     384,  -284,   352,   347,  -284,    16,   387,  -284,   182,    45,
      22,   395,  1033,   429,   295,  -284,  -284,   429,  1249,  -284,
    -284,  -284,  -284,   184,   774,  1033,   774,  -284,  1033,  -284,
    -284,  -284,   830,   368,   368,  -284,   704,   704,   704,  -284,
     414,  -284,  -284,     6,  1033,   368,   262,   368,   429,   368,
    -284,    91,   285,  -284,    20,  -284,  -284,  1033,   182,  -284,
    -284,  -284,  1033,  1249,  -284,  -284,  -284,   434,   365,  -284,
      16,   148,   420,   400,  -284,   455,   109,   417,   429,  -284,
    -284,  1163,  -284,   429,  -284,  -284,    48,  1200,    48,  1249,
    -284,   252,  -284,  -284,  -284,  -284,  -284,  -284,  1033,   262,
     432,  1249,  -284,   429,   368,   368,   392,  -284,  -284,   774,
    1033,   713,  -284,  -284,  -284,  -284,  1249,  -284,  1033,   439,
    -284,  -284,  1033,   774,  -284,    16,   442,   704,   424,   491,
     424,   411,   226,  -284,  -284,   465,  -284,    22,  -284,  -284,
    -284,  1249,   429,   368,   368,   392,   203,   392,  -284,  -284,
    -284,   166,  1249,   130,  1249,  1033,  1249,   158,  -284,    16,
    -284,  -284,   424,  -284,   704,   468,  -284,   417,  -284,   429,
    -284,   392,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
    1207,  1033,  -284,   443,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  1249,  -284
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,   193,    53,   182,   181,   192,   189,   190,   191,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    62,     0,
       0,     0,   186,   187,   188,     0,     0,     0,     0,     5,
       7,    14,    56,   183,    60,     0,   229,   195,   224,   228,
     225,   241,     0,     0,   227,   226,    55,     0,   196,    56,
     229,   236,     0,   226,    22,     0,     0,    82,     0,   203,
     205,   207,   206,     0,    41,    20,    16,    18,     0,     0,
     219,     0,   179,   180,     0,     0,     0,    44,    13,    65,
      64,     0,    42,     0,    38,     0,    15,   202,     1,     2,
      10,     3,     8,     6,     9,     0,    63,    61,   234,    69,
       0,   234,     0,   234,     0,     0,   204,     0,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     0,     0,     0,
     100,     0,     0,   218,     0,    49,    48,    50,     0,    39,
      40,    25,     0,    47,    23,   199,   198,     0,   200,    19,
       0,     0,     0,    12,    84,     0,    32,     0,    35,     0,
     100,   100,    73,     0,   100,    57,     0,   235,     0,     0,
       0,    37,     0,   184,     0,     0,   185,    46,   244,   243,
       0,     0,   242,     0,   248,   245,   217,   210,   211,   215,
     216,   212,     0,   208,   209,   213,   214,    54,   106,   106,
     136,     0,   161,   130,   131,    56,   175,   106,     0,   101,
     102,   134,   106,   106,   197,   237,    56,   238,    51,    52,
      28,    26,    27,    24,    31,    83,    21,    17,     0,    56,
       0,    85,    86,     0,    89,     0,     0,     0,    80,     0,
       0,    77,     0,    74,    75,    92,     0,   230,    70,     0,
     175,     0,     0,   175,   165,    71,   177,   173,    43,   221,
     223,   222,   247,     0,     0,     0,     0,   201,     0,   126,
     128,   137,   140,   106,   106,   164,   159,     0,     0,   155,
     162,   160,   105,     0,     0,   106,   136,   106,   176,   106,
     112,     0,     0,   135,   132,   111,   124,     0,    11,    90,
      91,   220,     0,    88,    33,    34,    36,     0,    67,    72,
       0,     0,     0,    93,    94,     0,   174,   175,   175,   168,
     170,     0,   167,   175,   178,   246,   251,     0,   250,   107,
     141,   138,   110,   123,   158,   156,   157,   163,     0,   136,
       0,   119,   127,   137,   106,   106,   106,   125,   113,     0,
       0,     0,   231,    29,   103,   133,   239,    87,     0,     0,
      66,    76,     0,     0,    78,     0,     0,     0,   175,     0,
     175,   175,     0,   153,   143,   145,   169,   175,   166,   249,
     139,   118,   137,   106,   106,   106,   136,   106,   109,   120,
     121,     0,    30,     0,    81,     0,    99,    96,    95,    92,
     149,   154,   175,   151,     0,   147,   142,   175,   146,   175,
     171,   106,   108,   114,   115,   129,   117,   122,   232,   233,
       0,     0,    98,     0,   152,   150,   148,   144,   172,   116,
      68,    97,    79
  };

  const short
  parser::yypgoto_[] =
  {
    -284,  -284,  -284,  -284,   466,  -284,  -284,  -284,  -284,  -284,
      36,     8,   -30,  -284,   -57,   370,    31,  -129,   176,   463,
    -284,     9,  -284,   482,  -284,   433,  -284,  -284,  -284,   204,
    -284,  -284,   500,  -284,  -284,   227,  -284,   131,  -284,  -284,
     169,   122,  -284,  -284,   112,   239,  -171,  -284,  -284,  -283,
    -244,  -284,  -145,   133,  -112,  -196,  -167,  -126,  -188,    12,
    -284,  -114,  -284,    -2,  -284,    49,     0,  -284,  -284,   332,
      39,    37,    88
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    36,    37,    38,    39,    74,    75,    76,   139,   140,
     352,   353,    40,   142,    41,   144,    42,   253,    43,    44,
      45,    60,    91,   109,   360,   110,    94,   242,   243,   244,
      96,    87,    66,   230,   231,   232,   233,   312,   313,   422,
     314,   208,   209,   283,   269,   210,   211,   212,   272,   273,
     318,   372,   373,   374,   213,   279,   280,   256,   375,   288,
      84,    47,    48,    49,    50,    51,    61,    53,    54,   166,
     167,    63,   186
  };

  const short
  parser::yytable_[] =
  {
      52,   206,   255,   344,   183,     2,   281,   143,   104,    46,
     323,    99,    67,    67,   197,    70,    71,    72,   287,     2,
      65,    81,     2,    85,    78,     2,   -45,   338,  -104,   271,
     299,   206,   206,   148,   141,   206,   183,    55,    52,   249,
     264,    56,    59,    97,   116,    69,    79,    46,   147,    77,
      62,     2,   339,  -104,   183,   355,   383,   131,     2,    82,
      10,   300,   319,   116,    52,   322,    10,   183,   264,   100,
     317,   108,   265,    46,   118,    55,   282,   -45,   340,  -104,
     334,   335,   336,   143,   -45,    88,   266,   125,   274,   156,
      89,   146,    10,   158,   111,   170,    89,   183,    98,    10,
     265,    55,    73,   415,   149,   112,   125,    64,   147,   152,
     222,   349,   350,   351,   183,   343,   184,   177,   171,   187,
     188,   189,   190,   191,    64,   192,   193,   194,   195,   196,
     376,   324,   215,   409,   217,   378,   165,   218,   219,    59,
      52,    64,    59,   173,    59,    59,   176,   225,   184,    46,
     183,   350,   183,   175,   234,   235,   105,   236,   183,   238,
     132,   205,   324,   206,   114,   216,   184,   185,   382,   362,
     258,   400,   113,   421,   345,   115,   133,    55,   264,   184,
      64,   257,    59,   405,   393,   229,   264,   350,   371,   410,
     227,   205,   205,   241,   363,   205,    80,   134,    83,   185,
      86,  -182,   264,   130,   264,    90,    93,    95,   425,   184,
     265,    59,  -182,   257,   257,   271,    64,   185,   265,    62,
     324,   428,    90,   401,   266,   403,   184,   384,   105,   154,
     185,   268,   266,   303,   265,   183,   265,   325,   226,   371,
     402,   371,  -181,   304,   305,   306,   261,   108,   266,   183,
     266,   289,   321,  -181,   159,    90,   248,   424,   145,   324,
     185,   324,   184,   105,   184,   327,   150,   134,   329,   263,
     184,   201,   264,   371,   416,   406,   311,   185,   371,   249,
     105,   160,   239,   240,   341,   324,   246,   380,   257,   257,
     257,     2,   197,   168,   182,   169,   407,   356,   346,   294,
     220,   163,   234,   198,   265,   151,   207,   202,   203,   157,
     204,   270,   161,   185,   105,   185,   298,   162,   266,   290,
     199,   185,   224,   205,   295,   296,   182,   105,   164,   228,
     201,   200,    10,   229,   105,  -183,   207,   207,   381,   237,
     207,   241,   105,   317,   182,   254,  -183,   184,   370,   245,
     392,   385,   326,   201,   328,   387,   247,   182,   394,   116,
     331,   184,   396,   257,     2,   197,   202,   203,   134,   204,
     118,    26,    27,   106,   259,   249,   250,   254,   254,   257,
     119,   120,   260,   268,   123,   332,   333,   182,   291,   202,
     203,   292,   204,   275,   411,   420,   311,   342,   185,   347,
     297,   348,   125,   309,   182,    10,   251,   268,   252,   249,
     126,   127,   185,   301,   302,   128,   257,   310,     2,   178,
     179,   431,   307,     2,   197,   316,   404,   418,   249,   419,
     311,   197,   367,   308,   249,   368,   315,   391,   370,   367,
     182,   249,   182,   172,   320,   174,   249,   293,   182,   337,
     116,   397,   254,   254,   254,   358,   388,   389,   390,    10,
     180,   118,   276,   277,   181,   278,   116,   359,   207,   364,
     365,   119,   120,   121,   101,   123,   366,   118,   386,     1,
       2,     3,     4,     5,     6,     7,     8,   395,     9,   369,
     399,   123,   432,   125,   116,   412,   413,   414,   197,   417,
     408,   126,   127,   426,   103,   118,   128,   129,   107,   125,
     223,    92,   153,    68,   361,   119,   120,   126,   127,   123,
     249,    10,    11,   429,   284,   182,    12,   254,    13,   357,
     423,   354,   102,    14,   398,    15,    16,   125,   285,   182,
     427,    17,     0,   254,     0,   126,   127,     0,    18,   286,
      19,    20,    21,    22,     0,    23,   116,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,   118,    25,    26,
      27,    28,    29,    30,    31,     0,     0,   119,   120,     0,
     254,   123,    32,    33,    34,    35,     1,     2,     3,     4,
       5,     6,     7,     8,   116,     9,     0,     0,     0,   125,
     117,     0,     0,     0,     0,   118,     0,   126,   127,     0,
       0,     0,   128,   129,     0,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    12,     0,    13,     0,   125,     0,   221,
      14,     0,    15,    16,     0,   126,   127,     0,    17,     0,
     128,   129,     0,     0,     0,    18,     0,     0,    20,    21,
      22,   116,    23,   116,   135,   136,   137,   138,     0,    24,
       0,     0,   118,     0,   118,     0,    26,    27,    28,    29,
      30,     0,   119,   120,   121,   122,   123,   124,     0,    32,
      33,    34,    35,     1,     2,     3,     4,     5,     6,     7,
       8,   214,     9,     0,   125,     0,   125,     0,     0,     0,
       2,   197,   126,   127,   126,   127,     0,   128,   129,     2,
     197,   249,   250,     0,     0,     0,     0,     0,     0,     0,
     249,   250,     0,     0,     0,    10,    11,     0,     0,   275,
      12,     0,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    10,   251,     0,   252,    17,     0,     0,     0,     0,
      10,   251,    18,   252,     0,    20,    21,    22,   116,    23,
       0,   135,   136,   137,   138,     0,    24,     0,     0,   118,
       2,   178,   179,    26,    27,    28,    29,    30,     0,   119,
     120,   121,   122,   123,   124,     0,    32,    33,    34,    35,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,   125,   267,     0,     0,     0,     0,     0,     0,   126,
     127,    10,   180,     0,   128,   129,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,   178,   179,     0,
       0,     0,    10,    11,     0,     0,     0,    12,     0,    13,
       0,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,     0,     0,   330,     0,     0,     0,    18,
       0,    19,    20,    21,    22,     0,    23,    10,   180,     0,
       0,     0,   181,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    10,
      11,    58,     0,     0,    12,     0,    13,     0,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
      10,    11,     0,    64,     0,    12,     0,    13,     0,    20,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,    26,    27,    28,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,    26,    27,
      28,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,    32,    33,    34,    35,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,   262,     0,     0,    12,     0,
      13,     0,     0,     0,     0,    14,     0,    15,    16,     0,
      10,    11,     0,    17,     0,    12,     0,    13,     0,     0,
       0,     0,    14,    20,    15,    16,   116,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,   118,     0,     0,
      20,    26,    27,    28,     0,     0,     0,   119,   120,   121,
     122,   123,   124,     0,    32,    33,    34,    35,    26,    27,
      28,     0,     0,     0,     0,   116,     0,    64,     0,   125,
       0,    32,    33,    34,    35,   155,   118,   126,   127,     0,
       0,     0,   128,   129,     0,     0,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,    64,     0,   125,     0,
       0,     0,     0,   118,     0,     0,   126,   127,     0,     0,
       0,   128,   129,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,   377,   125,   116,     0,     0,     0,
     118,     0,     0,   126,   127,     0,     0,   118,   128,   129,
     119,   120,   121,   122,   123,   124,     0,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   379,     0,     0,   430,     0,   116,   125,
     126,   127,     0,     0,     0,   128,   129,   126,   127,   118,
       0,     0,   128,   129,     0,     0,     0,     0,     0,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,   128,   129
  };

  const short
  parser::yycheck_[] =
  {
       0,   130,   169,   286,   118,     6,   202,    64,    38,     0,
     254,     0,    12,    13,     7,    15,    16,    17,   206,     6,
      12,    21,     6,    23,    75,     6,     0,    21,    21,   200,
      15,   160,   161,    55,    64,   164,   150,     0,    38,    17,
      20,    10,    11,    35,     9,    14,    97,    38,    70,    18,
      11,     6,    46,    46,   168,    35,   339,    57,     6,     7,
      47,    46,   250,     9,    64,   253,    47,   181,    20,    58,
      48,    52,    52,    64,    20,    38,   205,    51,    72,    72,
     276,   277,   278,   140,    58,     5,    66,    52,   200,    81,
      77,    53,    47,    85,    48,    21,    77,   211,     0,    47,
      52,    64,   103,   386,    73,    59,    52,    50,    70,    78,
     140,    20,    21,    22,   228,   286,   118,   117,   110,   119,
     120,   121,   122,   123,    50,   125,   126,   127,   128,   129,
     318,   257,   132,   377,   134,   323,   105,   137,   138,   108,
     140,    50,   111,   112,   113,   114,   115,   147,   150,   140,
     264,    21,   266,   114,   154,   155,    47,   157,   272,   159,
      46,   130,   288,   292,    48,   134,   168,   118,   339,    21,
     170,   367,    48,    15,   286,    59,    49,   140,    20,   181,
      50,   169,   151,   371,   351,   154,    20,    21,   317,   377,
     151,   160,   161,   162,    46,   164,    20,    70,    22,   150,
      24,    48,    20,    48,    20,    29,    30,    31,   404,   211,
      52,   180,    59,   201,   202,   386,    50,   168,    52,   180,
     346,   409,    46,   368,    66,   370,   228,   339,    47,    48,
     181,    15,    66,   233,    52,   349,    52,    53,   150,   368,
     369,   370,    48,   235,   236,   237,    49,    52,    66,   363,
      66,    35,   252,    59,    21,    79,   168,   402,    53,   385,
     211,   387,   264,    47,   266,   265,    46,    70,   268,   181,
     272,    68,    20,   402,   386,    49,   245,   228,   407,    17,
      47,    48,   160,   161,   284,   411,   164,    35,   276,   277,
     278,     6,     7,    20,   118,    22,    70,   297,   286,   211,
      58,    21,   302,    18,    52,    15,   130,   104,   105,    80,
     107,   199,    48,   264,    47,   266,   228,    50,    66,   207,
      35,   272,    51,   292,   212,   213,   150,    47,    48,    46,
      68,    46,    47,   302,    47,    48,   160,   161,   338,    82,
     164,   310,    47,    48,   168,   169,    59,   349,   317,    48,
     350,   339,   264,    68,   266,   343,    53,   181,   358,     9,
     272,   363,   362,   351,     6,     7,   104,   105,    70,   107,
      20,    95,    96,    97,    49,    17,    18,   201,   202,   367,
      30,    31,    49,    15,    34,   273,   274,   211,    49,   104,
     105,    70,   107,    35,   382,   395,   365,   285,   349,   287,
      46,   289,    52,    51,   228,    47,    48,    15,    50,    17,
      60,    61,   363,    49,    70,    65,   404,    70,     6,     7,
       8,   421,    49,     6,     7,   249,    15,   391,    17,   393,
     399,     7,    15,    49,    17,    18,    49,   349,   407,    15,
     264,    17,   266,   111,    49,   113,    17,    35,   272,    35,
       9,   363,   276,   277,   278,    21,   344,   345,   346,    47,
      48,    20,   104,   105,    52,   107,     9,   102,   292,    49,
      70,    30,    31,    32,     0,    34,    21,    20,    46,     5,
       6,     7,     8,     9,    10,    11,    12,    48,    14,    72,
      48,    34,    49,    52,     9,   383,   384,   385,     7,   387,
      35,    60,    61,    35,    38,    20,    65,    66,    45,    52,
     140,    29,    79,    13,   310,    30,    31,    60,    61,    34,
      17,    47,    48,   411,    21,   349,    52,   351,    54,   302,
     399,   292,    58,    59,   365,    61,    62,    52,    35,   363,
     407,    67,    -1,   367,    -1,    60,    61,    -1,    74,    46,
      76,    77,    78,    79,    -1,    81,     9,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    20,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    30,    31,    -1,
     404,    34,   108,   109,   110,   111,     5,     6,     7,     8,
       9,    10,    11,    12,     9,    14,    -1,    -1,    -1,    52,
      15,    -1,    -1,    -1,    -1,    20,    -1,    60,    61,    -1,
      -1,    -1,    65,    66,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    52,    -1,    54,    -1,    52,    -1,    58,
      59,    -1,    61,    62,    -1,    60,    61,    -1,    67,    -1,
      65,    66,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,     9,    81,     9,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    20,    -1,    20,    -1,    95,    96,    97,    98,
      99,    -1,    30,    31,    32,    33,    34,    35,    -1,   108,
     109,   110,   111,     5,     6,     7,     8,     9,    10,    11,
      12,    49,    14,    -1,    52,    -1,    52,    -1,    -1,    -1,
       6,     7,    60,    61,    60,    61,    -1,    65,    66,     6,
       7,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    47,    48,    -1,    -1,    35,
      52,    -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    47,    48,    -1,    50,    67,    -1,    -1,    -1,    -1,
      47,    48,    74,    50,    -1,    77,    78,    79,     9,    81,
      -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,    20,
       6,     7,     8,    95,    96,    97,    98,    99,    -1,    30,
      31,    32,    33,    34,    35,    -1,   108,   109,   110,   111,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    47,    48,    -1,    65,    66,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    52,    -1,    54,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    35,    -1,    -1,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    47,    48,    -1,
      -1,    -1,    52,    88,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    52,    -1,    54,    -1,    -1,    -1,
      -1,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      47,    48,    -1,    50,    -1,    52,    -1,    54,    -1,    77,
      -1,    -1,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    95,    96,
      97,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,   108,   109,   110,   111,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,    -1,
      54,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,
      47,    48,    -1,    67,    -1,    52,    -1,    54,    -1,    -1,
      -1,    -1,    59,    77,    61,    62,     9,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      77,    95,    96,    97,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,   108,   109,   110,   111,    95,    96,
      97,    -1,    -1,    -1,    -1,     9,    -1,    50,    -1,    52,
      -1,   108,   109,   110,   111,    58,    20,    60,    61,    -1,
      -1,    -1,    65,    66,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    60,    61,    -1,    -1,
      -1,    65,    66,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    51,    52,     9,    -1,    -1,    -1,
      20,    -1,    -1,    60,    61,    -1,    -1,    20,    65,    66,
      30,    31,    32,    33,    34,    35,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    49,    -1,     9,    52,
      60,    61,    -1,    -1,    -1,    65,    66,    60,    61,    20,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    65,    66
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      47,    48,    52,    54,    59,    61,    62,    67,    74,    76,
      77,    78,    79,    81,    88,    94,    95,    96,    97,    98,
      99,   100,   108,   109,   110,   111,   113,   114,   115,   116,
     124,   126,   128,   130,   131,   132,   133,   173,   174,   175,
     176,   177,   178,   179,   180,   183,   128,    46,    49,   128,
     133,   178,   182,   183,    50,   123,   144,   178,   144,   128,
     178,   178,   178,   103,   117,   118,   119,   128,    75,    97,
     130,   178,     7,   130,   172,   178,   130,   143,     5,    77,
     130,   134,   135,   130,   138,   130,   142,   123,     0,     0,
      58,     0,    58,   116,   124,    47,    97,   131,    52,   135,
     137,    48,    59,    48,    48,    59,     9,    15,    20,    30,
      31,    32,    33,    34,    35,    52,    60,    61,    65,    66,
      48,   178,    46,    49,    70,    83,    84,    85,    86,   120,
     121,   124,   125,   126,   127,    53,    53,    70,    55,   128,
      46,    15,   128,   137,    48,    58,   123,    80,   123,    21,
      48,    48,    50,    21,    48,   128,   181,   182,    20,    22,
      21,   123,   181,   128,   181,   182,   128,   178,     7,     8,
      48,    52,   130,   173,   175,   177,   184,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,     7,    18,    35,
      46,    68,   104,   105,   107,   128,   129,   130,   153,   154,
     157,   158,   159,   166,    49,   178,   128,   178,   178,   178,
      58,    58,   124,   127,    51,   178,   184,   182,    46,   128,
     145,   146,   147,   148,   178,   178,   178,    82,   178,   153,
     153,   128,   139,   140,   141,    48,   153,    53,   184,    17,
      18,    48,    50,   129,   130,   168,   169,   171,   178,    49,
      49,    49,    49,   184,    20,    52,    66,    53,    15,   156,
     156,   158,   160,   161,   166,    35,   104,   105,   107,   167,
     168,   167,   129,   155,    21,    35,    46,   170,   171,    35,
     156,    49,    70,    35,   184,   156,   156,    46,   184,    15,
      46,    49,    70,   178,   123,   123,   123,    49,    49,    51,
      70,   128,   149,   150,   152,    49,   130,    48,   162,   170,
      49,   178,   170,   162,   169,    53,   184,   178,   184,   178,
      35,   184,   156,   156,   167,   167,   167,    35,    21,    46,
      72,   178,   156,   158,   161,   166,   171,   156,   156,    20,
      21,    22,   122,   123,   157,    35,   178,   147,    21,   102,
     136,   141,    21,    46,    49,    70,    21,    15,    18,    72,
     128,   129,   163,   164,   165,   170,   170,    51,   170,    53,
      35,   178,   158,   161,   166,   171,    46,   171,   156,   156,
     156,   184,   178,   168,   178,    48,   178,   184,   152,    48,
     167,   164,   129,   164,    15,   170,    49,    70,    35,   162,
     170,   171,   156,   156,   156,   161,   166,   156,   122,   122,
     178,    15,   151,   149,   164,   167,    35,   165,   170,   156,
      49,   178,    49
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   112,   113,   113,   114,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   121,   121,   122,
     122,   123,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   128,   129,   130,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   136,   136,   137,
     137,   137,   138,   139,   139,   140,   140,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   159,   159,   159,   159,   160,   160,   161,   161,
     161,   161,   162,   163,   163,   164,   164,   164,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   167,   167,   167,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   176,
     176,   177,   177,   177,   178,   178,   178,   178,   178,   179,
     179,   180,   180,   180,   181,   181,   182,   182,   182,   182,
     183,   183,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184
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
       1,     2,     1,     2,     1,     1,     5,     0,     4,     1,
       3,     3,     4,     0,     1,     1,     3,     1,     5,     8,
       3,     6,     1,     3,     0,     1,     1,     3,     2,     1,
       2,     2,     0,     1,     1,     3,     0,     2,     4,     3,
       0,     1,     1,     3,     0,     1,     0,     2,     5,     4,
       3,     2,     2,     3,     5,     5,     6,     5,     4,     3,
       4,     4,     5,     3,     2,     3,     2,     3,     2,     5,
       1,     1,     2,     3,     1,     2,     0,     1,     2,     3,
       1,     2,     3,     1,     3,     1,     2,     2,     3,     2,
       3,     2,     3,     1,     2,     2,     3,     3,     3,     2,
       2,     1,     1,     2,     1,     1,     3,     2,     2,     3,
       2,     4,     5,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     3,     3,
       3,     4,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       5,     4,     4,     4,     1,     1,     1,     1,     1,     1,
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
  "\"consteval modifier\"", "\"runctime modifier\"", "\"nil\"", "\"true\"",
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
       0,   340,   340,   341,   345,   347,   349,   366,   368,   369,
     371,   376,   378,   380,   382,   384,   389,   390,   395,   397,
     402,   403,   408,   410,   412,   417,   419,   420,   422,   428,
     431,   442,   447,   449,   451,   453,   455,   457,   467,   472,
     473,   477,   479,   481,   488,   490,   492,   500,   501,   503,
     505,   507,   509,   514,   522,   537,   539,   541,   547,   548,
     552,   553,   557,   559,   564,   566,   571,   589,   591,   603,
     604,   606,   613,   618,   619,   623,   625,   630,   636,   638,
     661,   667,   684,   686,   692,   693,   697,   699,   704,   706,
     711,   713,   719,   720,   724,   726,   731,   732,   736,   738,
     745,   746,   750,   752,   757,   758,   762,   763,   768,   772,
     774,   778,   781,   786,   794,   796,   798,   800,   803,   805,
     808,   810,   812,   814,   816,   824,   826,   828,   830,   835,
     842,   843,   847,   849,   853,   855,   860,   865,   869,   871,
     875,   877,   887,   892,   894,   900,   902,   905,   907,   911,
     914,   920,   923,   936,   939,   944,   945,   946,   947,   948,
     949,   950,   954,   955,   956,   960,   962,   964,   966,   968,
     970,   972,   974,   976,   981,   986,   988,   992,   994,  1000,
    1002,  1007,  1009,  1011,  1013,  1015,  1020,  1022,  1024,  1026,
    1028,  1030,  1032,  1034,  1036,  1038,  1039,  1041,  1047,  1055,
    1057,  1059,  1061,  1063,  1070,  1077,  1079,  1081,  1086,  1088,
    1092,  1094,  1096,  1099,  1103,  1106,  1109,  1111,  1141,  1154,
    1158,  1165,  1167,  1169,  1174,  1175,  1176,  1177,  1178,  1183,
    1185,  1190,  1197,  1205,  1216,  1218,  1223,  1225,  1231,  1236,
    1244,  1246,  1286,  1288,  1290,  1292,  1293,  1295,  1297,  1298,
    1300,  1302
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
#line 5663 "annium.tab.cpp"

#line 1636 "annium.y"

