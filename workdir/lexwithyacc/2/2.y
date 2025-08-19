%{
    
    #include <stdio.h>
    #include <stdlib.h>

    int yyerror(const char *);
    int yylex();

%}

%token  IDENT INR_ASSG SUB_ASSG DIV_ASSG MUL_ASSG ADD SUB DIV MUL ASSG NEWLINE NUM

%left ADD SUB
%left MUL DIV


%%
start       :   valid NEWLINE           {   printf("Accepted\n"); 
                                            exit(0);
                                        }
valid       :   IDENT INR_ASSG expr     { }
            |   IDENT SUB_ASSG expr     { }
            |   IDENT MUL_ASSG expr     { }
            |   IDENT DIV_ASSG expr     { }
            |   IDENT ASSG expr         { }
            ;
expr        :   expr ADD expr   { }
            |   expr SUB expr   { }
            |   expr MUL expr   { }
            |   expr DIV expr   { }
            |   '(' expr ')'    { }
            |   IDENT      { }
            |   NUM             { }
            ;

%%

int yyerror(const char* s){
    printf("Not Accepted\n");
    return 1;
}


int main(){
    yyparse();
    return 0;
}