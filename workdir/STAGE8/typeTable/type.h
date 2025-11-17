#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"

struct ASTNode;

extern struct Typetable *TypeTable;
extern int Fieldindex;

void TypeTableCreate();
struct Typetable *TLookup(char *name);
struct Typetable *TInstall(char *name, int size, struct Fieldlist *fields, int category);
void PrintTypeTable();

struct Fieldlist *FLookup(struct Fieldlist *fieldList, char *name);

struct Fieldlist *createField(char* type, char* id);
struct Fieldlist *appendField(struct Fieldlist* head, struct Fieldlist* node);

struct Typetable* updateUserDefined(char* name, struct Fieldlist* fields);

#endif 
