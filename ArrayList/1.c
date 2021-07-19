#include <stdio.h>
#include "ArrayList.h"

int main() {
    //1�� �κ�
    List list;
    ListInit(&list);
    for (int i = 1; i <= 9; i++) {
        LInsert(&list, i);
    }

    //2�� �κ�
    LData data;
    int sum = 0;

    if (LFirst(&list, &data)) {
        sum += data;
        while(LNext(&list, &data)) {
            sum += data;
        }
    }
    else puts("����!");

    printf("sum = %d\n", sum);

    //3�� �κ�
    if (LFirst(&list, &data)) {
        if (!(data%2) || !(data%3)) LRemove(&list);
        while (LNext(&list, &data)) {
            if (!(data%2) || !(data%3)) LRemove(&list);
        }
    }
    
    //4�� �κ�

    printf("����Ʈ ��: ");
    if (LFirst(&list, &data)) {
        printf("%d ", data);
        while (LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n");

    return 0;
}