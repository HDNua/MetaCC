%{

%}




%x IN_ESCAPED_IDENTIFIER
%%

[0-9]+ {
	strcpy(yylval.token_str, yytext);
	return SV_INTEGER;
}
[a-zA-Z_][a-zA-Z_0-9]* {
	strcpy(yylval.token_str, yytext);
	return SV_IDENTIFIER;
}



"\\" {
	dst = yylval.token_str;
	BEGIN(IN_ESCAPED_IDENTIFIER);
}
<IN_ESCAPED_IDENTIFIER>[ \r\t] {
	*dst = '\0';
	BEGIN(INITIAL);
	return SV_ESCAPED_IDENTIFIER;
}
<IN_ESCAPED_IDENTIFIER>\n {
	*dst = '\0';
	++line_count;
	BEGIN(INITIAL);
	return SV_ESCAPED_IDENTIFIER;
}
<IN_ESCAPED_IDENTIFIER>[^ \r\t\n] {
	*dst++ = *yytext;
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



[1-9][0-9_*]"."[0-9]* {
	strcpy(yylval.token_str, yytext);
	return SV_FIXED_POINT_NUMBER;
}
[1-9][0-9_*]("."[0-9]*)?[eE][+-]?(0-9)+ {
	strcpy(yylval.token_str, yytext);
	return SV_EXPONENTIAL_NUMBER;
}












