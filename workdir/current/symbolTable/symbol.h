#ifndef SYMBOL_H
#define SYMBOL_H

#include "../main.h"
#include "../constant.h"
#include "../typeTable/type.h"

extern struct GSymbol* GST;
extern struct LSymbol* LST;
extern int currBinding;

struct GSymbol* insertToGlobal(struct ASTNode* id, struct Typetable* type, int rowSize, int colSize, struct param* list, int nodetype);
struct GSymbol* GSTLookup(char* name);
void printGST();


void setType(struct ASTNode* id);
void setGType(struct ASTNode* id);


/* parameter functions  */
struct param* createParam(struct Typetable* type, struct ASTNode* id);
struct param* appendParam(struct param* head, struct param* node);
void validateFunct(struct Typetable* type, struct ASTNode* id, struct param* paramlist, struct ASTNode* return_val);
struct LSymbol* addParamtoLST(struct param* list);

/* Managing local variables*/
struct LSymbol* createLST(struct ASTNode* id, struct Typetable* type);
struct LSymbol* LSTLookup(char* name);
void printLST(char* name);


void validateMain(struct ASTNode* node);

#endif