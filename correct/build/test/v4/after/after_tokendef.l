%{

%}




%x IN_STRING

%%

[0-9]+ {
	strcpy(yylval.token_str, yytext);
	return INTEGER;
}
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return IDENTIFIER;
}


