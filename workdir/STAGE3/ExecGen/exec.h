#ifndef MACHINE_PROGRAM_H
#define MACHINE_PROGRAM_H

#include "../main.h"

// Max nesting depth of loops
#define MAX_LOOP_NESTING 100

// Struct to hold start/end labels of a loop
struct LoopLabels {
    int start;
    int end;
};

// Stack operations
void pushLoop(int start, int end);
void popLoop(void);
int getLoopStart(void);
int getLoopEnd(void);

extern int newLabel;

/* -----Register managing----- */
int getReg();
int freeReg(int r);


/* -----output generation----- */

void createOutput(struct tnode* root, FILE* output);

void evaluator(struct tnode* root);

#endif
