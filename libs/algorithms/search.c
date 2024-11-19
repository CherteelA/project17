//
// Created by admin on 15.10.2024.
//
#include "search.h"
#include <stdio.h>
#include <string.h>


void* linear_search(void* arr, int size, int elem_size, void* target) {
    char* arr_ptr = (char*)arr;
    char* target_ptr = (char*)target;
    int count = 0;
    for (int i = 0; i < size; i++) {
        char* elem_ptr = arr_ptr + i * elem_size;
        count++;
        if (memcmp(elem_ptr, target_ptr, elem_size) == 0) {
            printf("%d", count);
            return elem_ptr;
        }
    }

    return NULL;
}


void* linear_search_Fast(void* arr, int size, int elem_size){
    char* arr_ptr = (char*)arr;
    char* target_ptr = (char*)(arr + (size-1)*elem_size);
    int i = 0;
    int count = 0;
    while (1){
        char* elem_ptr = arr_ptr + i * elem_size;
        count++;
        if (memcmp(elem_ptr, target_ptr, elem_size) == 0) {
            if(target_ptr == elem_ptr)
                break;
            printf("%d", count);
            return elem_ptr;
        }
        i++;
    }
    return NULL;
}


void* linear_search_Sorted(void* arr, int size, int elem_size, void* target){
    char* arr_ptr = (char*)arr;
    char* target_ptr = (char*)target;
    int count = 0;
    for (int i = 0; i < size; i++) {
        char* elem_ptr = arr_ptr + i * elem_size;
        int ans = memcmp(elem_ptr, target_ptr, elem_size);
        count++;
        if (ans == 0) {
            printf("%d", count);
            return elem_ptr;
        }
        if (*(int*)elem_ptr > *(int*)target_ptr) {
            break;
        }
    }
    return NULL;
}


void* binary_Search(void* arr, int size, int elem_size, void* target) {
    int x = 0;
    int y = size - 1;
    char* arr_ptr = (char*)arr;
    char* target_ptr = (char*)target;
    int count = 0;
    while (x <= y) {
        int i = x + (y - x) / 2;
        char* elem_ptr = arr_ptr + i * elem_size;
        int ans = memcmp(elem_ptr, target_ptr, elem_size);
        count++;
        if (ans == 0) {
            printf("%d", count);
            return elem_ptr;
        } else if (ans > 0) {
            y = i - 1;
        } else {
            x = i + 1;
        }
    }

    return NULL; // Элемент не найден
}

void* box_search(void* arr, int size, int elem_size, void *target){
    int x = 5;
    char* arr_ptr = (char*)arr;
    char* target_ptr = (char*)target;
    int count = 0;
    int *t = target;
    int tt =*t;
    while (x < size){
        char* elem_ptr = arr_ptr + x * elem_size;
        int ans = memcmp(elem_ptr, target_ptr, elem_size);
        count++;
        if(*(int*)elem_ptr < *(int*)target_ptr){
            if(x == size-1)
                return NULL;
            x+=5;
            if(x >= size)
                x = size-1;
        }
        else if(*(int*)elem_ptr > *(int*)target_ptr){
            for(int i = x - 5; i < x; i++){
                count++;
                if(x == size)
                    return NULL;
                elem_ptr = arr_ptr + i * elem_size;
                ans = memcmp(elem_ptr, target_ptr, elem_size);
                if(ans == 0){
                    printf("%d", count);
                    return elem_ptr;
                }
            }

            return NULL;
        }
        else{
            printf("%d", count);
            return elem_ptr;
        }
    }
    return NULL;
}