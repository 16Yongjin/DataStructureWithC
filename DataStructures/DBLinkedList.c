#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->head = (Node*)malloc(sizeof(Node));
	
    plist->head->prev = NULL;
    plist->head->next = plist->tail;
    plist->tail->next = NULL;
    plist->tail->prev = plist->head; //더미노드 서로 연결
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;
    
    newNode->next = plist->tail;
    plist->tail->prev = newNode; //편하게 전선만 옮겨주면 됨.

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist)
{
    Node * rNode = plist->cur;
    Data rData = rNode->data;
    
    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    
    plist->cur = plist->cur->prev; // 현재위치 뒤로 물리기.
    
    free(rNode);
    (plist->numOfData)--; // 이거 필수
    return rData;
    
}

int LCount(List * plist)
{
	return plist->numOfData;
}
