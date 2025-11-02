#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"

// Forward declaration of ASTNode
struct ASTNode;

// Field list structure
struct Fieldlist {
    char *name;
    struct Typetable *type;
    int fieldIndex;
    struct Fieldlist *next;
};

// Type table structure
struct Typetable {
    char *name;
    int size;
    int category;
    struct Fieldlist *fields;
    struct Typetable *next;
};

// Global type table pointer and field index
extern struct Typetable *TypeTable;
extern int Fieldindex;

// Type table functions
void TypeTableCreate();
struct Typetable *TLookup(char *name);
struct Typetable *TInstall(char *name, int size, struct Fieldlist *fields, int category);
void PrintTypeTable();

// Field list functions
struct Fieldlist *FLookup(struct Fieldlist *fieldList, char *name);
// struct Fieldlist *FInstall(struct Fieldlist *fieldList, char *name, struct Typetable *type);

// Tuple-specific functions
// struct Typetable *TInstallTuple(struct ASTNode* id, struct Fieldlist* fields);
struct Fieldlist *createField(struct Typetable* type, struct ASTNode* id);
struct Fieldlist *appendField(struct Fieldlist* head, struct Fieldlist* node);

struct Typetable* updateUserDefined(char* name, struct Fieldlist* fields);

#endif // TYPE_H
