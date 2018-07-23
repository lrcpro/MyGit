//
//  LinkList.h
//  LinkList
//
//  Created by Lrc mac on 2018/6/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node* next;
}Node,*pNode, List, *pList;

void InitLinkList(pList* pplist);
//void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PrintLinkList(pList plist);
void PrintTailtoHead(pList plist);
pNode FindNode(pList plist, DataType d);
void InsertFront(pNode node, DataType d);
void InversionList(pList* plist);
void JudgeCircle(pList plist);
pNode GetEndNode(pList plist);
void JudgeCircle(pList plist);
void JudgeIntersect(pList plist, pList plist2);

#endif /* LinkList_h */
