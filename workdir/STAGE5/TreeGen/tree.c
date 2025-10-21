#include "tree.h"

bool isIntegerLike(struct Typetable* t) {
    return t == TLookup("int") || t == TLookup("int arr");
}
bool isStringLike(struct Typetable* t) {
    return t == TLookup("str") || t == TLookup("str arr");
}
bool isBoolLike(struct Typetable* t) {
    return t == TLookup("bool");
}

struct Typetable* resolveType(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2) {

    struct Typetable* leftType = ptr1->type;

    if(!ptr2)
        switch(nodetype){
            case NODE_READ:
            case NODE_WRITE:
                if(ptr1->nodetype != NODE_FUNCT && (ptr1->Gentry && ptr1->Gentry->flabel != -1)){
                    printf("Error: Type mismatch\n");
                    exit(1);
                }
                if(ptr1->type->fields != NULL){
                    printf("Error: No fields\n");
                    exit(1);
                }
                return TLookup("void");
        }

    struct Typetable* rightType = ptr2->type;

    if(ptr1->nodetype != NODE_FUNCT && (ptr1->Gentry && ptr1->Gentry->flabel != -1)){
        printf("Error: Invalid use of function\n");
        exit(1);
    }
    if(ptr2->nodetype != NODE_FUNCT && (ptr2->Gentry && ptr2->Gentry->flabel != -1)){
        printf("Error: Invalid use of function\n");
        exit(1);
    }

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
            printf("Type mistmatch in conditional operation\n");
            exit(1);

        case NODE_ASSIGN:
            if(ptr1->nodetype == NODE_ID || ptr1->nodetype == NODE_TUPLE || ptr2->nodetype == NODE_TUPLE){
                if(strcmp(leftType->name, rightType->name) == 0 && ptr1->isPointer==ptr2->isPointer){
                    return TLookup("void");
                }
                printf("Type mismatch in assignment\n");
                exit(1);
            }else if(ptr1->nodetype == NODE_DEREF && ptr2->nodetype == NODE_DEREF){
                if(strcmp(ptr1->ptr1->type->name, ptr2->ptr1->type->name) == 0){
                    return TLookup("void");
                }
                printf("Type mismatch in assignment\n");
                exit(1);
            }else if(ptr1->nodetype == NODE_DEREF){
                if(strcmp(ptr1->type->name, ptr2->type->name) == 0 && !ptr2->isPointer){
                    return TLookup("void");
                }
                printf("Type mismatch in assignment\n");
                exit(1);
            }else if(ptr2->nodetype == NODE_DEREF){
                if(strcmp(ptr2->type->name, ptr1->type->name) == 0 && !ptr1->isPointer){
                    return TLookup("void");
                }
                printf("Type mismatch in assignment\n");
                exit(1);
            }else if(ptr2->nodetype == NODE_ADDR && strcmp(leftType->name, rightType->name)==0 && ptr1->isPointer){
                    return TLookup("void");
            }
            else{
                printf("Type mismatch in assignment\n");
                exit(1);
            }
            
        default: {
            if(ptr1->nodetype != NODE_FUNCT && (ptr1->Gentry && ptr1->Gentry->flabel != -1)){
                printf("Error: Assignment to a function\n");
                exit(1);
            }
            if(ptr2->nodetype != NODE_FUNCT && (ptr2->Gentry && ptr2->Gentry->flabel != -1)){
                printf("Error: Assignment to a function\n");
                exit(1);
            }
            return TLookup("void");
        }
    }
}

struct ASTNode* createDerefNode(struct ASTNode* id) {

    setType(id);

    if (!id->isPointer) {
        printf("Cannot dereference a non-pointer type\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = NODE_DEREF;
    node->ptr1 = id;
    node->ptr2 = NULL;
    node->type = id->type;

    return node;
}

struct ASTNode* createAddrNode(struct ASTNode* id) {
    setType(id);

    if (id->nodetype != NODE_ID) {
        printf("Cannot take address of non-variable type\n");
        exit(1);
    }

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->nodetype = NODE_ADDR;
    node->ptr1 = id;
    node->ptr2 = NULL;

    node->type = id->type;
    node->isPointer = true;

    return node;
}

struct ASTNode* createTreeNode(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2){

    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->Gentry = NULL;

    node->nodetype = nodetype;
    node->ptr1 = ptr1;
    node->ptr2 = ptr2;

    node->isPointer = false;

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
    node->isPointer = false;

    node->name = varname;
    node->nodetype = varname?NODE_ID:NODE_CONST;
    node->type  = type;

    if(node->nodetype == NODE_CONST){
        if(strcmp(type->name,"int") == 0){
            node->value.intVal = val;
        }else if(strcmp(type->name,"str") == 0){
            node->value.strVal = str_val;
        }
    }

    return node;
}

struct ASTNode* createArrayNode(struct ASTNode* id, struct ASTNode* ptr1, struct ASTNode* ptr2){

    setType(id);

    if(id->type != TLookup("int arr") && id->type != TLookup("str arr")){
        printf("'%s' is not an array\n", id->name);
        exit(1);
    }

    id->type = (id->type == TLookup("int arr")?TLookup("int"):TLookup("str"));
    
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
    
    setType(id);

    if(id->Gentry->flabel == -1){
        printf("'%s' is not a function\n", id->name);
        exit(1);
    }
    struct param* declared = id->Gentry->paramlist;
    struct ASTNode* passed = arglist;

    while(declared && passed){
        if(declared->type != passed->type || declared->isPointer != passed->isPointer){
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


struct ASTNode* createTupleNode(struct ASTNode* id, struct ASTNode* field){
    if(field == NULL){
        printf("Error: some field is required\n");
        exit(1);
    }

    if(id->nodetype != NODE_ID && id->nodetype != NODE_DEREF){
        printf("Error: Cannot dereference\n");
        exit(1);
    }

    if(id->nodetype == NODE_ID){
        setType(id);
        if(id->isPointer){
            printf("Error: '%s' is a pointer type\n", id->name);
            exit(1);
        }
    }

    struct Typetable* targetType = (id->nodetype == NODE_ID?id->type:id->ptr1->type);
    if (targetType == NULL || targetType->fields == NULL) {
        printf("Error: '%s' is not a tuple type\n", id->name);
        exit(1);
    }
    
    struct Fieldlist* temp = FLookup(targetType->fields, field->name);

    if(temp == NULL){
        printf("Error: No field named '%s' in '%s'\n", field->name, id->name);
        exit(1);
    }


    struct ASTNode* node = malloc(sizeof(struct ASTNode));

    node->type = temp->type;
    node->nodetype = NODE_TUPLE;
    node->ptr1 = id;
    node->ptr2 = field;
    
    return node;
}
