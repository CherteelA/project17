//
// Created by admin on 10.04.2024.
//
#include "string_.h"
#include "processing_string.h"

//убирает пробелы
char *getEndOfString(char *s){
    while(*s != '\0'){
        s++;
    }
    return s;
}
bool isspase_(char s){
    return 0 == isspace(s);
}
void removeNonLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isspase_);
    *destination = '\0';
}