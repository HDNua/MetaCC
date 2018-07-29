#include <stdio.h>
#include <stdlib.h>
#include "parser_ast.h"



//==============================================================================
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
static int description_depth = 0;
static int describe_begin() {
    return ++description_depth;
}
static int describe_end() {
    return --description_depth;
}
static void indent_depth(const char *s) {
    int i;
    for (i=0; i<description_depth; ++i) {
        printf("%s", s);
    }
}
static void tab_depth() {
    indent_depth("    ");
}



// 
void ast_list_traverse(struct ast_list *list) {
    
}
// 
void ast_list_node_describe(struct ast_list_node *node) {
    
}
void ast_list_node_action(struct ast_list_node *node) {
    
}






// 
void ast_line_list_describe(FILE *out, struct ast_line_list *this) {
    
}
// 
void ast_line_list_action(FILE *out, struct ast_line_list *this) {
    
}



// 
void ast_line_describe(FILE *out, struct ast_line *this) {
    
}
// 
void ast_line_action(FILE *out, struct ast_line *this) {
    
}



// 
void ast_expr_describe(FILE *out, struct ast_expr *this) {
    
}
// 
void ast_expr_action(FILE *out, struct ast_expr *this) {
    
}



// 
void ast_term_describe(FILE *out, struct ast_term *this) {
    
}
// 
void ast_term_action(FILE *out, struct ast_term *this) {
    
}



// 
void ast_primary_describe(FILE *out, struct ast_primary *this) {
    
}
// 
void ast_primary_action(FILE *out, struct ast_primary *this) {
    
}



