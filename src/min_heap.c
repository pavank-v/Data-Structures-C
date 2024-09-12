#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"

Heap* create_min_heap(int capacity){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (!heap){
        printf("Memory allocation failed\n");
    }
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void resize_heap(Heap* heap){
    heap->capacity *= 2;
    heap->arr = (int*)realloc(heap->arr, heap->capacity * sizeof(int));
    if (heap->arr == NULL){
        printf("Memeory allocation failed\n");
        exit(1);
    }
}
void heapify_up(Heap* heap, int index){
    int parent = (index - 1) / 2;

    while (index > 0 && heap->arr[parent] > heap->arr[index]){
        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}
void insert_min_heap(Heap* heap, int value){
    if (heap->size == heap->capacity){
        resize_heap(heap);
    }

    heap->arr[heap->size++] = value;
    heapify_up(heap, heap->size - 1);
}

void heapify_down(Heap* heap, int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest]){
        smallest = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]){
        smallest = right;
    }

    if (smallest != index){
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapify_down(heap, smallest);
    }
}

int extract_min(Heap* heap){
    if (heap->size == 0){
        printf("Heap is empty\n");
        return -1;
    }
    int item = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify_down(heap, 0);
    return item;
}

void free_heap(Heap* heap){
    free(heap->arr);
    free(heap);
}