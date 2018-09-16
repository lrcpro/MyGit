//
//  main.c
//  Tree
//
//  Created by Lrc mac on 2018/9/5.
//  Copyright © 2018年 Lrc mac. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

int main()
{
    char preOrder[] = "ABD###CE##FGH###";
    //char preOrder[] = "ABD##E##CF###";
    int use = 0;
    TreeNode *root = CreateTree(preOrder, sizeof(preOrder)/sizeof(preOrder[0])-1, &use);
    //TreeNode* ance = GetNearestAncestors(root, 'D', 'E');
    int THight = 0;
    int balan = IsBalanceGetHight(root,&THight);
    return 0;
}
