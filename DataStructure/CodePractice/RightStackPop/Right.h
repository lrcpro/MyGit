//
//  Right.h
//  Interview2
//
//  Created by Lrc mac on 2018/9/3.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Right_h
#define Right_h

#include "Stack.h"

int IsRihgt(int *inArr, int inSize, int *outArr, int outSize)
{
    Stack s;
    int _In = 0,_Out = 0;
    if (inSize != outSize)
    {
        return 0;
    }
    StackInit(&s);
    while (_Out < outSize)
    {
        while (StackEmpty(&s)||StackTop(&s) != outArr[_Out])
        {
            if (_In < inSize)
            {
                StackPush(&s, inArr[_In]++);
            }
            else
            {
                printf("not right！");
                return 0;
            }
            
        }
        StackPop(&s);
        _Out++;
    }
    
    printf("right!");
    return 1;
}

#endif /* Right_h */
