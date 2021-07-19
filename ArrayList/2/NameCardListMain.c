#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main() {
    //1��
    List list;
    ListInit(&list);
    NameCard * pcard;

    pcard = MakeNameCard("��âȣ", "010-5026-2713");
    LInsert(&list, pcard);

    pcard = MakeNameCard("�Ѿ��", "02-2220-0114");
    LInsert(&list, pcard);

    pcard = MakeNameCard("����ķ��", "123456789");
    LInsert(&list, pcard);

    //2��
    char findname[20];
    printf("ã�� �̸�: ");
    scanf("%s", findname);

    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, findname))
            ShowNameCardInfo(pcard);
        while(LNext(&list, &pcard)) {
            if (!NameCompare(pcard, findname))
                ShowNameCardInfo(pcard);
        }
    }

    //3��
    char phone[20];
    printf("������ �̸�: ");
    scanf("%s", findname);
    printf("�ٲ� ��ȣ: ");
    scanf("%s", phone);
    
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, findname))
            ChangePhoneNum(pcard, phone);
        while(LNext(&list, &pcard)) {
            if (!NameCompare(pcard, findname))
                ChangePhoneNum(pcard, phone);
        }
    }

    //4��
    printf("������ �̸�: ");
    scanf("%s", findname);
    
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, findname))
            LRemove(&list);
        while(LNext(&list, &pcard)) {
            if (!NameCompare(pcard, findname))
                LRemove(&list);
                free(pcard);
        }
    }

    //5��
    if (LFirst(&list, &pcard)) {
        ShowNameCardInfo(pcard);
        free(pcard);
        while(LNext(&list, &pcard)) {
            ShowNameCardInfo(pcard);
            free(pcard);
        }
    }

    return 0;
}