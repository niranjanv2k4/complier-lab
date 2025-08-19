%{
    #include <stdio.h>
    int count_word;
    int count_char;
    int count_line;
%}

characters  [^ \t\n]
words {characters}+

%%

{words}     {   
                count_word++;
                count_char+=yyleng;
            }
\n          {   count_line++;   }
.           {}

%%

int yywrap(){
    return 1;
}

int main(int argc, char* argv[]){

    char* file = argv[1];
    yyin = fopen(file, "r");

    yylex();

    printf("Number of lines: %d\n", count_line);
    printf("Number of characters: %d\n", count_char);
    printf("Number of words: %d\n", count_word);

    return 1;
}