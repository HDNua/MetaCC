%{
#define MAX_TOKEN_LEN 2048

#include <stdio.h>
#include "y.tab.h"


#ifdef YYDEBUG
extern int yydebug = 1;
#endif

extern int line_count;

int 
yywrap(void)
{
	return 1;
}
%}


%x COMMENT
%x LINECOMMENT
%x STRING
%%



[ \t\r\n]		;
"|"			return VBAR;
"("			return LP;
")"			return RP;
","			return COMMA;



"LIST"			return LIST;
"OPTION"		return OPTION;
"STAR"			return STAR;



"/*"			{
	BEGIN(COMMENT);
}
<COMMENT>"\n"		{
	++line_count;
}
<COMMENT>"*/"		{
	BEGIN(INITIAL);
}
"#"			{
	BEGIN(LINECOMMENT);
}
"//"			{
	BEGIN(LINECOMMENT);
}
<LINECOMMENT>"\n"	{
	++line_count;
	BEGIN(INITIAL);
}



"\""			{
	BEGIN(STRING);
}
<STRING>"\n"		{
	exit(1);
}
<STRING>"\""		{
	BEGIN(INITIAL);
	strcpy(yylval.token_str, yytext);
	return MCC_STRING;
}





[a-z][a-z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return MCC_SYMBOL;
}
[A-Z][A-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return MCC_METHOD;
}




