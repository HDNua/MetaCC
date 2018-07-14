%{
# vim: tabstop=4 shiftwidth=4
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1


int yylex();

int yyerror(char const *str);

%}
%union {
	char    token_str[MAX_TOKEN_LEN];
}
%token	<double_value>	DOUBLE_LITERAL;

%token	ADD SUB MUL DIV CR



%type	<double_value> expression term primary_expression;
%type	<token_value> string
%%




/*
 * A1.3 Module and primitive source text
 */
source_text
	: { description }
	;

description
	: module_declaration
	| udp_declaration
	;

module_declaration
	: { attribute_instance } module_keyword module_identifier [ module_parameter_port_list ] 
		[ list_of_ports ] ; { module_item } 
		endmodule
	| { attribute_instance } module_keyword module_identifier [ module_parameter_port_list ] 
		[ list_of_port_declarations ] ; { non_port_module_item }
		endmodule
	;

module_keyword
	: module
	| macromodule



/*
 * A1.4 Module parameters and ports
 */
module_parameter_port_list
	: # ( parameter_declaration { , parameter_declaration } )

list_of_ports
	: ( port { , port } )

list_of_port_declarations
	: ( port_declaration { , port_declaration } )
	| ( )

port
	: [ port_expression ]
	| .port_identifier ( [ port_expression ] )

port_expression
	: port_reference
	| { port_reference { , port_reference } }

port_reference
	: port_identifier
	| port_identifier [ constant_expression ]
	| port_identifier [ range_expression ]
    ;

port_declaration
	: { attribute_instance } inout_declaration
	| { attribute_instance } input_declaration
	| { attribute_instance } output_declaration
    ;


/*
 * A1.5 Module Items
 */
module_item
	: module_or_generate_item
	| port_declaration ;
	| { attribute_instance } generated_instantiation
	| { attribute_instance } local_parameter_declaration
	| { attribute_instance } parameter_declaration
	| { attribute_instance } specify_block
	| { attribute_instance } specparam_declaration
    ;



/*
 * A2.1.1 Module Parameter declarations
 */



/*
 * A
 */



/*
 * A
 */



/*
 * A
 */



/*
 * A
 */



/*
 * A
 */



/*
 * A
 */













/*************************************************************/
%%
int
yyerror(char const *str)
{
	extern char *yytext;
	fprintf(stderr, "parser error near %s \n", yytext);
	return 0;
}

int main(void) {
	extern int yyparse(void);
	extern FILE *yyin;

	yyin = stdin;
	if (yyparse()) {
		fprintf(stderr, "ERROR \n");
	}
}
