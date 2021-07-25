#include <stdio.h>
#include "ExpressionTree.h"

int main() {
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("����: ");
    ShowPrefixTypeExp(eTree); putchar('\n');
    printf("����: ");
    ShowInfixTypeExp(eTree); putchar('\n');
    printf("����: ");
    ShowPostfixTypeExp(eTree); putchar('\n');

    printf("���: %d\n", EvaluateExpTree(eTree));

    return 0;
}