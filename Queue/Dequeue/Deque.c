#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq) {
    if (pdeq->head == NULL) return TRUE;
    else return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pdeq->head; //head 자리에 newNode를 추가하기 때문
    newNode->prev = NULL;

    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else 
        pdeq->head->prev = newNode;
    
    pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;
    newNode->next = NULL;

    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    Node * delNode = pdeq->head;
    Data rdata = delNode->data;
    pdeq->head = pdeq->head->next;

    free(delNode);

    if (pdeq->head == NULL) //지웠더니 empty면 tail도 null로 바꿔줘야함
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL; //그게 아니면 연결만 끊어주기

    return rdata;
}

Data DQRemoveLast(Deque * pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    Node * delNode = pdeq->tail;
    Data rdata = delNode->data;
    pdeq->tail = pdeq->tail->prev;

    free(delNode);

    if (pdeq->tail == NULL) //비어있지만 empty로는 검사할수 없기에 empty상태인
        pdeq->head = NULL;  //head = null로 변경해주어야 함!
    else
        pdeq->tail->next = NULL; //연결 끊어주기        

    return rdata;
}

Data DQGetFirst(Deque * pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque Memory Error!\n");
        exit(-1);
    }

    return pdeq->tail->data;
}