%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"
    #include "./typeTable/type.h"

    #include "y.tab.h"

    int yywrap(); 

%}

digit     [0-9]+
letter     [a-zA-Z]


%%

{digit}+        {   
                    yylval.node = createLeafNode(TLookup("int"), NULL, atoi(yytext), NULL);
                    return NUM; 
                }
\"[^\"]*\"      {   yylval.node = createLeafNode(TLookup("str"), NULL, 0, strdup(yytext));
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
"||"            {   return OR;  }
"&&"            {   return AND; }

"decl"          {   return DECL;    }
"enddecl"       {   return ENDDECL; }
"int"           {   return INT; }
"str"           {   return STR; }

"main"          {   return MAIN;    }
"return"        {   return RETURN;  }

"type"          {   return TYPE;    }
"endtype"       {   return ENDTYPE;    }
"alloc"         {   return ALLOC;   }
"initialize"    {   return INITIALIZE;  }
"free"          {   return FREE;    }
"null"          {   return NULL_VAL;    }

{letter}({letter}|{digit}|_)*          {   yylval.node = createLeafNode(NULL, strdup(yytext), 0, NULL); 
                    return ID;  
                }

[ \t\n]         {   }
[(){},\[\]&.]     {   return *yytext; }
.               {   }

%%

int yywrap(){
    return 1;
}
