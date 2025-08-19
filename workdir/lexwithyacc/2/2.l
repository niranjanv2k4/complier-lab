%{
    
    #include <stdio.h>
    #include "y.tab.h"

%}

character       [a-zA-Z_]
others          [a-zA-Z_0-9]*
number          [0-9]
identifiers     {character}+{others}

%%

{identifiers}       {   return IDENT;   }
{number}+           {   return NUM;     }
"+="                {   return INR_ASSG; }
"-="                {   return SUB_ASSG;    }
"*="                {   return MUL_ASSG; }
"/="                {   return DIV_ASSG;    }
"="                 {   return ASSG;    }
"+"                 {   return ADD; }
"-"                 {   return SUB; }
"*"                 {   return MUL; }
"/"                 {   return DIV; }
"\n"                {   return NEWLINE; }
[ \t]               {   }
.                   {   }

%%

int yywrap(){
    return 1;
}