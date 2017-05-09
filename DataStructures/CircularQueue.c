//
//  CircularQue.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 13..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

typedef CQueue Queue;

void QueueInit(Queue * pq){
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq){
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if(pos == QUE_LEN-1)
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pq, Data data){
    if(NextPosIdx(pq->rear)== pq->front)
    {
        printf("꽉찼네요\n");
        exit(-1);
    }
    printf("채운다 %d!\n", data);
    pq->rear=NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
    
}

Data Dequeue(Queue * pq){
    if(QIsEmpty(pq))
    {
        printf("비었네요\n");
        exit(-1);
    }
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue * pq){
    if(QIsEmpty(pq))
    {
        printf("비었네요\n");
        exit(-1);
    }
    
    return pq->queArr[pq->front+1];
}
