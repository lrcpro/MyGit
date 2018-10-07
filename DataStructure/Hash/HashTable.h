//
//  HashTable.h
//  Hash
//
//  Created by Lrc mac on 2018/9/27.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef size_t(*HashFunc) (KeyType key, size_t capacity);

typedef enum
{
    EMPTY,
    EXIST,
    DELETE
}State;

typedef struct
{
    KeyType Key;
    State state;
}ItemType;

typedef struct HashTable
{
    ItemType *array;
    size_t size;
    size_t Capacity;
    HashFunc hash;
}HashTable;

size_t mod(KeyType key, size_t capacity);

void HashTableInit(HashTable *pHT, size_t capacity,HashFunc hash);
int HashTableSearch(HashTable *pHT, KeyType key);
void HashTableInsert(HashTable *pHT, KeyType key);
void HashTableDelete(HashTable *pHT, KeyType key);

#endif /* HashTable_h */
