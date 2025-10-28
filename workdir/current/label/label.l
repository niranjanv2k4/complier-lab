%{
    
    #include "./label.h"

    int CurrAddr = 2040;
    bool tableCreated = false;

    FILE* translated = NULL;

    struct LabelList* labelList = NULL;

%}

labels   (L[0-9]+|__F[0-9]+|MAIN)


%%

{labels}:"\n"                       {   
                                        if(!tableCreated){
                                            labelList = insertNewLabel(labelList, strndup(yytext, yyleng - 2), CurrAddr);
                                        }
                                    }
{labels}                            {
                                        if(tableCreated)
                                            fprintf(translated, "%d", getAddr(labelList, yytext)); 

                                    }
"\n"                                {
                                        if(!tableCreated)
                                            CurrAddr+=2;
                                        else
                                            fprintf(translated, "\n");

                                    }
.                                   {   
                                        if(tableCreated)
                                            fprintf(translated, "%s", yytext); 
                                    }

%%

int yywrap(){
    if(!tableCreated){
        tableCreated = true;
        fseek(yyin, 0, SEEK_SET);
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
    }

    translated = fopen("translated.xsm", "w");
    
    yylex();
}