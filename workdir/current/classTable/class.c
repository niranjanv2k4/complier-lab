#include "./class.h"
#include "../typeTable/type.h"
#include "../symbolTable/symbol.h"

struct Classtable* CTable = NULL;
static int Flabel = 0;
static int fieldIndex = 0;
int funcposition = 0;
int classindex = 0;

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

int compareParams(struct param* list1, struct param* list2, struct ASTNode* arglist) {
    struct param* temp1 = list1;
    if(list2){
        struct param* temp2 = list2;
        while (temp1 && temp2) {
            if (strcmp(temp1->type->name, temp2->type->name) != 0) {
                return 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return (!temp1 && !temp2); 
    }
    struct ASTNode* tempArglist = arglist;
    while(temp1 && tempArglist){

        if(strcmp(temp1->type->name, tempArglist->type->name) != 0){
            return 0;
        }
        temp1 = temp1->next;
        tempArglist = tempArglist->arglist;
    }

    return (!temp1 && !tempArglist);
}
struct Methodlist* ClassMLookup(struct Classtable* class, char* name, struct param* list, struct ASTNode* arglist, struct Typetable* type){
    struct Methodlist* temp = class->methods;
    while(temp){
        if(strcmp(temp->name, name) == 0 && compareParams(temp->paramlist, list, arglist)){
            if(type){
                if(type == temp->type){
                    return temp;
                }
            }else
                return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

static struct Methodlist* createMethod(char* name, struct Typetable* type, struct param* paramlist, int Flabel){
    struct Methodlist* node = malloc(sizeof(struct Methodlist));

    node->name = strdup(name);
    node->type = type;
    node->paramlist = paramlist;
    node->funcposition = funcposition++;
    node->Flabel = Flabel;
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
    node->classindex = classindex++;
    node->methodcount = 0;
    node->next = NULL;

    return node;
}

void ClassFInstall(struct Classtable* class, char* type, char* name, bool isProtected){

    if(ClassFLookup(class, name)){
        printf("Error: '%s' method is already declared\n", name);
        exit(1);
    }
    
    struct Fieldlist* node = malloc(sizeof(struct Fieldlist));

    node->name = name;
    node->type = TLookup(type);
    node->class = CLookup(type);
    node->next = NULL;
    node->isProtected = isProtected;
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
    if(ClassMLookup(class, name, paramlist, NULL, TLookup(type))){
        printf("Error: '%s' method is already declared\n", name);
        exit(1);
    }
    struct Methodlist* node = createMethod(name, TLookup(type), paramlist, Flabel++);

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

    int addr = getMem(MAX_FIELDS);

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

    struct Methodlist* method = ClassMLookup(current_class, id, paramlist, NULL, type);

    if(method == NULL){
        printf("Error: No method named '%s' declared\n", id);
        exit(1);
    }
    if(strcmp(type->name, method->type->name) != 0 || strcmp(type->name, code->ptr2->type->name) != 0){
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
        if(defined->type != declared->type){
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

    int relativeAddr = -4;
    struct LSymbol* tempLST = LST;

    struct param* tempParamlist = paramlist;
    while(tempParamlist){
        relativeAddr--;
        tempParamlist = tempParamlist->next;
    }

    while(tempLST){
        if(relativeAddr == -4)
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

void updateClassEntry() {
    funcposition = 0;

    if (!current_class) 
        return;
    struct Classtable* parent = current_class->parent;
    
    if (!parent) 
        return;

    int parent_field_count = parent->fieldcount;

    struct Fieldlist* cf = current_class->fields;
    while (cf) {
        cf->fieldIndex += parent_field_count;
        cf = cf->next;
    }

    struct Fieldlist* ph = NULL, *pt = NULL;
    struct Fieldlist* pf = parent->fields;
    while (pf) {
        if (ClassFLookup(current_class, pf->name)) {
            printf("Error: duplicate field '%s' from parent\n", pf->name);
            exit(1);
        }
        struct Fieldlist* nf = malloc(sizeof(struct Fieldlist));
        nf->name = strdup(pf->name);
        nf->type = pf->type;
        nf->class = pf->class;
        nf->fieldIndex = pf->fieldIndex;
        nf->next = NULL;
        if (!ph) ph = pt = nf;
        else { pt->next = nf; pt = nf; }
        pf = pf->next;
    }

    if (pt) { 
        pt->next = current_class->fields; 
        current_class->fields = ph; 
    }
    
    current_class->fieldcount = parent->fieldcount + current_class->fieldcount;

    struct Methodlist *mh = NULL, *mt = NULL;

    struct Methodlist* pm = parent->methods;
    while (pm) {
        struct Methodlist *prev = NULL, *cur = current_class->methods;
        struct Methodlist *childOverride = NULL;
        while (cur) {
            if (strcmp(cur->name, pm->name) == 0  && strcmp(cur->type->name, pm->type->name) == 0) {
                if (prev) 
                    prev->next = cur->next;
                else    
                    current_class->methods = cur->next;
                cur->next = NULL;
                childOverride = cur;
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (childOverride) {
            if (!mh) 
                mh = mt = childOverride;
            else { 
                mt->next = childOverride; 
                mt = childOverride; 
            }
        } else {
            struct Methodlist* inherited = createMethod(pm->name, pm->type, pm->paramlist, pm->Flabel);
            inherited->next = NULL;
            if (!mh) 
                mh = mt = inherited;
            else { 
                mt->next = inherited; 
                mt = inherited; 
            }
        }
        pm = pm->next;
    }

    struct Methodlist* rem = current_class->methods;
    while (rem) {
        struct Methodlist* next = rem->next;
        rem->next = NULL;
        if (!mh) 
            mh = mt = rem;
        else { 
            mt->next = rem; 
            mt = rem; 
        }
        rem = next;
    }

    current_class->methods = mh;

    int count = 0;
    struct Methodlist* t = current_class->methods;
    while (t) {
        t->funcposition = count++;
        t = t->next;
    }

    current_class->methodcount = count;

    if (current_class->fieldcount > MAX_FIELDS || count > MAX_FIELDS) {
        printf("Error: Max number of fields/methods allowed is %d\n", MAX_FIELDS);
        exit(1);
    }
}