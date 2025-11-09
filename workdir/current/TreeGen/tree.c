#include "tree.h"


struct ASTNode* createNode(){

    struct ASTNode* node = malloc(sizeof(struct ASTNode));;

    node->ptr1 = NULL;
    node->ptr2 = NULL;
    node->ptr3 = NULL;
    node->Gentry = NULL;
    node->Lentry = NULL;
    node->arglist = NULL;
    node->name = NULL;
    node->type = NULL;
    node->method = NULL;

    return node;
}
bool isIntegerLike(struct Typetable* t) {
    return t == TLookup("int") || t == TLookup("int arr");
}
bool isStringLike(struct Typetable* t) {
    return t == TLookup("str") || t == TLookup("str arr");
}
bool isBoolLike(struct Typetable* t) {
    return t == TLookup("bool");
}

bool checkType(struct ASTNode* id, int category){
    if(id->Lentry && id->Lentry->category == category){
        return true;
    }
    return id->Gentry->category == category;
}

struct Typetable* resolveType(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2) {


    if(!ptr2)
        switch(nodetype){
            case NODE_READ:
            case NODE_WRITE:{
                bool flag = ptr1->nodetype != NODE_FUNCT && ptr1->Gentry && ptr1->Gentry->flabel != -1;
                flag |= ptr1->type->category != TYPE_PRIMITIVE;
                if(flag){
                    printf("Error: Type mismatch in I/O statement\n");
                    exit(1);
                }
                return TLookup("void");
            }
            case NODE_ALLOC:{
                if(ptr1->type->category != TYPE_USERDEF){
                    printf("Error: '%s' is not a user defined type\n", ptr1->name);
                    exit(1);
                }
                
                return TLookup("void");
            }
        }

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
            if(isIntegerLike(ptr1->type) && isIntegerLike(ptr2->type))
                return TLookup("int");
            
            printf("Type mismatch in arithmatic operation\n");
            exit(1);
            
        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE:
            if((isIntegerLike(ptr1->type) && isIntegerLike(ptr2->type)) || (isStringLike(ptr1->type) && isStringLike(ptr2->type)))
                return TLookup("bool");
            if(ptr2->nodetype == NODE_NULL){
                if(ptr1->type->category == TYPE_USERDEF){
                    return TLookup("bool");
                }
            }
            if(ptr1->nodetype == NODE_NULL){
                if(ptr2->type->category == TYPE_USERDEF){
                    return TLookup("bool");
                }
            }
            printf("Type mistmatch in boolean operation\n");
            exit(1);
        case NODE_AND:
        case NODE_OR:
            if((isBoolLike(ptr1->type) && isBoolLike(ptr2->type)))
                return TLookup("bool");
            printf("Type mistmatch in conditional operation\n");
            exit(1);

        case NODE_ASSIGN:
            if(ptr2->nodetype == NODE_NULL && ptr1->type->category == TYPE_USERDEF){
                    return TLookup("void");
            }
            else if(ptr1->nodetype == NODE_ID || ptr1->nodetype == NODE_FIELDACCESS){
                if(ptr1->type && ptr2->type && strcmp(ptr1->type->name, ptr2->type->name) == 0){
                    return TLookup("void");
                }
                if(ptr1->class && ptr2->class && strcmp(ptr1->class->name, ptr2->class->name) == 0){
                    return TLookup("void");
                }
                printf("Type mismatch in assignment\n");
                exit(1);
            }else{
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

struct ASTNode* createTreeNode(int nodetype, struct ASTNode* ptr1, struct ASTNode* ptr2){

    struct ASTNode* node = createNode();;

    if(nodetype == NODE_ASSIGN){
        if(ptr1)
            setType(ptr1);
        if(ptr2)
            setType(ptr2);
    }

    node->nodetype = nodetype;
    node->ptr1 = ptr1;
    node->ptr2 = ptr2;
    node->type = resolveType(nodetype, ptr1, ptr2);

    return node;
}


/*-----Node for Constants and identifiers-----*/
struct ASTNode* createLeafNode(int nodetype, char* type, char* varname, int val, char* str_val){
    struct ASTNode* node = createNode();;

    node->name = varname;
    node->nodetype = nodetype;

    if(node->nodetype == NODE_CONST){
        if(strcmp(type,"int") == 0){
            node->value.intVal = val;
        }else if(strcmp(type,"str") == 0){
            node->value.strVal = str_val;
        }
        node->type = TLookup(type);
        return node;
    }

    return node;
}

struct ASTNode* createArrayNode(struct ASTNode* id, struct ASTNode* ptr1, struct ASTNode* ptr2){

    setType(id);

    if(id->Gentry->colSize == 0){
        printf("Error: '%s' is not an array\n", id->name);
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
    
    if(id->name)
        setType(id);

    struct ASTNode* node = createNode();

    node->nodetype = NODE_FUNCT;
    node->ptr1 = id;
    node->ptr1->arglist = arglist;

    if(id->method){
        struct Methodlist* method = id->method;
        struct param* declared = method->paramlist;
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

        node->type = method->type;
        return node;
    }

    if(!id->Gentry || id->Gentry->flabel == -1){
        printf("Error: '%s' is not %s\n", id->name, (id->Gentry?"not a function":"declared"));
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

    node->type = id->Gentry->type;

    return node;
}

struct ASTNode* createFieldAccessNode(struct ASTNode* ptr1, struct ASTNode* ptr2){

    if(ptr1->name){
        setType(ptr1);
    }

    struct ASTNode* node = createNode();;
    node->nodetype = NODE_FIELDACCESS;

    bool flag = ptr1->type && ptr1->type->fields;
    if(flag){
        struct Fieldlist* f = FLookup(ptr1->type->fields, ptr2->name);
        if(!f){
            printf("Error: '%s' does not have a field named '%s'\n", ptr1->type->name, ptr2->name);
            exit(1);
        }
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;
        node->type = f->type;
        return node;
    }

    if(ptr1->class){
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;
        struct Fieldlist* f = ClassFLookup(ptr1->class, ptr2->name);
        if(f){
            node->type = f->type;
            node->class = f->class;
            return node;
        }
        struct Methodlist* m = ClassMLookup(ptr1->class, ptr2->name);

        if(m){
            node->nodetype == NODE_METHOD;
            node->type = m->type;
            node->class = ptr1->class;
            node->method = m;
            return node;
        }

        printf("Error: Class '%s' do not have a member named '%s'\n", ptr1->class->name, ptr2->name);
        exit(1);
        
    }
    return node;
}

struct ASTNode* createRtnNode(struct ASTNode* rtn){

    struct ASTNode* node = createNode();;
    node->ptr1 = rtn;
    node->type = rtn->type;
    node->nodetype = NODE_RET;

    return node;
}

struct ASTNode* createDynamicNode(int nodetype, struct ASTNode* id){

    if(nodetype == NODE_NULL || nodetype == NODE_INITIALIZE){
        struct ASTNode* node = createNode();;
        node->nodetype = nodetype;
        return node;
    }

    if(id->type->category == TYPE_PRIMITIVE){
        printf("Error: Memory allocation can only be done to user defined variables\n");
        exit(1);
    }

    struct ASTNode* node = createNode();;
    node->nodetype = nodetype;
    node->ptr1 = id;

    return node;
}

struct ASTNode* createClassNode(int nodetype, struct ASTNode* id, char* baseClass){
    
    if(id->name)
        setType(id);

    struct ASTNode* node = createNode();;
    node->nodetype = nodetype;
    node->ptr1 = id;

    if(nodetype == NODE_DELETE){
        if(!id->class){
            printf("Error: mismatch type in deleting\n");
            exit(1);
        }

    }else{

        struct Classtable* class = CLookup(baseClass);

        if(class == NULL){
            printf("Error: '%s' is not a class datatype\n", baseClass);
            exit(1);
        }
        if(!id->class){
            printf("Error: left side is not a class type\n");
            exit(1);
        }

        node->class = class;
    }
    
    return node;
}
