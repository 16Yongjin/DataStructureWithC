//
//  SimpleHeap.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 12. 25..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc) //힙을 초기화함. 배열을 초기화하고 우선순위함수를 지정
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap * ph) //비어있는지 확인하기, 힙에 있는 모든 요소를 꺼낼 때 사용
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx / 2;
}

int GetLChildIDX(int idx)
{
    return idx * 2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx)+1;
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData) //자식 노드 인덱스가 전체 노드 인덱스를 넘어간다 = 자식 노드 없다. 0개 이다.
        return 0; //왼쪽 노드부터 채우므로 오른쪽노드를 받으면 자식이 0개인지 1개인지 불명확
    
    else if (GetLChildIDX(idx) == ph->numOfData) //자식노드 1개 있다.
        return GetRChildIDX(idx);
    
    else //자식노드의 인덱스가 전체의 인덱스보다 작다는 것은 자식노드가 두개 있다는 뜻
    {
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0) //우선 순위 함수가 순위 결정
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data)
{
    int idx = ph->numOfData + 1;
    
    while (idx != 1)
    {
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }
    
    ph -> heapArr[idx] = data;
    ph -> numOfData += 1;
    
}

HData HDelete(Heap * ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph -> heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while ((childIdx = GetHiPriChildIDX(ph, parentIdx)))
    {
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}
