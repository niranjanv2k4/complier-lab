#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct LabelList {
    char LabelName[10];
    int addr;
    struct LabelList* next;
};

struct LabelList* insertNewLabel(struct LabelList* head, char LabelName[], int addr);
int getAddr(struct LabelList* head, char LabelName[]);

#endif