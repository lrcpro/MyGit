//
//  main.c
//  Hash
//
//  Created by Lrc mac on 2018/9/27.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"
int main()
{
    HashTable HT;
    HashTableInit(&HT, 7, mod);
    HashTableInsert(&HT, 1);
    HashTableInsert(&HT, 5);
    HashTableInsert(&HT, 7);
    HashTableInsert(&HT, 12);
    for (int i = 0; i<7; i++)
    {
	if(HT.array[i].state == EXIST)
	{
        printf("%d",HT.array[i].Key);
	}
    }
    return 0;
}
