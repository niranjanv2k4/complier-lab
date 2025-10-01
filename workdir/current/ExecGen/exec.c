#include "exec.h"

void writeToTerminal(FILE* output, int r);
void readFromTerminal(FILE* output, struct tnode* root);
int exprEvaluate(struct tnode* root, FILE* output);
int boolEvaluate(struct tnode* root, FILE* output);

/**/

static uint32_t used = 0;
int newLabel = 0;


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
    return -1;
}

int freeReg(int reg){
    if(reg>=0 && reg<20 && (used & (1u <<reg))){
        used &= ~(1u <<reg);
        return 0;
    }
    return -1;
}

int getNewLabel(){
    return newLabel++;
}


/* -----I/O managing----- */
void writeToTerminal(FILE* output, int reg){

    int temp = getReg();
    if(temp==-1){
        printf("Out of registers\n");
        exit(1);
    }

    fprintf(output, "MOV R%d, \"Write\"\nPUSH R%d\n", temp, temp);
    fprintf(output, "MOV R%d, -2\nPUSH R%d\n", temp, temp);

    fprintf(output, "PUSH R%d\n", reg);
    fprintf(output, "PUSH R%d\nPUSH R%d\n", temp, temp);

    fprintf(output, "CALL 0\n");

    fprintf(output, "POP R0\n");

    fprintf(output, "POP R0\nPOP R0\nPOP R0\nPOP R0\n");

    freeReg(temp);

}

void readFromTerminal(FILE* output, struct tnode* root){
    
    int addr = root->STentry->binding;
    int reg = getReg();
    int temp = getReg();
    
    fprintf(output, "MOV R%d, %d\n", reg, addr);

    if(root->STentry->isArray){
        int offset = exprEvaluate(root->left, output);
        // int check = getReg();
        // fprintf(output, "MOV R%d, R%d\n", check, root->STentry->size);
        // fprintf()
        fprintf(output, "ADD R%d, R%d\n", reg, offset);
        freeReg(offset);
    }

    fprintf(output, "MOV R%d, \"Read\"\nPUSH R%d\n", temp, temp);
    fprintf(output, "MOV R%d, -1\nPUSH R%d\n", temp, temp);

    fprintf(output, "PUSH R%d\nPUSH R%d\nPUSH R%d\n", reg, reg, reg);

    fprintf(output, "CALL 0\n");
    
    fprintf(output, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");

    freeReg(reg);
    freeReg(temp);
}

void exitProg(FILE* output){
    int r1 = getReg();

    fprintf(output, "MOV R%d, \"Exit\"\nPUSH R%d\n", r1, r1);
    fprintf(output, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r1, r1, r1, r1);
    fprintf(output, "CALL 0\n");

    freeReg(r1);
}


/* -----output generation----- */
int codeGen(struct tnode* root, FILE* output);

int exprEvaluate(struct tnode* root, FILE* output){
    if(root->nodetype==NODE_LEAF){
        int reg = getReg();

        if(reg==-1){
            printf("Out of registers\n");
            exit(1);
        }
        switch(root->type){
            case TYPE_INT: 
                fprintf(output, "MOV R%d, %d\n", reg, root->val);
                break;
            case TYPE_STR: 
                fprintf(output, "MOV R%d, %s\n", reg, root->str_val);
                break;
            case TYPE_ID_INT:
            case TYPE_ID_STR: {
                
                int addr = root->STentry->binding;
                
                if(root->STentry->isArray){
                    int offset = exprEvaluate(root->left, output);

                    int temp = getReg();

                    fprintf(output, "MOV R%d, %d\n", temp, addr);
                    fprintf(output, "ADD R%d, R%d\n", temp, offset);
                    fprintf(output, "MOV R%d, [R%d]\n", reg, temp);

                    freeReg(temp);
                    freeReg(offset);
                }
                else{
                    fprintf(output, "MOV R%d, [%d]\n", reg, addr);
                }
            }
        }
        return reg;
    }

    int left = codeGen(root->left, output);
    int right = codeGen(root->right, output);

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
    }

    freeReg(right);
    return left;
}

int boolEvaluate(struct tnode* root, FILE* output){
    if(root->nodetype==NODE_LEAF){
        int reg = getReg();

        if(reg==-1){
            printf("Out of registers\n");
            exit(1);
        }
        switch(root->type){
            case TYPE_INT: 
                fprintf(output, "MOV R%d, %d\n", reg, root->val);
                break;
            case TYPE_STR: 
                fprintf(output, "MOV R%d, %s\n", reg, root->str_val);
                break;
            case TYPE_ID_INT:
            case TYPE_ID_STR: {
                
                int addr = root->STentry->binding;
                int offset = 0;
                if(root->STentry->isArray){
                    int offset = exprEvaluate(root->left, output);
                }

                int temp = getReg();

                fprintf(output, "MOV R%d, %d\n", temp, offset);
                fprintf(output, "MOV R%d, %d\n", reg, addr);
                fprintf(output, "ADD R%d, R%d\n", reg, temp);
                fprintf(output, "MOV R%d, [R%d]\n", reg, reg);

                freeReg(temp);
            }
        }
        return reg;
    }

    int left = codeGen(root->left, output);
    int right = codeGen(root->right, output);

    switch (root->nodetype){
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

/* codeGen for if block */

void generateIfElseBlock(FILE* output, struct tnode* root){

    int flag = boolEvaluate(root->left, output);
    int ifEndLabel = getNewLabel();

    if(root->nodetype == NODE_IFELSE){

        int elseLabel = getNewLabel();

        fprintf(output, "JZ R%d, L%d\n", flag, elseLabel);

        codeGen(root->right->left, output);
        fprintf(output, "JMP L%d\n", ifEndLabel);

        if(root->right->right != NULL){
            fprintf(output, "L%d:\n", elseLabel);
            codeGen(root->right->right, output);
        }

        fprintf(output, "L%d:\n", ifEndLabel);

    }else{

        fprintf(output, "JZ R%d, L%d\n", flag, ifEndLabel);

        codeGen(root->right->left, output);
        fprintf(output, "L%d:\n", ifEndLabel);

    }

    freeReg(flag);
}

void generateWhileBlock(FILE* output, struct tnode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);

    int flag = boolEvaluate(root->left, output);

    fprintf(output, "JZ R%d, L%d\n", flag, endLabel);
    codeGen(root->right, output);

    fprintf(output, "JMP L%d\n", startLabel);
    fprintf(output, "L%d:\n", endLabel);

    popLoop();
}

void generateDoWhileBlock(FILE* output, struct tnode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);
    codeGen(root->right, output);

    int flag = boolEvaluate(root->left, output);

    fprintf(output, "JNZ R%d, L%d\n", flag, startLabel);

    fprintf(output, "L%d:\n", endLabel);

    popLoop();
}

void generateRptUtlBlock(FILE* output, struct tnode* root){

    int startLabel = getNewLabel();
    int endLabel = getNewLabel();

    pushLoop(startLabel, endLabel);

    fprintf(output, "L%d:\n", startLabel);
    codeGen(root->right, output);

    int flag = boolEvaluate(root->left, output);

    fprintf(output, "JNZ R%d, L%d\n", flag, startLabel);

    fprintf(output, "L%d:\n", endLabel);

    popLoop();
}

int codeGen(struct tnode* root, FILE* output){
    if(!root)
        return -1;

    if(root->nodetype==NODE_LEAF){
        int reg = getReg();

        switch(root->type){
            case TYPE_INT: 
                fprintf(output, "MOV R%d, %d\n", reg, root->val);
                break;
            case TYPE_STR: 
                fprintf(output, "MOV R%d, %s\n", reg, root->str_val);
                break;
            case TYPE_ID_INT:
            case TYPE_ID_STR: {
                
                int addr = root->STentry->binding;
                
                if(root->STentry->isArray){
                    int offset = exprEvaluate(root->left, output);

                    int temp = getReg();

                    fprintf(output, "MOV R%d, %d\n", temp, addr);
                    fprintf(output, "ADD R%d, R%d\n", temp, offset);
                    fprintf(output, "MOV R%d, [R%d]\n", reg, temp);

                    freeReg(temp);
                    freeReg(offset);
                }
                else{
                    fprintf(output, "MOV R%d, [%d]\n", reg, addr);
                }
            }
        }

        return reg;
    }

    switch (root->nodetype){
        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV: {
            return exprEvaluate(root, output);
        }

        case NODE_READ:{
            readFromTerminal(output, root->left);
            return -1;
        }

        case NODE_WRITE:{
            int reg = exprEvaluate(root->left, output);

            writeToTerminal(output, reg);
            freeReg(reg);
            
            return -1;
        }

        case NODE_ASSIGN:{
            
            int addr = root->left->STentry->binding;
            int reg = exprEvaluate(root->right, output);
            
            if(root->left->STentry->isArray){
                int offset = exprEvaluate(root->left->left, output);
                int temp = getReg();

                fprintf(output, "MOV R%d, %d\n", temp, addr);
                fprintf(output, "ADD R%d, R%d\n", temp, offset);
                fprintf(output, "MOV [R%d], R%d\n", temp, reg);

                freeReg(temp);
                freeReg(offset);
            }
            else{
                fprintf(output, "MOV [%d], R%d\n", addr, reg);
            }

            freeReg(reg);
            return -1;
        }

        case NODE_CONNECTOR:{
            codeGen(root->left, output);
            codeGen(root->right, output);
            return -1;
        }

        case NODE_IF:
        case NODE_IFELSE:{
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

        default:
            return -1;
    }
}


void createOutput(struct tnode* root, FILE* output){

    // header for the executable
    fprintf(output, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(output, "ADD SP, 26\n");
    int r = codeGen(root, output);

    freeReg(r);
    exitProg(output);
}