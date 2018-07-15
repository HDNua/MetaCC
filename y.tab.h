#define COLON 257
#define SEMICOLON 258
#define MCC_STRING 259
#define MCC_SYMBOL 260
#define MCC_METHOD 261
#define VBAR 262
#define LP 263
#define RP 264
#define COMMA 265
#define LIST 266
#define OPTION 267
#define STAR 268
#define SKIP 269
#define CSTRING 270
#define NULL_ 271
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char                                    token_str[MAX_TOKEN_LEN];
	
	struct ast_list                         *ast_list;
	struct ast_symbol_definition            *ast_symbol_definition;
	struct ast_symbol_key                   *ast_symbol_key;
	struct ast_key_attributes               *ast_key_attributes;
	struct ast_symbol_value                 *ast_symbol_value;
	struct ast_symbol_value_element         *ast_symbol_value_element;
	struct ast_list_parameter               *ast_list_parameter;
	struct ast_option_parameter             *ast_option_parameter;
	struct ast_star_parameter               *ast_star_parameter;
	struct ast_list_parameter_value         *ast_list_parameter_value;
	struct ast_option_parameter_value       *ast_option_parameter_value;
	struct ast_star_parameter_value         *ast_star_parameter_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
