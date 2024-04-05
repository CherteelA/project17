//
// Created by admin on 04.04.2024.
//
#include "../string.h"
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

void str_test(){
    test_strlen_();
    test_find();
}