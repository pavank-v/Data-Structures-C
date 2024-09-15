#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Deque* create_deque(unsigned capacity){
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
    deque->arr = (int*)malloc(capacity * sizeof(int));
    return deque;
}

int is_full(Deque* deque){
    return (deque->size == deque->capacity);
}

int is_empty(Deque* deque){
    return (deque->size == 0);
}

void insert_front(Deque* deque, int element){
    if (is_full(deque)){
        printf("Queue is Full, cannot insert at front\n");
        return;
    }
    if (deque->front== -1) {
        deque->front = 0;
        deque->rear = 0;
    }
    else if(deque->front == 0){
        deque->front = deque->capacity-1;
    }
    else{
        deque->front--;
    }
    deque->arr[deque->front] = element;
    deque->size++;
    printf("%d inserted at front\n", element);
}

void insert_rear(Deque* deque, int element){
    if (is_full(deque)){
        printf("Queue is full, cannot insert at rear\n");
        return;
    }
    if (deque->front == -1){
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->rear == deque->capacity-1){
        deque->rear = 0;
    }
    else{
        deque->rear++;
    }
    deque->arr[deque->rear] = element;
    deque->size++;
    printf("%d inserted at rear\n", element);
}

int delete_front(Deque* deque){
    if (is_empty(deque)){
        printf("Queue is empty, connot delete at front");
        return -1;
    }
    int item = deque->arr[deque->front];
    if (deque->front == deque->rear){
        deque->front = -1;
        deque->rear = -1;
    }
    else if(deque->front == deque->capacity-1){
        deque->front = 0;
    }
    else{
        deque->front++;
    }
    deque->size--;
    return item;
}

int delete_rear(Deque* deque){
    if (is_empty(deque)){
        printf("Queue is empty, cannot delete at rear\n");
    }
    int item = deque->arr[deque->rear];
    if (deque->rear == deque->front){
        deque->front = -1;
        deque->rear = -1;
    }
    else if(deque->rear == 0){
        deque->rear = deque->capacity-1;
    }
    else{
        deque->rear--;
    }
    deque->size--;
    return item;
}

void free_deque(Deque* deque){
    free(deque->arr);
    free(deque);
}