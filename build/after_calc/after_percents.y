%{
%}
%union {
	struct ast_library_text *ast_library_text;	struct ast_source_text *ast_source_text;
}
%type <ast_library_text> library_text
%type <ast_source_text> source_text
%%



start_calc
	: line_list
	;

// start
// 	: library_text
// 	{
// 		start_library_text = $1;
// 	}
// 	| source_text
// 	{
// 		start_source_text = $1;
// 	}
// 	;

