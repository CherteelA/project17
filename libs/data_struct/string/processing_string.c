//
// Created by admin on 10.04.2024.
//
#include "string_.h"
#include "processing_string.h"
#include <stdio.h>
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

//убирает пробелы
char *getEndOfString(char *s){
    while(*s != '\0'){
        s++;
    }
    return s;
}

bool isspase_(char *s){
    return 0 == isspace(*s);
}

void removeNonLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isspase_);
    *destination = '\0';
}

//Преобразовать строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
bool AdjacentLetesIsNotEquale(char *s){
    return *s != *(s-1);
}

void removeAdjacentEqualLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s+1, endSource, s+1, AdjacentLetesIsNotEquale);
    *destination = '\0';
}

//Сократить количество пробелов между словами данного предложения до
//одного (void removeExtraSpaces(char *s))
bool AdjacentSpaseIsNotEquale(char *s){
    if(isspace(*s))
        return ' ' != *(s-1);
    return true;
}
void removeExtraSpaces(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s+1, endSource, s+1, AdjacentSpaseIsNotEquale);
    *destination = '\0';
}

// выражаем слово из строки
int getWord(char *beginSearch, WordDescriptor *word){
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

// выражаем слово из строки начиная с конца
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word){
    word->end = findNonSpaceReverse(rend, rbegin);
    if (*word->end == '\0')
        return false;
    word->begin = findSpaceReverse(word->end, rbegin)+1;
    return true;
}


bool isNumb(char *s){
    return *s > 47 && *s <58;
}
bool isNotNumb(char *s){
    return !(*s > 47 && *s < 58);
}
void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end+1,_stringBuffer) - 1;
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isNumb);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isNotNumb);
}

//цифры записывает в начало слова в обратном порядке,
//а буквы в конец слова без изменения порядка
void changeWords_numb(char *s){
    char *beginSearch = s;
    WordDescriptor word;
    while(getWord(beginSearch, &word)){
        digitToStart(word);
        beginSearch += (word.end + 1 - beginSearch);
    }
}
//противоположная для digitToStart, задача первая из 3 номера
void LettersToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer) - 1;
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isNotNumb);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isNumb);
}

//буквы записывает в начало слова в обратном порядке,
//а цифры в конец слова без изменения порядка
void changeWords_Letters(char *s){
    char *beginSearch = s;
    WordDescriptor word;
    while(getWord(beginSearch, &word)){
        LettersToStart(word);
        beginSearch += (word.end + 1 - beginSearch);
    }
}

//4.................................................................................................................
//количество цифр = количиству пробелов
void doSpace(char *s){
    char *end__stringBuffer = copy(s, s+ strlen_(s),_stringBuffer) - 1;
    *end__stringBuffer = '\0';
    char *begin = s;
    char *ptr = _stringBuffer;
    while(*ptr!='\0'){
        if(*ptr > 47 && *ptr < 58){
            int space = 0;
            while(space < (int)*ptr-48){
                *begin = ' ';
                begin++;
                space++;
            }
        } else{
            *begin = *ptr;
            begin++;
        }
        ptr++;
    }
}

