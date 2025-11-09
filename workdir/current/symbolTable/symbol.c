#include "./symbol.h"
#include "../classTable/class.h"


int currBinding = STACK_BASE;
static int Flabel = 0;

int getMem(int size){
    int mem = currBinding;
    currBinding += size;
    return mem;
}

struct GSymbol* GSTLookup(char* name){
    struct GSymbol* temp = GST;

    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct LSymbol* LSTLookup(char* name){
    struct LSymbol* temp = LST;

    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct GSymbol* insertToGlobal(char* id, int size, int rowSize, int colSize, struct param* list, int nodetype){

    if(GSTLookup(id)!=NULL){
        printf("Variable '%s' already declared\n", id);
        exit(1);
    }

    struct GSymbol* node = malloc(sizeof(struct GSymbol));

    node->name = id;

    node->size = (colSize*rowSize != 0)?colSize*rowSize:1;
    node->type = current_type;
    node->class = current_class;

    node->rowSize = rowSize;
    node->colSize = colSize;
    node->binding = -1;
    node->flabel = -1;
    node->paramlist = list;

    /* NO LABEL IF IT IS A FUNCTION */
    if(nodetype == NODE_FUNCT){
        node->flabel = Flabel++;
    }else{
        node->binding = getMem(node->size);
    }

    node->next = NULL;

    if(GST==NULL){
        return node;
    }
    struct GSymbol* temp = GST;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;

    list = NULL;

    return GST;
}

/* FUNCTIONS FOR CREATING PARAMLIST */
struct param* createParam(char* type_name, char* id){

    struct Typetable* type = TLookup(type_name);

    if(type == NULL){
        printf("Error: unknown type '%s' encountered\n", type_name);
        exit(1);
    }

    struct param* node = malloc(sizeof(struct param));
    node->next = NULL;

    node->name = id;
    node->type = type;

    LST = addParamtoLST(node);

    return node;
}
struct param* appendParam(struct param* head, struct param* node){

    if(!head)
        return node;
    
    struct param* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;
    return head;
}


/* ADDING PARAMETERS TO LST */
struct LSymbol* addParamtoLST(struct param* id) {

    if(LSTLookup(id->name)){
        printf("Error: '%s' already exist\n", id->name);
        exit(1);
    }
    
    struct LSymbol* node = malloc(sizeof(struct LSymbol));
    
    node->name = strdup(id->name);
    node->type = id->type;
    node->class = CLookup(id->type->name);

    node->next = NULL;

    if(LST == NULL)
        return node;

    struct LSymbol* temp = LST;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = node;

    return LST;
}
struct LSymbol* createLST(char* id, char* type){

    if(LSTLookup(id)){
        printf("Error: '%s' already exist\n", id);
        exit(1);
    }

    struct LSymbol* node = malloc(sizeof(struct LSymbol));

    node->name = id;
    node->type = TLookup(type);
    node->class = CLookup(type);
    node->next = NULL;

    if(LST == NULL)
        return node;

    struct LSymbol* temp = LST;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;

    return LST;
}


/* FUNCTIONS TO SET TYPES */
void setGType(struct ASTNode* id){
    struct GSymbol* temp = GSTLookup(id->name);
    if(temp==NULL){
        printf("Variable '%s' not declared.\n", id->name);
        exit(1);
    }

    id->Gentry = temp;
    id->type = temp->type;
    id->class= temp->class;

}

void setType(struct ASTNode* id){
    
    if(!id->name)
        return;
    
    struct LSymbol* temp = LST;
    while(temp){
        if(strcmp(temp->name, id->name)==0){
            break;
        }
        temp = temp->next;
    }


    if(temp == NULL){
        setGType(id);
        return;
    }

    id->type = temp->type;
    id->class = temp->class;
    id->Lentry = temp;

}

/* FUNCTION FOR VALIDATING THE FUNCTIONS */
void validateFunct(struct Typetable* type, char* id, struct param* paramlist, struct ASTNode* return_val){

    struct GSymbol* temp = GST;
    while(temp){
        if(strcmp(id, temp->name)==0){
            break;
        }
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Error: No function '%s' declared\n", id);
        exit(1);
    }else if(temp->flabel == -1){
        printf("Error: '%s' is not a function\n", id);
        exit(1);
    }
    else if(type != temp->type || return_val->ptr2->type != temp->type){
        printf("Error: Conflicting return types for '%s'\n", temp->name);
        exit(1);
    }

    struct param* declared = temp->paramlist;
    struct param* defined = paramlist;

    while(defined && declared){
        if(strcmp(defined->name, declared->name)!=0){
            printf("Error: Unknown parameter '%s'\n", declared->name);
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

    int relativeAddr = -2;
    struct LSymbol* tempLST = LST;

    struct param* tempParamlist = paramlist;
    while(tempParamlist){
        relativeAddr--;
        tempParamlist = tempParamlist->next;
    }

    while(tempLST){
        if(relativeAddr == -2)
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
}

void validateMain(struct ASTNode* node){
    if(node->ptr2->type != TLookup("int")){
        printf("Error: Conflicting  return type for 'main'\n");
        exit(1);
    }
    struct LSymbol* tempLST = LST;

    int relativeAddr = 1;
    while(tempLST){
        tempLST->binding = relativeAddr++;
        tempLST=tempLST->next;
    }
}


/* FUNCTION FOR PRINTING SYMBOL TABLES */
void printLST(char* name){
    struct LSymbol* t = LST;
    printf("FUNCTION - %s\n", name);
    printf("%-14s %-14s %-30s\n", "name", "type/class", "Fields");

    while(t){
        printf("%-14s %-14s ", t->name, t->type?t->type->name:t->class->name);

        if(t->type){
            if(t->type->fields){
                printf("  ");
                struct Fieldlist* f = t->type->fields;
                while(f){
                    printf("%s %s", f->type->name, f->name);
                    if(f->next) printf(", ");
                    f = f->next;
                }
            }
        }else if(t->class){
            if(t->class->fields){
                printf("  ");
                struct Fieldlist* f = t->class->fields;
                while(f){
                    printf("%s %s", f->type?f->type->name:f->class->name, f->name);
                    if(f->next) printf(", ");
                    f = f->next;
                }
            }
            if(t->class->methods){
                printf("  ");
                struct Methodlist* m = t->class->methods;
                while(m){
                    printf("%s %s", m->type->name, m->name);
                    if(m->next) printf(", ");
                    m = m->next;
                }
            }
        }
        printf("\n");
        t = t->next;
    }
    printf("\n");
}

void printGST(){
    struct GSymbol* temp = GST;
    printf("\t\tGST\n");
    printf("%-12s %-15s %-20s\n", "name", "type/class", "Parameters/Fields");

    while(temp){
        printf("%-12s %-10s ", temp->name, (temp->type!=NULL?temp->type->name:temp->class->name));

        if(temp->flabel != -1){
            printf("  ");
            struct param* list = temp->paramlist;
            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next) printf(", ");
                list = list->next;
            }
        } else if(temp->type && temp->type->fields){
            printf("  ");
            struct Fieldlist* list = temp->type->fields;
            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next) printf(", ");
                list = list->next;
            }
        } else if(temp->class){
            printf("  ");
            struct Fieldlist* f = temp->class->fields;
            while(f){
                printf("%s %s", f->type?f->type->name:f->class->name, f->name);
                if(f->next) printf(", ");
                f = f->next;
            }
            printf("  ");
            struct Methodlist* m = temp->class->methods;
            while(m){
                printf("%s %s", m->type->name, m->name);
                if(m->next) printf(", ");
                m = m->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
}


void clearLST() {
    struct LSymbol* temp;
    while (LST) {
        temp = LST;
        LST = LST->next;
        free(temp);
    }
    LST = NULL;
}

