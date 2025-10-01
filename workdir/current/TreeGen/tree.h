#ifndef TREE_H
#define TREE_H

#include "../main.h"

struct tnode* createLeafNode(int type, char* varname, int val, char* str_val);
struct tnode* createTreeNode(int nodetype, struct tnode* left, struct tnode* right);

struct tnode* createArrayNode(struct tnode* id, struct tnode* expr);

void isValid(struct tnode* id, int index);
#endif