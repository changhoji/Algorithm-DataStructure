#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {
    int expLen = strlen(exp)+1;
    char * cpyExp = (char*)malloc(expLen+1); //전달된 문자열의 변경을 막기 위해 복사함
    strcpy(cpyExp, exp);

    ConvToRPNExp(cpyExp);
    int result = EvalRPNExp(cpyExp);
    free(cpyExp);

    return result;
}