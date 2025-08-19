%option noyywrap

%{
    #include <stdio.h>
    #define ID 1
    #define ER 2
%}

digit   [0-9]
low     [a-z]
high    [A-Z]


%%

({low}|{high})({low}|{high})*({digit})    return ID;
.*                                        return ER;

%%

int main(){
    int token = yylex();
    if(token==1){
        printf("Acceptable\n");
    }else{
        printf("Unacceptable\n");
    }
    return 1;
}