//
//  SeqList.h
//  SeqList
//
//  Created by Lrc mac on 2018/6/19.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

typedef int DataType;

#define MAX_SIZE 10

typedef struct SeqList
{
    DataType _array[MAX_SIZE];
    int _size;
}SeqList;

void SeqListInit(SeqList* pSeq);
void SeqListPushBack(SeqList* pSeq, DataType data);
void SeqListPopBack(SeqList* pSeq);
void SeqListPushFront(SeqList* pSeq, DataType data);
void SeqListPopFront(SeqList* pSeq);
void SeqListInsert(SeqList* pSeq, int pos, DataType data);
void SeqListErase(SeqList* pSeq, int pos);
void SeqListRemove(SeqList* pSeq, DataType data);
void SeqListRemoveAll(SeqList* pSeq, DataType data);
int SeqListFind(SeqList* pSeq, DataType data);
void SeqListSize(SeqList* pSeq);
//------------
void PrintList(SeqList* pSeq);
void BubbleSort(SeqList* pSeq);
void SelectSort(SeqList* pSeq);
void SelectSort_OP(SeqList* pSeq);
void BinarySearch(SeqList* pSeq, DataType data);

#endif /* SeqList_h */
