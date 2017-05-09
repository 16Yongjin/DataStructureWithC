//
//  MergeSortRescripting.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 7..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void MergeSortTwo(int arr[], int first, int mid, int last)
{
    int * sortArr = (int*)malloc(sizeof(int)*(last+1));
    int leftIdx = first;
    int rightIdx = mid+1;
    int sIdx = first;
    int i;
    
    while(leftIdx <= mid && rightIdx <= last)
    {
        if(arr[leftIdx] <= arr[rightIdx])
            sortArr[sIdx] = arr[leftIdx++];
        else
            sortArr[sIdx] = arr[rightIdx++];
        
        sIdx++;
    }
    
    if (leftIdx <= mid)
        for(i=leftIdx; i<=mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    else
        for(i=rightIdx; i<=last; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    
    for(i = first; i<=last; i++)
        arr[i] = sortArr[i];
    
    free(sortArr);

}

void MergeSort(int arr[], int first, int last)
{
    int mid;
    
    if (first < last) //first 와 last가 같다 = 들어온 배열이 1개 이다.
    {
        mid = (first+last)/2;
        
        MergeSort(arr, first, mid);
        MergeSort(arr, mid+1, last);
        
        
        MergeSortTwo(arr, first, mid, last);
    }
}

int main() {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    
    
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    
    for(int i = 0; i<7; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

