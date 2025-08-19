%{
    #include <stdio.h>

    int nested_level = 0;    

    void yyerror(const char *);
    int yylex();

%}

%token IF

%%

expr : IF '(' expr ')'      { nested_level++; } 

%%

int yyerror(){
    printf("Error\n");
}

int yylex(){

}

int main(){
    yyparse();
    return 1;
}