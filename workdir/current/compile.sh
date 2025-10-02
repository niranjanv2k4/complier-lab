#!/bin/bash

# $1 will be the first argument passed to the script
INPUT_FILE="$1"

lex compiler.l
yacc -d compiler.y
gcc y.tab.c lex.yy.c ./symbolTable/symbol.c ./Conditionals/jump.c TreeGen/tree.c ExecGen/exec.c -o compiler

./compiler "$INPUT_FILE"

cd ./label || exit

lex label.l
gcc lex.yy.c label.c -o translator

./translator ../output.xsm
