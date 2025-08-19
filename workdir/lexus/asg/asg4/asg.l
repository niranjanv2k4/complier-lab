%{
    #include <stdio.h>
%}

%%


\/\/[^\n]*                          { printf("Single line : %s\n", yytext); }
"/*"([^*]|\*+[^/])*"\*/"            { printf("Multi Line : %s\n", yytext); }
[ \t\n]                             { }
.                                   { }


%%

int yywrap(){
    return 1;
}

int main(){
    yyin = fopen("input.yyin", "r");
    yylex();
    return 1;
}