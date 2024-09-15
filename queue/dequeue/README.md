# Deque Implementation in C

A Deque (Double-Ended Queue) is a data structure that allows insertion and deletion of elements from both ends. This implementation provides a circular array-based deque with operations to insert and delete elements from both the front and rear.

## Features

- **Circular Array**: Utilizes a circular array to efficiently manage the deque operations.
- **Dynamic Size Management**: Automatically adjusts the front and rear pointers to manage elements.
- **Efficient Operations**: Provides constant-time operations for inserting and deleting elements at both ends.

## File Structure

- **deque.h**: Header file defining the structure of the deque and function prototypes.
- **deque.c**: Implementation of deque operations (insertion, deletion, etc.).
- **main.c**: Example file demonstrating how to use the deque.

## How to Use

1. **Include the Header**: Include `deque.h` in your project to access the deque functions.

2. **Create a Deque**: Use `create_deque()` to initialize a new deque with a specified capacity.

3. **Insert Elements**: Use the following functions to insert elements:
   - `insert_front(Deque* deque, int element)` - Inserts an element at the front.
   - `insert_rear(Deque* deque, int element)` - Inserts an element at the rear.

4. **Delete Elements**: Use the following functions to delete elements:
   - `delete_front(Deque* deque)` - Removes and returns an element from the front.
   - `delete_rear(Deque* deque)` - Removes and returns an element from the rear.

5. **Free Memory**: Use `free_deque()` to free the memory allocated for the deque.

## Example

```c
#include "deque.h"
#include <stdio.h>

int main() {
    Deque* deque = create_deque(5);

    insert_front(deque, 10);
    insert_rear(deque, 20);
    insert_front(deque, 30);
    insert_rear(deque, 40);

    printf("Deleted from front: %d\n", delete_front(deque));
    printf("Deleted from rear: %d\n", delete_rear(deque));

    free_deque(deque);
    return 0;
}
```


## Compilation
```bash
    gcc main.c deque.c -o deque_program
````