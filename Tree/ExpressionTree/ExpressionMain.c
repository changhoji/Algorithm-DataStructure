#include <stdio.h>
#include "ExpressionTree.h"

int main() {
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("전위: ");
    ShowPrefixTypeExp(eTree); putchar('\n');
    printf("중위: ");
    ShowInfixTypeExp(eTree); putchar('\n');
    printf("후위: ");
    ShowPostfixTypeExp(eTree); putchar('\n');

    printf("결과: %d\n", EvaluateExpTree(eTree));

    return 0;
}