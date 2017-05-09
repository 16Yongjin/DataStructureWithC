//
//  ExpressionTree.h
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 29..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#ifndef ExpressionTree_h
#define ExpressionTree_h
#include "BinaryTree.h"
#include <stdio.h>

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowIntFixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif /* ExpressionTree_h */
