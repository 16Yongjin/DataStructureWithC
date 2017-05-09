//
//  Deque.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 21..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
    if(pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = pdeq->tail;
    
    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    
    newNode->next = NULL;
    pdeq->tail = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = pdeq->head;
    
    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;
    
    newNode->prev = NULL;
    pdeq->head = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
    
    if(DQIsEmpty(pdeq))
    {
        printf("비었어요 \n");
        exit(-1);
    }
    Node *rNode = (Node*)malloc(sizeof(Node));
    Data rData;
    
    rNode = pdeq->tail;
    rData = pdeq->tail->data;
    
    pdeq->tail = pdeq->tail->prev;
    free(rNode);
    
    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
    

    return rData;
}

Data DQRemoveLast(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("비었어요 \n");
        exit(-1);
    }
    
    Node *rNode = (Node*)malloc(sizeof(Node));
    Data rData;
    
    rNode = pdeq->head;
    rData = pdeq->head->data;
    
    pdeq->head = pdeq->head->next; //앞으로 넘어감
    free(rNode);
    if(pdeq->head == NULL) //head = tail
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;
    

    return rData;
}

Data DQGetFirst(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("비었어요 \n");
        exit(-1);
    }
    
        return pdeq->tail->data;
}

Data DQGetLast(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("비었어요 \n");
        exit(-1);
    }
    
        return pdeq->head->data;
}
