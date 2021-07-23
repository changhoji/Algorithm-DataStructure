#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op) {
    switch(op) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '(':
            return 1;
    }
}

int WhoPrecOp(char op1, char op2) {
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) return 1;
    else if (op1Prec < op2Prec) return -1;
    else return 0;
}

void ConvToRPNExp(char exp[]) {
    Stack stack;
    StackInit(&stack);
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(sizeof(char)*expLen+1);

    char tok, popData;
    int convIdx = 0;

    for (int i = 0; i < expLen; i++) {
        tok = exp[i];
        if (isdigit(tok)) {
            convExp[convIdx++] = tok;
        }
        else {
            switch(tok) {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(1) {
                        popData = SPop(&stack);
                        if(popData == '(')
                            break;
                        convExp[convIdx++] = popData;
                    }
                    break;

                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) 
                        convExp[convIdx++] = SPop(&stack); //비어있지 않고 자기보다 우선순위가 높은걸 찾을때까지
                    SPush(&stack, tok); 
                    break;
            }
        }
    }

    while(!SIsEmpty(&stack)) { //스택에 오퍼레이터들이 남아있음
        convExp[convIdx++] = SPop(&stack);
    }

    strcpy(exp, convExp);
    free(convExp);
}
