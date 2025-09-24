#include "tree.h"


int isIntegerLike(int t) {
    return t == TYPE_INT || t == TYPE_ID_INT;
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
            if(isIntegerLike(leftType) && isIntegerLike(rightType))
                return TYPE_INT;
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
            if(isIntegerLike(leftType) && isIntegerLike(rightType))
                return TYPE_BOOLEAN;
            else {
                printf("Type mistmatch\n");
                exit(1);
            }

        case NODE_ASSIGN:
            if(leftType == TYPE_ID_INT && (rightType == TYPE_INT || rightType == TYPE_ID_INT))
                return NO_TYPE;
            else {
                printf("Type mismatch\n");
                exit(1);
            }

        default:
            return NO_TYPE;
    }
}

struct tnode* createTreeNode(int nodetype, struct tnode* left, struct tnode* right){

    struct tnode* node = malloc(sizeof(struct tnode));

    node->val = 0;
    node->varname = NULL;
    
    node->nodetype = nodetype;
    node->left = left;

    node->type = resolveType(nodetype, left, right);

    /*right is null for read and write*/
    node->right = right;

    return node;
}


/*-----Node for Constants and identifiers-----*/
struct tnode* createLeafNode(int type, char* varname, int val){
    struct tnode* node = malloc(sizeof(struct tnode));

    node->left = NULL;
    node->right = NULL;

    node->nodetype = NODE_LEAF;
    node->type  = type;
    node->val = val;
    node->varname = varname;

    return node;
}

