#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


enum NodeType {
    NODE_LEAF      = 0,
    NODE_READ      = 1,
    NODE_WRITE     = 2,
    NODE_CONNECTOR = 3,
    NODE_ADD       = 4,
    NODE_SUB       = 5,
    NODE_MUL       = 6,
    NODE_DIV       = 7,
    NODE_ASSIGN    = 8
};

enum DataType {
    TYPE_INTERNAL = 0,
    TYPE_INT = 1,
    TYPE_ID  = 2
};

struct tnode{
    int val;
    int type;
    char *varname;
    int nodetype;
    struct tnode *left;
    struct tnode *right;
};

struct tnode* createLeafNode(int type, char* varname, int val);
struct tnode* createOperatorNode(int nodetype, struct tnode* left, struct tnode* right);

/* -----operators----- */
struct tnode* createAssignNode(struct tnode* left, struct tnode* right);
struct tnode* createWriteNode(struct tnode* exprNode);
struct tnode* createReadNode(struct tnode* idNode);
struct tnode* createConnecterNode(struct tnode* left, struct tnode* right);

int evaluate(struct tnode* root);


#endif