/*=============================================================================
    Annium programming language (c) 2025 by Alexander Pototskiy
    Annium is licensed under the terms of the MIT License.
==============================================================================*/
%require "3.2"
%language "c++"
//%debug
%define api.value.type variant
//%define api.value.automove
%define api.prefix {annium_lang}
//%define lr.type ielr
//%define parse.lac full

%defines
%locations
%token-table
%define parse.error verbose

%parse-param { void * scanner }
%param { parser_context & ctx }
%lex-param { void * scanner }

%start begin

%{
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

%}

%token END 0 "end of file"

%token COMMENT_BEGIN
%token COMMENT_END

%token <annium::annotated_string_view> STRING IDENTIFIER CONTEXT_IDENTIFIER RESERVED_IDENTIFIER INTEGER_INDEX
%token <annium::annotated_integer_view> INTEGER
%token <annium::annotated_decimal_view> DECIMAL DECIMAL_S
%token <sonia::string_view> OPERATOR_TERM
%token <annotated_identifier> CT_IDENTIFIER

%token <resource_location> ASSIGN               "`=`"

%token APOSTROPHE           "APOSTROPHE"
%token AT_SYMBOL            "`@`"
%token <resource_location> UNDERSCORE           "`_`"
%token ARROWAST             "`->*`"
%token ARROW                "`->`"
%token ARROWEXPR            "`=>`"
%token FARROW               "`~>`"
%token PTAST                "`.*`"

%token DBLPLUS              "`++`"
%token DBLMINUS             "`--`"
%token LEFTSHIFT            "`<<`"
%token RIGHTSHIFT           "`>>`"
%token LE                   "`<=`"
%token GE                   "`>=`"
%token <resource_location> EQ                   "`==`"
%token <resource_location> NE                   "`!=`"
%token <resource_location> LOGIC_AND            "`&&`"
%token <resource_location> LOGIC_OR             "`||`"
%token <resource_location> CONCAT               "`..`"
%token <resource_location> ELLIPSIS "`...`"
%token ADDASSIGN            "`+=`"
%token SUBASSIGN            "`-=`"
%token MULASSIGN            "`*=`"
%token DIVASSIGN            "`/=`"
%token MODASSIGN            "`%=`"
%token LSHIFTSSIGN          "`<<=`"
%token RSHIFTSSIGN          "`>>=`"
%token BITANDASSIGN         "`&=`"
%token BITORASSIGN          "`|=`"
%token BITXORASSIGN         "`^=`"

%token COLON                "`:`"
%token DBLCOLON             "`::`"
%token <resource_location> OPEN_PARENTHESIS       "`(`"
%token CLOSE_PARENTHESIS    "`)`"
%token <resource_location> OPEN_BRACE             "`{`"
%token CLOSE_BRACE			"`}`"
%token <resource_location> OPEN_SQUARE_BRACKET    "`[`"
%token CLOSE_SQUARE_BRACKET "`]`"
%token <resource_location> OPEN_SQUARE_DBL_BRACKET "`[[`"
%token CLOSE_SQUARE_DBL_BRACKET "`]]`"
%token OPEN_BROKET          "`<`"
%token CLOSE_BROKET         "`>`"
%token END_STATEMENT		"`;`"
%token <resource_location> POINT      "`.`"
%token <resource_location> PLUS       "`+`"
%token <resource_location> MINUS      "`-`"
%token <resource_location> ASTERISK   "`*`"
%token SLASH                "`/`"
%token PERCENT              "`%`"
%token <resource_location> AMPERSAND  "`&`"
%token <resource_location> BITOR      "`|`"
%token <resource_location> EXCLPT     "`!`" 
%token TILDA                "`~`"
%token EXCL                 "`^`"
%token COMMA                ","
%token DOLLAR               "`$`"
%token <resource_location> QMARK      "`?`"
%token HASHTAG              "`#`"

%token LET
%token VAR
%token EXTERN

%token <resource_location> NEW        "`new`"
%token WHILE                "`while`"
%token FOR                  "`for`"
%token IN_                  "`in`"
%token IF                   "`if`"
%token ELSE                 "`else`"
%token <resource_location> CONTINUE   "`continue`"
%token <resource_location> BREAK      "`break`"
%token <resource_location> RETURN     "`return`"
%token <resource_location> YIELD      "`yield`"

%token AUTO
%token USING
%token THROW
%token SIZEOF


// 16 priority
//%left COMMA

// 15 priority
//%right ASSIGN               "`=`"
//%right COLON ADDASSIGN SUBASSIGN MULASSIGN MODASSIGN DIVASSIGN LSHIFTSSIGN RSHIFTSSIGN BITANDASSIGN BITORASSIGN BITXORASSIGN THROW

// 14 priority
//%left LOGIC_OR

// 13 priority
//%left LOGIC_AND

// 12 priority
//%left BITOR

// 11 priority
//%left EXCL



// 9 priority
//%left EQ NE

// 8 priority
//%left OPEN_BROKET LE CLOSE_BROKET GE
//%left OPEN_BROKET LE GE

// 7 priority
//%left RIGHTSHIFT LEFTSHIFT

// 4 priority
//%left PTAST ARROWAST

// 3 priority
//%right PREFIXDBLPLUS PREFIXDBLMINUS PREFIXPLUS PREFIXMINUS EXCLPT TILDA CAST ADDRESS SIZEOF

// 2 priority
//%left DBLPLUS DBLMINUS OPEN_PARENTHESIS CLOSE_PARENTHESIS OPEN_SQUARE_BRACKET CLOSE_SQUARE_BRACKET POINT

// 1 priority
//%left IDENTIFIER
////////////////////////////////////////////////////////////////////////
%left LOWEST

%right ARROWEXPR
%left ELLIPSIS
%left COLON

// 15 priority
%right ASSIGN

// 14 priority
%left LOGIC_OR

// 13 priority
%left LOGIC_AND

// 12 priority
%left BITOR

// 10 priority
%left AMPERSAND

// 9 priority
%left EQ NE

// 6 priority
%left CONCAT
%left PLUS MINUS

// 5 priority
%left ASTERISK SLASH PERCENT

// 4 priority
%right ARROW

// 3 priority
%right DEREF EXCLPT PREFIXMINUS

// 2 priority
%left OPEN_BRACE OPEN_PARENTHESIS OPEN_SQUARE_BRACKET POINT INTEGER_INDEX
%right QMARK

%left DBLCOLON

// 1 priority
%right IDENTIFIER CONTEXT_IDENTIFIER RESERVED_IDENTIFIER

// STATEMENTS
%token INCLUDE
%type <statement> statement infunction-statement
%type <statement> finished-statement
%type <statement> generic-statement

%type <statement_list_t> statement_any finished-statement-any
%type <statement_list_t> infunction-statement-any finished-infunction-statement-any infunction-statement-set braced-statements function-body

%type <let_statement> let-decl-start let-decl-start-with-opt-type let-decl

//%type <identifier_chain_t> identifier-chain

// QNAME
%type <context_identifier> internal-identifier internal-identifier-opt
%type <annotated_identifier> identifier
//%type <annotated_identifier> any_identifier
%type <annotated_qname> qname


// FUNCTIONS
%token INLINE
%token VIABLE
%token <resource_location> FN "`fn`"
%token <resource_location> TYPEFN "`typefn`"
%type <fn_kind> fn-kind fn-kind-set
%type <std::pair<resource_location, fn_kind>> fn-prefix-decl
%type <fn_pure> fn-start-decl fn-decl
%type <annium::annotated_qname_view> fn-name
//%type <fn_requirements_t> fn-requirements-any fn-requirements
//%type <fn_requirement_t> fn-requirement
%type <syntax_expression const*> fn-requirement-opt

// ENUMERATIONS
%token ENUM
%type <enum_decl> enum-decl
%type <std::vector<identifier>> case-list-opt case-list
%type <identifier> case-decl

// TYPES
%token STRUCT
%token EXTENDS

%type <struct_decl> struct-decl
%type <using_decl> using-decl

//%type <extension_list_t> type-extension-list
//%type <extension_list_t> type-extension-any

%type <opt_named_expression_list_t> argument-list argument-list-opt
%type <opt_named_expression_t> argument
%type <annotated_identifier> argument-name

%type <std::vector<field>> field-list field-list-opt
%type <field> field
%type <field::default_spec> field-default-value-opt

%type <parameter_list_t> parameter-list parameter-list-opt // for unification, empty assignment
%type <parameter> parameter-decl
%type <parameter::default_spec> parameter-default-value-opt

%token REQUIRES

%token WEAK "weak modifier"
%token <resource_location> TYPENAME "typename modifier"
%token <resource_location> CONSTEXPR "constexpr modifier"
%token <resource_location> CONSTEVAL "consteval modifier"
%token <resource_location> RUNTIME "runctime modifier"

// EXPRESSIONS
%token <annotated_nil> NIL_WORD "nil"

%token <annotated_bool> TRUE_WORD "true"
%token <annotated_bool> FALSE_WORD "false"
%token <resource_location> PROBE

%type <reference_expression> reference-expression
%type <syntax_expression> type-expr
//%type <syntax_expression> parenthesized-expression
%type <syntax_expression> syntax-expression-base grouped-expression any-reference-expression concept-expression syntax-expression
%type <syntax_expression> new-expression call-expression lambda-expression compound-expression
//%type <syntax_expression> apostrophe-expression 
%type <opt_named_expression_list_t> pack-expression pack-expression-opt

%type <std::pair<resource_location, lambda>> lambda-start-decl
%type <syntax_expression_list_t> expression-list


// PATTERNS
//%type <parameter_constraint_modifier_t> constraint-expression-mod
%type <std::pair<resource_location, parameter_constraint_modifier_t>> constraint-expression-mod constraint-expression-specified-mod
%type <std::pair<std::variant<syntax_expression const*, syntax_pattern const*>, parameter_constraint_modifier_t>> constraint-expression constraint-expression-specified
%type <std::pair<syntax_pattern, parameter_constraint_modifier_t>> pattern-mod pattern-sfx
%type <syntax_pattern> pattern
%type <syntax_pattern::field> pattern-field pattern-field-sfx
%type <syntax_pattern_field_list_t> subpatterns pattern-list
%type <syntax_expression_list_t> concept-expression-list concept-expression-list-opt

%destructor { } <*>
%printer { } <*>

%%

begin:
	  statement_any[sts] END { ctx.set_root_statements(std::move($sts)); }
    | finished-statement-any[sts] END { ctx.set_root_statements(std::move($sts)); }
	;

statement_any:
      %empty
        { $$ = statement_list_t{}; }
    | statement
        { $$ = statement_list_t{ std::move($statement) }; }
    | finished-statement-any[sts] statement
        { $$ = std::move($sts); $$.emplace_back(std::move($statement)); }
/*
    |
    NAMESPACE nsname
        {
            ctx.push_ns(std::move($2));
        }
        OPEN_BRACE statement_any CLOSE_BRACE
        {
            $$ = std::move($5);
            ctx.pop_ns();
        }
*/
    ;

finished-statement-any:
      finished-statement[st]
        { $$ = statement_list_t{ std::move($st) }; }
    | finished-statement-any[sts] END_STATEMENT { $$ = std::move($sts); }
    | finished-statement-any[sts] finished-statement[st]
        { $$ = std::move($sts); $$.emplace_back(std::move($st));  }
    | statement_any[sts] END_STATEMENT
        { $$ = std::move($sts); }
    ;

statement:
      EXTERN VAR identifier COLON type-expr[type]
        { $$ = statement{ extern_var{ .name = std::move($identifier), .type = std::move($type) } }; }
    | EXTERN FN fn-decl[fn]
        { $$ = statement{ std::move($fn) }; IGNORE_TERM($FN); }
    | INCLUDE STRING
        { $$ = statement{ include_decl{ ctx.make_string_view(std::move($STRING)) } }; }
    | generic-statement[st]
        { $$ = std::move($st); }
    | STRUCT struct-decl[struct]
        { $$ = statement{ std::move($struct) }; }
	;
 
let-decl:
      let-decl-start-with-opt-type
    | let-decl-start-with-opt-type[st] ASSIGN pack-expression[value]
        { $$ = std::move($st); $$.expressions = ctx.make_array<opt_named_expression_t>($value); $$.assign_location = std::move($ASSIGN); }
    ;

let-decl-start:
      identifier
        { $$ = let_statement{ .aname = std::move($identifier), .weakness = false }; }
    | WEAK identifier
        { $$ = let_statement{ .aname = std::move($identifier), .weakness = true }; }
    ;

let-decl-start-with-opt-type :
      let-decl-start
    | let-decl-start[st] COLON type-expr[type]
        { $$ = std::move($st); $$.type = std::move($type); }
    ;

infunction-statement-any:
      %empty
        { $$ = statement_list_t{}; }
    | infunction-statement[st]
        { $$ = statement_list_t{ std::move($st) }; }
    | finished-infunction-statement-any[sts] infunction-statement[st]
        { $$ = std::move($sts); $$.emplace_back(std::move($st)); }
    ;

finished-infunction-statement-any:
      finished-statement[st]
        { $$ = statement_list_t{ std::move($st) }; }
    | finished-infunction-statement-any[sts] END_STATEMENT { $$ = std::move($sts); }
    | finished-infunction-statement-any[sts] finished-statement[st]
        { $$ = std::move($sts); $$.emplace_back(std::move($st)); }
    | infunction-statement-any[sts] END_STATEMENT
        { $$ = std::move($sts); }
    ;

// lambda only
function-body:
      braced-statements
    //| ARROWEXPR syntax-expression[value] apostrophe-opt
    //    { $$ = statement_list_t{ statement{ return_statement{ std::move($value) } } }; }
    | ARROWEXPR syntax-expression[value]
        { $$ = statement_list_t{ statement{ return_statement{ std::move($value) } } }; }
    ;
    /*
apostrophe-opt:
      %empty
    | APOSTROPHE
    ;
    */

braced-statements:
    OPEN_BRACE infunction-statement-set[sts] CLOSE_BRACE
        { $$ = std::move($sts); IGNORE_TERM($1); }
    ;

finished-statement:
      WHILE syntax-expression[condition] braced-statements[body]
        { $$ = statement{ while_decl{ std::move($condition), ctx.make_array<statement>($body) } }; }
    | WHILE syntax-expression[condition] END_STATEMENT syntax-expression[continue] braced-statements[body]
        { $$ = statement{ while_decl{ std::move($condition), ctx.make_array<statement>($body), std::move($continue) } }; }
    | FOR reference-expression[iter] IN_ syntax-expression[coll] braced-statements[body]
        { $$ = statement{ for_statement{ .iter = std::move($iter), .coll = std::move($coll), .body = ctx.make_array<statement>($body) } }; }
    | IF syntax-expression[cond] braced-statements[body]
        { $$ = statement{ if_decl{ .condition = std::move($cond), .true_body = ctx.make_array<statement>($body) } }; }
    | IF syntax-expression[cond] braced-statements[trueBody] ELSE braced-statements[falseBody]
        { $$ = statement{ if_decl{ .condition = std::move($cond), .true_body = ctx.make_array<statement>($trueBody), .false_body = ctx.make_array<statement>($falseBody) } }; }
    | fn-prefix-decl[fndescr] fn-decl[fn] braced-statements[body]
        {   
            $fn.location = std::move(get<0>($fndescr));
            $fn.kind = get<1>($fndescr);
            $$ = statement{ fn_decl{ std::move($fn), ctx.make_array<statement>($body) } };
        }
    //| STRUCT qname braced-statements[body]
    //    { $$ = struct_decl{ .name = std::move($qname), .body = ctx.make_array<statement>($body) }; }
    //| STRUCT qname OPEN_PARENTHESIS[beginParams] parameter-list-opt[parameters] CLOSE_PARENTHESIS braced-statements[body]
    //    { $$ = struct_decl{ .name = std::move($qname), .parameters = std::move($parameters), .body = ctx.make_array<statement>($body)) }; IGNORE_TERM($beginParams); }
    | ENUM enum-decl[enum]
        { $$ = statement{ std::move($enum) }; }
    ;

infunction-statement-set:
      infunction-statement-any
    | finished-infunction-statement-any
    ;

generic-statement:
      LET let-decl[let]
        { $$ = statement{ std::move($let) }; }
    | TYPEFN fn-start-decl[fn]
        { $$ = statement{ typefn_decl{ std::move($fn) } }; IGNORE_TERM($TYPEFN); }
    | fn-prefix-decl[fndescr] fn-decl[fn] ARROWEXPR syntax-expression[value]
        {
            statement_list_t return_stmt{ statement{ return_statement{ std::move($value) } } };
            $fn.location = std::move(get<0>($fndescr));
            $fn.kind = get<1>($fndescr);
            $$ = statement{ fn_decl{ std::move($fn), ctx.make_array<statement>(return_stmt) } };
        }
    | USING using-decl[alias]
        { $$ = statement{ std::move($alias) }; }
    | compound-expression[expr]
        { $$ = statement{ expression_statement{ std::move($expr) } }; }
    | syntax-expression[lexpr] ASSIGN syntax-expression[rexpr]
        { 
            $$ = statement{ expression_statement{ syntax_expression{ std::move($ASSIGN),
                binary_expression{ binary_operator_type::ASSIGN, ctx.make_span_for_args<opt_named_expression_t>(std::move($lexpr), std::move($rexpr)) } } } };
        }
    ;

infunction-statement:
      generic-statement
    | BREAK
        { $$ = statement{ break_statement{ std::move($BREAK) } }; }
    | CONTINUE
        { $$ = statement{ continue_statement{ std::move($CONTINUE) } }; }
    | RETURN
        { $$ = statement{ return_statement{ .location = std::move($RETURN) } }; }
    | RETURN syntax-expression[expr]
        { $$ = statement{ return_statement{ .expression = std::move($expr), .location = std::move($RETURN) } }; }
    | YIELD syntax-expression[expr]
        { $$ = statement{ yield_statement{ .expression = std::move($expr), .location = std::move($YIELD) } }; }
    ;

identifier:
    IDENTIFIER
      { $$ = ctx.make_identifier(std::move($IDENTIFIER)); }
/*  
	| DOLLAR OPEN_PARENTHESIS ct-expression CLOSE_PARENTHESIS
*/  
	;

internal-identifier:
    CONTEXT_IDENTIFIER
        { $$ = context_identifier { ctx.make_identifier(std::move($CONTEXT_IDENTIFIER)) }; }
    ;

/*
any_identifier:
      identifier
    | CONTEXT_IDENTIFIER
        { $$ = ctx.make_identifier(std::move($1)); }
    | RESERVED_IDENTIFIER
        { $$ = ctx.make_identifier(std::move($1)); }
    ;
*/
///////////////////////////////////////////////// QNAME
qname:
      DBLCOLON identifier
        { $$ = annotated_qname{ qname{$2.value}, std::move($2.location) }; }
    | identifier
        { $$ = annotated_qname{ qname{$1.value, false}, std::move($1.location) }; }
    | qname DBLCOLON identifier
        { $$ = std::move($1); $$.value.append(std::move($3.value)); }
    ;

///////////////////////////////////////////////// FUNCTIONS
fn-kind:
      INLINE { $$ = fn_kind::INLINE; }
    | VIABLE { $$ = fn_kind::VIABLE; }
    ;

fn-kind-set:
      fn-kind[kind] { $$ = $kind; }
    | fn-kind-set[set] fn-kind[kind] { $$ = $set | $kind; }
    ;

fn-prefix-decl:
      FN
        { $$ = std::pair{ std::move($FN), fn_kind::DEFAULT }; }
    | fn-kind-set[set] FN
        { $$ = std::pair{ std::move($FN), $set }; }
    ;

fn-name:
      qname
        { $$ = ctx.make_qname_view(std::move($qname)); } 
    | NEW
        { $$ = ctx.make_qname_view(annotated_string_view{ "new"sv, std::move($NEW) }); }
    ;

fn-start-decl:
      fn-name[name] OPEN_PARENTHESIS parameter-list-opt[parameters] CLOSE_PARENTHESIS fn-requirement-opt[req]
        { $$ = fn_pure{ .name = $name.value, .location = std::move($name.location), .parameters = ctx.make_array<parameter>($parameters), .requirement = std::move($req) }; IGNORE_TERM($OPEN_PARENTHESIS); }
    ;

/*
fn-requirements-any:
       %empty { $$ = {}; }
    | fn-requirements
    ;

fn-requirements:
      fn-requirement[req]
        { $$ = fn_requirements_t{ std::move($req) }; }
    | fn-requirements[reqs] COMMA fn-requirement[req]
        { $$ = std::move($reqs); $$.emplace_back(std::move($req)); }
    ;
*/
fn-requirement-opt:
      %empty { $$ = nullptr; }
    // we need parentheses to avoid ambiguity with a function type declaration (near ARROW token)
    | REQUIRES OPEN_PARENTHESIS syntax-expression[expr] CLOSE_PARENTHESIS
        { $$ = ctx.make<syntax_expression>(std::move($expr)); IGNORE_TERM($OPEN_PARENTHESIS); }
    ;
    /*
    | VIABLE
        { $$ = viable_clause_t{ .location = std::move($VIABLE) };  }
    | VIABLE braced-statements[body]
        { $$ = viable_clause_t{ .location = std::move($VIABLE), .body = ctx.push(std::move($body)) }; }
        //{ $$ = viable_clause_t{ .location = {}, .body = ctx.push(std::move($body)) }; }
    ;
    */
fn-decl:
      fn-start-decl
    | fn-start-decl[fn] ARROW type-expr[type]
        { $$ = $fn; $$.result = ctx.make<syntax_expression>(std::move($type)); }
    | fn-start-decl[fn] FARROW pattern
        { $$ = $fn; $$.result = ctx.make<syntax_pattern>(std::move($pattern)); }
    ;


///////////////////////////////////////////////// ENUMERATIONS
enum-decl:
    qname OPEN_BRACE case-list-opt[cases] CLOSE_BRACE
        { $$ = enum_decl{ ctx.make_qname_view(std::move($qname)), ctx.make_array<identifier>($cases) }; IGNORE_TERM($OPEN_BRACE); }
    ;

case-list-opt:
      %empty { $$ = {}; }
    | case-list
    ;

case-list:
      case-decl[case]
        { $$ = std::vector<identifier>{ std::move($case) }; }
    | case-list[list] COMMA case-decl[case]
        { $$ = std::move($list); $$.emplace_back(std::move($case)); }
    ;

case-decl:
    identifier
        { $$ = $1.value; }
    ;
///////////////////////////////////////////////// TYPES

struct-decl:
      qname ARROWEXPR OPEN_PARENTHESIS[begin] field-list-opt[fields] CLOSE_PARENTHESIS
        { $$ = struct_decl{ .name = ctx.make_qname_view(std::move($qname)), .body = ctx.make_array<field>($fields) }; IGNORE_TERM($begin); }
    | qname OPEN_PARENTHESIS[beginParams] parameter-list-opt[parameters] CLOSE_PARENTHESIS ARROWEXPR OPEN_PARENTHESIS[begin] field-list-opt[fields] CLOSE_PARENTHESIS
        { $$ = struct_decl{ .name = ctx.make_qname_view(std::move($qname)), .parameters = ctx.make_array<parameter>($parameters), .body = ctx.make_array<field>($fields) }; IGNORE_TERM($beginParams); IGNORE_TERM($begin); }
    ;

/*
type-extension-any:
    %empty { $$ = {}; }
    |
    EXTENDS type-extension-list { $$ = std::move($2); }
    ;

type-extension-list:
    qname
        { $$ = extension_list_t{ctx.make_qname_identifier(std::move($1))}; }
    |
    type-extension-list COMMA qname
        { $$ = std::move($1); $$.emplace_back(ctx.make_qname_identifier(std::move($3))); }
    ;
*/

///////////////////////////////////////////////// ALIASES

using-decl:
      qname ARROWEXPR syntax-expression[expr]
        {
            auto loc = $expr.location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move($expr), .location = std::move(loc) } } };
            $$ = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move($qname.value)), .location = std::move($qname.location), .result = nullptr }, ctx.make_array<statement>(sts) } };
        }
    | qname OPEN_PARENTHESIS[beginParams] parameter-list-opt[parameters] CLOSE_PARENTHESIS ARROWEXPR syntax-expression[expr]
        {
            auto loc = $expr.location;
            statement_list_t sts{ statement{ return_statement{ .expression = std::move($expr), .location = std::move(loc) } } };
            $$ = using_decl{ fn_decl{ fn_pure{ .name = ctx.make_qname_view(std::move($qname.value)), .location = std::move($qname.location), .parameters = ctx.make_array<parameter>($parameters), .result = nullptr }, ctx.make_array<statement>(sts) } };
            IGNORE_TERM($beginParams);
        }
    ;

////////////////////// LIST (aka vector/list elements)
/*
expression-list-any:
      %empty { $$ = {}; }
    | expression-list
    ;
*/
expression-list:
      syntax-expression[value]
        { $$ = syntax_expression_list_t{ $value }; }
    | expression-list[list] COMMA syntax-expression[value]
        { $$ = std::move($list); $$.emplace_back(std::move($value)); }
    ;

////////////////////// ARGUMENTS (aka function call arguments)
argument-list-opt:
       %empty { $$ = {}; }
    | argument-list
    ;

argument-list:
      argument[arg]
        { $$ = opt_named_expression_list_t{ std::move($arg) }; }
    | argument-list[list] COMMA argument[arg]
        { $$ = std::move($list); $$.emplace_back(std::move($arg)); }
    ;

argument:
      argument-name[name] syntax-expression[value]
        { $$ = opt_named_expression_t{ std::move($name), std::move($value) }; }
    | syntax-expression[value]
        { $$ = opt_named_expression_t{ std::move($value) }; }
    ;

argument-name:
      identifier[id] ASSIGN
        { $$ = std::move($id); IGNORE_TERM($ASSIGN); }
    | identifier[id] COLON
        { $$ = std::move($id); }
    ;

////////////////////// FIELDS (structure fields declaration)
field-list-opt:
       %empty { $$ = {}; }
    | field-list
    ;

field-list:
      field
        { $$ = std::vector<field>{ std::move($field) }; }
    | field-list[list] COMMA field
        { $$ = std::move($list); $$.emplace_back(std::move($field)); }
    ;

field-default-value-opt:
      %empty { $$ = required_t{}; }
    | ASSIGN syntax-expression[value] { $$ = std::move($value); IGNORE_TERM($ASSIGN); }
    ;

field:
      identifier COLON type-expr[type] field-default-value-opt[default]
        { $$ = field{ .name = std::move($identifier), .modifier = parameter_constraint_modifier_t::runtime_type, .type_or_value = std::move($type), .value = std::move($default) }; }
    | identifier ARROWEXPR syntax-expression[value]
        { $$ = field{ .name = std::move($identifier), .modifier = parameter_constraint_modifier_t::constexpr_value, .type_or_value = std::move($value) }; }
    ;

////////////////////// PARAMETERS (function parameters declaration)

parameter-list-opt:
       %empty { $$ = {}; }
    |  parameter-list
    ;

parameter-list:
      parameter-decl[param]
        { $$ = parameter_list_t{ std::move($param) }; }
    | parameter-list[list] COMMA parameter-decl[param]
        { $$ = std::move($list); $$.emplace_back(std::move($param)); }
    ;

internal-identifier-opt:
      %empty { $$ = context_identifier{}; }
    | internal-identifier[intid] { $$ = std::move($intid); }
    ;

parameter-default-value-opt:
      %empty { $$ = required_t{}; }
    | ASSIGN syntax-expression[value] { $$ = ctx.make<syntax_expression>(std::move($value)); IGNORE_TERM($ASSIGN); }
    ;

parameter-decl:
// named parameter main case: foo(paramName [$internalParamName] : [constexpr | runtime] type-expression [...] [= expression])
      identifier[id] internal-identifier-opt[intid] COLON constraint-expression[ce] parameter-default-value-opt[default]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = std::move(get<0>($ce)), .default_value = std::move($default), .modifier = get<1>($ce) }; }

// unnamed parameter main case: foo([$internalParamName] : [constexpr | runtime] type-expression [...] [= expression])
    | internal-identifier[intid] COLON constraint-expression[ce] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint = std::move(get<0>($ce)), .default_value = std::move($default), .modifier = get<1>($ce) }; }
    | COLON constraint-expression[ce] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>($ce)), .default_value = std::move($default), .modifier = get<1>($ce) }; }
    
// abbreviated main case: foo([constexpr | runtime] type-expression [...] [= expression])
    | constraint-expression-specified[ce] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = std::move(get<0>($ce)), .default_value = std::move($default), .modifier = get<1>($ce) }; }
    // parse special case, when type-expression is just a qname and we have no 'constexpr' or 'runtime' modifier
    | qname parameter-default-value-opt[default]
        {
            auto constraint = ctx.make<syntax_expression>(std::move($qname.location), qname_reference_expression{ ctx.make_qname_view(std::move($qname)) });
            $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move($default), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
    | qname ELLIPSIS parameter-default-value-opt[default]
        {
            auto constraint = ctx.make<syntax_expression>(std::move($qname.location), qname_reference_expression{ ctx.make_qname_view(std::move($qname)) });
            $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = constraint, .default_value = std::move($default), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::ellipsis };
            IGNORE_TERM($ELLIPSIS);
        }


    | identifier[id] internal-identifier-opt[intid] COLON pattern-mod[pm] parameter-default-value-opt[default]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>($pm))), .default_value = std::move($default), .modifier = get<1>($pm) }; }
    | identifier[id] internal-identifier-opt[intid] COLON concept-expression-list[cpts] parameter-default-value-opt[default]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($id.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };  }
    | identifier[id] internal-identifier-opt[intid] COLON constraint-expression-specified-mod[mod] concept-expression-list[cpts] parameter-default-value-opt[default]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($id.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier = get<1>($mod) };  }
    | identifier[id] internal-identifier-opt[intid] QMARK COLON pattern-mod[pm] 
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>($pm))), .default_value = optional_t{}, .modifier = get<1>($pm) }; IGNORE_TERM($QMARK); }
    
    | identifier[id] internal-identifier-opt[intid] ARROWEXPR syntax-expression[value]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = ctx.make<syntax_expression>(std::move($value)), .modifier = parameter_constraint_modifier_t::constexpr_value }; }
    | internal-identifier[intid] ARROWEXPR syntax-expression[value]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint = ctx.make<syntax_expression>(std::move($value)), .modifier = parameter_constraint_modifier_t::constexpr_value }; }

    | internal-identifier[intid] COLON pattern-mod[pm] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>($pm))), .default_value = std::move($default), .modifier = get<1>($pm) }; }
    | internal-identifier[intid] COLON concept-expression-list[cpts] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($intid.name.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type };   }        
    | internal-identifier[intid] COLON constraint-expression-specified-mod[mod] concept-expression-list[cpts] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint =  ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($intid.name.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier = get<1>($mod) }; }
    | COLON pattern-mod[pm] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>($pm))), .default_value = std::move($default), .modifier = get<1>($pm) }; }
    | pattern-mod[pm] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>(std::move(get<0>($pm))), .default_value = std::move($default), .modifier = get<1>($pm) }; }

    // sugar for simple placeholder types
    //| identifier[id] internal-identifier-opt[intid] concept-expression-list-opt[cpts] parameter-default-value-opt[default] 
    //    { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($intid.name.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier = parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
    //| identifier[id] internal-identifier[intid] QMARK
    //    { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($intid.name.location) } } ), .default_value = optional_t{}, .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
    | internal-identifier[intid] concept-expression-list-opt[cpts] parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($intid.name.location) }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
    | UNDERSCORE parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($UNDERSCORE) } } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
    | internal-identifier[intid] ELLIPSIS parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ std::move($intid.name) }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($ELLIPSIS) } } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
    | ELLIPSIS parameter-default-value-opt[default]
        { $$ = parameter{ .name = unnamed_parameter_name{ }, .constraint = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ std::move($ELLIPSIS) } } ), .default_value = std::move($default), .modifier =  parameter_constraint_modifier_t::constexpr_or_runtime_type | parameter_constraint_modifier_t::ellipsis }; }
    
    //| TILDA pattern-mod[pm] parameter-default-value-opt[default]
    //    { $$ = parameter{ .name = unnamed_parameter_name{}, .constraint = std::move(get<0>($pm)), .default_value = std::move($default), .modifier =  get<1>($pm) }; }
    | identifier[id] internal-identifier-opt[intid] QMARK COLON constraint-expression[ce]
        { $$ = parameter{ .name = named_parameter_name{ std::move($id), std::move($intid.name) }, .constraint = std::move(get<0>($ce)), .default_value = optional_t{}, .modifier = get<1>($ce) }; IGNORE_TERM($QMARK); }
    

    ;

constraint-expression-specified-mod:
      CONSTEXPR { $$ = std::pair{ std::move($CONSTEXPR), parameter_constraint_modifier_t::constexpr_type }; }
    | RUNTIME { $$ = std::pair{ std::move($RUNTIME), parameter_constraint_modifier_t::runtime_type }; }
    ;

constraint-expression-specified:
      constraint-expression-specified-mod[mod] type-expr[match]
        { $$ = std::pair{ ctx.make<syntax_expression>(std::move($match)), get<1>($mod) }; }
    | constraint-expression-specified-mod[mod] type-expr[match] ELLIPSIS
        { $$ = std::pair{ ctx.make<syntax_expression>(std::move($match)), get<1>($mod) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM($ELLIPSIS); }
    
    // not a type expression, but a placeholders
    | constraint-expression-specified-mod[mod]
        { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move(get<0>($mod)) } }), get<1>($mod) }; }
    | constraint-expression-specified-mod[mod] ELLIPSIS
        { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move($ELLIPSIS) } }), get<1>($mod) | parameter_constraint_modifier_t::ellipsis }; }
    ;

constraint-expression-mod:
      %empty
        {
            location_type const& loc = @-1;
            $$ = std::pair{ resource_location{ loc.begin.line, loc.begin.column, ctx.get_resource_id() }, parameter_constraint_modifier_t::constexpr_or_runtime_type };
        }
    | constraint-expression-specified-mod
    ;

constraint-expression:
      constraint-expression-mod[mod] type-expr[match]
        { $$ = std::pair{ ctx.make<syntax_expression>(std::move($match)), get<1>($mod) }; }
    | constraint-expression-mod[mod] type-expr[match] ELLIPSIS
        { $$ = std::pair{ ctx.make<syntax_expression>(std::move($match)), get<1>($mod) | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM($ELLIPSIS); }

    // not a type expression, but a placeholders
    | constraint-expression-mod[mod]
        { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ get<0>($mod) } }), get<1>($mod) }; }
    | constraint-expression-mod[mod] ELLIPSIS
        { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move($ELLIPSIS) } }), get<1>($mod) | parameter_constraint_modifier_t::ellipsis }; }
    //| TYPENAME 
    //    { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move($TYPENAME) } }), parameter_constraint_modifier_t::typename_value }; }
    //| TYPENAME ELLIPSIS
    //    { $$ = std::pair{ ctx.make<syntax_pattern>(syntax_pattern{ .descriptor = placeholder{ std::move($TYPENAME) } }), parameter_constraint_modifier_t::typename_value | parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM($ELLIPSIS); }
    ;

/////////////////////////// PATTERNS
subpatterns:
    OPEN_PARENTHESIS pattern-list[list] CLOSE_PARENTHESIS
        { $$ = std::move($list); IGNORE_TERM($OPEN_PARENTHESIS); }
    ;

pattern-list:
      pattern-field[field]
        { $$ = syntax_pattern_field_list_t{ std::move($field) }; }
    | pattern-list[list] COMMA pattern-field[field]
        { $$ = std::move($list); $$.emplace_back(std::move($field)); }
    ;

pattern-field-sfx:
      // named placeholder
      concept-expression-list-opt[cpts]
        { $$ = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>($cpts) } ) }; }
    | concept-expression-list-opt[cpts] ELLIPSIS
        { $$ = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .ellipsis = true }; IGNORE_TERM($ELLIPSIS); }
      // named placeholder with bound variable
    | internal-identifier[iid] concept-expression-list-opt[cpts]
        { $$ = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move($iid.name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>($cpts) } ) }; }
    | internal-identifier[iid] concept-expression-list-opt[cpts] ELLIPSIS
        { $$ = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move($iid.name), .value = ctx.make<syntax_pattern>( syntax_pattern{ .descriptor = placeholder{ }, .concepts = ctx.make_array<syntax_expression>($cpts) } ), .ellipsis = true }; IGNORE_TERM($ELLIPSIS); }
    
      // named pattern
    | ASSIGN pattern-sfx[ps]
        { $$ = syntax_pattern::field{ .name = nullptr, .value = ctx.make<syntax_pattern>(std::move(get<0>($ps))), .ellipsis = has(get<1>($ps), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM($ASSIGN); }
      // named pattern with a bound variable
    | internal-identifier[iid] ASSIGN pattern-sfx[ps]
        { $$ = syntax_pattern::field{ .name = nullptr, .bound_variable = std::move($iid.name), .value = ctx.make<syntax_pattern>(std::move(get<0>($ps))), .ellipsis = has(get<1>($ps), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM($ASSIGN); }
    ;

pattern-field:
      // named field
      identifier[id] pattern-field-sfx[f]
        { $$ = std::move($f); $$.name = std::move($id); }
      // named placeholder field
    | QMARK internal-identifier[nid] pattern-field-sfx[f]
        { $$ = std::move($f); $$.name = std::move($nid); IGNORE_TERM($QMARK); }
    /*
    | QMARK UNDERSCORE pattern-field-sfx[f]
        { $$ = std::move($f); $$.name = placeholder{ std::move($UNDERSCORE) }; IGNORE_TERM($QMARK); }
    | QMARK concept-expression-list-opt[cpts]
        { $$ = syntax_pattern::field{ .name = placeholder{ std::move($QMARK) }, .value = syntax_pattern{ .descriptor = placeholder{ }, .concepts = std::move($cpts) } }; }
    | QMARK concept-expression-list-opt[cpts] ELLIPSIS
        { $$ = syntax_pattern::field{ .name = placeholder{ std::move($QMARK) }, .value = syntax_pattern{ .descriptor = placeholder{ }, .concepts = std::move($cpts) }, .ellipsis = true }; IGNORE_TERM($ELLIPSIS); }
    | QMARK ASSIGN pattern-sfx[ps]
        { $$ = syntax_pattern::field{ .name = placeholder{ std::move($QMARK) }, .value = std::move(get<0>($ps)), .ellipsis = has(get<1>($ps), parameter_constraint_modifier_t::ellipsis) }; IGNORE_TERM($ASSIGN); }
    */
        // unnamed field
    | pattern-field-sfx[f]
        { $$ = std::move($f); $$.name = placeholder{ }; }
        // field with name placeholder, matches any name and unnamed
    | UNDERSCORE pattern-field-sfx[f]
        { $$ = std::move($f); $$.name = placeholder{ std::move($UNDERSCORE) }; }
    ;

pattern-mod:
      TILDA pattern-sfx[ps]                   { $$ = std::pair{ std::move(get<0>($ps)), get<1>($ps) | parameter_constraint_modifier_t::constexpr_or_runtime_type }; }
    | TILDA CONSTEXPR pattern-sfx[ps]         { $$ = std::pair{ std::move(get<0>($ps)), get<1>($ps) | parameter_constraint_modifier_t::constexpr_type }; IGNORE_TERM($CONSTEXPR); }
    | TILDA RUNTIME pattern-sfx[ps]           { $$ = std::pair{ std::move(get<0>($ps)), get<1>($ps) | parameter_constraint_modifier_t::runtime_type }; IGNORE_TERM($RUNTIME); }
    | TILDA TYPENAME pattern-sfx[ps]          { $$ = std::pair{ std::move(get<0>($ps)), get<1>($ps) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM($TYPENAME); }
    | TILDA TYPENAME                          { $$ = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move($TYPENAME) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM($TYPENAME); }
    | TYPENAME pattern-sfx[ps]                { $$ = std::pair{ std::move(get<0>($ps)), get<1>($ps) | parameter_constraint_modifier_t::typename_value }; IGNORE_TERM($TYPENAME); }
    | TYPENAME                                { $$ = std::pair{ syntax_pattern{ .descriptor = placeholder{ std::move($TYPENAME) } }, parameter_constraint_modifier_t::typename_value }; IGNORE_TERM($TYPENAME); }
    ;

pattern-sfx:
      pattern { $$ = std::pair{ std::move($pattern), parameter_constraint_modifier_t::none }; }
    | pattern ELLIPSIS { $$ = std::pair{ std::move($pattern), parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM($ELLIPSIS); }
    | ELLIPSIS { $$ = std::pair{ syntax_pattern{ .descriptor = placeholder{} }, parameter_constraint_modifier_t::ellipsis }; IGNORE_TERM($ELLIPSIS); }
    ;

pattern:
      qname
        { $$ = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move($qname)) } }; }
    | qname subpatterns concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make_qname_view(std::move($qname)), .fields = ctx.make_array<syntax_pattern::field>($subpatterns) }, .concepts = ctx.make_array<syntax_expression>($cpts) }; }
    | internal-identifier[iid] concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = std::move($iid), .concepts = std::move($cpts) }; }
    | UNDERSCORE concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = placeholder{ std::move($UNDERSCORE) }, .concepts = std::move($cpts) }; }
    | UNDERSCORE subpatterns concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = placeholder{ std::move($UNDERSCORE) }, .fields = ctx.make_array<syntax_pattern::field>($subpatterns) }, .concepts = ctx.make_array<syntax_expression>($cpts) }; }
    | OPEN_PARENTHESIS CLOSE_PARENTHESIS
        { $$ = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move($OPEN_PARENTHESIS), ctx.make_entity_identifier(builtin_eid::void_type)) }; }
    | OPEN_BRACE[start] syntax-expression[expr] CLOSE_BRACE concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = ctx.make<syntax_expression>(std::move($expr)), .concepts = ctx.make_array<syntax_expression>($cpts) }; IGNORE_TERM($start); }
    | OPEN_BRACE[start] syntax-expression[expr] CLOSE_BRACE subpatterns concept-expression-list-opt[cpts]
        { $$ = syntax_pattern{ .descriptor = syntax_pattern::signature_descriptor{ .name = ctx.make<syntax_expression>(std::move($expr)), .fields = ctx.make_array<syntax_pattern::field>($subpatterns) }, .concepts = ctx.make_array<syntax_expression>($cpts) }; IGNORE_TERM($start); }
    | concept-expression-list[cpts]
        { $$ = syntax_pattern{ .descriptor = placeholder{}, .concepts = ctx.make_array<syntax_expression>($cpts) }; }
    ;

concept-expression:
    AT_SYMBOL qname
        { $$ = syntax_expression{ .location = $qname.location, .value = qname_reference_expression{ ctx.make_qname_view(std::move($qname.value)) } }; }
    ;

concept-expression-list-opt:
    %empty
        { $$ = {}; }
    | concept-expression-list
    ;

concept-expression-list:
    concept-expression[concept]
        { $$ = syntax_expression_list_t{ std::move($concept) }; }
    | concept-expression-list[list] concept-expression[concept]
        { $$ = std::move($list); $$.emplace_back(std::move($concept)); }
    ;

/////////////////////////// EXPRESSIONS
reference-expression:
      CONTEXT_IDENTIFIER[id]
        { $$ = reference_expression{ std::move($id.location), name_reference_expression{ ctx.make_identifier(std::move($id.value)) } }; }
    | qname
        { $$ = reference_expression{ std::move($qname.location), qname_reference_expression{ ctx.make_qname_view(std::move($qname.value)) } }; }
    ;

any-reference-expression:
      RESERVED_IDENTIFIER
        { $$ = syntax_expression{ std::move($RESERVED_IDENTIFIER.location), name_reference_expression{ ctx.make_identifier(std::move($RESERVED_IDENTIFIER.value)) } }; }
    | CONTEXT_IDENTIFIER[id]
        { $$ = syntax_expression{ std::move($id.location), name_reference_expression{ ctx.make_identifier(std::move($id.value)) } }; }
    | qname
        { $$ = syntax_expression{ std::move($qname.location), qname_reference_expression{ ctx.make_qname_view(std::move($qname.value)) } }; }
    | any-reference-expression[object] POINT identifier[property]
         { $$ = syntax_expression{ $object.location, member_expression{ ctx.make<syntax_expression>($object), ctx.make<syntax_expression>($property.location, std::move($property.value)) } }; IGNORE_TERM($2); }
    | call-expression[object] POINT identifier[property]
         { $$ = syntax_expression{ $object.location, member_expression{ ctx.make<syntax_expression>($object), ctx.make<syntax_expression>($property.location, std::move($property.value)) } }; IGNORE_TERM($2); }
    ;

syntax-expression-base:
      NIL_WORD
        { $$ = syntax_expression{ $NIL_WORD.location, nil_expression{ } }; }
    | TRUE_WORD
        { $$ = syntax_expression{ $TRUE_WORD.location, $TRUE_WORD.value }; }
    | FALSE_WORD
        { $$ = syntax_expression{ $FALSE_WORD.location, $FALSE_WORD.value }; }
    | INTEGER
        { $$ = syntax_expression{ $INTEGER.location, std::move($INTEGER.value) }; }
    | DECIMAL
        { $$ = syntax_expression{ $DECIMAL.location, std::move($DECIMAL.value) }; }
    | DECIMAL_S
        { $$ = syntax_expression{ $DECIMAL_S.location, std::move($DECIMAL_S.value) }; }
    | INTEGER_INDEX
        { $$ = syntax_expression{ $INTEGER_INDEX.location, ctx.make_decimal_view($INTEGER_INDEX.value) }; }
    | STRING
        { $$ = syntax_expression{ $STRING.location, ctx.make_string_view($STRING.value) }; }
    | CT_IDENTIFIER
        { $$ = syntax_expression{ $CT_IDENTIFIER.location, name_reference_expression{ std::move($CT_IDENTIFIER.value) } }; }
    | any-reference-expression
    | OPEN_PARENTHESIS CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), ctx.make_entity_identifier(builtin_eid::void_) }; }
    | OPEN_PARENTHESIS COLON syntax-expression[expr] CLOSE_PARENTHESIS
        {
            // one element tuple
            $$ = syntax_expression{ $OPEN_PARENTHESIS, function_call{ nullptr, std::span{ ctx.make<opt_named_expression_t>(opt_named_expression_t{ std::move($expr) }), 1 } } };
        }

    | OPEN_SQUARE_BRACKET expression-list[list] CLOSE_SQUARE_BRACKET
        { 
            if ($list.size() == 1) {
                $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), bracket_expression{ ctx.make<syntax_expression>(std::move($list.front())) } };
            } else {
                $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), array_expression{ ctx.make_array<syntax_expression>($list) } };
            }
        }
    | OPEN_SQUARE_BRACKET braced-statements[body] CLOSE_SQUARE_BRACKET
        { $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), array_with_body_expression{ ctx.make_array<statement>($body) } }; } 
    | OPEN_SQUARE_DBL_BRACKET expression-list[list] CLOSE_SQUARE_DBL_BRACKET
        { $$ = syntax_expression{ std::move($OPEN_SQUARE_DBL_BRACKET), array_expression{ ctx.make_array<syntax_expression>($list) } }; }
    | syntax-expression[type] OPEN_SQUARE_BRACKET syntax-expression[index] CLOSE_SQUARE_BRACKET
        { $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), index_expression{ ctx.make<syntax_expression>(std::move($type)), ctx.make<syntax_expression>(std::move($index)) } }; }
    | PROBE braced-statements[body]
        { $$ = syntax_expression{ std::move($PROBE), probe_expression{ ctx.make_array<statement>($body) } }; }
    | POINT identifier
        { $$ = syntax_expression{ std::move($POINT), std::move($identifier.value) }; }
    //| syntax-expression[object] POINT syntax-expression[property]
    //    { $$ = member_expression_t{ std::move($object), std::move($property) }; IGNORE_TERM($POINT); }
    
    //| syntax-expression[object] POINT apostrophe-expression[property]
    //     { $$ = member_expression_t{ std::move($object), std::move($property) }; IGNORE_TERM($POINT); }
    | syntax-expression[object] INTEGER_INDEX[property]
        {
            $$ = syntax_expression{ $object.location, member_expression{ 
                ctx.make<syntax_expression>(std::move($object)),
                ctx.make<syntax_expression>($property.location, ctx.make_integer_view($property.value.substr(1))) } };
        }
//////////////////////////// 3 priority
    | MINUS syntax-expression[expr] %prec PREFIXMINUS
        { $$ = syntax_expression{ std::move($MINUS), unary_expression{ unary_operator_type::MINUS, true, std::span{ ctx.make<opt_named_expression_t>(std::move($expr)), 1 } } }; }
    | EXCLPT syntax-expression[expr]
		{ $$ = syntax_expression{ std::move($EXCLPT), unary_expression{ unary_operator_type::NEGATE, true, std::span{ ctx.make<opt_named_expression_t>(std::move($expr)), 1 } } }; }
    | ASTERISK syntax-expression[expr] %prec DEREF
		{ $$ = syntax_expression{ std::move($ASTERISK), unary_expression{ unary_operator_type::DEREF, true, std::span{ ctx.make<opt_named_expression_t>(std::move($expr)), 1 } } }; }
//////////////////////////// 5 priorit

//////////////////////////// 6 priority
    | syntax-expression[larg] PLUS syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($PLUS), binary_expression{ binary_operator_type::PLUS, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
    | syntax-expression[larg] MINUS syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($MINUS), binary_expression{ binary_operator_type::MINUS, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }

//////////////////////////// 9 priority
    | syntax-expression[larg] EQ syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($EQ), binary_expression{ binary_operator_type::EQ, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
    | syntax-expression[larg] NE syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($NE), binary_expression{ binary_operator_type::NE, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
    | syntax-expression[larg] CONCAT syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($CONCAT), binary_expression{ binary_operator_type::CONCAT, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
//////////////////////////// 10 priority
    | syntax-expression[larg] AMPERSAND syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($AMPERSAND), binary_expression{ binary_operator_type::BIT_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }

//////////////////////////// 12 priority
    | syntax-expression[larg] BITOR syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($BITOR), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
//////////////////////////// 13 priority
    | syntax-expression[larg] LOGIC_AND syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($LOGIC_AND), binary_expression{ binary_operator_type::LOGIC_AND, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
//////////////////////////// 14 priority
    | syntax-expression[larg] LOGIC_OR syntax-expression[rarg]
        { $$ = syntax_expression{ std::move($LOGIC_OR), binary_expression{ binary_operator_type::LOGIC_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move($larg), std::move($rarg)) } }; }
    | syntax-expression[lexpr] ARROW type-expr[rexpr]
        {
            annium_fn_type fnt{ .result = ctx.make<syntax_expression>(std::move($rexpr)) };
            if (function_call const* fn_type = get_if<function_call>(&$lexpr.value)) {
                fnt.args = fn_type->args;
            } else if (entity_identifier const* peid = get_if<entity_identifier>(&$lexpr.value); !peid || *peid != ctx.make_entity_identifier(builtin_eid::void_)) {
                opt_named_expression_list_t args{ opt_named_expression_t{ std::move($lexpr) } };
                fnt.args = ctx.make_array<opt_named_expression_t>(args);
            } // else void args
            $$ = syntax_expression{ $lexpr.location, std::move(fnt) }; 
        }
    
    ;

/*
parenthesized-expression:
    OPEN_PARENTHESIS syntax-expression[expr] COMMA pack-expression[list] CLOSE_PARENTHESIS
        { 
            $list.emplace_front(opt_named_expression_t{ std::move($expr) });
            $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), function_call{ nullptr, ctx.make_array<opt_named_expression_t>($list) } };
        }
        ;

grouped-expression:
    OPEN_PARENTHESIS syntax-expression[expr] CLOSE_PARENTHESIS
        { $$ = std::move($expr); }
    ;
*/

grouped-expression:
    OPEN_PARENTHESIS pack-expression[list] CLOSE_PARENTHESIS
        {
            if ($list.size() == 1 && !$list.front().has_name()) { // single unnamed expression => extract
                $$ = std::move($list.front().value());
            } else {
                BOOST_ASSERT(!$list.empty());
                $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), function_call{ nullptr, ctx.make_array<opt_named_expression_t>($list) } };
            }
        }
    ;


new-expression:
      NEW qname[type]
        { $$ = syntax_expression{ std::move($NEW), new_expression{ ctx.make<syntax_expression>(std::move($type.location), qname_reference_expression{ ctx.make_qname_view(std::move($type.value)) }) } }; }
    //| NEW apostrophe-expression[typeExpr]
    //    { $$ = syntax_expression{ std::move($NEW), new_expression{ ctx.make<syntax_expression>(std::move($typeExpr)) } }; }
    | NEW qname[type] OPEN_PARENTHESIS argument-list-opt[arguments] CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($NEW), new_expression{ ctx.make<syntax_expression>(std::move($type.location), qname_reference_expression{ ctx.make_qname_view(std::move($type.value)) }), ctx.make_array<opt_named_expression_t>($arguments) } }; IGNORE_TERM($OPEN_PARENTHESIS); }
    //| NEW apostrophe-expression[typeExpr] OPEN_PARENTHESIS argument-list-opt[arguments] CLOSE_PARENTHESIS
    //    { $$ = syntax_expression{ std::move($NEW), new_expression{ ctx.make<syntax_expression>(std::move($typeExpr)), ctx.make_array<opt_named_expression_t>($arguments) } }; IGNORE_TERM($OPEN_PARENTHESIS); }
    ;

call-expression:
      any-reference-expression[refExpr] OPEN_PARENTHESIS pack-expression-opt[arguments] CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), function_call{ ctx.make<syntax_expression>(std::move($refExpr)), ctx.make_array<opt_named_expression_t>($arguments) } }; }
    | call-expression[nameExpr] OPEN_PARENTHESIS pack-expression[arguments] CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), function_call{ ctx.make<syntax_expression>(std::move($nameExpr)), ctx.make_array<opt_named_expression_t>($arguments) } }; }
    | grouped-expression[expr] OPEN_PARENTHESIS[start] pack-expression-opt[arguments] CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($start), function_call{ ctx.make<syntax_expression>(std::move($expr)), ctx.make_array<opt_named_expression_t>($arguments) } }; }
    ;

syntax-expression:
      syntax-expression-base
    | new-expression
    | compound-expression
    | lambda-expression
    | grouped-expression
    //| parenthesized-expression
    ;

lambda-start-decl:
      fn-prefix-decl[fndescr]
        { $$ = std::pair{ std::move(get<0>($fndescr)), lambda{ fn_pure{ .result = nullptr, .kind = get<1>($fndescr) | fn_kind::VIABLE } } }; }
    | fn-prefix-decl[fndescr] OPEN_SQUARE_BRACKET pack-expression-opt[captures] CLOSE_SQUARE_BRACKET
        { $$ = std::pair{ std::move(get<0>($fndescr)), lambda{ fn_pure{ .result = nullptr, .kind = get<1>($fndescr) | fn_kind::VIABLE }, {}, ctx.make_array<opt_named_expression_t>($captures) } }; IGNORE_TERM($OPEN_SQUARE_BRACKET); }
    ;

lambda-expression:
      lambda-start-decl[lst] OPEN_PARENTHESIS parameter-list-opt[parameters] CLOSE_PARENTHESIS function-body[body]
        { 
            $lst.second.parameters = ctx.make_array<parameter>($parameters);
            $lst.second.body = ctx.make_array<statement>($body);
            $$ = syntax_expression{ $lst.first, std::move($lst.second) };
            IGNORE_TERM($OPEN_PARENTHESIS);
        }
    | lambda-start-decl[lst] OPEN_PARENTHESIS parameter-list-opt[parameters] CLOSE_PARENTHESIS ARROW type-expr[type] function-body[body]
        {
            $lst.second.parameters = ctx.make_array<parameter>($parameters);
            $lst.second.result = ctx.make<syntax_expression>(std::move($type));
            $lst.second.body = ctx.make_array<statement>($body);
            $$ = syntax_expression{ $lst.first, std::move($lst.second) };
            IGNORE_TERM($OPEN_PARENTHESIS);
        }
    | lambda-start-decl[lst] OPEN_PARENTHESIS parameter-list-opt[parameters] CLOSE_PARENTHESIS FARROW pattern[type] function-body[body]
        {
            $lst.second.parameters = ctx.make_array<parameter>($parameters);
            $lst.second.result = ctx.make<syntax_pattern>(std::move($type));
            $lst.second.body = ctx.make_array<statement>($body);
            $$ = syntax_expression{ $lst.first, std::move($lst.second) };
            IGNORE_TERM($OPEN_PARENTHESIS);
        }
    ;

pack-expression-opt:
      %empty
        { $$ = opt_named_expression_list_t{}; }
    | pack-expression[list]
        { $$ = std::move($list); }
    ;

pack-expression:
      syntax-expression[expr]
        { $$ = opt_named_expression_list_t{ opt_named_expression_t{ std::move($expr) } }; }
    | identifier[id] COLON syntax-expression[expr]
        {
            $$ = opt_named_expression_list_t {
                opt_named_expression_t{ std::move($id), std::move($expr) }
            };
        }
    | pack-expression[list] COMMA syntax-expression[expr]
        {
            $$ = std::move($list);
            $$.emplace_back(opt_named_expression_t{ std::move($expr) });
        }
    | pack-expression[list] COMMA identifier[id] COLON syntax-expression[expr]
        {
            $$ = std::move($list);
            $$.emplace_back(opt_named_expression_t{ std::move($id), std::move($expr) });
        }
    ;

compound-expression:
        syntax-expression[expr] ELLIPSIS
        { $$ = syntax_expression{ std::move($ELLIPSIS), unary_expression{ unary_operator_type::ELLIPSIS, false, std::span{ ctx.make<opt_named_expression_t>(std::move($expr)), 1 } } }; }
      | call-expression

    /*
    | syntax-expression OPEN_BRACE argument-list-opt[arguments] CLOSE_BRACE
        { 
           $$ = function_call_t{ std::move($2), std::move($1), std::move($arguments) };
            //$$ = function_call_t{}; IGNORE_TERM($1, $2, $3);
        }
    */
    //| syntax-expression ASSIGN syntax-expression
    //    { $$ = binary_expression{ binary_operator_type::ASSIGN, std::move($1), std::move($3), std::move($2) }; }
    ;

/*
opt-named-expr-list-any:
    %empty
        { $$ = named_expression_list_t{}; }
    | opt-named-expr-list
    ;

opt-named-expr-list:
      opt-named-expr
        { $$ = named_expression_list_t{std::move($1)}; }
    | opt-named-expr-list COMMA opt-named-expr
        {
            $$ = std::move($1);
            $$.emplace_back(std::move($3));
		}
	;

opt-named-expr:
      identifier COLON syntax-expression
        { $$ = named_expression_t{ std::move($1), std::move($3) }; }
    | syntax-expression
        { $$ = named_expression_t{ std::move($1) }; }
    ;
*/

// TYPE EXPRESSIONS
type-expr:
      qname
        { $$ = syntax_expression{ std::move($qname.location), qname_reference_expression{ ctx.make_qname_view(std::move($qname.value)) } }; }
    | RESERVED_IDENTIFIER
        { $$ = syntax_expression{ std::move($RESERVED_IDENTIFIER.location), name_reference_expression{ ctx.make_identifier(std::move($RESERVED_IDENTIFIER.value)) } }; }
    | CONTEXT_IDENTIFIER[id]
        { $$ = syntax_expression{ std::move($id.location), name_reference_expression{ ctx.make_identifier(std::move($id.value)) } }; }
    | call-expression
    | OPEN_SQUARE_BRACKET type-expr[type] CLOSE_SQUARE_BRACKET
        { $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), bracket_expression{ ctx.make<syntax_expression>(std::move($type)) } }; }
    | OPEN_PARENTHESIS CLOSE_PARENTHESIS
        { $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), ctx.make_entity_identifier(builtin_eid::void_) }; }
    | grouped-expression
    | type-expr[type] OPEN_SQUARE_BRACKET syntax-expression[index] CLOSE_SQUARE_BRACKET
        { $$ = syntax_expression{ std::move($OPEN_SQUARE_BRACKET), index_expression{ ctx.make<syntax_expression>(std::move($type)), ctx.make<syntax_expression>(std::move($index)) } }; }
    | type-expr[ltype] BITOR type-expr[rtype]
        { $$ = syntax_expression{ std::move($BITOR), binary_expression{ binary_operator_type::BIT_OR, ctx.make_span_for_args<opt_named_expression_t>(std::move($ltype), std::move($rtype)) } }; }
    | type-expr[lexpr] ARROW type-expr[rexpr]
        {
            annium_fn_type fnt{ .result = ctx.make<syntax_expression>(std::move($rexpr)) };
            if (function_call const* fn_type = get_if<function_call>(&$lexpr.value)) {
                fnt.args = fn_type->args;
            } else if (entity_identifier const* peid = get_if<entity_identifier>(&$lexpr.value); !peid || *peid != ctx.make_entity_identifier(builtin_eid::void_)) {
                opt_named_expression_list_t args{ opt_named_expression_t{ std::move($lexpr) } };
                fnt.args = ctx.make_array<opt_named_expression_t>(args);
            } // else void args
            $$ = syntax_expression{ $lexpr.location, std::move(fnt) }; 
        }
    //| grouped-expression[lexpr] ARROW type-expr[rexpr]
    //    { $$ = syntax_expression{ $lexpr.location, annium_fn_type{ .args = $lexpr, .result = ctx.make<syntax_expression>(std::move($rexpr)) } }; }
    //| OPEN_PARENTHESIS pack-expression[elements] CLOSE_PARENTHESIS ARROW type-expr[rexpr]
    //    { $$ = syntax_expression{ std::move($OPEN_PARENTHESIS), annium_fn_type{ .args = ctx.make_array<opt_named_expression_t>($elements), .result = ctx.make<syntax_expression>(std::move($rexpr)) } }; }
    ;

    /*
opt-type-list:
    %empty
        { $$ = annium_preliminary_tuple_t{}; }
    | type-expr
        { $$ = annium_preliminary_tuple_t{}; $$.fields.emplace_back(std::move($1)); }
    | opt-type-list COMMA type-expr
        { $$ = std::move($1); $$.fields.emplace_back(std::move($3)); }
    ;
    */



    /*
expression:
      expression QMARK
        { $$ = not_empty_expression_t{ std::move($1) }; }

    //| expression QMARK POINT identifier
    //    { $$ = member_expression_t { std::move($1), std::move($4), true }; IGNORE_TERM($3); }
    | expression LOGIC_AND expression
        { $$ = binary_expression{ binary_operator_type::LOGIC_AND, std::move($1), std::move($3), std::move($2) }; }
	| expression LOGIC_OR expression
        { $$ = binary_expression{ binary_operator_type::LOGIC_OR, std::move($1), std::move($3), std::move($2) }; }
    //| expression PLUS expression
    //    { $$ = binary_expression{ binary_operator_type::PLUS, std::move($1), std::move($3), std::move($2) }; }


//////////////////////////// 9 priority



    //| qname OPEN_BROKET opt-named-expr-list CLOSE_BROKET
   //     { $$ = syntax_expression { ctprocedure{ std::move($1), std::move($3) } }; }
    ;

    */

//identifier-chain:
//      identifier
//        { $$ = identifier_chain_t{ std::move($1) }; }
//    | identifier-chain POINT identifier
//        { $$ = std::move($1); $1.emplace_back(std::move($3)); }
//    ;


/*
   expr-with-comma END_STATEMENT
        { $$ = std::move($1); }
   |
   RETURN expr-with-comma END_STATEMENT
        { $$ = return_statement_t{std::move($2)}; }
   ;
*/
/*

arg-list:
	  %empty
        { $$ = named_expression_term_list_t{}; }
	| arg-list-not-empty
	;

arg-list-not-empty:
	  named-arg
        { $$ = named_expression_term_list_t{std::move($1)}; }
	| arg-list-not-empty COMMA named-arg
        { $$ = std::move($1); $$.push_back(std::move($3)); }
	;

named-arg:
	identifier COLON expr
        { $$ = std::pair{std::move($1), $3}; }
    | HASHTAG IDENTIFIER COLON expr
        { $$ = std::pair{ctx.make_required_identifier($2), $4}; }
	;
*/
/*

opt-type-expr-list:
    %empty
        { $$ = type_expression_list_t{}; }
	| type-expr-list-not-empty
	;

type-expr-list-not-empty:
	  type-expr
        { $$ = type_expression_list_t{std::move($1)}; }
	| type-expr-list-not-empty COMMA type-expr
        { $$ = std::move($1); $$.push_back(std::move($3)); }
	;
*/
/*
    CONST_ IDENTIFIER opt-type-modifiers
        {
            $$ = type_expression_list_t{type_modifier::CONST_MODIFIER, ctx.make_identifier($2)};
            $$.insert($$.end(), std::make_move_iterator($3.begin()), std::make_move_iterator($3.end()));
        }
    | IDENTIFIER opt-type-modifiers
        {
            $$ = type_expression_list_t{ctx.make_identifier($1)};
            $$.insert($$.end(), std::make_move_iterator($2.begin()), std::make_move_iterator($2.end()));
        }
    | OPEN_PARENTHESIS type-expr CLOSE_PARENTHESIS
        {
            $$ = $2;
        }
    | type-expr ARROW type-expr
        {
            $$ = $1;
            $$.push_back(std::move($3));
        }
    ;

opt-type-modifiers:
    %empty
        { $$ = type_expression_list_t{}; }
    | type-modifiers
        { $$ = std::move($1); }
    ;
  
type-modifiers:
      type-modifier
        { $$ = type_expression_list_t{$1}; }
    | type-modifiers type-modifier
        { $$ = std::move($1); $$.push_back($2); }
    ;
    

type-modifier:
      CONST { $$ = type_modifier::CONST_MODIFIER; }
    | ASTERISK { $$ = type_modifier::POINTER_MODIFIER; }
    | AMPERSAND { $$ = type_modifier::REFERENCE_MODIFIER; }
    | AND { $$ = type_modifier::RVALUE_REFERENCE_MODIFIER; }
    ;
*/

/*
nsname:
    DBLCOLON
        {
            $$ = qname();
        }
    |
    qname
    ;


*/

//////////////
/*
expr:
      VOID_
        { $$ = expression_list{ctx.make_identifier("void")}; }
    | IDENTIFIER
        { $$ = expression_list{ctx.make_identifier($1)}; }
    | expr DBLCOLON IDENTIFIER
        {
            expression_list arg{ctx.make_identifier($3)};
            $$ = handle_call_op($1, arg, operator_type::DBLCOLON);
        }

    | expr CLOSE_BROKET %prec IDENTIFIER
        { $$ = std::move($1); $$.push_back(operator_type::POSTFIX_CLOSE_BROKET); }
    | expr RIGHTSHIFT %prec IDENTIFIER
        { $$ = std::move($1); $$.push_back(operator_type::POSTFIX_RIGHTSHIFT); }
    | OPEN_PARENTHESIS expr-with-comma CLOSE_PARENTHESIS
        { $$ = std::move($2); }
	| expr DBLPLUS
		{ $$ = std::move($1); $$.push_back(operator_type::POSTFIX_INCREMENT); }
	| expr DBLMINUS
		{ $$ = std::move($1); $$.push_back(operator_type::POSTFIX_DECREMENT); }
	| expr OPEN_PARENTHESIS opt-expr CLOSE_PARENTHESIS
		{ $$ = expression_list{function_t{call_type::FUNCTION_CALL, std::move($1), std::move($3)}}; }
	| expr OPEN_SQUARE_BRACKET opt-expr CLOSE_SQUARE_BRACKET
        { $$ = expression_list{function_t{call_type::SUBSCRIPT, std::move($1), std::move($3)}}; }
	| expr POINT expr
		{ $$ = handle_call_op($1, $3, operator_type::PERIOD); }
	| expr ARROW expr
        { $$ = handle_call_op($1, $3, operator_type::ARROW); }

    //////////////////////////// 3 priority
    
	| DBLPLUS expr %prec PREFIXDBLPLUS
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_INCREMENT); }
	| DBLMINUS expr %prec PREFIXDBLMINUS
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_DECREMENT); }
	| PLUS expr %prec PREFIXPLUS
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_PLUS); }
	| MINUS expr %prec PREFIXMINUS
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_MINUS); }
	| EXCLPT expr
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_INV); }
	| TILDA expr
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_BITINV); }
	| OPEN_PARENTHESIS expr-with-comma CLOSE_PARENTHESIS expr %prec CAST
        { $$ = handle_call_op($2, $4, operator_type::TYPE_CAST); }
    | AMPERSAND expr %prec ADDRESS
		{ $$ = std::move($2); $$.push_back(operator_type::PREFIX_ADDRESS); }
	| SIZEOF expr
		{ $$ = std::move($2); $$.push_back(operator_type::SIZEOF); }

    //////////////////////////// 4 priority
    
    | expr PTAST expr
        { $$ = handle_call_op($1, $3, operator_type::MBPTR); }
    | expr ARROWAST expr
        { $$ = handle_call_op($1, $3, operator_type::PTRMBPTR); }

    //////////////////////////// 5 priority
    
    | expr ASTERISK expr
        { $$ = handle_call_op($1, $3, operator_type::MUL); }
    | expr SLASH expr
        { $$ = handle_call_op($1, $3, operator_type::DIV); }
    | expr PERCENT expr
        { $$ = handle_call_op($1, $3, operator_type::MOD); }


    //////////////////////////// 7 priority
    
	| expr LEFTSHIFT expr
        { $$ = handle_call_op($1, $3, operator_type::LEFTSHIFT); }
	| expr RIGHTSHIFT expr
        { $$ = handle_call_op($1, $3, operator_type::RIGHTSHIFT); }

    //////////////////////////// 8 priority

	| expr OPEN_BROKET expr
        { $$ = handle_call_op($1, $3, operator_type::LESS); }
    | expr LE expr
        { $$ = handle_call_op($1, $3, operator_type::LE); }
    | expr CLOSE_BROKET expr
        { $$ = handle_call_op($1, $3, operator_type::GREATER); }
    | expr GE expr
        { $$ = handle_call_op($1, $3, operator_type::GE); }

    //////////////////////////// 11 priority

	| expr EXCL expr
        { $$ = handle_call_op($1, $3, operator_type::BITXOR); }


    //////////////////////////// 14 priority

	| expr AND expr
        { $$ = handle_call_op($1, $3, operator_type::AND); }

    //////////////////////////// 14 priority

	| expr OR expr
        { $$ = handle_call_op($1, $3, operator_type::OR); }

    //////////////////////////// 15 priority

    | expr QMARK expr COLON expr
        {
			$$ = std::move($1);
			$$.insert($$.end(), std::make_move_iterator($3.begin()), std::make_move_iterator($3.end()));
            $$.insert($$.end(), std::make_move_iterator($5.begin()), std::make_move_iterator($5.end()));
			$$.push_back(operator_type::IFF);
		}
    | expr ASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::ASSIGN); }
    | expr ADDASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::ADDASSIGN); }
    | expr SUBASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::SUBASSIGN); }
    | expr MULASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::MULASSIGN); }
    | expr DIVASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::DIVASSIGN); }
    | expr MODASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::MODASSIGN); }
    | expr LSHIFTSSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::LSHIFTSSIGN); }
    | expr RSHIFTSSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::RSHIFTSSIGN); }
    | expr BITANDASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::BITANDASSIGN); }
    | expr BITORASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::BITORASSIGN); }
    | expr BITXORASSIGN expr
        { $$ = handle_call_op($1, $3, operator_type::BITXORASSIGN); }
    | THROW expr
        {
			$$ = std::move($2);
			$$.push_back(operator_type::THROW);
		}
        
//	| expr COMMA expr
//        {
//            $$ = std::move($1);
//            $$.insert($$.end(), std::make_move_iterator($3.begin()), std::make_move_iterator($3.end()));
//            $$.push_back(operator_type::COMMA);
//		}

	;
*/
    //////////////////////////// 16 priority
    
    /*
expr-with-comma:
      expr
    | expr-with-comma COMMA expr
        {
            $$ = std::move($1);
            $$.insert($$.end(), std::make_move_iterator($3.begin()), std::make_move_iterator($3.end()));
            $$.push_back(operator_type::COMMA);
		}
	;
    
opt-expr:
      %empty { $$ = expression_list{}; }
    | expr-with-comma
    ;
    */
%%
