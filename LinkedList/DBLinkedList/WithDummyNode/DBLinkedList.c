#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
    plist->head = (Node*)malloc(sizeof(Node)); //head쪽 더미노드
    plist->tail = (Node*)malloc(sizeof(Node)); //tail쪽 더미노드

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL; //cur는 First에서 정해짐
    
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data) { //tail쪽에 추가
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
} //더미노드를 사용했기 때문에 if문 없이 일관된 진행을 보임

int LFirst(List * plist, Data * pdata) {
    if (plist->head->next == plist->tail) //head더미의 next가 tail더미이면 처음 상태임
        return FALSE;
    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, Data * pdata) {
    if (plist->cur->next == plist->tail) //다음이 tail더미이면
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