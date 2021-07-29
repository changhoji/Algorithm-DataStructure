#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen) {
    Queue buckets[BUCKET_NUM];
    int bi;
    int pos;
    int di;

    int divfac = 1;
    int radix;

    for (bi = 0; bi < BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]); //버켓들 초기화

    for (pos = 0; pos < maxLen; pos++) { //pos: 최대 자리수만큼 반복
        for (di = 0; di < num; di++) { //정렬할 데이터의 개수만큼 반복
            radix = (arr[di] / divfac) % 10; //자리수 구하기
            Enqueue(&buckets[radix], arr[di]); //radix번째 버켓 큐에 저장
        }

        for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
            while(!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]); //배열에 저장
        }

        divfac *= 10;
    }
}

int main() {
    int arr[] = {13, 212, 14, 7141, 10987, 6, 15};
    RadixSort(arr, 7, 5);

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}