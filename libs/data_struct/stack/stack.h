//
// Created by admin on 14.09.2024.
//

#ifndef PROJECT17_STACK_H
#define PROJECT17_STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stackNode{
    char *data;
    struct stackNode *next;
}stackNode;

stackNode * push_(stackNode *n, void *data, int size);
stackNode * pop_(stackNode *n);
void freeStack(stackNode *n);

#endif //PROJECT17_STACK_H
