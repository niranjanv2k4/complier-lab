#include "exec.h"

void writeToTerminal(FILE* output, int r);
void readFromTerminal(FILE* output, struct ASTNode* root);
int evaluate(struct ASTNode* root, FILE* output);
int codeGen(struct ASTNode* root, FILE* output);


/**/

static uint32_t used = 0;
int newLabel = 0;
int regNum = 0;

bool isMain = false;

/* array for keeping track of current  loop labels */
static struct LoopLabels loopStack[MAX_LOOP_NESTING];
static int loopTop = -1;

void pushLoop(int start, int end) {
    loopTop++;
    loopStack[loopTop].start = start;
    loopStack[loopTop].end   = end;
}
void popLoop(void) {
    loopTop--;
}
int getLoopStart(void) {
    return loopStack[loopTop].start;
}
int getLoopEnd(void) {
    return loopStack[loopTop].end;
}

/* -----Register & label managing----- */
int getReg(){
    for(int i = 0; i<20; i++){
        if(!(used & (1u <<i))){
            used |= (1u <<i);
            return i;
        }
    }
    printf("Out of regusters\n");
    exit(1);
    return -1;
}

int freeReg(int reg){
    if(reg>=0 && reg<20 && (used & (1u <<reg))){
        used &= ~(1u <<reg);
        return 0;
    }
    printf("No registers to free - %d\n", reg);
    exit(1);
    return -1;
}

int getNewLabel(){
    return newLabel++;
}


int getAddr(FILE* output, struct ASTNode* node){

    int reg = getReg();

    if(node->Lentry){

        fprintf(output, "MOV R%d, BP\n", reg);
        fprintf(output, "ADD R%d, %d\n", reg, node->Lentry->binding);

    }else{

        fprintf(output, "MOV R%d, %d\n", reg, node->Gentry->binding);

        if(node->Gentry->size != 1){

            if(node->ptr1){
                int rowOffset = codeGen(node->ptr1, output);
                int colOffset = codeGen(node->ptr2, output);

                fprintf(output, "MUL R%d, %d\n", rowOffset, node->Gentry->rowSize);
                fprintf(output, "ADD R%d, R%d\n", rowOffset, colOffset);
                fprintf(output, "ADD R%d, R%d\n", reg, rowOffset);

                freeReg(rowOffset);
                freeReg(colOffset);
            }else{
                int colOffset = codeGen(node->ptr2, output);
                
                fprintf(output, "ADD R%d, R%d\n", reg, colOffset);

                freeReg(colOffset);
            }
        }
    }

    return reg;
}

void writeToTerminal(FILE* output, int reg){

    int temp = getReg();

    fprintf(output, "MOV R%d, \"Write\"\nPUSH R%d\n", temp, temp);
    fprintf(output, "MOV R%d, -2\nPUSH R%d\n", temp, temp);

    fprintf(output, "PUSH R%d\n", reg);
    fprintf(output, "PUSH R%d\nPUSH R%d\n", temp, temp);

    fprintf(output, "CALL 0\n");

    fprintf(output, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", temp, temp, temp, temp, temp);

    freeReg(temp);

}

void readFromTerminal(FILE* output, struct ASTNode* root){
    
    int reg = getAddr(output, root);
    int temp = getReg();

    fprintf(output, "MOV R%d, \"Read\"\nPUSH R%d\n", temp, temp);
    fprintf(output, "MOV R%d, -1\nPUSH R%d\n", temp, temp);

    fprintf(output, "PUSH R%d\nPUSH R%d\nPUSH R%d\n", reg, reg, reg);

    fprintf(output, "CALL 0\n");
    
    fprintf(output, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", temp , temp , temp , temp , temp);

    freeReg(reg);
    freeReg(temp);
}

void exitProg(FILE* output){
    fprintf(output, "MOV R0, \"Exit\"\nPUSH R0\n");
    fprintf(output, "PUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\n");
    fprintf(output, "CALL 0\n");
    fprintf(output, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
}

int evaluate(struct ASTNode* root, FILE* output){
    switch(root->nodetype){
        case NODE_CONST:{
            int reg = getReg();
            if(TLookup("int") == root->type){
                fprintf(output, "MOV R%d, %d\n", reg, root->value.intVal);
            }else{
                fprintf(output, "MOV R%d, %s\n", reg, root->value.strVal);
            }
            return reg;
        }
        case NODE_ID:{

            int reg = getAddr(output, root);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);
            return reg;
        
        }
        case NODE_FUNCT:{

            /* storing the used registers */
            for(int i = 0; i<20; i++){
                if(used & (1u <<i)){
                    fprintf(output, "PUSH R%d\n", i);
                }
            }

            int res = getReg();

            /* pushing arguments */
            struct ASTNode* tempArglist = root->ptr1->arglist;
            while(tempArglist){
                int reg = evaluate(tempArglist, output);
                fprintf(output, "PUSH R%d\n", reg);
                freeReg(reg);
                tempArglist= tempArglist->arglist;
            }

            /* space for return value */
            fprintf(output, "PUSH R%d\n", res);

            fprintf(output, "CALL __F%d\n", root->ptr1->Gentry->flabel);

            /* taking the return value */
            fprintf(output, "POP R%d\nBRKP\n", res);

            int temp = getReg();
            tempArglist = root->ptr1->arglist;
            while(tempArglist){
                fprintf(output, "POP R%d\n",temp);
                tempArglist = tempArglist->arglist;
            }
            freeReg(temp);

            for(int i = 19; i>=0; i--){
                if((used & (1u <<i)) && i!= res) {
                    fprintf(output, "POP R%d\n", i);
                }
            }

            return res;
        }
        case NODE_OR: {
            int label_true = getNewLabel();
            int label_end  = getNewLabel();

            int res = getReg();
            int left = evaluate(root->ptr1, output);

            fprintf(output, "JNZ R%d, L%d\n", left, label_true);
            freeReg(left);

            int right = evaluate(root->ptr2, output);
            fprintf(output, "MOV R%d, R%d\n", res, right);
            freeReg(right);
            fprintf(output, "JMP L%d\n", label_end);

            fprintf(output, "L%d:\n", label_true);
            fprintf(output, "MOV R%d, 1\n", res);

            fprintf(output, "L%d:\n", label_end);

            return res;
        }
        case NODE_AND: {
            int label_false = getNewLabel();
            int label_end   = getNewLabel();

            int res = getReg();
            int left = evaluate(root->ptr1, output);

            fprintf(output, "JZ R%d, L%d\n", left, label_false);
            freeReg(left);

            int right = evaluate(root->ptr2, output);
            fprintf(output, "MOV R%d, R%d\n", res, right);
            freeReg(right);
            fprintf(output, "JMP L%d\n", label_end);

            fprintf(output, "L%d:\n", label_false);
            fprintf(output, "MOV R%d, 0\n", res);

            fprintf(output, "L%d:\n", label_end);

            return res;
        }

    }

    int left = codeGen(root->ptr1, output);
    int right = codeGen(root->ptr2, output);

    switch(root->nodetype){
        case NODE_ADD:   
            fprintf(output, "ADD R%d, R%d\n", left, right);
            break;

        case NODE_SUB:   
            fprintf(output, "SUB R%d, R%d\n", left, right);
            break;

        case NODE_MUL:   
            fprintf(output, "MUL R%d, R%d\n", left, right);
            break;

        case NODE_DIV:   
            fprintf(output, "DIV R%d, R%d\n", left, right);
            break;
        case NODE_MOD:   
            fprintf(output, "MOD R%d, R%d\n", left, right);
            break;
        case NODE_LT:
            fprintf(output, "LT R%d, R%d\n", left, right);
            break;

        case NODE_GT:
            fprintf(output, "GT R%d, R%d\n", left, right);
            break;

        case NODE_LE:
            fprintf(output, "LE R%d, R%d\n", left, right);
            break;

        case NODE_GE:
            fprintf(output, "GE R%d, R%d\n", left, right);
            break;
        
        case NODE_EQ:
            fprintf(output, "EQ R%d, R%d\n", left, right);
            break;

        case NODE_NE:
            fprintf(output, "NE R%d, R%d\n", left, right);
            break;

        default:
            break;
    }

    freeReg(right);
    return left;
}

void generateIfElseBlock(FILE* output, struct ASTNode* root){
    int flag = evaluate(root->ptr1, output);
    int ifEndLabel = getNewLabel();

    if(root->ptr3){
        int elseLabel = getNewLabel();

        fprintf(output, "JZ R%d, L%d\n", flag, elseLabel);
        codeGen(root->ptr2, output);
        fprintf(output, "JMP L%d\n", ifEndLabel);

        fprintf(output, "L%d:\n", elseLabel);
        codeGen(root->ptr3, output);

        fprintf(output, "L%d:\n", ifEndLabel);

    }else{

        fprintf(output, "JZ R%d, L%d\n", flag, ifEndLabel);

        codeGen(root->ptr2, output);

        fprintf(output, "L%d:\n", ifEndLabel);

    }

    freeReg(flag);
}
void generateWhileBlock(FILE* output, struct ASTNode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);

    int flag = evaluate(root->ptr1, output);

    fprintf(output, "JZ R%d, L%d\n", flag, endLabel);

    codeGen(root->ptr2, output);

    fprintf(output, "JMP L%d\n", startLabel);
    fprintf(output, "L%d:\n", endLabel);

    freeReg(flag);
    popLoop();
}
void generateDoWhileBlock(FILE* output, struct ASTNode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);

    codeGen(root->ptr2, output);

    int flag = evaluate(root->ptr1, output);

    fprintf(output, "JNZ R%d, L%d\n", flag, startLabel);

    fprintf(output, "L%d:\n", endLabel);

    freeReg(flag);
    popLoop();
}
void generateRptUtlBlock(FILE* output, struct ASTNode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);
    codeGen(root->ptr2, output);

    int flag = evaluate(root->ptr1, output);

    fprintf(output, "JNZ R%d, L%d\n", flag, startLabel);

    fprintf(output, "L%d:\n", endLabel);

    freeReg(flag);
    popLoop();
}

int codeGen(struct ASTNode* root, FILE* output){
    switch(root->nodetype){
        case NODE_CONST:{
            int reg = getReg();
            if(TLookup("int") == root->type){
                fprintf(output, "MOV R%d, %d\n", reg, root->value.intVal);
            }else{
                fprintf(output, "MOV R%d, %s\n", reg, root->value.strVal);
            }
            return reg;
        }
        case NODE_ID:{

            int reg = getAddr(output, root);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);
            return reg;
        
        }
        case NODE_FUNCT:{

            /* storing the used registers */
            for(int i = 0; i<20; i++){
                if(used & (1u <<i)){
                    fprintf(output, "PUSH R%d\n", i);
                }
            }

            int res = getReg();

            /* pushing arguments */
            struct ASTNode* tempArglist = root->ptr1->arglist;
            while(tempArglist){
                int reg = evaluate(tempArglist, output);
                fprintf(output, "PUSH R%d\n", reg);
                freeReg(reg);
                tempArglist= tempArglist->arglist;
            }

            /* space for return value */
            fprintf(output, "PUSH R%d\n", res);

            fprintf(output, "CALL __F%d\n", root->ptr1->Gentry->flabel);

            /* taking the return value */

            int usedReg = regNum;


            fprintf(output, "POP R%d\nBRKP\n", res);

            int temp = getReg();
            tempArglist = root->ptr1->arglist;
            while(tempArglist){
                fprintf(output, "POP R%d\n",temp);
                tempArglist = tempArglist->arglist;
            }
            freeReg(temp);

            for(int i = 19; i>=0; i--){
                if((used & (1u <<i)) && i!= res) {
                    fprintf(output, "POP R%d\n", i);
                }
            }

            return res;
        }
    }
    switch (root->nodetype){
        case NODE_CONST:{
            int reg = getReg();
            if(TLookup("int") == root->type){
                fprintf(output, "MOV R%d, %d\n", reg, root->value.intVal);
            }else{
                fprintf(output, "MOV R%d, %s\n", reg, root->value.strVal);
            }
            return reg;
        }
        case NODE_ID:{
            int reg = getAddr(output, root);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);
            return reg;
        }
        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_MOD:
        case NODE_DIV: {
            return evaluate(root, output);
        }

        case NODE_READ:{
            readFromTerminal(output, root->ptr1);
            return -1;
        }

        case NODE_WRITE:{
            int reg = evaluate(root->ptr1, output);
    fprintf(output, "BRKP\n");

            writeToTerminal(output, reg);
            freeReg(reg);
            return -1;
        }

        case NODE_ASSIGN:{

            int res = evaluate(root->ptr2, output);
            int addr = getAddr(output, root->ptr1);
            
            fprintf(output, "MOV [R%d], R%d\n", addr, res);

            freeReg(addr);
            freeReg(res);

            return -1;
        }

        case NODE_CONNECTOR:{
            codeGen(root->ptr1, output);
            codeGen(root->ptr2, output);
            return -1;
        }

        case NODE_IF:{
            generateIfElseBlock(output, root);
            return -1;
        }

        case NODE_WHILE:{
            generateWhileBlock(output, root);
            return -1;
        }

        case NODE_DOWHILE:{
            generateDoWhileBlock(output, root);
            return -1;
        }

        case NODE_RPTUTL:{
            generateRptUtlBlock(output, root);
            return -1;
        }

        case NODE_BREAK:{
            if(loopTop >=0 ){
                fprintf(output, "JMP L%d\n", getLoopEnd());
            }
            return -1;
        }

        case NODE_CONTINUE:{
            if(loopTop>=0){
                fprintf(output, "JMP L%d\n", getLoopStart());
            }
            return -1;
        }
        case NODE_RET:{

            int res = evaluate(root->ptr1, output);
            int temp = getReg();
            
            
            if(!isMain){
                fprintf(output, "MOV SP, BP\n");
                fprintf(output,"MOV R%d, BP\n", temp);
                fprintf(output,"SUB R%d, 2\n", temp);
                fprintf(output, "MOV [R%d], R%d\n", temp, res);
            }

            freeReg(temp);
            freeReg(res);
            return -1;
        }
        

        default:
            return -1;
    }
}

void generateFunct(FILE* output, struct ASTNode* id, struct ASTNode* code){

    if(id == NULL){
        fprintf(output, "MAIN:\n");
        struct LSymbol* tempLST = LST;

        fprintf(output, "MOV BP, SP\n");

        while(tempLST){
            fprintf(output, "PUSH R0\n");
            tempLST = tempLST->next;
        }
        isMain = true;
        codeGen(code, output);
        isMain = false;
        regNum = 0;

        return;
    }

    fprintf(output, "__F%d:\n", id->Gentry->flabel);

    fprintf(output, "BRKP\n");

    fprintf(output, "PUSH BP\nMOV BP, SP\n");
    
    struct param* tempParamlist = id->Gentry->paramlist;
    struct LSymbol* tempLST = LST;


    while(tempParamlist){
        tempParamlist = tempParamlist->next;
        tempLST = tempLST->next;
    }

    while(tempLST){
        fprintf(output, "PUSH R0\n");
        tempLST = tempLST->next;
    }

    codeGen(code, output);

    fprintf(output, "POP BP\n");
    fprintf(output, "RET\n");
    
    used = 0;
}

void setHeader(FILE* output){
    fprintf(output, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(output, "MOV SP, %d\n", currBinding);
    fprintf(output, "JMP MAIN\n");

}