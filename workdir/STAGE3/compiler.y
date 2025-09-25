%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"

    int yyerror();
    int yylex();


    FILE *output;

%}

%union{
    struct tnode* node;
}

%token ADD SUB MUL DIV
%token T_BEGIN T_END READ WRITE ASSGN SEMI_COLON

%token IF THEN ELSE ENDIF GE LE EQ GT LT NE WHILE DO END_WHILE BREAK CONTINUE REPEAT UNTILL

%token <node> NUM ID

%type <node> IfStmt AsgnStmt OutputStmt InputStmt Stmt Slist expr WhileStmt RptUntlStmt DoWhileStmt

%left ADD SUB
%left MUL DIV
%nonassoc GE LE EQ GT LT NE ASSGN


%%

program     :   T_BEGIN Slist T_END SEMI_COLON      {   createOutput($2, output);
                                                        evaluator($2);
                                                    }
            ;
Slist       :   Slist Stmt                          {   $$ = createTreeNode(NODE_CONNECTOR, $1, $2);   }
            |   Stmt                                {   $$ = $1; }
            ;
Stmt        :   InputStmt                           {   $$ = $1; }
            |   OutputStmt                          {   $$ = $1; }
            |   AsgnStmt                            {   $$ = $1; }
            |   IfStmt                              {   $$ = $1; }
            |   WhileStmt                           {   $$ = $1; }
            |   BREAK SEMI_COLON                    {   $$ = createControlFlowNode(NODE_BREAK); }
            |   CONTINUE SEMI_COLON                 {   $$ = createControlFlowNode(NODE_CONTINUE); }
            |   RptUntlStmt                         {   $$ = $1; }
            |   DoWhileStmt                         {   $$ = $1; }
            ;
InputStmt   :   READ'('ID')' SEMI_COLON             {   $$ = createTreeNode(NODE_READ, $3, NULL);   }
            ;
OutputStmt  :   WRITE'(' expr ')' SEMI_COLON        {   $$ = createTreeNode(NODE_WRITE, $3, NULL);     }
            ;
AsgnStmt    :   ID ASSGN expr SEMI_COLON            {   $$ = createTreeNode(NODE_ASSIGN, $1, $3);    }
            ;
IfStmt      :   IF '(' expr ')' THEN Slist ELSE Slist ENDIF SEMI_COLON   {  $$ = createIfNode($3, $6, $8);  }
            |   IF '(' expr ')' THEN Slist ENDIF SEMI_COLON              {  $$ = createIfNode($3, $6, NULL); }
            ;
WhileStmt   :   WHILE '(' expr ')' DO Slist END_WHILE SEMI_COLON         {  $$ = createLoopNode(NODE_WHILE, $3, $6);   }
            ;
RptUntlStmt :   REPEAT '{' Slist '}' UNTILL '(' expr ')' SEMI_COLON      {  $$ = createLoopNode(NODE_RPTUTL, $7, $3);   }
            ;
DoWhileStmt :   DO '{' Slist '}'  WHILE '(' expr ')' SEMI_COLON          {  $$ = createLoopNode(NODE_DOWHILE, $7, $3);   }
            ;
expr        :   expr ADD expr                         {   $$ = createTreeNode(NODE_ADD, $1, $3); }
            |   expr SUB expr                         {   $$ = createTreeNode(NODE_SUB, $1, $3); }
            |   expr MUL expr                         {   $$ = createTreeNode(NODE_MUL, $1, $3); }
            |   expr DIV expr                         {   $$ = createTreeNode(NODE_DIV, $1, $3); }
            |   expr EQ expr                          {   $$ = createTreeNode(NODE_EQ, $1, $3); }
            |   expr NE expr                          {   $$ = createTreeNode(NODE_NE, $1, $3); }
            |   expr GT expr                          {   $$ = createTreeNode(NODE_GT, $1, $3); }
            |   expr GE expr                          {   $$ = createTreeNode(NODE_GE, $1, $3); }
            |   expr LT expr                          {   $$ = createTreeNode(NODE_LT, $1, $3); }
            |   expr LE expr                          {   $$ = createTreeNode(NODE_LE, $1, $3); }
            |   '(' expr ')'                          {   $$ = $2;    }
            |   NUM                                   {   $$ = $1;    }
            |   ID                                    {   $$ = $1;    }
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