%{
// # vim: tabstop=4 shiftwidth=4
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048


struct ast_list *symbol_definition_list;



int yylex();
int yyerror(char const *str);

%}
%union {
	char                                    token_str[MAX_TOKEN_LEN];
	
	struct ast_list                         *ast_list;
	struct ast_symbol_definition            *ast_symbol_definition;
	struct ast_symbol_key                   *ast_symbol_key;
	struct ast_key_attributes               *ast_key_attributes;
	struct ast_symbol_value                 *ast_symbol_value;
	struct ast_symbol_value_element         *ast_symbol_value_element;
	struct ast_list_parameter               *ast_list_parameter;
	struct ast_option_parameter             *ast_option_parameter;
	struct ast_star_parameter               *ast_star_parameter;
	struct ast_list_parameter_value         *ast_list_parameter_value;
	struct ast_option_parameter_value       *ast_option_parameter_value;
	struct ast_star_parameter_value         *ast_star_parameter_value;
}

%token	COLON SEMICOLON
%token	MCC_STRING
%token	MCC_SYMBOL MCC_METHOD

%token	VBAR LP RP COMMA
%token	LIST OPTION STAR

%type <token_str> MCC_STRING
%type <token_str> MCC_SYMBOL MCC_METHOD
%type <token_str> list_parameter_delim

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
// %type <ast_symbol_value_element> list_parameter_value
// %type <ast_symbol_value_element> option_parameter_value
// %type <ast_symbol_value_element> star_parameter_value



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
		struct ast_list *list = ast_list_new(AST_SYMBOL_DEFINITION);
		ast_list_append(list, $1, AST_SYMBOL_DEFINITION);
		$$ = list;
	}
	| symbol_definition_list symbol_definition
	{
		ast_list_append($1, $2, AST_SYMBOL_DEFINITION);
		$$ = $1;
	}
	;
symbol_definition
	: symbol_key COLON symbol_value_list SEMICOLON 
	{
		struct ast_symbol_definition *ret = 
			(struct ast_symbol_definition *)malloc(sizeof(struct ast_symbol_definition));
		ret->ast_symbol_key = $1;
		ret->ast_symbol_value_list = $3;
		$$ = ret;
	}
	;
symbol_key
	: MCC_SYMBOL 
	{
		struct ast_symbol_key *ret = 
			(struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		ret->symbol_name = strdup($1);
		ret->ast_key_attributes = NULL;
		$$ = ret;
	}
	/*
	| MCC_SYMBOL key_attributes
	{
		struct ast_symbol_key *ret = 
			(struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		ret->symbol_name = strdup($1);
		ret->ast_key_attributes = NULL;
		$$ = ret;
	}
	*/
	;
key_attributes
	: "CANNOT_MATCH_STRING"
	{
		$$ = NULL;
	}
	;
symbol_value_list
	: symbol_value
	{
		struct ast_list *list = (struct ast_list *)malloc(sizeof(struct ast_list));
		ast_list_append(list, $1, AST_SYMBOL_VALUE);
		$$ = list;
	}
	| symbol_value_list VBAR symbol_value
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ast_list_append($1, $3, AST_SYMBOL_VALUE);
		$$ = $1;
	}
	;
symbol_value
	: symbol_value_element_list
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ret->ast_symbol_value_element_list = $1;
		$$ = ret;
	}
	;
symbol_value_element_list
	: symbol_value_element
	{
		struct ast_list *list = ast_list_new(AST_SYMBOL_VALUE_ELEMENT);
		ast_list_append(list, $1, AST_SYMBOL_VALUE_ELEMENT);
		$$ = list;
	}
	| symbol_value_element_list symbol_value_element
	{
		ast_list_append($1, $2, AST_SYMBOL_VALUE_ELEMENT);
		$$ = $1;
	}
	;
symbol_value_element
	: MCC_STRING
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_STRING;
		ret->u.string = strdup($1);
		$$ = ret;
	}
	| MCC_SYMBOL
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_SYMBOL;
		ret->u.mcc_symbol = strdup($1);
		$$ = ret;
	}
	| LIST LP list_parameter RP
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_LIST_PARAMETER;
		ret->u.ast_list_parameter = $3;
		$$ = ret;
	}
	| OPTION LP option_parameter RP
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_OPTION_PARAMETER;
		ret->u.ast_option_parameter = $3;
		$$ = ret;
	}
	| STAR LP star_parameter RP
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_STAR_PARAMETER;
		ret->u.ast_star_parameter = $3;
		$$ = ret;
	}
	;
list_parameter
	: list_parameter_value COMMA list_parameter_delim
	{
		struct ast_list_parameter *ret = 
			(struct ast_list_parameter *)malloc(sizeof(struct ast_list_parameter));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_list_parameter_value = $1;
		ret->ast_list_parameter_delim = $3;
		$$ = ret;
	}
	;
option_parameter
	: option_parameter_value
	{
		struct ast_option_parameter *ret = 
			(struct ast_option_parameter *)malloc(sizeof(struct ast_option_parameter));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_option_parameter_value = $1;
		$$ = ret;
	}
	;
star_parameter
	: star_parameter_value
	{
		struct ast_star_parameter *ret = (struct ast_star_parameter *)
			malloc(sizeof(struct ast_star_parameter));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_star_parameter_value = $1;
		$$ = ret;
	}
	;
list_parameter_value
	: symbol_value_element
	{
		struct ast_list_parameter_value *ret = (struct ast_list_parameter_value *)
			malloc(sizeof(struct ast_list_parameter_value));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_symbol_value_element = $1;
		$$ = ret;
	}
	;
list_parameter_delim
	: MCC_STRING
	;
option_parameter_value
	: symbol_value_element
	{
		struct ast_option_parameter_value *ret = (struct ast_option_parameter_value *)
			malloc(sizeof(struct ast_option_parameter_value));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_symbol_value_element = $1;
		$$ = ret;
	}
	;
star_parameter_value
	: symbol_value_element
	{
		struct ast_star_parameter_value *ret = (struct ast_star_parameter_value *)
			malloc(sizeof(struct ast_star_parameter_value));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_symbol_value_element = $1;
		$$ = ret;
	}
	;



/*************************************************************/
%%

int line_count = 0;

int
yyerror(char const *str)
{
	extern char *yytext;
	fprintf(stderr, "%4d: %s: syntax error \n", line_count, yytext);
	return 0;
}

int main(void) {
	extern int yyparse(void);
	extern FILE *yyin;

	yyin = stdin;
	if (yyparse()) {
		fprintf(stderr, "ERROR \n");
	}

	return 0;
}
