#include "tree.h"


void isValid(struct tnode* id, int index){
    if(id->STentry->size<=index){
        printf("Index out bound\n");
        exit(1);
    }
}

int isIntegerLike(int t) {
    return t == TYPE_INT || t == TYPE_ID_INT;
}
int isStringLike(int t) {
    return t == TYPE_STR || t == TYPE_ID_STR;
}

int resolveType(int nodetype, struct tnode* left, struct tnode* right) {

    int leftType = left->type;

    if(right == NULL)
        return NO_TYPE;

    int rightType = right->type;

    switch(nodetype) {
        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
            if(isIntegerLike(leftType) && isIntegerLike(rightType)){
                return TYPE_INT;
            }
            else {
                printf("Type mismatch\n");
                exit(1);
            }

        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE:
            if(isIntegerLike(leftType) && isIntegerLike(rightType)){
                return TYPE_BOOLEAN;
            }
            else {
                printf("Type mistmatch\n");
                exit(1);
            }

        case NODE_ASSIGN:
            // Case 1: normal variable assignment
            if((leftType == TYPE_ID_INT && isIntegerLike(rightType)) ||
            (leftType == TYPE_ID_STR && isStringLike(rightType))) {
                return NO_TYPE;
            }

            // Case 2: pointer-to-pointer assignment
            if((leftType == TYPE_INT_PTR && rightType == TYPE_INT_PTR) ||
            (leftType == TYPE_STR_PTR && rightType == TYPE_STR_PTR)) {
                return NO_TYPE;
            }

            // Case 3: LHS is a dereference (*p = ...)
            if(left->nodetype == NODE_DEREF) {
                if((leftType == TYPE_ID_INT && isIntegerLike(rightType)) ||
                (leftType == TYPE_ID_STR && isStringLike(rightType))) {
                    return NO_TYPE;
                }
            }

            // Case 4: RHS is address-of (p = &a)
                // printf("%d\t%d",right->nodetype, leftType);
            if(right->nodetype == NODE_ADDR) {
                if(leftType == right->type) {  // pointer types must match
                    return NO_TYPE;
                }
            }

            printf("Type mismatch in assignment\n");
            exit(1);
            

        default:
            return NO_TYPE;
    }
}

struct tnode* createDerefNode(struct tnode* id) {
    if (!(id->type == TYPE_INT_PTR || id->type == TYPE_STR_PTR)) {
        printf("Cannot dereference a non-pointer type\n");
        exit(1);
    }
    struct tnode* node = malloc(sizeof(struct tnode));
    node->nodetype = NODE_DEREF;
    node->left = id;
    node->right = NULL;
    node->type = (id->type == TYPE_INT_PTR) ? TYPE_ID_INT : TYPE_ID_STR;
    return node;
}

struct tnode* createAddrNode(struct tnode* id) {
    if (!(id->type == TYPE_ID_INT || id->type == TYPE_ID_STR)) {
        printf("Cannot take address of non-variable type\n");
        exit(1);
    }
    struct tnode* node = malloc(sizeof(struct tnode));
    node->nodetype = NODE_ADDR;
    node->left = id;
    node->right = NULL;
    node->type = (id->type == TYPE_ID_INT) ? TYPE_INT_PTR : TYPE_STR_PTR;
    return node;
}

struct tnode* createTreeNode(int nodetype, struct tnode* left, struct tnode* right){

    struct tnode* node = malloc(sizeof(struct tnode));

    node->val = 0;
    node->varname = NULL;
    node->str_val = NULL;
    node->STentry = NULL;

    node->nodetype = nodetype;
    node->left = left;
    node->right = right;

    node->type = resolveType(nodetype, left, right);

    /*right is null for read and write*/

    return node;
}


/*-----Node for Constants and identifiers-----*/
struct tnode* createLeafNode(int type, char* varname, int val, char* str_val){
    struct tnode* node = malloc(sizeof(struct tnode));

    node->left = NULL;
    node->right = NULL;

    node->str_val = str_val;
    node->nodetype = NODE_LEAF;
    node->STentry = NULL;
    node->type  = type;
    node->val = val;
    node->varname = varname;

    return node;
}

struct tnode* createArrayNode(struct tnode* id, struct tnode* row, struct tnode* col){

    if(!(id->STentry->isArray)){
        printf("'%s' is not an array\n", id->varname);
        exit(1);
    }
    // if(!isIntegerLike(row->nodetype)){
    //     printf("Index should be of type 'INT'\n");
    //     exit(1);
    // }
    // if(col && !isIntegerLike(col->nodetype)){
    //     printf("Index should be of type 'INT'\n");
    //     exit(1);
    // }

    id->left = row;
    id->right = col;

    return id;
}