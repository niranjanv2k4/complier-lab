#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct tnode{
    int val;
    char *op;
    struct tnode *l;
    struct tnode *r;
};

struct tnode *createLeafNode(int val);
struct tnode *createInternalNode(char op, struct tnode* l, struct tnode* r);
int calc(struct tnode* root);

void prefix(struct tnode* root);
void postfix(struct tnode* root);
void infix(struct tnode* root);

/*REGISTER MANAGING*/
int getReg();
int freeReg(int r);


/*CODE GENERATION*/

void execGen(struct tnode* root, FILE* ptr);

int codeGen(struct tnode* root, FILE* ptr);
void printRes(FILE* ptr, int r);
void exitProg(FILE* ptr);


#endif