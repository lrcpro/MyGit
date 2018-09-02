//
//  Queue.c
//  Queue
//
//  Created by Lrc mac on 2018/7/22.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "Queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

pListNode BuyNode(QDataType d)
{
    pListNode new = malloc(sizeof(ListNode));
    new->_data = d;
    new->_pNext = NULL;
    return new;
}

void QueueInit(Queue* q)
{
    assert(q);
    q->_pHead = BuyNode(0);
    q->_pTail =q->_pHead;
}

void QueuePush(Queue* q, QDataType d)
{
    assert(q);
    q->_pTail->_pNext = BuyNode(d);
    q->_pTail = q->_pTail->_pNext;
    
}

void QueuePop(Queue* q)
{
    pListNode dNode = q->_pHead->_pNext;
    if (dNode) {
        q->_pHead->_pNext = dNode->_pNext;
	if(q->_pHead->_pNext == NULL)
	{  q->_pTail = q->_pHead; }
        free(dNode);
    }
}

int QueueSize(Queue* q)
{
    assert(q);
    pListNode pre = q->_pHead->_pNext;
    int count = 0;
    while (pre)
    {
        count++;
        pre = pre->_pNext;
    }
    return count;
}
int QueueEmpty(Queue* q)
{
    return NULL == q->_pHead->_pNext;
    
}
QDataType Front(Queue* q)
{
    return q->_pHead->_pNext->_data;
}
QDataType Back(Queue* q)
{
    return q->_pTail->_data;
}



