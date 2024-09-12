#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef struct Heap{
    int *arr;
    int capacity;
    int size;
}Heap;

Heap* create_min_heap(int capacity);
void resize_heap(Heap* heap);
void insert_min_heap(Heap* heap, int value);
int extract_min(Heap* heap);
void free_heap(Heap* heap);

#endif