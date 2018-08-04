%{
#define MAX_TOKEN_LEN 2048

#include <stdio.h>
#include "y.tab.h"


#ifdef YYDEBUG
extern int yydebug;
#endif

extern int line_count;

int
yywrap(void)
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
	return STRING;
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

[0-9]+ {
	strcpy(yylval.token_str, yytext);
	return INTEGER;
}
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return IDENTIFIER;
}


