//
//  Stack.h
//  RightStackPop
//
//  Created by Lrc mac on 2018/9/3.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 20
typedef int DataType;

typedef struct stack
{
    DataType _arr[MAX_SIZE];
    int _top ;
}Stack;

void StackInit(Stack *s)
{
    assert(s);
    s->_top = 0;
}

void StackPush(Stack* s, DataType d)
{
    assert(s);
    if(s->_top == MAX_SIZE)
    {
        printf("full stack\n");
        return ;
    }
    else
    {
        s->_arr[s->_top] = d;
        s->_top ++;
    }
}
int StackEmpty(Stack* s)
{
    if (s->_top==0)
    {
        return 1;
    }
    return 0;
}

void StackPop(Stack* s)
{
    assert(s);
    if (StackEmpty(s))
    {
        printf("empty stack\n");
        return ;
    }
    
    s->_top --;
}

DataType StackTop(Stack* s)
{
    assert(s);
    return s->_arr[s->_top -1];
}

int StackSize(Stack* s)
{
    return s->_top;
}

#endif /* Stack_h */
