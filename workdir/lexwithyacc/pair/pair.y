%{
    #include<stdio.h>    

    int yyerror();
    int yylex();
%}

%union {
    int val;
}

%token <val> DIGIT
%type <val> num

%%

start   : 
        |  start pair '\n'    {   printf("Complete\n");   }
        ;
        ;
pair    :   num ',' num {   printf("(%d, %d)", $1, $3); }
        ;
num     : DIGIT         {   $$=$1;  }   
        ;

%%

int yyerror(){
    printf("Error");
    return 1;
}

int main(){
    yyparse();
    return 0;
}

