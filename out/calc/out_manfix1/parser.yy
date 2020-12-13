%{
#include <cstdio>
#include <cstdlib>

#include "parser_ast.h"
const int MAX_TOKEN_LEN = 2048;



class ast::object *start;
class ast::object *start_library_text;
class ast::object *start_source_text;



int yylex();
int yyerror(char const *str);

%}
%union {
    char token_str[MAX_TOKEN_LEN];
    class ast::list<class ast::object *> *ast_list;
    
    ast::line_list *ast_line_list;
    ast::line      *ast_line;
    ast::expr      *ast_expr;
    ast::term      *ast_term;
    ast::primary   *ast_primary;
    ast::attribute *ast_attribute;
}



%token TOKEN_0 /* ; */
%token TOKEN_1 /* + */
%token TOKEN_2 /* - */
%token TOKEN_3 /* * */
%token TOKEN_4 /* / */
%token TOKEN_5 /* ( */
%token TOKEN_6 /* ) */
%token SV_UNSIGNED_NUMBER /* SV_UNSIGNED_NUMBER */
%token SV_DECIMAL_NUMBER /* SV_DECIMAL_NUMBER */
%token SV_BINARY_NUMBER /* SV_BINARY_NUMBER */
%token SV_OCTAL_NUMBER /* SV_OCTAL_NUMBER */
%token SV_HEX_NUMBER /* SV_HEX_NUMBER */
%token SV_STRING    /* SV_STRING */
%token SV_IDENTIFIER /* SV_IDENTIFIER */
%type <ast_line_list>   line_list
%type <ast_line>        line
%type <ast_expr>        expr
%type <ast_term>        term
%type <ast_primary>     primary
%type <ast_attribute>   attribute
%type <ast_list> LIST_0
%type <token_str> TOKEN_0
%type <token_str> TOKEN_1
%type <token_str> TOKEN_2
%type <token_str> TOKEN_3
%type <token_str> TOKEN_4
%type <token_str> TOKEN_5
%type <token_str> TOKEN_6
%type <token_str> SV_UNSIGNED_NUMBER
%type <token_str> SV_DECIMAL_NUMBER
%type <token_str> SV_BINARY_NUMBER
%type <token_str> SV_OCTAL_NUMBER
%type <token_str> SV_HEX_NUMBER
%type <token_str> SV_STRING
%type <token_str> SV_IDENTIFIER

%%




start_calc
	: line_list
	{
		start = $1;
	}
	;

// start
// 	: library_text
// 	{
// 		start_library_text = $1;
// 	}
// 	| source_text
// 	{
// 		start_source_text = $1;
// 	}
// 	;





line_list 
    : LIST_0 
    {
        ast::line_list *ret = new ast::line_list;
		ret->init_with_list($1);
        $$ = ret;
    }
    ;

line 
    : expr TOKEN_0 /* ; */ 
    {
        ast::line *ret = new ast::line;
		ret->init_with_expr($1);
        $$ = ret;
    }
    ;

expr 
    : expr TOKEN_1 /* + */ term 
    {
        ast::expr *ret = new ast::expr;
		ret->init_with_add($1, $2, $3);
        $$ = ret;
    }
    | expr TOKEN_2 /* - */ term 
    {
        ast::expr *ret = new ast::expr;
		ret->init_with_sub($1, $2, $3);
        $$ = ret;
    }
    | term 
    {
        ast::expr *ret = new ast::expr;
		ret->init_with_term($1);
        $$ = ret;
    }
    ;

term 
    : term TOKEN_3 /* * */ primary 
    {
        ast::term *ret = new ast::term;
		fprintf(stderr, "[parser.yy/term] OP IS [ %s ] \n", $2);
		ret->init_with_mul($1, $2, $3);
        $$ = ret;
    }
    | term TOKEN_4 /* / */ primary 
    {
        ast::term *ret = new ast::term;
		ret->init_with_div($1, $2, $3);
        $$ = ret;
    }
    | primary 
    {
        ast::term *ret = new ast::term;
		ret->init_with_primary($1);
        $$ = ret;
    }
    ;

primary 
    : SV_UNSIGNED_NUMBER
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_unsigned_number($1);
        $$ = ret;
    }
    | SV_DECIMAL_NUMBER
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_decimal_number($1);
        $$ = ret;
    }
    | SV_BINARY_NUMBER
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_binary_number($1);
        $$ = ret;
    }
    | SV_OCTAL_NUMBER
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_octal_number($1);
        $$ = ret;
    }
    | SV_HEX_NUMBER
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_hex_number($1);
        $$ = ret;
    }
    | SV_STRING
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_string($1);
        $$ = ret;
    }
    | attribute
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_attribute($1);
        $$ = ret;
    }
    | TOKEN_5 /* ( */ expr TOKEN_6 /* ) */
    {
        ast::primary *ret = new ast::primary;
		ret->init_with_expr($2);
        $$ = ret;
    }
    ;

attribute 
    : SV_IDENTIFIER
    {
        ast::attribute *ret = new ast::attribute;
		ret->init_with_identifier($1);
        $$ = ret;
    }
    ;

LIST_0
    : line 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        list->append($1);
        $$ = list;
    }
    | LIST_0  line 
    {
        $1->append($2);
        $$ = $1;
    }
    ;

%%
int line_count = 0;

// 
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "%5d: %s: syntax error\n", line_count, yytext);
    return 0;
}

// 
int main(int argc, const char *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;
    
    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Compilation error \n");
    }
    
	//
	if (argc == 2) {
		fprintf(stdout, "BEGINNING OF DESCRIPTION \n");
		if (start) {
			start->describe(ast::cs_info(0));
		}
		fprintf(stdout, "END OF DESCRIPTION \n");
	}

	//
    return 0;
}
