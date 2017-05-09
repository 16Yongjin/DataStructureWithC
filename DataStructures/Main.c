/*
#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0;
    else
        return 1;
}

int main(void)
{
    
    List list; //연결자
    int data; //데이터 그릇
    ListInit(&list); //0, NULL로 초기화
    
    SetSortRule(&list, WhoIsPrecede); //오름차순 설정
    
    
    LInsert(&list, 55);  LInsert(&list, 11);
    LInsert(&list, 32);  LInsert(&list, 22);
    LInsert(&list, 33); //데이터 넣기
    
    
    printf("저장된 데이터의 개수: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    
    
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    
    printf("저장된 데이터의 개수: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}
*/
