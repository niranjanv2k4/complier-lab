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

struct GSymbol* insertToGlobal(struct ASTNode* id, struct Typetable* type, int rowSize, int colSize, struct param* list, int nodetype){

    if(GSTLookup(id->name)!=NULL){
        printf("Variable '%s' already declared\n", id->name);
        exit(1);
    }

    struct GSymbol* node = malloc(sizeof(struct GSymbol));

    node->name = strdup(id->name);
    
    node->type = type;

    node->rowSize = rowSize;
    node->colSize = colSize;

    node->size = rowSize*colSize;

    /* NO LABEL IF IT IS A FUNCTION */
    if(nodetype == NODE_FUNCT){
        node->binding = -1;
        node->paramlist = list;
        node->flabel = functionLabel++;
    
    }else{
        node->binding = getMem(node->size);
        node->paramlist = NULL;
        node->flabel = -1;
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

    return GST;
}

struct param* createParam(struct Typetable* type, struct ASTNode* id){
    struct param* node = malloc(sizeof(struct param));

    node->name = malloc(strlen(id->name)+1);
    strcpy(node->name, id->name);

    node->type = type;
    node->next = NULL;

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

struct LSymbol* createLST(struct ASTNode* id, struct Typetable* type){

    struct LSymbol* node = malloc(sizeof(struct LSymbol));

    node->name = strdup(id->name);

    // if(TLookup("int") == type){
    //     node->type = isPtr? TLookup("int ptr"):TLookup("int");
    // }else{
    //     node->type = isPtr? TLookup("str ptr"):TLookup("str");
    // }

    node->type = type;
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

}

/* ADDING PARAMETERS TO LST */
struct LSymbol* addParamtoLST(struct param* id) {
    
    struct LSymbol* node = malloc(sizeof(struct LSymbol));
    
    node->name = strdup(id->name);
    node->type = id->type;
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
            printf("Unknown parameter '%s'\n", declared->name);
            exit(1);
        }
        if(defined->type != declared->type){
            printf("Conflicting types for '%s' in '%s'\n",defined->name, id->name);
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
void printLST(){
    struct LSymbol* temp = LST;
    
    printf("name\ttype\tbinding\n");

    while(temp){
        printf("%s\t%s\t%d\n", temp->name, temp->type->name, temp->binding);
        temp = temp->next;
    }
    printf("\n");
}

void printGST(){
    struct GSymbol* temp = GST;
    printf("\t\tGST\t\t");
    printf("\nname\ttype\tsize\tbinding\tFlabel\n");

    while(temp){

        printf("%s\t%s\t%d\t%d\t%d\t", temp->name, temp->type->name, temp->size, temp->binding, temp->flabel);

        if(temp->flabel!=-1){

            printf("\tParameters: ");
            struct param* list = temp->paramlist;

            while(list){
                printf("%s %s", list->type->name, list->name);
                if(list->next)
                    printf(", ");
                list = list->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
}