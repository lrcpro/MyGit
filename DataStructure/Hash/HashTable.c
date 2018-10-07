//
//  HashTable.c
//  Hash
//
//  Created by Lrc mac on 2018/9/27.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "HashTable.h"
#include <assert.h>
size_t mod(KeyType key, size_t capacity)
{
    return key%capacity;
}

void HashTableInit(HashTable *pHT, size_t capacity,HashFunc hash)
{
    pHT->array = (ItemType*)malloc(sizeof(ItemType)*capacity);
    pHT->size = 0;
    pHT->Capacity = capacity;
    pHT->hash = hash;
    for (int i = 0; i<pHT->Capacity; i++)
    {
        pHT->array[i].Key = 0;
        pHT->array[i].state = EMPTY;
    }
}

int HashTableSearch(HashTable *pHT, KeyType key)
{
    assert(pHT);
    size_t index = pHT->hash(key, pHT->Capacity);
    while (pHT->array[index].state !=EMPTY)
    {
        if (pHT->array[index].state ==EXIST &&
            pHT->array[index].Key == key)
        {
            return (int)index;
        }
        index = (index+1)%pHT->Capacity;
    }
    return -1;
}

int ExpandIfRequired(HashTable *pHT)
{
    if ((pHT->size*10/pHT->Capacity)<8)
    {
        return 0;
    }
    
    HashTable tmp;
    HashTableInit(&tmp, pHT->Capacity*2, pHT->hash);
    for (int i = 0; i<pHT->Capacity; i++)
    {
        if (pHT->array[i].state==EXIST)
        {
            HashTableInsert(&tmp, pHT->array[i].Key);
        }
    }
    free(pHT->array);
    pHT->array = tmp.array;
    
    return 1;
}

void HashTableInsert(HashTable *pHT, KeyType key)
{
    assert(pHT);
    if (HashTableSearch(pHT, key)>0)
    {
        return;
    }
    size_t index = pHT->hash(key,pHT->Capacity);
    while (pHT->array[index].state == EXIST)
    {
        index = (index+1)%pHT->Capacity;
    }
    pHT->array[index].Key=key;
    pHT->array[index].state = EXIST;
    pHT->size++;
    
}

void HashTableDelete(HashTable *pHT, KeyType key)
{
    assert(pHT);
    size_t index = pHT->hash(key, pHT->Capacity);
    while (pHT->array[index].state !=EMPTY)
    {
        if (pHT->array[index].state==EXIST &&
            pHT->array[index].Key == key)
        {
            pHT->array[index].state =DELETE;
            pHT->size--;
            return;
        }
    }
}
