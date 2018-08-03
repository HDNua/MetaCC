#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"

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

// 
const char *LYC_L_INIT_AFTER        = "after/after_init.l";
const char *LYC_L_PERCENTS_AFTER    = "after/after_percents.l";
const char *LYC_L_TOKENDEF_AFTER    = "after/after_tokendef.l";
const char *LYC_Y_UNION_AFTER       = "after/after_union.y";
const char *LYC_Y_TOKEN_AFTER       = "after/after_token.y";
const char *LYC_Y_TYPE_AFTER        = "after/after_type.y";
const char *LYC_Y_PERCENTS_AFTER    = "after/after_percents.y";
const int HEAD_IGNORE_COUNT         = 10;



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
// 
void paste_s2f_slice(FILE *out, const char *srcname, int head_ignore) {
    static char buf[ast::MAX_TOKEN_LEN];
    FILE *fin = fopen(srcname, "rt");
    if (fin == NULL) {
        fprintf(stderr, "cannot open file named [%s]; no such file or directory. \n", srcname);
        exit(1);
    }
    fflush(out);

    // 
    while (head_ignore--) {
        fgets(buf, sizeof(buf), fin);
    }
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
        fprintf(stderr, "usage: %s [ lyc ] \n", argv[0]);
        return 1;
    }
    else if (strcmp(argv[1], "javacc") == 0) {
        using namespace ast::javacc;
        
        // 
        out_jj          = fopen("out/SVParser.jj", "wt");
        out_java        = fopen("out/SVObject.java", "wt");
    }
    else if (strcmp(argv[1], "lyc") == 0) {
        using namespace ast::lyc;

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

    // need to update after traverse.
    const char *start_symbol = "expression";

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "compilation has failed. \n");
    }

    // templates
    if (strcmp(argv[1], "javacc") == 0) {
        ast::javacc::main();
    }
    // 
    else if (strcmp(argv[1], "lyc") == 0) {
        ast::lyc::main();
    }
    
    return 0;
}
