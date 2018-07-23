//
//  LinkList.c
//  LinkList
//
//  Created by Lrc mac on 2018/6/23.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//
#include <stdio.h>
#include <assert.h>
#include "LinkList.h"

void InitLinkList(pList* pplist)
{
    *pplist = NULL;
}

pNode BuyNode()
{
    pNode p = malloc(sizeof(Node));
    if (p!=NULL)
    {
        p->next = NULL;
    }
    return p;
}
void PushBack(pList* pplist, DataType d)
{
    if (*pplist == NULL)
    {
        *pplist = BuyNode();
        (*pplist)->data = d;
        
    }
    else
    {
        pNode pre = *pplist;
        while (pre->next != NULL)
        {
            pre = pre->next;
        }
        pre->next = BuyNode();
        pre->next->data = d;
    }
}

void PrintLinkList(pList plist)
{
    if (plist == NULL)
    {
        printf("no list");
    }
    else
    {
        pNode pre = plist;
        while (pre)
        {
            printf("%d\t",pre->data);
            pre = pre->next;
        }
        
    }
}


//-------------------------------------------


void PrintTailtoHead(pList plist)
{
    if (plist == NULL)
        return;
    else{
        PrintTailtoHead(plist->next);
        printf("%d\t",plist->data);
    }
}

pNode FindNode(pList plist, DataType d)
{
    if (plist==NULL) {
        printf("空链表\n");
    }
    pNode pre = plist;
    while (pre!=NULL)
    {
        if (pre->data == d)
            return pre;
        pre = pre->next;
    }
    
    return NULL;
}

void InsertFront(pNode node, DataType d)
{
    assert(node != NULL);
    DataType tmpD = node->data;
    pNode tmp = node->next;
    node->next = BuyNode();
    node->data = d;
    node->next->data = tmpD;
    node->next->next = tmp;
    
}

void InversionList(pList* plist)
{
    if (*plist==NULL)
        printf("空链表\n");
        
    if ((*plist)->next == NULL)
        return;
    
    pNode pre = (*plist)->next;
    pNode cul = pre;
    (*plist)->next = NULL;
    while (pre!=NULL)
    {
        cul = cul->next;
        pre->next = *plist;
        *plist = pre;
        pre = cul;
        
    }
}

pNode GetEndNode(pList plist)
{
    pNode pre = plist;
    while (pre->next!=NULL)
    {
        pre=pre->next;
    }
    return pre;
}

void JudgeCircle(pList plist)
{
    pNode slow = plist;
    pNode fast = plist->next;
    int count = 1;
    while (fast!=slow)
    {
        if (fast==NULL||slow==NULL)
        {
            printf("no circle!\n");
            return;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    
    printf("hava circle, at data = %d\n",fast->data);

    slow=slow->next;
    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }
    
    printf("long = %d\n",count);
    
    fast = plist;
    slow = slow->next;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    printf("入口点位置的数据是%d\n", fast->data);
}

void JudgeIntersect(pList plist1, pList plist2)
{
    pNode p1 = plist1;
    int count_1 = 1;
    pNode p2 = plist2;
    int count_2 = 1;
    
    while (p1->next!=NULL){
        p1 = p1->next;
        count_1++;}
    while (p2->next!=NULL){
        p2 = p2->next;
        count_2++;}
    if (p2 == p1)
    {
        printf("intersect\n");
    }
    int step = count_1-count_2;
    if (step>0)
    {
        p1 = plist1;
        p2 = plist2;
        while (step) {
            p1 = p1->next;
            step--;
        }
    }
    else
    {
        p1 = plist1;
        p2 = plist2;
        while (step<0) {
            p2 = p2->next;
            step++;
        }
    }
    while (p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    printf("intersection at data = %d\n",p1->data);
}


