/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_HANDY_WORK_PROJECT_METACC_DEV_CALC_V1_OUT_BUILD_PARSER_TAB_HH_INCLUDED
# define YY_YY_HOME_HANDY_WORK_PROJECT_METACC_DEV_CALC_V1_OUT_BUILD_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_0 = 258,
    TOKEN_1 = 259,
    TOKEN_2 = 260,
    TOKEN_3 = 261,
    TOKEN_4 = 262,
    TOKEN_5 = 263,
    TOKEN_6 = 264,
    SV_UNSIGNED_NUMBER = 265,
    SV_DECIMAL_NUMBER = 266,
    SV_BINARY_NUMBER = 267,
    SV_OCTAL_NUMBER = 268,
    SV_HEX_NUMBER = 269,
    SV_STRING = 270,
    SV_IDENTIFIER = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.yy" /* yacc.c:1909  */

    char token_str[MAX_TOKEN_LEN];
    class ast::list<class ast::object *> *ast_list;
    
    ast::line_list *ast_line_list;
    ast::line      *ast_line;
    ast::expr      *ast_expr;
    ast::term      *ast_term;
    ast::primary   *ast_primary;
    ast::attribute *ast_attribute;

#line 83 "/home/handy/work/project/metacc/dev/calc_v1/out/build/parser.tab.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HANDY_WORK_PROJECT_METACC_DEV_CALC_V1_OUT_BUILD_PARSER_TAB_HH_INCLUDED  */
