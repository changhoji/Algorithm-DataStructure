#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
    pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) {
    if (pstack->head == NULL) return TRUE;
    else return FALSE;
}

void SPush(Stack * pstack, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack * pstack) {
    if (pstack->head == NULL) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    Node * rnode = pstack->head;
    Data rdata = rnode->data;

    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}

Data SPeek(Stack * pstack) {
    if (pstack->head == NULL) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->head->data;
}