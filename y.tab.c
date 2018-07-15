/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "main.y"
/* # vim: tabstop=4 shiftwidth=4*/
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048


struct ast_list *symbol_definition_list;



int yylex();
int yyerror(char const *str);

#line 19 "main.y"
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
#line 62 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    5,    6,    6,    7,    3,    3,    8,
    4,    4,    9,    9,    9,    9,    9,    9,    9,   10,
   11,   12,   13,    1,   14,   15,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    4,    1,    2,    1,    1,    3,    1,
    1,    2,    1,    1,    4,    4,    4,    1,    1,    3,
    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    2,    0,    7,    6,    3,    0,   13,
   14,    0,    0,    0,   18,   19,    0,    0,    8,   11,
    0,    0,    0,    4,    0,   12,    0,    0,    0,    0,
    0,   21,    0,    0,   22,    9,   15,    0,   16,   17,
   24,   20,
};
static const YYINT yydgoto[] = {                          2,
   42,    3,   17,   18,    4,    5,    7,   19,   20,   28,
   31,   34,   29,   32,   35,
};
static const YYINT yysindex[] = {                      -247,
 -254,    0, -247,    0, -239,    0,    0,    0, -259,    0,
    0, -244, -243, -242,    0,    0, -256, -259,    0,    0,
 -259, -259, -259,    0, -259,    0, -240, -241, -238, -240,
 -236,    0, -240, -235,    0,    0,    0, -234,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -233,    0,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -248,    0,    0,
    0,    0,    0,    0,    0,    0, -232,    0,    0, -230,
    0,    0, -229,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -18,    0,   27,    0,    0,    6,   14,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 35
static const YYINT yytable[] = {                         10,
   11,   24,   27,   30,   33,   25,   12,   13,   14,   10,
   15,   16,    1,   10,    6,   10,   10,    9,   21,   22,
   23,   25,   37,    5,   41,    1,   38,   39,   40,    8,
   36,   26,   23,   25,   26,
};
static const YYINT yycheck[] = {                        259,
  260,  258,   21,   22,   23,  262,  266,  267,  268,  258,
  270,  271,  260,  262,  269,  264,  265,  257,  263,  263,
  263,  262,  264,  257,  259,    0,  265,  264,  264,    3,
   25,   18,  265,  264,  264,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 289
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"COLON","SEMICOLON","MCC_STRING",
"MCC_SYMBOL","MCC_METHOD","VBAR","LP","RP","COMMA","LIST","OPTION","STAR",
"SKIP","CSTRING","NULL_",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : source_text",
"source_text : symbol_definition_list",
"symbol_definition_list : symbol_definition",
"symbol_definition_list : symbol_definition_list symbol_definition",
"symbol_definition : symbol_key COLON symbol_value_list SEMICOLON",
"symbol_key : MCC_SYMBOL",
"symbol_key : MCC_SYMBOL key_attributes",
"key_attributes : SKIP",
"symbol_value_list : symbol_value",
"symbol_value_list : symbol_value_list VBAR symbol_value",
"symbol_value : symbol_value_element_list",
"symbol_value_element_list : symbol_value_element",
"symbol_value_element_list : symbol_value_element_list symbol_value_element",
"symbol_value_element : MCC_STRING",
"symbol_value_element : MCC_SYMBOL",
"symbol_value_element : LIST LP list_parameter RP",
"symbol_value_element : OPTION LP option_parameter RP",
"symbol_value_element : STAR LP star_parameter RP",
"symbol_value_element : CSTRING",
"symbol_value_element : NULL_",
"list_parameter : list_parameter_value COMMA list_parameter_delim",
"option_parameter : option_parameter_value",
"star_parameter : star_parameter_value",
"list_parameter_value : symbol_value_list",
"list_parameter_delim : MCC_STRING",
"option_parameter_value : symbol_value_list",
"star_parameter_value : symbol_value_list",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 289 "main.y"

int line_count = 0;

int
yyerror(char const *str)
{
	extern char *yytext;
	fprintf(stderr, "%4d: %s: syntax error \n", line_count, yytext);
	return 0;
}

int main(void) {
	extern int yyparse(void);
	extern FILE *yyin;

	yyin = stdin;
	if (yyparse()) {
		fprintf(stderr, "ERROR \n");
	}

	return 0;
}
#line 272 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 74 "main.y"
	{
		symbol_definition_list = yystack.l_mark[0].ast_list;
	}
break;
case 2:
#line 80 "main.y"
	{
		struct ast_list *list = ast_list_new(AST_SYMBOL_DEFINITION);
		ast_list_append(list, yystack.l_mark[0].ast_symbol_definition, AST_SYMBOL_DEFINITION);
		yyval.ast_list = list;
	}
break;
case 3:
#line 86 "main.y"
	{
		ast_list_append(yystack.l_mark[-1].ast_list, yystack.l_mark[0].ast_symbol_definition, AST_SYMBOL_DEFINITION);
		yyval.ast_list = yystack.l_mark[-1].ast_list;
	}
break;
case 4:
#line 93 "main.y"
	{
		struct ast_symbol_definition *ret = 
			(struct ast_symbol_definition *)malloc(sizeof(struct ast_symbol_definition));
		ret->ast_symbol_key = yystack.l_mark[-3].ast_symbol_key;
		ret->ast_symbol_value_list = yystack.l_mark[-1].ast_list;
		yyval.ast_symbol_definition = ret;
	}
break;
case 5:
#line 103 "main.y"
	{
		struct ast_symbol_key *ret = 
			(struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		ret->symbol_name = strdup(yystack.l_mark[0].token_str);
		ret->ast_key_attributes = NULL;
		yyval.ast_symbol_key = ret;
	}
break;
case 6:
#line 111 "main.y"
	{
		struct ast_symbol_key *ret = 
			(struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		ret->symbol_name = strdup(yystack.l_mark[-1].token_str);
		ret->ast_key_attributes = yystack.l_mark[0].ast_key_attributes;
		yyval.ast_symbol_key = ret;
	}
break;
case 7:
#line 121 "main.y"
	{
		yyval.ast_key_attributes = NULL;
	}
break;
case 8:
#line 127 "main.y"
	{
		struct ast_list *list = (struct ast_list *)malloc(sizeof(struct ast_list));
		ast_list_append(list, yystack.l_mark[0].ast_symbol_value, AST_SYMBOL_VALUE);
		yyval.ast_list = list;
	}
break;
case 9:
#line 133 "main.y"
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ast_list_append(yystack.l_mark[-2].ast_list, yystack.l_mark[0].ast_symbol_value, AST_SYMBOL_VALUE);
		yyval.ast_list = yystack.l_mark[-2].ast_list;
	}
break;
case 10:
#line 142 "main.y"
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ret->ast_symbol_value_element_list = yystack.l_mark[0].ast_list;
		yyval.ast_symbol_value = ret;
	}
break;
case 11:
#line 151 "main.y"
	{
		struct ast_list *list = ast_list_new(AST_SYMBOL_VALUE_ELEMENT);
		ast_list_append(list, yystack.l_mark[0].ast_symbol_value_element, AST_SYMBOL_VALUE_ELEMENT);
		yyval.ast_list = list;
	}
break;
case 12:
#line 157 "main.y"
	{
		ast_list_append(yystack.l_mark[-1].ast_list, yystack.l_mark[0].ast_symbol_value_element, AST_SYMBOL_VALUE_ELEMENT);
		yyval.ast_list = yystack.l_mark[-1].ast_list;
	}
break;
case 13:
#line 164 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_STRING;
		ret->u.string = strdup(yystack.l_mark[0].token_str);
		yyval.ast_symbol_value_element = ret;
	}
break;
case 14:
#line 172 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_SYMBOL;
		ret->u.mcc_symbol = strdup(yystack.l_mark[0].token_str);
		yyval.ast_symbol_value_element = ret;
	}
break;
case 15:
#line 180 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_LIST_PARAMETER;
		ret->u.ast_list_parameter = yystack.l_mark[-1].ast_list_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 16:
#line 188 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_OPTION_PARAMETER;
		ret->u.ast_option_parameter = yystack.l_mark[-1].ast_option_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 17:
#line 196 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_STAR_PARAMETER;
		ret->u.ast_star_parameter = yystack.l_mark[-1].ast_star_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 18:
#line 204 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		/* ret->type = AST_STAR_PARAMETER;*/
		/* ret->u.ast_star_parameter = $3;*/
		yyval.ast_symbol_value_element = ret;
	}
break;
case 19:
#line 212 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		/* ret->type = AST_STAR_PARAMETER;*/
		/* ret->u.ast_star_parameter = $3;*/
		yyval.ast_symbol_value_element = ret;
	}
break;
case 20:
#line 222 "main.y"
	{
		struct ast_list_parameter *ret = 
			(struct ast_list_parameter *)malloc(sizeof(struct ast_list_parameter));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_list_parameter_value = yystack.l_mark[-2].ast_list_parameter_value;
		ret->ast_list_parameter_delim = yystack.l_mark[0].token_str;
		yyval.ast_list_parameter = ret;
	}
break;
case 21:
#line 233 "main.y"
	{
		struct ast_option_parameter *ret = 
			(struct ast_option_parameter *)malloc(sizeof(struct ast_option_parameter));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_option_parameter_value = yystack.l_mark[0].ast_option_parameter_value;
		yyval.ast_option_parameter = ret;
	}
break;
case 22:
#line 243 "main.y"
	{
		struct ast_star_parameter *ret = (struct ast_star_parameter *)
			malloc(sizeof(struct ast_star_parameter));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_star_parameter_value = yystack.l_mark[0].ast_star_parameter_value;
		yyval.ast_star_parameter = ret;
	}
break;
case 23:
#line 253 "main.y"
	{
		struct ast_list_parameter_value *ret = (struct ast_list_parameter_value *)
			malloc(sizeof(struct ast_list_parameter_value));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_symbol_value_element_list = yystack.l_mark[0].ast_list;
		yyval.ast_list_parameter_value = ret;
	}
break;
case 25:
#line 266 "main.y"
	{
		struct ast_option_parameter_value *ret = (struct ast_option_parameter_value *)
			malloc(sizeof(struct ast_option_parameter_value));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_symbol_value_element_list = yystack.l_mark[0].ast_list;
		yyval.ast_option_parameter_value = ret;
	}
break;
case 26:
#line 276 "main.y"
	{
		struct ast_star_parameter_value *ret = (struct ast_star_parameter_value *)
			malloc(sizeof(struct ast_star_parameter_value));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_symbol_value_element_list = yystack.l_mark[0].ast_list;
		yyval.ast_star_parameter_value = ret;
	}
break;
#line 703 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
