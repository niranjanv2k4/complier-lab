#include "tree.h"


// void isValid(struct ASTNode* id, int index){
//     if(id->Gentry->size<=index){
//         printf("Index out bound\n");
//         exit(1);
//     }
// }

bool isIntegerLike(struct Typetable* t) {
    return t == TLookup("int");
}
bool isStringLike(struct Typetable* t) {
    return t == TLookup("str");
}
bool isBoolLike(struct Typetable* t) {
    return t == TLookup("bool");
}

struct Typetable* resolveType(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2) {

    struct Typetable* leftType = ptr1->type;

    if(!ptr2)
        return TLookup("void");

    struct Typetable* rightType = ptr2->type;

    switch(nodetype) {
        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
            if(isIntegerLike(leftType) && isIntegerLike(rightType))
                return TLookup("int");
            
            printf("Type mismatch in arithmatic operation\n");
            exit(1);
            
        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE:
            if((isIntegerLike(leftType) && isIntegerLike(rightType)) || (isStringLike(leftType) && isStringLike(rightType)))
                return TLookup("bool");

            printf("Type mistmatch in boolean operation\n");
            exit(1);
        case NODE_AND:
        case NODE_OR:
            if((isBoolLike(leftType) && isBoolLike(rightType)))
                return TLookup("bool");
            printf("Type mistmatch in boolean operation\n");
            exit(1);

        case NODE_ASSIGN:
            if(ptr1->nodetype == NODE_ID || ptr1->nodetype == NODE_DEREF){
                if(leftType == rightType){
                    return TLookup("void");
                }

                if(ptr1->nodetype == NODE_DEREF) {
                    if(ptr1->ptr1->type == ptr2->type) {
                        return TLookup("void");
                    }
                }

                if(ptr2->nodetype == NODE_ADDR) {
                    if(leftType == ptr2->type) {
                        return TLookup("void");
                    }
                }
                printf("Type mismatch in assignment\n");
            }else{
                printf("Left side is not an identifier\n");
            }
            exit(1);
            

        default:
            return TLookup("void");
    }
}

struct ASTNode* createDerefNode(struct ASTNode* id) {
    if (id->type != TLookup("int ptr") && id->type != TLookup("str ptr")) {
        printf("Cannot dereference a non-pointer type\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = NODE_DEREF;
    node->ptr1 = id;
    node->ptr2 = NULL;
    node->type = TLookup(strcmp(id->type->name ,"int ptr") == 0 ? "int" : "str");

    return node;
}

struct ASTNode* createAddrNode(struct ASTNode* id) {
    if (id->nodetype != NODE_ID) {
        printf("Cannot take address of non-variable type\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = NODE_ADDR;
    node->ptr1 = id;
    node->ptr2 = NULL;

    node->type = TLookup(strcmp(id->type->name, "int") == 0 ? "int ptr" : "str ptr");

    return node;
}

struct ASTNode* createTreeNode(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2){

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->Gentry = NULL;

    node->nodetype = nodetype;
    node->ptr1 = ptr1;
    node->ptr2 = ptr2;

    node->type = resolveType(nodetype, ptr1, ptr2);

    /*right is null for read and write*/

    return node;
}


/*-----Node for Constants and identifiers-----*/
struct ASTNode* createLeafNode(struct Typetable* type, char* varname, int val, char* str_val){
    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->ptr1 = NULL;
    node->ptr2 = NULL;
    node->ptr3 = NULL;
    node->Gentry = NULL;
    node->Lentry = NULL;

    node->name = varname;
    node->nodetype = varname?NODE_ID:NODE_CONST;
    node->type  = type;

    if(type){
        if(strcmp(type->name,"int") == 0){
            node->value.intVal = val;
        }else if(strcmp(type->name,"str") == 0){
            node->value.strVal = str_val;
        }
    }

    return node;
}

struct ASTNode* createArrayNode(struct ASTNode* id, struct ASTNode* ptr1, struct ASTNode* ptr2){

    if(id->Gentry->size==1){
        printf("'%s' is not an array\n", id->name);
        exit(1);
    }

    id->ptr1 = ptr1;
    id->ptr2 = ptr2;

    return id;
}

/*---arguments list functions---*/

struct ASTNode* appendArgNode(struct ASTNode* list, struct ASTNode* expr){

    if(!list){
        return expr;
    }
    struct ASTNode* temp = list;
    
    while(temp->arglist){
        temp = temp->arglist;
    }
    temp->arglist = expr;

    return list;
}

struct ASTNode* createFunctNode(struct ASTNode* id, struct ASTNode* arglist){

    if(id->Gentry->flabel == -1){
        printf("'%s' is not a function\n", id->name);
        exit(1);
    }
    struct param* declared = id->Gentry->paramlist;
    struct ASTNode* passed = arglist;

    while(declared && passed){
        if(declared->type != passed->type){
            printf("conflicting type for '%s'\n", declared->name);
            exit(1);
        }
        declared = declared->next;
        passed = passed->arglist;
    }

    if(declared || passed){
        printf("Different number of arguments\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = NODE_FUNCT;
    node->type = id->Gentry->type;
    node->ptr1 = id;
    node->ptr1->arglist = arglist;

    return node;
}


struct ASTNode* createRtnNode(struct ASTNode* rtn){

    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->ptr1 = rtn;
    node->type = rtn->type;
    node->nodetype = NODE_RET;

    return node;
}
