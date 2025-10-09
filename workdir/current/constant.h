#ifndef CONSTANTS_H
#define CONSTANTS_H

#define STACK_BASE 4096

enum NodeType {
    NODE_LEAF      = 0,
    NODE_READ      = 1,
    NODE_WRITE     = 2,
    NODE_CONNECTOR = 3,
    NODE_ASSIGN    = 4,

    // Arithmetic
    NODE_ADD       = 10,
    NODE_SUB       = 11,
    NODE_MUL       = 12,
    NODE_DIV       = 13,
    NODE_MOD       = 14,

    // Logical
    NODE_IF        = 17,
    NODE_WHILE     = 18,
    NODE_IFELSE    = 19,
    NODE_LT        = 20,
    NODE_GT        = 21,
    NODE_LE        = 22,
    NODE_GE        = 23,
    NODE_EQ        = 24,
    NODE_NE        = 25,

    // Control flow
    NODE_BREAK     = 26,
    NODE_CONTINUE  = 27,

    NODE_RPTUTL    = 28,
    NODE_DOWHILE   = 29,

    NODE_DEREF     = 30,
    NODE_ADDR       = 31,

    NODE_AND        = 32,
    NODE_OR         = 33
};

enum DataType {
    NO_TYPE = 0,
    TYPE_INT = 1,
    TYPE_ID_INT  = 2,
    TYPE_BOOLEAN = 3,
    TYPE_STR = 4,
    TYPE_ID_STR = 5,
    TYPE_INT_PTR = 6,
    TYPE_STR_PTR = 7,
    TYPE_FUNCT = 8
};

#endif