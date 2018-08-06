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



//------------------------------------------------------------------------------
// 
//////// extern struct table string_token_keys;
//////// extern struct table string_token_values;
//////// 
//////// extern struct table tokens;
//////// 
//////// extern struct table table_LIST_keys;
//////// extern struct table table_OPT_keys;
//////// extern struct table table_STAR_keys;
//////// extern struct ast_table table_LIST_values;
//////// extern struct ast_table table_OPT_values;
//////// extern struct ast_table table_STAR_values;



//==============================================================================
// 
template <class Type>
std::string list<Type>::glance(FILE *out, act_opt option) {
    // static int depth = 0;
    auto node = this->first(); // list_node *node;

    // 
    if (out_lyc) {
        /*
        if (this->elem_type() == AST_SYMBOL_VALUE) {
            ++depth;
            for (node=this->first(); node; node=node->next()) {
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
                node->glance(out, option);
            }
        }
        */

        // 
        for (node = this->first(); node != this->end(); ++node) {
            (*node)->glance(out, option);
        }
    }

    // 
    return std::string("");
}
/*
std::string list_node::glance(FILE *out, act_opt option) {
    if (this->type() == AST_LIST_NODE) {
        return this->ast_elem()->glance(out, option);
    }
    else {
        fprintf(stderr, "invalid node \n");
        exit(1);
    }
}
*/



// 
std::string symbol_definition::glance(FILE *out, act_opt option) {
    symbol_key *ast_symbol_key = this->ast_symbol_key();
    key_attributes *ast_key_attr = ast_symbol_key->ast_key_attributes();
    symbol_value_list *ast_symbol_value_list = this->ast_symbol_value_list();
    // const char *symbol_name = ast_symbol_key->symbol_name().c_str();

    // 
    if (ast_key_attr) {
        // 
    }

    //======================================================================================
    // yields Lex & Yacc files.
    // > parser.l : lexical file.
    // > parser.y : yacc syntax file.
    // > ast.h    : abstract syntax tree interface.
    // > ast.c    : abstract syntax tree implementation.
    if (out_lyc)
    {
        // gather syntax list.
        return ast_symbol_value_list->glance(out, option);

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
        // IMPORTANT
        // C++ std::string does not ensure that entered C character string ends with NULL;
        //  you have to initialize all of C string buffer with 0.
        char key_name[256] = "";
        int index = string_tokens_value_index(_value.c_str());

        // 
        //// sprintf(key_name, "TOKEN_%d", index);
        if (index < 0) {
            index = string_tokens.size(); //_keys.count;
            sprintf(key_name, "TOKEN_%d", index);
            string_tokens_add(key_name, _value.c_str());
            fprintf(out_lyc_l_tokendef, "\"%s\" return %s;\n", _value.c_str(), key_name);
        }
        else {
            // sprintf(key_name, "%s", string_token_keys.list[index]);
            sprintf(key_name, "%s", string_tokens[index].first.c_str());
        }

        // 
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
        char key_name[256] = "";

        list_parameter_value *ast_list_parameter_value = this->ast_list_parameter_value();
        symbol_value_list *ast_symbol_value_list 
            = ast_list_parameter_value->ast_symbol_value_list();
        // mcc_symbol *new_elem = nullptr;

        // std::vector< std::vector<std::string> > symbol_list_list;
        std::vector< std::vector<ast::object *> > object_list_list;
        for (auto node1 = ast_symbol_value_list->first(); 
                node1 != ast_symbol_value_list->end(); 
                ++node1) {
            symbol_value *elem1 = dynamic_cast<symbol_value *>(*node1);
            std::string symbol1 = elem1->glance(out, option);

            // 
            symbol_value_element_list *ast_elem_list 
                = elem1->ast_symbol_value_element_list();
            // std::vector< std::string> symbol_list;
            std::vector<ast::object *> object_list;
            for (auto node2 = ast_elem_list->first(); 
                    node2 != ast_elem_list->end(); 
                    ++node2) {
                symbol_value_element *elem2 
                    = dynamic_cast<symbol_value_element *>(*node2);
                std::string symbol2 = elem2->glance(out, option);

                /*
                switch (elem2->elem_type()) {
                    case AST_MCC_STRING:
                    case AST_MCC_SYMBOL:
                    case AST_TOKEN_DEFINITION:
                        break;
                    case AST_LIST_PARAMETER:
                    case AST_OPTION_PARAMETER:
                    case AST_STAR_PARAMETER:
                        break;
                    default:
fprintf(stderr, "list_parameter >> invalid type [%s] \n", ast_str(node2->elem_type()));
                        // exit(1);
                        break;
                }
                */

                // 
                object_list.push_back(elem2);
            }

            // 
            object_list_list.push_back(object_list);
        }

        // 
        int index = ast_table_LIST_index(this);
        sprintf(key_name, "LIST_%d", index);
        if (index < 0) {
            index = ast_table_LIST.size(); // .count;
            sprintf(key_name, "LIST_%d", index);
            ast_table_LIST_add(key_name, this);

            // 
            bool first = true;
            fprintf(out_lyc_y_list, "LIST_%d\n", index);
            for (std::vector< std::vector<ast::object *> >::iterator it1 
                    = object_list_list.begin(); 
                    it1 != object_list_list.end();
                    ++it1) {
                std::vector<ast::object *> &objects = *it1;
                fprintf(out_lyc_y_list, "    %c ", (first) ? (first=false, ':') : ('|'));

                // 
                for (std::vector<ast::object *>::iterator it2 = objects.begin(); 
                        it2 != objects.end(); 
                        ++it2) {
                    //
                    std::string symbol = (*it2)->glance(stdout, ACTOPT_NONE);
                    fprintf(out_lyc_y_list, "%s ", symbol.c_str());
                }

                // 
                fprintf(out_lyc_y_list, "\n");
                fprintf(out_lyc_y_list, "    {\n");
                fprintf(out_lyc_y_list, "        ast::list<ast::object *> ");
                fprintf(out_lyc_y_list, "*list = new ast::list<ast::object *>();\n");
                fprintf(out_lyc_y_list, "        // list->append($1);\n");
                fprintf(out_lyc_y_list, "        $$ = list;\n");
                fprintf(out_lyc_y_list, "    }\n");

                // 
                fprintf(out_lyc_y_list, "    | LIST_%d ", index);
                std::string delim = list_parameter_delim()->glance(out, option);
                fprintf(out_lyc_y_list, "%s ", delim.c_str());

                // 
                for (std::vector<ast::object *>::iterator it2 = objects.begin(); 
                        it2 != objects.end(); 
                        ++it2) {
                    //
                    std::string symbol = (*it2)->glance(stdout, ACTOPT_NONE);
                    fprintf(out_lyc_y_list, "%s ", symbol.c_str());
                }

                // 
                fprintf(out_lyc_y_list, "\n");
                fprintf(out_lyc_y_list, "    {\n");
                fprintf(out_lyc_y_list, "        // $1->append($2);\n");
                fprintf(out_lyc_y_list, "        $$ = $1;\n");
                fprintf(out_lyc_y_list, "    }\n");
            }
            fprintf(out_lyc_y_list, "    ;\n");
        }

        return std::string(key_name);
    }
    return "null";
}
// 
std::string option_parameter::glance(FILE *out, act_opt option) {
    //
    if (out_lyc) {
        char key_name[256] = "";
        option_parameter_value *ast_option_parameter_value 
            = this->ast_option_parameter_value();
        symbol_value_list *ast_symbol_value_list 
            = ast_option_parameter_value->ast_symbol_value_list();

        // 
        std::vector< std::vector<ast::object *> > object_list_list;
        for (auto node1 = ast_symbol_value_list->first(); 
                node1 != ast_symbol_value_list->end(); 
                ++node1) {
            symbol_value *elem1 = dynamic_cast<symbol_value *>(*node1);
            std::string symbol1 = elem1->glance(out, option);

            // 
            symbol_value_element_list *ast_elem_list 
                = elem1->ast_symbol_value_element_list();
            std::vector<ast::object *> object_list;
            for (auto node2 = ast_elem_list->first(); 
                    node2 != ast_elem_list->end(); 
                    ++node2) {
                symbol_value_element *elem2 
                    = dynamic_cast<symbol_value_element *>(*node2);
                std::string symbol2 = elem2->glance(out, option);

                /*
                switch (elem2->elem_type()) {
                    case AST_MCC_STRING:
                    case AST_MCC_SYMBOL:
                    case AST_TOKEN_DEFINITION:
                        break;
                    case AST_LIST_PARAMETER:
                    case AST_OPTION_PARAMETER:
                    case AST_STAR_PARAMETER:
                        break;
                    default:
fprintf(stderr, "option_parameter >> invalid type [%s] \n", ast_str(node2->elem_type()));
                        // exit(1);
                        break;
                }
                */

                // 
                object_list.push_back(elem2);
            }

            // 
            object_list_list.push_back(object_list);
        }
        // 
        int index = ast_table_OPT_index(this);
        sprintf(key_name, "OPT_%d", index);
        if (index < 0) {
            index = ast_table_OPT.size(); // count;
            sprintf(key_name, "OPT_%d", index);
            ast_table_OPT_add(key_name, this);

            // 
            fprintf(out_lyc_y_option, "OPT_%d\n", index);
            // fprintf(out_lyc_y_option, "    %c ", (first) ? (first=false, ':') : ('|'));
            fprintf(out_lyc_y_option, "    : /""* empty *""/\n");
            fprintf(out_lyc_y_option, "    {\n");
            fprintf(out_lyc_y_option, "        $$ = NULL;\n");
            fprintf(out_lyc_y_option, "    }\n");
            for (std::vector< std::vector<ast::object *> >::iterator it1 
                    = object_list_list.begin(); 
                    it1 != object_list_list.end();
                    ++it1) {
                std::vector<ast::object *> &objects = *it1;
                fprintf(out_lyc_y_option, "    | ");
                for (std::vector<ast::object *>::iterator it2 = objects.begin(); 
                        it2 != objects.end(); 
                        ++it2) {
                    std::string symbol = (*it2)->glance(stdout, ACTOPT_NONE);
                    fprintf(out_lyc_y_option, "%s ", symbol.c_str());

                    // 
                    switch (symbol[0]) {
                        case 'T': // TOKEN in string_tokens
                            {
                                int token_index = string_tokens_value_index(symbol.c_str());
                                fprintf(out_lyc_y_option, "/""* %s *""/ ", 
                                        string_tokens[token_index].second.c_str());
                            }
                            break;
                        default:
                            break;
                    }
                }
                fprintf(out_lyc_y_option, "\n");
                fprintf(out_lyc_y_option, "    {\n");
                fprintf(out_lyc_y_option, "        ast::list<ast::object *> *list \n");
                fprintf(out_lyc_y_option, "= new ast::list<ast::object *>();\n");
                fprintf(out_lyc_y_option, "        // list->append($1);\n");
                fprintf(out_lyc_y_option, "        $$ = list;\n");
                fprintf(out_lyc_y_option, "    }\n");
            }
            fprintf(out_lyc_y_option, "    ;\n");
        }

        return std::string(key_name);
    }
    return "null";
}
// 
std::string star_parameter::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        char key_name[256] = "";
        star_parameter_value *ast_star_parameter_value = this->ast_star_parameter_value();
        list_parameter *ast_list_parameter = ast_star_parameter_value->ast_list_parameter();
        list_parameter_value *ast_list_parameter_value 
            = ast_list_parameter->ast_list_parameter_value();
        symbol_value_list *ast_symbol_value_list 
            = ast_list_parameter_value->ast_symbol_value_list();

        // 
        std::vector< std::vector<ast::object *> > object_list_list;
        // for (list_node *node1=ast_symbol_value_list->first(); node1; node1=node1->next()) {
        for (auto node1 = ast_symbol_value_list->first(); 
                node1 != ast_symbol_value_list->end(); 
                ++node1) {
            symbol_value *elem1 = dynamic_cast<symbol_value *>(*node1);
            std::string symbol1 = elem1->glance(out, option);

            // 
            symbol_value_element_list *ast_elem_list 
                = elem1->ast_symbol_value_element_list();
            std::vector<ast::object *> object_list;
            // for (list_node *node2=ast_elem_list->first(); node2; node2=node2->next()) {
            for (auto node2 = ast_elem_list->first(); 
                    node2 != ast_elem_list->end(); 
                    ++node2) {
                symbol_value_element *elem2 
                    = dynamic_cast<symbol_value_element *>(*node2);
                std::string symbol2 = elem2->glance(out, option);

                /*
                switch (elem2->elem_type()) {
                    case AST_MCC_STRING:
                    case AST_MCC_SYMBOL:
                    case AST_TOKEN_DEFINITION:
                        break;
                    case AST_LIST_PARAMETER:
                    case AST_OPTION_PARAMETER:
                    case AST_STAR_PARAMETER:
                        break;
                    default:
    fprintf(stderr, "star_parameter >> invalid type [%s] \n", ast_str(node2->elem_type()));
                        // exit(1);
                        break;
                }
                */

                // 
                object_list.push_back(elem2);
            }

            // 
            object_list_list.push_back(object_list);
        }
        // 
        int index = ast_table_STAR_index(this);
        sprintf(key_name, "STAR_%d", index);
        if (index < 0) {
            index = ast_table_STAR.size();
            sprintf(key_name, "STAR_%d", index);
            ast_table_STAR_add(key_name, this);

            // 
            // bool first = true;
            fprintf(out_lyc_y_star, "STAR_%d\n", index);
            fprintf(out_lyc_y_star, "    : /""* empty *""/\n");
            fprintf(out_lyc_y_star, "    {\n");
            fprintf(out_lyc_y_star, "        $$ = NULL;\n");
            fprintf(out_lyc_y_star, "    }\n");
            for (std::vector< std::vector<ast::object *> >::iterator it1 
                    = object_list_list.begin(); 
                    it1 != object_list_list.end();
                    ++it1) {
                std::vector<ast::object *> &objects = *it1;
                fprintf(out_lyc_y_star, "    | LIST_%d \n", ast_table_LIST_index(objects));
                fprintf(out_lyc_y_star, "    {\n");
                fprintf(out_lyc_y_star, "        $$ = $1;\n");
                fprintf(out_lyc_y_star, "    }\n");
                // fprintf(out_lyc_y_star, "\n");
            }
            fprintf(out_lyc_y_star, "    ;\n");
        }

        return std::string(key_name);
    }
    return "null";
}
// 
std::string list_parameter_value::glance(FILE *out, act_opt option) {
    if (out_lyc) {
        return this->ast_symbol_value_list()->glance(out, option);
    }
    return "null";
}
// 
std::string option_parameter_value::glance(FILE *out, act_opt option) {
    if (out_lyc) {
        return this->ast_symbol_value_list()->glance(out, option);
    }
    return "null";
}
// 
std::string star_parameter_value::glance(FILE *out, act_opt option) {
    if (out_lyc) {
        return this->ast_list_parameter()->glance(out, option);
    }
    return "null";
}
// 
std::string token_definition::glance(FILE *out, act_opt option) {
    // 
    if (out_lyc) {
        if (tokens_index(this->token_key().c_str()) < 0) {
            tokens_add(this->token_key().c_str());
        }
        return this->token_key();
    }
    return "null";
}










// 
std::string symbol_value_list::glance(FILE *out, act_opt option) {
    symbol_value_list *ast_list = this;
    auto node = ast_list->first();
    int elem_list_flag = 0;

    // fprintf(out_lyc, "    %c", (value_list_flag ? '|' : (value_list_flag=1, ':')));
    for (node = ast_list->first(); node != ast_list->end(); ++node) {
        symbol_value *ast_symbol_value = dynamic_cast<symbol_value *>(*node);
        symbol_value_element_list *ast_elem_list 
            = ast_symbol_value->ast_symbol_value_element_list();
        // list_node *node2;
        auto node2 = ast_elem_list->first();

        // 
        fprintf(out_lyc, "    %c ", (elem_list_flag ? '|' : (elem_list_flag=1, ':')));
        for (node2 = ast_elem_list->first(); node2 != ast_elem_list->end(); ++node2) {
            symbol_value_element *ast_elem = dynamic_cast<symbol_value_element *>(*node2);
            if (ast_elem != nullptr) {
                mcc_symbol *new_elem = new mcc_symbol(ast_elem->glance(out, option));
                // delete ast_elem;
                //////// node->set_ast_elem(new_elem);
                *node2 = new_elem;
                new_elem->action(out, option);
            }
        }
        // fprintf(out_lyc, "\n    {\n        $$ = 0;\n    }\n");
    }
    return std::string("symbol_value_list");
}
