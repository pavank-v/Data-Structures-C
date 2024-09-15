#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct MaxHeap{
    int *arr;
    int size;
    int capacity;
}MaxHeap;

MaxHeap* create_max_heap(int capacity);
void resize_heap(MaxHeap* heap);
void insert_max_heap(MaxHeap* heap, int value);
int extract_max(MaxHeap* heap);
void free_max_heap(MaxHeap* heap);

#endif