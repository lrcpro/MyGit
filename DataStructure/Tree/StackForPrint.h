//
//  Header.h
//  Tree
//
//  Created by Lrc mac on 2018/9/10.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef StackForPrint_h
#define StackForPrint_h

#include "Tree.h"
#include "assert.h"

#define MAX_SIZE 20

typedef struct stack
{
    TreeNode* _arr[MAX_SIZE];
    int _top ;
}Stack;

void StackInit(Stack *s)
{
    assert(s);
    s->_top = 0;
    for (int i = 0; i<MAX_SIZE; i++)
    {
        s->_arr[i] = NULL;
    }
}
void StackPush(Stack* s, TreeNode* d)
{
    s->_arr[s->_top] = d;
    s->_top++;
}

void StackPop(Stack* s)
{
    s->_top--;
}
TreeNode* StackTop(Stack* s)
{
    return s->_arr[s->_top-1];
}
int StackSize(Stack* s)
{
    return s->_top;
}
int StackEmpty(Stack* s)
{
    return s->_top==0;
}











#endif /* StackForPrint_h */
