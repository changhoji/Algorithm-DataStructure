#include <stdio.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

int main() {
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);

    while(!SIsEmtpy(&stack)) {
        printf("%d ", SPop(&stack));
    }

    return 0;
}
