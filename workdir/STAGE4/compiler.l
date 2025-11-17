%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"

    #include "y.tab.h"

    int yywrap(); 

%}

digit     [0-9]+
letter     [a-zA-Z]


%%

{digit}+       {   yylval.node = createLeafNode(TYPE_INT, NULL, atoi(yytext), NULL); 
                    return NUM; 
                }
\"[^\"]*\"      {   yylval.node = createLeafNode(TYPE_STR, NULL, 0, strdup(yytext));
                    return STR_LITERAL;
                }
"+"             {   return ADD;    }
"-"             {   return SUB;    }
"%"             {   return MOD;    }
"*"             {   return STAR;   }
"/"             {   return DIV;    }
"="             {   return ASSGN;   }

";"             {   return EOL;  }
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
"untill"        {   return UNTILL;  }

"<="            {   return LE;  }
">="            {   return GE;  }
"=="            {   return EQ;  }
"!="            {   return NE;  }
"<"             {   return LT;  }
">"             {   return GT;  }

"decl"          {   return DECL;    }
"enddecl"       {   return ENDDECL; }
"int"           {   return INT; }
"str"           {   return STR; }
"pair"          {   return PAIR;    }
"first"         {   return FIRST;   }
"second"        {   return SECOND;  }
"."             {   return DOT; }

{letter}({letter}|{digit})*          {   yylval.node = createLeafNode(NO_TYPE, strdup(yytext), 0, NULL); 
                    return ID;  
                }

[ \t\n]         {   }
[(){},\[\]&]     {   return *yytext; }
.               {   }

%%

int yywrap(){
    return 1;
}
