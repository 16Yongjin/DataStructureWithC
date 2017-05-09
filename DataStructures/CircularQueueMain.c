//
//  CircularQueueMain.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 14..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "CircularQueue.h"

int main() {
    Queue q;
    
    QueueInit(&q);
    
    for(int i=1; i<100; i++)
    {
        Enqueue(&q, i);
    }
    
    for(int i=0 ; i<100; i++)
    {
        printf("%d \n", Dequeue(&q));
    }
    
    return 0;
}
