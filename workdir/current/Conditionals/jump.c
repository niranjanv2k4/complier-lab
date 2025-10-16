#include "jump.h"

struct ASTNode* createIfNode(struct ASTNode* CondNode, struct ASTNode* ifNode, struct ASTNode* elseNode){
    if(CondNode->type!=TLookup("bool")){
        printf("Type mismatch!\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->Gentry = NULL;
    node->Lentry = NULL;

    node->type = TLookup("void");

    node->nodetype = NODE_IF;

    node->ptr1 = CondNode;
    node->ptr2 = ifNode;
    node->ptr3 = elseNode;

    return node;
}

struct ASTNode* createLoopNode(int nodetype, struct ASTNode* CondNode, struct ASTNode* Slist){
    if(CondNode->type!=TLookup("bool")){
        printf("Type mismatch!\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->Gentry = NULL;
    node->Lentry = NULL;

    node->type = TLookup("void");

    node->nodetype = nodetype;

    node->ptr1 = CondNode;
    node->ptr2 = Slist;

    return node;
}

struct ASTNode* createControlFlowNode(int nodetype){
    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = nodetype;
    node->type = TLookup("void");

    return node;
}