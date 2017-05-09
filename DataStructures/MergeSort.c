//
//  MergeSort.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 4..
//  Copyright © 2017년 JoYongJin. All rights reserved.
// 같은 이름의 함수가 두 개가 다른 스크립트에 있고 이를 참고하고 있으면 아무리 main함수가 있는 스크립트에 c파일을 인클루드하지 않아도 링커에서 오류난다.

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;
    
    int * sortArr = (int *)malloc(sizeof(int)*(right+1)); //정수 정렬을 위한 임시 공간, 메모리절약을 위해 right-left+1 개 만큼 만들면 안됨, 1. 최초배열의 인덱스에 맞춰야 정수를 넣는게 쉽기에 2. 메모리는 어차피 회수함 3. 만약 분리된 배열의 수만큼 공간을 할당할 경우 sIdx = 0, 마지막 임시배열의 요소를 원래 배열의 요소에 넣을 때, for(sIdx = 0;;sIdx++) 가 추가 되어야함
    int sIdx = left;
    
    while(fIdx <= mid && rIdx <= right) //이게 끝났다는 것은 어느 한쪽의 정렬이 끝났다. 를 의미. 그렇기에 다른 쪽의 이미 정렬된 요소들을 옮길 필요가 있음.
    {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];
        
        sIdx++;
    }
    
    if (fIdx > mid) // 밑에 for문이 실행될 땐, fIdx - mid = 1인 경우만 있음 위에 while에서 fIdx = mid일 때 실행되고 대입 과정 후의 fIdx++때문에
        for(i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    else
        for(i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    
    for (i = left; i <= right; i++) // 임시배열에 정렬된 요소들 차례로 옮기기.
        arr[i] = sortArr[i];
    
    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;
    
    if (left < right) //배열이 1개로만 나눠진 경우 정렬을 할 필요없어서.
    {
        mid = (left+right) / 2;
        
        MergeSort(arr, left, mid); //재귀적 용법 왼쪽에서 오른쪽으로, 적은 idx에서 큰 인덱스 순으로 정렬이 진행됨.
        MergeSort(arr, mid+1, right);
        
        MergeTwoArea(arr, left, mid, right);
    }
}

int main() {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    
    
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    
    for(int i = 0; i<7; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
