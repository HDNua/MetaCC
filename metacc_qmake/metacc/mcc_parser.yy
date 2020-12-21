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
    char                                      token_str[MAX_TOKEN_LEN];

    class ast::list<ast::object *>            *ast_list;
    class ast::symbol_definition_list         *ast_symbol_definition_list;
    class ast::symbol_value_list              *ast_symbol_value_list;
    class ast::symbol_value_element_list      *ast_symbol_value_element_list;
    class ast::symbol_value_initializer_list  *ast_symbol_value_initializer_list;
    class ast::field_declaration_list         *ast_field_declaration_list;
    class ast::method_declaration_list        *ast_method_declaration_list;

    class ast::symbol_definition              *ast_symbol_definition;
    class ast::symbol_key                     *ast_symbol_key;
    class ast::key_attributes                 *ast_key_attributes;
    class ast::symbol_value                   *ast_symbol_value;
    class ast::symbol_value_element           *ast_symbol_value_element;
    class ast::list_parameter                 *ast_list_parameter;
    class ast::option_parameter               *ast_option_parameter;
    class ast::star_parameter                 *ast_star_parameter;
    class ast::list_parameter_value           *ast_list_parameter_value;
    class ast::option_parameter_value         *ast_option_parameter_value;
    class ast::star_parameter_value           *ast_star_parameter_value;
    class ast::token_definition               *ast_token_definition;

    class ast::symbol_value_implementation    *ast_symbol_value_implementation;
    class ast::symbol_value_initializer       *ast_symbol_value_initializer;
    class ast::initializer_call               *ast_initializer_call;

    class ast::field_initializer              *ast_field_initializer;
    class ast::field_declaration              *ast_field_declaration;
    class ast::method_initializer             *ast_method_initializer;
    class ast::method_declaration             *ast_method_declaration;

    class ast::C_variable_declaration         *ast_C_variable_declaration;
    class ast::C_function_declaration         *ast_C_function_declaration;
    class ast::C_function_call                *ast_C_function_call;
    class ast::C_declaration_qualifier        *ast_C_declaration_qualifier;
    class ast::C_init_declarator_list         *ast_C_init_declarator_list;
    class ast::C_init_declarator              *ast_C_init_declarator;
    class ast::C_declarator                   *ast_C_declarator;
    class ast::C_direct_declarator            *ast_C_direct_declarator;
}

%token    COLON SEMICOLON
%token    MCC_STRING
%token    MCC_SYMBOL MCC_METHOD
%token  C_MCC_TYPE C_IDENTIFIER

%token    VBAR LP RP MLP MRP COMMA ASTERISK
%token    LIST OPTION STAR
%token    CSTRING NULL_
%token    SKIP TERMINAL
%token    TOKEN
%token  FIELDS METHODS

%type <token_str> MCC_STRING
%type <token_str> MCC_SYMBOL MCC_METHOD
%type <token_str> list_parameter_delim
%type <token_str> SKIP TERMINAL TOKEN
%type <token_str> C_MCC_TYPE C_IDENTIFIER

%type <ast_symbol_definition_list> symbol_definition_list
%type <ast_symbol_value_list> symbol_value_list
%type <ast_symbol_value_element_list> symbol_value_element_list
%type <ast_symbol_value_initializer_list> symbol_value_initializer_list
%type <ast_field_declaration_list> field_declaration_list
%type <ast_method_declaration_list> method_declaration_list

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
%type <ast_symbol_value_implementation> symbol_value_implementation
%type <ast_symbol_value_initializer> symbol_value_initializer
%type <ast_initializer_call> initializer_call 

%type <ast_field_initializer> field_initializer
%type <ast_field_declaration> field_declaration
%type <ast_method_initializer> method_initializer
%type <ast_method_declaration> method_declaration

%type <ast_C_variable_declaration> C_variable_declaration
%type <ast_C_function_declaration> C_function_declaration
%type <ast_C_function_call> C_function_call
%type <ast_C_declaration_qualifier> C_declaration_qualifier
%type <ast_C_init_declarator_list> C_init_declarator_list
%type <ast_C_init_declarator> C_init_declarator
%type <ast_C_declarator> C_declarator
%type <ast_C_direct_declarator> C_direct_declarator

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
                ast::symbol_definition *self = new ast::symbol_definition($1, $3);
                $$ = self;
        }
        | symbol_key METHODS method_initializer COLON symbol_value_list SEMICOLON
        {
                ast::symbol_definition *self = new ast::symbol_definition($1, $3, $5);
                $$ = self;
        }
        | symbol_key FIELDS field_initializer COLON symbol_value_list SEMICOLON
        {
                ast::symbol_definition *self = new ast::symbol_definition($1, $3, $5);
                $$ = self;
        }
        | symbol_key FIELDS field_initializer METHODS method_initializer COLON symbol_value_list SEMICOLON
        {
                ast::symbol_definition *self = new ast::symbol_definition($1, $3, $5, $7);
                $$ = self;
        }
        ;
symbol_key
        : MCC_SYMBOL
        {
                ast::symbol_key *self = new ast::symbol_key($1, nullptr);
                $$ = self;
        }
        | MCC_SYMBOL key_attributes
        {
                ast::symbol_key *self = new ast::symbol_key($1, $2);
                $$ = self;
        }
        ;
key_attributes
        : SKIP
        {
                ast::key_attributes *self = new ast::key_attributes($1);
                $$ = self;
        }
        | TERMINAL
        {
                ast::key_attributes *self = new ast::key_attributes($1);
                $$ = self;
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
        : symbol_value_element_list MLP symbol_value_implementation MRP
        {
                ast::symbol_value *self = new ast::symbol_value($1, $3);
                $$ = self;
        }
        | symbol_value_element_list
        {
                ast::symbol_value *self = new ast::symbol_value($1);
                $$ = self;
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
                ast::mcc_string *self = new ast::mcc_string($1);
                $$ = self;
        }
        | MCC_SYMBOL
        {
                ast::mcc_symbol *self = new ast::mcc_symbol($1);
                $$ = self;
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
                ast::list_parameter *self = new ast::list_parameter($1, $3);
                $$ = self;
        }
        ;
option_parameter
        : option_parameter_value
        {
                ast::option_parameter *self = new ast::option_parameter($1);
                $$ = self;
        }
        ;
star_parameter
        : star_parameter_value
        {
                ast::star_parameter *self = new ast::star_parameter($1);
                $$ = self;
        }
        ;
list_parameter_value
        : symbol_value_list
        {
                ast::list_parameter_value *self = new ast::list_parameter_value($1);
                $$ = self;
        }
        ;
list_parameter_delim
        : MCC_STRING
        ;
option_parameter_value
        : symbol_value_list
        {
                ast::option_parameter_value *self = new ast::option_parameter_value($1);
                $$ = self;
        }
        ;
star_parameter_value
        : list_parameter_value // symbol_value_list
        {
                ast::list_parameter *lp = new ast::list_parameter($1, "");
                ast::star_parameter_value *self = new ast::star_parameter_value(lp);
                $$ = self;
        }
        ;
token_definition
    : TOKEN LP MCC_STRING RP
    {
        ast::token_definition *self =
            new ast::token_definition($3, "");
        $$ = self;
    }
    ;
symbol_value_implementation
    : symbol_value_initializer_list
    {
        ast::symbol_value_implementation *self =
            new ast::symbol_value_implementation($1);
        $$ = self;
    }
    ;
symbol_value_initializer_list
    : symbol_value_initializer
    {
        ast::symbol_value_initializer_list *self =
            new ast::symbol_value_initializer_list();
        //self->append($1);
        //$$ = self;
    }
    | symbol_value_initializer_list symbol_value_initializer
    {
        $1->append($2);
        $$ = $1;
    }
    ;
symbol_value_initializer
    : initializer_call
    {
        ast::symbol_value_initializer *self = 
            new ast::symbol_value_initializer($1);
        $$ = self;
    }
    ;
initializer_call
    : C_function_call
    {
        ast::initializer_call *self
            = new ast::initializer_call($1);
        $$ = self;
    }
    ;

field_initializer
    : MLP field_declaration_list MRP
    {
        ast::field_initializer *self
            = new ast::field_initializer();
        self->init_with_field_declaration_list($2);
        $$ = self;
    }
    ;
field_declaration_list
    : field_declaration
    {
        ast::field_declaration_list *self
            = new ast::field_declaration_list();
        self->append($1);
        $$ = self;
    }
    | field_declaration_list field_declaration
    {
        $1->append($2);
        $$ = $1;
    }
    ;
field_declaration
    : C_variable_declaration
    {
        ast::field_declaration *self
            = new ast::field_declaration();
        self->init_with_C_variable_declaration($1);
        $$ = self;
    }
    ;

method_initializer
    : MLP method_declaration_list MRP
    {
        ast::method_initializer *self
            = new ast::method_initializer();
        self->init_with_method_declaration_list($2);
        $$ = self;
    }
    ;
method_declaration_list
    : method_declaration
    {
        ast::method_declaration_list *self
            = new ast::method_declaration_list();
        self->append($1);
        $$ = self;
    }
    | method_declaration_list method_declaration
    {
        $1->append($2);
        $$ = $1;
    }
    ;
method_declaration
    : C_function_declaration
    {
        ast::method_declaration *self
            = new ast::method_declaration();
        self->init_with_C_function_declaration($1);
        $$ = self;
    }
    ;

C_variable_declaration
    : C_declaration_qualifier C_init_declarator_list SEMICOLON
    {
        ast::C_variable_declaration *self
            = new ast::C_variable_declaration();
        self->init_with_1($1, $2);
        $$ = self;
    }
    ;
C_function_declaration
    : C_declaration_qualifier C_direct_declarator LP RP SEMICOLON
    {
        ast::C_function_declaration *self
            = new ast::C_function_declaration();
        self->init_with_1($1, $2);
        $$ = self;
    }
    ;
C_function_call
    : C_direct_declarator LP RP SEMICOLON
    {
        ast::C_function_call *self
            = new ast::C_function_call();
        self->init_with_1($1);
        $$ = self;
    }
    ;
C_declaration_qualifier
    : C_MCC_TYPE
    {
        ast::C_declaration_qualifier *self
            = new ast::C_declaration_qualifier();
        self->init_with_C_MCC_TYPE($1);
        $$ = self;
    }
    | MCC_SYMBOL
    {
        ast::C_declaration_qualifier *self
            = new ast::C_declaration_qualifier();
        self->init_with_MCC_SYMBOL($1);
        $$ = self;
    }
    ;
C_init_declarator_list
    : C_init_declarator
    {
        ast::C_init_declarator_list *self
            = new ast::C_init_declarator_list();
        self->append($1);
        $$ = self;
    }
    | C_init_declarator_list C_init_declarator
    {
        $1->append($2);
        $$ = $1;
    }
    ;
C_init_declarator
    : C_declarator
    {
        ast::C_init_declarator *self
            = new ast::C_init_declarator();
        self->init_with_C_declarator($1);
        $$ = self;
    }
    ;
C_declarator
    : ASTERISK C_declarator
    {
        ast::C_declarator *self
            = new ast::C_declarator();
        self->init_with_ASTERISK_C_declarator($2);
        $$ = self;
    }
    | C_direct_declarator
    {
        ast::C_declarator *self
            = new ast::C_declarator();
        self->init_with_C_direct_declarator($1);
        $$ = self;
    }
    ;
C_direct_declarator
    : MCC_SYMBOL
    {
        ast::C_direct_declarator *self
            = new ast::C_direct_declarator();
        self->init_with_MCC_SYMBOL($1);
        $$ = self;
    }
    | C_IDENTIFIER
    {
        ast::C_direct_declarator *self
            = new ast::C_direct_declarator();
        self->init_with_C_IDENTIFIER($1);
        $$ = self;
    }
    | LP C_declarator RP
    {
        ast::C_direct_declarator *self
            = new ast::C_direct_declarator();
        self->init_with_C_declarator($2);
        $$ = self;
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

#ifdef YYDEBUG
        extern int yydebug;
        yydebug = 1;
#endif

        try {
            if (metacc_init(argc, argv) == 0) {
                    return metacc_main(argc, argv);
            }
            else {
                    return 0;
            }
        }
        catch (...) {
            fprintf(stderr, "ERROR OCCURRED \n");
            return 1;
        }
}






