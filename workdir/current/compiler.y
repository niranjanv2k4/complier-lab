%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"
    #include "./typeTable/type.h"
    #include "./classTable/class.h"

    int yyerror();
    int yylex();

    FILE *output;

    struct GSymbol* GST = NULL;
    struct LSymbol* LST = NULL;
    struct Typetable* current_type;
    struct Classtable* current_class;

    bool isInsideClass = false;

    char* Ldatatype = NULL;


%}

%union{
    struct ASTNode* node;
    struct param* parameter;
    struct LSymbol* localSymbolTable;
    struct Arglist* Args;
    struct Fieldlist* fieldlist;
    char* string;
    int type;
}


%token ADD SUB STAR DIV MOD
%token T_BEGIN T_END READ WRITE ASSGN EOL

%token IF THEN ELSE ENDIF 
%token GE LE EQ GT LT NE 
%token WHILE DO END_WHILE BREAK CONTINUE REPEAT UNTILL 
%token DECL ENDDECL 
%token <string> INT STR ID
%token MAIN
%token TYPE ENDTYPE ALLOC INITIALIZE FREE NULL_VAL
%token CLASS ENDCLASS EXTENDS NEW DELETE SELF

%token  RETURN

%token <node> NUM STR_LITERAL

%type <node> WhileStmt DoWhileStmt RptUntlStmt IfStmt
%type <node> Fdef 
%type <node> Stmt Slist expr
%type <node> AsgnStmt OutputStmt InputStmt
%type <node> Coderegion RtnStmt
%type <node> IDENTIFIERS
%type <parameter> Param ParamList
%type <fieldlist> FieldDeclList FieldDecl
%type <string> Type

%type <node> ArgList;

%type <localSymbolTable> IdList

%right ASSGN              
%left OR                  
%left AND                  
%nonassoc EQ NE GT GE LT LE
%left ADD SUB           
%left STAR DIV MOD  


%nonassoc '('
%left '.'

%%

program     :   TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock  {   exitProg(output);PrintClassTable();  }
            |   TypeDefBlock ClassDefBlock GDeclBlock MainBlock            {   exitProg(output);PrintClassTable();  }
            |   TypeDefBlock ClassDefBlock MainBlock                       {   exitProg(output);PrintClassTable();  }
            ;

/* --------------------------------------------------------------------------------------------------- */

ClassDefBlock   : CLASS { isInsideClass = true;  } ClassDefList  {  isInsideClass = false;  }ENDCLASS
                |
                ;
ClassDefList    : ClassDefList ClassDef
                | ClassDef
                ;
ClassDef        : Cname '{'DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'   
                ;
Cname           : ID       	                                                {   current_class = CInstall($1, NULL);}         
                | ID EXTENDS ID	                                            {   current_class = CInstall($1, $3);}
                ;
Fieldlists 	    : Fieldlists Fld   
		        |
                ;     
Fld             : Type ID EOL		                                        {   ClassFInstall(current_class, $1, $2);} 
                ;
MethodDecl      : MethodDecl MDecl 
	            | MDecl 
                ;       
MDecl           : Type ID '(' ParamList ')' EOL                             {   ClassMInstall(current_class, $1, $2, $4);clearLST(); } 
                ;
MethodDefns     : MethodDefns Fdef
                | Fdef
                ;

/* -------------------------------------------------------------------------------------------------- */

TypeDefBlock    :   TYPE TypeDefList ENDTYPE
                |                                                
                ;

TypeDefList     :   TypeDefList TypeDef
                |   TypeDef
                ;

TypeDef         :   ID  { TInstall($1, 0, NULL, TYPE_USERDEF); } '{' FieldDeclList '}'   {   updateUserDefined($1, $4); }
                ;

FieldDeclList   :   FieldDeclList FieldDecl       {   $$ = appendField($1, $2);   }
                |   FieldDecl                     {   $$ = $1; }
                ;

FieldDecl       :   Type ID EOL               {   $$ = createField($1, $2); }
                ;
/* -------------------------------------------------------------------------------------------------- */

GDeclBlock  :   DECL GDeclList ENDDECL          {   }
            |   DECL ENDDECL                    {   }
            ;
GDeclList   :   GDeclList GDecl
            |   GDecl
GDecl       :   Type GidList EOL                {     }
            ;
Type        :   INT                             {   $$ = $1;current_type = TLookup("int");      }
            |   STR                             {   $$ = $1;current_type = TLookup("str");      }
            |   ID                              {   $$ = $1;current_type = TLookup($1);  }
            ;
GidList     :   GidList ',' Gid
            |   Gid
            ;
Gid         :   ID                              {   GST = insertToGlobal($1, 1, 0, 0,NULL, NODE_ID);    }
            |   ID '[' NUM ']'                  {   GST = insertToGlobal($1, $3->value.intVal, 1, $3->value.intVal, NULL, NODE_ID);   }
            |   ID '(' ParamList ')'            {   GST = insertToGlobal($1, 0, 0, 0, $3, NODE_FUNCT);  
                                                    clearLST();  
                                                }
            ;

/* ------------------------------------------------------------------------------- */
FDefBlock   :   FDefBlock Fdef                  {      }
            |   Fdef                            {      }
            ;
Fdef        :   Type ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'      {   
                                                                                if(isInsideClass)
                                                                                    validateMethod(TLookup($1), $2, $4, $8); 
                                                                                else
                                                                                    validateFunct(TLookup($1), $2, $4, $8); 
                                                                                // generateFunct(output, $2, $8);
                                                                                clearLST();  
                                                                            }
            ;

/* --------------------------------------------------------------------------------- */

MainBlock   :   INT MAIN '('')' '{' LDeclBlock Coderegion '}'               {   
                                                                                setHeader(output);  
                                                                                validateMain($7);
                                                                                // generateFunct(output, NULL, $7);
                                                                                printLST("MAIN");
                                                                                clearLST();
                                                                            }
            ;

/* --------------------------------------------------------------------------------- */

ParamList   :   ParamList ',' Param     {   $$ = appendParam($1, $3); }
            |   Param                   {   $$ = $1; }
            |                           {   $$ = NULL; }
            ;
Param       :   Type ID                  {   $$ = createParam($1, $2);   }
            ;

/* ------------------------------------------------------------------------------------ */

LDeclBlock  :   DECL LDeclList ENDDECL              {  }
            |   DECL ENDDECL
            |
            ;
LDeclList   :   LDeclList LDecl                     {  }
            |   LDecl                               {  }
            ;
LDecl       :   Type {  Ldatatype = $1;  } IdList  EOL                    
            ;
IdList      :   IdList ',' ID                       {   LST = createLST($3, Ldatatype);   }
            |   ID                                  {   LST = createLST($1, Ldatatype);   }
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
            |   DELETE '(' IDENTIFIERS ')' EOL      {   $$ = createClassNode(NODE_DELETE, createLeafNode(NODE_ID, NULL, $3->name, 0, NULL), NULL);    }
            ;
InputStmt   :   READ'('IDENTIFIERS')' EOL           {   $$ = createTreeNode(NODE_READ, $3, NULL);   }
            ;
OutputStmt  :   WRITE'(' expr ')' EOL               {   $$ = createTreeNode(NODE_WRITE, $3, NULL);     }
            ;
AsgnStmt    :   IDENTIFIERS ASSGN expr EOL                      {   $$ = createTreeNode(NODE_ASSIGN, $1, $3);    }
            |   IDENTIFIERS ASSGN ALLOC '('')' EOL              {   setType($$);$$ = createDynamicNode(NODE_ALLOC, $1);  }
            |   IDENTIFIERS ASSGN INITIALIZE '('')' EOL         {   $$ = createDynamicNode(NODE_INITIALIZE, NULL);  }
            |   IDENTIFIERS ASSGN NEW '(' ID ')' EOL            {   $$ = createClassNode(NODE_NEW, $1, $5); }
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
            |   IDENTIFIERS                         {   $$ = $1; validateAndSetType($$);    }
            |   NULL_VAL                            {   $$ = createDynamicNode(NODE_NULL, NULL);    }
            ;
IDENTIFIERS :   ID                                  {   $$ = createLeafNode(NODE_ID, NULL, $1, 0, NULL); }
            |   SELF                                {   $$ = createLeafNode(NODE_SELF, NULL, "self", 0, NULL);  }
            |   ID '[' expr ']'                     {   $$ = createArrayNode(createLeafNode(NODE_ID, NULL, $1, 0, NULL), NULL, $3); }
            |   IDENTIFIERS '(' ArgList ')'         {   $$ = createFunctNode($1, $3);   }
            |   IDENTIFIERS '.' IDENTIFIERS         {   $$ = createFieldAccessNode($1, $3);    }
            ;
ArgList     :   ArgList ',' expr                    {   $$ = appendArgNode($1, $3); }
            |   expr                                {   $$ = $1; }
            |                                       {   $$ = NULL;  }
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