%{
// # vim: tabstop=4 shiftwidth=4
// #include <stdio.h>
// #include <stdlib.h>
#include <cstdio>
#include <cstdlib>


#include "ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048


ast::list *symbol_definition_list;



int yylex();
int yyerror(char const *str);

%}
%union {
    char                                    token_str[MAX_TOKEN_LEN];
											
    class ast::list                         *ast_list;
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

%type <ast_list> symbol_definition_list
%type <ast_list> symbol_value_list 
%type <ast_list> symbol_value_element_list
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
		// struct ast_list *list = ast_list_new(AST_SYMBOL_DEFINITION);
		// ast_list_append(list, $1, AST_SYMBOL_DEFINITION);
		// $$ = list;
		ast::list *list = new ast::list(ast::AST_SYMBOL_DEFINITION);
		if ($1 == nullptr) { puts("1"); }
		list->append($1, ast::AST_SYMBOL_DEFINITION);
		$$ = list;
	}
	| symbol_definition_list symbol_definition
	{
		// ast_list_append($1, $2, AST_SYMBOL_DEFINITION);
		// $$ = $1;
		if ($2 == nullptr) { puts("2"); }
		$1->append($2, ast::AST_SYMBOL_DEFINITION);
		$$ = $1;
	}
	;
symbol_definition
	: symbol_key COLON symbol_value_list SEMICOLON 
	{
		// struct ast_symbol_definition *ret = 
		//     (struct ast_symbol_definition *)malloc(sizeof(struct ast_symbol_definition));
		// ret->type = AST_SYMBOL_DEFINITION;
		// ret->ast_symbol_key = $1;
		// ret->ast_symbol_value_list = $3;
		// $$ = ret;
		ast::symbol_definition *ret = new ast::symbol_definition($1, $3);
		$$ = ret;
	}
	;
symbol_key
	: MCC_SYMBOL 
	{
		// struct ast_symbol_key *ret = 
		//     (struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		// ret->type = AST_SYMBOL_KEY;
		// ret->symbol_name = strdup($1);
		// ret->ast_key_attributes = NULL;
		// $$ = ret;
		ast::symbol_key *ret = new ast::symbol_key($1, nullptr);
		$$ = ret;
	}
	| MCC_SYMBOL key_attributes
	{
		// struct ast_symbol_key *ret = 
		//     (struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		// ret->type = AST_SYMBOL_KEY;
		// ret->symbol_name = strdup($1);
		// ret->ast_key_attributes = $2;
		// $$ = ret;
		ast::symbol_key *ret = new ast::symbol_key($1, $2);
		$$ = ret;
	}
	;
key_attributes
	: SKIP
	{
		// struct ast_key_attributes *ret = 
		// 	(struct ast_key_attributes *)malloc(sizeof(struct ast_key_attributes));
		// ret->type = AST_KEY_ATTRIBUTES;
		// ret->attributes = strdup($1);
		// $$ = ret;
		ast::key_attributes *ret = new ast::key_attributes($1);
		$$ = ret;
	}
	| TERMINAL
	{
		// struct ast_key_attributes *ret = 
		//     (struct ast_key_attributes *)malloc(sizeof(struct ast_key_attributes));
		// ret->type = AST_KEY_ATTRIBUTES;
		// ret->attributes = strdup($1);
		// $$ = ret;
		ast::key_attributes *ret = new ast::key_attributes($1);
		$$ = ret;
	}
	;
symbol_value_list
	: symbol_value
	{
		// struct ast_list *list = ast_list_new(AST_SYMBOL_VALUE);
		// ast_list_append(list, $1, AST_SYMBOL_VALUE);
		// $$ = list;
		ast::list *list = new ast::list(ast::AST_SYMBOL_VALUE);
		if ($1 == nullptr) { puts("3"); }
		list->append($1, ast::AST_SYMBOL_VALUE);
		$$ = list;
	}
	| symbol_value_list VBAR symbol_value
	{
		// struct ast_symbol_value *ret = 
		//     (struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		// ret->type = AST_SYMBOL_VALUE;
		// ast_list_append($1, $3, AST_SYMBOL_VALUE);
		// $$ = $1;
		if ($3 == nullptr) { puts("4"); }
		$1->append($3, ast::AST_SYMBOL_VALUE);
		$$ = $1;
	}
	;
symbol_value
	: symbol_value_element_list
	{
		// struct ast_symbol_value *ret = 
		//     (struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		// ret->type = AST_SYMBOL_VALUE;
		// ret->ast_symbol_value_element_list = $1;
		// $$ = ret;
		ast::symbol_value *ret = new ast::symbol_value($1);
		$$ = ret;
	}
	;
symbol_value_element_list
	: symbol_value_element
	{
		// struct ast_list *list = ast_list_new(AST_SYMBOL_VALUE_ELEMENT);
		// ast_list_append(list, $1, AST_SYMBOL_VALUE_ELEMENT);
		// $$ = list;
		ast::list *list = new ast::list(ast::AST_SYMBOL_VALUE_ELEMENT);
		if ($1 == nullptr) { puts("5"); }
		list->append($1, ast::AST_SYMBOL_VALUE_ELEMENT);
		$$ = list;
	}
	| symbol_value_element_list symbol_value_element
	{
		// ast_list_append($1, $2, AST_SYMBOL_VALUE_ELEMENT);
		// $$ = $1;
		if ($2 == nullptr) { puts("6"); }
		$1->append($2, ast::AST_SYMBOL_VALUE_ELEMENT);
		$$ = $1;
	}
	;
symbol_value_element
	: MCC_STRING
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_MCC_STRING;
		// ret->u.mcc_string = strdup($1);
		// $$ = ret;
		ast::mcc_string *ret = new ast::mcc_string($1);
		$$ = ret;
	}
	| MCC_SYMBOL
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_MCC_SYMBOL;
		// ret->u.mcc_symbol = strdup($1);
		// $$ = ret;
		ast::mcc_symbol *ret = new ast::mcc_symbol($1);
		$$ = ret;
	}
	| LIST LP list_parameter RP
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_LIST_PARAMETER;
		// ret->u.ast_list_parameter = $3;
		// $$ = ret;
		$$ = $3;
	}
	| OPTION LP option_parameter RP
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_OPTION_PARAMETER;
		// ret->u.ast_option_parameter = $3;
		// $$ = ret;
		$$ = $3;
	}
	| STAR LP star_parameter RP
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_STAR_PARAMETER;
		// ret->u.ast_star_parameter = $3;
		// $$ = ret;
		$$ = $3;
	}
	| NULL_
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_NULL;
		// ret->u.null_ = NULL; // strdup($1);
		// $$ = ret;
		$$ = nullptr;
	}
	| token_definition
	{
		// struct ast_symbol_value_element *ret = 
		//     (struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		// ret->type = AST_SYMBOL_VALUE_ELEMENT;
		// ret->elem_type = AST_TOKEN_DEFINITION;
		// ret->u.ast_token_definition = $1;
		// $$ = ret;
		$$ = $1;
	}
	;
list_parameter
	: list_parameter_value COMMA list_parameter_delim
	{
		// struct ast_list_parameter *ret = 
		//     (struct ast_list_parameter *)malloc(sizeof(struct ast_list_parameter));
		// ret->type = AST_LIST_PARAMETER;
		// ret->ast_list_parameter_value = $1;
		// ret->list_parameter_delim = strdup($3);
		// $$ = ret;

		ast::list_parameter *ret = new ast::list_parameter($1, $3);
		$$ = ret;
	}
	;
option_parameter
	: option_parameter_value
	{
		// struct ast_option_parameter *ret = 
		//     (struct ast_option_parameter *)malloc(sizeof(struct ast_option_parameter));
		// ret->type = AST_OPTION_PARAMETER;
		// ret->ast_option_parameter_value = $1;
		// $$ = ret;
		ast::option_parameter *ret = new ast::option_parameter($1);
		$$ = ret;
	}
	;
star_parameter
	: star_parameter_value
	{
		// struct ast_star_parameter *ret = (struct ast_star_parameter *)
		//     malloc(sizeof(struct ast_star_parameter));
		// ret->type = AST_STAR_PARAMETER;
		// ret->ast_star_parameter_value = $1;
		// $$ = ret;
		ast::star_parameter *ret = new ast::star_parameter($1);
		$$ = ret;
	}
	;
list_parameter_value
	: symbol_value_list
	{
		// struct ast_list_parameter_value *ret = (struct ast_list_parameter_value *)
		//     malloc(sizeof(struct ast_list_parameter_value));
		// ret->type = AST_LIST_PARAMETER_VALUE;
		// ret->ast_symbol_value_list = $1;
		// $$ = ret;
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
		// struct ast_option_parameter_value *ret = (struct ast_option_parameter_value *)
		// 	malloc(sizeof(struct ast_option_parameter_value));
		// ret->type = AST_OPTION_PARAMETER_VALUE;
		// ret->ast_symbol_value_list = $1;
		// $$ = ret;
		ast::option_parameter_value *ret = new ast::option_parameter_value($1);
		$$ = ret;
	}
	;
star_parameter_value
	: symbol_value_list
	{
		// struct ast_star_parameter_value *ret = (struct ast_star_parameter_value *)
		//     malloc(sizeof(struct ast_star_parameter_value));
		// ret->type = AST_STAR_PARAMETER_VALUE;
		// ret->ast_symbol_value_list = $1;
		// $$ = ret;
		ast::star_parameter_value *ret = new ast::star_parameter_value($1);
		$$ = ret;
	}
	;
token_definition
	: TOKEN LP MCC_STRING RP
	{
		// struct ast_token_definition *ret = (struct ast_token_definition *)
		//     malloc(sizeof(struct ast_token_definition));
		// ret->type = AST_TOKEN_DEFINITION;
		// ret->token_key = strdup($3);
		//     // ret->token_value = strdup($5);
		// $$ = ret;
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






