#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
    int firstIdx = left;
    int secondIdx = mid+1;

    int * sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sortIdx = left;

    while (firstIdx <= mid && secondIdx <= right) {
        if (arr[firstIdx] <= arr[secondIdx])
            sortArr[sortIdx] = arr[firstIdx++];
        else 
            sortArr[sortIdx] = arr[secondIdx++];

        sortIdx++;
    }

    if (firstIdx <= mid) { //첫번째가 남아있으면
        for (int i = firstIdx; i <= mid; i++)
            sortArr[sortIdx++] = arr[i];
    }
    else {
        for (int i = secondIdx; i <= right; i++)
            sortArr[sortIdx++] = arr[i];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) { //나눌수 있으면
        int mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 4, 3, 6, 7, 1};
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}