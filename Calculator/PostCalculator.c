#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
    Stack stack;
    StackInit(&stack);

    int expLen = strlen(exp);
    char tok;

    for (int i = 0; i < expLen; i++) {
        tok = exp[i];
        if (isdigit(tok)) {
            SPush(&stack, tok - '0');
        }
        else {
            char num2 = SPop(&stack);
            char num1 = SPop(&stack);

            switch (tok) {
                case '+':
                    SPush(&stack, num1+num2);
                    break;
                case '-':
                    SPush(&stack, num1-num2);
                    break;
                case '*':
                    SPush(&stack, num1*num2);
                    break;
                case '/':
                    SPush(&stack, num1/num2);
                    break;
            }
        }
    }

    return SPop(&stack);
}