#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* arr;
} Queue;

Queue* create_queue(unsigned capacity);
void enqueue(Queue* queue, int element);
int dequeue(Queue* queue);
int is_empty(Queue* queue);
int is_full(Queue* queue);
void free_queue(Queue* queue);

#endif