//
// Created by admin on 10.04.2024.
//

#ifndef PROJECT17_PROCESSING_STRING_H
#define PROJECT17_PROCESSING_STRING_H
//убирает пробелы
void removeNonLetters(char *s);

//Преобразовать строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

//Сократить количество пробелов между словами данного предложения до
//одного (void removeExtraSpaces(char *s))
void removeExtraSpaces(char *s);
#endif //PROJECT17_PROCESSING_STRING_H
