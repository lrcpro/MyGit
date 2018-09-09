//
//  Queue.h
//  Interview2
//
//  Created by Lrc mac on 2018/9/2.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;

typedef struct ListNode
{
    QDataType _data;
    struct ListNode *_next;
}ListNode;

typedef struct Queue
{
    ListNode *_pHead;
    ListNode *_pTail;
    
}Queue;

ListNode* BuyNode(QDataType d)
{
    ListNode *NewNode = (ListNode*)malloc(sizeof(ListNode));
    NewNode->_data = d;
    NewNode->_next = NULL;
    return NewNode;
}
void QueueInit(Queue *q)
{
    assert(q);
    q->_pHead = BuyNode(0);
    q->_pTail = q->_pHead;
}
void QueuePush(Queue *q, QDataType d)
{
    q->_pTail->_next = BuyNode(d);
    q->_pTail = q->_pTail->_next;
}
void QueuePop(Queue *q)
{
    ListNode *delete = q->_pHead->_next;
    q->_pHead->_next = delete->_next;
    if (q->_pHead->_next == NULL)
    { q->_pTail = q->_pHead; }
    free(delete);
}
int QueueIsEmpty(Queue *q)
{
    if (NULL == q->_pHead->_next)
    {
        return 1;
    }
    return 0;
}
int QueueSize(Queue *q)
{
    ListNode *pre = q->_pHead->_next;
    int count = 0;
    while (pre)
    {
        count++;
        pre = pre->_next;
    }
    return count;
}
QDataType QueueGetHead(Queue *q)
{
    return q->_pHead->_next->_data;
}
QDataType QueueGetTail(Queue *q)
{
    return q->_pTail->_data;
}



#endif /* Queue_h */
