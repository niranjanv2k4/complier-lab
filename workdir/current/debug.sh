#!/bin/bash


# The file argument passed to the script
INPUT_FILE=$1

# Step 1: Generate the lexer from your Lex file
lex compiler.l

# Step 2: Generate the parser from your Yacc file
yacc -d compiler.y

# Step 3: Compile everything to create the executable a.out
gcc -g y.tab.c lex.yy.c ./symbolTable/symbol.c ./Conditionals/jump.c TreeGen/tree.c typeTable/type.c ExecGen/exec.c -o a.out

# Step 4: Run the program with the input file as an argument
gdb --args ./a.out $INPUT_FILE
