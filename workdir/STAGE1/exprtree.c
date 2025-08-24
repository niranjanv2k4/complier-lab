#include "exprtree.h"


struct tnode* createLeafNode(int val){
    struct tnode* node = malloc(sizeof(struct tnode));

    node->op = NULL;
    node->val = val;
    node->l = node->r = NULL;

    return node;
}

struct tnode* createInternalNode(char op, struct tnode* l, struct tnode* r){
    struct tnode* node = malloc(sizeof(struct tnode));
    node->op = malloc(sizeof(char));

    *(node->op) = op;
    node->l = l;
    node->r = r;

    return node;
}


int calc(struct tnode* root){
    if(root->op==NULL){
        return root->val;
    }

    switch(*(root->op)){
        case '+': return calc(root->l) + calc(root->r);
        case '-': return calc(root->l) - calc(root->r);
        case '*': return calc(root->l) * calc(root->r);
        case '/': return calc(root->l) / calc(root->r);
    }

    return 0;
}


void prefix(struct tnode* root){
    if(!root)return;

    if(!root->op){
        printf("%d ", root->val);
    }else{
        printf("%c ", *(root->op));
    }
    prefix(root->l);
    prefix(root->r);
}

void postfix(struct tnode* root){
    if(!root)return;

    postfix(root->l);
    postfix(root->r);
    if(!root->op){
        printf("%d ", root->val);
    }else{
        printf("%c ", *(root->op));
    }
}

void infix(struct tnode* root){
    if(!root)return;

    postfix(root->l);
    if(!root->op){
        printf("%d ", root->val);
    }else{
        printf("%c ", *(root->op));
    }
    postfix(root->r);
}


/*------FUNCTIONS------*/


static uint32_t used = 0;

void execGen(struct tnode* root, FILE* ptr){

    fprintf(ptr, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    int r = codeGen(root, ptr);
    printRes(ptr, r);

    freeReg(r);
    exitProg(ptr);
}

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


int codeGen(struct tnode* root, FILE* ptr){
    if(!root->op){
        int reg = getReg();
        if(reg==-1){
            printf("Out of registers\n");
            exit(1);
        }
        fprintf(ptr, "MOV R%d, %d\n", reg, root->val);
        return reg;
    }

    int l = codeGen(root->l, ptr);
    int r = codeGen(root->r, ptr);
    switch(*(root->op)){
        case '+':   fprintf(ptr, "ADD R%d, R%d\n", l, r);
                    freeReg(r);
                    break;
        case '-':   fprintf(ptr, "SUB R%d, R%d\n", l, r);
                    freeReg(r);
                    break;
        case '*':   fprintf(ptr, "MUL R%d, R%d\n", l, r);
                    freeReg(r);
                    break;
        case '/':   fprintf(ptr, "DIV R%d, R%d\n", l, r);
                    freeReg(r);
                    break;
    }

    return l;
}

void printRes(FILE* ptr, int r){
    
    fprintf(ptr, "MOV [4096], R%d\n", r);

    int r1 = getReg();
    if(r1==-1){
        printf("Out of registers\n");
        exit(1);
    }

    fprintf(ptr, "MOV R%d, \"Write\"\nPUSH R%d\n", r1, r1);
    fprintf(ptr, "MOV R%d, -2\nPUSH R%d\n", r1, r1);

    fprintf(ptr, "PUSH R%d\n", r);
    fprintf(ptr, "PUSH R%d\n", r1);
    fprintf(ptr, "PUSH R%d\n", r1);

    fprintf(ptr, "CALL 0\n");

    fprintf(ptr, "POP R0\n");
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);

    freeReg(r1);

}

void exitProg(FILE* ptr){
    int r = getReg();

    fprintf(ptr, "MOV R%d, \"Exit\"\nPUSH R%d\n", r, r);
    fprintf(ptr, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r, r, r, r);
    fprintf(ptr, "CALL 0");

    freeReg(r);
}


/* MODIFICATION */

struct tnode* modifyNode(struct tnode* node){
    node->val *=-1;
    return node;
}