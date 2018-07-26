//
//  Queue.h
//  Queue
//
//  Created by Lrc mac on 2018/7/22.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef int QDataType;

typedef struct ListNode
{
    QDataType _data;
    struct ListNode* _pNext;
}ListNode,*pListNode;

typedef struct Queue
{
    pListNode _pHead;
    pListNode _pTail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType d);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QDataType Front(Queue* q);
QDataType Back(Queue* q);



#endif /* Queue_h */
