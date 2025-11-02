#include "./symbol.h"


int currBinding = STACK_BASE;
int functionLabel = 0;

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

struct GSymbol* insertToGlobal(struct ASTNode* id, struct Typetable* type, int size, int rowSize, int colSize, struct param* list, int nodetype, bool isPointer){

    if(GSTLookup(id->name)!=NULL){
        printf("Variable '%s' already declared\n", id->name);
        exit(1);
    }

    struct GSymbol* node = malloc(sizeof(struct GSymbol));

    node->name = strdup(id->name);

    node->size = (colSize*rowSize != 0)?colSize*rowSize:1;
    node->type = type;

    node->rowSize = rowSize;
    node->colSize = colSize;
    node->isPointer = isPointer;
    node->binding = -1;
    node->flabel = -1;
    node->paramlist = list;

    /* NO LABEL IF IT IS A FUNCTION */
    if(nodetype == NODE_FUNCT){
        node->flabel = functionLabel++;
    }else{
        node->binding = getMem(node->size);
    }

    node->next = NULL;

    id->Gentry = node;
    id->type = type;

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
struct param* createParam(char* type_name, struct ASTNode* id, bool isPointer){

    struct Typetable* type = TLookup(type_name);

    if(type == NULL){
        printf("Error: unknown type '%s' encountered\n", type_name);
        exit(1);
    }

    struct param* node = malloc(sizeof(struct param));
    node->next = NULL;

    node->name = strdup(id->name);
    node->type = type;
    node->isPointer = isPointer;

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
    node->next = NULL;
    node->isPointer = id->isPointer;

    if(LST == NULL)
        return node;

    struct LSymbol* temp = LST;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = node;

    return LST;
}
struct LSymbol* createLST(struct ASTNode* id, struct Typetable* type, bool isPointer){

    if(LSTLookup(id->name)){
        printf("Error: '%s' already exist\n", id->name);
        exit(1);
    }

    struct LSymbol* node = malloc(sizeof(struct LSymbol));

    node->name = strdup(id->name);

    node->type = type;
    node->next = NULL;
    node->isPointer = isPointer;

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
    id->isPointer = temp->isPointer;
}

void setType(struct ASTNode* id){
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
    id->Lentry = temp;
    id->isPointer = temp->isPointer;

}

/* FUNCTION FOR VALIDATING THE FUNCTIONS */
void validateFunct(struct Typetable* type, struct ASTNode* id, struct param* paramlist, struct ASTNode* return_val){

    struct GSymbol* temp = GST;
    while(temp){
        if(strcmp(id->name, temp->name)==0){
            break;
        }
        temp = temp->next;
    }

    if(temp==NULL){
        printf("No function '%s' declared\n", id->name);
        exit(1);
    }else if(temp->flabel == -1){
        printf("'%s' is not a function\n", id->name);
        exit(1);
    }
    else if(type != temp->type || return_val->ptr2->type != temp->type){
        printf("Conflicting return types for '%s'\n", temp->name);
        exit(1);
    }

    id->Gentry = temp;

    struct param* declared = temp->paramlist;
    struct param* defined = paramlist;

    while(defined && declared){
        if(strcmp(defined->name, declared->name)!=0){
            printf("Error: Unknown parameter '%s'\n", declared->name);
            exit(1);
        }
        if(defined->type != declared->type || (declared->isPointer != defined->isPointer)){
            printf("Error: Conflicting types for '%s' in '%s'\n",defined->name, id->name);
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
    struct LSymbol* temp = LST;
    printf("FUNCTION - %s\n", name);
    printf("%-14s %-14s %-10s %-10s %-30s\n", "name", "type", "binding", "Pointer", "Fields");

    while(temp){
        printf("%-14s %-14s %-10d %-10s", temp->name, temp->type->name, temp->binding, temp->isPointer ? "Yes" : "No");

        if(temp->type->fields){
            printf("  ");
            struct Fieldlist* list = temp->type->fields;
            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next) printf(", ");
                list = list->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

void printGST(){
    struct GSymbol* temp = GST;
    printf("\t\tGST\n");
    printf("%-12s %-10s %-6s %-8s %-6s %-6s %-20s\n", "name", "type", "size", "binding", "Flabel", "Pointer", "Parameters/Fields");

    while(temp){
        printf("%-12s %-10s %-6d %-8d %-6d %-6s", temp->name, temp->type->name, temp->size, temp->binding, temp->flabel, temp->isPointer ? "Yes" : "No");

        if(temp->flabel != -1){
            printf("  ");
            struct param* list = temp->paramlist;
            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next) printf(", ");
                list = list->next;
            }
        } else if(temp->type->fields){
            printf("  ");
            struct Fieldlist* list = temp->type->fields;
            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next) printf(", ");
                list = list->next;
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

