%{
    #include <stdio.h>
    int count_int;
    int count_float;
%}

digit   [0-9]
number  {digit}+
float   {number}\.{number}
sign    -?

%%

{sign}{number}      { count_int++; }
{sign}{float}       { count_float++; }
[ \n\t]             {  }
.                   {  }

%%

int yywrap(){
    return 1;
}

int main(int argc, char* argv[]){
    yyin = fopen(argv[1], "r");
    yylex();

    printf("Number of integers: %d\n", count_int);
    printf("Number of float: %d\n", count_float);
    
    return 0;
}

