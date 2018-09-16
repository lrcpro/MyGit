//
//  QueueForLP.h
//  Tree
//
//  Created by Lrc mac on 2018/9/8.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef QueueForLP_h
#define QueueForLP_h

#include "Tree.h"

typedef struct QueueNode
{
    TreeNode *Tdata;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue
{
    QueueNode *Head;
    QueueNode *Tail;
}Queue;

QueueNode *BuyQueueNode(TreeNode *Td)
{
    QueueNode *New = (QueueNode*)malloc(sizeof(QueueNode));
    New->Tdata = Td;
    New->next = NULL;
    return New;
}


void QueueInit(Queue *q)
{
    //asssert
    q->Head = BuyQueueNode(NULL);
    q->Tail = q->Head;
}

void QueuePush(Queue *q, TreeNode *iRoot)
{
    q->Tail->next = BuyQueueNode(iRoot);
    q->Tail = q->Tail->next;
}

void QueuePop(Queue *q)
{
    QueueNode *del = q->Head->next;
    q->Head->next = del->next;
    if (del)
    {
        if (del == q->Tail)
        {
            q->Tail = q->Head;
        }
        free(del);
    }
}

TreeNode *GetQfront(Queue *q)
{
    return q->Head->next->Tdata;
}

int IsEmptyQueue(Queue *q)
{
    if (q->Head == q->Tail)
    {
        return 1;
    }
    return 0;
}



















#endif /* QueueForLP_h */
