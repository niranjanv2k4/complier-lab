#ifndef EXPR_TREE_H  // change this to a unique name
#define EXPR_TREE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct tnode{
    bool flag;
    int val;
    char *op;
    struct tnode* l;
    struct tnode* r;

};

typedef struct tnode tnode;

struct tnode *makeLeafNode(int val);
struct tnode *makeOperatorNode(char op, struct tnode *l, struct tnode *r);
int evaluate(struct tnode *root);


void preorder(struct tnode *root);
void inorder(struct tnode *root);

#endif