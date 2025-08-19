%{
    
    #include<stdio.h>
    #include "y.tab.h"

%}

%%

[0-9]+      {   
                yylval.val = atoi(yytext);
                return DIGIT;
            }
"\n"        {   return *yytext; }
.           {   return *yytext; }

%%

int yywrap(){
    return 1;
}