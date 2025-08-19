%{
    #include <stdio.h>
    #include <stdlib.h>

    int num_1, num_2;
%}

number_sequence [0-9]*

%%

{number_sequence}[0|2|4|6|8]    {
                                    printf("Even number [%d]\n", yyleng);
                                    return atoi(yytext);
                                }
{number_sequence}[1|3|5|7|9]    {
                                    printf("Odd number [%d]\n", yyleng);
                                    return atoi(yytext);
                                }

%%

int yywrap(){
    return 1;
}

int main(){%{
    #include <stdio.h>
    #include <stdlib.h>

    int num_1, num_2;
%}

number_sequence [0-9]*

%%

{number_sequence}[02468]    {
                                    printf("Even number [%d]\n", yyleng);
                                    return atoi(yytext);
                                }
{number_sequence}[13579]    {
                                    printf("Odd number [%d]\n", yyleng);
                                    return atoi(yytext);
                                }

%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter a even number and odd number: ");

    num_1 = yylex();
    num_2 = yylex();

    int diff = num_1-num_2;

    if(diff%2==0){
        printf("\nYour input were check for correctness.\nResult : Correct\n");
    }else {
        printf("\nYour input were check for correctness.\nResult : Incorrect\n");
    }

    return 1;
}