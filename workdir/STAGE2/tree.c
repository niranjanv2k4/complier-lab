#include "tree.h"

struct tnode* createOperatorNode(int nodetype, struct tnode* left, struct tnode* right){
    
    struct tnode* node = malloc(sizeof(struct tnode));

    node->nodetype = nodetype;
    node->left = left;
    node->right = right;

    return node;
}

struct tnode* createLeafNode(int type, char* varname, int val){
    struct tnode* node = malloc(sizeof(struct tnode));

    node->left = NULL;
    node->right = NULL;

    node->nodetype = NODE_LEAF;
    node->type  = type;
    node->val = val;
    node->varname = varname;

    return node;
}

struct tnode* createAssignNode(struct tnode* left, struct tnode* right){

    // r = leftside is a identifier node
    // l = rightside is a expression node

    struct tnode* node = malloc(sizeof(struct tnode));

    node->val = 0;
    node->type = TYPE_INTERNAL;
    node->varname = NULL;

    node->nodetype = NODE_ASSIGN;
    node->left = left;
    node->right = right;

    return node;

}

struct tnode* createWriteNode(struct tnode* exprNode){
    
    struct tnode* node = malloc(sizeof(struct tnode));

    node->nodetype = NODE_WRITE;
    node->left = exprNode;
    
    node->right = NULL;
    node->type = TYPE_INTERNAL;
    node->varname = NULL;
    node->val = 0;

    return node;

}

struct tnode* createReadNode(struct tnode* idNode){
    
    struct tnode* node = malloc(sizeof(struct tnode));

    node->nodetype = NODE_READ;
    node->left = idNode;
    
    node->right = NULL;
    node->type = TYPE_INTERNAL;
    node->varname = NULL;
    node->val = 0;

    return node;
    
}

struct tnode* createConnecterNode(struct tnode* left, struct tnode* right){

    struct tnode* node = malloc(sizeof(struct tnode));

    node->nodetype = NODE_CONNECTOR;
    node->left = left;
    node->right = right;

    node->val = 0;
    node->varname = NULL;
    node->type = TYPE_INTERNAL;

    return node;
}