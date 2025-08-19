%{
    
    #include <stdio.h>

    int yyerror();
    int yylex();

%}

%token DIGIT 

%left '+'
%left '*'

%%

start   :
        |   start expr '\n'       {   printf("Expression value: %d\n", $2);   }
        ;
expr    :   expr '+' expr   {   $$ = $1 + $3;   }
        |   expr '*' expr   {   $$ = $1 * $3;   }
        |   '(' expr ')'    {   $$ = $2;    }
        |   DIGIT           {   $$ = $1;    }
        ;
%%

int yyerror(){
    printf("Error\n");
    return 1;
}

int main(){
    yyparse();
    return 1;
}