%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"

    int yyerror();
    int yylex();


    FILE *output;

    struct Gnode* list = NULL;
    int current_type;
    struct PairList* pairs = NULL;
    char* currName = NULL;

%}

%union{
    struct tnode* node;
    int type;
}

%token ADD SUB STAR DIV MOD
%token T_BEGIN T_END READ WRITE ASSGN EOL

%token IF THEN ELSE ENDIF GE LE EQ GT LT NE WHILE DO END_WHILE BREAK CONTINUE REPEAT UNTILL DECL ENDDECL INT STR PAIR DOT FIRST SECOND

%token <node> NUM ID STR_LITERAL

%type <node> program Coderegion
%type <node> IfStmt AsgnStmt OutputStmt InputStmt
%type <node> Stmt Slist expr
%type <node> WhileStmt RptUntlStmt DoWhileStmt
%type <node> IDENTIFIERS

%nonassoc GE LE EQ GT LT NE ASSGN
%left ADD SUB
%left STAR DIV MOD


%%

program     :   Declarations Coderegion             {   
                                                        $$ = $2;
                                                        createOutput($$, output);
                                                        printST(list);
                                                    }
            ;
Coderegion  :   T_BEGIN Slist T_END EOL             {   $$ = $2;    }
            ;
Slist       :   Slist Stmt                          {   $$ = createTreeNode(NODE_CONNECTOR, $1, $2);   }
            |   Stmt                                {   $$ = $1; }
            ;
Stmt        :   InputStmt                           {   $$ = $1; }
            |   OutputStmt                          {   $$ = $1; }
            |   AsgnStmt                            {   $$ = $1; }
            |   IfStmt                              {   $$ = $1; }
            |   WhileStmt                           {   $$ = $1; }
            |   BREAK EOL                           {   $$ = createControlFlowNode(NODE_BREAK); }
            |   CONTINUE EOL                        {   $$ = createControlFlowNode(NODE_CONTINUE); }
            |   RptUntlStmt                         {   $$ = $1; }
            |   DoWhileStmt                         {   $$ = $1; }
            ;
InputStmt   :   READ'('IDENTIFIERS')' EOL           {   $$ = createTreeNode(NODE_READ, $3, NULL);   }
            ;
OutputStmt  :   WRITE'(' expr ')' EOL               {   $$ = createTreeNode(NODE_WRITE, $3, NULL);     }
            ;
AsgnStmt    :   IDENTIFIERS ASSGN expr EOL          {   $$ = createTreeNode(NODE_ASSIGN, $1, $3);    }
            |   IDENTIFIERS ASSGN '&' IDENTIFIERS EOL{   
                                                        $$ = createTreeNode(NODE_ASSIGN, $1, createAddrNode($4));
                                                    }
            ;

IfStmt      :   IF '(' expr ')' THEN Slist ELSE Slist ENDIF EOL  {  $$ = createIfNode($3, $6, $8);  }
            |   IF '(' expr ')' THEN Slist ENDIF EOL             {  $$ = createIfNode($3, $6, NULL); }
            ;
WhileStmt   :   WHILE '(' expr ')' DO Slist END_WHILE EOL        {  $$ = createLoopNode(NODE_WHILE, $3, $6);   }
            ;
RptUntlStmt :   REPEAT '{' Slist '}' UNTILL '(' expr ')' EOL     {  $$ = createLoopNode(NODE_RPTUTL, $7, $3);   }
            ;
DoWhileStmt :   DO '{' Slist '}'  WHILE '(' expr ')' EOL         {  $$ = createLoopNode(NODE_DOWHILE, $7, $3);   }
            ;


Declarations:   DECL DeclList ENDDECL                                   {  }
            ;
DeclList    :   DeclList Decl                                           {  }
            |   Decl                                                    {  }
            ;
Decl        :   Type Varlist  EOL                                       {  }
            ;
Type        :   INT                                                     {   current_type = TYPE_ID_INT;  }
            |   STR                                                     {   current_type = TYPE_ID_STR;  }
            |   PAIR ID '(' INT ',' STR ')'                  {   current_type = TYPE_ID_PAIR;currName = strdup($2->varname);pairs = installPair($2->varname, TYPE_ID_INT, TYPE_ID_STR);    }
            |   PAIR ID '(' INT ',' INT ')'                  {   current_type = TYPE_ID_PAIR;currName = strdup($2->varname);pairs = installPair($2->varname, TYPE_ID_INT, TYPE_ID_INT);    }
            |   PAIR ID '(' STR ',' STR ')'                  {   current_type = TYPE_ID_PAIR;currName = strdup($2->varname);pairs = installPair($2->varname, TYPE_ID_STR, TYPE_ID_STR);    }
            |   PAIR ID '(' STR ',' INT ')'                  {   current_type = TYPE_ID_PAIR;currName = strdup($2->varname);pairs = installPair($2->varname, TYPE_ID_STR, TYPE_ID_INT);    }
            ;
Varlist     :   Varlist ',' ID                                          {   list = insert(list, $3, currName, current_type, 1, 1, false);    }
            |   Varlist ',' ID '[' NUM ']'                              {   list = insert(list, $3, currName, current_type, 1, ($5)->val, true);  }
            |   Varlist ',' ID '[' NUM ']''[' NUM ']'                   {   list = insert(list, $3, currName, current_type, ($5)->val, ($8)->val, true);  }
            |   ID                                                      {   list = insert(list, $1, currName, current_type, 1, 1, false);    }
            |   ID '[' NUM ']'                                          {   list = insert(list, $1, currName, current_type, 1, ($3)->val, true);    }
            |   ID '[' NUM ']''[' NUM ']'                               {   list = insert(list, $1, currName, current_type, ($3)->val, ($6)->val, true);   }
            |   Varlist ',' STAR ID                                  {   
                                                                            int temp = current_type==TYPE_ID_INT?TYPE_INT_PTR:TYPE_STR_PTR;
                                                                            list = insert(list, $4, currName, temp, 1, 1, false);
                                                                        }
            |   STAR ID                                                 {   
                                                                            int temp = current_type==TYPE_ID_INT?TYPE_INT_PTR:TYPE_STR_PTR;
                                                                            list = insert(list, $2, currName, temp, 1, 1, false);
                                                                        }
            ;

expr        :   expr ADD expr                       {   $$ = createTreeNode(NODE_ADD, $1, $3); }
            |   expr SUB expr                       {   $$ = createTreeNode(NODE_SUB, $1, $3); }
            |   expr STAR expr                      {   $$ = createTreeNode(NODE_MUL, $1, $3); }
            |   expr DIV expr                       {   $$ = createTreeNode(NODE_DIV, $1, $3); }
            |   expr MOD expr                       {   $$ = createTreeNode(NODE_MOD, $1, $3); }
            |   expr EQ expr                        {   $$ = createTreeNode(NODE_EQ, $1, $3); }
            |   expr NE expr                        {   $$ = createTreeNode(NODE_NE, $1, $3); }
            |   expr GT expr                        {   $$ = createTreeNode(NODE_GT, $1, $3); }
            |   expr GE expr                        {   $$ = createTreeNode(NODE_GE, $1, $3); }
            |   expr LT expr                        {   $$ = createTreeNode(NODE_LT, $1, $3); }
            |   expr LE expr                        {   $$ = createTreeNode(NODE_LE, $1, $3); }
            |   '(' expr ')'                        {   $$ = $2;    }
            |   NUM                                 {   $$ = $1;    }
            |   STR_LITERAL                         {   $$ = $1;    }
            |   IDENTIFIERS                         {   $$ = $1;    }
            ;

IDENTIFIERS :   ID                                  {   
                                                        setType(list, $1);
                                                        $$ = $1; 
                                                    }
            |   ID '[' expr ']'                     {   
                                                        setType(list, $1); 
                                                        $1 = createArrayNode($1, $3, NULL);
                                                        $$ = $1;
                                                    }
            |   ID '[' expr ']' '[' expr ']'        {   
                                                        setType(list, $1); 
                                                        $1 = createArrayNode($1, $3, $6);
                                                        $$ = $1;
                                                    }
            |   STAR ID                             {   
                                                        setType(list, $2);
                                                        $2 = createDerefNode($2);
                                                        $$ = $2;
                                                    }
            |   ID DOT FIRST                        {   setType(list, $1);  $$ = createPairNode(NODE_FIRST, $1); }
            |   ID DOT SECOND                       {   setType(list, $1);  $$ = createPairNode(NODE_SECOND, $1);    }
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