#ifndef MACHINE_PROGRAM_H
#define MACHINE_PROGRAM_H

#include "../main.h"
#include "../symbolTable/symbol.h"
#include "../typeTable/type.h"
#include "../constant.h"

#define MAX_LOOP_NESTING 100

struct LoopLabels {
    int start;
    int end;
};

void pushLoop(int start, int end);
void popLoop(void);
int getLoopStart(void);
int getLoopEnd(void);


extern int newLabel;
extern struct param* paramlist;

/* -----output generation----- */

void createOutput(struct ASTNode* root, FILE* output);

void evaluator(struct ASTNode* root);

void setHeader(FILE* output);
void generateFunct(FILE* output, struct ASTNode* id, struct ASTNode* code);

void exitProg(FILE* output);
#endif
