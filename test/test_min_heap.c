#include <stdio.h>
#include "min_heap.h"

int main() {
    MinHeap *heap = create_min_heap(4);

    insert_min_heap(heap, 30);
    insert_min_heap(heap, 20);
    insert_min_heap(heap, 10);
    insert_min_heap(heap, 15);

    printf("Extracted: %d\n", extract_min(heap));
    printf("Extracted: %d\n", extract_min(heap));

    insert_min_heap(heap, 5);
    insert_min_heap(heap, 8);

    printf("Extracted: %d\n", extract_min(heap));

    free_min_heap(heap);

    return 0;
}
