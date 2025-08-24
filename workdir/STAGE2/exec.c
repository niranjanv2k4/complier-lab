#include "exec.h"

void writeToTerminal(FILE* output, int r);
void readFromTerminal(FILE* output, char a);
int exprEvaluate(struct tnode* root, FILE* output);

static uint32_t used = 0;

/* -----Register managing----- */
int getReg(){
    for(int i = 0; i<20; i++){
        if(!(used & (1u <<i))){
            used |= (1u <<i);
            return i;
        }
    }
    return -1;
}

int freeReg(int r){
    if(r>=0 && r<20 && (used & (1u <<r))){
        used &= ~(1u <<r);
        return 0;
    }
    return -1;
}


/* -----output generation----- */

void createOutput(struct tnode* root, FILE* output){

    // header for the executable
    fprintf(output, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(output, "ADD SP, 26\n");

    int r = codeGen(root, output);

    freeReg(r);
    exitProg(output);
}


int codeGen(struct tnode* root, FILE* output){
    if(!root)return -1;

    if(root->nodetype==NODE_LEAF){
        int reg = getReg();

        if(root->type == TYPE_INT){
            fprintf(output, "MOV R%d, %d\n", reg, root->val);
        }
        else if(root->type == TYPE_ID){
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

        default:
            return -1;
    }
}

void writeToTerminal(FILE* output, int r){

    int r1 = getReg();
    if(r1==-1){
        printf("Out of registers\n");
        exit(1);
    }

    fprintf(output, "MOV R%d, \"Write\"\nPUSH R%d\n", r1, r1);
    fprintf(output, "MOV R%d, -2\nPUSH R%d\n", r1, r1);

    fprintf(output, "PUSH R%d\n", r);
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
    int temp = getReg();

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
    int r = getReg();

    fprintf(output, "MOV R%d, \"Exit\"\nPUSH R%d\n", r, r);
    fprintf(output, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r, r, r, r);
    fprintf(output, "CALL 0");

    freeReg(r);
}


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
        else if(root->type==TYPE_ID){
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




static int arr[26] = {0};

int evaluate(struct tnode* root){

    if(!root)
        return -1;

    if(root->nodetype == NODE_LEAF){
        if(root->type == TYPE_INT){
            return root->val;
        }
        else if(root->type == TYPE_ID){
            return arr[root->varname[0] - 'a'];
        }
    }

    switch (root->nodetype){
        case NODE_ADD:
            return evaluate(root->left) + evaluate(root->right);
        case NODE_SUB:
            return evaluate(root->left) - evaluate(root->right);
        case NODE_MUL:
            return evaluate(root->left) * evaluate(root->right);
        case NODE_DIV:
            return evaluate(root->left) / evaluate(root->right);
        case NODE_ASSIGN:{
            arr[root->left->varname[0] - 'a'] = evaluate(root->right);
            return -1;
        }
        case NODE_CONNECTOR:{
            evaluate(root->left);
            evaluate(root->right);
            return -1;
        }
        case NODE_WRITE:{
            printf("%d\n", evaluate(root->left));
            return -1;
        }
        case NODE_READ:{
            int idx = root->left->varname[0] - 'a';
            scanf("%d", &arr[idx]);
            return -1;
        }
        default:
            return -1;  
    }
}

void evaluator(struct tnode* root){
    evaluate(root);

    for(int i = 0; i<26; i++){
        if(arr[i]!=0){
            printf("%c - %d\n", 'a' + i, arr[i]);
        }
    }
}