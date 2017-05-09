//
//  SimpleHeapMain.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 12. 30..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char p1, char p2)
{
    return p2-p1;
}

int main() {
    Heap * h;
    HeapInit(h, DataPriorityComp);
    
    HInsert(h, 'A');
    HInsert(h, 'B');
    HInsert(h, 'C');
    HInsert(h, 'D');
    HInsert(h, 'E');
    HInsert(h, 'A');
    HInsert(h, 'B');
    HInsert(h, 'C');
    HInsert(h, 'D');
    HInsert(h, 'E');
    HInsert(h, 'D');
    
    while(!HIsEmpty(h))
    {
        printf("%c \n", HDelete(h));
    }
}
