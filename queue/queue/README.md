# Queue Implementation in C

A Queue is a linear data structure that follows the First In, First Out (FIFO) principle. This implementation uses a circular array to efficiently manage queue operations.

## Features

- **Circular Array**: Utilizes a circular array to manage queue operations efficiently.
- **Dynamic Size Management**: Adjusts the front and rear pointers to manage elements.
- **Efficient Operations**: Provides constant-time operations for enqueueing and dequeueing elements.

## File Structure

- **queue.h**: Header file defining the structure of the queue and function prototypes.
- **queue.c**: Implementation of queue operations (enqueue, dequeue, etc.).
- **main.c**: Example file demonstrating how to use the queue.

## How to Use

1. **Include the Header**: Include `queue.h` in your project to access the queue functions.

2. **Create a Queue**: Use `create_queue()` to initialize a new queue with a specified capacity.

3. **Enqueue Elements**: Use `enqueue()` to add elements to the rear of the queue.

4. **Dequeue Elements**: Use `dequeue()` to remove and return elements from the front of the queue.

5. **Free Memory**: Use `free_queue()` to free the memory allocated for the queue.

## Example

```c
#include "queue.h"
#include <stdio.h>

int main() {
    Queue* queue = create_queue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    free_queue(queue);
    return 0;
}
```


## Compilation
```bash
    gcc main.c queue.c -o queue_program
````