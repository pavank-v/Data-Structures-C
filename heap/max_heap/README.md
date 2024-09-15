# Max Heap Implementation in C

This project implements a Max Heap in C. The Max Heap is a binary heap where the root node contains the maximum value, and each parent node is greater than its child nodes. This implementation includes functions for inserting values, extracting the maximum value, and heapifying up and down.

## Features

- **Dynamic Resizing**: Automatically resizes when the heap reaches its capacity.
- **Max Heap Property**: Maintains the max-heap property where each parent node is larger than its children.
- **Heap Operations**: Supports insert, extract max, and heapify operations.
- **Efficient**: Provides logarithmic time complexity for insertions and extractions.

## File Structure

- **max_heap.h**: Header file that defines the `MaxHeap` structure and function prototypes.
- **max_heap.c**: Implementation of the max heap operations (insert, extract, heapify, etc.).
- **main.c**: Example file that demonstrates how to use the max heap.

## How to Use

1. **Include the Header**: Include `max_heap.h` in your project to access the MaxHeap functions.

2. **Create a Max Heap**: Call `create_max_heap()` to create a new max heap with an initial capacity.

3. **Insert Elements**: Use `insert_max_heap()` to insert elements into the heap.

4. **Extract the Maximum**: Use `extract_max()` to remove and return the maximum element from the heap.

5. **Free Memory**: When done, use `free_max_heap()` to release all memory associated with the heap.

## Example

```c
#include "max_heap.h"
#include <stdio.h>

int main() {
    MaxHeap* heap = create_max_heap(10);

    insert_max_heap(heap, 45);
    insert_max_heap(heap, 20);
    insert_max_heap(heap, 35);
    insert_max_heap(heap, 50);

    printf("Max value: %d\n", extract_max(heap));  // Should return 50
    printf("Max value: %d\n", extract_max(heap));  // Should return 45

    free_max_heap(heap);
    return 0;
}
```

## Compilation
```bash
    gcc main.c max_heap.c -o max_heap_program
````