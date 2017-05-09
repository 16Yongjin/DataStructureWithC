//
//  Stacking.cpp
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 1..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include "Stacking.hpp"
#include <stdlib.h>

void StackInit(Stack * pstack)
{
    pstack->plist = (List*)malloc(sizeof(List));
    ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack)
{
    if(LCount(pstack->plist) == 0)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack)
{
    Data rData;
    LFirst(pstack->plist, &rData);
    LRemove(pstack->plist);
    return rData;
}

