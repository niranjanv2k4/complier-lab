%{
    
    #include <stdio.h>
    #include "y.tab.h"
    #include "exprtree.h"

    int yywrap(); 

%}

numbers     [0-9]+


%%

{numbers}       {   yylval.node = createLeafNode(atoi(yytext));
                    return NUM; }
"+"             {   return ADD;    }
"-"             {   return SUB;    }
"*"             {   return MUL;    }
"/"             {   return DIV;    }
[ \t]           {   }
[\n()]          {   return *yytext; }
.               {   }

%%

int yywrap(){
    return 1;
}
