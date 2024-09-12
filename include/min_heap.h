#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef struct MinHeap{
    int *arr;
    int capacity;
    int size;
}MinHeap;

MinHeap* create_min_heap(int capacity);
void resize_heap(MinHeap* heap);
void insert_min_heap(MinHeap* heap, int value);
int extract_min(MinHeap* heap);
void free_min_heap(MinHeap* heap);

#endif