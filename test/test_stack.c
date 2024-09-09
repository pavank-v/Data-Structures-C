#include <stdio.h>
#include "stack.h"

int main(){
    Stack* stack = create_stack(10);
    push(stack, 12);
    push(stack, 7);
    push(stack, 8);
    
    printf("Popped: %d\n", pop(stack));

    free_stack(stack);
    return 0;
}