/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../metacc/mcc_parser.yy"

// # vim: tabstop=4 shiftwidth=4
#include <cstdio>
#include <cstdlib>


#include "ast.h"
#define YYDEBUG 1
#define MAX_TOKEN_LEN 2048



ast::symbol_definition_list *symbol_definition_list;



int yylex();
int yyerror(char const *str);


#line 91 "mcc_parser.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MCC_PARSER_TAB_HH_INCLUDED
# define YY_YY_MCC_PARSER_TAB_HH_INCLUDED
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
    C_MCC_TYPE = 263,
    C_IDENTIFIER = 264,
    VBAR = 265,
    LP = 266,
    RP = 267,
    MLP = 268,
    MRP = 269,
    COMMA = 270,
    ASTERISK = 271,
    LIST = 272,
    OPTION = 273,
    STAR = 274,
    CSTRING = 275,
    NULL_ = 276,
    SKIP = 277,
    TERMINAL = 278,
    TOKEN = 279,
    FIELDS = 280,
    METHODS = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "../metacc/mcc_parser.yy"

    char                                      token_str[MAX_TOKEN_LEN];

    class ast::list<ast::object *>            *ast_list;
    class ast::symbol_definition_list         *ast_symbol_definition_list;
    class ast::symbol_value_list              *ast_symbol_value_list;
    class ast::symbol_value_element_list      *ast_symbol_value_element_list;
	class ast::symbol_value_initializer_list  *ast_symbol_value_initializer_list;
	class ast::field_declaration_list         *ast_field_declaration_list;
	class ast::method_declaration_list        *ast_method_declaration_list;

    class ast::symbol_definition              *ast_symbol_definition;
    class ast::symbol_key                     *ast_symbol_key;
    class ast::key_attributes                 *ast_key_attributes;
    class ast::symbol_value                   *ast_symbol_value;
    class ast::symbol_value_element           *ast_symbol_value_element;
    class ast::list_parameter                 *ast_list_parameter;
    class ast::option_parameter               *ast_option_parameter;
    class ast::star_parameter                 *ast_star_parameter;
    class ast::list_parameter_value           *ast_list_parameter_value;
    class ast::option_parameter_value         *ast_option_parameter_value;
    class ast::star_parameter_value           *ast_star_parameter_value;
    class ast::token_definition               *ast_token_definition;

	class ast::symbol_value_implementation    *ast_symbol_value_implementation;
	class ast::symbol_value_initializer       *ast_symbol_value_initializer;
	class ast::initializer_call               *ast_initializer_call;

    class ast::field_initializer              *ast_field_initializer;
	class ast::field_declaration              *ast_field_declaration;
    class ast::method_initializer             *ast_method_initializer;
	class ast::method_declaration             *ast_method_declaration;

	class ast::C_variable_declaration         *ast_C_variable_declaration;
	class ast::C_function_declaration         *ast_C_function_declaration;
	class ast::C_function_call                *ast_C_function_call;
	class ast::C_declaration_qualifier        *ast_C_declaration_qualifier;
	class ast::C_init_declarator_list         *ast_C_init_declarator_list;
	class ast::C_init_declarator              *ast_C_init_declarator;
	class ast::C_declarator                   *ast_C_declarator;
	class ast::C_direct_declarator            *ast_C_direct_declarator;

#line 213 "mcc_parser.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MCC_PARSER_TAB_HH_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

#define YYUNDEFTOK  2
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   127,   134,   142,   147,   152,   157,   164,
     169,   176,   181,   188,   195,   203,   208,   215,   222,   230,
     235,   240,   244,   248,   252,   256,   262,   269,   276,   283,
     290,   293,   300,   308,   316,   324,   331,   338,   346,   355,
     363,   370,   377,   384,   390,   394,   400,   407,   413,   419,
     424,   425,   428,   429,   432,   435,   436,   439,   440,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "SEMICOLON", "MCC_STRING",
  "MCC_SYMBOL", "MCC_METHOD", "C_MCC_TYPE", "C_IDENTIFIER", "VBAR", "LP",
  "RP", "MLP", "MRP", "COMMA", "ASTERISK", "LIST", "OPTION", "STAR",
  "CSTRING", "NULL_", "SKIP", "TERMINAL", "TOKEN", "FIELDS", "METHODS",
  "$accept", "source_text", "symbol_definition_list", "symbol_definition",
  "symbol_key", "key_attributes", "symbol_value_list", "symbol_value",
  "symbol_value_element_list", "symbol_value_element", "list_parameter",
  "option_parameter", "star_parameter", "list_parameter_value",
  "list_parameter_delim", "option_parameter_value", "star_parameter_value",
  "token_definition", "symbol_value_implementation",
  "symbol_value_initializer_list", "symbol_value_initializer",
  "initializer_call", "field_initializer", "field_declaration_list",
  "field_declaration", "method_initializer", "method_declaration_list",
  "method_declaration", "C_variable_declaration", "C_function_declaration",
  "C_function_call", "C_declaration_qualifier", "C_init_declarator_list",
  "C_init_declarator", "C_declarator", "C_direct_declarator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281
};
# endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,     6,    32,    -2,   -59,    -1,   -59,   -59,   -59,   -59,
     -59,    37,    24,    27,   -59,   -59,    52,    53,    59,   -59,
      60,    47,   -59,    17,   -59,   -59,    42,     0,    42,    46,
      37,    37,    37,    62,   -59,    37,    10,   -59,   -59,   -59,
      38,   -59,   -59,     2,    37,    27,    39,   -59,   -59,    10,
      37,    63,    57,    61,    63,    65,   -59,    66,   -59,   -59,
      67,   -59,   -59,   -59,     2,    68,    10,   -59,   -59,   -59,
      64,   -59,   -59,     2,     1,   -59,   -59,   -59,    55,    69,
     -59,   -59,    70,    56,   -59,    75,   -59,   -59,   -59,    71,
     -59,   -59,    72,   -59,   -59,   -59,   -59,    37,    73,   -59,
     -59,   -59,   -59,    83,    58,    84,   -59,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,     0,     2,     3,     0,    11,    12,    10,     1,
       4,     0,     0,     0,    19,    20,     0,     0,     0,    24,
       0,     0,    13,    16,    17,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,    18,    51,    50,
       0,    40,    42,     0,     0,     0,     0,    44,    46,     0,
       0,    29,     0,     0,    31,     0,    27,     0,    32,    28,
       0,    14,    57,    58,     0,     0,    34,    35,    37,    38,
       0,    39,    41,     0,     0,    52,    54,    56,     0,     0,
      43,    45,     0,     0,    21,     0,    22,    23,    33,     0,
      15,    36,     0,    55,    47,    53,     7,     0,     0,     6,
      30,    26,    59,     0,     0,     0,    49,     8,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,    86,   -59,   -59,   -11,    74,   -59,    51,
     -59,   -59,   -59,    76,   -59,   -59,   -59,   -59,   -59,   -59,
      25,   -59,   -59,   -59,    50,    48,   -59,    49,   -59,   -59,
     -59,   -19,   -59,    18,   -58,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     8,    51,    22,    23,    24,
      52,    55,    57,    53,   101,    56,    59,    25,    65,    66,
      67,    68,    27,    40,    41,    29,    46,    47,    42,    48,
      69,    43,    74,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    70,    11,    44,     1,    94,    89,    62,    62,    49,
      63,    63,    64,    64,    82,    93,    62,    73,    73,    63,
      54,    64,    14,    15,    12,    13,    45,    49,     6,     7,
      36,    70,     9,    78,    16,    17,    18,    26,    19,    83,
      28,    20,    14,    15,    38,    38,    39,    39,    38,    50,
      39,    34,    71,    80,    16,    17,    18,    35,    19,    96,
      99,    20,   107,    30,    31,    35,    35,    60,    35,    84,
      32,    33,    97,    35,    37,    92,    85,    86,    87,    88,
     100,    98,    90,   102,   103,   105,   104,   106,   108,    10,
      72,    91,    95,    79,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    61
};

static const yytype_int8 yycheck[] =
{
      11,    36,     3,     3,     6,     4,    64,     6,     6,    28,
       9,     9,    11,    11,    49,    73,     6,    16,    16,     9,
      31,    11,     5,     6,    25,    26,    26,    46,    22,    23,
      13,    66,     0,    44,    17,    18,    19,    13,    21,    50,
      13,    24,     5,     6,     6,     6,     8,     8,     6,     3,
       8,     4,    14,    14,    17,    18,    19,    10,    21,     4,
       4,    24,     4,    11,    11,    10,    10,     5,    10,    12,
      11,    11,     3,    10,    23,    11,    15,    12,    12,    12,
       5,    11,    14,    12,    12,    12,    97,     4,     4,     3,
      40,    66,    74,    45,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    28,    29,    30,    31,    22,    23,    32,     0,
      30,     3,    25,    26,     5,     6,    17,    18,    19,    21,
      24,    33,    34,    35,    36,    44,    13,    49,    13,    52,
      11,    11,    11,    11,     4,    10,    13,    36,     6,     8,
      50,    51,    55,    58,     3,    26,    53,    54,    56,    58,
       3,    33,    37,    40,    33,    38,    42,    39,    40,    43,
       5,    34,     6,     9,    11,    45,    46,    47,    48,    57,
      62,    14,    51,    16,    59,    60,    61,    62,    33,    52,
      14,    54,    62,    33,    12,    15,    12,    12,    12,    61,
      14,    47,    11,    61,     4,    60,     4,     3,    11,     4,
       5,    41,    12,    12,    33,    12,     4,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    27,    28,    29,    29,    30,    30,    30,    30,    31,
      31,    32,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    36,    36,    36,    36,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    46,    47,    48,    49,
      50,    50,    51,    52,    53,    53,    54,    55,    56,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     6,     6,     8,     1,
       2,     1,     1,     1,     3,     4,     1,     1,     2,     1,
       1,     4,     4,     4,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     2,     1,     1,     3,
       1,     2,     1,     3,     1,     2,     1,     3,     5,     4,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 122 "../metacc/mcc_parser.yy"
        {
                symbol_definition_list = (yyvsp[0].ast_symbol_definition_list);
        }
#line 1467 "mcc_parser.tab.cc"
    break;

  case 3:
#line 128 "../metacc/mcc_parser.yy"
        {
                ast::symbol_definition_list *list = new ast::symbol_definition_list();
                if ((yyvsp[0].ast_symbol_definition) == nullptr) { puts("1"); }
                list->append((yyvsp[0].ast_symbol_definition));
                (yyval.ast_symbol_definition_list) = list;
        }
#line 1478 "mcc_parser.tab.cc"
    break;

  case 4:
#line 135 "../metacc/mcc_parser.yy"
        {
                if ((yyvsp[0].ast_symbol_definition) == nullptr) { puts("2"); }
                (yyvsp[-1].ast_symbol_definition_list)->append((yyvsp[0].ast_symbol_definition));
                (yyval.ast_symbol_definition_list) = (yyvsp[-1].ast_symbol_definition_list);
        }
#line 1488 "mcc_parser.tab.cc"
    break;

  case 5:
#line 143 "../metacc/mcc_parser.yy"
        {
                ast::symbol_definition *self = new ast::symbol_definition((yyvsp[-3].ast_symbol_key), (yyvsp[-1].ast_symbol_value_list));
                (yyval.ast_symbol_definition) = self;
        }
#line 1497 "mcc_parser.tab.cc"
    break;

  case 6:
#line 148 "../metacc/mcc_parser.yy"
        {
                ast::symbol_definition *self = new ast::symbol_definition((yyvsp[-5].ast_symbol_key), (yyvsp[-3].ast_method_initializer), (yyvsp[-1].ast_symbol_value_list));
                (yyval.ast_symbol_definition) = self;
        }
#line 1506 "mcc_parser.tab.cc"
    break;

  case 7:
#line 153 "../metacc/mcc_parser.yy"
        {
                ast::symbol_definition *self = new ast::symbol_definition((yyvsp[-5].ast_symbol_key), (yyvsp[-3].ast_field_initializer), (yyvsp[-1].ast_symbol_value_list));
                (yyval.ast_symbol_definition) = self;
        }
#line 1515 "mcc_parser.tab.cc"
    break;

  case 8:
#line 158 "../metacc/mcc_parser.yy"
        {
                ast::symbol_definition *self = new ast::symbol_definition((yyvsp[-7].ast_symbol_key), (yyvsp[-5].ast_field_initializer), (yyvsp[-3].ast_method_initializer), (yyvsp[-1].ast_symbol_value_list));
                (yyval.ast_symbol_definition) = self;
        }
#line 1524 "mcc_parser.tab.cc"
    break;

  case 9:
#line 165 "../metacc/mcc_parser.yy"
        {
                ast::symbol_key *self = new ast::symbol_key((yyvsp[0].token_str), nullptr);
                (yyval.ast_symbol_key) = self;
        }
#line 1533 "mcc_parser.tab.cc"
    break;

  case 10:
#line 170 "../metacc/mcc_parser.yy"
        {
                ast::symbol_key *self = new ast::symbol_key((yyvsp[-1].token_str), (yyvsp[0].ast_key_attributes));
                (yyval.ast_symbol_key) = self;
        }
#line 1542 "mcc_parser.tab.cc"
    break;

  case 11:
#line 177 "../metacc/mcc_parser.yy"
        {
                ast::key_attributes *self = new ast::key_attributes((yyvsp[0].token_str));
                (yyval.ast_key_attributes) = self;
        }
#line 1551 "mcc_parser.tab.cc"
    break;

  case 12:
#line 182 "../metacc/mcc_parser.yy"
        {
                ast::key_attributes *self = new ast::key_attributes((yyvsp[0].token_str));
                (yyval.ast_key_attributes) = self;
        }
#line 1560 "mcc_parser.tab.cc"
    break;

  case 13:
#line 189 "../metacc/mcc_parser.yy"
        {
                ast::symbol_value_list *list = new ast::symbol_value_list();
                if ((yyvsp[0].ast_symbol_value) == nullptr) { puts("symbol_value_list found nullptr parameter $1;"); }
                list->append((yyvsp[0].ast_symbol_value));
                (yyval.ast_symbol_value_list) = list;
        }
#line 1571 "mcc_parser.tab.cc"
    break;

  case 14:
#line 196 "../metacc/mcc_parser.yy"
        {
                if ((yyvsp[0].ast_symbol_value) == nullptr) { puts("symbol_value_list found nullptr parameter $3;"); }
                (yyvsp[-2].ast_symbol_value_list)->append((yyvsp[0].ast_symbol_value));
                (yyval.ast_symbol_value_list) = (yyvsp[-2].ast_symbol_value_list);
        }
#line 1581 "mcc_parser.tab.cc"
    break;

  case 15:
#line 204 "../metacc/mcc_parser.yy"
        {
                ast::symbol_value *self = new ast::symbol_value((yyvsp[-3].ast_symbol_value_element_list), (yyvsp[-1].ast_symbol_value_implementation));
                (yyval.ast_symbol_value) = self;
        }
#line 1590 "mcc_parser.tab.cc"
    break;

  case 16:
#line 209 "../metacc/mcc_parser.yy"
        {
                ast::symbol_value *self = new ast::symbol_value((yyvsp[0].ast_symbol_value_element_list));
                (yyval.ast_symbol_value) = self;
        }
#line 1599 "mcc_parser.tab.cc"
    break;

  case 17:
#line 216 "../metacc/mcc_parser.yy"
        {
                ast::symbol_value_element_list *list = new ast::symbol_value_element_list();
                if ((yyvsp[0].ast_symbol_value_element) == nullptr) { puts("5"); }
                list->append((yyvsp[0].ast_symbol_value_element));
                (yyval.ast_symbol_value_element_list) = list;
        }
#line 1610 "mcc_parser.tab.cc"
    break;

  case 18:
#line 223 "../metacc/mcc_parser.yy"
        {
                if ((yyvsp[0].ast_symbol_value_element) == nullptr) { puts("6"); }
                (yyvsp[-1].ast_symbol_value_element_list)->append((yyvsp[0].ast_symbol_value_element));
                (yyval.ast_symbol_value_element_list) = (yyvsp[-1].ast_symbol_value_element_list);
        }
#line 1620 "mcc_parser.tab.cc"
    break;

  case 19:
#line 231 "../metacc/mcc_parser.yy"
        {
                ast::mcc_string *self = new ast::mcc_string((yyvsp[0].token_str));
                (yyval.ast_symbol_value_element) = self;
        }
#line 1629 "mcc_parser.tab.cc"
    break;

  case 20:
#line 236 "../metacc/mcc_parser.yy"
        {
                ast::mcc_symbol *self = new ast::mcc_symbol((yyvsp[0].token_str));
                (yyval.ast_symbol_value_element) = self;
        }
#line 1638 "mcc_parser.tab.cc"
    break;

  case 21:
#line 241 "../metacc/mcc_parser.yy"
        {
                (yyval.ast_symbol_value_element) = (yyvsp[-1].ast_list_parameter);
        }
#line 1646 "mcc_parser.tab.cc"
    break;

  case 22:
#line 245 "../metacc/mcc_parser.yy"
        {
                (yyval.ast_symbol_value_element) = (yyvsp[-1].ast_option_parameter);
        }
#line 1654 "mcc_parser.tab.cc"
    break;

  case 23:
#line 249 "../metacc/mcc_parser.yy"
        {
                (yyval.ast_symbol_value_element) = (yyvsp[-1].ast_star_parameter);
        }
#line 1662 "mcc_parser.tab.cc"
    break;

  case 24:
#line 253 "../metacc/mcc_parser.yy"
        {
                (yyval.ast_symbol_value_element) = nullptr;
        }
#line 1670 "mcc_parser.tab.cc"
    break;

  case 25:
#line 257 "../metacc/mcc_parser.yy"
        {
                (yyval.ast_symbol_value_element) = (yyvsp[0].ast_token_definition);
        }
#line 1678 "mcc_parser.tab.cc"
    break;

  case 26:
#line 263 "../metacc/mcc_parser.yy"
        {
                ast::list_parameter *self = new ast::list_parameter((yyvsp[-2].ast_list_parameter_value), (yyvsp[0].token_str));
                (yyval.ast_list_parameter) = self;
        }
#line 1687 "mcc_parser.tab.cc"
    break;

  case 27:
#line 270 "../metacc/mcc_parser.yy"
        {
                ast::option_parameter *self = new ast::option_parameter((yyvsp[0].ast_option_parameter_value));
                (yyval.ast_option_parameter) = self;
        }
#line 1696 "mcc_parser.tab.cc"
    break;

  case 28:
#line 277 "../metacc/mcc_parser.yy"
        {
                ast::star_parameter *self = new ast::star_parameter((yyvsp[0].ast_star_parameter_value));
                (yyval.ast_star_parameter) = self;
        }
#line 1705 "mcc_parser.tab.cc"
    break;

  case 29:
#line 284 "../metacc/mcc_parser.yy"
        {
                ast::list_parameter_value *self = new ast::list_parameter_value((yyvsp[0].ast_symbol_value_list));
                (yyval.ast_list_parameter_value) = self;
        }
#line 1714 "mcc_parser.tab.cc"
    break;

  case 31:
#line 294 "../metacc/mcc_parser.yy"
        {
                ast::option_parameter_value *self = new ast::option_parameter_value((yyvsp[0].ast_symbol_value_list));
                (yyval.ast_option_parameter_value) = self;
        }
#line 1723 "mcc_parser.tab.cc"
    break;

  case 32:
#line 301 "../metacc/mcc_parser.yy"
        {
                ast::list_parameter *lp = new ast::list_parameter((yyvsp[0].ast_list_parameter_value), "");
                ast::star_parameter_value *self = new ast::star_parameter_value(lp);
                (yyval.ast_star_parameter_value) = self;
        }
#line 1733 "mcc_parser.tab.cc"
    break;

  case 33:
#line 309 "../metacc/mcc_parser.yy"
    {
        ast::token_definition *self =
			new ast::token_definition((yyvsp[-1].token_str), "");
        (yyval.ast_token_definition) = self;
    }
#line 1743 "mcc_parser.tab.cc"
    break;

  case 34:
#line 317 "../metacc/mcc_parser.yy"
    {
		ast::symbol_value_implementation *self =
			new ast::symbol_value_implementation((yyvsp[0].ast_symbol_value_initializer_list));
		(yyval.ast_symbol_value_implementation) = self;
    }
#line 1753 "mcc_parser.tab.cc"
    break;

  case 35:
#line 325 "../metacc/mcc_parser.yy"
    {
		ast::symbol_value_initializer_list *self =
			new ast::symbol_value_initializer_list();
        //self->append($1);
		//$$ = self;
    }
#line 1764 "mcc_parser.tab.cc"
    break;

  case 36:
#line 332 "../metacc/mcc_parser.yy"
    {
		(yyvsp[-1].ast_symbol_value_initializer_list)->append((yyvsp[0].ast_symbol_value_initializer));
		(yyval.ast_symbol_value_initializer_list) = (yyvsp[-1].ast_symbol_value_initializer_list);
    }
#line 1773 "mcc_parser.tab.cc"
    break;

  case 37:
#line 339 "../metacc/mcc_parser.yy"
    {
        ast::symbol_value_initializer *self = 
            new ast::symbol_value_initializer((yyvsp[0].ast_initializer_call));
		(yyval.ast_symbol_value_initializer) = self;
    }
#line 1783 "mcc_parser.tab.cc"
    break;

  case 38:
#line 347 "../metacc/mcc_parser.yy"
    {
        ast::initializer_call *self
			= new ast::initializer_call((yyvsp[0].ast_C_function_call));
		(yyval.ast_initializer_call) = self;
    }
#line 1793 "mcc_parser.tab.cc"
    break;

  case 39:
#line 356 "../metacc/mcc_parser.yy"
    {
        ast::field_initializer *self
			= new ast::field_initializer((yyvsp[-1].ast_field_declaration_list));
		(yyval.ast_field_initializer) = self;
    }
#line 1803 "mcc_parser.tab.cc"
    break;

  case 40:
#line 364 "../metacc/mcc_parser.yy"
    {
        ast::field_declaration_list *self
            = new ast::field_declaration_list();
        self->append((yyvsp[0].ast_field_declaration));
        (yyval.ast_field_declaration_list) = self;
    }
#line 1814 "mcc_parser.tab.cc"
    break;

  case 41:
#line 371 "../metacc/mcc_parser.yy"
    {
        (yyvsp[-1].ast_field_declaration_list)->append((yyvsp[0].ast_field_declaration));
		(yyval.ast_field_declaration_list) = (yyvsp[-1].ast_field_declaration_list);
    }
#line 1823 "mcc_parser.tab.cc"
    break;

  case 42:
#line 378 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1831 "mcc_parser.tab.cc"
    break;

  case 43:
#line 385 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1839 "mcc_parser.tab.cc"
    break;

  case 44:
#line 391 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1847 "mcc_parser.tab.cc"
    break;

  case 45:
#line 395 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1855 "mcc_parser.tab.cc"
    break;

  case 46:
#line 401 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1863 "mcc_parser.tab.cc"
    break;

  case 47:
#line 408 "../metacc/mcc_parser.yy"
    {
        ;
    }
#line 1871 "mcc_parser.tab.cc"
    break;

  case 48:
#line 414 "../metacc/mcc_parser.yy"
        {
		;
	}
#line 1879 "mcc_parser.tab.cc"
    break;

  case 49:
#line 420 "../metacc/mcc_parser.yy"
        {
	}
#line 1886 "mcc_parser.tab.cc"
    break;


#line 1890 "mcc_parser.tab.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 446 "../metacc/mcc_parser.yy"

int line_count = 0;

//
int
yyerror(char const *str)
{
        extern char *yytext;
        fprintf(stderr, "%4d: %s: syntax error \n", line_count, yytext);
        return 0;
}

//
int main(int argc, const char *argv[]) {
        extern int metacc_init(int, const char *[]);
        extern int metacc_main(int, const char *[]);

#ifdef YYDEBUG
        extern int yydebug;
        yydebug = 1;
#endif

        try {
            if (metacc_init(argc, argv) == 0) {
                    return metacc_main(argc, argv);
            }
            else {
                    return 0;
            }
        }
        catch (...) {
            fprintf(stderr, "ERROR OCCURRED \n");
            return 1;
        }
}






