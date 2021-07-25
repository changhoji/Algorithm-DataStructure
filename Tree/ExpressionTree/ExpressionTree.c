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

BTreeNode * MakeExpTree(char exp[]) { //���� ǥ��� -> Ʈ��
    Stack stack;
    StackInit(&stack);

    BTreeNode * pnode;

    int expLen = strlen(exp);
    char tok;

    for (int i = 0; i < expLen; i++) {
        pnode = MakeBTreeNode();
        tok = exp[i];

        if (isdigit(tok)) {
            SetData(pnode, tok-'0'); //���� ����
        }
        else {
            MakeRightSubTree(pnode, SPop(&stack));  //���߿� ���� ����������
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, tok);
        }

        SPush(&stack, pnode);
    }

    return SPop(&stack); //�������� �ϼ��� �ϳ��� Ʈ���� ������
}

int EvaluateExpTree(BTreeNode * bt) {
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) //����Ұ� ������ ��� Ż��
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