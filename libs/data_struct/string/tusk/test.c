//
// Created by admin on 04.04.2024.
//
#include "../string_.h"
#include <assert.h>
#include "test.h"
#include <stdio.h>

void test_strlen_(){
    char *word = "hello";
    char str[10] = "prog";
    assert(strlen_(word) == 5);
    assert(strlen_(str) == 4);
}

void test_find(){
    char *word_1 = "hello";
    assert(word_1+2 == find(word_1,word_1+4, 108));
    char *word_2 = "programmer";
    assert(word_2+6 == find(word_2,word_2+9, 109));
    char *word_3 = "university";
    assert(word_3+9 == find(word_3,word_3+9, 97));
}
void test_findNonSpace(){
    char *word_1 = " hello";
    assert(word_1+1 == findNonSpace(word_1));
    char *word_2 = "progr ammer";
    assert(word_2 == findNonSpace(word_2));
    char *word_3 = "\nuniversity";
    assert(word_3+1 == findNonSpace(word_3));
}

void test_findSpace(){
    char *word_1 = " hello";
    assert(word_1 == findSpace(word_1));
    char *word_2 = "progr\nammer";
    assert(word_2+5 == findSpace(word_2));
    char *word_3 = "university";
    assert(word_3+10 == findSpace(word_3));
}

void test_findNonSpaceReverse(){
    char *word_1 = " hello";
    assert(word_1+5 == findNonSpaceReverse(word_1+5,word_1));
    char *word_2 = "progr\namm\ter\t";
    assert(word_2+11 == findNonSpaceReverse(word_2+12, word_2));
    char *word_3 = "university";
    assert(word_3+9 == findNonSpaceReverse(word_3+9, word_3));
}

void test_findSpaceReverse(){
    char *word_1 = " hello";
    assert(word_1 == findSpaceReverse(word_1+5,word_1));
    char *word_2 = "progr\namm\ter\t";
    assert(word_2+12 == findSpaceReverse(word_2+12, word_2));
    char *word_3 = "university";
    assert(word_3 == findSpaceReverse(word_3+9, word_3));
}

void test_strcmp_(){
    char *word_1 = " hello";
    char *word_2 = " hello";
    assert(strcmp_(word_1, word_2));
    char *word_3 = "hello";
    char *word_4 = " hello";
    assert(!strcmp_(word_3, word_4));
}

void test_copy(){
    char *word_1 = "hello";
    char *beginDestination = malloc(10);
    assert(beginDestination+5 == copy(word_1, word_1+4, beginDestination));
    free(beginDestination);
}

bool funct(char a){
    return a < 111;
}

void test_copyIf(){
    char *word = "beginDestination";
    char *beginDestination = malloc(100);
    assert(beginDestination + 11 == copyIf(word,word+15,beginDestination,funct));
    free(beginDestination);
}
void test_copyIfReverse(){
    char *word = "beginDestination";
    char *beginDestination = malloc(100);
    assert(beginDestination + 5 == copyIfReverse(word+8,word+1,beginDestination,funct));
    free(beginDestination);
}

void str_test() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}