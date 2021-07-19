#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main() {
    //1번
    List list;
    ListInit(&list);
    NameCard * pcard;

    pcard = MakeNameCard("이창호", "010-5026-2713");
    LInsert(&list, pcard);

    pcard = MakeNameCard("한양대", "02-2220-0114");
    LInsert(&list, pcard);

    pcard = MakeNameCard("리오캠핑", "123456789");
    LInsert(&list, pcard);

    //2번
    char findname[20];
    printf("찾을 이름: ");
    scanf("%s", findname);

    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, findname))
            ShowNameCardInfo(pcard);
        while(LNext(&list, &pcard)) {
            if (!NameCompare(pcard, findname))
                ShowNameCardInfo(pcard);
        }
    }

    //3번
    char phone[20];
    printf("변경할 이름: ");
    scanf("%s", findname);
    printf("바꿀 번호: ");
    scanf("%s", phone);
    
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, findname))
            ChangePhoneNum(pcard, phone);
        while(LNext(&list, &pcard)) {
            if (!NameCompare(pcard, findname))
                ChangePhoneNum(pcard, phone);
        }
    }

    //4번
    printf("삭제할 이름: ");
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

    //5번
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