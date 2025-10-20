#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"
struct Fieldlist;

struct Typetable {
    char *name;                  
    int size;                    
    struct Fieldlist *fields;    
    struct Typetable *next;      
};


struct Fieldlist {
    char *name;                  
    struct Typetable *type;      
    int fieldIndex;              
    struct Fieldlist *next;      
};


extern struct Typetable *TypeTable;

void TypeTableCreate();  
struct Typetable *TLookup(char *name);
struct Typetable *TInstall(char *name, int size, struct Fieldlist *fields);
struct Fieldlist *FLookup(struct Fieldlist *fieldList, char *name);
struct Fieldlist *FInstall(struct Fieldlist *fieldList, char *name, struct Typetable *type);
void PrintTypeTable();
struct Typetable* TInstallTuple(struct ASTNode* id, struct Fieldlist* fields);
#endif
