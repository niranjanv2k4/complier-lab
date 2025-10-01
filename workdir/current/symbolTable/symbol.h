#ifndef SYMBOL_H
#define SYMBOL_H

#include "../main.h"
#include <string.h>

extern struct Gnode* list;

struct Gnode* lookup(struct Gnode* head, char* name);
struct Gnode* insert(struct Gnode* head, struct tnode* id, int type, int size, bool isArray);
void printST(struct Gnode* head);


void Assign(struct Gnode* head, struct tnode* id, struct tnode* expr);
void setType(struct Gnode* head, struct tnode* id);

#endif