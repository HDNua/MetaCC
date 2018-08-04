%{
#include <stdio.h>
#include <stdlib.h>

#include "parser_ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048
#define new(TYPE) (TYPE *)malloc(sizeof(TYPE))



struct ast_list *start_list;



int yylex();
int yyerror(char const *str);

%}
%union {
    char token_str[MAX_TOKEN_LEN];
    struct ast_line_list *ast_line_list;
    struct ast_line      *ast_line;
    struct ast_expr      *ast_expr;
    struct ast_term      *ast_term;
    struct ast_primary   *ast_primary;
}




%token TOKEN_0     /* ; */
%token TOKEN_1     /* + */
%token TOKEN_2     /* - */
%token TOKEN_3     /* * */
%token TOKEN_4     /* / */
%token TOKEN_5     /* ( */
%token TOKEN_6     /* ) */
%token INTEGER      /* INTEGER */
%type <ast_line_list>   line_list
%type <ast_line>        line
%type <ast_expr>        expr
%type <ast_term>        term
%type <ast_primary>     primary
%type <token_str> INTEGER

%%



start
    : line_list
    ;




line_list 
    : line 
    {
        struct ast_line_list *ret = new (struct ast_line_list);
        $$ = ret;
    }
    | line_list line 
    {
        struct ast_line_list *ret = new (struct ast_line_list);
        $$ = ret;
    }
    ;

line 
    : expr TOKEN_0 /* ; */ 
    {
        struct ast_line *ret = new (struct ast_line);
        $$ = ret;
    }
    ;

expr 
    : expr TOKEN_1 /* + */ term 
    {
        struct ast_expr *ret = new (struct ast_expr);
        $$ = ret;
    }
    | expr TOKEN_2 /* - */ term 
    {
        struct ast_expr *ret = new (struct ast_expr);
        $$ = ret;
    }
    | term 
    {
        struct ast_expr *ret = new (struct ast_expr);
        $$ = ret;
    }
    ;

term 
    : term TOKEN_3 /* * */ primary 
    {
        struct ast_term *ret = new (struct ast_term);
        $$ = ret;
    }
    | term TOKEN_4 /* / */ primary 
    {
        struct ast_term *ret = new (struct ast_term);
        $$ = ret;
    }
    | primary 
    {
        struct ast_term *ret = new (struct ast_term);
        $$ = ret;
    }
    ;

primary 
    : INTEGER 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | TOKEN_5 /* ( */ expr TOKEN_6 /* ) */ 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    ;


%%
int line_count = 0;

// 
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "%5d: %s: syntax error", line_count, yytext);
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
