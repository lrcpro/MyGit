//
//  Queue2Stack.c
//  Interview
//
//  Created by Lrc mac on 2018/7/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "Queue2Stack.h"
#include <assert.h>
void Queue2Init(Queue2Stack *q)
{
    StackInit(&q->_s1);
    StackInit(&q->_s2);
    
}

void Queue2Push(Queue2Stack* q, DataType d)
{
    StackPush(&q->_s1, d);
}

void Queue2Pop(Queue2Stack* q)
{
    if (StackEmpty(&q->_s1)&&StackEmpty(&q->_s2))
    {
        return;
    }
    if (StackEmpty(&q->_s2))
    {
        while (!StackEmpty(&q->_s1))
        {
            StackPush(&q->_s2, StackTop(&q->_s1));
            StackPop(&q->_s1);
        }
    }
    StackPop(&q->_s2);
}

DataType Queue2Front(Queue2Stack* q)
{
    assert(!StackEmpty(&q->_s2) || !StackEmpty(&q->_s1));
    
    if (StackEmpty(&q->_s2))
    {
        while (!StackEmpty(&q->_s1))
        {
            StackPush(&q->_s2, StackTop(&q->_s1));
            StackPop(&q->_s1);
        }
    }
    return StackTop(&q->_s2);
}

DataType Queue2Back(Queue2Stack* q)
{
    assert(!StackEmpty(&q->_s2) || !StackEmpty(&q->_s1));
    
    if (StackEmpty(&q->_s1))
    {
        while (!StackEmpty(&q->_s2))
        {
            StackPush(&q->_s1, StackTop(&q->_s2));
            StackPop(&q->_s2);
        }
    }
    return StackTop(&q->_s1);
}

int Queue2Size(Queue2Stack* q)
{
    return StackSize(&q->_s1)+StackSize(&q->_s2);
}

