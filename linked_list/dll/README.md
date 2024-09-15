# Doubly Linked List (DLL) Implementation in C

This project implements a Doubly Linked List (DLL) in C. A DLL is a type of linked list where each node points not only to the next node but also to the previous one, allowing traversal in both directions. This implementation supports common operations such as insertion, deletion, and traversal.

## Features

- **Bidirectional Traversal**: Each node has pointers to both the next and previous nodes.
- **Flexible Insertion**: Supports insertion at the front, end, or any specific position in the list.
- **Efficient Deletion**: Allows for efficient removal of any node in the list.
- **Memory Management**: Provides functions to free allocated memory for the list.

## File Structure

- **dll.h**: Header file defining the structure of the doubly linked list node and function prototypes.
- **dll.c**: Implementation of the doubly linked list operations (insert, delete, traversal, etc.).
- **main.c**: Example file demonstrating how to use the doubly linked list.

## How to Use

1. **Include the Header**: Include `dll.h` in your project to access the DLL functions.

2. **Create a Node**: Use `create_D_Node()` to create a new node for the list.

3. **Insert Elements**: Use the following functions for inserting elements into the list:
   - `insert_D_front()` for inserting at the front.
   - `insert_D_end()` for inserting at the end.
   - `insert_D_middle()` for inserting at a specific position.

4. **Delete Nodes**: Use `delete_D_Node()` to delete a node with a specific value.

5. **Print the List**: Use `print_DLL()` to print the contents of the list.

6. **Free Memory**: When done, use `free_DLL()` to free all memory associated with the list.

## Example

```c
#include "dll.h"
#include <stdio.h>

int main() {
    D_Node* head = NULL;

    insert_D_front(&head, 10);
    insert_D_front(&head, 20);
    insert_D_end(&head, 30);
    insert_D_middle(&head, 25, 2);

    print_DLL(head); // Expected output: 20 -> 10 -> 25 -> 30 -> NULL

    delete_D_Node(&head, 10);
    print_DLL(head); // Expected output: 20 -> 25 -> 30 -> NULL

    free_DLL(head);
    return 0;
}
```


## Compilation
```bash
    gcc main.c dll.c -o dll_program
````