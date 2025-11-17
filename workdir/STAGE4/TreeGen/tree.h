#ifndef TREE_H
#define TREE_H

#include "../main.h"
#include "../symbolTable/symbol.h"

struct tnode* createLeafNode(int type, char* varname, int val, char* str_val);
struct tnode* createTreeNode(int nodetype, struct tnode* left, struct tnode* right);

struct tnode* createArrayNode(struct tnode* id, struct tnode* row, struct tnode* col);

struct tnode* createDerefNode(struct tnode* id);
struct tnode* createAddrNode(struct tnode* id);
void isValid(struct tnode* id, int index);

struct tnode* createPairNode(int nodetype, struct tnode* id);

#endif