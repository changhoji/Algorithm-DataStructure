#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target);

int main() {
    int arr[] = {1, 3, 5, 7, 9};

    printf("%d\n", BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 6));
    
    return 0;
}

int BSearchRecur(int arr[], int first, int last, int target) {
    if (first > last) return -1;
    int mid = (first + last) / 2;
    if (arr[mid] == target) return mid;

    if (arr[mid] > target)
        return BSearchRecur(arr, first, mid-1, target);
    else
        return BSearchRecur(arr, mid+1, last, target);
}