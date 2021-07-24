#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pqueue) {
    pqueue->front = 0;
    pqueue->rear = 0;
}

int QIsEmpty(Queue * pqueue) {
    if (pqueue->front == pqueue->rear) return TRUE;
    else return FALSE;
}

int NextPosIdx(int pos) {
    if (pos == QUE_LEN-1) //원형 큐이므로
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pqueue, Data data) {
    if (NextPosIdx(pqueue->rear) == pqueue->front) { //데이터 추가 못함
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pqueue->rear = NextPosIdx(pqueue->rear);
    pqueue->queArr[pqueue->rear] = data;
}

Data Dequeue(Queue * pqueue) {
    if (QIsEmpty(pqueue)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pqueue->front = NextPosIdx(pqueue->front);
    return pqueue->queArr[pqueue->front]; //front의 위치: 첫번째 데이터 전
}

Data QPeek(Queue * pqueue) {
    if (QIsEmpty(pqueue)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    return pqueue->queArr[NextPosIdx(pqueue->front)];
}