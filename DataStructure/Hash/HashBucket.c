//
//  HashBucket.c
//  HashBucket
//
//  Created by Lrc mac on 2018/10/9.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "HashBucket.h"
#include <stdio.h>
#include <stdlib.h>

void HashBucketInit(HashBucket *pHB, size_t capacity)
{
    pHB->Array = (Node**)malloc(sizeof(Node *)*capacity);
    pHB->Capacity = capacity;
    pHB->Size = 0;
    for (int i = 0; i<capacity; i++)
    {
        pHB->Array[i]=NULL;
    }
}

void ListDestroy(Node *fist)
{
    Node *next;
    for (Node *cur = fist; cur!=NULL; cur = next)
    {
        next = cur->Next;
        free(cur);
    }
}

void HashBucketDestroy(HashBucket *pHB)
{
    for (int i = (int)pHB->Capacity; i>0; i--)
    {
        ListDestroy(pHB->Array[i]);
    }
    free(pHB->Array);
}

void HashBucketInsert()
{
    
}














