#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct GSymbolTable{
    char* name;
    int type;
    int size;
    int binding;
    
    int rowSize;
    int colSize;

    bool isFunct;
    int flabel;
    
    struct param* paramlist;
    struct GSymbolTable* next;
};

struct param{
    char* name;
    int type;
    struct param* next;
};

struct LSymbolTable{
    char* name;
    int type;
    int binding;
    struct LSymbolTable* next;
};

struct tnode{
    int val;
    char* str_val;
    int type;
    char *varname;
    int nodetype;
    struct GSymbolTable* STentry;
    struct tnode *left;
    struct tnode *right;
};

#include "./constant.h"

#endif