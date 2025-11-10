#include "./class.h"
#include "../typeTable/type.h"
#include "../symbolTable/symbol.h"

struct Classtable* CTable = NULL;
static int Flabel = 0;
static int fieldIndex = 0;
int funcposition = 0;

struct Classtable* CLookup(char* name){
    struct Classtable* temp = CTable;

    while(temp){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Fieldlist* ClassFLookup(struct Classtable* class, char* name){
    struct Fieldlist* temp = class->fields;
    while(temp){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Methodlist* ClassMLookup(struct Classtable* class, char* name){
    struct Methodlist* temp = class->methods;
    while(temp){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

static struct Methodlist* createMethod(char* name, struct Typetable* type, struct param* paramlist){
    struct Methodlist* node = malloc(sizeof(struct Methodlist));

    node->name = strdup(name);
    node->type = type;
    node->paramlist = paramlist;
    node->funcposition = funcposition++;
    node->Flabel = Flabel++;
    node->next = NULL;

    return node;
}

static struct Classtable* createClass(char* name, char* parent){
    struct Classtable* node = malloc(sizeof(struct Classtable));

    node->name = strdup(name);
    node->fields = NULL;
    node->methods = NULL;
    node->parent = parent?CLookup(parent):NULL;
    node->fieldcount = 0;
    node->classindex = -1;
    node->methodcount = 0;
    node->next = NULL;

    return node;
}

void ClassFInstall(struct Classtable* class, char* type, char* name){

    if(ClassFLookup(class, name)){
        printf("Error: '%s' method is already declared\n", name);
        exit(1);
    }
\
    struct Fieldlist* node = malloc(sizeof(struct Fieldlist));

    node->name = name;
    node->type = TLookup(type);
    node->class = CLookup(type);
    node->next = NULL;
    node->fieldIndex = fieldIndex++;

    if(class->fields == NULL){
        class->fields = node;
        class->fieldcount = 1;
        return;
    }

    struct Fieldlist* temp = class->fields;
    
    while(temp->next){
        temp = temp->next;
    }

    class->fieldcount++;
    temp->next = node;
}

void ClassMInstall(struct Classtable* class, char* type, char* name, struct param* paramlist){
    if(ClassMLookup(class, name)){
        printf("Error: '%s' method is already declared\n", name);
        exit(1);
    }
    
    struct Methodlist* node = createMethod(name, TLookup(type), paramlist);

    if(!class->methods){
        class->methods = node;
        class->methodcount = 1;
        return;
    }

    struct Methodlist* temp = class->methods;
    while(temp->next){
        temp = temp->next;
    }

    class->methodcount++;
    temp->next = node;
}


struct Classtable* CInstall(char* name, char* parent){

    if(CLookup(name)){
        printf("Error: '%s' class already declared\n", name);
        exit(1);
    }
    if(TLookup(name)){
        printf("Error: '%s' user defined already declared\n", name);
        exit(1);
    }

    struct Classtable* node = createClass(name, parent);

    if(!CTable){
        CTable = node;
        return node;
    }

    struct Classtable* temp = CTable;

    while(temp->next){
        temp = temp->next;
    } 
    temp->next = node;

    return node;
}

void PrintClassTable() {
    struct Classtable *t = CTable;
    printf("------ Class Table ------\n");
    printf("%-15s %-15s %-15s %-15s\n", "Name", "Field", "Methods", "Fields");
    while (t) {
        printf("%-15s %-15d %-15d", t->name, t->fieldcount, t->methodcount);
        struct Fieldlist *f = t->fields;
        while (f) {
            printf("%s(%s)", f->name, f->type?f->type->name:f->class->name);
            f = f->next;
            if(f)
                printf(", ");
        }
        struct Methodlist *m = t->methods;
        if(m)printf(", ");
        while(m){
            printf("%s(%s)", m->name, m->type->name);
            m = m->next;
            if(m)
                printf(", ");
        }
        printf("\n");
        t = t->next;
    }
    printf("------------------------\n");
}



void validateMethod(struct Typetable* type, char* id, struct param* paramlist, struct ASTNode* code){

    struct Typetable* temp = TLookup(type->name);

    if(temp==NULL){
        printf("Error: No Class '%s' declared\n", type->name);
        exit(1);
    }

    struct Methodlist* method = ClassMLookup(current_class, id);

    if(method == NULL){
        printf("Error: No method named '%s' declared\n", id);
        exit(1);
        printf("Error: Conflicting type for '%s'\n", method->name);
        exit(1);
    }

    struct param* declared = method->paramlist;
    struct param* defined = paramlist;

    while(defined && declared){
        if(strcmp(defined->name, declared->name)!=0){
            printf("Error: Unknown parameter '%s'\n", defined->name);
            exit(1);
        }
        if(defined->type != declared->type || (declared->isPointer != defined->isPointer)){
            printf("Error: Conflicting types for '%s' in '%s'\n",defined->name, id);
            exit(1);
        }
        defined = defined->next;
        declared = declared->next;
    }

    if(defined || declared){
        printf("Different parameter numbers\n");
        exit(1);
    }

    int relativeAddr = -3;
    struct LSymbol* tempLST = LST;

    struct param* tempParamlist = paramlist;
    while(tempParamlist){
        relativeAddr--;
        tempParamlist = tempParamlist->next;
    }

    while(tempLST){
        if(relativeAddr == -3)
            relativeAddr = 1;
        tempLST->binding = relativeAddr++;
        tempLST=tempLST->next;
    }

    struct param* prev = NULL;
    while(paramlist){
        prev = paramlist;
        paramlist = paramlist->next;
        free(prev);
    }

    paramlist = NULL;
    funcposition = 0;
}

void validateAndSetType(struct ASTNode* node){
    if(node->name){
        setType(node);
    }else{
        if(node->nodetype == NODE_METHOD){
            printf("Error: Missing arguments\n");
            exit(1);
        }
    }
}