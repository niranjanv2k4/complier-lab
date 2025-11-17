#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LOOP_NESTING 100

/* ---- Loop label management ---- */
struct LoopLabels {
    int start;
    int end;
};

extern uint32_t used;
extern int newLabel;
extern int regNum;
extern bool isMain;
extern bool headerSet;
extern int loopTop;

/* ---- Forward declarations ---- */
struct ASTNode;
struct Fieldlist;

void pushLoop(int start, int end);
void popLoop(void);
int getLoopStart(void);
int getLoopEnd(void);

/* ---- Register & label management ---- */
int getReg(void);
int freeReg(int reg);
int getNewLabel(void);


#endif // HELPER_H
