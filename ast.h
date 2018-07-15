#ifndef __HANDY_AST_H__
#define __HANDY_AST_H__

#include <string.h>


typedef enum ast_type {
    AST_LIST,
    AST_SYMBOL_DEFINITION,
    AST_SYMBOL_KEY,
    AST_KEY_ATTRIBUTES,
    AST_SYMBOL_VALUE,
    AST_SYMBOL_VALUE_ELEMENT,
    AST_LIST_PARAMETER,
    AST_OPTION_PARAMETER,
    AST_STAR_PARAMETER,

    // 
    AST_LIST_NODE,
    AST_MCC_STRING,
    AST_MCC_SYMBOL,

} ast_type;



// 
struct ast_list_node {
    ast_type                            type;
    void                                *elem;
    struct ast_list_node                *next;
};
// 
void ast_list_node_describe(struct ast_list_node *node);
// 
void ast_list_node_action(struct ast_list_node *node);
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
void ast_list_iterate(struct ast_list *list);
// 
void ast_list_traverse(struct ast_list *list);



// 
struct ast_symbol_definition {
    ast_type	                        type;

    struct ast_symbol_key               *ast_symbol_key; 
    struct ast_list                     *ast_symbol_value_list;
};
// 
void ast_symbol_definition_describe(struct ast_symbol_definition *);
//
void ast_symbol_definition_action(struct ast_symbol_definition *);

// 
struct ast_symbol_key {
    ast_type	                        type;

    const char                          *symbol_name;
    struct ast_key_attributes           *ast_key_attributes;
};
// 
void ast_symbol_key_describe(struct ast_symbol_key *);
//
void ast_symbol_key_action(struct ast_symbol_key *);

// 
struct ast_key_attributes {
    ast_type	                        type;

};
// 
void ast_key_attributes_describe(struct ast_key_attributes *);
// 
void ast_key_attributes_action(struct ast_key_attributes *);

// 
struct ast_symbol_value {
    ast_type	                        type;

    struct ast_list                     *ast_symbol_value_element_list;
};
// 
void ast_symbol_value_describe(struct ast_symbol_value *);
// 
void ast_symbol_value_action(struct ast_symbol_value *);

// 
struct ast_symbol_value_element {
    ast_type	                        type;

    union {
        const char                      *string;
        const char                      *mcc_symbol;
        struct ast_list_parameter       *ast_list_parameter;
        struct ast_option_parameter     *ast_option_parameter;
        struct ast_star_parameter       *ast_star_parameter;
    } u;
};
// 
void ast_symbol_value_element_describe(struct ast_symbol_value_element *);
// 
void ast_symbol_value_element_action(struct ast_symbol_value_element *);

// 
struct ast_list_parameter {
    ast_type	                        type;
    struct ast_list_parameter_value     *ast_list_parameter_value;
    const char                          *ast_list_parameter_delim;
};
// 
void ast_list_parameter_describe(struct ast_list_parameter *);
// 
void ast_list_parameter_action(struct ast_list_parameter *);

// 
struct ast_option_parameter {
    ast_type	                        type;
    struct ast_option_parameter_value   *ast_option_parameter_value;
};
// 
void ast_option_parameter_describe(struct ast_option_parameter *);
//
void ast_option_parameter_action(struct ast_option_parameter *);

// 
struct ast_star_parameter {
    ast_type	                        type;
    struct ast_star_parameter_value     *ast_star_parameter_value;
};
// 
void ast_star_parameter_describe(struct ast_star_parameter *);
// 
void ast_star_parameter_action(struct ast_star_parameter *);



// 
struct ast_list_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_element_list;
};
// 
void ast_list_parameter_value_describe(struct ast_list_parameter_value *);
// 
void ast_list_parameter_value_action(struct ast_list_parameter_value *);
// 
struct ast_option_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_element_list;
};
// 
void ast_option_parameter_value_describe(struct ast_option_parameter_value *);
// 
void ast_option_parameter_value_action(struct ast_option_parameter_value *);
// 
struct ast_star_parameter_value {
    ast_type	                        type;
    struct ast_list                     *ast_symbol_value_element_list;
};
// 
void ast_star_parameter_value_describe(struct ast_star_parameter_value *);
// 
void ast_star_parameter_value_action(struct ast_star_parameter_value *);












#endif
