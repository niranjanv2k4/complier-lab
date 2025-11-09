#ifndef TREE_H
#define TREE_H

#include "../main.h"
#include "../typeTable/type.h"
#include "../symbolTable/symbol.h"
#include "../classTable/class.h"

struct ASTNode* createLeafNode(int nodetype, char* type, char* varname, int val, char* str_val);
struct ASTNode* createTreeNode(int nodetype, struct ASTNode* left, struct ASTNode* right);

struct ASTNode* createArrayNode(struct ASTNode* id, struct ASTNode* row, struct ASTNode* col);

struct ASTNode* createDerefNode(struct ASTNode* id);
struct ASTNode* createAddrNode(struct ASTNode* id);
// void isValid(struct ASTNode* id, int index);

/*---arguments list functions---*/

struct ASTNode* appendArgNode(struct ASTNode* list, struct ASTNode* expr);
struct ASTNode* createFunctNode(struct ASTNode* id, struct ASTNode* args);
struct ASTNode* createRtnNode(struct ASTNode* rtn);

struct ASTNode* createTupleNode(struct ASTNode* id, struct ASTNode* field);
struct ASTNode* createFieldAccessNode(struct ASTNode* ptr1, struct ASTNode* ptr2);
struct ASTNode* createDynamicNode(int nodetype, struct ASTNode* id);
struct ASTNode* createClassNode(int nodetype, struct ASTNode* id, char* baseClass);

#endif