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

        if (pq->comp(data1, data2) < 0) //������ �켱������ ũ��
            return RightIndex(idx);
        else
            return LeftIndex(idx);
    }
}

void HInsert(Heap * ph, HData data) {
    int idx = ++(ph->numOfData);

    while(idx != 1) {
        int pIdx = ParentIndex(idx);
        if (ph->comp(data, ph->heapArr[pIdx]) > 0) { //�߰��� ������ �켱���� ������
            ph->heapArr[idx] = ph->heapArr[pIdx];
            idx = pIdx;
        }
        else
            break;
    } //while���� ������ ������ �ڸ��� �߰�

    ph->heapArr[idx] = data;
}

HData HDelete(Heap * ph) {
    HData rdata = ph->heapArr[1];
    HData moveData = ph->heapArr[ph->numOfData];
    int fromIndex, toIndex;
    toIndex = 1;

    while(fromIndex = GetHiPriChildIDX(ph, toIndex)) { //fromIndex�� ������ ���� �ݺ�
        if (ph->comp(moveData, ph->heapArr[fromIndex]) >= 0) //to�� �켱������ �� ������
            break; //����!!

        ph->heapArr[toIndex] = ph->heapArr[fromIndex];
        toIndex = fromIndex; 
    }

    ph->heapArr[toIndex] = moveData;
    (ph->numOfData)--;
    return rdata;
}
