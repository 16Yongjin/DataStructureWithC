//
//  BinarySearchTree.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 27..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include "BinarySearchTree.h"
#include <stdlib.h>
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL;
    BTreeNode * cNode = *pRoot;
    BTreeNode * nNode = NULL;
    
    while(cNode != NULL) //넣을 자리 찾기
    {
        if (GetData(cNode) == data)
            return;
        
        pNode = cNode; //무언가가 들어있다 = 넣을 공간 없다, 자식 노드에 넣어야 한다. 그래서 이 노드를 부모노드로 만들어야 한다.
        
        if(GetData(cNode) > data) // 넣을 키 값이 작다.
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode); //트리에 넣기 위해서는 부모 노드가 필요하므로 cNode는 빈 자리 찾기에만 쓰이고 버려진다ㅠ
    }
    
    nNode = MakeBTreeNode();
    SetData(nNode, data); // 노드 만들기
    
    if (pNode != NULL) // 부모 노드에 뭔가 들어 있다 = 루트 노드가 아니다.
    {
        if (data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        * pRoot = nNode; //루트노드이다 = 선택지가 하나 밖에 없음, 그냥 넣기
    }
    
    Rebalance(pRoot);
}

BTreeNode * BSTInsert2(BTreeNode ** pRoot, BTData data)
{
    if (*pRoot == NULL)
    {
        *pRoot = MakeBTreeNode();
        SetData(*pRoot, data);
    }
    else if (data < GetData(*pRoot))
    {
        BSTInsert2(&((*pRoot)->left), data);
        Rebalance(pRoot);
    }
    else if (data > GetData(*pRoot))
    {
        BSTInsert2(&((*pRoot)->right), data);
        Rebalance(pRoot);
    }
    else
    {
        return NULL;
    }
    
    return *pRoot;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst; // 현재 노드
    BSTData cData; // 현재 노드에 들어가 있는 값
    
    while(cNode != NULL)
    {
        cData = GetData(cNode);
        
        if (target == cData)
            return cNode;
        else if (target < cData)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
    BTreeNode * pVRoot = MakeBTreeNode(); //가상 노드
    BTreeNode * pNode = pVRoot; // 가상 노드의 첫번째 값을 받음 = 메모리 맨 앞에 있는 부모 노드// 지울 노드가 루트 노드인 경우도 있으므로 자식노드로 만들고 지워야함?
    BTreeNode * cNode = *pRoot; //현재 노드 위치 값이 저장될 포인터. 현재는 pRoot 의 주소값을 띄고있는 상태
    BTreeNode * dNode; //지울 노드의 주소값이 저장될 노드
    
    ChangeRightSubTree(pVRoot, *pRoot); //삭제 노드와 삭제 노드의 부모 노드 간의 관계를  루트노드에도 적용시켜 if else 문을 이용하기 위함
    
    while(cNode != NULL && GetData(cNode) != target) //cNode에 뭐 들어있고, 찾는 데이터도 다들 때.
    {                                                //cNode에 뭐 안들어있으면 찾을 데이터도 없다는 뜻, cNode의 데이터가 타겟과 같다면 데이터 찾았다는 것.
        //뭐 들어있고, 찾는 데이터도 없다. 그러면 내려가야지
        pNode = cNode;
        if (GetData(cNode) > target) //이 안에 ==인 경우는 없기에, >=로 굳이 안써줘도 됨
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    } // 탐색 위치 찾기 완료. 찾았거나 못 찾았거나임
    
    if (cNode == NULL) // 못찾았으면 그만 두기
        return NULL;
    
    dNode = cNode;
    //4가지 케이스가 있다. 지울노드가 1. 자식 노드 없는 경우 2. 하나만 3. 둘 다
    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if (GetLeftSubTree(pNode) == cNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    } // 그냥 루트 트리에 들어있는 지울 노드만 NULL값으로 대체해준다. 그리고 지울 노드의 주소는 잘 보관되어있으니까 저 밑에서 반환하고, 반환값은 함수밖에서 처리할 예정
    
    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) // 둘다 빈 경우는 위에서 처리되었으니 둘 중 하나만 비어있을 경우
    {
        BTreeNode * dcNode; // 지울 노드의 자식노드의 위치를 알아야함
        if(GetLeftSubTree(dNode) != NULL) // 지울 노드 중심의 위치
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);
        
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode); //삭제될 노드 오른쪽에서 제일 작은 값을 가진 '대체 노드'를 저장하기 위한 변수
        BTreeNode * mpNode = dNode; //대체 노드의 부모 노드가 필요한 이유, 대체 노드가 왼쪽에 붙어있는지 오른쪽에 붙어있는지 확인하려고
        int delData;
        
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        //찾았으면
        delData = GetData(dNode); //포인팅 대상을 바꾸는게 아니라 그냥 안에 있는 값을 바꿔서 대체할 것이기에 값을 백업 해놓음
        SetData(dNode, delData);
        
        if (GetRightSubTree(mpNode) == mNode)
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));//대체 노드는 제일 왼쪽에 있는 것이기에 오른쪽 자식이 널이든 뭐든 상관없이 그 값을 대.부.노드에 연결해주면 된다.
        else
            ChangeLeftSubTree(mpNode, mNode);
        
        dNode = mNode;
        SetData(dNode, delData); // SetData(mNode, delData);dNode = mNode; 해도 되는데 뭐가 더 성능에 좋은지 생각해보기.
        //삭제 노드가 아니라, 대체 노드가 삭제 노드의 데이터를 가지고 메모리에서 소멸될 예정임. 뭔가 관료주의적 회사 생활같다.
    }
    
    if (GetRightSubTree(pVRoot) != *pRoot) //루트노드가 다른 노드로 대체되는 경우도 있으므로, 루트노드가 이진 탐색 트리의 루트 노드를 가르키도록 체크함
        *pRoot = GetRightSubTree(pVRoot);
    
    free(pVRoot);
    Rebalance(pRoot);
    return dNode;
}

void ShowInData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowInData);
}
