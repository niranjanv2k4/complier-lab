%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"

    #include "y.tab.h"

    int yywrap(); 

%}

numbers     [0-9]+


%%

{numbers}       {   yylval.node = createLeafNode(TYPE_INT, NULL, atoi(yytext)); 
                    return NUM; 
                }
[a-z]           {   yylval.node = createLeafNode(TYPE_ID_INT, strdup(yytext), 0); 
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

"if"            {   return IF;  }
"then"          {   return THEN;    }
"else"          {   return ELSE;    }
"endif"         {   return ENDIF;   }

"while"         {   return WHILE;   }
"do"            {   return DO;  }
"endwhile"      {   return END_WHILE;    }

"break"         {   return BREAK;   }
"continue"      {   return CONTINUE;    }

"repeat"        {   return REPEAT;  }
"until"         {   return UNTILL;  }

"<="            {   return LE;  }
">="            {   return GE;  }
"=="            {   return EQ;  }
"!="            {   return NE;  }
"<"             {   return LT;  }
">"             {   return GT;  }

[ \t\n]         {   }
[(){}]          {   return *yytext; }
.               {   }

%%

int yywrap(){
    return 1;
}
