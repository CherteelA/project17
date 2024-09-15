#include "stack.h"

stackNode * push_(stackNode *n, char *data, int size){
    stackNode *newStackNode = (stackNode*)malloc(sizeof(stackNode));
    newStackNode->data = malloc(size);
    memcpy(newStackNode->data, data, size);
    newStackNode->next = n;
    return newStackNode;
}

stackNode * pop_(stackNode *n){
    stackNode *next = n->next;
    free(n->data);
    free(n);
    return next;
}

void freeStack(stackNode *n){
    while (n){
        n = pop_(n);
    }
}