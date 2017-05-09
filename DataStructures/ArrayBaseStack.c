#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	//시작하기 겸 초기화
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	//비어있는지 확인하기
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    pstack->stackArr[++(pstack->topIndex)] = data; // 넣기
}

Data SPop(Stack * pstack) //꺼내기
{
	if(SIsEmpty(pstack))
    {
        printf("This is empty \n");
        exit(1);
    }
    Data popN = pstack->stackArr[(pstack->topIndex)--];
    return popN;
}

Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("This is empty \n");
        exit(1);
    }
    
    Data peekN = pstack->stackArr[pstack->topIndex];
    return peekN;
}
