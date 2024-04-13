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
    char words[] = "aaa bb bb";
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
//3.......................................................................................................................
void test_digitToStart_first(){
    char s[] = "hello81 F822";
    changeWords_numb(s);
    ASSERT_STRING("18hello 228F", s);
}
void test_digitToStart_second(){
    char s[] = "hello81 zxc123456789 856947";
    changeWords_numb(s);
    ASSERT_STRING("18hello 987654321zxc 749658", s);
}
void test_digitToStart_third(){
    char s[] = "";
    changeWords_numb(s);
    ASSERT_STRING("", s);
}
void test_getWordReverse(){
    WordDescriptor word;
    char s[] = "123 222 8585";
    getWordReverse(s,s + strlen_(s)-1, &word);
    ASSERT_STRING("8585", word.begin);
}
//решение задачи №1
void test_LettersToStart_first(){
    char s[] = "hello81 tF822";
    changeWords_Letters(s);
    ASSERT_STRING("olleh81 Ft822", s);
}
void test_LettersToStart_second(){
    char s[] = "18hello 987654321zxc 749658";
    changeWords_Letters(s);
    ASSERT_STRING("olleh18 cxz987654321 749658", s);
}

//4.....................................................................................................................
void test_doSpace_first(){
    char s[100] = "he3l1lo5";
    doSpace(s);
    ASSERT_STRING("he   l lo     ", s);
}
void test_doSpace_second(){
    char s[100] = "123";
    doSpace(s);
    ASSERT_STRING("      ", s);
}
void test_doSpace_third(){
    char s[100] = "";
    doSpace(s);
    ASSERT_STRING("", s);
}

//5.....................................................................................................................
void test_replace_first(){
    char s[] = "hhhhh hhhhhf hhh";
    char s1[] = "hhhhh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhhhhf hhh", s);
}
void test_replace_second(){
    char s[] = "hhhhh hhhhh hhhhh hhhhh";
    char s1[] = "hhhhh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hhh hhh", s);
}
void test_replace_third(){
    char s[] = "adfg adfg adfg adfg ,adfg";
    char s1[] = "adfg";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hhh hhh ,adfg", s);
}
void test_replace_fourth(){
    char s[] = ",adfg ,adfg ,adfg ,adfg ,adfg";
    char s1[] = "adfg";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING(",adfg ,adfg ,adfg ,adfg ,adfg", s);
}
void test_replace_fifth(){
    char s[] = "hh hh hha";
    char s1[] = "hh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hha", s);
}
void test_replace_sixth(){
    char s[] = "hh hh h";
    char s1[] = "hh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh h", s);
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
    test_digitToStart_first();
    test_digitToStart_second();
    test_digitToStart_third();
    test_LettersToStart_first();
    test_LettersToStart_second();
    test_getWordReverse();
    test_doSpace_first();
    test_doSpace_second();
    test_doSpace_third();
    test_replace_first();
    test_replace_second();
    test_replace_third();
    test_replace_fourth();
    test_replace_fifth();
    test_replace_sixth();
}