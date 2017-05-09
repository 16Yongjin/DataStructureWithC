//
//  AVLRebalance.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 3. 28..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//
#include <stdio.h>
#include "AVLRebalance.h"
#include "BinaryTree3.h"

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode = bst;
    BTreeNode * cNode = GetLeftSubTree(bst);
    
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    
    return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode = bst;
    BTreeNode * cNode = GetRightSubTree(bst);
    
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    
    return cNode;
}

BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode = bst;
    BTreeNode * cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode = bst;
    BTreeNode * cNode = GetLeftSubTree(bst);
    
    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

int GetHeight(BTreeNode * bst)
{
    int leftH=0;
    int rightH=0;
    
    if(bst == NULL)
        return 0;
    
    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));
    
    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
    if(bst == NULL)
        return 0;
    
    int lsh = GetHeight(GetLeftSubTree(bst));
    int rsh = GetHeight(GetRightSubTree(bst));
    
    return lsh - rsh;
    
}
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);
    
    if (hDiff > 1)
    {
        if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    else
    {
        if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    
    return *pRoot;
}



