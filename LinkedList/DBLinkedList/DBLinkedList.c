#include <stdio.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
    plist->numOfData = 0;
    plist->head = NULL;
}

void LInsert(List * plist, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head; //newNode의 next가 원래 head를 가르키고
    if (plist->head != NULL) //노드가 존재하면
        plist->head->prev = newNode; //기존 head의 prev는 newNode를 가르킴

    newNode->prev = NULL; //head위치의 newNode는 prev가 가르키는 대상이 없음
    plist->head = newNode; //head를 newNode로 바꿈

    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
    if (plist->head == NULL) return FALSE; //데이터가 없으면

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