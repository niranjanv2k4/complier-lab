#ifndef SYMBOL_H
#define SYMBOL_H

#include "../main.h"
#include <string.h>

extern struct Gnode* list;
extern struct PairList* pairs;

struct Gnode* lookup(struct Gnode* head, char* name);
struct Gnode* insert(struct Gnode* head, struct tnode* id, char* typeName, int type, int rowSize, int colSize, bool isArray);
void printST(struct Gnode* head);


void Assign(struct Gnode* head, struct tnode* id, struct tnode* expr);
void setType(struct Gnode* head, struct tnode* id);

struct PairList* installPair(char* name, int first, int second);
struct PairList* Plookup(char* name);

#endif