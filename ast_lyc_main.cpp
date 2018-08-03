#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"

#include <unistd.h>
#include <sys/stat.h>



// 
int ast::lyc::main(int argc, const char *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;
    // extern struct table symbols;

    // need to update after traverse.
    const char *start_symbol = "expression"; // symbols.list[0];

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "compilation has failed. \n");
    }

    // 
        extern class ast::list *symbol_definition_list;
        FILE *out;

        // 
        {
            out = out_lyc;
            fprintf(out, "\n");
        }
        // 
        {
            out = out_lyc_y_union;

            // 
            fprintf(out, "%%union {\n");
            fprintf(out, "    char token_str[MAX_TOKEN_LEN];\n");
            fprintf(out, "    struct ast_list *ast_list;\n");
            fprintf(out, "    \n");
        }
        // 
        {
            /*
            char fmt[ast::MAX_TOKEN_LEN] = "";
            extern struct table tokens;
            out = out_lyc_y_type;

            // 
            for (int i=0, len=tokens.count; i < len; ++i) {
                sprintf(fmt, "");
                fprintf(out, "%%type <ast_%s> \n");
            }
            fprintf(out, "\n");
            fprintf(out, "\n");
            */
        }
        // 
        {
            out = out_lyc_y_token;
            fprintf(out, "\n");
        }
        // 
        {
            out = out_lyc_l;
            fprintf(out, "%%{\n");
            fprintf(out, "#define MAX_TOKEN_LEN 2048\n");
            fprintf(out, "\n");
            fprintf(out, "#include <stdio.h>\n");
            fprintf(out, "#include <stdlib.h>\n");
            fprintf(out, "#include <string.h>\n");
            fprintf(out, "#include \"y.tab.h\"\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "#ifdef YYDEBUG\n");
            fprintf(out, "extern int yydebug;\n");
            fprintf(out, "#endif\n");
            fprintf(out, "\n");
            fprintf(out, "extern int line_count;\n");
            fprintf(out, "\n");
            fprintf(out, "int\n");
            fprintf(out, "yywrap(void)\n");
            fprintf(out, "{\n");
            fprintf(out, "    return 1;\n");
            fprintf(out, "}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "char *dst;\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "%%}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");

            // 
            paste_s2f_slice(out, LYC_L_INIT_AFTER, HEAD_IGNORE_COUNT);
        }
        // 
        {
            out = out_lyc_ast_h;
            fprintf(out, "#ifndef __HANDY_VAST_H__\n");
            fprintf(out, "#define __HANDY_VAST_H__\n");
            fprintf(out, "\n");
            fprintf(out, "#include <stdio.h>\n");
            fprintf(out, "#include <string.h>\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
        }
        // 
        {
            out = out_lyc_ast_c;
            fprintf(out, "#include <stdio.h>\n");
            fprintf(out, "#include <stdlib.h>\n");
            fprintf(out, "#include \"parser_ast.h\"\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "//==============================================================================\n");
            fprintf(out, "// \n");
            fprintf(out, "static struct ast_list_node *ast_list_node_new(void *elem, ast_type type) {\n");
            fprintf(out, "    struct ast_list_node *ret = (struct ast_list_node *)malloc(sizeof(struct ast_list_node));\n");
            fprintf(out, "    ret->type = AST_LIST_NODE;\n");
            fprintf(out, "    ret->elem_type = type;\n");
            fprintf(out, "    ret->elem = elem;\n");
            fprintf(out, "    ret->next = NULL;\n");
            fprintf(out, "    return ret;\n");
            fprintf(out, "}\n");
            fprintf(out, "// \n");
            fprintf(out, "struct ast_list *ast_list_new(ast_type type) {\n");
            fprintf(out, "    struct ast_list *ret = (struct ast_list *)malloc(sizeof(struct ast_list));\n");
            fprintf(out, "    ret->type = AST_LIST;\n");
            fprintf(out, "    ret->elem_type = type;\n");
            fprintf(out, "    ret->tail = &ret->head;\n");
            fprintf(out, "    ret->count = 0;\n");
            fprintf(out, "    return ret;\n");
            fprintf(out, "};\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_append(struct ast_list *self, void *elem, ast_type type) {\n");
            fprintf(out, "    struct ast_list_node *node = ast_list_node_new(elem, type);\n");
            fprintf(out, "    self->tail->next = node;\n");
            fprintf(out, "    self->tail = node;\n");
            fprintf(out, "    self->count += 1;\n");
            fprintf(out, "}\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_iterate(struct ast_list *self) {\n");
            fprintf(out, "    struct ast_list_node *node;\n");
            fprintf(out, "    for (node=self->head.next; node; node=node->next) {\n");
            fprintf(out, "        ast_list_node_describe(node);\n");
            fprintf(out, "    }\n");
            fprintf(out, "}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "// \n");
            fprintf(out, "static int description_depth = 0;\n");
            fprintf(out, "static int describe_begin() {\n");
            fprintf(out, "    return ++description_depth;\n");
            fprintf(out, "}\n");
            fprintf(out, "static int describe_end() {\n");
            fprintf(out, "    return --description_depth;\n");
            fprintf(out, "}\n");
            fprintf(out, "static void indent_depth(const char *s) {\n");
            fprintf(out, "    int i;\n");
            fprintf(out, "    for (i=0; i<description_depth; ++i) {\n");
            fprintf(out, "        printf(\"%%s\", s);\n");
            fprintf(out, "    }\n");
            fprintf(out, "}\n");
            fprintf(out, "static void tab_depth() {\n");
            fprintf(out, "    indent_depth(\"    \");\n");
            fprintf(out, "}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_traverse(struct ast_list *list) {\n");
            fprintf(out, "    \n");
            fprintf(out, "}\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_node_describe(struct ast_list_node *node) {\n");
            fprintf(out, "    \n");
            fprintf(out, "}\n");
            fprintf(out, "void ast_list_node_action(struct ast_list_node *node) {\n");
            fprintf(out, "    \n");
            fprintf(out, "}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
        }

        // 
        symbol_definition_list->action(out_lyc, ast::ACTOPT_NONE);

        // 
        {
            out = out_lyc;

            // 
            fclose(out_lyc_y_list);
            out_lyc_y_list = NULL;
            paste_s2f(out, LYC_Y_LIST);

            fclose(out_lyc_y_option);
            out_lyc_y_option = NULL;
            paste_s2f(out, LYC_Y_OPT);

            fclose(out_lyc_y_star);
            out_lyc_y_star = NULL;
            paste_s2f(out, LYC_Y_STAR);

            // 
            fclose(out_lyc);
            out_lyc = NULL;
        }
        // 
        {
            char fmt[ast::MAX_TOKEN_LEN] = "";
            extern struct table symbols;
            out = out_lyc_y_union;

            for (int i=0, len=symbols.count; i<len; ++i) {
                const char *symbol_name = symbols.list[i];

                // 
                sprintf(fmt, "    struct ast_%%-%ds *ast_%%s;\n", ::longest_symbol_length);
                fprintf(out_lyc_y_union, fmt, symbol_name, symbol_name);
            }

            // 
            fprintf(out, "}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");

            // 
            fprintf(stdout, "longest symbol length: %d\n", ::longest_symbol_length);

            // 
            {
                // 
                paste_s2f_slice(out_lyc_y_union, LYC_Y_UNION_AFTER, HEAD_IGNORE_COUNT);
            }
            fclose(out_lyc_y_union);
            out_lyc_y_union = NULL;
        }
        // 
        {
            char fmt[ast::MAX_TOKEN_LEN] = "";
            char type_left[ast::MAX_TOKEN_LEN] = "";
            extern struct table symbols;
            extern struct table table_LIST_keys;
            extern struct table table_OPT_keys;
            extern struct table table_STAR_keys;
            extern struct table string_token_keys;
            out = out_lyc_y_type;

            // 
            for (int i=0, len=symbols.count; i < len; ++i) {
                const char *symbol_name = symbols.list[i];

                // 
                sprintf(fmt, "%%%%type %%-%ds %%s\n", ::longest_symbol_length+8);
                sprintf(type_left, "<ast_%-s>", symbol_name);
                fprintf(out, fmt, type_left, symbol_name);
            }

            // 
            for (int i=0, len=table_LIST_keys.count; i<len; ++i) {
                fprintf(out, "%%type <ast_list> %s\n", table_LIST_keys.list[i]);
            }
            for (int i=0, len=table_OPT_keys.count; i<len; ++i) {
                fprintf(out, "%%type <ast_list> %s\n", table_OPT_keys.list[i]);
            }
            for (int i=0, len=table_STAR_keys.count; i<len; ++i) {
                fprintf(out, "%%type <ast_list> %s\n", table_STAR_keys.list[i]);
            }
            for (int i=0, len=string_token_keys.count; i<len; ++i) {
                fprintf(out, "%%type <token_str> %s\n", string_token_keys.list[i]);
            }

            // fprintf(out, "\n");
            // fprintf(out, "\n");
            // fprintf(out, "\n");

            // 
            //// fclose(out_lyc_y_type);
            //// out_lyc_y_type = NULL;
        }
        // 
        {
            int i, len;
            extern struct table tokens;
            extern struct table string_token_keys;
            extern struct table string_token_values;
            out = out_lyc_y_token;

            // define string tokens list.
            for (i=0, len=string_token_keys.count; i < len; ++i) {
                fprintf(out, "%%token TOKEN_%-5d /* %s */\n", i, string_token_values.list[i]);
            }

            // define extended tokens list.
            for (i=0, len=tokens.count; i < len; ++i) {
                fprintf(out, "%%token %-12s /* %s */\n", tokens.list[i], tokens.list[i]);
                fprintf(out_lyc_y_type, "%%type <token_str> %s\n", tokens.list[i]);
            }

            //
            {
                paste_s2f_slice(out_lyc_l_tokendef, LYC_L_TOKENDEF_AFTER, HEAD_IGNORE_COUNT);

                // 
                paste_s2f_slice(out_lyc_y_token, LYC_Y_TOKEN_AFTER, HEAD_IGNORE_COUNT);
                paste_s2f_slice(out_lyc_y_type, LYC_Y_TYPE_AFTER, HEAD_IGNORE_COUNT);

                // 
            }
            fclose(out_lyc_l_tokendef);
            fclose(out_lyc_y_token);
            fclose(out_lyc_y_type);
            out_lyc_l_tokendef = NULL;
            out_lyc_y_token = NULL;
            out_lyc_y_type = NULL;
        }
        // 
        {
            out = out_lyc_l;
            fprintf(out, "%%%%\n");
            fprintf(out, "\n");
            fprintf(out, "\n");

            // 
            paste_s2f_slice(out, LYC_L_PERCENTS_AFTER, HEAD_IGNORE_COUNT);

            // 
            paste_s2f(out, LYC_L_TOKENDEF);

            // 
            fclose(out_lyc_l);
            out_lyc_l = NULL;
        }
        // 
        {
            out = out_lyc_ast_h;

            // type definitions.
            fprintf(out, "typedef enum ast_type {\n");
            fprintf(out, "    AST_UNTYPED,\n");
            fprintf(out, "    AST_LIST,\n");
            fprintf(out, "    AST_LIST_NODE,\n");

            fclose(out_lyc_ast_h_typedef);
            paste_s2f(out, LYC_AST_H_TYPEDEF);

            fprintf(out, "} ast_type;\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            
            // common list & node definitions.
            fprintf(out, "// \n");
            fprintf(out, "struct ast_list_node {\n");
            fprintf(out, "    ast_type                      type;\n");
            fprintf(out, "    ast_type                      elem_type;\n");
            fprintf(out, "    void                          *elem;\n");
            fprintf(out, "    struct ast_list_node          *next;\n");
            fprintf(out, "};\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_node_describe(struct ast_list_node *node);\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_node_action(struct ast_list_node *node);\n");
            fprintf(out, "// \n");
            fprintf(out, "struct ast_list {\n");
            fprintf(out, "    ast_type                      type;\n");
            fprintf(out, "    ast_type                      elem_type;\n");
            fprintf(out, "    \n");
            fprintf(out, "    struct ast_list_node          head;\n");
            fprintf(out, "    struct ast_list_node          *tail;\n");
            fprintf(out, "    int                           count;\n");
            fprintf(out, "};\n");
            fprintf(out, "// \n");
            fprintf(out, "struct ast_list *ast_list_new(ast_type type);\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_append(struct ast_list *list, void *elem, ast_type type);\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_iterate(struct ast_list *list);\n");
            fprintf(out, "// \n");
            fprintf(out, "void ast_list_traverse(struct ast_list *list);\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");

            // rest of symbols definitions.
            fclose(out_lyc_ast_h_declaration);
            out_lyc_ast_h_declaration = NULL;
            paste_s2f(out, LYC_AST_H_DECLARATION);
            
            // end of symbol definitions.
            fprintf(out, "#endif\n");
            fclose(out_lyc_ast_h);
            out_lyc_ast_h = NULL;
        }
        // 
        {
            // 
            out = out_lyc_ast_c;

            // 
            fclose(out_lyc_ast_c_templates);
            out_lyc_ast_c_templates = NULL;
            paste_s2f(out, LYC_AST_C_TEMPLATES);

            // 
            fclose(out_lyc_ast_c);
            out_lyc_ast_c = NULL;
        }

        //
        out_lyc_y = fopen(LYC_Y, "wt");

        // 
        fprintf(out_lyc_y, "%%{\n");
        fprintf(out_lyc_y, "#include <stdio.h>\n");
        fprintf(out_lyc_y, "#include <stdlib.h>\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "#include \"parser_ast.h\"\n");
        fprintf(out_lyc_y, "#define MAX_TOKEN_LEN 2048\n");
        fprintf(out_lyc_y, "#define new(TYPE) (TYPE *)malloc(sizeof(TYPE))\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "#ifdef YYDEBUG\n");
        fprintf(out_lyc_y, "int yydebug = 1;\n");
        fprintf(out_lyc_y, "#endif\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "struct ast_list *start_list;\n");
        fprintf(out_lyc_y, "struct ast_library_text *start_library_text;\n");
        fprintf(out_lyc_y, "struct ast_source_text *start_source_text;\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "int yylex();\n");
        fprintf(out_lyc_y, "int yyerror(char const *str);\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "%%}\n");

        // 
        paste_s2f(out_lyc_y, LYC_Y_UNION);

        // 
        paste_s2f(out_lyc_y, LYC_Y_TOKEN);

        // 
        paste_s2f(out_lyc_y, LYC_Y_TYPE);

        // 
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "%%%%\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        
        /*
        fprintf(out_lyc_y, "start\n");
        fprintf(out_lyc_y, "    : %s\n", symbols.list[0]);
        fprintf(out_lyc_y, "    ;\n");
        */
        paste_s2f_slice(out_lyc_y, LYC_Y_PERCENTS_AFTER, HEAD_IGNORE_COUNT);

        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");

        // 
        paste_s2f(out_lyc_y, LYC_Y_SYNTAX);

        // 
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "%%%%\n");
        fprintf(out_lyc_y, "int line_count = 0;\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "// \n");
        fprintf(out_lyc_y, "int\n");
        fprintf(out_lyc_y, "yyerror(char const *str)\n");
        fprintf(out_lyc_y, "{\n");
        fprintf(out_lyc_y, "    extern char *yytext;\n");
        fprintf(out_lyc_y, "    fprintf(stderr, \"%%5d: %%s: syntax error\\n\", line_count, yytext);\n");
        fprintf(out_lyc_y, "    return 0;\n");
        fprintf(out_lyc_y, "}\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "// \n");
        fprintf(out_lyc_y, "int main(int argc, const char *argv[]) {\n");
        fprintf(out_lyc_y, "    extern int yyparse(void);\n");
        fprintf(out_lyc_y, "    extern FILE *yyin;\n");
        fprintf(out_lyc_y, "    \n");
        fprintf(out_lyc_y, "    yyin = stdin;\n");
        fprintf(out_lyc_y, "    if (yyparse()) {\n");
        fprintf(out_lyc_y, "        fprintf(stderr, \"Compilation error \\n\");\n");
        fprintf(out_lyc_y, "    }\n");
        fprintf(out_lyc_y, "    \n");
        fprintf(out_lyc_y, "    return 0;\n");
        fprintf(out_lyc_y, "}\n");

        // 
        fclose(out_lyc_y);    
    return 0;
}
