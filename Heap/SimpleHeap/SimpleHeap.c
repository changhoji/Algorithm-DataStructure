#include "SimpleHeap.h"

void HeapInit(Heap * ph) {
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph) {
    if (ph->numOfData) return FALSE;
    else return TRUE;
}

int GetParentIDX(int idx) {
    return idx/2;
}

int GetLChildIDX(int idx) {
    return idx*2;
}

int GetRChildIDX(int idx) {
    return idx*2+1;
}

int GetHiPriChildIdx(Heap * ph, int idx) {
    if (GetLChildIDX(idx) > ph->numOfData) 
        return 0;
    else if (GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else {
        if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetLChildIDX(idx);
        else 
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data, Priority pr) {
    HeapElem newHEle = {pr, data};
    int idx = ph->numOfData;

    while (idx != 1) {
        if (pr < ph->heapArr[GetParentIDX(idx)].pr) { //추가할 노드가 부모노드보가 우선순위가 높다면
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; //부모노드 밑으로 내림
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    (ph->numOfData)++;
    ph->heapArr[idx] = newHEle;
}

HData HDelete(Heap * ph) {
    HData rdata = ph->heapArr[1].data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while(childIdx = GetHiPriChildIdx(ph, parentIdx)) {
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    (ph->numOfData)--;
    return rdata;
}