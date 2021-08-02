#include <stdio.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot) {
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst) {
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data) {
    BTreeNode * pNode = NULL;    //parrent node
    BTreeNode * cNode = *pRoot;  //current node
    BTreeNode * nNode = NULL;    //new node

    while (cNode != NULL) { //Ȯ���� ��ġ�� NULL�� �ƴҶ����� = �߰��� ��ġ�� ã��������
        if (data == GetData(cNode))
            return; //�ߺ��� Ű�� �Ұ�

        pNode = cNode;

        if (GetData(cNode) > data) //�߰��� ���� ������
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    } //�߰��� ��ġ�� ã��

    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if(pNode != NULL) {
        if (GetData(cNode) > data)
            MakeLeftSubTree(cNode, nNode);
        else
            MakeRightSubTree(cNode, nNode);
    }
    else
        *pRoot = nNode;

}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) {
    BTreeNode * cNode = bst; //current node
    BSTData cData; //current data

    while (cNode != NULL) {
        cData = GetData(cNode);

        if (cData == target)
            return cNode;
        else if (cData > target)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    return NULL;
}