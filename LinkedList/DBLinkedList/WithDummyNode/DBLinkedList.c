#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
    plist->head = (Node*)malloc(sizeof(Node)); //head�� ���̳��
    plist->tail = (Node*)malloc(sizeof(Node)); //tail�� ���̳��

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL; //cur�� First���� ������
    
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data) { //tail�ʿ� �߰�
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
} //���̳�带 ����߱� ������ if�� ���� �ϰ��� ������ ����

int LFirst(List * plist, Data * pdata) {
    if (plist->head->next == plist->tail) //head������ next�� tail�����̸� ó�� ������
        return FALSE;
    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, Data * pdata) {
    if (plist->cur->next == plist->tail) //������ tail�����̸�
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List * plist) {
    Node * rpos = plist->cur;
    Data rdata = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    plist->cur = plist->cur->prev;

    free(rpos);
    (plist->numOfData)--;
    
    return rdata;
}

int LCount(List * plist) {
    return plist->numOfData;
}