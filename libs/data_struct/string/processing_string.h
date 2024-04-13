//
// Created by admin on 10.04.2024.
//

#ifndef PROJECT17_PROCESSING_STRING_H
#define PROJECT17_PROCESSING_STRING_H
typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

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
#endif //PROJECT17_PROCESSING_STRING_H
