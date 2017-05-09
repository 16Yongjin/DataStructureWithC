//
//  SelectionSort.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 2..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>

void SelSort(int arr[], int n)
{
    int maxidx;
    int temp;
    
    for (int i = 0; i < n-1; i++) {
        maxidx = i;
        
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[maxidx])
                maxidx = j; //작은 놈이 맥스가 됨(?)
        }
        
        temp = arr[i];
        arr[i] = arr[maxidx];
        arr[maxidx] = temp;
        
        for(int k=0;k<n;k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
} // 제일 작은 요소를 찾아서 순차대로 앞 인덱스 바꾸면서 채우기

int main() {
    int arr[] = {3, 4, 1, 2};
    
    SelSort(arr, 4);
}
