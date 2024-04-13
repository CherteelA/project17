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
//tusk 1.........................................................................................
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
void test_removeNonLetters_fourth(){
    char words[] = "  ";
    removeNonLetters(words);
    ASSERT_STRING("", words);
}
//tusk 2.1......................................................................................
void test_removeAdjacentEqualLetters_first(){
    char words[] = "aaaaa";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a", words);
}
void test_removeAdjacentEqualLetters_second(){
    char words[] = "aaa bb b";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a b b", words);
}
void test_removeAdjacentEqualLetters_third(){
    char words[] = "  ";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING(" ", words);
}
void test_removeAdjacentEqualLetters_fourth(){
    char words[] = "";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("", words);
}
//2.2..............................................................................
void test_removeExtraSpaces_first(){
    char words[] = "aaaaa";
    removeExtraSpaces(words);
    ASSERT_STRING("aaaaa", words);
}
void test_removeExtraSpaces_second(){
    char words[] = "aaa  bb  b";
    removeExtraSpaces(words);
    ASSERT_STRING("aaa bb b", words);
}
void test_removeExtraSpaces_third(){
    char words[] = "  ";
    removeExtraSpaces(words);
    ASSERT_STRING(" ", words);
}
void test_removeExtraSpaces_fourth(){
    char words[] = "";
    removeExtraSpaces(words);
    ASSERT_STRING("", words);
}

void test_lab18(){
    test_removeNonLetters_first();
    test_removeNonLetters_second();
    test_removeNonLetters_third();
    test_removeNonLetters_fourth();
    test_removeAdjacentEqualLetters_first();
    test_removeAdjacentEqualLetters_second();
    test_removeAdjacentEqualLetters_third();
    test_removeAdjacentEqualLetters_fourth();
    test_removeExtraSpaces_first();
    test_removeExtraSpaces_second();
    test_removeExtraSpaces_third();
    test_removeExtraSpaces_fourth();

}