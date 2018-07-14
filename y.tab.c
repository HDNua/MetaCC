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
#define CANNOT_MATCH_STRING 269
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    5,    6,    7,    3,    3,    8,    4,
    4,    9,    9,    9,    9,    9,   10,   11,   12,   13,
    1,   14,   15,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    4,    1,    1,    1,    3,    1,    1,
    2,    1,    1,    4,    4,    4,    3,    1,    1,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    5,    0,    0,    2,    0,    3,    0,   12,   13,    0,
    0,    0,    0,    0,    7,   10,    0,    0,    0,    4,
    0,   11,   20,    0,    0,   22,    0,   18,   23,    0,
   19,    8,   14,    0,   15,   16,   21,   17,
};
static const YYINT yydgoto[] = {                          2,
   38,    3,   13,   14,    4,    5,    0,   15,   16,   24,
   27,   30,   25,   28,   31,
};
static const YYINT yysindex[] = {                      -257,
    0,    0, -257,    0, -253,    0, -259,    0,    0, -258,
 -252, -245, -256, -259,    0,    0, -259, -259, -259,    0,
 -259,    0,    0, -247, -244,    0, -242,    0,    0, -241,
    0,    0,    0, -240,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -246,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,   21,    0,    0,    4,   -4,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 25
static const YYINT yytable[] = {                          8,
    9,   20,    1,    7,   17,   21,   10,   11,   12,   22,
   18,    9,   23,   26,   29,    9,   33,   19,   37,    1,
   34,   35,   36,    6,   32,
};
static const YYINT yycheck[] = {                        259,
  260,  258,  260,  257,  263,  262,  266,  267,  268,   14,
  263,  258,   17,   18,   19,  262,  264,  263,  259,    0,
  265,  264,  264,    3,   21,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 287
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
"\"CANNOT_MATCH_STRING\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : source_text",
"source_text : symbol_definition_list",
"symbol_definition_list : symbol_definition",
"symbol_definition_list : symbol_definition_list symbol_definition",
"symbol_definition : symbol_key COLON symbol_value_list SEMICOLON",
"symbol_key : MCC_SYMBOL",
"key_attributes : \"CANNOT_MATCH_STRING\"",
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
"list_parameter : list_parameter_value COMMA list_parameter_delim",
"option_parameter : option_parameter_value",
"star_parameter : star_parameter_value",
"list_parameter_value : symbol_value_element",
"list_parameter_delim : MCC_STRING",
"option_parameter_value : symbol_value_element",
"star_parameter_value : symbol_value_element",

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
#line 274 "main.y"

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
#line 262 "y.tab.c"

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
#line 73 "main.y"
	{
		symbol_definition_list = yystack.l_mark[0].ast_list;
	}
break;
case 2:
#line 79 "main.y"
	{
		struct ast_list *list = ast_list_new(AST_SYMBOL_DEFINITION);
		ast_list_append(list, yystack.l_mark[0].ast_symbol_definition, AST_SYMBOL_DEFINITION);
		yyval.ast_list = list;
	}
break;
case 3:
#line 85 "main.y"
	{
		ast_list_append(yystack.l_mark[-1].ast_list, yystack.l_mark[0].ast_symbol_definition, AST_SYMBOL_DEFINITION);
		yyval.ast_list = yystack.l_mark[-1].ast_list;
	}
break;
case 4:
#line 92 "main.y"
	{
		struct ast_symbol_definition *ret = 
			(struct ast_symbol_definition *)malloc(sizeof(struct ast_symbol_definition));
		ret->ast_symbol_key = yystack.l_mark[-3].ast_symbol_key;
		ret->ast_symbol_value_list = yystack.l_mark[-1].ast_list;
		yyval.ast_symbol_definition = ret;
	}
break;
case 5:
#line 102 "main.y"
	{
		struct ast_symbol_key *ret = 
			(struct ast_symbol_key *)malloc(sizeof(struct ast_symbol_key));
		ret->symbol_name = strdup(yystack.l_mark[0].token_str);
		ret->ast_key_attributes = NULL;
		yyval.ast_symbol_key = ret;
	}
break;
case 6:
#line 122 "main.y"
	{
		yyval.ast_key_attributes = NULL;
	}
break;
case 7:
#line 128 "main.y"
	{
		struct ast_list *list = (struct ast_list *)malloc(sizeof(struct ast_list));
		ast_list_append(list, yystack.l_mark[0].ast_symbol_value, AST_SYMBOL_VALUE);
		yyval.ast_list = list;
	}
break;
case 8:
#line 134 "main.y"
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ast_list_append(yystack.l_mark[-2].ast_list, yystack.l_mark[0].ast_symbol_value, AST_SYMBOL_VALUE);
		yyval.ast_list = yystack.l_mark[-2].ast_list;
	}
break;
case 9:
#line 143 "main.y"
	{
		struct ast_symbol_value *ret = 
			(struct ast_symbol_value *)malloc(sizeof(struct ast_symbol_value));
		ret->ast_symbol_value_element_list = yystack.l_mark[0].ast_list;
		yyval.ast_symbol_value = ret;
	}
break;
case 10:
#line 152 "main.y"
	{
		struct ast_list *list = ast_list_new(AST_SYMBOL_VALUE_ELEMENT);
		ast_list_append(list, yystack.l_mark[0].ast_symbol_value_element, AST_SYMBOL_VALUE_ELEMENT);
		yyval.ast_list = list;
	}
break;
case 11:
#line 158 "main.y"
	{
		ast_list_append(yystack.l_mark[-1].ast_list, yystack.l_mark[0].ast_symbol_value_element, AST_SYMBOL_VALUE_ELEMENT);
		yyval.ast_list = yystack.l_mark[-1].ast_list;
	}
break;
case 12:
#line 165 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_STRING;
		ret->u.string = strdup(yystack.l_mark[0].token_str);
		yyval.ast_symbol_value_element = ret;
	}
break;
case 13:
#line 173 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_MCC_SYMBOL;
		ret->u.mcc_symbol = strdup(yystack.l_mark[0].token_str);
		yyval.ast_symbol_value_element = ret;
	}
break;
case 14:
#line 181 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_LIST_PARAMETER;
		ret->u.ast_list_parameter = yystack.l_mark[-1].ast_list_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 15:
#line 189 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_OPTION_PARAMETER;
		ret->u.ast_option_parameter = yystack.l_mark[-1].ast_option_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 16:
#line 197 "main.y"
	{
		struct ast_symbol_value_element *ret = 
			(struct ast_symbol_value_element *)malloc(sizeof(struct ast_symbol_value_element));
		ret->type = AST_STAR_PARAMETER;
		ret->u.ast_star_parameter = yystack.l_mark[-1].ast_star_parameter;
		yyval.ast_symbol_value_element = ret;
	}
break;
case 17:
#line 207 "main.y"
	{
		struct ast_list_parameter *ret = 
			(struct ast_list_parameter *)malloc(sizeof(struct ast_list_parameter));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_list_parameter_value = yystack.l_mark[-2].ast_list_parameter_value;
		ret->ast_list_parameter_delim = yystack.l_mark[0].token_str;
		yyval.ast_list_parameter = ret;
	}
break;
case 18:
#line 218 "main.y"
	{
		struct ast_option_parameter *ret = 
			(struct ast_option_parameter *)malloc(sizeof(struct ast_option_parameter));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_option_parameter_value = yystack.l_mark[0].ast_option_parameter_value;
		yyval.ast_option_parameter = ret;
	}
break;
case 19:
#line 228 "main.y"
	{
		struct ast_star_parameter *ret = (struct ast_star_parameter *)
			malloc(sizeof(struct ast_star_parameter));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_star_parameter_value = yystack.l_mark[0].ast_star_parameter_value;
		yyval.ast_star_parameter = ret;
	}
break;
case 20:
#line 238 "main.y"
	{
		struct ast_list_parameter_value *ret = (struct ast_list_parameter_value *)
			malloc(sizeof(struct ast_list_parameter_value));
		ret->type = AST_LIST_PARAMETER;
		ret->ast_symbol_value_element = yystack.l_mark[0].ast_symbol_value_element;
		yyval.ast_list_parameter_value = ret;
	}
break;
case 22:
#line 251 "main.y"
	{
		struct ast_option_parameter_value *ret = (struct ast_option_parameter_value *)
			malloc(sizeof(struct ast_option_parameter_value));
		ret->type = AST_OPTION_PARAMETER;
		ret->ast_symbol_value_element = yystack.l_mark[0].ast_symbol_value_element;
		yyval.ast_option_parameter_value = ret;
	}
break;
case 23:
#line 261 "main.y"
	{
		struct ast_star_parameter_value *ret = (struct ast_star_parameter_value *)
			malloc(sizeof(struct ast_star_parameter_value));
		ret->type = AST_STAR_PARAMETER;
		ret->ast_symbol_value_element = yystack.l_mark[0].ast_symbol_value_element;
		yyval.ast_star_parameter_value = ret;
	}
break;
#line 663 "y.tab.c"
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
