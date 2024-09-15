# Singly Linked List (SLL) Implementation in C

This project implements a Singly Linked List (SLL) in C. A Singly Linked List is a type of linked list where each node points to the next node in the sequence. This implementation supports various operations including insertion, deletion, and traversal.

## Features

- **Single Direction Traversal**: Each node points to the next node only.
- **Flexible Insertion**: Supports insertion at the front, end, or any specific position in the list.
- **Efficient Deletion**: Allows removal of nodes with specific values.
- **Memory Management**: Provides a function to free allocated memory for the list.

## File Structure

- **sll.h**: Header file defining the structure of the singly linked list node and function prototypes.
- **sll.c**: Implementation of the singly linked list operations (insert, delete, traversal, etc.).
- **main.c**: Example file demonstrating how to use the singly linked list.

## How to Use

1. **Include the Header**: Include `sll.h` in your project to access the SLL functions.

2. **Create a Node**: Use `create_node()` to create a new node for the list.

3. **Insert Elements**: Use the following functions for inserting elements into the list:
   - `insert_front()` for inserting at the front.
   - `insert_end()` for inserting at the end.
   - `insert_middle()` for inserting at a specific position.

4. **Delete Nodes**: Use `delete_node()` to delete a node with a specific value.

5. **Print the List**: Use `print_LL()` to print the contents of the list.

6. **Free Memory**: When done, use `free_list()` to free all memory associated with the list.

## Example

```c
#include "sll.h"
#include <stdio.h>

int main() {
    Node* head = NULL;

    insert_front(&head, 10);
    insert_end(&head, 20);
    insert_middle(&head, 15, 1);

    print_LL(head); // Expected output: List: 10 -> 15 -> 20 -> NULL

    delete_node(&head, 15);
    print_LL(head); // Expected output: List: 10 -> 20 -> NULL

    free_list(head);
    return 0;
}
``` 


## Compilation
```bash
    gcc main.c sll.c -o sll_program
````