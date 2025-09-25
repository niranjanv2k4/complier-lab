#include "exec.h"

void writeToTerminal(FILE* output, int r);
void readFromTerminal(FILE* output, char a);
int exprEvaluate(struct tnode* root, FILE* output);

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

    int r1 = getReg();
    if(r1==-1){
        printf("Out of registers\n");
        exit(1);
    }

    fprintf(output, "MOV R%d, \"Write\"\nPUSH R%d\n", r1, r1);
    fprintf(output, "MOV R%d, -2\nPUSH R%d\n", r1, r1);

    fprintf(output, "PUSH R%d\n", reg);
    fprintf(output, "PUSH R%d\nPUSH R%d\n", r1, r1);

    fprintf(output, "CALL 0\n");

    fprintf(output, "POP R0\n");

    int r2 = getReg();
    fprintf(output, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", r2, r2, r2, r2);

    freeReg(r1);
    freeReg(r2);

}

void readFromTerminal(FILE* output, char a){

    int offset = a - 'a';

    int reg = getReg();

    fprintf(output, "MOV R%d, \"Read\"\nPUSH R%d\n", reg, reg);
    fprintf(output, "MOV R%d, -1\nPUSH R%d\n", reg, reg);

    fprintf(output, "MOV R%d, 4096\nADD R%d, %d\n", reg, reg, offset);

    fprintf(output, "PUSH R%d\nPUSH R%d\nPUSH R%d\n", reg, reg, reg);

    fprintf(output, "CALL 0\n");
    
    int r2 = getReg();
    fprintf(output, "POP R0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", r2, r2, r2, r2);

    freeReg(reg);
    freeReg(r2);
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
        if(root->type==TYPE_INT){
            fprintf(output, "MOV R%d, %d\n", reg, root->val);
        }
        else if(root->type==TYPE_ID_INT){
            int offset = root->varname[0] - 'a';

            fprintf(output, "MOV R%d, 4096\nADD R%d, %d\n", reg, reg, offset);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);

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
        if(root->type==TYPE_INT){
            fprintf(output, "MOV R%d, %d\n", reg, root->val);
        }
        else if(root->type==TYPE_ID_INT){
            int offset = root->varname[0] - 'a';

            fprintf(output, "MOV R%d, 4096\nADD R%d, %d\n", reg, reg, offset);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);

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
            fprintf(output, "LE R%d, R%d\n", left, right);
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

    fprintf(output, "JZ R%d, L%d\n", flag, startLabel);

    fprintf(output, "L%d:\n", endLabel);

    popLoop();
}

int codeGen(struct tnode* root, FILE* output){
    if(!root)
        return -1;

    if(root->nodetype==NODE_LEAF){
        int reg = getReg();

        if(root->type == TYPE_INT){
            fprintf(output, "MOV R%d, %d\n", reg, root->val);
        }
        else if(root->type == TYPE_ID_INT){
            int offset = root->varname[0] - 'a';

            fprintf(output, "MOV R%d, 4096\nADD R%d, %d\n", reg, reg, offset);
            fprintf(output, "MOV R%d, [R%d]\n", reg, reg);
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
            readFromTerminal(output, root->left->varname[0]);
            return -1;
        }

        case NODE_WRITE:{
            int reg = exprEvaluate(root->left, output);

            writeToTerminal(output, reg);
            freeReg(reg);
            
            return -1;
        }

        case NODE_ASSIGN:{
            int reg = exprEvaluate(root->right, output);
            int addr = getReg();
            int offset = root->left->varname[0] - 'a';

            fprintf(output, "MOV R%d, 4096\nADD R%d, %d\n", addr, addr, offset);
            fprintf(output, "MOV [R%d], R%d\n", addr, reg);

            freeReg(reg);
            freeReg(addr);

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
    fprintf(output, "BRKP\nADD SP, 26\n");

    int r = codeGen(root, output);

    freeReg(r);
    exitProg(output);
}






/* ------EVALUATOR------ */

#define SIGNAL_NONE 0
#define SIGNAL_BREAK 1
#define SIGNAL_CONTINUE 2

static int arr[26] = {0};
int evaluate(struct tnode* root, bool inLoop);

/*-----Helper for boolean evaluator-----*/
bool boolEvaluator(struct tnode* root){

    int left = evaluate(root->left, false);
    int right = evaluate(root->right, false);

    switch (root->nodetype){
        case NODE_LT: return left < right;
        case NODE_GT: return left > right;
        case NODE_LE: return left <= right;
        case NODE_GE: return left >= right;
        case NODE_EQ: return left == right;
        case NODE_NE: return left != right; 
        default: return false;
    }
}

int evaluate(struct tnode* root, bool inLoop){
    if(!root) return SIGNAL_NONE;

    if(root->nodetype == NODE_LEAF){
        if(root->type == TYPE_INT) return root->val;
        else if(root->type == TYPE_ID_INT) return arr[root->varname[0] - 'a'];
    }

    switch(root->nodetype){

        case NODE_ADD: return evaluate(root->left, inLoop) + evaluate(root->right, inLoop);
        case NODE_SUB: return evaluate(root->left, inLoop) - evaluate(root->right, inLoop);
        case NODE_MUL: return evaluate(root->left, inLoop) * evaluate(root->right, inLoop);
        case NODE_DIV: return evaluate(root->left, inLoop) / evaluate(root->right, inLoop);

        case NODE_ASSIGN:
            arr[root->left->varname[0] - 'a'] = evaluate(root->right, inLoop);
            return SIGNAL_NONE;

        case NODE_CONNECTOR: {
            int sig = evaluate(root->left, inLoop);
            if(sig != SIGNAL_NONE) return sig;
            return evaluate(root->right, inLoop);
        }

        case NODE_WRITE:
            printf("%d\n", evaluate(root->left, inLoop));
            return SIGNAL_NONE;

        case NODE_READ: {
            int idx = root->left->varname[0] - 'a';
            scanf("%d", &arr[idx]);
            return SIGNAL_NONE;
        }

        case NODE_IFELSE: {
            bool res = boolEvaluator(root->left);
            int sig = SIGNAL_NONE;
            if(res) sig = evaluate(root->right->left, inLoop);
            else if(root->right->right) sig = evaluate(root->right->right, inLoop);
            return sig;
        }

        case NODE_IF: {
            if(boolEvaluator(root->left))
                return evaluate(root->right->left, inLoop);
            return SIGNAL_NONE;
        }

        case NODE_WHILE: {
            while(boolEvaluator(root->left)){
                int sig = evaluate(root->right, true);
                if(sig == SIGNAL_BREAK) break;
                if(sig == SIGNAL_CONTINUE) continue;
            }
            return SIGNAL_NONE;
        }

        case NODE_RPTUTL: {
            int sig;
            do{
                sig = evaluate(root->right, true);
                if(sig == SIGNAL_BREAK) break;
                if(sig == SIGNAL_CONTINUE) continue;
            }
            while(!boolEvaluator(root->left));
            return SIGNAL_NONE;
        }
        case NODE_DOWHILE: {
            int sig;
            do{
                sig = evaluate(root->right, true);
                if(sig == SIGNAL_BREAK) break;
                if(sig == SIGNAL_CONTINUE) continue;
            }
            while(boolEvaluator(root->left));
            return SIGNAL_NONE;
        }

        case NODE_BREAK: return inLoop?SIGNAL_BREAK:SIGNAL_NONE;
        case NODE_CONTINUE: return inLoop?SIGNAL_CONTINUE:SIGNAL_NONE;

        default: return SIGNAL_NONE;
    }
}

void evaluator(struct tnode* root){
    evaluate(root, false);

    for(int i = 0; i<26; i++){
        if(arr[i]!=0){
            printf("%c - %d\n", 'a' + i, arr[i]);
        }
    }
}