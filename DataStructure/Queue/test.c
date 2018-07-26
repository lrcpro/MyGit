//
//  main.c
//  Queue
//
//  Created by Lrc mac on 2018/7/22.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"
int main()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    printf("%d\t",Front(&q));
    printf("%d\t",Back(&q));
    
    QueuePush(&q,5);
    printf("%d\t",Back(&q));
    
    QueuePop(&q);
    printf("%d\t",Front(&q));
    printf("%d\t",Back(&q));
    

    
    return 0;
}
