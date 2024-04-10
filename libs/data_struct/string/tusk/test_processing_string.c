//
// Created by admin on 10.04.2024.
//

#include "test_processing_string.h"
#include "../string_.h"
#include <stdio.h>
#include "../processing_string.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (!strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters_first(){
    char words[] = "hello, how are you";
    removeNonLetters(words);
    ASSERT_STRING("hello,howareyou", words);
}
void test_removeNonLetters_second(){
    char words[] = "hi 12 3     25548\n 15 jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}
void test_removeNonLetters_third(){
    char words[] = "hi1232554815jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}

void test_lab18(){
    test_removeNonLetters_first();
    test_removeNonLetters_second();
    test_removeNonLetters_third();
}