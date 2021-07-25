/*
#include <stdio.h>
#include "CLinkedList.h"

int main() {
    List list;
    Data data;
    ListInit(&list);

    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    if (LFirst(&list, &data)) {
        printf("%d ", data);
        for (int i = 0; i < 3*LCount(&list)-1; i++) {
            if (LNext(&list, &data)) {
                printf("%d ", data);
            }
        }
    }
    printf("\n");

    int nodeNum = LCount(&list);

    if (nodeNum) {
        LFirst(&list, &data);
        if (!(data%2)) LRemove(&list);
        for (int i = 0; i < nodeNum-1; i++) {//while(LNext(&list, &data))를 사용하면 무한루프를 돌게됨. 원형리스트기 때문에!
            if (LNext(&list, &data)) {
                if (!(data%2)) LRemove(&list);
            }
        }
    }

    if (LFirst(&list, &data)) {
        printf("%d ", data);
        for (int i = 0; i < nodeNum-1; i++) {
            if (LNext(&list, &data)) {
                printf("%d ", data);
            }
        }
    }

    return 0;
}
*/