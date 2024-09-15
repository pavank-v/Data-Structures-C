# Stack Implementation in C

A Stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This implementation uses a dynamic array to efficiently manage stack operations.

## Features

- **Dynamic Array**: Utilizes a dynamic array to manage stack operations efficiently.
- **Constant-Time Operations**: Provides constant-time operations for push and pop.

## File Structure

- **stack.h**: Header file defining the structure of the stack and function prototypes.
- **stack.c**: Implementation of stack operations (push, pop, etc.).
- **main.c**: Example file demonstrating how to use the stack.

## How to Use

1. **Include the Header**: Include `stack.h` in your project to access the stack functions.

2. **Create a Stack**: Use `create_stack()` to initialize a new stack with a specified capacity.

3. **Push Elements**: Use `push()` to add elements to the stack.

4. **Pop Elements**: Use `pop()` to remove and return elements from the stack.

5. **Check if Empty**: Use `is_empty()` to check if the stack is empty.

6. **Free Memory**: Use `free_stack()` to free the memory allocated for the stack.

## Example

```c
#include "stack.h"
#include <stdio.h>

int main() {
    Stack* stack = create_stack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    free_stack(stack);
    return 0;
}
```

## Compilation
```bash
    gcc main.c max_heap.c -o max_heap_program
````