//
//  Tree.c
//  Tree
//
//  Created by Lrc mac on 2018/9/5.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include "Tree.h"
#include "QueueForLP.h"
#include "StackForPrint.h"

TreeNode *BuyTreeNode(TDataType d)
{
    TreeNode *New = (TreeNode*)malloc(sizeof(TreeNode));
    if (New!=NULL)
    {
        New->data = d;
        New->Left = NULL;
        New->Right = NULL;
        return New;
    }
    printf("New erro");
    exit(0);
}

TreeNode *CreateTree(TDataType preOrder[], int size, int *pUsed)
{
    if (size==0) {
        *pUsed = 0;
        return NULL;
    }
    if (preOrder[0]== '#') {
        *pUsed = 1;
        return NULL;
    }
    int leftUsed=0, rightUsed=0;
    TreeNode *root = BuyTreeNode(preOrder[0]);
    
    root->Left = CreateTree(preOrder+1, size-1, &leftUsed);
    root->Right=  CreateTree(preOrder+1+leftUsed, size-1-leftUsed, &rightUsed);
    *pUsed = 1 + leftUsed + rightUsed;
    
    
    return root;
}

#define MAX(a,b) ((a)>=(b) ? (a):(b))
int GetTreeHigh(TreeNode *root)
{
    if (root==NULL)
    {
        return 0;
    }
    int Left = GetTreeHigh(root->Left);
    int Right =GetTreeHigh(root->Right);
    return MAX(Left, Right)+1;
}

int GetLeafNodeNum(TreeNode *root)
{
    if (root==NULL)
    {
        return 0;
    }
    if (root->Left==NULL && root->Right==NULL)
    {
        return 1;
    }
    return GetLeafNodeNum(root->Left)+GetLeafNodeNum(root->Right);
}

int GetLevel_k_Num(TreeNode *root, int k)
{
    if (root==NULL)
    {
        return 0;
    }
    if (k==1)
    {
        return 1;
    }
    return GetLevel_k_Num(root->Left, k-1)+GetLevel_k_Num(root->Right, k-1);
}

void PrePrint(TreeNode *root)
{
    if (root==NULL)
    {
        printf("#");
        return ;
    }

    printf("%c",root->data);
    PrePrint(root->Left);
    PrePrint(root->Right);
}

TreeNode *FindNode(TreeNode *root, TDataType d)
{
    if (NULL == root)
    {
        return NULL;
    }
    if (root->data==d)
    {
        return root;
    }
    TreeNode *node = FindNode(root->Left, d);
    if (node != NULL)
    {
        return node;
    }
    node = FindNode(root->Right, d);
    if (node != NULL)
    {
        return node;
    }
    return NULL;
}

void LevelPrint(TreeNode *root)
{
    Queue q;
    QueueInit(&q);
    TreeNode *cur;
    printf("%c",root->data);
    QueuePush(&q, root);
    
    while (!IsEmptyQueue(&q))
    {
        cur = GetQfront(&q);
        QueuePop(&q);
        if (cur->Left !=NULL)
        {
            printf("%c",cur->Left->data);
            QueuePush(&q, cur->Left);
        }
        if (cur->Right != NULL)
        {
            printf("%c",cur->Right->data);
            QueuePush(&q,cur->Right);
        }
    }

}

int IsCompleteTree(TreeNode *root)
{
    Queue q;
    QueueInit(&q);
    TreeNode *cur;
    printf("%c",root->data);
    QueuePush(&q, root);
    
    while (!IsEmptyQueue(&q))
    {
        cur = GetQfront(&q);
        QueuePop(&q);
        if (cur->Left !=NULL)
        {
            printf("%c",cur->Left->data);
            QueuePush(&q, cur->Left);
        }
        else
            return 0;
        if (cur->Right != NULL)
        {
            printf("%c",cur->Right->data);
            QueuePush(&q,cur->Right);
        }
        else
            break;
    }
    while (!IsEmptyQueue(&q))
    {
        cur = GetQfront(&q);
        QueuePop(&q);
        if (cur->Left !=NULL || cur->Right != NULL)
        {
            return 0;
        }
    }
    return 1;
}

void PrintLoop(TreeNode *root)
{
    Stack s;
    StackInit(&s);
    TreeNode *cur;
    if (root==NULL) {
        return;
    }
    cur = root;
    while (cur!=NULL||!StackEmpty(&s))
    {
        while(cur!=NULL)
        {
            //printf("%c",cur->data);
            StackPush(&s, cur);
            cur = cur->Left;
        }
        cur = StackTop(&s);
        printf("%c",cur->data);
        cur = cur->Right;
        StackPop(&s);
    }
    
}

TreeNode *GetNearestAncestors(TreeNode* root, TDataType n1,
                              TDataType n2)
{
    TreeNode *n1inL = FindNode(root->Left, n1);
    TreeNode *n2inL = FindNode(root->Left, n2);
    
    if (n1inL!=NULL && n2inL==NULL){
        return root;
    }
    if (n1inL==NULL && n2inL!=NULL){
        return root;
    }
    if (n1inL!=NULL) {
       return  GetNearestAncestors(root->Left, n1, n2);
    }
    else{
       return  GetNearestAncestors(root->Right, n1, n2);
    }
}

int IsBalance(TreeNode *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int hLeft = GetTreeHigh(root->Left);
    int hRight = GetTreeHigh(root->Right);
    int diff = hLeft-hRight;
    if (!(diff<=1&&diff>=-1))
    {
        return 0;
    }
    int leftBala = IsBalance(root->Left);
    if (leftBala==1)
    {
        return 1;
    }
    int rightBala = IsBalance(root->Right);
    if (rightBala==1)
    {
        return 1;
    }
    return 0;
}

int IsBalanceGetHight(TreeNode *root, int *hight)
{
    if (root == NULL)
    {
        *hight = 0;
        return 1;
    }
    int leftHight, rightHight;
    IsBalanceGetHight(root->Left,&leftHight);
    IsBalanceGetHight(root->Right,&rightHight);
    int diff = leftHight-rightHight;
    
    *hight = MAX(leftHight, rightHight)+1;
    
    if (!(diff<=1&&diff>=-1))
    {
        return 0;
    }
    
    return 1;
}

int GetLongFarset(TreeNode *root)
{
    if (root==NULL)
    {
        return 0;
    }
    int leftH_A_rightH = GetTreeHigh(root->Left)+GetTreeHigh(root->Right)+1;
    int fastL = GetLongFarset(root->Left);
    int fastR = GetLongFarset(root->Right);
    int max = MAX(fastL, fastR);
    
    return MAX(leftH_A_rightH, max);
}

TreeNode *CreateTreePreInOrder(TDataType preT[],
                               TDataType inT[],int size)
{
    if (size==0) {
        return NULL;
    }
    TDataType rootValue = preT[0];
    TreeNode *root = BuyTreeNode(rootValue);
    int i;
    for (i = 0; i<size; i++)
    {
        if (inT[i]==rootValue)
        {break;}
    }
    root->Left = CreateTreePreInOrder(preT+1, inT, i);
    root->Right= CreateTreePreInOrder(preT+i+1, inT+i+1, size-i-1);
    
    return root;
}








