//
//  Tree.h
//  Tree
//
//  Created by Lrc mac on 2018/9/5.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>
typedef char TDataType;

typedef struct TreeNode
{
    TDataType data;
    struct TreeNode *Left;
    struct TreeNode *Right;
    
}TreeNode;

TreeNode *BuyTreeNode(TDataType d);
TreeNode *CreateTree(TDataType preOrder[], int size, int *pUsed);
void PrePrint(TreeNode *root);
int GetTreeHigh(TreeNode *root);
int GetLeafNodeNum(TreeNode *root);
int GetLevel_k_Num(TreeNode *root, int k);
TreeNode *FindNode(TreeNode *root, TDataType d);
void LevelPrint(TreeNode *root);
int IsCompleteTree(TreeNode *root);
void PrintLoop(TreeNode *root);
TreeNode *GetNearestAncestors(TreeNode* root, TDataType n1,
                              TDataType n2);
int IsBalance(TreeNode *root);
int IsBalanceGetHight(TreeNode *root, int *hight);
int GetLongFarset(TreeNode *root);
TreeNode *CreateTreePreInOrder(TDataType preT[],
                               TDataType inT[],int size);

#endif /* Tree_h */
