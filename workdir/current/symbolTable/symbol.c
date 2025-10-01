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

struct Gnode* insert(struct Gnode* head, struct tnode* id, int type, int size, bool isArray){

    if(lookup(head, id->varname)!=NULL){
        printf("Variable '%s' already declared\n", id->varname);
        exit(1);
    }

    struct Gnode* node = malloc(sizeof(struct Gnode));

    node->name = malloc(strlen(id->varname)+1);
    strcpy(node->name, id->varname);
    
    node->type = type;

    node->isArray = isArray;

    node->size = size;
    node->binding = getMem(size);

    node->next = NULL;

    id->STentry = node;
    id->type = type;

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

/* currently useless*/
// void Assign(struct Gnode* head, struct tnode* id, struct tnode* expr){

//     setType(head, id);
    
//     if(id->type == TYPE_ID_INT){
//         if(expr->type!=TYPE_INT && expr->type != TYPE_ID_INT){
//             printf("Type mismatch\n");
//             exit(1);
//         }
//     }
//     if(id->type == TYPE_ID_STR){
//         if(expr->type!=TYPE_STR && expr->type != TYPE_ID_STR){
//             printf("Type mismatch\n");
//             exit(1);
//         }
//     }
// }
