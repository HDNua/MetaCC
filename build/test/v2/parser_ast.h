#ifndef __HANDY_VAST_H__
#define __HANDY_VAST_H__

#include <stdio.h>
#include <string.h>



typedef enum ast_type {
    AST_UNTYPED,
    AST_LIST,
    AST_LIST_NODE,
    AST_LINE_LIST,
    AST_LINE,
    AST_EXPR,
    AST_TERM,
    AST_PRIMARY,
} ast_type;



// 
struct ast_list_node {
    ast_type                      type;
    ast_type                      elem_type;
    void                          *elem;
    struct ast_list_node          *next;
};
// 
void ast_list_node_describe(struct ast_list_node *node);
// 
void ast_list_node_action(struct ast_list_node *node);
// 
struct ast_list {
    ast_type                      type;
    ast_type                      elem_type;
    
    struct ast_list_node          head;
    struct ast_list_node          *tail;
    int                           count;
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
struct ast_line_list {
    ast_type                        type;
};
// 
void ast_line_list_describe(FILE *out, struct ast_line_list *this);
// 
void ast_line_list_action(FILE *out, struct ast_line_list *this);



// 
struct ast_line {
    ast_type                        type;
};
// 
void ast_line_describe(FILE *out, struct ast_line *this);
// 
void ast_line_action(FILE *out, struct ast_line *this);



// 
struct ast_expr {
    ast_type                        type;
};
// 
void ast_expr_describe(FILE *out, struct ast_expr *this);
// 
void ast_expr_action(FILE *out, struct ast_expr *this);



// 
struct ast_term {
    ast_type                        type;
};
// 
void ast_term_describe(FILE *out, struct ast_term *this);
// 
void ast_term_action(FILE *out, struct ast_term *this);



// 
struct ast_primary {
    ast_type                        type;
};
// 
void ast_primary_describe(FILE *out, struct ast_primary *this);
// 
void ast_primary_action(FILE *out, struct ast_primary *this);



#endif
