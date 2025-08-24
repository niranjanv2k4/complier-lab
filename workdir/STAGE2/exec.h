#ifndef MACHINE_PROGRAM_H
#define MACHINE_PROGRAM_H

#include "tree.h"

/* -----Register managing----- */
int getReg();
int freeReg(int r);


/* -----output generation----- */

void createOutput(struct tnode* root, FILE* output);

int codeGen(struct tnode* root, FILE* output);
void write(FILE* output, int r);
void exitProg(FILE* output);

void evaluator(struct tnode* root);

#endif
