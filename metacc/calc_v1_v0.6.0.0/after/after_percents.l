%{

%}


%x IN_COMMENT
%x IN_LINECOMMENT
%x IN_STRING
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

