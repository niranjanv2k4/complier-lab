%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex();
    int yyerror(const char* s);
%}

%token DIGIT NEWLINE
%left '+'
%left '-'

%%

start : expr NEWLINE    {   
                            printf("complete\n");
                            exit(1);
                        }
     ;
expr : expr '+' expr    {   printf("+ ");    }
     | expr '-' expr    {   printf("- ");    }
     | '(' expr ')'     { }
     | DIGIT            {   printf("%d ", $1); }
     ;

%%

int yyerror(const char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    yyparse();
    return 1;
}