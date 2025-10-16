#ifndef JUMP_H
#define JUMP_H

#include "../main.h"
#include "../TreeGen/tree.h"
#include "../typeTable/type.h"

struct ASTNode* createIfNode(struct ASTNode* CondNode, struct ASTNode* ifNode, struct ASTNode* elseNode);
struct ASTNode* createControlFlowNode(int nodetype);
struct ASTNode* createLoopNode(int nodetype, struct ASTNode* CondNode, struct ASTNode* stmt);

#endif