#include <stdio.h>
#include "max_heap.h"

int main() {
    MaxHeap* heap = create_max_heap(4);  // Initial capacity of 4

    insert_max_heap(heap, 10);
    insert_max_heap(heap, 20);
    insert_max_heap(heap, 15);
    insert_max_heap(heap, 30);
    insert_max_heap(heap, 25);

    printf("Extracted max: %d\n", extract_max(heap));
    printf("Extracted max: %d\n", extract_max(heap));

    free_max_heap(heap);  // Free memory
    return 0;
}