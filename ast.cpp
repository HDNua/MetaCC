#include "ast.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

#include <boost/format.hpp>

#ifndef nullptr
#define nullptr NULL
#endif

// 
using namespace ast;

// 
const int MAX_TOKEN_LEN = 2048;


//==============================================================================
FILE *out_jj;
FILE *out_java;

//------------------------------------------------------------------------------
FILE *out_lyc;
FILE *out_lyc_y;
FILE *out_lyc_y_token;
FILE *out_lyc_y_list;
FILE *out_lyc_y_option;
FILE *out_lyc_y_star;
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
static const char *ast_str(ast::ast_type type) {
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
int ast_table_LIST_index(list_parameter *elem) {
    // return ast_table_index(&table_LIST_values, elem, (int(*)(const void *, const void *))list_parameter::compare);
    return -1;
}
// 
void ast_table_LIST_add(const char *key, list_parameter *elem) {
    table_add(&table_LIST_keys, key);
    ast_table_add(&table_LIST_values, elem);
}
// 
void ast_table_OPT_init() {
    table_init(&table_OPT_keys);
    ast_table_init(&table_OPT_values);
}
// 
int ast_table_OPT_index(option_parameter *elem) {
    // return ast_table_index(&table_OPT_values, elem, (int(*)(const void *, const void *))ast_option_parameter_compare);
    return -1;
}
// 
void ast_table_OPT_add(const char *key, option_parameter *elem) {
    table_add(&table_OPT_keys, key);
    ast_table_add(&table_OPT_values, elem);
}
// 
void ast_table_STAR_init() {
    table_init(&table_STAR_keys);
    ast_table_init(&table_STAR_values);
}
// 
int ast_table_STAR_index(star_parameter *elem) {
    // return ast_table_index(&table_STAR_values, elem, (int(*)(const void *, const void *))ast_star_parameter_compare);
    return -1;
}
// 
void ast_table_STAR_add(const char *key, star_parameter *elem) {
    table_add(&table_STAR_keys, key);
    ast_table_add(&table_STAR_values, elem);
}



//==============================================================================
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



//==============================================================================
// 
object::~object() {

}
list_node::~list_node() {
    delete _elem;
}
list::~list() {
    while (_tail) {
        list_node *target = _tail;
        _tail = _tail->next();
        delete target;
    }
}
symbol_definition::~symbol_definition() {
    delete _symbol_key;
    delete _symbol_value_list;
}
symbol_key::~symbol_key() {
    delete _key_attributes;
}
key_attributes::~key_attributes() {

}
symbol_value::~symbol_value() {
    delete _symbol_value_element_list;
}
symbol_value_element::~symbol_value_element() {

}
mcc_string::~mcc_string() {

}
mcc_symbol::~mcc_symbol() {

}
list_parameter::~list_parameter() {
    delete _list_parameter_value;
    delete _list_parameter_delim;
}
option_parameter::~option_parameter() {
    delete _option_parameter_value;
}
star_parameter::~star_parameter() {
    delete _star_parameter_value;
}
list_parameter_value::~list_parameter_value() {
    delete _symbol_value_list;
}
option_parameter_value::~option_parameter_value() {
    delete _symbol_value_list;
}
star_parameter_value::~star_parameter_value() {
    // delete _symbol_value_list;
    delete _list_parameter;
}
token_definition::~token_definition() {

}










//==============================================================================
/*
static list_node *ast_list_node_new(void *elem, ast_type type) {
    list_node *ret = (list_node *)malloc(sizeof(list_node));
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
void ast_list_append(struct ast_list *this, void *elem, ast_type type) {
    list_node *node = ast_list_node_new(elem, type);
    this->tail->next = node;
    this->tail = node;
    this->count += 1;
}
// 
list_node *ast_list_first(struct ast_list *this) {
    return this->head.next;
}
// 
void ast_list_iterate(FILE *out, struct ast_list *this) {
    list_node *node;
    for (node=this->head.next; node; node=node->next) {
        list_node::describe(out, node);
    }
}
*/



// 
int list_node::compare(const list_node *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return 1;
        }
        else if (this->elem_type() != p2->elem_type()) {
            return 1;
        }
        else {
            /*
            switch (this->elem_type()) {
                case AST_LIST:
                    return list::compare(p2->elem());
                case AST_SYMBOL_DEFINITION:
                    return ast_symbol_definition_compare(p2->elem());
                case AST_SYMBOL_KEY:
                    return ast_symbol_key_compare(p2->elem());
                case AST_KEY_ATTRIBUTES:
                    return ast_key_attributes_compare(p2->elem());
                case AST_SYMBOL_VALUE:
                    return ast_symbol_value_compare(p2->elem());
                case AST_SYMBOL_VALUE_ELEMENT:
                    return ast_symbol_value_element_compare(p2->elem());
                case AST_LIST_PARAMETER:
                    return list_parameter::compare(p2->elem());
                case AST_OPTION_PARAMETER:
                    return ast_option_parameter_compare(p2->elem());
                case AST_STAR_PARAMETER:
                    return ast_star_parameter_compare(p2->elem());
                case AST_TOKEN_DEFINITION:
                    return token_definition::compare(p2->elem());
                default:
                    fprintf(stderr, "list_node_cmp >> invalid type [%s] \n", ast_str(this->elem_type()));
                    return 1;
            }
            */
            return this->ast_elem()->compare(p2->ast_elem());
        }
    }
    return 0;
}
// 
int list::compare(const list *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (this->elem_type() != p2->elem_type()) {
            return 1;
        }
        else if (this->count() != p2->count()) {
            return 1;
        }
        else {
            int i, len;
            const list_node *n1 = this->first();
            const list_node *n2 = p2->first();
            for (i=0, len=this->count(); i<len; ++i) {
                if (n1->compare(n2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
// 
int symbol_definition::compare(const symbol_definition *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (this->ast_symbol_key()->compare(p2->ast_symbol_key())) {
            return 1;
        }
        // return list::compare(this->ast_symbol_value_list, p2->ast_symbol_value_list);
        return ast_symbol_value_list()->compare(p2->ast_symbol_value_list());
    }
    return 0;
}
// 
int symbol_key::compare(const symbol_key *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (this->symbol_name() != p2->symbol_name()) {
            return 1;
        }
        // return ast_key_attributes_compare(this->ast_key_attributes, p2->ast_key_attributes);
        return this->ast_key_attributes()->compare(p2->ast_key_attributes());
    }
    return 0;
}
// 
int key_attributes::compare(const key_attributes *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        // return strcmp(this->attributes, p2->attributes);
        return this->attributes() != p2->attributes();
    }
    return 0;
}
// 
int symbol_value::compare(const symbol_value *p2) const {
    if (this != p2) {
        return list::compare(this->ast_symbol_value_element_list(), p2->ast_symbol_value_element_list());
    }
    return 0;
}
/*
int symbol_value_element::compare(const symbol_value_element *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            fprintf(stderr, ">> super weird situation occurred \n");
            return -1;
        }
        else if (this->elem_type() != p2->elem_type()) {
            return 1;
        }
        else {
            / *
            switch (this->elem_type) {
                case AST_MCC_STRING:
                    return strcmp(this->u.mcc_string, p2->u.mcc_string);
                case AST_MCC_SYMBOL:
                    return strcmp(this->u.mcc_symbol, p2->u.mcc_symbol);
                case AST_LIST_PARAMETER:
                    return list_parameter::compare(this->u.ast_list_parameter, p2->u.ast_list_parameter);
                case AST_OPTION_PARAMETER:
                    return ast_option_parameter_compare(this->u.ast_option_parameter, p2->u.ast_option_parameter);
                case AST_STAR_PARAMETER:
                    return ast_star_parameter_compare(this->u.ast_star_parameter, p2->u.ast_star_parameter);
                case AST_CSTRING:
                    return strcmp(this->u.cstring, p2->u.cstring);
                case AST_NULL:
                    return strcmp(this->u.null_, p2->u.null_);
                case AST_TOKEN_DEFINITION:
                    return token_definition::compare(this->u.ast_token_definition, p2->u.ast_token_definition);
                default:
                    fprintf(stderr, "symbol_value_element_cmp >> invalid type [%s] \n", ast_str(this->elem_type));
                    return 1;
            }
            * /
            return this->compare();
        }
    }
    return 0;
}
*/
// 
int list_parameter::compare(const list_parameter *p2) const {
    if (this != p2) {
        if (this->type() != p2->type()) {
            return -1;
        }
        else if (list_parameter_value::compare(this->ast_list_parameter_value(), p2->ast_list_parameter_value())) {
            return 1;
        }
        else if (this->list_parameter_delim() != p2->list_parameter_delim()) {
            return 1;
        }
    }
    return 0;
}
// 
int option_parameter::compare(const option_parameter *p2) const {
    if (this != p2) {
        return option_parameter_value::compare(this->ast_option_parameter_value(), p2->ast_option_parameter_value());
    }
    return 0;
}
// 
int star_parameter::compare(const star_parameter *p2) const {
    if (this != p2) {
        return star_parameter_value::compare(this->ast_star_parameter_value(), p2->ast_star_parameter_value());
    }
    return 0;
}
// 
int list_parameter_value::compare(const list_parameter_value *p2) const {
    if (this != p2) {
        return list::compare(this->ast_symbol_value_list(), p2->ast_symbol_value_list());
    }
    return 0;
}
// 
int option_parameter_value::compare(const option_parameter_value *p2) const {
    if (this != p2) {
        return list::compare(this->ast_symbol_value_list(), p2->ast_symbol_value_list());
    }
    return 0;
}
// 
int star_parameter_value::compare(const star_parameter_value *p2) const {
    if (this != p2) {
        // return list::compare(this->ast_symbol_value_list(), p2->ast_symbol_value_list());
        return this->ast_list_parameter()->compare(p2->ast_list_parameter());
    }
    return 0;
}
// 
int token_definition::compare(const token_definition *p2) const {
    if (this != p2) {
        // int ret;
        // if (ret = strcmp(this->token_key, p2->token_key)) {
        //     return ret;
        // }
        // if (ret = strcmp(this->token_value, p2->token_value)) {
        //     return ret;
        // }
        if (this->token_key() != p2->token_key()) {
            return 1;
        }
        else if (this->token_value() != p2->token_value()) {
            return 1;
        }
    }
    return 0;
}



// 
void list_node::describe(FILE *out) {
    describe_begin();

    /*
    if (this->type == AST_LIST_NODE) {
        // tab_depth();
        // fprintf(out_jj, "%s \n", ast_str(this->type));
        switch (this->elem_type) {
            case AST_LIST:
                ast_list_iterate(out, this->elem);
                break;
            case AST_SYMBOL_DEFINITION:
                ast_symbol_definition_describe(out, this->elem);
                break;
            case AST_SYMBOL_KEY:
                ast_symbol_key_describe(out, this->elem);
                break;
            case AST_KEY_ATTRIBUTES:
                ast_key_attributes_describe(out, this->elem);
                break;
            case AST_SYMBOL_VALUE:
                ast_symbol_value_describe(out, this->elem);
                break;
            case AST_SYMBOL_VALUE_ELEMENT:
                ast_symbol_value_element_describe(out, this->elem);
                break;
            case AST_LIST_PARAMETER:
                list_parameter::describe(out, this->elem);
                break;
            case AST_OPTION_PARAMETER:
                ast_option_parameter_describe(out, this->elem);
                break;
            case AST_STAR_PARAMETER:
                ast_star_parameter_describe(out, this->elem);
                break;
            default:
                fprintf(stderr, "invalid node element type [%d] \n", this->elem_type);
                exit(1);
                break;
        }
    }
    else {
        fprintf(stderr, "invalid node \n");
        exit(1);
    }
    */

    describe_end();
}



// 
void ast_symbol_definition_describe(FILE *out) {
    describe_begin();
    tab_depth();

    /*
    // fprintf(out_jj, "%s \n", ast_str(this->type));
    ast_symbol_key_describe(out, this->ast_symbol_key);
    ast_list_iterate(out, this->ast_symbol_value_list);
    */

    describe_end();
}
// 
void ast_symbol_key_describe(FILE *out) {
    /*
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(this->type));

    tab_depth();
    // fprintf(out_jj, ": %s \n", this->symbol_name);
    fprintf(out_jj, "%s: \n", this->symbol_name);

    if (this->ast_key_attributes) {
        ast_key_attributes_describe(out, this->ast_key_attributes);
    }

    // describe_end();
    */
}
// 
void ast_key_attributes_describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(this->type));

    describe_end();
    */
}
// 
void ast_symbol_value_describe(FILE *out) {
    /*
    describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(this->type));

    ast_list_iterate(out, this->ast_symbol_value_element_list);

    describe_end();
    */
}
// 
void ast_symbol_value_element_describe(FILE *out) {
    /*
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(this->type));

    switch (this->elem_type) {
        case AST_MCC_STRING:
            tab_depth();
            fprintf(out_jj, "\"%s\" \n", this->u.mcc_string);
            break;
        case AST_MCC_SYMBOL:
            tab_depth();
            fprintf(out_jj, "%s \n", this->u.mcc_symbol);
            break;
        case AST_LIST_PARAMETER:
            list_parameter::describe(out, this->u.ast_list_parameter);
            break;
        case AST_OPTION_PARAMETER:
            ast_option_parameter_describe(out, this->u.ast_option_parameter);
            break;
        case AST_STAR_PARAMETER:
            ast_star_parameter_describe(out, this->u.ast_star_parameter);
            break;
        case AST_TOKEN_DEFINITION:
            token_definition::describe(out, this->u.ast_token_definition);
            break;
        case AST_CSTRING:
            tab_depth();
            fprintf(out_jj, "C\"%s\" \n", this->u.cstring);
            break;
        case AST_NULL:
            tab_depth();
            fprintf(out_jj, "%s \n", this->u.null_);
            break;
        case AST_TOKEN:
            token_definition::describe(out, this->u.ast_token_definition);
            break;
        default:
            fprintf(stderr, "invalid symbol value element [%d] \n", this->elem_type);
            exit(1);
    }

    // describe_end();
    */
}
// 
void list_parameter::describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "LIST(%s, [%s]) \n", ast_str(this->type), this->list_parameter_delim);

    describe_end();
    */
}
// 
void ast_option_parameter_describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "OPTION(%s) \n", ast_str(this->type));

    describe_end();
    */
}
// 
void ast_star_parameter_describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "STAR(%s) \n", ast_str(this->type));

    describe_end();
    */
}
// 
void list_parameter_value::describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(this->type));

    describe_end();
    */
}
// 
void option_parameter_value::describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(this->type));

    describe_end();
    */
}
// 
void star_parameter_value::describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(this->type));

    describe_end();
    */
}
// 
void token_definition::describe(FILE *out) {
    /*
    describe_begin();
    tab_depth();
    fprintf(out_jj, "%s \n", ast_str(this->type));

    describe_end();
    */
}









// 
void list::action(FILE *out, act_opt option) {
    static int depth = 0;
    list_node *node;

    // 
    if (out_lyc) {
        if (this->elem_type() == AST_SYMBOL_VALUE) {
            ++depth;
            for (node=this->first(); node; node=node->next()) {
                // list_node::action(out, node, option);
                node->action(out, option);

                if (this->elem_type() == AST_SYMBOL_VALUE) {
                    if (node->next()) {
                        if (depth == 0) {
                            fprintf(out_lyc, ":");
                        }
                    }
                }
            }
            --depth;
        }
        else {
            for (node=this->first(); node; node=node->next()) {
                // list_node::action(out, node, option);
                node->action(out, option);
            }
        }
    }
}
// 
void list_node::action(FILE *out, act_opt option) {
    if (this->type() == AST_LIST_NODE) {
        this->ast_elem()->action(out, option);
    }
    else {
        fprintf(stderr, "invalid node \n");
        exit(1);
    }
}



// 
void symbol_definition::action(FILE *out, act_opt option) {
    symbol_key *ast_symbol_key = this->ast_symbol_key();
    key_attributes *ast_key_attr = ast_symbol_key->ast_key_attributes();
    list *ast_symbol_value_list = this->ast_symbol_value_list();
    const char *symbol_name = ast_symbol_key->symbol_name().c_str();

    // 
    if (ast_key_attr) {
        /*
        if (strcmp(ast_key_attr->attributes, "SKIP") == 0) {
            return;
        }
        else if (strcmp(ast_key_attr->attributes, "TERMINAL") == 0) {
            // return;
        }
        else {
            exit(1);
        }
        */
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
        fprintf(out_lyc, "%s \n", symbol_name);

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
        fprintf(out_lyc_ast_h_declaration, "void ast_%s_describe(FILE *out, struct ast_%s *this);\n", symbol_name, symbol_name);
        fprintf(out_lyc_ast_h_declaration, "// \n");
        fprintf(out_lyc_ast_h_declaration, "void ast_%s_action(FILE *out, struct ast_%s *this);\n", symbol_name, symbol_name);
        fprintf(out_lyc_ast_h_declaration, "\n");
        fprintf(out_lyc_ast_h_declaration, "\n");
        fprintf(out_lyc_ast_h_declaration, "\n");

        // 
        fprintf(out_lyc_ast_c_templates, "// \n");
        fprintf(out_lyc_ast_c_templates, "void ast_%s_describe(FILE *out, struct ast_%s *this) {\n", symbol_name, symbol_name);
        fprintf(out_lyc_ast_c_templates, "    \n");
        fprintf(out_lyc_ast_c_templates, "}\n");
        fprintf(out_lyc_ast_c_templates, "// \n");
        fprintf(out_lyc_ast_c_templates, "void ast_%s_action(FILE *out, struct ast_%s *this) {\n", symbol_name, symbol_name);
        fprintf(out_lyc_ast_c_templates, "    \n");
        fprintf(out_lyc_ast_c_templates, "}\n");
        fprintf(out_lyc_ast_c_templates, "\n");
        fprintf(out_lyc_ast_c_templates, "\n");
        fprintf(out_lyc_ast_c_templates, "\n");

        // gather syntax list.
        {
            list *ast_list = ast_symbol_value_list;
            list_node *node;
            int elem_list_flag = 0;

            // fprintf(out_lyc, "    %c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->first(); node; node = node->next()) {
                symbol_value *ast_symbol_value = dynamic_cast<symbol_value *>(node->ast_elem());
                list *ast_elem_list = ast_symbol_value->ast_symbol_value_element_list();
                list_node *node2;

                // 
                fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
                for (node2 = ast_elem_list->first(); node2; node2 = node2->next()) {
                    symbol_value_element *ast_elem = dynamic_cast<symbol_value_element *>(node2->ast_elem());
                    mcc_symbol *new_elem = nullptr;

                    if (ast_elem == nullptr) {
                        fprintf(out_lyc, "/""* empty *""/ ");
                        continue;
                    }

                    switch (ast_elem->elem_type()) {
                        case AST_MCC_STRING:
                        case AST_MCC_SYMBOL:
                        case AST_TOKEN_DEFINITION:
                            ast_elem->glance(out, option);
                            ast_elem->action(out, option);
                            break;
                        case AST_LIST_PARAMETER:
                        case AST_OPTION_PARAMETER:
                        case AST_STAR_PARAMETER:
                            new_elem = new mcc_symbol(ast_elem->glance(out, option));
                            delete ast_elem;
                            node2->set_ast_elem(new_elem);
                            new_elem->action(out, option);
                            break;

                        default:
                            fprintf(stderr, "symbol_definition_action >> invalid type [%s] \n", 
                                    ast_str(ast_elem->elem_type()));
                            exit(1);
                    }
                }
                fprintf(out_lyc, "\n    {\n        $$ = 0;\n    }\n");
            }
        }

        // 
        fprintf(out_lyc, "    ;\n\n");
    }
}
// 
void symbol_key::action(FILE *out, act_opt option) {
    if (out_lyc) {
        // describe_begin();
        // tab_depth();
        // fprintf(out_jj, "%s \n", ast_str(this->type));
        // tab_depth();
        // fprintf(out_jj, ": %s \n", this->symbol_name);
        // fprintf(out_lyc, "%s: \n", this->symbol_name);
        // 
        // if (this->ast_key_attributes) {
        //    key_attributes::action(this->ast_key_attributes);
        // }
        // describe_end();
    }
}
// 
void key_attributes::action(FILE *out, act_opt option) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(this->type));
    // describe_end();
}

// 
void symbol_value::action(FILE *out, act_opt option) {
    // describe_begin();
    // tab_depth();
    // fprintf(out_jj, "%s \n", ast_str(this->type));

    // ast_list_traverse(out, this->ast_symbol_value_element_list, option);
    // this->ast_symbol_value_element_list()->action(out, option);

    list *ast_symbol_value_element_list = this->ast_symbol_value_element_list();
    for (list_node *node=ast_symbol_value_element_list->first(); node; node=node->next()) {
        symbol_value_element *elem = dynamic_cast<symbol_value_element *>(node->ast_elem());
        mcc_symbol *ret;
        
        // 
        switch (elem->elem_type()) {
            case AST_MCC_STRING:
                ret = new mcc_symbol(elem->glance(out, option));
                delete elem;
                node->set_ast_elem(ret);
                ret->action(out, option);
                break;

            case AST_MCC_SYMBOL:
                elem->action(out, option);
                break;

            case AST_LIST_PARAMETER:
                ret = new mcc_symbol(elem->glance(out, option));
                delete elem;
                node->set_ast_elem(ret);
                ret->action(out, option);
                break;

            case AST_OPTION_PARAMETER:
                ret = new mcc_symbol(elem->glance(out, option));
                delete elem;
                node->set_ast_elem(ret);
                ret->action(out, option);
                break;

            case AST_STAR_PARAMETER:
                ret = new mcc_symbol(elem->glance(out, option));
                delete elem;
                node->set_ast_elem(ret);
                ret->action(out, option);
                break;

            case AST_TOKEN_DEFINITION:
                elem->action(out, option);
                break;
                
            default:
                fprintf(stderr, "symbol_value_action >> invalid type [%s] \n", ast_str(elem->elem_type()));
                break;
        }
    }

    // describe_end();
}
// 
void symbol_value_element::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        /*
        switch (this->elem_type) {
            case AST_MCC_STRING:
                mcc_string_action(out, this->u.mcc_string, option);
                break;
            case AST_MCC_SYMBOL:
                // fprintf(out, "/""* out_lyc(%p) vs out(%p) *""/ ", out_lyc, out);
                if (option & ~ACTOPT_IS_NONTERMINAL) {
                    fprintf(out, "%s ", this->u.mcc_symbol);
                }
                break;
            case AST_LIST_PARAMETER:
                list_parameter::action(out, this->u.ast_list_parameter, option | ACTOPT_IS_NONTERMINAL);
                break;
            case AST_OPTION_PARAMETER:
                option_parameter::action(out, this->u.ast_option_parameter, option | ACTOPT_IS_NONTERMINAL);
                break;
            case AST_STAR_PARAMETER:
                star_parameter::action(out, this->u.ast_star_parameter, option | ACTOPT_IS_NONTERMINAL);
                break;
            case AST_TOKEN_DEFINITION:
                token_definition::action(out, this->u.ast_token_definition, option | ACTOPT_IS_NONTERMINAL);
                break;
            case AST_CSTRING:
                fprintf(out, "C\"%s\" ", this->u.cstring);
                break;
            case AST_NULL:
                fprintf(out, "%s ", this->u.null_);
                break;
            case AST_TOKEN:
                token_definition::action(out, this->u.ast_token_definition, option);
                break;
            default:
                fprintf(stderr, "invalid symbol value element [%d] \n", this->elem_type);
                exit(1);
        }
        */
        throw std::string("INVALID CASE");
    }
}
// 
void mcc_string::action(FILE *out, act_opt option) {
    if (0) {
        char key_name[256];
        int index = string_tokens_index(_value.c_str());

        // 
        sprintf(key_name, "TOKEN_%d", index);
        if (index < 0) {
            index = string_token_keys.count;
            string_tokens_add(key_name, _value.c_str());

            // 
            sprintf(key_name, "TOKEN_%d", index);
            fprintf(out_lyc_l_tokendef, "\"%s\" return %s;\n", _value.c_str(), key_name);
        }

        // 
        fprintf(out, "%s /* %s */ ", key_name, _value.c_str());
    }
    else if (1) {
        if (_value != "") {
            char key_name[256];
            int index = string_tokens_index(_value.c_str());

            if (index < 0) {
                fprintf(stderr, "mcc_string_action >> cannot find token definition of [%s] \n", _value.c_str());
                exit(1);
            }

            // 
            sprintf(key_name, "TOKEN_%d", index);
            fprintf(out, "%s /* %s */ ", key_name, _value.c_str());
        }
    }

}
// 
void mcc_symbol::action(FILE *out, act_opt option) {
    // 
    fprintf(out, "%s ", this->value().c_str());
}

// 
void list_parameter::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        std::string ret = this->ast_list_parameter_value()->glance(out_lyc_y_list, option);
        int index = ast_table_LIST_index(this);
        if (index < 0) {
            fprintf(stderr, "list_parameter_action >> cannot find definition of LIST[%s] \n", ret.c_str());
            // exit(1);
        }
        // 
        fprintf(out, "%s ", ret.c_str());
    }
}
// 
void option_parameter::action(FILE *out, act_opt option) {
    //
    if (out_lyc) {
        std::string ret = this->ast_option_parameter_value()->glance(out_lyc_y_option, option);
        int index = ast_table_OPT_index(this);
        if (index < 0) {
            fprintf(stderr, "option_parameter_action >> cannot find definition of OPTION[%s] \n", ret.c_str());
            // exit(1);
        }
        // 
        fprintf(out, "%s ", ret.c_str());
    }
}
// 
void star_parameter::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        std::string ret = this->ast_star_parameter_value()->glance(out_lyc_y_star, option);
        int index = ast_table_STAR_index(this);
        if (index < 0) {
            fprintf(stderr, "star_parameter_action >> cannot find definition of STAR[%s] \n", ret.c_str());
            // exit(1);
        }
        // 
        fprintf(out, "%s ", ret.c_str());
    }
}
// 
void list_parameter_value::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // fprintf(stderr, "/* LIST(%d) */\n", this->ast_symbol_value_list->count);
        // ast_list_traverse(out, this->ast_symbol_value_list, option);
        this->ast_symbol_value_list()->action(out, option);
    }
}
// 
void option_parameter_value::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // fprintf(stderr, "/* OPTION(%d) */\n", this->ast_symbol_value_list->count);
        // list::describe(out, this->ast_symbol_value_list, option);
        this->ast_symbol_value_list()->action(out, option);
    }
}
// 
void star_parameter_value::action(FILE *out, act_opt option) {
    //
    if (out_jj) {
        fprintf(out_jj, "6");
    }

    // 
    if (out_lyc) {
        // fprintf(stderr, "/* STAR(%d) */\n", this->ast_symbol_value_list->count);
        // ast_list_traverse(out, this->ast_symbol_value_list, option);
        // this->ast_symbol_value_list()->action(out, option);
        this->ast_list_parameter()->action(out, option);
    }
}
// 
void token_definition::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // char token_key_buf[128];
        // char token_value_buf[128];
        // sprintf(token_key_buf, "\"%s\"", this->token_key);
        // sprintf(token_value_buf, "%s", this->token_key);

        // fprintf(out_lyc_l_tokendef, "%-40s return %s;\n", token_key_buf, token_value_buf);
        
        // 
        if (tokens_index(this->token_key().c_str()) < 0) {
            tokens_add(this->token_key().c_str());
        }
        // fprintf(out_lyc_y_token, "%%token %s\n", this->token_key);
        
        // 
        fprintf(out_lyc, "%s ", this->token_key().c_str());
    }
}

/*
// 
void ast_symbol_value_list_node_action(FILE *out, act_opt option) {
    if (this->type == AST_LIST_NODE) {
        switch (this->elem_type) {
            case AST_LIST:
                ast_list_traverse(out, this->elem, option);
                break;
            case AST_SYMBOL_DEFINITION:
                symbol_definition::action(out, this->elem, option);
                break;
            case AST_SYMBOL_KEY:
                symbol_key::action(out, this->elem, option);
                break;
            case AST_KEY_ATTRIBUTES:
                key_attributes::action(out, this->elem, option);
                break;
            case AST_SYMBOL_VALUE:
                symbol_value::action(out, this->elem, option);
                break;
            case AST_SYMBOL_VALUE_ELEMENT:
                symbol_value_element::action(out, this->elem, option);
                break;
            case AST_LIST_PARAMETER:
                list_parameter::action(out, this->elem, option);
                break;
            case AST_OPTION_PARAMETER:
                option_parameter::action(out, this->elem, option);
                break;
            case AST_STAR_PARAMETER:
                star_parameter::action(out, this->elem, option);
                break;
            default:
                fprintf(stderr, "invalid node element type [%d] \n", this->elem_type);
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
void ast_symbol_value_list_traverse(FILE *out, act_opt option) {
    list_node *node;
    for (node=this->head.next; node; node=node->next) {
        ast_symbol_value_list_node_action(out, node, option);
    }
}
*/










// 
std::string list::glance(FILE *out, act_opt option) {
    static int depth = 0;
    list_node *node;

    // 
    if (out_lyc) {
        if (this->elem_type() == AST_SYMBOL_VALUE) {
            ++depth;
            for (node=this->first(); node; node=node->next()) {
                // list_node::glance(out, node, option);
                node->glance(out, option);

                if (this->elem_type() == AST_SYMBOL_VALUE) {
                    if (node->next()) {
                        if (depth == 0) {
                            fprintf(out_lyc, ":");
                        }
                    }
                }
            }
            --depth;
        }
        else {
            for (node=this->first(); node; node=node->next()) {
                // list_node::glance(out, node, option);
                node->glance(out, option);
            }
        }
    }

    // 
    return std::string("");
}
// 
std::string list_node::glance(FILE *out, act_opt option) {
    if (this->type() == AST_LIST_NODE) {
        return this->ast_elem()->glance(out, option);
    }
    else {
        fprintf(stderr, "invalid node \n");
        exit(1);
    }
}



// 
std::string symbol_definition::glance(FILE *out, act_opt option) {
    symbol_key *ast_symbol_key = this->ast_symbol_key();
    key_attributes *ast_key_attr = ast_symbol_key->ast_key_attributes();
    list *ast_symbol_value_list = this->ast_symbol_value_list();
    // const char *symbol_name = ast_symbol_key->symbol_name().c_str();

    // 
    if (ast_key_attr) {
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
        // fprintf(out_lyc, "%s \n", symbol_name);
        
        // gather syntax list.
        {
            list *ast_list = ast_symbol_value_list;
            list_node *node;
            int elem_list_flag = 0;

            // fprintf(out_lyc, "    %c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->first(); node; node = node->next()) {
                symbol_value *ast_symbol_value = dynamic_cast<symbol_value *>(node->ast_elem());
                list *ast_elem_list = ast_symbol_value->ast_symbol_value_element_list();
                list_node *node2;

                // 
                fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
                for (node2 = ast_elem_list->first(); node2; node2 = node2->next()) {
                    symbol_value_element *ast_elem = dynamic_cast<symbol_value_element *>(node2->ast_elem());
                    if (ast_elem != nullptr) {
                        mcc_symbol *new_elem = new mcc_symbol(ast_elem->glance(out, option));
                        delete ast_elem;
                        node->set_ast_elem(new_elem);
                        new_elem->action(out, option);
                    }
                }
                // fprintf(out_lyc, "\n    {\n        $$ = 0;\n    }\n");
            }
        }

        // add current list
        throw std::string("INVALID CASE");
        return std::string("INVALID CASE");
    }
    return "null";
}
// 
std::string symbol_key::glance(FILE *out, act_opt option) {
    if (out_lyc) {
        // describe_begin();
        // tab_depth();
        // fprintf(out_jj, "%s \n", ast_str(this->type));
        // tab_depth();
        // fprintf(out_jj, ": %s \n", this->symbol_name);
        // fprintf(out_lyc, "%s: \n", this->symbol_name);
        // 
        // if (this->ast_key_attributes) {
        //    key_attributes::glance(this->ast_key_attributes);
        // }
        // describe_end();

        return symbol_name();
    }
    return "null";
}
// 
std::string key_attributes::glance(FILE *out, act_opt option) {
    return attributes();
}

// 
std::string symbol_value::glance(FILE *out, act_opt option) {
    return this->ast_symbol_value_element_list()->glance(out, option);
}
// 
std::string symbol_value_element::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // 
        return std::string("null");
    }
    return "null";
}
// 
std::string mcc_string::glance(FILE *out, act_opt option) {
    if (_value != "") {
        char key_name[256];
        int index = string_tokens_index(_value.c_str());

        // 
        sprintf(key_name, "TOKEN_%d", index);
        if (index < 0) {
            index = string_token_keys.count;
            string_tokens_add(key_name, _value.c_str());

            // 
            sprintf(key_name, "TOKEN_%d", index);
            fprintf(out_lyc_l_tokendef, "\"%s\" return %s;\n", _value.c_str(), key_name);
        }

        // 
        // fprintf(out, "%s /* %s */ ", key_name, _value.c_str());
        // return str(boost::format("%1% /""* %2% *""/") % key_name % _value.c_str());
        return std::string(key_name);
    }
    return std::string("");
}
// 
std::string mcc_symbol::glance(FILE *out, act_opt option) {
    return value();
}

// 
std::string list_parameter::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        char key_name[256];

        if (1) {
            list_parameter_value *ast_list_parameter_value = this->ast_list_parameter_value();
            list *ast_symbol_value_list = ast_list_parameter_value->ast_symbol_value_list();
            mcc_symbol *new_elem = nullptr;

            std::vector< std::vector<std::string> > symbol_list_list;
            for (list_node *node1=ast_symbol_value_list->first(); node1; node1=node1->next()) {
                symbol_value *elem1 = dynamic_cast<symbol_value *>(node1->ast_elem());
                std::string symbol1 = elem1->glance(out, option);

                // 
                list *ast_elem_list = elem1->ast_symbol_value_element_list();
                std::vector< std::string> symbol_list;
                for (list_node *node2=ast_elem_list->first(); node2; node2=node2->next()) {
                    symbol_value_element *elem2 = dynamic_cast<symbol_value_element *>(node2->ast_elem());
                    std::string symbol2 = elem2->glance(out, option);

                    switch (elem2->elem_type()) {
                        case AST_MCC_STRING:
                        case AST_MCC_SYMBOL:
                        case AST_TOKEN_DEFINITION:
                            break;
                        case AST_LIST_PARAMETER:
                        case AST_OPTION_PARAMETER:
                        case AST_STAR_PARAMETER:
                            new_elem = new mcc_symbol(symbol2);
                            delete elem2;
                            node2->set_ast_elem(new_elem);
                            // elem2 = new_elem;
                            break;
                        default:
                            fprintf(stderr, "list_parameter >> invalid type [%s] \n", ast_str(node2->elem_type()));
                            // exit(1);
                            break;
                    }

                    // 
                    symbol_list.push_back(symbol2);
                }

                // 
                symbol_list_list.push_back(symbol_list);
            }

            // 
            if (symbol_list_list.size() == 1) {
                // 
                int index = ast_table_LIST_index(this);
                if (index < 0) {
                    index = table_LIST_keys.count;
                    sprintf(key_name, "LIST_%d", index);
                    ast_table_LIST_add(key_name, this);

                    // 
                    fprintf(out_lyc_y_list, "LIST_%d\n", index);
                    fprintf(out_lyc_y_list, "    : ");
                    ast_symbol_value_list->action(out, option);
                    fprintf(out_lyc_y_list, "\n");
                    fprintf(out_lyc_y_list, "    | LIST_%d %s ", index, list_parameter_delim()->glance(out, option).c_str());
                    ast_symbol_value_list->action(out, option);
                    fprintf(out_lyc_y_list, "\n");
                    fprintf(out_lyc_y_list, "    ;\n");
                }
            }
            else {
                fprintf(stderr, "list_parameter >> LIST cannot contain VBAR('|') \n");
                // exit(1);
            }
        }
        else if (0) {
            // char key_name[256];
            int index;

            // ast_list_traverse(this->list_parameter::value->ast_symbol_value_list);
            // list_parameter_value::glance(out, this->list_parameter::value, option);
            std::string ret = this->ast_list_parameter_value()->glance(out, option);

            index = ast_table_LIST_index(this);
            if (index < 0) {
                index = table_LIST_keys.count;

                // 
                sprintf(key_name, "LIST_%d", index);
                ast_table_LIST_add(key_name, this);

                // 
                fprintf(out_lyc_y_list, "LIST_%d\n", index);
                fprintf(out_lyc_y_list, "    : ");

                // list_parameter_value::glance(this->list_parameter::value);
                // ast_list_traverse(out_lyc_y_list, this->list_parameter::value->ast_symbol_value_list, option);
                this->ast_list_parameter_value()->ast_symbol_value_list()->glance(out, option);

                fprintf(out_lyc_y_list, "\n");
                fprintf(out_lyc_y_list, "    | LIST_%d ", index);

                // if (strcmp(this->list_parameter_delim, "") == 0) {
                if (this->list_parameter_delim()->compare("") == 0) {
                    // fprintf(out_lyc_y_list, "\"%s\" ", this->list_parameter_delim);
                }
                else {
                    // mcc_string_glance(out_lyc_y_list, this->list_parameter_delim, option);
                    this->list_parameter_delim()->action(out_lyc_y_list, option);


                    // int token_index = string_tokens_index(this->list_parameter_delim);
                    // if (token_index < 0) {
                    // fprintf(out_lyc_y_list, "\"%s\" ", this->list_parameter_delim);
                    // token_index = tokens.count;
                    // tokens_add(this->list_parameter_delim);
                    // }
                    // fprintf(out_lyc_y_list, "TOKEN_%d ", token_index);
                }

                // list_parameter_value::glance(this->list_parameter::value);
                // ast_list_traverse(out_lyc_y_list, this->list_parameter::value->ast_symbol_value_list, option);
                this->ast_list_parameter_value()->ast_symbol_value_list()->glance(out, option);

                fprintf(out_lyc_y_list, "\n");
                fprintf(out_lyc_y_list, "    ;\n");
            }

            // 
            // fprintf(out, "LIST_%d ", index);
            // return std::string("LIST_") + std::string(index);
            //// return str(boost::format("LIST_%1%") % index);
            return ret;
            }
    }
    return "null";
}
// 
std::string option_parameter::glance(FILE *out, act_opt option) {
    //
    if (out_lyc) {
        char key_name[256];
        int index;

        // ast_list_traverse(this->list_parameter::value->ast_symbol_value_list);
        // option_parameter_value::glance(out, this->ast_option_parameter_value(), option);
        std::string ret = this->ast_option_parameter_value()->glance(out, option);

        index = ast_table_OPT_index(this);
        if (index < 0) {
            index = table_OPT_keys.count;

            // 
            sprintf(key_name, "OPT_%d", index);
            ast_table_OPT_add(key_name, this);

            // 
            fprintf(out_lyc_y_option, "OPT_%d\n", index);
            fprintf(out_lyc_y_option, "    : /* empty */\n");
            fprintf(out_lyc_y_option, "    | ");
            
            // list_parameter_value::glance(this->list_parameter::value);
            // ast_list_traverse(out_lyc_y_option, this->ast_option_parameter_value->ast_symbol_value_list, option);
            this->ast_option_parameter_value()->glance(out_lyc_y_option, option);

            fprintf(out_lyc_y_option, "\n");
            fprintf(out_lyc_y_option, "    ;\n");
        }

        // 
        // fprintf(out, "OPT_%d ", index);
        // return std::string("OPT_") + index;
        //// return str(boost::format("OPT_%1%") % index);
        return ret;
    }
    return "null";
}
// 
std::string star_parameter::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        char key_name[256];
        int index;

        // star_parameter_value::glance(out, this->ast_star_parameter_value, option);
        std::string ret = this->ast_star_parameter_value()->glance(out, option);

        index = ast_table_STAR_index(this);
        if (index < 0) {
            index = table_STAR_keys.count;

            // 
            sprintf(key_name, "STAR_%d", index);
            ast_table_STAR_add(key_name, this);

            // 
            fprintf(out_lyc_y_star, "STAR_%d\n", index);
            fprintf(out_lyc_y_star, "    : /* empty */\n");
            fprintf(out_lyc_y_star, "    | ");
            
            // ast_list_traverse(out_lyc_y_star, this->ast_star_parameter_value->ast_symbol_value_list, option);
            this->ast_star_parameter_value()->action(out_lyc_y_star, option);

            fprintf(out_lyc_y_star, "\n");

            // WORKING
            if (0) {
                fprintf(out_lyc_y_star, "    | STAR_%d ", index);
            }
            else {

            }

            // list_parameter_value::glance(this->list_parameter::value);
            // ast_list_traverse(out_lyc_y_star, this->ast_star_parameter_value->ast_symbol_value_list, option);
            this->ast_star_parameter_value()->action(out_lyc_y_star, option);

            fprintf(out_lyc_y_star, "\n");
            fprintf(out_lyc_y_star, "    ;\n");
        }

        // 
        // fprintf(out, "STAR_%d ", index);
        //// return str(boost::format("STAR_%1%") % index);
        return ret;
    }
    return "null";
}
// 
std::string list_parameter_value::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // fprintf(stderr, "/* LIST(%d) */\n", this->ast_symbol_value_list->count);
        // ast_list_traverse(out, this->ast_symbol_value_list, option);
        return this->ast_symbol_value_list()->glance(out, option);
    }
    return "null";
}
// 
std::string option_parameter_value::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // fprintf(stderr, "/* OPTION(%d) */\n", this->ast_symbol_value_list->count);
        // list::describe(out, this->ast_symbol_value_list, option);
        return this->ast_symbol_value_list()->glance(out, option);
    }
    return "null";
}
// 
std::string star_parameter_value::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // fprintf(stderr, "/* STAR(%d) */\n", this->ast_symbol_value_list->count);
        // ast_list_traverse(out, this->ast_symbol_value_list, option);
        // return this->ast_symbol_value_list()->glance(out, option);
        return this->ast_list_parameter()->glance(out, option);
    }
    return "null";
}
// 
std::string token_definition::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // char token_key_buf[128];
        // char token_value_buf[128];
        // sprintf(token_key_buf, "\"%s\"", this->token_key);
        // sprintf(token_value_buf, "%s", this->token_key);

        // fprintf(out_lyc_l_tokendef, "%-40s return %s;\n", token_key_buf, token_value_buf);
        
        // 
        if (tokens_index(this->token_key().c_str()) < 0) {
            tokens_add(this->token_key().c_str());
        }
        // fprintf(out_lyc_y_token, "%%token %s\n", this->token_key);
        
        // 
        // fprintf(out_lyc, "%s ", this->token_key().c_str());
        return this->token_key();
    }
    return "null";
}

/*
// 
void ast_symbol_value_list_node_glance(FILE *out, act_opt option) {
    if (this->type == AST_LIST_NODE) {
        switch (this->elem_type) {
            case AST_LIST:
                ast_list_traverse(out, this->elem, option);
                break;
            case AST_SYMBOL_DEFINITION:
                symbol_definition::glance(out, this->elem, option);
                break;
            case AST_SYMBOL_KEY:
                symbol_key::glance(out, this->elem, option);
                break;
            case AST_KEY_ATTRIBUTES:
                key_attributes::glance(out, this->elem, option);
                break;
            case AST_SYMBOL_VALUE:
                symbol_value::glance(out, this->elem, option);
                break;
            case AST_SYMBOL_VALUE_ELEMENT:
                symbol_value_element::glance(out, this->elem, option);
                break;
            case AST_LIST_PARAMETER:
                list_parameter::glance(out, this->elem, option);
                break;
            case AST_OPTION_PARAMETER:
                option_parameter::glance(out, this->elem, option);
                break;
            case AST_STAR_PARAMETER:
                star_parameter::glance(out, this->elem, option);
                break;
            default:
                fprintf(stderr, "invalid node element type [%d] \n", this->elem_type);
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
void ast_symbol_value_list_traverse(FILE *out, act_opt option) {
    list_node *node;
    for (node=this->head.next; node; node=node->next) {
        ast_symbol_value_list_node_glance(out, node, option);
    }
}
*/
