%{
    
    #include <stdio.h>

    int yyerror();
    int yylex();

%}


%union{
    int val;
    char *c;
};

%token <c> CHARACTER


%left '+' '-'
%left '*' '/'



%%

start   :  expr '\n'        {   printf("\nComplete\n");   }
        ;
expr    :   expr '+' expr   {   printf("+ ");   }
        |   expr '*' expr   {   printf("* ");   }
        |   expr '-' expr   {   printf("- ");   }
        |   expr '/' expr   {   printf("/ ");   }
        |   '(' expr ')'    { }
        |   CHARACTER       {   printf("%s ", $<c>1);  }
        ;

%%

int yyerror(const char* str){
    printf("Error : %s\n",str);
    return 1;
}

int main(){
    yyparse();
    return 0;
}