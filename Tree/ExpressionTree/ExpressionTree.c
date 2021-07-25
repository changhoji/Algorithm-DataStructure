#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "ListBaseStack.h"

void ShowNodeData(int data) {
    if (0 <= data && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

BTreeNode * MakeExpTree(char exp[]) { //후위 표기법 -> 트리
    Stack stack;
    StackInit(&stack);

    BTreeNode * pnode;

    int expLen = strlen(exp);
    char tok;

    for (int i = 0; i < expLen; i++) {
        pnode = MakeBTreeNode();
        tok = exp[i];

        if (isdigit(tok)) {
            SetData(pnode, tok-'0'); //정수 저장
        }
        else {
            MakeRightSubTree(pnode, SPop(&stack));  //나중에 들어간게 오른쪽으로
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, tok);
        }

        SPush(&stack, pnode);
    }

    return SPop(&stack); //마지막에 완성된 하나의 트리를 리턴함
}

int EvaluateExpTree(BTreeNode * bt) {
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) //계산할게 없으면 재귀 탈출
        return GetData(bt);
    int op1, op2;

    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt)) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }

    return 0;
}

void ShowPrefixTypeExp(BTreeNode * bt) {
    PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt) {
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt) {
    PostorderTraverse(bt, ShowNodeData);
}