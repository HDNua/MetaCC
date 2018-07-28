#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#include <unistd.h>
#include <sys/stat.h>



//==============================================================================
//
const char *LYC_Y                   = "out/parser.y";
const char *LYC_Y_SYNTAX            = "out/parser.y.syntax";
const char *LYC_Y_UNION             = "out/parser.y.union";
const char *LYC_Y_TOKEN             = "out/parser.y.token";
const char *LYC_Y_TYPE              = "out/parser.y.type";
const char *LYC_Y_LIST              = "out/parser.y.list";
const char *LYC_Y_OPT               = "out/parser.y.opt";
const char *LYC_Y_STAR              = "out/parser.y.star";
const char *LYC_L                   = "out/parser.l";
const char *LYC_L_TOKENDEF          = "out/parser.l.tokendef";
const char *LYC_AST_H               = "out/parser_ast.h";
const char *LYC_AST_H_TYPEDEF       = "out/parser_ast.h.typedef";
const char *LYC_AST_H_DECLARATION   = "out/parser_ast.h.declaration";
const char *LYC_AST_C               = "out/parser_ast.c";
const char *LYC_AST_C_TEMPLATES     = "out/parser_ast.c.templates";



//==============================================================================
// 
void paste_file(FILE *fout, FILE *fin) {
    char buf[1024] = "";
    while (fgets(buf, sizeof(buf), fin) != NULL) {
        fputs(buf, fout);
        memset(buf, 0, sizeof(buf));
    }
}
// 
void paste_s2f(FILE *out, const char *srcname) {
    FILE *fin = fopen(srcname, "rt");
    if (fin == NULL) {
        fprintf(stderr, "cannot open file named [%s]; no such file or directory. \n", srcname);
        exit(1);
    }
    fflush(out);
    paste_file(out, fin);
    fflush(out);
    fclose(fin);
}



//==============================================================================
// 
int metacc_init(int argc, const char *argv[]) {
    // 
    mkdir("out", 0777);

    // 
    if (argc < 2) {
        fprintf(stderr, "usage: %s [ javacc | lyc | lycpp ] \n", argv[0]);
        return 1;
    }
    else if (strcmp(argv[1], "javacc") == 0) {
        extern FILE *out_jj;
        extern FILE *out_java;
        
        // 
        out_jj          = fopen("out/SVParser.jj", "wt");
        out_java        = fopen("out/SVObject.java", "wt");
    }
    else if (strcmp(argv[1], "lyc") == 0) {
        extern FILE *out_lyc;
        extern FILE *out_lyc_y;
        extern FILE *out_lyc_y_union;
        extern FILE *out_lyc_y_token;
        extern FILE *out_lyc_y_type;
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

        // 
        out_lyc                             = fopen(LYC_Y_SYNTAX,           "wt");
        out_lyc_y                           = fopen(LYC_Y,                  "wt");
        out_lyc_y_union                     = fopen(LYC_Y_UNION,            "wt");
        out_lyc_y_token                     = fopen(LYC_Y_TOKEN,            "wt");      
        out_lyc_y_type                      = fopen(LYC_Y_TYPE,             "wt");
        out_lyc_y_list                      = fopen(LYC_Y_LIST,             "wt");      
        out_lyc_y_option                    = fopen(LYC_Y_OPT,              "wt");      
        out_lyc_y_star                      = fopen(LYC_Y_STAR,             "wt");      
        out_lyc_l                           = fopen(LYC_L,                  "wt");
        out_lyc_l_tokendef                  = fopen(LYC_L_TOKENDEF,         "wt");
        out_lyc_ast_h                       = fopen(LYC_AST_H,              "wt");
        out_lyc_ast_h_typedef               = fopen(LYC_AST_H_TYPEDEF,      "wt");
        out_lyc_ast_h_declaration           = fopen(LYC_AST_H_DECLARATION,  "wt");
        out_lyc_ast_c                       = fopen(LYC_AST_C,              "wt");
        out_lyc_ast_c_templates             = fopen(LYC_AST_C_TEMPLATES,    "wt");

        // 
    }
    else if (strcmp(argv[1], "lycpp") == 0) {
        fprintf(stderr, "not implemented \n");
        return 1;
    }
    else {
        fprintf(stderr, "usage: %s [ javacc | lyc | lycpp ] \n", argv[0]);
        return 1;
    }

    return 0;
}
// 
int metacc_main(int argc, const char *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;

    const char *start_symbol = "expression";

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "compilation has failed. \n");
    }

    // templates
    if (out_jj) {
        extern class ast::list *symbol_definition_list;
        const char *parser_name = "SVParser";

        // 
        fprintf(out_jj, "options {\n");
        fprintf(out_jj, "    STATIC = false;\n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "PARSER_BEGIN(%s)\n", parser_name);
        fprintf(out_jj, "import java.io.*;\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "class %s {\n", parser_name);
        fprintf(out_jj, "    public static void main(String[] args) {\n");
        fprintf(out_jj, "        try {\n");
        fprintf(out_jj, "            for (String arg: args) {\n");
        fprintf(out_jj, "                check(arg);\n");
        fprintf(out_jj, "            }\n");
        fprintf(out_jj, "        }\n");
        fprintf(out_jj, "        catch (ParseException ex) {\n");
        fprintf(out_jj, "            System.err.println(ex.getMessage());\n");
        fprintf(out_jj, "        }\n");
        fprintf(out_jj, "    }\n");
        fprintf(out_jj, "    public static String check(String s) throws ParseException {\n");
        fprintf(out_jj, "        Reader reader = new StringReader(s);\n");
        fprintf(out_jj, "        return new SVParser(reader).%s().toString();\n", start_symbol);
        fprintf(out_jj, "    }\n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "PARSER_END(%s)\n", parser_name);
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");

        // 
        /// ast_list_traverse(out_jj, symbol_definition_list, ast::ACTOPT_NONE);    
        symbol_definition_list->action(out_jj, ast::ACTOPT_NONE);

        // 
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "SKIP: { <[\" \", \"\\t\", \"\\r\", \"\\n\"]> }\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "TOKEN: {\n");
        fprintf(out_jj, "  <FILE_PATH: ([\"a\"-\"z\",\"A\"-\"Z\",\"0\"-\"9\",\"_\",\".\",\"/\"])+ >\n");
        fprintf(out_jj, "| <IDENTIFIER: [\"a\"-\"z\",\"A\"-\"Z\",\"_\"]([\"a\"-\"z\",\"A\"-\"Z\",\"0\"-\"9\",\"_\",\"$\"])* >\n");
        fprintf(out_jj, "    \n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "//=========================================================================================\n");
        fprintf(out_jj, "// STRING \n");
        fprintf(out_jj, "//-----------------------------------------------------------------------------------------\n");
        fprintf(out_jj, "MORE: { <\"\\\"\">: IN_SV_STRING }\n");
        fprintf(out_jj, "<IN_SV_STRING> MORE: {\n");
        fprintf(out_jj, "    \"\\\\\": IN_SV_STRING_ESCAPE \n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "<IN_SV_STRING> TOKEN: {\n");
        fprintf(out_jj, "    <SV_STRING:\"\\\"\">: DEFAULT \n");
        fprintf(out_jj, "|   <CHAR:~[\"\\\"\",\"\\\\\"]> \n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "<IN_SV_STRING_ESCAPE> TOKEN: {\n");
        fprintf(out_jj, "    <[\"\\\"\",\"\\\\\",\"/\",\"b\",\"f\",\"n\",\"r\",\"t\"]>: IN_SV_STRING \n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");

        // 
        fclose(out_jj);
        fclose(out_java);
    }
    // 
    else if (out_lyc) {
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
            fprintf(out, "\n");
            fprintf(out, "%%}\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "%%%%\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");
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
            fclose(out_lyc_y_union);
            out_lyc_y_union = NULL;
        }
        // 
        {
            char fmt[ast::MAX_TOKEN_LEN] = "";
            char type_left[ast::MAX_TOKEN_LEN] = "";
            extern struct table symbols;
            out = out_lyc_y_type;

            // 
            for (int i=0, len=symbols.count; i < len; ++i) {
                const char *symbol_name = symbols.list[i];

                // 
                sprintf(fmt, "%%%%type %%-%ds %%s\n", ::longest_symbol_length+8);
                sprintf(type_left, "<ast_%-s>", symbol_name);
                fprintf(out, fmt, type_left, symbol_name);
            }
            fprintf(out, "\n");
            fprintf(out, "\n");
            fprintf(out, "\n");

            // 
            fclose(out_lyc_y_type);
            out_lyc_y_type = NULL;
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
                fprintf(out_lyc_l_tokendef, "\"%s\" return %s;\n", tokens.list[i], tokens.list[i]);
            }

            //
            fclose(out_lyc_y_token);
            out_lyc_y_token = NULL;
        }
        // 
        {
            out = out_lyc_l;

            // 
            fclose(out_lyc_l_tokendef);
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
        fprintf(out_lyc_y, "#define YYDEBUG 1\n");
        fprintf(out_lyc_y, "#define MAX_TOKEN_LEN 2048\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "struct ast_list *start_list;\n");
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
        fprintf(out_lyc_y, "start\n");
        fprintf(out_lyc_y, "    : source_text\n");
        fprintf(out_lyc_y, "    ;\n");
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
        fprintf(out_lyc_y, "    fprintf(stderr, \"%%5d: %%s: syntax error\", line_count, yytext);\n");
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
    }
    
    return 0;
}
