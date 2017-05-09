//
//  InterpolSearch.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 27..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>

int ISearch(int arr[], int first, int last, int target)
{
    int mid;
    
    if(arr[first] > target || arr[last] < target)
        return -1;
    
    mid = (last-first) * (target - arr[first]) / (double)(arr[last] - arr[first]) + first;
    
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return ISearch(arr, first, mid-1, target);
    else
        return ISearch(arr, mid+1, last, target);
}

int main() {
    int arr[11] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    
    int idx = ISearch(arr, 0, 10, 5);
    
    printf("%d \n", idx);
}
