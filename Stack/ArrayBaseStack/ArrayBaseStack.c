#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) {
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) {
    if (pstack->topIndex == -1) return TRUE;
    else return FALSE;
}

void SPush(Stack * pstack, Data data) {
    if (pstack->topIndex == STACK_LEN-1) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }
    
    (pstack->topIndex)++;
    pstack->stackArr[pstack->topIndex] = data;
}

Data Spop(Stack * pstack) {
    int rIdx;

    if (SIsEmpty(pstack)) { //비어있으면 pop 못함
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    rIdx = pstack->topIndex;
    (pstack->topIndex)--;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack) {
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}