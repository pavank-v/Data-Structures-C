#ifndef DEQUE_H
#define DEQUE_H

typedef struct Deque{
    int front, rear, size;
    unsigned capacity;
    int* arr;
} Deque;

Deque* create_deque(unsigned capacity);
int is_full(Deque* deque);
int is_empty(Deque* deque);
void insert_front(Deque* deque, int element);
void insert_rear(Deque* deque, int element);
int delete_front(Deque* deque);
int delete_rear(Deque* deque);
void free_deque(Deque* deque);

#endif