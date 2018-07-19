#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN   2048



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
        "cstring",
        "null"
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
void ast_symbol_definition_describe(struct ast_symbol_definition *self) {
    // describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));
    
    ast_symbol_key_describe(self->ast_symbol_key);
    ast_list_iterate(self->ast_symbol_value_list);

    // describe_end();
}
// 
void ast_symbol_key_describe(struct ast_symbol_key *self) {
    // describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));
    
    tab_depth();
    // printf(": %s \n", self->symbol_name);
    printf("%s: \n", self->symbol_name);

    if (self->ast_key_attributes) {
        ast_key_attributes_describe(self->ast_key_attributes);
    }

    // describe_end();
}
// 
void ast_key_attributes_describe(struct ast_key_attributes *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_symbol_value_describe(struct ast_symbol_value *self) {
    describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));

    ast_list_iterate(self->ast_symbol_value_element_list);

    describe_end();
}
// 
void ast_symbol_value_element_describe(struct ast_symbol_value_element *self) {
    // describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));

    switch (self->elem_type) {
    case AST_MCC_STRING:
        tab_depth();
        printf("\"%s\" \n", self->u.mcc_string);
        break;
    case AST_MCC_SYMBOL:
        tab_depth();
        printf("%s \n", self->u.mcc_symbol);
        break;
    case AST_LIST_PARAMETER:
        ast_list_parameter_describe(self->u.ast_list_parameter);
        break;
    case AST_OPTION_PARAMETER:
        ast_option_parameter_describe(self->u.ast_option_parameter);
        break;
    case AST_STAR_PARAMETER:
        ast_star_parameter_describe(self->u.ast_star_parameter);
        break;
	case AST_TOKEN_DEFINITION:
		ast_token_definition_describe(self->u.ast_token_definition);
		break;
    case AST_CSTRING:
        tab_depth();
        printf("C\"%s\" \n", self->u.cstring);
        break;
    case AST_NULL:
        tab_depth();
        printf("%s \n", self->u.null_);
        break;
	case AST_TOKEN:
		ast_token_definition_describe(self->u.ast_token_definition);
		break;
    default:
        fprintf(stderr, "invalid symbol value element [%d] \n", self->elem_type);
        exit(1);
    }

    // describe_end();
}
// 
void ast_list_parameter_describe(struct ast_list_parameter *self) {
    describe_begin();
    tab_depth();
    printf("LIST(%s, [%s]) \n", ast_str(self->type), self->list_parameter_delim);

    describe_end();
}
// 
void ast_option_parameter_describe(struct ast_option_parameter *self) {
    describe_begin();
    tab_depth();
    printf("OPTION(%s) \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_describe(struct ast_star_parameter *self) {
    describe_begin();
    tab_depth();
    printf("STAR(%s) \n", ast_str(self->type));

    describe_end();
}
// 
void ast_list_parameter_value_describe(struct ast_list_parameter_value *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_option_parameter_value_describe(struct ast_option_parameter_value *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_value_describe(struct ast_star_parameter_value *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_token_definition_describe(struct ast_token_definition *self) {
    describe_begin();
    tab_depth();
    printf("%s \n", ast_str(self->type));

    describe_end();
}









// 
void ast_list_traverse(struct ast_list *self) {
    struct ast_list_node *node;
    for (node=self->head.next; node; node=node->next) {
        ast_list_node_action(node);
    }
}
// 
void ast_list_node_action(struct ast_list_node *self) {
    if (self->type == AST_LIST_NODE) {
        switch (self->elem_type) {
            case AST_LIST:
                ast_list_traverse(self->elem);
                break;
            case AST_SYMBOL_DEFINITION:
                ast_symbol_definition_action(self->elem);
                break;
            case AST_SYMBOL_KEY:
                ast_symbol_key_action(self->elem);
                break;
            case AST_KEY_ATTRIBUTES:
                ast_key_attributes_action(self->elem);
                break;
            case AST_SYMBOL_VALUE:
                ast_symbol_value_action(self->elem);
                break;
            case AST_SYMBOL_VALUE_ELEMENT:
                ast_symbol_value_element_action(self->elem);
                break;
            case AST_LIST_PARAMETER:
                ast_list_parameter_action(self->elem);
                break;
            case AST_OPTION_PARAMETER:
                ast_option_parameter_action(self->elem);
                break;
            case AST_STAR_PARAMETER:
                ast_star_parameter_action(self->elem);
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
}
// 
void ast_symbol_definition_action(struct ast_symbol_definition *self) {
    if (0) {
        describe_begin();
        tab_depth();
        printf("%s \n", ast_str(self->type));
        ast_symbol_key_describe(self->ast_symbol_key);
        ast_list_iterate(self->ast_symbol_value_list);
        describe_end();
    }
    else {
        static char symbol_key_className[MAX_TOKEN_LEN];
        struct ast_symbol_key *ast_symbol_key = self->ast_symbol_key;
        struct ast_key_attributes *ast_key_attr = ast_symbol_key->ast_key_attributes;
        struct ast_list *ast_symbol_value_list = self->ast_symbol_value_list;
        const char *symbol_name = ast_symbol_key->symbol_name;

        // 
        if (ast_key_attr) {
            if (strcmp(ast_key_attr->attributes, "SKIP") == 0) {
                return;
            }
            else if (strcmp(ast_key_attr->attributes, "TERMINAL") == 0) {
                // 
                // return;
            }
            else {
                exit(1);
            }
        }

        // get symbol key class name & values informations.
        {
            char *dst = symbol_key_className;
            const char *src = symbol_name;

            *dst++ = toupper(*src++);
            while (*src != '\0') {
                if (*src == '_') {
                    ++src;
                    *dst++ = toupper(*src++);
                }
                else {
                    *dst++ = *src++;
                }
            }
            *dst = '\0';
        }

        // 
        printf("SV%s %s(): {\n", symbol_key_className, symbol_name);

        // gather token list.
        {
			/*
            struct ast_list *ast_list = ast_symbol_value_list;
            struct ast_list_node *node;
            for (node = ast_list->head.next; node; node = node->next) {
                printf("%s \n", ast_str(ast_list->elem_type));
            }
			*/
        }
        printf("} {\n");

        // gather syntax list.
        {
            struct ast_list *ast_list = ast_symbol_value_list;
            struct ast_list_node *node;
            int value_list_flag = 0;
            int elem_list_flag = 0;
            
            // printf("\t%c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->head.next; node; node = node->next) {
                struct ast_symbol_value *ast_symbol_value = node->elem;
                struct ast_list *ast_elem_list = 
                    ast_symbol_value->ast_symbol_value_element_list;
                struct ast_list_node *node2;

                // 
                // printf("\t%c", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
                printf("\t");
                for (node2 = ast_elem_list->head.next; node2; node2 = node2->next) {
                    struct ast_symbol_value_element *ast_elem = node2->elem;
                    // printf("%c%s", (elem_list_flag ? '|' : (elem_list_flag=1, ' ')), 
                    //    ast_str(ast_elem->elem_type));
                    // printf(" %s", ast_str(ast_elem->elem_type));
                    // printf(" ");
					ast_symbol_value_element_action(ast_elem);
                }
                printf("\n\t{\n\t\t\n\t}\n");
            }
        }

        // 
        printf("}\n\n");
    }
}
// 
void ast_symbol_key_action(struct ast_symbol_key *self) {
    // describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));
    
    tab_depth();
    // printf(": %s \n", self->symbol_name);
    printf("%s: \n", self->symbol_name);

    if (self->ast_key_attributes) {
        ast_key_attributes_describe(self->ast_key_attributes);
    }

    // describe_end();
}
// 
void ast_key_attributes_action(struct ast_key_attributes *self) {
    // describe_begin();
    // tab_depth();
    printf("%s \n", ast_str(self->type));

    // describe_end();
}

// 
void ast_symbol_value_action(struct ast_symbol_value *self) {
    // describe_begin();
    // tab_depth();
    // printf("%s \n", ast_str(self->type));

    ast_list_traverse(self->ast_symbol_value_element_list);

    // describe_end();
}
// 
void ast_symbol_value_element_action(struct ast_symbol_value_element *self) {
    switch (self->elem_type) {
    case AST_MCC_STRING:
        printf("\"%s\" ", self->u.mcc_string);
        break;
    case AST_MCC_SYMBOL:
        printf("%s() ", self->u.mcc_symbol);
        break;
    case AST_LIST_PARAMETER:
        ast_list_parameter_action(self->u.ast_list_parameter);
        break;
    case AST_OPTION_PARAMETER:
        ast_option_parameter_action(self->u.ast_option_parameter);
        break;
    case AST_STAR_PARAMETER:
        ast_star_parameter_action(self->u.ast_star_parameter);
        break;
    case AST_TOKEN_DEFINITION:
        ast_token_definition_action(self->u.ast_token_definition);
        break;
    case AST_CSTRING:
        printf("C\"%s\" ", self->u.cstring);
        break;
    case AST_NULL:
        printf("%s ", self->u.null_);
        break;
	case AST_TOKEN:
		ast_token_definition_action(self->u.ast_token_definition);
		break;
    default:
        fprintf(stderr, "invalid symbol value element [%d] \n", self->elem_type);
        exit(1);
    }

    // describe_end();
}
// 
void ast_list_parameter_action(struct ast_list_parameter *self) {
    // printf("LIST(%s, [%s])", ast_str(self->type), self->list_parameter_delim);
	// printf("2");
	// printf("%s ( %s %s )*", self->ast_list_parameter_value;
	ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);

	printf("( ");
	if (strcmp(self->list_parameter_delim, "") != 0) {
		printf("\"%s\" ", self->list_parameter_delim);
	}

	ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);
	printf(")* ");
}
// 
void ast_option_parameter_action(struct ast_option_parameter *self) {
    // printf("OPTION(%s) \n", ast_str(self->type));
	// printf("2");
	printf("( ");
	ast_list_traverse(self->ast_option_parameter_value->ast_symbol_value_element_list);
	printf(")? ");
}
// 
void ast_star_parameter_action(struct ast_star_parameter *self) {
    // printf("STAR(%s) \n", ast_str(self->type));
	// printf("3");
	printf("( ");
	ast_list_traverse(self->ast_star_parameter_value->ast_symbol_value_element_list);
	printf(")* ");
}
// 
void ast_list_parameter_value_action(struct ast_list_parameter_value *self) {
    // printf("%s \n", ast_str(self->type));
	printf("4");
}
// 
void ast_option_parameter_value_action(struct ast_option_parameter_value *self) {
    // printf("%s \n", ast_str(self->type));
	printf("5");
}
// 
void ast_star_parameter_value_action(struct ast_star_parameter_value *self) {
	// printf("%s \n", ast_str(self->type));
	printf("6");
}
// 
void ast_token_definition_action(struct ast_token_definition *self) {
	printf("<%s> ", self->token_key);
	// printf("6");
}











