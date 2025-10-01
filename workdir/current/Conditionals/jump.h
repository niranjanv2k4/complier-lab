#ifndef JUMP_H
#define JUMP_H

#include "../main.h"
#include "../TreeGen/tree.h"

struct tnode* createIfNode(struct tnode* CondNode, struct tnode* ifNode, struct tnode* elseNode);
struct tnode* createControlFlowNode(int nodetype);
struct tnode* createLoopNode(int nodetype, struct tnode* CondNode, struct tnode* stmt);

#endif