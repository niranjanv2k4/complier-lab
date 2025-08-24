%{
    #include <stdio.h>
    #include <stdlib.h>

    int nested_level = 0;    

    void yyerror(const char *);
    int yylex();

%}

%token IF LBRACE RBRACE CL_BRACE RL_BRACE

%%

start   :   valid                       {   printf("Nesting level = %d\n", nested_level);
                                            exit(0);
                                        }
valid   : IF LBRACE  RBRACE CL_BRACE Stmt RL_BRACE     {   nested_level++; } 
        ;
Stmt    :   valid
        |
        ;

%%

void yyerror(const char* s){
    printf("Error\n");
}

int yylex(void) {
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') continue;

        if (c == '(') return LBRACE;
        if (c == ')') return RBRACE;
        if (c == '{') return CL_BRACE;
        if (c == '}') return RL_BRACE;

        if (c == 'i') {
            char d = getchar();
            if (d == 'f') return IF;
            ungetc(d, stdin);
        }
    }
    return 0;
}

int main(int argc, char* argv[]){
    yyparse();
    return 1;
}