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

void str_test(){
    test_strlen_();
}