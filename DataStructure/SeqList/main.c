//
//  main.c
//  SeqList
//
//  Created by Lrc mac on 2018/6/19.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include <stdio.h>
#include "SeqList.h"

int main()
{
    SeqList Seq;
    SeqListInit(&Seq);
    
    SeqListPushBack(&Seq, 1);
    SeqListPushBack(&Seq, 2);
    SeqListPushBack(&Seq, 3);
    SeqListPushBack(&Seq, 4);
    SeqListPushBack(&Seq, 5);
    SeqListPushBack(&Seq, 6);
    SeqListPushBack(&Seq, 7);
    SeqListPushBack(&Seq, 8);
    PrintList(&Seq);
    BinarySearch(&Seq, 9);
    //SeqListRemove(&Seq, 5);
    
    
    return 0;
}
