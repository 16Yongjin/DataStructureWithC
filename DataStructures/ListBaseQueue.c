//
//  ListBaseQueue.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 15..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "ListBaseQueue.h"
#include <stdlib.h>

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }
    
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue * pq)
{
    if (QIsEmpty(pq)) {
        printf("비었네요");
        exit(-1);
    }
    Node * delNode;
    Data rData = pq->front->data;
    
    delNode = pq->front;
    pq->front = pq->front->next;
    free(delNode);
    return rData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("비었네요");
        exit(-1);
    }
    
    return pq->front->data;
}
