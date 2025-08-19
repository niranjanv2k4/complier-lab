%{
    #include <stdio.h>
%}

characters  [a-zA-Z]


%%

{characters}+   { 
                    if(yyleng==3)
                        printf("%s ", yytext); 
                }
.               {  }

%%

int yywrap(){
    return 1;
}

int main(int argc, char* argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    return 1;
}