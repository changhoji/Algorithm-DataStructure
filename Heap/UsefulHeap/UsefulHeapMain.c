#include <stdio.h>
#include "UsefulHeap.h"

int CompFunc(char ch1, char ch2) {
    return ch2 - ch1;
    //return ch1 - ch2;
}

int main() {
    Heap heap;
    HeapInit(&heap, CompFunc);

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    
    while(!HIsEmpty(&heap)) {
        printf("%c ", HDelete(&heap));
    }

    return 0;
}