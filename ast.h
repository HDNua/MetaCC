#ifndef __HANDY_AST_H__
#define __HANDY_AST_H__

#include <stdio.h>
#include <string.h>


typedef enum ast_type {
    AST_UNTYPED,                    // 0
    AST_LIST,                       // 1
    AST_SYMBOL_DEFINITION,          // 2
    AST_SYMBOL_KEY,                 // 3
    AST_KEY_ATTRIBUTES,             // 4
    AST_SYMBOL_VALUE,               // 5
    AST_SYMBOL_VALUE_ELEMENT,       // 6
    AST_LIST_PARAMETER,             // 7
    AST_OPTION_PARAMETER,           // 8
    AST_STAR_PARAMETER,             // 9
	AST_TOKEN_DEFINITION,           // 10

    // 
    AST_LIST_NODE,                  // 11

    // 
    AST_MCC_STRING,                 // 12
    AST_MCC_SYMBOL,                 // 13
    AST_CSTRING,                    // 14
    AST_NULL,                       // 15
	AST_TOKEN,                      // 16

    // 
    AST_LIST_PARAMETER_VALUE,
    AST_OPTION_PARAMETER_VALUE,
    AST_STAR_PARAMETER_VALUE,

} ast_type;



typedef enum action_option {
    ACTOPT_NONE,
    ACTOPT_IS_NONTERMINAL,

} act_opt;



// 
struct ast_list_node {
    ast_type                            type;
    ast_type                            elem_type;
    void                                *elem;
    struct ast_list_node                *next;
};
// 
void ast_list_node_describe(FILE *out, struct ast_list_node *node);
// 
void ast_list_node_action(FILE *out, struct ast_list_node *node, act_opt);
// 
int ast_list_node_compare(const struct ast_list_node *, const struct ast_list_node *);



// 
struct ast_list {
    ast_type                            type;
    ast_type                            elem_type;

    struct ast_list_node                head;
    struct ast_list_node                *tail;
    int                         	    count;
};
// 
struct ast_list *ast_list_new(ast_type type);
// 
void ast_list_append(struct ast_list *list, void *elem, ast_type type);
// 
struct ast_list_node *ast_list_first(struct ast_list *list);
// 
void ast_list_iterate(FILE *out, struct ast_list *list);
// 
void ast_list_traverse(FILE *out, struct ast_list *list, act_opt);
// 
int ast_list_compare(const struct ast_list *, const struct ast_list *);



// 
struct ast_symbol_definition {
    ast_type	                        type;

    struct ast_symbol_key               *ast_symbol_key; 
    struct ast_list                     *ast_symbol_value_list;
};
// 
void ast_symbol_definition_describe(FILE *out, struct ast_symbol_definition *);
//
void ast_symbol_definition_action(FILE *out, struct ast_symbol_definition *, act_opt);
// 
int ast_symbol_definition_compare(const struct ast_symbol_definition *, const struct ast_symbol_definition *);


// 
struct ast_symbol_key {
    ast_type	                        type;

    const char                          *symbol_name;
    struct ast_key_attributes           *ast_key_attributes;
};
// 
void ast_symbol_key_describe(FILE *out, struct ast_symbol_key *);
//
void ast_symbol_key_action(FILE *out, struct ast_symbol_key *, act_opt);
// 
int ast_symbol_key_compare(const struct ast_symbol_key *, const struct ast_symbol_key *);


// 
struct ast_key_attributes {
    ast_type	                        type;
    
    const char                          *attributes;
};
// 
void ast_key_attributes_describe(FILE *out, struct ast_key_attributes *);
// 
void ast_key_attributes_action(FILE *out, struct ast_key_attributes *, act_opt);
// 
int ast_key_attributes_compare(const struct ast_key_attributes *, const struct ast_key_attributes *);


// 
struct ast_symbol_value {
    ast_type	                        type;

    struct ast_list                     *ast_symbol_value_element_list;
};
// 
void ast_symbol_value_describe(FILE *out, struct ast_symbol_value *);
// 
void ast_symbol_value_action(FILE *out, struct ast_symbol_value *, act_opt);
// 
int ast_symbol_value_compare(const struct ast_symbol_value *, const struct ast_symbol_value *);


// 
struct ast_symbol_value_element {
    ast_type	                        type;
    ast_type                            elem_type;

    union {
        const char                      *mcc_string;
        const char                      *mcc_symbol;
        struct ast_list_parameter       *ast_list_parameter;
        struct ast_option_parameter     *ast_option_parameter;
        struct ast_star_parameter       *ast_star_parameter;
        const char                      *cstring;
        const char                      *null_;
		struct ast_token_definition     *ast_token_definition;
    } u;
};
// 
void ast_symbol_value_element_describe(FILE *out, struct ast_symbol_value_element *);
// 
void ast_symbol_value_element_action(FILE *out, struct ast_symbol_value_element *, act_opt);
// 
int ast_symbol_value_element_compare(const struct ast_symbol_value_element *, const struct ast_symbol_value_element *);


// 
struct ast_list_parameter {
    ast_type	                        type;
    struct ast_list_parameter_value     *ast_list_parameter_value;
    const char                          *list_parameter_delim;
};
// 
void ast_list_parameter_describe(FILE *out, struct ast_list_parameter *);
// 
void ast_list_parameter_action(FILE *out, struct ast_list_parameter *, act_opt);
// 
int ast_list_parameter_compare(const struct ast_list_parameter *, const struct ast_list_parameter *);

// 
struct ast_option_parameter {
    ast_type	                        type;
    struct ast_option_parameter_value   *ast_option_parameter_value;
};
// 
void ast_option_parameter_describe(FILE *out, struct ast_option_parameter *);
//
void ast_option_parameter_action(FILE *out, struct ast_option_parameter *, act_opt);
// 
int ast_option_parameter_compare(const struct ast_option_parameter *, const struct ast_option_parameter *);

// 
struct ast_star_parameter {
    ast_type	                        type;
    struct ast_star_parameter_value     *ast_star_parameter_value;
};
// 
void ast_star_parameter_describe(FILE *out, struct ast_star_parameter *);
// 
void ast_star_parameter_action(FILE *out, struct ast_star_parameter *, act_opt);
// 
int ast_star_parameter_compare(const struct ast_star_parameter *, const struct ast_star_parameter *);



// 
struct ast_list_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_list;
};
// 
void ast_list_parameter_value_describe(FILE *out, struct ast_list_parameter_value *);
// 
void ast_list_parameter_value_action(FILE *out, struct ast_list_parameter_value *, act_opt);
// 
int ast_list_parameter_value_compare(const struct ast_list_parameter_value *, const struct ast_list_parameter_value *);


// 
struct ast_option_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_list;
};
// 
void ast_option_parameter_value_describe(FILE *out, struct ast_option_parameter_value *);
// 
void ast_option_parameter_value_action(FILE *out, struct ast_option_parameter_value *, act_opt);
// 
int ast_option_parameter_value_compare(const struct ast_option_parameter_value *, const struct ast_option_parameter_value *);


// 
struct ast_star_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_list;
};
// 
void ast_star_parameter_value_describe(FILE *out, struct ast_star_parameter_value *);
// 
void ast_star_parameter_value_action(FILE *out, struct ast_star_parameter_value *, act_opt);
// 
int ast_star_parameter_value_compare(const struct ast_star_parameter_value *, const struct ast_star_parameter_value *);




// 
struct ast_token_definition {
    ast_type	                        type;
	const char                          *token_key;
	const char                          *token_value;
};
// 
void ast_token_definition_describe(FILE *out, struct ast_token_definition *);
// 
void ast_token_definition_action(FILE *out, struct ast_token_definition *, act_opt);
// 
int ast_token_definition_compare(const struct ast_token_definition *, const struct ast_token_definition *);




//==============================================================================
// 
void mcc_string_action(FILE *out, const char *s, act_opt);



//==============================================================================
extern FILE *out_jj;
extern FILE *out_java;

//------------------------------------------------------------------------------
extern FILE *out_lyc;
extern FILE *out_lyc_y;
extern FILE *out_lyc_y_token;
extern FILE *out_lyc_y_list;
extern FILE *out_lyc_y_option;
extern FILE *out_lyc_y_star;
extern FILE *out_lyc_l;
extern FILE *out_lyc_l_tokendef;
extern FILE *out_lyc_ast_h;
extern FILE *out_lyc_ast_h_typedef;
extern FILE *out_lyc_ast_h_declaration;
extern FILE *out_lyc_ast_c;
extern FILE *out_lyc_ast_c_templates;

//------------------------------------------------------------------------------
extern FILE *out_lycpp;





//==============================================================================
// tables.
struct table {
    char *list[1024];
    int count;
};
struct ast_table {
    void *list[1024];
    int count;
};












#endif
