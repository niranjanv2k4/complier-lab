#ifndef SYMBOL_H
#define SYMBOL_H

#include "../main.h"
#include <string.h>

extern struct GSymbolTable* GST;
extern struct LSymbolTable* LST;

struct GSymbolTable* insertToGlobal(struct GSymbolTable* head, struct tnode* id, int type, int rowSize, int colSize, struct param* list, bool isFunct);


struct GSymbolTable* GSTLookup(struct GSymbolTable* head, char* name);
void printGST(struct GSymbolTable* head);


void Assign(struct GSymbolTable* head, struct tnode* id, struct tnode* expr);
void setType(struct GSymbolTable* head, struct tnode* id);


/* parameter functions  */
struct param* createParam(int type, struct tnode* id);
struct param* appendParam(struct param* head, struct param* node);
void validateFunct(struct GSymbolTable* list, int type, struct tnode* id, struct param* paramlist);


/* Managing local variables*/
struct LSymbolTable* createLST(struct LSymbolTable* LST, struct tnode* id, int type);
#endif