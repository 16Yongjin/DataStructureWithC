#include <stdio.h>
#include "BinaryTree3.h"	// ∆Æ∏Æ¿« ±∏¡∂∏¶ »Æ¿Œ«œ±‚ ¿ß«ÿº≠
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node
	BSTMakeAndInit(&avlRoot);

	BSTInsert2(&avlRoot, 1);
	BSTInsert2(&avlRoot, 2);
	BSTInsert2(&avlRoot, 3);
	BSTInsert2(&avlRoot, 4);
	BSTInsert2(&avlRoot, 5);
	BSTInsert2(&avlRoot, 6);
	BSTInsert2(&avlRoot, 7);
	BSTInsert2(&avlRoot, 8);
	BSTInsert2(&avlRoot, 9);

	printf("루트노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽 1: %d, 오른쪽 1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽 2: %d, 오른쪽 2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽 3: %d, 오른쪽 3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽 4: %d, 오른쪽 4: %d \n", GetData(clNode), GetData(crNode));
	return 0;
}
