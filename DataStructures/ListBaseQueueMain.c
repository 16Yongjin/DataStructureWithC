//
//  ListBaseQueueMain.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 15..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "ListBaseQueue.h"
#include <stdlib.h>

int main() {
    Queue * q = (Queue*)malloc(sizeof(Queue));
    QueueInit(q);
    
    for(int i=1; i<6; i++)
    {
        Enqueue(q, i);
    }
    
    for(int i = 0; i<5; i++)
    {
        printf("%d\n", Dequeue(q));
    }
    
}
