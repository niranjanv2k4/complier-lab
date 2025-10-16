#include "./label.h"

struct LabelList* insertNewLabel(struct LabelList* head, char* LabelName, int addr){
    struct LabelList* node = malloc(sizeof(struct LabelList));

    node->LabelName = LabelName;
    node->addr = addr;
    node->next = NULL;

    if(head == NULL){
        return node;
    }
    
    struct LabelList* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = node;

    return head;
}

int getAddr(struct LabelList* head, char* LabelName){

    struct LabelList* temp = head;
    while(temp){
        if(strcmp(temp->LabelName, LabelName) == 0){
            return temp->addr;
        }
        temp = temp->next;
    }

    return -1;
}