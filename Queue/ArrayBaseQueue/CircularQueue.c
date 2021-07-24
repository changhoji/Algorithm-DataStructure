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
    if (pos == QUE_LEN-1) //���� ť�̹Ƿ�
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pqueue, Data data) {
    if (NextPosIdx(pqueue->rear) == pqueue->front) { //������ �߰� ����
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
    return pqueue->queArr[pqueue->front]; //front�� ��ġ: ù��° ������ ��
}

Data QPeek(Queue * pqueue) {
    if (QIsEmpty(pqueue)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    return pqueue->queArr[NextPosIdx(pqueue->front)];
}