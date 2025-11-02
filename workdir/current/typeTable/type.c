#include "type.h"

struct Typetable *TypeTable = NULL;
int Fieldindex = 1;

static struct Typetable *newType(char *name, int size, struct Fieldlist *fields, int category) {
    struct Typetable *t = (struct Typetable *)malloc(sizeof(struct Typetable));
    t->name = strdup(name);
    t->size = size;
    t->fields = fields;
    t->next = NULL;
    t->category = category;
    return t;
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

static struct Fieldlist *newField(char *name, struct Typetable *type, int index) {
    struct Fieldlist *f = (struct Fieldlist *)malloc(sizeof(struct Fieldlist));
    f->name = strdup(name);
    f->type = type;
    f->fieldIndex = index;
    f->next = NULL;
    return f;
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

void TypeTableCreate() {
    TInstall("int", 1, NULL, TYPE_PRIMITIVE);
    TInstall("str", 1, NULL, TYPE_PRIMITIVE);
    TInstall("bool", 1, NULL, TYPE_PRIMITIVE);
    TInstall("int ptr", 1, NULL, TYPE_PRIMITIVE);
    TInstall("str ptr", 1, NULL, TYPE_PRIMITIVE);
    TInstall("void", 1, NULL, TYPE_PRIMITIVE);
}

struct Typetable *TInstall(char *name, int size, struct Fieldlist *fields, int category) {
    if (TLookup(name) != NULL) {
        printf("Type Error: Type '%s' already exists.\n", name);
        exit(1);
    }

    struct Typetable *newTypeEntry = newType(name, size, fields, category);
    newTypeEntry->next = TypeTable;
    TypeTable = newTypeEntry;
    return newTypeEntry;
}

struct Fieldlist* createField(struct Typetable* type, struct ASTNode* id){
    struct Fieldlist* node = malloc(sizeof(struct Fieldlist));

    node->name = strdup(id->name);
    node->fieldIndex = Fieldindex++;
    node->type = type;
    node->next = NULL;

    return node;
}
struct Fieldlist* appendField(struct Fieldlist* head, struct Fieldlist* node){

    if(!head)
        return node;

    struct Fieldlist* temp = head;

    while(temp->next){
        if(strcmp(temp->name, node->name) == 0){
            printf("Error: '%s' already exits in the tuple\n", temp->name);
            exit(1);
        }
        temp = temp->next;
    }

    temp->next = node;
    return head;
}

/* for setting the fields and size for the user defined structures */
struct Typetable* updateUserDefined(char* name, struct Fieldlist* fields){

    if(fields == NULL){
        printf("Error: Atleast one field is required\n");
        exit(1);
    }

    struct Typetable* table = TLookup(name);
    
    struct Fieldlist* temp = fields;

    int size = 0;
    while(temp){
        temp = temp->next;
        size++;
    }

    if(size > HB_SIZE){
        printf("Error: maximum number of fields permitted is 8, '%s' have %d fields\n", name, size);
        exit(1);
    }

    table->size = size;
    table->fields = fields;

    Fieldindex = 1;
    return table;
}


/* printing the type table */
void PrintTypeTable() {
    struct Typetable *t = TypeTable;
    printf("------ Type Table ------\n");
    printf("%-15s %-10s %-15s\n", "Name", "Size", "Fields");
    while (t) {
        printf("%-15s %-10d ", t->name, t->size);
        struct Fieldlist *f = t->fields;
        while (f) {
            printf("%s(%s - %d)", f->name, f->type->name, f->fieldIndex);
            f = f->next;
            if(f)
                printf(", ");
        }
        printf("\n");
        t = t->next;
    }
    printf("------------------------\n");
}