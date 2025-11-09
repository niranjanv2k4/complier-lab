#!/bin/bash

INPUT_FILE="$1"

lex compiler.l
yacc -d compiler.y

gcc -g y.tab.c lex.yy.c ./symbolTable/symbol.c \
    ./Conditionals/jump.c TreeGen/tree.c \
    ./typeTable/type.c ./ExecGen/exec.c ./ExecGen/helper.c ./classTable/class.c -o compiler

gdb --args ./compiler "$INPUT_FILE"
