#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




// 
struct ast_list_node *ast_list_node_new(void *elem, ast_type type) {
    struct ast_list_node *ret = (struct ast_list_node *)malloc(sizeof(struct ast_list_node));
    ret->type = type;
    ret->elem = elem;
    ret->next = NULL;
    return ret;
}
// 
struct ast_list *ast_list_new(ast_type type) {
    struct ast_list *ret = (struct ast_list *)malloc(sizeof(struct ast_list));
    ret->type = AST_LIST;
    ret->elem_type = type;
    ret->tail = &ret->head;
    ret->count = 0;
    return ret;
};
// 
void ast_list_append(struct ast_list *self, void *elem, ast_type type) {
    struct ast_list_node *node = ast_list_node_new(elem, type);
    self->tail->next = node;
    self->tail = node;
    self->count += 1;
}
// 
void ast_list_iterate(struct ast_list *self) {
    struct ast_list_node *node;
    for (node=self->head.next; node; node=node->next) {
        ast_list_node_describe(node);
    }
}
// 
void ast_list_traverse(struct ast_list *self) {
    // 
}



// 
void ast_list_node_describe(struct ast_list_node *self) {
    // 
}



// 
void ast_symbol_definition_describe(struct ast_symbol_definition *self) {

}
//
void ast_symbol_definition_action(struct ast_symbol_definition *self) {

}

// 
void ast_symbol_key_describe(struct ast_symbol_key *self) {

}
//
void ast_symbol_key_action(struct ast_symbol_key *self) {

}

// 
void ast_key_attributes_describe(struct ast_key_attributes *self) {

}
// 
void ast_key_attributes_action(struct ast_key_attributes *self) {

}

// 
void ast_symbol_value_describe(struct ast_symbol_value *self) {

}
// 
void ast_symbol_value_action(struct ast_symbol_value *self) {

}

// 
void ast_symbol_value_element_describe(struct ast_symbol_value_element *self) {

}
// 
void ast_symbol_value_element_action(struct ast_symbol_value_element *self) {

}

// 
void ast_list_parameter_describe(struct ast_list_parameter *self) {

}
// 
void ast_list_parameter_action(struct ast_list_parameter *self) {

}

// 
void ast_option_parameter_describe(struct ast_option_parameter *self) {

}
//
void ast_option_parameter_action(struct ast_option_parameter *self) {

}

// 
void ast_star_parameter_describe(struct ast_star_parameter *self) {

}
// 
void ast_star_parameter_action(struct ast_star_parameter *self) {

}

// 
void ast_list_parameter_value_describe(struct ast_list_parameter_value *self) {

}
// 
void ast_list_parameter_value_action(struct ast_list_parameter_value *self) {

}

// 
void ast_option_parameter_value_describe(struct ast_option_parameter_value *self) {

}
// 
void ast_option_parameter_value_action(struct ast_option_parameter_value *self) {

}

// 
void ast_star_parameter_value_describe(struct ast_star_parameter_value *self) {

}
// 
void ast_star_parameter_value_action(struct ast_star_parameter_value *self) {

}

