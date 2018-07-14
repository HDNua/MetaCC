#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>






struct ast_list *ast_list_new(ast_type type) {
	struct ast_list *ret = (struct ast_list *)malloc(sizeof(struct ast_list));
	ret->type = AST_LIST;
	ret->elem_type = type;

	ret->tail = ret->head.next;
	return ret;
};
