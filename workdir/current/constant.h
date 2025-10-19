#ifndef CONSTANTS_H
#define CONSTANTS_H

#define STACK_BASE 4096

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
    NODE_TUPLE
};


// enum DataType {
//     NO_TYPE = 0,
//     TYPE_INT = 1,
//     TYPE_ID_INT  = 2,
//     TYPE_BOOLEAN = 3,
//     TYPE_STR = 4,
//     TYPE_ID_STR = 5,
//     TYPE_INT_PTR = 6,
//     TYPE_STR_PTR = 7,
//     TYPE_FUNCT = 8
// };

#endif