#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



// 
static const char *ast_str(ast_type type) {
    static const char *ast_str_[] = {
        "untyped",
        "list",
        "symbol_definition",
        "symbol_key",
        "key_attributes",
        "symbol_value",
        "symbol_value_element",
        "list_parameter",
        "option_parameter",
        "star_parameter",
        "list_node",
        "mcc_string",
        "mcc_symbol",
    };

    return ast_str_[type];
}



// 
static struct ast_list_node *ast_list_node_new(void *elem, ast_type type) {
    struct ast_list_node *ret = (struct ast_list_node *)malloc(sizeof(struct ast_list_node));
    ret->type = AST_LIST_NODE;
    ret->elem_type = type;
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
    struct ast_list_node *node;
    for (node=self->head.next; node; node=node->next) {
        ast_list_node_action(node);
    }
}



// 
static int description_depth = 0;
static int describe_begin() {
    return ++description_depth;
}
static int describe_end() {
    return --description_depth;
}
static void indent_depth(char ch) {
    int i;
    for (i=0; i<description_depth; ++i) {
        putchar(ch);
    }
}
static void tab_depth() {
    indent_depth('\t');
}



// 
void ast_list_node_describe(struct ast_list_node *self) {
    // describe_begin();
    if (self->type == AST_LIST_NODE) {
        // tab_depth();
        // printf("%s \n", ast_str(self->type));
        switch (self->elem_type) {
            case AST_LIST:
                ast_list_iterate(self->elem);
                break;
            case AST_SYMBOL_DEFINITION:
                ast_symbol_definition_describe(self->elem);
                break;
            case AST_SYMBOL_KEY:
                ast_symbol_key_describe(self->elem);
                break;
            case AST_KEY_ATTRIBUTES:
                ast_key_attributes_describe(self->elem);
                break;
            case AST_SYMBOL_VALUE:
                ast_symbol_value_describe(self->elem);
                break;
            case AST_SYMBOL_VALUE_ELEMENT:
                ast_symbol_value_element_describe(self->elem);
                break;
            case AST_LIST_PARAMETER:
                ast_list_parameter_describe(self->elem);
                break;
            case AST_OPTION_PARAMETER:
                ast_option_parameter_describe(self->elem);
                break;
            case AST_STAR_PARAMETER:
                ast_star_parameter_describe(self->elem);
                break;
            default:
                fprintf(stderr, "invalid node element type [%d] \n", self->elem_type);
                exit(1);
                break;
        }
    }
    else {
        fprintf(stderr, "invalid node \n");
        exit(1);
    }
    // describe_end();
}
// 
void ast_list_node_action(struct ast_list_node *self) {

}



// 
void ast_symbol_definition_describe(struct ast_symbol_definition *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));
    
    ast_symbol_key_describe(self->ast_symbol_key);
    ast_list_iterate(self->ast_symbol_value_list);

    describe_end();
}
//
void ast_symbol_definition_action(struct ast_symbol_definition *self) {
}

// 
void ast_symbol_key_describe(struct ast_symbol_key *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
//
void ast_symbol_key_action(struct ast_symbol_key *self) {

}

// 
void ast_key_attributes_describe(struct ast_key_attributes *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_key_attributes_action(struct ast_key_attributes *self) {

}

// 
void ast_symbol_value_describe(struct ast_symbol_value *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_symbol_value_action(struct ast_symbol_value *self) {

}

// 
void ast_symbol_value_element_describe(struct ast_symbol_value_element *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_symbol_value_element_action(struct ast_symbol_value_element *self) {

}

// 
void ast_list_parameter_describe(struct ast_list_parameter *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_list_parameter_action(struct ast_list_parameter *self) {

}

// 
void ast_option_parameter_describe(struct ast_option_parameter *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
//
void ast_option_parameter_action(struct ast_option_parameter *self) {

}

// 
void ast_star_parameter_describe(struct ast_star_parameter *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_action(struct ast_star_parameter *self) {

}

// 
void ast_list_parameter_value_describe(struct ast_list_parameter_value *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_list_parameter_value_action(struct ast_list_parameter_value *self) {

}

// 
void ast_option_parameter_value_describe(struct ast_option_parameter_value *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_option_parameter_value_action(struct ast_option_parameter_value *self) {

}

// 
void ast_star_parameter_value_describe(struct ast_star_parameter_value *self) {
    describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_value_action(struct ast_star_parameter_value *self) {

}

