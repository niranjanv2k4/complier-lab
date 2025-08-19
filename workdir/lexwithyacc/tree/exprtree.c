#include "exprtree.h"

struct tnode *makeLeafNode(int val){
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->op = NULL;

    node->l = node->r = NULL;
    node->val = val;

    return node; 
}

struct tnode *makeOperatorNode(char op, struct tnode *l, struct tnode *r){
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));

    node->op = malloc(sizeof(char));
    *(node->op) = op;
    
    node->l = l;
    node->r = r;

    return node;
}


int evaluate(struct tnode *root){
    if(root->op==NULL){
        return root->val;
    }else{
        switch(*(root->op)){
            case '+':   return evaluate(root->l) + evaluate(root->r);
            case '-':   return evaluate(root->l) - evaluate(root->r);
            case '*':   return evaluate(root->l) * evaluate(root->r);
            case '/':   return evaluate(root->l) / evaluate(root->r);
        }
    }
    return 0;
}

void inorder(struct tnode *root){
    if(!root)return;

    inorder(root->l);
    if(root->op)printf("%c ", *(root->op));
    else printf("%d ", root->val);
    inorder(root->r);
}
void preorder(struct tnode *root){
    if(!root)return;

    if(root->op)printf("%c ", *(root->op));
    else printf("%d ", root->val);
    preorder(root->l);
    preorder(root->r);
}