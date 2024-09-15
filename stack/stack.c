#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* create_stack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int ele){
    if (stack->top == stack->capacity - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = ele;
}

int pop(Stack* stack){
    if (stack->top == -1){
        printf("Stack Underflow");
        return -1;
    }
    return stack->arr[stack->top--];
}

int is_empty(Stack* stack){
    return stack->top == -1;
}

void free_stack(Stack* stack){
    free(stack->arr);
    free(stack);
}
