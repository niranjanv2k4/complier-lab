#ifndef CLASS_H
#define CLASS_H

#include "../main.h"

extern struct Classtable* CTable;
extern struct LSymbol* LST;
extern struct Classtable* current_class;
extern struct Typetable* current_type;

struct Classtable* CLookup(char* name);
struct Fieldlist* ClassFLookup(struct Classtable* class, char* name);
struct Methodlist* ClassMLookup(struct Classtable* class, char* name, struct param* paramlist, struct ASTNode* arglist, struct Typetable* type);
void ClassFInstall(struct Classtable* class, char* type, char* name, bool isProtected);
void ClassMInstall(struct Classtable* class, char* type, char* name, struct param* paramlist);
struct Classtable* CInstall(char* name, char* parent);
void PrintClassTable();


void validateMethod(struct Typetable* type, char* id, struct param* paramlist, struct ASTNode* code);
void validateAndSetType(struct ASTNode* node);

void updateClassEntry();

int compareParams(struct param* list1, struct param* list2, struct ASTNode* arglist);

#endif