//
//  InsertionSort.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 1. 2..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>

void InsertSort(int arr[], int n)
{
    int insertData;
    int j;
    for (int i = 1; i < n; i++) // 맨 앞은 정렬되있다고 가정하기에 1부터 시작
    {
        insertData = arr[i];
        
        for(j = i-1; j>=0; j--) //따로 넣어둔 데이터 앞에서 차례로 비교하기
        {
            if (arr[j] > insertData)
                arr[j+1] = arr[j]; //뒤로 한 칸 씩 밀기
            else
                break; //앞에건 이미 정렬되있으니까 탈출함
        }
        
        arr[j+1] = insertData; //멈춘 인덱스 = 넣을 데이터보다 작은 것이기에 j+1 임
        
        for(int k=0; k<n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
    int arr[5] = {5, 3, 2, 4, 1};
    
    InsertSort(arr, 5);
}
