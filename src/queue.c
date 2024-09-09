#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* create_queue(unsigned capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int is_full(Queue* queue){
    return (queue->size == queue->capacity);
}

int is_empty(Queue* queue){
    return (queue->size == 0);
}

void enqueue(Queue* queue, int element){
    if (is_full(queue)){
        printf("Queue is full, connot enqueue\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = element;
    queue->size += 1;
    printf("Enqueued: %d\n", element);
}

int dequeue(Queue* queue){
    if (is_empty(queue)){
        printf("Queue is empty, cannnot dequeue\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

void free_queue(Queue* queue){
    free(queue->arr);
    free(queue);
}