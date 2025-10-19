#include "type.h"

struct Typetable *TypeTable = NULL;

static struct Typetable *newType(char *name, int size, struct Fieldlist *fields) {
    struct Typetable *t = (struct Typetable *)malloc(sizeof(struct Typetable));
    t->name = strdup(name);
    t->size = size;
    t->fields = fields;
    t->next = NULL;
    return t;
}

static struct Fieldlist *newField(char *name, struct Typetable *type, int index) {
    struct Fieldlist *f = (struct Fieldlist *)malloc(sizeof(struct Fieldlist));
    f->name = strdup(name);
    f->type = type;
    f->fieldIndex = index;
    f->next = NULL;
    return f;
}

void TypeTableCreate() {
    TInstall("int", 1, NULL);
    TInstall("str", 1, NULL);
    TInstall("bool", 1, NULL);
    TInstall("int ptr", 1, NULL);
    TInstall("str ptr", 1, NULL);
    TInstall("void", 0, NULL);
}

struct Typetable *TLookup(char *name) {
    struct Typetable *temp = TypeTable;
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Typetable *TInstall(char *name, int size, struct Fieldlist *fields) {
    if (TLookup(name) != NULL) {
        printf("Type Error: Type '%s' already exists.\n", name);
        exit(1);
    }

    struct Typetable *newTypeEntry = newType(name, size, fields);
    newTypeEntry->next = TypeTable;
    TypeTable = newTypeEntry;
    return newTypeEntry;
}

struct Fieldlist *FLookup(struct Fieldlist *fieldList, char *name) {
    struct Fieldlist *temp = fieldList;
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Fieldlist *FInstall(struct Fieldlist *fieldList, char *name, struct Typetable *type) {
    if (FLookup(fieldList, name)) {
        printf("Field Error: Field '%s' already exists.\n", name);
        exit(1);
    }

    int index = 0;
    struct Fieldlist *temp = fieldList;
    if (temp) {
        while (temp->next) temp = temp->next;
        index = temp->fieldIndex + 1;
    }

    struct Fieldlist *newFieldEntry = newField(name, type, index);

    if (!fieldList)
        return newFieldEntry;

    temp->next = newFieldEntry;
    return fieldList;
}

void PrintTypeTable() {
    struct Typetable *t = TypeTable;
    printf("------ Type Table ------\n");
    printf("%-15s %-10s %-15s\n", "Name", "Size", "Fields");
    while (t) {
        printf("%-15s %-10d ", t->name, t->size);
        struct Fieldlist *f = t->fields;
        while (f) {
            printf("%s(%s) ", f->name, f->type->name);
            f = f->next;
        }
        printf("\n");
        t = t->next;
    }
    printf("------------------------\n");
}

struct Typetable* TInstallTuple(struct ASTNode* id, struct param* list){
    if(TLookup(id->name)!=NULL){
        printf("Type '%s' already declared\n", id->name);
        exit(1);
    }
    
    if(list == NULL){
        printf("Error: Atleast one field is required\n");
        exit(1);
    }

    struct Fieldlist* fields = NULL;
    struct param* temp = list;

    int size = 0;
    while(temp){
        fields = FInstall(fields, temp->name, temp->type);
        temp = temp->next;
        size++;
    }

    return TInstall(id->name, size, fields);
}