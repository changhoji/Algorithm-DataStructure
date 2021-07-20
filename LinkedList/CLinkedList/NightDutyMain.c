#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "CLinkedList.h"

void ShowEmployeeInfo(Employee * pemp);
Employee * FindNightDuty(List * plist, char findName[], int day);

int main() {
    //����Ʈ �ʱ�ȭ �� �������� �߰�
    List list;
    ListInit(&list);
    Employee * newEmp;

    newEmp = (Employee*)malloc(sizeof(Employee));
    newEmp->empNum = 1111;
    strcpy(newEmp->name, "Mario");
    LInsert(&list, newEmp);

    newEmp = (Employee*)malloc(sizeof(Employee));
    newEmp->empNum = 2222;
    strcpy(newEmp->name, "Luigi");
    LInsert(&list, newEmp);

    newEmp = (Employee*)malloc(sizeof(Employee));
    newEmp->empNum = 3333;
    strcpy(newEmp->name, "Peach");
    LInsert(&list, newEmp);

    newEmp = (Employee*)malloc(sizeof(Employee));
    newEmp->empNum = 2222;
    strcpy(newEmp->name, "Daisy");
    LInsert(&list, newEmp);

    Employee * dutyEmp = FindNightDuty(&list, "Mario", 1);
    if (dutyEmp == NULL) printf("����!\n");
    else ShowEmployeeInfo(dutyEmp);

    Employee * pemp;
    if (LFirst(&list, &pemp)) {
        free(pemp);
        for (int i = 1; i < LCount(&list)-1; i++) {
            if (LNext(&list, &pemp)) {
                free(pemp);
            }
        }
    }

    return 0;
}

void ShowEmployeeInfo(Employee * pemp) {
    printf("[%d] %s\n", pemp->empNum, pemp->name);
}

Employee * FindNightDuty(List * plist, char findName[], int day) {
    Employee * pemp;
    int cnt = LCount(plist);

    if(LFirst(plist, &pemp)) {
        if (strcmp(findName, pemp->name)) { // ��ã������ LNext�� Ž��
            for (int i = 1; i < cnt; i++) {
                if (LNext(plist, &pemp)) {
                    if (!strcmp(findName, pemp->name)) break;
                }
                return NULL; //findName�� ��ã��
            }
        }
    }
    else return NULL;

    for (int i = 0; i < day%cnt; i++) {
        if (!LNext(plist, &pemp)) return NULL;
    }

    return pemp;
}