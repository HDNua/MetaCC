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
const int MAX_TOKEN_LEN = 2048;



//==============================================================================
extern FILE *out_jj;
extern FILE *out_java;

//------------------------------------------------------------------------------
extern FILE *out_lyc;
extern FILE *out_lyc_y;
extern FILE *out_lyc_y_token;
extern FILE *out_lyc_y_list;
extern FILE *out_lyc_y_option;
extern FILE *out_lyc_y_star;
extern FILE *out_lyc_l;
extern FILE *out_lyc_l_tokendef;
extern FILE *out_lyc_ast_h;
extern FILE *out_lyc_ast_h_typedef;
extern FILE *out_lyc_ast_h_declaration;
extern FILE *out_lyc_ast_c;
extern FILE *out_lyc_ast_c_templates;

//------------------------------------------------------------------------------
extern FILE *out_lycpp;



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

