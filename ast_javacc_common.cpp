#include "ast_javacc.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

#include <boost/format.hpp>

#ifndef nullptr
#define nullptr NULL
#endif



//==============================================================================
// 
using namespace ast::javacc;

// 
// const int MAX_TOKEN_LEN = 2048;


//==============================================================================
FILE *out_jj;
FILE *out_java;

//------------------------------------------------------------------------------
FILE *out_lyc;
FILE *out_lyc_y;
FILE *out_lyc_y_union;
FILE *out_lyc_y_token;
FILE *out_lyc_y_type;
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
const char *ast::ast_str(ast::ast_type type) {
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

    // 
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
int longest_symbol_length = 0;
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
        
        // 
        int symbol_length = (int)strlen(symbol_name);
        if (::longest_symbol_length < symbol_length) {
//            printf("longest symbol length has been updated from [%d] to [%d] \n",
//                    ::longest_symbol_length, symbol_length);
            ::longest_symbol_length = symbol_length;
        }
        return 0;
    }
    else {
        return 1;
    }
}

//------------------------------------------------------------------------------
//
struct table string_token_keys;
struct table string_token_values;
// 
void string_tokens_init() {
    table_init(&string_token_keys);
    table_init(&string_token_values);
}
// 
int string_tokens_key_index(const char *key) {
    return table_index(&string_token_keys, key);
}
// 
int string_tokens_value_index(const char *value) {
    return table_index(&string_token_values, value);
}
// 
int string_tokens_add(const char *key, const char *value) {
    if (string_tokens_key_index(key) < 0) {
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
int ast_table_index(struct ast_table *table, symbol_value_element *elem) {
    // / *
    int i, len;
    symbol_value_element **list = table->list;
    for (i=0, len=table->count; i<len; ++i) {
        int ret = 0;

        // 
        switch (elem->elem_type()) {
            case AST_LIST_PARAMETER:
                if (0) {
                    ret = dynamic_cast<list_parameter *>(elem)->compare(
                            dynamic_cast<list_parameter *>(list[i]));
                }
                else {
                    list_parameter *elem_ = (list_parameter *)elem;
                    ret = elem_->compare(list[i]);
                }
                break;
            case AST_OPTION_PARAMETER:
                if (0) {
                    ret = dynamic_cast<option_parameter *>(elem)->compare(
                            dynamic_cast<option_parameter *>(list[i]));
                }
                else {
                    option_parameter *elem_ = (option_parameter *)elem;
                    ret = elem_->compare(list[i]);
                }
                break;
            case AST_STAR_PARAMETER:
                if (0) {
                    ret = dynamic_cast<star_parameter *>(elem)->compare(
                            dynamic_cast<star_parameter *>(list[i]));
                }
                else {
                    star_parameter *elem_ = (star_parameter *)elem;
                    ret = elem_->compare(list[i]);
                }
                break;
            default:
                fprintf(stderr, "weird parameter [%s] \n", ast_str(elem->elem_type()));
                break;
        }

        // 
        if (ret == 0)
            return i;
    }
    // 
    return -1;
}
void ast_table_add(struct ast_table *table, symbol_value_element *elem) {
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
    return ast_table_index(&table_LIST_values, elem);
}
// 
int ast_table_LIST_index(const std::vector<std::string> &sve_list) {
    list *ast_symbol_value_element_list = new list(AST_MCC_SYMBOL);
    for (std::vector<std::string>::const_iterator it = sve_list.begin(); it != sve_list.end(); ++it) {
        ast_symbol_value_element_list->append(new mcc_symbol(*it), AST_MCC_SYMBOL);
    }

    // 
    symbol_value *ast_symbol_value = new symbol_value(ast_symbol_value_element_list);

    // 
    list *ast_symbol_value_list = new list(AST_SYMBOL_VALUE);
    ast_symbol_value_list->append(ast_symbol_value, AST_SYMBOL_VALUE);

    // 
    list_parameter_value *ast_list_param_value = new list_parameter_value(ast_symbol_value_list);

    // 
    list_parameter *ast_list_parameter = new list_parameter(ast_list_param_value, "");

    // 
    std::string key_name = ast_list_parameter->glance(out_lyc_y_list, ACTOPT_NONE);
    int index = ast_table_index(&table_LIST_values, ast_list_parameter);
    if (index < 0) {
        fprintf(stderr, "cannot find defined LIST [%d] \n", index);
        exit(1);
    }
    else {
        // delete ast_list_parameter;
    }
    return index;
}
// 
int ast_table_LIST_index(const std::vector<ast::object *> &obj_list) {
    list *ast_symbol_value_element_list = new list(AST_SYMBOL_VALUE_ELEMENT);
    for (std::vector<ast::object *>::const_iterator it = obj_list.begin(); 
            it != obj_list.end(); 
            ++it) {
        ast_symbol_value_element_list->append(*it, AST_SYMBOL_VALUE_ELEMENT);
    }

    // 
    symbol_value *ast_symbol_value = new symbol_value(ast_symbol_value_element_list);

    // 
    list *ast_symbol_value_list = new list(AST_SYMBOL_VALUE);
    ast_symbol_value_list->append(ast_symbol_value, AST_SYMBOL_VALUE);

    // 
    list_parameter_value *ast_list_param_value 
        = new list_parameter_value(ast_symbol_value_list);

    // 
    list_parameter *ast_list_parameter = new list_parameter(ast_list_param_value, "");

    // 
    std::string key_name = ast_list_parameter->glance(out_lyc_y_list, ACTOPT_NONE);
    int index = ast_table_index(&table_LIST_values, ast_list_parameter);
    if (index < 0) {
        fprintf(stderr, "cannot find defined LIST [%d] \n", index);
        exit(1);
    }
    else {
        // delete ast_list_parameter;
    }
    return index;   
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
    return ast_table_index(&table_OPT_values, elem);
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
    return ast_table_index(&table_STAR_values, elem);
}
// 
void ast_table_STAR_add(const char *key, star_parameter *elem) {
    table_add(&table_STAR_keys, key);
    ast_table_add(&table_STAR_values, elem);
}



//==============================================================================
// 
object::~object() {

}
list_node::~list_node() {
    delete _elem;
    fprintf(stderr, "~list_node(%p) \n", this);
}
list::~list() {
    while (_tail) {
        list_node *target = _tail;
        _tail = _tail->next();
        delete target;
    }
    fprintf(stderr, "~list(%p) \n", this);
}
symbol_definition::~symbol_definition() {
    delete _symbol_key;
    delete _symbol_value_list;
    fprintf(stderr, "~symbol_definition(%p) \n", this);
}
symbol_key::~symbol_key() {
    delete _key_attributes;
    fprintf(stderr, "~symbol_key(%p) \n", this);
}
key_attributes::~key_attributes() {
    fprintf(stderr, "~key_attributes(%p) \n", this);
}
symbol_value::~symbol_value() {
    delete _symbol_value_element_list;
    fprintf(stderr, "~symbol_value(%p) \n", this);
}
symbol_value_element::~symbol_value_element() {
    fprintf(stderr, "~symbol_value_element(%p) \n", this);
}
mcc_string::~mcc_string() {
    fprintf(stderr, "~mcc_string(%p) \n", this);
}
mcc_symbol::~mcc_symbol() {
    fprintf(stderr, "~mcc_symbol(%p) \n", this);
}
list_parameter::~list_parameter() {
    delete _list_parameter_value;
    delete _list_parameter_delim;
    fprintf(stderr, "~list_parameter(%p) \n", this);
}
option_parameter::~option_parameter() {
    delete _option_parameter_value;
    fprintf(stderr, "~option_parameter(%p) \n", this);
}
star_parameter::~star_parameter() {
    delete _star_parameter_value;
    fprintf(stderr, "~star_parameter(%p) \n", this);
}
list_parameter_value::~list_parameter_value() {
    delete _symbol_value_list;
    fprintf(stderr, "~list_parameter_value(%p) \n", this);
}
option_parameter_value::~option_parameter_value() {
    delete _symbol_value_list;
    fprintf(stderr, "~option_parameter_value(%p) \n", this);
}
star_parameter_value::~star_parameter_value() {
    delete _list_parameter;
    fprintf(stderr, "~star_parameter_value(%p) \n", this);
}
token_definition::~token_definition() {
    fprintf(stderr, "~token_definition(%p) \n", this);
}










//==============================================================================
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
            switch (this->elem_type()) {
                case AST_LIST:
                    // return list::compare                (this->ast_elem(), p2->ast_elem());
                    {
                        const list *elem = dynamic_cast<const list *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_SYMBOL_DEFINITION:
                    // return symbol_definition::compare   (this->p2->elem());
                    {
                        const symbol_definition *elem = dynamic_cast<const symbol_definition *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_SYMBOL_KEY:
                    // return symbol_key::compare          (p2->elem());
                    {
                        const symbol_key *elem = dynamic_cast<const symbol_key *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_KEY_ATTRIBUTES:
                    // return key_attributes::compare      (p2->elem());
                    {
                        const key_attributes *elem = dynamic_cast<const key_attributes *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_SYMBOL_VALUE:
                    // return symbol_value::compare        (p2->elem());
                    {
                        const symbol_value *elem = dynamic_cast<const symbol_value *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_SYMBOL_VALUE_ELEMENT:
                    // return symbol_value_element::compare(p2->elem());
                    {
                        const symbol_value_element *sv_elem = dynamic_cast<const symbol_value_element *>(this->ast_elem());
                        const symbol_value_element *sv_elem2 = dynamic_cast<const symbol_value_element *>(p2->ast_elem());
                        if (sv_elem->elem_type() != sv_elem2->elem_type()) {
                            return 1;
                        }

                        switch (sv_elem->elem_type()) {
                            case AST_MCC_STRING:
                                {
                                    const mcc_string *elem = dynamic_cast<const mcc_string *>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            case AST_MCC_SYMBOL:
                                {
                                    const mcc_symbol *elem = dynamic_cast<const mcc_symbol *>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            case AST_LIST_PARAMETER:
                                // return list_parameter::compare      (p2->elem());
                                {
                                    const list_parameter *elem = dynamic_cast<const list_parameter *>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            case AST_OPTION_PARAMETER:
                                // return option_parameter::compare    (p2->elem());
                                {
                                    const option_parameter *elem = dynamic_cast<const option_parameter *>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            case AST_STAR_PARAMETER:
                                // return star_parameter::compare      (p2->elem());
                                {
                                    const star_parameter *elem = dynamic_cast<const star_parameter *>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            case AST_TOKEN_DEFINITION:
                                // return token_definition::compare    (p2->elem());
                                {
                                    const token_definition *elem = dynamic_cast<const token_definition*>(this->ast_elem());
                                    return elem->compare(p2->ast_elem());
                                }
                            default:
                                fprintf(stderr, "list_node_cmp >> invalid elem type [%s] \n", ast_str(this->elem_type()));
                                return 1;
                        }
                        return sv_elem->compare(p2->ast_elem());
                    }
                case AST_LIST_PARAMETER_VALUE:
                    {
                        const list_parameter_value *elem = dynamic_cast<const list_parameter_value *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_OPTION_PARAMETER_VALUE:
                    {
                        const option_parameter_value *elem = dynamic_cast<const option_parameter_value *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_STAR_PARAMETER_VALUE:
                    {
                        const star_parameter_value *elem = dynamic_cast<const star_parameter_value *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }

                case AST_MCC_STRING:
                    {
                        const mcc_string *elem = dynamic_cast<const mcc_string *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_MCC_SYMBOL:
                    {
                        const mcc_symbol *elem = dynamic_cast<const mcc_symbol *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_LIST_PARAMETER:
                    // return list_parameter::compare      (p2->elem());
                    {
                        const list_parameter *elem = dynamic_cast<const list_parameter *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_OPTION_PARAMETER:
                    // return option_parameter::compare    (p2->elem());
                    {
                        const option_parameter *elem = dynamic_cast<const option_parameter *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_STAR_PARAMETER:
                    // return star_parameter::compare      (p2->elem());
                    {
                        const star_parameter *elem = dynamic_cast<const star_parameter *>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }
                case AST_TOKEN_DEFINITION:
                    // return token_definition::compare    (p2->elem());
                    {
                        const token_definition *elem = dynamic_cast<const token_definition*>(this->ast_elem());
                        return elem->compare(p2->ast_elem());
                    }

                default:
                    fprintf(stderr, "list_node_cmp >> invalid type [%s] \n", ast_str(this->elem_type()));
                    return 1;
            }
            // return this->ast_elem()->compare(p2->ast_elem());
            return 0;
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

                n1 = n1->next();
                n2 = n2->next();
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
        // else if (this->list_parameter_delim() != p2->list_parameter_delim()) {
        // !!!!! IMPORTANT !!!!!
        // error occurred because list_parameter_delim() returns a pointer of mcc_string
        //  but I misunderstood that the method returns the reference of it.
        //  This resulted a pointer-pointer comparison instead of mcc_string comparison
        //  and always failed because newly allocated class object's address can never be
        //  same with previously defined entity.
        else if (*this->list_parameter_delim() != *p2->list_parameter_delim()) {
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
