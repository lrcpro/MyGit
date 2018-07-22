//
//  SeqList.c
//  SeqList
//
//  Created by Lrc mac on 2018/6/19.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//
#include <stdio.h>
#include "SeqList.h"

void SeqListInit(SeqList* pSeq)
{
    for (int i = 0; i<MAX_SIZE; i++)
    {
        pSeq->_array[i] = 0;
        pSeq->_size = 0;
    }
}

void SeqListPushBack(SeqList* pSeq, DataType data)
{
    pSeq->_array[pSeq->_size] = data;
    pSeq->_size ++;
}

void SeqListPopBack(SeqList* pSeq)
{
    pSeq->_size --;
}

void SeqListPushFront(SeqList* pSeq, DataType data)
{
    if (pSeq->_size == MAX_SIZE)
    {
        printf("size==MAX_SIZE can't Push!\n");
        return;
    }
    for (int i = pSeq->_size; i>0; i--)
    {
        pSeq->_array[i] = pSeq->_array[i-1];
    }
    pSeq->_array[0] = data;
    pSeq->_size++;
}

void SeqListPopFront(SeqList* pSeq)
{
    for (int i = 0; i<pSeq->_size-1; i++)
    {
        pSeq->_array[i] = pSeq->_array[i+1];
    }
    pSeq->_size--;
}

void SeqListInsert(SeqList* pSeq, int pos, DataType data)
{
    if (pSeq->_size == MAX_SIZE)
    {
        printf("size==MAX_SIZE can't Push!\n");
        return;
    }
    for (int i = pSeq->_size; i>pos; i--)
    {
        pSeq->_array[i] = pSeq->_array[i-1];
    }
    pSeq->_array[pos] = data;
    pSeq->_size++;
}

void SeqListErase(SeqList* pSeq, int pos)
{
    if (pos>=0 && pos < pSeq->_size)
    {
        for (int i = pos; i<pSeq->_size-1; i++)
        {
            pSeq->_array[i] = pSeq->_array[i+1];
        }
        pSeq->_size--;
    }
}

int SeqListFind(SeqList* pSeq, DataType data)
{
    for (int i = 0; i<pSeq->_size; i++)
    {
        if (data == pSeq->_array[i])
        {
            return i;
        }
    }
    return -1;
}


void SeqListRemove(SeqList* pSeq, DataType data)
{
    //    for (int i = 0; i<pSeq->_size; i++)
    //    {
    //        if (data == pSeq->_array[i])
    //        {
    //            SeqListErase(pSeq, i);
    //        }
    //    }
    int pos = SeqListFind(pSeq, data);
    if (pos >=0) {
        SeqListErase(pSeq, pos);
    }
}

void SeqListRemoveAll(SeqList* pSeq, DataType data)
{
    for (int i = 0; i<pSeq->_size; i++)
    {
        if (pSeq->_array[i] == data)
        {
            SeqListErase(pSeq, i);
            i--;
        }
    }
}


//-----------------
void PrintList(SeqList* pSeq)
{
    for (int i = 0; i<pSeq->_size; i++)
    {
        printf("%d ",pSeq->_array[i]);
    }
    printf("\n");
}
void swap(DataType* p1,DataType* p2)
{
    DataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    
}

void BubbleSort(SeqList* pSeq)
{
    for (int i = 0; i<pSeq->_size; i++)
    {
        for (int j = 0; j<pSeq->_size-1-i; j++)
        {
            if (pSeq->_array[j]<pSeq->_array[j+1])
            {
                swap(pSeq->_array+j, pSeq->_array+j+1);
                
            }
        }
    }
}

void SelectSort(SeqList* pSeq)
{
    for (int i = 0; i<pSeq->_size-1; i++)
    {
        for (int j = i+1; j<pSeq->_size; j++)
        {
            if (pSeq->_array[i]<pSeq->_array[j])
            {
                swap(pSeq->_array+i, pSeq->_array+j);
            }
        }
    }
}

void BinarySearch(SeqList* pSeq, DataType data)
{
    int start = 0;
    int end = pSeq->_size-1;
    while (start<=end)
    {
        int mid = (start+end)/2;
        if (data == pSeq->_array[mid])
        {
            printf("the pos = %d\n",mid);
            return;
        }
        else if (data < pSeq->_array[mid])
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    printf("Can't find!\n");
}





