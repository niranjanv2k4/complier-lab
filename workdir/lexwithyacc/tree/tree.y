%{
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"
    // #include "exprtree.c"

    int yyerror();
    int yylex(void);

%}


%union{
    struct tnode* no;
};

%type <no> expr start
%token DIV MUL SUB ADD END
%token <no> NUM


%left ADD SUB
%left MUL DIV

%%

start   :   expr END        {   
                                printf("result: %d\n", evaluate($1));
                                exit(1);
                            }
expr    :   expr ADD expr   {   $$ = makeOperatorNode('+', $1, $3); }
        |   expr SUB expr   {   $$ = makeOperatorNode('-', $1, $3); }
        |   expr MUL expr   {   $$ = makeOperatorNode('*', $1, $3); }
        |   expr DIV expr   {   $$ = makeOperatorNode('/', $1, $3); }
        |   '(' expr ')'    {   $$ = $2;    }
        |   NUM             {   $$ = $1;    }
        ;

%%

int yyerror(const char *err){
    printf("Error:  %s\n", err);
    return 1;
}

int main(){
    yyparse();
    return 0;
}