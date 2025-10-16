%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"
    #include "./typeTable/type.h"

    int yyerror();
    int yylex();


    FILE *output;

    struct GSymbol* GST = NULL;
    struct param* paramlist = NULL;
    struct LSymbol* LST = NULL;

    struct Typetable* current_type;

    bool isFirst = true;

%}

%union{
    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    int type;
}

%token ADD SUB STAR DIV MOD
%token T_BEGIN T_END READ WRITE ASSGN EOL

%token IF THEN ELSE ENDIF 
%token GE LE EQ GT LT NE 
%token WHILE DO END_WHILE BREAK CONTINUE REPEAT UNTILL 
%token DECL ENDDECL 
%token INT STR
%token MAIN

%token  RETURN

%token <node> NUM ID STR_LITERAL

%type <node> WhileStmt DoWhileStmt RptUntlStmt IfStmt
%type <node> Fdef 
%type <node> Stmt Slist expr
%type <node> AsgnStmt OutputStmt InputStmt
%type <node> Coderegion RtnStmt
%type <node> IDENTIFIERS
%type <parameter> Param ParamList

%type <node> ArgList;

%type <localSymbolTable> IdList

%right ASSGN              
%left OR                  
%left AND                  
%nonassoc EQ NE GT GE LT LE
%left ADD SUB           
%left STAR DIV MOD  




%%

program     :   GDeclBlock FDefBlock MainBlock  {   
                                                    printf("Success\n");
                                                    exitProg(output);
                                                    printGST();  
                                                }
            |   FDefBlock MainBlock             {   
                                                    printf("Success\n");
                                                    exitProg(output);
                                                    printGST();  
                                                }
            |   GDeclBlock MainBlock            {   
                                                    printf("Success\n");
                                                    exitProg(output);
                                                    printGST();  
                                                }
            |   MainBlock                       {
                                                    printf("Success\n");
                                                    exitProg(output);
                                                    printGST();  
                                                }
            ;

GDeclBlock  :   DECL GDeclList ENDDECL          {   setHeader(output);  }
            |   DECL ENDDECL                    {   }
            ;
GDeclList   :   GDeclList GDecl
            |   GDecl
GDecl       :   Type GidList EOL                {   }
            ;
GidList     :   GidList ',' Gid
            |   Gid
            ;
Type        :   INT                             {   current_type = TLookup("int");    }
            |   STR                             {   current_type = TLookup("str");    }
            ;
Gid         :   ID                              {   GST = insertToGlobal($1, current_type, 1, 1,NULL, NODE_ID);    }
            |   ID '[' NUM ']'                  {   GST = insertToGlobal($1, current_type, 1, $3->value.intVal, NULL, NODE_ID); }
            |   ID '(' ParamList ')'            {   GST = insertToGlobal($1, current_type, 1, 1, $3, NODE_FUNCT);LST = NULL;    }
            ;

/* ------------------------------------------------------------------------------- */
FDefBlock   :   FDefBlock Fdef                  {      }
            |   Fdef                            {      }
            ;
Fdef        :   INT ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                validateFunct(TLookup("int"), $2, $4, $8); 
                                                                                printf("FUNCTION - %s\n", $2->name);
                                                                                printLST(LST);
                                                                                generateFunct(output, $2, $8);
                                                                                LST = NULL;
                                                                            }
            |   STR ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                validateFunct(TLookup("str"), $2, $4, $8);    
                                                                                printf("FUNCTION - %s\n", $2->name);
                                                                                generateFunct(output, $2, $8);
                                                                                printLST(LST);
                                                                                LST = NULL;
                                                                            }
            ;
ParamList   :   ParamList ',' Param     {   $$ = appendParam($1, $3); }
            |   Param                   {   $$ = $1; }
            |                           {   $$ = NULL; }
            ;

Param       :   INT ID                 {   
                                            $$ = createParam(TLookup("int"), $2);  
                                            LST = addParamtoLST($$);
                                        }
            |   STR ID                  {
                                            $$ = createParam(TLookup("str"), $2);  
                                            LST = addParamtoLST($$);
                                        }
            ;

/* --------------------------------------------------------------------------------- */

MainBlock   :   INT MAIN '('')' '{' LDeclBlock Coderegion '}'   {   
                                                                    validateMain($7);
                                                                    printf("FUNCTION - MAIN\n");
                                                                    generateFunct(output, NULL, $7);
                                                                    printLST(LST);
                                                                    LST = NULL;
                                                                   }
            ;

/* --------------------------------------------------------------------------------- */

LDeclBlock  :   DECL LDeclList ENDDECL                          {  }
            |
            |   DECL ENDDECL
            ;
LDeclList   :   LDeclList LDecl                                 {  }
            |   LDecl                                           {  }
            ;
LDecl       :   Type IdList  EOL                                {  }
            ;
IdList      :   IdList ',' ID                                   {   LST = createLST($3, current_type);   }
            |   ID                                              {   LST = createLST($1, current_type);   }
            ;   

/* ---------------------------------------------------------------------------------- */

Coderegion  :   T_BEGIN Slist RtnStmt T_END         {   $$ = createTreeNode(NODE_CONNECTOR, $2, $3);    }
            ;
RtnStmt     :   RETURN expr EOL                     {   
                                                        $$ = createRtnNode($2);
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
            |   BREAK EOL                           {   $$ = createControlFlowNode(NODE_BREAK); }
            |   CONTINUE EOL                        {   $$ = createControlFlowNode(NODE_CONTINUE); }
            |   RptUntlStmt                         {   $$ = $1; }
            |   DoWhileStmt                         {   $$ = $1; }
            ;
InputStmt   :   READ'('IDENTIFIERS')' EOL               {   $$ = createTreeNode(NODE_READ, $3, NULL);   }
            ;
OutputStmt  :   WRITE'(' expr ')' EOL                   {   $$ = createTreeNode(NODE_WRITE, $3, NULL);     }
            ;
AsgnStmt    :   IDENTIFIERS ASSGN expr EOL              {   $$ = createTreeNode(NODE_ASSIGN, $1, $3);    }
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
            |   expr OR expr                        {   $$ = createTreeNode(NODE_OR, $1, $3); }
            |   expr AND expr                       {   $$ = createTreeNode(NODE_AND, $1, $3); }
            |   '(' expr ')'                        {   $$ = $2;    }
            |   NUM                                 {   $$ = $1;    }
            |   STR_LITERAL                         {   $$ = $1;    }
            |   ID '(' ArgList ')'                  {   
                                                        setType($1);
                                                        $$ = createFunctNode($1, $3); 
                                                    }
            |   IDENTIFIERS                         {   $$ = $1;    }
            ;

IDENTIFIERS :   ID                                  {   
                                                        setType($1);
                                                        $$ = $1;    
                                                    }
            |   ID '[' expr ']'                     {   
                                                        setType($1);
                                                        $$ = createArrayNode($1, NULL, $3); 
                                                    }
            ;
ArgList     :   ArgList ',' expr                    {   $$ = appendArgNode($1, $3); }
            |   expr                                {   $$ = $1; }
            |                                       {   $$ = NULL; }
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
    TypeTableCreate();
    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}