%{
    
    #include <stdio.h>
    #include "y.tab.h"
    #include "tree.h"

    int yywrap(); 

%}

numbers     [0-9]+


%%

{numbers}       {   yylval.node = createLeafNode(TYPE_INT, NULL, atoi(yytext)); 
                    return NUM; 
                }
[a-z]           {   yylval.node = createLeafNode(TYPE_ID, strdup(yytext), 0); 
                    return ID;  
                }
"+"             {   return ADD;    }
"-"             {   return SUB;    }
"*"             {   return MUL;    }
"/"             {   return DIV;    }
"="             {   return ASSGN;   }
";"             {   return SEMI_COLON;  }
"begin"         {   return T_BEGIN;   }
"end"           {   return T_END; }
"read"          {   return READ;    }
"write"         {   return WRITE;   }
[ \t\n]         {   }
[()]            {   return *yytext; }
.               {   }

%%

int yywrap(){
    return 1;
}
