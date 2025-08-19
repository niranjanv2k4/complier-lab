%{
    
    #include <stdio.h>
    #include <string.h>
    int yyerror();
    int yylex();

%}

%union{
    char *s;
};

%token <s> STR
%type <s> expr

%left '+' '-'
%left '*' '/'

%%

start   : expr '\n'     {   printf("%s\n", $1);    }
        ;
expr    : expr '+' expr {
                char buf[256];
                sprintf(buf, "+ %s %s", $1, $3);
                $$ = strdup(buf);
            }
        
        | expr '-' expr {
                char buf[256];
                sprintf(buf, "- %s %s", $1, $3);
                $$ = strdup(buf);
            }

        | expr '*' expr {
                char buf[256];
                sprintf(buf, "* %s %s", $1, $3);
                $$ = strdup(buf);
            }

        | expr '/' expr {
                char buf[256];
                sprintf(buf, "/ %s %s", $1, $3);
                $$ = strdup(buf);
            }

        | '(' expr ')'  {   $$ = $2;    }
        | STR           {   $$ = $1;    }
        ;

%%

int yyerror(const char* s){
    printf("Error: %s\n", s);
    return 1;
}

int main(){
    yyparse();
    return 0;
}