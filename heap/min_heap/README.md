# Min Heap Implementation in C

This project implements a Min Heap in C. A Min Heap is a binary heap where the root node contains the minimum value, and each parent node is smaller than its child nodes. This implementation includes functions for inserting values, extracting the minimum value, and heapifying up and down.

## Features

- **Dynamic Resizing**: Automatically resizes when the heap reaches its capacity.
- **Min Heap Property**: Ensures that each parent node is smaller than its child nodes.
- **Heap Operations**: Supports insert, extract min, and heapify operations.
- **Efficient**: Provides logarithmic time complexity for insertions and extractions.

## File Structure

- **min_heap.h**: Header file that defines the `MinHeap` structure and function prototypes.
- **min_heap.c**: Implementation of the min heap operations (insert, extract, heapify, etc.).
- **main.c**: Example file that demonstrates how to use the min heap.

## How to Use

1. **Include the Header**: Include `min_heap.h` in your project to access the MinHeap functions.

2. **Create a Min Heap**: Call `create_min_heap()` to create a new min heap with an initial capacity.

3. **Insert Elements**: Use `insert_min_heap()` to insert elements into the heap.

4. **Extract the Minimum**: Use `extract_min()` to remove and return the minimum element from the heap.

5. **Free Memory**: When done, use `free_min_heap()` to release all memory associated with the heap.

## Example

```c
#include "min_heap.h"
#include <stdio.h>

int main() {
    MinHeap* heap = create_min_heap(10);

    insert_min_heap(heap, 15);
    insert_min_heap(heap, 5);
    insert_min_heap(heap, 10);
    insert_min_heap(heap, 20);

    printf("Min value: %d\n", extract_min(heap));  // Should return 5
    printf("Min value: %d\n", extract_min(heap));  // Should return 10

    free_min_heap(heap);
    return 0;
}
```


## Compilation
```bash
    gcc main.c min_heap.c -o min_heap_program
````