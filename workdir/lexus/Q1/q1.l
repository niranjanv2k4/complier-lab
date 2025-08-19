%option noyywrap

%{
    #include <stdio.h>


    int total = 0;    
%}

character   [a-zA-Z0-9]

%%

[a-zA-Z]{character}*    {   total++;
                            printf("%s ", yytext);

                        }
.                       { }

%%

int main(){
    /* yyin = fopen("input.yyin", "r"); */
    yylex();
    printf("\nTotal number of identifier: %d\n", total);
    return 0;
}