%option noyywrap
%{
    #include <stdio.h>
    int global_variable;
%}

NUMBER      [0-9]+
OP  [+\-*/=]


%%

{NUMBER}    {printf("NUMBER\n");}
{OP}    {printf("OPERATOR\n");}

%%

int main(){
    yylex();
    return 0;
}