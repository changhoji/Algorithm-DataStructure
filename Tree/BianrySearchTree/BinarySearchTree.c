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

    while (cNode != NULL) { //확인할 위치가 NULL이 아닐때동안 = 추가할 위치를 찾을때까지
        if (data == GetData(cNode))
            return; //중복된 키값 불가

        pNode = cNode;

        if (GetData(cNode) > data) //추가할 것이 작으면
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    } //추가할 위치를 찾음

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