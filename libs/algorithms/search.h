//
// Created by admin on 15.10.2024.
//

#ifndef PROJECT17_SEARCH_H
#define PROJECT17_SEARCH_H

void* linear_search(void* arr, int size, int elem_size, void* target);
void* linear_search_Fast(void* arr, int size, int elem_size);
void* linear_search_Sorted(void* arr, int size, int elem_size, void* target);
void* binary_Search(void* arr, int size, int elem_size, void* target);
void* box_search(void* arr, int size, int elem_size, void *target);
#endif //PROJECT17_SEARCH_H
