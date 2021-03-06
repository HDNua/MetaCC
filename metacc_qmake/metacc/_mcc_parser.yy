%{
// # vim: tabstop=4 shiftwidth=4
#include <cstdio>
#include <cstdlib>


#include "ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048



ast::symbol_definition_list *symbol_definition_list;



int yylex();
int yyerror(char const *str);

%}
%union {
    char                                    token_str[MAX_TOKEN_LEN];

    class ast::list<ast::object *>          *ast_list;
    class ast::symbol_definition_list       *ast_symbol_definition_list;
    class ast::symbol_value_list            *ast_symbol_value_list;
    class ast::symbol_value_element_list    *ast_symbol_value_element_list;

    class ast::symbol_definition            *ast_symbol_definition;
    class ast::symbol_key                   *ast_symbol_key;
    class ast::key_attributes               *ast_key_attributes;
    class ast::symbol_value                 *ast_symbol_value;
    class ast::symbol_value_element         *ast_symbol_value_element;
    class ast::list_parameter               *ast_list_parameter;
    class ast::option_parameter             *ast_option_parameter;
    class ast::star_parameter               *ast_star_parameter;
    class ast::list_parameter_value         *ast_list_parameter_value;
    class ast::option_parameter_value       *ast_option_parameter_value;
    class ast::star_parameter_value         *ast_star_parameter_value;
    class ast::token_definition             *ast_token_definition;
}

%token	COLON SEMICOLON
%token	MCC_STRING
%token	MCC_SYMBOL MCC_METHOD

%token	VBAR LP RP COMMA
%token	LIST OPTION STAR
%token	CSTRING NULL_
%token	SKIP TERMINAL
%token	TOKEN

%type <token_str> MCC_STRING
%type <token_str> MCC_SYMBOL MCC_METHOD
%type <token_str> list_parameter_delim
%type <token_str> SKIP TERMINAL TOKEN

%type <ast_symbol_definition_list> symbol_definition_list
%type <ast_symbol_value_list> symbol_value_list
%type <ast_symbol_value_element_list> symbol_value_element_list

%type <ast_symbol_definition> symbol_definition
%type <ast_symbol_key> symbol_key
%type <ast_key_attributes> key_attributes
%type <ast_symbol_value> symbol_value
%type <ast_symbol_value_element> symbol_value_element
%type <ast_list_parameter> list_parameter
%type <ast_option_parameter> option_parameter
%type <ast_star_parameter> star_parameter
%type <ast_list_parameter_value> list_parameter_value
%type <ast_option_parameter_value> option_parameter_value
%type <ast_star_parameter_value> star_parameter_value
%type <ast_token_definition> token_definition

%%
source_text
        : symbol_definition_list
        {
                symbol_definition_list = $1;
        }
        ;
symbol_definition_list
        : symbol_definition
        {
                ast::symbol_definition_list *list = new ast::symbol_definition_list();
                if ($1 == nullptr) { puts("1"); }
                list->append($1);
                $$ = list;
        }
        | symbol_definition_list symbol_definition
        {
                if ($2 == nullptr) { puts("2"); }
                $1->append($2);
                $$ = $1;
        }
        ;
symbol_definition
        : symbol_key COLON symbol_value_list SEMICOLON
        {
                ast::symbol_definition *ret = new ast::symbol_definition($1, $3);
                $$ = ret;
        }
        ;
symbol_key
        : MCC_SYMBOL
        {
                ast::symbol_key *ret = new ast::symbol_key($1, nullptr);
                $$ = ret;
        }
        | MCC_SYMBOL key_attributes
        {
                ast::symbol_key *ret = new ast::symbol_key($1, $2);
                $$ = ret;
        }
        ;
key_attributes
        : SKIP
        {
                ast::key_attributes *ret = new ast::key_attributes($1);
                $$ = ret;
        }
        | TERMINAL
        {
                ast::key_attributes *ret = new ast::key_attributes($1);
                $$ = ret;
        }
        ;
symbol_value_list
        : symbol_value
        {
                ast::symbol_value_list *list = new ast::symbol_value_list();
                if ($1 == nullptr) { puts("symbol_value_list found nullptr parameter $1;"); }
                list->append($1);
                $$ = list;
        }
        | symbol_value_list VBAR symbol_value
        {
                if ($3 == nullptr) { puts("symbol_value_list found nullptr parameter $3;"); }
                $1->append($3);
                $$ = $1;
        }
        ;
symbol_value
        : symbol_value_element_list
        {
                ast::symbol_value *ret = new ast::symbol_value($1);
                $$ = ret;
        }
        ;
symbol_value_element_list
        : symbol_value_element
        {
                ast::symbol_value_element_list *list = new ast::symbol_value_element_list();
                if ($1 == nullptr) { puts("5"); }
                list->append($1);
                $$ = list;
        }
        | symbol_value_element_list symbol_value_element
        {
                if ($2 == nullptr) { puts("6"); }
                $1->append($2);
                $$ = $1;
        }
        ;
symbol_value_element
        : MCC_STRING
        {
                ast::mcc_string *ret = new ast::mcc_string($1);
                $$ = ret;
        }
        | MCC_SYMBOL
        {
                ast::mcc_symbol *ret = new ast::mcc_symbol($1);
                $$ = ret;
        }
        | LIST LP list_parameter RP
        {
                $$ = $3;
        }
        | OPTION LP option_parameter RP
        {
                $$ = $3;
        }
        | STAR LP star_parameter RP
        {
                $$ = $3;
        }
        | NULL_
        {
                $$ = nullptr;
        }
        | token_definition
        {
                $$ = $1;
        }
        ;
list_parameter
        : list_parameter_value COMMA list_parameter_delim
        {
                ast::list_parameter *ret = new ast::list_parameter($1, $3);
                $$ = ret;
        }
        ;
option_parameter
        : option_parameter_value
        {
                ast::option_parameter *ret = new ast::option_parameter($1);
                $$ = ret;
        }
        ;
star_parameter
        : star_parameter_value
        {
                ast::star_parameter *ret = new ast::star_parameter($1);
                $$ = ret;
        }
        ;
list_parameter_value
        : symbol_value_list
        {
                ast::list_parameter_value *ret = new ast::list_parameter_value($1);
                $$ = ret;
        }
        ;
list_parameter_delim
        : MCC_STRING
        ;
option_parameter_value
        : symbol_value_list
        {
                ast::option_parameter_value *ret = new ast::option_parameter_value($1);
                $$ = ret;
        }
        ;
star_parameter_value
        : list_parameter_value // symbol_value_list
        {
                ast::list_parameter *lp = new ast::list_parameter($1, "");
                ast::star_parameter_value *ret = new ast::star_parameter_value(lp);
                $$ = ret;
        }
        ;
token_definition
        : TOKEN LP MCC_STRING RP
        {
                ast::token_definition *ret = new ast::token_definition($3, "");
                $$ = ret;
        }
        ;


/*************************************************************/
%%
int line_count = 0;

//
int
yyerror(char const *str)
{
        extern char *yytext;
        fprintf(stderr, "%4d: %s: syntax error \n", line_count, yytext);
        return 0;
}

//
int main(int argc, const char *argv[]) {
        extern int metacc_init(int, const char *[]);
        extern int metacc_main(int, const char *[]);

        if (metacc_init(argc, argv) == 0) {
                return metacc_main(argc, argv);
        }
        else {
                return 0;
        }
}






