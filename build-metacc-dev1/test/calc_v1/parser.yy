%{
#include <cstdio>
#include <cstdlib>

#include "parser_ast.h"
const int MAX_TOKEN_LEN = 2048;



class ast::object *start;
// class ast::library_text *start_library_text;
// class ast::source_text *start_source_text;



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
}



%token TOKEN_0     /* ; */
%token TOKEN_1     /* + */
%token TOKEN_2     /* - */
%token TOKEN_3     /* * */
%token TOKEN_4     /* / */
%token TOKEN_5     /* ( */
%token TOKEN_6     /* ) */
%token SV_UNSIGNED_INTEGER /* SV_UNSIGNED_INTEGER */
%token SV_STRING    /* SV_STRING */
%token SV_IDENTIFIER /* SV_IDENTIFIER */
%token SV_INTEGER
%token SV_ESCAPED_IDENTIFIER
%token SV_UNSIGNED_NUMBER
%token SV_DECIMAL_NUMBER
%token SV_BINARY_NUMBER
%token SV_OCTAL_NUMBER
%token SV_HEX_NUMBER
%token SV_FIXED_POINT_NUMBER
%token SV_EXPONENTIAL_NUMBER
%type <ast_line_list>   line_list
%type <ast_line>        line
%type <ast_expr>        expr
%type <ast_term>        term
%type <ast_primary>     primary
%type <ast_list> LIST_0
%type <token_str> TOKEN_0
%type <token_str> TOKEN_1
%type <token_str> TOKEN_2
%type <token_str> TOKEN_3
%type <token_str> TOKEN_4
%type <token_str> TOKEN_5
%type <token_str> TOKEN_6
%type <token_str> SV_UNSIGNED_INTEGER
%type <token_str> SV_STRING
%type <token_str> SV_IDENTIFIER
%type <token_str> SV_INTEGER


%%




start_calc
	: line_list
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
        $$ = ret;
    }
    ;

line 
    : expr TOKEN_0 /* ; */ 
    {
        ast::line *ret = new ast::line;
        $$ = ret;
    }
    ;

expr 
    : expr TOKEN_1 /* + */ term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    | expr TOKEN_2 /* - */ term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    | term 
    {
        ast::expr *ret = new ast::expr;
        $$ = ret;
    }
    ;

term 
    : term TOKEN_3 /* * */ primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    | term TOKEN_4 /* / */ primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    | primary 
    {
        ast::term *ret = new ast::term;
        $$ = ret;
    }
    ;

primary 
    : SV_UNSIGNED_INTEGER 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | SV_STRING 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | SV_IDENTIFIER 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | TOKEN_5 /* ( */ expr TOKEN_6 /* ) */ 
    {
        ast::primary *ret = new ast::primary;
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
    
    return 0;
}
