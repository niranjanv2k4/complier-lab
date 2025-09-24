#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct tnode{
    int val;
    int type;
    char *varname;
    int nodetype;
    struct tnode *left;
    struct tnode *right;
};

#include "./constant.h"

#endif