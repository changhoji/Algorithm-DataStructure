#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pqueue);
int QIsEmpty(Queue * pqueue);

void Enqueue(Queue * pqueue, Data data);
Data Dequeue(Queue * pqueue);
Data QPeek(Queue * pqueue);

#endif