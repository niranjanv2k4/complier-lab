#ifndef MACHINE_PROGRAM_H
#define MACHINE_PROGRAM_H

#include "../main.h"

extern int newLabel;

/* -----Register managing----- */
int getReg();
int freeReg(int r);


/* -----output generation----- */

void createOutput(struct tnode* root, FILE* output);

void evaluator(struct tnode* root);

#endif
