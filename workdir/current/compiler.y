%{
    
    #include "main.h"

    #include "./Conditionals/jump.h"
    #include "./ExecGen/exec.h"
    #include "./TreeGen/tree.h"
    #include "./symbolTable/symbol.h"

    int yyerror();
    int yylex();


    FILE *output;

    struct GSymbolTable* GST = NULL;
    struct param* paramlist = NULL;
    struct LSymbolTable* LST = NULL;


    int current_type;

%}

%union{
    struct tnode* node;
    struct param* parameter;
    struct LSymbolTable* localSymbolTable;
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
%type <parameter> Param ParamList

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
                                                    printGST(GST);  
                                                }
            ;

GDeclBlock  :   DECL GDeclList ENDDECL          {   }
            |   DECL ENDDECL                    {   }
            |
            ;
GDeclList   :   GDeclList GDecl
            |   GDecl
GDecl       :   Type GidList EOL                {   }
            ;
GidList     :   GidList ',' Gid
            |   Gid
            ;
Type        :   INT                             {   current_type = TYPE_INT;    }
            |   STR                             {   current_type = TYPE_STR;    }
            ;
Gid         :   ID                              {   GST = insertToGlobal(GST, $1, current_type, 1, 1,NULL, false);    }
            |   ID '[' NUM ']'                  {   GST = insertToGlobal(GST, $1, current_type, 1, $3->val, NULL, false); }
            |   ID '(' ParamList ')'            {   GST = insertToGlobal(GST, $1, current_type, 1, 1, $3, true);    }
            ;

/* ------------------------------------------------------------------------------- */
FDefBlock   :   FDefBlock Fdef                  {      }
            |   Fdef                            {      }
            ;
Fdef        :   INT ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'     {   }
            |   STR ID '(' ParamList ')' '{' LDeclBlock Coderegion '}'     {   }
            ;
ParamList   :   ParamList ',' Param     {   $$ = appendParam($1, $3); }
            |   Param                   {   }
            |                           {   $$ = NULL; }
            ;

Param       :   INT ID                 {   $$ = createParam(TYPE_INT, $2);  }
            |   STR ID                 {   $$ = createParam(TYPE_STR, $2);  }
            ;

/* --------------------------------------------------------------------------------- */

MainBlock   :   INT MAIN '('')' '{' LDeclBlock Coderegion '}'           {   }
            ;

/* --------------------------------------------------------------------------------- */

LDeclBlock  :   DECL LDeclList ENDDECL                                  {  }
            |
            |   DECL ENDDECL
            ;
LDeclList   :   LDeclList LDecl                                         {  }
            |   LDecl                                                   {  }
            ;
LDecl       :   Type IdList  EOL                                        {  }
            ;
IdList      :   IdList ',' ID                                           {   }
            |   ID                                                      {   }
            ;   

/* ---------------------------------------------------------------------------------- */

Coderegion  :   T_BEGIN Slist RtnStmt T_END         {   }
            ;
RtnStmt     :   RETURN expr EOL                     {   }
            ;
Slist       :   Slist Stmt                          {   }
            |   Stmt                                {   }
            ;
Stmt        :   InputStmt                           {   }
            |   OutputStmt                          {   }
            |   AsgnStmt                            {   }
            |   IfStmt                              {   }
            |   WhileStmt                           {   }
            |   BREAK EOL                           {   }
            |   CONTINUE EOL                        {   }
            |   RptUntlStmt                         {   }
            |   DoWhileStmt                         {   }
            ;
InputStmt   :   READ'('ID')' EOL                        {   }
            |   READ'('ID '[' expr ']'')' EOL           {   }
            ;
OutputStmt  :   WRITE'(' expr ')' EOL                   {   }
            ;
AsgnStmt    :   ID ASSGN expr EOL                       {   }
            |   ID '[' expr ']' ASSGN expr EOL          {   }
            ;

IfStmt      :   IF '(' expr ')' THEN Slist ELSE Slist ENDIF EOL  {  }
            |   IF '(' expr ')' THEN Slist ENDIF EOL             {  }
            ;
WhileStmt   :   WHILE '(' expr ')' DO Slist END_WHILE EOL        {  }
            ;
RptUntlStmt :   REPEAT '{' Slist '}' UNTILL '(' expr ')' EOL     {  }
            ;
DoWhileStmt :   DO '{' Slist '}'  WHILE '(' expr ')' EOL         {  }
            ;



expr        :   expr ADD expr                       {   }
            |   expr SUB expr                       {   }
            |   expr STAR expr                      {   }
            |   expr DIV expr                       {   }
            |   expr MOD expr                       {   }
            |   expr EQ expr                        {   }
            |   expr NE expr                        {   }
            |   expr GT expr                        {   }
            |   expr GE expr                        {   }
            |   expr LT expr                        {   }
            |   expr LE expr                        {   }
            |   expr OR expr                        {   }
            |   expr AND expr                       {   }
            |   '(' expr ')'                        {   }
            |   NUM                                 {   }
            |   STR_LITERAL                         {   }
            |   ID '('')'                           {   }
            |   ID '(' ArgList ')'                  {   }
            |   ID                                  {   }
            |   ID '[' expr ']'                     {   }
                                                    
            ;
ArgList     :   ArgList ',' expr
            |   expr
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