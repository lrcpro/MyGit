//
//  Stack.h
//  Stack
//
//  Created by Lrc mac on 2018/7/21.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#define MAX_SIZE 20
typedef int DataType;

typedef struct stack
{
    DataType _arr[MAX_SIZE];
    int _top ;
}Stack;

void StackInit(Stack *s);
void StackPush(Stack* s, DataType d);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);


//--------括号，RPN



#endif /* Stack_h */
