#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


union Constant{
    int intVal;
    char* strVal;
};


struct GSymbol{
    char* name;
    struct Typetable *type; 
    int size;
    int binding;
    bool isPointer;
    
    int rowSize;
    int colSize;

    int flabel;
    
    struct param* paramlist;
    struct GSymbol* next;
};

struct param{
    char* name;
    struct Typetable *type; 
    struct param* next;
};

struct LSymbol{
    char* name;
    struct Typetable *type; 
    bool isPointer;
    int binding;
    struct LSymbol* next;
};

struct ASTNode{
  struct Typetable *type;           //pointer to the type table entry
  int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc 
  char *name;                       //stores the variable/function name in case of variable/function nodes
  bool isPointer;
  union Constant value;             //stores the value of the constant if the node corresponds to a constant
  struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
  struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
  struct GSymbol *Gentry;           //pointer to GST entry for global variables and functions
  struct LSymbol *Lentry;           //pointer to the function's LST for local variables and arguements
};

#endif