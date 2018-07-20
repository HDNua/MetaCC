#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#include <unistd.h>
#include <sys/stat.h>



//==============================================================================
// 
void paste_file(FILE *out, FILE *in) {
    char buf[256];
    while (fgets(buf, sizeof(buf), in) != NULL) {
        fputs(buf, out);
    }
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
        extern FILE *out_lyc_y_token;
        extern FILE *out_lyc_l;
        extern FILE *out_lyc_ast_h;
        extern FILE *out_lyc_ast_c;

        // 
        out_lyc                 = fopen("out/parser.y.syntax", "wt");
        out_lyc_y_token         = fopen("out/parser.y.token", "wt");
        out_lyc_l               = fopen("out/parser.l", "wt");
        out_lyc_ast_h           = fopen("out/parser_ast.h", "wt");
        out_lyc_ast_c           = fopen("out/parser_ast.c", "wt");

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
        extern struct ast_list *symbol_definition_list;
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
        fprintf(out_jj, "        Reader reader = new Reader(s);\n");
        fprintf(out_jj, "        return new SVParser(reader).%s();\n", start_symbol);
        fprintf(out_jj, "    }\n");
        fprintf(out_jj, "}\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "PARSER_END(%s)\n", parser_name);
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");
        fprintf(out_jj, "\n");

        // 
        ast_list_traverse(symbol_definition_list);    

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
    else if (out_lyc) {
        extern struct ast_list *symbol_definition_list;
        ast_list_traverse(symbol_definition_list);    

        // 
        fclose(out_lyc);
        fclose(out_lyc_y_token);
        fclose(out_lyc_l);
        fclose(out_lyc_ast_h);
        fclose(out_lyc_ast_c);

        // 
        FILE *in_lyc_y_token = fopen("out/parser.y.token", "rt");
        FILE *in_lyc_l       = fopen("out/parser.l", "rt");
        FILE *in_lyc_ast_h   = fopen("out/parser_ast.h", "rt");
        FILE *in_lyc_ast_c   = fopen("out/parser_ast.c", "rt");

        //
        out_lyc_y = fopen("out/parser.y", "wt");

        // 
        fprintf(out_lyc_y, "%%%%\n");
        fprintf(out_lyc_y, "\n");
        paste_file(out_lyc_y, in_lyc_y_token);
        fprintf(out_lyc_y, "\n");
        fprintf(out_lyc_y, "%%%%\n");
        fprintf(out_lyc_y, "\n");
        fclose(out_lyc_y);
    }
    
    return 0;
}



