#include "jump.h"

struct tnode* createIfNode(struct tnode* CondNode, struct tnode* ifNode, struct tnode* elseNode){
    if(CondNode->type!=TYPE_BOOLEAN){
        printf("Type mismatch!\n");
        exit(1);
    }

    struct tnode* node = malloc(sizeof(struct tnode));

    node->val = 0;
    node->varname = NULL;
    node->STentry = NULL;
    node->str_val = NULL;
    node->type = NO_TYPE;

    node->nodetype = elseNode?NODE_IFELSE:NODE_IF;
    node->left = CondNode;
    node->right = createTreeNode(NODE_CONNECTOR, ifNode, elseNode);

    return node;
}

struct tnode* createLoopNode(int nodetype, struct tnode* CondNode, struct tnode* Slist){
    if(CondNode->type!=TYPE_BOOLEAN){
        printf("Type mismatch!\n");
        exit(1);
    }

    struct tnode* node = malloc(sizeof(struct tnode));

    node->val = 0;
    node->varname = NULL;
    node->STentry = NULL;
    node->str_val = NULL;
    node->type = NO_TYPE;

    node->nodetype = nodetype;
    node->left = CondNode;
    node->right = Slist;

    return node;
}

struct tnode* createControlFlowNode(int nodetype){
    struct tnode* node = malloc(sizeof(struct tnode));

    node->nodetype = nodetype;
    node->type = NO_TYPE;

    return node;
}