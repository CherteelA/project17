//
// Created by admin on 10.04.2024.
//
#include "string_.h"

#ifndef PROJECT17_PROCESSING_STRING_H
#define PROJECT17_PROCESSING_STRING_H
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;



//получает конец
char *getEndOfString(char *s);

//убирает пробелы
void removeNonLetters(char *s);

//Преобразовать строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

//Сократить количество пробелов между словами данного предложения до
//одного (void removeExtraSpaces(char *s))
void removeExtraSpaces(char *s);

// выражаем слово из строки
int getWord(char *beginSearch, WordDescriptor *word);

// выражаем слово из строки начиная с конца
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//цифры записывает в начало слова в обратном порядке,
//а буквы в конец слова без изменения порядка
void changeWords_numb(char *s);

//буквы записывает в начало слова в обратном порядке,
//а цифры в конец слова без изменения порядка
void changeWords_Letters(char *s);

//количество цифр = количиству пробелов
void doSpace(char *s);

//заменя всех слов w1 на w2
void replace(char *source, char *w1, char *w2);

//сравнение слов, словов w1 стоит выше чем w2 по алфавиту 0,
//словов w2 стоит выше чем w1 по алфавиту 1, если слова совпали то 2
int areWordsEqual_comparison(WordDescriptor w1, WordDescriptor w2);

//Определить, упорядочены ли лексикографически слова данного предложения.
bool OrderedWords(char *s);

//получаем алреса начала и конца всех слов
void getBagOfWords(BagOfWords *bag, char *s);

//выводит строку с конца
void print_string_revers(char *s);

//возвращает количиство слов
int count_words(char *s);
#endif //PROJECT17_PROCESSING_STRING_H
