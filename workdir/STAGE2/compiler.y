%{
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "tree.h"
    #include "exec.h"

    int yyerror();
    int yylex();


    FILE *output;

%}

%union{
    struct tnode* node;
}

%token ADD SUB MUL DIV
%token T_BEGIN T_END READ WRITE ASSGN SEMI_COLON

%token <node> NUM ID

%type <node> expr AsgnStmt OutputStmt InputStmt Stmt Slist



%left ADD SUB
%left MUL DIV


%%

program     :   T_BEGIN Slist T_END SEMI_COLON      {   createOutput($2, output); 
                                                        evaluator($2);
                                                    }
            ;
Slist       :   Slist Stmt                          {   $$ = createConnecterNode($1, $2);   }
            |   Stmt                                {   $$ = $1; }
            ;
Stmt        :   InputStmt                           {   $$ = $1; }
            |   OutputStmt                          {   $$ = $1; }
            |   AsgnStmt                            {   $$ = $1; }
            ;
InputStmt   :   READ'('ID')' SEMI_COLON             {   $$ = createReadNode($3);   }
            ;
OutputStmt  :   WRITE'(' expr ')' SEMI_COLON        {   $$ = createWriteNode($3);     }
            ;
AsgnStmt    :   ID ASSGN expr SEMI_COLON            {   $$ = createAssignNode($1, $3);    }
            ;
expr        :   expr ADD expr                       {   $$ = createOperatorNode(NODE_ADD, $1, $3); }
            |   expr SUB expr                       {   $$ = createOperatorNode(NODE_SUB, $1, $3); }
            |   expr MUL expr                       {   $$ = createOperatorNode(NODE_MUL, $1, $3); }
            |   expr DIV expr                       {   $$ = createOperatorNode(NODE_DIV, $1, $3); }
            |   '(' expr ')'                        {   $$ = $2;    }
            |   NUM                                 {   $$ = $1;    }
            |   ID                                  {   $$ = $1;    }
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
            return 1;
        }
    }

    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}