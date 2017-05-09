//
//  BubbleSort.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 2..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    //int n = sizeof(arr)/sizeof(typeof(int));
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j< (n-i)-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
            for(int k=0; k<n; k++)
                printf("%d ", arr[k]);
            printf("\n");
            
        }
    }
}

int main() {
    int arr[4] = {3, 2, 4, 1};
    
    BubbleSort(arr, 4);
    
    return 0;
}
