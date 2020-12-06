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
void symbol_definition::action(FILE *out, act_opt option) {
    action_header();
    symbol_key *ast_symbol_key = this->ast_symbol_key();
    key_attributes *ast_key_attr = ast_symbol_key->ast_key_attributes();
    symbol_value_list *ast_symbol_value_list = this->ast_symbol_value_list();
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
        fprintf(out_lyc_ast_h_declaration, "    %s(): object(%s) {\n", symbol_name, buf);
        fprintf(out_lyc_ast_h_declaration, "        \n");
        fprintf(out_lyc_ast_h_declaration, "    }\n");
        fprintf(out_lyc_ast_h_declaration, "    ~%s() {\n", symbol_name);
        fprintf(out_lyc_ast_h_declaration, "        \n");
        fprintf(out_lyc_ast_h_declaration, "    }\n");
        fprintf(out_lyc_ast_h_declaration, "    \n");
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

        // 
        ast_symbol_value_list->set_symbol_name(symbol_name);
        ast_symbol_value_list->action(out, option);
    }
}
// 
void symbol_key::action(FILE *out, act_opt option) {
    action_header();
    if (out_lyc) {
        // 
    }
}
// 
void key_attributes::action(FILE *out, act_opt option) {
    action_header();
    // 
}
// 
void symbol_value::action(FILE *out, act_opt option) {
    action_header();
    symbol_value_element_list *ast_symbol_value_element_list 
        = this->ast_symbol_value_element_list();
    for (auto node = ast_symbol_value_element_list->first(); 
            node != ast_symbol_value_element_list->end();
            ++node) {
        symbol_value_element *elem = dynamic_cast<symbol_value_element *>(*node);
        elem->action(out, option);
    }
}
void symbol_value_element::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        throw std::string("INVALID CASE");
    }
}
// 
void mcc_string::action(FILE *out, act_opt option) {
    action_header();
    if (_value != "") {
        // IMPORTANT
        // C++ std::string does not ensure that entered C character string ends with NULL;
        //  you have to initialize all of C string buffer with 0.
        char key_name[256] = "";
        char sec_name[256] = "";
        int index = string_tokens_value_index(_value.c_str());
        if (index < 0) {
fprintf(stderr, "mcc_string_action >> cannot find token [%s] \n", _value.c_str());
            exit(1);
        }

        // 
        sprintf(key_name, "%s", ast::string_tokens[index].first.c_str());
        sprintf(sec_name, "%s", ast::string_tokens[index].second.c_str());
        //fprintf(out, "%s ", key_name);
        fprintf(out, "%s /""* %s *""/ ", key_name, sec_name);
    }
}
// 
void mcc_symbol::action(FILE *out, act_opt option) {
    action_header();
    // 
    fprintf(out, "%s ", this->value().c_str());
}

// 
void list_parameter::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        // this->ast_list_parameter_value()->glance(out_lyc_y_list, option);
        std::string ret = this->glance(out_lyc_y_list, option);
        int index = ast_table_LIST_index(this);
        if (index < 0) {
fprintf(stderr, "list_parameter_action >> cannot find definition of LIST[%d] \n", index);
            exit(1);
        }

        // 
        fprintf(out, "LIST_%d ", index);
    }
}
// 
void option_parameter::action(FILE *out, act_opt option) {
    action_header();
    //
    if (out_lyc) {
        // this->ast_option_parameter_value()->glance(out_lyc_y_option, option);
        std::string ret = this->glance(out_lyc_y_option, option);
        int index = ast_table_OPT_index(this);
        if (index < 0) {
            using ast::ast_table_OPT;
fprintf(stderr, "option_parameter_action >> cannot find definition of OPTION[%d] \n", index);
fprintf(stderr, "%p \n", this);

            // 
            for (auto it = ast::ast_table_LIST.begin(); it != ast::ast_table_LIST.end(); ++it) {
                std::string key = it->first;
                auto value = it->second;

                // 
                fprintf(stderr, "[%s/%p] \n", key.c_str(), value);
            }
            // 
            for (auto it = ast::ast_table_OPT.begin(); it != ast::ast_table_OPT.end(); ++it) {
                std::string key = it->first;
                option_parameter *value = it->second;

                // 
                fprintf(stderr, "[%s/%p] \n", key.c_str(), value);
            }
            // 
            for (auto it = ast::ast_table_STAR.begin(); it != ast::ast_table_STAR.end(); ++it) {
                std::string key = it->first;
                auto value = it->second;

                // 
                fprintf(stderr, "[%s/%p] \n", key.c_str(), value);
            }


            // 
            exit(1);
        }

        // 
        //////// printf("OPT_%d fetched successfully. \n", index);
        fprintf(out, "OPT_%d ", index);
    }
}
// 
void star_parameter::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        // this->ast_star_parameter_value()->glance(out_lyc_y_star, option);
        std::string ret = this->glance(out_lyc_y_star, option);
        int index = ast_table_STAR_index(this);
        if (index < 0) {
fprintf(stderr, "star_parameter_action >> cannot find definition of STAR[%d] \n", index);
            exit(1);
        }
        
        // 
        fprintf(out, "STAR_%d ", index);
    }
}
// 
void list_parameter_value::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        this->ast_symbol_value_list()->action(out, option);
    }
}
// 
void option_parameter_value::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        this->ast_symbol_value_list()->action(out, option);
    }
}
// 
void star_parameter_value::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        this->ast_list_parameter()->action(out, option);
    }
}
// 
void token_definition::action(FILE *out, act_opt option) {
    action_header();
    // 
    if (out_lyc) {
        // 
        if (tokens_index(this->token_key().c_str()) < 0) {
            tokens_add(this->token_key().c_str());
        }
        
        // 
        fprintf(out_lyc, "%s ", this->token_key().c_str());
    }
}










//==============================================================================
// 
void symbol_definition_list::action(FILE *out, act_opt option) {
    action_header();
    // static int depth = 0;
    auto node = this->first(); // list_node *node;

    // 
    if (out_lyc) {
        for (node = this->first(); node != this->end(); ++node) {
            (*node)->action(out, option);
            // printf("=== [%s] \n", (*node)->ast_symbol_key()->symbol_name().c_str());
        }
    }

    // 
}
// 
void symbol_value_list::action(FILE *out, act_opt option) {
    action_header();
    // gather syntax list.
    symbol_value_list *ast_list = this;
    auto node = ast_list->first();
    int elem_list_flag = 0;

    // 
    for (node = ast_list->first(); node != ast_list->end(); ++node) {
        symbol_value *ast_symbol_value = dynamic_cast<symbol_value *>(*node);
        symbol_value_element_list *ast_elem_list 
            = ast_symbol_value->ast_symbol_value_element_list();
        auto node2 = ast_elem_list->first();

        // 
        fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
        for (node2 = ast_elem_list->first(); 
                node2 != ast_elem_list->end(); 
                ++node2) {
            symbol_value_element *ast_elem = dynamic_cast<symbol_value_element *>(*node2);

            if (ast_elem == nullptr) {
                fprintf(out_lyc, "/""* empty *""/ ");
                continue;
            }

            // 
            ast_elem->glance(out, option);
            ast_elem->action(out, option);
        }
        fprintf(out_lyc, "\n    {\n");
        if (islower(symbol_name()[0])) {
            fprintf(out_lyc, "        ast::%s *ret = new ast::%s;\n", 
                    symbol_name().c_str(), symbol_name().c_str());
            fprintf(out_lyc, "        $$ = ret;\n");
        }
        fprintf(out_lyc, "    }\n");
    }

    // 
    fprintf(out_lyc, "    ;\n\n");
}
// 
void symbol_value_element_list::action(FILE *out, act_opt option) {
    action_header();

    auto node = this->first();

    if (out_lyc) {
        for (node = this->first(); node != this->end(); ++node) {
            (*node)->action(out, option);
        }
    }
}
















