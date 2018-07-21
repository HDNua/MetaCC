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
FILE *out_lyc_l_tokendef;
FILE *out_lyc_ast_h;
FILE *out_lyc_ast_h_typedef;
FILE *out_lyc_ast_h_declaration;
FILE *out_lyc_ast_c;
FILE *out_lyc_ast_c_templates;

//------------------------------------------------------------------------------
FILE *out_lycpp;

//==============================================================================
// 
static const char *ast_str(ast_type type) {
    static const char *ast_str_[] = {
        "untyped",                  // 0
        "list",                     // 1
        "symbol_definition",        // 2
        "symbol_key",               // 3
        "key_attributes",           // 4
        "symbol_value",             // 5
        "symbol_value_element",     // 6
        "list_parameter",           // 7
        "option_parameter",         // 8
        "star_parameter",           // 9
        "token_definition",         // 10
        
        // 
        "list_node",                // 11
        
        // 
        "mcc_string",               // 12
        "mcc_symbol",               // 13
        "cstring",                  // 14
        "null",                     // 15
        "token",                    // 16
    };
    return ast_str_[type];
}

//==============================================================================
// tables.
// 
void table_init(struct table *table) {
    table->count = 0;
}
// 
int table_index(struct table *table, const char *key) {
    int i, len;
    const char **list = (const char **)table->list;

    for (i=0, len=table->count; i < len; ++i) {
        if (strcmp(list[i], key) == 0) {
            return i;
        }
    }
    return -1;
}
// 
void table_add(struct table *table, const char *key) {
    table->list[table->count++] = strdup(key);
}


//------------------------------------------------------------------------------
// 
struct table symbols;
// 
void symbols_init() {
    table_init(&symbols);
}
// 
int symbols_index(const char *symbol_name) {
    return table_index(&symbols, symbol_name);
}
// 
int symbols_add(const char *symbol_name) {
    if (symbols_index(symbol_name) < 0) {
        table_add(&symbols, symbol_name);
        return 0;
    }
    else {
        return 1;
    }
}

//------------------------------------------------------------------------------
struct table string_token_keys;
struct table string_token_values;
// 
void string_tokens_init() {
    table_init(&string_token_keys);
    table_init(&string_token_values);
}
// 
int string_tokens_index(const char *symbol_name) {
    return table_index(&string_token_values, symbol_name);
}
// 
int string_tokens_add(const char *key, const char *value) {
    if (string_tokens_index(key) < 0) {
        table_add(&string_token_keys, key);
        table_add(&string_token_values, value);
        return 0;
    }
    else {
        return 1;
    }
}

//------------------------------------------------------------------------------
struct table tokens;
// 
void tokens_init() {
    table_init(&tokens);
}
// 
int tokens_index(const char *symbol_name) {
    return table_index(&tokens, symbol_name);
}
// 
void tokens_add(const char *token_name) {
    table_add(&tokens, token_name);
}



//==============================================================================
// 
void ast_table_init(struct ast_table *table) {
    table->count = 0;
}
int ast_table_index(struct ast_table *table, void *elem, int cmp(const void *, const void *)) {
    int i, len;
    void **list = table->list;
    for (i=0, len=table->count; i<len; ++i) {
        if (cmp(list[i], elem) == 0) {
            return i;
        }
    }
    return -1;
}
void ast_table_add(struct ast_table *table, void *elem) {
    table->list[table->count++] = elem;
}
//------------------------------------------------------------------------------
struct table table_LIST_keys;
struct table table_OPT_keys;
struct table table_STAR_keys;
struct ast_table table_LIST_values;
struct ast_table table_OPT_values;
struct ast_table table_STAR_values;
// 
void ast_table_LIST_init() {
    table_init(&table_LIST_keys);
    ast_table_init(&table_LIST_values);
}
// 
int ast_table_LIST_index(struct ast_list_parameter *elem) {
    return ast_table_index(&table_LIST_values, elem, (int(*)(const void *, const void *))ast_list_parameter_compare);
}
// 
void ast_table_LIST_add(const char *key, struct ast_list_parameter *elem) {
    table_add(&table_LIST_keys, key);
    ast_table_add(&table_LIST_values, elem);
}
// 
void ast_table_OPT_init() {
    table_init(&table_OPT_keys);
    ast_table_init(&table_OPT_values);
}
// 
int ast_table_OPT_index(struct ast_option_parameter *elem) {
    return ast_table_index(&table_OPT_values, elem, (int(*)(const void *, const void *))ast_option_parameter_compare);
}
// 
void ast_table_OPT_add(const char *key, struct ast_option_parameter *elem) {
    table_add(&table_OPT_keys, key);
    ast_table_add(&table_OPT_values, elem);
}
// 
void ast_table_STAR_init() {
    table_init(&table_STAR_keys);
    ast_table_init(&table_STAR_values);
}
// 
int ast_table_STAR_index(struct ast_star_parameter *elem) {
    return ast_table_index(&table_STAR_values, elem, (int(*)(const void *, const void *))ast_star_parameter_compare);
}
// 
void ast_table_STAR_add(const char *key, struct ast_star_parameter *elem) {
    table_add(&table_STAR_keys, key);
    ast_table_add(&table_STAR_values, elem);
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
struct ast_list_node *ast_list_first(struct ast_list *self) {
    return self->head.next;
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
// 
static int describe_begin() {
    return ++description_depth;
}
// 
static int describe_end() {
    return --description_depth;
}
// 
static void indent_depth(const char *s) {
    int i;
    for (i=0; i<description_depth; ++i) {
        fprintf(out_jj, "%s", s); 
    }
}
// 
static void tab_depth() {
    indent_depth("    ");
}



// 
int ast_list_node_compare(const struct ast_list_node *p1, const struct ast_list_node *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return 1;
        }
        else if (p1->elem_type != p2->elem_type) {
            return 1;
        }
        else {
            switch (p1->elem_type) {
                case AST_LIST:
                    return ast_list_compare(p1->elem, p2->elem);
                case AST_SYMBOL_DEFINITION:
                    return ast_symbol_definition_compare(p1->elem, p2->elem);
                case AST_SYMBOL_KEY:
                    return ast_symbol_key_compare(p1->elem, p2->elem);
                case AST_KEY_ATTRIBUTES:
                    return ast_key_attributes_compare(p1->elem, p2->elem);
                case AST_SYMBOL_VALUE:
                    return ast_symbol_value_compare(p1->elem, p2->elem);
                case AST_SYMBOL_VALUE_ELEMENT:
                    return ast_symbol_value_element_compare(p1->elem, p2->elem);
                case AST_LIST_PARAMETER:
                    return ast_list_parameter_compare(p1->elem, p2->elem);
                case AST_OPTION_PARAMETER:
                    return ast_option_parameter_compare(p1->elem, p2->elem);
                case AST_STAR_PARAMETER:
                    return ast_star_parameter_compare(p1->elem, p2->elem);
                case AST_TOKEN_DEFINITION:
                    return ast_token_definition_compare(p1->elem, p2->elem);
                default:
                    fprintf(stderr, "list_node_cmp >> invalid type [%s] \n", ast_str(p1->elem_type));
                    return 1;
            }
        }
    }
    return 0;
}
// 
int ast_list_compare(const struct ast_list *p1, const struct ast_list *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (p1->elem_type != p2->elem_type) {
            return 1;
        }
        else if (p1->count != p2->count) {
            return 1;
        }
        else {
            int i, len;
            struct ast_list_node *n1 = ast_list_first((struct ast_list *)p1);
            struct ast_list_node *n2 = ast_list_first((struct ast_list *)p2);
            for (i=0, len=p1->count; i<len; ++i) {
                if (ast_list_node_compare(n1, n2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
// 
int ast_symbol_definition_compare(const struct ast_symbol_definition *p1, const struct ast_symbol_definition *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (ast_symbol_key_compare(p1->ast_symbol_key, p2->ast_symbol_key)) {
            return 1;
        }
        return ast_list_compare(p1->ast_symbol_value_list, p2->ast_symbol_value_list);
    }
    return 0;
}
// 
int ast_symbol_key_compare(const struct ast_symbol_key *p1, const struct ast_symbol_key *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (strcmp(p1->symbol_name, p2->symbol_name)) {
            return 1;
        }
        return ast_key_attributes_compare(p1->ast_key_attributes, p2->ast_key_attributes);
    }
    return 0;
}
// 
int ast_key_attributes_compare(const struct ast_key_attributes *p1, const struct ast_key_attributes *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        return strcmp(p1->attributes, p2->attributes);
    }
    return 0;
}
// 
int ast_symbol_value_compare(const struct ast_symbol_value *p1, const struct ast_symbol_value *p2) {
    if (p1 != p2) {
        return ast_list_compare(p1->ast_symbol_value_element_list, p2->ast_symbol_value_element_list);
    }
    return 0;
}
// 
int ast_symbol_value_element_compare(const struct ast_symbol_value_element *p1, const struct ast_symbol_value_element *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (p1->elem_type != p2->elem_type) {
            return 1;
        }
        else {
            switch (p1->elem_type) {
                case AST_MCC_STRING:
                    return strcmp(p1->u.mcc_string, p2->u.mcc_string);
                case AST_MCC_SYMBOL:
                    return strcmp(p1->u.mcc_symbol, p2->u.mcc_symbol);
                case AST_LIST_PARAMETER:
                    return ast_list_parameter_compare(p1->u.ast_list_parameter, p2->u.ast_list_parameter);
                case AST_OPTION_PARAMETER:
                    return ast_option_parameter_compare(p1->u.ast_option_parameter, p2->u.ast_option_parameter);
                case AST_STAR_PARAMETER:
                    return ast_star_parameter_compare(p1->u.ast_star_parameter, p2->u.ast_star_parameter);
                case AST_CSTRING:
                    return strcmp(p1->u.cstring, p2->u.cstring);
                case AST_NULL:
                    return strcmp(p1->u.null_, p2->u.null_);
                case AST_TOKEN_DEFINITION:
                    return ast_token_definition_compare(p1->u.ast_token_definition, p2->u.ast_token_definition);
                default:
                    fprintf(stderr, "symbol_value_element_cmp >> invalid type [%s] \n", ast_str(p1->elem_type));
                    return 1;
            }
        }
        return 1;
    }
    return 0;
}
// 
int ast_list_parameter_compare(const struct ast_list_parameter *p1, const struct ast_list_parameter *p2) {
    if (p1 != p2) {
        if (p1->type != p2->type) {
            return -1;
        }
        else if (ast_list_parameter_value_compare(p1->ast_list_parameter_value, p2->ast_list_parameter_value)) {
            return 1;
        }
        else if (strcmp(p1->list_parameter_delim, p2->list_parameter_delim)) {
            return 1;
        }
    }
    return 0;
}
// 
int ast_option_parameter_compare(const struct ast_option_parameter *p1, const struct ast_option_parameter *p2) {
    if (p1 != p2) {
        return ast_option_parameter_value_compare(p1->ast_option_parameter_value, p2->ast_option_parameter_value);
    }
    return 0;
}
// 
int ast_star_parameter_compare(const struct ast_star_parameter *p1, const struct ast_star_parameter *p2) {
    if (p1 != p2) {
        return ast_star_parameter_value_compare(p1->ast_star_parameter_value, p2->ast_star_parameter_value);
    }
    return 0;
}
// 
int ast_list_parameter_value_compare(const struct ast_list_parameter_value *p1, const struct ast_list_parameter_value *p2) {
    if (p1 != p2) {
        return ast_list_compare(p1->ast_symbol_value_list, p2->ast_symbol_value_list);
    }
    return 0;
}
// 
int ast_option_parameter_value_compare
    (const struct ast_option_parameter_value *p1, const struct ast_option_parameter_value *p2) {
    if (p1 != p2) {
        return ast_list_compare(p1->ast_symbol_value_list, p2->ast_symbol_value_list);
    }
    return 0;
}
// 
int ast_star_parameter_value_compare(const struct ast_star_parameter_value *p1, const struct ast_star_parameter_value *p2) {
    if (p1 != p2) {
        return ast_list_compare(p1->ast_symbol_value_list, p2->ast_symbol_value_list);
    }
    return 0;
}
// 
int ast_token_definition_compare(const struct ast_token_definition *p1, const struct ast_token_definition *p2) {
    if (p1 != p2) {
        int ret;
        if (ret = strcmp(p1->token_key, p2->token_key)) {
            return ret;
        }
        if (ret = strcmp(p1->token_value, p2->token_value)) {
            return ret;
        }
    }
    return 0;
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
        /// fprintf(out_lyc_ast_h, " \n");
        /// fprintf(out_lyc_ast_c, " \n");
        
        // 
        fprintf(out_lyc, "%s \n", symbol_name);

        {
            // 
            char buf[MAX_TOKEN_LEN];
            char *dst = buf;
            const char *src = symbol_name;

            // 
            *dst++ = 'A';
            *dst++ = 'S';
            *dst++ = 'T';
            *dst++ = '_';
            while (*src) {
                *dst++ = toupper(*src++);
            }
            *dst++ = '\0';

            // 
            fprintf(out_lyc_ast_h_typedef, "    %s,\n", buf);

            // 
            fprintf(out_lyc_ast_h_declaration, "// \n");
            fprintf(out_lyc_ast_h_declaration, "struct ast_%s {\n", symbol_name);
            fprintf(out_lyc_ast_h_declaration, "    %-31s %s;\n", "ast_type", "type");
            fprintf(out_lyc_ast_h_declaration, "};\n");
            fprintf(out_lyc_ast_h_declaration, "// \n");
            fprintf(out_lyc_ast_h_declaration, "void ast_%s_describe(struct ast_%s *self);\n", symbol_name, symbol_name);
            fprintf(out_lyc_ast_h_declaration, "// \n");
            fprintf(out_lyc_ast_h_declaration, "void ast_%s_action(struct ast_%s *self);\n", symbol_name, symbol_name);
            fprintf(out_lyc_ast_h_declaration, "\n");
            fprintf(out_lyc_ast_h_declaration, "\n");
            fprintf(out_lyc_ast_h_declaration, "\n");
 
            // 
            fprintf(out_lyc_ast_c_templates, "// \n");
            fprintf(out_lyc_ast_c_templates, "void ast_%s_describe(struct ast_%s *self) {\n", symbol_name, symbol_name);
            fprintf(out_lyc_ast_c_templates, "    \n");
            fprintf(out_lyc_ast_c_templates, "}\n");
            fprintf(out_lyc_ast_c_templates, "// \n");
            fprintf(out_lyc_ast_c_templates, "void ast_%s_action(struct ast_%s *self) {\n", symbol_name, symbol_name);
            fprintf(out_lyc_ast_c_templates, "    \n");
            fprintf(out_lyc_ast_c_templates, "}\n");
            fprintf(out_lyc_ast_c_templates, "\n");
            fprintf(out_lyc_ast_c_templates, "\n");
            fprintf(out_lyc_ast_c_templates, "\n");
        }

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
                fprintf(out_lyc, "\n    {\n        $$ = 0;\n    }\n");
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
                // fprintf(out_lyc, "\"%s\" ", self->u.mcc_string);
                mcc_string_action(self->u.mcc_string);
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
void mcc_string_action(const char *string_value) {
    char key_name[256];
    int index = string_tokens_index(string_value);

    // 
    sprintf(key_name, "TOKEN_%d", index);
    if (index < 0) {
        index = string_token_keys.count;
        string_tokens_add(key_name, string_value);

        // 
        sprintf(key_name, "TOKEN_%d", index);
        fprintf(out_lyc_l_tokendef, "\"%s\" return %s;\n", string_value, key_name);
    }
    fprintf(out_lyc, "%s /* %s */ ", key_name, string_value);
}
// 
void ast_list_parameter_action(struct ast_list_parameter *self) {
    if (out_jj) {
        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_list);

        fprintf(out_jj, "( ");
        if (strcmp(self->list_parameter_delim, "") != 0) {
            fprintf(out_jj, "\"%s\" ", self->list_parameter_delim);
        }

        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_list);
        fprintf(out_jj, ")* ");
    }

    // 
    if (out_lyc) {
        char key_name[256];
        int index;

        ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_list);
        
        index = ast_table_LIST_index(self);
        if (index < 0) {
            index = table_LIST_keys.count;
            
            // 
            sprintf(key_name, "LIST_%d", index);
            ast_table_LIST_add(key_name, self);
        }

        // 
        fprintf(out_lyc, "LIST_%d ", index);
        fprintf(out_lyc, "    : ");
        ast_list_parameter_value_action(self->ast_list_parameter_value);
        fprintf(out_lyc, "    | LIST_%d %s ", index, self->list_parameter_delim);
        ast_list_parameter_value_action(self->ast_list_parameter_value);
        fprintf(out_lyc, "    ; ");

        /*
        struct ast_list *ast_symbol_value_list = self->ast_list_parameter_value->ast_symbol_value_list;

        if (ast_symbol_value_list->count == 1) {
            struct ast_symbol_value *ast_symbol_value = ast_list_first(ast_symbol_value_list)->elem;
            struct ast_list *list = ast_symbol_value->ast_symbol_value_element_list;

            // 
            if (list->count == 1) {
            // if (1) {
                char symbol_name[256] = "";
                struct ast_symbol_value_element *ast_symbol_value_element = ast_list_first(list)->elem;
                ast_type type = ast_symbol_value_element->elem_type;

                switch (type) {
                    case AST_MCC_STRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_string);
                        break;
                    case AST_MCC_SYMBOL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_symbol);
                        break;
                    case AST_CSTRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.cstring);
                        break;
                    case AST_NULL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.null_);
                        break;
                    case AST_TOKEN:
                        sprintf(symbol_name, "%s", "ast_token");
                        break;
                    default:
                        fprintf(stderr, "\tlist_parameter_action >> unknown type [%s] \n", ast_str(type));
                        break;
                }

                fprintf(out_lyc, "%s_LIST ", symbol_name);
                if (symbols_index(symbol_name) < 0) {
                    symbols_add(symbol_name);

                    // 
                }
            }
            else {
                // fprintf(out_lyc, "LIST(%d) ", list->count);
                fprintf(out_lyc, "/""* LIST(%d) *""/", list->count);
            }

            // 
            //// ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_list);

            // 
            // fprintf(out_lyc, "%s ", "_list");
            //// fprintf(out_lyc, "( ");
            //// if (strcmp(self->list_parameter_delim, "") != 0) {
            ////     fprintf(out_lyc, "\"%s\" ", self->list_parameter_delim);
            //// }

            // 
            //// ast_list_traverse(self->ast_list_parameter_value->ast_symbol_value_list);
            //// fprintf(out_lyc, ")* ");
        }
        */
    }
}
// 
void ast_option_parameter_action(struct ast_option_parameter *self) {
    // 
    if (out_jj) {
        fprintf(out_jj, "( ");
        ast_list_traverse(self->ast_option_parameter_value->ast_symbol_value_list);
        fprintf(out_jj, ")? ");
    }
    
    // 
    //
    if (out_lyc) {
        /*
        struct ast_list *ast_symbol_value_list = self->ast_option_parameter_value->ast_symbol_value_list;

        if (ast_symbol_value_list->count == 1) {
            struct ast_symbol_value *ast_symbol_value = ast_list_first(ast_symbol_value_list)->elem;
            struct ast_list *list = ast_symbol_value->ast_symbol_value_element_list;

            // 
            if (list->count == 1) {
                char symbol_name[256] = "";
                struct ast_symbol_value_element *ast_symbol_value_element = ast_list_first(list)->elem;
                ast_type type = ast_symbol_value_element->elem_type;

                switch (type) {
                    case AST_MCC_STRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_string);
                        break;
                    case AST_MCC_SYMBOL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_symbol);
                        break;
                    case AST_CSTRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.cstring);
                        break;
                    case AST_NULL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.null_);
                        break;
                    case AST_TOKEN:
                        sprintf(symbol_name, "%s", "ast_token");
                        break;
                    default:
                        fprintf(stderr, "\toption_parameter_action >> unknown type [%s] \n", ast_str(type));
                        break;
                }

                fprintf(out_lyc, "%s_OPT ", symbol_name);
                if (symbols_index(symbol_name) < 0) {
                    symbols_add(symbol_name);

                    // 
                }
            }
            else {
                fprintf(out_lyc, "OPT(%d) ", list->count);
            }
        }
        */

        //// fprintf(out_lyc, "( ");
        //// ast_list_traverse(self->ast_option_parameter_value->ast_symbol_value_list);
        //// fprintf(out_lyc, ")? ");
        
        fprintf(out_lyc, "/* OPTION */ ");
    }
}
// 
void ast_star_parameter_action(struct ast_star_parameter *self) {
    // fprintf(out_jj, "STAR(%s) \n", ast_str(self->type));
    // fprintf(out_jj, "3");

    //
    if (out_jj) {
        fprintf(out_jj, "( ");
        ast_list_traverse(self->ast_star_parameter_value->ast_symbol_value_list);
        fprintf(out_jj, ")* ");
    }
    
    // 
    if (out_lyc) {
        struct ast_list *ast_symbol_value_list = self->ast_star_parameter_value->ast_symbol_value_list;

        if (ast_symbol_value_list->count == 1) {
            struct ast_symbol_value *ast_symbol_value = ast_list_first(ast_symbol_value_list)->elem;
            struct ast_list *list = ast_symbol_value->ast_symbol_value_element_list;

            // 
            if (list->count == 1) {
                char symbol_name[256] = "";
                struct ast_symbol_value_element *ast_symbol_value_element = ast_list_first(list)->elem;
                ast_type type = ast_symbol_value_element->elem_type;

                switch (type) {
                    case AST_MCC_STRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_string);
                        break;
                    case AST_MCC_SYMBOL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.mcc_symbol);
                        break;
                    case AST_CSTRING:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.cstring);
                        break;
                    case AST_NULL:
                        sprintf(symbol_name, "%s", ast_symbol_value_element->u.null_);
                        break;
                    case AST_TOKEN:
                        sprintf(symbol_name, "%s", "ast_token");
                        break;
                    default:
                        fprintf(stderr, "\tstar_parameter_action >> unknown type [%s] \n", ast_str(type));
                        break;
                }

                fprintf(out_lyc, "%s_STAR ", symbol_name);
                if (symbols_index(symbol_name) < 0) {
                    symbols_add(symbol_name);

                    // 
                }
            }
            else {
                // fprintf(out_lyc, "STAR(%d) ", list->count);
                fprintf(out_lyc, "/* STAR(%d) */ ", list->count);
            }
        }

        //// fprintf(out_lyc, "( ");
        //// ast_list_traverse(self->ast_star_parameter_value->ast_symbol_value_list);
        //// fprintf(out_lyc, ")* ");
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
        // char token_key_buf[128];
        // char token_value_buf[128];
        // sprintf(token_key_buf, "\"%s\"", self->token_key);
        // sprintf(token_value_buf, "%s", self->token_key);

        // fprintf(out_lyc_l_tokendef, "%-40s return %s;\n", token_key_buf, token_value_buf);
        
        // 
        if (tokens_index(self->token_key) < 0) {
            tokens_add(self->token_key);
        }
        // fprintf(out_lyc_y_token, "%%token %s\n", self->token_key);
        
        // 
        // fprintf(out_lyc, "%s", self->token_key);
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




