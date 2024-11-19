//
// Created by admin on 15.10.2024.
//
//СОРТИРОВКА ВКЛЮЧЕНИЕМ


#include <stdlib.h>
#include <math.h>
#include "sort.h"


void Insertion_Sort(int *array, int n, int *count) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int k = i - 1;
        if(!(k >= 0 && array[k] > key))
            (*count)++;
        while (k >= 0 && array[k] > key) {
            (*count)++;
            array[k + 1] = array[k];
            k--;
        }
        array[k + 1] = key;
    }
}

//СОРТИРОВКА ВЫБОРОМ
void Selection_Sort(int *array, int n, int *count){
    for(int i = 0; i < n; i++){
        int min = INT_MAX;
        int indx;
        for(int j = i; j < n; j++){
            (*count)++;
            if(min > array[j]){
                min = array[j];
                indx = j;
            }
        }
        array[indx] = array[i];
        array[i] = min;
    }
}

//СОРТИРОВКА ОБМЕНОМ
void Exchange_Sort(int *array, int n, int *count){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > 0; j--){
            (*count)++;
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

//СОРТИРОВКА ОБМЕНОМ 1
void Exchange_Sort1(int *array, int n, int *count){
    for(int i = 0; i < n; i++){
        int is_sort = 1;
        for(int j = n - 1; j > 0; j--){
            (*count)++;
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                is_sort = 0;
            }
        }
        if(is_sort){
            break;
        }
    }
}



//СОРТИРОВКА ОБМЕНОМ 2
void Exchange_Sort2(int *array, int n, int *count){
    for(int i = 0; i < n; i++){
        int is_sort = 1;
        for(int j = n - 1; j > i; j--){
            (*count)++;
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                is_sort = 0;
            }
        }
        if(is_sort){
            break;
        }
    }
}


//Сортировка Шелла
void Shell_Sort(int arr[], int n, int *count) {
    int gap, i, j, temp;
    int ii = 1;
    int D[n];
    while (1) {
        gap = ((int)round(pow(3,ii)) - 1)/2;
        if(gap >= (int)round((double )n/3)){
            break;
        }
        D[ii-1] = gap;
        ii++;
    }
    ii--;
    gap = D[ii-1];
    while (1) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;
            if(!(j >= gap && arr[j - gap] > temp))
                (*count)++;
            while (j >= gap && arr[j - gap] > temp) {
                (*count)++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        if(ii == 0){
            break;
        }
        gap = D[--ii];

    }
}


//сортировка Хоара
int partition(int arr[], int low, int high, int *count) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        if(!(i <= j && arr[j] > pivot) && !(i <= j && arr[i] <= pivot))
            (*count)++;
        while (i <= j && arr[i] <= pivot) {
            (*count)++;
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            (*count)++;
            j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quick_sort(int arr[], int low, int high, int *count) {
    int pivot;
    if (low < high) {
        pivot = partition(arr, low, high, count);
        quick_sort(arr, low, pivot-1, count);
        quick_sort(arr, pivot+1, high, count);
    }
}


// пирамидальная функция сортировки
void Sift(int A[],int Left,int Right, int *count)
{
    int i,j,x,temp;
    i = Left;
    j = 2*Left+1;
    x = A[Left];
    if ((j<Right) && (A[j]<A[j+1]))
        j++;
    while ((j<=Right) && (x<A[j]))
    {
        (*count)++;
        temp=A[i];
        A[i] = A[j];
        A[j]=temp;
        i = j;
        j = 2*j+1;
        if ((j<Right) && (A[j]<A[j+1]))
            j++;

    }



}

void Heap_Sort(int A[],int N, int *count)
{
    int Left,Right,x;
    Left = N/2 ;
    Right = N-1;
    while ( Left>0 )
    {
        (*count)++;
        Left = Left - 1;
        Sift(A,Left,Right,count);
    }
    while ( Right>0 )
    {
        (*count)++;
        x = A[0];
        A[0] = A[Right];
        A[Right] = x;
        Right--;
        Sift(A,Left,Right,count);
    }
}