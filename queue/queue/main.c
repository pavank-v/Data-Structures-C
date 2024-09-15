#include <stdio.h>
#include "queue.h"

int main(){
    Queue* queue = create_queue(10);

    enqueue(queue, 19);
    enqueue(queue, 2);
    enqueue(queue, 23);
    enqueue(queue, 230499);

    printf("%d dequeued from queue\n", dequeue(queue));

    free_queue(queue);
    return 0;
}