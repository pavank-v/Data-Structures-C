#ifndef STACK_H
#define STACK_H

typedef struct Stack{
    int top;
    unsigned capacity;
    int *arr;
} Stack;

Stack* create_stack(unsigned capacity);
void push(Stack* stack, int element);
int pop(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);

#endif