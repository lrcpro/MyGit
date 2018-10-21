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

size_t HashFunc(HashBucket *pHB,HashKey key)
{
    return key%pHB->Capacity;
}

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

int HashBucketSearch(const HashBucket *pHB, HashKey key)
{
    assert(pHB);
    for (int i = 0; i<pHB->Capacity; i++)
    {
        if (pHB->Array[i]!=NULL)
        {
            Node* cur = pHB->Array[i];
            while (cur!=NULL)
            {
                if (cur->key == key)
                    return 1;
                
                cur = cur->Next;
            }
        }
    }
    return 0;
}

void HashBucketInsert(HashBucket *pHB, HashKey key)
{
    if (HashBucketSearch(pHB, key))
    {
        return;
    }
    
    //explor
    int index = (int)HashFunc(pHB, key);
    if (pHB->Array[index] == NULL)
    {
        pHB->Array[index] = (Node*)malloc(sizeof(Node));
        pHB->Array[index]->key = key;
        pHB->Array[index]->Next = NULL;
    }
    else
    {
        Node *NewNode = (Node*)malloc(sizeof(Node));
        NewNode->Next = pHB->Array[index];
        NewNode->key =key;
        pHB->Array[index] = NewNode;
    }
    pHB->Size++;
    
}














