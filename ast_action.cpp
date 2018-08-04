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
        fprintf(out_lyc_ast_h_declaration, "class %s: public object {\n", symbol_name);
        fprintf(out_lyc_ast_h_declaration, "    %-31s %s;\n", "ast_type", "type");
        fprintf(out_lyc_ast_h_declaration, "    \n");
        fprintf(out_lyc_ast_h_declaration, "public: \n");
        fprintf(out_lyc_ast_h_declaration, "    // \n");
        fprintf(out_lyc_ast_h_declaration, "    void describe(FILE *out);\n");
        fprintf(out_lyc_ast_h_declaration, "    // \n");
        fprintf(out_lyc_ast_h_declaration, "    void action(FILE *out);\n");
        fprintf(out_lyc_ast_h_declaration, "};\n");
        fprintf(out_lyc_ast_h_declaration, "\n");
        fprintf(out_lyc_ast_h_declaration, "\n");
        fprintf(out_lyc_ast_h_declaration, "\n");

        // 
        fprintf(out_lyc_ast_c_templates, "// \n");
        fprintf(out_lyc_ast_c_templates, "void ast::%s::describe(FILE *out) {\n", symbol_name);
        fprintf(out_lyc_ast_c_templates, "    \n");
        fprintf(out_lyc_ast_c_templates, "}\n");
        fprintf(out_lyc_ast_c_templates, "// \n");
        fprintf(out_lyc_ast_c_templates, "void ast::%s::action(FILE *out) {\n", symbol_name);
        fprintf(out_lyc_ast_c_templates, "    \n");
        fprintf(out_lyc_ast_c_templates, "}\n");
        fprintf(out_lyc_ast_c_templates, "\n");
        fprintf(out_lyc_ast_c_templates, "\n");
        fprintf(out_lyc_ast_c_templates, "\n");

        // 
        symbols_add(symbol_name);

        // gather syntax list.
        {
            list *ast_list = ast_symbol_value_list;
            list_node *node;
            int elem_list_flag = 0;

            // fprintf(out_lyc, "    %c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
            for (node = ast_list->first(); node; node = node->next()) {
                symbol_value *ast_symbol_value 
                    = dynamic_cast<symbol_value *>(node->ast_elem());
                list *ast_elem_list = ast_symbol_value->ast_symbol_value_element_list();
                list_node *node2;

                // 
                fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
                for (node2 = ast_elem_list->first(); node2; node2 = node2->next()) {
                    symbol_value_element *ast_elem 
                        = dynamic_cast<symbol_value_element *>(node2->ast_elem());
                    // mcc_symbol *new_elem = nullptr;

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
                            ast_elem->glance(out, option);
                            ast_elem->action(out, option);
                            break;

                        default:
                            fprintf(stderr, "symbol_definition_action >> invalid type [%s] \n", 
                                    ast_str(ast_elem->elem_type()));
                            exit(1);
                    }
                }
                fprintf(out_lyc, "\n    {\n");
                if (islower(symbol_name[0])) {
                    fprintf(out_lyc, "        ast::%s *ret = new ast::%s;\n", symbol_name, symbol_name);
                    fprintf(out_lyc, "        $$ = ret;\n");
                }
                fprintf(out_lyc, "    }\n");
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
        // mcc_symbol *ret;
        
        // 
        switch (elem->elem_type()) {
            case AST_MCC_STRING:
                // ret = new mcc_symbol(elem->glance(out, option));
                // delete elem;
                // node->set_ast_elem(ret);
                // ret->action(out, option);
                elem->action(out, option);
                break;

            case AST_MCC_SYMBOL:
                elem->action(out, option);
                break;

            case AST_LIST_PARAMETER:
                // ret = new mcc_symbol(elem->glance(out, option));
                // delete elem;
                // node->set_ast_elem(ret);
                // ret->action(out, option);
                elem->action(out, option);
                break;

            case AST_OPTION_PARAMETER:
                // ret = new mcc_symbol(elem->glance(out, option));
                // delete elem;
                // node->set_ast_elem(ret);
                // ret->action(out, option);
                elem->action(out, option);
                break;

            case AST_STAR_PARAMETER:
                // ret = new mcc_symbol(elem->glance(out, option));
                // delete elem;
                // node->set_ast_elem(ret);
                // ret->action(out, option);
                elem->action(out, option);
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
    if (_value != "") {
        // IMPORTANT
        // C++ std::string does not ensure that entered C character string ends with NULL;
        //  you have to initialize all of C string buffer with 0.
        char key_name[256] = "";
        int index = string_tokens_value_index(_value.c_str());

        if (index < 0) {
            fprintf(stderr, "mcc_string_action >> cannot find token definition of [%s] \n", _value.c_str());
            exit(1);
        }

        // 
        sprintf(key_name, "TOKEN_%d", index);
        fprintf(out, "%s /* %s */ ", key_name, _value.c_str());
    }
}
// 
void mcc_symbol::action(FILE *out, act_opt option) {
    // 
    // fprintf(out, "%s /""* MCC_SYMBOL *""/ ", this->value().c_str());
    fprintf(out, "%s ", this->value().c_str());
}

// 
void list_parameter::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // std::string ret = this->ast_list_parameter_value()->glance(out_lyc_y_list, option);
        this->ast_list_parameter_value()->glance(out_lyc_y_list, option);
        int index = ast_table_LIST_index(this);
        if (index < 0) {
            fprintf(stderr, 
                    "list_parameter_action >> cannot find definition of LIST[%d] \n", 
                    index);
            exit(1);
        }
        // 
        // fprintf(out, "%s ", ret.c_str());
        fprintf(out, "LIST_%d ", index);
    }
}
// 
void option_parameter::action(FILE *out, act_opt option) {
    //
    if (out_lyc) {
        // std::string ret = this->ast_option_parameter_value()->glance(out_lyc_y_option, option);
        this->ast_option_parameter_value()->glance(out_lyc_y_option, option);
        int index = ast_table_OPT_index(this);
        if (index < 0) {
            fprintf(stderr, 
                    "option_parameter_action >> cannot find definition of OPTION[%d] \n", 
                    index);
            exit(1);
        }
        // 
        // fprintf(out, "%s ", ret.c_str());
        fprintf(out, "OPT_%d ", index);
    }
}
// 
void star_parameter::action(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        // std::string ret = this->ast_star_parameter_value()->glance(out_lyc_y_star, option);
        this->ast_star_parameter_value()->glance(out_lyc_y_star, option);
        int index = ast_table_STAR_index(this);
        if (index < 0) {
            fprintf(stderr, 
                    "star_parameter_action >> cannot find definition of STAR[%d] \n", 
                    index);
            exit(1);
        }
        // 
        // fprintf(out, "%s ", ret.c_str());
        fprintf(out, "STAR_%d ", index);
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

