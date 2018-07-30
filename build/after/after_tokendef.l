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
