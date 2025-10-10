#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct Gnode{
    char* name;
    int type;
    int size;
    int binding;
    
    bool isArray;
    int rowSize;
    int colSize;
    
    struct Gnode* next;
};

struct tnode{
    int val;
    char* str_val;
    int type;
    char *varname;
    int nodetype;
    struct Gnode* STentry;
    struct tnode *left;
    struct tnode *right;
};

#include "./constant.h"

#endif