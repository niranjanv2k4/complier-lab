lex compiler.l
yacc -d compiler.y
gcc y.tab.c lex.yy.c ./Conditionals/jump.c TreeGen/tree.c ExecGen/exec.c