#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN   2048


//==============================================================================
FILE *out_jj;
FILE *out_java;

//------------------------------------------------------------------------------
FILE *out_lyc;
FILE *out_lyc_y;
FILE *out_lyc_y_token;
FILE *out_lyc_l;
FILE *out_lyc_ast_h;
FILE *out_lyc_ast_c;

//------------------------------------------------------------------------------
FILE *out_lycpp;

//==============================================================================
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
        fprintf(out_jj, "%s", s); 
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
        // fprintf(out_jj, "%s \n", ast_str(self->type));
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
    // fprintf(out_jj, "%s \n", ast_str(self->type));

    ast_symbol_key_describe(self->ast_symbol_key);
    ast_list_iterate(self->ast_symbol_value_list);

    // describe_end();
}
// 
void ast_symbol_key_describe(struct ast_symbol_key *self) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(self->type));

    tab_depth();
    // fprintf(out_jj, ": %s \n", self->symbol_name);
    fprintf(out_jj, "%s: \n", self->symbol_name);

    if (self->ast_key_attributes) {
        ast_key_attributes_describe(self->ast_key_attributes);
    }

    // describe_end();
}
// 
void ast_key_attributes_describe(struct ast_key_attributes *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_symbol_value_describe(struct ast_symbol_value *self) {
    describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(self->type));

    ast_list_iterate(self->ast_symbol_value_element_list);

    describe_end();
}
// 
void ast_symbol_value_element_describe(struct ast_symbol_value_element *self) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(self->type));

    switch (self->elem_type) {
        case AST_MCC_STRING:
            tab_depth();
            fprintf(out_jj, "\"%s\" \n", self->u.mcc_string);
            break;
        case AST_MCC_SYMBOL:
            tab_depth();
            fprintf(out_jj, "%s \n", self->u.mcc_symbol);
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
            fprintf(out_jj, "C\"%s\" \n", self->u.cstring);
            break;
        case AST_NULL:
            tab_depth();
            fprintf(out_jj, "%s \n", self->u.null_);
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
    fprintf(out_jj, "LIST(%s, [%s]) \n", ast_str(self->type), self->list_parameter_delim);

    describe_end();
}
// 
void ast_option_parameter_describe(struct ast_option_parameter *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "OPTION(%s) \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_describe(struct ast_star_parameter *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "STAR(%s) \n", ast_str(self->type));

    describe_end();
}
// 
void ast_list_parameter_value_describe(struct ast_list_parameter_value *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_option_parameter_value_describe(struct ast_option_parameter_value *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_star_parameter_value_describe(struct ast_star_parameter_value *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(self->type));

    describe_end();
}
// 
void ast_token_definition_describe(struct ast_token_definition *self) {
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(self->type));

    describe_end();
}









// 
void ast_list_traverse(struct ast_list *self) {
    static int depth = 0;
    struct ast_list_node *node;

    // 
    if (out_jj) {
        if (self->elem_type == AST_SYMBOL_VALUE) {
            ++depth;
            for (node=self->head.next; node; node=node->next) {
                ast_list_node_action(node);

                if (node->next) {
                    if (depth >= 1) {
                        fprintf(out_jj, "| ");
                    }
                }
            }
            --depth;
        }
        else {
            for (node=self->head.next; node; node=node->next) {
                ast_list_node_action(node);
            }
        }
    }

    // 
    if (out_lyc) {
        for (node=self->head.next; node; node=node->next) {
            ast_list_node_action(node);

            if (self->elem_type == AST_SYMBOL_VALUE) {
                if (node->next) {
                    if (depth == 0) {
                        fprintf(out_lyc, ":");
                    }
                }
            }
        }
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

    //======================================================================================
    // output to JavaCC files.
    // > SVParser.jj   : 
    // > SVObject.java : 
    if (out_jj)
    {
        // get symbol key class name & values informations.
        {
            char *dst = symbol_key_className;
            const char *src = symbol_name;

            *dst++ = 'S';
            *dst++ = 'V';
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
        fprintf(out_java, "class %s {\n", symbol_key_className);
        fprintf(out_java, "    public String toString() {\n");
        fprintf(out_java, "        return \"%s\";\n", symbol_key_className);
        fprintf(out_java, "    }\n");
        fprintf(out_java, "}\n\n");

        // 
        fprintf(out_jj, "%s %s(): {\n", symbol_key_className, symbol_name);

        // gather token list.
        {
            /*
               struct ast_list *ast_list = ast_symbol_value_list;
               struct ast_list_node *node;
               for (node = ast_list->head.next; node; node = node->next) {
               fprintf(out_jj, "%s \n", ast_str(ast_list->elem_type));
               }
               */
        }
        fprintf(out_jj, "} {\n");

        // gather syntax list.
        {
            struct ast_list *ast_list = ast_symbol_value_list;
            struct ast_list_node *node;
            int value_list_flag = 0;
            int elem_list_flag = 0;

            // fprintf(out_jj, "\t%c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->head.next; node; node = node->next) {
                struct ast_symbol_value *ast_symbol_value = node->elem;
                struct ast_list *ast_elem_list = 
                    ast_symbol_value->ast_symbol_value_element_list;
                struct ast_list_node *node2;

                // 
                fprintf(out_jj, "    %s", (elem_list_flag ? "|\n    " : (elem_list_flag=1, "")));
                for (node2 = ast_elem_list->head.next; node2; node2 = node2->next) {
                    struct ast_symbol_value_element *ast_elem = node2->elem;
                    // fprintf(out_jj, "%c%s", (elem_list_flag ? '|' : (elem_list_flag=1, ' ')), 
                    //    ast_str(ast_elem->elem_type));
                    // fprintf(out_jj, " %s", ast_str(ast_elem->elem_type));
                    // fprintf(out_jj, " ");
                    ast_symbol_value_element_action(ast_elem);
                }
                fprintf(out_jj, "\n    {\n        return null;\n    }\n");
            }
        }

        // 
        fprintf(out_jj, "}\n\n");
    }

    //======================================================================================
    // yields Lex & Yacc files.
    // > parser.l : lexical file.
    // > parser.y : yacc syntax file.
    // > ast.h    : abstract syntax tree interface.
    // > ast.c    : abstract syntax tree implementation.
    if (out_lyc)
    {
        // 
        fprintf(out_lyc_ast_h, " \n");
        fprintf(out_lyc_ast_c, " \n");
        
        // 
        fprintf(out_lyc, "%s \n", symbol_name);

        // gather syntax list.
        {
            struct ast_list *ast_list = ast_symbol_value_list;
            struct ast_list_node *node;
            int value_list_flag = 0;
            int elem_list_flag = 0;

            // fprintf(out_lyc, "    %c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->head.next; node; node = node->next) {
                struct ast_symbol_value *ast_symbol_value = node->elem;
                struct ast_list *ast_elem_list = 
                    ast_symbol_value->ast_symbol_value_element_list;
                struct ast_list_node *node2;

                // 
                fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
                for (node2 = ast_elem_list->head.next; node2; node2 = node2->next) {
                    struct ast_symbol_value_element *ast_elem = node2->elem;
                    // fprintf(out_jj, "%c%s", (elem_list_flag ? '|' : (elem_list_flag=1, ' ')), 
                    //     ast_str(ast_elem->elem_type));
                    // fprintf(out_jj, " %s", ast_str(ast_elem->elem_type));
                    // fprintf(out_jj, " ");
                    ast_symbol_value_element_action(ast_elem);
                }
                fprintf(out_lyc, "\n    {\n        $$ = NULL;\n    }\n");
            }
        }

        // 
        fprintf(out_lyc, "    ;\n\n");
    }
}
// 
void ast_symbol_key_action(struct ast_symbol_key *self) {
    if (out_jj) {
        // fprintf(out_jj, ": %s \n", self->symbol_name);
        // fprintf(out_jj, "%s: \n", self->symbol_name);
        // 
        // if (self->ast_key_attributes) {
        //     ast_key_attributes_action(self->ast_key_attributes);
        // }
        // 
        // describe_end();
    }

    if (out_lyc) {
        // describe_begin();
        // tab_depth();
        // fprintf(out_jj, "%s \n", ast_str(self->type));
        // tab_depth();
        // fprintf(out_jj, ": %s \n", self->symbol_name);
        // fprintf(out_lyc, "%s: \n", self->symbol_name);
        // 
        // if (self->ast_key_attributes) {
        //    ast_key_attributes_action(self->ast_key_attributes);
        // }
        // describe_end();
    }
}
// 
void ast_key_attributes_action(struct ast_key_attributes *self) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(self->type));
    // describe_end();
}

// 
void ast_symbol_value_action(struct ast_symbol_value *self) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(self->type));

    ast_list_traverse(self->ast_symbol_value_element_list);

    // describe_end();
}
// 
void ast_symbol_value_element_action(struct ast_symbol_value_element *self) {
    if (out_jj) {
        switch (self->elem_type) {
            case AST_MCC_STRING:
                fprintf(out_jj, "\"%s\" ", self->u.mcc_string);
                break;
            case AST_MCC_SYMBOL:
                fprintf(out_jj, "%s() ", self->u.mcc_symbol);
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
                fprintf(out_jj, "C\"%s\" ", self->u.cstring);
                break;
            case AST_NULL:
                fprintf(out_jj, "%s ", self->u.null_);
                break;
            case AST_TOKEN:
                ast_token_definition_action(self->u.ast_token_definition);
                break;
            default:
                fprintf(stderr, "invalid symbol value element [%d] \n", self->elem_type);
                exit(1);
        }
    }

    if (out_lyc) {
        switch (self->elem_type) {
            case AST_MCC_STRING:
                fprintf(out_lyc, "\"%s\" ", self->u.mcc_string);
                break;
            case AST_MCC_SYMBOL:
                fprintf(out_lyc, "%s ", self->u.mcc_symbol);
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
                fprintf(out_lyc, "C\"%s\" ", self->u.cstring);
                break;
            case AST_NULL:
                fprintf(out_lyc, "%s ", self->u.null_);
                break;
            case AST_TOKEN:
                ast_token_definition_action(self->u.ast_token_definition);
                break;
            default:
                fprintf(stderr, "invalid symbol value element [%d] \n", self->elem_type);
                exit(1);
        }
    }
}
// 
void ast_list_parameter_action(struct ast_list_parameter *self) {
    if (out_jj) {
        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);

        fprintf(out_jj, "( ");
        if (strcmp(self->list_parameter_delim, "") != 0) {
            fprintf(out_jj, "\"%s\" ", self->list_parameter_delim);
        }

        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);
        fprintf(out_jj, ")* ");
    }

    if (out_lyc) {
        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);

        fprintf(out_lyc, "( ");
        if (strcmp(self->list_parameter_delim, "") != 0) {
            fprintf(out_lyc, "\"%s\" ", self->list_parameter_delim);
        }

        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_element_list);
        fprintf(out_lyc, ")* ");
    }
}
// 
void ast_option_parameter_action(struct ast_option_parameter *self) {
    // 
    if (out_jj) {
        fprintf(out_jj, "( ");
        ast_list_traverse(self->ast_option_parameter_value->ast_symbol_value_element_list);
        fprintf(out_jj, ")? ");
    }
    
    // 
    if (out_lyc) {
        fprintf(out_lyc, "( ");
        ast_list_traverse(self->ast_option_parameter_value->ast_symbol_value_element_list);
        fprintf(out_lyc, ")? ");
    }
}
// 
void ast_star_parameter_action(struct ast_star_parameter *self) {
    // fprintf(out_jj, "STAR(%s) \n", ast_str(self->type));
    // fprintf(out_jj, "3");

    //
    if (out_jj) {
        fprintf(out_jj, "( ");
        ast_list_traverse(self->ast_star_parameter_value->ast_symbol_value_element_list);
        fprintf(out_jj, ")* ");
    }
    
    // 
    if (out_lyc) {
        fprintf(out_lyc, "( ");
        ast_list_traverse(self->ast_star_parameter_value->ast_symbol_value_element_list);
        fprintf(out_lyc, ")* ");
    }
}
// 
void ast_list_parameter_value_action(struct ast_list_parameter_value *self) {
    // fprintf(out_jj, "%s \n", ast_str(self->type));
    //
    if (out_jj) {
        fprintf(out_jj, "4");
    }

    // 
    if (out_lyc) {
        fprintf(out_lyc, "4");
    }
}
// 
void ast_option_parameter_value_action(struct ast_option_parameter_value *self) {
    // fprintf(out_jj, "%s \n", ast_str(self->type));
    // 
    if (out_jj) {
        fprintf(out_jj, "5");
    }

    // 
    if (out_lyc) {
        fprintf(out_lyc, "5");
    }
}
// 
void ast_star_parameter_value_action(struct ast_star_parameter_value *self) {
    // fprintf(out_jj, "%s \n", ast_str(self->type));
    //
    if (out_jj) {
        fprintf(out_jj, "6");
    }

    // 
    if (out_lyc) {
        fprintf(out_lyc, "6");
    }
}
// 
void ast_token_definition_action(struct ast_token_definition *self) {
    // 
    if (out_jj) {
        fprintf(out_jj, "<%s> ", self->token_key);
    }
    
    // 
    if (out_lyc) {
        char token_key_buf[256];
        char token_value_buf[256];
        sprintf(token_key_buf, "\"%s\"", self->token_key);
        sprintf(token_value_buf, "%s", self->token_key);
        fprintf(out_lyc_l, "%-40s return %s;\n", token_key_buf, token_value_buf);
        
        // 
        fprintf(out_lyc_y_token, "%%token %s\n", self->token_key);
        
        // 
        fprintf(out_lyc, "%s", self->token_key);
    }
}






// 
void ast_symbol_value_list_node_action(struct ast_list_node *self) {
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
void ast_symbol_value_list_traverse(struct ast_list *self) {
    struct ast_list_node *node;
    for (node=self->head.next; node; node=node->next) {
        ast_symbol_value_list_node_action(node);
    }
}




