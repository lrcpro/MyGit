//
//  MinStack.c
//  Interview
//
//  Created by Lrc mac on 2018/7/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "MinStack.h"
#include <assert.h>


void StackInit(Stack *s)
{
    assert(s);
    s->_top = 0;
}

int StackEmpty(Stack* s)
{
    if (s->_top==0)
    {
        return 1;
    }
    return 0;
}

DataType StackTop(Stack* s)
{
    assert(s);
    return s->_arr[s->_top -1];
}

void StackPush(Stack* s, minDataType d)
{
    assert(s);
    SElem tmp;
    tmp._min =d;
    tmp._data = d;
    if(s->_top == MAX_SIZE)
    {
        printf("full stack\n");
        return ;
    }
    else
    {
        
        if (!StackEmpty(s))
        {
            if (StackTop(s)._min<d)
            {
                tmp._min = StackTop(s)._min;
            }
        }
        s->_arr[s->_top] = tmp;
        s->_top ++;
    }
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



int StackSize(Stack* s)
{
    return s->_top;
}

int StackGetMin(Stack* s)
{
    return s->_arr[s->_top-1]._min;
}
