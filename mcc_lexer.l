%option nounput
%{
// #define MAX_TOKEN_LEN 2048
const int MAX_TOKEN_LEN = 2048;

#include "ast.h"
#include <stdio.h>
#include <string.h>
// #include "y.tab.h"
// #include "sv_parser.h"
#include "mcc_parser.tab.hh"


#ifdef YYDEBUG
extern int yydebug;
#endif

extern int line_count;

extern "C" int yywrap(void)
{
	return 1;
}

// 
char mcc_string_buf[MAX_TOKEN_LEN];
// 
char *mcc_string_ptr;

%}
%x COMMENT
%x LINECOMMENT
%x STRING
%%



[ \t\r]			;
[\n]			{
	++line_count;
}
"|"				return VBAR;
"("				return LP;
")"				return RP;
","				return COMMA;
":"				return COLON;
";"				return SEMICOLON;



"LIST"			return LIST;
"OPTION"		return OPTION;
"STAR"			return STAR;



"CSTRING"		return CSTRING;
"NULL"			return NULL_;
"TOKEN"			return TOKEN;



"SKIP"			{
	strcpy(yylval.token_str, yytext);
	return SKIP;
}
"TERMINAL"		{
	strcpy(yylval.token_str, yytext);
	return TERMINAL;
}



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
<LINECOMMENT>\n		{
	++line_count;
	BEGIN(INITIAL);
}
<LINECOMMENT>.		{
	
}



\"			{
	BEGIN(STRING);
	mcc_string_ptr = mcc_string_buf;
}
<STRING>\n		{
	fprintf(stderr, "invalid stirng \n");
	exit(1);
}
<STRING>\"		{
	*mcc_string_ptr = '\0';
	BEGIN(INITIAL);
	strcpy(yylval.token_str, mcc_string_buf);
	return MCC_STRING;
}
<STRING>.		{
	*mcc_string_ptr++ = *yytext;
}






[a-z$][a-z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return MCC_SYMBOL;
}
[A-Z][A-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return MCC_METHOD;
}




