#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist) {
    plist->numOfData = 0;
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
}

void LInsert(List * plist, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode; //현재 tail의 next를 newNode로 지정
        plist->tail = newNode; //tail을 newNode로 지정
    }
    (plist->numOfData)++;
}

void LInsertFront(List * plist, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
    if (plist->tail == NULL) return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, Data * pdata) {
    if (plist->tail == NULL) return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List * plist) {
    Node * rpos = plist->cur;
    Data rdata = rpos->data;

    if (rpos == plist->tail) {
        if (plist->tail == plist->tail->next) //마지막 남은 노드면
            plist->tail = NULL;
        else
            plist->tail = plist->before; //cur가 tail이면 tail이 가르키는 대상이 없어지므로 before로 하나 돌려줌
    }

    plist->before->next = plist->cur->next; //cur자리를 없애므로 하나 뛰어서 연결시켜줘야함
    plist->cur = plist->before; //삭제했으므로 cur 하나 되돌리기
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List * plist) {
    return plist->numOfData;
}