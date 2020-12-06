%{

%}




%x IN_ESCAPED_IDENTIFIER
%%

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



