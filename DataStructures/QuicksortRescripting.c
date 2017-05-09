//
//  QuicksortRescripting.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 11..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>
void Swap(int arr[], int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int low = left+1;
    int high = right;
    
    int pivot = arr[left];
    
    while(low <= high)
    {
        while(arr[low] <= pivot && low <= right)
            low++;
        
        while(arr[high] > pivot && high >= left)
            high--;
        if(low<=high)
         Swap(arr, low, high);
    }
    
    Swap(arr, left, high);
    
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(){
    int arr[8] = {1,1,1,1,1,1,1,5};
    
    QuickSort(arr, 0, 7);
    
    for(int i=0;i<8; i++)
        printf("%d ", arr[i]);
}
