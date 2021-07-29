#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap * ph) {
    if (ph->numOfData) return FALSE;
    else return TRUE;
}

int LeftIndex(int index) {
    return index*2;
}

int RightIndex(int index) {
    return index*2+1;
}

int ParentIndex(int index) {
    return index/2;
}

int GetHiPriChildIDX(Heap * pq, int idx) {
    if (LeftIndex(idx) > pq->numOfData) return 0;
    else if (LeftIndex(idx) == pq->numOfData)
        return LeftIndex(idx);
    else {
        HData data1, data2;
        data1 = pq->heapArr[LeftIndex(idx)];
        data2 = pq->heapArr[RightIndex(idx)];

        if (pq->comp(data1, data2) < 0) //오른쪽 우선순위가 크면
            return RightIndex(idx);
        else
            return LeftIndex(idx);
    }
}

void HInsert(Heap * ph, HData data) {
    int idx = ++(ph->numOfData);

    while(idx != 1) {
        int pIdx = ParentIndex(idx);
        if (ph->comp(data, ph->heapArr[pIdx]) > 0) { //추가할 데이터 우선순위 높으면
            ph->heapArr[idx] = ph->heapArr[pIdx];
            idx = pIdx;
        }
        else
            break;
    } //while문이 끝나면 정해진 자리에 추가

    ph->heapArr[idx] = data;
}

HData HDelete(Heap * ph) {
    HData rdata = ph->heapArr[1];
    HData moveData = ph->heapArr[ph->numOfData];
    int fromIndex, toIndex;
    toIndex = 1;

    while(fromIndex = GetHiPriChildIDX(ph, toIndex)) { //fromIndex가 존재할 동안 반복
        if (ph->comp(moveData, ph->heapArr[fromIndex]) >= 0) //to의 우선순위가 더 높으면
            break; //멈춰!!

        ph->heapArr[toIndex] = ph->heapArr[fromIndex];
        toIndex = fromIndex; 
    }

    ph->heapArr[toIndex] = moveData;
    (ph->numOfData)--;
    return rdata;
}
