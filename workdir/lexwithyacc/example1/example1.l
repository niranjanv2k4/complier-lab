%{
    
    #include <stdio.h>
    #include "y.tab.h"

%}


%%
[a-zA-Z]        {   yylval.c = *yytext;
                    return CHARACTER;
                }
[-+*\/]         {   return *yytext; }
"\n"            {   return *yytext; }
.               {    }

%%

int yywrap(){
    return 1;
}