#ifndef SYMBOL_H
#define SYMBOL_H

#include "../main.h"
#include "../typeTable/type.h"

extern struct GSymbol* GST;
extern struct LSymbol* LST;
extern int currBinding;

struct GSymbol* insertToGlobal(struct ASTNode* id, struct Typetable* type, int size, int rowSize, int colSize, struct param* list, int nodetype, bool isPointer);
struct GSymbol* insertTupleToGST(struct ASTNode* id, struct param* list);
struct GSymbol* GSTLookup(char* name);
void printGST();
void clearLST();


void setType(struct ASTNode* id);
void setGType(struct ASTNode* id);


/* parameter functions  */
struct param* createParam(char* type, struct ASTNode* id, bool isPointer);
struct param* appendParam(struct param* head, struct param* node);
void validateFunct(struct Typetable* type, struct ASTNode* id, struct param* paramlist, struct ASTNode* return_val);
struct LSymbol* addParamtoLST(struct param* list);

/* field functions */
struct Fieldlist* createField(struct Typetable* type, struct ASTNode* id);
struct Fieldlist* appendField(struct Fieldlist* head, struct Fieldlist* node);

/* Managing local variables*/
struct LSymbol* createLST(struct ASTNode* id, struct Typetable* type, bool sPointer);
struct LSymbol* LSTLookup(char* name);
void printLST(char* name);


void validateMain(struct ASTNode* node);

#endif