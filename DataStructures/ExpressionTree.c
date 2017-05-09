//
//  ExpressionTree.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 29..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pNode;
    
    int explen = (int)strlen(exp);
    
    StackInit(&stack);
    
    for(int i=0; i<explen; i++)
    {
        pNode = MakeBTreeNode();
        
        if(isdigit(exp[i]))
        {
            SetData(pNode, exp[i]-'0');
        }
        else
        {
            MakeRightSubTree(pNode, SPop(&stack));
            MakeLeftSubTree(pNode, SPop(&stack));
            SetData(pNode, exp[i]);
        }
        
        SPush(&stack, pNode);
    }
    
    return SPop(&stack); //맨위 인자 반환.
    

}
int EvaluateExpTree(BTreeNode * bt) {
   
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return bt->data;
    
    int op1 = EvaluateExpTree(GetLeftSubTree(bt));
    int op2 = EvaluateExpTree(GetRightSubTree(bt));
    
    
    
    switch (GetData(bt)) {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        default:
            break;
    }
    
    return 0;
}

void ShowNode(int data)
{
    if(data >= 0 && data<=9)
        printf("%d ", data);
    else
        printf("%c ", data);
        
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNode);
}

void ShowIntFixTypeExp(BTreeNode * bt)
{
    InorderTraverse(bt, ShowNode);
}
void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNode);
}
