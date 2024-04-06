//
// Created by admin on 01.04.2024.
//
#include <ctype.h>
#include <stdlib.h>
#ifndef LABA_STRING_H
#define LABA_STRING_H

//подсчёт длины строки
size_t strlen_(char *begin);

//возвращает указатель
//на первый элемент с кодом ch,
char* find(char *begin, char *end, int ch);

//возвращает указатель на первый
//символ, отличный от пробельных
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных
char* findNonSpaceReverse(char *rbegin, const char *rend);
#endif //LABA_STRING_H
