//
//  HashBucket.h
//  HashBucket
//
//  Created by Lrc mac on 2018/10/9.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef HashBucket_h
#define HashBucket_h

#include <stdio.h>

typedef int HashKey;

typedef struct Node
{
    HashKey key;
    struct Node* Next;
}Node;

typedef struct HashBucket
{
    Node **Array;
    size_t Size;
    size_t Capacity;
    
}HashBucket;

void HashBucketInit(HashBucket *pHB, size_t capacity);
void HashBucketDestroy(HashBucket *pHB);
int HashBucketSearch(const HashBucket *pHB, HashKey key);
void HashBucketInsert(HashBucket *pHB, HashKey key);


#endif /* HashBucket_h */
