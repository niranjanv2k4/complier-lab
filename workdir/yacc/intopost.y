%{
/*** Auxiliary declarations section ***/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* Custom function to print an operator*/
void print_operator(char op);



int yylex();
void yyerror(const char *);

/* Variable to keep track of the position of the number in the input */
int pos=0;

%}

 /*** YACC Declarations section ***/
%token DIGIT
%left '+'
%left '*'
%%

/*** Rules Section ***/
start : expr '\n'		{exit(1);}
      ;

expr: expr '+' expr     {print_operator('+');}
    | expr '*' expr     {print_operator('*');}
    | '(' expr ')'
    | DIGIT             {printf("NUM%d(%d) ",pos, $1);}
    ;

%%


/*** Auxiliary functions section ***/

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS(+) ");
                    break;
        case '*'  : printf("MUL(*) ");
                    break;
    }
    return;
}

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        pos++;
        yylval = c-'0';
        return DIGIT;
    }
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else {
        return c;
    }
}

int main()
{
	yyparse();
	return 1;
}