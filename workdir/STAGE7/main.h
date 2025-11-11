#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define STACK_BASE 4096
#define HEAP_BASE 1024
#define HB_SIZE 8

enum NodeType {
    NODE_CONST,
    NODE_READ,
    NODE_WRITE,
    NODE_CONNECTOR,
    NODE_ASSIGN,

    // Arithmetic
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD,

    // Logical / Conditional
    NODE_IF,
    NODE_WHILE,
    NODE_LT,
    NODE_GT,
    NODE_LE,
    NODE_GE,
    NODE_EQ,
    NODE_NE,

    // Control flow
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_RPTUTL,
    NODE_DOWHILE,

    NODE_DEREF,
    NODE_ADDR,
    NODE_AND,
    NODE_OR,

    NODE_FUNCT,
    NODE_ID,
    NODE_RET,
    NODE_PTR,
    NODE_ALLOC,
    NODE_FIELDACCESS,
    NODE_INITIALIZE,
    NODE_FREE,
    NODE_NULL,
    NODE_DELETE,
    NODE_NEW,
    NODE_SELF,
    NODE_METHOD
};

enum TypeCategory { TYPE_PRIMITIVE, TYPE_USERDEF, TYPE_CLASS };

union Constant{
    int intVal;
    char* strVal;
};

struct GSymbol{
    char* name;
    struct Typetable *type; 
    struct Classtable *class;

    int size;
    int binding;
    bool isPointer;
    
    int rowSize;
    int colSize;

    int flabel;
    
    int category;

    struct param* paramlist;
    struct GSymbol* next;
};

struct param{
    char* name;
    bool isPointer;
    struct Typetable *type;
    struct Classtable *class; 
    struct param* next;
};

struct LSymbol{
    char* name;
    struct Typetable *type; 
    struct Classtable *class;
    int binding;
    int category;
    struct LSymbol* next;
};

struct ASTNode{
  struct Typetable *type;           //pointer to the type table entry
  struct Classtable *class;           //pointer to the type table entry
  struct Methodlist *method;           //pointer to the type table entry
  int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc 
  char *name;                       //stores the variable/function name in case of variable/function nodes
  union Constant value;             //stores the value of the constant if the node corresponds to a constant
  struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
  struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
  struct GSymbol *Gentry;           //pointer to GST entry for global variables and functions
  struct LSymbol *Lentry;           //pointer to the function's LST for local variables and arguements
};

// Field list structure
struct Fieldlist {
    char *name;
    struct Typetable *type;
    struct Classtable *class;
    int fieldIndex;
    struct Fieldlist *next;
};

// Type table structure
struct Typetable {
    char *name;
    int size;
    int category;
    struct Fieldlist *fields;
    struct Typetable *next;
};


struct Methodlist {
 	char *name;                      //name of the member function in the class
	struct Typetable *type;          //pointer to typetable
	struct param *paramlist;   //pointer to the head of the formal parameter list
	int funcposition;                //position of the function in the class table
 	int Flabel;                      //A label for identifying the starting address of the function's code in the memory
	struct Methodlist *next;     //pointer to next Methodlist entry
};

struct Classtable {
 	char *name;                           //name of the class
	struct Fieldlist *fields;        //pointer to Fieldlist 
	struct Methodlist *methods;      //pointer to Methodlist
	struct Classtable *parent;         //pointer to the parent's class table
	int classindex;                      //position of the class in the virtual function table
	int fieldcount;                       //count of fields
  	int methodcount;                      //count of methods
	struct Classtable *next;              //pointer to next class table entry
};

#endif