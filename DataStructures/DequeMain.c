//
//  DequeMain.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 21..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "Deque.h"
#include <stdlib.h>

int main()
{
    Deque * d = (Deque*)malloc(sizeof(Deque));
    
    DequeInit(d);
    for(int i =0 ; i< 10; i++)
        DQAddLast(d, i);
    
    for(int i = 15; i<20; i++)
        DQAddFirst(d, i);
    
    for(int i=0; i<15; i++)
        printf("%d ", DQRemoveLast(d));
}
