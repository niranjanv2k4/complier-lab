#ifndef TREE_H
#define TREE_H

#include "../main.h"

struct tnode* createLeafNode(int type, char* varname, int val);
struct tnode* createTreeNode(int nodetype, struct tnode* left, struct tnode* right);

#endif