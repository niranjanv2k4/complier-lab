#include "./helper.h"

uint32_t used = 0;
int newLabel = 0;
int regNum = 0;

bool isMain = false;
bool headerSet = true;

/* array for keeping track of current  loop labels */
static struct LoopLabels loopStack[MAX_LOOP_NESTING];
int loopTop = -1;

void pushLoop(int start, int end) {
    loopTop++;
    loopStack[loopTop].start = start;
    loopStack[loopTop].end   = end;
}
void popLoop(void) {
    loopTop--;
}
int getLoopStart(void) {
    return loopStack[loopTop].start;
}
int getLoopEnd(void) {
    return loopStack[loopTop].end;
}

/* -----Register & label managing----- */
int getReg(){
    for(int i = 0; i<20; i++){
        if(!(used & (1u <<i))){
            used |= (1u <<i);
            return i;
        }
    }
    printf("Out of regusters\n");
    exit(1);
    return -1;
}

int freeReg(int reg){
    if(reg>=0 && reg<20 && (used & (1u <<reg))){
        used &= ~(1u <<reg);
        return 0;
    }
    printf("No registers to free - %d\n", reg);
    exit(1);
    return -1;
}

int getNewLabel(){
    return newLabel++;
}

