//
// Created by admin on 01.04.2024.
//
#include "string.h"
#include <stdio.h>

//подсчёт длины строки
size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}

//возвращает указатель
//на первый элемент с кодом ch,
char* find(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

//возвращает указатель на первый
//символ, отличный от пробельных
char* findNonSpace(char *begin){
    return NULL;
}
