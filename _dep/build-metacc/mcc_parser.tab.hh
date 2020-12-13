/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_METACC_MCC_PARSER_TAB_HH_INCLUDED
# define YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_METACC_MCC_PARSER_TAB_HH_INCLUDED
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
    COLON = 258,
    SEMICOLON = 259,
    MCC_STRING = 260,
    MCC_SYMBOL = 261,
    MCC_METHOD = 262,
    VBAR = 263,
    LP = 264,
    RP = 265,
    COMMA = 266,
    LIST = 267,
    OPTION = 268,
    STAR = 269,
    CSTRING = 270,
    NULL_ = 271,
    SKIP = 272,
    TERMINAL = 273,
    TOKEN = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "mcc_parser.yy"

    char                                    token_str[MAX_TOKEN_LEN];
											
    class ast::list<ast::object *>          *ast_list;
    class ast::symbol_definition_list       *ast_symbol_definition_list;
    class ast::symbol_value_list            *ast_symbol_value_list;
    class ast::symbol_value_element_list    *ast_symbol_value_element_list;

    class ast::symbol_definition            *ast_symbol_definition;
    class ast::symbol_key                   *ast_symbol_key;
    class ast::key_attributes               *ast_key_attributes;
    class ast::symbol_value                 *ast_symbol_value;
    class ast::symbol_value_element         *ast_symbol_value_element;
    class ast::list_parameter               *ast_list_parameter;
    class ast::option_parameter             *ast_option_parameter;
    class ast::star_parameter               *ast_star_parameter;
    class ast::list_parameter_value         *ast_list_parameter_value;
    class ast::option_parameter_value       *ast_option_parameter_value;
    class ast::star_parameter_value         *ast_star_parameter_value;
    class ast::token_definition             *ast_token_definition;

#line 99 "/home/handy/Dropbox/linux/work/yacc/metacc/latest/build-metacc/mcc_parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HANDY_DROPBOX_LINUX_WORK_YACC_METACC_LATEST_BUILD_METACC_MCC_PARSER_TAB_HH_INCLUDED  */
