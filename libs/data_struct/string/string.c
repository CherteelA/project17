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

