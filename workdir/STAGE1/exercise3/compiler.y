%{
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"

    int yyerror();
    int yylex();


    FILE *output;

%}

%union{
    struct tnode* node;
}

%token ADD SUB MUL DIV
%token <node> NUM
%type <node> expr start

%left ADD SUB
%left MUL DIV


%%

start   :   expr            {   printf("Result: %d\n", calc($1));
                                prefix($1);
                                //printf("\n");
                                //infix($1);
                                printf("\n");
                                postfix($1);
                                printf("\n");
                                execGen($1, output);
                                exit(0);
                            }
        ;
expr    :   ADD expr expr   {   $$ = createInternalNode('+', $2, $3); }
        |   SUB expr expr   {   $$ = createInternalNode('-', $2, $3); }
        |   MUL expr expr   {   $$ = createInternalNode('*', $2, $3); }
        |   DIV expr expr   {   $$ = createInternalNode('/', $2, $3); }
        |   NUM             {   $$ = $1;    }
        ;
        
%%

extern FILE* yyin;

int yyerror(const char* s){
    printf("Error: %s\n", s);
    return 1;
}

int main(int argc, char **argv){

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Error opening file\n");
        }else{
            yyin = stdin;
        }
    }

    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}