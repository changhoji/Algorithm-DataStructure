#include <stdio.h>
#include "ArrayList.h"

int main() {
    //1번 부분
    List list;
    ListInit(&list);
    for (int i = 1; i <= 9; i++) {
        LInsert(&list, i);
    }

    //2번 부분
    LData data;
    int sum = 0;

    if (LFirst(&list, &data)) {
        sum += data;
        while(LNext(&list, &data)) {
            sum += data;
        }
    }
    else puts("오류!");

    printf("sum = %d\n", sum);

    //3번 부분
    if (LFirst(&list, &data)) {
        if (!(data%2) || !(data%3)) LRemove(&list);
        while (LNext(&list, &data)) {
            if (!(data%2) || !(data%3)) LRemove(&list);
        }
    }
    
    //4번 부분

    printf("리스트 값: ");
    if (LFirst(&list, &data)) {
        printf("%d ", data);
        while (LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n");

    return 0;
}