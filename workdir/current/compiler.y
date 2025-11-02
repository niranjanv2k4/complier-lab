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
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;

%}

%union{
    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
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
%token TYPE ENDTYPE ALLOC INITIALIZE FREE NULL_VAL

%token  RETURN

%token <node> NUM ID STR_LITERAL

%type <node> WhileStmt DoWhileStmt RptUntlStmt IfStmt
%type <node> Fdef 
%type <node> Stmt Slist expr
%type <node> AsgnStmt OutputStmt InputStmt
%type <node> Coderegion RtnStmt
%type <node> IDENTIFIERS
%type <node> UserDef
%type <parameter> Param ParamList
%type <fieldlist> FieldDeclList FieldDecl

%type <node> ArgList;

%type <localSymbolTable> IdList

%right ASSGN              
%left OR                  
%left AND                  
%nonassoc EQ NE GT GE LT LE
%left ADD SUB           
%left STAR DIV MOD  

%nonassoc '.'
%right '&'

%%

program     :   TypeDefBlock GDeclBlock FDefBlock MainBlock  {   exitProg(output);  }
            |   TypeDefBlock GDeclBlock MainBlock            {   exitProg(output);  }
            |   TypeDefBlock MainBlock                       {   exitProg(output);  }
            ;
     
/* -------------------------------------------------------------------------------------------------- */

TypeDefBlock    :   TYPE TypeDefList ENDTYPE
                |                                                
                ;

TypeDefList     :   TypeDefList TypeDef
                |   TypeDef
                ;

TypeDef         :   ID  { TInstall($1->name, 0, NULL, TYPE_USERDEF); } '{' FieldDeclList '}'   {   updateUserDefined($1->name, $4); }
                ;

FieldDeclList   :   FieldDeclList FieldDecl       {   $$ = appendField($1, $2);   }
                |   FieldDecl                     {   $$ = $1; }
                ;

FieldDecl       :   TypeName ID EOL               {   $$ = createField(current_type, $2); }
                ;
TypeName        :   INT                           {   current_type = TLookup("int"); }
                |   STR                           {   current_type = TLookup("str"); }
                |   ID                            {   current_type = TLookup($1->name);  }
                ;

/* -------------------------------------------------------------------------------------------------- */

GDeclBlock  :   DECL GDeclList ENDDECL          {   }
            |   DECL ENDDECL                    {   }
            ;
GDeclList   :   GDeclList GDecl
            |   GDecl
GDecl       :   Type GidList EOL                {  }
            ;
Type        :   INT                             {   current_type = TLookup("int");      }
            |   STR                             {   current_type = TLookup("str");      }
            |   ID                              {   current_type = TLookup($1->name);   }
            ;
GidList     :   GidList ',' Gid
            |   Gid
            ;
Gid         :   ID                              {   GST = insertToGlobal($1, current_type, 1, 0, 0,NULL, NODE_ID, false);    }
            |   STAR ID                         {   GST = insertToGlobal($2, current_type, 1, 0, 0, NULL, NODE_ID, true);    }
            |   ID '[' NUM ']'                  {   GST = insertToGlobal($1, current_type, $3->value.intVal, 1, $3->value.intVal, NULL, NODE_ID, false);   }
            |   ID '(' ParamList ')'            {   GST = insertToGlobal($1, current_type, 0, 0, 0, $3, NODE_FUNCT,false);  
                                                    clearLST();  
                                                }
            ;

/* ------------------------------------------------------------------------------- */
FDefBlock   :   FDefBlock Fdef                  {      }
            |   Fdef                            {      }
            ;
Fdef        :   INT ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("int"), $2, $4, $8); 
                                                                                // printLST($2->name);
                                                                                generateFunct(output, $2, $8);
                                                                                clearLST();  
                                                                            }
            |   STR ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup("str"), $2, $4, $8);    
                                                                                // printLST($2->name);
                                                                                generateFunct(output, $2, $8);
                                                                                clearLST();  
                                                                            }
            |   ID  ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                setHeader(output);  
                                                                                validateFunct(TLookup($1->name), $2, $4, $8);    
                                                                                // printLST($2->name);
                                                                                generateFunct(output, $2, $8);
                                                                                clearLST();  
                                                                            }
            ;

/* --------------------------------------------------------------------------------- */

MainBlock   :   INT MAIN '('')' '{' LDeclBlock Coderegion '}'               {   
                                                                                setHeader(output);  
                                                                                validateMain($7);
                                                                                // printLST("MAIN");
                                                                                generateFunct(output, NULL, $7);
                                                                                clearLST();
                                                                            }
            ;

/* --------------------------------------------------------------------------------- */

ParamList   :   ParamList ',' Param     {   $$ = appendParam($1, $3); }
            |   Param                   {   $$ = $1; }
            |                           {   $$ = NULL; }
            ;
Param       :   INT ID                  {   $$ = createParam("int", $2, false);   }
            |   STR ID                  {   $$ = createParam("str", $2, false);   }
            |   INT STAR ID             {   $$ = createParam("int", $3, true);   }
            |   STR STAR ID             {   $$ = createParam("str", $3, true);   }
            |   ID STAR ID              {   $$ = createParam($1->name, $3, true);  }
            |   ID ID                   {   $$ = createParam($1->name, $2, false); }
            ;

/* ------------------------------------------------------------------------------------ */

LDeclBlock  :   DECL LDeclList ENDDECL              {  }
            |
            |   DECL ENDDECL
            ;
LDeclList   :   LDeclList LDecl                     {  }
            |   LDecl                               {  }
            ;
LDecl       :   Type IdList  EOL                    {  }
            ;
IdList      :   IdList ',' ID                       {   LST = createLST($3, current_type, false);   }
            |   ID                                  {   LST = createLST($1, current_type, false);   }
            |   IdList ',' STAR ID                  {   LST = createLST($4, current_type, true);   }
            |   STAR ID                             {   LST = createLST($2, current_type, true);    }
            ;   

/* ---------------------------------------------------------------------------------- */

Coderegion  :   T_BEGIN Slist RtnStmt T_END         {   $$ = createTreeNode(NODE_CONNECTOR, $2, $3);    }
            ;
RtnStmt     :   RETURN expr EOL                     {   $$ = createRtnNode($2); }
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
            |   FREE '(' IDENTIFIERS ')' EOL        {   $$ = createDynamicNode(NODE_FREE, $3);  }
            ;
InputStmt   :   READ'('IDENTIFIERS')' EOL           {   $$ = createTreeNode(NODE_READ, $3, NULL);   }
            ;
OutputStmt  :   WRITE'(' expr ')' EOL               {   $$ = createTreeNode(NODE_WRITE, $3, NULL);     }
            ;
AsgnStmt    :   IDENTIFIERS ASSGN expr EOL          {   $$ = createTreeNode(NODE_ASSIGN, $1, $3);    }
            |   IDENTIFIERS ASSGN ALLOC '('')' EOL  {   $$ = createDynamicNode(NODE_ALLOC, $1);  }
            |   IDENTIFIERS ASSGN INITIALIZE '('')' EOL  {   $$ = createDynamicNode(NODE_INITIALIZE, NULL);  }
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
            |   STR_LITERAL                         {   $$ = $1;   }
            |   ID '(' ArgList ')'                  {   $$ = createFunctNode($1, $3);   }
            |   IDENTIFIERS                         {   $$ = $1;    }
            |   NULL_VAL                            {   $$ = createDynamicNode(NODE_NULL, NULL);    }
            ;
ArgList     :   ArgList ',' expr                    {   $$ = appendArgNode($1, $3); }
            |   expr                                {   $$ = $1; }
            |                                       {   $$ = NULL;  }
            ;

IDENTIFIERS :   ID                                  {   setType($1); $$ = $1; }
            |   ID '[' expr ']'                     {   $$ = createArrayNode($1, NULL, $3); }
            |   STAR ID                             {   $$ = createDerefNode($2); }
            |   '&' ID                              {   $$ = createAddrNode($2); }
            |   '(' expr  ')' '.' ID                {   $$ = createFieldAccessNode($2, $5); }
            |   UserDef                             {   $$ = $1;    }
UserDef     :   UserDef '.' ID                      {   $$ = createFieldAccessNode($1, $3);  }
            |   ID '.' ID                           {   $$ = createFieldAccessNode($1, $3); }
            |   ID '[' expr ']' '.' ID              {   $$ = createFieldAccessNode(createArrayNode($1, NULL, $3), $6); }
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
    printGST();
    fclose(output);
    return 0;
}