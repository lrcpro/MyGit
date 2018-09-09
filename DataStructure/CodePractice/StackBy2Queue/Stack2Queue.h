//
//  Stack2Queue.h
//  Interview2
//
//  Created by Lrc mac on 2018/9/2.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Stack2Queue_h
#define Stack2Queue_h

#include <stdio.h>
#include "Queue.h"

typedef struct Stack
{
    Queue Q1;
    Queue Q2;
}Stack;

void StackInit(Stack *s)
{
    assert(s);
    QueueInit(&s->Q1);
    QueueInit(&s->Q2);
}
void StackPush(Stack *s, QDataType d)
{
    if (!QueueIsEmpty(&s->Q2))
    {
        QueuePush(&s->Q2, d);
    }
    else
    {
        QueuePush(&s->Q1, d);
    }
}
void StackPop(Stack *s)
{
    if (QueueIsEmpty(&s->Q2))
    {
        while (QueueSize(&s->Q1)>1)
        {
            QueuePush(&s->Q2, QueueGetHead(&s->Q1));
            QueuePop(&s->Q1);
        }
        QueuePop(&s->Q1);
    }
    else
    {
        while (QueueSize(&s->Q2)>1)
        {
            QueuePush(&s->Q1, QueueGetHead(&s->Q2));
            QueuePop(&s->Q2);
        }
        QueuePop(&s->Q2);
    }
    
}
int StackIsEmpty(Stack *s)
{
    return QueueIsEmpty(&s->Q2)&&QueueIsEmpty(&s->Q1);
}
QDataType StackGetTop(Stack *s)
{
    if (QueueIsEmpty(&s->Q1))
    {
        return QueueGetTail(&s->Q2);
    }
    else
    {
        return QueueGetTail(&s->Q1);
    }
}
int StackSize(Stack *s)
{
    return QueueSize(&s->Q1)+QueueSize(&s->Q2);
}

#endif /* Stack2Queue_h */
