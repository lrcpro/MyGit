//
//  main.c
//  LinkList
//
//  Created by Lrc mac on 2018/6/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"

int main()
{
    pList L;
    pList J;
    
    InitLinkList(&L);
    PushBack(&L, 1);
    PushBack(&L, 2);
    PushBack(&L, 3);
    PushBack(&L, 4);
    PushBack(&L, 5);
    PushBack(&L, 6);
    PushBack(&L, 7);
    PushBack(&L, 8);

//    InitLinkList(&J);
//    PushBack(&J, 1);
//    PushBack(&J, 2);
//    PushBack(&J, 3);

    FindNode(L, 8)->next = FindNode(L, 5);

    JudgeCircle(L);

    
    
    return 0;
}







//     有头
//     双向
