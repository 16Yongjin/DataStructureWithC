//
//  QuickSort.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 7..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>

void Swap(int arr[], int one, int two)
{
    int temp = arr[one];
    arr[one] = arr[two];
    arr[two] = temp;
}

int Partition (int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left+1;
    int high = right;
    
    while(low <= high)
    {
        while(pivot >= arr[low] && low <= right) //low번째 값이 피벗보다 크면, 즉 우선순위가 작으면 멈춤 / 숫자가 같을 때도 인덱스가 올라가야 탈출할 수 있기에 >= 연산
            low++; // 3 2 1 인경우 3이 피벗, 1이 로우,하이에 다 걸린다. 그 상황을 위해 low <= right, 로우가 배열의 인덱스를 넘어갈까 걱정했지만, 넘어가면 교차가되서 인덱스바꾸기 연산이 수행되지 않기에 문제가 없다.
        
        while(pivot <= arr[high] && high >= (left+1)) //high번째 값이 피벗보다 작으면 즉, 우선순위가 크면 멈춤
            high--;
        
        if(low <= high) //둘이 교차되면 안바꿈
            Swap(arr, low, high);
    }
    
    Swap(arr, left, high); //바꿀게 없으면
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

int main() {
    int arr[7] = {4, 2, 1, 5, 7, 3, 9};
    
    QuickSort(arr, 0, 6);
    
    for(int i =0; i<7; i++)
        printf("%d ", arr[i]);
    
}
