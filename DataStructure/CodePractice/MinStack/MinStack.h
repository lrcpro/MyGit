//
//  MinStack.h
//  Interview
//
//  Created by Lrc mac on 2018/7/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef MinStack_h
#define MinStack_h

#include <stdio.h>

/////////////////////////////////////////
typedef int minDataType;
typedef struct SElem
{
    minDataType _data;
    minDataType _min;
}SElem;
/////////////////////////////////////////
#define MAX_SIZE 20
typedef SElem DataType;

typedef struct stack
{
    DataType _arr[MAX_SIZE];
    int _top ;
}Stack;

void StackInit(Stack *s);
void StackPush(Stack* s, minDataType d);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
int StackGetMin(Stack* s);



#endif /* MinStack_h */
