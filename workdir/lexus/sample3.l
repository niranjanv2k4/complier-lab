%option noyywrap
%{
    #include <stdio.h>
%}

%%
"--"        { printf("%s(DECREMENT)\n", yytext);}
"-"         { printf("%s(MINUS)\n", yytext);}
%%

int main(){
    yylex();
    return 1;
}