%{
    
    #include <stdio.h>
    #include "y.tab.h"
    #include "exprtree.h"
    // #include "exprtree.c"

%}


%%

[0-9]+          {   yylval.no = makeLeafNode(atoi(yytext));
                    return NUM;
                }
"+"             {   return ADD;    }
"-"             {   return SUB;    }
"*"             {   return MUL;    }
"/"             {   return DIV;    }
"\n"            {   return END;  }
[()]            {   return *yytext;  }
.               {   printf("unknown character\n");
                    exit(1); 
                }

%%

int yywrap(void){
    return 1;
}