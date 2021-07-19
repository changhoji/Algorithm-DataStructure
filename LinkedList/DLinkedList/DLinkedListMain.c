#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(LData d1, LData d2) {
    if (d1 < d2) return 0;
    else return 1;
}

int main() {
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    //저장된 데이터 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }

        printf("\n");
    }

    //22 제거
    if (LFirst(&list, &data)) {
        if (data == 22) LRemove(&list);

        while(LNext(&list, &data)) {
            if (data == 22) LRemove(&list);
        }

        printf("\n");
    }

    //22 제거 후 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }

        printf("\n");
    }

    return 0;
}