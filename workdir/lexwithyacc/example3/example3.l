%{
    
    #include <stdio.h>
    #include "y.tab.h"

%}

%%

[a-zA-Z]+       {   yylval.s = strdup(yytext);
                    return STR;
                }
[-+*\/]         {   return *yytext; }
[()]            {   return *yytext; }
"\n"            {   return *yytext; }
.               { }

%%

int yywrap(){
    return 1;
}