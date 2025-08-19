%option noyywrap
%{
    #include <stdio.h>
%}

IDENT   [a-zA-Z_][a-zA-Z0-9_]*
NUMBER  [0-9]+
OP      [+\-*/=]


%%

{IDENT}     { printf("%s(IDENTIFIER) ", yytext) ;}
{NUMBER}    { printf("%s(NUMBER) ", yytext) ;}
{OP}        { printf("%s(OPERATOR) ", yytext) ;}
[ \t\n]+    { printf("%s", yytext); }
.           { }
%%

int main(int argc, char* argv[]){
    if(argc>1){
        FILE* fp = fopen(argv[1], "r");
        if(fp)yyin = fp;
    }
    yylex();
    return 0;
}