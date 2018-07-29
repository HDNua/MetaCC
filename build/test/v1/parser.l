%{
#define MAX_TOKEN_LEN 2048

#include <stdio.h>
#include "y.tab.h"


#ifdef YYDEBUG
extern int yydebug;
#endif

extern int line_count;

int
yywrap(void)
{
    return 1;
}



%}



%%



";" return TOKEN_0;
"+" return TOKEN_1;
"-" return TOKEN_2;
"*" return TOKEN_3;
"/" return TOKEN_4;
"(" return TOKEN_5;
")" return TOKEN_6;
"INTEGER" return INTEGER;
