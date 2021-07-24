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
    newNode->next = pdeq->head; //head �ڸ��� newNode�� �߰��ϱ� ����
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

    if (pdeq->head == NULL) //�������� empty�� tail�� null�� �ٲ������
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL; //�װ� �ƴϸ� ���Ḹ �����ֱ�

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

    if (pdeq->tail == NULL) //��������� empty�δ� �˻��Ҽ� ���⿡ empty������
        pdeq->head = NULL;  //head = null�� �������־�� ��!
    else
        pdeq->tail->next = NULL; //���� �����ֱ�        

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