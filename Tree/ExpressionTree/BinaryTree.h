#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode();
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data); //http://www.orentec.co.kr/q_a/list.php?rowid=13259&page=1

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);   //전위 순회
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);    //중위 순회
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);  //후위 순회

void DeleteTree(BTreeNode * bt);

#endif
