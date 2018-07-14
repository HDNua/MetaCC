%{
#include <stdio.h>
#include "y.tab.h"

int 
yywrap(void)
{
	return 1;
}
%}
%%

[ \t\r\n]	;



[a-z_0-9]+ {
	strcpy(yylval.token_str, yytext);
	return MCC_SYMBOL;
}
[A-Z_0-9]+ {
	strcpy(yylval.token_str, yytext);
	return MCC_METHOD;
}




[1-9][0-9]* {
	double temp;
	sscanf(yytext, "%lf", &temp);
	yylval.double_value = temp;
	return DOUBLE_LITERAL;
}
[0-9]*\.[0-9]* {
	double temp;
	sscanf(yytext, "%lf", &temp);
	yylval.double_value = temp;
	return DOUBLE_LITERAL;
}
%%
