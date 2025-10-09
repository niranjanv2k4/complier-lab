#include "./symbol.h"


int currBinding = STACK_BASE;
int functionLabel = 0;

int getMem(int size){
    int mem = currBinding;
    currBinding += size;
    return mem;
}


void setType(struct GSymbolTable* head, struct tnode* id){
    struct GSymbolTable* temp = GSTLookup(head, id->varname);
    if(temp==NULL){
        printf("Variable '%s' not declared.\n", id->varname);
        exit(1);
    }

    id->STentry = temp;
    id->type = temp->type;
}

struct GSymbolTable* GSTLookup(struct GSymbolTable* head, char* name){
    struct GSymbolTable* temp = head;

    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct GSymbolTable* insertToGlobal(struct GSymbolTable* head, struct tnode* id, int type, int rowSize, int colSize, struct param* list, bool isFunct){

    if(GSTLookup(head, id->varname)!=NULL){
        printf("Variable '%s' already declared\n", id->varname);
        exit(1);
    }

    struct GSymbolTable* node = malloc(sizeof(struct GSymbolTable));

    node->name = malloc(strlen(id->varname)+1);
    strcpy(node->name, id->varname);
    
    node->type = type;

    node->isFunct = isFunct;
    node->rowSize = rowSize;
    node->colSize = colSize;

    node->size = rowSize*colSize;

    /* NO LABEL IF IT IS A FUNCTION */
    if(isFunct){
        node->binding = -1;
        node->paramlist = list;
        node->flabel = functionLabel++;
    
    }else{
        node->binding = getMem(node->size);
        node->paramlist = NULL;
        node->flabel = -1;
    }

    node->next = NULL;

    id->STentry = node;
    id->type = type;

    if(head==NULL){
        return node;
    }
    struct GSymbolTable* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;

    return head;
}

void printGST(struct GSymbolTable* head){
    struct GSymbolTable* temp = head;
    
    printf("name\ttype\tsize\tbinding\tFlabel\n");

    while(temp){

        printf("%s\t%d\t%d\t%d\t%d\t", temp->name, temp->type, temp->size, temp->binding, temp->flabel);

        if(temp->isFunct){

            printf("\tParameters: ");
            struct param* list = temp->paramlist;

            while(list){
                printf("%s ", list->type==TYPE_INT?"int":"str");
                printf("%s", list->name);
                if(list->next)printf(", ");
                list = list->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
}

struct param* createParam(int type, struct tnode* id){
    struct param* node = malloc(sizeof(struct param));

    node->name = malloc(strlen(id->varname)+1);
    strcpy(node->name, id->varname);

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

void validateFunct(struct GSymbolTable* list, int type, struct tnode* id, struct param* paramlist){
    struct GSymbolTable* temp = list;
    while(temp){
        if(strcmp(id->varname, temp->name)==0){
            break;
        }
        temp = temp->next;
    }

    if(temp==NULL){
        printf("No function '%s' declared\n", id->varname);
        exit(1);
    }else if(!temp->isFunct){
        printf("'%s' is not a function\n", id->varname);
        exit(1);
    }else if(temp->type!=type){
        printf("Conflicting return types\n");
        exit(1);
    }

    id->STentry = temp;

    struct param* declared = temp->paramlist;
    struct param* defined = paramlist;

    while(defined && declared){
        if(strcmp(defined->name, declared->name)!=0){
            printf("Unknown parameter '%s'\n", declared->name);
            exit(1);
        }
        if(defined->type != declared->type){
            printf("Conflicting types for '%s'\n",defined->name);
            exit(1);
        }
        defined = defined->next;
        declared = declared->next;
    }

    if(defined || declared){
        printf("Different parameter numbers\n");
        exit(1);
    }
}

struct LSymbolTable* createLST(struct LSymbolTable* LST, struct tnode* id, int type){

    struct LSymbolTable* node = malloc(sizeof(struct LSymbolTable));

    node->name = malloc(sizeof(char)*strlen(id->varname));
    strcpy(node->name, id->varname);

    node->type = type;
    node->next = NULL;

    if(LST == NULL)
        return node;

    struct LSymbolTable* temp = LST;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;

    return LST;
}