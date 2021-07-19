#include <stdio.h>

int BinarySearch(int arr[], int len, int target);

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 7);
    printf("%d\n", idx);

    idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 4);
    printf("%d\n", idx);

    return 0;
}

int BinarySearch(int arr[], int len, int target) {
    int first = 0;
    int last = len-1;
    int mid;

    while (first <= last) { //first == last일때도 비교대상이 남아있음
        mid = (first + last) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] > target) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return -1;
}