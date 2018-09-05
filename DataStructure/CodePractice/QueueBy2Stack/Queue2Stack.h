//
//  Queue2Stack.h
//  Interview
//
//  Created by Lrc mac on 2018/7/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Queue2Stack_h
#define Queue2Stack_h

#include <stdio.h>
#include "Stack.h"

typedef struct Queue2Stack
{
    Stack _s1;
    Stack _s2;
}Queue2Stack;

void Queue2Init(Queue2Stack *q);
void Queue2Push(Queue2Stack* q, DataType d);
void Queue2Pop(Queue2Stack* q);
DataType Queue2Front(Queue2Stack* q);
DataType Queue2Back(Queue2Stack* q);
int Queue2Size(Queue2Stack* q);





#endif /* Queue2Stack_h */
