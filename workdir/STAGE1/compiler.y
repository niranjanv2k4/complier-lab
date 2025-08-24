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
                                printf("\n");
                                //infix($1);
                                //printf("\n");
                                postfix($1);
                                printf("\n");
                                execGen($1, output);
                                exit(0);
                            }
        ;
expr    :   expr ADD expr   {   $$ = createInternalNode('+', $1, $3); }
        |   expr SUB expr   {   $$ = createInternalNode('-', $1, $3); }
        |   expr MUL expr   {   $$ = createInternalNode('*', $1, $3); }
        |   expr DIV expr   {   $$ = createInternalNode('/', $1, $3); }
        |   '(' expr ')'    {   $$ = $2;    }
        |   SUB expr        {   struct tnode* temp = createLeafNode(0);
                                $$ = createInternalNode('-', temp, $2);
                            }
        |   ADD expr        {   $$ = $2;    }
        |   NUM             {   $$ = $1;    }
        ;
        
%%

extern FILE* yyin;

int yyerror(const char* s){
    printf("Error: %s\n", s);
    return 1;
}

int main(int argc, char **argv){

    /* if(argc > 0){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Error opening file\n");
            return 1;
        }
    } */

    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}