#include "./symbol.h"


int currBinding = STACK_BASE;

int getMem(int size){
    int mem = currBinding;
    currBinding += size;
    return mem;
}


void setType(struct Gnode* head, struct tnode* id){
    struct Gnode* temp = lookup(list, id->varname);
    if(temp==NULL){
        printf("Variable '%s' not declared.\n", id->varname);
        exit(1);
    }

    id->STentry = temp;
    id->type = temp->type;
    
    if(temp->typeName){
        id->typeName = strdup(temp->typeName);
    }
}

struct Gnode* lookup(struct Gnode* head, char* name){
    struct Gnode* temp = head;

    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct Gnode* insert(struct Gnode* head, struct tnode* id, char* typeName, int type, int rowSize, int colSize, bool isArray){

    if(lookup(head, id->varname)!=NULL){
        printf("Variable '%s' already declared\n", id->varname);
        exit(1);
    }

    struct Gnode* node = malloc(sizeof(struct Gnode));

    node->name = malloc(strlen(id->varname)+1);
    strcpy(node->name, id->varname);
    
    node->type = type;

    node->isArray = isArray;
    node->rowSize = rowSize;
    node->colSize = colSize;

    node->size = rowSize*colSize;
    node->binding = getMem((type == TYPE_ID_PAIR?2:node->size));

    node->next = NULL;

    id->STentry = node;
    id->type = type;

    if(type == TYPE_ID_PAIR){
        node->typeName = strdup(typeName);
    }

    if(head==NULL){
        return node;
    }
    struct Gnode* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;

    return head;
}

void printST(struct Gnode* head){
    struct Gnode* temp = head;
    
    printf("name\ttype\tsize\tbinding\tarray\n");

    while(temp){
        printf("%s\t%d\t%d\t%d\t", temp->name, temp->type, temp->size, temp->binding);
        printf("%s\n", temp->isArray?"Yes":"No");
        temp = temp->next;
    }
}

struct PairList* Plookup(char* name){
    struct PairList* temp = pairs;
    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct PairList* installPair(char* name, int first, int second){

    if(Plookup(name) != NULL){
        printf("Error: already declared\n");
        exit(1);
    }

    struct PairList* node = malloc(sizeof(struct PairList));
    node->name = strdup(name);
    node->first = first;
    node->second = second;
    node->next = NULL;

    if(!pairs)return node;

    struct PairList* temp = pairs;
    while(temp->next)temp=temp->next;
    temp->next = node;

    return pairs;
}


