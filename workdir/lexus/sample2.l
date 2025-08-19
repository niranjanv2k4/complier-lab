%{
    #include <stdio.h>
    #include <stdlib.h>
%}

number  [0-9]+

%%

{number}    {   //return atoi(yytext);
                printf("FOUND: %d\n", atoi(yytext));
                int temp = atoi(yytext);
                if(temp%2==0)
                    printf("Number is even\n");
                else 
                    printf("Number is odd\n");  
                //return 1;
            }

%%


int yywrap(){
    static int done = 0;
    if(!done){
        char file[256];
        printf("Enter the second file: ");
        scanf("%s", file);
        yyin = fopen(file, "r");
        done = 1;
        return  0;
    }
    return 1;
}


int main(){
    char file[256];
    printf("Enter the first file: ");
    scanf("%s", file);
    yyin = fopen(file, "r");
    int num = yylex();
    printf("%d", num);
    return 0;
}
