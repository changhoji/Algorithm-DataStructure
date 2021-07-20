#include <stdio.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
    plist->numOfData = 0;
    plist->head = NULL;
}

void LInsert(List * plist, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head; //newNode�� next�� ���� head�� ����Ű��
    if (plist->head != NULL) //��尡 �����ϸ�
        plist->head->prev = newNode; //���� head�� prev�� newNode�� ����Ŵ

    newNode->prev = NULL; //head��ġ�� newNode�� prev�� ����Ű�� ����� ����
    plist->head = newNode; //head�� newNode�� �ٲ�

    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
    if (plist->head == NULL) return FALSE; //�����Ͱ� ������

    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, Data * pdata) {
    if (plist->cur->next == NULL) return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrevious(List * plist, Data * pdata) {
    if (plist->cur->prev == NULL) return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List * plist) {
    return plist->numOfData;
}