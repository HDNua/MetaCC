#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"

#include <unistd.h>
#include <sys/stat.h>



// 
int ast::javacc::main(int argc, const char *argv[]) {
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

    return 0;
}
