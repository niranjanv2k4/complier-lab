%{
    
    #include "./label.h"

    int CurrAddr = 2056;
    bool tableCreated = false;

    FILE* translated = NULL;

    struct LabelList* labelList = NULL;

%}

label       L[0-9]+
register    R[0-9]+
numbers     [0-9]+

%%
{numbers}\n                         {   
                                        if(tableCreated){
                                            fprintf(translated, "%s", yytext); 
                                        }
                                    }
{label}":\n"                        {   
                                        if(!tableCreated){
                                            char temp[11];
                                            strncpy(temp, yytext, yyleng - 2);
                                            temp[yyleng - 2] = '\0';
                                            labelList = insertNewLabel(labelList, temp, CurrAddr);
                                            //printf("%s - %d\n", temp, CurrAddr);
                                        }
                                    }

"JZ "{register}", "{label}\n        {   
                                        if(tableCreated){
                                            char reg[10], label[10];
                                            sscanf(yytext, "JZ %[^,], %s", reg, label);
                                            int labelAddr = getAddr(labelList, label);

                                            if(labelAddr == -1){
                                                printf("Label undeclared\n");
                                                exit(1);
                                            }

                                            fprintf(translated, "JZ %s, %d\n", reg, labelAddr);
                                        }else{
                                            CurrAddr += 2;
                                        }
                                    }
"JNZ "{register}", "{label}\n       {   
                                        if(tableCreated){
                                            char reg[10], label[10];
                                            sscanf(yytext, "JNZ %[^,], %s", reg, label);
                                            int labelAddr = getAddr(labelList, label);

                                            if(labelAddr == -1){
                                                printf("Label undeclared\n");
                                                exit(1);
                                            }

                                            fprintf(translated, "JNZ %s, %d\n", reg, labelAddr);
                                        }else{
                                            CurrAddr += 2;
                                        }
                                    }
"JMP "{label}\n                     {   
                                        if(tableCreated){
                                            char reg[10], label[10];
                                            sscanf(yytext, "JMP %s", label);
                                            int labelAddr = getAddr(labelList, label);

                                            if(labelAddr == -1){
                                                printf("Label undeclared\n");
                                                exit(1);
                                            }

                                            fprintf(translated, "JMP %d\n", labelAddr);
                                        }else{
                                            CurrAddr += 2;
                                        }
                                    }
.*\n                              {   
                                        if(!tableCreated)
                                            CurrAddr += 2;
                                        else
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