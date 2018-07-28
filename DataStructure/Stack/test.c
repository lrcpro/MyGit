//
//  main.c
//  Stack
//
//  Created by Lrc mac on 2018/7/21.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>

int main()
{
    
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 1);
    StackPush(&s, 1);
    StackPop(&s);

    
    return 0;
}
