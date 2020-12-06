%option nounput
%{
const int MAX_TOKEN_LEN = 2048;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "parser_ast.h"
#include "parser.tab.hh"


#ifdef YYDEBUG
extern int yydebug;
#endif

extern int line_count;

extern "C" int yywrap(void)
{
    return 1;
}


char *dst;


%}



%x IN_STRING
%x IN_COMMENT
%x IN_LINECOMMENT
%%


[ \t\r] {

}
\n {
	++line_count;
}



\"       {
	dst = yylval.token_str;
	BEGIN(IN_STRING);
}
<IN_STRING>[^\"\n] {
	*dst++ = *yytext;
}
<IN_STRING>\n {
	fprintf(stderr, 
	"cannot include new line character inside string; use escaped sequence insead. \n");
	exit(1);
}
<IN_STRING>"\"" {
	*dst = '\0';
	BEGIN(INITIAL);
	return SV_STRING;
}

"/*" {
	BEGIN(IN_COMMENT);
}
<IN_COMMENT>"*/" {
	BEGIN(INITIAL);
}
<IN_COMMENT>[^\n] {

}
<IN_COMMENT>\n {
	++line_count;
}

"//" {
	BEGIN(IN_LINECOMMENT);
}
<IN_LINECOMMENT>[^\n] {
	;
}
<IN_LINECOMMENT>\n {
	BEGIN(INITIAL);
	++line_count;
}

";" return TOKEN_0;
"+" return TOKEN_1;
"-" return TOKEN_2;
"*" return TOKEN_3;
"/" return TOKEN_4;
"(" return TOKEN_5;
")" return TOKEN_6;
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return SV_IDENTIFIER;
}



[1-9][0-9_]* {
	strcpy(yylval.token_str, yytext);
	return SV_UNSIGNED_NUMBER;
}
[1-9][0-9_]*'[sS]?[dD][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_DECIMAL_NUMBER;
}
[1-9][0-9_]*'[sS]?[oO][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_OCTAL_NUMBER;
}
[1-9][0-9_]*'[sS]?[bB][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_BINARY_NUMBER;
}
[1-9][0-9_]*'[sS]?[hH][0-9_xXzZ]+ {
	strcpy(yylval.token_str, yytext);
	return SV_HEX_NUMBER;
}



