lex compiler.l
yacc -d compiler.y
gcc y.tab.c lex.yy.c ./Conditionals/jump.c TreeGen/tree.c ExecGen/exec.c


./a.out input.yyin

cd ./label
lex label.l
gcc lex.yy.c label.c -o translator

./translator ../output.xsm