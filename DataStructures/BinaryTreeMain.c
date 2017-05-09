//
//  BinaryTreeMain.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 27..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"
#include "ExpressionTree.h"

void inOrderTravel(BTreeNode * b)
{
    if(b == NULL)
        return;
    
    
    inOrderTravel(b->left);
    
    inOrderTravel(b->right);
    printf("%d \n", b->data);
    
}


int main()
{
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);
    
    printf("연산의 결과: %d \n", EvaluateExpTree(eTree));
    
    return 0;
    
}
