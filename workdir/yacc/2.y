%{
#include <stdio.h>
#include <ctype.h>

int yylex(void);
int yyerror(const char *s);

%}

%token ID

%%

start   : ID { printf("Valid variable\n"); }
        ;

%%

int yylex(void) {
    int c = getchar();
    if (isalpha(c)) {
        while (isalnum(c = getchar())) ;
        ungetc(c, stdin);
        return ID;
    }
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}

int main() {
    return yyparse();
}
